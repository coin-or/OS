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
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	};

generalStatusAttributes: generalStatusAttList
	{	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	};

generalStatusAttList: generalStatusATT | generalStatusAttList generalStatusATT;

generalStatusATT: 
    typeAttribute
    { 
	    if ((parserData->typeAttribute != "error"  ) &&
	        (parserData->typeAttribute != "warning") && 
	        (parserData->typeAttribute != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not match any legal value");
		osresult->setGeneralStatusType(parserData->typeAttribute); 
	}
  | descriptionAttribute 
	{   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
  | generalStatusNumberOfATT;


generalStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses($3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
};

generalStatusContent: 
	generalStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
  | generalStatusBody
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	};

generalStatusEmpty: GREATERTHAN GENERALSTATUSEND | ENDOFELEMENT; 

generalStatusBody:  GREATERTHAN generalSubstatusArray GENERALSTATUSEND;

generalSubstatusArray: generalSubstatus | generalSubstatusArray generalSubstatus;

generalSubstatus: generalSubstatusStart generalSubstatusAttributes generalSubstatusEnd
{	parserData->kounter++;
};	

generalSubstatusStart: SUBSTATUSSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};
		
generalSubstatusAttributes: generalSubstatusAttList		
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
};	

generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: 
	nameAttribute 
	{	
		osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
	} 
  | descriptionAttribute
	{	
		osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute);
	}; 

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

generalOtherResults: generalOtherResultsStart generalOtherResultsAttributes generalOtherResultsContent;

generalOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	};

generalOtherResultsAttributes: NUMBEROFOTHERRESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	osresult->setNumberOfOtherGeneralResults($3);
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

generalOtherResultsBody:  GREATERTHAN generalOtherResultArray OTHERRESULTSEND;

generalOtherResultArray: generalOtherResult | generalOtherResultArray generalOtherResult; 

generalOtherResult: generalOtherResultStart generalOtherAttributes generalOtherEnd
{	parserData->kounter++;
};	

generalOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

generalOtherAttributes: generalOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
};	

generalOtherAttList: | generalOtherAttList generalOtherAtt;

generalOtherAtt: 
	nameAttribute
	{	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	}
  | valueAttribute
	{	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	}
  | descriptionAttribute
	{	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	}
;

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

availableDiskSpace: availableDiskSpaceStart availableDiskSpaceAttributes availableDiskSpaceContent;

availableDiskSpaceStart: AVAILABLEDISKSPACESTART
	{	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};

availableDiskSpaceAttributes: availableDiskSpaceAttList;

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: 
	unitAttribute
	{	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableDiskSpaceContent: GREATERTHAN availableDiskSpaceValue AVAILABLEDISKSPACEEND;

availableDiskSpaceValue:
     INTEGER {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableDiskSpaceValue( $1);  parserData->errorText = NULL;};


availableMemory: availableMemoryStart availableMemoryAttributes availableMemoryContent;

availableMemoryStart: AVAILABLEMEMORYSTART
	{	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};

availableMemoryAttributes: availableMemoryAttList;

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: 
	unitAttribute 
	{	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableMemoryContent: GREATERTHAN availableMemoryValue AVAILABLEMEMORYEND;

availableMemoryValue:
     INTEGER {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableMemoryValue( $1);  parserData->errorText = NULL;};


availableCPUSpeed: availableCPUSpeedStart availableCPUSpeedAttributes availableCPUSpeedContent;

availableCPUSpeedStart: AVAILABLECPUSPEEDSTART
	{	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};

availableCPUSpeedAttributes: availableCPUSpeedAttList;

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: 
	unitAttribute 
	{	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableCPUSpeedContent: GREATERTHAN availableCPUSpeedValue AVAILABLECPUSPEEDEND;

availableCPUSpeedValue:
     INTEGER {osresult->setAvailableCPUSpeedValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setAvailableCPUSpeedValue( $1);  parserData->errorText = NULL;};


availableCPUNumber: availableCPUNumberStart availableCPUNumberAttributes availableCPUNumberContent;

availableCPUNumberStart: AVAILABLECPUNUMBERSTART
	{	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	};

availableCPUNumberAttributes: 
  | descriptionAttribute
	{	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableCPUNumberContent: GREATERTHAN availableCPUNumberValue AVAILABLECPUNUMBEREND;

availableCPUNumberValue:
     INTEGER {osresult->setAvailableCPUNumberValue( $1);  parserData->errorText = NULL;};


systemOtherResults: systemOtherResultsStart systemOtherResultsAttributes systemOtherResultsContent;

systemOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	};

systemOtherResultsAttributes: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults($3);
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

systemOtherResultsBody:  GREATERTHAN systemOtherResultArray OTHERRESULTSEND;

systemOtherResultArray: systemOtherResult | systemOtherResultArray systemOtherResult; 

systemOtherResult: systemOtherResultStart systemOtherAttributes systemOtherEnd
{	parserData->kounter++;
};	

systemOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

systemOtherAttributes: systemOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
};
	
systemOtherAttList: | systemOtherAttList systemOtherAtt;

systemOtherAtt:
	nameAttribute
	{	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	}
  | valueAttribute
	{	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	}
  | descriptionAttribute
	{	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	}
;

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
	{	parserData->tempStr = $2;
		if (parserData->tempStr != "busy"                &&
			parserData->tempStr != "busyButAccepting"    &&
			parserData->tempStr != "idle"                &&
			parserData->tempStr != "idleButNotAccepting" &&
			parserData->tempStr != "noResponse"             )
			osrlerror(NULL, NULL, parserData, "current system state not recognized");
		osresult->setCurrentState(parserData->tempStr); 
		parserData->errorText = NULL;
	}
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


serviceOtherResults: serviceOtherResultsStart serviceOtherResultsAttributes serviceOtherResultsContent;

serviceOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	};

serviceOtherResultsAttributes: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults($3);
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

serviceOtherResultsBody:  GREATERTHAN serviceOtherResultArray OTHERRESULTSEND;

serviceOtherResultArray: serviceOtherResult | serviceOtherResultArray serviceOtherResult; 

serviceOtherResult: serviceOtherResultStart serviceOtherAttributes serviceOtherEnd
{	parserData->kounter++;
};

serviceOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

serviceOtherAttributes: serviceOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
};
	
serviceOtherAttList: | serviceOtherAttList serviceOtherAtt;

serviceOtherAtt: 
	nameAttribute 
	{	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	}
  | valueAttribute 
	{	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	}
  | descriptionAttribute
	{	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	}
;
  
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
	{	parserData->tempStr = $2; free($2);
		if (parserData->tempStr != "waiting"  &&
			parserData->tempStr != "running"  &&
			parserData->tempStr != "killed"   &&
			parserData->tempStr != "finished" &&
			parserData->tempStr != "unknown"     )
			osrlerror (NULL, NULL, parserData, "status of this job not recognized");
		osresult->setJobStatus(parserData->tempStr);  
		parserData->errorText = NULL;
	}
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

timingInformation: timingInformationStart timingInformationAttributes timingInformationContent;

timingInformationStart: TIMINGINFORMATIONSTART
	{	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	};

timingInformationAttributes: NUMBEROFTIMESATT QUOTE INTEGER QUOTE 
{	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = $3;
	parserData->ivar = 0;
};

timingInformationContent: 
	timingInformationEmpty 
	{	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	}
  | timingInformationBody
	{	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	};

timingInformationEmpty: GREATERTHAN TIMINGINFORMATIONEND | ENDOFELEMENT;   

timingInformationBody:  GREATERTHAN timeArray TIMINGINFORMATIONEND;

timeArray: time | timeArray time;

time: timeStart timeAttributes timeContent;

timeStart: TIMESTART
{	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "";
	parserData->typeAttribute = "";
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
};

timeAttributes: | timeAttributes timeAtt;

timeAtt: 
	unitAttribute 
	{	if (parserData->unitAttribute != "tick"        &&
			parserData->unitAttribute != "millisecond" &&
			parserData->unitAttribute != "second"      &&
			parserData->unitAttribute != "minute"      &&
			parserData->unitAttribute != "hour"        &&
			parserData->unitAttribute != "day"         &&
			parserData->unitAttribute != "week"        &&
			parserData->unitAttribute != "month"       &&
			parserData->unitAttribute != "year"   )     
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	};
  | typeAttribute 
	{	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	}
  | categoryAttribute 
	{	if (parserData->categoryAttribute != "total"          &&
			parserData->categoryAttribute != "input"          &&
			parserData->categoryAttribute != "preprocessing"  &&
			parserData->categoryAttribute != "optimization"   &&
			parserData->categoryAttribute != "postprocessing" &&
			parserData->categoryAttribute != "output"         &&
 			parserData->categoryAttribute != "other"   )
			osrlerror(NULL, NULL, parserData, "time category not recognized");
	}
  | descriptionAttribute;


timeContent: timeEmpty | timeBody;

timeEmpty: GREATERTHAN TIMEEND  |  ENDOFELEMENT;

timeBody:  GREATERTHAN timeValue TIMEEND
{	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
}; 

timeValue:
  DOUBLE  { parserData->timeValue = $1; }
| INTEGER { parserData->timeValue = $1; };


usedDiskSpace: usedDiskSpaceStart usedDiskSpaceAttributes usedDiskSpaceContent;

usedDiskSpaceStart: USEDDISKSPACESTART
	{	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	};
	
usedDiskSpaceAttributes: usedDiskSpaceAttList;

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: 
	unitAttribute
	{	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setUsedDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedDiskSpaceContent: GREATERTHAN usedDiskSpaceValue USEDDISKSPACEEND;

usedDiskSpaceValue:
     INTEGER {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedDiskSpaceValue( $1);  parserData->errorText = NULL;};


usedMemory: usedMemoryStart usedMemoryAttributes usedMemoryContent;

usedMemoryStart: USEDMEMORYSTART
	{	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};
	
usedMemoryAttributes: usedMemoryAttList;
			
usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: 
	unitAttribute 
	{	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
		osresult->setUsedMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedMemoryContent: GREATERTHAN usedMemoryValue USEDMEMORYEND;

usedMemoryValue:
     INTEGER {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedMemoryValue( $1);  parserData->errorText = NULL;};


usedCPUSpeed: usedCPUSpeedStart usedCPUSpeedAttributes usedCPUSpeedContent;
              
usedCPUSpeedStart: USEDCPUSPEEDSTART
	{	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	};
              
usedCPUSpeedAttributes: usedCPUSpeedAttList;
	
usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: 
	unitAttribute 
	{	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setUsedCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedCPUSpeedContent: GREATERTHAN usedCPUSpeedValue USEDCPUSPEEDEND;

usedCPUSpeedValue:
     INTEGER {osresult->setUsedCPUSpeedValue( $1);  parserData->errorText = NULL;}
   | DOUBLE  {osresult->setUsedCPUSpeedValue( $1);  parserData->errorText = NULL;};


usedCPUNumber: usedCPUNumberStart usedCPUNumberAttributes usedCPUNumberContent;
               
usedCPUNumberStart: USEDCPUNUMBERSTART               
	{	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	};
               

usedCPUNumberAttributes: 
  | descriptionAttribute
	{	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedCPUNumberContent: GREATERTHAN usedCPUNumberValue USEDCPUNUMBEREND;

usedCPUNumberValue:
     INTEGER {osresult->setUsedCPUNumberValue( $1);  parserData->errorText = NULL;};



jobOtherResults: jobOtherResultsStart jobOtherResultsAttributes jobOtherResultsContent;

jobOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	};

jobOtherResultsAttributes: NUMBEROFOTHERRESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults($3);
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

jobOtherResultsBody:  GREATERTHAN jobOtherResultArray OTHERRESULTSEND;

jobOtherResultArray: jobOtherResult | jobOtherResultArray jobOtherResult; 

jobOtherResult: jobOtherResultStart jobOtherAttributes jobOtherEnd
{	parserData->kounter++;
};	

jobOtherResultStart: OTHERSTART
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

jobOtherAttributes: jobOtherAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
};

jobOtherAttList: | jobOtherAttList jobOtherAtt;

jobOtherAtt: 
	nameAttribute 
	{	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	}
 | valueAttribute 
	{	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	}
 | descriptionAttribute
	{	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	}
;

jobOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


optimizationElement: | optimizationStart optimizationAttributes optimizationContent;

optimizationStart: OPTIMIZATIONSTART
{	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
};

optimizationAttributes: optimizationAttList
{	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
};	

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
	optimizationNumberOfSolutionsATT   
  | optimizationNumberOfVariablesATT             
  | optimizationNumberOfConstraintsATT 
  | optimizationNumberOfObjectivesATT  
  ;

optimizationNumberOfSolutionsATT: NUMBEROFSOLUTIONSATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = $3; 
	osresult->setSolutionNumber($3);
	parserData->solutionIdx = 0;
};	

optimizationNumberOfVariablesATT: NUMBEROFVARIABLESATT quote INTEGER quote 
{	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = $3; 
	osresult->setVariableNumber($3);
};

optimizationNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = $3; 
	osresult->setConstraintNumber($3);
};

optimizationNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = $3; 
	osresult->setObjectiveNumber($3);
};
	
optimizationContent: 
	optimizationEmpty 
	{	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	}
  | optimizationBody
	{	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	};

optimizationEmpty: GREATERTHAN OPTIMIZATIONEND | ENDOFELEMENT;

optimizationBody: GREATERTHAN solutionArray otherSolverOutput OPTIMIZATIONEND;

solutionArray: solution | solutionArray solution;  

solution: solutionStart solutionAttributes solutionContent

solutionStart: SOLUTIONSTART
{
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
};

solutionAttributes: solutionAttList

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
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
};

solutionContent: GREATERTHAN solutionStatus solutionMessage
          variables objectives constraints otherSolutionResults SOLUTIONEND
	{
		parserData->solutionIdx++;
	};

solutionStatus: solutionStatusStart solutionStatusAttributes solutionStatusContent;

solutionStatusStart: STATUSSTART
	{	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	};

solutionStatusAttributes: solutionStatusAttList
	{	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	};

solutionStatusAttList: solutionStatusATT | solutionStatusAttList solutionStatusATT;

solutionStatusATT: 
	typeAttribute
	{   if ((parserData->typeAttribute != "unbounded"      ) && 
			(parserData->typeAttribute != "globallyOptimal") && 
	        (parserData->typeAttribute != "locallyOptimal" ) &&
	        (parserData->typeAttribute != "optimal"        ) && 
	        (parserData->typeAttribute != "bestSoFar"      ) &&
	        (parserData->typeAttribute != "feasible"       ) && 
	        (parserData->typeAttribute != "infeasible"     ) &&
	        (parserData->typeAttribute != "unsure"         ) && 
	        (parserData->typeAttribute != "error"          ) &&
	        (parserData->typeAttribute != "other"          ))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute); 
	}
  | descriptionAttribute
	{   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	}
  | solutionStatusNumberOfATT;	

solutionStatusNumberOfATT: NUMBEROFSUBSTATUSESATT QUOTE INTEGER QUOTE 
{   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, $3);
	parserData->numberOf = $3;
	parserData->kounter = 0;
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

solutionStatusBody:  GREATERTHAN solutionSubstatusArray STATUSEND;

solutionSubstatusArray: solutionSubstatus | solutionSubstatusArray solutionSubstatus;

solutionSubstatus: solutionSubstatusStart solutionSubstatusAttributes solutionSubstatusEnd
{	parserData->kounter++; };	

solutionSubstatusStart: SUBSTATUSSTART 
{	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

solutionSubstatusAttributes: solutionSubstatusAttList
{	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
};	

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: 
	typeAttribute 
	{	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	}; 
  | descriptionAttribute
	{	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	}; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


solutionMessage:
| MESSAGESTART GREATERTHAN ELEMENTTEXT MESSAGEEND 
	{	osresult->setSolutionMessage(parserData->solutionIdx, $3); free($3);
	}
| MESSAGESTART GREATERTHAN MESSAGEEND
| MESSAGESTART ENDOFELEMENT;


variables: | variablesStart numberOfOtherVariableResults variablesContent;

variablesStart: VARIABLESSTART
{	parserData->numberOfOtherVariableResults = 0; };

numberOfOtherVariableResults:
  | NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
	{	
		if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, $3);
		parserData->numberOfOtherVariableResults = $3;
		parserData->iOther = 0;
	};

variablesContent: ENDOFELEMENT | variablesBody;

variablesBody: GREATERTHAN variableValues variableValuesString basisStatus otherVariableResultsArray VARIABLESEND;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART;

numberOfVarATT: NUMBEROFVARATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = $3; 
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

variableValuesBody:  GREATERTHAN varValueArray VALUESEND;

varValueArray: varValue | varValueArray varValue;

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

variableValuesStringStart: VALUESSTRINGSTART;

numberOfVarStringATT: NUMBEROFVARATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = $3;
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
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

variableValuesStringBody: GREATERTHAN varValueStringArray VALUESSTRINGEND;

varValueStringArray: varValueString | varValueStringArray varValueString;

varValueString: varValueStringStart varStrIdxATT GREATERTHAN ELEMENTTEXT VAREND
{
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
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

basisStatusStart: BASISSTATUSSTART;

numberOfBasisVarATT : NUMBEROFVARATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = $3;
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

basisStatusBody: GREATERTHAN basisVarArray BASISSTATUSEND;

basisVarArray : basisVar | basisVarArray basisVar;

basisVar: basisVarStart basisVarIdxATT GREATERTHAN ELEMENTTEXT VAREND
{	parserData->tempStr = $4;
	if (parserData->tempStr != "unknown"  &&
		parserData->tempStr != "basic"    &&
		parserData->tempStr != "atLower"  &&
		parserData->tempStr != "atUpper"  &&
		parserData->tempStr != "superBasic" )
		osrlerror(NULL, NULL, parserData, "unrecognized basis status");
	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 	  parserData->idx,         parserData->tempStr);
	parserData->kounter++;
}; 

basisVarStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

basisVarIdxATT : IDXATT quote INTEGER quote { parserData->idx = $3; };
  

otherVariableResultsArray: | otherVariableResultsArray otherVariableResult;

otherVariableResult: otherVariableResultStart otherVariableResultAttributes otherVariableResultContent
	{ 	 
		parserData->iOther++;  
	}
;

otherVariableResultStart: OTHERSTART
{
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
}; 

otherVariableResultAttributes: otherVariableResultAttList 
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	};
	  
otherVariableResultAttList: | otherVariableResultAttList otherVariableResultATT;

otherVariableResultATT: 
	numberOfOtherVariableResultsATT 
  | valueAttribute
  {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
  }
  | nameAttribute 
  {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
  }
  | descriptionAttribute
  {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
  };
  
