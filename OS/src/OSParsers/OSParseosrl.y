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

 
  

#include "OSErrorClass.h"
#include "OSResult.h"
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
void osrlset_extra (OSrLParserData* parserData ,   void* yyscanner );
OSResult *yygetOSResult( std::string parsestring) ;


%}


%pure-parser
%locations
%defines
%parse-param{OSResult *osresult}
%parse-param{OSrLParserData *parserData}
%lex-param {void* scanner}




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
%token RESULTDATASTART RESULTDATAEND RESULTDATASTARTANDEND
%token OPTIMIZATIONSTART OPTIMIZATIONEND
%token SOLUTIONSTART SOLUTIONEND  VALUESSTART VALUESEND 
%token DUALVALUESSTART DUALVALUESEND  
%token VARIABLESSTART VARIABLESEND VARSTART VAREND 
%token OBJECTIVESSTART OBJECTIVESEND OBJSTART OBJEND 
%token CONSTRAINTSSTART CONSTRAINTSEND CONSTART CONEND
%token STATUSSTART STATUSEND GENERALSTATUSSTART GENERALSTATUSEND 
%token MESSAGESTART MESSAGEEND MESSAGESTARTANDEND OTHERSTART OTHEREND



%token NUMBEROFSOLUTIONSATT NUMBEROFVARIABLESATT NUMBEROFCONSTRAINTSATT NUMBEROFOBJECTIVESATT
%token OBJECTIVEIDXATT IDXATT TYPEATT DESCRIPTIONATT NAMEATT

%token DUMMY

%%


osrldoc: osrlstart resultHeader resultData 
{
 	if(parserData->numberOfSolutions > 0){
		for(int solIdx = 0; solIdx <  parserData->numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, parserData->statusType, parserData->statusDescription);
			osresult->setPrimalVariableValues(solIdx, parserData->primalSolution[ solIdx]);
		    osresult->setNumberOfOtherVariableResult(solIdx, parserData->numberOfOtherVariableResult);
			for(int k = 0; k < parserData->numberOfOtherVariableResult; k++){
				osresult->setAnOtherVariableResult(solIdx, k, parserData->otherVarVec[ k]->name, parserData->otherVarVec[ k]->description, parserData->otherVarVec[ k]->otherVarText);				
			}
			if( (parserData->dualSolution != NULL) &&  (parserData->dualSolution[ solIdx] != NULL) )  osresult->setDualVariableValues(solIdx, parserData->dualSolution[ solIdx]);
			if( (parserData->objectiveValues != NULL) &&  (parserData->objectiveValues[ solIdx] != NULL) ) osresult->setObjectiveValues(solIdx, parserData->objectiveValues[ solIdx]);
		    osresult->setSolutionObjectiveIndex(solIdx,  *(parserData->objectiveIdx + solIdx));
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
| SERVICEURISTART ELEMENTTEXT SERVICEURIEND {osresult->setServiceURI( $2); free($2); $2=NULL;}
| SERVICEURISTART SERVICEURIEND ;


serviceName: 
| SERVICENAMESTARTANDEND
| SERVICENAMESTART ELEMENTTEXT SERVICENAMEEND {osresult->setServiceName( $2);  free($2);   $2=NULL;}
| SERVICENAMESTART SERVICENAMEEND ;

instanceName: 
| INSTANCENAMESTARTANDEND
| INSTANCENAMESTART ELEMENTTEXT INSTANCENAMEEND {osresult->setInstanceName( $2) ;  free($2);   $2=NULL;}
| INSTANCENAMESTART INSTANCENAMEEND ;

jobID: 
| JOBIDSTARTANDEND
| JOBIDSTART ELEMENTTEXT JOBIDEND {osresult->setJobID( $2);  free($2);  $2=NULL;}
| JOBIDSTART JOBIDEND ;

headerMessage: 
| MESSAGESTARTANDEND
| MESSAGESTART ELEMENTTEXT MESSAGEEND {osresult->setGeneralMessage( $2);  free($2);  $2=NULL;}
| MESSAGESTART MESSAGEEND ;

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
			if( parserData->numberOfVariables > 0){
				parserData->primalSolution = new double* [parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->primalSolution[ i] = new double[ parserData->numberOfVariables];
				}
			}
			//if( parserData->numberOfConstraints > 0){
			//	parserData->dualSolution = new double*[ parserData->numberOfSolutions];
			//	for(int i = 0; i < parserData->numberOfSolutions; i++){
			//		parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
			//	}
			//}
			if( parserData->numberOfObjectives > 0){
				parserData->objectiveValues = new double*[ parserData->numberOfSolutions];
				parserData->objectiveIdx = new int[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->objectiveValues[ i] = new double[ parserData->numberOfObjectives];
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


anothersolution: SOLUTIONSTART objectiveIDXATT GREATERTHAN status message variables objectives  constraints  otherSolution   {parserData->solutionIdx++;};





objectiveIDXATT: 
| OBJECTIVEIDXATT INTEGER quote {if($2 >= 0) osrlerror(NULL, NULL, NULL, "objective index must be nonpositive");
*(parserData->objectiveIdx + parserData->solutionIdx) = $2;};

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:  TYPEATT ATTRIBUTETEXT  quote  {parserData->statusType = $2; parserData->statusTypePresent = true;}  
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
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter ) = $4;
	}
|  VARSTART anIDXATT GREATERTHAN INTEGER VAREND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter) = $4;
}; 



