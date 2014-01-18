/* $Id$ */
/** @file OSParseosol.y
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2013, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

%{


#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);



%}


%pure-parser
%locations
%defines
%parse-param{OSOption *osoption}
%parse-param{OSoLParserData *parserData}
%parse-param{OSgLParserData *osglData}
%lex-param {void* scanner}


%union {
    double dval;
    int ival;
    char* sval;
}

/* %name-prefix="osol"
this fails in Mac OS X
*/

%{

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg );

int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
std::string osol_errmsg;
bool suppressFurtherErrorMessages;
bool ignoreDataAfterErrors;

#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE

%token TWOQUOTES GREATERTHAN ENDOFELEMENT
%token OSOLSTART OSOLSTARTEMPTY OSOLATTRIBUTETEXT OSOLEND


%token NUMBEROFOTHEROPTIONSATT NUMBEROFENUMERATIONSATT;
%token NUMBEROFJOBIDSATT NUMBEROFPATHSATT NUMBEROFPATHPAIRSATT;
%token FROMATT TOATT MAKECOPYATT CATEGORYATT TYPEATT GROUPWEIGHTATT;
%token NUMBEROFPROCESSESATT NUMBEROFSOLVEROPTIONSATT NUMBEROFSOSATT;
%token NUMBEROFVARIABLESATT NUMBEROFOBJECTIVESATT NUMBEROFCONSTRAINTSATT;
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT;
%token NUMBEROFOTHERCONSTRAINTOPTIONSATT NUMBEROFITEMSATT;
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT NUMBEROFELATT;
%token NAMEATT IDXATT SOSIDXATT VALUEATT UNITATT DESCRIPTIONATT;
%token CONTYPEATT EMPTYCONTYPEATT ENUMTYPEATT EMPTYENUMTYPEATT 
%token OBJTYPEATT EMPTYOBJTYPEATT VARTYPEATT EMPTYVARTYPEATT 
%token EMPTYTYPEATT EMPTYNAMEATT EMPTYCATEGORYATT EMPTYDESCRIPTIONATT EMPTYUNITATT EMPTYVALUEATT;
%token EMPTYLBVALUEATT EMPTYUBVALUEATT LBVALUEATT UBVALUEATT
%token EMPTYLBDUALVALUEATT EMPTYUBDUALVALUEATT LBDUALVALUEATT UBDUALVALUEATT
%token SOLVERATT EMPTYSOLVERATT WEIGHTATT EMPTYWEIGHTATT;
%token TRANSPORTTYPEATT LOCATIONTYPEATT;

%token HEADERSTART HEADEREND GENERALSTART GENERALEND SYSTEMSTART SYSTEMEND SERVICESTART SERVICEEND;
%token JOBSTART JOBEND OPTIMIZATIONSTART OPTIMIZATIONEND;

%token FILENAMESTART FILENAMEEND FILENAMEEMPTY FILENAMESTARTANDEND;
%token FILESOURCESTART FILESOURCEEND FILESOURCEEMPTY FILESOURCESTARTANDEND;
%token FILEDESCRIPTIONSTART FILEDESCRIPTIONEND FILEDESCRIPTIONEMPTY FILEDESCRIPTIONSTARTANDEND; 
%token FILECREATORSTART FILECREATOREND FILECREATOREMPTY FILECREATORSTARTANDEND;
%token FILELICENCESTART FILELICENCEEND FILELICENCEEMPTY FILELICENCESTARTANDEND;

%token SERVICEURISTART SERVICEURIEND SERVICENAMESTART SERVICENAMEEND;
%token INSTANCENAMESTART INSTANCENAMEEND INSTANCELOCATIONSTART INSTANCELOCATIONEND;
%token JOBIDSTART JOBIDEND SOLVERTOINVOKESTART SOLVERTOINVOKEEND;
%token LICENSESTART LICENSEEND USERNAMESTART USERNAMEEND PASSWORDSTART PASSWORDEND;
%token CONTACTSTART CONTACTEND OTHEROPTIONSSTART OTHEROPTIONSEND OTHERSTART OTHEREND;
%token MINDISKSPACESTART MINDISKSPACEEND MINMEMORYSTART MINMEMORYEND MINCPUSPEEDSTART MINCPUSPEEDEND;
%token MINCPUNUMBERSTART MINCPUNUMBEREND SERVICETYPESTART SERVICETYPEEND;
%token MAXTIMESTART MAXTIMEEND REQUESTEDSTARTTIMESTART REQUESTEDSTARTTIMEEND;
%token DEPENDENCIESSTART DEPENDENCIESEND;
%token REQUIREDDIRECTORIESSTART REQUIREDDIRECTORIESEND REQUIREDFILESSTART REQUIREDFILESEND;
%token PATHSTART PATHEND PATHPAIRSTART PATHPAIREND;
%token DIRECTORIESTOMAKESTART DIRECTORIESTOMAKEEND FILESTOMAKESTART FILESTOMAKEEND;
%token DIRECTORIESTODELETESTART DIRECTORIESTODELETEEND FILESTODELETESTART FILESTODELETEEND;
%token  INPUTDIRECTORIESTOMOVESTART  INPUTDIRECTORIESTOMOVEEND  INPUTFILESTOMOVESTART  INPUTFILESTOMOVEEND;
%token OUTPUTDIRECTORIESTOMOVESTART OUTPUTDIRECTORIESTOMOVEEND OUTPUTFILESTOMOVESTART OUTPUTFILESTOMOVEEND;
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND;

%token VARIABLESSTART VARIABLESEND;
%token INITIALVARIABLEVALUESSTART INITIALVARIABLEVALUESEND VARSTART VAREND;
%token INITIALVARIABLEVALUESSTRINGSTART INITIALVARIABLEVALUESSTRINGEND;
%token INITIALBASISSTATUSSTART INITIALBASISSTATUSEND;
%token BASICSTART BASICEND ATUPPERSTART ATUPPEREND ATLOWERSTART ATLOWEREND ATEQUALITYSTART ATEQUALITYEND
%token SUPERBASICSTART SUPERBASICEND ISFREESTART ISFREEEND UNKNOWNSTART UNKNOWNEND
%token INTEGERVARIABLEBRANCHINGWEIGHTSSTART INTEGERVARIABLEBRANCHINGWEIGHTSEND
%token SOSVARIABLEBRANCHINGWEIGHTSSTART SOSVARIABLEBRANCHINGWEIGHTSEND
%token SOSSTART SOSEND

%token OBJECTIVESSTART OBJECTIVESEND;
%token INITIALOBJECTIVEVALUESSTART INITIALOBJECTIVEVALUESEND OBJSTART OBJEND;
%token INITIALOBJECTIVEBOUNDSSTART INITIALOBJECTIVEBOUNDSEND;
%token CONSTRAINTSSTART CONSTRAINTSEND;
%token INITIALCONSTRAINTVALUESSTART INITIALCONSTRAINTVALUESEND CONSTART CONEND;
%token INITIALDUALVALUESSTART INITIALDUALVALUESEND;
%token SOLVEROPTIONSSTART SOLVEROPTIONSEND SOLVEROPTIONSTART SOLVEROPTIONEND;
%token ENUMERATIONSTART ENUMERATIONEND;
%token ITEMEMPTY ITEMSTART ITEMEND ITEMSTARTANDEND;
%token BASE64START BASE64END;
%token INCRATT MULTATT SIZEOFATT;
%token ELSTART ELEND;

%token DUMMY

%%


osoldoc: 
    osolStartEmpty osolBody osolEnd
  | osolStart osolAttributes osolContent;

osolStartEmpty: OSOLSTARTEMPTY
{
#ifdef DEBUG
    yydebug = 1;
#endif
}; 

osolStart: OSOLSTART
{
#ifdef DEBUG
    yydebug = 1;
#endif
    osol_errmsg = "";
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;
}; 

osolAttributes: | OSOLATTRIBUTETEXT;

osolContent: osolEmpty | osolLaden;

osolEmpty: ENDOFELEMENT;

osolLaden: GREATERTHAN osolBody osolEnd; 
    
