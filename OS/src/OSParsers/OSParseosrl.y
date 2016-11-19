/* $Id$ */
/** @file OSParseosrl.y.1
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosrl.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the first part of the file OSParseosrl.y. It contains the
 * preamble and tokens that are unique to the OSrL parser.
 * Tokens pertaining to the auxiliary OSgL and OSnL parsers are appended.
 * These are in files OSParseosgl.y.tokens and OSParseosnl.y.tokens.   
 * Then follow the syntax rules involving only OSrL constructs (OSParseosrl.y.2). 
 * After that we put the syntax rules for elements from the OSgL schema, 
 * maintained in the file OSParseosgl.y.syntax, and then the OSnL syntax
 * in OSParseosnl.y.syntax. The postamble in OSParseosrl.y.3 is appended at the end.
 * This process could be repeated for as many other auxiliary schemas as needed.
 *
 * Note: Make changes in this file rather than OSParseosrl.y or OSParserosrl.tab.cpp,
 *       as the latter files are recreated by the build system and are thus to be
 *       considered fragile.
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
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <cstring>

#define OSRESULT_AVAILABLE

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
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
void osrl_empty_vectors( OSrLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);



%}


%pure-parser
%locations
%defines
%parse-param{OSResult *osresult}
%parse-param{OSrLParserData *parserData}
%parse-param{OSgLParserData *osglData}
%parse-param{OSnLParserData *osnlData}
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
std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData* osnlData, std::string errormsg);
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE
%token <sval> TWOQUOTES
%token <sval> BOOLEAN

%token GREATERTHAN ENDOFELEMENT

%token OSRLSTART OSRLSTARTEMPTY OSRLATTRIBUTETEXT OSRLEND

%token WEIGHTEDOBJECTIVESATT EMPTYWEIGHTEDOBJECTIVESATT
%token TARGETOBJECTIVENAMEATT EMPTYTARGETOBJECTIVENAMEATT

%token NUMBEROFOTHERCONSTRAINTRESULTSATT NUMBEROFOTHEROBJECTIVERESULTSATT 
%token NUMBEROFOTHERRESULTSATT NUMBEROFOTHERSOLUTIONRESULTSATT 
%token NUMBEROFOTHERVARIABLERESULTSATT NUMBEROFSOLUTIONSATT 
%token NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT
%token NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT NUMBEROFOTHERMATRIXVARIABLERESULTSATT
%token NUMBEROFSOLVEROUTPUTSATT NUMBEROFSUBSTATUSESATT NUMBEROFTIMESATT 

%token TARGETOBJECTIVEIDXATT

%token ACTUALSTARTTIMESTART ACTUALSTARTTIMEEND
%token AVAILABLECPUNUMBERSTART AVAILABLECPUNUMBEREND
%token AVAILABLECPUSPEEDSTART AVAILABLECPUSPEEDEND
%token AVAILABLEDISKSPACESTART AVAILABLEDISKSPACEEND
%token AVAILABLEMEMORYSTART AVAILABLEMEMORYEND
%token BASISSTATUSSTART BASISSTATUSEND
%token CURRENTJOBCOUNTSTART CURRENTJOBCOUNTEND
%token CURRENTSTATESTART CURRENTSTATEEND
%token DUALVALUESSTART DUALVALUESEND  
%token ENDTIMESTART ENDTIMEEND
%token IDXSTART IDXEND
%token GENERALSTATUSSTART GENERALSTATUSEND 
%token GENERALSUBSTATUSSTART GENERALSUBSTATUSEND 
%token MESSAGESTART MESSAGEEND
%token OPTIMIZATIONSOLUTIONSTATUSSTART OPTIMIZATIONSOLUTIONSTATUSEND
%token OPTIMIZATIONSOLUTIONSUBSTATUSSTART  OPTIMIZATIONSOLUTIONSUBSTATUSEND 
%token OTHERRESULTSSTART OTHERRESULTSEND
%token OTHERSOLUTIONRESULTSTART  OTHERSOLUTIONRESULTEND
%token OTHERSOLUTIONRESULTSSTART OTHERSOLUTIONRESULTSEND
%token OTHERSOLVEROUTPUTSTART OTHERSOLVEROUTPUTEND
%token SCHEDULEDSTARTTIMESTART SCHEDULEDSTARTTIMEEND
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
%token VALUESSTRINGSTART VALUESSTRINGEND

%token OTHERMATRIXVARIABLERESULTSTART OTHERMATRIXVARIABLERESULTEND
%token OTHERMATRIXOBJECTIVERESULTSTART OTHERMATRIXOBJECTIVERESULTEND
%token OTHERMATRIXCONSTRAINTRESULTSTART OTHERMATRIXCONSTRAINTRESULTEND
%token OTHERMATRIXPROGRAMMINGRESULTSTART
%token OTHERMATRIXPROGRAMMINGRESULTEND

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
%token SCALARMULTIPLIERATT BLOCKROWIDXATT BLOCKCOLIDXATT REATT IMATT

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

%token COMPLEXCONJUGATESTART COMPLEXCONJUGATEEND COMPLEXMINUSSTART COMPLEXMINUSEND
%token COMPLEXNEGATESTART COMPLEXNEGATEEND COMPLEXNUMBERSTART COMPLEXNUMBEREND
%token COMPLEXPLUSSTART COMPLEXPLUSEND COMPLEXSQUARESTART COMPLEXSQUAREEND
%token COMPLEXSUMSTART COMPLEXSUMEND COMPLEXTIMESSTART COMPLEXTIMESEND
%token CREATECOMPLEXSTART CREATECOMPLEXEND

%token EMPTYINCLUDEDIAGONALATT INCLUDEDIAGONALATT EMPTYTRANSPOSEATT TRANSPOSEATT

%token EMPTYIDATT IDATT

/* $Id$ */
/** @file OSParseosrl.y.2
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
 * This is the third part of the file OSParseosrl.y, containing 
 * the grammar rules involving only OSrL constructs. 
 *
 * See also the comments in OSParseosrl.y.1. 
 */

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
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}; 

osrlAttributes: | OSRLATTRIBUTETEXT;

osrlContent: osrlEmpty | osrlLaden;

osrlEmpty: ENDOFELEMENT;

osrlLaden: GREATERTHAN osrlBody osrlEnd; 

osrlEnd: osrlEnding
    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSrL input is either invalid or not well-formed.\n"); 
            osrlerror( NULL, osresult, parserData, osglData, osnlData, parserData->parser_errors);
        }
    };

osrlEnding: OSRLEND
  | { parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");};

osrlBody: 
    headerElement generalElement systemElement serviceElement jobElement optimizationElement;


/**
 * ========================================================== 
 * OSrL header 
 * ==========================================================
 */

headerElement: | osglFileHeader
{
    if (!osresult->setHeader(osglData->fileName, osglData->source,     
            osglData->description, osglData->fileCreator, osglData->licence) )    
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "setHeader failed");
};


/**
 * ========================================================== 
 * <general> element 
 * ==========================================================
 */
generalElement: | generalElementStart generalElementContent;

generalElementStart: GENERALSTART
{
    parserData->generalStatusPresent        = false;    
    parserData->generalMessagePresent       = false;
    parserData->generalServiceURIPresent    = false;
    parserData->generalServiceNamePresent   = false;
    parserData->generalInstanceNamePresent  = false;
    parserData->generalJobIDPresent         = false;
    parserData->generalSolverInvokedPresent = false;
    parserData->generalTimeStampPresent     = false;
    parserData->otherGeneralResultsPresent  = false;
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one generalStatus element allowed");    
        if (osresult->general->generalStatus != NULL) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "generalStatus previously allocated");
        parserData->generalStatusPresent = true;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        osglData->typePresent = false;
        osglData->type = "";
        osglData->descriptionPresent = false;
        osglData->description = "";
    };

generalStatusAttributes: generalStatusAttList
    {
        if (!osglData->typePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    };

generalStatusAttList: generalStatusATT | generalStatusAttList generalStatusATT;

generalStatusATT: 
    osglTypeATT
    { 
        if (osresult->setGeneralStatusType(osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "general status type does not match any legal value");
    }
  | osglDescriptionATT
    {   
        osresult->setGeneralStatusDescription(osglData->description);
    }
  | numberOfSubstatusesAttribute
    {
       if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Attempting to reallocate substatus array. Potential loss of data.");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    };

generalStatusContent: 
    generalStatusEmpty 
    {    if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <substatus> element");
    }
  | generalStatusLaden
    {    if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <substatus> elements than specified");
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
        osrlerror( NULL, NULL, parserData, osglData, osnlData, "more <substatus> elements than specified");
    osglData->namePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->description = "";
};
        
generalSubstatusAttributes: generalSubstatusAttList        
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have name attribute");
};    

generalSubstatusAttList: | generalSubstatusAttList generalSubstatusATT;
 
generalSubstatusATT: 
    osglNameATT 
    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Error while setting <general> substatus name");
    } 
  | osglDescriptionATT
    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Error while setting <general> substatus description");
    }; 

generalSubstatusEnd: GREATERTHAN SUBSTATUSEND | ENDOFELEMENT; 


generalMessage: generalMessageStart generalMessageContent;

generalMessageStart: MESSAGESTART
    {
        if (parserData->generalMessagePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one message element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceURI element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceName element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one instanceName element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one jobID element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one solverInvoked element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timeStamp element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one general other results element allowed");
        parserData->otherGeneralResultsPresent = true;
    };

otherGeneralResultsAttributes: numberOfOtherResultsAttribute 
{
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other general results cannot be negative");
    if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "Attempting to reallocate other general results array. Potential loss of data.");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherGeneralResultsContent: 
    otherGeneralResultsEmpty 
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }  
  | otherGeneralResultsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherGeneralResultAttributes: otherGeneralResultAttList
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
};    

otherGeneralResultAttList: | otherGeneralResultAttList otherGeneralResultAtt;

otherGeneralResultAtt: 
    osglNameATT
    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultName failed");
    }
  | osglValueATT
    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultValue failed");
    }
  | osglDescriptionATT
    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultDescription failed");
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