otherVariables:
| otherVariables otherVariableResult;

otherVariableResult:  OTHERSTART {  
    parserData->numberOfOtherVariableResult++;
	parserData->otherVarStruct = new OtherVariableResultStruct(); 
	parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];} anotherotherVarATT GREATERTHAN {if(parserData->otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	parserData->otherNamePresent = false;  
	}  othervar OTHEREND {parserData->otherVarVec.push_back( parserData->otherVarStruct);  };
 
othervar: anotherothervar
| othervar anotherothervar;

anotherothervar: VARSTART anIDXATT  GREATERTHAN ELEMENTTEXT  VAREND { 
std::ostringstream outStr;
outStr << $4;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
free($4); $4=NULL;
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
}
|
VARSTART anIDXATT  GREATERTHAN DOUBLE  VAREND { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << $4;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
|VARSTART anIDXATT  GREATERTHAN INTEGER  VAREND { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << $4;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
};

 
anotherotherVarATT: otheratt
	|  anotherotherVarATT otheratt  ; 

otheratt:  NAMEATT ATTRIBUTETEXT quote  { parserData->otherNamePresent = true; parserData->otherVarStruct->name = $2;}
		| DESCRIPTIONATT ATTRIBUTETEXT  quote {   parserData->otherVarStruct->description = $2;}    ;


objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND;

obj: anotherobj
| obj anotherobj;

anotherobj: OBJSTART anIDXATT GREATERTHAN DOUBLE OBJEND { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;
}
| OBJSTART anIDXATT GREATERTHAN INTEGER OBJEND { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;};


constraints:
| CONSTRAINTSSTART GREATERTHAN DUALVALUESSTART
{
			if( parserData->numberOfConstraints > 0){
				parserData->dualSolution = new double*[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
}
 GREATERTHAN con DUALVALUESEND otherConstraints CONSTRAINTSEND;

con: anothercon
| con anothercon;

anothercon: CONSTART anIDXATT GREATERTHAN DOUBLE CONEND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = $4;}
|  CONSTART anIDXATT GREATERTHAN INTEGER CONEND { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = $4;} ;




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
	outStr << "The offending text is: " << osrlget_text ( scanner ) << std::endl; 
	error = outStr.str();
	printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	osrllex_destroy( scanner);
	throw ErrorClass( error);
} //end osrlerror

OSResult *yygetOSResult(std::string parsestring, OSResult *osresult, OSrLParserData *parserData){
	try{
		// call the flex scanner
		osrllex_init( &scanner);
		osrlset_extra (parserData ,   scanner);
		osrl_scan_string( parsestring.c_str(), scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData) != 0) {
			osrllex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSrL");
		 }
		osrllex_destroy( scanner);
		return osresult;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult

