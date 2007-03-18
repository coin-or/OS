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

 
  
//#include "lexyaccparser.h"
//#include "externalvars.h"
#include "ErrorClass.h"
#include "OSResult.h"
#include "osrlparservariables.h"


#include "OSrLParserData.h"
#include <iostream>
#include <sstream> 


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string (const char *yy_str , void* yyscanner  );
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* yyscanner );
int osrlget_lineno( void* yyscanner);
char *osrlget_text (void* yyscanner );
void osrlset_lineno (int line_number , void* yyscanner );
OSResult *yygetOSResult( std::string parsestring) ;
void osrlClearMemory();

%}


%pure-parser
%locations
%lex-param {void* scanner}
%parse-param{OSResult *osresult}
%parse-param{OSrLParserData *parserData}



%union {
	double dval;
	int ival;
	char* charval;
}

/* %name-prefix="osrl" 
this fails on in Mac OS X
*/

%{

void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg );
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
 
#define scanner parserData->scanner
%}

%token <charval> ATTRIBUTETEXT
%token <charval> ELEMENTTEXT
%token <ival> INTEGER
%token <dval> DOUBLE




%token QUOTE GREATERTHAN ENDOFELEMENT 
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


osrldoc: osrlstart resultHeader resultData 
{
 	if(parserData->numberOfSolutions > 0){
		for(int solIdx = 0; solIdx <  parserData->numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, parserData->statusType, parserData->statusDescription);
			osresult->setPrimalVariableValues(solIdx, primalSolution[ solIdx]);
			osresult->setNumberOfOtherVariableResult(solIdx, numberOfOtherVariableResult);
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				osresult->setAnOtherVariableResult(solIdx, k, otherVarVec[ k]->name, otherVarVec[ k]->description, otherVarVec[ k]->otherVarText);				
			}
			osresult->setDualVariableValues(solIdx, dualSolution[ solIdx]);
			osresult->setObjectiveValues(solIdx, objectiveValues[ solIdx]);
			osresult->setSolutionObjectiveIndex(solIdx,  *(objectiveIdx + solIdx));
		}
	}
}
OSRLEND;

osrlstart:	OSRLSTART  GREATERTHAN 
			| OSRLSTART OSRLATTRIBUTETEXT GREATERTHAN ;



resultHeader: RESULTHEADERSTART generalStatus serviceURI serviceName instanceName jobID headerMessage RESULTHEADEREND  ; 
   
