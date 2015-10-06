/* $Id$ */
/** @file OSParseosol.y.1
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the first part of the file OSParseosol.y. It contains the
 * preamble and tokens that are unique to the OSoL parser.
 * Tokens pertaining to the OSgL and OSnL parsers are appended next.
 * These are in files OSParseosgl.y.tokens and OSParseosnl.y.tokens.   
 * Then follow the syntax rules involving only OSoL constructs (OSParseosol.y.2). 
 * After that we put the syntax rules for elements from the OSgL schema, 
 * maintained in the file OSParseosgl.y.syntax, and then the OSnL syntax
 * in OSParseosnl.y.syntax. The postamble in OSParseosol.y.3 is appended at the end.
 * This process could be repeated for as many other auxiliary schemas as needed. 
 *
 * Note: Make changes in this file rather than OSParseosol.y or OSParserosol.tab.cpp,
 *       as the latter files are recreated by the build system and are thus to be
 *       considered fragile.
 */

%{


#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

#define OSOPTION_AVAILABLE

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
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);


%}


%pure-parser
%locations
%defines
%parse-param{OSOption *osoption}
%parse-param{OSoLParserData *parserData}
%parse-param{OSgLParserData *osglData}
%parse-param{OSnLParserData *osnlData}
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

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg );
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE
%token <sval> TWOQUOTES

%token GREATERTHAN ENDOFELEMENT

%token OSOLSTART OSOLSTARTEMPTY OSOLATTRIBUTETEXT OSOLEND 

%token EMPTYLBVALUEATT EMPTYUBVALUEATT LBVALUEATT UBVALUEATT
%token EMPTYLBDUALVALUEATT EMPTYUBDUALVALUEATT LBDUALVALUEATT UBDUALVALUEATT
%token WEIGHTATT EMPTYWEIGHTATT
%token TRANSPORTTYPEATT LOCATIONTYPEATT
%token FROMATT TOATT MAKECOPYATT 

%token NUMBEROFJOBIDSATT NUMBEROFPATHSATT NUMBEROFPATHPAIRSATT NUMBEROFPROCESSESATT
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT NUMBEROFOTHERCONSTRAINTOPTIONSATT 
%token NUMBEROFSOLVEROPTIONSATT NUMBEROFOTHEROPTIONSATT NUMBEROFSOSATT

%token SOSIDXATT GROUPWEIGHTATT
 
%token INSTANCELOCATIONSTART INSTANCELOCATIONEND SOLVERTOINVOKESTART SOLVERTOINVOKEEND
%token LICENSESTART LICENSEEND USERNAMESTART USERNAMEEND PASSWORDSTART PASSWORDEND;
%token CONTACTSTART CONTACTEND 

%token MINDISKSPACESTART MINDISKSPACEEND MINMEMORYSTART MINMEMORYEND
%token MINCPUSPEEDSTART MINCPUSPEEDEND MINCPUNUMBERSTART MINCPUNUMBEREND 

%token SERVICETYPESTART SERVICETYPEEND

%token MAXTIMESTART MAXTIMEEND REQUESTEDSTARTTIMESTART REQUESTEDSTARTTIMEEND

%token DEPENDENCIESSTART DEPENDENCIESEND PATHSTART PATHEND PATHPAIRSTART PATHPAIREND
%token REQUIREDDIRECTORIESSTART REQUIREDDIRECTORIESEND REQUIREDFILESSTART REQUIREDFILESEND
%token DIRECTORIESTOMAKESTART DIRECTORIESTOMAKEEND FILESTOMAKESTART FILESTOMAKEEND
%token DIRECTORIESTODELETESTART DIRECTORIESTODELETEEND FILESTODELETESTART FILESTODELETEEND
%token  INPUTDIRECTORIESTOMOVESTART  INPUTDIRECTORIESTOMOVEEND  INPUTFILESTOMOVESTART  INPUTFILESTOMOVEEND
%token OUTPUTDIRECTORIESTOMOVESTART OUTPUTDIRECTORIESTOMOVEEND OUTPUTFILESTOMOVESTART OUTPUTFILESTOMOVEEND
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND

%token INITIALVARIABLEVALUESSTART INITIALVARIABLEVALUESEND
%token INITIALVARIABLEVALUESSTRINGSTART INITIALVARIABLEVALUESSTRINGEND
%token INITIALBASISSTATUSSTART INITIALBASISSTATUSEND
%token INTEGERVARIABLEBRANCHINGWEIGHTSSTART INTEGERVARIABLEBRANCHINGWEIGHTSEND
%token SOSVARIABLEBRANCHINGWEIGHTSSTART SOSVARIABLEBRANCHINGWEIGHTSEND SOSSTART SOSEND
%token INITIALOBJECTIVEVALUESSTART INITIALOBJECTIVEVALUESEND
%token INITIALOBJECTIVEBOUNDSSTART INITIALOBJECTIVEBOUNDSEND
%token INITIALCONSTRAINTVALUESSTART INITIALCONSTRAINTVALUESEND
%token INITIALDUALVALUESSTART INITIALDUALVALUESEND
%token SOLVEROPTIONSSTART SOLVEROPTIONSEND SOLVEROPTIONSTART SOLVEROPTIONEND
%token OTHEROPTIONSSTART OTHEROPTIONSEND



/* $Id$ */
/** @file OSParseosgl.y.tokens
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, the files 
 * OSParseosil.y, OSParseosol.y and OSParseosrl.y are stored in several pieces.
 * These are the tokens pertaining to the OSgL parser, 
 * which are defined in OSParseosgl.l.patterns.
 * They are appended after the regular OSxL tokens.
 */

%token HEADERSTART HEADEREND

%token FILENAMESTART        FILENAMEEND        FILENAMEEMPTY        FILENAMESTARTANDEND
%token FILESOURCESTART      FILESOURCEEND      FILESOURCEEMPTY      FILESOURCESTARTANDEND
%token FILEDESCRIPTIONSTART FILEDESCRIPTIONEND FILEDESCRIPTIONEMPTY FILEDESCRIPTIONSTARTANDEND
%token FILECREATORSTART     FILECREATOREND     FILECREATOREMPTY     FILECREATORSTARTANDEND
%token FILELICENCESTART     FILELICENCEEND     FILELICENCEEMPTY     FILELICENCESTARTANDEND

%token INDEXESSTART INDEXESEND VALUESSTART VALUESEND NONZEROSSTART NONZEROSEND

%token ELSTART ELEND 
%token ENUMERATIONSTART ENUMERATIONEND 
%token ITEMEMPTY ITEMSTART ITEMEND ITEMSTARTANDEND 
%token BASE64START BASE64END

%token NUMBEROFELATT NUMBEROFENUMERATIONSATT NUMBEROFITEMSATT

%token EMPTYCATEGORYATT CATEGORYATT EMPTYDESCRIPTIONATT DESCRIPTIONATT EMPTYSOLVERATT SOLVERATT
%token EMPTYNAMEATT NAMEATT EMPTYTYPEATT TYPEATT EMPTYENUMTYPEATT ENUMTYPEATT EMPTYSHAPEATT SHAPEATT
%token EMPTYUNITATT UNITATT EMPTYVALUEATT VALUEATT EMPTYVALUETYPEATT VALUETYPEATT
%token EMPTYCONTYPEATT CONTYPEATT EMPTYOBJTYPEATT OBJTYPEATT EMPTYVARTYPEATT VARTYPEATT 
%token EMPTYMATRIXCONTYPEATT MATRIXCONTYPEATT
%token EMPTYMATRIXOBJTYPEATT MATRIXOBJTYPEATT
%token EMPTYMATRIXVARTYPEATT MATRIXVARTYPEATT
%token EMPTYMATRIXTYPEATT MATRIXTYPEATT EMPTYSYMMETRYATT SYMMETRYATT 
%token EMPTYROWMAJORATT ROWMAJORATT EMPTYBASETRANSPOSEATT BASETRANSPOSEATT

%token NUMBEROFBLOCKSATT NUMBEROFCOLUMNSATT NUMBEROFROWSATT NUMBEROFMATRICESATT NUMBEROFVALUESATT
%token NUMBEROFCONSTRAINTSATT NUMBEROFCONATT NUMBEROFCONIDXATT
%token NUMBEROFOBJECTIVESATT NUMBEROFOBJATT NUMBEROFOBJIDXATT
%token NUMBEROFVARIABLESATT NUMBEROFVARATT NUMBEROFVARIDXATT
%token NUMBEROFMATRIXCONATT NUMBEROFMATRIXOBJATT NUMBEROFMATRIXVARATT

%token BASEMATRIXIDXATT TARGETMATRIXFIRSTROWATT TARGETMATRIXFIRSTCOLATT
%token BASEMATRIXSTARTROWATT BASEMATRIXSTARTCOLATT BASEMATRIXENDROWATT BASEMATRIXENDCOLATT
%token SCALARMULTIPLIERATT BLOCKROWIDXATT BLOCKCOLIDXATT 

%token MATRIXVARIDXATT MATRIXOBJIDXATT MATRIXCONIDXATT

%token IDXATT INCRATT MULTATT SIZEOFATT 

%token COEFATT CONSTANTATT

%token MATRICESSTART MATRICESEND MATRIXSTART MATRIXEND BASEMATRIXEND BASEMATRIXSTART
%token BLOCKSSTART BLOCKSEND BLOCKSTART BLOCKEND
%token COLOFFSETSTART COLOFFSETEND ROWOFFSETSTART ROWOFFSETEND

%token ELEMENTSSTART ELEMENTSEND
%token CONSTANTELEMENTSSTART CONSTANTELEMENTSEND
%token COMPLEXELEMENTSSTART COMPLEXELEMENTSEND
%token VARREFERENCEELEMENTSSTART VARREFERENCEELEMENTSEND
%token LINEARELEMENTSSTART LINEARELEMENTSEND
%token CONREFERENCEELEMENTSSTART CONREFERENCEELEMENTSEND
%token OBJREFERENCEELEMENTSSTART OBJREFERENCEELEMENTSEND
%token REALVALUEDEXPRESSIONSSTART REALVALUEDEXPRESSIONSSEND
%token COMPLEXVALUEDEXPRESSIONSSTART COMPLEXVALUEDEXPRESSIONSSEND
%token STRINGVALUEDELEMENTSSTART STRINGVALUEDELEMENTSEND 


%token STARTVECTORSTART STARTVECTOREND INDEXSTART INDEXEND VALUESTART VALUEEND

%token VARIDXSTART VARIDXEND TRANSFORMATIONSTART TRANSFORMATIONEND

%token MATRIXPROGRAMMINGSTART MATRIXPROGRAMMINGEND
%token MATRIXVARIABLESSTART   MATRIXVARIABLESEND   MATRIXVARSTART MATRIXVAREND
%token MATRIXOBJECTIVESSTART  MATRIXOBJECTIVESEND  MATRIXOBJSTART MATRIXOBJEND
%token MATRIXCONSTRAINTSSTART MATRIXCONSTRAINTSEND MATRIXCONSTART MATRIXCONEND

%token CONSTART CONEND CONSTRAINTSSTART CONSTRAINTSEND
%token OBJSTART OBJEND OBJECTIVESSTART  OBJECTIVESEND
%token VARSTART VAREND VARIABLESSTART   VARIABLESEND

%token GENERALSTART GENERALEND SYSTEMSTART SYSTEMEND SERVICESTART SERVICEEND 

%token JOBSTART JOBEND OPTIMIZATIONSTART OPTIMIZATIONEND

%token ATEQUALITYSTART ATEQUALITYEND ATLOWERSTART ATLOWEREND ATUPPERSTART ATUPPEREND
%token BASICSTART BASICEND ISFREESTART ISFREEEND SUPERBASICSTART SUPERBASICEND
%token UNKNOWNSTART UNKNOWNEND

%token SERVICEURISTART SERVICEURIEND SERVICENAMESTART SERVICENAMEEND
%token INSTANCENAMESTART INSTANCENAMEEND JOBIDSTART JOBIDEND

%token OTHERSTART OTHEREND

%token DUMMY

/* $Id$ */
/** @file OSParseosnl.y.tokens
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, the files 
 * OSParseosil.y, OSParseosol.y and OSParseosrl.y are stored in several pieces.
 * These are the tokens pertaining to the OSnL parser.
 * They are appended after the regular OSxL tokens.
 *
 */

%token NONLINEAREXPRESSIONSSTART NONLINEAREXPRESSIONSEND NUMBEROFNONLINEAREXPRESSIONS NLSTART NLEND
%token MATRIXEXPRESSIONSSTART MATRIXEXPRESSIONSEND NUMBEROFEXPR EXPRSTART EXPREND
%token NUMBEROFMATRIXTERMSATT MATRIXTERMSTART MATRIXTERMEND

%token POWERSTART POWEREND PLUSSTART PLUSEND MINUSSTART MINUSEND
%token DIVIDESTART DIVIDEEND LNSTART LNEND SQRTSTART SQRTEND SUMSTART SUMEND PRODUCTSTART PRODUCTEND 
%token EXPSTART EXPEND NEGATESTART NEGATEEND IFSTART IFEND
%token SQUARESTART SQUAREEND COSSTART COSEND SINSTART SINEND
%token VARIABLESTART VARIABLEEND ABSSTART ABSEND ERFSTART ERFEND  MAXSTART MAXEND
%token ALLDIFFSTART ALLDIFFEND MINSTART MINEND ESTART EEND PISTART PIEND
%token TIMESSTART TIMESEND NUMBERSTART NUMBEREND 

%token MATRIXDETERMINANTSTART MATRIXDETERMINANTEND MATRIXTRACESTART MATRIXTRACEEND MATRIXTOSCALARSTART MATRIXTOSCALAREND

%token MATRIXDIAGONALSTART MATRIXDIAGONALEND MATRIXDOTTIMESSTART MATRIXDOTTIMESEND
%token MATRIXLOWERTRIANGLESTART MATRIXLOWERTRIANGLEEND MATRIXUPPERTRIANGLESTART MATRIXUPPERTRIANGLEEND
%token MATRIXMERGESTART MATRIXMERGEEND MATRIXMINUSSTART MATRIXMINUSEND MATRIXNEGATESTART MATRIXNEGATEEND
%token MATRIXPLUSSTART MATRIXPLUSEND MATRIXTIMESSTART MATRIXTIMESEND MATRIXPRODUCTSTART MATRIXPRODUCTEND
%token MATRIXSCALARTIMESSTART MATRIXSCALARTIMESEND MATRIXSUBMATRIXATSTART MATRIXSUBMATRIXATEND
%token MATRIXTRANSPOSESTART MATRIXTRANSPOSEEND MATRIXREFERENCESTART MATRIXREFERENCEEND
%token IDENTITYMATRIXSTART IDENTITYMATRIXEND MATRIXINVERSESTART  MATRIXINVERSEEND

%token EMPTYINCLUDEDIAGONALATT INCLUDEDIAGONALATT

%token EMPTYIDATT IDATT

/* $Id$ */
/** @file OSParseosol.y.2
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the third part of the file OSParseosol.y, containing 
 * the grammar rules involving only OSoL constructs. 
 *
 * See also the comments in OSParseosol.y.1. 
 */

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
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}; 

osolAttributes: | OSOLATTRIBUTETEXT;

osolContent: osolEmpty | osolLaden;

osolEmpty: ENDOFELEMENT;

osolLaden: GREATERTHAN osolBody osolEnd; 
    
osolEnd: osolEnding
    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSoL input is either invalid or not well-formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, osnlData, parserData->parser_errors);
        }
    };

osolEnding: OSOLEND
  | { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");};

osolBody: 
    headerElement generalElement systemElement serviceElement jobElement optimizationElement;

/**
 * ========================================================== 
 * OSoL header 
 * ==========================================================
 */

headerElement: | osglFileHeader
{
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setHeader failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
};

serviceURIContent: serviceURIEmpty | serviceURILaden; 

serviceURIEmpty: GREATERTHAN SERVICEURIEND | ENDOFELEMENT;

serviceURILaden: GREATERTHAN serviceURIBody SERVICEURIEND;

serviceURIBody:  ELEMENTTEXT 
    {
        if (osoption->setServiceURI($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceURI failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    };

serviceNameContent: serviceNameEmpty | serviceNameLaden;

serviceNameEmpty: GREATERTHAN SERVICENAMEEND | ENDOFELEMENT;

serviceNameLaden: GREATERTHAN serviceNameBody SERVICENAMEEND;

serviceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setServiceName($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    };

instanceNameContent: instanceNameEmpty | instanceNameLaden;

instanceNameEmpty: GREATERTHAN INSTANCENAMEEND | ENDOFELEMENT;

instanceNameLaden: GREATERTHAN instanceNameBody INSTANCENAMEEND;

instanceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setInstanceName($1) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceLocation: instanceLocationStart instanceLocationAttributes instanceLocationContent
{
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceLocation failed");
    parserData->errorText = NULL;
};

instanceLocationStart:  INSTANCELOCATIONSTART 
    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    };

instanceLocationAttributes: 
    | locationTypeAttribute
    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "instance location type not recognized");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    };
    
jobIDContent: jobIDEmpty | jobIDLaden;

jobIDEmpty: GREATERTHAN JOBIDEND | ENDOFELEMENT;

jobIDLaden: GREATERTHAN jobIDBody JOBIDEND;

