/* $Id$ */
/** @file parseosrl.y
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.0, 19/07/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
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
void osrl_empty_vectors( OSrLParserData* parserData);


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
%token NUMBEROFOTHERSOLUTIONRESULTSATT NUMBEROFRECORDSATT 
%token OTHERSOLUTIONRESULTSSTART OTHERSOLUTIONRESULTSEND
%token OTHERSOLUTIONRESULTSTART  OTHERSOLUTIONRESULTEND
%token RECORDSTART RECORDEND


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
   
generalStatus: GENERALSTATUSSTART anotherGeneralStatusATT GREATERTHAN GENERALSTATUSEND {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for generalStatus element");}
| GENERALSTATUSSTART anotherGeneralStatusATT ENDOFELEMENT {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;};

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
{	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = $3;
	parserData->ivar = 0;
};

timingContent: ENDOFELEMENT | GREATERTHAN listOfTimes TIMINGINFORMATIONEND;

listOfTimes: | listOfTimes time;

time: TIMESTARTANDEND
    | TIMESTART timeAttList GREATERTHAN timeValue TIMEEND
      {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, parserData, "Too many time measurements");
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

optimizationElement: | OPTIMIZATIONSTART optimizationContent OPTIMIZATIONEND;

optimizationContent:   anotherOptATT  optend ;


optend:   ENDOFELEMENT 
		| GREATERTHAN  solution ;

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


anothersolution: SOLUTIONSTART {parserData->numberOfVar = 0;  parserData->numberOfCon = 0;  parserData->numberOfObj = 0;} targetObjectiveIDXATT GREATERTHAN status message variables objectives  constraints  otherSolutionResults solutionEnd
   {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   };

targetObjectiveIDXATT: 
| TARGETOBJECTIVEIDXATT quote INTEGER quote {
	if($3 >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3);
 };

status: STATUSSTART anotherStatusATT GREATERTHAN  STATUSEND {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
| STATUSSTART anotherStatusATT ENDOFELEMENT {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);};


anotherStatusATT: statusatt
	| anotherStatusATT statusatt  ;

statusatt:     TYPEATT ATTRIBUTETEXT quote  {parserData->statusType = $2; parserData->statusTypePresent = true; free($2);}  
 |        EMPTYTYPEATT                      {parserData->statusType = ""; parserData->statusTypePresent = true;}  
 |      DESCRIPTIONATT ATTRIBUTETEXT quote  {parserData->statusDescription = $2;  free($2);}  
 | EMPTYDESCRIPTIONATT                      {parserData->statusDescription = "";}  ;

message:
| MESSAGESTART ELEMENTTEXT MESSAGEEND 
	{/*osresult->optimization->solution[parserData->solutionIdx]->message = $2; */
		osresult->setSolutionMessage(parserData->solutionIdx, $2); free($2);
	}
| MESSAGESTART MESSAGEEND
	{/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	}
;

variables:
| VARIABLESSTART numberOfOtherVariableResults GREATERTHAN VALUESSTART numberOfVarATT 
  GREATERTHAN var VALUESEND otherVariables VARIABLESEND
  {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  };

numberOfOtherVariableResults:
| NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
	{  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	}
;

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
	{
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = $3;
	}
; 

var:  anothervar
| var anothervar;

anothervar: VARSTART aVARIDXATT GREATERTHAN DoubleOrInt VAREND; 

DoubleOrInt: 
   INTEGER {parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  
   }
   
  | DOUBLE {parserData->tempVal = $1; 
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair); 
  };
  
  
aVARIDXATT: IDXATT INTEGER quote { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;};
  


otherVariables:
| otherVariables otherVariableResult;

otherVariableResult: otherVariableStart otherVariableATTlist GREATERTHAN othervarlist OTHEREND
	{ 	 
		
		parserData->otherVarVec.push_back( parserData->otherVarStruct); 
		parserData->numberOfOtherVariableResults++; 
		parserData->otherNamePresent = false;	
		
	
		osresult->setAnOtherVariableResultSparse(parserData->solutionIdx, parserData->iOther,  parserData->otherVarStruct->name,
			parserData->otherVarStruct->value, parserData->otherVarStruct->description, parserData->otherVarStruct->otherVarIndex,
			parserData->otherVarStruct->otherVarText, parserData->otherVarStruct->numberOfVar );
							
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
				
	};

otherVariableStart: OTHERSTART 
	{  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	}; 

otherVariableATTlist: 
	{	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	}  
	| othervariableATT otherVariableATTlist;

othervariableATT: numberOfOtherVarATT | otherVarValueATT | otherVarNameATT | otherVarDescriptionATT;
  
numberOfOtherVarATT: NUMBEROFVARATT quote INTEGER quote 
{
	parserData->otherVarStruct->numberOfVar = $3;
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
}; 

otherVarValueATT: 
  EMPTYVALUEATT {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
}
  |    VALUEATT ATTRIBUTETEXT quote {parserData->tmpOtherValue=$2; parserData->otherVarStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free($2);}
;

otherVarNameATT: 
  EMPTYNAMEATT 
{ 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{
parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherVarStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
};

otherVarDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
{
parserData->tmpOtherDescription=$2; parserData->otherVarStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
};




othervarlist: 
| othervar othervarlist;

othervar: othervarstart anIDXATT  GREATERTHAN ElementValue VAREND {  
parserData->otherVarStruct->otherVarText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
parserData->outStr.str("");
parserData->otherVarStruct->otherVarIndex[parserData->kounter] =  parserData->ivar;
parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar)
if (parserData->kounter == osresult->getAnOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many variables"); 
if (parserData->numberOfVariables > 0 && (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) ) 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of variables");
   

parserData->kounter++;
};

ElementValue: 
    ELEMENTTEXT  { parserData->outStr << $1; free($1); }
  | INTEGER      { parserData->outStr << $1; /*free($1);*/ }
  | DOUBLE       { parserData->outStr << $1; /*free($1);*/ };
  
othervarstart: VARSTART 
	{	if(parserData->otherVarStruct->numberOfVar <= 0) 
			osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}; 

objectives:
| OBJECTIVESSTART GREATERTHAN VALUESSTART  numberOfObjATT GREATERTHAN obj VALUESEND otherObjectives OBJECTIVESEND{
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
};

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote{
			parserData->numberOfObj = $3;
} ;

obj: 
| obj anotherobj;

anotherobj: OBJSTART anOBJIDXATT GREATERTHAN DOUBLE OBJEND { 

	parserData->objValPair->value = $4;
	parserData->objVals.push_back( parserData->objValPair);

}
| OBJSTART anOBJIDXATT GREATERTHAN INTEGER OBJEND {


 	parserData->objValPair->value = $4;
	parserData->objVals.push_back( parserData->objValPair);
  };


anOBJIDXATT: IDXATT INTEGER quote { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = $2;   };


constraints:
| CONSTRAINTSSTART GREATERTHAN DUALVALUESSTART numberOfConATT
{

			
			
}
 GREATERTHAN con DUALVALUESEND otherConstraints CONSTRAINTSEND {
 
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}
 };
 
 
numberOfConATT: NUMBEROFCONATT quote INTEGER quote
{
	parserData->numberOfCon = $3;

};

con: anothercon
| con anothercon;

anothercon: CONSTART aCONIDXATT GREATERTHAN DOUBLE CONEND { 
	
	parserData->dualValPair->value = $4;
	parserData->dualVals.push_back( parserData->dualValPair); 
	
	
	}
|  CONSTART aCONIDXATT GREATERTHAN INTEGER CONEND { 
	
	parserData->dualValPair->value = $4;
	parserData->dualVals.push_back( parserData->dualValPair); 
	
	} ;


aCONIDXATT: IDXATT INTEGER quote { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = $2;   };

anIDXATT: IDXATT INTEGER quote {parserData->ivar = $2;    };



otherObjectives:
| DUMMY;

otherConstraints:
| DUMMY;

otherSolutionResults: 
| OTHERSOLUTIONRESULTSSTART numberOfOtherSolutionResults GREATERTHAN otherSolutionResultList OTHERSOLUTIONRESULTSEND
{
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
};

