/** @file parseosrl.y
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 2.0, 02/04/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

%{

 
#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include <iostream>
#include <sstream> 
#include <stdio.h>


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string (const char *yy_str , void* yyscanner  );
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* yyscanner );
int osrlget_lineno( void* yyscanner);
char *osrlget_text (void* yyscanner );
void osrlset_lineno (int line_number , void* yyscanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData ) throw(ErrorClass);


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
	char* sval;
}

/* %name-prefix="osrl" 
this fails in Mac OS X
*/

%{

void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg ) ;
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
 
#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <ival> INTEGER
%token <dval> DOUBLE




%token QUOTE GREATERTHAN ENDOFELEMENT 
%token OSRLSTART OSRLATTRIBUTETEXT OSRLEND
%token GENERALSTART GENERALEND 
%token SYSTEMSTART  SYSTEMEND 
%token SERVICESTART SERVICEEND 
%token JOBSTART JOBEND 
%token SERVICEURISTARTANDEND  SERVICEURISTART SERVICEURIEND
%token SERVICENAMESTARTANDEND SERVICENAMESTART SERVICENAMEEND
%token INSTANCENAMESTARTANDEND INSTANCENAMESTART INSTANCENAMEEND
%token JOBIDSTARTANDEND JOBIDSTART JOBIDEND
%token TIMINGINFORMATIONSTART  TIMINGINFORMATIONEND
%token TIMESTARTANDEND TIMESTART TIMEEND
%token OPTIMIZATIONSTART OPTIMIZATIONEND
%token SOLUTIONSTART SOLUTIONEND  VALUESSTART VALUESEND 
%token DUALVALUESSTART DUALVALUESEND  
%token VARIABLESSTART VARIABLESEND VARSTART VAREND 
%token OBJECTIVESSTART OBJECTIVESEND OBJSTART OBJEND 
%token CONSTRAINTSSTART CONSTRAINTSEND CONSTART CONEND
%token STATUSSTART STATUSEND GENERALSTATUSSTART GENERALSTATUSEND 
%token MESSAGESTART MESSAGEEND MESSAGESTARTANDEND OTHERSTART OTHEREND


%token NUMBEROFTIMESATT
%token NUMBEROFSOLUTIONSATT NUMBEROFVARIABLESATT NUMBEROFCONSTRAINTSATT NUMBEROFOBJECTIVESATT
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT
%token TARGETOBJECTIVEIDXATT IDXATT TYPEATT DESCRIPTIONATT NAMEATT

%token DUMMY

%%


osrldoc: osrlstart generalElement systemElement serviceElement jobElement 
         optimizationElement OSRLEND ;

osrlstart:	OSRLSTART  GREATERTHAN  
			| OSRLSTART OSRLATTRIBUTETEXT GREATERTHAN ;



generalElement: | GENERALSTART generalStatus serviceURI serviceName instanceName jobID headerMessage GENERALEND ; 
   