systemInformationStart:    SYSTEMINFORMATIONSTART 
    {
        if (parserData->systemInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one systemInformation element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableDiskSpace element allowed");
        parserData->systemAvailableDiskSpacePresent = true;    
        osglData->unitPresent = false;    
        osglData->unit = "byte";    
        osglData->descriptionPresent = false;
        osglData->description = "";
    };

availableDiskSpaceAttributes: availableDiskSpaceAttList;

availableDiskSpaceAttList: | availableDiskSpaceAttList availableDiskSpaceAtt;

availableDiskSpaceAtt: 
    osglUnitATT
    {
        if (osresult->setAvailableDiskSpaceUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setAvailableDiskSpaceDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableMemory element allowed");
        parserData->systemAvailableMemoryPresent = true;
        osglData->unitPresent = false;    
        osglData->unit = "byte";    
        osglData->descriptionPresent = false;
        osglData->description = "";
    };

availableMemoryAttributes: availableMemoryAttList;

availableMemoryAttList: | availableMemoryAttList availableMemoryAtt;

availableMemoryAtt: 
    osglUnitATT
    {
        if (osresult->setAvailableMemoryUnit( osglData->unit) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setAvailableMemoryDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableCPUSpeed element allowed");
        parserData->systemAvailableCPUSpeedPresent = true;
        osglData->unitPresent = false;    
        osglData->unit = "hertz";    
        osglData->descriptionPresent = false;    
        osglData->description = "";
    };

availableCPUSpeedAttributes: availableCPUSpeedAttList;

availableCPUSpeedAttList: | availableCPUSpeedAttList availableCPUSpeedAtt;

availableCPUSpeedAtt: 
    osglUnitATT
    {
        if (osresult->setAvailableCPUSpeedUnit( osglData->unit) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setAvailableCPUSpeedDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableCPUNumber element allowed");
        parserData->systemAvailableCPUNumberPresent = true;
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    };

availableCPUNumberAttributes: 
  | osglDescriptionATT
    {
        osresult->setAvailableCPUNumberDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one system other results element allowed");
        parserData->otherSystemResultsPresent = true;
    };

otherSystemResultsAttributes: numberOfOtherResultsAttribute
{
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other system results cannot be negative");
    if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSystemResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherSystemResultsContent: 
    otherSystemResultsEmpty
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherSystemResultsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherSystemResultAttributes: otherSystemResultAttList
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherSystemResultAttList: | otherSystemResultAttList otherSystemResultAtt;

otherSystemResultAtt:
    osglNameATT
    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultName failed");
    }
  | osglValueATT
    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultValue failed");
    }
  | osglDescriptionATT
    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultDescription failed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceCurrentStatePresent = true;
    };

currentStateContent: currentStateEmpty | currentStateLaden;

currentStateEmpty: GREATERTHAN CURRENTSTATEEND | ENDOFELEMENT;

currentStateLaden: GREATERTHAN currentStateBody CURRENTSTATEEND;

currentStateBody:  ELEMENTTEXT  
    {
       parserData->tempStr = $1; free($1);
        if (osresult->setCurrentState(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setCurrentState failed; current system state not recognized");
        parserData->errorText = NULL;
    };

currentJobCount: currentJobCountStart currentJobCountContent;

currentJobCountStart: CURRENTJOBCOUNTSTART
    {
        if (parserData->serviceCurrentJobCountPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one currentJobCount element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one totalJobsSoFar element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timeServiceStarted element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceUtilization element allowed");
        parserData->serviceUtilizationPresent = true;
    };

serviceUtilizationContent: serviceUtilizationEmpty | serviceUtilizationLaden;

serviceUtilizationEmpty: GREATERTHAN SERVICEUTILIZATIONEND | ENDOFELEMENT;

serviceUtilizationLaden: GREATERTHAN serviceUtilizationBody SERVICEUTILIZATIONEND;

serviceUtilizationBody:  aNumber  
{
    if (osresult->setServiceUtilization( parserData->tempVal) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceUtilization failed");
    parserData->errorText = NULL;
};

otherServiceResults: otherServiceResultsStart otherServiceResultsAttributes otherServiceResultsContent;

otherServiceResultsStart: OTHERRESULTSSTART
    {
        if (parserData->otherServiceResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one service other results element allowed");
        parserData->otherServiceResultsPresent = true;
    };

otherServiceResultsAttributes: numberOfOtherResultsAttribute
{
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other service results cannot be negative");
    if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherServiceResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherServiceResultsContent: 
    otherServiceResultsEmpty
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherServiceResultsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherServiceResultAttributes: otherServiceResultAttList
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherServiceResultAttList: | otherServiceResultAttList otherServiceResultAtt;

otherServiceResultAtt: 
    osglNameATT
    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultName failed");
    }
  | osglValueATT
    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultValue failed");
    }
  | osglDescriptionATT
    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultDescription failed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job status element allowed");
        parserData->jobStatusPresent = true;
    };

jobStatusContent: jobStatusEmpty | jobStatusLaden;

jobStatusEmpty: GREATERTHAN STATUSEND | ENDOFELEMENT;

jobStatusLaden: GREATERTHAN jobStatusBody STATUSEND;

jobStatusBody:  ELEMENTTEXT  
    {
        parserData->tempStr = $1; free($1);
        if (osresult->setJobStatus(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobStatus failed");
        parserData->errorText = NULL;
    };

submitTime: submitTimeStart submitTimeContent;

submitTimeStart: SUBMITTIMESTART 
    {
        if (parserData->jobSubmitTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one submitTime element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one scheduledStartTime element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one actualStartTime element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job endTime element allowed");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timingInformation element allowed");
        parserData->jobTimingInformationPresent = true;
    };

timingInformationAttributes: numberOfTimesAttribute 
{
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of time measurements cannot be negative");
    if (osresult->setNumberOfTimes(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfTimes failed");
    parserData->numberOfTimes = parserData->tempInt;
    parserData->ivar = 0;
};

timingInformationContent: 
    timingInformationEmpty 
    {
        if (parserData->numberOfTimes > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <time> element");
    }
  | timingInformationLaden
    {
        if (parserData->ivar != parserData->numberOfTimes)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <time> elements than specified");
    };

timingInformationEmpty: GREATERTHAN TIMINGINFORMATIONEND | ENDOFELEMENT;   

timingInformationLaden: GREATERTHAN timingInformationBody TIMINGINFORMATIONEND;

timingInformationBody:  timeArray;

timeArray: time | timeArray time;

time: timeStart timeAttributes timeContent;

timeStart: TIMESTART
{
    if (parserData->ivar >= parserData->numberOfTimes)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <time> elements than specified");
    osglData->unitPresent = false;
    osglData->typePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->unit = "second";
    osglData->type = "elapsedTime";
    osglData->category = "total";
    osglData->description = "";
};

timeAttributes: | timeAttributes timeAtt;

timeAtt: 
    osglUnitATT | osglTypeATT | osglCategoryATT | osglDescriptionATT;


timeContent: timeEmpty | timeLaden;

timeEmpty: GREATERTHAN TIMEEND | ENDOFELEMENT;

timeLaden: GREATERTHAN timeBody TIMEEND;

timeBody:  timeValue 
{    
    if (osresult->setTimingInformation(parserData->ivar, osglData->type, osglData->category,
        osglData->unit, osglData->description, parserData->timeValue) == false)       
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "timing information could not be stored");
    parserData->ivar++;
}; 

timeValue:
    DOUBLE  { parserData->timeValue = $1; }
  | INTEGER { parserData->timeValue = $1; };


usedDiskSpace: usedDiskSpaceStart usedDiskSpaceAttributes usedDiskSpaceContent;

usedDiskSpaceStart: USEDDISKSPACESTART
    {
        if (parserData->jobUsedDiskSpacePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedDiskSpace element allowed");
        parserData->jobUsedDiskSpacePresent = true;        
        osglData->unitPresent = false;    
        osglData->unit = "byte";
        osglData->descriptionPresent = false;
        osglData->description = "";
    };
    
usedDiskSpaceAttributes: usedDiskSpaceAttList;

usedDiskSpaceAttList: | usedDiskSpaceAttList usedDiskSpaceAtt;

usedDiskSpaceAtt: 
    osglUnitATT
    {
        if (osresult->setUsedDiskSpaceUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setUsedDiskSpaceDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedMemory element allowed");
        parserData->jobUsedMemoryPresent = true;
        osglData->unitPresent = false;    
        osglData->unit = "byte";
        osglData->descriptionPresent = false;    
        osglData->description = "";
    };
    
usedMemoryAttributes: usedMemoryAttList;
            
usedMemoryAttList: | usedMemoryAttList usedMemoryAtt;

usedMemoryAtt: 
    osglUnitATT
    {
        if (osresult->setUsedMemoryUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setUsedMemoryDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedCPUSpeed element allowed");
        parserData->jobUsedCPUSpeedPresent = true;
        osglData->unitPresent = false;    
        osglData->unit = "hertz";    
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    };
              
usedCPUSpeedAttributes: usedCPUSpeedAttList;
    
usedCPUSpeedAttList: | usedCPUSpeedAttList usedCPUSpeedAtt;

usedCPUSpeedAtt: 
    osglUnitATT
    {
        if (osresult->setUsedCPUSpeedUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
  | osglDescriptionATT
    {
        osresult->setUsedCPUSpeedDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedCPUNumber element allowed");
        parserData->jobUsedCPUNumberPresent = true;
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    };
               

usedCPUNumberAttributes: 
  | osglDescriptionATT
    {
        osresult->setUsedCPUNumberDescription( osglData->description); 
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job other results element allowed");
        parserData->otherJobResultsPresent = true;
    };

otherJobResultsAttributes: numberOfOtherResultsAttribute 
{
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other job results cannot be negative");
    if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherJobResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherJobResultsContent: 
    otherJobResultsEmpty
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherJobResultsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
};

otherJobResultAttributes: otherJobResultAttList
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
};

otherJobResultAttList: | otherJobResultAttList otherJobResultAtt;

otherJobResultAtt: 
    osglNameATT
    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultName failed");
    }
 | osglValueATT
    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultValue failed");
    }
 | osglDescriptionATT
    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultDescription failed");
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
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions was never set");
};    

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
    numberOfSolutionsAttribute 
    {
        parserData->numberOfSolutions = parserData->tempInt; 
        if (osresult->setSolutionNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionNumber failed");
        parserData->solutionIdx = 0;
    }
  | osglNumberOfVariablesATT 
    {
        if (osresult->setVariableNumber(osglData->numberOfVariables) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVariableNumber failed");
    }             
  | osglNumberOfConstraintsATT 
    {
        if (osresult->setConstraintNumber(osglData->numberOfConstraints) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setConstraintNumber failed");
    } 
  | osglNumberOfObjectivesATT 
    {    
        if (osresult->setObjectiveNumber(osglData->numberOfObjectives) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setObjectiveNumber failed");
    };
    
optimizationContent: 
    optimizationEmpty 
    {
        if (parserData->numberOfSolutions > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solution> element");
    }
  | optimizationLaden
    {
        if (parserData->solutionIdx != parserData->numberOfSolutions)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solution> elements than specified");
    };

optimizationEmpty: GREATERTHAN OPTIMIZATIONEND | ENDOFELEMENT;

optimizationLaden: GREATERTHAN optimizationBody OPTIMIZATIONEND;

optimizationBody:  solutionArray otherSolverOutput;

solutionArray: solution | solutionArray solution;  

solution: solutionStart solutionAttributes solutionContent;

solutionStart: SOLUTIONSTART
{
    if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "too many solutions"); 
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective idx previously set");
    parserData->idxAttributePresent = true;
    if($3 >= 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, $3) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveIdx failed");
 };

targetObjectiveNameATT: TARGETOBJECTIVENAMEATT ATTRIBUTETEXT quote
{
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = $2; free($2);
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveName failed");
 };

weightedObjectivesATT: WEIGHTEDOBJECTIVESATT ATTRIBUTETEXT quote
{
    if (parserData->weightedObjAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "weighted objective attribute previously set");
    parserData->weightedObjAttributePresent = true;
    parserData->tempStr = $2; free($2);
    if (parserData->tempStr == "true" || parserData->tempStr == "1")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionWeightedObjectives failed");
    }
    else if (parserData->tempStr == "false" || parserData->tempStr == "0")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionWeightedObjectives failed");
    }
    else
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "weightedobjectives must be true or false");
};

solutionContent: GREATERTHAN solutionStatus solutionMessage
          variables objectives constraints matrixProgramming otherSolutionResults SOLUTIONEND
    {
        parserData->solutionIdx++;
    };

solutionStatus: solutionStatusStart solutionStatusAttributes solutionStatusContent;

solutionStatusStart: STATUSSTART
    {
        osglData->typePresent = false;
        osglData->type = "";
        osglData->description = "";
        osglData->descriptionPresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
    };

solutionStatusAttributes: solutionStatusAttList
    {
        if (!osglData->typePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for solution status element");
    };

solutionStatusAttList: solutionStatusATT | solutionStatusAttList solutionStatusATT;

solutionStatusATT: 
    osglTypeATT
    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionStatusType failed");
    }
  | osglDescriptionATT
    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionStatusDescription failed");
    }
  | numberOfSubstatusesAttribute
    {
        if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolutionSubstatuses failed");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    };
    
  
solutionStatusContent: 
    solutionStatusEmpty 
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <substatus> element");
    }
  | solutionStatusLaden
    {
        if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <substatus> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <substatus> elements than specified");
    osglData->typePresent = false;
    osglData->type = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
};

solutionSubstatusAttributes: solutionSubstatusAttList
{
    if (!osglData->typePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have type attribute");
};    

solutionSubstatusAttList: | solutionSubstatusAttList solutionSubstatusATT;
 
solutionSubstatusATT: 
    osglTypeATT
    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionSubstatusType failed");
    }; 
  | osglDescriptionATT
    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionSubstatusDescription failed");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherVariableResults failed");
    parserData->numberOfOtherVariableResults = parserData->tempInt;
    parserData->iOther = 0;
};

variablesContent: variablesEmpty | variablesLaden;

variablesEmpty: ENDOFELEMENT;

variablesLaden: GREATERTHAN variablesBody VARIABLESEND;

variablesBody:  variableValues variableValuesString variableBasisStatus otherVariableResultsArray;

variableValues: | variableValuesStart numberOfVarATT variableValuesContent;

variableValuesStart: VALUESSTART
{
    osglData->numberOfVarPresent = false;
};

numberOfVarATT: osglNumberOfVarATT
{
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, osglData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}; 

variableValuesContent: 
    variableValuesEmpty 
    {
        if (osglData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
  | variableValuesLaden
    {
        if (parserData->kounter != osglData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    };
 
variableValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

variableValuesLaden: GREATERTHAN variableValuesBody VALUESEND;

variableValuesBody:   varValueArray;

varValueArray: varValue | varValueArray varValue;

varValue: varValueStart varValueAttList varValueContent
{
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
                              osglData->idx, osglData->name, parserData->tempVal) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValue failed");
    parserData->kounter++;
}; 

varValueStart: VARSTART
{    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
};

varValueAttList: | varValueAttList varValueAtt;

varValueAtt:
    osglIdxATT
  | osglNameATT
  ;

varValueContent: GREATERTHAN aNumber VAREND;
  

variableValuesString: | variableValuesStringStart numberOfVarStringATT variableValuesStringContent;

variableValuesStringStart: VALUESSTRINGSTART
{
    osglData->numberOfVarPresent = false;
};

numberOfVarStringATT: osglNumberOfVarATT
{
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, osglData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}; 

variableValuesStringContent: 
    variableValuesStringEmpty 
    {
        if (osglData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
  | variableValuesStringLaden
    {
        if (parserData->kounter != osglData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    };

variableValuesStringEmpty: GREATERTHAN VALUESSTRINGEND | ENDOFELEMENT; 

variableValuesStringLaden: GREATERTHAN variableValuesStringBody VALUESSTRINGEND;

variableValuesStringBody:  varValueStringArray;

varValueStringArray: varValueString | varValueStringArray varValueString;

varValueString: varValueStringStart varValueStringAttList varValueStringContent
{
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
                                    osglData->idx, osglData->name, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValueString failed");
    parserData->kounter++;
}; 

varValueStringStart: VARSTART 
{    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
};

varValueStringAttList: | varValueStringAttList varValueStringAtt;

varValueStringAtt:
    osglIdxATT
  | osglNameATT
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

variablesBasic: | osglBasisStatusBasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesAtLower: | osglBasisStatusAtLower
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesAtUpper: | osglBasisStatusAtUpper
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesAtEquality: | osglBasisStatusAtEquality
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesIsFree: | osglBasisStatusIsFree
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesSuperbasic: | osglBasisStatusSuperbasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

variablesUnknown: | osglBasisStatusUnknown
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};


otherVariableResultsArray: | otherVariableResultsArray otherVariableResult;

otherVariableResult: otherVariableResultStart otherVariableResultAttributes otherVariableResultContent
    {      
        parserData->iOther++;
    };

otherVariableResultStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherVariableResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfVarPresent = false;    
    osglData->varTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->varType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
}; 

otherVariableResultAttributes: otherVariableResultAttList 
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    };
      
otherVariableResultAttList: | otherVariableResultAttList otherVariableResultATT;

otherVariableResultATT: 
    osglNumberOfVarATT 
    {
        if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
                                                        parserData->iOther, 
                                                        osglData->numberOfVar) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData,
                "setOtherVariableResultNumberOfVar failed");
        parserData->kounter = 0;
    } 
  | osglNumberOfEnumerationsATT
    {
        if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }  
  | osglValueATT
    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultValue failed");
    }
  | osglSolverATT
    {    
         if (osresult->setOtherVariableResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultSolver failed");
    }
  | osglNameATT 
    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultName failed");
    }
  | osglTypeATT
    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultType failed");
    }
  | osglVarTypeATT
    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->varType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarType failed");
    }
  | osglEnumTypeATT
    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultEnumType failed");
    }
  | osglDescriptionATT
    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultDescription failed");
    };
  
otherVariableResultContent: otherVariableResultEmpty | otherVariableResultLaden;

otherVariableResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableResultLaden: GREATERTHAN otherVariableResultBody OTHEREND;

otherVariableResultBody:  otherVarList | otherVarEnumerationList;

otherVarList: otherVar | otherVarList otherVar;

otherVar: otherVarStart otherVarAttList otherVarContent 
{     
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
};

otherVarStart: VARSTART
{    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = ""    ;
};

otherVarAttList: | otherVarAttList otherVarAtt;

otherVarAtt:
    osglIdxATT
    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarIdx failed");
    }
  | osglNameATT
    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarName failed");
    };

otherVarContent: otherVarEmpty | otherVarLaden;

otherVarEmpty: GREATERTHAN VAREND | ENDOFELEMENT;

otherVarLaden: GREATERTHAN otherVarBody VAREND;

otherVarBody:  ElementValue  
    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVar failed");
    };


otherVarEnumerationList: otherVarEnumeration | otherVarEnumerationList otherVarEnumeration;

otherVarEnumeration: otherVarEnumerationStart otherVarEnumerationAttributes otherVarEnumerationContent 
{     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->kounter++;
};

otherVarEnumerationStart: ENUMERATIONSTART
{
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
};    

otherVarEnumerationAttributes: otherVarEnumerationAttList 
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    };
      
otherVarEnumerationAttList: | otherVarEnumerationAttList otherVarEnumerationATT;

otherVarEnumerationATT: 
    osglNumberOfElATT 
    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
};

objectivesContent: objectivesEmpty | objectivesLaden;

objectivesEmpty: ENDOFELEMENT;

objectivesLaden: GREATERTHAN objectivesBody OBJECTIVESEND;

objectivesBody:  objectiveValues objectiveBasisStatus otherObjectiveResultsArray;

objectiveValues: | objectiveValuesStart numberOfObjATT objectiveValuesContent;

objectiveValuesStart: VALUESSTART
{
    osglData->numberOfObjPresent = false;
};

numberOfObjATT: osglNumberOfObjATT
{
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, osglData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}; 

objectiveValuesContent: 
    objectiveValuesEmpty 
    {
        if (osglData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <obj> element");
    }
  | objectiveValuesLaden
    {
        if (parserData->kounter != osglData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <obj> elements than specified");
    };
 
objectiveValuesEmpty: GREATERTHAN VALUESEND | ENDOFELEMENT; 

objectiveValuesLaden: GREATERTHAN objectiveValuesBody VALUESEND;

objectiveValuesBody:   objValueArray;


objValueArray: objValue | objValueArray objValue;

objValue: objValueStart objValueAttList objValueContent
{
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              osglData->idx, osglData->name, parserData->tempVal) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setObjValue failed");
    parserData->kounter++;
}; 

objValueStart: OBJSTART
{    
    if (parserData->kounter >= osglData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    osglData->idxPresent = false;
    osglData->idx = -1;
    osglData->namePresent = false;
    osglData->name = ""    ;
};

objValueAttList: | objValueAttList objValueAtt;

objValueAtt:
    osglIdxATT
  | osglNameATT
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

objectivesBasic: | osglBasisStatusBasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesAtLower: | osglBasisStatusAtLower
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesAtUpper: | osglBasisStatusAtUpper
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesAtEquality: | osglBasisStatusAtEquality
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesIsFree: | osglBasisStatusIsFree
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesSuperbasic: | osglBasisStatusSuperbasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

objectivesUnknown: | osglBasisStatusUnknown
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};


otherObjectiveResultsArray: | otherObjectiveResultsArray otherObjectiveResult;

otherObjectiveResult: otherObjectiveResultStart otherObjectiveResultAttributes otherObjectiveResultContent
    {      
        parserData->iOther++;  
    }
;

otherObjectiveResultStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherObjectiveResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfObjPresent = false;    
    osglData->objTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->objType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
};

otherObjectiveResultAttributes: otherObjectiveResultAttList
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    };


otherObjectiveResultAttList: | otherObjectiveResultAttList otherObjectiveResultATT;

otherObjectiveResultATT: 
    osglNumberOfObjATT 
    {
        if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfObj failed");
        parserData->kounter = 0;
    }
  | osglNumberOfEnumerationsATT
    {
        if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }  
  | osglValueATT 
    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultValue failed");
    }
  | osglSolverATT
    {    
         if (osresult->setOtherObjectiveResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                     osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultSolver failed");
    }
  | osglNameATT
    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultName failed");
    }
  | osglTypeATT
    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultType failed");
    }
  | osglObjTypeATT
    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->objType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjType failed");
    }
  | osglEnumTypeATT
    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultEnumType failed");
    }
  | osglDescriptionATT
    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultDescription failed");
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
    if (parserData->kounter >= osglData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    osglData->idxPresent = false;
    osglData->idx = -1;    
    osglData->namePresent = false;
    osglData->name = ""    ;
};

otherObjAttList: | otherObjAttList otherObjAtt;

otherObjAtt:
    osglIdxATT
    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjIdx failed");
    }
  | osglNameATT
    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjName failed");
    };

otherObjContent: otherObjEmpty | otherObjLaden;

otherObjEmpty: GREATERTHAN OBJEND | ENDOFELEMENT;

otherObjLaden: GREATERTHAN otherObjBody OBJEND;

otherObjBody:  ElementValue  
    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObj failed");
    };


otherObjEnumerationList: otherObjEnumeration | otherObjEnumerationList otherObjEnumeration;

otherObjEnumeration: otherObjEnumerationStart otherObjEnumerationAttributes otherObjEnumerationContent 
{     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other objective option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
};

otherObjEnumerationStart: ENUMERATIONSTART
{
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->value = "";
    osglData->description = "";
};    

otherObjEnumerationAttributes: otherObjEnumerationAttList 
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    };
      
otherObjEnumerationAttList: | otherObjEnumerationAttList otherObjEnumerationATT;

otherObjEnumerationATT: 
    osglNumberOfElATT
    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
};

constraintsContent: constraintsEmpty | constraintsLaden;

constraintsEmpty: ENDOFELEMENT;

constraintsLaden: GREATERTHAN constraintsBody CONSTRAINTSEND;

constraintsBody:  dualValues slackBasisStatus otherConstraintResultsArray;

dualValues: | dualValuesStart numberOfConAttribute dualValuesContent;

dualValuesStart: DUALVALUESSTART
{
    osglData->numberOfConPresent = false;
};

numberOfConAttribute: osglNumberOfConATT
{
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, osglData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
};

dualValuesContent:
    dualValuesEmpty 
    {
        if (osglData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <con> element");
    }
  | dualValuesLaden
    {
        if (parserData->kounter != osglData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <con> elements than specified");
    };

dualValuesEmpty: GREATERTHAN DUALVALUESEND | ENDOFELEMENT; 

dualValuesLaden: GREATERTHAN dualValuesBody DUALVALUESEND;

dualValuesBody:  dualValueArray;

dualValueArray: dualValue | dualValueArray dualValue;

dualValue: dualValueStart dualValueAttList dualValueContent 
{
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               osglData->idx, osglData->name, parserData->tempVal ) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setDualValue failed");
    parserData->kounter++;
}; 

dualValueStart: CONSTART
{    
    if (parserData->kounter >= osglData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
};

dualValueAttList: | dualValueAttList dualValueAtt;

dualValueAtt:
    osglIdxATT
  | osglNameATT
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

slacksBasic: | osglBasisStatusBasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksAtLower: | osglBasisStatusAtLower
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksAtUpper: | osglBasisStatusAtUpper
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksAtEquality: | osglBasisStatusAtEquality
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksIsFree: | osglBasisStatusIsFree
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksSuperbasic: | osglBasisStatusSuperbasic
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

slacksUnknown: | osglBasisStatusUnknown
{
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
};

                         
otherConstraintResultsArray: | otherConstraintResultsArray otherConstraintResult;

otherConstraintResult: otherConstraintResultStart otherConstraintResultAttributes otherConstraintResultContent
    {      
        parserData->iOther++;  
    }
;

otherConstraintResultStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherConstraintResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfConPresent = false;    
    osglData->conTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->conType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
}; 

otherConstraintResultAttributes: otherConstraintResultAttList
    {
        if (!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    };

otherConstraintResultAttList: | otherConstraintResultAttList otherConstraintResultATT;

otherConstraintResultATT: 
    osglNumberOfConATT
    {
        if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          osglData->numberOfCon) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfCon failed");
        parserData->kounter = 0;
    } 
  | osglNumberOfEnumerationsATT
    {
        if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }  
  | osglValueATT
    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultValue failed");
    }
  | osglSolverATT
    {    
         if (osresult->setOtherConstraintResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                      osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultSolver failed");
    }
  | osglNameATT
    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultName failed");
    }
  | osglTypeATT
    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultType failed");
    }
  | osglConTypeATT
    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->conType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConType failed");
    }
  | osglEnumTypeATT
    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultEnumType failed");
    }
  | osglDescriptionATT
    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultDescription failed");
    };
  
otherConstraintResultContent: otherConstraintResultEmpty | otherConstraintResultLaden;

otherConstraintResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT    

otherConstraintResultLaden: GREATERTHAN otherConstraintResultBody OTHEREND;

otherConstraintResultBody:  otherConList | otherConEnumerationList;

otherConList: otherCon | otherConList otherCon;

otherCon: otherConStart otherConAttList otherConContent 
{     
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
};
  
otherConStart: CONSTART
{    
    if (parserData->kounter >= osglData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = ""    ;
};

otherConAttList: | otherConAttList otherConAtt;


otherConAtt:
    osglIdxATT
    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, osglData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConIdx failed");
    }
  | osglNameATT
    {
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                       parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConName failed");
    }
  ;

otherConContent: otherConEmpty | otherConLaden;

otherConEmpty: GREATERTHAN CONEND | ENDOFELEMENT;

otherConLaden: GREATERTHAN otherConBody CONEND;

otherConBody:  ElementValue  
    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther,
                parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultCon failed");
    };


otherConEnumerationList: otherConEnumeration | otherConEnumerationList otherConEnumeration;

otherConEnumeration: otherConEnumerationStart otherConEnumerationAttributes otherConEnumerationContent 
{     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other constraint option failed");
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
};

otherConEnumerationStart: ENUMERATIONSTART
{
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
};    

otherConEnumerationAttributes: otherConEnumerationAttList 
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    };
      
otherConEnumerationAttList: | otherConEnumerationAttList otherConEnumerationATT;

otherConEnumerationATT: 
    osglNumberOfElATT
    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
  ;


otherConEnumerationContent: otherConEnumerationEmpty | otherConEnumerationLaden;

otherConEnumerationEmpty: ENDOFELEMENT;

otherConEnumerationLaden: GREATERTHAN otherConEnumerationBody ENUMERATIONEND;

otherConEnumerationBody:  osglIntArrayData;  


matrixProgramming: | matrixProgrammingStart matrixProgrammingAttributes matrixProgrammingContent; 
        
matrixProgrammingStart: MATRIXPROGRAMMINGSTART
{
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        = new MatrixProgrammingSolution();
};

matrixProgrammingAttributes: | numberOfOtherMatrixProgrammingResultsATT
{
    parserData->numberOfOtherMatrixProgrammingResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->numberOfOtherMatrixProgrammingResults = parserData->tempInt;
};


matrixProgrammingContent: matrixProgrammingEmpty | matrixProgrammingLaden;

matrixProgrammingEmpty: ENDOFELEMENT;

matrixProgrammingLaden: GREATERTHAN  matrixVariables /*matrixObjectives matrixConstraints*/
                        otherMatrixProgrammingResults MATRIXPROGRAMMINGEND;

matrixVariables: | matrixVariablesStart matrixVariablesAttributes matrixVariablesContent
    {
        if (osglData->matrixCounter < osglData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                "actual number of matrixVar less than number attribute");   
    };


matrixVariablesStart: MATRIXVARIABLESSTART
{
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        = new MatrixVariableSolution(); 
};

matrixVariablesAttributes: numberOfOtherMatrixVariableResultsATT
{
    parserData->numberOfOtherMatrixVariableResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->numberOfOtherMatrixVariableResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->other = new OtherMatrixVariableResult*[parserData->tempInt];
    for (int i=0; i < parserData->tempInt; i++)
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[i] = NULL;
    parserData->iOther = 0;
};

matrixVariablesContent: matrixVariablesEmpty | matrixVariablesLaden;

matrixVariablesEmpty: ENDOFELEMENT;

matrixVariablesLaden: GREATERTHAN matrixVariableValues otherMatrixVariableResults matrixVariablesEnd;

matrixVariablesEnd: MATRIXVARIABLESEND;

matrixVariableValues: | matrixVariableValuesStart matrixVariableValuesAttributes
                        matrixVariableValuesContent;

matrixVariableValuesStart: VALUESSTART
{
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables->values
        = new MatrixVariableValues();
    osglData->numberOfMatrixVarPresent = false;
};

matrixVariableValuesAttributes: osglNumberOfMatrixVarATT
{
    osglData->numberOfMatrixVar = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->matrixVariables->values->numberOfMatrixVar = parserData->tempInt;

    osglData->matrixWithMatrixVarIdx = new OSMatrixWithMatrixVarIdx*[parserData->tempInt];
    for (int i=0; i < parserData->tempInt; i++)
        osglData->matrixWithMatrixVarIdx[i] = NULL;
    osglData->matrixCounter = 0;
};

matrixVariableValuesContent: matrixVariableValuesEmpty | matrixVariableValuesLaden;

matrixVariableValuesEmpty: ENDOFELEMENT;

matrixVariableValuesLaden: GREATERTHAN matrixVarList matrixVariableValuesEnd;

matrixVariableValuesEnd: VALUESEND
{
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->matrixVariables->values->matrixVar = osglData->matrixWithMatrixVarIdx;
};

matrixVarList: | matrixVarList osglMatrixWithMatrixVarIdx;

otherMatrixVariableResults: | otherMatrixVariableResults otherMatrixVariableResult;

otherMatrixVariableResult: otherMatrixVariableResultStart otherMatrixVariableResultAttributes
                           otherMatrixVariableResultContent
    {      
        parserData->iOther++;
    };

otherMatrixVariableResultStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherMatrixVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherMatrixVariableResults> than specified");
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->other[parserData->iOther] = new OtherMatrixVariableResult();

    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->numberOfMatrixVarPresent = false;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->matrixVarTypePresent = false;
    osglData->enumTypePresent = false;
    osglData->matrixVarType = "";
    osglData->enumType = "";

    osglData->matrixCounter = 0; 
};

