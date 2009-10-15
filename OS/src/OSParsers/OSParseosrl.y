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
		parserData->generalStatusPresent = true;
	};

generalStatusAttributes: generalStatusAttList
	{	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->kounter = 0;
	};

generalStatusAttList: generalStatusATT | generalStatusAttList generalStatusATT;

generalStatusATT: 
    generalStatusTypeATT 
	{   if (parserData->typeAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
	    parserData->typeAttributePresent = true;
	    if ((parserData->tempStr != "error"  ) &&
	        (parserData->tempStr != "warning") && 
	        (parserData->tempStr != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not matched any legal value");
		osresult->setGeneralStatusType(parserData->tempStr); 
	}
  | generalStatusDescriptionATT 
	{   if (parserData->descriptionAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->descriptionAttributePresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	}
  | generalStatusNumberOfATT;

generalStatusTypeATT: TYPEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}   
    |            EMPTYTYPEATT                     { parserData->tempStr = "";          };

generalStatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
    |                   EMPTYDESCRIPTIONATT                     { parserData->tempStr = "";          };

generalStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
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

generalSubstatus: generalSubstatusStart generalSubstatusAttributes generalSubstatusEnd
{	parserData->kounter++;
};	

generalSubstatusStart: SUBSTATUSSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
};
		
generalSubstatusAttributes: generalSubstatusAttList		
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};	

generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: generalSubstatusNameATT | generalSubstatusDescriptionATT
{	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->descriptionAttributePresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter,parserData->tempStr);
}; 

generalSubstatusNameATT: NAMEATT ATTRIBUTETEXT QUOTE 
{	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
	parserData->nameAttributePresent = true;
	osresult->setGeneralSubstatusName(parserData->kounter,$2);
}; 

generalSubstatusDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT QUOTE { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          }; 

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
	}  
  | generalOtherResultsBody
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};
	
generalOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

generalOtherResultsBody: GREATERTHAN generalOtherResultSEQ OTHERRESULTSEND;

generalOtherResultSEQ: generalOtherResult | generalOtherResultSEQ generalOtherResult; 

generalOtherResult: generalOtherResultStart generalOtherAttributes generalOtherEnd
{	parserData->kounter++;
};	

generalOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

generalOtherAttributes: generalOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};	

generalOtherAttList: | generalOtherAttList generalOtherAtt;

generalOtherAtt: 
	generalOtherNameATT
	{	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | generalOtherValueATT
	{	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | generalOtherDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

generalOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);};

generalOtherValueATT: 
	VALUEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                { parserData->tempStr = "";          }; 

generalOtherDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          }; 

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

availableDiskSpace: availableDiskSpaceStart availableDiskSpaceAttributes GREATERTHAN availableDiskSpaceValue 
                    AVAILABLEDISKSPACEEND;

availableDiskSpaceStart: AVAILABLEDISKSPACESTART
	{	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
	};

availableDiskSpaceAttributes: availableDiskSpaceAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: 
	availableDiskSpaceUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | availableDiskSpaceDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

availableDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote 
	{	parserData->tempStr = $2; free ($2);
		if (parserData->tempStr != "exabyte"  && parserData->tempStr != "petabyte" && 
			parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" &&
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && 
			parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	};

availableDiskSpaceDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

availableDiskSpaceValue:
     INTEGER {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;};

availableMemory: availableMemoryStart availableMemoryAttributes GREATERTHAN availableMemoryValue 
                 AVAILABLEMEMORYEND;

availableMemoryStart: AVAILABLEMEMORYSTART
	{	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	};

availableMemoryAttributes: availableMemoryAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	};

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: 
	availableMemoryUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | availableMemoryDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

availableMemoryUnitATT: UNITATT ATTRIBUTETEXT quote
	{	parserData->tempStr = $2; free ($2);
		if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
};

availableMemoryDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

availableMemoryValue:
     INTEGER {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;};

availableCPUSpeed: availableCPUSpeedStart availableCPUSpeedAttributes GREATERTHAN availableCPUSpeedValue 
                   AVAILABLECPUSPEEDEND;

availableCPUSpeedStart: AVAILABLECPUSPEEDSTART
	{	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	};

availableCPUSpeedAttributes: availableCPUSpeedAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	};

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: 
	availableCPUSpeedUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | availableCPUSpeedDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

availableCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
};

availableCPUSpeedDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

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

availableCPUNumberAttList: 
  | availableCPUNumberDescriptionATT
	{	osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

availableCPUNumberDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

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

systemOtherResult: systemOtherResultStart systemOtherAttributes systemOtherEnd
{	parserData->kounter++;
};	

systemOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

systemOtherAttributes: systemOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};
	
systemOtherAttList: | systemOtherAttList systemOtherAtt;

systemOtherAtt:
	systemOtherNameATT
	{	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | systemOtherValueATT
	{	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | systemOtherDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

systemOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

systemOtherValueATT: 
	VALUEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                { parserData->tempStr = "";          }; 

systemOtherDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };
  
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

serviceOtherResult: serviceOtherResultStart serviceOtherAttributes serviceOtherEnd
{	parserData->kounter++;
};

serviceOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

serviceOtherAttributes: serviceOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};
	
serviceOtherAttList: | serviceOtherAttList serviceOtherAtt;

serviceOtherAtt: 
	serviceOtherNameATT 
	{	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	}
  | serviceOtherValueATT 
	{	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	}
  | serviceOtherDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;
  
serviceOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

serviceOtherValueATT: 
	VALUEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                { parserData->tempStr = "";          }; 

serviceOtherDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

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

timeAtt: 
	timeUnit 
	{	if (parserData->timeUnit != "tick"        &&
			parserData->timeUnit != "millisecond" &&
			parserData->timeUnit != "second"      &&
			parserData->timeUnit != "minute"      &&
			parserData->timeUnit != "hour"        &&
			parserData->timeUnit != "day"         &&
			parserData->timeUnit != "week"        &&
			parserData->timeUnit != "month"       &&
			parserData->timeUnit != "year"   )     
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	};
  | timeType 
  | timeCategory 
  | timeDescription;

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


usedDiskSpace: usedDiskSpaceStart usedDiskSpaceAttributes GREATERTHAN usedDiskSpaceValue 
               USEDDISKSPACEEND;

usedDiskSpaceStart: USEDDISKSPACESTART
	{	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
	};
	
usedDiskSpaceAttributes: usedDiskSpaceAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	};

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: 
	usedDiskSpaceUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | usedDiskSpaceDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

usedDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
};

usedDiskSpaceDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

usedDiskSpaceValue:
     INTEGER {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;};

usedMemory: usedMemoryStart usedMemoryAttributes GREATERTHAN usedMemoryValue 
            USEDMEMORYEND;

usedMemoryStart: USEDMEMORYSTART
	{	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	};
	
usedMemoryAttributes: usedMemoryAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	};
			
usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: 
	usedMemoryUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | usedMemoryDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

usedMemoryUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
};

usedMemoryDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

usedMemoryValue:
     INTEGER {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;};


usedCPUSpeed: usedCPUSpeedStart usedCPUSpeedAttributes GREATERTHAN usedCPUSpeedValue 
              USEDCPUSPEEDEND;
              
usedCPUSpeedStart: USEDCPUSPEEDSTART
	{	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	};
              
usedCPUSpeedAttributes: usedCPUSpeedAttList
	{	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};
	
usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: 
	usedCPUSpeedUnitATT 
	{	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	};
  | usedCPUSpeedDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

usedCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote
{	parserData->tempStr = $2; free ($2);
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "usedCPUSpeed unit not recognized");
};

usedCPUSpeedDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

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
               

usedCPUNumberAttList: 
  | usedCPUNumberDescriptionATT
	{	osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	};

usedCPUNumberDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";          };

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

jobOtherResult: jobOtherResultStart jobOtherAttributes jobOtherEnd
{	parserData->kounter++;
};	

jobOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
};

jobOtherAttributes: jobOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

jobOtherAttList: | jobOtherAttList jobOtherAtt;

jobOtherAtt: 
	jobOtherNameATT 
 	{	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	}
 | jobOtherValueATT 
	{	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	}
 | jobOtherDescriptionATT
	{	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	}
;

jobOtherNameATT: NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}; 

jobOtherValueATT: 
	VALUEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2); }
  | EMPTYVALUEATT                { parserData->tempStr = "";           }; 

jobOtherDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2); }
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = "";           };

jobOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


optimizationElement: | OptimizationStart optimizationAttributes optimizationContent;

OptimizationStart: OPTIMIZATIONSTART;

optimizationAttributes: optimizationAttList
{	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
	parserData->solutionIdx = 0;
};	

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
	optimizationNumberOfSolutionsATT   quote
  | optimizationNumberOfVariablesATT   quote          
  | optimizationNumberOfConstraintsATT quote
  | optimizationNumberOfObjectivesATT  quote
  ;

optimizationNumberOfSolutionsATT: NUMBEROFSOLUTIONSATT quote INTEGER  
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = $3; 
	osresult->setSolutionNumber($3);
};	

optimizationNumberOfVariablesATT: NUMBEROFVARIABLESATT quote INTEGER  
{	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = $3; 
	osresult->setVariableNumber($3);
};

optimizationNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT quote INTEGER  
{	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = $3; 
	osresult->setConstraintNumber($3);
};

optimizationNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT quote INTEGER  
{	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = $3; 
	osresult->setObjectiveNumber($3);
};
	
optimizationContent: optimizationEmpty | optimizationBody;

optimizationEmpty: GREATERTHAN OPTIMIZATIONEND | ENDOFELEMENT;

optimizationBody: GREATERTHAN solutionSEQ otherSolverOutput OPTIMIZATIONEND;

solutionSEQ: solution | solutionSEQ solution;  

solution: solutionStart solutionAttributes solutionBody
   {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   };

solutionStart: SOLUTIONSTART
{   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
};

solutionAttributes: solutionAttList
{	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
};

solutionAttList: | solutionAttList solutionATT;

solutionATT: targetObjectiveIdxATT | weightedObjectivesATT;

targetObjectiveIdxATT: TARGETOBJECTIVEIDXATT quote INTEGER quote
{	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if($3 >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3);
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = $2;
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
};

solutionBody: GREATERTHAN solutionStatus solutionMessage
          variables objectives constraints otherSolutionResults solutionEnd;

solutionStatus: solutionStatusStart solutionStatusAttributes solutionStatusContent;

solutionStatusStart: STATUSSTART
	{ parserData->numberOf = 0; };

solutionStatusAttributes: solutionStatusAttList
	{	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->kounter = 0;
	};

solutionStatusAttList: solutionStatusATT | solutionStatusAttList solutionStatusATT;

solutionStatusATT: 
	solutionStatusTypeATT
	{   if (parserData->typeAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for solution status element");
	    parserData->typeAttributePresent = true;
	    if ((parserData->tempStr != "unbounded"     ) && (parserData->tempStr != "globallyOptimal") && 
	        (parserData->tempStr != "locallyOptimal") && (parserData->tempStr != "optimal") && 
	        (parserData->tempStr != "bestSoFar"     ) && (parserData->tempStr != "feasible") && 
	        (parserData->tempStr != "infeasible"    ) && (parserData->tempStr != "unsure") && 
	        (parserData->tempStr != "error"         ) && (parserData->tempStr != "other"))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->tempStr); 
	}
  | solutionStatusDescriptionATT
	{   if (parserData->descriptionAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for solution status element");
	    parserData->descriptionAttributePresent = true;
		osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->tempStr);
	}
  | solutionStatusNumberOfATT;	

solutionStatusTypeATT: TYPEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}   
    |             EMPTYTYPEATT                     { parserData->tempStr = "";          };
 
solutionStatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
    |                    EMPTYDESCRIPTIONATT                     { parserData->tempStr = "";          };

solutionStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
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

solutionSubstatus: solutionSubstatusStart solutionSubstatusAttributes solutionSubstatusEnd
{	parserData->kounter++; };	

solutionSubstatusStart: SUBSTATUSSTART 
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
};

solutionSubstatusAttributes: solutionSubstatusAttList
{	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};	

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: solutionSubstatusTypeATT | solutionSubstatusDescriptionATT
{	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->descriptionAttributePresent = true;
	osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,parserData->tempStr);
}; 