generalStatus: GENERALSTATUSSTART anotherGeneralStatusATT GREATERTHAN GENERALSTATUSEND {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");}
| GENERALSTATUSSTART anotherGeneralStatusATT ENDOFELEMENT {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;};

anotherGeneralStatusATT: generalstatusatt
	| anotherGeneralStatusATT generalstatusatt;

generalstatusatt: TYPEATT ATTRIBUTETEXT quote  { osresult->setGeneralStatusType($2);  free($2);  ; parserData->generalStatusTypePresent = true;}   
		|  DESCRIPTIONATT ATTRIBUTETEXT  quote {  osresult->setGeneralStatusDescription($2);    free($2);}    


serviceURI: 
| SERVICEURISTARTANDEND
| SERVICEURISTART ELEMENTTEXT SERVICEURIEND {osresult->setServiceURI( $2); free($2); parserData->errorText = NULL;}
| SERVICEURISTART SERVICEURIEND ;


serviceName: 
| SERVICENAMESTARTANDEND
| SERVICENAMESTART ELEMENTTEXT SERVICENAMEEND {osresult->setServiceName( $2);  free($2);   parserData->errorText = NULL;}
| SERVICENAMESTART SERVICENAMEEND ;

instanceName: 
| INSTANCENAMESTARTANDEND
| INSTANCENAMESTART ELEMENTTEXT INSTANCENAMEEND {osresult->setInstanceName( $2) ;  free($2);   parserData->errorText = NULL;}
| INSTANCENAMESTART INSTANCENAMEEND ;

jobID: 
| JOBIDSTARTANDEND
| JOBIDSTART ELEMENTTEXT JOBIDEND {osresult->setJobID( $2); free($2);  parserData->errorText = NULL;}
| JOBIDSTART JOBIDEND ;

headerMessage: 
| MESSAGESTARTANDEND
| MESSAGESTART ELEMENTTEXT MESSAGEEND {osresult->setGeneralMessage( $2);  free($2);  parserData->errorText = NULL;}
| MESSAGESTART MESSAGEEND ;

systemElement: | SYSTEMSTART SYSTEMEND {printf("processed systemElement");};

serviceElement: | SERVICESTART SERVICEEND {printf("processed serviceElement");};

jobElement: | JOBSTART {printf("processed JOBSTART");} timingInformation JOBEND;

timingInformation:
| TIMINGINFORMATIONSTART  {printf("processed TIMINGINFORMATIONSTART");} numberoftimes timingContent;

numberoftimes: {printf("processing numberOfTimes");} NUMBEROFTIMESATT QUOTE INTEGER QUOTE 
{
};

timingContent: ENDOFELEMENT | GREATERTHAN listOfTimes TIMINGINFORMATIONEND;

listOfTimes: | time listOfTimes
{
};

time: TIMESTARTANDEND
    | TIMESTART timeAttList timeValue TIMEEND;

timeAttList: timeAtt timeAttList;

timeAtt: | timeType timeCategory timeUnit timeDescription;

timeType: ;

timeCategory:;

timeUnit: ;

timeDescription: ;

timeValue:
  DOUBLE  {/*osresult->setTime( $2)*/; }
| INTEGER {/*osresult->setTime( $2)*/; };

optimizationElement: | OPTIMIZATIONSTART optimizationContent OPTIMIZATIONEND;

optimizationContent:   anotherOptATT
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
	| anotherOptATT  optatt  ;

optatt:   optnumsolatt    quote
		| optnumvaratt   quote          
		| optnumconatt  quote
		| optnumobjatt   quote
		;


optnumsolatt:   NUMBEROFSOLUTIONSATT quote INTEGER   { parserData->numberOfSolutions = $3; osresult->setSolutionNumber($3);} ;
   	
optnumvaratt: NUMBEROFVARIABLESATT quote INTEGER  {parserData->numberOfVariables = $3; osresult->setVariableNumber($3); } ; 
	
optnumconatt: NUMBEROFCONSTRAINTSATT quote INTEGER   {parserData->numberOfConstraints = $3; osresult->setConstraintNumber($3);}  ;

optnumobjatt: NUMBEROFOBJECTIVESATT quote INTEGER   {parserData->numberOfObjectives = $3; osresult->setObjectiveNumber($3);}  ;
	


solution:  
| anothersolution   
| solution anothersolution  


anothersolution: SOLUTIONSTART targetObjectiveIDXATT GREATERTHAN status message variables objectives  constraints  otherSolution   {parserData->solutionIdx++;};


targetObjectiveIDXATT: 
| TARGETOBJECTIVEIDXATT quote INTEGER quote {if($3 >= 0) osrlerror(NULL, NULL, NULL, "target objective index must be negative");
*(parserData->objectiveIdx + parserData->solutionIdx) = $3;};

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:  TYPEATT ATTRIBUTETEXT  quote  {parserData->statusType = $2; parserData->statusTypePresent = true; free($2);}  
		|  DESCRIPTIONATT ATTRIBUTETEXT quote  {parserData->statusDescription = $2;  free($2);}  ;

message:
| MESSAGESTART ELEMENTTEXT MESSAGEEND
| MESSAGESTART MESSAGEEND;

variables:
| VARIABLESSTART GREATERTHAN VALUESSTART  numberOfVarATT GREATERTHAN var VALUESEND 
 otherVariables VARIABLESEND;
 
numberOfVarATT: NUMBEROFVARATT quote INTEGER quote ; 

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
   // parserData->numberOfOtherVariableResults++;
	parserData->otherVarStruct = new OtherVariableResultStruct(); 
	parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];} anotherotherVarATT GREATERTHAN {if(parserData->otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	parserData->otherNamePresent = false;  
	}  othervar { if(parserData->otherVarStruct->numberOfVar <= 0) osrlerror(NULL, NULL,  parserData, "must specify the number of varaibles") ;} OTHEREND {parserData->otherVarVec.push_back( parserData->otherVarStruct); parserData->numberOfOtherVariableResults++; };
 
othervar: anotherothervar
| othervar anotherothervar;

anotherothervar: VARSTART anIDXATT  GREATERTHAN ELEMENTTEXT  VAREND { 
std::ostringstream outStr;
outStr << $4;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
free($4); parserData->errorText = NULL;
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

 
anotherotherVarATT:  
	|  otheratt
	|  anotherotherVarATT otheratt  ; 

otheratt:  NAMEATT ATTRIBUTETEXT quote  { parserData->otherNamePresent = true; parserData->otherVarStruct->name = $2;  free($2);}
		| DESCRIPTIONATT ATTRIBUTETEXT  quote {   parserData->otherVarStruct->description = $2;  free($2);}   
		| NUMBEROFVARATT quote INTEGER quote {parserData->otherVarStruct->numberOfVar = $3;};


objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART  numberOfObjATT GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND;

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote;

obj: 
| anotherobj
| obj anotherobj;

anotherobj: OBJSTART anIDXATT GREATERTHAN DOUBLE OBJEND { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;
}
| OBJSTART anIDXATT GREATERTHAN INTEGER OBJEND { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;};


constraints:
| CONSTRAINTSSTART GREATERTHAN DUALVALUESSTART numberOfConATT
{
			if( parserData->numberOfConstraints > 0){
				parserData->dualSolution = new double*[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
}
 GREATERTHAN con DUALVALUESEND otherConstraints CONSTRAINTSEND;
 
 
numberOfConATT: NUMBEROFCONATT quote INTEGER quote;

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
| DUMMY SOLUTIONEND  ;





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
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osrllex_destroy( scanner);
	throw ErrorClass( error);
} //end osrlerror

void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData) throw(ErrorClass){
	try{
		osrl_scan_string( parsestring, scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData) != 0) {
			//osrllex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSrL");
		 }
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult

