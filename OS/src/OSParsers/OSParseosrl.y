/* $Id$ */
/** @file OSParseosrl.y
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

%{

 
#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"

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
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osrl_empty_vectors( OSrLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);



%}


%pure-parser
%locations
%defines
%parse-param{OSResult *osresult}
%parse-param{OSrLParserData *parserData}
%parse-param{OSgLParserData *osglData}
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

void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, const char* errormsg);
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
 
#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE

%token TWOQUOTES GREATERTHAN ENDOFELEMENT 
%token OSRLSTART OSRLSTARTEMPTY OSRLATTRIBUTETEXT OSRLEND

%token NUMBEROFCONATT NUMBEROFCONSTRAINTSATT NUMBEROFELATT NUMBEROFENUMERATIONSATT
%token NUMBEROFIDXATT NUMBEROFITEMSATT NUMBEROFOBJATT NUMBEROFOBJECTIVESATT
%token NUMBEROFOTHERCONSTRAINTRESULTSATT NUMBEROFOTHEROBJECTIVERESULTSATT 
%token NUMBEROFOTHERRESULTSATT NUMBEROFOTHERSOLUTIONRESULTSATT 
%token NUMBEROFOTHERVARIABLERESULTSATT NUMBEROFSOLUTIONSATT 
%token NUMBEROFSOLVEROUTPUTSATT NUMBEROFSUBSTATUSESATT NUMBEROFTIMESATT 
%token NUMBEROFVARATT NUMBEROFVARIABLESATT NUMBEROFVARIDXATT

%token TARGETOBJECTIVEIDXATT IDXATT INCRATT MULTATT SIZEOFATT

%token CATEGORYATT EMPTYCATEGORYATT DESCRIPTIONATT EMPTYDESCRIPTIONATT 
%token NAMEATT EMPTYNAMEATT TYPEATT EMPTYTYPEATT 
%token CONTYPEATT EMPTYCONTYPEATT ENUMTYPEATT EMPTYENUMTYPEATT 
%token OBJTYPEATT EMPTYOBJTYPEATT VARTYPEATT EMPTYVARTYPEATT 
%token UNITATT EMPTYUNITATT VALUEATT EMPTYVALUEATT
%token WEIGHTEDOBJECTIVESATT EMPTYWEIGHTEDOBJECTIVESATT
%token TARGETOBJECTIVENAMEATT EMPTYTARGETOBJECTIVENAMEATT

%token HEADERSTART HEADEREND
%token GENERALSTART GENERALEND 
%token SYSTEMSTART  SYSTEMEND 
%token SERVICESTART SERVICEEND 
%token JOBSTART JOBEND 
%token OPTIMIZATIONSTART OPTIMIZATIONEND

%token ITEMSTART ITEMEND ITEMSTARTANDEND ITEMEMPTY

%token FILENAMESTART FILENAMEEND FILENAMEEMPTY FILENAMESTARTANDEND;
%token FILESOURCESTART FILESOURCEEND FILESOURCEEMPTY FILESOURCESTARTANDEND;
%token FILEDESCRIPTIONSTART FILEDESCRIPTIONEND FILEDESCRIPTIONEMPTY FILEDESCRIPTIONSTARTANDEND; 
%token FILECREATORSTART FILECREATOREND FILECREATOREMPTY FILECREATORSTARTANDEND;
%token FILELICENCESTART FILELICENCEEND FILELICENCEEMPTY FILELICENCESTARTANDEND;

%token ACTUALSTARTTIMESTART ACTUALSTARTTIMEEND
%token ATEQUALITYSTART ATEQUALITYEND
%token ATLOWERSTART ATLOWEREND
%token ATUPPERSTART ATUPPEREND 
%token AVAILABLECPUNUMBERSTART AVAILABLECPUNUMBEREND
%token AVAILABLECPUSPEEDSTART AVAILABLECPUSPEEDEND
%token AVAILABLEDISKSPACESTART AVAILABLEDISKSPACEEND
%token AVAILABLEMEMORYSTART AVAILABLEMEMORYEND
%token BASE64START BASE64END
%token BASICSTART BASICEND
%token BASISSTATUSSTART BASISSTATUSEND
%token BASSTATUSSTART BASSTATUSEND
%token CONSTART CONEND
%token CONSTRAINTSSTART CONSTRAINTSEND 
%token CURRENTJOBCOUNTSTART CURRENTJOBCOUNTEND
%token CURRENTSTATESTART CURRENTSTATEEND
%token DUALVALUESSTART DUALVALUESEND  
%token ELSTART ELEND
%token ENUMERATIONSTART ENUMERATIONEND
%token ENDTIMESTART ENDTIMEEND
%token GENERALSTATUSSTART GENERALSTATUSEND 
%token GENERALSUBSTATUSSTART GENERALSUBSTATUSEND 
%token IDXSTART IDXEND
%token INSTANCENAMESTART INSTANCENAMEEND
%token ISFREESTART ISFREEEND
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
%token SUPERBASICSTART SUPERBASICEND
%token SYSTEMINFORMATIONSTART SYSTEMINFORMATIONEND
%token TIMESTART TIMEEND
%token TIMESERVICESTARTEDSTART TIMESERVICESTARTEDEND
%token TIMESTAMPSTART TIMESTAMPEND
%token TIMINGINFORMATIONSTART  TIMINGINFORMATIONEND
%token TOTALJOBSSOFARSTART TOTALJOBSSOFAREND
%token UNKNOWNSTART UNKNOWNEND
%token USEDCPUNUMBERSTART USEDCPUNUMBEREND
%token USEDCPUSPEEDSTART USEDCPUSPEEDEND
%token USEDDISKSPACESTART USEDDISKSPACEEND
%token USEDMEMORYSTART USEDMEMORYEND
%token VALUESSTART VALUESEND 
%token VALUESSTRINGSTART VALUESSTRINGEND
%token VARSTART VAREND 
%token VARIABLESSTART VARIABLESEND 
%token VARIDXSTART VARIDXEND 

%token DUMMY

%%


osrldoc: 
	osrlStartEmpty osrlBody osrlEnd
  | osrlStart osrlAttributes osrlContent
  
osrlStartEmpty: OSRLSTARTEMPTY
{
#ifdef DEBUG
	yydebug = 1;
#endif
}; 

osrlStart: OSRLSTART
{
#ifdef DEBUG
	yydebug = 1;
#endif
}; 

osrlAttributes: | OSRLATTRIBUTETEXT;

osrlContent: osrlEmpty | osrlLaden;

osrlEmpty: ENDOFELEMENT;

osrlLaden: GREATERTHAN osrlBody osrlEnd; 

osrlEnd: OSRLEND
	| {	osrlerror( NULL, osresult, parserData, osglData, "unexpected end of file, expecting </osrl>");};

osrlBody: 
	headerElement generalElement systemElement serviceElement jobElement optimizationElement;


/**
 * ========================================================== 
 * OSrL header 
 * ==========================================================
 */

headerElement: | headerElementStart headerElementContent
{
	if (!osresult->setResultHeader(osglData->fileName, osglData->source, 	
			osglData->description, osglData->fileCreator, osglData->licence) )	
		osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
};
 
headerElementStart: HEADERSTART
{
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
};

headerElementContent: headerElementEmpty | headerElementLaden;

headerElementEmpty: ENDOFELEMENT;

headerElementLaden: GREATERTHAN headerElementBody HEADEREND; 

headerElementBody:  fileName fileSource fileDescription fileCreator fileLicence

fileName: | fileNameContent;

fileNameContent: fileNameEmpty | fileNameLaden;

fileNameEmpty: FILENAMESTARTANDEND | FILENAMEEMPTY;

fileNameLaden: FILENAMESTART ITEMTEXT FILENAMEEND
{
	osglData->fileName = $2;
	free($2);
};

fileSource: | fileSourceContent;

fileSourceContent: fileSourceEmpty | fileSourceLaden;

fileSourceEmpty: FILESOURCESTARTANDEND | FILESOURCEEMPTY;

fileSourceLaden: FILESOURCESTART ITEMTEXT FILESOURCEEND
{
	osglData->source = $2;
	free($2);
};

fileDescription: | fileDescriptionContent;

fileDescriptionContent: fileDescriptionEmpty | fileDescriptionLaden;

fileDescriptionEmpty: FILEDESCRIPTIONSTARTANDEND | FILEDESCRIPTIONEMPTY;

fileDescriptionLaden: FILEDESCRIPTIONSTART ITEMTEXT FILEDESCRIPTIONEND
{
	osglData->description = $2;
	free($2);
};

fileCreator: | fileCreatorContent;

fileCreatorContent: fileCreatorEmpty | fileCreatorLaden;

fileCreatorEmpty: FILECREATORSTARTANDEND | FILECREATOREMPTY;

fileCreatorLaden: FILECREATORSTART ITEMTEXT FILECREATOREND
{
	osglData->fileCreator = $2;
	free($2);
};

fileLicence: | fileLicenceContent;

fileLicenceContent: fileLicenceEmpty | fileLicenceLaden;

fileLicenceEmpty: FILELICENCESTARTANDEND | FILELICENCEEMPTY;

fileLicenceLaden: FILELICENCESTART ITEMTEXT FILELICENCEEND
{
	osglData->licence = $2;
	free($2);
};

/**
 * ========================================================== 
 * <general> element 
 * ==========================================================
 */
generalElement: | generalElementStart generalElementContent;

generalElementStart: GENERALSTART
{
	parserData->generalStatusPresent = false;	
	parserData->generalMessagePresent = false;
	parserData->generalServiceURIPresent = false;
	parserData->generalServiceNamePresent = false;
	parserData->generalInstanceNamePresent = false;
	parserData->generalJobIDPresent = false;
	parserData->generalSolverInvokedPresent = false;
	parserData->generalTimeStampPresent = false;
	parserData->otherGeneralResultsPresent = false;
	osresult->general = new GeneralResult();
};

generalElementContent: generalElementEmpty | generalElementLaden;

generalElementEmpty: GREATERTHAN GENERALEND | ENDOFELEMENT;

generalElementLaden: GREATERTHAN generalElementBody GENERALEND; 

generalElementBody:  generalElementList;

generalElementList:  generalChild | generalElementList generalChild;

generalChild: 
	generalStatus
  | generalMessage
  | serviceURI 
  | serviceName 
  | instanceName 
  | jobID 
  | solverInvoked 
  | timeStamp 
  | otherGeneralResults
  ;
              
generalStatus: generalStatusStart generalStatusAttributes generalStatusContent;

generalStatusStart: GENERALSTATUSSTART
	{
		if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, osglData, "generalStatus previously allocated");
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	};

generalStatusAttributes: generalStatusAttList
	{
		if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	};

generalStatusAttList: generalStatusATT | generalStatusAttList generalStatusATT;

generalStatusATT: 
    typeAttribute
    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	}
  | descriptionAttribute 
	{   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
  | numberOfSubstatusesAttribute
	{
	   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	};

generalStatusContent: 
	generalStatusEmpty 
	{	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
  | generalStatusLaden
	{	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	};

generalStatusEmpty:  GREATERTHAN GENERALSTATUSEND | ENDOFELEMENT; 

generalStatusLaden: GREATERTHAN generalStatusBody GENERALSTATUSEND;

generalStatusBody:   generalSubstatusArray;

generalSubstatusArray: generalSubstatus | generalSubstatusArray generalSubstatus;

generalSubstatus: generalSubstatusStart generalSubstatusAttributes generalSubstatusEnd
{
	parserData->kounter++;
};	

generalSubstatusStart: SUBSTATUSSTART
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
};
		
generalSubstatusAttributes: generalSubstatusAttList		
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
};	

generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: 
	nameAttribute 
	{	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	} 
  | descriptionAttribute
	{	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	}; 

generalSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


generalMessage: generalMessageStart generalMessageContent;

generalMessageStart: MESSAGESTART
	{
		if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	};

generalMessageContent: generalMessageEmpty | generalMessageLaden;

generalMessageEmpty:  GREATERTHAN MESSAGEEND | ENDOFELEMENT;

generalMessageLaden:  GREATERTHAN generalMessageBody MESSAGEEND;

generalMessageBody:   ELEMENTTEXT  
		{osresult->setGeneralMessage($1); free($1); parserData->errorText = NULL;};

serviceURI: serviceURIStart serviceURIContent;

serviceURIStart: SERVICEURISTART
	{
		if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	};

serviceURIContent: serviceURIEmpty | serviceURILaden;

serviceURIEmpty:  GREATERTHAN SERVICEURIEND | ENDOFELEMENT;

serviceURILaden:  GREATERTHAN serviceURIBody SERVICEURIEND;

serviceURIBody:   ELEMENTTEXT  
	{
		osresult->setServiceURI($1); free($1); parserData->errorText = NULL;
	};

serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
	{
		if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	};

serviceNameContent: serviceNameEmpty | serviceNameLaden;

serviceNameEmpty: GREATERTHAN SERVICENAMEEND | ENDOFELEMENT;

serviceNameLaden: GREATERTHAN serviceNameBody SERVICENAMEEND;

serviceNameBody:  ELEMENTTEXT  
	{
		osresult->setServiceName($1); free($1); parserData->errorText = NULL;
	};

instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
	{
		if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	};

instanceNameContent: instanceNameEmpty | instanceNameLaden;

instanceNameEmpty: GREATERTHAN INSTANCENAMEEND | ENDOFELEMENT;

instanceNameLaden: GREATERTHAN instanceNameBody INSTANCENAMEEND;

instanceNameBody:  ELEMENTTEXT  
	{
		osresult->setInstanceName($1); free($1); parserData->errorText = NULL;
	};

jobID: jobIDStart jobIDContent;

jobIDStart: JOBIDSTART 
	{
		if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	};
	
jobIDContent: jobIDEmpty | jobIDLaden;

jobIDEmpty: GREATERTHAN JOBIDEND | ENDOFELEMENT;

jobIDLaden: GREATERTHAN jobIDBody JOBIDEND;

jobIDBody:  ELEMENTTEXT  
	{
		osresult->setJobID($1); free($1); parserData->errorText = NULL;
	};

solverInvoked: solverInvokedStart solverInvokedContent;

solverInvokedStart: SOLVERINVOKEDSTART 
	{
		if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	};

solverInvokedContent: solverInvokedEmpty | solverInvokedLaden;

solverInvokedEmpty: GREATERTHAN SOLVERINVOKEDEND | ENDOFELEMENT;

solverInvokedLaden: GREATERTHAN solverInvokedBody SOLVERINVOKEDEND;

solverInvokedBody:  ELEMENTTEXT  
	{
		osresult->setSolverInvoked($1); free($1); parserData->errorText = NULL;
	};

timeStamp: timeStampStart timeStampContent;
  
timeStampStart: TIMESTAMPSTART 
	{
		if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	};

timeStampContent: timeStampEmpty | timeStampLaden;

timeStampEmpty: GREATERTHAN TIMESTAMPEND | ENDOFELEMENT;

timeStampLaden: GREATERTHAN timeStampBody TIMESTAMPEND;

timeStampBody:  ELEMENTTEXT  
	{
		osresult->setTimeStamp($1); free($1); parserData->errorText = NULL;
	};

otherGeneralResults: otherGeneralResultsStart otherGeneralResultsAttributes otherGeneralResultsContent;

otherGeneralResultsStart: OTHERRESULTSSTART
	{
		if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	};

otherGeneralResultsAttributes: numberOfOtherResultsAttribute 
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

otherGeneralResultsContent: 
	otherGeneralResultsEmpty 
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}  
  | otherGeneralResultsLaden
	{
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	};
	
otherGeneralResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

otherGeneralResultsLaden: GREATERTHAN otherGeneralResultsBody OTHERRESULTSEND;

otherGeneralResultsBody:  otherGeneralResultArray;

otherGeneralResultArray:  otherGeneralResult | otherGeneralResultArray otherGeneralResult; 

otherGeneralResult: otherGeneralResultStart otherGeneralResultAttributes otherGeneralResultEnd
{
	parserData->kounter++;
};	

otherGeneralResultStart: OTHERSTART
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};

otherGeneralResultAttributes: otherGeneralResultAttList
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
};	

otherGeneralResultAttList: | otherGeneralResultAttList otherGeneralResultAtt;

otherGeneralResultAtt: 
	nameAttribute
	{
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	}
  | valueAttribute
	{	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	}
;

otherGeneralResultEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



systemElement: | systemElementStart systemElementContent;

systemElementStart: SYSTEMSTART
{
	parserData->systemInformationPresent = false;	
	parserData->systemAvailableDiskSpacePresent = false;	
	parserData->systemAvailableMemoryPresent = false;
	parserData->systemAvailableCPUSpeedPresent = false;
	parserData->systemAvailableCPUNumberPresent = false;
	parserData->otherSystemResultsPresent = false;
	osresult->system = new SystemResult();
};

systemElementContent: systemElementEmpty | systemElementLaden;

systemElementEmpty: GREATERTHAN SYSTEMEND | ENDOFELEMENT;

systemElementLaden: GREATERTHAN systemElementBody SYSTEMEND; 
          
systemElementBody:  systemElementList;
               
systemElementList:  systemChild | systemElementList systemChild; 

systemChild: 
	systemInformation 
  | availableDiskSpace 
  | availableMemory 
  | availableCPUSpeed
  | availableCPUNumber 
  | otherSystemResults
  ; 

systemInformation: systemInformationStart systemInformationContent;

systemInformationStart:	SYSTEMINFORMATIONSTART 
	{
		if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	};
	
systemInformationContent: systemInformationEmpty | systemInformationLaden;

systemInformationEmpty: GREATERTHAN SYSTEMINFORMATIONEND | ENDOFELEMENT;

systemInformationLaden: GREATERTHAN systemInformationBody SYSTEMINFORMATIONEND;

systemInformationBody:  ELEMENTTEXT   
	{
		osresult->setSystemInformation($1); 
		free($1); 
		parserData->errorText = NULL;
	};

availableDiskSpace: availableDiskSpaceStart availableDiskSpaceAttributes availableDiskSpaceContent;

availableDiskSpaceStart: AVAILABLEDISKSPACESTART
	{
		if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	};