jobIDBody:  ELEMENTTEXT  
    {
        if (osoption->setJobID($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setJobID failed");
        free($1); 
        parserData->errorText = NULL;
    };

/* -------------------------------------------- */
solverToInvoke: solverToInvokeStart solverToInvokeContent;

solverToInvokeStart: SOLVERTOINVOKESTART 
    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    };

solverToInvokeContent: solverToInvokeEmpty | solverToInvokeLaden;

solverToInvokeEmpty: GREATERTHAN SOLVERTOINVOKEEND | ENDOFELEMENT;

solverToInvokeLaden: GREATERTHAN solverToInvokeBody SOLVERTOINVOKEEND;

solverToInvokeBody:  ELEMENTTEXT  
    {
        if (osoption->setSolverToInvoke($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverToInvoke failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
license: licenseStart licenseContent;

licenseStart: LICENSESTART
{
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <license>");
    parserData->licensePresent = true;    
};

licenseContent: licenseEmpty | licenseLaden;

licenseEmpty: GREATERTHAN LICENSEEND | ENDOFELEMENT;

licenseLaden: GREATERTHAN licensebody LICENSEEND;

licensebody: ELEMENTTEXT 
    {
        if (osoption->setLicense($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setLicense failed");
        free($1);
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
username: usernameStart usernameContent;

usernameStart: USERNAMESTART
{    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
};

usernameContent: usernameEmpty | usernameLaden;

usernameEmpty: GREATERTHAN USERNAMEEND | ENDOFELEMENT;

usernameLaden: GREATERTHAN usernamebody USERNAMEEND;

usernamebody: ELEMENTTEXT 
    {
        if (osoption->setUserName($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setUsername failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
password: passwordStart passwordContent;

passwordStart: PASSWORDSTART
{    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
};

passwordContent: passwordEmpty | passwordLaden;

passwordEmpty: GREATERTHAN PASSWORDEND | ENDOFELEMENT;

passwordLaden: GREATERTHAN passwordbody PASSWORDEND;

passwordbody: ELEMENTTEXT 
    {
        if (osoption->setPassword($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setPassword failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
contact: contactStart contactAttributes contactContent
{
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setContact failed");
    parserData->errorText = NULL;
};

contactStart: CONTACTSTART
{
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
};

contactAttributes: 
    | transportTypeAttribute
    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "transport type not recognized");
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
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherGeneralOptionsStart: OTHEROPTIONSSTART
    {
        if (parserData->otherGeneralOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    };

otherGeneralOptionsAttributes: numberOfOtherOptionsAttribute 
    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    };

otherGeneralOptionsContent: 
    otherGeneralOptionsEmpty 
    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }  
  | otherGeneralOptionsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };
    
otherGeneralOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherGeneralOptionsLaden: GREATERTHAN otherGeneralOptionsBody OTHEROPTIONSEND;

otherGeneralOptionsBody:  otherGeneralOptionArray;


/* -------------------------------------------- */
otherGeneralOptionArray:  otherGeneralOption | otherGeneralOptionArray otherGeneralOption; 

otherGeneralOption: otherOptionStart otherOptionAttributes otherOptionEnd 
                    /*otherGeneralOptionStart otherGeneralAttributes otherGeneralEnd*/
    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(osglData->name, osglData->value, 
                                                  osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "setOtherGeneralOption failed");
    };    

otherOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherOptionAttributes: otherOptionAttList
{
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};    

otherOptionAttList: | otherOptionAttList otherOptionAtt;

otherOptionAtt:
    osglNameATT
    {    if (osglData->name.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | osglValueATT
  | osglDescriptionATT
  ;

otherOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;

/*
otherGeneralOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherGeneralAttributes: otherGeneralAttList
{
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};    

otherGeneralAttList: | otherGeneralAttList otherGeneralAtt;

otherGeneralAtt:
    osglNameATT
    {    if (osglData->name.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | osglValueATT
  | osglDescriptionATT
  ;

otherGeneralEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;
*/


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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "byte";    
        osglData->description = "";
    };

minDiskSpaceAttributes: minDiskSpaceAttList;

minDiskSpaceAttList: | minDiskSpaceAttList minDiskSpaceAtt;

minDiskSpaceAtt:
    osglUnitATT
  | osglDescriptionATT
  ;
  
minDiskSpaceContent: GREATERTHAN minDiskSpaceValue MINDISKSPACEEND;

minDiskSpaceValue: aNumber
{
    if (osoption->setMinDiskSpace(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
};

/* -------------------------------------------- */
minMemorySize: minMemoryStart minMemoryAttributes minMemoryContent;

minMemoryStart: MINMEMORYSTART
    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "byte";    
        osglData->description = "";
    };

minMemoryAttributes: minMemoryAttList;

minMemoryAttList: | minMemoryAttList minMemoryAtt;

minMemoryAtt: 
    osglUnitATT
  | osglDescriptionATT
  ;

minMemoryContent: GREATERTHAN minMemoryValue MINMEMORYEND;

minMemoryValue: aNumber
{
    if (osoption->setMinMemorySize(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinMemorySize failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUSpeed: minCPUSpeedStart minCPUSpeedAttributes minCPUSpeedContent;

minCPUSpeedStart: MINCPUSPEEDSTART
    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "hertz";    
        osglData->description = "";
    };

minCPUSpeedAttributes: minCPUSpeedAttList;

minCPUSpeedAttList: | minCPUSpeedAttList minCPUSpeedAtt;

minCPUSpeedAtt: 
    osglUnitATT
  | osglDescriptionATT
  ;

minCPUSpeedContent: GREATERTHAN minCPUSpeedValue MINCPUSPEEDEND;

minCPUSpeedValue: aNumber
{    
    if (osoption->setMinCPUSpeed(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUNumber: minCPUNumberStart minCPUNumberAttributes minCPUNumberContent;

minCPUNumberStart: MINCPUNUMBERSTART
{    
    if (parserData->minCPUNumberPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "only one minCPUNumber element allowed");
    parserData->minCPUNumberPresent = true;
    osglData->descriptionPresent = false;    
    osglData->description = "";    
};

minCPUNumberAttributes: 
  | osglDescriptionATT;

minCPUNumberContent: GREATERTHAN minCPUNumberValue MINCPUNUMBEREND;

minCPUNumberValue: INTEGER 
{
    if (osoption->setMinCPUNumber($1, osglData->description) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "setMinCPUNumber failed");
    parserData->errorText = NULL; 
};



/* -------------------------------------------- */
otherSystemOptions: otherSystemOptionsStart otherSystemOptionsAttributes otherSystemOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherSystemOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherSystemOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
};

otherSystemOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherSystemOptionsContent: 
    otherSystemOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherSystemOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherSystemOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherSystemOptionsLaden: GREATERTHAN otherSystemOptionsBody OTHEROPTIONSEND;

otherSystemOptionsBody:  otherSystemOptionArray;


/* -------------------------------------------- */
otherSystemOptionArray:  otherSystemOption | otherSystemOptionArray otherSystemOption; 

otherSystemOption: otherOptionStart otherOptionAttributes otherOptionEnd 
                    /*otherSystemOptionStart otherSystemOptionAttributes otherSystemOptionEnd*/
    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherSystemOption failed");
    };

/*
otherSystemOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherSystemOptionAttList: | otherSystemOptionAttList otherSystemOptionAtt;

otherSystemOptionAtt:
    nameAttribute
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute
  | descriptionAttribute
  ;

otherSystemOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;
*/


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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one currentState element allowed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
otherServiceOptions: otherServiceOptionsStart otherServiceOptionsAttributes otherServiceOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherServiceOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
};

otherServiceOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherServiceOptionsContent: 
    otherServiceOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherServiceOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherServiceOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherServiceOptionsLaden: GREATERTHAN otherServiceOptionsBody OTHEROPTIONSEND

otherServiceOptionsBody:  otherServiceOptionArray;


/* -------------------------------------------- */
otherServiceOptionArray: otherServiceOption | otherServiceOptionArray otherServiceOption; 

otherServiceOption: otherOptionStart otherOptionAttributes otherOptionEnd 
/*otherServiceOptionStart otherServiceOptionAttributes otherServiceOptionEnd*/
    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherServiceOption failed");
    };
/*
otherServiceOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherServiceOptionAttList: | otherServiceOptionAttList otherServiceOptionAtt;

otherServiceOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;
  
otherServiceOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;
*/

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
    if (osoption->setMaxTime(parserData->maxTimeValue, osglData->unit) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "max time request could not be honored");
}; 

maxTimeStart: MAXTIMESTART
{    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <maxTime> element allowed");
    osglData->unitPresent = false;    
    osglData->unit = "second"; 
    parserData->maxTimePresent = true;
    parserData->maxTimeValue = OSDBL_MAX;
};

maxTimeAttributes: |
           osglUnitATT

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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    };

requestedStartTimeContent: requestedStartTimeEmpty | requestedStartTimeLaden;

requestedStartTimeEmpty: GREATERTHAN REQUESTEDSTARTTIMEEND | ENDOFELEMENT;

requestedStartTimeLaden: GREATERTHAN requestedStartTimeBody REQUESTEDSTARTTIMEEND;

requestedStartTimeBody:  ELEMENTTEXT  
    {
        if (osoption->setRequestedStartTime($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setRequestedStartTime failed");    
        free($1); 
        parserData->errorText = NULL;
        };


/* -------------------------------------------- */
dependencies: dependenciesStart dependenciesAttributes dependenciesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

dependenciesStart: DEPENDENCIESSTART
{
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

dependenciesList: dependencyJobID | dependenciesList dependencyJobID;

dependencyJobID: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many job IDs in <dependencies> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

requiredDirectoriesStart: REQUIREDDIRECTORIESSTART
{
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
};

requiredDirectoriesContent: requiredDirectoriesEmpty | requiredDirectoriesLaden;

requiredDirectoriesEmpty: GREATERTHAN REQUIREDDIRECTORIESEND | ENDOFELEMENT;

requiredDirectoriesLaden: GREATERTHAN PathList REQUIREDDIRECTORIESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
requiredFiles: requiredFilesStart numberOfPathsAttribute requiredFilesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

requiredFilesStart: REQUIREDFILESSTART
{
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
};

requiredFilesContent: requiredFilesEmpty | requiredFilesLaden;

requiredFilesEmpty: GREATERTHAN REQUIREDFILESEND | ENDOFELEMENT;

requiredFilesLaden: GREATERTHAN PathList REQUIREDFILESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToMake: directoriesToMakeStart numberOfPathsAttribute directoriesToMakeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

directoriesToMakeStart: DIRECTORIESTOMAKESTART
{
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
};

directoriesToMakeContent: directoriesToMakeEmpty | directoriesToMakeLaden;

directoriesToMakeEmpty: GREATERTHAN DIRECTORIESTOMAKEEND | ENDOFELEMENT;

directoriesToMakeLaden: GREATERTHAN PathList DIRECTORIESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
filesToMake: filesToMakeStart numberOfPathsAttribute filesToMakeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

filesToMakeStart: FILESTOMAKESTART
{
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
};

filesToMakeContent: filesToMakeEmpty | filesToMakeLaden;

filesToMakeEmpty: GREATERTHAN FILESTOMAKEEND | ENDOFELEMENT;

filesToMakeLaden: GREATERTHAN PathList FILESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
inputDirectoriesToMove: inputDirectoriesToMoveStart inputDirectoriesToMoveAttributes inputDirectoriesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
};

inputDirectoriesToMoveStart: INPUTDIRECTORIESTOMOVESTART
{
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

inputDirectoriesToMoveList: inputDirectoryToMove | inputDirectoriesToMoveList inputDirectoryToMove;

inputDirectoryToMove: PathPair;


/* -------------------------------------------- */
inputFilesToMove: inputFilesToMoveStart inputFilesToMoveAttributes inputFilesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

inputFilesToMoveStart: INPUTFILESTOMOVESTART
{
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

inputFilesToMoveList: inputFileToMove | inputFilesToMoveList inputFileToMove;

inputFileToMove: PathPair;


/* -------------------------------------------- */
outputFilesToMove: outputFilesToMoveStart outputFilesToMoveAttributes outputFilesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

outputFilesToMoveStart: OUTPUTFILESTOMOVESTART
{
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

outputFilesToMoveList: outputFileToMove | outputFilesToMoveList outputFileToMove;

outputFileToMove: PathPair;


/* -------------------------------------------- */
outputDirectoriesToMove: outputDirectoriesToMoveStart outputDirectoriesToMoveAttributes outputDirectoriesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

outputDirectoriesToMoveStart: OUTPUTDIRECTORIESTOMOVESTART
{
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

outputDirectoriesToMoveList: outputDirectoryToMove | outputDirectoriesToMoveList outputDirectoryToMove;

outputDirectoryToMove: PathPair;


/* -------------------------------------------- */
filesToDelete: filesToDeleteStart filesToDeleteAttributes filesToDeleteContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

filesToDeleteStart: FILESTODELETESTART
{
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToDelete: directoriesToDeleteStart directoriesToDeleteAttributes directoriesToDeleteContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

directoriesToDeleteStart: DIRECTORIESTODELETESTART
{
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

/*
directoriesToDeleteList: directoryToDelete | directoriesToDeleteList directoryToDelete;

directoryToDelete: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
    if (parserData->kounter >= parserData->numberOf)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <directoriesToDelete> element");
    else
    {
        parserData->paths[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};
*/

/* -------------------------------------------- */
processesToKill: processesToKillStart processesToKillAttributes processesToKillContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

processesToKillStart: PROCESSESTOKILLSTART
{
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

processesToKillList: processID | processesToKillList processID;

processID: PROCESSSTART GREATERTHAN ELEMENTTEXT PROCESSEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many process IDs in <processesToKill> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherJobOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
};

otherJobOptionsAttributes: numberOfOtherOptionsAttribute 
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherJobOptionsContent: 
    otherJobOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherJobOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherJobOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherJobOptionsLaden: GREATERTHAN otherJobOptionsBody OTHEROPTIONSEND;

otherJobOptionsBody:   otherJobOptionArray;


/* -------------------------------------------- */
otherJobOptionArray: otherJobOption | otherJobOptionArray otherJobOption; 

otherJobOption: otherOptionStart otherOptionAttributes otherOptionEnd 
            /*otherJobOptionStart otherJobOptionAttributes otherJobOptionEnd*/
    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherJobOption failed");
    };    
/*
otherJobOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};

otherJobOptionAttList: | otherJobOptionAttList otherJobOptionAtt;

otherJobOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;

otherJobOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;
*/

/**
 * ========================================================== 
 * <optimization> element 
 * ==========================================================
 */
optimizationElement: | optimizationStart optimizationAttributes optimizationContent;

optimizationStart: OPTIMIZATIONSTART
{
    osoption->optimization = new OptimizationOption();
    osglData->numberOfVariablesPresent = false;
    osglData->numberOfObjectivesPresent = false;
    osglData->numberOfConstraintsPresent = false;
};

optimizationAttributes: optimizationAttList

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
    osglNumberOfVariablesATT
    {    
//        osglData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(osglData->numberOfVariables) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfVariables failed");
    }             
  |  osglNumberOfConstraintsATT
    {
//        osglData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(osglData->numberOfConstraints) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfConstraints failed");
    } 
  | osglNumberOfObjectivesATT
    {    
//        osglData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(osglData->numberOfObjectives) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfObjectives failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
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
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialVariableValues: | initialVariableValuesStart initialVariableValuesAttributes initialVariableValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(osglData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

initialVariableValuesStart: INITIALVARIABLEVALUESSTART
{
    osglData->numberOfVarPresent = false;
};

initialVariableValuesAttributes: osglNumberOfVarATT
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfVar];
    parserData->namArray = new std::string[osglData->numberOfVar];
    parserData->valArray = new      double[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

initialVariableValuesContent: 
    initialVariableValuesEmpty 
    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesLaden
    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
};

initVarValueAttributes: initVarValueAttList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

initVarValueAttList: | initVarValueAttList initVarValueAtt;

initVarValueAtt: 
    osglIdxATT
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
  | osglValueATT
    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    };

initVarValueContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
initialVariableValuesString: | initialVariableValuesStringStart initialVariableValuesStringAttributes initialVariableValuesStringContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(osglData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

initialVariableValuesStringStart: INITIALVARIABLEVALUESSTRINGSTART
{
    osglData->numberOfVarPresent = false;
};

initialVariableValuesStringAttributes: osglNumberOfVarATT
{
    parserData->kounter = 0;
    parserData->idxArray    = new         int[osglData->numberOfVar];
    parserData->namArray    = new std::string[osglData->numberOfVar];
    parserData->valueString = new std::string[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valueString[i] = "";
}; 

initialVariableValuesStringContent: 
    initialVariableValuesStringEmpty 
    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesStringLaden
    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
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
    osglData->value = ""; //Make sure to remove random string
}; 

initVarValueStringStart: VARSTART
{    
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->value = "48r 87e WY EUV e7 df"; //random string...
};

initVarValueStringAttributes: initVarValueStringAttList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

initVarValueStringAttList: | initVarValueStringAttList initVarValueStringAtt;

initVarValueStringAtt:
    osglIdxATT
    {
        if (osglData->idx< 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
  | osglValueATT
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = osglData->value;
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
variablesBasic: | osglBasisStatusBasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

/*
variablesBasicStart variablesBasicNumberOfElATT variablesBasicContent

variablesBasicStart: BASICSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesBasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesBasicContent: variablesBasicEmpty | variablesBasicLaden;

variablesBasicEmpty: ENDOFELEMENT;

variablesBasicLaden: GREATERTHAN variablesBasicBody BASICEND;

variablesBasicBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesAtLower: | osglBasisStatusAtLower
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

/*
variablesAtLowerStart: ATLOWERSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtLowerContent: variablesAtLowerEmpty | variablesAtLowerLaden;

variablesAtLowerEmpty: ENDOFELEMENT;

variablesAtLowerLaden: GREATERTHAN variablesAtLowerBody ATLOWEREND;

variablesAtLowerBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesAtUpper: | osglBasisStatusAtUpper
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
variablesAtUpperStart: ATUPPERSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtUpperContent: variablesAtUpperEmpty | variablesAtUpperLaden;

variablesAtUpperEmpty: ENDOFELEMENT;

variablesAtUpperLaden: GREATERTHAN variablesAtUpperBody ATUPPEREND;

variablesAtUpperBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesAtEquality: | osglBasisStatusAtEquality
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
variablesAtEqualityStart: ATEQUALITYSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtEqualityContent: variablesAtEqualityEmpty | variablesAtEqualityLaden;

variablesAtEqualityEmpty: ENDOFELEMENT;

variablesAtEqualityLaden: GREATERTHAN variablesAtEqualityBody ATEQUALITYEND;

variablesAtEqualityBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesIsFree: | osglBasisStatusIsFree
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
variablesIsFreeStart: ISFREESTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesIsFreeContent: variablesIsFreeEmpty | variablesIsFreeLaden;

variablesIsFreeEmpty: ENDOFELEMENT;

variablesIsFreeLaden: GREATERTHAN variablesIsFreeBody ISFREEEND;

variablesIsFreeBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesSuperbasic: | osglBasisStatusSuperbasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
variablesSuperbasicStart: SUPERBASICSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

variablesSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesSuperbasicContent: variablesSuperbasicEmpty | variablesSuperbasicLaden;

variablesSuperbasicEmpty: ENDOFELEMENT;

variablesSuperbasicLaden: GREATERTHAN variablesSuperbasicBody SUPERBASICEND;

variablesSuperbasicBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
variablesUnknown: | osglBasisStatusUnknown
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
variablesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesUnknownContent: variablesUnknownEmpty | variablesUnknownLaden;

variablesUnknownEmpty: ENDOFELEMENT;

variablesUnknownLaden: GREATERTHAN variablesUnknownBody UNKNOWNEND;

variablesUnknownBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
integerVariableBranchingWeights: | integerVariableBranchingWeightsStart
    integerVariableBranchingWeightsAttributes integerVariableBranchingWeightsContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(osglData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <IntegerVariableBranchingWeights> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

integerVariableBranchingWeightsStart: INTEGERVARIABLEBRANCHINGWEIGHTSSTART
{
    osglData->numberOfVarPresent = false;
};

integerVariableBranchingWeightsAttributes: osglNumberOfVarATT
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfVar];
    parserData->namArray = new std::string[osglData->numberOfVar];
    parserData->valArray = new      double[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

integerVariableBranchingWeightsContent:
    integerVariableBranchingWeightsEmpty
    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | integerVariableBranchingWeightsLaden
    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";
    osglData->valuePresent = false;
    osglData->value = "1.0";
};

branchingWeightAttributes: branchingWeightAttList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

branchingWeightAttList: | branchingWeightAttList branchingWeightAtt;

branchingWeightAtt: 
    osglIdxATT 
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
  | osglValueATT
    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    };

branchingWeightContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
sosVariableBranchingWeights: | sosVariableBranchingWeightsStart sosVariableBranchingWeightsAttributes sosVariableBranchingWeightsContent
{
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

sosVariableBranchingWeightsStart: SOSVARIABLEBRANCHINGWEIGHTSSTART
{
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}; 

sosVariableBranchingWeightsAttributes: NUMBEROFSOSATT QUOTE INTEGER QUOTE   
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = $3;
};

sosVariableBranchingWeightsContent:
    sosVariableBranchingWeightsEmpty
    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | sosVariableBranchingWeightsLaden
    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

sosVariableBranchingWeightsEmpty: GREATERTHAN SOSVARIABLEBRANCHINGWEIGHTSEND | ENDOFELEMENT;

sosVariableBranchingWeightsLaden: GREATERTHAN sosWeightGroupArray SOSVARIABLEBRANCHINGWEIGHTSEND;

sosWeightGroupArray: sosWeightGroup | sosWeightGroupArray sosWeightGroup;

sosWeightGroup: sosWeightGroupStart sosWeightGroupAttributes sosWeightGroupContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    osglData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray, parserData->valArray, parserData->namArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


sosWeightGroupStart: SOSSTART
{
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many SOS branching weights");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
    osglData->numberOfVarPresent = false;
};

sosWeightGroupAttributes: sosWeightGroupAttList
{
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index required");
    if (!osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar required");
};

sosWeightGroupAttList: | sosWeightGroupAttList sosWeightGroupAtt; 

sosWeightGroupAtt: 
    sosIdxAttribute;
  | osglNumberOfVarATT
    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[osglData->numberOfVar];
        parserData->namArray = new std::string[osglData->numberOfVar];
        parserData->valArray = new      double[osglData->numberOfVar];
        for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        osglData->numberOfVarPresent = true;
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
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfVarPresent = false;
    osglData->numberOfVar = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->varTypePresent = false;    
    osglData->varType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}; 

otherVariableOptionAttributes: otherVariableOptionAttList 
    {
        if (!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfVar,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->varType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };
      
otherVariableOptionAttList: | otherVariableOptionAttList otherVariableOptionATT;

otherVariableOptionATT: 
    osglNumberOfVarATT 
    {
        parserData->kounter = 0;
    }  
  | osglNumberOfEnumerationsATT
    {
        parserData->kounter = 0;
    }  
  | osglNameATT 
  | osglValueATT
  | osglSolverATT
  | osglCategoryATT
  | osglTypeATT
  | osglVarTypeATT
  | osglEnumTypeATT
  | osglDescriptionATT
  ;
  
otherVariableOptionContent: otherVariableOptionEmpty | otherVariableOptionLaden;

otherVariableOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableOptionLaden: GREATERTHAN otherVariableOptionBody OTHEREND;

otherVariableOptionBody:  otherVarList | otherEnumerationList;

otherVarList: otherVar | otherVarList otherVar;

/* -------------------------------------------- */
otherVar: otherVarStart otherVarAttributes otherVarContent 
{     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other variable option <var> element failed");
    parserData->kounter++;
};

otherVarStart: VARSTART
{
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherVarAttributes: otherVarAttList;

otherVarAttList: | otherVarAttList otherVarAtt;

otherVarAtt:
    osglIdxATT
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
    }
  | osglNameATT
  | osglValueATT
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
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
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialObjectiveValues: | initialObjectiveValuesStart initialObjectiveValuesAttributes initialObjectiveValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(osglData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialObjectiveValuesStart: INITIALOBJECTIVEVALUESSTART
{
    osglData->numberOfObjPresent = false;
};


initialObjectiveValuesAttributes: osglNumberOfObjATT
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfObj];
    parserData->namArray = new std::string[osglData->numberOfObj];
    parserData->valArray = new      double[osglData->numberOfObj];
    for (int i=0; i < osglData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < osglData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}; 

initialObjectiveValuesContent: 
    initialObjectiveValuesEmpty 
    {    
        if (osglData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveValuesLaden
    {
        if (parserData->kounter < osglData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->idx = -1;
};

initObjValueAttributes: initObjValueAttList;

initObjValueAttList: | initObjValueAttList initObjValueAtt;

initObjValueAtt: 
    osglIdxATT
    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
  | osglValueATT
    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    };

initObjValueContent: GREATERTHAN OBJEND | ENDOFELEMENT;

/* -------------------------------------------- */
initialObjectiveBounds: | initialObjectiveBoundsStart numberOfObjATT initialObjectiveBoundsContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(osglData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialObjectiveBoundsStart: INITIALOBJECTIVEBOUNDSSTART
{
    osglData->numberOfObjPresent = false;
};

numberOfObjATT: osglNumberOfObjATT
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[osglData->numberOfObj];
    parserData->lbValArray = new      double[osglData->numberOfObj];
    parserData->ubValArray = new      double[osglData->numberOfObj];
    parserData->namArray   = new std::string[osglData->numberOfObj];
    for (int i=0; i < osglData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < osglData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < osglData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialObjectiveBoundsContent: 
    initialObjectiveBoundsEmpty 
    {
        if (osglData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveBoundsLaden
    {
        if (parserData->kounter < osglData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idx = -1;
    osglData->idxPresent = false;
    osglData->namePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
};

initObjBoundAttributes: initObjBoundAttList;

initObjBoundAttList: | initObjBoundAttList initObjBoundAtt;

initObjBoundAtt: 
    osglIdxATT
    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
  | lbValueAttribute
    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
  | ubValueAttribute
    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
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
objectivesBasic: | osglBasisStatusBasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesBasicStart: BASICSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

objectivesBasicNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesBasicContent: objectivesBasicEmpty | objectivesBasicLaden;

objectivesBasicEmpty: ENDOFELEMENT;

objectivesBasicLaden: GREATERTHAN objectivesBasicBody BASICEND;

objectivesBasicBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
objectivesAtLower: | osglBasisStatusAtLower
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesAtLowerStart: ATLOWERSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent= false;
};

objectivesAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->counter = 0; 
    osglData->numberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtLowerContent: objectivesAtLowerEmpty | objectivesAtLowerLaden;

objectivesAtLowerEmpty: ENDOFELEMENT;

objectivesAtLowerLaden: GREATERTHAN objectivesAtLowerBody ATLOWEREND;

objectivesAtLowerBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
objectivesAtUpper: | osglBasisStatusAtUpper
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtUpperContent: objectivesAtUpperEmpty | objectivesAtUpperLaden;

objectivesAtUpperEmpty: ENDOFELEMENT;

objectivesAtUpperLaden: GREATERTHAN objectivesAtUpperBody ATUPPEREND;

objectivesAtUpperBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
objectivesAtEquality: | osglBasisStatusAtEquality
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtEqualityContent: objectivesAtEqualityEmpty | objectivesAtEqualityLaden;

objectivesAtEqualityEmpty: ENDOFELEMENT;

objectivesAtEqualityLaden: GREATERTHAN objectivesAtEqualityBody ATEQUALITYEND;

objectivesAtEqualityBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
objectivesIsFree: | osglBasisStatusIsFree
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesIsFreeContent: objectivesIsFreeEmpty | objectivesIsFreeLaden;

objectivesIsFreeEmpty: ENDOFELEMENT;

objectivesIsFreeLaden: GREATERTHAN objectivesIsFreeBody ISFREEEND;

objectivesIsFreeBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
objectivesSuperbasic: | osglBasisStatusSuperbasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};


objectivesSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesSuperbasicContent: objectivesSuperbasicEmpty | objectivesSuperbasicLaden;

objectivesSuperbasicEmpty: ENDOFELEMENT;

objectivesSuperbasicLaden: GREATERTHAN objectivesSuperbasicBody SUPERBASICEND;

objectivesSuperbasicBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
objectivesUnknown: | osglBasisStatusUnknown
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
objectivesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesUnknownContent: objectivesUnknownEmpty | objectivesUnknownLaden;

objectivesUnknownEmpty: ENDOFELEMENT;

objectivesUnknownLaden: GREATERTHAN objectivesUnknownBody UNKNOWNEND;

objectivesUnknownBody:  osglIntArrayData;
*/

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
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfObjPresent = false;    
    osglData->numberOfObj = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->objTypePresent = false;    
    osglData->objType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}; 

otherObjectiveOptionAttributes: otherObjectiveOptionAttList
    {
        if (!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfObj,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->objType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };


otherObjectiveOptionAttList: | otherObjectiveOptionAttList otherObjectiveOptionATT;

otherObjectiveOptionATT: 
    osglNumberOfObjATT 
    {
        parserData->kounter = 0;
    }
  | osglNumberOfEnumerationsATT
    {
        parserData->kounter = 0;
    }
  | osglNameATT
  | osglValueATT
  | osglSolverATT
  | osglCategoryATT
  | osglTypeATT
  | osglObjTypeATT
  | osglEnumTypeATT
  | osglDescriptionATT
  ;
    
otherObjectiveOptionContent: otherObjectiveOptionEmpty | otherObjectiveOptionLaden;

otherObjectiveOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherObjectiveOptionLaden: GREATERTHAN otherObjectiveOptionBody OTHEREND;

otherObjectiveOptionBody:  otherObjList | otherEnumerationList;

otherObjList: otherObj | otherObjList otherObj;

/* -------------------------------------------- */
otherObj: otherObjStart otherObjAttributes  otherObjContent 
{  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other objective option <obj> element failed");
    parserData->kounter++;
};

otherObjStart: OBJSTART
{

    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->idx = -1;
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherObjAttributes: otherObjAttList;

otherObjAttList: | otherObjAttList otherObjAtt;

otherObjAtt:
    osglIdxATT
    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
    }
  | osglNameATT
  | osglValueATT
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherConstraintOptions failed");
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
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialConstraintValues: | initialConstraintValuesStart initialConstraintValuesAttributes initialConstraintValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(osglData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialConstraintValuesStart:  INITIALCONSTRAINTVALUESSTART
{
    osglData->numberOfConPresent = false;
};

initialConstraintValuesAttributes: osglNumberOfConATT
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfCon];
    parserData->namArray = new std::string[osglData->numberOfCon];
    parserData->valArray = new      double[osglData->numberOfCon];
    for (int i=0; i < osglData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}; 

initialConstraintValuesContent:
    initialConstraintValuesEmpty 
    {
        if (osglData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialConstraintValuesLaden
    {
        if (parserData->kounter < osglData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->name = "";
    osglData->namePresent = false;
    osglData->valuePresent = false;
};

initConValueAttributes: initConValueAttList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "<con> element must have idx attribute");
};

initConValueAttList: | initConValueAttList initConValueAtt;

initConValueAtt: 
    osglIdxATT
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
  | osglValueATT
    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    };

initConValueContent: GREATERTHAN CONEND | ENDOFELEMENT;


/* -------------------------------------------- */
initialDualValues: | initialDualValuesStart initialDualValuesAttributes initialDualValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(osglData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialDualValuesStart: INITIALDUALVALUESSTART
{
    osglData->numberOfConPresent = false;
};

initialDualValuesAttributes: osglNumberOfConATT
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[osglData->numberOfCon];
    parserData->namArray   = new std::string[osglData->numberOfCon];
    parserData->lbValArray = new      double[osglData->numberOfCon];
    parserData->ubValArray = new      double[osglData->numberOfCon];
    for (int i=0; i < osglData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < osglData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialDualValuesContent: 
    initialDualValuesEmpty 
    {
        if (osglData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialDualValuesLaden
    {
        if (parserData->kounter < osglData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
};

initDualValueAttributes: initDualValueAttList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "<con> element must have idx attribute");
};

initDualValueAttList: | initDualValueAttList initDualValueAtt;

initDualValueAtt: 
    osglIdxATT
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
  | osglNameATT
    {
        parserData->namArray[parserData->kounter] = osglData->name;
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
slacksBasic: | osglBasisStatusBasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksBasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksBasicContent: slacksBasicEmpty | slacksBasicLaden;

slacksBasicEmpty: ENDOFELEMENT;

slacksBasicLaden: GREATERTHAN slacksBasicBody BASICEND;

slacksBasicBody:  osglIntArrayData;
*/
/* -------------------------------------------- */
slacksAtLower: | osglBasisStatusAtLower
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtLowerContent: slacksAtLowerEmpty | slacksAtLowerLaden;

slacksAtLowerEmpty: ENDOFELEMENT;

slacksAtLowerLaden: GREATERTHAN slacksAtLowerBody ATLOWEREND;

slacksAtLowerBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
slacksAtUpper: | osglBasisStatusAtUpper
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*

slacksAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtUpperContent: slacksAtUpperEmpty | slacksAtUpperLaden;

slacksAtUpperEmpty: ENDOFELEMENT;

slacksAtUpperLaden: GREATERTHAN slacksAtUpperBody ATUPPEREND;

slacksAtUpperBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
slacksAtEquality: | osglBasisStatusAtEquality
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtEqualityContent: slacksAtEqualityEmpty | slacksAtEqualityLaden;

slacksAtEqualityEmpty: ENDOFELEMENT;

slacksAtEqualityLaden: GREATERTHAN slacksAtEqualityBody ATEQUALITYEND;

slacksAtEqualityBody:  osglIntArrayData;

*/
/* -------------------------------------------- */
slacksIsFree: | osglBasisStatusIsFree
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksIsFreeContent: slacksIsFreeEmpty | slacksIsFreeLaden;

slacksIsFreeEmpty: ENDOFELEMENT;

slacksIsFreeLaden: GREATERTHAN slacksIsFreeBody ISFREEEND;

slacksIsFreeBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
slacksSuperbasic: | osglBasisStatusSuperbasic
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksSuperbasicContent: slacksSuperbasicEmpty | slacksSuperbasicLaden;

slacksSuperbasicEmpty: ENDOFELEMENT;

slacksSuperbasicLaden: GREATERTHAN slacksSuperbasicBody SUPERBASICEND;

slacksSuperbasicBody:  osglIntArrayData;
*/

/* -------------------------------------------- */
slacksUnknown: | osglBasisStatusUnknown
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};
/*
slacksUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksUnknownContent: slacksUnknownEmpty | slacksUnknownLaden;

slacksUnknownEmpty: ENDOFELEMENT;

slacksUnknownLaden: GREATERTHAN slacksUnknownBody UNKNOWNEND;

slacksUnknownBody:  osglIntArrayData;
*/

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
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfConPresent = false;    
    osglData->numberOfCon = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->conTypePresent = false;    
    osglData->conType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}; 

otherConstraintOptionAttributes: otherConstraintOptionAttList
    {
        if(!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfCon,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->conType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };

otherConstraintOptionAttList: | otherConstraintOptionAttList otherConstraintOptionATT;

otherConstraintOptionATT: 
    osglNumberOfConATT
    {
        parserData->kounter = 0;
    } 
  | osglNumberOfEnumerationsATT
    {
        parserData->kounter = 0;
    }  
  | osglNameATT
  | osglValueATT
  | osglSolverATT
  | osglCategoryATT
  | osglTypeATT
  | osglConTypeATT
  | osglEnumTypeATT
  | osglDescriptionATT
  ;
  
otherConstraintOptionContent: otherConstraintOptionEmpty | otherConstraintOptionLaden;

otherConstraintOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT    

otherConstraintOptionLaden: GREATERTHAN otherConstraintOptionBody OTHEREND;

otherConstraintOptionBody:  otherConList | otherEnumerationList;

otherConList: otherCon | otherConList otherCon;

/* -------------------------------------------- */
otherCon: otherConStart otherConAttributes  otherConContent 
{     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other constraint option <con> element failed");
    parserData->kounter++;
};
  
otherConStart: CONSTART
{
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherConAttributes: otherConAttList;

otherConAttList: | otherConAttList otherConAtt;

otherConAtt:
    osglIdxATT
    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "constraint index exceeds upper limit");
        };
    }
  | osglNameATT
  | osglValueATT
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
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

solverOptionsStart: SOLVEROPTIONSSTART;

numberOfSolverOptionsATT: numberOfSolverOptionsAttribute
{
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}; 

solverOptionsContent:
    solverOptionsEmpty
    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | solverOptionsLaden
    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

solverOptionsEmpty: ENDOFELEMENT;

solverOptionsLaden: GREATERTHAN solverOptionArray SOLVEROPTIONSEND;

solverOptionArray: | solverOptionArray solverOption;


/* -------------------------------------------- */
solverOption: solverOptionStart solverOptionAttributes solverOptionContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    osglData->numberOfItems,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->description,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (osglData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
};

solverOptionStart: SOLVEROPTIONSTART
{
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->solverPresent = false;
    osglData->categoryPresent = false;
    osglData->typePresent = false;
    osglData->descriptionPresent = false;
    osglData->numberOfItemsPresent = false;
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->type = "";
    osglData->description = "";
    osglData->numberOfItems = 0;
    parserData->kounter = 0;
};

solverOptionAttributes: solverOptionAttList
{
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
};

solverOptionAttList: solverOptionATT | solverOptionAttList solverOptionATT;

solverOptionATT:
    osglNameATT
  | osglValueATT
  | osglSolverATT
  | osglCategoryATT
  | osglTypeATT
  | osglDescriptionATT
  | osglNumberOfItemsATT
    {
            parserData->itemList = new std::string[osglData->numberOfItems];
    }
  ;

solverOptionContent:
    solverOptionEmpty
    {
        if (osglData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
 | solverOptionLaden
    {
        if (parserData->kounter < osglData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
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
        if (parserData->kounter >= osglData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }    
  | solverOptionItemLaden; 

solverOptionItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOptionItemLaden: ITEMSTART solverOptionItemBody ITEMEND;

solverOptionItemBody:  ITEMTEXT 
{
    if (parserData->kounter >= osglData->numberOfItems)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <requiredDirectories> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
};

PathPairStart: PATHPAIRSTART
{
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = $2;
    free($2);
};

PathPairToATT: TOATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = $2;
    free($2);
};

PathPairMakeCopyATT: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp($2,"true") == 0);
    free($2);
};

PathPairEnd: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


/*********************************************************************************
 *  Here we collect the rules for some attributes that are used repeatedly       *
 *  (These are in addition to ruls for shared attributes found in OSParseOSgL.)  *
 *********************************************************************************/
/*categoryAttribute: categoryAtt
{   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one category attribute allowed for this element");
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
*/
/* ----------------------------------------------------------------------- 
conTypeAttribute: conTypeAtt
        {   if (parserData->conTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
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

 ----------------------------------------------------------------------- 
descriptionAttribute: descriptionAtt
{
    if (parserData->descriptionAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one description attribute allowed for this element");
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

 ----------------------------------------------------------------------- 
enumTypeAttribute: enumTypeAtt
        {   if (parserData->enumTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
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
*/

/* ----------------------------------------------------------------------- */
groupWeightAttribute: groupWeightAtt
{
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
};

groupWeightAtt: GROUPWEIGHTATT QUOTE aNumber QUOTE
{
    parserData->groupWeight = parserData->tempVal;
};


/* ----------------------------------------------------------------------- */
/*idxAttribute: idxAtt
{   
    if (parserData->idxAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
};

idxAtt: idxAttContent;

idxAttContent: IDXATT quote INTEGER quote 
{ 
    parserData->idxAttribute = $3;
};
*/
/* ----------------------------------------------------------------------- */
lbValueAttribute: lbValueAtt
{   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
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
/*nameAttribute: nameAtt
    {
        if (parserData->nameAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one name attribute allowed for this element");
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

 ----------------------------------------------------------------------- 
objTypeAttribute: objTypeAtt
        {   if (parserData->objTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
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


 ----------------------------------------------------------------------- 
solverAttribute: solverAtt
    {   if (parserData->solverAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one solver attribute allowed for this element");
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
*/
/* ----------------------------------------------------------------------- */
sosIdxAttribute: sosIdxAtt
    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    };

sosIdxAtt: sosIdxAttContent;

sosIdxAttContent: SOSIDXATT quote INTEGER quote 
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = $3;
};

/* ----------------------------------------------------------------------- */
/*typeAttribute: typeAtt
        {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one type attribute allowed for this element");
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
*/
/* ----------------------------------------------------------------------- */
ubValueAttribute: ubValueAtt
{
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
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
/*unitAttribute: unitAtt
        {   if (parserData->unitAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
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

 ----------------------------------------------------------------------- 
valueAttribute: valueAtt
        {   if (parserData->valueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one value attribute allowed for this element");
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

 ----------------------------------------------------------------------- 
varTypeAttribute: varTypeAtt
        {   if (parserData->varTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
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
*/



/*************************************************************************************
 *  There are so many numberOf... attributes that they warrant their own section...  *
 *************************************************************************************/
/*
numberOfConAttribute: NUMBEROFCONATT quote INTEGER quote
{
    if (parserData->numberOfConAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = $3;
};

numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = $3; 
};

numberOfElAttribute: NUMBEROFELATT quote INTEGER quote 
{
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = $3; 
}; 

numberOfEnumerationsAttribute: NUMBEROFENUMERATIONSATT quote INTEGER quote 
{
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = $3; 
}; 

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = $3;
};
*/
numberOfJobIDsATT: NUMBEROFJOBIDSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};
/*
numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = $3;
}; 

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = $3; 
};
*/
numberOfOtherConstraintOptionsAttribute: NUMBEROFOTHERCONSTRAINTOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherObjectiveOptionsAttribute: NUMBEROFOTHEROBJECTIVEOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherOptionsAttribute: NUMBEROFOTHEROPTIONSATT quote INTEGER quote
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherVariableOptionsAttribute: NUMBEROFOTHERVARIABLEOPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = $3;
};

numberOfPathPairsAttribute: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of path pairs cannot be negative");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};

numberOfProcessesATT: NUMBEROFPROCESSESATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};


numberOfSolverOptionsAttribute: NUMBEROFSOLVEROPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = $3;
};
/*
numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = $3; 
}; 

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = $3; 
};
*/
//numberOfVarIdxAttribute: NUMBEROFVARIDXATT quote INTEGER quote 
//{
//    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
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
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionOrResultEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->numberOfEl, 
                osglData->value, 
                osglData->description, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
};

otherEnumerationStart: ENUMERATIONSTART
{
    if (parserData->kounter >= osglData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
};    

otherEnumerationAttributes: otherEnumerationAttList 
    {
        if(!osglData->numberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!osglData->valuePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    };
      
otherEnumerationAttList: | otherEnumerationAttList otherEnumerationATT;

otherEnumerationATT: 
    osglNumberOfElATT 
    {
        osglData->osglCounter = 0;
//        osglData->numberOfElPresent = true;
//        osglData->numberOfEl = parserData->numberOf;
        if (osglData->numberOfEl > 0)
            osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
  ;


otherEnumerationContent: otherEnumerationEmpty | otherEnumerationLaden;

otherEnumerationEmpty: ENDOFELEMENT;


otherEnumerationLaden: GREATERTHAN otherEnumerationBody ENUMERATIONEND;

otherEnumerationBody:  osglIntArrayData;  


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
            

/* $Id$ */
/** @file OSParseosgl.y.syntax
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains parser elements that are contained in the OSgL schema
 * and are shared between several of the main schemas, OSiL, OSoL and OSrL.
 *
 * The code is maintained in such a way that it can be inserted into any one
 * of these parsers by a makefile with minimal changes. 
 * The only change required is to change every occurrence of the
 * placeholder "osoption, parserData, osglData, osnlData" to the appropriate reference, which is
 * for OSiL files "osinstance, parserData, osglData, osnlData", 
 * for OSoL files,  "osoption, parserData, osglData, osnlData", and
 * for OSrL files,  "osresult, parserData, osglData, osnlData".
 * Other schemas with their own separate syntax elements can be added as needed.
 * The makefile accomplishes this through maintaining each parser 
 * in several parts and to copy this include file between the OSxL syntax rules
 * and the postamble to make the final OSParseosxl.y file.
 */

/** ==========================================================================
 *    This portion parses a header object used in OSoL and OSrL schema files
 *  ==========================================================================
 */
osglFileHeader: headerElementStart headerElementContent;
 
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

headerElementEmpty: ENDOFELEMENT;

headerElementLaden: GREATERTHAN headerElementBody HEADEREND; 

headerElementBody: headerElementList;

headerElementList: | headerElementList headerChild;

headerChild:
    fileName 
  | fileSource 
  | fileDescription 
  | fileCreator 
  | fileLicence;

fileName: fileNameContent
{
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
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

fileLicence: fileLicenceContent
{
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
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

/** ==========================================================================
 *         This portion parses the content of an IntVector <el> array
 *  ==========================================================================
 */

osglIntArrayData:
    osglIntVectorElArray 
    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
 | osglIntVectorBase64;

osglIntVectorElArray: | osglIntVectorElArray osglIntVectorEl;

osglIntVectorEl: osglIntVectorElStart osglIntVectorElAttributes osglIntVectorElContent;

osglIntVectorElStart: ELSTART
{    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
};


osglIntVectorElAttributes: osglIntVectorElAttList;

osglIntVectorElAttList: | osglIntVectorElAttList osglIntVectorElAtt;

osglIntVectorElAtt: osglMultATT | osglIncrATT;

osglIntVectorElContent: GREATERTHAN INTEGER ELEND
{
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = $2 + i*osglData->incr;    
};

osglIntVectorBase64: BASE64START osglBase64SizeATT osglIntVectorBase64Content;


osglIntVectorBase64Content: osglIntVectorBase64Empty | osglIntVectorBase64Laden;

osglIntVectorBase64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;


osglIntVectorBase64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
    char* b64string = $2;
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free($2);
};

/** ==========================================================================
 *        This portion parses the content of a DoubleVector <el> element
 *  ==========================================================================
 */

osglDblArrayData: 
    osglDblVectorElArray 
    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
 | osglDblVectorBase64;

osglDblVectorElArray: | osglDblVectorElArray osglDblVectorEl;

osglDblVectorEl: osglDblVectorElStart osglDblVectorElAttributes osglDblVectorElContent;

osglDblVectorElStart: ELSTART
{    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
};


osglDblVectorElAttributes: | osglMultATT;

osglDblVectorElContent: GREATERTHAN aNumber ELEND
{
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
};

osglDblVectorBase64: BASE64START osglBase64SizeATT osglDblVectorBase64Content;

osglDblVectorBase64Content: osglDblVectorBase64Empty | osglDblVectorBase64Laden;

osglDblVectorBase64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;

osglDblVectorBase64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
    char* b64string = $2;
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free($2);
};


/** ==========================================================================
 *              This portion parses the content of a SparseVector object
 *  ==========================================================================
 */

osglSparseVector: osglSparseVectorNumberOfElATT GREATERTHAN osglSparseVectorIndexes osglSparseVectorValues
{
};

osglSparseVectorNumberOfElATT: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    if (osglData->numberOfEl > 0)
    {
        osglData->osglIntArray = new    int[osglData->numberOfEl];
        osglData->osglDblArray = new double[osglData->numberOfEl];
    }
}; 

osglSparseVectorIndexes: INDEXESSTART GREATERTHAN osglIntVectorElArray INDEXESEND
{
    osglData->osglCounter = 0;
};

osglSparseVectorValues:  VALUESSTART  GREATERTHAN osglDblVectorElArray VALUESEND
{
    osglData->osglCounter = 0;
};


/** ==========================================================================
 *          This portion parses the content of a SparseIntVector object
 *  ==========================================================================
 */

osglSparseIntVector: osglSparseIntVectorNumberOfElATT GREATERTHAN osglSparseIntVectorIndexes osglSparseIntVectorValues
{
};

osglSparseIntVectorNumberOfElATT: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    if (osglData->numberOfEl > 0)
    {
        osglData->osglIntArray = new int[osglData->numberOfEl];
        osglData->osglValArray = new int[osglData->numberOfEl];
    }
}; 

osglSparseIntVectorIndexes: INDEXESSTART GREATERTHAN osglIntVectorElArray INDEXESEND
{
    osglData->osglCounter = 0;
};

osglSparseIntVectorValues:  VALUESSTART  GREATERTHAN osglIntVectorElArray VALUESEND
{
    osglData->osglCounter = 0;
};

/** ===================================================================================
 *       This portion parses an enumeration list of objects associated with 
 *       either options or results that can take on only a (small) number of
 *       distinct values for all members of a particular index class 
 *       (such as variables, objectives, constraints, etc.)
 *  ===================================================================================
 */
osglOtherOptionOrResultEnumerationList: 
    osglOtherOptionOrResultEnumeration 
  | osglOtherOptionOrResultEnumerationList osglOtherOptionOrResultEnumeration;

osglOtherOptionOrResultEnumeration: osglOtherOptionOrResultEnumerationStart osglOtherOptionOrResultEnumerationAttributes 
                           osglOtherOptionOrResultEnumerationContent 
{
//    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther, 
//            parserData->problemComponent, osglData->osglCounter, parserData->valueAttribute, 
//            parserData->descriptionAttribute, osglData->osglIntArray, osglData->numberOfEl) != true)
//        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set option or result enumeration  failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    osglData->osglCounter++;
};

osglOtherOptionOrResultEnumerationStart: ENUMERATIONSTART
{
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->value = "";
    osglData->description = "";
};    

osglOtherOptionOrResultEnumerationAttributes: osglOtherOptionOrResultEnumerationAttList 
    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    };
      
osglOtherOptionOrResultEnumerationAttList: 
  | osglOtherOptionOrResultEnumerationAttList osglOtherOptionOrResultEnumerationATT;

osglOtherOptionOrResultEnumerationATT: 
    osglNumberOfElATT 
    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
  ;


osglOtherOptionOrResultEnumerationContent: 
    osglOtherOptionOrResultEnumerationEmpty 
  | osglOtherOptionOrResultEnumerationLaden;

osglOtherOptionOrResultEnumerationEmpty: ENDOFELEMENT;

osglOtherOptionOrResultEnumerationLaden: GREATERTHAN osglOtherOptionOrResultEnumerationBody ENUMERATIONEND;

osglOtherOptionOrResultEnumerationBody:  osglIntArrayData;  

/** ===================================================================================
 *    This portion parses elements of an LP basis; used in OSoL and OSrL schema files
 *  ===================================================================================
 */
osglBasisStatusBasic: osglBasicStart osglBasisNumberOfElAttribute osglBasicContent

osglBasicStart: BASICSTART
{
    osglData->numberOfElPresent = false;
};

osglBasicContent: osglBasicEmpty | osglBasicLaden;

osglBasicEmpty: ENDOFELEMENT;

osglBasicLaden: GREATERTHAN osglBasicBody BASICEND;

osglBasicBody:  osglIntArrayData;


osglBasisStatusAtLower: osglAtLowerStart osglBasisNumberOfElAttribute osglAtLowerContent

osglAtLowerStart: ATLOWERSTART
{
    osglData->numberOfElPresent = false;
};

osglAtLowerContent: osglAtLowerEmpty | osglAtLowerLaden;

osglAtLowerEmpty: ENDOFELEMENT;

osglAtLowerLaden: GREATERTHAN osglAtLowerBody ATLOWEREND;

osglAtLowerBody:  osglIntArrayData;


osglBasisStatusAtUpper: osglAtUpperStart osglBasisNumberOfElAttribute osglAtUpperContent

osglAtUpperStart: ATUPPERSTART
{
    osglData->numberOfElPresent = false;
};

osglAtUpperContent: osglAtUpperEmpty | osglAtUpperLaden;

osglAtUpperEmpty: ENDOFELEMENT;

osglAtUpperLaden: GREATERTHAN osglAtUpperBody ATUPPEREND;

osglAtUpperBody:  osglIntArrayData;


osglBasisStatusAtEquality: osglAtEqualityStart osglBasisNumberOfElAttribute osglAtEqualityContent

osglAtEqualityStart: ATEQUALITYSTART
{
    osglData->numberOfElPresent = false;
};

osglAtEqualityContent: osglAtEqualityEmpty | osglAtEqualityLaden;

osglAtEqualityEmpty: ENDOFELEMENT;

osglAtEqualityLaden: GREATERTHAN osglAtEqualityBody ATEQUALITYEND;

osglAtEqualityBody:  osglIntArrayData;


osglBasisStatusIsFree: osglIsFreeStart osglBasisNumberOfElAttribute osglIsFreeContent

osglIsFreeStart: ISFREESTART
{
    osglData->numberOfElPresent = false;
};

osglIsFreeContent: osglIsFreeEmpty | osglIsFreeLaden;

osglIsFreeEmpty: ENDOFELEMENT;

osglIsFreeLaden: GREATERTHAN osglIsFreeBody ISFREEEND;

osglIsFreeBody:  osglIntArrayData;


osglBasisStatusSuperbasic: osglSuperbasicStart osglBasisNumberOfElAttribute osglSuperbasicContent

osglSuperbasicStart: SUPERBASICSTART
{
    osglData->numberOfElPresent = false;
};

osglSuperbasicContent: osglSuperbasicEmpty | osglSuperbasicLaden;

osglSuperbasicEmpty: ENDOFELEMENT;

osglSuperbasicLaden: GREATERTHAN osglSuperbasicBody SUPERBASICEND;

osglSuperbasicBody:  osglIntArrayData;


osglBasisStatusUnknown: osglUnknownStart osglBasisNumberOfElAttribute osglUnknownContent

osglUnknownStart: UNKNOWNSTART
{
    osglData->numberOfElPresent = false;
};

osglUnknownContent: osglUnknownEmpty | osglUnknownLaden;

osglUnknownEmpty: ENDOFELEMENT;

osglUnknownLaden: GREATERTHAN osglUnknownBody UNKNOWNEND;

osglUnknownBody:  osglIntArrayData;


osglBasisNumberOfElAttribute: osglNumberOfElATT
{
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}; 

/** ===================================================================================
 *    This portion parses an OSMatrix object used in OSiL, OSoL and OSrL schema files
 *  ===================================================================================
 *
 *       Note: An OSMatrix is essentially a list of constructors.
 *       This is very similar to parsing an expression tree.
 */
osglMatrix: matrixStart matrixAttributes matrixContent
{
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
};


/**
 *  Note: The OSoL and OSrL schemas use modifications of OSMatrix
 *        that include the index of a matrixVar or matrixObj or matrixCon object.
 *        These modifications are given next.
 */
osglMatrixWithMatrixVarIdx: matrixVarStart matrixWithMatrixVarIdxAttributes matrixVarContent
{
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter] = 
        (OSMatrixWithMatrixVarIdx*)((OSMatrixWithMatrixVarIdx*)osglData->mtxConstructorVec[0])
            ->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter]->matrixVarIdx
        = osglData->matrixVarIdx;
    osglData->matrixCounter++;
};

osglMatrixWithMatrixObjIdx: matrixObjStart matrixWithMatrixObjIdxAttributes matrixObjContent
{
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrixWithMatrixObjIdx[osglData->matrixCounter] = 
        (OSMatrixWithMatrixObjIdx*)((OSMatrixWithMatrixObjIdx*)osglData->mtxConstructorVec[0])
            ->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrixWithMatrixObjIdx[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixWithMatrixObjIdx[osglData->matrixCounter]->matrixObjIdx
        = osglData->matrixObjIdxATT;
    osglData->matrixCounter++;
};

osglMatrixWithMatrixConIdx: matrixConStart matrixWithMatrixConIdxAttributes matrixConContent
{
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrixWithMatrixConIdx[osglData->matrixCounter] = 
        (OSMatrixWithMatrixConIdx*)((OSMatrixWithMatrixConIdx*)osglData->mtxConstructorVec[0])
            ->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrixWithMatrixConIdx[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixWithMatrixConIdx[osglData->matrixCounter]->matrixConIdx
        = osglData->matrixConIdxATT;
    osglData->matrixCounter++;
};
 
matrixStart: MATRIXSTART
{
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back((OSMatrix*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrix*)osglData->tempC);
};

matrixAttributes: matrixAttributeList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
};

matrixAttributeList: | matrixAttributeList matrixAttribute;

matrixAttribute:
      osglSymmetryATT
    | osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | osglNameATT
    | osglTypeATT
;


matrixVarStart: MATRIXVARSTART 
{
    if (osglData->matrixCounter >= osglData->numberOfMatrixVar)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->matrixVarIdxPresent = false;

    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrixWithMatrixVarIdx();
    osglData->mtxConstructorVec.push_back((OSMatrixWithMatrixVarIdx*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrixWithMatrixVarIdx*)osglData->tempC);
}; 

matrixWithMatrixVarIdxAttributes: matrixWithMatrixVarIdxATTList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixVarIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
    else
        ((OSMatrixWithMatrixVarIdx*)osglData->tempC)->matrixVarIdx = osglData->matrixVarIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
};

matrixWithMatrixVarIdxATTList: | matrixWithMatrixVarIdxATTList matrixWithMatrixVarIdxATT;

matrixWithMatrixVarIdxATT:
      osglSymmetryATT
    | osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | osglNameATT
    | osglTypeATT
    | osglMatrixVarIdxATT
;

matrixObjStart: MATRIXOBJSTART 
{
    if (osglData->matrixCounter >= osglData->numberOfMatrixObj)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->matrixObjIdxPresent = false;

    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrixWithMatrixObjIdx();
    osglData->mtxConstructorVec.push_back((OSMatrixWithMatrixObjIdx*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrixWithMatrixObjIdx*)osglData->tempC);
}; 

matrixWithMatrixObjIdxAttributes: matrixWithMatrixObjIdxATTList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixObjIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute matrixObjIdx is missing");
    else
        ((OSMatrixWithMatrixObjIdx*)osglData->tempC)->matrixObjIdx = osglData->matrixObjIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
};

matrixWithMatrixObjIdxATTList: | matrixWithMatrixObjIdxATTList matrixWithMatrixObjIdxATT;

matrixWithMatrixObjIdxATT:
      osglSymmetryATT
    | osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | osglNameATT
    | osglTypeATT
    | osglMatrixObjIdxATT
;

matrixConStart: MATRIXCONSTART 
{
    if (osglData->matrixCounter >= osglData->numberOfMatrixCon)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->matrixConIdxPresent = false;

    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrixWithMatrixConIdx();
    osglData->mtxConstructorVec.push_back((OSMatrixWithMatrixConIdx*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrixWithMatrixConIdx*)osglData->tempC);
}; 

matrixWithMatrixConIdxAttributes: matrixWithMatrixConIdxATTList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixConIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute matrixConIdx is missing");    
    else
        ((OSMatrixWithMatrixConIdx*)osglData->tempC)->matrixConIdx = osglData->matrixConIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
};

matrixWithMatrixConIdxATTList: | matrixWithMatrixConIdxATTList matrixWithMatrixConIdxATT;

matrixWithMatrixConIdxATT:
      osglSymmetryATT
    | osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | osglNameATT
    | osglTypeATT
    | osglMatrixConIdxATT
;


matrixContent: matrixEmpty | matrixLaden;

matrixEmpty: ENDOFELEMENT;

matrixLaden: GREATERTHAN matrixBody MATRIXEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}; 

matrixVarContent: matrixVarEmpty | matrixVarLaden;

matrixVarEmpty: ENDOFELEMENT;

matrixVarLaden: GREATERTHAN matrixBody MATRIXVAREND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
};

matrixObjContent: matrixObjEmpty | matrixObjLaden;

matrixObjEmpty: ENDOFELEMENT;

matrixObjLaden: GREATERTHAN matrixBody MATRIXOBJEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}; 

matrixConContent: matrixConEmpty | matrixConLaden;

matrixConEmpty: ENDOFELEMENT;

matrixConLaden: GREATERTHAN matrixBody MATRIXCONEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
};

matrixBody: baseMatrix matrixConstructorList;

baseMatrix: | baseMatrixStart baseMatrixAttributes baseMatrixEnd
{
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
};

baseMatrixStart: BASEMATRIXSTART
{
    osglData->tempC = new BaseMatrix();
    osglData->mtxConstructorVec.push_back((BaseMatrix*)osglData->tempC);

    osglData->baseMatrixIdxPresent = false;
    osglData->targetMatrixFirstRowPresent = false;
    osglData->targetMatrixFirstColPresent = false;
    osglData->baseMatrixStartRowPresent = false;
    osglData->baseMatrixStartColPresent = false;
    osglData->baseMatrixEndRowPresent = false;
    osglData->baseMatrixEndColPresent = false;
    osglData->baseTransposePresent = false;
    osglData->scalarMultiplierPresent = false;
    osglData->baseMatrixEndRow = -1;
    osglData->baseMatrixEndCol = -1;
};

baseMatrixAttributes: baseMatrixAttList
{
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
    {
        ((BaseMatrix*)osglData->tempC)->baseMatrixIdx = osglData->baseMatrixIdx;
        ((BaseMatrix*)osglData->tempC)->baseMatrix = (OSMatrix*)osglData->matrix[osglData->baseMatrixIdx];
    }
    if (osglData->targetMatrixFirstRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstRow = osglData->targetMatrixFirstRow;
    if (osglData->targetMatrixFirstColPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstCol = osglData->targetMatrixFirstCol;
    if (osglData->baseMatrixStartRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartRow = osglData->baseMatrixStartRow;
    if (osglData->baseMatrixStartColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartCol = osglData->baseMatrixStartCol;
    if (osglData->baseMatrixEndRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndRow = osglData->baseMatrixEndRow;
    if (osglData->baseMatrixEndColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndCol = osglData->baseMatrixEndCol;
    if (osglData->baseTransposePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseTranspose = osglData->baseTranspose;
    if (osglData->scalarMultiplierPresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarMultiplier = osglData->scalarMultiplier;
};

baseMatrixAttList: | baseMatrixAttList baseMatrixAtt;

baseMatrixAtt:
      osglBaseMatrixIdxATT
    | osglTargetMatrixFirstRowATT
    | osglTargetMatrixFirstColATT
    | osglBaseMatrixStartRowATT
    | osglBaseMatrixStartColATT
    | osglBaseMatrixEndRowATT
    | osglBaseMatrixEndColATT
    | osglBaseTransposeATT
    | osglScalarMultiplierATT;


baseMatrixEnd: GREATERTHAN BASEMATRIXEND | ENDOFELEMENT;

matrixConstructorList: | matrixConstructorList matrixConstructor
{
    osglData->mtxBlkVec.back()->inumberOfChildren++;
};

matrixConstructor: constantElements | varReferenceElements | linearElements | realValuedExpressions |
                   objReferenceElements | conReferenceElements | matrixTransformation | matrixBlocks;

constantElements: constantElementsStart constantElementsAttributes GREATERTHAN constantElementsContent; 

constantElementsStart: CONSTANTELEMENTSSTART
{
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

constantElementsAttributes: constantElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
};

constantElementsAttList: | constantElementsAttList constantElementsAtt;

constantElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
  | osglRowMajorATT
    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

constantElementsContent: matrixElementsStartVector constantElementsNonzeros CONSTANTELEMENTSEND;

constantElementsNonzeros: | matrixElementsIndexVector constantElementsValues;

/**
 *  All types of elements have a start vector and an index vector. 
 *  Parsing these elements can therefore be shared among them.
 */
matrixElementsStartVector: matrixElementsStartVectorStart matrixElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

matrixElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

matrixElementsStartVectorContent: matrixElementsStartVectorEmpty | matrixElementsStartVectorLaden;

matrixElementsStartVectorEmpty: ENDOFELEMENT;

matrixElementsStartVectorLaden: GREATERTHAN matrixElementsStartVectorBody STARTVECTOREND;

matrixElementsStartVectorBody: osglIntArrayData;


matrixElementsIndexVector: matrixElementsIndexStart matrixElementsIndexContent
{
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

matrixElementsIndexStart: INDEXSTART
{
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

matrixElementsIndexContent: matrixElementsIndexEmpty | matrixElementsIndexLaden;

matrixElementsIndexEmpty: ENDOFELEMENT;

matrixElementsIndexLaden: GREATERTHAN matrixElementsIndexBody INDEXEND;

matrixElementsIndexBody: osglIntArrayData;


/**
 *  The <value> element is specific to each type
 */
constantElementsValues: constantElementsValueStart constantElementsValueContent
{
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

constantElementsValueStart: VALUESTART
{
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

constantElementsValueContent: constantElementsValueEmpty | constantElementsValueLaden;

constantElementsValueEmpty: ENDOFELEMENT;

constantElementsValueLaden: GREATERTHAN constantElementsValueBody VALUEEND;

constantElementsValueBody: osglDblArrayData;


varReferenceElements: varReferenceElementsStart varReferenceElementsAttributes GREATERTHAN varReferenceElementsContent; 

varReferenceElementsStart: VARREFERENCEELEMENTSSTART
{
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

varReferenceElementsAttributes: varReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
};

varReferenceElementsAttList: | varReferenceElementsAttList varReferenceElementsAtt;

varReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
  | osglRowMajorATT
    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

varReferenceElementsContent: matrixElementsStartVector varReferenceElementsNonzeros VARREFERENCEELEMENTSEND;

varReferenceElementsNonzeros: | matrixElementsIndexVector varReferenceElementsValues;

varReferenceElementsValues: varReferenceElementsValuesStart varReferenceElementsValuesContent
{
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

varReferenceElementsValuesStart: VALUESTART
{
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

varReferenceElementsValuesContent: varReferenceElementsValuesEmpty | varReferenceElementsValuesLaden;

varReferenceElementsValuesEmpty: ENDOFELEMENT;

varReferenceElementsValuesLaden: GREATERTHAN varReferenceElementsValuesBody VALUEEND;

varReferenceElementsValuesBody: osglIntArrayData;

linearElements: linearElementsStart linearElementsAttributes GREATERTHAN linearElementsContent; 

linearElementsStart: LINEARELEMENTSSTART
{
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

linearElementsAttributes: linearElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
};

linearElementsAttList: | linearElementsAttList linearElementsAtt;

linearElementsAtt: 
    osglNumberOfValuesATT
    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
  | osglRowMajorATT
    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

linearElementsContent: matrixElementsStartVector linearElementsNonzeros LINEARELEMENTSEND;

linearElementsNonzeros: | matrixElementsIndexVector linearElementsValues;

linearElementsValues:
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    };    
  | 
    linearElementsValuesStart linearElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

linearElementsValuesStart: VALUESTART
{
    osglData->numberOfValues = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;
    ((LinearMatrixElements*)osglData->tempC)->value = new LinearMatrixValues();
    ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl
        = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;    
    ((LinearMatrixElements*)osglData->tempC)->value->el
        = new LinearMatrixElement*[((LinearMatrixElements*)osglData->tempC)->numberOfValues]; 
    for (int i=0; i < ((LinearMatrixElements*)osglData->tempC)->numberOfValues; i++)
        ((LinearMatrixElements*)osglData->tempC)->value->el[i] = new LinearMatrixElement(); 
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxPresent = false;
};

linearElementsValuesContent: linearElementsValuesEmpty | linearElementsValuesLaden;

linearElementsValuesEmpty: ENDOFELEMENT;

linearElementsValuesLaden: GREATERTHAN linearElementsValuesBody VALUEEND;

linearElementsValuesBody: linearElementsValuesElList;

linearElementsValuesElList:  | linearElementsValuesElList linearElementsValuesEl;

linearElementsValuesEl: linearElementsValuesElStart linearElementsValuesElAttributes linearElementsValuesElContent
{
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
};

linearElementsValuesElStart: ELSTART
{
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
};  

linearElementsValuesElAttributes: linearElementsValuesElAttList
{
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
        = osglData->constant;
    osglData->osglCounter = 0;
};

linearElementsValuesElAttList: | linearElementsValuesElAttList linearElementsValuesElAtt;

linearElementsValuesElAtt: 
      osglNumberOfVarIdxATT
    | osglConstantATT;

linearElementsValuesElContent: linearElementsValuesElEmpty | linearElementsValuesElLaden;

linearElementsValuesElEmpty: ENDOFELEMENT;

linearElementsValuesElLaden: GREATERTHAN linearElementsValuesVarIdxList ELEND;

linearElementsValuesVarIdxList: | linearElementsValuesVarIdxList linearElementsValuesVarIdx;

linearElementsValuesVarIdx: 
    linearElementsValuesVarIdxStart LinearElementsValuesVarIdxCoefATT linearElementsValuesVarIdxContent;

linearElementsValuesVarIdxStart: VARIDXSTART
{
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
};

LinearElementsValuesVarIdxCoefATT: | osglCoefATT
{
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}; 

linearElementsValuesVarIdxContent: GREATERTHAN INTEGER VARIDXEND
{
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = $2;
    osglData->osglCounter++;
};


realValuedExpressions: realValuedExpressionsStart realValuedExpressionsAttributes GREATERTHAN realValuedExpressionsContent; 

realValuedExpressionsStart: REALVALUEDEXPRESSIONSSTART
{
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

realValuedExpressionsAttributes: realValuedExpressionsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
};

realValuedExpressionsAttList: | realValuedExpressionsAttList realValuedExpressionsAtt;

realValuedExpressionsAtt: 
    osglNumberOfValuesATT
    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
  | osglRowMajorATT
    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

realValuedExpressionsContent: 
    matrixElementsStartVector realValuedExpressionsNonzeros REALVALUEDEXPRESSIONSSEND;

realValuedExpressionsNonzeros: | matrixElementsIndexVector realValuedExpressionsValues;

realValuedExpressionsValues:
    | realValuedExpressionsValuesStart realValuedExpressionsValuesContent;

realValuedExpressionsValuesStart: VALUESTART
{
    osglData->nonzeroCounter = 0;
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((RealValuedExpressions*)osglData->tempC)->value->el
        = new RealValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((RealValuedExpressions*)osglData->tempC)->value->el[i] = new RealValuedExpressionTree();
};

realValuedExpressionsValuesContent: realValuedExpressionsValuesEmpty | realValuedExpressionsValuesLaden;

realValuedExpressionsValuesEmpty: ENDOFELEMENT;

realValuedExpressionsValuesLaden: GREATERTHAN realValuedExpressionsElList VALUEEND;

realValuedExpressionsElList:  | realValuedExpressionsElList realValuedExpressionsEl;

realValuedExpressionsEl: realValuedExpressionsElStart realValuedExpressionsElContent;

realValuedExpressionsElStart: ELSTART
    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

realValuedExpressionsElContent: realValuedExpressionsElEmpty | realValuedExpressionsElLaden;

realValuedExpressionsElEmpty: ENDOFELEMENT;

realValuedExpressionsElLaden: GREATERTHAN nlnode ELEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    };


objReferenceElements: objReferenceElementsStart objReferenceElementsAttributes GREATERTHAN objReferenceElementsContent; 

objReferenceElementsStart: OBJREFERENCEELEMENTSSTART
{
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

objReferenceElementsAttributes: objReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
};

objReferenceElementsAttList: | objReferenceElementsAttList objReferenceElementsAtt;

objReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
  | osglRowMajorATT
    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

objReferenceElementsContent: matrixElementsStartVector objReferenceElementsNonzeros OBJREFERENCEELEMENTSEND;

objReferenceElementsNonzeros: | matrixElementsIndexVector objReferenceElementsValues;

objReferenceElementsValues: objReferenceElementsValuesStart objReferenceElementsValuesContent
{
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objReferenceElementsValuesStart: VALUESTART
{
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

objReferenceElementsValuesContent: objReferenceElementsValuesEmpty | objReferenceElementsValuesLaden;

objReferenceElementsValuesEmpty: ENDOFELEMENT;

objReferenceElementsValuesLaden: GREATERTHAN objReferenceElementsValuesBody VALUEEND;

objReferenceElementsValuesBody: osglIntArrayData;


conReferenceElements: conReferenceElementsStart conReferenceElementsAttributes GREATERTHAN conReferenceElementsContent; 

conReferenceElementsStart: CONREFERENCEELEMENTSSTART
{
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

conReferenceElementsAttributes: conReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
};

conReferenceElementsAttList: | conReferenceElementsAttList conReferenceElementsAtt;

conReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
  | osglRowMajorATT
    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

conReferenceElementsContent: matrixElementsStartVector conReferenceElementsNonzeros CONREFERENCEELEMENTSEND;

conReferenceElementsNonzeros: | matrixElementsIndexVector conReferenceElementsValues;

conReferenceElementsValues: 
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    };    

  | conReferenceElementsValuesStart conReferenceElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

conReferenceElementsValuesStart: VALUESTART
{
    osglData->numberOfValues = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->value = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((ConReferenceMatrixElements*)osglData->tempC)->value->el
        = new ConReferenceMatrixElement*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->value->el[i] = new ConReferenceMatrixElement();
};

conReferenceElementsValuesContent: conReferenceElementsValuesEmpty | conReferenceElementsValuesLaden;

conReferenceElementsValuesEmpty: ENDOFELEMENT;

conReferenceElementsValuesLaden: GREATERTHAN conReferenceElementsElList VALUEEND;

conReferenceElementsElList: | conReferenceElementsElList conReferenceElementsEl;

conReferenceElementsEl: conReferenceElementsElStart conReferenceElementsElAttributeList
                        conReferenceElementsElContent
{
//    osglData->nonzeroCounter++;
//    if (osglData->nonzeroCounter > osglData->osglNumberOfNonzeros)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "conReference matrix elements: too many nonzeros");
};

conReferenceElementsElStart: ELSTART
    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = ""; //ENUM_CONREFERENCE_VALUETYPE_value;
    };

conReferenceElementsElAttributeList: | conReferenceElementsElAttributeList conReferenceElementsElAttribute;

conReferenceElementsElAttribute: 
    osglValueTypeATT
  | osglMultATT
  | osglIncrATT;

/*
conReferenceElementsElValueTypeATT: VALUETYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "only one valueType attribute allowed");

    std::string tmpStr = $2;
    if (returnConReferenceValueType(tmpStr) > 0)  
        osglData->valueType = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(tmpStr); 
    else
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
    free($2);
};
*/
conReferenceElementsElContent: GREATERTHAN INTEGER ELEND
{
    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
        else
        {
            for (int i=0; i<osglData->mult; i++)
            {
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->conReference
                    = $2 + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
};


matrixTransformation: matrixTransformationStart matrixTransformationShapeATT GREATERTHAN 
                      OSnLMNode matrixTransformationEnd;

matrixTransformationStart: TRANSFORMATIONSTART
{
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back((MatrixTransformation*)osglData->tempC);

    // clear the vectors of pointers
    osnlData->nlNodeVec.clear();
    osnlData->sumVec.clear();
    osnlData->allDiffVec.clear();
    osnlData->maxVec.clear();
    osnlData->minVec.clear();
    osnlData->productVec.clear();
    osnlData->matrixSumVec.clear();
    osnlData->matrixProductVec.clear();

    osglData->shapePresent = false;   
};

matrixTransformationShapeATT: | osglShapeATT
{
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
};


matrixTransformationEnd: TRANSFORMATIONEND
{
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
};

matrixBlocks: matrixBlocksStart matrixBlocksAttributes matrixBlocksContent
{
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
};

matrixBlocksStart: BLOCKSSTART
{
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
};

matrixBlocksAttributes: osglNumberOfBlocksATT
{
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
};

matrixBlocksContent: GREATERTHAN colOffsets rowOffsets blockList matrixBlocksEnd;

matrixBlocksEnd: BLOCKSEND
{
    if ( ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren != 
                           osglData->nBlocksVec.back())
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
};


colOffsets: colOffsetStart colOffsetNumberOfElAttribute colOffsetContent
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

colOffsetStart: COLOFFSETSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
};

colOffsetNumberOfElAttribute: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}; 

colOffsetContent: colOffsetEmpty | colOffsetLaden;

colOffsetEmpty: ENDOFELEMENT;

colOffsetLaden: GREATERTHAN colOffsetBody COLOFFSETEND;

colOffsetBody:  osglIntArrayData;

rowOffsets: rowOffsetStart rowOffsetNumberOfElAttribute rowOffsetContent
{
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

rowOffsetStart: ROWOFFSETSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
};

rowOffsetNumberOfElAttribute: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}; 

rowOffsetContent: rowOffsetEmpty | rowOffsetLaden;

rowOffsetEmpty: ENDOFELEMENT;

rowOffsetLaden: GREATERTHAN rowOffsetBody ROWOFFSETEND;

rowOffsetBody:  osglIntArrayData;

blockList: | blockList matrixBlock
{
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
};

matrixBlock: matrixBlockStart matrixBlockAttributes matrixBlockContent
{
    osglData->mtxBlkVec.pop_back();
};

matrixBlockStart: BLOCKSTART
{
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back((MatrixBlock*)osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}; 

matrixBlockAttributes: matrixBlockAttList;

matrixBlockAttList: | matrixBlockAttList matrixBlockAtt;

matrixBlockAtt:
      osglBlockRowIdxATT
    | osglBlockColIdxATT 
    | osglSymmetryATT
    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    | osglTypeATT
    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
;

matrixBlockContent: blockEmpty | blockLaden;

blockEmpty: ENDOFELEMENT;

blockLaden: GREATERTHAN blockBody BLOCKEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}; 

blockBody: baseMatrix matrixConstructorList;




/** Here we parse every attribute that appears in more than one schema 
 *  There are three sections:
 *  1. numberOf... attributes
 *  2. Other attributes returning numbers
 *  3. Attributes returning strings (that may be empty)
 */

/*  1. numberOf... attributes */ 

osglNumberOfBlocksATT: NUMBEROFBLOCKSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = $3;
};

osglNumberOfColumnsATT: NUMBEROFCOLUMNSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = $3;
};

osglNumberOfConATT: NUMBEROFCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = $3;
};

osglNumberOfConIdxATT: NUMBEROFCONIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <conIdx> cannot be negative");
    osglData->numberOfConIdxPresent = true;        
    osglData->numberOfConIdx = $3;
};

osglNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = $3;
};

osglNumberOfElATT: NUMBEROFELATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = $3;
};

osglNumberOfEnumerationsATT: NUMBEROFENUMERATIONSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = $3;
};

osglNumberOfItemsATT: NUMBEROFITEMSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = $3;
};

osglNumberOfMatricesATT: NUMBEROFMATRICESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <matrices> cannot be negative");
    osglData->numberOfMatricesPresent = true;        
    osglData->numberOfMatrices = $3;
};

osglNumberOfMatrixConATT: NUMBEROFMATRIXCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfMatrixCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <matrixCon> cannot be negative");
    osglData->numberOfMatrixConPresent = true;        
    osglData->numberOfMatrixCon = $3;
};

osglNumberOfMatrixObjATT: NUMBEROFMATRIXOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfMatrixObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <matrixObj> cannot be negative");
    osglData->numberOfMatrixObjPresent = true;        
    osglData->numberOfMatrixObj = $3;
};

osglNumberOfMatrixVarATT: NUMBEROFMATRIXVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = $3;
};

/*
osglNumberOfNonzerosATT: NUMBEROFNONZEROSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfNonzerosPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfNonzeros attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of nonzeros cannot be negative");
    osglData->numberOfNonzerosPresent = true;        
    osglData->numberOfNonzeros = $3;
};
*/

osglNumberOfObjATT: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = $3;
};

osglNumberOfObjIdxATT: NUMBEROFOBJIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <objIdx> cannot be negative");
    osglData->numberOfObjIdxPresent = true;        
    osglData->numberOfObjIdx = $3;
};

osglNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = $3;
};

osglNumberOfRowsATT: NUMBEROFROWSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = $3;
};

osglNumberOfValuesATT: NUMBEROFVALUESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = $3;
};

osglNumberOfVarATT: NUMBEROFVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = $3;
};

osglNumberOfVarIdxATT: NUMBEROFVARIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = $3;
};

osglNumberOfVariablesATT: NUMBEROFVARIABLESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = $3;
};

/*  2. Other attributes returning numbers */

osglBase64SizeATT: SIZEOFATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = $3;
};

osglBaseMatrixIdxATT: BASEMATRIXIDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ($3 > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = $3; 
};

osglBaseMatrixStartRowATT: BASEMATRIXSTARTROWATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = $3; 
};

osglBaseMatrixStartColATT: BASEMATRIXSTARTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = $3; 
};

osglBaseMatrixEndRowATT: BASEMATRIXENDROWATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = $3; 
};

osglBaseMatrixEndColATT: BASEMATRIXENDCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = $3; 
};

