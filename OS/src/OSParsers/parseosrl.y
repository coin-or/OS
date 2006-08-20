/** @file parseosrl.l
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

%{

 
  
#include "lexyaccparser.h"
#include "externalvars.h"
#include "ErrorClass.h"
#include "OSResult.h"
#include "osrlparservariables.h"
#include <iostream>
#include <sstream> 

 




%}

%union {
	double dval;
	int ival;
	char* charval;
}

/* %name-prefix="osrl" 
this fails on in Mac OS X
*/

%token <charval> ATTRIBUTETEXT
%token <charval> ELEMENTTEXT
%token <ival> INTEGER
%token <dval> DOUBLE




%token QUOTE GREATERTHAN ENDOFELEMENT 
%token ATTRIBUTETEXT ELEMENTTEXT INTEGER DOUBLE

%token OSRLSTART OSRLATTRIBUTETEXT OSRLEND
%token RESULTHEADERSTART RESULTHEADEREND 
%token SERVICEURISTARTANDEND  SERVICEURISTART SERVICEURIEND
%token SERVICENAMESTARTANDEND SERVICENAMESTART SERVICENAMEEND
%token INSTANCENAMESTARTANDEND INSTANCENAMESTART INSTANCENAMEEND
%token JOBIDSTARTANDEND JOBIDSTART JOBIDEND
%token HEADERMESSAGESTARTANDEND HEADERMESSAGESTART HEADERMESSAGEEND
%token RESULTDATASTART RESULTDATAEND RESULTDATASTARTANDEND
%token OPTIMIZATIONSTART OPTIMIZATIONEND
%token SOLUTIONSTART SOLUTIONEND  VALUESSTART VALUESEND 
%token DUALVALUESSTART DUALVALUESEND  
%token VARIABLESSTART VARIABLESEND VARSTART VAREND 
%token OBJECTIVESSTART OBJECTIVESEND OBJSTART OBJEND 
%token CONSTRAINTSSTART CONSTRAINTSEND CONSTART CONEND
%token STATUSSTART STATUSEND GENERALSTATUSSTART GENERALSTATUSEND 
%token MESSAGESTART MESSAGEEND OTHERSTART OTHEREND



%token NUMBEROFSOLUTIONSATT NUMBEROFVARIABLESATT NUMBEROFCONSTRAINTSATT NUMBEROFOBJECTIVESATT
%token OBJECTIVEIDXATT IDXATT TYPEATT DESCRIPTIONATT NAMEATT

%token DUMMY

%%


osrldoc: osrlstart resultHeader resultData  OSRLEND;

osrlstart:	OSRLSTART  GREATERTHAN 
			| OSRLSTART OSRLATTRIBUTETEXT GREATERTHAN ;



resultHeader: RESULTHEADERSTART generalStatus serviceURI serviceName instanceName jobID headerMessage RESULTHEADEREND  ; 
   
generalStatus: GENERALSTATUSSTART anotherGeneralStatusATT GREATERTHAN GENERALSTATUSEND {if(generalStatusTypePresent == false) osrlerror("a type attribute required for generalStatus element");}
| GENERALSTATUSSTART anotherGeneralStatusATT ENDOFELEMENT {if(generalStatusTypePresent == false) osrlerror("a type attribute required for generalStatus element"); generalStatusTypePresent = false;};

anotherGeneralStatusATT: generalstatusatt
	| anotherGeneralStatusATT generalstatusatt  ;

generalstatusatt: TYPEATT ATTRIBUTETEXT quote  {generalStatusType = $2; generalStatusTypePresent = true;}   
		|  DESCRIPTIONATT ATTRIBUTETEXT  quote {generalStatusDescription = $2;}    


serviceURI: 
| SERVICEURISTARTANDEND
| SERVICEURISTART ELEMENTTEXT SERVICEURIEND {serviceURI = $2;}
| SERVICEURISTART SERVICEURIEND ;


serviceName: 
| SERVICENAMESTARTANDEND
| SERVICENAMESTART ELEMENTTEXT SERVICENAMEEND {serviceName = $2;}
| SERVICENAMESTART SERVICENAMEEND ;

instanceName: 
| INSTANCENAMESTARTANDEND
| INSTANCENAMESTART ELEMENTTEXT INSTANCENAMEEND {instanceName = $2;}
| INSTANCENAMESTART INSTANCENAMEEND ;

jobID: 
| JOBIDSTARTANDEND
| JOBIDSTART ELEMENTTEXT JOBIDEND {jobID = $2;}
| JOBIDSTART JOBIDEND ;

headerMessage: 
| HEADERMESSAGESTARTANDEND
| HEADERMESSAGESTART ELEMENTTEXT HEADERMESSAGEEND {headerMessage = $2;}
| HEADERMESSAGESTART HEADERMESSAGEEND ;

resultData: RESULTDATASTART statistics optimization otherResultData RESULTDATAEND
|  RESULTDATASTARTANDEND

otherResultData:
| DUMMY;
   
statistics:
| DUMMY