availableDiskSpaceAttributes: availableDiskSpaceAttList;

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: 
	unitAttribute
	{
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableDiskSpaceContent: GREATERTHAN availableDiskSpaceValue AVAILABLEDISKSPACEEND;

availableDiskSpaceValue: aNumber
{
	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
};

availableMemory: availableMemoryStart availableMemoryAttributes availableMemoryContent;

availableMemoryStart: AVAILABLEMEMORYSTART
	{
		if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	};

availableMemoryAttributes: availableMemoryAttList;

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: 
	unitAttribute 
	{
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableMemoryContent: GREATERTHAN availableMemoryValue AVAILABLEMEMORYEND;

availableMemoryValue: aNumber
{
	osresult->setAvailableMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


availableCPUSpeed: availableCPUSpeedStart availableCPUSpeedAttributes availableCPUSpeedContent;

availableCPUSpeedStart: AVAILABLECPUSPEEDSTART
	{
		if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	};

availableCPUSpeedAttributes: availableCPUSpeedAttList;

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: 
	unitAttribute 
	{
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableCPUSpeedContent: GREATERTHAN availableCPUSpeedValue AVAILABLECPUSPEEDEND;

availableCPUSpeedValue: aNumber
{
	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


availableCPUNumber: availableCPUNumberStart availableCPUNumberAttributes availableCPUNumberContent;

availableCPUNumberStart: AVAILABLECPUNUMBERSTART
	{
		if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	};

availableCPUNumberAttributes: 
  | descriptionAttribute
	{
		osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

availableCPUNumberContent: GREATERTHAN availableCPUNumberValue AVAILABLECPUNUMBEREND;

availableCPUNumberValue: INTEGER 
{
	osresult->setAvailableCPUNumberValue( $1);  parserData->errorText = NULL;
};


otherSystemResults: otherSystemResultsStart otherSystemResultsAttributes otherSystemResultsContent;

otherSystemResultsStart: OTHERRESULTSSTART
	{
		if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	};

otherSystemResultsAttributes: numberOfOtherResultsAttribute
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

otherSystemResultsContent: 
	otherSystemResultsEmpty
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
  | otherSystemResultsLaden
	{
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	};

otherSystemResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

otherSystemResultsLaden: GREATERTHAN otherSystemResultsBody OTHERRESULTSEND;

otherSystemResultsBody:  otherSystemResultArray;

otherSystemResultArray:  otherSystemResult | otherSystemResultArray otherSystemResult; 

otherSystemResult: otherSystemResultStart otherSystemResultAttributes otherSystemResultEnd
{
	parserData->kounter++;
};	

otherSystemResultStart: OTHERSTART
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};

otherSystemResultAttributes: otherSystemResultAttList
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
};
	
otherSystemResultAttList: | otherSystemResultAttList otherSystemResultAtt;

otherSystemResultAtt:
	nameAttribute
	{
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	}
  | valueAttribute
	{	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	};

otherSystemResultEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



serviceElement: | serviceElementStart serviceElementContent;

serviceElementStart: SERVICESTART
{
	parserData->serviceCurrentStatePresent = false;	
	parserData->serviceCurrentJobCountPresent = false;	
	parserData->serviceTotalJobsSoFarPresent = false;	
	parserData->timeServiceStartedPresent = false;	
	parserData->serviceUtilizationPresent = false;	
	parserData->otherServiceResultsPresent = false;
	osresult->service = new ServiceResult();
};

serviceElementContent: serviceElementEmpty | serviceElementLaden;

serviceElementEmpty: GREATERTHAN SERVICEEND | ENDOFELEMENT; 

serviceElementLaden: GREATERTHAN serviceElementBody SERVICEEND;

serviceElementBody:  serviceElementList;
                
serviceElementList:  serviceChild | serviceElementList serviceChild;
        
serviceChild: 
	currentState 
  | currentJobCount 
  | totalJobsSoFar 
  | timeServiceStarted 
  | serviceUtilization 
  | otherServiceResults
  ;

currentState: currentStateStart currentStateContent;

currentStateStart: CURRENTSTATESTART 
	{
		if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	};

currentStateContent: currentStateEmpty | currentStateLaden;

currentStateEmpty: GREATERTHAN CURRENTSTATEEND | ENDOFELEMENT;

currentStateLaden: GREATERTHAN currentStateBody CURRENTSTATEEND;

currentStateBody:  ELEMENTTEXT  
    {
	   parserData->tempStr = $1; free($1);
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	};

currentJobCount: currentJobCountStart currentJobCountContent;

currentJobCountStart: CURRENTJOBCOUNTSTART
	{
		if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	};

currentJobCountContent: currentJobCountEmpty | currentJobCountLaden;

currentJobCountEmpty: GREATERTHAN CURRENTJOBCOUNTEND | ENDOFELEMENT;

currentJobCountLaden: GREATERTHAN currentJobCountBody CURRENTJOBCOUNTEND;

currentJobCountBody:  INTEGER  
	{
		osresult->setCurrentJobCount($1); parserData->errorText = NULL;
	};

totalJobsSoFar: totalJobsSoFarStart totalJobsSoFarContent;

totalJobsSoFarStart: TOTALJOBSSOFARSTART 
	{
		if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	};

totalJobsSoFarContent: totalJobsSoFarEmpty | totalJobsSoFarLaden;

totalJobsSoFarEmpty: GREATERTHAN TOTALJOBSSOFAREND | ENDOFELEMENT;

totalJobsSoFarLaden: GREATERTHAN totalJobsSoFarBody TOTALJOBSSOFAREND;

totalJobsSoFarBody:  INTEGER  
	{
		osresult->setTotalJobsSoFar($1); parserData->errorText = NULL; 
	};

timeServiceStarted: timeServiceStartedStart timeServiceStartedContent;

timeServiceStartedStart: TIMESERVICESTARTEDSTART 
	{
		if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	};

timeServiceStartedContent: timeServiceStartedEmpty | timeServiceStartedLaden;

timeServiceStartedEmpty: GREATERTHAN TIMESERVICESTARTEDEND | ENDOFELEMENT;

timeServiceStartedLaden: GREATERTHAN timeServiceStartedBody TIMESERVICESTARTEDEND;

timeServiceStartedBody:  ELEMENTTEXT  
	{
		osresult->setTimeServiceStarted($1); free($1); parserData->errorText = NULL;
	};

serviceUtilization: serviceUtilizationStart serviceUtilizationContent;

serviceUtilizationStart: SERVICEUTILIZATIONSTART 
	{
		if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	};

serviceUtilizationContent: serviceUtilizationEmpty | serviceUtilizationLaden;

serviceUtilizationEmpty: GREATERTHAN SERVICEUTILIZATIONEND | ENDOFELEMENT;

serviceUtilizationLaden: GREATERTHAN serviceUtilizationBody SERVICEUTILIZATIONEND;

serviceUtilizationBody:  aNumber  
{
	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
};

otherServiceResults: otherServiceResultsStart otherServiceResultsAttributes otherServiceResultsContent;

otherServiceResultsStart: OTHERRESULTSSTART
	{
		if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	};

otherServiceResultsAttributes: numberOfOtherResultsAttribute
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

otherServiceResultsContent: 
	otherServiceResultsEmpty
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
  | otherServiceResultsLaden
	{
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	};

otherServiceResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

otherServiceResultsLaden: GREATERTHAN otherServiceResultsBody OTHERRESULTSEND

otherServiceResultsBody:  otherServiceResultArray;

otherServiceResultArray:  otherServiceResult | otherServiceResultArray otherServiceResult; 

otherServiceResult: otherServiceResultStart otherServiceResultAttributes otherServiceResultEnd
{
	parserData->kounter++;
};

otherServiceResultStart: OTHERSTART
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};

otherServiceResultAttributes: otherServiceResultAttList
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
};
	
otherServiceResultAttList: | otherServiceResultAttList otherServiceResultAtt;

otherServiceResultAtt: 
	nameAttribute 
	{
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	}
  | valueAttribute 
	{	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	}
  | descriptionAttribute
	{	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	}
;
  
otherServiceResultEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


jobElement: | jobElementStart jobElementContent;

jobElementStart: JOBSTART
{
	parserData->jobStatusPresent = false;	
	parserData->jobSubmitTimePresent = false;	
	parserData->scheduledStartTimePresent = false;	
	parserData->actualStartTimePresent = false;	
	parserData->jobEndTimePresent = false;	
	parserData->jobTimingInformationPresent = false;	
	parserData->jobUsedDiskSpacePresent = false;	
	parserData->jobUsedMemoryPresent = false;	
	parserData->jobUsedCPUSpeedPresent = false;	
	parserData->jobUsedCPUNumberPresent = false;	
	parserData->otherJobResultsPresent = false;	 
	osresult->job = new JobResult();
};

jobElementContent: jobElementEmpty | jobElementLaden;

jobElementEmpty: GREATERTHAN JOBEND | ENDOFELEMENT;

jobElementLaden: GREATERTHAN jobElementBody JOBEND;

jobElementBody:  jobElementList;

jobElementList:  jobChild | jobElementList jobChild;

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
  | otherJobResults
  ;

jobStatus: jobStatusStart jobStatusContent;

jobStatusStart: STATUSSTART 
	{
		if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	};

jobStatusContent: jobStatusEmpty | jobStatusLaden;

jobStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT;

jobStatusLaden: GREATERTHAN jobStatusBody STATUSEND;

jobStatusBody:  ELEMENTTEXT  
	{
		parserData->tempStr = $1; free($1);
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	};

submitTime: submitTimeStart submitTimeContent;

submitTimeStart: SUBMITTIMESTART 
	{
		if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	};

submitTimeContent: submitTimeEmpty | submitTimeLaden;

submitTimeEmpty: GREATERTHAN SUBMITTIMEEND | ENDOFELEMENT;

submitTimeLaden: GREATERTHAN submitTimeBody SUBMITTIMEEND

submitTimeBody:  ELEMENTTEXT  
	{
		osresult->setJobSubmitTime($1); free($1); parserData->errorText = NULL;
	};

scheduledStartTime: scheduledStartTimeStart scheduledStartTimeContent;

scheduledStartTimeStart: SCHEDULEDSTARTTIMESTART 
	{
		if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	};

scheduledStartTimeContent: scheduledStartTimeEmpty | scheduledStartTimeLaden;

scheduledStartTimeEmpty: GREATERTHAN SCHEDULEDSTARTTIMEEND | ENDOFELEMENT;

scheduledStartTimeLaden: GREATERTHAN scheduledStartTimeBody SCHEDULEDSTARTTIMEEND;

scheduledStartTimeBody:  ELEMENTTEXT  
	{
		osresult->setScheduledStartTime($1); free($1); parserData->errorText = NULL;
	};

actualStartTime: actualStartTimeStart actualStartTimeContent;

actualStartTimeStart: ACTUALSTARTTIMESTART 
	{
		if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	};

actualStartTimeContent: actualStartTimeEmpty | actualStartTimeLaden;

actualStartTimeEmpty: GREATERTHAN ACTUALSTARTTIMEEND | ENDOFELEMENT;

actualStartTimeLaden: GREATERTHAN actualStartTimeBody ACTUALSTARTTIMEEND;

actualStartTimeBody:  ELEMENTTEXT   
	{
		osresult->setActualStartTime($1); free($1);  parserData->errorText = NULL;
	};

endTime: endTimeStart endTimeContent;

endTimeStart: ENDTIMESTART 
	{
		if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	};

endTimeContent: endTimeEmpty | endTimeLaden;

endTimeEmpty: GREATERTHAN ENDTIMEEND | ENDOFELEMENT;

endTimeLaden: GREATERTHAN endTimeBody ENDTIMEEND;

endTimeBody:  ELEMENTTEXT   
	{
		osresult->setJobEndTime($1); free($1);  parserData->errorText = NULL;
	};

timingInformation: timingInformationStart timingInformationAttributes timingInformationContent;

timingInformationStart: TIMINGINFORMATIONSTART
	{
		if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	};

timingInformationAttributes: numberOfTimesAttribute 
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
};

timingInformationContent: 
	timingInformationEmpty 
	{
		if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	}
  | timingInformationLaden
	{
		if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	};

timingInformationEmpty: GREATERTHAN TIMINGINFORMATIONEND | ENDOFELEMENT;   

timingInformationLaden: GREATERTHAN timingInformationBody TIMINGINFORMATIONEND;

timingInformationBody:  timeArray;

timeArray: time | timeArray time;

time: timeStart timeAttributes timeContent;

timeStart: TIMESTART
{
	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, osglData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "second";
	parserData->typeAttribute = "elapsedTime";
	parserData->categoryAttribute = "total";
	parserData->descriptionAttribute = "";
};

timeAttributes: | timeAttributes timeAtt;

timeAtt: 
	unitAttribute | typeAttribute | categoryAttribute | descriptionAttribute;


timeContent: timeEmpty | timeLaden;

timeEmpty: GREATERTHAN TIMEEND | ENDOFELEMENT;

timeLaden: GREATERTHAN timeBody TIMEEND;

timeBody:  timeValue 
{	
	if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
			osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
	parserData->ivar++;
}; 

timeValue:
	DOUBLE  { parserData->timeValue = $1; }
  | INTEGER { parserData->timeValue = $1; };


usedDiskSpace: usedDiskSpaceStart usedDiskSpaceAttributes usedDiskSpaceContent;

usedDiskSpaceStart: USEDDISKSPACESTART
	{
		if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	};
	
usedDiskSpaceAttributes: usedDiskSpaceAttList;

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: 
	unitAttribute
	{
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedDiskSpaceContent: GREATERTHAN usedDiskSpaceValue USEDDISKSPACEEND;

usedDiskSpaceValue: aNumber
{
	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


usedMemory: usedMemoryStart usedMemoryAttributes usedMemoryContent;

usedMemoryStart: USEDMEMORYSTART
	{
		if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	};
	
usedMemoryAttributes: usedMemoryAttList;
			
usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: 
	unitAttribute 
	{
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedMemoryContent: GREATERTHAN usedMemoryValue USEDMEMORYEND;

usedMemoryValue: aNumber
{
	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


usedCPUSpeed: usedCPUSpeedStart usedCPUSpeedAttributes usedCPUSpeedContent;
              
usedCPUSpeedStart: USEDCPUSPEEDSTART
	{
		if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	};
              
usedCPUSpeedAttributes: usedCPUSpeedAttList;
	
usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: 
	unitAttribute 
	{
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	}
  | descriptionAttribute
	{
		osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedCPUSpeedContent: GREATERTHAN usedCPUSpeedValue USEDCPUSPEEDEND;

usedCPUSpeedValue: aNumber
{
	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
};


usedCPUNumber: usedCPUNumberStart usedCPUNumberAttributes usedCPUNumberContent;
               
usedCPUNumberStart: USEDCPUNUMBERSTART               
	{
		if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	};
               

usedCPUNumberAttributes: 
  | descriptionAttribute
	{
		osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	};

usedCPUNumberContent: GREATERTHAN usedCPUNumberValue USEDCPUNUMBEREND;

usedCPUNumberValue: INTEGER 
{ 
	osresult->setUsedCPUNumberValue( $1);  parserData->errorText = NULL; 
};



otherJobResults: otherJobResultsStart otherJobResultsAttributes otherJobResultsContent;

otherJobResultsStart: OTHERRESULTSSTART
	{
		if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	};

otherJobResultsAttributes: numberOfOtherResultsAttribute 
{
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
};

otherJobResultsContent: 
	otherJobResultsEmpty
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
  | otherJobResultsLaden
	{
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	};

otherJobResultsEmpty: GREATERTHAN OTHERRESULTSEND | ENDOFELEMENT;

otherJobResultsLaden: GREATERTHAN otherJobResultsBody OTHERRESULTSEND;

otherJobResultsBody:   otherJobResultArray;

otherJobResultArray: otherJobResult | otherJobResultArray otherJobResult; 

otherJobResult: otherJobResultStart otherJobResultAttributes otherJobResultEnd
{
	parserData->kounter++;
};	

otherJobResultStart: OTHERSTART
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};

otherJobResultAttributes: otherJobResultAttList
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
};

otherJobResultAttList: | otherJobResultAttList otherJobResultAtt;

otherJobResultAtt: 
	nameAttribute 
	{
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	}
 | valueAttribute 
	{	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	}
 | descriptionAttribute
	{	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	}
;

otherJobResultEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


optimizationElement: | optimizationStart optimizationAttributes optimizationContent;

optimizationStart: OPTIMIZATIONSTART
{
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
};

optimizationAttributes: optimizationAttList
{
	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
};	

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
	numberOfSolutionsAttribute 
	{
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	}
  | numberOfVariablesAttribute 
	{	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	}             
  | numberOfConstraintsAttribute 
	{
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	} 
  | numberOfObjectivesAttribute 
	{	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	};
	
optimizationContent: 
	optimizationEmpty 
	{
		if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	}
  | optimizationLaden
	{
		if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	};

optimizationEmpty: GREATERTHAN OPTIMIZATIONEND | ENDOFELEMENT;

optimizationLaden: GREATERTHAN optimizationBody OPTIMIZATIONEND;

optimizationBody:  solutionArray otherSolverOutput;

solutionArray: solution | solutionArray solution;  

solution: solutionStart solutionAttributes solutionContent;

solutionStart: SOLUTIONSTART
{
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
};

solutionAttributes: solutionAttList;

solutionAttList: | solutionAttList solutionATT;

solutionATT: targetObjectiveIdxATT | targetObjectiveNameATT | weightedObjectivesATT;

targetObjectiveIdxATT: TARGETOBJECTIVEIDXATT quote INTEGER quote
{
	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if($3 >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 };

targetObjectiveNameATT: TARGETOBJECTIVENAMEATT ATTRIBUTETEXT quote
{
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
	parserData->nameAttributePresent = true;
	parserData->tempStr = $2; free($2);
  	if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{
	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "weighted objective attribute previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = $2; free($2);
	if (parserData->tempStr == "true")
	{
	  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else if (parserData->tempStr == "false")
	{
	  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else
		osrlerror(NULL, NULL, parserData, osglData, "weightedobjectives must be true or false");
};

solutionContent: GREATERTHAN solutionStatus solutionMessage
          variables objectives constraints otherSolutionResults SOLUTIONEND
	{
		parserData->solutionIdx++;
	};

solutionStatus: solutionStatusStart solutionStatusAttributes solutionStatusContent;

solutionStatusStart: STATUSSTART
	{
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	};

solutionStatusAttributes: solutionStatusAttList
	{
		if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	};

solutionStatusAttList: solutionStatusATT | solutionStatusAttList solutionStatusATT;

solutionStatusATT: 
	typeAttribute
	{   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	}
  | descriptionAttribute
	{
	   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	}
  | numberOfSubstatusesAttribute
	{
		if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	};
	
  
solutionStatusContent: 
    solutionStatusEmpty 
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
  | solutionStatusLaden
	{
		if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	};

solutionStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT; 

solutionStatusLaden: GREATERTHAN solutionStatusBody STATUSEND;

solutionStatusBody:  solutionSubstatusArray;

solutionSubstatusArray: solutionSubstatus | solutionSubstatusArray solutionSubstatus;

solutionSubstatus: solutionSubstatusStart solutionSubstatusAttributes solutionSubstatusEnd
{
	parserData->kounter++; 
};

solutionSubstatusStart: SUBSTATUSSTART 
{
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
};

solutionSubstatusAttributes: solutionSubstatusAttList
{
	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
};	

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: 
	typeAttribute 
	{	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	}; 
  | descriptionAttribute
	{	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	}; 

solutionSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


solutionMessage: | solutionMessageStart solutionMessageContent;

solutionMessageStart: MESSAGESTART;

solutionMessageContent: solutionMessageEmpty | solutionMessageLaden;

solutionMessageEmpty: GREATERTHAN MESSAGEEND | ENDOFELEMENT;

solutionMessageLaden: GREATERTHAN solutionMessageBody MESSAGEEND;

solutionMessageBody:  ELEMENTTEXT  
	{
		parserData->tempStr = $1;
		free($1);
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	};

variables: | variablesStart numberOfOtherVariableResults variablesContent;

variablesStart: VARIABLESSTART
{
	parserData->numberOfOtherVariableResults = 0;
	osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
};

numberOfOtherVariableResults: | numberOfOtherVariableResultsAttribute
{	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
};

variablesContent: variablesEmpty | variablesLaden;

variablesEmpty: ENDOFELEMENT;

variablesLaden: GREATERTHAN variablesBody VARIABLESEND;

variablesBody:  variableValues variableValuesString variableBasisStatus otherVariableResultsArray;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART;

numberOfVarATT: numberOfVarAttribute 
{
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
}; 

variableValuesContent: 
	variableValuesEmpty 
	{
		if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
  | variableValuesLaden
	{
		if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	};
 
variableValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

variableValuesLaden: GREATERTHAN variableValuesBody VALUESEND;

variableValuesBody:   varValueArray;

varValueArray: varValue | varValueArray varValue;

varValue: varValueStart varValueAttList varValueContent
{
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
}; 

varValueStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
};

varValueAttList: | varValueAttList varValueAtt;

varValueAtt:
	idxAttribute
  | nameAttribute
  ;

varValueContent: GREATERTHAN aNumber VAREND;
  

variableValuesString: | variableValuesStringStart numberOfVarStringATT variableValuesStringContent;

variableValuesStringStart: VALUESSTRINGSTART;

numberOfVarStringATT: numberOfVarAttribute 
{
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
}; 

variableValuesStringContent: 
	variableValuesStringEmpty 
	{
		if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
  | variableValuesStringLaden
	{
		if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	};

variableValuesStringEmpty: GREATERTHAN VALUESSTRINGEND | ENDOFELEMENT; 

variableValuesStringLaden: GREATERTHAN variableValuesStringBody VALUESSTRINGEND;

variableValuesStringBody:  varValueStringArray;

varValueStringArray: varValueString | varValueStringArray varValueString;

varValueString: varValueStringStart varValueStringAttList varValueStringContent
{
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->nameAttribute,
									parserData->tempStr                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
}; 

varValueStringStart: VARSTART 
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
};

varValueStringAttList: | varValueStringAttList varValueStringAtt;

varValueStringAtt:
	idxAttribute
  | nameAttribute
  ;
  
varValueStringContent: 
	varValueStringEmpty {parserData->tempStr = "";};
  | varValueStringLaden; 
  
varValueStringEmpty: GREATERTHAN VAREND | ENDOFELEMENT;

varValueStringLaden: GREATERTHAN varValueStringBody VAREND;

varValueStringBody: ELEMENTTEXT 
	{
		parserData->tempStr = $1; free($1);
	};

variableBasisStatus: | variableBasisStatusStart variableBasisStatusContent;

variableBasisStatusStart: BASISSTATUSSTART
{
	osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
};

variableBasisStatusContent: variableBasisStatusEmpty | variableBasisStatusLaden;

variableBasisStatusEmpty: ENDOFELEMENT;

variableBasisStatusLaden: GREATERTHAN variableBasisStatusBody BASISSTATUSEND;

variableBasisStatusBody:  variablesBasic variablesAtLower variablesAtUpper variablesAtEquality variablesIsFree variablesSuperbasic variablesUnknown;

variablesBasic: | variablesBasicStart variablesBasicNumberOfElATT variablesBasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesBasicStart: BASICSTART;

variablesBasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesBasicContent: variablesBasicEmpty | variablesBasicLaden;

variablesBasicEmpty: ENDOFELEMENT;

variablesBasicLaden: GREATERTHAN variablesBasicBody BASICEND;

variablesBasicBody:  osglIntArrayData;


variablesAtLower: | variablesAtLowerStart variablesAtLowerNumberOfElATT variablesAtLowerContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};


variablesAtLowerStart: ATLOWERSTART;

variablesAtLowerNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtLowerContent: variablesAtLowerEmpty | variablesAtLowerLaden;

variablesAtLowerEmpty: ENDOFELEMENT;

variablesAtLowerLaden: GREATERTHAN variablesAtLowerBody ATLOWEREND;

variablesAtLowerBody:  osglIntArrayData;


variablesAtUpper: | variablesAtUpperStart variablesAtUpperNumberOfElATT variablesAtUpperContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesAtUpperStart: ATUPPERSTART;

variablesAtUpperNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtUpperContent: variablesAtUpperEmpty | variablesAtUpperLaden;

variablesAtUpperEmpty: ENDOFELEMENT;

variablesAtUpperLaden: GREATERTHAN variablesAtUpperBody ATUPPEREND;

variablesAtUpperBody:  osglIntArrayData;


variablesAtEquality: | variablesAtEqualityStart variablesAtEqualityNumberOfElATT variablesAtEqualityContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesAtEqualityStart: ATEQUALITYSTART;

variablesAtEqualityNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtEqualityContent: variablesAtEqualityEmpty | variablesAtEqualityLaden;

variablesAtEqualityEmpty: ENDOFELEMENT;

variablesAtEqualityLaden: GREATERTHAN variablesAtEqualityBody ATEQUALITYEND;

variablesAtEqualityBody:  osglIntArrayData;


variablesIsFree: | variablesIsFreeStart variablesIsFreeNumberOfElATT variablesIsFreeContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesIsFreeStart: ISFREESTART;

variablesIsFreeNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesIsFreeContent: variablesIsFreeEmpty | variablesIsFreeLaden;

variablesIsFreeEmpty: ENDOFELEMENT;

variablesIsFreeLaden: GREATERTHAN variablesIsFreeBody ISFREEEND;

variablesIsFreeBody:  osglIntArrayData;


variablesSuperbasic: | variablesSuperbasicStart variablesSuperbasicNumberOfElATT variablesSuperbasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesSuperbasicStart: SUPERBASICSTART;

variablesSuperbasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesSuperbasicContent: variablesSuperbasicEmpty | variablesSuperbasicLaden;

variablesSuperbasicEmpty: ENDOFELEMENT;

variablesSuperbasicLaden: GREATERTHAN variablesSuperbasicBody SUPERBASICEND;

variablesSuperbasicBody:  osglIntArrayData;


variablesUnknown: | variablesUnknownStart variablesUnknownNumberOfElATT variablesUnknownContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

variablesUnknownStart: UNKNOWNSTART;

variablesUnknownNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesUnknownContent: variablesUnknownEmpty | variablesUnknownLaden;

variablesUnknownEmpty: ENDOFELEMENT;

variablesUnknownLaden: GREATERTHAN variablesUnknownBody UNKNOWNEND;

variablesUnknownBody:  osglIntArrayData;


otherVariableResultsArray: | otherVariableResultsArray otherVariableResult;

otherVariableResult: otherVariableResultStart otherVariableResultAttributes otherVariableResultContent
	{ 	 
		parserData->iOther++;
	};

otherVariableResultStart: OTHERSTART
{
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfVarAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->typeAttributePresent = false;
	parserData->varTypeAttributePresent = false;
	parserData->enumTypeAttributePresent = false;
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->typeAttribute = "";
	parserData->varTypeAttribute = "";
	parserData->enumTypeAttribute = "";
	parserData->descriptionAttribute = "";	
}; 

otherVariableResultAttributes: otherVariableResultAttList 
	{
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	};
	  
otherVariableResultAttList: | otherVariableResultAttList otherVariableResultATT;

otherVariableResultATT: 
	numberOfVarAttribute 
	{
		if (parserData->numberOfVarAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
		parserData->numberOfVarAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	} 
  | numberOfEnumerationsAttribute
	{
		if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}  
  | valueAttribute
    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
  | nameAttribute 
    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
  | typeAttribute 
    {	
	 	if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultType failed");
    }
  | varTypeAttribute 
    {	
	 	if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->varTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarType failed");
    }
  | enumTypeAttribute 
    {	
	 	if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultEnumType failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    };
  
otherVariableResultContent: otherVariableResultEmpty | otherVariableResultLaden;

otherVariableResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableResultLaden: GREATERTHAN otherVariableResultBody OTHEREND;

otherVariableResultBody:  otherVarList | otherVarEnumerationList;

otherVarList: otherVar | otherVarList otherVar;

otherVar: otherVarStart otherVarAttList otherVarContent 
{ 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
};

otherVarStart: VARSTART
{	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
};

otherVarAttList: | otherVarAttList otherVarAtt;

otherVarAtt:
	idxAttribute
	{	
 		if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->idx) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
	}
  | nameAttribute
	{	
 		if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
	};

otherVarContent: otherVarEmpty | otherVarLaden;

otherVarEmpty: GREATERTHAN VAREND | ENDOFELEMENT;

otherVarLaden: GREATERTHAN otherVarBody VAREND;

otherVarBody:  ElementValue  
	{	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	};


otherVarEnumerationList: otherVarEnumeration | otherVarEnumerationList otherVarEnumeration;

otherVarEnumeration: otherVarEnumerationStart otherVarEnumerationAttributes otherVarEnumerationContent 
{ 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
};

otherVarEnumerationStart: ENUMERATIONSTART
{
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};	

otherVarEnumerationAttributes: otherVarEnumerationAttList 
	{
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	};
	  
otherVarEnumerationAttList: | otherVarEnumerationAttList otherVarEnumerationATT;

otherVarEnumerationATT: 
	numberOfElAttribute 
	{
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	} 
  | valueAttribute
  | descriptionAttribute
  ;


otherVarEnumerationContent: otherVarEnumerationEmpty | otherVarEnumerationLaden;

otherVarEnumerationEmpty: ENDOFELEMENT;

otherVarEnumerationLaden: GREATERTHAN otherVarEnumerationBody ENUMERATIONEND;


otherVarEnumerationBody:  osglIntArrayData;  



objectives: | objectivesStart numberOfOtherObjectiveResults objectivesContent;

objectivesStart: OBJECTIVESSTART
{
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
};


numberOfOtherObjectiveResults: | numberOfOtherObjectiveResultsAttribute
{
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
};

objectivesContent: objectivesEmpty | objectivesLaden;

objectivesEmpty: ENDOFELEMENT;

objectivesLaden: GREATERTHAN objectivesBody OBJECTIVESEND;

objectivesBody:  objectiveValues objectiveBasisStatus otherObjectiveResultsArray;

objectiveValues: | objectiveValuesStart numberOfObjATT objectiveValuesContent;

objectiveValuesStart: VALUESSTART;

numberOfObjATT: numberOfObjAttribute
{
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}; 

objectiveValuesContent: 
	objectiveValuesEmpty 
	{
		if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
  | objectiveValuesLaden
	{
		if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	};
 
objectiveValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

objectiveValuesLaden: GREATERTHAN objectiveValuesBody VALUESEND;

objectiveValuesBody:   objValueArray;


objValueArray: objValue | objValueArray objValue;

objValue: objValueStart objValueAttList objValueContent
{
	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
}; 

objValueStart: OBJSTART
{	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
};

objValueAttList: | objValueAttList objValueAtt;

objValueAtt:
	idxAttribute
  | nameAttribute
  ;

objValueContent: GREATERTHAN aNumber OBJEND;


objectiveBasisStatus: | objectiveBasisStatusStart objectiveBasisStatusContent;

objectiveBasisStatusStart: BASISSTATUSSTART
{
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
};

objectiveBasisStatusContent: objectiveBasisStatusEmpty | objectiveBasisStatusLaden;
 

objectiveBasisStatusEmpty: ENDOFELEMENT;

objectiveBasisStatusLaden: GREATERTHAN objectiveBasisStatusBody BASISSTATUSEND;

objectiveBasisStatusBody:  objectivesBasic objectivesAtLower objectivesAtUpper objectivesAtEquality objectivesIsFree objectivesSuperbasic objectivesUnknown;

objectivesBasic: | objectivesBasicStart objectivesBasicNumberOfElATT objectivesBasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesBasicStart: BASICSTART;

objectivesBasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesBasicContent: objectivesBasicEmpty | objectivesBasicLaden;

objectivesBasicEmpty: ENDOFELEMENT;

objectivesBasicLaden: GREATERTHAN objectivesBasicBody BASICEND;

objectivesBasicBody:  osglIntArrayData;

objectivesAtLower: | objectivesAtLowerStart objectivesAtLowerNumberOfElATT objectivesAtLowerContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesAtLowerStart: ATLOWERSTART;

objectivesAtLowerNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtLowerContent: objectivesAtLowerEmpty | objectivesAtLowerLaden;

objectivesAtLowerEmpty: ENDOFELEMENT;

objectivesAtLowerLaden: GREATERTHAN objectivesAtLowerBody ATLOWEREND;

objectivesAtLowerBody:  osglIntArrayData;


objectivesAtUpper: | objectivesAtUpperStart objectivesAtUpperNumberOfElATT objectivesAtUpperContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesAtUpperStart: ATUPPERSTART;

objectivesAtUpperNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtUpperContent: objectivesAtUpperEmpty | objectivesAtUpperLaden;

objectivesAtUpperEmpty: ENDOFELEMENT;

objectivesAtUpperLaden: GREATERTHAN objectivesAtUpperBody ATUPPEREND;

objectivesAtUpperBody:  osglIntArrayData;


objectivesAtEquality: | objectivesAtEqualityStart objectivesAtEqualityNumberOfElATT objectivesAtEqualityContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesAtEqualityStart: ATEQUALITYSTART;

objectivesAtEqualityNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtEqualityContent: objectivesAtEqualityEmpty | objectivesAtEqualityLaden;

objectivesAtEqualityEmpty: ENDOFELEMENT;

objectivesAtEqualityLaden: GREATERTHAN objectivesAtEqualityBody ATEQUALITYEND;

objectivesAtEqualityBody:  osglIntArrayData;


objectivesIsFree: | objectivesIsFreeStart objectivesIsFreeNumberOfElATT objectivesIsFreeContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesIsFreeStart: ISFREESTART;

objectivesIsFreeNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesIsFreeContent: objectivesIsFreeEmpty | objectivesIsFreeLaden;

objectivesIsFreeEmpty: ENDOFELEMENT;

objectivesIsFreeLaden: GREATERTHAN objectivesIsFreeBody ISFREEEND;

objectivesIsFreeBody:  osglIntArrayData;


objectivesSuperbasic: | objectivesSuperbasicStart objectivesSuperbasicNumberOfElATT objectivesSuperbasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesSuperbasicStart: SUPERBASICSTART;

objectivesSuperbasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesSuperbasicContent: objectivesSuperbasicEmpty | objectivesSuperbasicLaden;

objectivesSuperbasicEmpty: ENDOFELEMENT;

objectivesSuperbasicLaden: GREATERTHAN objectivesSuperbasicBody SUPERBASICEND;

objectivesSuperbasicBody:  osglIntArrayData;


objectivesUnknown: | objectivesUnknownStart objectivesUnknownNumberOfElATT objectivesUnknownContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

objectivesUnknownStart: UNKNOWNSTART;

objectivesUnknownNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesUnknownContent: objectivesUnknownEmpty | objectivesUnknownLaden;

objectivesUnknownEmpty: ENDOFELEMENT;

objectivesUnknownLaden: GREATERTHAN objectivesUnknownBody UNKNOWNEND;

objectivesUnknownBody:  osglIntArrayData;


otherObjectiveResultsArray: | otherObjectiveResultsArray otherObjectiveResult;

otherObjectiveResult: otherObjectiveResultStart otherObjectiveResultAttributes otherObjectiveResultContent
	{ 	 
		parserData->iOther++;  
	}
;

otherObjectiveResultStart: OTHERSTART
{
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfObjAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->objTypeAttributePresent = false;
	parserData->enumTypeAttributePresent = false;
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->typeAttribute = "";
	parserData->objTypeAttribute = "";
	parserData->enumTypeAttribute = "";
	parserData->descriptionAttribute = "";
}; 

otherObjectiveResultAttributes: otherObjectiveResultAttList
	{
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	};


otherObjectiveResultAttList: | otherObjectiveResultAttList otherObjectiveResultATT;

otherObjectiveResultATT: 
	numberOfObjAttribute 
	{
		if (parserData->numberOfObjAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
		parserData->numberOfObjAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	}
  | numberOfEnumerationsAttribute
	{
		if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}  
  | valueAttribute 
    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
  | nameAttribute 
    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
  | typeAttribute 
    {	
	 	if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultType failed");
    }
  | objTypeAttribute 
    {	
	 	if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->objTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjType failed");
    }
  | enumTypeAttribute 
    {	
	 	if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultEnumType failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    };
  
otherObjectiveResultContent: otherObjectiveResultEmpty | otherObjectiveResultLaden;

otherObjectiveResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherObjectiveResultLaden: GREATERTHAN otherObjectiveResultBody OTHEREND;

otherObjectiveResultBody:  otherObjList | otherObjEnumerationList;

otherObjList: otherObj | otherObjList otherObj;

otherObj: otherObjStart otherObjAttList otherObjContent 
{  
	parserData->kounter++;
};

otherObjStart: OBJSTART
{	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;	
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
};

otherObjAttList: | otherObjAttList otherObjAtt;

otherObjAtt:
	idxAttribute
	{
		if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
	}
  | nameAttribute
	{	
 		if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
	};

otherObjContent: otherObjEmpty | otherObjLaden;

otherObjEmpty: GREATERTHAN OBJEND | ENDOFELEMENT;

otherObjLaden: GREATERTHAN otherObjBody OBJEND;

otherObjBody:  ElementValue  
	{
		if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	};


otherObjEnumerationList: otherObjEnumeration | otherObjEnumerationList otherObjEnumeration;

otherObjEnumeration: otherObjEnumerationStart otherObjEnumerationAttributes otherObjEnumerationContent 
{ 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
};

otherObjEnumerationStart: ENUMERATIONSTART
{
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};	

otherObjEnumerationAttributes: otherObjEnumerationAttList 
	{
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	};
	  
otherObjEnumerationAttList: | otherObjEnumerationAttList otherObjEnumerationATT;

otherObjEnumerationATT: 
	numberOfElAttribute 
	{
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	} 
  | valueAttribute
  | descriptionAttribute
  ;


otherObjEnumerationContent: otherObjEnumerationEmpty | otherObjEnumerationLaden;

otherObjEnumerationEmpty: ENDOFELEMENT;

otherObjEnumerationLaden: GREATERTHAN otherObjEnumerationBody ENUMERATIONEND;


otherObjEnumerationBody:  osglIntArrayData;  


constraints: | constraintsStart numberOfOtherConstraintResults constraintsContent;

constraintsStart: CONSTRAINTSSTART
{
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
};

numberOfOtherConstraintResults: | numberOfOtherConstraintResultsAttribute
{
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
};

constraintsContent: constraintsEmpty | constraintsLaden;

constraintsEmpty: ENDOFELEMENT;

constraintsLaden: GREATERTHAN constraintsBody CONSTRAINTSEND;

constraintsBody:  dualValues slackBasisStatus otherConstraintResultsArray;

dualValues: | dualValuesStart numberOfConATT dualValuesContent;

dualValuesStart: DUALVALUESSTART
{	parserData->numberAttributePresent = false; };

numberOfConATT: numberOfConAttribute
{
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
};

dualValuesContent:
	dualValuesEmpty 
	{
		if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	}
  | dualValuesLaden
	{
		if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	};

dualValuesEmpty: GREATERTHAN DUALVALUESEND | ENDOFELEMENT; 

dualValuesLaden: GREATERTHAN dualValuesBody DUALVALUESEND;

dualValuesBody:  dualValueArray;

dualValueArray: dualValue | dualValueArray dualValue;

dualValue: dualValueStart dualValueAttList dualValueContent 
{
	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->nameAttribute,
							   parserData->tempVal                           ) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
}; 

dualValueStart: CONSTART
{	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
};

dualValueAttList: | dualValueAttList dualValueAtt;

dualValueAtt:
	idxAttribute
  | nameAttribute
  ;

dualValueContent: GREATERTHAN aNumber CONEND;


slackBasisStatus: | slackBasisStatusStart slackBasisStatusContent;

slackBasisStatusStart: BASISSTATUSSTART
{
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
};

slackBasisStatusContent: slackBasisStatusEmpty | slackBasisStatusLaden;
 
slackBasisStatusEmpty: ENDOFELEMENT;

slackBasisStatusLaden: GREATERTHAN slackBasisStatusBody BASISSTATUSEND;

slackBasisStatusBody:  slacksBasic slacksAtLower slacksAtUpper slacksAtEquality slacksIsFree slacksSuperbasic slacksUnknown;

slacksBasic: | slacksBasicStart slacksBasicNumberOfElATT slacksBasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksBasicStart: BASICSTART;

slacksBasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksBasicContent: slacksBasicEmpty | slacksBasicLaden;

slacksBasicEmpty: ENDOFELEMENT;

slacksBasicLaden: GREATERTHAN slacksBasicBody BASICEND;

slacksBasicBody:  osglIntArrayData;

slacksAtLower: | slacksAtLowerStart slacksAtLowerNumberOfElATT slacksAtLowerContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksAtLowerStart: ATLOWERSTART;

slacksAtLowerNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtLowerContent: slacksAtLowerEmpty | slacksAtLowerLaden;

slacksAtLowerEmpty: ENDOFELEMENT;

slacksAtLowerLaden: GREATERTHAN slacksAtLowerBody ATLOWEREND;

slacksAtLowerBody:  osglIntArrayData;


slacksAtUpper: | slacksAtUpperStart slacksAtUpperNumberOfElATT slacksAtUpperContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksAtUpperStart: ATUPPERSTART;

slacksAtUpperNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtUpperContent: slacksAtUpperEmpty | slacksAtUpperLaden;

slacksAtUpperEmpty: ENDOFELEMENT;

slacksAtUpperLaden: GREATERTHAN slacksAtUpperBody ATUPPEREND;

slacksAtUpperBody:  osglIntArrayData;


slacksAtEquality: | slacksAtEqualityStart slacksAtEqualityNumberOfElATT slacksAtEqualityContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksAtEqualityStart: ATEQUALITYSTART;

slacksAtEqualityNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtEqualityContent: slacksAtEqualityEmpty | slacksAtEqualityLaden;

slacksAtEqualityEmpty: ENDOFELEMENT;

slacksAtEqualityLaden: GREATERTHAN slacksAtEqualityBody ATEQUALITYEND;

slacksAtEqualityBody:  osglIntArrayData;


slacksIsFree: | slacksIsFreeStart slacksIsFreeNumberOfElATT slacksIsFreeContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksIsFreeStart: ISFREESTART;

slacksIsFreeNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksIsFreeContent: slacksIsFreeEmpty | slacksIsFreeLaden;

slacksIsFreeEmpty: ENDOFELEMENT;

slacksIsFreeLaden: GREATERTHAN slacksIsFreeBody ISFREEEND;

slacksIsFreeBody:  osglIntArrayData;


slacksSuperbasic: | slacksSuperbasicStart slacksSuperbasicNumberOfElATT slacksSuperbasicContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksSuperbasicStart: SUPERBASICSTART;

slacksSuperbasicNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksSuperbasicContent: slacksSuperbasicEmpty | slacksSuperbasicLaden;

slacksSuperbasicEmpty: ENDOFELEMENT;

slacksSuperbasicLaden: GREATERTHAN slacksSuperbasicBody SUPERBASICEND;

slacksSuperbasicBody:  osglIntArrayData;


slacksUnknown: | slacksUnknownStart slacksUnknownNumberOfElATT slacksUnknownContent
{
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
};

slacksUnknownStart: UNKNOWNSTART;

slacksUnknownNumberOfElATT: numberOfElAttribute
{
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksUnknownContent: slacksUnknownEmpty | slacksUnknownLaden;

slacksUnknownEmpty: ENDOFELEMENT;

slacksUnknownLaden: GREATERTHAN slacksUnknownBody UNKNOWNEND;

slacksUnknownBody:  osglIntArrayData;

                         
otherConstraintResultsArray: | otherConstraintResultsArray otherConstraintResult;

otherConstraintResult: otherConstraintResultStart otherConstraintResultAttributes otherConstraintResultContent
	{ 	 
		parserData->iOther++;  
	}
;

otherConstraintResultStart: OTHERSTART
{
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfConAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->typeAttributePresent = false;
	parserData->conTypeAttributePresent = false;
	parserData->enumTypeAttributePresent = false;
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->typeAttribute = "";
	parserData->conTypeAttribute = "";
	parserData->enumTypeAttribute = "";
	parserData->descriptionAttribute = "";
}; 

otherConstraintResultAttributes: otherConstraintResultAttList
	{
		if (!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	};

otherConstraintResultAttList: | otherConstraintResultAttList otherConstraintResultATT;

otherConstraintResultATT: 
	numberOfConAttribute
	{
		if (parserData->numberOfConAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
		parserData->numberOfConAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	} 
  | numberOfEnumerationsAttribute
	{
		if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}  
  | valueAttribute 
    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
  | nameAttribute 
    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
  | typeAttribute 
    {	
	 	if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultType failed");
    }
  | conTypeAttribute 
    {	
	 	if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->conTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConType failed");
    }
  | enumTypeAttribute 
    {	
	 	if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultEnumType failed");
    }
  | descriptionAttribute
    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    };
  
otherConstraintResultContent: otherConstraintResultEmpty | otherConstraintResultLaden;

otherConstraintResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT	

otherConstraintResultLaden: GREATERTHAN otherConstraintResultBody OTHEREND;

otherConstraintResultBody:  otherConList | otherConEnumerationList;

otherConList: otherCon | otherConList otherCon;

otherCon: otherConStart otherConAttList otherConContent 
{ 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
};
  
otherConStart: CONSTART
{	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
};

otherConAttList: | otherConAttList otherConAtt;


otherConAtt:
	idxAttribute
	{	
 		if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
	}
  | nameAttribute
	{	
 		if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
	}
  ;

otherConContent: otherConEmpty | otherConLaden;

otherConEmpty: GREATERTHAN CONEND | ENDOFELEMENT;

otherConLaden: GREATERTHAN otherConBody CONEND;

otherConBody:  ElementValue  
	{	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	};


otherConEnumerationList: otherConEnumeration | otherConEnumerationList otherConEnumeration;

otherConEnumeration: otherConEnumerationStart otherConEnumerationAttributes otherConEnumerationContent 
{ 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
};

otherConEnumerationStart: ENUMERATIONSTART
{
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
};	

otherConEnumerationAttributes: otherConEnumerationAttList 
	{
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	};
	  
otherConEnumerationAttList: | otherConEnumerationAttList otherConEnumerationATT;

otherConEnumerationATT: 
	numberOfElAttribute 
	{
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	} 
  | valueAttribute
  | descriptionAttribute
  ;


otherConEnumerationContent: otherConEnumerationEmpty | otherConEnumerationLaden;

otherConEnumerationEmpty: ENDOFELEMENT;

otherConEnumerationLaden: GREATERTHAN otherConEnumerationBody ENUMERATIONEND;

otherConEnumerationBody:  osglIntArrayData;  



otherSolutionResults: | otherSolutionResultsStart numberOfOtherSolutionResults otherSolutionResultsContent;

otherSolutionResultsStart: OTHERSOLUTIONRESULTSSTART
{
	parserData->numberOf = 0; 
};

numberOfOtherSolutionResults: numberOfOtherSolutionResultsAttribute
{	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
};

otherSolutionResultsContent:
	otherSolutionResultsEmpty 
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	}
  | otherSolutionResultsLaden
	{
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	};

otherSolutionResultsEmpty: GREATERTHAN OTHERSOLUTIONRESULTSEND | ENDOFELEMENT;

otherSolutionResultsLaden: GREATERTHAN otherSolutionResultsBody OTHERSOLUTIONRESULTSEND;

otherSolutionResultsBody:  otherSolutionResultArray; 

otherSolutionResultArray: otherSolutionResult | otherSolutionResultArray otherSolutionResult;

otherSolutionResult: otherSolutionResultStart otherSolutionResultAttributes otherSolutionResultContent
{
	parserData->iOther++;
};	

otherSolutionResultStart: OTHERSOLUTIONRESULTSTART  
{
	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
};

otherSolutionResultAttributes: otherSolutionResultAttList 
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
};	

otherSolutionResultAttList: | otherSolutionResultAttList otherSolutionResultAtt;

otherSolutionResultAtt: 
	nameAttribute 
	{	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	} 
  | categoryAttribute 
	{	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	} 
  | descriptionAttribute
	{	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	}
  | numberOfItemsAttribute
	{	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	};

otherSolutionResultContent:
	otherSolutionResultEmpty
	{
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
  | otherSolutionResultLaden
	{
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	};

otherSolutionResultEmpty: GREATERTHAN OTHERSOLUTIONRESULTEND | ENDOFELEMENT; 

otherSolutionResultLaden: GREATERTHAN otherSolutionResultBody OTHERSOLUTIONRESULTEND;

otherSolutionResultBody:   otherSolutionResultItemArray;

otherSolutionResultItemArray: otherSolutionResultItem | otherSolutionResultItemArray otherSolutionResultItem;

otherSolutionResultItem: otherSolutionResultItemContent
{
	parserData->kounter++;
};	

otherSolutionResultItemContent: 
	otherSolutionResultItemEmpty
	{
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}
  | otherSolutionResultItemLaden; 

otherSolutionResultItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

otherSolutionResultItemLaden: ITEMSTART otherSolutionResultItemBody ITEMEND;

otherSolutionResultItemBody:  ITEMTEXT 
{
	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = $1; free($1);
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
};


otherSolverOutput: | otherSolverOutputStart numberOfSolverOutputsATT otherSolverOutputContent;

otherSolverOutputStart: OTHERSOLVEROUTPUTSTART
{
	parserData->numberOf = 0; 
};

numberOfSolverOutputsATT: numberOfSolverOutputsAttribute
{	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
};

otherSolverOutputContent: 
	otherSolverOutputEmpty 
	{
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	}
  | otherSolverOutputLaden
	{
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	};

otherSolverOutputEmpty: GREATERTHAN OTHERSOLVEROUTPUTEND | ENDOFELEMENT;

otherSolverOutputLaden: GREATERTHAN otherSolverOutputBody OTHERSOLVEROUTPUTEND;

otherSolverOutputBody:   solverOutputArray;

solverOutputArray: solverOutput | solverOutputArray solverOutput;

solverOutput: solverOutputStart solverOutputAttributes solverOutputContent
{
	parserData->iOther++;
};	

solverOutputStart: SOLVEROUTPUTSTART
{
	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
};

solverOutputAttributes: solverOutputAttList
{
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
};	

solverOutputAttList: | solverOutputAttList solverOutputAtt;

solverOutputAtt: 
	 nameAttribute
	{	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	} 
  | categoryAttribute
	{	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	} 
  | descriptionAttribute
	{	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	}
  | numberOfItemsAttribute
	{	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	};

solverOutputContent: 
	solverOutputEmpty 
	{
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
  | solverOutputLaden
	{
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	};

solverOutputEmpty: GREATERTHAN SOLVEROUTPUTEND | ENDOFELEMENT;

solverOutputLaden: GREATERTHAN solverOutputBody SOLVEROUTPUTEND;

solverOutputBody:  solverOutputItemArray;

solverOutputItemArray: solverOutputItem | solverOutputItemArray solverOutputItem;

solverOutputItem: solverOutputItemContent 
{
	parserData->kounter++;
};	

solverOutputItemContent:
	solverOutputItemEmpty
	{
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}	
  | solverOutputItemLaden; 
	
solverOutputItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOutputItemLaden: ITEMSTART solverOutputItemBody ITEMEND;

solverOutputItemBody:  ITEMTEXT 
{
	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = $1; free($1);
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
};


categoryAttribute: categoryAtt
	{
		if (parserData->categoryAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
		parserData->categoryAttributePresent = true;
	};

categoryAtt: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{ 
	parserData->categoryAttribute = ""; 
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT quote 
{ 
	parserData->categoryAttribute = $2; free($2); 
};

conTypeAttribute: conTypeAtt
	{
		if (parserData->conTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one conType attribute allowed for this element");
		parserData->conTypeAttributePresent = true;
	};

conTypeAtt: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ 
	parserData->conTypeAttribute = ""; 
};

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT quote 
{ 
	parserData->conTypeAttribute = $2; free($2);
};

descriptionAttribute: descriptionAtt
	{
		if (parserData->descriptionAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
		parserData->descriptionAttributePresent = true;
	};

descriptionAtt: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ 
	parserData->descriptionAttribute = ""; 
};

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT quote 
{ 
	parserData->descriptionAttribute = $2; free($2);
};

enumTypeAttribute: enumTypeAtt
	{
		if (parserData->enumTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one enumType attribute allowed for this element");
		parserData->enumTypeAttributePresent = true;
	};

enumTypeAtt: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ 
	parserData->enumTypeAttribute = ""; 
};

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT quote 
{ 
	parserData->enumTypeAttribute = $2; free($2);
};

idxAttribute: IDXATT quote INTEGER quote 
	{	
		if (parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
		parserData->idxAttributePresent = true;
		parserData->idx = $3; 
	};

nameAttribute: nameAtt
	{
	   if (parserData->nameAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	};

nameAtt: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
{ 
	parserData->nameAttribute = ""; 
};

nameAttContent: NAMEATT ATTRIBUTETEXT quote 
{ 
	parserData->nameAttribute = $2; free($2);
};

objTypeAttribute: objTypeAtt
	{
		if (parserData->objTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one objType attribute allowed for this element");
		parserData->objTypeAttributePresent = true;
	};

objTypeAtt: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{ 
	parserData->objTypeAttribute = ""; 
};

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT quote 
{ 
	parserData->objTypeAttribute = $2; free($2);
};

typeAttribute: typeAtt
	{
		if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
		parserData->typeAttributePresent = true;
	};

typeAtt: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{ 
	parserData->typeAttribute = ""; 
};

typeAttContent: TYPEATT ATTRIBUTETEXT quote 
{ 
	parserData->typeAttribute = $2; free($2);
};

unitAttribute: unitAtt
	{
		if (parserData->unitAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
		parserData->unitAttributePresent = true;
	};
		
unitAtt: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ 
	parserData->unitAttribute = ""; 
};

unitAttContent: UNITATT ATTRIBUTETEXT quote 
{ 
	parserData->unitAttribute = $2; free($2);
};

valueAttribute: valueAtt
	{
		if (parserData->valueAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
		parserData->valueAttributePresent = true;
	};

valueAtt: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ 
	parserData->valueAttribute = ""; 
};

valueAttContent: VALUEATT ATTRIBUTETEXT quote 
{ 
	parserData->valueAttribute = $2; free($2);
};

varTypeAttribute: varTypeAtt
	{
		if (parserData->varTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one varType attribute allowed for this element");
		parserData->varTypeAttributePresent = true;
	};

varTypeAtt: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{ 
	parserData->varTypeAttribute = ""; 
};

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT quote 
{ 
	parserData->varTypeAttribute = $2; free($2);
};


numberOfConAttribute: NUMBEROFCONATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = $3;
};

numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{
	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = $3; 
};

numberOfElAttribute: NUMBEROFELATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = $3; 
}; 

numberOfEnumerationsAttribute: NUMBEROFENUMERATIONSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = $3; 
}; 

/*
numberOfIdxAttribute: NUMBEROFIDXATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <idx> cannot be negative");
	parserData->numberOfIdx = $3;
}; 
*/

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = $3;
};

numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = $3;
}; 

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{
	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = $3; 
};

numberOfOtherConstraintResultsAttribute: NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherObjectiveResultsAttribute: NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherResultsAttribute: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherSolutionResultsAttribute: NUMBEROFOTHERSOLUTIONRESULTSATT quote INTEGER quote 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = $3;
};

numberOfOtherVariableResultsAttribute: NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = $3;
};

numberOfSolutionsAttribute: NUMBEROFSOLUTIONSATT quote INTEGER quote 
{
	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = $3; 
};	

numberOfSolverOutputsAttribute: NUMBEROFSOLVEROUTPUTSATT quote INTEGER quote
{	
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = $3;
};

numberOfSubstatusesAttribute: NUMBEROFSUBSTATUSESATT quote INTEGER quote 
{
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = $3;
};

numberOfTimesAttribute: NUMBEROFTIMESATT quote INTEGER quote
{
	parserData->tempInt = $3;
};

numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = $3; 
}; 

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{
	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = $3; 
};

//numberOfVarIdxAttribute: NUMBEROFVARIDXATT quote INTEGER quote 
//{
//	if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <varIdx> cannot be negative");
//	parserData->numberOfVarIdx = $3; 
//}; 

/** ==========================================================================
 *  The code between this and the following marker ought to be shared between 
 *  the OSoL and OSrL parsers. Unfortunately I have not been able to figure out 
 *  yet how to do that, and if it is even possible. Nonetheless the code is
 *  being developed so that it can be cut and pasted without any changes,
 *  and could be moved to an include file once the mechanism has been established. 
 *  The purpose is to parse the OSgL type IntVector and store it in memory.
 *  The IntVector is first processed into a temporary data structure held in 
 *  OSgLParserData and can then be moved to the appropriate permanent spot.
 * ============================================================================ */

osglIntArrayData: 
	osglIntVectorElArray 
	{
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	}
 | osglIntVectorBase64;

osglIntVectorElArray: | osglIntVectorElArray osglIntVectorEl;

osglIntVectorEl: osglIntVectorElStart osglIntVectorElAttributes osglIntVectorElContent;

osglIntVectorElStart: ELSTART
{	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
};


osglIntVectorElAttributes: osglIntVectorElAttList;

osglIntVectorElAttList: | osglIntVectorElAttList osglIntVectorElAtt;

osglIntVectorElAtt: osglMultAttribute | osglIncrAttribute;

osglIntVectorElContent: GREATERTHAN INTEGER ELEND
{
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = $2 + i*osglData->osglIncr;	
};

osglIntVectorBase64: BASE64START Base64SizeAttribute Base64Content;

Base64SizeAttribute: SIZEOFATT quote INTEGER quote
{
	osglData->osglSize = $3;
};

Base64Content: Base64Empty | Base64Laden;

Base64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;

Base64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
	char* b64string = $2;
	if (b64string == NULL) 
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data length does not match numberOfEl"); 
	intvec = (int*)&base64decodeddata[0];
	for (int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete [] b64string;
	free($2);
};


osglIncrAttribute: INCRATT quote INTEGER quote 
{	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = $3;
};

osglMultAttribute: MULTATT quote INTEGER quote 
{	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ($3 <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = $3;
};

/** ==========================================================================
 *  End of marker (see previous comment)
 * ============================================================================ */

aNumber:
	INTEGER {parserData->tempVal = $1;}
  | DOUBLE  {parserData->tempVal = $1;}
  ;

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

void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
	osrl_empty_vectors( parserData );
	osgl_empty_vectors(   osglData );
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "OSrL input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "Error occurred when reading: " << osrlget_text ( scanner ) << std::endl; 
	outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osrllex_destroy( scanner);
	throw ErrorClass( error);
} //end osrlerror

void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass)
{
	try
	{
		osrl_scan_string( parsestring, scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData, osglData) != 0) {
			//osrllex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSrL file");
		 }
	}
	catch(const ErrorClass& eclass)
	{
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult


void osrl_empty_vectors( OSrLParserData* parserData)
{
	int k;
	int numOtherVarVec = parserData->otherVarVec.size();
   
	for (k = 0; k < numOtherVarVec; k++)
	{
		if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarText  != NULL) ) 
			delete[] parserData->otherVarVec[k]->otherVarText;
		if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarIndex != NULL) ) 
			delete[] parserData->otherVarVec[k]->otherVarIndex;
			
		if (  parserData->otherVarVec[k] != NULL) delete parserData->otherVarVec[k];
    	}
  	parserData->otherVarVec.clear(); 
  	
  	int numDualVals =  parserData->dualVals.size();
  	for (k = 0; k < numDualVals; k++)
	{
  		if (parserData->dualVals[k]  != NULL  ) 
			delete parserData->dualVals[k];
  	}
  	parserData->dualVals.clear();
  	
  	
   	int numObjVals =  parserData->objVals.size();
  	for (k = 0; k < numObjVals; k++)
	{
  		if (parserData->objVals[ k]  != NULL  ) 
			delete parserData->objVals[ k];
  	}
  	parserData->objVals.clear();
  	
  	
   	int numPrimalVals =  parserData->primalVals.size();
  	for (k = 0; k < numPrimalVals; k++)
	{	
  		if (parserData->primalVals[ k]  != NULL  ) 
			delete parserData->primalVals[ k];
  	}
  	parserData->primalVals.clear();
}//end osrl_empty_vectors