osglBlockRowIdxATT: BLOCKROWIDXATT quote INTEGER quote
{
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = $3;
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
};

osglBlockColIdxATT: BLOCKCOLIDXATT quote INTEGER quote
{
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = $3;       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
};

osglCoefATT: COEFATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
};

osglConstantATT: CONSTANTATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
};

osglIdxATT: IDXATT QUOTE INTEGER QUOTE 
    { 
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *$2 != *$4 ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
        osglData->idx = $3;
    };

osglIncrATT: INCRATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = $3;
};

osglMatrixConIdxATT: MATRIXCONIDXATT quote INTEGER quote 
{
    if (osglData->matrixConIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixConIdx attribute in <matrixCon> element");
    osglData->matrixConIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixConIdx> cannot be negative");
    osglData->matrixConIdx = $3; 
};

osglMatrixObjIdxATT: MATRIXOBJIDXATT quote INTEGER quote 
{
    if (osglData->matrixObjIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixObjIdx attribute in <matrixObj> element");
    osglData->matrixObjIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixObjIdx> cannot be negative");
    osglData->matrixObjIdx = $3; 
};

osglMatrixVarIdxATT: MATRIXVARIDXATT quote INTEGER quote 
{
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = $3; 
};

osglMultATT: MULTATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ($3 <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = $3;
};

osglScalarMultiplierATT: SCALARMULTIPLIERATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
};

osglTargetMatrixFirstRowATT: TARGETMATRIXFIRSTROWATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = $3; 
};