numberOfOtherVariableResultsATT: NUMBEROFVARATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = $3;
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, $3);
	parserData->kounter = 0;
}; 

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
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherVarContent: 
	GREATERTHAN ElementValue VAREND 
	{	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN VAREND 
  | ENDOFELEMENT;


objectives: | objectivesStart numberOfOtherObjectiveResults objectivesContent;

objectivesStart: OBJECTIVESSTART
{	parserData->numberOfOtherObjectiveResults = 0; };


numberOfOtherObjectiveResults:
  | NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
	{
		if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
		parserData->numberOfOtherObjectiveResults = $3;
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
	};

objectivesContent: ENDOFELEMENT | objectivesBody;

objectivesBody: GREATERTHAN objectiveValues otherObjectiveResultsArray OBJECTIVESEND;

objectiveValues: | objectiveValuesStart numberOfObjATT objectiveValuesContent;

objectiveValuesStart: VALUESSTART;

numberOfObjATT: NUMBEROFOBJATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = $3;
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
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

objectiveValuesBody:  GREATERTHAN objValueArray VALUESEND;


objValueArray: objValue | objValueArray objValue;

objValue: objValueStart objIdxATT GREATERTHAN objVal OBJEND
{	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
}; 

objValueStart: OBJSTART
{	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
};

objIdxATT: | IDXATT quote INTEGER quote { parserData->idx = $3; };

objVal:
   INTEGER {parserData->tempVal = $1; }
 | DOUBLE  {parserData->tempVal = $1; };



otherObjectiveResultsArray: | otherObjectiveResultsArray otherObjectiveResult;

otherObjectiveResult: otherObjectiveResultStart otherObjectiveResultAttributes otherObjectiveResultContent
	{ 	 
		parserData->iOther++;  
	}
;

otherObjectiveResultStart: OTHERSTART
	{
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}; 

otherObjectiveResultAttributes: otherObjectiveResultAttList
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	};


otherObjectiveResultAttList: | otherObjectiveResultAttList otherObjectiveResultATT;

otherObjectiveResultATT: 
	numberOfOtherObjectiveResultsATT 
  | valueAttribute 
  {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
  }
  | nameAttribute 
  {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
  }
  | descriptionAttribute
  {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
  };
  
numberOfOtherObjectiveResultsATT: NUMBEROFOBJATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = $3;
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, $3);
	parserData->kounter = 0;
}; 

otherObjectiveResultContent: ENDOFELEMENT
| GREATERTHAN otherObjList OTHEREND;

otherObjList: | otherObjList otherObj ;

otherObj: otherObjStart otherObjIdxATT  otherObjContent 
{  
	parserData->kounter++;
};

otherObjStart: OBJSTART; 

otherObjIdxATT: IDXATT quote INTEGER quote 
{	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherObjContent: 
	GREATERTHAN ElementValue OBJEND 
	{	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN OBJEND 
  | ENDOFELEMENT;



constraints: | constraintsStart numberOfOtherConstraintResults constraintsContent;

constraintsStart: CONSTRAINTSSTART
{		parserData->numberOfOtherObjectiveResults = 0; };

numberOfOtherConstraintResults:
  | NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
	{
		if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
		parserData->numberOfOtherConstraintResults = $3;
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
		parserData->iOther = 0;
	};

constraintsContent: ENDOFELEMENT | constraintsBody;

constraintsBody: GREATERTHAN dualValues otherConstraintResultsArray CONSTRAINTSEND;

dualValues: | dualValuesStart numberOfConATT dualValuesContent;

dualValuesStart: DUALVALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfConATT: NUMBEROFCONATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = $3;
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
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

dualValuesBody:  GREATERTHAN dualValueArray DUALVALUESEND;

dualValueArray: dualValue | dualValueArray dualValue;

dualValue: dualValueStart conIdxATT GREATERTHAN dualVal CONEND 
{	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
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

                         
otherConstraintResultsArray: | otherConstraintResultsArray otherConstraintResult;

otherConstraintResult: otherConstraintResultStart otherConstraintResultAttributes otherConstraintResultContent
	{ 	 
		parserData->iOther++;  
	}
;

otherConstraintResultStart: OTHERSTART
{
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
}; 

otherConstraintResultAttributes: otherConstraintResultAttList
	{	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	};

otherConstraintResultAttList: | otherConstraintResultAttList otherConstraintResultATT;

otherConstraintResultATT: 
	numberOfOtherConstraintResultATT 
  | valueAttribute 
  {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
  }
  | nameAttribute 
  {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
  }
  | descriptionAttribute
  {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
  };
  
numberOfOtherConstraintResultATT: NUMBEROFCONATT quote INTEGER quote
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = $3;
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, $3);
	parserData->kounter = 0;
}; 

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
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3);
};

