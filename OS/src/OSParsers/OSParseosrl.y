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




%token QUOTE TWOQUOTES GREATERTHAN ENDOFELEMENT 
%token OSRLSTART OSRLSTARTEMPTY OSRLATTRIBUTETEXT OSRLEND
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
%token NUMBEROFOTHERVARIABLERESULTSATT NUMBEROFOTHEROBJECTIVERESULTSATT NUMBEROFOTHERCONSTRAINTRESULTSATT

%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT TARGETOBJECTIVEIDXATT IDXATT 
%token TYPEATT EMPTYTYPEATT DESCRIPTIONATT EMPTYDESCRIPTIONATT NAMEATT EMPTYNAMEATT 
%token CATEGORYATT EMPTYCATEGORYATT UNITATT EMPTYUNITATT VALUEATT EMPTYVALUEATT

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

generalstatusatt: TYPEATT ATTRIBUTETEXT quote { osresult->setGeneralStatusType($2);  free($2);  ; parserData->generalStatusTypePresent = true;}   
    |        EMPTYTYPEATT                     { osresult->setGeneralStatusType("");               parserData->generalStatusTypePresent = true;}   
    |      DESCRIPTIONATT ATTRIBUTETEXT quote { osresult->setGeneralStatusDescription($2);    free($2);} 
    | EMPTYDESCRIPTIONATT                     { osresult->setGeneralStatusDescription("");}; 


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

systemElement: | SYSTEMSTART SYSTEMEND ;

serviceElement: | SERVICESTART SERVICEEND ;

jobElement: | JOBSTART timingInformation JOBEND;

timingInformation:
| TIMINGINFORMATIONSTART numberoftimes timingContent;

numberoftimes: NUMBEROFTIMESATT QUOTE INTEGER QUOTE 
{	if ($3 < 0) osrlerror(NULL, NULL, NULL, "number of time measurements cannot be negative");
	parserData->numberOfTimes = $3;
	parserData->ivar = 0;
};

timingContent: ENDOFELEMENT | GREATERTHAN listOfTimes TIMINGINFORMATIONEND;

listOfTimes: | listOfTimes time;

time: TIMESTARTANDEND
    | TIMESTART timeAttList GREATERTHAN timeValue TIMEEND
      {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, NULL, "Too many time measurements");
       osresult->addTimingInformation(parserData->timeType, parserData->timeCategory,
                                      parserData->timeUnit, parserData->timeDescription, parserData->timeValue);       
       parserData->ivar++;
       parserData->timeType = "elapsedTime";
       parserData->timeCategory = "total";
       parserData->timeUnit = "second";
       parserData->timeDescription = "";      
      };

timeAttList: | timeAttList timeAtt;

timeAtt: timeType | timeCategory | timeUnit | timeDescription;

timeType: TYPEATT ATTRIBUTETEXT QUOTE {parserData->timeType = $2;  free($2);}
   | EMPTYTYPEATT ;

timeCategory: CATEGORYATT ATTRIBUTETEXT QUOTE {parserData->timeCategory = $2;  free($2);}
   | EMPTYCATEGORYATT ;

timeUnit: UNITATT ATTRIBUTETEXT QUOTE {parserData->timeUnit = $2;   free($2);}
   | EMPTYUNITATT ;

timeDescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE {parserData->timeDescription = $2;  free($2);}
   | EMPTYDESCRIPTIONATT;

timeValue:
  DOUBLE  { parserData->timeValue = $1; }
| INTEGER { parserData->timeValue = $1; };

optimizationElement: | OPTIMIZATIONSTART optimizationContent {printf("\nbefore OPTIMIZATIONEND\n");} OPTIMIZATIONEND;

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
		| GREATERTHAN  solution {printf("\nat optend\n");};

anotherOptATT: 
	| anotherOptATT  optatt  ;

optatt:   optnumsolatt  quote
		| optnumvaratt  quote          
		| optnumconatt  quote
		| optnumobjatt  quote
		;


optnumsolatt: NUMBEROFSOLUTIONSATT quote INTEGER   { parserData->numberOfSolutions = $3; osresult->setSolutionNumber($3);} ;
   	