generalStatus: GENERALSTATUSSTART anotherGeneralStatusATT GREATERTHAN GENERALSTATUSEND {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");}
| GENERALSTATUSSTART anotherGeneralStatusATT ENDOFELEMENT {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;};

anotherGeneralStatusATT: generalstatusatt
	| anotherGeneralStatusATT generalstatusatt  ;

generalstatusatt: TYPEATT ATTRIBUTETEXT quote  { osresult->setGeneralStatusType($2);  parserData->generalStatusTypePresent = true;}   
		|  DESCRIPTIONATT ATTRIBUTETEXT  quote {  osresult->setGeneralStatusDescription($2); }    


serviceURI: 
| SERVICEURISTARTANDEND
| SERVICEURISTART ELEMENTTEXT SERVICEURIEND {osresult->setServiceURI( $2);}
| SERVICEURISTART SERVICEURIEND ;


serviceName: 
| SERVICENAMESTARTANDEND
| SERVICENAMESTART ELEMENTTEXT SERVICENAMEEND {osresult->setServiceName( $2);}
| SERVICENAMESTART SERVICENAMEEND ;

instanceName: 
| INSTANCENAMESTARTANDEND
| INSTANCENAMESTART ELEMENTTEXT INSTANCENAMEEND {osresult->setInstanceName( $2) ;}
| INSTANCENAMESTART INSTANCENAMEEND ;

jobID: 
| JOBIDSTARTANDEND
| JOBIDSTART ELEMENTTEXT JOBIDEND {osresult->setJobID( $2);}
| JOBIDSTART JOBIDEND ;

headerMessage: 
| HEADERMESSAGESTARTANDEND
| HEADERMESSAGESTART ELEMENTTEXT HEADERMESSAGEEND {osresult->setGeneralMessage( $2);}
| HEADERMESSAGESTART HEADERMESSAGEEND ;

resultData: RESULTDATASTARTANDEND 
|  RESULTDATASTART statistics optimization otherResultData RESULTDATAEND
| RESULTDATASTART RESULTDATAEND

otherResultData:
| DUMMY;
   
statistics:
| DUMMY

optimization: OPTIMIZATIONSTART anotherOptATT
{
// we now have the basic problem parameters
	if(parserData->numberOfSolutions > 0){
			primalSolution = new double* [parserData->numberOfSolutions];
			dualSolution = new double*[ parserData->numberOfSolutions];
			objectiveValues = new double*[ parserData->numberOfSolutions];
			objectiveIdx = new int[ parserData->numberOfSolutions];
			if( parserData->numberOfVariables > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					primalSolution[ i] = new double[ parserData->numberOfVariables];
				}
			}
			if( parserData->numberOfConstraints > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
			if( parserData->numberOfObjectives > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					objectiveValues[ i] = new double[ parserData->numberOfObjectives];
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


optnumsolatt: NUMBEROFSOLUTIONSATT INTEGER   {parserData->numberOfSolutions = $2; osresult->setSolutionNumber($2);}  ;
	
optnumvaratt: NUMBEROFVARIABLESATT INTEGER  {parserData->numberOfVariables = $2; osresult->setVariableNumber($2); } ; 
	
optnumconatt: NUMBEROFCONSTRAINTSATT INTEGER   {parserData->numberOfConstraints = $2; osresult->setConstraintNumber($2);}  ;

optnumobjatt: NUMBEROFOBJECTIVESATT INTEGER   {parserData->numberOfObjectives = $2; osresult->setObjectiveNumber($2);}  ;
	


solution:  OPTIMIZATIONEND
| anothersolution  OPTIMIZATIONEND
| solution anothersolution  OPTIMIZATIONEND;


anothersolution: SOLUTIONSTART objectiveIDXATT GREATERTHAN status message variables objectives constraints otherSolution   {solutionIdx++;};





objectiveIDXATT: 
| OBJECTIVEIDXATT INTEGER quote {if($2 >= 0) osrlerror(NULL, NULL, NULL, "objective index must be nonpositive");
*(objectiveIdx + solutionIdx) = $2;};

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(solutionIdx, parserData->statusType, parserData->statusDescription);}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); statusTypePresent = false; osresult->setSolutionStatus(solutionIdx, parserData->statusType, parserData->statusDescription);};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:  TYPEATT ATTRIBUTETEXT  quote  {parserData->statusType = $2; statusTypePresent = true;}  
		|  DESCRIPTIONATT ATTRIBUTETEXT quote  {parserData->statusDescription = $2;}  ;

message:
| MESSAGESTART ELEMENTTEXT MESSAGEEND
| MESSAGESTART MESSAGEEND;

variables:
| VARIABLESSTART GREATERTHAN VALUESSTART GREATERTHAN var VALUESEND 
 otherVariables VARIABLESEND;

var: anothervar
| var anothervar;

anothervar: VARSTART anIDXATT GREATERTHAN DOUBLE VAREND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + parserData->kounter ) = $4;
	}
|  VARSTART anIDXATT GREATERTHAN INTEGER VAREND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + parserData->kounter) = $4;
}; 



otherVariables:
| otherVariables otherVariableResult;

otherVariableResult:  OTHERSTART {  
    numberOfOtherVariableResult++;
	otherVarStruct = new OtherVariableResultStruct(); 
	otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];} anotherotherVarATT GREATERTHAN {if(otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	otherNamePresent = false;  
	}  othervar OTHEREND {otherVarVec.push_back( otherVarStruct);};
 
othervar: anotherothervar
| othervar anotherothervar;

anotherothervar: VARSTART anIDXATT  GREATERTHAN ELEMENTTEXT  VAREND { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
otherVarStruct->otherVarText[parserData->kounter] = $4;
}
|
VARSTART anIDXATT  GREATERTHAN DOUBLE  VAREND { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << $4;
otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
|VARSTART anIDXATT  GREATERTHAN INTEGER  VAREND { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << $4;
otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
};

 
anotherotherVarATT: otheratt
	|  anotherotherVarATT otheratt  ; 

otheratt:  NAMEATT ATTRIBUTETEXT quote  { otherNamePresent = true; otherVarStruct->name = $2;}
		| DESCRIPTIONATT ATTRIBUTETEXT  quote {   otherVarStruct->description = $2;}    ;


objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND;

obj: anotherobj
| obj anotherobj;

anotherobj: OBJSTART anIDXATT GREATERTHAN DOUBLE OBJEND { *(objectiveValues[solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;
}
| OBJSTART anIDXATT GREATERTHAN INTEGER OBJEND { *(objectiveValues[solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;};


constraints:
| CONSTRAINTSSTART GREATERTHAN DUALVALUESSTART GREATERTHAN con DUALVALUESEND otherConstraints CONSTRAINTSEND;

con: anothercon
| con anothercon;

anothercon: CONSTART anIDXATT GREATERTHAN DOUBLE CONEND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + parserData->kounter) = $4;}
|  CONSTART anIDXATT GREATERTHAN INTEGER CONEND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + parserData->kounter) = $4;} ;




anIDXATT: IDXATT INTEGER quote {parserData->kounter = $2;};





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

void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, const char* errormsg )
{
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
	outStr << "The offending text is: " << *osrlget_text ( scanner ) << std::endl; 
	error = outStr.str();
	throw ErrorClass( error);
} //end osrlerror

OSResult *yygetOSResult(std::string parsestring){
	void osrlinitialize();
	osrlinitialize();
	
	try{
		OSResult* osresult = NULL;
		osresult = new OSResult();
		OSrLParserData *parserData = NULL;
		parserData = new OSrLParserData();
		// call the flex scanner
		osrllex_init( &scanner);
		osrl_scan_string( parsestring.c_str(), scanner);

		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData) != 0) {
			osrllex_destroy(scanner);
		 	delete parserData;
		  	throw ErrorClass(  "Error parsing the OSiL");
		 }
		osrllex_destroy(scanner);
		delete parserData;
		return osresult;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult

void osrlClearMemory(){
	//delete osresult;
	//osresult = NULL;
	/*if(numberOfSolutions > 0){
		delete[] objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
			delete[] primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				delete[] otherVarVec[ k]->otherVarText;
				otherVarVec[ k] = NULL;				
			}
			otherVarVec.clear();
			if( numberOfConstraints > 0){
				delete[] dualSolution[ i];
				dualSolution[ i] = NULL;
			}
			delete[] objectiveValues[i];
			objectiveValues = NULL;
		}
	}
	delete primalSolution;
	primalSolution = NULL;
	delete dualSolution;
	dualSolution = NULL;
	*/
} // end osrlClearMemory

void osrlinitialize(){
	//numberOfSolutions = 0;
	//numberOfVariables = 0;
	//numberOfConstraints = 0;
	//numberOfObjectives = 0;
	//statusType = "";
	//statusDescription = "";
	//generalStatusType = "";
	//generalStatusDescription = "";
	//beginElementText = false;
	statusTypePresent = false;
	generalStatusTypePresent = false;
	otherNamePresent = false;
	solutionIdx = 0;
	objectiveValues = NULL;
	primalSolution = NULL;
	dualSolution = NULL;
	objectiveIdx = NULL;
	//kounter = 0;
	//serviceURI = "";
	//serviceName = "";
	//instanceName = "";
	//jobID = "";
	//headerMessage = "";
	otherVarVec.reserve(20);
}// end osrlinitialize