osglTargetMatrixFirstColATT: TARGETMATRIXFIRSTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = $3; 
};

/* 3. Attributes returning strings (that may be empty) */

osglBaseTransposeATT: baseTransposeAttEmpty | baseTransposeAttContent;

baseTransposeAttEmpty: EMPTYBASETRANSPOSEATT
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
};

baseTransposeAttContent: BASETRANSPOSEATT ATTRIBUTETEXT quote 
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->baseTranspose = false;
        else if (strcmp($2,"true" ) == 0) osglData->baseTranspose = true;
        else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free($2);
};

osglCategoryATT: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = $2; 
    free($2);
};

osglConTypeATT: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
};

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = $2; 
    free($2);
};

osglDescriptionATT: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
};

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = $2;
    free($2);
};

osglEnumTypeATT: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
};

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = $2; 
    free($2);
};

osglMatrixConTypeATT: matrixConTypeAttEmpty | matrixConTypeAttContent;

matrixConTypeAttEmpty: EMPTYMATRIXCONTYPEATT
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
};

matrixConTypeAttContent: MATRIXCONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
    osglData->matrixConType = $2; 
    free($2);
};

osglMatrixObjTypeATT: matrixObjTypeAttEmpty | matrixObjTypeAttContent;

matrixObjTypeAttEmpty: EMPTYMATRIXOBJTYPEATT
{ 
    if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
};