osolEnd: osolEnding
    {
        if (osol_errmsg != "")
        {
            osol_errmsg += ("\n\nOSoL input is either not valid or well formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, osol_errmsg);
        }
    };

osolEnding: OSOLEND
  | { osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");};

osolBody: 
    headerElement generalElement systemElement serviceElement jobElement optimizationElement;

/**
 * ========================================================== 
 * OSoL header 
 * ==========================================================
 */

headerElement: | headerElementStart headerElementContent
{
    if (!osoption->setOptionHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setHeader failed");
};
 
headerElementStart: HEADERSTART
{
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
};

headerElementContent: headerElementEmpty | headerElementLaden;

headerElementEmpty: GREATERTHAN HEADEREND | ENDOFELEMENT;

headerElementLaden: GREATERTHAN headerElementBody HEADEREND; 

headerElementBody: headerElementList;

headerElementList: headerChild | headerElementList headerChild;

headerChild:
    fileName 
  | fileSource 
  | fileDescription 
  | fileCreator 
  | fileLicence;

fileName: fileNameContent
{
    if (osglData->fileNamePresent == true)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
};

fileNameContent: fileNameEmpty | fileNameLaden;

fileNameEmpty: FILENAMESTARTANDEND | FILENAMEEMPTY;

fileNameLaden: FILENAMESTART ITEMTEXT FILENAMEEND
{
    osglData->fileName = $2;
    free($2);
};

fileSource: fileSourceContent
{
    if (osglData->sourcePresent == true)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
};


fileSourceContent: fileSourceEmpty | fileSourceLaden;

fileSourceEmpty: FILESOURCESTARTANDEND | FILESOURCEEMPTY;

fileSourceLaden: FILESOURCESTART ITEMTEXT FILESOURCEEND
{
    osglData->source = $2;
    free($2);
};

fileDescription: fileDescriptionContent
{
    if (osglData->descriptionPresent == true)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
};

fileDescriptionContent: fileDescriptionEmpty | fileDescriptionLaden;

fileDescriptionEmpty: FILEDESCRIPTIONSTARTANDEND | FILEDESCRIPTIONEMPTY;

fileDescriptionLaden: FILEDESCRIPTIONSTART ITEMTEXT FILEDESCRIPTIONEND
{
    osglData->description = $2;
    free($2);
};

fileCreator: fileCreatorContent
{
    if (osglData->fileCreatorPresent == true)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
};

fileCreatorContent: fileCreatorEmpty | fileCreatorLaden;

fileCreatorEmpty: FILECREATORSTARTANDEND | FILECREATOREMPTY;

fileCreatorLaden: FILECREATORSTART ITEMTEXT FILECREATOREND
{
    osglData->fileCreator = $2;
    free($2);
};

fileLicence: fileLicenceContent{
    if (osglData->licencePresent == true)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
};

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
    parserData->serviceURIPresent          = false;    
    parserData->serviceNamePresent         = false;
    parserData->instanceNamePresent        = false;
    parserData->instanceLocationPresent    = false;
    parserData->jobIDPresent               = false;
    parserData->solverToInvokePresent      = false;
    parserData->licensePresent             = false;
    parserData->usernamePresent            = false;
    parserData->passwordPresent            = false;
    parserData->contactPresent             = false;
    parserData->otherGeneralOptionsPresent = false;
    osoption->general = new GeneralOption();
};

generalElementContent: generalElementEmpty | generalElementLaden;

generalElementEmpty: GREATERTHAN GENERALEND | ENDOFELEMENT;

generalElementLaden: GREATERTHAN generalElementBody GENERALEND; 

generalElementBody:  generalElementList;

generalElementList:  generalChild | generalElementList generalChild;

generalChild: 
    serviceURI 
  | serviceName
  | instanceName 
  | instanceLocation 
  | jobID
  | solverToInvoke 
  | license 
  | username 
  | password 
  | contact 
  | otherGeneralOptions
  ;

/* -------------------------------------------- */
serviceURI: serviceURIStart serviceURIContent;

serviceURIStart: SERVICEURISTART
{
    if (parserData->serviceURIPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
};

serviceURIContent: serviceURIEmpty | serviceURILaden; 

serviceURIEmpty: GREATERTHAN SERVICEURIEND | ENDOFELEMENT;

serviceURILaden: GREATERTHAN serviceURIBody SERVICEURIEND;

serviceURIBody:  ELEMENTTEXT 
    {
        if (osoption->setServiceURI($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceURI failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
    {
        if (parserData->serviceNamePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    };

serviceNameContent: serviceNameEmpty | serviceNameLaden;

serviceNameEmpty: GREATERTHAN SERVICENAMEEND | ENDOFELEMENT;

serviceNameLaden: GREATERTHAN serviceNameBody SERVICENAMEEND;

serviceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setServiceName($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
    {    if (parserData->instanceNamePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    };

instanceNameContent: instanceNameEmpty | instanceNameLaden;

instanceNameEmpty: GREATERTHAN INSTANCENAMEEND | ENDOFELEMENT;

instanceNameLaden: GREATERTHAN instanceNameBody INSTANCENAMEEND;

instanceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setInstanceName($1) == false) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceLocation: instanceLocationStart instanceLocationAttributes instanceLocationContent
{
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceLocation failed");
    parserData->errorText = NULL;
};

instanceLocationStart:  INSTANCELOCATIONSTART 
    {
        if (parserData->instanceLocationPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    };

instanceLocationAttributes: 
    | locationTypeAttribute
    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "instance location type not recognized");
        parserData->errorText = NULL;
    };

locationTypeAttribute: LOCATIONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->typeAttribute = $2; 
    free($2);
};

instanceLocationContent: instanceLocationEmpty | instanceLocationLaden;

instanceLocationEmpty: GREATERTHAN INSTANCELOCATIONEND | ENDOFELEMENT;

instanceLocationLaden: GREATERTHAN instanceLocationBody INSTANCELOCATIONEND;

instanceLocationBody:  ELEMENTTEXT  
    {    
        parserData->tempStr = $1;
        free($1); 
    };


/* -------------------------------------------- */
jobID: jobIDStart jobIDContent;

jobIDStart: JOBIDSTART 
    {    if (parserData->jobIDPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    };
    
jobIDContent: jobIDEmpty | jobIDLaden;

jobIDEmpty: GREATERTHAN JOBIDEND | ENDOFELEMENT;

jobIDLaden: GREATERTHAN jobIDBody JOBIDEND;

jobIDBody:  ELEMENTTEXT  
    {
        if (osoption->setJobID($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setJobID failed");
        free($1); 
        parserData->errorText = NULL;
    };

/* -------------------------------------------- */
solverToInvoke: solverToInvokeStart solverToInvokeContent;

solverToInvokeStart: SOLVERTOINVOKESTART 
    {
        if (parserData->solverToInvokePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    };

solverToInvokeContent: solverToInvokeEmpty | solverToInvokeLaden;

solverToInvokeEmpty: GREATERTHAN SOLVERTOINVOKEEND | ENDOFELEMENT;

solverToInvokeLaden: GREATERTHAN solverToInvokeBody SOLVERTOINVOKEEND;

solverToInvokeBody:  ELEMENTTEXT  
    {
        if (osoption->setSolverToInvoke($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
license: licenseStart licenseContent;

licenseStart: LICENSESTART
{
    if (parserData->licensePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <license>");
    parserData->licensePresent = true;    
};

licenseContent: licenseEmpty | licenseLaden;

licenseEmpty: GREATERTHAN LICENSEEND | ENDOFELEMENT;

licenseLaden: GREATERTHAN licensebody LICENSEEND;

licensebody: ELEMENTTEXT 
    {
        if (osoption->setLicense($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setLicense failed");
        free($1);
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
username: usernameStart usernameContent;

usernameStart: USERNAMESTART
{    if (parserData->usernamePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
};

usernameContent: usernameEmpty | usernameLaden;

usernameEmpty: GREATERTHAN USERNAMEEND | ENDOFELEMENT;

usernameLaden: GREATERTHAN usernamebody USERNAMEEND;

usernamebody: ELEMENTTEXT 
    {
        if (osoption->setUserName($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setUsername failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
password: passwordStart passwordContent;

passwordStart: PASSWORDSTART
{    if (parserData->passwordPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
};

passwordContent: passwordEmpty | passwordLaden;

passwordEmpty: GREATERTHAN PASSWORDEND | ENDOFELEMENT;

passwordLaden: GREATERTHAN passwordbody PASSWORDEND;

passwordbody: ELEMENTTEXT 
    {
        if (osoption->setPassword($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setPassword failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
contact: contactStart contactAttributes contactContent
{
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setContact failed");
    parserData->errorText = NULL;
};

contactStart: CONTACTSTART
{
    if (parserData->contactPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
};

contactAttributes: 
    | transportTypeAttribute
    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "transport type not recognized");
    };

transportTypeAttribute: TRANSPORTTYPEATT ATTRIBUTETEXT QUOTE 
    { 
        parserData->typeAttribute = $2; 
        free($2);
    };


contactContent: contactContentEmpty | contactContentLaden;

contactContentEmpty: GREATERTHAN CONTACTEND | ENDOFELEMENT;

contactContentLaden: GREATERTHAN contactBody CONTACTEND;

contactBody: ELEMENTTEXT
    {
        parserData->tempStr = $1;
        free($1);
    };


/* -------------------------------------------- */
otherGeneralOptions: otherGeneralOptionsStart otherGeneralOptionsAttributes otherGeneralOptionsContent
    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    };

otherGeneralOptionsStart: OTHEROPTIONSSTART
    {
        if (parserData->otherGeneralOptionsPresent)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <general> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    };

otherGeneralOptionsAttributes: numberOfOtherOptionsAttribute 
    {
        if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    };

otherGeneralOptionsContent: 
    otherGeneralOptionsEmpty 
    {
        if (parserData->numberOf > 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }  
  | otherGeneralOptionsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    };
    
otherGeneralOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherGeneralOptionsLaden: GREATERTHAN otherGeneralOptionsBody OTHEROPTIONSEND;

otherGeneralOptionsBody:  otherGeneralOptionArray;


/* -------------------------------------------- */
otherGeneralOptionArray:  otherGeneralOption | otherGeneralOptionArray otherGeneralOption; 

otherGeneralOption: otherGeneralOptionStart otherGeneralAttributes otherGeneralEnd
    {    
        parserData->kounter++;
        if (!ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherGeneralOption failed");
    };    

otherGeneralOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherGeneralAttributes: otherGeneralAttList
{
    if (!parserData->nameAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
};    

otherGeneralAttList: | otherGeneralAttList otherGeneralAtt;

otherGeneralAtt: 
    nameAttribute
    {    if (parserData->nameAttribute.length() == 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
  | valueAttribute
  | descriptionAttribute
  ;

otherGeneralEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



/**
 * ========================================================== 
 * <system> element 
 * ==========================================================
 */
systemElement: | systemElementStart systemElementContent;

systemElementStart: SYSTEMSTART
{
    parserData->minDiskSpacePresent = false;    
    parserData->minMemoryPresent = false;
    parserData->minCPUSpeedPresent = false;
    parserData->minCPUNumberPresent = false;
    parserData->otherSystemOptionsPresent = false;
    osoption->system = new SystemOption();
};

systemElementContent: systemElementEmpty | systemElementLaden;

systemElementEmpty: GREATERTHAN SYSTEMEND | ENDOFELEMENT;

systemElementLaden: GREATERTHAN systemElementBody SYSTEMEND; 
          
systemElementBody:  systemElementList;
               
systemElementList:  systemChild | systemElementList systemChild; 

systemChild: 
    minDiskSpace 
  | minMemorySize 
  | minCPUSpeed 
  | minCPUNumber 
  | otherSystemOptions
  ;

/* -------------------------------------------- */
minDiskSpace: minDiskSpaceStart minDiskSpaceAttributes minDiskSpaceContent;

minDiskSpaceStart: MINDISKSPACESTART
    {    if (parserData->minDiskSpacePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    };

minDiskSpaceAttributes: minDiskSpaceAttList;

minDiskSpaceAttList: | minDiskSpaceAttList minDiskSpaceAtt;

minDiskSpaceAtt: 
    unitAttribute
  | descriptionAttribute
  ;
  
minDiskSpaceContent: GREATERTHAN minDiskSpaceValue MINDISKSPACEEND;

minDiskSpaceValue: aNumber
{
    if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
};

/* -------------------------------------------- */
minMemorySize: minMemoryStart minMemoryAttributes minMemoryContent;

minMemoryStart: MINMEMORYSTART
    {    if (parserData->minMemoryPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    };

minMemoryAttributes: minMemoryAttList;

minMemoryAttList: | minMemoryAttList minMemoryAtt;

minMemoryAtt: 
    unitAttribute 
  | descriptionAttribute
  ;

minMemoryContent: GREATERTHAN minMemoryValue MINMEMORYEND;

minMemoryValue: aNumber
{
    if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUSpeed: minCPUSpeedStart minCPUSpeedAttributes minCPUSpeedContent;

minCPUSpeedStart: MINCPUSPEEDSTART
    {    if (parserData->minCPUSpeedPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "hertz";    
        parserData->descriptionAttribute = "";
    };

minCPUSpeedAttributes: minCPUSpeedAttList;

minCPUSpeedAttList: | minCPUSpeedAttList minCPUSpeedAtt;

minCPUSpeedAtt: 
    unitAttribute 
  | descriptionAttribute
  ;

minCPUSpeedContent: GREATERTHAN minCPUSpeedValue MINCPUSPEEDEND;

minCPUSpeedValue: aNumber
{    
    if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUNumber: minCPUNumberStart minCPUNumberAttributes minCPUNumberContent;

minCPUNumberStart: MINCPUNUMBERSTART
    {    if (parserData->minCPUNumberPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    };

minCPUNumberAttributes: 
  | descriptionAttribute;

minCPUNumberContent: GREATERTHAN minCPUNumberValue MINCPUNUMBEREND;

minCPUNumberValue: INTEGER 
{
    if (osoption->setMinCPUNumber($1, parserData->descriptionAttribute) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUNumber failed");
    //free($1); 
    parserData->errorText = NULL; 
};



/* -------------------------------------------- */
otherSystemOptions: otherSystemOptionsStart otherSystemOptionsAttributes otherSystemOptionsContent
    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    };

otherSystemOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherSystemOptionsPresent)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <system> <otherOptions>");
            ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
};

otherSystemOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherSystemOptionsContent: 
    otherSystemOptionsEmpty
    {    if (parserData->numberOf > 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
  | otherSystemOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    };

otherSystemOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherSystemOptionsLaden: GREATERTHAN otherSystemOptionsBody OTHEROPTIONSEND;

otherSystemOptionsBody:  otherSystemOptionArray;


/* -------------------------------------------- */
otherSystemOptionArray:  otherSystemOption | otherSystemOptionArray otherSystemOption; 

otherSystemOption: otherSystemOptionStart otherSystemOptionAttributes otherSystemOptionEnd
    {
        parserData->kounter++;
        if (!ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherSystemOption failed");
    };

otherSystemOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherSystemOptionAttributes: otherSystemOptionAttList
{    if (!parserData->nameAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
};
    
otherSystemOptionAttList: | otherSystemOptionAttList otherSystemOptionAtt;

otherSystemOptionAtt:
    nameAttribute
    {
        if (parserData->nameAttribute.length() == 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
  | valueAttribute
  | descriptionAttribute
  ;

otherSystemOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



/**
 * ========================================================== 
 * <service> element 
 * ==========================================================
 */
serviceElement: | serviceElementStart serviceElementContent;

serviceElementStart: SERVICESTART
{
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
};

serviceElementContent: serviceElementEmpty | serviceElementLaden;

serviceElementEmpty: GREATERTHAN SERVICEEND | ENDOFELEMENT; 

serviceElementLaden: GREATERTHAN serviceElementBody SERVICEEND;

serviceElementBody:  serviceElementList;
                
serviceElementList:  serviceChild | serviceElementList serviceChild;
        
serviceChild: 
    serviceType 
  | otherServiceOptions
  ;

/* -------------------------------------------- */
serviceType: serviceTypeStart serviceTypeContent;

serviceTypeStart: SERVICETYPESTART
    {    if (parserData->serviceTypePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    };

serviceTypeContent: serviceTypeEmpty | serviceTypeLaden;

serviceTypeEmpty: GREATERTHAN SERVICETYPEEND | ENDOFELEMENT;

serviceTypeLaden: GREATERTHAN serviceTypeBody SERVICETYPEEND;

serviceTypeBody:  ELEMENTTEXT  
    {
        parserData->tempStr = $1; 
        free($1);
        if (osoption->setServiceType(parserData->tempStr) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
otherServiceOptions: otherServiceOptionsStart otherServiceOptionsAttributes otherServiceOptionsContent
    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    };

otherServiceOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherServiceOptionsPresent)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <service> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
};

otherServiceOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherServiceOptionsContent: 
    otherServiceOptionsEmpty
    {    if (parserData->numberOf > 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
  | otherServiceOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    };

otherServiceOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherServiceOptionsLaden: GREATERTHAN otherServiceOptionsBody OTHEROPTIONSEND

otherServiceOptionsBody:  otherServiceOptionArray;


/* -------------------------------------------- */
otherServiceOptionArray: otherServiceOption | otherServiceOptionArray otherServiceOption; 

otherServiceOption: otherServiceOptionStart otherServiceOptionAttributes otherServiceOptionEnd
    {    
        parserData->kounter++;
        if (!ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherServiceOption failed");
    };

otherServiceOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherServiceOptionAttributes: otherServiceOptionAttList
{    if (!parserData->nameAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
};
    
otherServiceOptionAttList: | otherServiceOptionAttList otherServiceOptionAtt;

otherServiceOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;
  
otherServiceOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <job> element 
 * ==========================================================
 */
jobElement: | jobElementStart jobElementContent;

jobElementStart: JOBSTART
{
    parserData->maxTimePresent = false;    
    parserData->requestedStartTimePresent = false;    
    parserData->dependenciesPresent = false;    
    parserData->requiredDirectoriesPresent = false;    
    parserData->requiredFilesPresent = false;    
    parserData->directoriesToMakePresent = false;    
    parserData->filesToMakePresent = false;    
    parserData->inputDirectoriesToMovePresent = false;    
    parserData->inputFilesToMovePresent = false;    
    parserData->outputDirectoriesToMovePresent = false;    
    parserData->outputFilesToMovePresent = false;    
    parserData->filesToDeletePresent = false;    
    parserData->directoriesToDeletePresent = false;    
    parserData->processesToKillPresent = false;    
    parserData->otherJobOptionsPresent = false;     
    osoption->job = new JobOption();
 };

jobElementContent: jobElementEmpty | jobElementLaden;

jobElementEmpty: GREATERTHAN JOBEND | ENDOFELEMENT;

jobElementLaden: GREATERTHAN jobElementBody JOBEND;

jobElementBody:  jobElementList;

jobElementList:  jobChild | jobElementList jobChild;

jobChild: 
    maxTime 
  | requestedStartTime 
  | dependencies 
  | requiredDirectories 
  | requiredFiles
  | directoriesToMake 
  | filesToMake 
  | inputDirectoriesToMove 
  | inputFilesToMove 
  | outputDirectoriesToMove
  | outputFilesToMove  
  | filesToDelete 
  | directoriesToDelete 
  | processesToKill 
  | otherJobOptions
  ;


/* -------------------------------------------- */
maxTime: maxTimeStart maxTimeAttributes maxTimeContent
{    
    if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "max time request could not be honored");
}; 

maxTimeStart: MAXTIMESTART
{    
    if (parserData->maxTimePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
    parserData->maxTimePresent = true;
    parserData->unitAttributePresent = false;    
    parserData->unitAttribute = "second"; 
    parserData->maxTimeValue = OSDBL_MAX;
};

maxTimeAttributes: |
           unitAttribute; 

maxTimeContent: maxTimeEmpty | maxTimeLaden;

maxTimeEmpty: GREATERTHAN MAXTIMEEND | ENDOFELEMENT;

maxTimeLaden: GREATERTHAN maxTimeBody MAXTIMEEND;

maxTimeBody:  maxTimeValue;

maxTimeValue: aNumber
{
    parserData->maxTimeValue = parserData->tempVal;
};


/* -------------------------------------------- */
requestedStartTime: requestedStartTimeStart requestedStartTimeContent;

requestedStartTimeStart: REQUESTEDSTARTTIMESTART 
    {    if (parserData->requestedStartTimePresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    };

requestedStartTimeContent: requestedStartTimeEmpty | requestedStartTimeLaden;

requestedStartTimeEmpty: GREATERTHAN REQUESTEDSTARTTIMEEND | ENDOFELEMENT;

requestedStartTimeLaden: GREATERTHAN requestedStartTimeBody REQUESTEDSTARTTIMEEND;

requestedStartTimeBody:  ELEMENTTEXT  
    {
        if (osoption->setRequestedStartTime($1) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setRequestedStartTime failed");    
        free($1); 
        parserData->errorText = NULL;
        };


/* -------------------------------------------- */
dependencies: dependenciesStart dependenciesAttributes dependenciesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

dependenciesStart: DEPENDENCIESSTART
{
    if (parserData->dependenciesPresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
};

dependenciesAttributes: numberOfJobIDsATT;

dependenciesContent: dependenciesEmpty | dependenciesLaden;

dependenciesEmpty: GREATERTHAN DEPENDENCIESEND | ENDOFELEMENT;

dependenciesLaden: GREATERTHAN dependenciesList DEPENDENCIESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
        ignoreDataAfterErrors = true;        
    }
};

dependenciesList: dependencyJobID | dependenciesList dependencyJobID;

dependencyJobID: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->jobDependencies[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};


/* -------------------------------------------- */
requiredDirectories: requiredDirectoriesStart numberOfPathsAttribute requiredDirectoriesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

requiredDirectoriesStart: REQUIREDDIRECTORIESSTART
{
    if (parserData->requiredDirectoriesPresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
};

requiredDirectoriesContent: requiredDirectoriesEmpty | requiredDirectoriesLaden;

requiredDirectoriesEmpty: GREATERTHAN REQUIREDDIRECTORIESEND | ENDOFELEMENT;

requiredDirectoriesLaden: GREATERTHAN PathList REQUIREDDIRECTORIESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
        ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
requiredFiles: requiredFilesStart numberOfPathsAttribute requiredFilesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

requiredFilesStart: REQUIREDFILESSTART
{
    if (parserData->requiredFilesPresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
};

requiredFilesContent: requiredFilesEmpty | requiredFilesLaden;

requiredFilesEmpty: GREATERTHAN REQUIREDFILESEND | ENDOFELEMENT;

requiredFilesLaden: GREATERTHAN PathList REQUIREDFILESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
        ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToMake: directoriesToMakeStart numberOfPathsAttribute directoriesToMakeContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

directoriesToMakeStart: DIRECTORIESTOMAKESTART
{
    if (parserData->directoriesToMakePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
};

directoriesToMakeContent: directoriesToMakeEmpty | directoriesToMakeLaden;

directoriesToMakeEmpty: GREATERTHAN DIRECTORIESTOMAKEEND | ENDOFELEMENT;

directoriesToMakeLaden: GREATERTHAN PathList DIRECTORIESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
        ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
filesToMake: filesToMakeStart numberOfPathsAttribute filesToMakeContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

filesToMakeStart: FILESTOMAKESTART
{
    if (parserData->filesToMakePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
};

filesToMakeContent: filesToMakeEmpty | filesToMakeLaden;

filesToMakeEmpty: GREATERTHAN FILESTOMAKEEND | ENDOFELEMENT;

filesToMakeLaden: GREATERTHAN PathList FILESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
        ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
inputDirectoriesToMove: inputDirectoriesToMoveStart inputDirectoriesToMoveAttributes inputDirectoriesToMoveContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;
};

inputDirectoriesToMoveStart: INPUTDIRECTORIESTOMOVESTART
{
    if (parserData->inputDirectoriesToMovePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
};

inputDirectoriesToMoveAttributes: numberOfPathPairsAttribute;

inputDirectoriesToMoveContent: inputDirectoriesToMoveEmpty | inputDirectoriesToMoveLaden;

inputDirectoriesToMoveEmpty: GREATERTHAN INPUTDIRECTORIESTOMOVEEND | ENDOFELEMENT;

inputDirectoriesToMoveLaden: GREATERTHAN inputDirectoriesToMoveList INPUTDIRECTORIESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
        ignoreDataAfterErrors = true;        
    }
};

inputDirectoriesToMoveList: inputDirectoryToMove | inputDirectoriesToMoveList inputDirectoryToMove;

inputDirectoryToMove: PathPair;


/* -------------------------------------------- */
inputFilesToMove: inputFilesToMoveStart inputFilesToMoveAttributes inputFilesToMoveContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

inputFilesToMoveStart: INPUTFILESTOMOVESTART
{
    if (parserData->inputFilesToMovePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
};

inputFilesToMoveAttributes: numberOfPathPairsAttribute;

inputFilesToMoveContent: inputFilesToMoveEmpty | inputFilesToMoveLaden;

inputFilesToMoveEmpty: GREATERTHAN INPUTFILESTOMOVEEND | ENDOFELEMENT;

inputFilesToMoveLaden: GREATERTHAN inputFilesToMoveList INPUTFILESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
        ignoreDataAfterErrors = true;        
    }
};

inputFilesToMoveList: inputFileToMove | inputFilesToMoveList inputFileToMove;

inputFileToMove: PathPair;


/* -------------------------------------------- */
outputFilesToMove: outputFilesToMoveStart outputFilesToMoveAttributes outputFilesToMoveContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

outputFilesToMoveStart: OUTPUTFILESTOMOVESTART
{
    if (parserData->outputFilesToMovePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
};

outputFilesToMoveAttributes: numberOfPathPairsAttribute;

outputFilesToMoveContent: outputFilesToMoveEmpty | outputFilesToMoveLaden;

outputFilesToMoveEmpty: GREATERTHAN OUTPUTFILESTOMOVEEND | ENDOFELEMENT;

outputFilesToMoveLaden: GREATERTHAN outputFilesToMoveList OUTPUTFILESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
        ignoreDataAfterErrors = true;        
    }
};

outputFilesToMoveList: outputFileToMove | outputFilesToMoveList outputFileToMove;

outputFileToMove: PathPair;


/* -------------------------------------------- */
outputDirectoriesToMove: outputDirectoriesToMoveStart outputDirectoriesToMoveAttributes outputDirectoriesToMoveContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

outputDirectoriesToMoveStart: OUTPUTDIRECTORIESTOMOVESTART
{
    if (parserData->outputDirectoriesToMovePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
};

outputDirectoriesToMoveAttributes: numberOfPathPairsAttribute;

outputDirectoriesToMoveContent: outputDirectoriesToMoveEmpty | outputDirectoriesToMoveLaden;

outputDirectoriesToMoveEmpty: GREATERTHAN OUTPUTDIRECTORIESTOMOVEEND | ENDOFELEMENT;

outputDirectoriesToMoveLaden: GREATERTHAN outputDirectoriesToMoveList OUTPUTDIRECTORIESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
        ignoreDataAfterErrors = true;        
    }
};

outputDirectoriesToMoveList: outputDirectoryToMove | outputDirectoriesToMoveList outputDirectoryToMove;

outputDirectoryToMove: PathPair;


/* -------------------------------------------- */
filesToDelete: filesToDeleteStart filesToDeleteAttributes filesToDeleteContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

filesToDeleteStart: FILESTODELETESTART
{
    if (parserData->filesToDeletePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
};

filesToDeleteAttributes: numberOfPathsAttribute;

filesToDeleteContent: filesToDeleteEmpty | filesToDeleteLaden;

filesToDeleteEmpty: GREATERTHAN FILESTODELETEEND | ENDOFELEMENT;

filesToDeleteLaden: GREATERTHAN PathList FILESTODELETEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
        ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToDelete: directoriesToDeleteStart directoriesToDeleteAttributes directoriesToDeleteContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

directoriesToDeleteStart: DIRECTORIESTODELETESTART
{
    if (parserData->directoriesToDeletePresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
};

directoriesToDeleteAttributes: numberOfPathsAttribute;

directoriesToDeleteContent: directoriesToDeleteEmpty | directoriesToDeleteLaden;

directoriesToDeleteEmpty: GREATERTHAN DIRECTORIESTODELETEEND | ENDOFELEMENT;

directoriesToDeleteLaden: GREATERTHAN PathList DIRECTORIESTODELETEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
        ignoreDataAfterErrors = true;        
    }
};

directoriesToDeleteList: directoryToDelete | directoriesToDeleteList directoryToDelete;

directoryToDelete: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
    if (parserData->kounter >= parserData->numberOf)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <directoriesToDelete> element");
    else
    {
        parserData->paths[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};


/* -------------------------------------------- */
processesToKill: processesToKillStart processesToKillAttributes processesToKillContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

processesToKillStart: PROCESSESTOKILLSTART
{
    if (parserData->processesToKillPresent)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
        ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
};

processesToKillAttributes: numberOfProcessesATT;

processesToKillContent: processesToKillEmpty | processesToKillLaden;

processesToKillEmpty: GREATERTHAN PROCESSESTOKILLEND | ENDOFELEMENT;

processesToKillLaden: GREATERTHAN processesToKillList PROCESSESTOKILLEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
        ignoreDataAfterErrors = true;        
    }
};

processesToKillList: processID | processesToKillList processID;

processID: PROCESSSTART GREATERTHAN ELEMENTTEXT PROCESSEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->processesToKill[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};


/* -------------------------------------------- */
otherJobOptions: otherJobOptionsStart otherJobOptionsAttributes otherJobOptionsContent
    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    };

otherJobOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherJobOptionsPresent)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <job> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
};

otherJobOptionsAttributes: numberOfOtherOptionsAttribute 
{
    if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherJobOptionsContent: 
    otherJobOptionsEmpty
    {    if (parserData->numberOf > 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
  | otherJobOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    };

otherJobOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherJobOptionsLaden: GREATERTHAN otherJobOptionsBody OTHEROPTIONSEND;

otherJobOptionsBody:   otherJobOptionArray;


/* -------------------------------------------- */
otherJobOptionArray: otherJobOption | otherJobOptionArray otherJobOption; 

otherJobOption: otherJobOptionStart otherJobOptionAttributes otherJobOptionEnd
    {
        parserData->kounter++;
        if (!ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherJobOption failed");
    };    

otherJobOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherJobOptionAttributes: otherJobOptionAttList
{
    if (!parserData->nameAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
};

otherJobOptionAttList: | otherJobOptionAttList otherJobOptionAtt;

otherJobOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;

otherJobOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> element 
 * ==========================================================
 */
optimizationElement: | optimizationStart optimizationAttributes optimizationContent;

optimizationStart: OPTIMIZATIONSTART
{
    osoption->optimization = new OptimizationOption();
    parserData->numberOfVariablesPresent = false;
    parserData->numberOfObjectivesPresent = false;
    parserData->numberOfConstraintsPresent = false;
};

optimizationAttributes: optimizationAttList

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
    numberOfVariablesAttribute 
    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(parserData->tempInt) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfVariables failed");
    }             
  | numberOfConstraintsAttribute 
    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfConstraints failed");
    } 
  | numberOfObjectivesAttribute 
    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfObjectives failed");
    };


optimizationContent: optimizationEmpty | optimizationLaden;

optimizationEmpty: ENDOFELEMENT;

optimizationLaden: GREATERTHAN optimizationBody OPTIMIZATIONEND;

optimizationBody: variables objectives constraints solverOptions;

/**
 * ========================================================== 
 * <optimization> <variables> 
 * ==========================================================
 */
variables: | variablesStart variablesAttributes variablesContent;

variablesStart: VARIABLESSTART
{
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
};

variablesAttributes: numberOfOtherVariableOptions
{    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
};

numberOfOtherVariableOptions: | numberOfOtherVariableOptionsAttribute
{    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
};

variablesContent: variablesEmpty | variablesLaden;

variablesEmpty: ENDOFELEMENT;

variablesLaden: GREATERTHAN variablesBody VARIABLESEND;

variablesBody:  initialVariableValues initialVariableValuesString variableInitialBasis 
    integerVariableBranchingWeights sosVariableBranchingWeights otherVariableOptionsArray
{
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialVariableValues: | initialVariableValuesStart initialVariableValuesAttributes initialVariableValuesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

initialVariableValuesStart: INITIALVARIABLEVALUESSTART
{
    parserData->numberOfVarAttributePresent = false;
};

initialVariableValuesAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

initialVariableValuesContent: 
    initialVariableValuesEmpty 
    {
        if (parserData->numberOfVar > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

initialVariableValuesEmpty: GREATERTHAN INITIALVARIABLEVALUESEND | ENDOFELEMENT;

initialVariableValuesLaden: GREATERTHAN initialVariableValuesBody INITIALVARIABLEVALUESEND;

initialVariableValuesBody:  initVarValueArray;

initVarValueArray: initVarValue | initVarValueArray initVarValue;

/* -------------------------------------------- */
initVarValue: initVarValueStart  initVarValueAttributes initVarValueContent
{
    parserData->kounter++;
}; 

initVarValueStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
};

initVarValueAttributes: initVarValueAttList
{
    if (parserData->idxAttributePresent == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
};

initVarValueAttList: | initVarValueAttList initVarValueAtt;

initVarValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        if (!ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initVarValueContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
initialVariableValuesString: | initialVariableValuesStringStart initialVariableValuesStringAttributes initialVariableValuesStringContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

initialVariableValuesStringStart: INITIALVARIABLEVALUESSTRINGSTART
{
    parserData->numberOfVarAttributePresent = false;
};

initialVariableValuesStringAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray    = new         int[parserData->numberOfVar];
    parserData->namArray    = new std::string[parserData->numberOfVar];
    parserData->valueString = new std::string[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}; 

initialVariableValuesStringContent: 
    initialVariableValuesStringEmpty 
    {
        if (parserData->numberOfVar > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValuesString>: expected at least one <var> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesStringLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
            ignoreDataAfterErrors = true;        
        }
    };

initialVariableValuesStringEmpty: GREATERTHAN INITIALVARIABLEVALUESSTRINGEND | ENDOFELEMENT;

initialVariableValuesStringLaden: GREATERTHAN initialVariableValuesStringBody INITIALVARIABLEVALUESSTRINGEND;

initialVariableValuesStringBody:  initVarValueStringArray;

initVarValueStringArray: initVarValueString | initVarValueStringArray initVarValueString;

/* -------------------------------------------- */
initVarValueString: initVarValueStringStart  initVarValueStringAttributes initVarValueStringContent
{
    parserData->kounter++;
}; 

initVarValueStringStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
};

initVarValueStringAttributes: initVarValueStringAttList
{
    if (parserData->idxAttributePresent == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
};

initVarValueStringAttList: | initVarValueStringAttList initVarValueStringAtt;

initVarValueStringAtt:
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (!ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = parserData->valueAttribute;
    }
    
initVarValueStringContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
variableInitialBasis: | variableInitialBasisStart variableInitialBasisContent;

variableInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
};

variableInitialBasisContent: variableInitialBasisEmpty | variableInitialBasisLaden;

variableInitialBasisEmpty: ENDOFELEMENT;

variableInitialBasisLaden: GREATERTHAN variableInitialBasisBody INITIALBASISSTATUSEND;

variableInitialBasisBody:  variablesBasic variablesAtLower variablesAtUpper variablesAtEquality variablesIsFree variablesSuperbasic variablesUnknown;

/* -------------------------------------------- */
variablesBasic: | variablesBasicStart variablesBasicNumberOfElATT variablesBasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesAtLower: | variablesAtLowerStart variablesAtLowerNumberOfElATT variablesAtLowerContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


variablesAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesAtUpper: | variablesAtUpperStart variablesAtUpperNumberOfElATT variablesAtUpperContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesAtEquality: | variablesAtEqualityStart variablesAtEqualityNumberOfElATT variablesAtEqualityContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesIsFree: | variablesIsFreeStart variablesIsFreeNumberOfElATT variablesIsFreeContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesSuperbasic: | variablesSuperbasicStart variablesSuperbasicNumberOfElATT variablesSuperbasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
variablesUnknown: | variablesUnknownStart variablesUnknownNumberOfElATT variablesUnknownContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

variablesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
integerVariableBranchingWeights: | integerVariableBranchingWeightsStart
    integerVariableBranchingWeightsAttributes integerVariableBranchingWeightsContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

integerVariableBranchingWeightsStart: INTEGERVARIABLEBRANCHINGWEIGHTSSTART
{
    parserData->numberOfVarAttributePresent = false;
};

integerVariableBranchingWeightsAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

integerVariableBranchingWeightsContent:
    integerVariableBranchingWeightsEmpty
    {
        if (parserData->numberOfVar > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | integerVariableBranchingWeightsLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

integerVariableBranchingWeightsEmpty: GREATERTHAN INTEGERVARIABLEBRANCHINGWEIGHTSEND | ENDOFELEMENT;

integerVariableBranchingWeightsLaden: GREATERTHAN integerVariableBranchingWeightsBody INTEGERVARIABLEBRANCHINGWEIGHTSEND;

integerVariableBranchingWeightsBody: branchingWeightsArray;


/* This code can be used in both <integerVariableBranchingWeights> and <sosBranchingWeights> <sos> 
   ------------------------------------------------------------------------------------------------*/
   
branchingWeightsArray: branchingWeight | branchingWeightsArray branchingWeight;

branchingWeight: branchingWeightStart branchingWeightAttributes branchingWeightContent
{
    parserData->kounter++;
}; 

branchingWeightStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "1.0";
};

branchingWeightAttributes: branchingWeightAttList
{
    if (parserData->idxAttributePresent == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
};

branchingWeightAttList: | branchingWeightAttList branchingWeightAtt;

branchingWeightAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        if (!ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

branchingWeightContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
sosVariableBranchingWeights: | sosVariableBranchingWeightsStart sosVariableBranchingWeightsAttributes sosVariableBranchingWeightsContent
{
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

sosVariableBranchingWeightsStart: SOSVARIABLEBRANCHINGWEIGHTSSTART
{
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}; 

sosVariableBranchingWeightsAttributes: NUMBEROFSOSATT QUOTE INTEGER QUOTE   
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = $3;
};

sosVariableBranchingWeightsContent:
    sosVariableBranchingWeightsEmpty
    {
        if (parserData->numberOfSOS > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | sosVariableBranchingWeightsLaden
    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

sosVariableBranchingWeightsEmpty: GREATERTHAN SOSVARIABLEBRANCHINGWEIGHTSEND | ENDOFELEMENT;

sosVariableBranchingWeightsLaden: GREATERTHAN sosWeightGroupArray SOSVARIABLEBRANCHINGWEIGHTSEND;

sosWeightGroupArray: sosWeightGroup | sosWeightGroupArray sosWeightGroup;

sosWeightGroup: sosWeightGroupStart sosWeightGroupAttributes sosWeightGroupContent
{
    if (!ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    parserData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray,     parserData->valArray, parserData->namArray) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


sosWeightGroupStart: SOSSTART
{
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many SOS branching weights");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->numberOfVarAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
};

sosWeightGroupAttributes: sosWeightGroupAttList
{
    if (!parserData->sosIdxAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
};

sosWeightGroupAttList: | sosWeightGroupAttList sosWeightGroupAtt; 

sosWeightGroupAtt: 
    sosIdxAttribute;
  | numberOfVarAttribute
    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[parserData->numberOfVar];
        parserData->namArray = new std::string[parserData->numberOfVar];
        parserData->valArray = new      double[parserData->numberOfVar];
        for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        parserData->numberOfVarAttributePresent = true;
    }
  | groupWeightAttribute
;

sosWeightGroupContent: sosWeightGroupEmpty | sosWeightGroupLaden;

sosWeightGroupEmpty:   GREATERTHAN SOSEND | ENDOFELEMENT;

sosWeightGroupLaden:   GREATERTHAN branchingWeightsArray SOSEND;



/* -------------------------------------------- */
otherVariableOptionsArray: | otherVariableOptionsArray otherVariableOption;

otherVariableOption: otherVariableOptionStart otherVariableOptionAttributes otherVariableOptionContent
    {      
        parserData->iOther++;
    };

otherVariableOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherVariableOptions> than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->numberOfVarAttributePresent = false;
    parserData->numberOfVar = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->varTypeAttributePresent = false;    
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}; 

otherVariableOptionAttributes: otherVariableOptionAttList 
    {
        if (!parserData->nameAttributePresent) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfVar,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->varTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    };
      
otherVariableOptionAttList: | otherVariableOptionAttList otherVariableOptionATT;

otherVariableOptionATT: 
    numberOfVarAttribute 
    {
        parserData->kounter = 0;
    }  
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | varTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
  
otherVariableOptionContent: otherVariableOptionEmpty | otherVariableOptionLaden;

otherVariableOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableOptionLaden: GREATERTHAN otherVariableOptionBody OTHEREND;

otherVariableOptionBody:  otherVarList | otherEnumerationList;

otherVarList: otherVar | otherVarList otherVar;

/* -------------------------------------------- */
otherVar: otherVarStart otherVarAttributes otherVarContent 
{     
    if (!ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other variable option <var> element failed");
    parserData->kounter++;
};

otherVarStart: VARSTART
{
    if (parserData->kounter >= parserData->numberOfVar)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherVarAttributes: otherVarAttList;

otherVarAttList: | otherVarAttList otherVarAtt;

otherVarAtt:
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;
      
otherVarContent: otherVarEmpty;

otherVarEmpty: GREATERTHAN VAREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> <objectives> 
 * ==========================================================
 */
objectives: | objectivesStart objectivesAttributes objectivesContent;

objectivesStart: OBJECTIVESSTART
{
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
};

objectivesAttributes: numberOfOtherObjectiveOptions
{    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
};

numberOfOtherObjectiveOptions: | numberOfOtherObjectiveOptionsAttribute
{    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
};

objectivesContent: objectivesEmpty | objectivesLaden;

objectivesEmpty: ENDOFELEMENT;

objectivesLaden: GREATERTHAN objectivesBody OBJECTIVESEND;

objectivesBody:  initialObjectiveValues initialObjectiveBounds objectiveInitialBasis otherObjectiveOptionsArray
{
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialObjectiveValues: | initialObjectiveValuesStart initialObjectiveValuesAttributes initialObjectiveValuesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


initialObjectiveValuesStart: INITIALOBJECTIVEVALUESSTART
{
    parserData->numberOfObjAttributePresent = false;
};


initialObjectiveValuesAttributes: numberOfObjAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfObj];
    parserData->namArray = new std::string[parserData->numberOfObj];
    parserData->valArray = new      double[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}; 

initialObjectiveValuesContent: 
    initialObjectiveValuesEmpty 
    {    
        if (parserData->numberOfObj > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveValuesLaden
    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

initialObjectiveValuesEmpty: GREATERTHAN INITIALOBJECTIVEVALUESEND | ENDOFELEMENT;

initialObjectiveValuesLaden: GREATERTHAN initialObjectiveValuesBody INITIALOBJECTIVEVALUESEND;

initialObjectiveValuesBody:  initObjValueArray;

initObjValueArray: initObjValue | initObjValueArray initObjValue;

/* -------------------------------------------- */
initObjValue: initObjValueStart initObjValueAttributes initObjValueContent
{
    parserData->kounter++;
}; 

initObjValueStart: OBJSTART
{    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->idxAttribute = -1;
};

initObjValueAttributes: initObjValueAttList;

initObjValueAttList: | initObjValueAttList initObjValueAtt;

initObjValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute >= 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initObjValueContent: GREATERTHAN OBJEND | ENDOFELEMENT;

/* -------------------------------------------- */
initialObjectiveBounds: | initialObjectiveBoundsStart numberOfObjATT initialObjectiveBoundsContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


initialObjectiveBoundsStart: INITIALOBJECTIVEBOUNDSSTART
{
    parserData->numberOfObjAttributePresent = false;
};

numberOfObjATT: numberOfObjAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfObj];
    parserData->lbValArray = new      double[parserData->numberOfObj];
    parserData->ubValArray = new      double[parserData->numberOfObj];
    parserData->namArray   = new std::string[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialObjectiveBoundsContent: 
    initialObjectiveBoundsEmpty 
    {
        if (parserData->numberOfObj > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveBoundsLaden
    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

initialObjectiveBoundsEmpty: GREATERTHAN INITIALOBJECTIVEBOUNDSEND | ENDOFELEMENT;

initialObjectiveBoundsLaden: GREATERTHAN initialObjectiveBoundsBody INITIALOBJECTIVEBOUNDSEND;

initialObjectiveBoundsBody:  initObjBoundArray;

initObjBoundArray: initObjBound | initObjBoundArray initObjBound;

/* -------------------------------------------- */
initObjBound: initObjBoundStart initObjBoundAttributes initObjBoundContent
{
    parserData->kounter++;
}; 

initObjBoundStart: OBJSTART
{    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->idxAttribute = -1;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
};

initObjBoundAttributes: initObjBoundAttList;

initObjBoundAttList: | initObjBoundAttList initObjBoundAtt;

initObjBoundAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute >= 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | lbValueAttribute
    {
        if (parserData->lbValueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
  | ubValueAttribute
    {
        if (parserData->ubValueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    };

initObjBoundContent: GREATERTHAN OBJEND | ENDOFELEMENT;


/* -------------------------------------------- */
objectiveInitialBasis: | objectiveInitialBasisStart objectiveInitialBasisContent;

objectiveInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
};

objectiveInitialBasisContent: objectiveInitialBasisEmpty | objectiveInitialBasisLaden;
 
objectiveInitialBasisEmpty: ENDOFELEMENT;

objectiveInitialBasisLaden: GREATERTHAN objectiveInitialBasisBody INITIALBASISSTATUSEND;

objectiveInitialBasisBody:  objectivesBasic objectivesAtLower objectivesAtUpper objectivesAtEquality objectivesIsFree objectivesSuperbasic objectivesUnknown;

/* -------------------------------------------- */
objectivesBasic: | objectivesBasicStart objectivesBasicNumberOfElATT objectivesBasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
objectivesAtLower: | objectivesAtLowerStart objectivesAtLowerNumberOfElATT objectivesAtLowerContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
objectivesAtUpper: | objectivesAtUpperStart objectivesAtUpperNumberOfElATT objectivesAtUpperContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
objectivesAtEquality: | objectivesAtEqualityStart objectivesAtEqualityNumberOfElATT objectivesAtEqualityContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
objectivesIsFree: | objectivesIsFreeStart objectivesIsFreeNumberOfElATT objectivesIsFreeContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
objectivesSuperbasic: | objectivesSuperbasicStart objectivesSuperbasicNumberOfElATT objectivesSuperbasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};


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


/* -------------------------------------------- */
objectivesUnknown: | objectivesUnknownStart objectivesUnknownNumberOfElATT objectivesUnknownContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

objectivesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
otherObjectiveOptionsArray: | otherObjectiveOptionsArray otherObjectiveOption;

otherObjectiveOption: otherObjectiveOptionStart otherObjectiveOptionAttributes otherObjectiveOptionContent
    {      
        parserData->iOther++;  
    }
;

otherObjectiveOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherObjectiveOptions> than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfObj = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->objTypeAttributePresent = false;    
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}; 

otherObjectiveOptionAttributes: otherObjectiveOptionAttList
    {
        if (!parserData->nameAttributePresent) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfObj,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->objTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    };


otherObjectiveOptionAttList: | otherObjectiveOptionAttList otherObjectiveOptionATT;

otherObjectiveOptionATT: 
    numberOfObjAttribute 
    {
        parserData->kounter = 0;
    }
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute 
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | objTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
    
otherObjectiveOptionContent: otherObjectiveOptionEmpty | otherObjectiveOptionLaden;

otherObjectiveOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherObjectiveOptionLaden: GREATERTHAN otherObjectiveOptionBody OTHEREND;

otherObjectiveOptionBody:  otherObjList | otherEnumerationList;

otherObjList: otherObj | otherObjList otherObj;

/* -------------------------------------------- */
otherObj: otherObjStart otherObjAttributes  otherObjContent 
{  
    if (!ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other objective option <obj> element failed");
    parserData->kounter++;
};

otherObjStart: OBJSTART
{

    if (parserData->kounter >= parserData->numberOfObj)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->idxAttribute = -1;
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherObjAttributes: otherObjAttList;

otherObjAttList: | otherObjAttList otherObjAtt;

otherObjAtt:
    idxAttribute
    {
        if (parserData->idxAttribute >= 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;

otherObjContent: otherObjEmpty;

otherObjEmpty: GREATERTHAN OBJEND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> <constraints> 
 * ==========================================================
 */
constraints: | constraintsStart constraintsAttributes constraintsContent;

constraintsStart: CONSTRAINTSSTART
{
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
};

constraintsAttributes: numberOfOtherConstraintOptions
{    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
};

numberOfOtherConstraintOptions: | numberOfOtherConstraintOptionsAttribute
{    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
};

constraintsContent: constraintsEmpty | constraintsLaden;

constraintsEmpty: ENDOFELEMENT;

constraintsLaden: GREATERTHAN constraintsBody CONSTRAINTSEND;

constraintsBody:  initialConstraintValues initialDualValues slacksInitialBasis otherConstraintOptionsArray
{
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialConstraintValues: | initialConstraintValuesStart initialConstraintValuesAttributes initialConstraintValuesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


initialConstraintValuesStart:  INITIALCONSTRAINTVALUESSTART
{
    parserData->numberOfConAttributePresent = false;
};

initialConstraintValuesAttributes: numberOfConAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfCon];
    parserData->namArray = new std::string[parserData->numberOfCon];
    parserData->valArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}; 

initialConstraintValuesContent:
    initialConstraintValuesEmpty 
    {
        if (parserData->numberOfCon > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialConstraintValuesLaden
    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

initialConstraintValuesEmpty: GREATERTHAN INITIALCONSTRAINTVALUESEND | ENDOFELEMENT;

initialConstraintValuesLaden: GREATERTHAN initialConstraintValuesBody INITIALCONSTRAINTVALUESEND;

initialConstraintValuesBody:  initConValueArray;

initConValueArray: initConValue | initConValueArray initConValue;

/* -------------------------------------------- */
initConValue: initConValueStart initConValueAttributes initConValueContent
{
    parserData->kounter++;
}; 

initConValueStart: CONSTART
{    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
};

initConValueAttributes: initConValueAttList
{
    if (parserData->idxAttributePresent == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
};

initConValueAttList: | initConValueAttList initConValueAtt;

initConValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initConValueContent: GREATERTHAN CONEND | ENDOFELEMENT;


/* -------------------------------------------- */
initialDualValues: | initialDualValuesStart initialDualValuesAttributes initialDualValuesContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};


initialDualValuesStart: INITIALDUALVALUESSTART
{
    parserData->numberOfConAttributePresent = false;
};

initialDualValuesAttributes: numberOfConAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfCon];
    parserData->namArray   = new std::string[parserData->numberOfCon];
    parserData->lbValArray = new      double[parserData->numberOfCon];
    parserData->ubValArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialDualValuesContent: 
    initialDualValuesEmpty 
    {
        if (parserData->numberOfCon > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | initialDualValuesLaden
    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

initialDualValuesEmpty: GREATERTHAN INITIALDUALVALUESEND | ENDOFELEMENT;

initialDualValuesLaden: GREATERTHAN initialDualValuesBody INITIALDUALVALUESEND;

initialDualValuesBody:  initDualValueArray;

initDualValueArray: initDualValue | initDualValueArray initDualValue;

/* -------------------------------------------- */
initDualValue: initDualValueStart  initDualValueAttributes initDualValueContent
{    
    parserData->kounter++;
}; 

initDualValueStart: CONSTART
{    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
};

initDualValueAttributes: initDualValueAttList
{
    if (parserData->idxAttributePresent == false)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
};

initDualValueAttList: | initDualValueAttList initDualValueAtt;

initDualValueAtt: 
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | lbDualValueAttribute
    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
  | ubDualValueAttribute
    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
  ;

initDualValueContent: GREATERTHAN CONEND | ENDOFELEMENT;


/* -------------------------------------------- */
slacksInitialBasis: | slacksInitialBasisStart slacksInitialBasisContent;

slacksInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
};

slacksInitialBasisContent: slacksInitialBasisEmpty | slacksInitialBasisLaden;
 
slacksInitialBasisEmpty: ENDOFELEMENT;

slacksInitialBasisLaden: GREATERTHAN slacksInitialBasisBody INITIALBASISSTATUSEND;

slacksInitialBasisBody:  slacksBasic slacksAtLower slacksAtUpper slacksAtEquality slacksIsFree slacksSuperbasic slacksUnknown;

/* -------------------------------------------- */
slacksBasic: | slacksBasicStart slacksBasicNumberOfElATT slacksBasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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

/* -------------------------------------------- */
slacksAtLower: | slacksAtLowerStart slacksAtLowerNumberOfElATT slacksAtLowerContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
slacksAtUpper: | slacksAtUpperStart slacksAtUpperNumberOfElATT slacksAtUpperContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
slacksAtEquality: | slacksAtEqualityStart slacksAtEqualityNumberOfElATT slacksAtEqualityContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
slacksIsFree: | slacksIsFreeStart slacksIsFreeNumberOfElATT slacksIsFreeContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
slacksSuperbasic: | slacksSuperbasicStart slacksSuperbasicNumberOfElATT slacksSuperbasicContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
slacksUnknown: | slacksUnknownStart slacksUnknownNumberOfElATT slacksUnknownContent
{
    if (!ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
};

slacksUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

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


/* -------------------------------------------- */
otherConstraintOptionsArray: | otherConstraintOptionsArray otherConstraintOption;

otherConstraintOption: otherConstraintOptionStart otherConstraintOptionAttributes otherConstraintOptionContent
    {      
        parserData->iOther++;  
    }
;

otherConstraintOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherConstraintOptions> than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfCon = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->conTypeAttributePresent = false;    
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}; 

otherConstraintOptionAttributes: otherConstraintOptionAttList
    {
        if(!parserData->nameAttributePresent) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfCon,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->conTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    };

otherConstraintOptionAttList: | otherConstraintOptionAttList otherConstraintOptionATT;

otherConstraintOptionATT: 
    numberOfConAttribute
    {
        parserData->kounter = 0;
    } 
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute 
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | conTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
  
otherConstraintOptionContent: otherConstraintOptionEmpty | otherConstraintOptionLaden;

otherConstraintOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT    

otherConstraintOptionLaden: GREATERTHAN otherConstraintOptionBody OTHEREND;

otherConstraintOptionBody:  otherConList | otherEnumerationList;

otherConList: otherCon | otherConList otherCon;

/* -------------------------------------------- */
otherCon: otherConStart otherConAttributes  otherConContent 
{     
    if (!ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other constraint option <con> element failed");
    parserData->kounter++;
};
  
otherConStart: CONSTART
{
    if (parserData->kounter >= parserData->numberOfCon)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherConAttributes: otherConAttList;

otherConAttList: | otherConAttList otherConAtt;

otherConAtt:
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;

otherConContent: otherConEmpty;

otherConEmpty: GREATERTHAN CONEND | ENDOFELEMENT;


/**
 * ========================================================== 
 * solver options
 * ==========================================================
 */
solverOptions: | solverOptionsStart numberOfSolverOptionsATT solverOptionsContent
    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    };

solverOptionsStart: SOLVEROPTIONSSTART;

numberOfSolverOptionsATT: numberOfSolverOptionsAttribute
{
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}; 

solverOptionsContent:
    solverOptionsEmpty
    {
        if (parserData->numberOfSolverOptions > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
            ignoreDataAfterErrors = true;        
        }
    }
  | solverOptionsLaden
    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

solverOptionsEmpty: ENDOFELEMENT;

solverOptionsLaden: GREATERTHAN solverOptionArray SOLVEROPTIONSEND;

solverOptionArray: | solverOptionArray solverOption;


/* -------------------------------------------- */
solverOption: solverOptionStart solverOptionAttributes solverOptionContent
{
    if (!ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    parserData->numberOfItems,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->descriptionAttribute,
                    parserData->itemList) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverOptionContent failed");
    if (parserData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
};

solverOptionStart: SOLVEROPTIONSTART
{
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->solverAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->numberOfItemsPresent = false;
    parserData->valueAttribute = "";
    parserData->solverAttribute = "";
    parserData->categoryAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
    parserData->kounter = 0;
};

solverOptionAttributes: solverOptionAttList
{
    if (!parserData->nameAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
};

solverOptionAttList: solverOptionATT | solverOptionAttList solverOptionATT;

solverOptionATT:
     nameAttribute 
  | valueAttribute 
  | solverAttribute
  | categoryAttribute 
  | typeAttribute 
  | descriptionAttribute
  | numberOfItemsAttribute
    {
            parserData->itemList = new std::string[parserData->numberOfItems];
    }
  ;

solverOptionContent:
    solverOptionEmpty
    {
        if (parserData->numberOfItems > 0)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
            ignoreDataAfterErrors = true;        
        }
    }
 | solverOptionLaden
    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
            ignoreDataAfterErrors = true;        
        }
    };

solverOptionEmpty: GREATERTHAN SOLVEROPTIONEND | ENDOFELEMENT;

solverOptionLaden: GREATERTHAN solverOptionBody SOLVEROPTIONEND;

solverOptionBody: solverOptionItemArray;

solverOptionItemArray: solverOptionItem | solverOptionItemArray solverOptionItem;

solverOptionItem: solverOptionItemContent
{    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
};    

solverOptionItemContent: 
    solverOptionItemEmpty
    {
        if (parserData->kounter >= parserData->numberOfItems)
            if (!suppressFurtherErrorMessages)
            {
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
                suppressFurtherErrorMessages = true;
                ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }    
  | solverOptionItemLaden; 

solverOptionItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOptionItemLaden: ITEMSTART solverOptionItemBody ITEMEND;

solverOptionItemBody:  ITEMTEXT 
{
    if (parserData->kounter >= parserData->numberOf)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    parserData->itemContent = $1; 
    free($1);
};


/**
 *  PathList is an object used repeatedly within the <job> element
 */
PathList: Path | PathList Path;

Path: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->paths[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};

/**
 *  PathPair is an object used repeatedly within the <job> element
 */
PathPair: PathPairStart PathPairAttributes PathPairEnd
{    
    if (parserData->kounter >= parserData->numberOfPathPairs)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
};

PathPairStart: PATHPAIRSTART
{
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    parserData->pathPairFrom = "";
    parserData->pathPairTo = "";
    parserData->pathPairFromPresent = false;
    parserData->pathPairToPresent = false;
    parserData->pathPairMakeCopyPresent = false;
    parserData->pathPairMakeCopy = false;
};
    
PathPairAttributes: PathPairAttList
{
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
};

PathPairAttList: | PathPairAttList PathPairAttribute;

PathPairAttribute:
    PathPairFromATT
  | PathPairToATT
  | PathPairMakeCopyATT;
      
PathPairFromATT: FROMATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairFromPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = $2;
    free($2);
};

PathPairToATT: TOATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairToPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = $2;
    free($2);
};

PathPairMakeCopyATT: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairMakeCopyPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp($2,"true") == 0);
    free($2);
};

PathPairEnd: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


/****************************************************************************
 *  Here we collect the rules for some attributes that are used repeatedly  *
 ****************************************************************************/
categoryAttribute: categoryAtt
{   
    if (parserData->categoryAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
    parserData->categoryAttributePresent = true;
};

categoryAtt: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{ 
    parserData->categoryAttribute = "";
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT quote 
{ 
    parserData->categoryAttribute = $2; 
    free($2); 
};

/* ----------------------------------------------------------------------- */
conTypeAttribute: conTypeAtt
        {   if (parserData->conTypeAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one conType attribute allowed for this element");
            parserData->conTypeAttributePresent = true;
        };

conTypeAtt: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ parserData->conTypeAttribute = ""; };

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->conTypeAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
descriptionAttribute: descriptionAtt
{
    if (parserData->descriptionAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
    parserData->descriptionAttributePresent = true;
};

descriptionAtt: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ parserData->descriptionAttribute = ""; };

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT quote 
{ 
    parserData->descriptionAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
enumTypeAttribute: enumTypeAtt
        {   if (parserData->enumTypeAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one enumType attribute allowed for this element");
            parserData->enumTypeAttributePresent = true;
        };

enumTypeAtt: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ parserData->enumTypeAttribute = ""; };

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->enumTypeAttribute = $2; 
    free($2);
};


/* ----------------------------------------------------------------------- */
groupWeightAttribute: groupWeightAtt
{
    if (parserData->groupWeightAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
};

groupWeightAtt: GROUPWEIGHTATT QUOTE aNumber QUOTE
{
    parserData->groupWeight = parserData->tempVal;
};


/* ----------------------------------------------------------------------- */
idxAttribute: idxAtt
{   
    if (parserData->idxAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
};

idxAtt: idxAttContent;

idxAttContent: IDXATT quote INTEGER quote 
{ 
    parserData->idxAttribute = $3;
};

/* ----------------------------------------------------------------------- */
lbValueAttribute: lbValueAtt
{   
    if (parserData->lbValueAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
};

lbValueAtt: lbValueAttEmpty | lbValueAttContent;

lbValueAttEmpty: EMPTYLBVALUEATT
{ 
    parserData->lbValueAttribute = ""; 
};

lbValueAttContent: LBVALUEATT ATTRIBUTETEXT quote
{ 
    parserData->lbValueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
lbDualValueAttribute: lbDualValueAtt
        {   if (parserData->lbValueAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        };

lbDualValueAtt: lbDualValueAttEmpty | lbDualValueAttContent;

lbDualValueAttEmpty: EMPTYLBDUALVALUEATT
{ 
    parserData->lbDualValue = 0.0; 
};

lbDualValueAttContent: LBDUALVALUEATT quote aNumber quote
{
    parserData->lbDualValue = parserData->tempVal;
};

/* ----------------------------------------------------------------------- */
nameAttribute: nameAtt
    {
        if (parserData->nameAttributePresent ) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    };

nameAtt: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
    { 
        parserData->nameAttribute = ""; 
    };

nameAttContent: NAMEATT ATTRIBUTETEXT quote 
    { 
        parserData->nameAttribute = $2; 
        free($2);
    };

/* ----------------------------------------------------------------------- */
objTypeAttribute: objTypeAtt
        {   if (parserData->objTypeAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one objType attribute allowed for this element");
            parserData->objTypeAttributePresent = true;
        };

objTypeAtt: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{ parserData->objTypeAttribute = ""; };

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->objTypeAttribute = $2; 
    free($2);
};


/* ----------------------------------------------------------------------- */
solverAttribute: solverAtt
    {   if (parserData->solverAttributePresent ) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    };

solverAtt: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{ parserData->solverAttribute = ""; };

solverAttContent: SOLVERATT ATTRIBUTETEXT quote 
{ 
    parserData->solverAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
sosIdxAttribute: sosIdxAtt
    {   if (parserData->sosIdxAttributePresent ) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    };

sosIdxAtt: sosIdxAttContent;

sosIdxAttContent: SOSIDXATT quote INTEGER quote 
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
    parserData->sosIdx = $3;
};

/* ----------------------------------------------------------------------- */
typeAttribute: typeAtt
        {   if (parserData->typeAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
            parserData->typeAttributePresent = true;
        };

typeAtt: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{ parserData->typeAttribute = ""; };

typeAttContent: TYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->typeAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
ubValueAttribute: ubValueAtt
{
   if (parserData->ubValueAttributePresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
};

ubValueAtt: ubValueAttEmpty | ubValueAttContent;

ubValueAttEmpty: EMPTYUBVALUEATT
{ 
    parserData->ubValueAttribute = ""; 
};

ubValueAttContent: UBVALUEATT ATTRIBUTETEXT quote
{ 
    parserData->ubValueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
ubDualValueAttribute: ubDualValueAtt
        {   if (parserData->ubValueAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        };

ubDualValueAtt: ubDualValueAttEmpty | ubDualValueAttContent;

ubDualValueAttEmpty: EMPTYUBDUALVALUEATT
{ parserData->ubDualValue = 0.0; };

ubDualValueAttContent: UBDUALVALUEATT quote aNumber quote
{ 
    parserData->ubDualValue = parserData->tempVal;
};


/* ----------------------------------------------------------------------- */
unitAttribute: unitAtt
        {   if (parserData->unitAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
            parserData->unitAttributePresent = true;
        };
        
unitAtt: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ parserData->unitAttribute = ""; };

unitAttContent: UNITATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->unitAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
valueAttribute: valueAtt
        {   if (parserData->valueAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
            parserData->valueAttributePresent = true;
        };

valueAtt: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ parserData->valueAttribute = ""; };

valueAttContent: VALUEATT ATTRIBUTETEXT QUOTE 
{
    parserData->valueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
varTypeAttribute: varTypeAtt
        {   if (parserData->varTypeAttributePresent ) 
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one varType attribute allowed for this element");
            parserData->varTypeAttributePresent = true;
        };

varTypeAtt: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{ parserData->varTypeAttribute = ""; };

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->varTypeAttribute = $2; 
    free($2);
};




/*************************************************************************************
 *  There are so many numberOf... attributes that they warrant their own section...  *
 *************************************************************************************/
numberOfConAttribute: NUMBEROFCONATT quote INTEGER quote
{
    if (parserData->numberOfConAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = $3;
};

numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{
    if (parserData->numberOfConstraintsPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = $3; 
};

numberOfElAttribute: NUMBEROFELATT quote INTEGER quote 
{
    if (osglData->osglNumberOfElPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = $3; 
}; 

numberOfEnumerationsAttribute: NUMBEROFENUMERATIONSATT quote INTEGER quote 
{
    if (parserData->numberOfEnumerationsAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = $3; 
}; 

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{    
   if (parserData->numberOfItemsPresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = $3;
};

numberOfJobIDsATT: NUMBEROFJOBIDSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};

numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
    if (parserData->numberOfObjAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = $3;
}; 

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{
    if (parserData->numberOfObjectivesPresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = $3; 
};

numberOfOtherConstraintOptionsAttribute: NUMBEROFOTHERCONSTRAINTOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherObjectiveOptionsAttribute: NUMBEROFOTHEROBJECTIVEOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherOptionsAttribute: NUMBEROFOTHEROPTIONSATT quote INTEGER quote
{
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherVariableOptionsAttribute: NUMBEROFOTHERVARIABLEOPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
    parserData->tempInt = $3;
};

numberOfPathPairsAttribute: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
    else if ($3 > 0)
    {
        parserData->fromPaths = new std::string[$3];
        parserData->toPaths   = new std::string[$3];
        parserData->makeCopy  = new bool[$3];
    }
    parserData->numberOfPathPairs = $3;
    parserData->kounter = 0;
};

numberOfPathsAttribute: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};

numberOfProcessesATT: NUMBEROFPROCESSESATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};


numberOfSolverOptionsAttribute: NUMBEROFSOLVEROPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = $3;
};

numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
    if (parserData->numberOfVarAttributePresent)
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = $3; 
}; 

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{    if (parserData->numberOfVariablesPresent)

        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = $3; 
};

//numberOfVarIdxAttribute: NUMBEROFVARIDXATT quote INTEGER quote 
//{
//    if ($3 < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <varIdx> cannot be negative");
//    parserData->numberOfVarIdx = $3; 
//}; 


/**
 *  <enumeration> lists occur three times in the OSoL schema:
 *  for variables, objectives and constraints. 
 *  The code below can be used for all three situations.
 */
otherEnumerationList: otherEnumeration | otherEnumerationList otherEnumeration;

otherEnumeration: otherEnumerationStart otherEnumerationAttributes otherEnumerationContent 
{     
    if (!ignoreDataAfterErrors)
        if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->osglNumberOfEl, 
                parserData->valueAttribute, 
                parserData->descriptionAttribute, 
                osglData->osglIntArray) )
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
};

otherEnumerationStart: ENUMERATIONSTART
{
    if (parserData->kounter >= parserData->numberOfEnumerations)
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <enumeration> elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    osglData->osglNumberOfElPresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};    

otherEnumerationAttributes: otherEnumerationAttList 
    {
        if(!osglData->osglNumberOfElPresent) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
    };
      
otherEnumerationAttList: | otherEnumerationAttList otherEnumerationATT;

otherEnumerationATT: 
    numberOfElAttribute 
    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    } 
  | valueAttribute
  | descriptionAttribute
  ;


otherEnumerationContent: otherEnumerationEmpty | otherEnumerationLaden;

otherEnumerationEmpty: ENDOFELEMENT;


otherEnumerationLaden: GREATERTHAN otherEnumerationBody ENUMERATIONEND;

otherEnumerationBody:  osglIntArrayData;  




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
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
            ignoreDataAfterErrors = true;
        }
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
    {
        if (!suppressFurtherErrorMessages)
        {
            osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more data elements than specified");
            suppressFurtherErrorMessages = true;
            ignoreDataAfterErrors = true;
        }
    }
    else
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
    if( b64string == NULL) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free($2);
};


osglIncrAttribute: INCRATT quote INTEGER quote 
{    
    if (osglData->osglIncrPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = $3;
};

osglMultAttribute: MULTATT quote INTEGER quote 
{    
    if (osglData->osglMultPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
    if ($3 <= 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = $3;
};

/** ==========================================================================
 *  End of marker (see previous comment)
 * ============================================================================ */

aNumber:
    INTEGER {parserData->tempVal = $1;}
  | DOUBLE  {parserData->tempVal = $1;};

//ElementValue: 
//    ELEMENTTEXT  { parserData->tempStr = $1;       /*free($1);*/ }
//  | INTEGER      { parserData->tempStr = os_dtoa_format($1); }
//  | DOUBLE       { parserData->tempStr = os_dtoa_format($1); };
  
quote: xmlWhiteSpace QUOTE;

xmlWhiteSpace:  | xmlWhiteSpace xmlWhiteSpaceChar;

xmlWhiteSpaceChar: ' ' 
                 | '\t'
                 | '\r'
                 | '\n';
            

%%

#if 0
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either not valid or well formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass){
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData) != 0) {
            //osollex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSoL file");
         }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSOption


void osol_empty_vectors( OSoLParserData* parserData){
/*
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
*/      
}//end osol_empty_vectors