optnumvaratt: NUMBEROFVARIABLESATT quote INTEGER  {parserData->numberOfVariables = $3; osresult->setVariableNumber($3); } ; 
	
optnumconatt: NUMBEROFCONSTRAINTSATT quote INTEGER   {parserData->numberOfConstraints = $3; osresult->setConstraintNumber($3);}  ;

optnumobjatt: NUMBEROFOBJECTIVESATT quote INTEGER   {parserData->numberOfObjectives = $3; osresult->setObjectiveNumber($3);}  ;
	


solution:  
| solution anothersolution;  


anothersolution: SOLUTIONSTART targetObjectiveIDXATT GREATERTHAN status message variables objectives  constraints  otherSolution
   {printf("\ncompleted solution %d out of %d\n",parserData->solutionIdx,parserData->numberOfSolutions);
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, NULL, "too many solutions"); 
    parserData->solutionIdx++;
   };

targetObjectiveIDXATT: 
| TARGETOBJECTIVEIDXATT quote INTEGER quote {if($3 >= 0) osrlerror(NULL, NULL, NULL, "target objective index must be negative");
*(parserData->objectiveIdx + parserData->solutionIdx) = $3;};

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:     TYPEATT ATTRIBUTETEXT quote  {parserData->statusType = $2; parserData->statusTypePresent = true; free($2);}  
 |        EMPTYTYPEATT                      {parserData->statusType = ""; parserData->statusTypePresent = true;}  
 |      DESCRIPTIONATT ATTRIBUTETEXT quote  {parserData->statusDescription = $2;  free($2);}  
 | EMPTYDESCRIPTIONATT                      {parserData->statusDescription = "";}  ;

message:
| MESSAGESTART ELEMENTTEXT MESSAGEEND 
	{osresult->optimization->solution[parserData->solutionIdx]->message = $2; free($2);}
| MESSAGESTART MESSAGEEND
	{osresult->optimization->solution[parserData->solutionIdx]->message = "";}
;

variables:
| VARIABLESSTART numberOfOtherVariableResults GREATERTHAN VALUESSTART numberOfVarATT 
  GREATERTHAN var VALUESEND otherVariables VARIABLESEND;

numberOfOtherVariableResults: { parserData->kounter = 0;}
| NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
	{  osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
	/*osresult->optimization->solution[parserData->solutionIdx]->variables->numberOfOtherVariableResults = $3*/;
	 parserData->kounter = 0;
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	}
;

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
	{osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	 /*osresult->optimization->solution[parserData->solutionIdx]->variables->values->numberOfVar = $3;*/
	}
; 

var:  anothervar
| var anothervar;

anothervar: VARSTART anIDXATT GREATERTHAN DoubleOrInt VAREND
 {
   if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->values->numberOfVar)
        osrlerror(NULL, NULL, NULL, "too many variables"); 
        
	if (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) 
	    osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	 
	    
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->ivar ) = parserData->tempVal;
	osresult->optimization->solution[parserData->solutionIdx]->variables->values->var.push_back(new VarValue());
	osresult->optimization->solution[parserData->solutionIdx]->variables->values->var[parserData->kounter]->idx   = parserData->ivar;
	osresult->optimization->solution[parserData->solutionIdx]->variables->values->var[parserData->kounter]->value = parserData->tempVal;
	
	
    parserData->kounter++;
}; 

DoubleOrInt: 
   INTEGER {parserData->tempVal = $1;}
  | DOUBLE {parserData->tempVal = $1;};


otherVariables:
| otherVariables otherVariableResult;

otherVariableResult: otherVariableStart otherVariableATTlist GREATERTHAN othervarlist OTHEREND
	{ 	 
		
		parserData->otherVarVec.push_back( parserData->otherVarStruct); 
		parserData->numberOfOtherVariableResults++; 
		parserData->otherNamePresent = false;	
		
		
		osresult->setAnOtherVariableResult(parserData->solutionIdx, parserData->iOther,  parserData->otherVarStruct->name,
			parserData->otherVarStruct->description, parserData->otherVarStruct->otherVarIndex, parserData->otherVarStruct->otherVarText,
			parserData->otherVarStruct->numberOfVar );
			
			
		std::cout  << "Other Name = " << parserData->otherVarStruct->name << std::endl;
		std::cout  << "Description  = " << parserData->otherVarStruct->description << std::endl;

		
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			

		
		
	};

