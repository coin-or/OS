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
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE

%token QUOTE TWOQUOTES GREATERTHAN ENDOFELEMENT 

%token NUMBEROFCONATT NUMBEROFCONSTRAINTSATT NUMBEROFITEMSATT  
%token NUMBEROFOBJATT NUMBEROFOBJECTIVESATT
%token NUMBEROFOTHERCONSTRAINTRESULTSATT NUMBEROFOTHEROBJECTIVERESULTSATT 
%token NUMBEROFOTHERRESULTSATT NUMBEROFOTHERSOLUTIONRESULTSATT 
%token NUMBEROFOTHERVARIABLERESULTSATT NUMBEROFSOLUTIONSATT 
%token NUMBEROFSOLVEROUTPUTSATT NUMBEROFSUBSTATUSESATT NUMBEROFTIMESATT 
%token NUMBEROFVARATT NUMBEROFVARIABLESATT 

%token TARGETOBJECTIVEIDXATT IDXATT 

%token CATEGORYATT EMPTYCATEGORYATT DESCRIPTIONATT EMPTYDESCRIPTIONATT 
%token NAMEATT EMPTYNAMEATT TYPEATT EMPTYTYPEATT 
%token UNITATT EMPTYUNITATT VALUEATT EMPTYVALUEATT
%token WEIGHTEDOBJECTIVESATT EMPTYWEIGHTEDOBJECTIVESATT

%token OSRLSTART OSRLSTARTEMPTY OSRLATTRIBUTETEXT OSRLEND
%token GENERALSTART GENERALEND 
%token SYSTEMSTART  SYSTEMEND 
%token SERVICESTART SERVICEEND 
%token JOBSTART JOBEND 
%token OPTIMIZATIONSTART OPTIMIZATIONEND

%token ITEMSTART ITEMEND ITEMSTARTANDEND ITEMEMPTY

%token ACTUALSTARTTIMESTART ACTUALSTARTTIMEEND
%token AVAILABLECPUNUMBERSTART AVAILABLECPUNUMBEREND
%token AVAILABLECPUSPEEDSTART AVAILABLECPUSPEEDEND
%token AVAILABLEDISKSPACESTART AVAILABLEDISKSPACEEND
%token AVAILABLEMEMORYSTART AVAILABLEMEMORYEND
%token BASISSTATUSSTART BASISSTATUSEND
%token BASSTATUSSTART BASSTATUSEND
%token CONSTART CONEND
%token CONSTRAINTSSTART CONSTRAINTSEND 
%token CURRENTJOBCOUNTSTART CURRENTJOBCOUNTEND
%token CURRENTSTATESTART CURRENTSTATEEND
%token DUALVALUESSTART DUALVALUESEND  
%token ENDTIMESTART ENDTIMEEND
%token GENERALSTATUSSTART GENERALSTATUSEND 
%token GENERALSUBSTATUSSTART GENERALSUBSTATUSEND 
%token INSTANCENAMESTART INSTANCENAMEEND
%token JOBIDSTART JOBIDEND
%token MESSAGESTART MESSAGEEND 
%token OBJSTART OBJEND 
%token OBJECTIVESSTART OBJECTIVESEND
%token OPTIMIZATIONSOLUTIONSTATUSSTART OPTIMIZATIONSOLUTIONSTATUSEND
%token OPTIMIZATIONSOLUTIONSUBSTATUSSTART  OPTIMIZATIONSOLUTIONSUBSTATUSEND 
%token OTHERSTART OTHEREND
%token OTHERRESULTSSTART OTHERRESULTSEND
%token OTHERSOLUTIONRESULTSTART  OTHERSOLUTIONRESULTEND
%token OTHERSOLUTIONRESULTSSTART OTHERSOLUTIONRESULTSEND
%token OTHERSOLVEROUTPUTSTART OTHERSOLVEROUTPUTEND
%token SCHEDULEDSTARTTIMESTART SCHEDULEDSTARTTIMEEND
%token SERVICENAMESTART SERVICENAMEEND
%token SERVICEURISTART  SERVICEURIEND
%token SERVICEUTILIZATIONSTART SERVICEUTILIZATIONEND
%token SOLUTIONSTART SOLUTIONEND  
%token SOLVERINVOKEDSTART SOLVERINVOKEDEND
%token SOLVEROUTPUTSTART SOLVEROUTPUTEND
%token STATUSSTART STATUSEND 
%token SUBMITTIMESTART SUBMITTIMEEND
%token SUBSTATUSSTART SUBSTATUSEND
%token SYSTEMINFORMATIONSTART SYSTEMINFORMATIONEND
%token TIMESTART TIMEEND
%token TIMESERVICESTARTEDSTART TIMESERVICESTARTEDEND
%token TIMESTAMPSTART TIMESTAMPEND
%token TIMINGINFORMATIONSTART  TIMINGINFORMATIONEND
%token TOTALJOBSSOFARSTART TOTALJOBSSOFAREND
%token USEDCPUNUMBERSTART USEDCPUNUMBEREND
%token USEDCPUSPEEDSTART USEDCPUSPEEDEND
%token USEDDISKSPACESTART USEDDISKSPACEEND
%token USEDMEMORYSTART USEDMEMORYEND
%token VALUESSTART VALUESEND 
%token VALUESSTRINGSTART VALUESSTRINGEND
%token VARSTART VAREND 
%token VARIABLESSTART VARIABLESEND 

%token DUMMY

%%


osrldoc: osrlstart generalElement systemElement serviceElement jobElement optimizationElement OSRLEND;

osrlstart: OSRLSTART GREATERTHAN  
         | OSRLSTART OSRLATTRIBUTETEXT GREATERTHAN;

generalElement: | GENERALSTART ENDOFELEMENT
                | GENERALSTART GREATERTHAN generalContent GENERALEND; 

generalContent: | generalContent generalChild;

generalChild: 
	generalStatus
  | generalMessage
  | serviceURI 
  | serviceName 
  | instanceName 
  | jobID 
  | solverInvoked 
  | timeStamp 
  | generalOtherResults
  ;
              
generalStatus: generalStatusStart generalStatusAttributes generalStatusContent;