otherMatrixVariableResultAttributes: otherMatrixVariableResultAttList
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, 
                "<other> element requires name attribute"); 
    };
      
otherMatrixVariableResultAttList: | otherMatrixVariableResultAttList otherMatrixVariableResultATT;

otherMatrixVariableResultATT: 
    osglNumberOfMatrixVarATT 
    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->numberOfMatrixVar = osglData->numberOfMatrixVar;
    
        osglData->matrixWithMatrixVarIdx = new OSMatrixWithMatrixVarIdx*[osglData->numberOfMatrixVar];
        for (int i=0; i < parserData->tempInt; i++)
            osglData->matrixWithMatrixVarIdx[i] = NULL;
        osglData->matrixCounter = 0;
    } 
  | osglNumberOfEnumerationsATT
    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->numberOfEnumerations = osglData->numberOfEnumerations;
        parserData->kounter = 0;
    }  
  | osglValueATT
    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->value = osglData->value;
    }
  | osglSolverATT
    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->solver = osglData->solver;
    }
  | osglNameATT 
    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->name = osglData->name;
    }
  | osglTypeATT
    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->type = osglData->type;
    }
  | osglMatrixVarTypeATT 
    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->matrixType = osglData->matrixVarType;
    }
  | osglEnumTypeATT 
    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->enumType = osglData->enumType;
    }
  | osglDescriptionATT
    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->description = osglData->description;
    };


otherMatrixVariableResultContent: otherMatrixVariableResultEmpty | otherMatrixVariableResultLaden;

otherMatrixVariableResultEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherMatrixVariableResultLaden: GREATERTHAN otherMatrixVariableResultBody OTHEREND;

otherMatrixVariableResultBody:  
    otherMatrixVarEnumerationList
  | otherMatrixVarList 
    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->matrixVar = osglData->matrixWithMatrixVarIdx;
    };

otherMatrixVarList: osglMatrixWithMatrixVarIdx | otherMatrixVarList osglMatrixWithMatrixVarIdx;


otherMatrixVarEnumerationList: otherMatrixVarEnumeration 
                             | otherMatrixVarEnumerationList otherMatrixVarEnumeration;

otherMatrixVarEnumeration: otherMatrixVarEnumerationStart otherMatrixVarEnumerationAttributes 
                           otherMatrixVarEnumerationContent 
{     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
};

otherMatrixVarEnumerationStart: ENUMERATIONSTART
{
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
};    

otherMatrixVarEnumerationAttributes: otherMatrixVarEnumerationAttList 
    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    };
      
otherMatrixVarEnumerationAttList: | otherMatrixVarEnumerationAttList otherMatrixVarEnumerationATT;

otherMatrixVarEnumerationATT: 
    osglNumberOfElATT
    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    } 
  | osglValueATT
  | osglDescriptionATT
  ;


otherMatrixVarEnumerationContent: otherMatrixVarEnumerationEmpty | otherMatrixVarEnumerationLaden;

otherMatrixVarEnumerationEmpty: ENDOFELEMENT;

otherMatrixVarEnumerationLaden: GREATERTHAN otherMatrixVarEnumerationBody ENUMERATIONEND;

otherMatrixVarEnumerationBody:  osglIntArrayData;  

/*
---------------------ditto for matrixObjectives and matrixConstraints (to be completed)
*/


otherMatrixProgrammingResults: | otherMatrixProgrammingResults otherMatrixProgrammingResult;

otherMatrixProgrammingResult: OTHERMATRIXPROGRAMMINGRESULTSTART
{
    parserData->numberOf = 0; 
};

otherSolutionResults: | otherSolutionResultsStart numberOfOtherSolutionResults otherSolutionResultsContent;

otherSolutionResultsStart: OTHERSOLUTIONRESULTSSTART
{
    parserData->numberOf = 0; 
};

numberOfOtherSolutionResults: numberOfOtherSolutionResultsAttribute
{    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
};

otherSolutionResultsContent:
    otherSolutionResultsEmpty 
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <otherSolutionResult> element");
    }
  | otherSolutionResultsLaden
    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <otherSolutionResult> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherSolutionResult> elements than specified");
    osglData->numberOfItemsPresent = false; 
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->category = "";
    osglData->description = "";
    osglData->numberOfItems = 0;
};

otherSolutionResultAttributes: otherSolutionResultAttList 
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have numberOfItems attribute");
};    

otherSolutionResultAttList: | otherSolutionResultAttList otherSolutionResultAtt;

otherSolutionResultAtt: 
    osglNameATT
    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultName failed");
    } 
  | osglValueATT
    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                  osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultValuee failed");
    } 
  | osglCategoryATT
    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     osglData->category) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultCategory failed");
    } 
  | osglDescriptionATT
    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
                                                        osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultDescription failed");
    }
  | osglNumberOfItemsATT
    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          osglData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    };