otherConContent: 
	GREATERTHAN ElementValue CONEND 
	{	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	}
  | GREATERTHAN CONEND 
  | ENDOFELEMENT;



otherSolutionResults: | otherSolutionResultsStart numberOfOtherSolutionResults otherSolutionResultsContent;

otherSolutionResultsStart: OTHERSOLUTIONRESULTSSTART
{
	parserData->numberOf = 0; 
};

numberOfOtherSolutionResults: NUMBEROFOTHERSOLUTIONRESULTSATT quote INTEGER quote 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, $3);
	parserData->numberOf = $3;
	parserData->iOther = 0; 
};

otherSolutionResultsContent:
	otherSolutionResultsEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	}
  | otherSolutionResultsBody
	{	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	};

otherSolutionResultsEmpty: GREATERTHAN OTHERSOLUTIONRESULTSEND | ENDOFELEMENT;

otherSolutionResultsBody: GREATERTHAN otherSolutionResultArray OTHERSOLUTIONRESULTSEND; 

otherSolutionResultArray: otherSolutionResult | otherSolutionResultArray otherSolutionResult;

otherSolutionResult: otherSolutionResultStart otherSolutionResultAttributes otherSolutionResultContent
{	parserData->iOther++;
};	

otherSolutionResultStart: OTHERSOLUTIONRESULTSTART  
{	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

otherSolutionResultAttributes: otherSolutionResultAttList 
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
};	

otherSolutionResultAttList: | otherSolutionResultAttList otherSolutionResultAtt;

otherSolutionResultAtt: 
	nameAttribute 
	{	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	} 
  | categoryAttribute 
	{	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	} 
  | descriptionAttribute
	{	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
											 parserData->descriptionAttribute);
	}
  | numberOfOtherSolutionResultItems;
  
numberOfOtherSolutionResultItems : NUMBEROFITEMSATT QUOTE INTEGER QUOTE 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = $3;
	osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
												  parserData->numberOfItems);
	parserData->kounter = 0;
};

otherSolutionResultContent:
	otherSolutionResultEmpty
	{	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
  | otherSolutionResultBody
	{	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	};

otherSolutionResultEmpty: GREATERTHAN OTHERSOLUTIONRESULTEND | ENDOFELEMENT; 

otherSolutionResultBody:  GREATERTHAN otherSolutionResultItemArray OTHERSOLUTIONRESULTEND;

otherSolutionResultItemArray: otherSolutionResultItem | otherSolutionResultItemArray otherSolutionResultItem;

otherSolutionResultItem: otherSolutionResultItemContent
{	parserData->kounter++;
};	

otherSolutionResultItemContent: 
	otherSolutionResultItemEmpty
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
}	
  | otherSolutionResultItemBody; 


otherSolutionResultItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

otherSolutionResultItemBody: ITEMSTART ITEMTEXT ITEMEND
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = $2; free($2);
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
}
;




otherSolverOutput: | otherSolverOutputStart numberOfSolverOutputsATT otherSolverOutputContent;

otherSolverOutputStart: OTHERSOLVEROUTPUTSTART
{
	parserData->numberOf = 0; 
};

numberOfSolverOutputsATT: NUMBEROFSOLVEROUTPUTSATT quote INTEGER quote
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
    osresult->setNumberOfSolverOutputs($3);
	parserData->numberOf = $3;
	parserData->iOther = 0; 
};