matrixObjTypeAttContent: MATRIXOBJTYPEATT ATTRIBUTETEXT QUOTE 
{ 
   if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
    osglData->matrixObjType = $2; 
    free($2);
};

osglMatrixTypeATT: matrixTypeAttEmpty | matrixTypeAttContent;

matrixTypeAttEmpty: EMPTYMATRIXTYPEATT
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
};

matrixTypeAttContent: MATRIXTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
    osglData->matrixType = $2; 
    free($2);
};

osglMatrixVarTypeATT: matrixVarTypeAttEmpty | matrixVarTypeAttContent;

matrixVarTypeAttEmpty: EMPTYMATRIXVARTYPEATT
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
};

matrixVarTypeAttContent: MATRIXVARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = $2; 
    free($2);
};

osglNameATT: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
};

nameAttContent: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = $2; 
    free($2);
};

osglObjTypeATT: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
};

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = $2; 
    free($2);
};

osglRowMajorATT: rowMajorAttEmpty | rowMajorAttContent;

rowMajorAttEmpty: EMPTYROWMAJORATT
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
};

rowMajorAttContent: ROWMAJORATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->rowMajor = false;
        else if (strcmp($2,"true" ) == 0) osglData->rowMajor = true;
        else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free($2);
};

osglShapeATT: shapeAttEmpty | shape;