otherSolutionResultContent:
    otherSolutionResultEmpty
    {
        if (osglData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
  | otherSolutionResultLaden
    {
        if (parserData->kounter != osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
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
        if (parserData->kounter >= osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
  | otherSolutionResultItemLaden; 

otherSolutionResultItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

otherSolutionResultItemLaden: ITEMSTART otherSolutionResultItemBody ITEMEND;

otherSolutionResultItemBody:  ITEMTEXT 
{
    if (parserData->kounter >= osglData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = $1; free($1);
    if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
                                             parserData->kounter, parserData->itemContent) 
                                                 == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultItem failed");
};


otherSolverOutput: | otherSolverOutputStart numberOfSolverOutputsATT otherSolverOutputContent;

otherSolverOutputStart: OTHERSOLVEROUTPUTSTART
{
    parserData->numberOf = 0; 
};

numberOfSolverOutputsATT: numberOfSolverOutputsAttribute
{    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
};

otherSolverOutputContent: 
    otherSolverOutputEmpty 
    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solverOutput> element");
    }
  | otherSolverOutputLaden
    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solverOutput> elements than specified");
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
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <solverOutput> elements than specified");
    osglData->numberOfItemsPresent = false; 
    osglData->namePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->category = "";
    osglData->description = "";
};

solverOutputAttributes: solverOutputAttList
{
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have name attribute");
    if (!osglData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have numberOfItems attribute");
};    

solverOutputAttList: | solverOutputAttList solverOutputAtt;

solverOutputAtt: 
     osglNameATT
    {    
        if (osresult->setSolverOutputName(parserData->iOther, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputName failed");
    } 
  | osglCategoryATT
    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, osglData->category) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputCategory failed");
    } 
  | osglDescriptionATT
    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputDescription failed");
    }
  | osglNumberOfItemsATT
    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, osglData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    };

solverOutputContent: 
    solverOutputEmpty 
    {
        if (osglData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
  | solverOutputLaden
    {
        if (parserData->kounter != osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
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
        if (parserData->kounter >= osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }    
  | solverOutputItemLaden; 
    
solverOutputItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOutputItemLaden: ITEMSTART solverOutputItemBody ITEMEND;

solverOutputItemBody:  ITEMTEXT 
{
    if (parserData->kounter >= osglData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = $1; free($1);
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputItem failed");
};

/*
categoryAttribute: categoryAtt
    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one category attribute allowed for this element");
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
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one description attribute allowed for this element");
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
*/
/*
enumTypeAttribute: enumTypeAtt
    {
        if (osglData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
        osglData->enumTypeAttributePresent = true;
    };

enumTypeAtt: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ 
    osglData->enumTypeAttribute = ""; 
};

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT quote 
{ 
    osglData->enumTypeAttribute = $2; free($2);
};


matrixVarTypeAttribute: MATRIXVARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;
    osglData->matrixVarType = $2; 
    free($2);
};
*/

/*
idxAttribute: IDXATT quote INTEGER quote 
    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = $3; 
    };

nameAttribute: nameAtt
    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one name attribute allowed for this element");
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
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
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

solverAttribute: solverAtt
    {
        if (parserData->solverAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    };

solverAtt: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{
    parserData->solverAttribute = ""; 
};

solverAttContent: SOLVERATT ATTRIBUTETEXT quote 
{
    parserData->solverAttribute = $2; free($2);
};

typeAttribute: typeAtt
    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one type attribute allowed for this element");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
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
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one value attribute allowed for this element");
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
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
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
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfCon = $3;
};
*/
numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = $3; 
};
/*
numberOfElAttribute: NUMBEROFELATT quote INTEGER quote 
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <el> cannot be negative");
    parserData->numberOf = $3; 
}; 

numberOfEnumerationsAttribute: NUMBEROFENUMERATIONSATT quote INTEGER quote 
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    osglData->numberOfEnumerations = $3; 
}; 

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = $3;
};

numberOfMatrixVarAttribute: NUMBEROFMATRIXVARATT quote INTEGER quote
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData,
        "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVar = $3;
}; 

numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObj = $3;
}; 

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = $3; 
};
*/
numberOfOtherConstraintResultsAttribute: NUMBEROFOTHERCONSTRAINTRESULTSATT quote INTEGER quote 
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other constraint results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherMatrixProgrammingResultsATT: NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT quote INTEGER quote
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix programming results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherMatrixVariableResultsATT: NUMBEROFOTHERMATRIXVARIABLERESULTSATT quote INTEGER quote
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix variable results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherObjectiveResultsAttribute: NUMBEROFOTHEROBJECTIVERESULTSATT quote INTEGER quote 
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other objective results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherResultsAttribute: NUMBEROFOTHERRESULTSATT quote INTEGER quote
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherSolutionResultsAttribute: NUMBEROFOTHERSOLUTIONRESULTSATT quote INTEGER quote 
{    
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solution results cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherVariableResultsAttribute: NUMBEROFOTHERVARIABLERESULTSATT quote INTEGER quote 
{    
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other variable results cannot be negative");
    parserData->tempInt = $3;
};

numberOfSolutionsAttribute: NUMBEROFSOLUTIONSATT quote INTEGER quote 
{
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions attribute previously set");
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = $3; 
};    

numberOfSolverOutputsAttribute: NUMBEROFSOLVEROUTPUTSATT quote INTEGER quote
{    
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solver outputs cannot be negative");
    parserData->tempInt = $3;
};

numberOfSubstatusesAttribute: NUMBEROFSUBSTATUSESATT quote INTEGER quote 
{
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = $3;
};

numberOfTimesAttribute: NUMBEROFTIMESATT quote INTEGER quote
{
    parserData->tempInt = $3;
};

numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVar = $3; 
}; 

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = $3; 
};

//numberOfVarIdxAttribute: NUMBEROFVARIDXATT quote INTEGER quote 
//{
//    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
//    parserData->numberOfVarIdx = $3; 
//}; 


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
 * placeholder "osresult, parserData, osglData, osnlData" to the appropriate reference, which is
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file name");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: source");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: description");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file creator");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: licence");
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

osglNonNegativeIntArrayData: osglIntArrayData
{
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
};

osglIntArrayData:
    osglIntVectorElArray 
    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
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
        throw ErrorClass("OSgL IntVector: more data elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
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
        throw ErrorClass("OSgL DblVector: more data elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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
 *        This portion parses the content of a StringVector <el> element
 *  ==========================================================================
 */

osglStrArrayData: 
    osglStrVectorElArray 
    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
;

osglStrVectorElArray: | osglStrVectorElArray osglStrVectorEl;

osglStrVectorEl: osglStrVectorElStart osglStrVectorElAttributes osglStrVectorElContent;

osglStrVectorElStart: ELSTART
{    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
};


osglStrVectorElAttributes: | osglMultATT;

osglStrVectorElContent: GREATERTHAN  ELEMENTTEXT  ELEND
{
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = $2;
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

/** ========================================================================================
 *  This portion parses the guts of a SolverOptionOrResult object used in both OSoL and OSrL
 *  ========================================================================================
 */
osglSolverOptionOrResultAttributes: osglSolverOptionOrResultAttList
{
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
};

osglSolverOptionOrResultAttList:
    osglSolverOptionOrResultATT 
  | osglSolverOptionOrResultAttList osglSolverOptionOrResultATT;

osglSolverOptionOrResultATT:
    osglNameATT
  | osglValueATT
  | osglSolverATT
  | osglCategoryATT
  | osglTypeATT
  | osglDescriptionATT
  | osglNumberOfItemsATT
    {
        osglData->itemList = new std::string[osglData->numberOfItems];
    }
  ;


osglSolverOptionOrResultBody: osglSolverOptionOrResultMatrixArray | osglSolverOptionOrResultItemArray;

osglSolverOptionOrResultMatrixArray: 
    osglSolverOptionOrResultMatrix
  | osglSolverOptionOrResultMatrixArray osglSolverOptionOrResultMatrix;

osglSolverOptionOrResultMatrix: osglMatrix;



osglSolverOptionOrResultItemArray: 
    osglSolverOptionOrResultItem 
  | osglSolverOptionOrResultItemArray osglSolverOptionOrResultItem;

osglSolverOptionOrResultItem: osglSolverOptionOrResultItemContent
{    
    osglData->itemList[osglData->kounter] = osglData->itemContent;
std::cout << " number of items seen so far: " << osglData->kounter << std::endl; 
    osglData->kounter++;
};    

osglSolverOptionOrResultItemContent: 
    osglSolverOptionOrResultItemEmpty
    {
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
        if (osglData->kounter >= osglData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        osglData->itemContent = "";            
    }    
  | osglSolverOptionOrResultItemLaden; 

osglSolverOptionOrResultItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

osglSolverOptionOrResultItemLaden: ITEMSTART osglSolverOptionOrResultItemBody ITEMEND;

osglSolverOptionOrResultItemBody:  ITEMTEXT 
{
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
    if (osglData->kounter >= osglData->numberOfItems)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->itemContent = $1; 
    free($1);
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
    if (osglData->matrixCounter < osglData->numberOfMatrices)
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
        throw ErrorClass("more matrices than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryPresent == true)
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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
        throw ErrorClass("more matrices than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixVarIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
    else
        ((OSMatrixWithMatrixVarIdx*)osglData->tempC)->matrixVarIdx = osglData->matrixVarIdx;
    if (osglData->symmetryPresent == true)
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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
        throw ErrorClass("more matrices than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixObjIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute matrixObjIdx is missing");
    else
        ((OSMatrixWithMatrixObjIdx*)osglData->tempC)->matrixObjIdx = osglData->matrixObjIdx;
    if (osglData->symmetryPresent == true)
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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
        throw ErrorClass("more matrices than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixConIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute matrixConIdx is missing");    
    else
        ((OSMatrixWithMatrixConIdx*)osglData->tempC)->matrixConIdx = osglData->matrixConIdx;
    if (osglData->symmetryPresent == true)
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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

matrixLaden: GREATERTHAN matrixOrBlockBody MATRIXEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}; 

matrixVarContent: matrixVarEmpty | matrixVarLaden;

matrixVarEmpty: ENDOFELEMENT;

matrixVarLaden: GREATERTHAN matrixOrBlockBody MATRIXVAREND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
};

matrixObjContent: matrixObjEmpty | matrixObjLaden;

matrixObjEmpty: ENDOFELEMENT;

matrixObjLaden: GREATERTHAN matrixOrBlockBody MATRIXOBJEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}; 

matrixConContent: matrixConEmpty | matrixConLaden;

matrixConEmpty: ENDOFELEMENT;

matrixConLaden: GREATERTHAN matrixOrBlockBody MATRIXCONEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
};

matrixOrBlockBody: baseMatrix matrixConstructorList;

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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
    {
        if (osglData->baseMatrixIdx < 0 || osglData->baseMatrixIdx >= osglData->matrixCounter)
            throw ErrorClass("Improper idx value for baseMatrix reference");
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

matrixConstructor: constantElements | complexElements | stringValuedElements |
                   varReferenceElements | objReferenceElements | conReferenceElements | 
                   linearElements | realValuedExpressions | complexValuedExpressions |  
                   matrixTransformation | matrixBlocks;

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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
};

constantElementsAttList: | constantElementsAttList constantElementsAtt;

constantElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
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

matrixElementsStartVectorLaden: GREATERTHAN matrixElementsStartVectorBody STARTVECTOREND
{
    //verify start vector: first element must be zero, vector must be nondecreasing, 
    //last element must equal numberOfValues; length must equal numberOfRows + 1 or numberOfColumns + 1
    if (osglData->osglIntArray[0] != 0)
        throw ErrorClass("first entry of matrix element start vector is not zero");
    for (int i=1; i < osglData->numberOfEl; i++)
    {
        if (osglData->osglIntArray[i] < osglData->osglIntArray[i-1])
            throw ErrorClass("matrix element start vector must be nondecreasing");
    }
    if (osglData->osglIntArray[osglData->numberOfEl-1] 
        != ((MatrixElements*)osglData->tempC)->numberOfValues)
            throw ErrorClass("last entry of matrix element start vector does not equal numberOfValues");
};

matrixElementsStartVectorBody: osglNonNegativeIntArrayData;


matrixElementsIndexVector: | matrixElementsIndexStart matrixElementsIndexContent
{
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    //check whether the values of the index array are legal and satisfy symmetry assertions
    int maxindex;
    //symmetry.substr(0,5) == "upper"/"lower"
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

matrixElementsIndexStart: INDEXSTART
{
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

matrixElementsIndexContent: matrixElementsIndexEmpty | matrixElementsIndexLaden;

matrixElementsIndexEmpty: ENDOFELEMENT;

matrixElementsIndexLaden: GREATERTHAN matrixElementsIndexBody INDEXEND;

matrixElementsIndexBody: osglNonNegativeIntArrayData;


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
    if (osglData->numberOfEl > 0)
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
};

varReferenceElementsAttList: | varReferenceElementsAttList varReferenceElementsAtt;

varReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

varReferenceElementsContent: matrixElementsStartVector varReferenceElementsNonzeros VARREFERENCEELEMENTSEND;

varReferenceElementsNonzeros: matrixElementsIndexVector varReferenceElementsValues;

varReferenceElementsValues: | varReferenceElementsValuesStart varReferenceElementsValuesContent
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
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

varReferenceElementsValuesContent: varReferenceElementsValuesEmpty | varReferenceElementsValuesLaden;

varReferenceElementsValuesEmpty: ENDOFELEMENT;

varReferenceElementsValuesLaden: GREATERTHAN varReferenceElementsValuesBody VALUEEND;

varReferenceElementsValuesBody: osglNonNegativeIntArrayData;


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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
};

linearElementsAttList: | linearElementsAttList linearElementsAtt;

linearElementsAtt: 
    osglNumberOfValuesATT
    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

linearElementsContent: matrixElementsStartVector linearElementsNonzeros LINEARELEMENTSEND;

linearElementsNonzeros: matrixElementsIndexVector linearElementsValues;

linearElementsValues:
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    };    
  | 
    linearElementsValuesStart linearElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");
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
    if (osglData->numberOfValues > 0)
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
};

linearElementsValuesElStart: ELSTART
{
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
};  

linearElementsValuesElAttributes: linearElementsValuesElAttList
{
    if (osglData->numberOfVarIdxPresent)
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
            = osglData->numberOfVarIdx;
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
            = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
            = osglData->constant;
    }
    else
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx = 0;
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    }
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
    linearElementsValuesVarIdxStart linearElementsValuesVarIdxCoefATT linearElementsValuesVarIdxContent;

linearElementsValuesVarIdxStart: VARIDXSTART
{
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
};

linearElementsValuesVarIdxCoefATT: | osglCoefATT
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
};

realValuedExpressionsAttList: | realValuedExpressionsAttList realValuedExpressionsAtt;

realValuedExpressionsAtt: 
    osglNumberOfValuesATT
    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

realValuedExpressionsContent: 
    matrixElementsStartVector realValuedExpressionsNonzeros REALVALUEDEXPRESSIONSSEND;

realValuedExpressionsNonzeros: matrixElementsIndexVector realValuedExpressionsValues;

realValuedExpressionsValues:
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
  | realValuedExpressionsValuesStart realValuedExpressionsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

realValuedExpressionsValuesStart: VALUESTART
{
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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


complexValuedExpressions: complexValuedExpressionsStart complexValuedExpressionsAttributes GREATERTHAN complexValuedExpressionsContent; 

complexValuedExpressionsStart: COMPLEXVALUEDEXPRESSIONSSTART
{
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

complexValuedExpressionsAttributes: complexValuedExpressionsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
};

complexValuedExpressionsAttList: | complexValuedExpressionsAttList complexValuedExpressionsAtt;

complexValuedExpressionsAtt: 
    osglNumberOfValuesATT
    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

complexValuedExpressionsContent: 
    matrixElementsStartVector complexValuedExpressionsNonzeros COMPLEXVALUEDEXPRESSIONSSEND;

complexValuedExpressionsNonzeros: matrixElementsIndexVector complexValuedExpressionsValues;

complexValuedExpressionsValues:
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
  | complexValuedExpressionsValuesStart complexValuedExpressionsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

complexValuedExpressionsValuesStart: VALUESTART
{
    osglData->numberOfValues = ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexValuedExpressions*)osglData->tempC)->value = new ComplexValuedExpressionArray();
    ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((ComplexValuedExpressions*)osglData->tempC)->value->el
        = new ComplexValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ComplexValuedExpressions*)osglData->tempC)->value->el[i] = new ComplexValuedExpressionTree();
};