otherSolverOutputContent: 
	otherSolverOutputEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	}
  | otherSolverOutputBody
	{	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	};

otherSolverOutputEmpty: GREATERTHAN OTHERSOLVEROUTPUTEND | ENDOFELEMENT;

otherSolverOutputBody:  GREATERTHAN solverOutputArray OTHERSOLVEROUTPUTEND;

solverOutputArray: solverOutput | solverOutputArray solverOutput;

solverOutput: solverOutputStart solverOutputAttributes solverOutputContent
{	parserData->iOther++;
};	

solverOutputStart: SOLVEROUTPUTSTART
{	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
};

solverOutputAttributes: solverOutputAttList
{	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
};	

solverOutputAttList: | solverOutputAttList solverOutputAtt;

solverOutputAtt: 
	numberOfSolverOutputItems 
  | nameAttribute
	{	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	} 
  | categoryAttribute
	{	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	} 
  | descriptionAttribute
	{	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	} 
  ;

numberOfSolverOutputItems: NUMBEROFITEMSATT QUOTE INTEGER QUOTE
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = $3;
	osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
	parserData->kounter = 0;
};

solverOutputContent: 
	solverOutputEmpty 
	{	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
  | solverOutputBody
	{	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	};

solverOutputEmpty: GREATERTHAN SOLVEROUTPUTEND | ENDOFELEMENT;

solverOutputBody:  GREATERTHAN solverOutputItemArray SOLVEROUTPUTEND;

solverOutputItemArray: solverOutputItem | solverOutputItemArray solverOutputItem;

solverOutputItem: solverOutputItemContent 
{	parserData->kounter++;
};	

solverOutputItemContent:
	solverOutputItemEmpty
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
}	
  | solverOutputItemBody; 
	
solverOutputItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOutputItemBody: ITEMSTART ITEMTEXT ITEMEND
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = $2; free($2);
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
}
;


categoryAttribute: categoryAttributeIdentifier categoryAttributeValue;

	categoryAttributeIdentifier: CATEGORYATT
		{   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		};
	
	categoryAttributeValue:	
		ATTRIBUTETEXT quote { parserData->categoryAttribute = $1; free($1);}   
		|             quote { parserData->categoryAttribute = "";          };

descriptionAttribute: descriptionAttributeIdentifier descriptionAttributeValue;

	descriptionAttributeIdentifier: DESCRIPTIONATT
		{   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		};
	
	descriptionAttributeValue:	
		ATTRIBUTETEXT quote { parserData->descriptionAttribute = $1; free($1);}   
		|             quote { parserData->descriptionAttribute = "";          };

nameAttribute: nameAttributeIdentifier nameAttributeValue;

	nameAttributeIdentifier: NAMEATT
		{   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		};
	
	nameAttributeValue:	
		ATTRIBUTETEXT quote { parserData->nameAttribute = $1; free($1);}   
		|             quote { parserData->nameAttribute = "";          };

typeAttribute: typeAttributeIdentifier typeAttributeValue;

	typeAttributeIdentifier: TYPEATT
		{   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		};
	
	typeAttributeValue:	
		ATTRIBUTETEXT quote { parserData->typeAttribute = $1; free($1);}   
		|             quote { parserData->typeAttribute = "";          };

unitAttribute: unitAttributeIdentifier unitAttributeValue;

	unitAttributeIdentifier: UNITATT
		{   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		};
	
	unitAttributeValue:	
		ATTRIBUTETEXT quote { parserData->unitAttribute = $1; free($1);}   
		|             quote { parserData->unitAttribute = "";          };

valueAttribute: valueAttributeIdentifier valueAttributeValue;

	valueAttributeIdentifier: VALUEATT
		{   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		};
	
	valueAttributeValue:	
		ATTRIBUTETEXT quote { parserData->valueAttribute = $1; free($1);}   
		|             quote { parserData->valueAttribute = "";          };


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