numberOfOtherSolutionResults: NUMBEROFOTHERSOLUTIONRESULTSATT QUOTE INTEGER  
{	
	int temp;
	temp = $3;
	if (temp < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults != NULL)
		osrlerror(NULL, NULL, parserData, "otherSolutionResults previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults = new OtherSolutionResults();	
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults = temp;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult = new OtherSolutionResult*[ temp];
	if (temp > 0)
		for(int i = 0; i < temp; i++) 	
			osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[i] = new OtherSolutionResult();
parserData->iOther = 0; // this will index the number of otherSolutionResult objects
} QUOTE;
    
otherSolutionResultList: 

 | otherSolutionResultList anotherSolutionResult;

anotherSolutionResult: OTHERSOLUTIONRESULTSTART  anotherSolutionResultAttList GREATERTHAN recordList OTHERSOLUTIONRESULTEND
{
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords)
	osrlerror(NULL, NULL, parserData, "fewer record elements present than given in numberOfRecords attribute");

parserData->iOther++;


};

anotherSolutionResultAttList: 
   | anotherSolutionResultAttList {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
} anotherSolutionResultAtt ;

anotherSolutionResultAtt: numberOfRecords | anotherSolutionResultNameATT | anotherSolutionResultCategoryATT | anotherSolutionDescriptionATT;

numberOfRecords: NUMBEROFRECORDSATT QUOTE INTEGER QUOTE 
{	

int temp;
temp = $3;
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of records cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords = temp;





	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record != NULL)
		osrlerror(NULL, NULL, parserData, "record array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record = new std::string[temp];
	parserData->kounter = 0; //this will count the number of records in an otherSolutionResult object
};

anotherSolutionResultNameATT: 
  EMPTYNAMEATT 
{ 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{
	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
};

anotherSolutionResultCategoryATT:
CATEGORYATT ATTRIBUTETEXT QUOTE {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
free($2);}
   | EMPTYCATEGORYATT ;
 
anotherSolutionDescriptionATT:
DESCRIPTIONATT ATTRIBUTETEXT QUOTE {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
free($2);}
   | EMPTYDESCRIPTIONATT ;

recordList: 
  | recordList anotherSolutionRecord;

anotherSolutionRecord: RECORDSTART recordContent
{

if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords)
	osrlerror(NULL, NULL, parserData, "numberOfRecords attribute less than the number of record elements");

osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record[parserData->kounter] = parserData->recordContent;
parserData->kounter++;
};

recordContent: emptyRecord {parserData->recordContent = "";}
    |    ELEMENTTEXT {parserData->recordContent = $1; free($1);} RECORDEND;

emptyRecord: ENDOFELEMENT | GREATERTHAN RECORDEND;


solutionEnd: SOLUTIONEND  {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
};

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
	osrl_empty_vectors( parserData);
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

void osrl_empty_vectors( OSrLParserData* parserData){

    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for( k = 0; k < numOtherVarVec; k++){
    	if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarText != NULL) ) 
			delete[] parserData->otherVarVec[ k]->otherVarText;
		if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarIndex != NULL) ) 
			delete[] parserData->otherVarVec[ k]->otherVarIndex;
			
		if( parserData->otherVarVec[ k]  != NULL) delete parserData->otherVarVec[ k];
    }
  	parserData->otherVarVec.clear(); 
  	
  	int numDualVals =  parserData->dualVals.size();
  	for(k = 0; k < numDualVals; k++){
  		if( parserData->dualVals[ k]  != NULL  ) 
			delete parserData->dualVals[ k];
  	}
  	parserData->dualVals.clear();
  	
  	
   	int numObjVals =  parserData->objVals.size();
  	for(k = 0; k < numObjVals; k++){
  		if( parserData->objVals[ k]  != NULL  ) 
			delete parserData->objVals[ k];
  	}
  	parserData->objVals.clear();
  	
  	
   	int numPrimalVals =  parserData->primalVals.size();
  	for(k = 0; k < numPrimalVals; k++){	
  		if( parserData->primalVals[ k]  != NULL  ) 
			delete parserData->primalVals[ k];
  	}
  	parserData->primalVals.clear();
}//end osrl_empty_vectors