solutionSubstatusTypeATT: TYPEATT ATTRIBUTETEXT QUOTE 
{	if (parserData->typeAttributePresent)
		osrlerror(NULL, NULL, parserData, "type attribute multiply specified");
	parserData->typeAttributePresent = true;
	osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter,$2);	
}; 

solutionSubstatusDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT QUOTE { parserData->tempStr = $2; }
  | EMPTYDESCRIPTIONATT                { parserData->tempStr = ""; }; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


solutionMessage:
| MESSAGESTART GREATERTHAN ELEMENTTEXT MESSAGEEND 
	{	osresult->setSolutionMessage(parserData->solutionIdx, $3); free($3);
	}
| MESSAGESTART GREATERTHAN MESSAGEEND
| MESSAGESTART ENDOFELEMENT;

variables:
| VARIABLESSTART numberOfOtherVariableResults variablesContent;

numberOfOtherVariableResults:
  | NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
	{	parserData->numberOfOtherVariableResults = $3;
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
	};

variablesContent: ENDOFELEMENT | variablesBody;

variablesBody: GREATERTHAN variableValues variableValuesString basisStatus otherVariableResultsSEQ VARIABLESEND;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
{	parserData->numberOfVar = $3; 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
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
}; 

varValueStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

varIdxATT: IDXATT quote INTEGER quote {	parserData->idx = $3; };
  
varVal: 
	INTEGER {parserData->tempVal = $1; }
  | DOUBLE  {parserData->tempVal = $1; };
  

variableValuesString: | variableValuesStringStart numberOfVarStringATT variableValuesStringContent;

variableValuesStringStart: VALUESSTRINGSTART 
{	parserData->numberAttributePresent = false; };

numberOfVarStringATT: NUMBEROFVARATT quote INTEGER quote 
{	parserData->numberOfVar = $3;
	parserData->kounter = 0;
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
}; 

variableValuesStringContent: 
	variableValuesStringEmpty 
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | variableValuesStringBody
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
  ;

variableValuesStringEmpty: GREATERTHAN VALUESSTRINGEND | ENDOFELEMENT; 

variableValuesStringBody: GREATERTHAN varValueStringSEQ VALUESSTRINGEND;

varValueStringSEQ: varValueString | varValueStringSEQ varValueString;

varValueString: varValueStringStart varStrIdxATT GREATERTHAN ELEMENTTEXT VAREND
{	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         $4);
	parserData->kounter++;
}; 

varValueStringStart: VARSTART 
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

varStrIdxATT: IDXATT quote INTEGER quote { parserData->idx = $3; };
  
  

basisStatus: | basisStatusStart numberOfBasisVarATT basisStatusContent;

basisStatusStart: BASISSTATUSSTART 
{	parserData->nVarPresent = false; };

numberOfBasisVarATT : NUMBEROFVARATT quote INTEGER quote 
{	parserData->numberOfVar = $3;
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
}; 

basisStatusContent:
	basisStatusEmpty
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | basisStatusBody
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
  ;

basisStatusEmpty: GREATERTHAN BASISSTATUSEND | ENDOFELEMENT;

basisStatusBody: GREATERTHAN basisVarSEQ BASISSTATUSEND;

basisVarSEQ : basisVar | basisVarSEQ basisVar;

basisVar: basisVarStart basisVarIdxATT GREATERTHAN ELEMENTTEXT VAREND
{	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         $4);
	parserData->kounter++;
}; 

basisVarStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

basisVarIdxATT : IDXATT quote INTEGER quote { parserData->idx = $3; };
  

otherVariableResultsSEQ: | otherVariableResultsSEQ otherVariableResult;

otherVariableResult: otherVariableResultStart otherVariableResultAttributes otherVariableResultContent
	{ 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	}
;

otherVariableResultStart: OTHERSTART; 

otherVariableResultAttributes: otherVariableResultAttList 
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	};
	  
otherVariableResultAttList: | otherVariableResultAttList otherVariableResultATT;

otherVariableResultATT: 
	numberOfOtherVariableResultsATT 
  | otherVariableResultValueATT
  {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherVariableResultNameATT 
  {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherVariableResultDescriptionATT
  {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  };
  
numberOfOtherVariableResultsATT: NUMBEROFVARATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = $3;
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, $3);
}; 