complexValuedExpressionsValuesContent: 
    complexValuedExpressionsValuesEmpty | complexValuedExpressionsValuesLaden;

complexValuedExpressionsValuesEmpty: ENDOFELEMENT;

complexValuedExpressionsValuesLaden: GREATERTHAN complexValuedExpressionsElList VALUEEND;

complexValuedExpressionsElList:  | complexValuedExpressionsElList complexValuedExpressionsEl;

complexValuedExpressionsEl: complexValuedExpressionsElStart complexValuedExpressionsElContent;

complexValuedExpressionsElStart: ELSTART
    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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

complexValuedExpressionsElContent: complexValuedExpressionsElEmpty | complexValuedExpressionsElLaden;

complexValuedExpressionsElEmpty: ENDOFELEMENT;

complexValuedExpressionsElLaden: GREATERTHAN OSnLCNode ELEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
};

objReferenceElementsAttList: | objReferenceElementsAttList objReferenceElementsAtt;

objReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

objReferenceElementsContent: matrixElementsStartVector objReferenceElementsNonzeros OBJREFERENCEELEMENTSEND;

objReferenceElementsNonzeros: matrixElementsIndexVector objReferenceElementsValues;

objReferenceElementsValues: | objReferenceElementsValuesStart objReferenceElementsValuesContent
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
    if (osglData->numberOfEl > 0)
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
};

conReferenceElementsAttList: | conReferenceElementsAttList conReferenceElementsAtt;

conReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

conReferenceElementsContent: matrixElementsStartVector conReferenceElementsNonzeros CONREFERENCEELEMENTSEND;

conReferenceElementsNonzeros: matrixElementsIndexVector conReferenceElementsValues;

conReferenceElementsValues: 
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
  | conReferenceElementsValuesStart conReferenceElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
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
    if (osglData->numberOfValues > 0)
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
                        conReferenceElementsElContent;

conReferenceElementsElStart: ELSTART
    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = "";
    };

conReferenceElementsElAttributeList: | conReferenceElementsElAttributeList conReferenceElementsElAttribute;

conReferenceElementsElAttribute: 
    osglValueTypeATT
  | osglMultATT
  | osglIncrATT;

conReferenceElementsElContent: GREATERTHAN INTEGER ELEND
{
    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
                "invalid valueType attribute in conReferenceElements");
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


complexElements: complexElementsStart complexElementsAttributes GREATERTHAN complexElementsContent; 

complexElementsStart: COMPLEXELEMENTSSTART
{
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};


complexElementsAttributes: complexElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
};

complexElementsAttList: | complexElementsAttList complexElementsAtt;

complexElementsAtt: 
    osglNumberOfValuesATT
    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

complexElementsContent: matrixElementsStartVector complexElementsNonzeros COMPLEXELEMENTSEND;

complexElementsNonzeros: matrixElementsIndexVector complexElementsValues;

complexElementsValues: 
    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
  | complexElementsValuesStart complexElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");
        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

complexElementsValuesStart: VALUESTART
{
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues> 0)
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
};

complexElementsValuesContent: complexElementsValuesEmpty | complexElementsValuesLaden;

complexElementsValuesEmpty: ENDOFELEMENT;

complexElementsValuesLaden: GREATERTHAN complexElementsElList VALUEEND;

complexElementsElList: | complexElementsElList complexElementsEl;

complexElementsEl: complexElementsElStart complexElementsElAttributeList complexElementsElEnd
{
    if (!osglData->realPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "real part missing");
    if (!osglData->imagPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "imaginary part missing");

    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        for (int i=0; i<osglData->mult; i++)
        {
            ((ComplexMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]
                = std::complex<double>(osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
};

complexElementsElStart: ELSTART
    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    };

complexElementsElAttributeList: | complexElementsElAttributeList complexElementsElAttribute;

complexElementsElAttribute: 
    osglRealPartATT
  | osglImagPartATT
  | osglMultATT;

complexElementsElEnd: GREATERTHAN ELEND | ENDOFELEMENT;


stringValuedElements: stringValuedElementsStart stringValuedElementsAttributes GREATERTHAN stringValuedElementsContent; 

stringValuedElementsStart: STRINGVALUEDELEMENTSSTART
{
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

stringValuedElementsAttributes: stringValuedElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
};

stringValuedElementsAttList: | stringValuedElementsAttList stringValuedElementsAtt;

stringValuedElementsAtt: 
    osglNumberOfValuesATT
    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
;

stringValuedElementsContent: matrixElementsStartVector stringValuedElementsNonzeros STRINGVALUEDELEMENTSEND;

stringValuedElementsNonzeros: matrixElementsIndexVector stringValuedElementsValues;

stringValuedElementsValues: | stringValuedElementsValueStart stringValuedElementsValueContent
{
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

stringValuedElementsValueStart: VALUESTART
{
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
};

stringValuedElementsValueContent: stringValuedElementsValueEmpty | stringValuedElementsValueLaden;

stringValuedElementsValueEmpty: ENDOFELEMENT;

stringValuedElementsValueLaden: GREATERTHAN stringValuedElementsValueBody VALUEEND;

stringValuedElementsValueBody: osglStrArrayData;


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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
};


colOffsets: colOffsetStart colOffsetNumberOfElAttribute colOffsetContent
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        if (osglData->symmetry == "none")
            osglData->symmetry =  "default";
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    | osglTypeATT
    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
;

matrixBlockContent: blockEmpty | blockLaden;

blockEmpty: ENDOFELEMENT;

blockLaden: GREATERTHAN matrixOrBlockBody BLOCKEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}; 



/** Here we parse every attribute that appears in more than one schema 
 *  There are four sections:
 *  1. numberOf... attributes
 *  2. Other attributes returning integers
 *  3. Attributes returning real numbers
 *  4. Attributes returning strings (that may be empty)
 */

/*  1. numberOf... attributes */ 

osglNumberOfBlocksATT: NUMBEROFBLOCKSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = $3;
};

osglNumberOfColumnsATT: NUMBEROFCOLUMNSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = $3;
};

osglNumberOfConATT: NUMBEROFCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = $3;
};

osglNumberOfConIdxATT: NUMBEROFCONIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfConIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <conIdx> cannot be negative");
    osglData->numberOfConIdxPresent = true;        
    osglData->numberOfConIdx = $3;
};

osglNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = $3;
};

osglNumberOfElATT: NUMBEROFELATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = $3;
};

osglNumberOfEnumerationsATT: NUMBEROFENUMERATIONSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = $3;
};

osglNumberOfItemsATT: NUMBEROFITEMSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = $3;
};

osglNumberOfMatricesATT: NUMBEROFMATRICESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrices> cannot be negative");
    osglData->numberOfMatricesPresent = true;        
    osglData->numberOfMatrices = $3;
};

osglNumberOfMatrixConATT: NUMBEROFMATRIXCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrixCon> cannot be negative");
    osglData->numberOfMatrixConPresent = true;        
    osglData->numberOfMatrixCon = $3;
};

osglNumberOfMatrixObjATT: NUMBEROFMATRIXOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrixObj> cannot be negative");
    osglData->numberOfMatrixObjPresent = true;        
    osglData->numberOfMatrixObj = $3;
};

osglNumberOfMatrixVarATT: NUMBEROFMATRIXVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = $3;
};

/*
osglNumberOfNonzerosATT: NUMBEROFNONZEROSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfNonzerosPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfNonzeros attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of nonzeros cannot be negative");
    osglData->numberOfNonzerosPresent = true;        
    osglData->numberOfNonzeros = $3;
};
*/

osglNumberOfObjATT: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = $3;
};

osglNumberOfObjIdxATT: NUMBEROFOBJIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObjIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <objIdx> cannot be negative");
    osglData->numberOfObjIdxPresent = true;        
    osglData->numberOfObjIdx = $3;
};

osglNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = $3;
};

osglNumberOfRowsATT: NUMBEROFROWSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = $3;
};

osglNumberOfValuesATT: NUMBEROFVALUESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = $3;
};

osglNumberOfVarATT: NUMBEROFVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = $3;
};

osglNumberOfVarIdxATT: NUMBEROFVARIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = $3;
};

osglNumberOfVariablesATT: NUMBEROFVARIABLESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = $3;
};


/*  2. Other attributes returning integers */

osglBase64SizeATT: SIZEOFATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = $3;
};

osglBaseMatrixIdxATT: BASEMATRIXIDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ($3 > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = $3; 
};

osglBaseMatrixStartRowATT: BASEMATRIXSTARTROWATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = $3; 
};

osglBaseMatrixStartColATT: BASEMATRIXSTARTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = $3; 
};

osglBaseMatrixEndRowATT: BASEMATRIXENDROWATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = $3; 
};

osglBaseMatrixEndColATT: BASEMATRIXENDCOLATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = $3; 
};

osglBlockRowIdxATT: BLOCKROWIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = $3;
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
};

osglBlockColIdxATT: BLOCKCOLIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = $3;       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
};

osglIdxATT: IDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = $3;
};

osglIncrATT: INCRATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = $3;
};

osglMatrixConIdxATT: MATRIXCONIDXATT quote INTEGER quote 
{
    if (osglData->matrixConIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixConIdx attribute in <matrixCon> element");
    osglData->matrixConIdxPresent = true;
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<matrixConIdx> cannot be negative");
    osglData->matrixConIdx = $3; 
};

osglMatrixObjIdxATT: MATRIXOBJIDXATT quote INTEGER quote 
{
    if (osglData->matrixObjIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixObjIdx attribute in <matrixObj> element");
    osglData->matrixObjIdxPresent = true;
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<matrixObjIdx> cannot be negative");
    osglData->matrixObjIdx = $3; 
};

osglMatrixVarIdxATT: MATRIXVARIDXATT quote INTEGER quote 
{
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = $3; 
};

osglMultATT: MULTATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ($3 <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = $3;
};

osglTargetMatrixFirstRowATT: TARGETMATRIXFIRSTROWATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = $3; 
};

osglTargetMatrixFirstColATT: TARGETMATRIXFIRSTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = $3; 
};


/*  3. Attributes returning real numbers */
osglCoefATT: COEFATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
};

osglConstantATT: CONSTANTATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
};

osglImagPartATT: IMATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
};

osglRealPartATT: REATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
};

osglScalarMultiplierATT: SCALARMULTIPLIERATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
};


/* 4. Attributes returning strings (that may be empty) */

osglBaseTransposeATT: baseTransposeAttEmpty | baseTransposeAttContent;

baseTransposeAttEmpty: EMPTYBASETRANSPOSEATT
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
};