optimization: OPTIMIZATIONSTART anotherOptATT
{
// we now have the basic problem parameters
	if( numberOfSolutions > 0){
			primalSolution = new double*[numberOfSolutions];
			dualSolution = new double*[numberOfSolutions];
			objectiveValues = new double*[numberOfSolutions];
			objectiveIdx = new int[ numberOfSolutions];
			if( numberOfVariables > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					primalSolution[ i] = new double[ numberOfVariables];
				}
			}
			if( numberOfConstraints > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					dualSolution[ i] = new double[ numberOfConstraints];
				}
			}
			if( numberOfObjectives > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					objectiveValues[ i] = new double[ numberOfObjectives];
				}
			}
	}
}
optend ;


optend:   ENDOFELEMENT 
		| GREATERTHAN  solution ;

anotherOptATT: 
	| anotherOptATT optatt  ;

optatt:  optnumsolatt  quote
		| optnumvaratt   quote          
		| optnumconatt  quote
		| optnumobjatt   quote
		;


optnumsolatt: NUMBEROFSOLUTIONSATT INTEGER   {numberOfSolutions = $2;}  ;
	
optnumvaratt: NUMBEROFVARIABLESATT INTEGER  {numberOfVariables = $2;} ;
	
optnumconatt: NUMBEROFCONSTRAINTSATT INTEGER   {numberOfConstraints = $2;}  ;


optnumobjatt: NUMBEROFOBJECTIVESATT INTEGER   {numberOfObjectives = $2;}  ;
	


solution:  OPTIMIZATIONEND
| anothersolution  OPTIMIZATIONEND
| solution anothersolution  OPTIMIZATIONEND;

anothersolution: SOLUTIONSTART objectiveIDXATT GREATERTHAN status message variables objectives constraints otherSolution   {solutionIdx++;};





objectiveIDXATT: 
| OBJECTIVEIDXATT INTEGER quote {if($2 >= 0) osrlerror("objective index must be nonpositive");
*(objectiveIdx + solutionIdx) = $2;};

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(statusTypePresent == false) osrlerror("a type attribute required for status element");}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(statusTypePresent == false) osrlerror("a type attribute required for status element"); statusTypePresent = false;};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:  TYPEATT ATTRIBUTETEXT  quote  {statusType = $2; statusTypePresent = true;}  
		|  DESCRIPTIONATT ATTRIBUTETEXT quote  {statusDescription = $2;}  ;

message:
| MESSAGESTART ELEMENTTEXT MESSAGEEND
| MESSAGESTART MESSAGEEND;

variables:
| VARIABLESSTART GREATERTHAN VALUESSTART GREATERTHAN var VALUESEND otherVariables VARIABLESEND;

var: anothervar
| var anothervar;

anothervar: VARSTART anIDXATT GREATERTHAN DOUBLE VAREND { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter ) = $4;
	}
|  VARSTART anIDXATT GREATERTHAN INTEGER VAREND { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter) = $4;
}; 



otherVariables:
| otherVariables otherVariableResult;

otherVariableResult:  OTHERSTART {  
    numberOfOtherVariableResult++;
	otherVarStruct = new OtherVariableResultStruct(); 
	otherVarStruct->rcost = new std::string[numberOfVariables];} anotherotherVarATT GREATERTHAN {if(otherNamePresent == false) osrlerror("other element requires name attribute"); 
	otherNamePresent = false;  
	}  othervar OTHEREND {otherVarVec.push_back( otherVarStruct);};
 
othervar: anotherothervar
| othervar anotherothervar;

anotherothervar: VARSTART anIDXATT {beginElementText = true;  }  GREATERTHAN ELEMENTTEXT  {beginElementText = false; } VAREND { 
if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
otherVarStruct->rcost[kounter] = $5;
};

 
anotherotherVarATT: otheratt
	|  anotherotherVarATT otheratt  ; 

otheratt:  NAMEATT ATTRIBUTETEXT quote  { otherNamePresent = true; otherVarStruct->name = $2;}
		| DESCRIPTIONATT ATTRIBUTETEXT  quote {   otherVarStruct->description = $2;}    ;


objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND;

obj: anotherobj
| obj anotherobj;

anotherobj: OBJSTART anIDXATT GREATERTHAN DOUBLE OBJEND { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = $4;
}
| OBJSTART anIDXATT GREATERTHAN INTEGER OBJEND { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = $4;};


constraints:
| CONSTRAINTSSTART GREATERTHAN DUALVALUESSTART GREATERTHAN con DUALVALUESEND otherConstraints CONSTRAINTSEND;

con: anothercon
| con anothercon;