otherVariableResultValueATT: 
	VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                {parserData->tempStr = "";          };

otherVariableResultNameATT: 
	NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYNAMEATT                {parserData->tempStr = "";          };

otherVariableResultDescriptionATT:
	DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                {parserData->tempStr = "";          };

otherVariableResultContent: ENDOFELEMENT	
| GREATERTHAN otherVarList OTHEREND;

otherVarList: | otherVarList otherVar;

otherVar: otherVarStart otherVarIdxATT otherVarContent 
{ 	
	parserData->kounter++;
};

otherVarStart: VARSTART; 

otherVarIdxATT: IDXATT quote INTEGER quote 
{	
 	osresult->setOtherVariableResultsVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherVarContent: 
	GREATERTHAN ElementValue VAREND 
	{	
	 	osresult->setOtherVariableResultsVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN VAREND 
  | ENDOFELEMENT;


objectives:
| OBJECTIVESSTART numberOfOtherObjectiveResults objectivesContent;

numberOfOtherObjectiveResults:
  | NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
	{	parserData->numberOfOtherObjectiveResults = $3;
//        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
	};

objectivesContent: ENDOFELEMENT | objectivesBody;

objectivesBody: GREATERTHAN objectiveValues otherObjectiveResultsSEQ OBJECTIVESEND;

objectiveValues: | objectiveValuesStart numberOfObjATT objectiveValuesContent;

objectiveValuesStart: VALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote
{	parserData->numberOfObj = $3;
//	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
}; 

objectiveValuesContent: 
	objectiveValuesEmpty 
	{	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	}
  | objectiveValuesBody
	{	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	}
  ;
 
objectiveValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

objectiveValuesBody:  GREATERTHAN objValueSEQ VALUESEND;


objValueSEQ: objValue | objValueSEQ objValue;

objValue: objValueStart objIdxATT GREATERTHAN objVal OBJEND
{//	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
//						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
}; 

objValueStart: OBJSTART
{	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
};

objIdxATT: IDXATT quote INTEGER quote { parserData->idx = $3; };

objVal:
   INTEGER {parserData->tempVal = $1; }
 | DOUBLE  {parserData->tempVal = $1; };



otherObjectiveResultsSEQ: | otherObjectiveResultsSEQ otherObjectiveResult;

otherObjectiveResult: otherObjectiveResultStart otherObjectiveResultAttributes otherObjectiveResultContent
	{ 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	}
;

otherObjectiveResultStart: OTHERSTART; 

otherObjectiveResultAttributes: otherObjectiveResultAttList
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	};


otherObjectiveResultAttList: | otherObjectiveResultAttList otherObjectiveResultATT;

otherObjectiveResultATT: 
	numberOfOtherObjectiveResultsATT 
  | otherObjectiveResultValueATT 
  {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 //	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherObjectiveResultNameATT 
  {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
// 	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherObjectiveResultDescriptionATT
  {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
// 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  };
  
numberOfOtherObjectiveResultsATT: NUMBEROFOBJATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = $3;
// 	osresult->setOtherVariableResultNumberOfObj(parserData->solutionIdx, parserData->iOther, $3);
}; 

otherObjectiveResultValueATT: 
	VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                {parserData->tempStr = "";          };

otherObjectiveResultNameATT: 
	NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYNAMEATT                {parserData->tempStr = "";          };

otherObjectiveResultDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
	DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                {parserData->tempStr = "";          };

otherObjectiveResultContent: ENDOFELEMENT
| GREATERTHAN otherObjList OTHEREND;

otherObjList: | otherObjList otherObj ;

otherObj: otherObjStart otherObjIdxATT  otherObjContent 
{  
	parserData->kounter++;
};

otherObjStart: OBJSTART; 

otherObjIdxATT: IDXATT quote INTEGER quote 
{	
// 	osresult->setOtherObjectiveResultsObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherObjContent: 
	GREATERTHAN ElementValue OBJEND 
	{	
//	 	osresult->setOtherObjectiveResultsObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN OBJEND 
  | ENDOFELEMENT;



constraints:
| CONSTRAINTSSTART numberOfOtherConstraintResults constraintsContent;

numberOfOtherConstraintResults:
  | NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
	{	parserData->numberOfOtherVariableResults = $3;
//		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
	};

constraintsContent: ENDOFELEMENT | constraintsBody;

constraintsBody: GREATERTHAN dualValues otherConstraintResultsSEQ CONSTRAINTSEND;

dualValues: | dualValuesStart numberOfConATT dualValuesContent;

dualValuesStart: DUALVALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfConATT: NUMBEROFCONATT quote INTEGER quote
{
	parserData->numberOfCon = $3;
//	osresult->setNumberOfConValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
};

dualValuesContent:
	dualValuesEmpty 
	{	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	}
  | dualValuesBody
	{	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	}
  ;

dualValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

dualValuesBody:  GREATERTHAN dualValueSEQ DUALVALUESEND;

dualValueSEQ: dualValue | dualValueSEQ dualValue;

dualValue: dualValueStart conIdxATT GREATERTHAN dualVal CONEND 
{//	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
//						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
}; 

dualValueStart: CONSTART
{	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
};

conIdxATT: IDXATT quote INTEGER quote { parserData->idx = $3; };

dualVal: 
	INTEGER {parserData->tempVal = $1; }
  | DOUBLE  {parserData->tempVal = $1; };

                         
otherConstraintResultsSEQ: | otherConstraintResultsSEQ otherConstraintResult;

otherConstraintResult: otherConstraintResultStart otherConstraintResultAttributes otherConstraintResultContent
	{ 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	}
;

otherConstraintResultStart: OTHERSTART;

otherConstraintResultAttributes: otherConstraintResultAttList
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	};

otherConstraintResultAttList: | otherConstraintResultAttList otherConstraintResultATT;

otherConstraintResultATT: 
	numberOfOtherConstraintResultATT 
  | otherConstraintResultValueATT 
  {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
// 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherConstraintResultNameATT 
  {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
// 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  }
  | otherConstraintResultDescriptionATT
  {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
// 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  };
  
numberOfOtherConstraintResultATT: NUMBEROFCONATT quote INTEGER quote
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = $3;
// 	osresult->setOtherConstraintResultNumberOfVar(parserData->solutionIdx, parserData->iOther, $3);
}; 

otherConstraintResultValueATT: 
	VALUEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYVALUEATT                {parserData->tempStr = "";          };

otherConstraintResultNameATT: 
	NAMEATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYNAMEATT                {parserData->tempStr = "";          };

otherConstraintResultDescriptionATT: 
	DESCRIPTIONATT ATTRIBUTETEXT quote {parserData->tempStr = $2; free($2);}
  | EMPTYDESCRIPTIONATT                {parserData->tempStr = "";          };

otherConstraintResultContent: ENDOFELEMENT	
| GREATERTHAN otherConList OTHEREND;


otherConList: | otherConList otherCon;

otherCon: otherConStart otherConIdxATT  otherConContent 
{ 	
	parserData->kounter++;
};
  
otherConStart: CONSTART;

otherConIdxATT: IDXATT quote INTEGER quote
{	
// 	osresult->setOtherConstraintResultsConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherConContent: 
	GREATERTHAN ElementValue VAREND 
	{	
//	 	osresult->setOtherConstraintResultsCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN VAREND 
  | ENDOFELEMENT;



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
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true;
//	parserData->otherVarStruct->name = "";
};
  | NAMEATT ATTRIBUTETEXT quote
{
	parserData->tmpOtherName=$2; //parserData->nameAttributePresent = true;
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
//	osrl_empty_vectors( parserData);
    
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
	parserData->nameAttributePresent = true; 
	parserData->otherVarStruct->name = "";
*/
};
  | NAMEATT ATTRIBUTETEXT QUOTE
{
/*	parserData->tmpOtherName=$2; parserData->nameAttributePresent = true;
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
    ELEMENTTEXT  { parserData->tempStr = $1;       free($1); }
  | INTEGER      { parserData->tempStr = os_dtoa_format($1); }
  | DOUBLE       { parserData->tempStr = os_dtoa_format($1); };
  


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

