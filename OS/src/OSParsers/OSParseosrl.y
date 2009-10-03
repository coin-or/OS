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
	{	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");
		parserData->generalStatusPresent = true;
	}
  | generalMessage
	{	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	}
  | serviceURI 
	{	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	}
  | serviceName 
	{	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	}
  | instanceName 
	{	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	}
  | jobID 
	{	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	}
  | solverInvoked 
	{	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	}
  | timeStamp 
	{	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	}
  | generalOtherResults
	{	if (parserData->generalOtherPresent)
			osrlerror(NULL, NULL, parserData, "only one general other element allowed");
		parserData->generalOtherPresent = true;
	}
  ;
              
generalStatus: 
   generalStatusStart generalStatusAttributes generalStatusContent;

generalStatusStart: GENERALSTATUSSTART
	{	parserData->generalStatusTypePresent = false;
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
		osresult->setGeneralStatusType(parserData->tempStr); 
	}
  | generalStatusDescriptionATT 
	{   if (parserData->generalStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->generalStatusDescriptionPresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	}
  | generalStatusNumberOfATT
	{ std::cout << "parsed numberOfGeneralSubstatuses" << std::endl;
	};

generalStatusTypeATT: TYPEATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}   
    |            EMPTYTYPEATT                     { parserData->tempStr = "";          };

generalStatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote { parserData->tempStr = $2; free($2);}
    |                   EMPTYDESCRIPTIONATT                     { parserData->tempStr = "";          };

generalStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->generalStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->generalStatusNumberOfPresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setGeneralStatusNumberOf($3);
	parserData->numberOf = $3;
};


generalStatusContent: generalStatusEmpty | generalStatusBody;

generalStatusEmpty: GREATERTHAN GENERALSTATUSEND | ENDOFELEMENT; 

generalStatusBody: GREATERTHAN generalSubstatusSEQ GENERALSTATUSEND
{std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
std::cout << "parserData->numberOf = " << parserData->numberOf << std::endl;
	if (parserData->kounter != parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
};

generalSubstatusSEQ: generalSubstatus | generalSubstatusSEQ generalSubstatus;

generalSubstatus: generalSubstatusStart generalSubstatusAttList generalSubstatusEnd
{	if (!parserData->generalSubstatusNamePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
};	

generalSubstatusStart: SUBSTATUSSTART
{std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
std::cout << "parserData->numberOf = " << parserData->numberOf << std::endl;
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
};
		
generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: generalSubstatusNameATT | generalSubstatusDescriptionATT
{	if (parserData->generalSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified specified");
	parserData->generalSubstatusDescriptionPresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter-1,parserData->tempStr);
}; 

generalSubstatusNameATT: NAMEATT ATTRIBUTETEXT QUOTE 
{	std::cout << "read \'name=\'" << std::endl;
	if (parserData->generalSubstatusNamePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified specified");
	parserData->generalSubstatusNamePresent = true;
	std::cout << "setGeneralSubstatusName" << std::endl; 
	osresult->setGeneralSubstatusName(parserData->kounter-1,$2);
	std::cout << "Done setGeneralSubstatusName" << std::endl; 
	
}; 

generalSubstatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{	parserData->tempStr = $2;
}
| EMPTYDESCRIPTIONATT
{	parserData->tempStr = "";
}
; 

generalSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


generalMessage: 
  MESSAGESTART GREATERTHAN ELEMENTTEXT MESSAGEEND {osresult->setGeneralMessage( $3);  free($3);  parserData->errorText = NULL;}
| MESSAGESTART GREATERTHAN MESSAGEEND 
| MESSAGESTART ENDOFELEMENT;

serviceURI: 
  SERVICEURISTART GREATERTHAN ELEMENTTEXT SERVICEURIEND {osresult->setServiceURI( $3); free($3); parserData->errorText = NULL;}
| SERVICEURISTART GREATERTHAN SERVICEURIEND 
| SERVICEURISTART ENDOFELEMENT;

serviceName: 
  SERVICENAMESTART GREATERTHAN ELEMENTTEXT SERVICENAMEEND {osresult->setServiceName($3);  free($3);   parserData->errorText = NULL;}
| SERVICENAMESTART GREATERTHAN SERVICENAMEEND 
| SERVICENAMESTART ENDOFELEMENT;

instanceName: 
  INSTANCENAMESTART GREATERTHAN ELEMENTTEXT INSTANCENAMEEND {osresult->setInstanceName( $3) ;  free($3);   parserData->errorText = NULL;}
| INSTANCENAMESTART GREATERTHAN INSTANCENAMEEND 
| INSTANCENAMESTART ENDOFELEMENT;

jobID: 
  JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND {osresult->setJobID( $3); free($3);  parserData->errorText = NULL;}
| JOBIDSTART GREATERTHAN JOBIDEND 
| JOBIDSTART ENDOFELEMENT;

solverInvoked: 
  SOLVERINVOKEDSTART GREATERTHAN ELEMENTTEXT SOLVERINVOKEDEND {std::cout << "!!!store solver invoked" << std::endl;}
| SOLVERINVOKEDSTART GREATERTHAN SOLVERINVOKEDEND 
| SOLVERINVOKEDSTART ENDOFELEMENT;

timeStamp: 
  TIMESTAMPSTART GREATERTHAN ELEMENTTEXT TIMESTAMPEND {std::cout << "!!!store time stamp" << std::endl;}
| TIMESTAMPSTART GREATERTHAN TIMESTAMPEND 
| TIMESTAMPSTART ENDOFELEMENT;

generalOtherResults: OTHERRESULTSSTART generalOtherResultsAttList generalOtherResultsBody;

generalOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote {std::cout << "!!!store numberOfOtherGeneralResults" << std::endl;} ;

generalOtherResultsBody: generalOtherResultsEmpty | generalOtherResultsContent;

generalOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

generalOtherResultsContent: GREATERTHAN generalOtherResultList OTHERRESULTSEND;

generalOtherResultList: generalOtherResult | generalOtherResultList generalOtherResult; 

generalOtherResult: OTHERSTART generalOtherAttList generalOtherEnd;

generalOtherAttList: | generalOtherAttList generalOtherAtt;

generalOtherAtt: generalOtherNameATT | generalOtherValueATT | generalOtherDescriptionATT;

generalOtherNameATT: NAMEATT ATTRIBUTETEXT quote
| EMPTYNAMEATT; 

generalOtherValueATT: VALUEATT ATTRIBUTETEXT quote
|EMPTYVALUEATT; 

generalOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
| EMPTYDESCRIPTIONATT; 

generalOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



systemElement: | SYSTEMSTART ENDOFELEMENT
               | SYSTEMSTART GREATERTHAN systemContent SYSTEMEND; 
               
systemContent: | systemContent systemChild; 

systemChild: systemInformation | availableDiskSpace | availableMemory |
             availableCPUSpeed | availableCPUNumber | systemOtherResults; 

systemInformation:
  SYSTEMINFORMATIONSTART GREATERTHAN ELEMENTTEXT SYSTEMINFORMATIONEND {}
| SYSTEMINFORMATIONSTART GREATERTHAN SYSTEMINFORMATIONEND 
| SYSTEMINFORMATIONSTART ENDOFELEMENT;

availableDiskSpace: AVAILABLEDISKSPACESTART availableDiskSpaceAttList GREATERTHAN availableDiskSpaceValue 
                    AVAILABLEDISKSPACEEND;

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: availableDiskSpaceUnitATT | availableDiskSpaceDescriptionATT;

availableDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote{};

availableDiskSpaceDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

availableDiskSpaceValue:
     INTEGER
   | DOUBLE;

availableMemory: AVAILABLEMEMORYSTART availableMemoryAttList GREATERTHAN availableMemoryValue 
                 AVAILABLEMEMORYEND;

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: availableMemoryUnitATT | availableMemoryDescriptionATT;

availableMemoryUnitATT: UNITATT ATTRIBUTETEXT quote{};

availableMemoryDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

availableMemoryValue:
     INTEGER
   | DOUBLE;

availableCPUSpeed: AVAILABLECPUSPEEDSTART availableCPUSpeedAttList GREATERTHAN availableCPUSpeedValue 
                   AVAILABLECPUSPEEDEND;

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: availableCPUSpeedUnitATT | availableCPUSpeedDescriptionATT;

availableCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote{};

availableCPUSpeedDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

availableCPUSpeedValue:
     INTEGER
   | DOUBLE;


availableCPUNumber: AVAILABLECPUNUMBERSTART availableCPUNumberAttList GREATERTHAN availableCPUNumberValue 
                    AVAILABLECPUNUMBEREND;

availableCPUNumberAttList: | availableCPUNumberAttList availableCPUNumberDescriptionATT;

availableCPUNumberDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

availableCPUNumberValue:
     INTEGER
   | DOUBLE;


systemOtherResults: OTHERRESULTSSTART systemOtherResultsAttList systemOtherResultsBody;

systemOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote {std::cout << "!!!store numberOfOtherSystemResults" << std::endl;} ;

systemOtherResultsBody: systemOtherResultsEmpty | systemOtherResultsContent;

systemOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

systemOtherResultsContent: GREATERTHAN systemOtherResultList OTHERRESULTSEND;

systemOtherResultList: systemOtherResult | systemOtherResultList systemOtherResult; 

systemOtherResult: OTHERSTART systemOtherAttList systemOtherEnd;

systemOtherAttList: | systemOtherAttList systemOtherAtt;

systemOtherAtt: systemOtherNameATT | systemOtherValueATT | systemOtherDescriptionATT;

systemOtherNameATT: NAMEATT ATTRIBUTETEXT quote; 

systemOtherValueATT: VALUEATT ATTRIBUTETEXT quote
| EMPTYVALUEATT; 

systemOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
| EMPTYDESCRIPTIONATT; 

systemOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



serviceElement: | SERVICESTART ENDOFELEMENT
                | SERVICESTART GREATERTHAN serviceContent SERVICEEND;
                
serviceContent: | serviceContent serviceChild;
        
serviceChild: currentState | currentJobCount | totalJobsSoFar |
              timeServiceStarted | serviceUtilization | serviceOtherResults;

currentState:
  CURRENTSTATESTART GREATERTHAN ELEMENTTEXT CURRENTSTATEEND {}
| CURRENTSTATESTART GREATERTHAN CURRENTSTATEEND 
| CURRENTSTATESTART ENDOFELEMENT;

currentJobCount:
  CURRENTJOBCOUNTSTART GREATERTHAN INTEGER CURRENTJOBCOUNTEND {}
| CURRENTJOBCOUNTSTART GREATERTHAN CURRENTJOBCOUNTEND 
| CURRENTJOBCOUNTSTART ENDOFELEMENT;

totalJobsSoFar:
  TOTALJOBSSOFARSTART GREATERTHAN INTEGER TOTALJOBSSOFAREND {}
| TOTALJOBSSOFARSTART GREATERTHAN TOTALJOBSSOFAREND 
| TOTALJOBSSOFARSTART ENDOFELEMENT;

timeServiceStarted:
  TIMESERVICESTARTEDSTART GREATERTHAN ELEMENTTEXT TIMESERVICESTARTEDEND {}
| TIMESERVICESTARTEDSTART GREATERTHAN TIMESERVICESTARTEDEND 
| TIMESERVICESTARTEDSTART ENDOFELEMENT;

serviceUtilization:
  SERVICEUTILIZATIONSTART GREATERTHAN aNumber SERVICEUTILIZATIONEND {}
| SERVICEUTILIZATIONSTART GREATERTHAN SERVICEUTILIZATIONEND 
| SERVICEUTILIZATIONSTART ENDOFELEMENT;


serviceOtherResults:  OTHERRESULTSSTART serviceOtherResultsAttList serviceOtherResultsBody;

serviceOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;} ;

serviceOtherResultsBody: serviceOtherResultsEmpty | serviceOtherResultsContent;

serviceOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

serviceOtherResultsContent: GREATERTHAN serviceOtherResultList OTHERRESULTSEND;

serviceOtherResultList: serviceOtherResult | serviceOtherResultList serviceOtherResult; 

serviceOtherResult: OTHERSTART serviceOtherAttList serviceOtherEnd;

serviceOtherAttList: | serviceOtherAttList serviceOtherAtt;

serviceOtherAtt: serviceOtherNameATT | serviceOtherValueATT | serviceOtherDescriptionATT;

serviceOtherNameATT: NAMEATT ATTRIBUTETEXT quote; 

serviceOtherValueATT: VALUEATT ATTRIBUTETEXT quote
| EMPTYVALUEATT; 

serviceOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
| EMPTYDESCRIPTIONATT; 

serviceOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


jobElement: | JOBSTART ENDOFELEMENT
            | JOBSTART GREATERTHAN jobContent JOBEND;
            
jobContent: | jobContent jobChild;

jobChild: status | submitTime | scheduledStartTime | actualStartTime | endTime | 
          timingInformation | usedCPUSpeed | usedCPUNumber | usedDiskSpace | usedMemory | jobOtherResults;

status:
  STATUSSTART GREATERTHAN ELEMENTTEXT STATUSEND {}
| STATUSSTART GREATERTHAN STATUSEND 
| STATUSSTART ENDOFELEMENT;

submitTime:
  SUBMITTIMESTART GREATERTHAN ELEMENTTEXT SUBMITTIMEEND {}
| SUBMITTIMESTART GREATERTHAN SUBMITTIMEEND 
| SUBMITTIMESTART ENDOFELEMENT;

scheduledStartTime:
  SCHEDULEDSTARTTIMESTART GREATERTHAN ELEMENTTEXT SCHEDULEDSTARTTIMEEND {}
| SCHEDULEDSTARTTIMESTART GREATERTHAN SCHEDULEDSTARTTIMEEND 
| SCHEDULEDSTARTTIMESTART ENDOFELEMENT;

actualStartTime:
  ACTUALSTARTTIMESTART GREATERTHAN ELEMENTTEXT ACTUALSTARTTIMEEND {}
| ACTUALSTARTTIMESTART GREATERTHAN ACTUALSTARTTIMEEND 
| ACTUALSTARTTIMESTART ENDOFELEMENT;

endTime:
  ENDTIMESTART GREATERTHAN ELEMENTTEXT ENDTIMEEND {}
| ENDTIMESTART GREATERTHAN ENDTIMEEND 
| ENDTIMESTART ENDOFELEMENT;

timingInformation:
  TIMINGINFORMATIONSTART numberoftimes timingContent;

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
   | EMPTYTYPEATT ;

timeCategory: CATEGORYATT ATTRIBUTETEXT QUOTE {parserData->timeCategory = $2;  free($2);}
   | EMPTYCATEGORYATT ;

timeUnit: UNITATT ATTRIBUTETEXT QUOTE {parserData->timeUnit = $2;   free($2);}
   | EMPTYUNITATT ;

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


usedCPUSpeed: USEDCPUSPEEDSTART usedCPUSpeedAttList GREATERTHAN usedCPUSpeedValue 
              USEDCPUSPEEDEND;

usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: usedCPUSpeedUnitATT | usedCPUSpeedDescriptionATT;

usedCPUSpeedUnitATT: UNITATT ATTRIBUTETEXT quote{};

usedCPUSpeedDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

usedCPUSpeedValue:
     INTEGER
   | DOUBLE;


usedCPUNumber: USEDCPUNUMBERSTART usedCPUNumberAttList GREATERTHAN usedCPUNumberValue 
               USEDCPUNUMBEREND;

usedCPUNumberAttList: | usedCPUNumberAttList usedCPUNumberDescriptionATT;

usedCPUNumberDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

usedCPUNumberValue:
     INTEGER
   | DOUBLE;


usedDiskSpace: USEDDISKSPACESTART usedDiskSpaceAttList GREATERTHAN usedDiskSpaceValue 
               USEDDISKSPACEEND;

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: usedDiskSpaceUnitATT | usedDiskSpaceDescriptionATT;

usedDiskSpaceUnitATT: UNITATT ATTRIBUTETEXT quote{};

usedDiskSpaceDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

usedDiskSpaceValue:
     INTEGER
   | DOUBLE;

usedMemory: USEDMEMORYSTART usedMemoryAttList GREATERTHAN usedMemoryValue 
            USEDMEMORYEND;

usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: usedMemoryUnitATT | usedMemoryDescriptionATT;

usedMemoryUnitATT: UNITATT ATTRIBUTETEXT quote{};

usedMemoryDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote{}
| EMPTYDESCRIPTIONATT;

usedMemoryValue:
     INTEGER
   | DOUBLE;



jobOtherResults: OTHERRESULTSSTART jobOtherResultsAttList jobOtherResultsBody;

jobOtherResultsAttList: NUMBEROFOTHERRESULTSATT quote INTEGER quote {std::cout << "!!!store numberOfOtherjobResults" << std::endl;} ;

jobOtherResultsBody: jobOtherResultsEmpty | jobOtherResultsContent;

jobOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

jobOtherResultsContent: GREATERTHAN jobOtherResultList OTHERRESULTSEND;

jobOtherResultList: jobOtherResult | jobOtherResultList jobOtherResult; 

jobOtherResult: OTHERSTART jobOtherAttList jobOtherEnd;

jobOtherAttList: | jobOtherAttList jobOtherAtt;

jobOtherAtt: jobOtherNameATT | jobOtherValueATT | jobOtherDescriptionATT;

jobOtherNameATT: NAMEATT ATTRIBUTETEXT quote; 

jobOtherValueATT: VALUEATT ATTRIBUTETEXT quote
| EMPTYVALUEATT; 

jobOtherDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT quote
| EMPTYDESCRIPTIONATT; 

jobOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



optimizationElement: | OPTIMIZATIONSTART optimizationAttList optimizationBody;

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: optimizationNumberOfSolutionsATT quote
		| optimizationNumberOfVariablesATT quote          
		| optimizationNumberOfConstraintsATT quote
		| optimizationNumberOfObjectivesATT quote
		;


optimizationNumberOfSolutionsATT :  NUMBEROFSOLUTIONSATT   quote INTEGER  {parserData->numberOfSolutions   = $3; osresult->setSolutionNumber($3);} ;	
optimizationNumberOfVariablesATT :  NUMBEROFVARIABLESATT   quote INTEGER  {parserData->numberOfVariables   = $3; osresult->setVariableNumber($3); } ;
optimizationNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT quote INTEGER  {parserData->numberOfConstraints = $3; osresult->setConstraintNumber($3);} ;
optimizationNumberOfObjectivesATT : NUMBEROFOBJECTIVESATT  quote INTEGER  {parserData->numberOfObjectives  = $3; osresult->setObjectiveNumber($3);}  ;
	

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
};

solutionAttList: | solutionAttList solutionATT;

solutionATT: targetObjectiveIdxATT | weightedObjectivesATT;

targetObjectiveIdxATT: TARGETOBJECTIVEIDXATT quote INTEGER quote
{
	if($3 >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3);
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{ parserData->tempStr = $2; };

solutionBody: GREATERTHAN solutionStatus solutionMessage
          variables objectives  constraints  otherSolutionResults solutionEnd;

solutionStatus: STATUSSTART solutionStatusAttList solutionStatusContent;

solutionStatusAttList: solutionStatusATT
	| solutionStatusAttList solutionStatusATT;

solutionStatusATT: TYPEATT ATTRIBUTETEXT quote  {parserData->statusType = $2; parserData->statusTypePresent = true; free($2);}  
 |            EMPTYTYPEATT                      {parserData->statusType = ""; parserData->statusTypePresent = true;}  
 |          DESCRIPTIONATT ATTRIBUTETEXT quote  {parserData->statusDescription = $2;  free($2);}  
 |     EMPTYDESCRIPTIONATT                      {parserData->statusDescription = "";}  
 |  NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE  {};

solutionStatusContent: 
    solutionStatusEmpty 
    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	}
  | solutionStatusBody
	{	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	};

solutionStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT; 

solutionStatusBody: GREATERTHAN solutionSubstatusSEQ STATUSEND;

solutionSubstatusSEQ: solutionSubstatus | solutionSubstatusSEQ solutionSubstatus;

solutionSubstatus: SUBSTATUSSTART solutionSubstatusAttList solutionSubstatusEnd;

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: solutionSubstatusTypeATT | solutionSubstatusDescriptionATT;

solutionSubstatusTypeATT: TYPEATT ATTRIBUTETEXT QUOTE 
{ std::cout << "parsed <solutionSubstatus type=" << std::endl;
}; 

solutionSubstatusDescriptionATT: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
| EMPTYDESCRIPTIONATT; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 



solutionMessage:
| MESSAGESTART GREATERTHAN ELEMENTTEXT MESSAGEEND 
	{/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, $3); free($3);
	}
| MESSAGESTART GREATERTHAN MESSAGEEND
	{/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	}
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
	}
;

variablesBody: variablesEmpty | variablesContent;

variablesEmpty: ENDOFELEMENT;

variablesContent: GREATERTHAN variableValues variableValuesString basisStatus otherVariablesSEQ VARIABLESEND;

variableValues: 
| VALUESSTART numberOfVarATT GREATERTHAN varValueList VALUESEND
  {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
| VALUESSTART numberOfVarATT ENDOFELEMENT
  {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
;

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
	{
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = $3;
	}
; 

varValueList : | varValueList varValue;

varValue: VARSTART varIdxATT GREATERTHAN varVal VAREND; 

varIdxATT : IDXATT quote INTEGER quote { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $3;};
  
varVal: 
   INTEGER {parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  
   }
  | DOUBLE {parserData->tempVal = $1; 
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair); 
  };
  

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