anothercon: CONSTART anIDXATT GREATERTHAN DOUBLE CONEND { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror("index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = $4;}
|  CONSTART anIDXATT GREATERTHAN INTEGER CONEND { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror("index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = $4;} ;




anIDXATT: IDXATT INTEGER quote {kounter = $2;};





otherObjectives:
| DUMMY;

otherConstraints:
| DUMMY;

otherSolution: SOLUTIONEND
| DUMMY SOLUTIONEND;





quote: xmlWhiteSpace QUOTE;

xmlWhiteSpaceChar: ' '
				| '\t'
				| '\r'
				| '\n' ;
				
xmlWhiteSpace: 
			| xmlWhiteSpace xmlWhiteSpaceChar ;
			

%%

void osrlerror(const char* errormsg)
{
	try{
		ostringstream outStr;
		std::string error = errormsg;
		error = "Input is either not valid or well formed: "  + error;
		outStr << error << endl;
		outStr << "Here is the last token read: " << osrltext << endl;
		outStr << "See line number: " << osrllineno << endl;
		error = outStr.str();
		throw ErrorClass( error);
		throw error;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} // end osrlerror

OSResult *yygetOSResult(std::string parsestring){
	void osrlinitialize();
	bool createOSResult();
	osrlinitialize();
	osrl_scan_string( parsestring.c_str());
	std::cout << std::endl << std::endl;
	std::cout << "start parsing now" << std::endl;
	osrlparse();
	std::cout << "Parse a success" << std::endl;
	if( createOSResult() == false) osrlerror("Could not create OSResult");
	return osresult;
} // end yygetOSResult

void osrlClearMemory(){
	delete osresult;
	osresult = NULL;
	if(numberOfSolutions > 0){
		delete[] objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
			delete[] primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				delete[] otherVarVec[ k]->rcost;
				otherVarVec[ k] = NULL;				
			}
			otherVarVec.clear();
			delete[] dualSolution[ i];
			dualSolution[ i] = NULL;
			delete[] objectiveValues[i];
			objectiveValues = NULL;
		}
	}
	delete primalSolution;
	primalSolution = NULL;
	delete dualSolution;
	dualSolution = NULL;
} // end osrlClearMemory

void osrlinitialize(){
	numberOfSolutions = 0;
	numberOfVariables = 0;
	numberOfConstraints = 0;
	numberOfObjectives = 0;
	statusType = "";
	statusDescription = "";
	generalStatusType = "";
	generalStatusDescription = "";
	beginElementText = false;
	statusTypePresent = false;
	generalStatusTypePresent = false;
	otherNamePresent = false;
	solutionIdx = 0;
	objectiveValues = NULL;
	primalSolution = NULL;
	dualSolution = NULL;
	objectiveIdx = NULL;
	kounter = 0;
	serviceURI = "";
	serviceName = "";
	instanceName = "";
	jobID = "";
	headerMessage = "";
	otherVarVec.reserve(20);
}// end osrlinitialize

bool createOSResult(){
	osresult = new OSResult();
	// set resultHeader parameters
	if(generalStatusType != "") osresult->setGeneralStatusType( generalStatusType);
	if(generalStatusDescription != "") osresult->setGeneralStatusType( generalStatusDescription);
	if(serviceName != "") osresult->setServiceName( serviceName);
	if(serviceURI != "") osresult->setServiceURI( serviceURI);
	if(instanceName != "") osresult->setInstanceName( instanceName);
	if(jobID != "") osresult->setJobID( jobID);
	if(headerMessage != "") osresult->setGeneralMessage( headerMessage);
	// set basic problem parameters
	if(osresult->setVariableNumber( numberOfVariables) != true)
		osrlerror("OSResult error: setVariableNumber");
	if(osresult->setObjectiveNumber( numberOfObjectives) != true)
		osrlerror("OSResult error: setObjectiveNumber");
	if(osresult->setConstraintNumber( numberOfConstraints) != true)
		osrlerror("OSResult error: setConstraintNumber");
	if(osresult->setSolutionNumber( numberOfSolutions) != true)
		osrlerror("OSResult error: setSolutionNumer");
	//
	// now loop over the solutions
	std::cout << "Number of Soutions = " << numberOfSolutions << std::endl;
	std::cout << "Number of Variables = " << numberOfVariables << std::endl;
	std::cout << "Number of Constraints = " << numberOfConstraints << std::endl;
	std::cout << "Number of Objectives = " << numberOfObjectives << std::endl;
	std::cout << "Status Type = " <<  statusType << std::endl;
	std::cout << std::endl << std::endl;
	//

	if(numberOfSolutions > 0){
		for(int solIdx = 0; solIdx < numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, statusType, statusDescription);
			osresult->setPrimalVariableValues(solIdx, primalSolution[ solIdx]);
			osresult->setNumberOfOtherVariableResult(solIdx, numberOfOtherVariableResult);
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				osresult->setAnOtherVariableResult(solIdx, k, otherVarVec[ k]->name, otherVarVec[ k]->description, otherVarVec[ k]->rcost);				
			}
			osresult->setDualVariableValues(solIdx, dualSolution[ solIdx]);
			osresult->setObjectiveValues(solIdx, objectiveValues[ solIdx]);
			osresult->setSolutionObjectiveIndex(solIdx,  *(objectiveIdx + solIdx));
		}
		
	}
	return true;
}







