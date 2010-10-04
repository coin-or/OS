/* $Id$ */
/** @file parseosrl.y
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.0, 19/07/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University and the University of Chicago.
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

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

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

void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg );
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


osrldoc: osrlStart osrlAttributes osrlContent;

osrlStart: OSRLSTART
{
#ifdef DEBUG
yydebug = 1;
#endif
}; 

osrlAttributes: | OSRLATTRIBUTETEXT;

osrlContent: GREATERTHAN osrlBody OSRLEND; 

osrlBody: generalElement systemElement serviceElement jobElement optimizationElement;


generalElement: | generalElementStart generalElementContent;

generalElementStart: GENERALSTART;

generalElementContent: generalElementEmpty | generalElementLaden;

generalElementEmpty: GREATERTHAN GENERALEND | ENDOFELEMENT;

generalElementLaden: GREATERTHAN generalElementBody GENERALEND; 

generalElementBody: generalElementList;

generalElementList: generalChild | generalElementList generalChild;

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
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting general status type");
	}
  | descriptionAttribute 
	{   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
  | numberOfSubstatusesAttribute
	{   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	};

generalStatusContent: 
	generalStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
  | generalStatusLaden
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	};

generalStatusEmpty:  GREATERTHAN GENERALSTATUSEND | ENDOFELEMENT; 

generalStatusLaden: GREATERTHAN generalStatusBody GENERALSTATUSEND;

generalStatusBody:   generalSubstatusArray;

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
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting <general> substatus name");
	} 
  | descriptionAttribute
	{	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting <general> substatus description");
	}; 

generalSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


generalMessage: generalMessageStart generalMessageContent;

generalMessageStart: MESSAGESTART
	{	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	};

generalMessageContent: generalMessageEmpty | generalMessageLaden;

generalMessageEmpty:  GREATERTHAN MESSAGEEND | ENDOFELEMENT;

generalMessageLaden: GREATERTHAN generalMessageBody MESSAGEEND;

generalMessageBody:   ELEMENTTEXT  
		{osresult->setGeneralMessage($1); free($1); parserData->errorText = NULL;};

serviceURI: serviceURIStart serviceURIContent;

serviceURIStart: SERVICEURISTART
	{	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	};

serviceURIContent: serviceURIEmpty | serviceURILaden;

serviceURIEmpty:  GREATERTHAN SERVICEURIEND | ENDOFELEMENT;

serviceURILaden: GREATERTHAN serviceURIBody SERVICEURIEND;

serviceURIBody:   ELEMENTTEXT  
		{osresult->setServiceURI($1); free($1); parserData->errorText = NULL;};

serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
	{	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	};

serviceNameContent: serviceNameEmpty | serviceNameLaden;

serviceNameEmpty:  GREATERTHAN SERVICENAMEEND | ENDOFELEMENT;

serviceNameLaden: GREATERTHAN serviceNameBody SERVICENAMEEND;

serviceNameBody:  ELEMENTTEXT  
		{osresult->setServiceName($1); free($1); parserData->errorText = NULL;};

instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
	{	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	};

instanceNameContent: instanceNameEmpty | instanceNameLaden;

instanceNameEmpty:  GREATERTHAN INSTANCENAMEEND | ENDOFELEMENT;

instanceNameLaden: GREATERTHAN instanceNameBody INSTANCENAMEEND;

instanceNameBody:  ELEMENTTEXT  
		{osresult->setInstanceName($1); free($1); parserData->errorText = NULL;};

jobID: jobIDStart jobIDContent;

jobIDStart: JOBIDSTART 
	{	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	};
	
jobIDContent: jobIDEmpty | jobIDLaden;

jobIDEmpty: GREATERTHAN JOBIDEND | ENDOFELEMENT;

jobIDLaden: GREATERTHAN jobIDBody JOBIDEND;

jobIDBody:  ELEMENTTEXT  
		{osresult->setJobID($1); free($1); parserData->errorText = NULL;};

solverInvoked: solverInvokedStart solverInvokedContent;

solverInvokedStart: SOLVERINVOKEDSTART 
	{	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	};

solverInvokedContent: solverInvokedEmpty | solverInvokedLaden;

solverInvokedEmpty: GREATERTHAN SOLVERINVOKEDEND | ENDOFELEMENT;

solverInvokedLaden: GREATERTHAN solverInvokedBody SOLVERINVOKEDEND;

solverInvokedBody:  ELEMENTTEXT  
		{osresult->setSolverInvoked($1); free($1); parserData->errorText = NULL;};

timeStamp: timeStampStart timeStampContent;
  
timeStampStart: TIMESTAMPSTART 
	{	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	};

timeStampContent: timeStampEmpty | timeStampLaden;

timeStampEmpty: GREATERTHAN TIMESTAMPEND | ENDOFELEMENT;

timeStampLaden: GREATERTHAN timeStampBody TIMESTAMPEND;

timeStampBody:  ELEMENTTEXT  
		{osresult->setTimeStamp($1); free($1); parserData->errorText = NULL;};

generalOtherResults: generalOtherResultsStart generalOtherResultsAttributes generalOtherResultsContent;

generalOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	};

generalOtherResultsAttributes: numberOfOtherResultsAttribute 
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

generalOtherResultsContent: 
	generalOtherResultsEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}  
  | generalOtherResultsLaden
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};
	
generalOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

generalOtherResultsLaden: GREATERTHAN generalOtherResultsBody OTHERRESULTSEND;

generalOtherResultsBody:   generalOtherResultArray;

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
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultName failed");
	}
  | valueAttribute
	{	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultDescription failed");
	}
;

generalOtherEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



systemElement: | systemElementStart systemElementContent;

systemElementStart: SYSTEMSTART;

systemElementContent: systemElementEmpty | systemElementLaden;

systemElementEmpty: GREATERTHAN SYSTEMEND | ENDOFELEMENT;

systemElementLaden: GREATERTHAN systemElementBody SYSTEMEND; 
          
systemElementBody: systemElementList;
               
systemElementList: systemChild | systemElementList systemChild; 

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
	
systemInformationContent: systemInformationEmpty | systemInformationLaden;

systemInformationEmpty: GREATERTHAN SYSTEMINFORMATIONEND | ENDOFELEMENT;

systemInformationLaden: GREATERTHAN systemInformationBody SYSTEMINFORMATIONEND;

systemInformationBody:  ELEMENTTEXT   
	{	osresult->setSystemInformation($1); 
		free($1); 
		parserData->errorText = NULL;
	};

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
	{
		if ( verifyStorageUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableDiskSpaceContent: GREATERTHAN availableDiskSpaceValue AVAILABLEDISKSPACEEND;

availableDiskSpaceValue: aNumber
{	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
};

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
	{
		if ( verifyStorageUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableMemoryContent: GREATERTHAN availableMemoryValue AVAILABLEMEMORYEND;

availableMemoryValue: aNumber
{	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
};


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
	{
//		if (parserData->unitAttribute != "terahertz" && 
//			parserData->unitAttribute != "gigahertz" && 
//			parserData->unitAttribute != "megahertz" && 
//			parserData->unitAttribute != "kilohertz" && 
//			parserData->unitAttribute != "hertz"     && 
//			parserData->unitAttribute != "petaflops" && 
//			parserData->unitAttribute != "teraflops" && 
//			parserData->unitAttribute != "gigaflops" && 
//			parserData->unitAttribute != "megaflops" && 
//			parserData->unitAttribute != "kiloflops" && 
//			parserData->unitAttribute != "flops" )
		if ( verifyCPUSpeedUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableCPUSpeedContent: GREATERTHAN availableCPUSpeedValue AVAILABLECPUSPEEDEND;

availableCPUSpeedValue: aNumber
{	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
};


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

availableCPUNumberValue: INTEGER 
{	osresult->setAvailableCPUNumberValue( $1);  parserData->errorText = NULL; };


systemOtherResults: systemOtherResultsStart systemOtherResultsAttributes systemOtherResultsContent;

systemOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	};

systemOtherResultsAttributes: numberOfOtherResultsAttribute
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

systemOtherResultsContent: 
	systemOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | systemOtherResultsLaden
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

systemOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

systemOtherResultsLaden: GREATERTHAN systemOtherResultsBody OTHERRESULTSEND;

systemOtherResultsBody:   systemOtherResultArray;

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
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultName failed");
	}
  | valueAttribute
	{	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultDescription failed");
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

currentStateContent: currentStateEmpty | currentStateLaden;

currentStateEmpty: GREATERTHAN CURRENTSTATEEND | ENDOFELEMENT;

currentStateLaden: GREATERTHAN currentStateBody CURRENTSTATEEND;

currentStateBody:  ELEMENTTEXT  
    {   parserData->tempStr = $1; free($1);
		if (parserData->tempStr != "busy"                &&
			parserData->tempStr != "busyButAccepting"    &&
			parserData->tempStr != "idle"                &&
			parserData->tempStr != "idleButNotAccepting" &&
			parserData->tempStr != "noResponse"             )
			osrlerror(NULL, NULL, parserData, "current system state not recognized");
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setCurrentState failed");
		parserData->errorText = NULL;
	};

currentJobCount: currentJobCountStart currentJobCountContent;

currentJobCountStart: CURRENTJOBCOUNTSTART
	{	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	};

currentJobCountContent: currentJobCountEmpty | currentJobCountLaden;

currentJobCountEmpty: GREATERTHAN CURRENTJOBCOUNTEND | ENDOFELEMENT;

currentJobCountLaden: GREATERTHAN currentJobCountBody CURRENTJOBCOUNTEND;

currentJobCountBody:  INTEGER  
	{ osresult->setCurrentJobCount($1); parserData->errorText = NULL; };

totalJobsSoFar: totalJobsSoFarStart totalJobsSoFarContent;

totalJobsSoFarStart: TOTALJOBSSOFARSTART 
	{	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	};

totalJobsSoFarContent: totalJobsSoFarEmpty | totalJobsSoFarLaden;

totalJobsSoFarEmpty: GREATERTHAN TOTALJOBSSOFAREND | ENDOFELEMENT;

totalJobsSoFarLaden: GREATERTHAN totalJobsSoFarBody TOTALJOBSSOFAREND;

totalJobsSoFarBody:  INTEGER  
	{ osresult->setTotalJobsSoFar($1); parserData->errorText = NULL; };

timeServiceStarted: timeServiceStartedStart timeServiceStartedContent;

timeServiceStartedStart: TIMESERVICESTARTEDSTART 
	{	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	};

timeServiceStartedContent: timeServiceStartedEmpty | timeServiceStartedLaden;

timeServiceStartedEmpty: GREATERTHAN TIMESERVICESTARTEDEND | ENDOFELEMENT;

timeServiceStartedLaden: GREATERTHAN timeServiceStartedBody TIMESERVICESTARTEDEND;

timeServiceStartedBody:  ELEMENTTEXT  
		{osresult->setTimeServiceStarted($1); free($1); parserData->errorText = NULL;};

serviceUtilization: serviceUtilizationStart serviceUtilizationContent;

serviceUtilizationStart: SERVICEUTILIZATIONSTART 
	{	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	};

serviceUtilizationContent: serviceUtilizationEmpty | serviceUtilizationLaden;

serviceUtilizationEmpty: GREATERTHAN SERVICEUTILIZATIONEND | ENDOFELEMENT;

serviceUtilizationLaden: GREATERTHAN serviceUtilizationBody SERVICEUTILIZATIONEND;

serviceUtilizationBody:  aNumber  
{	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, "setServiceUtilization failed");
	parserData->errorText = NULL;
};
serviceOtherResults: serviceOtherResultsStart serviceOtherResultsAttributes serviceOtherResultsContent;

serviceOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	};

serviceOtherResultsAttributes: numberOfOtherResultsAttribute
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

serviceOtherResultsContent: 
	serviceOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | serviceOtherResultsLaden
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

serviceOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

serviceOtherResultsLaden: GREATERTHAN serviceOtherResultsBody OTHERRESULTSEND

serviceOtherResultsBody:   serviceOtherResultArray;

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
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultName failed");
	}
  | valueAttribute 
	{	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultDescription failed");
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

jobStatusContent: jobStatusEmpty | jobStatusLaden;

jobStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT;

jobStatusLaden: GREATERTHAN jobStatusBody STATUSEND;

jobStatusBody:  ELEMENTTEXT  
	{	parserData->tempStr = $1; free($1);
		if (parserData->tempStr != "waiting"  &&
			parserData->tempStr != "running"  &&
			parserData->tempStr != "killed"   &&
			parserData->tempStr != "finished" &&
			parserData->tempStr != "unknown"     )
			osrlerror (NULL, NULL, parserData, "status of this job not recognized");
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setJobStatus failed");
		parserData->errorText = NULL;
	};

submitTime: submitTimeStart submitTimeContent;

submitTimeStart: SUBMITTIMESTART 
	{	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	};

submitTimeContent: submitTimeEmpty | submitTimeLaden;

submitTimeEmpty: GREATERTHAN SUBMITTIMEEND | ENDOFELEMENT;

submitTimeLaden: GREATERTHAN submitTimeBody SUBMITTIMEEND

submitTimeBody:  ELEMENTTEXT  
		{osresult->setJobSubmitTime($1); free($1); parserData->errorText = NULL;};

scheduledStartTime: scheduledStartTimeStart scheduledStartTimeContent;

scheduledStartTimeStart: SCHEDULEDSTARTTIMESTART 
	{	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	};

scheduledStartTimeContent: scheduledStartTimeEmpty | scheduledStartTimeLaden;

scheduledStartTimeEmpty: GREATERTHAN SCHEDULEDSTARTTIMEEND | ENDOFELEMENT;

scheduledStartTimeLaden: GREATERTHAN scheduledStartTimeBody SCHEDULEDSTARTTIMEEND;

scheduledStartTimeBody:  ELEMENTTEXT  
		{osresult->setScheduledStartTime($1); free($1); parserData->errorText = NULL;};

actualStartTime: actualStartTimeStart actualStartTimeContent;

actualStartTimeStart: ACTUALSTARTTIMESTART 
	{	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	};

actualStartTimeContent: actualStartTimeEmpty | actualStartTimeLaden;

actualStartTimeEmpty: GREATERTHAN ACTUALSTARTTIMEEND | ENDOFELEMENT;

actualStartTimeLaden: GREATERTHAN actualStartTimeBody ACTUALSTARTTIMEEND;

actualStartTimeBody:  ELEMENTTEXT   
		{osresult->setActualStartTime($1); free($1);  parserData->errorText = NULL;};

endTime: endTimeStart endTimeContent;

endTimeStart: ENDTIMESTART 
	{	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	};

endTimeContent: endTimeEmpty | endTimeLaden;

endTimeEmpty: GREATERTHAN ENDTIMEEND | ENDOFELEMENT;

endTimeLaden: GREATERTHAN endTimeBody ENDTIMEEND;

endTimeBody:  ELEMENTTEXT   
		{osresult->setJobEndTime($1); free($1);  parserData->errorText = NULL;};

timingInformation: timingInformationStart timingInformationAttributes timingInformationContent;

timingInformationStart: TIMINGINFORMATIONSTART
	{	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	};

timingInformationAttributes: numberOfTimesAttribute 
{	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
};

timingInformationContent: 
	timingInformationEmpty 
	{	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	}
  | timingInformationLaden
	{	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	};

timingInformationEmpty: GREATERTHAN TIMINGINFORMATIONEND | ENDOFELEMENT;   

timingInformationLaden: GREATERTHAN timingInformationBody TIMINGINFORMATIONEND;

timingInformationBody:   timeArray;

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
	{
 		if ( verifyTimeUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	};
  | typeAttribute 
	{
		if (parserData->typeAttribute != "cpuTime"     &&
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


timeContent: timeEmpty | timeLaden;

timeEmpty: GREATERTHAN TIMEEND | ENDOFELEMENT;

timeLaden: GREATERTHAN timeBody TIMEEND;

timeBody:   timeValue 
{	osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
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
	{
		if ( verifyStorageUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setUsedDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedDiskSpaceContent: GREATERTHAN usedDiskSpaceValue USEDDISKSPACEEND;

usedDiskSpaceValue: aNumber
{	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


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
	{
		if ( verifyStorageUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
		osresult->setUsedMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedMemoryContent: GREATERTHAN usedMemoryValue USEDMEMORYEND;

usedMemoryValue: aNumber
{	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


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
	{
//		if (parserData->unitAttribute != "terahertz" && 
//			parserData->unitAttribute != "gigahertz" && 
//			parserData->unitAttribute != "megahertz" && 
//			parserData->unitAttribute != "kilohertz" && 
//			parserData->unitAttribute != "hertz"     && 
//			parserData->unitAttribute != "petaflops" && 
//			parserData->unitAttribute != "teraflops" && 
//			parserData->unitAttribute != "gigaflops" && 
//			parserData->unitAttribute != "megaflops" && 
//			parserData->unitAttribute != "kiloflops" && 
//			parserData->unitAttribute != "flops" )
		if ( verifyCPUSpeedUnit(parserData->unitAttribute) == 0)
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setUsedCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedCPUSpeedContent: GREATERTHAN usedCPUSpeedValue USEDCPUSPEEDEND;

usedCPUSpeedValue: aNumber
{	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


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

usedCPUNumberValue: INTEGER 
{ osresult->setUsedCPUNumberValue( $1);  parserData->errorText = NULL; };



jobOtherResults: jobOtherResultsStart jobOtherResultsAttributes jobOtherResultsContent;

jobOtherResultsStart: OTHERRESULTSSTART
	{	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	};

jobOtherResultsAttributes: numberOfOtherResultsAttribute 
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

jobOtherResultsContent: 
	jobOtherResultsEmpty
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
  | jobOtherResultsLaden
	{	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	};

jobOtherResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

jobOtherResultsLaden: GREATERTHAN jobOtherResultsBody OTHERRESULTSEND;

jobOtherResultsBody:   jobOtherResultArray;

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
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultName failed");
	}
 | valueAttribute 
	{	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultValue failed");
	}
 | descriptionAttribute
	{	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultDescription failed");
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
	numberOfSolutionsAttribute 
	{
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	}
  | numberOfVariablesAttribute 
	{	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setVariableNumber failed");
	}             
  | numberOfConstraintsAttribute 
	{
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setConstraintNumber failed");
	} 
  | numberOfObjectivesAttribute 
	{	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setObjectiveNumber failed");
	};
	
optimizationContent: 
	optimizationEmpty 
	{	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	}
  | optimizationLaden
	{	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	};

optimizationEmpty: GREATERTHAN OPTIMIZATIONEND | ENDOFELEMENT;

optimizationLaden: GREATERTHAN optimizationBody OPTIMIZATIONEND;

optimizationBody:  solutionArray otherSolverOutput;

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
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3) == false)
		osrlerror(NULL, NULL, parserData, "setSolutionTargetObjectiveIdx failed");
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = $2; free($2);
	if (parserData->tempStr == "true")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionWeightedObjectives failed");
	}
	else if (parserData->tempStr == "false")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionWeightedObjectives failed");
	}
	else
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
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
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionStatusType failed");
	}
  | descriptionAttribute
	{   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionStatusDescription failed");
	}
  | numberOfSubstatusesAttribute
	{	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	};
	
  
solutionStatusContent: 
    solutionStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
  | solutionStatusLaden
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	}
;

solutionStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT; 

solutionStatusLaden: GREATERTHAN solutionStatusBody STATUSEND;

solutionStatusBody:   solutionSubstatusArray;

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
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionSubstatusType failed");
	}; 
  | descriptionAttribute
	{	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionSubstatusDescription failed");
	}; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


solutionMessage: | solutionMessageStart solutionMessageContent;

solutionMessageStart: MESSAGESTART;

solutionMessageContent: solutionMessageEmpty | solutionMessageLaden;

solutionMessageEmpty: GREATERTHAN MESSAGEEND | ENDOFELEMENT;

solutionMessageLaden: GREATERTHAN solutionMessageBody MESSAGEEND;

solutionMessageBody:  ELEMENTTEXT  
	{	parserData->tempStr = $1;
        free($1);
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	};

variables: | variablesStart numberOfOtherVariableResults variablesContent;

variablesStart: VARIABLESSTART
{	parserData->numberOfOtherVariableResults = 0; };

numberOfOtherVariableResults: | numberOfOtherVariableResultsAttribute
{	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
};

variablesContent: variablesEmpty | variablesLaden;

variablesEmpty: ENDOFELEMENT;

variablesLaden: GREATERTHAN variablesBody VARIABLESEND;

variablesBody:  variableValues variableValuesString basisStatus otherVariableResultsArray;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART;

numberOfVarATT: numberOfVarAttribute 
{
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
}; 

variableValuesContent: 
	variableValuesEmpty 
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | variableValuesLaden
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	};
 
variableValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

variableValuesLaden: GREATERTHAN variableValuesBody VALUESEND;

variableValuesBody:   varValueArray;

varValueArray: varValue | varValueArray varValue;

varValue: varValueStart  varIdxATT varValueContent
{	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, "setVarValue failed");
	parserData->kounter++;
}; 

varValueStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

varIdxATT: IDXATT quote INTEGER quote {	parserData->idx = $3; };

varValueContent: GREATERTHAN varVal VAREND;
  
varVal: 
	INTEGER {parserData->tempVal = $1; }
  | DOUBLE  {parserData->tempVal = $1; };
  

variableValuesString: | variableValuesStringStart numberOfVarStringATT variableValuesStringContent;

variableValuesStringStart: VALUESSTRINGSTART;

numberOfVarStringATT: numberOfVarAttribute 
{
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
}; 

variableValuesStringContent: 
	variableValuesStringEmpty 
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | variableValuesStringLaden
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	};

variableValuesStringEmpty: GREATERTHAN VALUESSTRINGEND | ENDOFELEMENT; 

variableValuesStringLaden: GREATERTHAN variableValuesStringBody VALUESSTRINGEND;

variableValuesStringBody:  varValueStringArray;

varValueStringArray: varValueString | varValueStringArray varValueString;

varValueString: varValueStringStart varStrIdxATT varValueStringContent
{
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setVarValueString failed");
	parserData->kounter++;
}; 

varValueStringStart: VARSTART 
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

varStrIdxATT: IDXATT quote INTEGER quote { parserData->idx = $3; };
  
varValueStringContent: 
	varValueStringEmpty {parserData->tempStr = "";};
  | varValueStringLaden; 
  
varValueStringEmpty: GREATERTHAN VAREND | ENDOFELEMENT;

varValueStringLaden: GREATERTHAN varValueStringBody VAREND;

varValueStringBody: ELEMENTTEXT 
	{parserData->tempStr = $1; free($1);};
  
basisStatus: | basisStatusStart numberOfBasisVarATT basisStatusContent;

basisStatusStart: BASISSTATUSSTART;

numberOfBasisVarATT : numberOfVarAttribute
{
	if (osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfBasisVar failed");
	parserData->kounter = 0;
}; 

basisStatusContent:
	basisStatusEmpty
	{	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
  | basisStatusLaden
	{	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	};

basisStatusEmpty: GREATERTHAN BASISSTATUSEND | ENDOFELEMENT;

basisStatusLaden: GREATERTHAN basisStatusBody BASISSTATUSEND;

basisStatusBody:  basisVarArray;

basisVarArray : basisVar | basisVarArray basisVar;

basisVar: basisVarStart basisVarIdxATT basisVarContent; 

basisVarStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
};

basisVarIdxATT : IDXATT quote INTEGER quote { parserData->idx = $3; };
  
basisVarContent: GREATERTHAN ELEMENTTEXT VAREND
{   parserData->tempStr = $2; free($2);
	if (parserData->tempStr != "unknown"  &&
		parserData->tempStr != "basic"    &&
		parserData->tempStr != "atLower"  &&
		parserData->tempStr != "atUpper"  &&
		parserData->tempStr != "superBasic" )
		osrlerror(NULL, NULL, parserData, "unrecognized basis status");
	if (osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setBasisVar failed");
	parserData->kounter++;
}; 

otherVariableResultsArray: | otherVariableResultsArray otherVariableResult;

otherVariableResult: otherVariableResultStart otherVariableResultAttributes otherVariableResultContent
	{ 	 
		parserData->iOther++;
	};

otherVariableResultStart: OTHERSTART
{
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, "more <otherVariableResults> than specified");
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
	numberOfVarAttribute 
	{	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
		parserData->numberAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	} 
  | valueAttribute
    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultValue failed");
    }
  | nameAttribute 
    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultName failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultDescription failed");
    };
  
otherVariableResultContent: otherVariableResultEmpty | otherVariableResultLaden;

otherVariableResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableResultLaden: GREATERTHAN otherVariableResultBody OTHEREND;

otherVariableResultBody:  otherVarList;

otherVarList: otherVar | otherVarList otherVar;

otherVar: otherVarStart otherVarIdxATT otherVarContent 
{ 	
	parserData->kounter++;
};

otherVarStart: VARSTART; 

otherVarIdxATT: IDXATT quote INTEGER quote 
{	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, $3) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultVarIdx failed");
};

otherVarContent: otherVarEmpty | otherVarLaden;

otherVarEmpty: GREATERTHAN VAREND | ENDOFELEMENT;

otherVarLaden: GREATERTHAN otherVarBody VAREND;

otherVarBody:  ElementValue  
	{	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultVar failed");
	};

objectives: | objectivesStart numberOfOtherObjectiveResults objectivesContent;

objectivesStart: OBJECTIVESSTART
{	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
};


numberOfOtherObjectiveResults: | numberOfOtherObjectiveResultsAttribute
{
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
};

objectivesContent: objectivesEmpty | objectivesLaden;

objectivesEmpty: ENDOFELEMENT;

objectivesLaden: GREATERTHAN objectivesBody OBJECTIVESEND;

objectivesBody:  objectiveValues otherObjectiveResultsArray;

objectiveValues: | objectiveValuesStart numberOfObjATT objectiveValuesContent;

objectiveValuesStart: VALUESSTART;

numberOfObjATT: numberOfObjAttribute
{
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}; 

objectiveValuesContent: 
	objectiveValuesEmpty 
	{	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	}
  | objectiveValuesLaden
	{	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	};
 
objectiveValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

objectiveValuesLaden: GREATERTHAN objectiveValuesBody VALUESEND;

objectiveValuesBody:   objValueArray;


objValueArray: objValue | objValueArray objValue;

objValue: objValueStart objIdxATT objValueContent
{	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, "setObjValue failed");
	parserData->kounter++;
}; 

objValueStart: OBJSTART
{	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
};

objIdxATT: | IDXATT quote INTEGER quote { parserData->idx = $3; };

objValueContent: GREATERTHAN objVal OBJEND;

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
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, "more <otherObjectiveResults> than specified");
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
	numberOfObjAttribute 
	{	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
		parserData->numberAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	}
  | valueAttribute 
    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultValue failed");
    }
  | nameAttribute 
    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultName failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultDescription failed");
    };
  
otherObjectiveResultContent: otherObjectiveResultEmpty | otherObjectiveResultLaden;

otherObjectiveResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherObjectiveResultLaden: GREATERTHAN otherObjectiveResultBody OTHEREND;

otherObjectiveResultBody:   otherObjList;

otherObjList: otherObj | otherObjList otherObj;

otherObj: otherObjStart otherObjIdxATT  otherObjContent 
{  
	parserData->kounter++;
};

otherObjStart: OBJSTART; 

otherObjIdxATT: IDXATT quote INTEGER quote 
{	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3) == false)
		osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultObjIdx failed");
};

otherObjContent: otherObjEmpty | otherObjLaden;

otherObjEmpty: GREATERTHAN OBJEND | ENDOFELEMENT;

otherObjLaden: GREATERTHAN otherObjBody OBJEND

otherObjBody:  ElementValue  
	{	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultObj failed");
	};


constraints: | constraintsStart numberOfOtherConstraintResults constraintsContent;

constraintsStart: CONSTRAINTSSTART
{	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
};

numberOfOtherConstraintResults: | numberOfOtherConstraintResultsAttribute
{
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
};

constraintsContent: constraintsEmpty | constraintsLaden;

constraintsEmpty: ENDOFELEMENT;

constraintsLaden: GREATERTHAN constraintsBody CONSTRAINTSEND;

constraintsBody:  dualValues otherConstraintResultsArray;

dualValues: | dualValuesStart numberOfConATT dualValuesContent;

dualValuesStart: DUALVALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfConATT: numberOfConAttribute
{
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
};

dualValuesContent:
	dualValuesEmpty 
	{	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	}
  | dualValuesLaden
	{	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	};

dualValuesEmpty: GREATERTHAN DUALVALUESEND | ENDOFELEMENT; 

dualValuesLaden: GREATERTHAN dualValuesBody DUALVALUESEND;

dualValuesBody:  dualValueArray;

dualValueArray: dualValue | dualValueArray dualValue;

dualValue: dualValueStart conIdxATT GREATERTHAN dualVal CONEND 
{	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, "setDualValue failed");
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
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, "more <otherConstraintResults> than specified");
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
	numberOfConAttribute
	{	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
		parserData->numberAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	} 
  | valueAttribute 
    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultValue failed");
    }
  | nameAttribute 
    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultName failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultDescription failed");
    };
  
otherConstraintResultContent: otherConstraintResultEmpty | otherConstraintResultLaden;

otherConstraintResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT	

otherConstraintResultLaden: GREATERTHAN otherConstraintResultBody OTHEREND;

otherConstraintResultBody:   otherConList;

otherConList: otherCon | otherConList otherCon;

otherCon: otherConStart otherConIdxATT  otherConContent 
{ 	
	parserData->kounter++;
};
  
otherConStart: CONSTART;

otherConIdxATT: IDXATT quote INTEGER quote
{	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, $3) == false)
		osrlerror(NULL, NULL, parserData, "setOtherConstraintResultConIdx failed");
};

otherConContent: otherConEmpty | otherConLaden;

otherConEmpty: GREATERTHAN CONEND | ENDOFELEMENT;

otherConLaden: GREATERTHAN otherConBody CONEND;

otherConBody:  ElementValue  
	{	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultCon failed");
	};


otherSolutionResults: | otherSolutionResultsStart numberOfOtherSolutionResults otherSolutionResultsContent;

otherSolutionResultsStart: OTHERSOLUTIONRESULTSSTART
{
	parserData->numberOf = 0; 
};

numberOfOtherSolutionResults: numberOfOtherSolutionResultsAttribute
{	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
};

otherSolutionResultsContent:
	otherSolutionResultsEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	}
  | otherSolutionResultsLaden
	{	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	};

otherSolutionResultsEmpty: GREATERTHAN OTHERSOLUTIONRESULTSEND | ENDOFELEMENT;

otherSolutionResultsLaden: GREATERTHAN otherSolutionResultsBody OTHERSOLUTIONRESULTSEND;

otherSolutionResultsBody:  otherSolutionResultArray; 

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
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultName failed");
	} 
  | categoryAttribute 
	{	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultCategory failed");
	} 
  | descriptionAttribute
	{	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultDescription failed");
	}
  | numberOfItemsAttribute
	{	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	};

otherSolutionResultContent:
	otherSolutionResultEmpty
	{	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
  | otherSolutionResultLaden
	{	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	};

otherSolutionResultEmpty: GREATERTHAN OTHERSOLUTIONRESULTEND | ENDOFELEMENT; 

otherSolutionResultLaden: GREATERTHAN otherSolutionResultBody OTHERSOLUTIONRESULTEND;

otherSolutionResultBody:   otherSolutionResultItemArray;

otherSolutionResultItemArray: otherSolutionResultItem | otherSolutionResultItemArray otherSolutionResultItem;

otherSolutionResultItem: otherSolutionResultItemContent
{	parserData->kounter++;
};	

otherSolutionResultItemContent: 
	otherSolutionResultItemEmpty
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
}	
  | otherSolutionResultItemLaden; 

otherSolutionResultItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

otherSolutionResultItemLaden: ITEMSTART otherSolutionResultItemBody ITEMEND;

otherSolutionResultItemBody:  ITEMTEXT 
{	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = $1; free($1);
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultItem failed");
};


otherSolverOutput: | otherSolverOutputStart numberOfSolverOutputsATT otherSolverOutputContent;

otherSolverOutputStart: OTHERSOLVEROUTPUTSTART
{
	parserData->numberOf = 0; 
};

numberOfSolverOutputsATT: numberOfSolverOutputsAttribute
{	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
};

otherSolverOutputContent: 
	otherSolverOutputEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	}
  | otherSolverOutputLaden
	{	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	};

otherSolverOutputEmpty: GREATERTHAN OTHERSOLVEROUTPUTEND | ENDOFELEMENT;

otherSolverOutputLaden: GREATERTHAN otherSolverOutputBody OTHERSOLVEROUTPUTEND;

otherSolverOutputBody:   solverOutputArray;

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
	 nameAttribute
	{	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputName failed");
	} 
  | categoryAttribute
	{	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputCategory failed");
	} 
  | descriptionAttribute
	{	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputDescription failed");
	}
  | numberOfItemsAttribute
	{	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	};

solverOutputContent: 
	solverOutputEmpty 
	{	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
  | solverOutputLaden
	{	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	};

solverOutputEmpty: GREATERTHAN SOLVEROUTPUTEND | ENDOFELEMENT;

solverOutputLaden: GREATERTHAN solverOutputBody SOLVEROUTPUTEND;

solverOutputBody:  solverOutputItemArray;

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
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, "setSolverOutputItem failed");
}
;


categoryAttribute: categoryAtt
		{   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		};

categoryAtt: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{ parserData->categoryAttribute = ""; };

categoryAttContent: CATEGORYATT ATTRIBUTETEXT quote 
{ parserData->categoryAttribute = $2; free($2); };

descriptionAttribute: descriptionAtt
		{   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		};

descriptionAtt: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ parserData->descriptionAttribute = ""; };

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT quote 
{ parserData->descriptionAttribute = $2; free($2);};


nameAttribute: nameAtt
		{   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		};

nameAtt: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
{ parserData->nameAttribute = ""; };

nameAttContent: NAMEATT ATTRIBUTETEXT quote 
{ parserData->nameAttribute = $2; free($2);};

typeAttribute: typeAtt
		{   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		};

typeAtt: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{ parserData->typeAttribute = ""; };

typeAttContent: TYPEATT ATTRIBUTETEXT quote 
{ parserData->typeAttribute = $2; free($2);};

unitAttribute: unitAtt
		{   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		};
		
unitAtt: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ parserData->unitAttribute = ""; };

unitAttContent: UNITATT ATTRIBUTETEXT quote 
{ parserData->unitAttribute = $2; free($2);};

valueAttribute: valueAtt
		{   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		};

valueAtt: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ parserData->valueAttribute = ""; };

valueAttContent: VALUEATT ATTRIBUTETEXT quote 
{ parserData->valueAttribute = $2; free($2);};

numberOfOtherResultsAttribute: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{
	parserData->tempInt = $3;
};

numberOfSolutionsAttribute: NUMBEROFSOLUTIONSATT quote INTEGER quote 
{	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = $3; 
};	

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = $3; 
};

numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = $3; 
};

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = $3; 
};

numberOfOtherVariableResultsAttribute: NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherObjectiveResultsAttribute: NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherConstraintResultsAttribute: NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherSolutionResultsAttribute: NUMBEROFOTHERSOLUTIONRESULTSATT quote INTEGER quote 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
	parserData->tempInt = $3;
};
	
numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = $3; 
}; 

numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = $3;
}; 

numberOfConAttribute: NUMBEROFCONATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = $3;
};

numberOfTimesAttribute: NUMBEROFTIMESATT quote INTEGER quote
{
	parserData->tempInt = $3;
};

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfItems attribute allowed");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = $3;
};

numberOfSolverOutputsAttribute: NUMBEROFSOLVEROUTPUTSATT quote INTEGER quote
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
	parserData->tempInt = $3;
};

numberOfSubstatusesAttribute: NUMBEROFSUBSTATUSESATT quote INTEGER quote 
{   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = $3;
};

aNumber:
	INTEGER {parserData->tempVal = $1;}
  | DOUBLE  {parserData->tempVal = $1;};

ElementValue: 
    ELEMENTTEXT  { parserData->tempStr = $1;       free($1); }
  | INTEGER      { parserData->tempStr = os_dtoa_format($1); }
  | DOUBLE       { parserData->tempStr = os_dtoa_format($1); };
  
quote: xmlWhiteSpace QUOTE;

xmlWhiteSpace:  | xmlWhiteSpace xmlWhiteSpaceChar;

xmlWhiteSpaceChar: ' ' 
				| '\t'
				| '\r'
				| '\n';
			

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