shapeAttEmpty: EMPTYSHAPEATT
{
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
};

shape: SHAPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = $2;
    free($2);
};

osglSolverATT: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
};

solverAttContent: SOLVERATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = $2; 
    free($2);
};

osglSymmetryATT: symmetryAttEmpty | symmetryAttContent;

symmetryAttEmpty: EMPTYSYMMETRYATT
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
};

symmetryAttContent: SYMMETRYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = $2; 
    free($2);
};

osglTypeATT: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
};

typeAttContent: TYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = $2; 
    free($2);
};

osglUnitATT: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
};

unitAttContent: UNITATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = $2; 
    free($2);
};

osglValueATT:       valueAttEmpty | valueAttContent;

osglValuestringATT: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
};

valueAttContent: VALUEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = $2; 
    free($2);
};

osglValueTypeATT: valueTypeAttEmpty | valueTypeAttContent;

valueTypeAttEmpty: EMPTYVALUETYPEATT
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
};

valueTypeAttContent: VALUETYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = $2; 
    free($2);
};

osglVarTypeATT: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
};

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = $2; 
    free($2);
};

/* $Id$ */
/** @file OSParseosnl.y.syntax
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains parser elements that are contained in the OSnL schema
 * and are shared between several of the main schemas, OSiL, OSoL and OSrL.
 *
 * The code is maintained in such a way that it can be inserted into any one
 * of these parsers by a makefile with minimal changes. 
 * The only change required is to change every occurrence of the placeholder
 * "targetObject" to the appropriate reference ("osinstance" for OSiL files, 
 * "osoption" for OSoL files and "osresult" for OSrL files). 
 * The makefile accomplishes this through maintaining each parser 
 * in several parts and to copy this include file between the OSxL syntax rules
 * and the postamble to make the final OSParseosxl.y file.
 */

/** ==========================================================================
 *           This portion parses nonlinear and matrix expressions
 *  ==========================================================================
 */

nonlinearExpressions:  
                | nonlinearExpressionsStart nlnumberatt nlnodes  NONLINEAREXPRESSIONSEND
    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    };

nonlinearExpressionsStart: NONLINEAREXPRESSIONSSTART
    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    };

nlnumberatt: NUMBEROFNONLINEAREXPRESSIONS QUOTE INTEGER QUOTE GREATERTHAN 
    { 
        if ( *$2 != *$4 ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
        if ($3 < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
        osnlData->nlnodenumber = $3;
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = $3;  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ $3 ];
        for (int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[i] = new Nl();
        }
    };

/**
 *  Note: In order to be semantically correct, the sequence of nlnodes must be structured
 *  such that the nodes can be partitioned into one or more expression trees. 
 *  The expression tree is eventually identified with its root node.
 */                  
nlnodes: 
        | nlnodes scalarExpressionTree;

scalarExpressionTree: nlstart nlAttributes GREATERTHAN nlnode NLEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    };

nlstart: NLSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

nlAttributes: nlAttributeList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
};


nlAttributeList: | nlAttributeList nlAttribute;

nlAttribute: 
      osglIdxATT 
    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new RealValuedExpressionTree();
    }
    | osglShapeATT
    {
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape 
                = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    };

nlnode: number
      | variable 
      | times 
      | plus 
      | sum 
      | minus 
      | negate
      | divide 
      | power 
      | product
      | ln 
      | sqrt 
      | square
      | sin
      | cos
      | exp
      | if
      | abs
      | erf
      | max
      | min
      | E
      | PI
      | allDiff 

      | matrixDeterminant
      | matrixTrace
      | matrixToScalar
;

/** The first two nodes are terminal nodes; they have no descendants */
E: ESTART {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);} eend;
    
eend: ENDOFELEMENT
            | GREATERTHAN EEND;
            
PI: PISTART {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);} piend;
    
piend: ENDOFELEMENT
            | GREATERTHAN PIEND;

   
/** These nodes have a fixed number of descendants (which get allocated automatically in the constructor) */
times: TIMESSTART {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode TIMESEND;

plus: PLUSSTART {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode PLUSEND;

minus: MINUSSTART {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode MINUSEND;

negate: NEGATESTART {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode  NEGATEEND;

divide: DIVIDESTART { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode DIVIDEEND;

power: POWERSTART {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode POWEREND;

ln: LNSTART {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode LNEND;

sqrt: SQRTSTART {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SQRTEND;

square: SQUARESTART {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SQUAREEND;

cos: COSSTART {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode COSEND;

sin: SINSTART {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SINEND;

exp: EXPSTART {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode EXPEND;

abs: absStart nlnode absEnd;

absStart: ABSSTART 
{
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

absEnd: ABSEND 
{
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
};

erf: ERFSTART {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode ERFEND {
};

if: IFSTART {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode nlnode IFEND
{
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
};


/** some more scalar-valued nodes that involve matrix children */
matrixDeterminant: MATRIXDETERMINANTSTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXDETERMINANTEND;

matrixTrace: MATRIXTRACESTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXTRACEEND;

matrixToScalar: MATRIXTOSCALARSTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXTOSCALAREND;


/** These next two nodes have attributes
 *  In addition <variable> has an optional OSnLNode descendant 
 *  (for variable index expressions) --- not implemented yet.
 */
number: numberStart numberAttributeList numberEnd
{
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
};

numberStart: NUMBERSTART 
{
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
};

numberEnd: ENDOFELEMENT
         | GREATERTHAN NUMBEREND;

numberAttributeList:
         | numberAttributeList numberAttribute;
            
numberAttribute: 
    osglTypeATT
    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
  | osglValueATT
    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    };
  | numberidATT            
            ;
            
numberidATT:   IDATT   ATTRIBUTETEXT 
{
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = $2;
    free($2);
} QUOTE;

numbervalueATT: VALUEATT QUOTE aNumber QUOTE 
{
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
};


variable: VARIABLESTART 
{
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
} anotherVariableATT  variableend {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;} ;
              
variableend: 
      ENDOFELEMENT
    | GREATERTHAN VARIABLEEND
    | GREATERTHAN nlnode 
        {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }    
        VARIABLEEND;
            
anotherVariableATT:
            | anotherVariableATT variableATT;
            
variableATT: 
      variablecoefATT  
        {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    | variableidxATT
        {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
;
            
variablecoefATT: COEFATT  QUOTE aNumber QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
};
                
variableidxATT: IDXATT QUOTE  INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = $3;
}; 


/** 
 *  These nodes have a variable number of descendants that cannot be allocated beforehand.
 *  Some dirty trickery is involved in accomplishing everything.
 *  First, when such a node is encountered, it is pushed onto two vectors simultaneously:
 *  the vector of all nl nodes and a vector of special nodes (to cater for the possibility
 *  that there might be nested sums, etc.). Both vectors point to the same memory location,
 *  which can be manipulated through whichever vector is more convenient. This is used in
 *  SUMEND below to allocate the right number of descendants (once this is known) and in
 *  nlnode below it to increment the number of descendants.
 */
sum: SUMSTART {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
anothersumnlnode SUMEND {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
};

anothersumnlnode: | anothersumnlnode nlnode { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; };
            

allDiff: ALLDIFFSTART {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
anotherallDiffnlnode ALLDIFFEND {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
};

anotherallDiffnlnode: 
            | anotherallDiffnlnode nlnode { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; };
            
            
max: MAXSTART {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
anothermaxnlnode MAXEND {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
};

anothermaxnlnode: 
            | anothermaxnlnode nlnode { osnlData->maxVec.back()->inumberOfChildren++; };


min: MINSTART {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
anotherminnlnode MINEND {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
};

anotherminnlnode: 
            | anotherminnlnode nlnode { osnlData->minVec.back()->inumberOfChildren++; };

            
product: PRODUCTSTART {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
anotherproductnlnode PRODUCTEND {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
};

anotherproductnlnode: 
            | anotherproductnlnode nlnode { osnlData->productVec.back()->inumberOfChildren++; };



/** OSnLMNodes are parsed in essentially the same way as OSnLNodes */

OSnLMNode: matrixReference
         | matrixVarReference
         | matrixObjReference
         | matrixConReference
         | matrixDiagonal
         | matrixDotTimes
         | matrixInverse
         | matrixLowerTriangle
         | matrixUpperTriangle
         | matrixMerge
         | matrixMinus
         | matrixNegate
         | matrixPlus
         | matrixTimes
         | matrixProduct
         | matrixScalarTimes
         | matrixSubMatrixAt
         | matrixTranspose
         | identityMatrix
;

matrixReference: matrixReferenceStart matrixIdxATT matrixReferenceEnd 
{
    osnlData->matrixidxattON = false;
};

matrixReferenceStart: MATRIXREFERENCESTART
{
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
};

              
matrixReferenceEnd: ENDOFELEMENT
           | GREATERTHAN MATRIXREFERENCEEND;
                           
matrixIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = $3;
}; 


matrixVarReference: matrixVarReferenceStart matrixVarIdxATT matrixVarReferenceEnd 
{
    osnlData->matrixidxattON = false;
};

matrixVarReferenceStart: MATRIXVARSTART
{
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
};

              
matrixVarReferenceEnd: ENDOFELEMENT
           | GREATERTHAN MATRIXVAREND;
                           
matrixVarIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = $3;
}; 

matrixObjReference: matrixObjReferenceStart matrixObjIdxATT matrixObjReferenceEnd 
{
    osnlData->matrixidxattON = false;
};

matrixObjReferenceStart: MATRIXOBJSTART
{
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
};

              
matrixObjReferenceEnd: ENDOFELEMENT
           | GREATERTHAN MATRIXOBJEND;
                           
matrixObjIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = $3;
}; 

matrixConReference: matrixConReferenceStart matrixConIdxATT matrixConReferenceEnd 
{
    osnlData->matrixidxattON = false;
};

matrixConReferenceStart: MATRIXCONSTART
{
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
};

              
matrixConReferenceEnd: ENDOFELEMENT
           | GREATERTHAN MATRIXCONEND;
                           
matrixConIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = $3;
}; 

matrixDiagonal: matrixDiagonalStart matrixDiagonalContent;

matrixDiagonalStart: MATRIXDIAGONALSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixDiagonalContent: OSnLMNode MATRIXDIAGONALEND;

matrixDotTimes: matrixDotTimesStart matrixDotTimesContent;

matrixDotTimesStart: MATRIXDOTTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixDotTimesContent: OSnLMNode OSnLMNode MATRIXDOTTIMESEND;

identityMatrix: identityMatrixStart identityMatrixContent;

identityMatrixStart: IDENTITYMATRIXSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

identityMatrixContent: nlnode IDENTITYMATRIXEND;

matrixInverse: matrixInverseStart matrixInverseContent;

matrixInverseStart: MATRIXINVERSESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixInverseContent: OSnLMNode MATRIXINVERSEEND;

matrixLowerTriangle: matrixLowerTriangleStart matrixLowerTriangleAttribute GREATERTHAN matrixLowerTriangleContent;

matrixLowerTriangleStart: MATRIXLOWERTRIANGLESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixLowerTriangleAttribute: | includeDiagonalATT
{
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
};

matrixLowerTriangleContent: OSnLMNode MATRIXLOWERTRIANGLEEND;

matrixUpperTriangle: matrixUpperTriangleStart matrixUpperTriangleAttribute GREATERTHAN matrixUpperTriangleContent;

matrixUpperTriangleStart: MATRIXUPPERTRIANGLESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixUpperTriangleAttribute: | includeDiagonalATT
{
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
};

matrixUpperTriangleContent: OSnLMNode MATRIXUPPERTRIANGLEEND;

includeDiagonalATT: INCLUDEDIAGONALATT ATTRIBUTETEXT QUOTE 
{
    if      (strcmp($2,"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp($2,"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free($2);
};


matrixMerge: matrixMergeStart matrixMergeEnd;

matrixMergeStart: MATRIXMERGESTART 
{
     parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "matrix merge not yet implemented");
};

matrixMergeEnd: ENDOFELEMENT | GREATERTHAN MATRIXMERGEEND;

matrixMinus: matrixMinusStart matrixMinusContent;

matrixMinusStart: MATRIXMINUSSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixMinusContent: OSnLMNode OSnLMNode MATRIXMINUSEND;


matrixNegate: matrixNegateStart matrixNegateContent;

matrixNegateStart: MATRIXNEGATESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixNegateContent: OSnLMNode MATRIXNEGATEEND;


matrixPlus: matrixPlusStart matrixPlusContent;

matrixPlusStart: MATRIXPLUSSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixPlusContent: OSnLMNode OSnLMNode MATRIXPLUSEND;


matrixTimes: matrixTimesStart matrixTimesContent;

matrixTimesStart: MATRIXTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixTimesContent: OSnLMNode OSnLMNode MATRIXTIMESEND;

            
matrixProduct: MATRIXPRODUCTSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
anothermatrixproductnode MATRIXPRODUCTEND 
{
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
};

anothermatrixproductnode: | anothermatrixproductnode OSnLMNode 
{ 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
};



matrixScalarTimes: matrixScalarTimesStart matrixScalarTimesContent;

matrixScalarTimesStart: MATRIXSCALARTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixScalarTimesContent: nlnode OSnLMNode MATRIXSCALARTIMESEND;

matrixSubMatrixAt: matrixSubMatrixAtStart matrixSubMatrixAtContent;

matrixSubMatrixAtStart: MATRIXSUBMATRIXATSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixSubMatrixAtContent: nlnode nlnode nlnode nlnode OSnLMNode MATRIXSUBMATRIXATEND;


matrixTranspose: matrixTransposeStart matrixTransposeContent;

matrixTransposeStart: MATRIXTRANSPOSESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixTransposeContent: OSnLMNode MATRIXTRANSPOSEEND;



/**
 *  Here we have the parser for the <matrixExpressions> <expr> element,
 *  which is essentially the same as a nonlinear expression, except that
 *  the root node returns a matrix. We reuse as much of the code and
 *  data structures as possible. 
 */
matrixExpressions: | matrixExpressionsStart matrixExpressionsAtt matrixExpressionsContent
    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    };

matrixExpressionsStart: MATRIXEXPRESSIONSSTART
    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    };

matrixExpressionsAtt: numberOfExprATT;

numberOfExprATT: NUMBEROFEXPR QUOTE INTEGER QUOTE 
    {
    #ifdef OSINSTANCE_AVAILABLE
        if (*$2 != *$4) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mismatched quotes");
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = $3;
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = $3;  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr
                = new MatrixExpression*[ $3 ];
        for (int i = 0; 
                 i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr;
                 i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i]
                = new MatrixExpression();
    #endif
    }; 

matrixExpressionsContent: matrixExpressionsEmpty | matrixExpressionsLaden;

matrixExpressionsEmpty: ENDOFELEMENT;

matrixExpressionsLaden: GREATERTHAN matrixExprList MATRIXEXPRESSIONSEND;

matrixExprList: | matrixExprList matrixExpr;

matrixExpr: matrixExprStart matrixExprAttributes GREATERTHAN OSnLMNode EXPREND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    };

matrixExprStart: EXPRSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of matrix expressions greater than number attribute");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

matrixExprAttributes: matrixExprAttributeList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
};

matrixExprAttributeList: | matrixExprAttributeList exprAttribute;

exprAttribute: 
      osglIdxATT 
    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    | osglShapeATT
    {
    #ifdef OSINSTANCE_AVAILABLE
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->matrixProgramming->matrixExpressions
                ->expr[ osnlData->tmpnlcount]->shape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    #endif
    };


/* $Id$ */
/** @file OSParseosol.y.3
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the last part of the file OSParseosol.y containing the postamble.
 * It is appended as the last file.
 */

%%

#if 0
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either invalid or not well-formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, 
      OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData, osnlData) != 0) {
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