generalStatusStart: GENERALSTATUSSTART
	{	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		osresult->general->generalStatus = new GeneralStatus();
		std::cout << "allocated generalStatus" << std::endl;
		parserData->generalStatusPresent = true;
		parserData->generalStatusTypePresent = false;
		parserData->generalStatusDescriptionPresent = false;
		parserData->generalStatusNumberOfPresent = false;
	};

generalStatusAttributes: generalStatusAttList
	{	if (!parserData->generalStatusTypePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	};

generalStatusAttList: generalStatusATT | generalStatusAttList generalStatusATT;

generalStatusATT: 
    generalStatusTypeATT 
	{   if (parserData->generalStatusTypePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
	    parserData->generalStatusTypePresent = true;
	    if ((parserData->tempStr != "error"  ) &&
	        (parserData->tempStr != "warning") && 
	        (parserData->tempStr != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not matched any legal value");
		osresult->setGeneralStatusType(parserData->tempStr); 
	}
  | generalStatusDescriptionATT 
	{   if (parserData->generalStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->generalStatusDescriptionPresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	}
  | generalStatusNumberOfATT;

generalStatusTypeATT: TYPEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}   
    |            EMPTYTYPEATT                     { parserData->tempStr = "";          };

generalStatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
    |                   EMPTYDESCRIPTIONATT                     { parserData->tempStr = "";          };

generalStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->generalStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->generalStatusNumberOfPresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses($3);
	parserData->numberOf = $3;
};


generalStatusContent: 
	generalStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
  | generalStatusBody
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	}
;

generalStatusEmpty: GREATERTHAN GENERALSTATUSEND | ENDOFELEMENT; 

generalStatusBody: GREATERTHAN generalSubstatusSEQ GENERALSTATUSEND;

generalSubstatusSEQ: generalSubstatus | generalSubstatusSEQ generalSubstatus;

generalSubstatus: generalSubstatusStart generalSubstatusAttList generalSubstatusEnd
{	if (!parserData->generalSubstatusNamePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
};	

generalSubstatusStart: SUBSTATUSSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
};
		
generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: generalSubstatusNameATT | generalSubstatusDescriptionATT
{	if (parserData->generalSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->generalSubstatusDescriptionPresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter,parserData->tempStr);
}; 

generalSubstatusNameATT: NAMEATT ATTRIBUTETEXT QUOTE 
{	if (parserData->generalSubstatusNamePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
	parserData->generalSubstatusNamePresent = true;
	osresult->setGeneralSubstatusName(parserData->kounter,$2);
	
}; 

generalSubstatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{	parserData->tempStr = $2;
}
| EMPTYDESCRIPTIONATT
{	parserData->tempStr = "";
}
; 

generalSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


generalMessage: generalMessageStart generalMessageContent;

generalMessageStart: MESSAGESTART
	{	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	};

generalMessageContent:
	GREATERTHAN ELEMENTTEXT MESSAGEEND 
		{osresult->setGeneralMessage($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN MESSAGEEND 
  | ENDOFELEMENT;

serviceURI: serviceURIStart serviceURIContent;

serviceURIStart: SERVICEURISTART
	{	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	};

serviceURIContent: 
	GREATERTHAN ELEMENTTEXT SERVICEURIEND 
		{osresult->setServiceURI($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SERVICEURIEND 
  | ENDOFELEMENT;

serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
	{	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	};

serviceNameContent: 
	GREATERTHAN ELEMENTTEXT SERVICENAMEEND 
		{osresult->setServiceName($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SERVICENAMEEND 
  | ENDOFELEMENT;

instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
	{	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	};

instanceNameContent:
	GREATERTHAN ELEMENTTEXT INSTANCENAMEEND 
		{osresult->setInstanceName($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN INSTANCENAMEEND 
  | ENDOFELEMENT;

jobID: jobIDStart jobIDContent;

jobIDStart: JOBIDSTART 
	{	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	};
	
jobIDContent:
	GREATERTHAN ELEMENTTEXT JOBIDEND 
		{osresult->setJobID($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN JOBIDEND 
  | ENDOFELEMENT;

solverInvoked: solverInvokedStart solverInvokedContent;

solverInvokedStart: SOLVERINVOKEDSTART 
	{	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	};

solverInvokedContent: 
	GREATERTHAN ELEMENTTEXT SOLVERINVOKEDEND 
		{osresult->setSolverInvoked($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SOLVERINVOKEDEND 
  | ENDOFELEMENT;

timeStamp: timeStampStart timeStampContent;
  
timeStampStart: TIMESTAMPSTART 
	{	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	};

timeStampContent: 
	GREATERTHAN ELEMENTTEXT TIMESTAMPEND 
		{osresult->setTimeStamp($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN TIMESTAMPEND 
  | ENDOFELEMENT;

generalOtherResults: generalOtherResultsStart generalOtherResultsAttList generalOtherResultsContent;

generalOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	};

generalOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote 
{	osresult->setNumberOfOtherGeneralResults($3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
};

generalOtherResultsContent: 
	generalOtherResultsEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}  | generalOtherResultsBody
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};
generalOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

generalOtherResultsBody: GREATERTHAN generalOtherResultSEQ OTHERRESULTSEND;

generalOtherResultSEQ: generalOtherResult | generalOtherResultSEQ generalOtherResult; 

generalOtherResult: generalOtherResultStart generalOtherAttList generalOtherEnd
{	if (!parserData->generalOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->generalOtherResultNamePresent = false;
	parserData->generalOtherResultValuePresent = false;
	parserData->generalOtherResultDescriptionPresent = false;
	parserData->kounter++;
};	

generalOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

generalOtherAttList: | generalOtherAttList generalOtherAtt;

generalOtherAtt: 
	generalOtherNameATT
	{	if (parserData->generalOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->generalOtherResultNamePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | generalOtherValueATT
	{	if (parserData->generalOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->generalOtherResultValuePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | generalOtherDescriptionATT
	{	if (parserData->generalOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->generalOtherResultDescriptionPresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

generalOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);};

generalOtherValueATT: VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
|EMPTYVALUEATT {parserData->tempStr = ""}; 

generalOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYDESCRIPTIONATT {parserData->tempStr = ""}; 

generalOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



systemElement: | SYSTEMSTART ENDOFELEMENT
               | SYSTEMSTART GREATERTHAN systemContent SYSTEMEND; 
               
systemContent: | systemContent systemChild; 

systemChild: 
	systemInformation 
  | availableDiskSpace 
  | availableMemory 
  | availableCPUSpeed
  | availableCPUNumber 
  | systemOtherResults
  ; 

systemInformation: systemInformationStart systemInformationContent;

systemInformationStart:	SYSTEMINFORMATIONSTART 
	{	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	};
	
systemInformationContent:
	GREATERTHAN ELEMENTTEXT SYSTEMINFORMATIONEND  
		{osresult->setSystemInformation($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SYSTEMINFORMATIONEND 
  | ENDOFELEMENT;

availableDiskSpace: availableDiskSpaceStart availableDiskSpaceAttList GREATERTHAN availableDiskSpaceValue 
                    AVAILABLEDISKSPACEEND;

availableDiskSpaceStart: AVAILABLEDISKSPACESTART
	{	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;		
	};

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: availableDiskSpaceUnitATT | availableDiskSpaceDescriptionATT;

availableDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote 
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	osresult->setAvailableDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};

availableDiskSpaceDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setAvailableDiskSpaceDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

availableDiskSpaceValue:
     INTEGER {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;};

availableMemory: availableMemoryStart availableMemoryAttList GREATERTHAN availableMemoryValue 
                 AVAILABLEMEMORYEND;

availableMemoryStart: AVAILABLEMEMORYSTART
	{	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	};

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: availableMemoryUnitATT | availableMemoryDescriptionATT;

availableMemoryUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
	osresult->setAvailableMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};

availableMemoryDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setAvailableMemoryDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

availableMemoryValue:
     INTEGER {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;};

availableCPUSpeed: availableCPUSpeedStart availableCPUSpeedAttList GREATERTHAN availableCPUSpeedValue 
                   AVAILABLECPUSPEEDEND;

availableCPUSpeedStart: AVAILABLECPUSPEEDSTART
	{	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	};

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: availableCPUSpeedUnitATT | availableCPUSpeedDescriptionATT;

availableCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
	osresult->setAvailableCPUSpeedUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};

availableCPUSpeedDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setAvailableCPUSpeedDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

availableCPUSpeedValue:
     INTEGER {osresult->setAvailableCPUSpeedValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableCPUSpeedValue( $1);  parserData->errorText = NULL;};


availableCPUNumber: availableCPUNumberStart availableCPUNumberAttList GREATERTHAN availableCPUNumberValue 
                    AVAILABLECPUNUMBEREND;

availableCPUNumberStart: AVAILABLECPUNUMBERSTART
	{	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	};

availableCPUNumberAttList: | availableCPUNumberDescriptionATT;

availableCPUNumberDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setAvailableCPUNumberDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

availableCPUNumberValue:
     INTEGER {osresult->setAvailableCPUNumberValue( $1);  parserData->errorText = NULL;};


systemOtherResults: systemOtherResultsStart systemOtherResultsAttList systemOtherResultsContent;

systemOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	};

systemOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{	osresult->setNumberOfOtherSystemResults($3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
};

systemOtherResultsContent: 
	systemOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | systemOtherResultsBody
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

systemOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

systemOtherResultsBody: GREATERTHAN systemOtherResultSEQ OTHERRESULTSEND;

systemOtherResultSEQ: systemOtherResult | systemOtherResultSEQ systemOtherResult; 

systemOtherResult: systemOtherResultStart systemOtherAttList systemOtherEnd
{	if (!parserData->systemOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->systemOtherResultNamePresent = false;
	parserData->systemOtherResultValuePresent = false;
	parserData->systemOtherResultDescriptionPresent = false;
	parserData->kounter++;
};	

systemOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

systemOtherAttList: | systemOtherAttList systemOtherAtt;

systemOtherAtt:
	systemOtherNameATT
	{	if (parserData->systemOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->systemOtherResultNamePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | systemOtherValueATT
	{	if (parserData->systemOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->systemOtherResultValuePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | systemOtherDescriptionATT
	{	if (parserData->systemOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->systemOtherResultDescriptionPresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

systemOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

systemOtherValueATT: VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYVALUEATT {parserData->tempStr = ""}; 

systemOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYDESCRIPTIONATT {parserData->tempStr = ""};

systemOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



serviceElement: | SERVICESTART ENDOFELEMENT
                | SERVICESTART GREATERTHAN serviceContent SERVICEEND;
                
serviceContent: | serviceContent serviceChild;
        
serviceChild: 
	currentState 
  | currentJobCount 
  | totalJobsSoFar 
  | timeServiceStarted 
  | serviceUtilization 
  | serviceOtherResults
  ;

currentState: currentStateStart currentStateContent;

currentStateStart: CURRENTSTATESTART 
	{	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	};

currentStateContent: 
	GREATERTHAN ELEMENTTEXT CURRENTSTATEEND 
		{osresult->setCurrentState($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN CURRENTSTATEEND 
  | ENDOFELEMENT;

currentJobCount: currentJobCountStart currentJobCountContent;

currentJobCountStart: CURRENTJOBCOUNTSTART
	{	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	};

currentJobCountContent: 
	GREATERTHAN INTEGER CURRENTJOBCOUNTEND 
		{osresult->setCurrentJobCount($2); /* free($2); */  parserData->errorText = NULL;}
  | GREATERTHAN CURRENTJOBCOUNTEND 
  | ENDOFELEMENT;

totalJobsSoFar: totalJobsSoFarStart totalJobsSoFarContent;

totalJobsSoFarStart: TOTALJOBSSOFARSTART 
	{	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	};

totalJobsSoFarContent:
	GREATERTHAN INTEGER TOTALJOBSSOFAREND 
		{osresult->setTotalJobsSoFar($2); /* free($2); */  parserData->errorText = NULL;}
  | GREATERTHAN TOTALJOBSSOFAREND 
  | ENDOFELEMENT;

timeServiceStarted: timeServiceStartedStart timeServiceStartedContent;

timeServiceStartedStart: TIMESERVICESTARTEDSTART 
	{	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	};

timeServiceStartedContent:
	GREATERTHAN ELEMENTTEXT TIMESERVICESTARTEDEND 
		{osresult->setTimeServiceStarted($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN TIMESERVICESTARTEDEND 
  | ENDOFELEMENT;

serviceUtilization: serviceUtilizationStart serviceUtilizationContent;

serviceUtilizationStart: SERVICEUTILIZATIONSTART 
	{	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	};

serviceUtilizationContent:
	GREATERTHAN aNumber SERVICEUTILIZATIONEND 
		{osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;}
  | GREATERTHAN SERVICEUTILIZATIONEND 
  | ENDOFELEMENT;


serviceOtherResults: serviceOtherResultsStart serviceOtherResultsAttList serviceOtherResultsContent;

serviceOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	};

serviceOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{	osresult->setNumberOfOtherServiceResults($3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
};

serviceOtherResultsContent: 
	serviceOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | serviceOtherResultsBody
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

serviceOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

serviceOtherResultsBody: GREATERTHAN serviceOtherResultSEQ OTHERRESULTSEND;

serviceOtherResultSEQ: serviceOtherResult | serviceOtherResultSEQ serviceOtherResult; 

serviceOtherResult: serviceOtherResultStart serviceOtherAttList serviceOtherEnd
{	if (!parserData->serviceOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->serviceOtherResultNamePresent = false;
	parserData->serviceOtherResultValuePresent = false;
	parserData->serviceOtherResultDescriptionPresent = false;
	parserData->kounter++;
};

serviceOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

serviceOtherAttList: | serviceOtherAttList serviceOtherAtt;

serviceOtherAtt: 
	serviceOtherNameATT 
	{	if (parserData->serviceOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->serviceOtherResultNamePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | serviceOtherValueATT 
	{	if (parserData->serviceOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->serviceOtherResultValuePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | serviceOtherDescriptionATT
	{	if (parserData->serviceOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->serviceOtherResultDescriptionPresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;
  
serviceOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

serviceOtherValueATT: VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYVALUEATT {parserData->tempStr = ""}; 

serviceOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYDESCRIPTIONATT {parserData->tempStr = "";}; 

serviceOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


jobElement: | JOBSTART ENDOFELEMENT
            | JOBSTART GREATERTHAN jobContent JOBEND;
            
jobContent: | jobContent jobChild;

jobChild: 
	jobStatus 
  | submitTime 
  | scheduledStartTime 
  | actualStartTime 
  | endTime 
  | timingInformation 
  | usedDiskSpace 
  | usedMemory 
  | usedCPUSpeed 
  | usedCPUNumber 
  | jobOtherResults
  ;

jobStatus: jobStatusStart jobStatusContent;

jobStatusStart: STATUSSTART 
	{	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	};

jobStatusContent:
	GREATERTHAN ELEMENTTEXT STATUSEND 
		{osresult->setJobStatus($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN STATUSEND 
  | ENDOFELEMENT;

submitTime: submitTimeStart submitTimeContent;

submitTimeStart: SUBMITTIMESTART 
	{	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	};

submitTimeContent:
	GREATERTHAN ELEMENTTEXT SUBMITTIMEEND 
		{osresult->setJobSubmitTime($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SUBMITTIMEEND 
  | ENDOFELEMENT;

scheduledStartTime: scheduledStartTimeStart scheduledStartTimeContent;

scheduledStartTimeStart: SCHEDULEDSTARTTIMESTART 
	{	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	};

scheduledStartTimeContent:
	GREATERTHAN ELEMENTTEXT SCHEDULEDSTARTTIMEEND 
		{osresult->setScheduledStartTime($2); free($2); parserData->errorText = NULL;}
  | GREATERTHAN SCHEDULEDSTARTTIMEEND 
  | ENDOFELEMENT;

actualStartTime: actualStartTimeStart actualStartTimeContent;

actualStartTimeStart: ACTUALSTARTTIMESTART 
	{	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	};

actualStartTimeContent:
	GREATERTHAN ELEMENTTEXT ACTUALSTARTTIMEEND  
		{osresult->setActualStartTime($2); free($2);  parserData->errorText = NULL;}
  | GREATERTHAN ACTUALSTARTTIMEEND 
  | ENDOFELEMENT;

endTime: endTimeStart endTimeContent;

endTimeStart: ENDTIMESTART 
	{	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	};

endTimeContent:
	GREATERTHAN ELEMENTTEXT ENDTIMEEND  
		{osresult->setJobEndTime($2); free($2);  parserData->errorText = NULL;}
  | GREATERTHAN ENDTIMEEND 
  | ENDOFELEMENT;

timingInformation: timingInformationStart numberoftimes timingContent;

timingInformationStart: TIMINGINFORMATIONSTART
	{	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	};

numberoftimes: NUMBEROFTIMESATT QUOTE INTEGER QUOTE 
{	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = $3;
	parserData->ivar = 0;
};

timingContent: ENDOFELEMENT | GREATERTHAN listOfTimes TIMINGINFORMATIONEND;

listOfTimes: | listOfTimes time;

time: TIMESTART timeAttList restOfTimeElement;

timeAttList: | timeAttList timeAtt;

timeAtt: timeType | timeCategory | timeUnit | timeDescription;

timeType: TYPEATT ATTRIBUTETEXT QUOTE {parserData->timeType = $2;  free($2);}
   | EMPTYTYPEATT;

timeCategory: CATEGORYATT ATTRIBUTETEXT QUOTE {parserData->timeCategory = $2;  free($2);}
   | EMPTYCATEGORYATT;

timeUnit: UNITATT ATTRIBUTETEXT QUOTE {parserData->timeUnit = $2;   free($2);}
   | EMPTYUNITATT;

timeDescription: DESCRIPTIONATT ATTRIBUTETEXT QUOTE {parserData->timeDescription = $2;  free($2);}
   | EMPTYDESCRIPTIONATT;

restOfTimeElement: timeEmpty | timeContent;

timeEmpty:  GREATERTHAN TIMEEND  |  ENDOFELEMENT;

timeContent: GREATERTHAN timeValue TIMEEND
      {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, parserData, "Too many time measurements");
       osresult->addTimingInformation(parserData->timeType, parserData->timeCategory,
                                      parserData->timeUnit, parserData->timeDescription, parserData->timeValue);       
       parserData->ivar++;
       parserData->timeType = "elapsedTime";
       parserData->timeCategory = "total";
       parserData->timeUnit = "second";
       parserData->timeDescription = "";      
      }
    | 


timeValue:
  DOUBLE  { parserData->timeValue = $1; }
| INTEGER { parserData->timeValue = $1; };


usedDiskSpace: usedDiskSpaceStart usedDiskSpaceAttList GREATERTHAN usedDiskSpaceValue 
               USEDDISKSPACEEND;

usedDiskSpaceStart: USEDDISKSPACESTART
	{	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
	};

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: usedDiskSpaceUnitATT | usedDiskSpaceDescriptionATT;

usedDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
	osresult->setUsedDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};


usedDiskSpaceDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setUsedDiskSpaceDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

usedDiskSpaceValue:
     INTEGER {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;};

usedMemory: usedMemoryStart usedMemoryAttList GREATERTHAN usedMemoryValue 
            USEDMEMORYEND;

usedMemoryStart: USEDMEMORYSTART
	{	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	};

usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: usedMemoryUnitATT | usedMemoryDescriptionATT;

usedMemoryUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
	osresult->setUsedMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};

usedMemoryDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setUsedMemoryDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

usedMemoryValue:
     INTEGER {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;};


usedCPUSpeed: usedCPUSpeedStart usedCPUSpeedAttList GREATERTHAN usedCPUSpeedValue 
              USEDCPUSPEEDEND;
              
usedCPUSpeedStart: USEDCPUSPEEDSTART
	{	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	};
              

usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: usedCPUSpeedUnitATT | usedCPUSpeedDescriptionATT;

usedCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "usedCPUSpeed unit not recognized");
	osresult->setUsedCPUSpeedUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
};

usedCPUSpeedDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setUsedCPUSpeedDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

usedCPUSpeedValue:
     INTEGER {osresult->setUsedCPUSpeedValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedCPUSpeedValue( $1);  parserData->errorText = NULL;};


usedCPUNumber: usedCPUNumberStart usedCPUNumberAttList GREATERTHAN usedCPUNumberValue 
               USEDCPUNUMBEREND;
               
usedCPUNumberStart: USEDCPUNUMBERSTART               
	{	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	};
               

usedCPUNumberAttList: | usedCPUNumberAttList usedCPUNumberDescriptionATT;

usedCPUNumberDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	{	osresult->setUsedCPUNumberDescription( $2); free($2);  parserData->errorText = NULL;}
| EMPTYDESCRIPTIONATT;

usedCPUNumberValue:
     INTEGER {osresult->setUsedCPUNumberValue( $1);  parserData->errorText = NULL;};



jobOtherResults: jobOtherResultsStart jobOtherResultsAttList jobOtherResultsContent;

jobOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	};

jobOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote 
{	osresult->setNumberOfOtherJobResults($3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
};

jobOtherResultsContent: 
	jobOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | jobOtherResultsBody
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

jobOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

jobOtherResultsBody: GREATERTHAN jobOtherResultSEQ OTHERRESULTSEND;

jobOtherResultSEQ: jobOtherResult | jobOtherResultSEQ jobOtherResult; 

jobOtherResult: jobOtherResultStart jobOtherAttList jobOtherEnd
{	if (!parserData->jobOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->jobOtherResultNamePresent = false;
	parserData->jobOtherResultValuePresent = false;
	parserData->jobOtherResultDescriptionPresent = false;
	parserData->kounter++;
};	

jobOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

jobOtherAttList: | jobOtherAttList jobOtherAtt;

jobOtherAtt: 
	jobOtherNameATT 
 	{	if (parserData->jobOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->jobOtherResultNamePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	}
 | jobOtherValueATT 
	{	if (parserData->jobOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->jobOtherResultValuePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	}
 | jobOtherDescriptionATT
	{	if (parserData->jobOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->jobOtherResultDescriptionPresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

jobOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

jobOtherValueATT: VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYVALUEATT {parserData->tempStr = ""}; 

jobOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
| EMPTYDESCRIPTIONATT {parserData->tempStr = ""};

jobOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


optimizationElement: | OPTIMIZATIONSTART optimizationAttList optimizationBody;

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
	optimizationNumberOfSolutionsATT   quote
  | optimizationNumberOfVariablesATT   quote          
  | optimizationNumberOfConstraintsATT quote
  | optimizationNumberOfObjectivesATT  quote
  ;

optimizationNumberOfSolutionsATT: NUMBEROFSOLUTIONSATT quote INTEGER  
{	if (parserData->numberOfSolutionsPresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	parserData->numberOfSolutionsPresent = true;
	parserData->numberOfSolutions = $3; 
	osresult->setSolutionNumber($3);
};	

optimizationNumberOfVariablesATT: NUMBEROFVARIABLESATT quote INTEGER  
{	if (parserData->numberOfVariablesPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->numberOfVariablesPresent = true;	
	parserData->numberOfVariables = $3; 
	osresult->setVariableNumber($3);
};

optimizationNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT quote INTEGER  
{	if (parserData->numberOfConstraintsPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->numberOfConstraintsPresent = true;		
	parserData->numberOfConstraints = $3; 
	osresult->setConstraintNumber($3);
};

optimizationNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT quote INTEGER  
{	if (parserData->numberOfObjectivesPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->numberOfObjectivesPresent = true;
	parserData->numberOfObjectives = $3; 
	osresult->setObjectiveNumber($3);
};
	
optimizationBody: GREATERTHAN optimizationContent OPTIMIZATIONEND | ENDOFELEMENT;

optimizationContent: solutionList otherSolverOutput;

solutionList: | solutionList solution;  

solution: solutionStart solutionAttList solutionBody
   {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   };

solutionStart: SOLUTIONSTART
{   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
	parserData->targetObjectiveIdxPresent = false;
	parserData->weightedObjectivesPresent = false;
};

solutionAttList: | solutionAttList solutionATT;

solutionATT: targetObjectiveIdxATT | weightedObjectivesATT;

targetObjectiveIdxATT: TARGETOBJECTIVEIDXATT quote INTEGER quote
{	if (parserData->targetObjectiveIdxPresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->targetObjectiveIdxPresent = true;
	if($3 >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3);
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{	if (parserData->weightedObjectivesPresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjectivesPresent = true;
	parserData->tempStr = $2;
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
};

solutionBody: GREATERTHAN solutionStatus solutionMessage
          variables objectives constraints otherSolutionResults solutionEnd;

solutionStatus: solutionStatusStart solutionStatusAttributes solutionStatusContent;

solutionStatusStart: STATUSSTART
	{	parserData->solutionStatusTypePresent = false;
		parserData->solutionStatusDescriptionPresent = false;
		parserData->solutionStatusNumberOfPresent = false;
		parserData->numberOf = 0;
	};

solutionStatusAttributes: solutionStatusAttList
	{	if (!parserData->solutionStatusTypePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
		parserData->kounter = 0;
	};

solutionStatusAttList: solutionStatusATT | solutionStatusAttList solutionStatusATT;

solutionStatusATT: 
	solutionStatusTypeATT
	{   if (parserData->solutionStatusTypePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for solution status element");
	    parserData->solutionStatusTypePresent = true;
	    if ((parserData->tempStr != "unbounded"     ) && (parserData->tempStr != "globallyOptimal") && 
	        (parserData->tempStr != "locallyOptimal") && (parserData->tempStr != "optimal") && 
	        (parserData->tempStr != "bestSoFar"     ) && (parserData->tempStr != "feasible") && 
	        (parserData->tempStr != "infeasible"    ) && (parserData->tempStr != "unsure") && 
	        (parserData->tempStr != "error"         ) && (parserData->tempStr != "other"))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->tempStr); 
	}
  | solutionStatusDescriptionATT
	{   if (parserData->solutionStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for solution status element");
	    parserData->solutionStatusDescriptionPresent = true;
		osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->tempStr);
	}
  | solutionStatusNumberOfATT;	

solutionStatusTypeATT: TYPEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}   
    |             EMPTYTYPEATT                     { parserData->tempStr = "";          };
 
solutionStatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
    |                    EMPTYDESCRIPTIONATT                     { parserData->tempStr = "";          };

solutionStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->solutionStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->solutionStatusNumberOfPresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, $3);
	parserData->numberOf = $3;
};
  
solutionStatusContent: 
    solutionStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
  | solutionStatusBody
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	}
;

solutionStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT; 

solutionStatusBody:  GREATERTHAN solutionSubstatusSEQ STATUSEND;

solutionSubstatusSEQ: solutionSubstatus | solutionSubstatusSEQ solutionSubstatus;

solutionSubstatus: solutionSubstatusStart solutionSubstatusAttList solutionSubstatusEnd
{	if (!parserData->solutionSubstatusTypePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
};	


solutionSubstatusStart: SUBSTATUSSTART 
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
};

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: solutionSubstatusTypeATT | solutionSubstatusDescriptionATT
{	if (parserData->solutionSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->solutionSubstatusDescriptionPresent = true;
	osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,parserData->tempStr);
}; 

solutionSubstatusTypeATT: TYPEATT ATTRIBUTETEXT QUOTE 
{	if (parserData->solutionSubstatusTypePresent)
		osrlerror(NULL, NULL, parserData, "type attribute multiply specified");
	parserData->solutionSubstatusTypePresent = true;
	osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter,$2);	
}; 

solutionSubstatusDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
	{	parserData->tempStr = $2; }
  | EMPTYDESCRIPTIONATT
	{	parserData->tempStr = ""; }; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


solutionMessage:
| MESSAGESTART GREATERTHAN ELEMENTTEXT MESSAGEEND 
	{	osresult->setSolutionMessage(parserData->solutionIdx, $3); free($3);
	}
| MESSAGESTART GREATERTHAN MESSAGEEND
| MESSAGESTART ENDOFELEMENT;

variables:
| VARIABLESSTART numberOfOtherVariableResults variablesBody;

numberOfOtherVariableResults:
  | NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
	{  
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
		parserData->tmpOtherValue = "";
		parserData->tmpOtherName = "";
		parserData->tmpOtherDescription = "";
	};

variablesBody: variablesEmpty | variablesContent;

variablesEmpty: ENDOFELEMENT;

variablesContent: GREATERTHAN variableValues variableValuesString basisStatus otherVariablesSEQ VARIABLESEND;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART
{	parserData->numberOfVarPresent = false; };

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
{	parserData->numberOfVar = $3; 
	parserData->kounter = 0;
	std::cout << "number of var: " << parserData->numberOfVar;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
}; 

variableValuesContent: 
	variableValuesEmpty 
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | variableValuesBody
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
  ;
 
variableValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

variableValuesBody:  GREATERTHAN varValueSEQ VALUESEND;

varValueSEQ: varValue | varValueSEQ varValue;

varValue: varValueStart  varIdxATT GREATERTHAN varVal VAREND
{	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
}; 

varValueStart: VARSTART
{	
	std::cout << "number of var: " << parserData->numberOfVar;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

varIdxATT: IDXATT quote INTEGER quote {	parserData->idx = $3; };
  
varVal: 
	INTEGER {parserData->tempVal = $1; }
  | DOUBLE  {parserData->tempVal = $1; };
  

variableValuesString: 
  | VALUESSTRINGSTART numberOfVarStringATT GREATERTHAN varValueStringList VALUESSTRINGEND
  {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  }
   | VALUESSTRINGSTART numberOfVarStringATT ENDOFELEMENT;

numberOfVarStringATT: NUMBEROFVARATT quote INTEGER quote 
	{
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = $3;
	}
; 

varValueStringList : | varValueStringList varValueString;

varValueString: VARSTART varStrIdxATT GREATERTHAN ELEMENTTEXT VAREND
{/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
}
| VARSTART varStrIdxATT GREATERTHAN VAREND
| VARSTART varStrIdxATT ENDOFELEMENT; 

varStrIdxATT: IDXATT quote INTEGER quote { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/};
  
  

basisStatus: | BASISSTATUSSTART numberOfBasisVarATT GREATERTHAN basisVarList BASISSTATUSEND
  {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  }
  | BASISSTATUSSTART numberOfBasisVarATT ENDOFELEMENT;

numberOfBasisVarATT : NUMBEROFVARATT quote INTEGER quote 
	{
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = $3;
	}
; 

basisVarList : | basisVarList basisVar;

basisVar: VARSTART basisVarIdxATT GREATERTHAN ELEMENTTEXT VAREND; 

basisVarIdxATT : IDXATT quote INTEGER quote { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/};
  
  
  

otherVariablesSEQ: | otherVariablesSEQ otherVariableResult;

otherVariableResult: otherVariableStart otherVariableAttributes
	{/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/}  
otherVariableResultContent
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
	}
;

otherVariableStart: OTHERSTART 
	{  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	}; 

otherVariableAttributes: otherVariableAttList 
	{	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	};
	  
otherVariableAttList: | otherVariableAttList otherVariableATT;

otherVariableATT: numberOfOtherVarATT | otherVarValueATT | otherVarNameATT | otherVarDescriptionATT;
  
numberOfOtherVarATT: NUMBEROFVARATT quote INTEGER quote 
{	
	parserData->otherVarStruct->numberOfVar = $3;

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
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
}
| EMPTYDESCRIPTIONATT;

otherVariableResultContent: ENDOFELEMENT	
| GREATERTHAN otherVarList OTHEREND;

otherVarList: | otherVarList otherVar;

otherVar: otherVarStart otherVarIdxATT otherVarContent {  
parserData->otherVarStruct->otherVarText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
parserData->outStr.str("");
parserData->otherVarStruct->otherVarIndex[parserData->kounter] =  parserData->ivar;
parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar)
std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
if (parserData->kounter == osresult->getAnOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many variables"); 
if (parserData->numberOfVariables > 0 && (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) ) 
	osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of variables");
//parserData->kounter++;
};

otherVarStart: VARSTART 
	{//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}; 

otherVarIdxATT: IDXATT quote INTEGER quote {};

otherVarContent: GREATERTHAN ElementValue VAREND | GREATERTHAN VAREND | ENDOFELEMENT;


objectives:
| OBJECTIVESSTART numberOfOtherObjectiveResults objectivesBody;

numberOfOtherObjectiveResults:
| NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
	{  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
;

objectivesBody: objectivesEmpty | objectivesContent;

objectivesEmpty: ENDOFELEMENT;

objectivesContent: GREATERTHAN objectiveValues otherObjectivesSEQ OBJECTIVESEND;

objectiveValues:
| VALUESSTART numberOfObjATT GREATERTHAN objValueList VALUESEND
{
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
}
| VALUESSTART numberOfObjATT ENDOFELEMENT;

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote{
			parserData->numberOfObj = $3;
} ;

objValueList: | objValueList objValue;

objValue: OBJSTART objIdxATT GREATERTHAN objVal OBJEND;

objIdxATT: IDXATT quote INTEGER quote { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = $3;   };

objVal:
   INTEGER {parserData->tempVal = $1;  
        parserData->objValPair->value = $1;                  
	parserData->objVals.push_back( parserData->objValPair);
}
 | DOUBLE {parserData->tempVal = $1;  
        parserData->objValPair->value = $1;
	parserData->objVals.push_back( parserData->objValPair);
  };


otherObjectivesSEQ: | otherObjectivesSEQ otherObjectiveResult;

otherObjectiveResult: otherObjectiveStart otherObjectiveAttList otherObjectiveResultContent;


otherObjectiveStart: OTHERSTART 
	{  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	}; 

otherObjectiveAttList: 
        | otherObjectiveAttList otherObjectiveATT;

otherObjectiveATT: numberOfOtherObjATT | otherObjValueATT | otherObjNameATT | otherObjDescriptionATT;
  
numberOfOtherObjATT: NUMBEROFOBJATT quote INTEGER quote 
{
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
}; 

otherObjValueATT: 
  EMPTYVALUEATT {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
}
  |    VALUEATT ATTRIBUTETEXT quote {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free($2);}
;

otherObjNameATT: 
  EMPTYNAMEATT 
{ 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
};

otherObjDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
{
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
}
| EMPTYDESCRIPTIONATT;


otherObjectiveResultContent: ENDOFELEMENT
| GREATERTHAN otherObjList OTHEREND
	{ 	 		
/*
	{	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	}  

*/
/*        parserData->otherObjVec.push_back( parserData->otherObjStruct); 
        parserData->numberOfOtherObjectiveResults++; 
		parserData->otherNamePresent = false;	
        osresult->setAnOtherObjectiveResultSparse(parserData->solutionIdx, parserData->iOther,  parserData->otherObjStruct->name,
		parserData->otherObjStruct->value, parserData->otherObjStruct->description, parserData->otherObjStruct->otherObjIndex,
		parserData->otherObjStruct->otherObjText, parserData->otherObjStruct->numberOfObj );							
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
*/				
	};


otherObjList: | otherObjList otherObj ;

otherObj: otherObjStart otherObjIdxATT  otherObjContent {  
//parserData->otherObjStruct->otherObjText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
//parserData->outStr.str("");
//parserData->otherObjStruct->otherObjIndex[parserData->kounter] =  parserData->iobj;
//parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj)
/*if (parserData->kounter == osresult->getAnOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many objectives"); 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of objectives");
*/
parserData->kounter++;
};

  
otherObjStart: OBJSTART 
	{//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	}; 

otherObjIdxATT: IDXATT quote INTEGER quote {};

otherObjContent: GREATERTHAN ElementValue OBJEND | GREATERTHAN OBJEND | ENDOFELEMENT;



constraints:
| CONSTRAINTSSTART numberOfOtherConstraintResults constraintsBody;

numberOfOtherConstraintResults:
| NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
	{  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
;

constraintsBody: constraintsEmpty | constraintsContent;

constraintsEmpty: ENDOFELEMENT;

constraintsContent: GREATERTHAN dualValues otherConstraintsSEQ CONSTRAINTSEND;


dualValues: 
| DUALVALUESSTART numberOfConATT GREATERTHAN dualValueList DUALVALUESEND
   {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 }
 | DUALVALUESSTART numberOfConATT ENDOFELEMENT;
 
numberOfConATT: NUMBEROFCONATT quote INTEGER quote
{
	parserData->numberOfCon = $3;
};

dualValueList : | dualValueList dualValue;

dualValue: CONSTART conIdxATT GREATERTHAN dualVal CONEND; 

conIdxATT : IDXATT quote INTEGER quote { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = $3;};


dualVal: DOUBLE { 	
        parserData->dualValPair->value = $1;
	parserData->dualVals.push_back( parserData->dualValPair); 		
	}
|  INTEGER  { 	
        parserData->dualValPair->value = $1;
	parserData->dualVals.push_back( parserData->dualValPair); 	
	} ;

                         
otherConstraintsSEQ: | otherConstraintsSEQ otherConstraintResult;

otherConstraintResult: otherConstraintStart otherConstraintAttList 
    otherConstraintResultContent;

otherConstraintStart: OTHERSTART;

otherConstraintAttList: | otherConstraintAttList otherConstraintATT;

otherConstraintATT: numberOfOtherConATT | otherConValueATT | otherConNameATT | otherConDescriptionATT;
  
numberOfOtherConATT: NUMBEROFCONATT quote INTEGER quote;

otherConValueATT: 
  EMPTYVALUEATT {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
}
  |    VALUEATT ATTRIBUTETEXT quote {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free($2);}
;

otherConNameATT: 
  EMPTYNAMEATT 
{ 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
};

otherConDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
{
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
}
| EMPTYDESCRIPTIONATT;

otherConstraintResultContent: ENDOFELEMENT	
| GREATERTHAN otherConList OTHEREND;


otherConList: | otherConList otherCon;

otherCon: otherConStart otherConIdxATT  otherConContent {  
//parserData->otherConStruct->otherConText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
//parserData->outStr.str("");
//parserData->otherConStruct->otherConIndex[parserData->kounter] =  parserData->icon;
//parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->numberOfCon)
/*if (parserData->kounter == osresult->getAnOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many constraints"); 
if (parserData->numberOfConstraints > 0 && (parserData->icon < 0 || parserData->icon > parserData->numberOfConstraints - 1) ) 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of constraints");
*/
parserData->kounter++;
};

  
otherConStart: CONSTART 
	{//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	}; 

otherConIdxATT: IDXATT quote INTEGER quote {};

otherConContent: GREATERTHAN ElementValue CONEND | GREATERTHAN CONEND | ENDOFELEMENT;



otherSolutionResults: 
| OTHERSOLUTIONRESULTSSTART numberOfOtherSolutionResults GREATERTHAN otherSolutionResultList OTHERSOLUTIONRESULTSEND
{
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
| OTHERSOLUTIONRESULTSSTART numberOfOtherSolutionResults ENDOFELEMENT
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
    
otherSolutionResultList:  | otherSolutionResultList anotherSolutionResult;

anotherSolutionResult: 
OTHERSOLUTIONRESULTSTART  anotherSolutionResultAttList GREATERTHAN anotherSolutionItemList OTHERSOLUTIONRESULTEND
{
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
| OTHERSOLUTIONRESULTSTART  anotherSolutionResultAttList ENDOFELEMENT
{
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
;

anotherSolutionResultAttList: 
   | anotherSolutionResultAttList {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
} anotherSolutionResultAtt ;

anotherSolutionResultAtt: numberOfOtherSolutionResultItems | anotherSolutionResultNameATT | anotherSolutionResultCategoryATT | anotherSolutionDescriptionATT;

numberOfOtherSolutionResultItems: NUMBEROFITEMSATT QUOTE INTEGER QUOTE 
{	
int temp;
temp = $3;
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
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

anotherSolutionItemList: 
  | anotherSolutionItemList anotherSolutionItem {parserData->kounter++;};

anotherSolutionItem:  
    otherSolutionItemEmpty   
{
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
}
|   otherSolutionItemContent
{
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
};


otherSolutionItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

otherSolutionItemContent: ITEMSTART ITEMTEXT 
{	parserData->itemContent = $2; free($2);
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
}
ITEMEND;

solutionEnd: SOLUTIONEND  {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
};



otherSolverOutput: | OTHERSOLVEROUTPUTSTART numberOfSolverOutputsATT otherSolverOutputBody;

numberOfSolverOutputsATT: NUMBEROFSOLVEROUTPUTSATT quote INTEGER quote;

otherSolverOutputBody: ENDOFELEMENT | GREATERTHAN solverOutputSEQ OTHERSOLVEROUTPUTEND;

solverOutputSEQ: | solverOutputSEQ solverOutput;

solverOutput: 
SOLVEROUTPUTSTART solverOutputAttList GREATERTHAN solverOutputItemList SOLVEROUTPUTEND
{
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
}
| SOLVEROUTPUTSTART solverOutputAttList ENDOFELEMENT;

solverOutputAttList: 
   | solverOutputAttList 
{/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/} solverOutputAtt ;

solverOutputAtt: numberOfSolverOutputItems | solverOutputNameATT | solverOutputCategoryATT | solverOutputDescriptionATT;

numberOfSolverOutputItems: NUMBEROFITEMSATT QUOTE INTEGER QUOTE 
{	
/* 
int temp;
temp = $3;
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
*/
};

solverOutputNameATT: 
  EMPTYNAMEATT 
{ 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
};
  | NAMEATT ATTRIBUTETEXT QUOTE
{
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
};

solverOutputCategoryATT: 
CATEGORYATT ATTRIBUTETEXT QUOTE 
{
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
}
   | EMPTYCATEGORYATT ;
 
solverOutputDescriptionATT:
DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
}
   | EMPTYDESCRIPTIONATT ;

solverOutputItemList: 
  | solverOutputItemList solverOutputItem;

solverOutputItem: solverOutputItemEmpty 
{
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/}
| solverOutputItemContent
{
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/};

solverOutputItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOutputItemContent: ITEMSTART ITEMTEXT 
 {/*parserData->itemContent = $2; free($2);*/}
ITEMEND;


aNumber:
	INTEGER   {parserData->tempVal = $1;}
	| DOUBLE  {parserData->tempVal = $1;};

quote: xmlWhiteSpace QUOTE;

ElementValue: 
    ELEMENTTEXT  { parserData->outStr << $1;    free($1); }
  | INTEGER      { parserData->outStr << $1;  /*free($1);*/ }
  | DOUBLE       { parserData->outStr << $1;  /*free($1);*/ };
  


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