otherVariableStart: OTHERSTART 
	{  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		parserData->otherVarStruct->otherVarText  = new std::string[parserData->numberOfVariables];	 
		parserData->otherVarStruct->otherVarIndex = new int[parserData->numberOfVariables];	 
		parserData->kounter = 0;
	}; 

otherVariableATTlist: 
	{	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	}  
	| othervariableATT otherVariableATTlist;

othervariableATT: numberOfOtherVarATT | otherVarValueATT | otherVarNameATT | otherVarDescriptionATT;
  
numberOfOtherVarATT: NUMBEROFVARATT quote INTEGER quote 
{parserData->otherVarStruct->numberOfVar = $3;
 osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
}; 

otherVarValueATT: 
  EMPTYVALUEATT                     {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";}
  |    VALUEATT ATTRIBUTETEXT quote {printf("\nset tmpOtherValue: %s\n",$2); parserData->tmpOtherValue=$2; parserData->otherVarStruct->value = $2;  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; free($2);}
;

otherVarNameATT: 
  EMPTYNAMEATT 
{ parserData->tmpOtherName=""; parserData->otherNamePresent = true; parserData->otherVarStruct->name = "";
 // osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{printf("\nset tmpOtherName: %s\n",$2);  parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherVarStruct->name = $2;  free($2);
 // osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;
};

otherVarDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
{printf("\nset tmpOtherDescription: %s\n",$2);  parserData->tmpOtherDescription=$2; parserData->otherVarStruct->description = $2;  free($2);
  //osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;
};




othervarlist: 
| othervar othervarlist;

othervar: othervarstart anIDXATT  GREATERTHAN ElementValue VAREND {  
parserData->otherVarStruct->otherVarText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
parserData->outStr.str("");
parserData->otherVarStruct->otherVarIndex[parserData->kounter] =  parserData->ivar;
parserData->errorText = NULL;
if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar)
    osrlerror(NULL, NULL, NULL, "too many variables"); 
if (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) 
    osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
   
//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->var.push_back(new OtherVarResult());
//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->var[parserData->kounter]->idx   = parserData->ivar;
//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->var[parserData->kounter]->value = parserData->tempVal;



parserData->kounter++;
};

ElementValue: 
    ELEMENTTEXT  {/*std::cout << "FOUND OTHER ELEMENT TEXT"  << std::endl;*/  parserData->outStr << $1; free($1); }
  | INTEGER      {/*std::cout << "FOUND OTHER ELEMENT INTEGER"  << std::endl;*/  parserData->outStr << $1; /*free($1);*/ }
  | DOUBLE       {/*std::cout << "FOUND OTHER ELEMENT DOUBLE"  << std::endl;*/ parserData->outStr << $1; /*free($1);*/ };
  
othervarstart: VARSTART 
	{	if(parserData->otherVarStruct->numberOfVar <= 0) 
			osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}; 

objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART  numberOfObjATT GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND;

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote ;

obj: 
| obj anotherobj;

anotherobj: OBJSTART anIDXATT GREATERTHAN DOUBLE OBJEND { /* *( parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = $4;*/
}
| OBJSTART anIDXATT GREATERTHAN INTEGER OBJEND {/*  *(parserData->objectiveValues[parserData->solutionIdx] +  (parserData->kounter + parserData->numberOfObjectives)) = $4; */};


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




anIDXATT: IDXATT INTEGER quote {parserData->ivar = $2;};





otherObjectives:
| DUMMY;

otherConstraints:
| DUMMY;

otherSolution: SOLUTIONEND {printf("\nprocessed SOLUTIONEND\n");}
| DUMMY SOLUTIONEND  {printf("\nprocessed SOLUTIONEND\n");};





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