baseTransposeAttContent: BASETRANSPOSEATT ATTRIBUTETEXT quote 
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->baseTranspose = false;
        else if (strcmp($2,"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp($2,"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp($2,"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free($2);
};

osglCategoryATT: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = $2; 
    free($2);
};

osglConTypeATT: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
};

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = $2; 
    free($2);
};

osglDescriptionATT: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
};

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = $2;
    free($2);
};

osglEnumTypeATT: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
};

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = $2; 
    free($2);
};

osglMatrixConTypeATT: matrixConTypeAttEmpty | matrixConTypeAttContent;

matrixConTypeAttEmpty: EMPTYMATRIXCONTYPEATT
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
};

matrixConTypeAttContent: MATRIXCONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
    osglData->matrixConType = $2; 
    free($2);
};

osglMatrixObjTypeATT: matrixObjTypeAttEmpty | matrixObjTypeAttContent;

matrixObjTypeAttEmpty: EMPTYMATRIXOBJTYPEATT
{ 
    if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
};

matrixObjTypeAttContent: MATRIXOBJTYPEATT ATTRIBUTETEXT QUOTE 
{ 
   if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
    osglData->matrixObjType = $2; 
    free($2);
};

osglMatrixTypeATT: matrixTypeAttEmpty | matrixTypeAttContent;

matrixTypeAttEmpty: EMPTYMATRIXTYPEATT
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
};

matrixTypeAttContent: MATRIXTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
    osglData->matrixType = $2; 
    free($2);
};

osglMatrixVarTypeATT: matrixVarTypeAttEmpty | matrixVarTypeAttContent;

matrixVarTypeAttEmpty: EMPTYMATRIXVARTYPEATT
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
};

matrixVarTypeAttContent: MATRIXVARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = $2; 
    free($2);
};

osglNameATT: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
};

nameAttContent: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = $2; 
    free($2);
};

osglObjTypeATT: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
};

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = $2; 
    free($2);
};

osglRowMajorATT: rowMajorAttEmpty | rowMajorAttContent;

rowMajorAttEmpty: EMPTYROWMAJORATT
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
};

rowMajorAttContent: ROWMAJORATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->rowMajor = false;
        else if (strcmp($2,"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp($2,"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp($2,"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free($2);
};

osglShapeATT: shapeAttEmpty | shape;

shapeAttEmpty: EMPTYSHAPEATT
{
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
};

shape: SHAPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = $2;
    free($2);
};

osglSolverATT: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
};

solverAttContent: SOLVERATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = $2; 
    free($2);
};

osglSymmetryATT: symmetryAttEmpty | symmetryAttContent;

symmetryAttEmpty: EMPTYSYMMETRYATT
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
};

symmetryAttContent: SYMMETRYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = $2; 
    free($2);
};

osglTypeATT: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
};

typeAttContent: TYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = $2; 
    free($2);
};

osglUnitATT: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
};

unitAttContent: UNITATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = $2; 
    free($2);
};

osglValueATT:       valueAttEmpty | valueAttContent;

osglValuestringATT: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
};

valueAttContent: VALUEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = $2; 
    free($2);
};

osglValueTypeATT: valueTypeAttEmpty | valueTypeAttContent;

valueTypeAttEmpty: EMPTYVALUETYPEATT
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
};

valueTypeAttContent: VALUETYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = $2; 
    free($2);
};

osglVarTypeATT: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
};

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
 		"actual number of nl terms less than number attribute");   

        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
        parserData->parser_errors = "";
    };

nonlinearExpressionsStart: NONLINEAREXPRESSIONSSTART
    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    };

nlnumberatt: NUMBEROFNONLINEAREXPRESSIONS QUOTE INTEGER QUOTE GREATERTHAN 
    { 
        if ( *$2 != *$4 ) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
                "start and end quotes are not the same");
        if ($3 < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "number of expressions cannot be negative");
        osnlData->nlnodenumber = $3;
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = $3;  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ $3 ];
        for (int i = 0; 
                 i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; 
                 i++)
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
        | nlnodes realValuedExpressionTree;

realValuedExpressionTree: nlstart nlAttributes GREATERTHAN nlnode NLEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->nonlinearExpressions
                    ->nl[osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
                ((OSnLNode*)
                    osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    };

nlstart: NLSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber)
            throw ErrorClass(  "actual number of nl terms greater than numberOfNonlinearExpressions");
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
        osnlData->cSumVec.clear();
    };

nlAttributes: nlAttributeList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "mandatory attribute idx is missing");    
};


nlAttributeList: | nlAttributeList nlAttribute;

nlAttribute: 
      osglIdxATT 
    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
                = new RealValuedExpressionTree();
//        }
    }
    | osglShapeATT
    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            if (returnNlExprShape(osglData->shape) > 0)
                osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->declaredShape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
            else
                parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
                    "unknown shape specified in real-valued expression");
//        }
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
            
numberidATT: IDATT ATTRIBUTETEXT 
{
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = $2;
    free($2);
} QUOTE;

numbervalueATT: VALUEATT QUOTE aNumber QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many number value attributes"); 
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
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }    
        VARIABLEEND;
            
anotherVariableATT:
            | anotherVariableATT variableATT;
            
variableATT: 
      variablecoefATT  
        {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    | variableidxATT
        {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
;
            
variablecoefATT: COEFATT QUOTE aNumber QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
};
                
variableidxATT: IDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ($3 < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "variable index cannot be negative");
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
 *  nlnode below it to increment the number of child nodes.
 */
sum: SUMSTART {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
anothersumnlnode SUMEND {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
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
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
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
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
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
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
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
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
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

matrixReference: matrixReferenceStart matrixRefAttributeList matrixReferenceEnd 
{
    osnlData->matrixidxattON = false;
    if (osnlData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory idx attribute missing");
    if (osnlData->transposeAttributePresent == true)
        osnlData->nlMNodeMatrixRef->transpose = osnlData->matrixTransposeAttribute;
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
};

matrixReferenceStart: MATRIXREFERENCESTART
{
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
};

matrixRefAttributeList: | matrixRefAttributeList matrixRefAttribute;

matrixRefAttribute:
    matrixIdxATT
  | matrixTransposeATT 

              
matrixReferenceEnd: ENDOFELEMENT
           | GREATERTHAN MATRIXREFERENCEEND;
                           
matrixIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ($3 < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = $3;
    osnlData->idxAttributePresent = true;
}; 

matrixTransposeATT: TRANSPOSEATT ATTRIBUTETEXT QUOTE 
{
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp($2,"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp($2,"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp($2,"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp($2,"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free($2);
    osnlData->transposeAttributePresent = true;
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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
    else if (strcmp($2,"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp($2,"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free($2);
};


matrixMerge: matrixMergeStart matrixMergeEnd;

matrixMergeStart: MATRIXMERGESTART 
{
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
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
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
};

anothermatrixproductnode: | anothermatrixproductnode OSnLMNode 
{ 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
};



matrixScalarTimes: matrixScalarTimesStart matrixScalarTimesContent;

matrixScalarTimesStart: MATRIXSCALARTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixScalarTimesContent: OSnLMNode scalarNode  MATRIXSCALARTIMESEND;

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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
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
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mismatched quotes");
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
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
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->
                    expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
                ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    };

matrixExprStart: EXPRSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            throw ErrorClass("actual number of matrix expressions greater than numberOfExpr attribute");
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
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
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
                ->expr[ osnlData->tmpnlcount]->declaredShape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
                "unknown shape specified in matrix expression");
    #endif
    };


/** scalarNodes can be either real-valued or complex-valued */

scalarNode: nlnode | OSnLCNode;

/** OSnLCNodes are parsed in essentially the same way as OSnLNodes */

OSnLCNode: complexNumber
         | createComplex
         | complexPlus
         | complexSum
         | complexMinus
         | complexNegate
         | complexConjugate
         | complexTimes
         | complexSquare
;


complexNumber: complexNumberStart complexNumberAttributes complexNumberEnd 
{
};

complexNumberStart: COMPLEXNUMBERSTART
{
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
};

              
complexNumberEnd: ENDOFELEMENT
           | GREATERTHAN COMPLEXNUMBEREND;

complexNumberAttributes: complexNumberAttList
{
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
};

complexNumberAttList: | complexNumberAttList complexNumberAtt;

complexNumberAtt:
      osglRealPartATT
    | osglImagPartATT
;


createComplex: createComplexStart GREATERTHAN createComplexContent;

createComplexStart: CREATECOMPLEXSTART 
{
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

createComplexContent: nlnode nlnode CREATECOMPLEXEND;


complexPlus: complexPlusStart GREATERTHAN complexPlusContent;

complexPlusStart: COMPLEXPLUSSTART 
{
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexPlusContent: scalarNode scalarNode COMPLEXPLUSEND;


complexSum: COMPLEXSUMSTART GREATERTHAN {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
anothercsumnode COMPLEXSUMEND {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
};

anothercsumnode: 
            | anothercsumnode scalarNode
{ 
    osnlData->cSumVec.back()->inumberOfChildren++; 
};


complexMinus: complexMinusStart GREATERTHAN complexMinusContent;

complexMinusStart: COMPLEXMINUSSTART 
{
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexMinusContent: scalarNode scalarNode COMPLEXMINUSEND;


complexNegate: complexNegateStart GREATERTHAN complexNegateContent;

complexNegateStart: COMPLEXNEGATESTART 
{
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexNegateContent: scalarNode COMPLEXNEGATEEND;


complexConjugate: complexConjugateStart GREATERTHAN complexConjugateContent;

complexConjugateStart: COMPLEXCONJUGATESTART 
{
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexConjugateContent: scalarNode COMPLEXCONJUGATEEND;


complexTimes: complexTimesStart GREATERTHAN complexTimesContent;

complexTimesStart: COMPLEXTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexTimesContent: scalarNode scalarNode COMPLEXTIMESEND;


complexSquare: complexSquareStart GREATERTHAN complexSquareContent;

complexSquareStart: COMPLEXSQUARESTART 
{
    osnlData->nlNodePoint = new OSnLCNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

complexSquareContent: scalarNode COMPLEXSQUAREEND;

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
 * This is the last part of the file OSParseosrl.y containing the postamble.
 * It is appended as the last file.
 */

%%

#if 0
void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osrl_empty_vectors( parserData );
    osgl_empty_vectors(   osglData );
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSrL input is either invalid or not well-formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osrlget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
    error = outStr.str();
    //printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
    //if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
    //osrllex_destroy( scanner);
    throw ErrorClass( error);
} //end osrlerror
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osrlget_lineno( scanner) << ": "; 
    outStr << osrlget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osrl_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osrlerror



void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try
    {
        osrl_scan_string( parsestring, scanner);
        osrlset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osrlparse( osresult,  parserData, osglData, osnlData) != 0) {
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
#if 0
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
#endif
}//end osrl_empty_vectors

