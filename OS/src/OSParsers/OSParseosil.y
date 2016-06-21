/* $Id$ */
/** @file OSParseosil.y.1
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
 * the files OSParseosil.y and OSParseosil.l are stored in several pieces
 * that are combined in the makefile.
 * This is the first part of the file OSParseosil.y. It contains the
 * preamble and tokens that are unique to the OSiL parser.
 * Tokens pertaining to the OSgL and OSnL parsers are appended next.
 * These are in files OSParseosgl.y.tokens and OSParseosnl.y.tokens.   
 * Then follow the syntax rules involving only OSiL constructs (OSParseosil.y.2). 
 * After that we put the syntax rules for elements from the OSgL schema, 
 * maintained in the file OSParseosgl.y.syntax, and then the OSnL syntax
 * in OSParseosnl.y.syntax. The postamble in OSParseosil.y.3 is appended at the end.
 * This process could be repeated for as many other auxiliary schemas as needed. 
 *
 * Note: Make changes in this file rather than OSParseosil.y or OSParserosil.tab.cpp,
 *       as the latter files are recreated by the build system and are thus to be
 *       considered fragile.
 */

%{

#include <string>
#include <iostream>
#include <sstream>  
#include <algorithm>
 
#include "OSInstance.h" 
#include "OSGeneral.h" 
#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSiLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "OSConfig.h"

#define OSINSTANCE_AVAILABLE

//#define CHECK_PARSE_TIME

// debugging tools. uncomment as needed 
#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif


#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osil_scan_string (const char *yy_str , void* yyscanner  );
int osillex_init(void** ptr_yy_globals);
int osillex_destroy (void* yyscanner );
void osilset_extra (OSiLParserData* parserData , void* yyscanner );
int osilget_lineno( void* yyscanner);
char *osilget_text (void* yyscanner );
void osilset_lineno (int line_number , void* yyscanner );
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass);
void osil_empty_vectors( OSiLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);

//

double atofmod1(int* osillineno, const char *ch1, const char *ch2 );
int atoimod1(int* osillineno, const char *ch1, const char *ch2);
// we distinguish a newline from other whitespace
// so that we can report proper line numbers in case of error
void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg);
bool isnewline(char c, int* osillineno);
bool parseVariables(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseObjectives(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseObjCoef(const char **pchar, int objcount, OSInstance *osinstance, int* osillineno);
bool parseConstraints(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseLinearConstraintCoefficients(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseStart(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseRowIdx(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseColIdx(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseValue(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseInstanceHeader(const char **pchar, OSInstance *osinstance, int* osillineno);
bool parseInstanceData( const char **pchar, OSInstance *osinstance, int* osillineno);
char *parseBase64( const char **p, long int *dataSize, int* osillineno);

#define ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define BURNWHITESPACE( X ) for(; ISWHITESPACE( *X) || isnewline( *X, osillineno); X++ )

#define FINDNEXTTAG( X )         \
    BURNWHITESPACE( X );                                                 \
    while(*X == '<' && *(X+1) == '!' && *(X+2) == '-' && *(X+3) == '-')  \
    {                                                                    \
        X += 4;                                                          \
        while (*X != '-' || *(X+1) != '-' || *(X+2) != '>')              \
            X++;                                                         \
        X += 3;                                                          \
        BURNWHITESPACE( X );                                             \
    }                                                 

#define ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  \
    BURNWHITESPACE( ch ); \
    if( *ch != '=') {  osilerror_wrapper( ch, osillineno, "found an attribute not defined"); return false;}  \
    ch++; \
    BURNWHITESPACE( ch ); \
    if(*ch == '\"'){ \
        ch++; \
        BURNWHITESPACE( ch ); \
        *p = ch; \
        for( ; *ch != '\"'; ch++); \
    }\
    else{\
        if(*ch == '\'') { \
            ch++; \
            BURNWHITESPACE( ch ); \
            *p = ch; \
            for( ; *ch != '\''; ch++); \
        } \
        else {  osilerror_wrapper( ch, osillineno,"missing quote on attribute"); return false;} \
    }\
    numChar = ch - *p; \
    attText = new char[numChar + 1]; \
    for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++); \
    attText[ki] = '\0'; \
    attTextEnd = &attText[ki]; 

    
#define GAIL printf("GAIL ANN HONDA\n")
    
#define ECHOCHECK \
    GAIL; \
    printf("%c", ch[-2]); \
    printf("%c", ch[-1]); \
    printf("%c", ch[0]); \
    printf("%c", ch[1]); \
    printf("%c", ch[2]); \
    printf("%c", ch[3]); \
    printf("%c", ch[4]); \
    printf("%c", ch[5]); \
    printf("%c \n", ch[6]); \
    GAIL;
%}

%pure-parser
%locations
%defines
%parse-param{OSInstance *osinstance}
%parse-param{OSiLParserData *parserData}
%parse-param{OSgLParserData *osglData}
%parse-param{OSnLParserData *osnlData}
%lex-param {void* scanner}




%error-verbose



/* %name-prefix="osil" 
this fails on in Mac OS X
*/

%union {
    double dval;
    int ival;
    char* sval;
    
}
%{
int osillex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner );
void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg );
std::string addErrorMsg(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg ) ;
 
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

%token ENDOFELEMENT GREATERTHAN

%token /*EMPTYIDATT IDATT*/ EMPTYSEMIDEFINITENESSATT SEMIDEFINITENESSATT

%token NUMBEROFQTERMSATT NUMBEROFCONESATT NUMBEROFSTAGESATT

%token IDXONEATT IDXTWOATT HORIZONATT STARTATT STARTIDXATT 
%token MATRIXIDXATT LBMATRIXIDXATT LBCONEIDXATT UBMATRIXIDXATT UBCONEIDXATT 
%token TEMPLATEMATRIXIDXATT REFERENCEMATRIXIDXATT
%token VARREFERENCEMATRIXIDXATT OBJREFERENCEMATRIXIDXATT CONREFERENCEMATRIXIDXATT
%token ORDERCONEIDXATT CONSTANTMATRIXIDXATT
%token NORMSCALEFACTORATT DISTORTIONMATRIXIDXATT
%token AXISDIRECTIONATT FIRSTAXISDIRECTIONATT SECONDAXISDIRECTIONATT

%token OSILEND INSTANCEDATAEND INSTANCEDATASTARTEND

%token QUADRATICCOEFFICIENTSSTART QUADRATICCOEFFICIENTSEND QTERMSTART QTERMEND

%token CONESSTART CONESEND 
%token NONNEGATIVECONESTART NONNEGATIVECONEEND NONPOSITIVECONESTART NONPOSITIVECONEEND
%token ORTHANTCONESTART ORTHANTCONEEND POLYHEDRALCONESTART POLYHEDRALCONEEND
%token QUADRATICCONESTART QUADRATICCONEEND ROTATEDQUADRATICCONESTART ROTATEDQUADRATICCONEEND
%token SEMIDEFINITECONESTART SEMIDEFINITECONEEND
%token PRODUCTCONESTART PRODUCTCONEEND INTERSECTIONCONESTART INTERSECTIONCONEEND
%token DUALCONESTART DUALCONEEND POLARCONESTART POLARCONEEND
%token DIRECTIONSTART DIRECTIONEND
%token FACTORSSTART FACTORSEND COMPONENTSSTART COMPONENTSEND

%token TIMEDOMAINSTART TIMEDOMAINEND
%token STAGESSTART STAGESEND STAGESTART STAGEEND
%token INTERVALSTART INTERVALEND

//%token EMPTYSEMIDEFINITENESSATT SEMIDEFINITENESSATT REFERENCEMATRIXIDXATT



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
/** @file OSParseosil.y.2
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
 * the files OSParseosil.y and OSParseosil.l are stored in several pieces
 * that are combined in the makefile.
 * This part contains the grammar rules involving only OSiL constructs. 
 *
 * See also the comments in OSParseosil.y.1. 
 */

%%

osildoc: quadraticCoefficients nonlinearExpressions matrices cones matrixProgramming timeDomain theInstanceEnd osilEnd;


theInstanceEnd:  INSTANCEDATASTARTEND
    | INSTANCEDATAEND ;

osilEnd: osilEnding
    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
    };

osilEnding: OSILEND
    | { parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unexpected end of file, expecting </osil>");};


quadraticCoefficients: 
    |  quadraticCoefficientsStart osilQuadnumberATT qTermlist  QUADRATICCOEFFICIENTSEND 
    {
        if (osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms
                                                             > parserData->qtermcount ) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                    "actual number of qterms less than numberOfQuadraticTerms");

        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
        parserData->parser_errors = "";
    };
   
quadraticCoefficientsStart: QUADRATICCOEFFICIENTSSTART
{
    osinstance->instanceData->quadraticCoefficients = new QuadraticCoefficients();
};

osilQuadnumberATT: NUMBEROFQTERMSATT QUOTE INTEGER QUOTE GREATERTHAN  
{ 
if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = $3;  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ $3 ];
for(int i = 0; i < $3; i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
parserData->qtermcount = 0;
};

qTermlist: | qTermlist qterm ;
           
qterm: qtermStart anotherqTermATT  qtermend 
{
    parserData->qtermcount++; 
    if(!parserData->qtermidxattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idx is required"); 
    if(!parserData->qtermidxOneattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idxOne is required"); 
    if(!parserData->qtermidxTwoattON)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "the qTerm attribute idxTwo is required"); 
    parserData->qtermidattON = false; 
    parserData->qtermidxattON = false; 
    parserData->qtermidxOneattON = false; 
    parserData->qtermidxTwoattON = false;
    parserData->qtermcoefattON = false;
} ;

qtermStart: QTERMSTART
{
    if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= parserData->qtermcount )
        throw ErrorClass("encountered more quadratic terms than specified");
} 
                
qtermend:  ENDOFELEMENT
        | GREATERTHAN  QTERMEND;
    

anotherqTermATT: 
    | anotherqTermATT qtermatt;
    

qtermatt:    osilQtermidxOneATT   
            { if(parserData->qtermidxOneattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxOne attributes"); 
            parserData->qtermidxOneattON = true;  }
        | osilQtermidxTwoATT      
            { if(parserData->qtermidxTwoattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxTwo attributes"); 
            parserData->qtermidxTwoattON = true;  }
        | osilQtermcoefATT 
            { if(parserData->qtermcoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm coef attributes"); 
            parserData->qtermcoefattON = true;  }
        | osilQtermidxATT 
            { if(parserData->qtermidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idx attributes"); 
            parserData->qtermidxattON = true;  }
        ;


osilQtermidxOneATT:  IDXONEATT QUOTE INTEGER QUOTE  {  if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = $3;
    if ($3 < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ($3 >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
};

osilQtermidxTwoATT: IDXTWOATT QUOTE INTEGER QUOTE  { if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = $3;
    if ($3 < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ($3 >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
};

osilQtermcoefATT: COEFATT QUOTE aNumber QUOTE  {if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = parserData->tempVal;
};

osilQtermidxATT: IDXATT QUOTE INTEGER  QUOTE {  if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = $3;
    if ($3 >= osinstance->instanceData->constraints->numberOfConstraints)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term exceeds number of constraints");
    if ($3 < -osinstance->instanceData->objectives->numberOfObjectives)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term refers to nonexisting objective");
};


matrices: | matricesStart matricesAttributes matricesContent
{
    if (osglData->matrixCounter < osglData->numberOfMatrices) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
    osinstance->instanceData->matrices->numberOfMatrices = osglData->numberOfMatrices;
    osinstance->instanceData->matrices->matrix = osglData->matrix;
};

matricesStart: MATRICESSTART
{
    osinstance->instanceData->matrices = new Matrices();
    osglData->numberOfMatricesPresent = false;
};

matricesAttributes: numberOfMatricesATT
{
    if (osglData->numberOfMatrices < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
    {
        osglData->matrix = new OSMatrix*[osglData->numberOfMatrices];
        for (int i=0; i < osglData->numberOfMatrices; i++)
            osglData->matrix[i] = NULL;
    }
};

matricesContent: matricesEmpty | matricesLaden;

matricesEmpty: ENDOFELEMENT;

matricesLaden: GREATERTHAN matrixList MATRICESEND;

/**
 *  Note: A matrix is essentially a list of constructors.
 *  We therefore treat each matrix as homeomorphic to an expression tree
 *  and use the same logic as for parsing the OSiL schema element <nonlinearExpressions>.
 */
matrixList: | matrixList osglMatrix;


cones: | conesStart conesAttributes conesContent
{
    if (parserData->coneCounter < parserData->numberOfCones) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer cones than specified");
};

conesStart: CONESSTART
{
    osinstance->instanceData->cones = new Cones();
    parserData->coneCounter = 0;
};

conesAttributes: numberOfConesATT
{
    if (parserData->numberOfCones < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones cannot be negative");
    else
    {
        osinstance->instanceData->cones->cone = new Cone*[parserData->numberOfCones];
        for (int i=0; i < parserData->numberOfCones; i++)
            osinstance->instanceData->cones->cone[i] = NULL;
    }
};

conesContent: conesEmpty | conesLaden;

conesEmpty: ENDOFELEMENT;

conesLaden: GREATERTHAN coneList CONESEND
{
};

coneList: | coneList cone
{
    parserData->coneCounter++;
    if (parserData->coneCounter > parserData->numberOfCones)
        throw ErrorClass("encountered more cones than specified");
    osinstance->instanceData->cones->numberOfCones = parserData->coneCounter;
};

cone: nonnegativeCone
    | nonpositiveCone
    | generalOrthantCone
    | polyhedralCone
    | quadraticCone
    | rotatedQuadraticCone
/*    | normedCone */
    | semidefiniteCone
/*    | copositiveMatricesCone */
/*    | completelyPositiveMatricesCone */
/*    | hyperbolicityCone */
/*    | sumOfSquaresPolynomialsCone */
/*    | nonnegativePolynomialsCone */
/*    | momentCone */
    | productCone
    | intersectionCone
/*    | dualCone */
/*    | polarCone */
/*    | customCone */
;

nonnegativeCone: nonnegativeConeStart nonnegativeConeAttributes nonnegativeConeEnd;

nonnegativeConeStart: NONNEGATIVECONESTART
{
std::cout << "Start nonnegative cone" << std::endl;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonnegativeCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_nonnegative;    
};

nonnegativeConeAttributes: nonnegativeConeAttList
{
std::cout << "Finish attribute list" << std::endl;
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};

nonnegativeConeAttList: | nonnegativeConeAttList nonnegativeConeAtt;

nonnegativeConeAtt:
      osglNumberOfRowsATT
        {
std::cout << "Number of rows attribute" << std::endl;
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
std::cout << "Number of columns attribute" << std::endl;
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };

nonnegativeConeEnd: ENDOFELEMENT | GREATERTHAN NONNEGATIVECONEEND;


nonpositiveCone: nonpositiveConeStart nonpositiveConeAttributes nonpositiveConeEnd;

nonpositiveConeStart: NONPOSITIVECONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonpositiveCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonpositive;    
};

nonpositiveConeAttributes: nonpositiveConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};


nonpositiveConeAttList: | nonpositiveConeAttList nonpositiveConeAtt;

nonpositiveConeAtt: 
      osglNumberOfRowsATT
        {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };

nonpositiveConeEnd: ENDOFELEMENT | GREATERTHAN NONPOSITIVECONEEND;


generalOrthantCone: generalOrthantConeStart generalOrthantConeAttributes generalOrthantConeContent;

generalOrthantConeStart: ORTHANTCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new OrthantCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_orthant;
};

generalOrthantConeAttributes: generalOrthantConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    osglData->numberOfEl = (osglData->numberOfRows)*(osglData->numberOfColumns);
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub 
        = new double[osglData->numberOfEl];  
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb
        = new double[osglData->numberOfEl];   
    osglData->osglCounter = 0;
};

generalOrthantConeAttList: | generalOrthantConeAttList generalOrthantConeAtt;

generalOrthantConeAtt: 
      osglNumberOfRowsATT
        {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };


generalOrthantConeContent: ENDOFELEMENT | GREATERTHAN generalOrthantConeDirectionList generalOrthantConeEnd
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of directions does not match");
};

generalOrthantConeDirectionList: generalOrthantConeDirections;

generalOrthantConeDirections: | generalOrthantConeDirections generalOrthantConeDirection;

generalOrthantConeDirection: generalOrthantConeDirectionStart generalOrthantConeDirectionAttributes generalOrthantConeDirectionEnd;

generalOrthantConeDirectionStart: DIRECTIONSTART
{
    osglData->typePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
};

generalOrthantConeDirectionAttributes: generalOrthantConeDirectionAttributeList
{
    double ubt;
    double lbt;
    if (osglData->type == "nonnegative")
    {
        ubt = OSDBL_MAX;
        lbt = 0.0;
    }
    else if (osglData->type == "nonpositive")
    {
        ubt = 0.0;
        lbt = -OSDBL_MAX;
    }
    else if (osglData->type == "free")
    {
        ubt =  OSDBL_MAX;
        lbt = -OSDBL_MAX;
    }
    else if (osglData->type == "zero")
    {
        ubt = 0.0;
        lbt = 0.0;
    }
    else
    {
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unrecognized direction type");
    }
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Too many directions given");
    else
        for (int i=0; i < osglData->mult; i++)
        {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub[osglData->osglCounter+i] = ubt;
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb[osglData->osglCounter+i] = lbt;
        }
    osglData->osglCounter += osglData->mult;
};

generalOrthantConeDirectionAttributeList: 
    | generalOrthantConeDirectionAttributeList generalOrthantConeDirectionAtt;

generalOrthantConeDirectionAtt: osglTypeATT | osglMultATT;

generalOrthantConeDirectionEnd: ENDOFELEMENT | GREATERTHAN DIRECTIONEND;

generalOrthantConeEnd: ORTHANTCONEEND;


polyhedralCone: polyhedralConeStart polyhedralConeAttributes polyhedralConeEnd;

polyhedralConeStart: POLYHEDRALCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new PolyhedralCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_polyhedral;    
};

polyhedralConeAttributes: polyhedralConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};


polyhedralConeAttList: | polyhedralConeAttList polyhedralConeAtt;

polyhedralConeAtt: 
      osglNumberOfRowsATT
        {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | referenceMatrixATT
        {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->referenceMatrixIdx
                = parserData->referenceMatrixIdx;
        }
    | osglNameATT
        {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };

referenceMatrixATT: REFERENCEMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->referenceMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "polyhedral cone referenceMatrixIdx attribute previously set");
    parserData->referenceMatrixIdxPresent = true;
    if ($3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index exceeds number of matrices");
    else if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index cannot be negative");
    else parserData->referenceMatrixIdx = $3; 
};

polyhedralConeEnd: ENDOFELEMENT | GREATERTHAN POLYHEDRALCONEEND;


quadraticCone: quadraticConeStart quadraticConeAttributes quadraticConeEnd;

quadraticConeStart: QUADRATICCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->axisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new QuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_quadratic;    
};

quadraticConeAttributes: quadraticConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    if (parserData->axisDirectionPresent)
    {
        if (parserData->axisDirection >= 
                ( ((QuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((QuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "axis direction index exceeds number of dimensions");
        if (parserData->axisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "axis direction index cannot be negative");
    }
};

quadraticConeAttList: | quadraticConeAttList quadraticConeAtt;

quadraticConeAtt: 
      osglNumberOfRowsATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    | distortionMatrixIdxATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    | normScaleFactorATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    | axisDirectionATT
        {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->axisDirection
                = parserData->axisDirection;
        }
;

quadraticConeEnd: ENDOFELEMENT | GREATERTHAN QUADRATICCONEEND;


rotatedQuadraticCone:  rotatedQuadraticConeStart rotatedQuadraticConeAttributes rotatedQuadraticConeEnd;

rotatedQuadraticConeStart: ROTATEDQUADRATICCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->firstAxisDirectionPresent = false;
    parserData->secondAxisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new RotatedQuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_rotatedQuadratic;    
};

rotatedQuadraticConeAttributes: rotatedQuadraticConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
    if (parserData->firstAxisDirectionPresent)
    {
        if (parserData->firstAxisDirection >= 
                ( ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "first axis direction index exceeds number of dimensions");
        if (parserData->firstAxisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "first axis direction index cannot be negative");
    }
    if (parserData->secondAxisDirectionPresent)
    {
        if (parserData->secondAxisDirection >= 
                ( ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows *
                    ((RotatedQuadraticCone*)
                        osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns) )
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "second axis direction index exceeds number of dimensions");
        if (parserData->secondAxisDirection < 0) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "second axis direction index cannot be negative");
    }
};


rotatedQuadraticConeAttList: | rotatedQuadraticConeAttList rotatedQuadraticConeAtt;

rotatedQuadraticConeAtt: 
      osglNumberOfRowsATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name
                = osglData->name;
        }
    | distortionMatrixIdxATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    | normScaleFactorATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    | firstAxisDirectionATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->firstAxisDirection
                = parserData->firstAxisDirection;
        }
    | secondAxisDirectionATT
        {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->secondAxisDirection
                = parserData->secondAxisDirection;
        }
;

rotatedQuadraticConeEnd: ENDOFELEMENT | GREATERTHAN ROTATEDQUADRATICCONEEND;

/* normedCone:  conesStart conesAttributes conesContent; */

semidefiniteCone:  semidefiniteConeStart semidefiniteConeAttributes semidefiniteConeEnd;

semidefiniteConeStart: SEMIDEFINITECONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->semidefinitenessPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new SemidefiniteCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_semidefinite;    
};

semidefiniteConeAttributes: semidefiniteConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};

semidefiniteConeAttList: | semidefiniteConeAttList semidefiniteConeAtt;

semidefiniteConeAtt: 
      osglNumberOfRowsATT
        {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    | semidefinitenessATT
        {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->semidefiniteness
                = parserData->semidefiniteness;
        }
;

semidefiniteConeEnd: ENDOFELEMENT | GREATERTHAN SEMIDEFINITECONEEND;

/* copositiveMatricesCone:  conesStart conesAttributes conesContent; */

/* completelyPositiveMatricesCone:  conesStart conesAttributes conesContent; */

/* hyperbolicityCone:  conesStart conesAttributes conesContent; */

/* nonnegativePolynomialsCone:  conesStart conesAttributes conesContent; */

/* sumOfSquaresPolynomialsCone:  conesStart conesAttributes conesContent; */

/* momentsCone:  conesStart conesAttributes conesContent; */

productCone:  productConeStart productConeAttributes productConeContent;

productConeStart: PRODUCTCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new ProductCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_product;    
};

productConeAttributes: productConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};

productConeAttList: | productConeAttList productConeAtt;

productConeAtt: 
      osglNumberOfRowsATT
        {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };

productConeContent: GREATERTHAN productConeFactors productConeEnd;

productConeFactors: productConeFactorsStart productConeFactorsAttributes productConeFactorsContent;

productConeFactorsStart: FACTORSSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
};

productConeFactorsAttributes: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}; 

productConeFactorsContent: productConeFactorsEmpty | productConeFactorsLaden;

productConeFactorsEmpty: ENDOFELEMENT; 

productConeFactorsLaden: GREATERTHAN productConeFactorList productConeFactorsEnd;

productConeFactorList: osglNonNegativeIntArrayData
{
    // factors must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "product cone factor has illegal index");
};

productConeFactorsEnd: FACTORSEND
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of factors does not match numberOfEl");
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors = new IntVector();
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors->numberOfEl
        = osglData->numberOfEl;
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors ->el 
        = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

productConeEnd: PRODUCTCONEEND;


intersectionCone:  intersectionConeStart intersectionConeAttributes intersectionConeContent;

intersectionConeStart: INTERSECTIONCONESTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new IntersectionCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_intersection;    
};

intersectionConeAttributes: intersectionConeAttList
{
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
};

intersectionConeAttList: | intersectionConeAttList intersectionConeAtt;

intersectionConeAtt: 
      osglNumberOfRowsATT
        {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    | osglNumberOfColumnsATT
        {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    | osglNameATT
        {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        };

intersectionConeContent: GREATERTHAN intersectionConeComponents intersectionConeEnd;

intersectionConeComponents: intersectionConeComponentsStart intersectionConeComponentsAttributes intersectionConeComponentsContent;

intersectionConeComponentsStart: COMPONENTSSTART
{
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
};

intersectionConeComponentsAttributes: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
};

intersectionConeComponentsContent: intersectionConeComponentsEmpty | intersectionConeComponentsLaden;

intersectionConeComponentsEmpty: ENDOFELEMENT;

intersectionConeComponentsLaden: GREATERTHAN intersectionConeComponentList intersectionConeComponentsEnd;

intersectionConeComponentList: osglNonNegativeIntArrayData
{
    // components must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "intersection cone component has illegal index");
};

intersectionConeComponentsEnd: COMPONENTSEND
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of components does not match numberOfEl");
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components = new IntVector();
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components->numberOfEl
        = osglData->numberOfEl;
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components ->el 
        = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

intersectionConeEnd: INTERSECTIONCONEEND;

/* dualCone:  conesStart conesAttributes conesContent; */

/* polarCone:  conesStart conesAttributes conesContent; */

/* customCone:  conesStart conesAttributes conesContent; */




matrixProgramming: | matrixProgrammingStart matrixProgrammingContent; 
        
matrixProgrammingStart: MATRIXPROGRAMMINGSTART
{
    osinstance->instanceData->matrixProgramming = new MatrixProgramming();
};

matrixProgrammingContent: matrixProgrammingEmpty | matrixProgrammingLaden;

matrixProgrammingEmpty: ENDOFELEMENT;

matrixProgrammingLaden: 
        GREATERTHAN  matrixVariables matrixObjectives matrixConstraints matrixExpressions MATRIXPROGRAMMINGEND;

matrixVariables: | matrixVariablesStart matrixVariablesAttributes matrixVariablesContent
    {  
        if (parserData->kounter < parserData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixVar less than number attribute");   
    };


matrixVariablesStart: MATRIXVARIABLESSTART
{
    osinstance->instanceData->matrixProgramming->matrixVariables = new MatrixVariables(); 
};

matrixVariablesAttributes: numberOfMatrixVarATT
{
    osinstance->instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar = parserData->numberOfMatrixVar;
    osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar
        = new MatrixVar*[parserData->numberOfMatrixVar];
    for (int i=0; i < parserData->numberOfMatrixVar; i++)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i] = new MatrixVar();
    parserData->kounter = 0;
};

matrixVariablesContent: matrixVariablesEmpty | matrixVariablesLaden;

matrixVariablesEmpty: ENDOFELEMENT;

matrixVariablesLaden: GREATERTHAN matrixVarList matrixVariablesEnd;

matrixVariablesEnd: MATRIXVARIABLESEND;

matrixVarList: | matrixVarList matrixVariable;

matrixVariable: matrixVariableStart matrixVariableAttributes matrixVariableEnd
{
    parserData->kounter += osglData->mult;
};

matrixVariableStart: MATRIXVARSTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    osglData->varTypePresent = false;
    parserData->templateMatrixIdxPresent = false;
    parserData->varReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
};

matrixVariableAttributes: matrixVariableAttList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixVar) 
        throw ErrorClass("actual number of matrixVar greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->numberOfColumns
            = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->varReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->varReferenceMatrixIdx
                = parserData->varReferenceMatrixIdx;
        if (parserData->lbMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->lbMatrixIdx
                = parserData->lbMatrixIdx;
        if (parserData->lbConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->lbConeIdx
                = parserData->lbConeIdx;
        if (parserData->ubMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->ubMatrixIdx
                = parserData->ubMatrixIdx;
        if (parserData->ubConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->ubConeIdx
                = parserData->ubConeIdx;
        if (osglData->varTypePresent)
        {
            if (returnVarType(osglData->varType[0]) > 0)  
                osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter+i]->varType
                = osglData->varType[0];
            else
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "varType must be one of C, B, I, S, D, J");
        }
    }
};

matrixVariableAttList: | matrixVariableAttList matrixVariableAtt;

matrixVariableAtt: 
      osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | templateMatrixIdxATT
    | varReferenceMatrixIdxATT
    | lbMatrixIdxATT
    | lbConeIdxATT
    | ubMatrixIdxATT
    | ubConeIdxATT
    | osglNameATT
    | osglVarTypeATT
    | osglMultATT
;

matrixVariableEnd: ENDOFELEMENT
            | GREATERTHAN MATRIXVAREND;

matrixObjectives: | matrixObjectivesStart matrixObjectivesAttributes matrixObjectivesContent
    {  
        if (parserData->kounter < parserData->numberOfMatrixObj)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj less than number attribute");
    };

matrixObjectivesStart: MATRIXOBJECTIVESSTART
{
    osinstance->instanceData->matrixProgramming->matrixObjectives = new MatrixObjectives(); 
};

matrixObjectivesAttributes: numberOfMatrixObjATT
{
    osinstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj = parserData->numberOfMatrixObj;
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj
        = new MatrixObj*[parserData->numberOfMatrixObj];
    for (int i=0; i < parserData->numberOfMatrixObj; i++)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i] = new MatrixObj();
    parserData->kounter = 0;
};

matrixObjectivesContent: matrixObjectivesEmpty | matrixObjectivesLaden;

matrixObjectivesEmpty: ENDOFELEMENT;

matrixObjectivesLaden: GREATERTHAN matrixObjList matrixObjectivesEnd;

matrixObjectivesEnd: MATRIXOBJECTIVESEND;

matrixObjList: | matrixObjList matrixObjective;

matrixObjective: matrixObjectiveStart matrixObjectiveAttributes matrixObjectiveEnd 
{
    parserData->kounter += osglData->mult;
};

matrixObjectiveStart: MATRIXOBJSTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    parserData->templateMatrixIdxPresent = false;
    parserData->objReferenceMatrixIdxPresent = false;
    parserData->orderConeIdxPresent = false;
    parserData->constantMatrixIdxPresent = false;
};

matrixObjectiveAttributes: matrixObjectiveAttList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixObj) 
        throw ErrorClass("actual number of matrixObj greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->numberOfColumns
                = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->objReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->objReferenceMatrixIdx
                = parserData->objReferenceMatrixIdx;
        if (parserData->orderConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->orderConeIdx
                = parserData->orderConeIdx;
        if (parserData->constantMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter+i]->constantMatrixIdx
                = parserData->constantMatrixIdx;
    }
};

matrixObjectiveAttList: | matrixObjectiveAttList matrixObjectiveAtt;

matrixObjectiveAtt: 
      osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | templateMatrixIdxATT
    | objReferenceMatrixIdxATT
    | orderConeIdxATT
    | constantMatrixIdxATT
    | osglNameATT
    | osglMultATT
;

matrixObjectiveEnd: ENDOFELEMENT
            | GREATERTHAN MATRIXOBJEND;


matrixConstraints: | matrixConstraintsStart matrixConstraintsAttributes matrixConstraintsContent
    {  
        if (parserData->kounter < parserData->numberOfMatrixCon)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon less than number attribute");   
    };

matrixConstraintsStart: MATRIXCONSTRAINTSSTART
{
    osinstance->instanceData->matrixProgramming->matrixConstraints = new MatrixConstraints(); 
};

matrixConstraintsAttributes: numberOfMatrixConATT
{
    osinstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon = parserData->numberOfMatrixCon;
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon
        = new MatrixCon*[parserData->numberOfMatrixCon];
    for (int i=0; i < parserData->numberOfMatrixCon; i++)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i] = new MatrixCon();
    parserData->kounter = 0;
};

matrixConstraintsContent: matrixConstraintsEmpty | matrixConstraintsLaden; 

matrixConstraintsEmpty: ENDOFELEMENT;

matrixConstraintsLaden: GREATERTHAN matrixConList matrixConstraintsEnd;

matrixConstraintsEnd: MATRIXCONSTRAINTSEND;

matrixConList: | matrixConList matrixConstraint;

matrixConstraint: matrixConstraintStart matrixConstraintAttributes matrixConstraintEnd 
{
    parserData->kounter += osglData->mult;
};

matrixConstraintStart: MATRIXCONSTART
{
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
    parserData->templateMatrixIdxPresent = false;
    parserData->conReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
};

matrixConstraintAttributes: matrixConstraintAttList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    if (parserData->kounter + osglData->mult > parserData->numberOfMatrixCon) 
        throw ErrorClass("actual number of matrixCon greater than number attribute");
    for (int i=0; i<osglData->mult; i++)
    {
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->numberOfRows
            = osglData->numberOfRows;
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->numberOfColumns
            = osglData->numberOfColumns;
        if (osglData->namePresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->name
                = osglData->name;
        if (parserData->templateMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->templateMatrixIdx
                = parserData->templateMatrixIdx;
        if (parserData->conReferenceMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->conReferenceMatrixIdx
                = parserData->conReferenceMatrixIdx;
        if (parserData->lbMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->lbMatrixIdx
                = parserData->lbMatrixIdx;
        if (parserData->lbConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->lbConeIdx
                = parserData->lbConeIdx;
        if (parserData->ubMatrixIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->ubMatrixIdx
                = parserData->ubMatrixIdx;
        if (parserData->ubConeIdxPresent)
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter+i]->ubConeIdx
                = parserData->ubConeIdx;
    }
};

matrixConstraintAttList: | matrixConstraintAttList matrixConstraintAtt;

matrixConstraintAtt:
      osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | templateMatrixIdxATT
    | conReferenceMatrixIdxATT
    | lbMatrixIdxATT
    | lbConeIdxATT
    | ubMatrixIdxATT
    | ubConeIdxATT
    | osglNameATT
;

matrixConstraintEnd: ENDOFELEMENT
            | GREATERTHAN MATRIXCONEND;



/* matrixTermList is used in both matrixObjectives and matrixConstraints */

/*
matrixTermList: | matrixTermList matrixTerm;

matrixTerm: matrixTermStart OSnLMNode matrixTermEnd;

matrixTermStart: MATRIXTERMSTART GREATERTHAN
    {
        if (parserData->kount2 >= parserData->numberOfMatrixTerms) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix terms greater than number attribute");

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

matrixTermEnd: MATRIXTERMEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (parserData->matrixTermInObj)
            osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->matrixTerm[parserData->kount2] = ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix(osnlData->nlNodeVec);
        else
            osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->matrixTerm[parserData->kount2] = ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix(osnlData->nlNodeVec);
        parserData->kount2++;
    };
*/





timeDomain: | timeDomainStart timeDomainContent;

timeDomainStart: TIMEDOMAINSTART {osinstance->instanceData->timeDomain = new TimeDomain();} 

timeDomainContent: timeDomainEmpty | timeDomainLaden;

timeDomainEmpty: ENDOFELEMENT
             | GREATERTHAN TIMEDOMAINEND;

timeDomainLaden: 
        GREATERTHAN stages   TIMEDOMAINEND
      | GREATERTHAN interval TIMEDOMAINEND;


stages: stagesstart osilNumberofstagesATT stagelist STAGESEND
{
    if( osinstance->instanceData->timeDomain->stages->numberOfStages > parserData->stagecount )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of stages less than numberOfStages");
 /* After stages have been processed, make sure that all variables and constraints have been assigned
  * to a stage (uniquely) and all objectives have been assigned as well (possibly more than once).
  * For future reference also record the stage to which each variable and constraint belongs. 
  */
    parserData->m_miVarStageInfo = new int [ osinstance->instanceData->variables->numberOfVariables ];
    parserData->m_miObjStageInfo = new int [ osinstance->instanceData->objectives->numberOfObjectives ];
    parserData->m_miConStageInfo = new int [ osinstance->instanceData->constraints->numberOfConstraints ];
    parserData->nvarcovered = 0;
    for (int i = 0; i < osinstance->instanceData->variables->numberOfVariables; i++)
         parserData->m_miVarStageInfo[i] = -1;
    for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
         parserData->m_miObjStageInfo[i] = -1;
    for (int i = 0; i < osinstance->instanceData->constraints->numberOfConstraints; i++)
         parserData->m_miConStageInfo[i] = -1;
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        {for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables; i++)
            {            
            if (parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] != -1)
                    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable belongs to two stages");
                parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] = k;
            };
         parserData->nvarcovered += osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables;
        };
    if (parserData->nvarcovered != osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some variables not assigned to any stage");
    parserData->nconcovered = 0;
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        {for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints; i++)
            {if (parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] != -1)
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint belongs to two stages");
                 parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] = k;
            };
         parserData->nconcovered += osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints;
        };
    if (parserData->nconcovered != osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some constraints not assigned to any stage");
    for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
        { for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->objectives->numberOfObjectives; i++)
            { if (parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] == -1)
                    parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] = k;
            };
        };
    for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
        if (parserData->m_miObjStageInfo[i] == -1)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "some objectives not assigned to any stage");
};

stagesstart: STAGESSTART {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}

osilNumberofstagesATT: NUMBEROFSTAGESATT QUOTE INTEGER QUOTE GREATERTHAN {
    if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ($3 < 1) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of stages must be positive");
    osinstance->instanceData->timeDomain->stages->numberOfStages = $3;
    if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
        osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ $3 ];
    for(int i = 0; i < $3; i++) 
    {    osinstance->instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
        osinstance->instanceData->timeDomain->stages->stage[i]->variables   = new TimeDomainStageVariables();
        osinstance->instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        osinstance->instanceData->timeDomain->stages->stage[i]->objectives  = new TimeDomainStageObjectives();
    }
};

stagelist: stage
    | stagelist stage;

stage: {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
STAGESTART osilStagenameATT stageend { /* set defaults for next stage */
    parserData->stagenameON = false;
    parserData->stageVariablesON = false;
    parserData->stageObjectivesON = false;
    parserData->stageConstraintsON = false;
    parserData->stageVariablesOrdered = false;
    parserData->stageObjectivesOrdered = false;
    parserData->stageConstraintsOrdered = false;
    parserData->stageVariableStartIdx = 0;
    parserData->stageObjectiveStartIdx = 0;
    parserData->stageConstraintStartIdx = 0;
    parserData->stagevarcount = 0;
    parserData->stageconcount = 0;
    parserData->stageobjcount = 0;
    parserData->stagecount++;
};

osilStagenameATT: 
        | NAMEATT ATTRIBUTETEXT QUOTE {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = $2; free($2);};
        
stageend: ENDOFELEMENT
        | GREATERTHAN stagecontent STAGEEND;

stagecontent: stagevariables stageconstraints stageobjectives;

stagevariables: 
      | VARIABLESSTART anotherstagevarATT restofstagevariables {
        parserData->stageVariablesON = true;
        };

anotherstagevarATT:
      | anotherstagevarATT stagevaratt;
        
stagevaratt: osilNumberofstagevariablesATT
      | osilStagevarstartidxATT;
           
osilNumberofstagevariablesATT: NUMBEROFVARIABLESATT QUOTE INTEGER QUOTE  
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of variables cannot be negative");
    if ($3 > osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");         
    if ($3 > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfVariables");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = $3;
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var = new TimeDomainStageVar*[ $3 ];
        for (int i = 0; i < $3; i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
        }
    };
};

osilStagevarstartidxATT: STARTIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ($3 < 0 && $3 >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = $3;
};

restofstagevariables: emptyvarlist {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    | GREATERTHAN stagevarlist VARIABLESEND {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      };

emptyvarlist: ENDOFELEMENT
            | GREATERTHAN VARIABLESEND;
        
stagevarlist: stagevar
            | stagevarlist stagevar;

stagevar: {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
        VARSTART osilStagevaridxATT stagevarend;

osilStagevaridxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0 || $3 >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = $3;
    parserData->stagevarcount++;
};

stagevarend: ENDOFELEMENT
           | GREATERTHAN VAREND;

stageconstraints: 
      | CONSTRAINTSSTART anotherstageconATT restofstageconstraints {
        parserData->stageConstraintsON = true;
    };

anotherstageconATT:
        | anotherstageconATT stageconatt;
        
stageconatt: osilNumberofstageconstraintsATT
           | osilStageconstartidxATT;
           
osilNumberofstageconstraintsATT: NUMBEROFCONSTRAINTSATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of constraints cannot be negative");
    if ($3 > osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");         
    if ($3 > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfConstraints");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = $3;
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con = new TimeDomainStageCon*[ $3 ];
        for (int i = 0; i < $3; i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
        }
    };
};

osilStageconstartidxATT: STARTIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ($3 < 0 && $3 >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = $3;
};

restofstageconstraints: emptyconlist {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    | GREATERTHAN stageconlist CONSTRAINTSEND {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      };
        
emptyconlist: ENDOFELEMENT
            | GREATERTHAN CONSTRAINTSEND;
            
stageconlist: stagecon
            | stageconlist stagecon;

stagecon: {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
        CONSTART osilStageconidxATT stageconend;

osilStageconidxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0 || $3 >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = $3;
    parserData->stageconcount++;
};

stageconend: ENDOFELEMENT
           | GREATERTHAN CONEND;

stageobjectives: { /* By default, an objective belongs to every stage */
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 
                osinstance->instanceData->objectives->numberOfObjectives;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = 
                new TimeDomainStageObj*[ osinstance->instanceData->objectives->numberOfObjectives ];
            for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++) 
            {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
                osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = -(i+1); 
            }
    };
    | OBJECTIVESSTART anotherstageobjATT restofstageobjectives {
      parserData->stageObjectivesON = true;
    };

anotherstageobjATT:
        | anotherstageobjATT stageobjatt;
        
stageobjatt: osilNumberofstageobjectivesATT
           | osilStageobjstartidxATT;
           
osilNumberofstageobjectivesATT: NUMBEROFOBJECTIVESATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of objectives cannot be negative");
    if ($3 > osinstance->instanceData->objectives->numberOfObjectives)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");         
    if ($3 > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfObjectives");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = $3;
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = new TimeDomainStageObj*[ $3 ];
        for (int i = 0; i < $3; i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = 0; 
        }
    };
};

restofstageobjectives: emptyobjlist {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    | GREATERTHAN stageobjlist OBJECTIVESEND {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    };
    
emptyobjlist: ENDOFELEMENT
            | GREATERTHAN OBJECTIVESEND;

stageobjlist: stageobj
            | stageobjlist stageobj;

stageobj: {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
        OBJSTART osilStageobjidxATT stageobjend;

osilStageobjidxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 >= 0 || $3 >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = $3;
    parserData->stageobjcount++;
};

stageobjend: ENDOFELEMENT
           | GREATERTHAN OBJEND;



interval: 
        {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
        INTERVALSTART anotherIntervalATT intervalend {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
};

intervalend: ENDOFELEMENT
    | GREATERTHAN INTERVALEND;

anotherIntervalATT:
    | anotherIntervalATT intervalatt;

intervalatt: osilIntervalhorizonATT 
        { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    |   osilIntervalstartATT 
        { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }


osilStageobjstartidxATT: STARTIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ($3 >= 0 && $3 <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = $3;
};

osilIntervalhorizonATT: HORIZONATT QUOTE aNumber QUOTE 
{
        if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;};

osilIntervalstartATT: STARTATT QUOTE aNumber QUOTE {
        if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;};


osilNumberOfElATT: NUMBEROFELATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    parserData->numberOfEl = $3; 
}; 

numberOfMatricesATT: NUMBEROFMATRICESATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    osglData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = $3;
}; 

numberOfConesATT: NUMBEROFCONESATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfConesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <cone> elements cannot be negative");
    parserData->numberOfConesPresent = true;
    parserData->numberOfCones = $3; 
}; 

numberOfMatrixVarATT: NUMBEROFMATRIXVARATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = $3; 
}; 

numberOfMatrixObjATT: NUMBEROFMATRIXOBJATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = $3; 
}; 

numberOfMatrixConATT: NUMBEROFMATRIXCONATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = $3; 
}; 

numberOfMatrixTermsATT: NUMBEROFMATRIXTERMSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->numberOfMatrixTermsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrixTerms attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix terms cannot be negative");
    parserData->numberOfMatrixTermsPresent = true;        
    parserData->numberOfMatrixTerms = $3;
};

normScaleFactorATT: NORMSCALEFACTORATT QUOTE aNumber QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->normScaleFactorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "normScaleFactor attribute previously set");
    if (parserData->tempVal <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "scale factor must be positive");
    parserData->normScaleFactorPresent = true;
    parserData->normScaleFactor = parserData->tempVal; 
};

distortionMatrixIdxATT: DISTORTIONMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->distortionMatrixPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortionMatrixIdx attribute previously set");
    parserData->distortionMatrixPresent = true;
    if ($3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index exceeds number of matrices");
    else if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index cannot be negative");
    else parserData->distortionMatrix = $3; 
};
 
axisDirectionATT: AXISDIRECTIONATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->axisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "axisDirection attribute previously set");
    parserData->axisDirectionPresent = true;
    parserData->axisDirection = $3;
std::cout << "found axis direction = " << parserData->axisDirection << std::endl;
};


firstAxisDirectionATT: FIRSTAXISDIRECTIONATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,     
            "mismatched quotes");
    if (parserData->firstAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "firstAxisDirection attribute previously set");
    parserData->firstAxisDirectionPresent = true;
    parserData->firstAxisDirection = $3; 
std::cout << "found first axis direction = " << parserData->firstAxisDirection << std::endl;
};

secondAxisDirectionATT: SECONDAXISDIRECTIONATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->secondAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "secondAxisDirection attribute previously set");
    parserData->secondAxisDirectionPresent = true;
    parserData->secondAxisDirection = $3; 
std::cout << "found second axis direction = " << parserData->secondAxisDirection << std::endl;
};

semidefinitenessATT: SEMIDEFINITENESSATT ATTRIBUTETEXT QUOTE 
{
    if (parserData->semidefinitenessPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->semidefinitenessPresent = true;
    parserData->semidefiniteness = $2; 
    free($2);
    if (parserData->semidefiniteness != "positive" && parserData->semidefiniteness != "negative")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "semidefiniteness must be either \"positive\" or \"negative\"");
};

matrixIdxATT: MATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->matrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrixIdx attribute previously set");
    parserData->matrixIdxPresent = true;
    if ($3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index exceeds number of matrices");
    else if ($3 < 0) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index cannot be negative");
    else parserData->matrixIdx = $3; 
};

lbMatrixIdxATT: LBMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbMatrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbMatrix attribute");
    parserData->lbMatrixIdxPresent = true;
    parserData->lbMatrixIdx = $3;
};

ubMatrixIdxATT: UBMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubMatrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubMatrix attribute");
    parserData->ubMatrixIdxPresent = true;
    parserData->ubMatrixIdx = $3;
};

constantMatrixIdxATT: CONSTANTMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->constantMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one constant matrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for constant matrix attribute");
    parserData->constantMatrixIdxPresent = true;
    parserData->constantMatrixIdx = $3;
};

templateMatrixIdxATT: TEMPLATEMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if (*$2 != *$4) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for template matrix index");
    parserData->templateMatrixIdxPresent = true;
    parserData->templateMatrixIdx = $3; 
};

varReferenceMatrixIdxATT: VARREFERENCEMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->varReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one varReference matrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for varReference matrix attribute");
    parserData->varReferenceMatrixIdxPresent = true;
    parserData->varReferenceMatrixIdx = $3;
};

objReferenceMatrixIdxATT: OBJREFERENCEMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->objReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one objReference matrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for objReference matrix attribute");
    parserData->objReferenceMatrixIdxPresent = true;
    parserData->objReferenceMatrixIdx = $3;
};

conReferenceMatrixIdxATT: CONREFERENCEMATRIXIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->conReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one conReference matrix attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for conReference matrix attribute");
    parserData->conReferenceMatrixIdxPresent = true;
    parserData->conReferenceMatrixIdx = $3;
};

lbConeIdxATT: LBCONEIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbCone attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbCone attribute");
    parserData->lbConeIdxPresent = true;
    parserData->lbConeIdx = $3;
};

ubConeIdxATT: UBCONEIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubCone attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubCone attribute");
    parserData->ubConeIdxPresent = true;
    parserData->ubConeIdx = $3;
};

orderConeIdxATT: ORDERCONEIDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->orderConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one orderCone attribute allowed");
    if ($3 < 0 || $3 >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for orderCone attribute");
    parserData->orderConeIdxPresent = true;
    parserData->orderConeIdx = $3;
};

/*
varTypeATT: VARTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (parserData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    parserData->varTypePresent = true;
    if (returnVarType($2[0]) > 0)  
        parserData->varType = returnVarType($2[0]); 
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType must be one of C, B, I, S, D, J");
    free($2);
};
*/

aNumber:
    xmlWhiteSpace INTEGER xmlWhiteSpace {parserData->tempVal = $2;}
  | xmlWhiteSpace DOUBLE  xmlWhiteSpace {parserData->tempVal = $2;};

//ElementValue: 
//    ELEMENTTEXT  { parserData->tempStr = $1;       /*free($1);*/ }
//  | INTEGER      { parserData->tempStr = os_dtoa_format($1); }
//  | DOUBLE       { parserData->tempStr = os_dtoa_format($1); };
  
quote: xmlWhiteSpace QUOTE;

xmlWhiteSpace:   | xmlWhiteSpace xmlWhiteSpaceChar;

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
 * placeholder "osinstance, parserData, osglData, osnlData" to the appropriate reference, which is
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Repeated header information: file name");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Repeated header information: source");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Repeated header information: description");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Repeated header information: file creator");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "Repeated header information: licence");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixVarIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
    else
        ((OSMatrixWithMatrixVarIdx*)osglData->tempC)->matrixVarIdx = osglData->matrixVarIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixObjIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute matrixObjIdx is missing");
    else
        ((OSMatrixWithMatrixObjIdx*)osglData->tempC)->matrixObjIdx = osglData->matrixObjIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixConIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute matrixConIdx is missing");    
    else
        ((OSMatrixWithMatrixConIdx*)osglData->tempC)->matrixConIdx = osglData->matrixConIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    };    
  | 
    linearElementsValuesStart linearElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
  | realValuedExpressionsValuesStart realValuedExpressionsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
  | complexValuedExpressionsValuesStart complexValuedExpressionsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
  | conReferenceElementsValuesStart conReferenceElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
  | complexElementsValuesStart complexElementsValuesContent
    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "real part missing");
    if (!osglData->imagPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "imaginary part missing");

    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
};


colOffsets: colOffsetStart colOffsetNumberOfElAttribute colOffsetContent
{
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = $3;
};

osglNumberOfColumnsATT: NUMBEROFCOLUMNSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = $3;
};

osglNumberOfConATT: NUMBEROFCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = $3;
};

osglNumberOfConIdxATT: NUMBEROFCONIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfConIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <conIdx> cannot be negative");
    osglData->numberOfConIdxPresent = true;        
    osglData->numberOfConIdx = $3;
};

osglNumberOfConstraintsATT: NUMBEROFCONSTRAINTSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = $3;
};

osglNumberOfElATT: NUMBEROFELATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = $3;
};

osglNumberOfEnumerationsATT: NUMBEROFENUMERATIONSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = $3;
};

osglNumberOfItemsATT: NUMBEROFITEMSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = $3;
};

osglNumberOfMatricesATT: NUMBEROFMATRICESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrices> cannot be negative");
    osglData->numberOfMatricesPresent = true;        
    osglData->numberOfMatrices = $3;
};

osglNumberOfMatrixConATT: NUMBEROFMATRIXCONATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrixCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrixCon> cannot be negative");
    osglData->numberOfMatrixConPresent = true;        
    osglData->numberOfMatrixCon = $3;
};

osglNumberOfMatrixObjATT: NUMBEROFMATRIXOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrixObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrixObj> cannot be negative");
    osglData->numberOfMatrixObjPresent = true;        
    osglData->numberOfMatrixObj = $3;
};

osglNumberOfMatrixVarATT: NUMBEROFMATRIXVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = $3;
};

/*
osglNumberOfNonzerosATT: NUMBEROFNONZEROSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfNonzerosPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfNonzeros attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of nonzeros cannot be negative");
    osglData->numberOfNonzerosPresent = true;        
    osglData->numberOfNonzeros = $3;
};
*/

osglNumberOfObjATT: NUMBEROFOBJATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = $3;
};

osglNumberOfObjIdxATT: NUMBEROFOBJIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfObjIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <objIdx> cannot be negative");
    osglData->numberOfObjIdxPresent = true;        
    osglData->numberOfObjIdx = $3;
};

osglNumberOfObjectivesATT: NUMBEROFOBJECTIVESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = $3;
};

osglNumberOfRowsATT: NUMBEROFROWSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = $3;
};

osglNumberOfValuesATT: NUMBEROFVALUESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = $3;
};

osglNumberOfVarATT: NUMBEROFVARATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = $3;
};

osglNumberOfVarIdxATT: NUMBEROFVARIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = $3;
};

osglNumberOfVariablesATT: NUMBEROFVARIABLESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = $3;
};


/*  2. Other attributes returning integers */

osglBase64SizeATT: SIZEOFATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = $3;
};

osglBaseMatrixIdxATT: BASEMATRIXIDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ($3 > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = $3; 
};

osglBaseMatrixStartRowATT: BASEMATRIXSTARTROWATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = $3; 
};

osglBaseMatrixStartColATT: BASEMATRIXSTARTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = $3; 
};

osglBaseMatrixEndRowATT: BASEMATRIXENDROWATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = $3; 
};

osglBaseMatrixEndColATT: BASEMATRIXENDCOLATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = $3; 
};

osglBlockRowIdxATT: BLOCKROWIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = $3;
};

osglIncrATT: INCRATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = $3;
};

osglMatrixConIdxATT: MATRIXCONIDXATT quote INTEGER quote 
{
    if (osglData->matrixConIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixConIdx attribute in <matrixCon> element");
    osglData->matrixConIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixConIdx> cannot be negative");
    osglData->matrixConIdx = $3; 
};

osglMatrixObjIdxATT: MATRIXOBJIDXATT quote INTEGER quote 
{
    if (osglData->matrixObjIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixObjIdx attribute in <matrixObj> element");
    osglData->matrixObjIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixObjIdx> cannot be negative");
    osglData->matrixObjIdx = $3; 
};

osglMatrixVarIdxATT: MATRIXVARIDXATT quote INTEGER quote 
{
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ($3 < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = $3; 
};

osglMultATT: MULTATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ($3 <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = $3;
};

osglTargetMatrixFirstRowATT: TARGETMATRIXFIRSTROWATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = $3; 
};

osglTargetMatrixFirstColATT: TARGETMATRIXFIRSTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = $3; 
};


/*  3. Attributes returning real numbers */
osglCoefATT: COEFATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
};

osglConstantATT: CONSTANTATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
};

osglImagPartATT: IMATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
};

osglRealPartATT: REATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
};

osglScalarMultiplierATT: SCALARMULTIPLIERATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
};


/* 4. Attributes returning strings (that may be empty) */

osglBaseTransposeATT: baseTransposeAttEmpty | baseTransposeAttContent;

baseTransposeAttEmpty: EMPTYBASETRANSPOSEATT
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
};

baseTransposeAttContent: BASETRANSPOSEATT ATTRIBUTETEXT quote 
{
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->baseTranspose = false;
        else if (strcmp($2,"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp($2,"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp($2,"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free($2);
};

osglCategoryATT: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = $2; 
    free($2);
};

osglConTypeATT: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
};

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = $2; 
    free($2);
};

osglDescriptionATT: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
};

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = $2;
    free($2);
};

osglEnumTypeATT: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
};

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = $2; 
    free($2);
};

osglMatrixConTypeATT: matrixConTypeAttEmpty | matrixConTypeAttContent;

matrixConTypeAttEmpty: EMPTYMATRIXCONTYPEATT
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
};

matrixConTypeAttContent: MATRIXCONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixConTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one matrixConType attribute");
    osglData->matrixConTypePresent = true;   
    osglData->matrixConType = $2; 
    free($2);
};

osglMatrixObjTypeATT: matrixObjTypeAttEmpty | matrixObjTypeAttContent;

matrixObjTypeAttEmpty: EMPTYMATRIXOBJTYPEATT
{ 
    if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
};

matrixObjTypeAttContent: MATRIXOBJTYPEATT ATTRIBUTETEXT QUOTE 
{ 
   if (osglData->matrixObjTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixObjType attribute");
    osglData->matrixObjTypePresent = true;   
    osglData->matrixObjType = $2; 
    free($2);
};

osglMatrixTypeATT: matrixTypeAttEmpty | matrixTypeAttContent;

matrixTypeAttEmpty: EMPTYMATRIXTYPEATT
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
};

matrixTypeAttContent: MATRIXTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixType attribute");
    osglData->matrixTypePresent = true;   
    osglData->matrixType = $2; 
    free($2);
};

osglMatrixVarTypeATT: matrixVarTypeAttEmpty | matrixVarTypeAttContent;

matrixVarTypeAttEmpty: EMPTYMATRIXVARTYPEATT
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
};

matrixVarTypeAttContent: MATRIXVARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = $2; 
    free($2);
};

osglNameATT: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
};

nameAttContent: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = $2; 
    free($2);
};

osglObjTypeATT: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
};

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = $2; 
    free($2);
};

osglRowMajorATT: rowMajorAttEmpty | rowMajorAttContent;

rowMajorAttEmpty: EMPTYROWMAJORATT
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
};

rowMajorAttContent: ROWMAJORATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->rowMajor = false;
        else if (strcmp($2,"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp($2,"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp($2,"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free($2);
};

osglShapeATT: shapeAttEmpty | shape;

shapeAttEmpty: EMPTYSHAPEATT
{
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
};

shape: SHAPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = $2;
    free($2);
};

osglSolverATT: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
};

solverAttContent: SOLVERATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = $2; 
    free($2);
};

osglSymmetryATT: symmetryAttEmpty | symmetryAttContent;

symmetryAttEmpty: EMPTYSYMMETRYATT
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
};

symmetryAttContent: SYMMETRYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = $2; 
    free($2);
};

osglTypeATT: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
};

typeAttContent: TYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = $2; 
    free($2);
};

osglUnitATT: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
};

unitAttContent: UNITATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = $2; 
    free($2);
};

osglValueATT:       valueAttEmpty | valueAttContent;

osglValuestringATT: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
};

valueAttContent: VALUEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = $2; 
    free($2);
};

osglValueTypeATT: valueTypeAttEmpty | valueTypeAttContent;

valueTypeAttEmpty: EMPTYVALUETYPEATT
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
};

valueTypeAttContent: VALUETYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = $2; 
    free($2);
};

osglVarTypeATT: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
};

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
                parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = $2;
    free($2);
} QUOTE;

numbervalueATT: VALUEATT QUOTE aNumber QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
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
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    | variableidxATT
        {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
;
            
variablecoefATT: COEFATT QUOTE aNumber QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
};
                
variableidxATT: IDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ($3 < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index cannot be negative");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory idx attribute missing");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ($3 < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = $3;
    osnlData->idxAttributePresent = true;
}; 

matrixTransposeATT: TRANSPOSEATT ATTRIBUTETEXT QUOTE 
{
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp($2,"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp($2,"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp($2,"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp($2,"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free($2);
};


matrixMerge: matrixMergeStart matrixMergeEnd;

matrixMergeStart: MATRIXMERGESTART 
{
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
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
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
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
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
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
/** @file OSParseosil.y.3
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
 * In order to allow easier maintenance of the parser, 
 * the files OSParseosil.y and OSParseosil.l are stored in several pieces
 * that are combined in the makefile.
 * This is the last part of the file OSParseosil.y containing the postamble.
 */

%%


// user defined functions

void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg )
{
    osil_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osilerror


std::string addErrorMsg(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osilget_lineno( scanner) << ": "; 
    outStr << osilget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg


void  yygetOSInstance( const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw (ErrorClass) {
    try {
        parseInstanceHeader( &osil, osinstance, &parserData->osillineno);
        parseInstanceData( &osil, osinstance, &parserData->osillineno);    
        /** at this point here we have parsed everything through <linearConstraintCoefficients>
         *    we have done so without bison and just moved the pointer on osil to point to what is past
         *    the linear part    
         * call the flex scanner and start scanning the nonlinear part of the problem
         */    
        osil_scan_string( osil, scanner );
        osilset_lineno (parserData->osillineno , scanner );
        //
        // call the Bison parser
        //
        if(  osilparse( osinstance,  parserData, osglData, osnlData) != 0) {
            throw ErrorClass(  "Error parsing the OSiL");
        }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
}//end yygetOSInstance

bool isnewline(char c, int* osillineno){
    if(c != '\n') return false;
    (*osillineno)++;
    return true;
}//end isnewline()

bool parseInstanceHeader( const char **p, OSInstance *osinstance, int* osillineno){
    //
    *osillineno = 1;
    const char *pchar = *p;
    
    //first check of osil start
    const char *startOSiL = "<osil";
    const char *pOSiLStart = strstr(pchar, startOSiL);
    if(pOSiLStart == NULL){
      osilerror_wrapper( pchar,osillineno,"<osil> element missing"); 
      return false;
    }else{
        //look for osil end
            const char *pOSiLEnd = strstr(pOSiLStart, ">");
        if(pOSiLEnd == NULL) {  osilerror_wrapper( pchar,osillineno,"end of <osil> element missing"); return false;
            } else {
            pchar = pOSiLEnd;
            pchar++;
        }
    }
    
    
    // create a char array that holds the instance header information
    const char *startInstanceHeader = "<instanceHeader";
    const char *endInstanceHeader = "instanceHeader"; // "</instanceHeader";
    const char *startName = "ame"; // "<name";
    const char *startSource = "ource"; // "<source";
    const char *startDescription = "escription"; // "<description";
    const char *startFileCreator = "ileCreator"; // "<fileCreator";
    const char *startLicence = "icence"; // "<licence";
    const char *endName = "</name";
    const char *endSource = "</source";
    const char *endDescription = "</description";
    const char *endFileCreator = "</fileCreator";
    const char *endLicence = "</licence";
    const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
    char *pelementText = NULL;
    const char *ptemp = NULL;
    long int elementSize;

    bool namePresent = false;
    bool sourcePresent = false;
    bool descriptionPresent = false;
    bool fileCreatorPresent = false;
    bool licencePresent = false;

    if(pinstanceHeadStart == NULL ) {
        const char *startInstanceData = "<instanceData";
        *p = strstr(pchar, startInstanceData);
        return true;
    }
    // increment the line number counter if there are any newlines between the start of
    // the osil string and pinstanceHeadStart
    long int kount = pinstanceHeadStart - pchar;
    while( kount-- > 0) if(*(pchar++) == '\n') (*osillineno)++;
    // important! pchar now points to the '<' in <instanceHeader
    // that is, both pinstanceHeadStart and pchar point to the same thing
     // 
     // move to the end of <instanceHeader
     pchar+=15;
    // burn any whitespace
    BURNWHITESPACE( pchar );
    // pchar better be pointing to the '>' in the <instanceHeader> element
    // or to /> if we have <instanceHeader />
    if( *pchar == '/'){
        pchar++;
        // better point to a '>'
        if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
        // there is no instanceHeader data
        pchar++;
        *p = pchar;
        return true;
    }
    else{
        // pchar better be '>' or there is an error
        if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
    }
    pchar++;
    // we are pointing to the character after <instanceHeader>
    //
    // The next element could be </instanceHeader or one of the content elements (in arbitrary order):
    // <name
    // <source
    // <description
    // <fileCreator
    // <licence

    for (;;)
    {
        // first burn any whitespace and comments
        FINDNEXTTAG( pchar );
        // remember where we are
        *p = pchar;
        // The next character should be '<'
        if (*pchar != '<') {osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
        pchar++;
        switch (*pchar)
        {
            case 'n':    // <name
                if (namePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <name> element"); 
                    return false;
                }
                else
                    namePresent = true;
                pchar++;
                while(*startName++  == *pchar) pchar++;
                if( (pchar - *p)  != 5) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a name element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <name> element");
                             return false;
                        }
                        pchar++;
                        // process <name> element text
                        // there better be a </name
                        ptemp = strstr( pchar, endName);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->name = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </name
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </name
                        // move to first char after </name
                        pchar += 6;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of name
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 's':    // <source
                if (sourcePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <source> element"); 
                    return false;
                }
                else
                    sourcePresent = true;
                pchar++;
                while(*startSource++  == *pchar) pchar++;
                if( (pchar - *p)  != 7) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a source element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <source> element");
                             return false;
                        }
                        pchar++;
                        // process <source> element text
                        // there better be a </source
                        ptemp = strstr( pchar, endSource);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->source = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </source
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </source
                        // move to first char after </source
                        pchar += 8;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of source
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'd':    // <description
                if (descriptionPresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <description> element"); 
                    return false;
                }
                else
                    descriptionPresent = true;
                pchar++;
                while(*startDescription++  == *pchar) pchar++;
                if( (pchar - *p)  != 12) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a description element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <description> element");
                             return false;
                        }
                        pchar++;
                        // process <description> element text
                        // there better be a </description
                        ptemp = strstr( pchar, endDescription);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->description = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </description
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </description
                        // move to first char after </description
                        pchar += 13;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of description
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'f':    // <fileCreator
                if (fileCreatorPresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <fileCreator> element"); 
                    return false;
                }
                else
                    fileCreatorPresent = true;
                pchar++;
                while(*startFileCreator++  == *pchar) pchar++;
                if( (pchar - *p)  != 12) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a fileCreator element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element");
                             return false;
                        }
                        pchar++;
                        // process <fileCreator> element text
                        // there better be a </fileCreator
                        ptemp = strstr( pchar, endFileCreator);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->fileCreator = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </fileCreator
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </fileCreator
                        // move to first char after </fileCreator
                        pchar += 13;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of fileCreator
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case 'l':    // <licence
                if (licencePresent)
                {  
                    osilerror_wrapper( pchar,osillineno,"duplicate <licence> element"); 
                    return false;
                }
                else
                    licencePresent = true;
                pchar++;
                while(*startLicence++  == *pchar) pchar++;
                if( (pchar - *p)  != 8) 
                {
                    osilerror_wrapper( pchar,osillineno,"tag not recognized"); 
                    return false;
                }
                else
                {
                    // we have a licence element, process the text
                    // burn the whitespace
                    BURNWHITESPACE( pchar );
                    if( *pchar == '/')
                    {
                        pchar++;
                        // better point to a '>'
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element"); 
                            return false;
                        }
                        pchar++;
                    }
                    else    
                    {
                        // pchar better be '>' or there is an error
                        if(*pchar != '>') 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element");
                             return false;
                        }
                        pchar++;
                        // process <licence> element text
                        // there better be a </licence
                        ptemp = strstr( pchar, endLicence);
                        if( ptemp == NULL) 
                        {  
                            osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); 
                            return false;
                        }
                        elementSize = ptemp - pchar;
                        pelementText = new char[ elementSize + 1];
                        strncpy(pelementText, pchar, elementSize);
                        pelementText[ elementSize] = '\0';
                        osinstance->instanceHeader->licence = pelementText;
                        //garbage collection
                        delete [] pelementText;
                        // move pchar up to the end of </licence
                        while(elementSize-- > 0)
                        {
                            if(*pchar++ == '\n') (*osillineno)++;
                        }
                        // pchar should now be pointing to the start of </licence
                        // move to first char after </licence
                        pchar += 9;
                        // get rid of the whitespace
                        BURNWHITESPACE( pchar );
                        // we better have the '>' for the end of licence
                        if(*pchar++ != '>')
                        {
                            osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); 
                            return false;
                        }   
                    }
                }
                break;

            case '/':    // </instanceHeader
                pchar++;
                while(*endInstanceHeader++  == *pchar) pchar++;
                if( (pchar - *p)  != 16) 
                {
                    osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); 
                    return false;
                }
                // pchar now points to the first character after </instanceHeader
                // get rid of white space
                BURNWHITESPACE( pchar );
                // pchar must point to '>' or there is an error
                if(*pchar != '>')
                {  
                    osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); 
                    return false;
                }
                pchar++;
                *p = pchar;
                return true;

            default:
                {osilerror_wrapper( pchar,osillineno,"tag not recognized"); return false;}
        }
    }
    return false;
}//end parseInstanceHeader


bool parseInstanceData( const char **p, OSInstance *osinstance, int* osillineno){
    //
    const char *pchar = *p;
    const char *startInstanceData = "<instanceData";
    // at this point *pchar should be pointing to the first char after the > in </instanceHeader>
    // burn the white space and any comments
    FINDNEXTTAG( pchar );
    // pchar should be point to a '<', if not there is an error
    if(*pchar != '<'){  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData element"); return false;}
    // make sure the element is <instanceData    
    *p = pchar;
    while(*startInstanceData++  == *pchar) pchar++;
    if( (pchar - *p) != 13) {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); return false;}    
    // now burn whitespace
    BURNWHITESPACE( pchar );
    // pchar must point to '>' or there is an error
    if(*pchar == '>'){
        pchar++;
        // we are now pointing to the first char after <instanceData>
        // burn any whitespace and comments
        FINDNEXTTAG( pchar );    
        // we should be pointing to the '<' char in <variables>
        *p = pchar;
        if( parseVariables  ( p, osinstance, osillineno) != true) throw ErrorClass("error in parseVariables");
        if( parseObjectives ( p, osinstance, osillineno) != true) throw ErrorClass("error in parseObjectives");
        if( parseConstraints( p, osinstance, osillineno) != true) throw ErrorClass("error in parseConstraints");
        if( parseLinearConstraintCoefficients( p, osinstance, osillineno) != true) throw ErrorClass("error in parseLinearConstraintCoefficients");
    }else{
        //osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); 
        return true;
    }
    // we should be pointing to the '<' char in <variables>
    return true;
}// end parseInstanceData


bool parseVariables( const char **p,  OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();
    const char *c_numberOfVariables = "numberOfVariables";
    const char *startVariables = "<variables";
    const char *endVariables = "</variables";
    const char *startVar = "<var";
    const char *endVar = "</var";
    // the attributes
    char *attText = NULL;
    const char *name = "name";
    const char *type = "type";
    const char *mult = "mult";
    // others
    int i;
    int varcount = 0;
    int vt;
    int numberOfVariables = 0;
// variable attribute boolean variables
    bool varlbattON   = false;
    bool varubattON   = false;
    bool vartypeattON = false;
    bool varnameattON = false;
    bool varmultattON = false;
    bool foundVar = false;
    int varmult; 
    //
    // start parsing -- okay not to have variables 
    // burn white space and comments
    FINDNEXTTAG( ch );
    *p = ch;
    while(*startVariables++  == *ch) ch++;
    //if( (ch - *p) != 10) {  osilerror_wrapper( ch,osillineno,"incorrect <variables tag>"); return false;}
    if( (ch - *p) != 10) {   return true;}

    osinstance->instanceData->variables = new Variables();

    // find numberOfVariables attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while(*c_numberOfVariables++  == *ch) ch++;
    if( (ch - *p) != 17) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfVariables attribute in <variables tag>"); return false;}    
    // buf_index should be pointing to the first character after "numberOfVariables" attribute
    GETATTRIBUTETEXT;
    ch++;
    numberOfVariables = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // get rid of white space after the numberOfVariables element
    BURNWHITESPACE( ch );

    osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
    if (numberOfVariables > 0)
    {
        osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
        for (i = 0; i < numberOfVariables; i++)
        {
            osinstance->instanceData->variables->var[ i] = new Variable();
        } 
        // If there is at least one variable, this element must end with '>', not '/>' 
        // better have an > sign or not valid
        if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"variables element does not have a proper closing >"); return false;}
        ch++;
        // get rid of white space and comments
        FINDNEXTTAG( ch );
        // now loop over the var element when the numberOfVariables is strictly positive
        *p = ch;
        while(*startVar++  == *ch) ch++;
        if( (ch - *p) ==  4) foundVar = true;
        else {osilerror_wrapper( ch,osillineno,"there must be at least one <var> element"); return false;}
        startVar -= 5;
        while(foundVar)
        {
            varlbattON   = false;
            varubattON   = false;
            vartypeattON = false;
            varnameattON = false;
            varmultattON = false;
            varmult = 1;
            foundVar = false;
            vt = 0;
            // assume we are pointing to the first character after the r in <var
            // it should be whitespace
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>')
            {
                switch (*ch) 
                {
                case 'n':
                    *p = ch;
                    while(*name++  == *ch) ch++;
                    if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"error in variables name attribute"); return false;}
                    name -= 5;
                    if(varnameattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable name attributes"); return false;}
                    varnameattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->name=attText;
                    delete [] attText;
                    break;
                case 't':
                    *p = ch;
                    while(*type++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables type attribute"); return false;}
                    type -= 5;
                    if(vartypeattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable type attributes"); return false;}
                    vartypeattON = true;
                    GETATTRIBUTETEXT;
                    vt = returnVarType(attText[0]);
                    if( vt == 0 ) {  osilerror_wrapper( ch,osillineno,"variable type not recognized"); return false;}
                    osinstance->instanceData->variables->var[varcount]->type = attText[0];
                    delete [] attText;
                    break;
                case 'l':
                    ch++;
                    if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables lower bound attribute"); return false;}
                    if(varlbattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable lb attributes"); return false;}
                    varlbattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->lb = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'u':
                    ch++;
                    if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables upper bound attribute"); return false;}
                    if(varubattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable ub attributes"); return false;}
                    varubattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->variables->var[varcount]->ub = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while(*mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables mult attribute"); return false;}
                    mult -= 5;
                    if(varmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable mult attributes"); return false;}
                    varmultattON = true;
                    GETATTRIBUTETEXT;
                    varmult = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character"); 
                    return false;
                    break;
                }
                // reset default upper bound for binary variables
                if (vt == ENUM_VARTYPE_binary) 
                {
                    if (varubattON == false)
                        osinstance->instanceData->variables->var[varcount]->ub = 1.0;
                }
                ch++;
            }
            //
            // assume all the attributes have been processed
            // must have either /> or > and then whitespace and </var whitespace>
            if ( *ch != '/' && *ch != '>') 
            {  
                osilerror_wrapper( ch,osillineno,"incorrect end of <var> element");
                return false;
            }
            if (*ch == '/')
            {
                ch++;
                if(*ch != '>') 
                {
                    osilerror_wrapper( ch,osillineno,"incorrect end of <var> element");
                    return false;
                }
                // get rid of whitespace and comments
                ch++;
                FINDNEXTTAG( ch );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4)
                {
                    foundVar = true;
                    startVar -= 5;
                }
                else
                {
                    foundVar = false;
                    ch = *p;
                }
            }
            else
            {
                // the buf_index is the > at the end of the var element 
                // double check to make sure it really is a >
                if(*ch != '>') 
                {
                    osilerror_wrapper( ch,osillineno,"improper ending to a <var> element");
                    return false;
                }
                // look for </var
                // first get rid of white space
                ch++;
                BURNWHITESPACE( ch );
                // we should be at </var or there is an error
                *p = ch;
                while(*endVar++  == *ch) ch++;
                endVar -= 6;
                if( (ch - *p) != 5) 
                {
                    osilerror_wrapper( ch,osillineno,"</var> element missing");
                    return false;
                }
                // burn off the whitespace
                BURNWHITESPACE( ch );
                // better have an > to end </var
                if(*ch++ != '>')
                {
                    osilerror_wrapper( ch,osillineno,"</var> element missing >");
                    return false;
                }
                // look for a new <var> element
                // get rid of whitespace
                ch++;
                FINDNEXTTAG( ch );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4)
                {
                    foundVar = true;
                    startVar -= 5;
                }
                else
                {
                    foundVar = false;
                    ch = *p;
                }
            }
            if( ((varcount+varmult) <= numberOfVariables))
            {
                for (int k=1; k < varmult; k++)
                {
                    osinstance->instanceData->variables->var[varcount+k]->name 
                    = osinstance->instanceData->variables->var[varcount]->name;
                    osinstance->instanceData->variables->var[varcount+k]->type 
                    = osinstance->instanceData->variables->var[varcount]->type;
                    osinstance->instanceData->variables->var[varcount+k]->lb 
                    = osinstance->instanceData->variables->var[varcount]->lb;
                    osinstance->instanceData->variables->var[varcount+k]->ub 
                    = osinstance->instanceData->variables->var[varcount]->ub;
                }
            }
            varcount += varmult;

//            if( (varcount >= numberOfVariables) && (foundVar == true) ) 
        // foundVar is bool, so =1 if true, =0 if false
            if( (varcount+foundVar) > numberOfVariables)
            {
                osilerror_wrapper( ch,osillineno,"actual number of variables exceeds attribute numberOfVariables");
                return false;
            }
        }// end while(foundVar)
        if(varcount < numberOfVariables)
        {
            osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is greater than actual number found");   
            return false;
        }
        // get the </variables> tag
        *p = ch;
        while(*endVariables++  == *ch) ch++;
        if( (ch - *p) != 11)
        {
            osilerror_wrapper( ch,osillineno,"cannot find </variables> tag");
            return false;
        }
        BURNWHITESPACE( ch );
        // better have >
        if(*ch != '>')
        {
            osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag");
            return false;
        }
        ch++;
    }
    else
    {   // end if(numberOfVariables > 0)
        // error if the number is negative
        if (numberOfVariables < 0)
        {
            osilerror_wrapper( ch,osillineno,"cannot have a negative number of variables");
            return false;
        }
        // if we are here we have numberOfVariables = 0
        // must close with /> or </variables>
        // get rid of white space
        BURNWHITESPACE( ch );
        if( *ch == '/')
        {
            // better have a >
            ch++;
            if( *ch  != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly closed variables tag");
                return false;
            }
            ch++;
        }
        else
        {
            // if we are here we must have an '>' and then  </variables> tag
            if( *ch  != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly closed variables tag");
                return false;
            }
            ch++;
            // burn white space and comments
            FINDNEXTTAG( ch );
            *p = ch;
            while( *endVariables++  == *ch) ch++;
            if ( (ch - *p) != 11)
            {
                osilerror_wrapper( ch,osillineno, "cannot find </variables> tag");
                return false;
            }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>')
            {
                osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag");
                return false;
            }
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE VARIABLES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseVariables


bool parseObjectives( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    int ki, numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();
    const char *c_numberOfObjectives = "numberOfObjectives";
    const char *startObjectives = "<objectives";
    const char *endObjectives = "</objectives";
    const char *startObj = "<obj";
    const char *endObj = "</obj";
    // attributes
    char *attText = NULL;
    const char *constant = "constant";
    const char *maxOrMin = "maxOrMin";
    const char *numberOfObjCoef = "numberOfObjCoef";
    const char *weight = "weight";
    const char *name = "name";
    const char *mult = "mult";
    // others
    int i;
    // objective function attribute boolean variables
    bool objmaxOrMinattON = false;
    bool objnameattON = false;
    bool objconstantattON = false;
    bool objweightattON = false;
    bool objmultattON = false;
    bool objnumberOfObjCoefattON = false;
    int objcount = 0;
    int numberOfObjectives;
    bool foundObj;
    int objmult; 
    // start parsing
    // burn white space and comments
    FINDNEXTTAG( ch );
    // if present, we should be pointing to <objectives element if there -- it is not required
    *p = ch;
    while( *startObjectives++  == *ch) ch++;
    if( (ch - *p) != 11) {
        //  note if we are here even though ch > *p we want to return *p
        return true;
    }

    osinstance->instanceData->objectives = new Objectives();

    // find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
    // However if the  number attribute is missing assume it is 1 
    // eat the white space
    BURNWHITESPACE( ch );
    // we just ate the white space. If numberOfObjectives is missing we assume it is 1
    // we therefore must have > char
    if(*ch == '>'){
        numberOfObjectives = 1;
        //ch++;
    }
    else{
        *p = ch;
        while( *c_numberOfObjectives++  == *ch) ch++;
        if( (ch - *p) != 18) {  osilerror_wrapper( ch,osillineno,"<objectives> tag needs numberOfObjectives or <obj> element"); return false;}    
        GETATTRIBUTETEXT;
        numberOfObjectives = atoimod1( osillineno, attText, attTextEnd);
        delete [] attText;
        ch++;
    }
    if(numberOfObjectives > 0){
        // get rid of white space after the numberOfObjectives attribute
        BURNWHITESPACE( ch );
        // we must have an >
        /*if(*ch == '/'){
            ch++;
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false; }
            else{
                if(numberOfObjectives > 0){   osilerror_wrapper( ch,osillineno,"numberOfObjectives positive but there are no objectives"); return false;}
                return false;
            }
        }*/
        //  we better have an > 
        if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false;} 
        osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
        if (numberOfObjectives < 0)
        {
            osilerror_wrapper( ch,osillineno,"cannot have a negative number of objectives");
            return false;
        }
        if (numberOfObjectives > 0)
            osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
        for(i = 0; i < numberOfObjectives; i++){
            osinstance->instanceData->objectives->obj[ i] = new Objective();
        }     
    // get rid of white space and any comments after the <objectives> element
    FINDNEXTTAG( ch );
    // now loop over the obj elements, there must be at least one obj element
    *p = ch;
    while( *startObj++  == *ch) ch++;
    if( (ch - *p) == 4) foundObj = true;
        else {  osilerror_wrapper( ch,osillineno,"there must be at least one <obj> element"); return false;}
    startObj -= 5;
    start = clock();    
    while(foundObj){
        objmaxOrMinattON = false;
        objnameattON = false;
        objconstantattON = false;
        objweightattON = false;
        objmultattON = false;
        objnumberOfObjCoefattON = false;
        objmult = 1;
        // assume we are pointing to the first character after the j in <obj
        // it should be a space so let's increment ch
        ch++;
        while(*ch != '/' && *ch != '>'){
            switch (*ch) {
            case 'n':
                if( *(ch+1) == 'u'){
                    *p = ch;
                    while( *numberOfObjCoef++  == *ch) ch++;
                    numberOfObjCoef -= 16;
                    if( ( (ch - *p) != 15)  ) {  osilerror_wrapper( ch,osillineno,"error in objective numberOfObjCoef attribute"); return false;}
                    else{
                        if(objnumberOfObjCoefattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj numberOfObjCoef attributes"); return false;}
                        objnumberOfObjCoefattON = true;
                        GETATTRIBUTETEXT;
                        osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod1( osillineno,attText, attTextEnd);
                        if(osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef > 0 && osinstance->instanceData->variables->numberOfVariables == 0){  osilerror_wrapper( ch,osillineno,"we have zero variables, but have objective function coefficients"); return false;}
                        osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
                        for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
                        delete [] attText;
                    }
                }
                else{
                    *p = ch;
                    while( *name++  == *ch) ch++;
                    name -= 5;
                    if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective name attribute"); return false;}
                    else{
                        if(objnameattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj name attributes"); return false;}
                        objnameattON = true;
                        GETATTRIBUTETEXT;
                        osinstance->instanceData->objectives->obj[objcount]->name=attText;
                        delete [] attText;
                    }
                }
                break;
            case 'c':
                *p = ch;
                while( *constant++  == *ch) ch++;
                constant -= 9;    
                if( ( (ch - *p) != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective constant attribute"); return false;}
                else{
                    if(objconstantattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj constant attributes"); return false;}
                    objconstantattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                }
                break;
            case 'w':
                *p = ch;
                while( *weight++  == *ch) ch++;
                weight -= 7;
                if( ( (ch - *p) != 6)  ) {  osilerror_wrapper( ch,osillineno,"error in objective weight attribute"); return false;}
                else{
                    if(objweightattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj weight attributes"); return false;}
                    objweightattON = true;
                    GETATTRIBUTETEXT;
                    osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                }
                break;
            case 'm':
                if(*(ch+1) == 'a'){
                    *p = ch;
                    while( *maxOrMin++  == *ch) ch++;
                    maxOrMin -= 9;
                    if( ( ( ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective maxOrMin attribute"); return false;}
                    else{
                        if(objmaxOrMinattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj maxOrMin attributes"); return false;}
                        objmaxOrMinattON = true;
                        GETATTRIBUTETEXT;
                        if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror_wrapper( ch,osillineno,"maxOrMin attribute in objective must be a max or min"); return false;}
                        osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
                        delete [] attText;
                    }
                }
                else{
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    mult -= 5;
                    if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective mult attribute"); return false;}
                    else{
                        if(objmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many obj mult attributes"); return false;}
                        objmultattON = true;
                        GETATTRIBUTETEXT;
                        objmult = atoimod1( osillineno,attText, attTextEnd);
                        delete [] attText;
                    }
                }
                break;
            // come back and do multiplicity
            case ' ':
                break;
            case '\n':
                (*osillineno)++;
                break;
            case '\t':
                break;
            case '\r':
                break;
            default:
                 
                osilerror_wrapper( ch,osillineno,"invalid attribute character");
                return false;
                break;
            }
            ch++;
        }
        //
        // assume all the attributes have been processed
        // must have either /> or > and then whitespace and </obj whitespace>
        if( *ch != '/' && *ch != '>') {   osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
        if(*ch == '/'){
            ch++;
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
            // get rid of whitespace and comments
            ch++;
            FINDNEXTTAG( ch );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        else{
            // the ch is the > at the end of the obj element
            // double check to make sure it really is a >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to an <obj> element"); return false;}
            // look for </obj
            // fist get rid of white space
            ch++;
            // first get the <coef> elements
            parseObjCoef(&ch,  objcount, osinstance, osillineno);
            FINDNEXTTAG( ch );
            // we should be at </obj or there is an error
            for(i = 0; endObj[i]  == *ch; i++, ch++);
            if(i != 5) {  osilerror_wrapper( ch,osillineno,"</obj> element missing or too many <coef> elements"); return false;}
            // burn off the whitespace
            BURNWHITESPACE( ch );
            // better have an > to end </obj
            if(*ch++ != '>'){   osilerror_wrapper( ch,osillineno,"</obj> element ill-formed"); return false;}
            // look for a new <obj> element
            // get rid of whitespace
            FINDNEXTTAG( ch );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        if ( (objcount+objmult) <= numberOfObjectives)
        {
            for (int k=1; k < objmult; k++)
            {
                osinstance->instanceData->objectives->obj[objcount+k]->name 
                = osinstance->instanceData->objectives->obj[objcount]->name;
                osinstance->instanceData->objectives->obj[objcount+k]->maxOrMin 
                = osinstance->instanceData->objectives->obj[objcount]->maxOrMin;
                osinstance->instanceData->objectives->obj[objcount+k]->constant 
                = osinstance->instanceData->objectives->obj[objcount]->constant;
                osinstance->instanceData->objectives->obj[objcount+k]->weight 
                = osinstance->instanceData->objectives->obj[objcount]->weight;
                osinstance->instanceData->objectives->obj[objcount+k]->numberOfObjCoef 
                = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
                if (osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef > 0)
                {
                    osinstance->instanceData->objectives->obj[objcount+k]->coef
                    = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
                    for (int i = 0; 
                             i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef;
                             i++)
                    {
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i] = new ObjCoef();
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->idx = 
                          osinstance->instanceData->objectives->obj[objcount]->coef[i]->idx;
                        osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->value = 
                          osinstance->instanceData->objectives->obj[objcount]->coef[i]->value;
                    }
                }
            }
        }
        objcount += objmult;
//        if( (objcount >= numberOfObjectives) && (foundObj == true))
        // foundObj is bool, so =1 if true, =0 if false
        if( (objcount+foundObj) > numberOfObjectives)
        {
            osilerror_wrapper( ch,osillineno,"actual number of objectives exceeds attribute numberOfObjectives"); return false;
        }
    }
    if(objcount < numberOfObjectives) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is greater than actual number found"); return false;}
    ch -= i;
    // get the </objectives> tag
    for(i = 0; endObjectives[i]  == *ch; i++, ch++);
    if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}    
    ch++;
    } // finish the (if numberOfObjectives > 0)
    else{
        // error if the number is negative
        if(numberOfObjectives < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of objectives"); return false;}
        // if we are here we have exactly 0 objectives 
        // must close with /> or </objectives>
        // get rid of white space
        BURNWHITESPACE( ch );
        if( *ch == '/'){
            // better have a >
            ch++;
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
            ch++;
        }
        else{
            // if we are here we must have an '>' and then  </objectives> tag
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
            ch++;
            // burn white space and comments
            FINDNEXTTAG( ch );
            for(i = 0; endObjectives[i]  == *ch; i++, ch++);
            if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}    
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseObjectives

bool parseConstraints( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock();    
    const char *c_numberOfConstraints = "numberOfConstraints";
    const char *startConstraints = "<constraints";
    const char *endConstraints = "</constraints";
    const char *startCon = "<con";
    const char *endCon = "</con";
    // attributes
    char *attText = NULL;
    const char *name = "name";
    const char *constant = "constant";
    const char *mult = "mult";
    // others
    int i; 
    int concount = 0;
    int numberOfConstraints = 0;
    // constraint attribute boolean variables
    bool conlbattON = false ;
    bool conubattON  = false;
    bool connameattON = false;
    bool conconstantattON  = false;
    bool conmultattON = false;
    bool foundCon = false;
    int conmult;
    // 
    // start parsing -- ok not to have constraints
    // burn white space
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <constraints element if there -- it is not required
    *p = ch;
    for(i = 0; startConstraints[i]  == *ch; i++, ch++);
    while( *startConstraints++  == *ch) ch++;
    if( (ch - *p) != 12) {
        //  *p is the correct value for the pointer
        return true;
    }

    osinstance->instanceData->constraints = new Constraints();

    // find numberOfConstraints attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while( *c_numberOfConstraints++  == *ch) ch++;
    if( (ch - *p) != 19) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfConstraints attribute in <constraints> tag"); return false;}    
    // ch should be pointing to the first character after numberOfConstraints
    GETATTRIBUTETEXT;
    ch++;
    numberOfConstraints = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // key if
    //
    if(numberOfConstraints > 0){
        osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
        osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
        for(i = 0; i < numberOfConstraints; i++){
            osinstance->instanceData->constraints->con[ i] = new Constraint();
        } 
    // get rid of white space after the numberOfConstraints element
    BURNWHITESPACE( ch );
    //  we better have an > 
    if( *ch++ != '>') {   osilerror_wrapper( ch,osillineno,"the constraints element does not have a proper closing"); return false;} 
    // get rid of white space and comments after the <constraints> element
    FINDNEXTTAG( ch );
    // now loop over the con elements, there must be at least one con element
    *p = ch;
    while( *startCon++  == *ch) ch++;
    if( (ch - *p) == 4) foundCon = true;
        else {  osilerror_wrapper( ch,osillineno,"there must be at least one <con> element"); return false;}
    startCon -= 5;
    while(foundCon){
        conlbattON = false ;
        conubattON  = false;
        connameattON = false;
        conconstantattON  = false;
        conmultattON = false;
        conmult = 1;

        // assume we are pointing to the first character after the n in <con
        // it should be a space so let's increment ch
        BURNWHITESPACE( ch );
        while(*ch != '/' && *ch != '>'){
            switch (*ch) {
            case 'n':
                *p = ch;
                while( *name++  == *ch) ch++;
                if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints name attribute"); return false;}
                if(connameattON == true) {  osilerror_wrapper( ch,osillineno,"too many con name attributes"); return false;}
                name -= 5;
                connameattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->name=attText;
                delete [] attText;
                break;
            case 'c':
                *p = ch;
                while( *constant++  == *ch) ch++;
                if( ((ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in constraint constant attribute"); return false;}
                if(conconstantattON == true) {  osilerror_wrapper( ch,osillineno,"too many con constant attributes"); return false;}
                constant -= 9;
                conconstantattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->constant=atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'l':
                ch++;
                if(*ch++ != 'b') {   osilerror_wrapper( ch,osillineno,"error in constraint lb attribute"); return false;}
                if(conlbattON == true) {  osilerror_wrapper( ch,osillineno,"too many con lb attributes"); return false;}
                conlbattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->lb = atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'u':
                ch++;
                if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in constraint ub attribute"); return false;}
                if(conubattON == true) {  osilerror_wrapper( ch,osillineno,"too many con ub attributes"); return false;}
                conubattON = true;
                GETATTRIBUTETEXT;
                osinstance->instanceData->constraints->con[concount]->ub = atofmod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case 'm':
                *p = ch;
                while( *mult++  == *ch) ch++;
                if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints mult attribute"); return false;}
                if(conmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many con mult attributes"); return false;}
                mult -= 5;
                conmultattON = true;
                GETATTRIBUTETEXT;
                conmult = atoimod1( osillineno,attText, attTextEnd);
                delete [] attText;
                break;
            case ' ':
                break;
            case '\n':
                (*osillineno)++;
                break;
            case '\t':
                break;
            case '\r':
                break;
            default:
                osilerror_wrapper( ch,osillineno,"invalid attribute character");
                return false;
                break;
            }
            ch++;
        }
        //
        // assume all the attributes have been processed
        // must have either /> or > and then whitespace and </con whitespace>
        if( *ch != '/' && *ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
        if(*ch == '/'){
            ch++;
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
            // get rid of whitespace
            ch++;
            FINDNEXTTAG( ch );
            // either have another <con> element or foundCon = false;
            *p = ch;
            while( *startCon++  == *ch) ch++;
            if( (ch - *p) == 4){
                 foundCon = true;
                 startCon -= 5;
            }
            else{
                foundCon = false;
                ch = *p;
            }
        }
        else{
            // the ch is the > at the end of the con element 
            // double check to make sure it really is a >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <con> element"); return false;}
            // look for </con
            // fist get rid of white space
            ch++;
            FINDNEXTTAG( ch );
            // we should be at </con or there is an error
            *p = ch;
            while( *endCon++  == *ch) ch++;
            if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</con> element missing"); return false;}
            endCon -= 6;
            // burn off the whitespace
            BURNWHITESPACE( ch );
            // better have an > to end </con
            if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</con> element missing >"); return false;}
            // look for a new <con> element
            // get rid of whitespace
            ch++;
            FINDNEXTTAG( ch );
            // either have another <con> element or foundVar = false;
            *p = ch;
            while( *startCon++  == *ch) ch++;
            if( (ch - *p) == 4){
                 foundCon = true;
                 startCon -= 5;
            }
            else{
                 foundCon = false;
                 ch = *p;
            }
        }
        if( (concount+conmult) <= numberOfConstraints)
        {
            for (int k=1; k < conmult; k++)
            {
                osinstance->instanceData->constraints->con[concount+k]->name
                = osinstance->instanceData->constraints->con[concount]->name;
                osinstance->instanceData->constraints->con[concount+k]->constant
                = osinstance->instanceData->constraints->con[concount]->constant;
                osinstance->instanceData->constraints->con[concount+k]->lb
                = osinstance->instanceData->constraints->con[concount]->lb;
                osinstance->instanceData->constraints->con[concount+k]->ub
                = osinstance->instanceData->constraints->con[concount]->ub;
            }
        }
        concount += conmult;

//        if( (concount >= numberOfConstraints) && (foundCon == true))
        // foundCon is bool, so =1 if true, =0 if false
        if( (concount+foundCon) > numberOfConstraints)
        {
            osilerror_wrapper( ch,osillineno,"actual number of constraints exceeds attribute numberOfConstraints");
            return false;
        }
    }
    if(concount < numberOfConstraints) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is greater than actual number found"); return false;}
    // get the </constraints> tag
    *p = ch;
    while( *endConstraints++  == *ch) ch++;
    if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag");    return false;}
    ch++;
    }// end if(numberOfConstraints > 0)
    else{
        // error if the number is negative
        if(numberOfConstraints < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of constraints"); return false;}
        // if we are here we have numberOfConstraints = 0
        // must close with /> or </constraints>
        // get rid of white space
        FINDNEXTTAG( ch );
        if( *ch == '/'){
            // better have a >
            ch++;
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
            ch++;
        }
        else{
            // if we are here we must have an '>' and then  </constraints> tag
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
            ch++;
            // burn white space
            FINDNEXTTAG( ch );
            *p = ch;
            while( *endConstraints++  == *ch) ch++;
            if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false; }
            BURNWHITESPACE( ch );
            // better have >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag"); return false;}    
            ch++;
        }
    }
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients( const char **p, OSInstance *osinstance, int* osillineno){;
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;    
    const char *c_numberOfValues = "numberOfValues";
    const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
    const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
    // attributes
    char *attText = NULL;
    // others
    int numberOfValues;
    // start parsing
    // burn white space and comments
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
    *p = ch;
    while( *startlinearConstraintCoefficients++  == *ch) ch++;
    if( (ch - *p) != 29) {
        //reset ch
        ch = *p;
        return true;
    }

    osinstance->instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients();

    // find numberOfValues attribute
    // eat the white space
    BURNWHITESPACE( ch );
    *p = ch;
    while( *c_numberOfValues++  == *ch) ch++;
    if( (ch - *p) != 14) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
    // ch should be pointing to the first character after numberOfValues
    GETATTRIBUTETEXT;
    ch++;
    numberOfValues = atoimod1( osillineno, attText, attTextEnd);
    if(numberOfValues > 0 && osinstance->instanceData->variables->numberOfVariables == 0){  osilerror_wrapper( ch,osillineno,"we have zero variables, but A matrix coefficients"); return false;}
    delete [] attText;
    if(numberOfValues <= 0) {  osilerror_wrapper( ch,osillineno,"the number of nonlinear nonzeros must be positive"); return false;}
    osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
    // get rid of white space after the numberOfConstraints element
    BURNWHITESPACE( ch );
    // we should have either an />  OR an >
    if(*ch == '/'){
        ch++;
        if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the linearConstraintCoefficients element does not have a proper closing"); return false;} 
        else{
            if(numberOfValues > 0) {  osilerror_wrapper( ch,osillineno,"numberOfValues positive, but there are no values"); return false;}
            return false;
        }        
    }
    //  we better have an > 
    if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
    // get rid of white space and commentsafter the <linearConstraintCoefficients> element
    FINDNEXTTAG( ch );
    if(  parseStart(  &ch, osinstance, osillineno) != true) {osilerror_wrapper( ch,osillineno,"error processing <start> element"); return false;}
//    if( (parseColIdx( &ch, osinstance, osillineno) != true) && (parseRowIdx( &ch, osinstance, osillineno) != true)) return false;
//    if( (parseColIdx( &ch, osinstance, osillineno) == true) && (parseRowIdx( &ch, osinstance, osillineno) == true)) {osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); return false;}

    if(  parseColIdx( &ch, osinstance, osillineno) == true) // <colIdx> is found as first element
    {
        if( parseRowIdx( &ch, osinstance, osillineno) == true) //also have <rowIdx> --- can't happen
        {
            osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); 
            return false;
        }
    }
    else //<colIdx> is not the first element
    {
        if( parseRowIdx( &ch, osinstance, osillineno) != true) // neither <rowIdx> nor <colIdx> is present
        {
            osilerror_wrapper( ch,osillineno,"must have either RowIdx or ColIdx"); 
            return false;
        }
        else //<rowIdx> is found as first element
        {
            if ( parseColIdx( &ch, osinstance, osillineno) == true ) //also have <colIdx> --- can't happen 
            {
                osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); 
                return false;
            }
        }
    }

    if(  parseValue(  &ch, osinstance, osillineno) != true) {osilerror_wrapper( ch,osillineno, "could not parse <value> element"); return false;}
    // get the </linearConstraintCoefficients> tag
    FINDNEXTTAG( ch );
    *p = ch;
    while( *endlinearConstraintCoefficients++  == *ch) ch++;
    if( (ch - *p) != 30) {  osilerror_wrapper( ch,osillineno, "cannot find </linearConstraintCoefficients> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </linearConstraintCoefficients> tag"); return false;}
    ch++;    
    *p = ch;
    return true;
}//end parseLinearConstraintCoefficients

bool parseStart(const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startStart = "<start";
    const char* endStart = "</start";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    FINDNEXTTAG( ch );
    // if, present we should now be pointing to <start element 
    *p = ch;
    while( *startStart++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <start
    BURNWHITESPACE( ch );
    // we should have an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <start> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL) {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
        intvec = (int*)&base64decodeddata[0];
        int k, kp;
        kp = 0;
        for (i = 0; i < (base64decodeddatalength/dataSize); i++)
        {
            k = *(intvec++);
            if (k < kp)
            {
                osilerror_wrapper( ch,osillineno,"<start> must have nondecreasing entries ");
                 return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = k;
            kp = k;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        osinstance->instanceData->linearConstraintCoefficients->start->el = 
        new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
        osinstance->instanceData->variables->numberOfVariables) + 1];
        while(foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in starts incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    if (elincr < 0)
                    {
                        osilerror_wrapper( ch,osillineno,"incr of start array cannot be negative");
                        return false;
                    }
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in starts mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }

            // start eating white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            
            // we better not exceed allocation
            if(kount + elmult > std::max(osinstance->instanceData->constraints->numberOfConstraints,
                                         osinstance->instanceData->variables->numberOfVariables) + 1 )
            {
                osilerror_wrapper( ch, osillineno,"number of start elements exceeds the maximum number of rows or columns plus  1");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);
            int kp;
            if (kount == 0)
                kp = 0;
            else
                kp = osinstance->instanceData->linearConstraintCoefficients->start->el[ kount-1];

            for (int j=0; j < elmult; j++)
            {
                if (k < kp)
                {
                    osilerror_wrapper( ch,osillineno,
                        "column starts in linear constraint coefficient matrix must be non-decreasing"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->start->el[ kount+j] = k;
                kp = k;
                k += elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p)  == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                 foundEl = false;
                 ch = *p;
            }
        }    
        
        if(osinstance->instanceData->linearConstraintCoefficients->start->el[ kount - 1 ] != 
        osinstance->instanceData->linearConstraintCoefficients->numberOfValues ) 
        osilerror_wrapper( ch, osillineno,"the value of the last start element is not equal to numberOfValues");    
    }
    // get the </start> tag
    *p = ch;
    while( *endStart++  == *ch) ch++;
    if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </start> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </start> tag");    return false;}
    ch++;    
    // get the end element
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE STARTS  = %f\n", duration);
    #endif
    *p = ch;
    osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements = kount;

    return true;
}//end parseStart

bool parseRowIdx( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startRowIdx = "<rowIdx";
    const char* endRowIdx = "</rowIdx";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    int numberOfEl;
    
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <rowIdx element 
    *p = ch;
    while( *startRowIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <rowIdx
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <rowIdx> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<rowIdx> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        numberOfEl = (base64decodeddatalength/dataSize);
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[numberOfEl ];
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = numberOfEl;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->variables->numberOfVariables + 1;
        intvec = (int*)&base64decodeddata[0];
        int k;
        for(i = 0; i < numberOfEl; i++)
        {
            k = *(intvec++);
            if (k < 0 || k >= osinstance->instanceData->constraints->numberOfConstraints)
            {
                osilerror_wrapper( ch,osillineno,"row index out of bounds"); 
                return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = k;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        // if we are here we are storing the problem by column
        // this means the number of start elements must equal the number of columns + 1
        if( osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->variables->numberOfVariables  + 1)
        osilerror_wrapper( ch, osillineno,"we are storing in column major format, but number of start elements not equal number of variables + 1");
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->variables->numberOfVariables + 1;
        while(foundEl){
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in rowIdx incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in rowIdx mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }

            // start munging white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // mung white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {   osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of rowIdx elements exceeds the number declared");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);

            for (int j=0; j < elmult; j++)
            {
                if (k < 0 || k >= osinstance->instanceData->constraints->numberOfConstraints)
                {
                    osilerror_wrapper( ch,osillineno,
                        "row index out of bounds in linear constraint coefficient matrix"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount+j] = k;
                k += elincr;
            }

            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p)  != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start munging white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                foundEl = true;
                startEl -= 4;
            }
            else{
                foundEl = false;
                ch = *p;
            }
        }
    }
    // get the </rowIdx> tag
    *p = ch;
    while( *endRowIdx++  == *ch) ch++;
    if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </rowIdx> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </rowIdx> tag");}    
    ch++;    
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
    #endif
    *p = ch;
     return true;
}//end parseRowIdx


bool parseColIdx( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startColIdx = "<colIdx";
    const char* endColIdx = "</colIdx";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    int elincr;
    int numberOfEl;
    
    FINDNEXTTAG( ch );
    // if, present we should be pointing to <colIdx element 
    *p = ch;
    while( *startColIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <colIdx
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <colIdx> element"); return false;}
    ch++;
    // get rid of white space and comments
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<colIdx> must have children or base64 data"); return false;}
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        int *intvec = NULL;
        numberOfEl = (base64decodeddatalength/dataSize);
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[numberOfEl ];
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = numberOfEl;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->constraints->numberOfConstraints + 1;
        intvec = (int*)&base64decodeddata[0];
        int k;
        for(i = 0; i < numberOfEl; i++)
        {
            k = *(intvec++);
            if (k < 0 || k >= osinstance->instanceData->variables->numberOfVariables)
            {
                osilerror_wrapper( ch,osillineno,"col index out of bounds"); 
                return false;
            }
            osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = k;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        // if we are here we are storing the problem by row
        // this means the number of start elements must equal the number of rows + 1
        if(osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->constraints->numberOfConstraints  + 1)
        osilerror_wrapper( ch, osillineno,"we are storing in row major format, but number of start elements not equal number of rows + 1");
        osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
        osinstance->instanceData->linearConstraintCoefficients->colIdx->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
        osinstance->instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = 0;
        osinstance->instanceData->linearConstraintCoefficients->start->numberOfEl = osinstance->instanceData->constraints->numberOfConstraints + 1;
        while(foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in colIdx incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atoimod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in colIdx mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }
        
            // start eating white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            // okay we better have a number, we will check later
            *p = ch;
            // find the end of the number, it better be an </el>
            // find </el
            while( *ch != '<' && *ch  != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of colIdx elements exceeds the number declared");
                return false; 
            }

            int k = atoimod1( osillineno, *p, ch);

            for (int j=0; j < elmult; j++)
            {
                if (k < 0 || k >= osinstance->instanceData->variables->numberOfVariables)
                {
                    osilerror_wrapper( ch,osillineno,
                        "col index out of bounds in linear constraint coefficient matrix"); 
                    return false;
                }
                osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount+j] = k;
                k += elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                 foundEl = false;
                 ch = *p;
            }
        }
    }
    // get the </colIdx> tag
    *p = ch;
    while( *endColIdx++  == *ch) ch++;        
    if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </colIdx> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </colIdx> tag"); return false;}    
    ch++;    
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
    #endif
    *p = ch;
     return true;
}//end parseColIdx

bool parseValue( const char **p, OSInstance *osinstance, int* osillineno){
    clock_t start, finish;
    #ifdef CHECK_PARSE_TIME
    double duration;
    #endif
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    start = clock(); 
    const char* startValue = "<value";
    const char* endValue = "</value";
    const char* startEl = "<el";
    const char* endEl = "</el";
    // attributes
    char *attText = NULL;
    const char *incr = "incr";
    const char *mult = "mult";
    int kount = 0;
    int i;
    // element attribute boolean variables
    bool elmultattON = false ;
    bool elincrattON = false;
    bool foundEl = false;
    int elmult;
    double elincr;
    FINDNEXTTAG( ch );
    // if present we should be pointing to <value element 
    *p = ch;
    while( *startValue++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <value
    BURNWHITESPACE( ch );
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <value> element"); return false;}
    ch++;
    // get rid of white space
    FINDNEXTTAG( ch );
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        long int dataSize = 0;
        char* b64string = parseBase64(&ch, &dataSize, osillineno );
        if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;};
        std::string base64decodeddata = Base64::decodeb64( b64string );
        int base64decodeddatalength = base64decodeddata.length();
        osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
        int kountChar = 0;
        int kj;
        /* Take care of Lou's memory alignment problem */
        /* dataSize had better equal sizeof( double) or we need to abandon ship */
        if( sizeof( double)  != dataSize ) {  
            osilerror_wrapper( ch, osillineno, 
                "base 64 encoded with a size of double different than on this machine"); 
            return false;
        }    
        union doubleBuffer{
            char memAlign[sizeof(double)];
            double dble;
        };
        doubleBuffer dbuf;
        for(i = 0; i < (base64decodeddatalength/dataSize); i++){
            for(kj = 0; kj < dataSize; kj++){
                dbuf.memAlign[ kj] = base64decodeddata[kountChar];
                kountChar++;
            }
            osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = dbuf.dble;
            //std::cout << dbuf.dble << std::endl;
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        osinstance->instanceData->linearConstraintCoefficients->value->el = 
            new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
        while( foundEl){
        
            elmultattON = false ;
            elincrattON  = false;
            elmult = 1;
            elincr = 0;

            // assume we are pointing to the first character after the l in <el
            // it should be a space so let's increment ch
            BURNWHITESPACE( ch );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
                case 'i':
                    *p = ch;
                    while( *incr++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in values incr attribute"); return false;}
                    if(elincrattON == true) {  osilerror_wrapper( ch,osillineno,"too many el incr attributes"); return false;}
                    incr -= 5;
                    elincrattON = true;
                    GETATTRIBUTETEXT;
                    elincr = atofmod1( osillineno,attText, attTextEnd);
                    delete [] attText;
                    break;
                case 'm':
                    *p = ch;
                    while( *mult++  == *ch) ch++;
                    if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in values mult attribute"); return false;}
                    if(elmultattON == true) {  osilerror_wrapper( ch,osillineno,"too many el mult attributes"); return false;}
                    mult -= 5;
                    elmultattON = true;
                    GETATTRIBUTETEXT;
                    elmult = atoimod1( osillineno,attText, attTextEnd);
                    if (elmult <= 0)
                    {
                        osilerror_wrapper( ch,osillineno,"el mult must be positive");
                        return false;
                    }
                    delete [] attText;
                    break;
                case ' ':
                    break;
                case '\n':
                    (*osillineno)++;
                    break;
                case '\t':
                    break;
                case '\r':
                    break;
                default:
                    osilerror_wrapper( ch,osillineno,"invalid attribute character");
                    return false;
                    break;
                }
                ch++;
            }
        
            // start eat white space until an '>' is found,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            BURNWHITESPACE( ch );
            *p = ch;
            // find the end of the number, it better be an </el>
            // find the < which begins the </el
            while( *ch != '<' && *ch != EOF){
                ch++;
            }
            // we better have a <, or not valid
            if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // we better not exceed allocation
            if(kount + elmult > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) 
            {
                osilerror_wrapper( ch, osillineno,"number of nonzero elements exceeds the number declared");
                return false;           
            }
            osinstance->instanceData->linearConstraintCoefficients->value->el[ kount] = atofmod1( osillineno, *p, ch);
            for (int k=1; k < elmult; k++)
            {
                osinstance->instanceData->linearConstraintCoefficients->value->el[ kount+k] 
                = osinstance->instanceData->linearConstraintCoefficients->value->el[ kount] + k*elincr;
            }
            kount += elmult;
            // we are pointing to <, make sure there is /el
            *p = ch;
            while( *endEl++  == *ch) ch++;
            endEl -= 5;
            if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
            // start eating white space until an '>' is found for </el>,
            BURNWHITESPACE( ch );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space and comments again,
            FINDNEXTTAG( ch );
            // either have another <el> element or foundEl = false;
            *p = ch;
            while( *startEl++  == *ch) ch++;
            if( (ch - *p) == 3){
                 foundEl = true;
                 startEl -= 4;
            }
            else{
                foundEl = false;
                ch = *p;
            }
        }    
    }
    osinstance->instanceData->linearConstraintCoefficients->value->numberOfEl = osinstance->instanceData->linearConstraintCoefficients->numberOfValues;
    
    // get the </value> tag
    *p = ch;
    while( *endValue++  == *ch) ch++;
    if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </value> tag"); return false;}
    BURNWHITESPACE( ch );
    // better have >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </value> tag");     return false;}
    ch++;    
    if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients greater than number of values found"); return false;}
    if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients less than the number of values found"); return false;}
    finish = clock();
    #ifdef CHECK_PARSE_TIME
    duration = (double) (finish - start) / CLOCKS_PER_SEC; 
    printf("TIME TO PARSE VALUES = %f\n", duration);
    #endif
    *p = ch;
    return true;
}//end parseValue

bool parseObjCoef( const char **p, int objcount, OSInstance *osinstance, int* osillineno){
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    const char* startCoef = "<coef";
    const char* endCoef = "</coef";
    const char* c_idx = "idx";
    char *attText = NULL;
    int k;
    int numberOfObjCoef = 0; 
    if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {  osilerror_wrapper( ch,osillineno,"we can't have objective function coefficients without an objective function"); return false;}
    numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
    if(numberOfObjCoef > 0)    {
    for(k = 0; k < numberOfObjCoef; k++){
        FINDNEXTTAG( ch );
        // if, present we should be pointing to <coef element 
        *p = ch;
        while( *startCoef++  == *ch) ch++;
        if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"improper <coef> element"); return false;}
        startCoef -= 6;
        // get the idx attribute
        // eat the white space after <coef
        BURNWHITESPACE( ch );
        *p = ch;
        while( *c_idx++  == *ch) ch++;
        if( (ch - *p) != 3) {  osilerror_wrapper( ch,osillineno,"incorrect idx attribute in objective function <idx> tag"); return false;}    
        c_idx -= 4;
        // ch should be pointing to the first character after idx attribute
        GETATTRIBUTETEXT;
        int idx = atoimod1( osillineno, attText, attTextEnd);
        if (idx < 0 || idx >= osinstance->instanceData->variables->numberOfVariables)
        {
            osilerror_wrapper( ch,osillineno,"incorrect variable idx in objective function specification");
            return false;
        }
        osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx = idx;
        delete [] attText;
        ch++;    
        // eat white space
        BURNWHITESPACE( ch );
        // if we don't have a > there is an error
        if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect <coef> element")    ; return false;}    
        // we should be pointing to first character after <coef>
        *p = ch;
        // eat characters until we find <
        for(; *ch != '<' && *ch != EOF; ch++); 
        // put back here

        // we should be pointing to a < in the </coef> tag    
        if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"improper </coef> tag"); return false;}
        osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( osillineno, *p, ch);
        *p = ch;
        while( *endCoef++  == *ch) ch++;
        if( (ch - *p) != 6)  {  osilerror_wrapper( ch,osillineno,"improper </coef> element"); return false;}
        endCoef -= 7;
        // get rid of white space after </coef
        BURNWHITESPACE( ch );
        // if we don't have a > there is an error
        if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect </coef> element")    ; return false;}
    }
    }// end if(numberOfObjCoef > 0)
    *p = ch;
    return true;
}//end parseObjCoef

char *parseBase64(const char **p, long int *dataSize, int* osillineno ){
    long int ki;
    long int numChar;
    char *attTextEnd;
    const char *ch = *p;
    const char *sizeOf = "sizeOf";
    //char *numericType = "numericType";
    const char *startBase64BinaryData = "<base64BinaryData";
    const char *endBase64BinaryData = "</base64BinaryData";
    char *attText = NULL;
    char *b64string = NULL;
    int i;
    // start parsing
    for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
    if(i != 17) {
        ch -= i;
        *p = ch;
        return b64string;
    }
    // find sizeOf attribute
    // eat the white space
    BURNWHITESPACE( ch );
    for(i = 0; sizeOf[i]  == *ch; i++, ch++);
    if(i != 6) {  osilerror_wrapper( ch,osillineno,"incorrect sizeOf attribute in <base64BinaryData> element"); return false;}    
    // ch should be pointing to the first character after sizeOf
    GETATTRIBUTETEXT;
    ch++;
    *dataSize = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // since the element must contain b64 data,  this element must end with > 
    // eat the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"<base64BinaryData> element does not have a proper closing >"); return false;}
    ch++;
    // we are now pointing start of the data
    const char *b64textstart = ch;
    // eat characters until we get to the </base64BinaryData element
    for(; *ch != '<' && *ch != EOF; ch++);
    const char *b64textend = ch;
    // we should be pointing to </base64BinaryData>
    for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
    if(i != 18) { osilerror_wrapper( ch,osillineno," problem with <base64BinaryData> element"); return false;}
    long int b64len = b64textend - b64textstart;
    b64string = new char[ b64len + 1]; 
    for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
    b64string[ki] = '\0';    
    // burn the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"</base64BinaryData> element does not have a proper closing >"); return false;}
    ch++;
    BURNWHITESPACE( ch );
    *p = ch;
    return b64string;
}


double atofmod1(int* osillineno, const char *number, const char *numberend){
    double val;
       char *pEnd;
    val = os_strtod_wrap(number, &pEnd);
    // pEnd should now point to the first character after the number;
    // burn off any white space    
    for( ; ISWHITESPACE( *pEnd) || isnewline( *pEnd, osillineno); pEnd++ ) ;
    // pEnd should now point to numberend, if not we have an error
    if(pEnd != numberend) osilerror_wrapper( pEnd,   osillineno, "error in parsing an XSD:double");
    return val;
}//end atofmod



int atoimod1(int* osillineno, const char *number, const char *numberend){
    // modified atoi from Kernighan and Ritchie
    int ival;
    int i, sign;
    int endWhiteSpace;
    for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
    endWhiteSpace = i;
    sign = (number[ i] == '-') ? -1 : 1;
    if (number[ i] == '+' || number[ i] == '-') i++;
    for(ival = 0; ISDIGIT( number[ i]); i++){
        ival = 10*ival + (number[ i] - '0') ;
    }
    if(i == endWhiteSpace) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int" );     }
    // if we are here we should having nothing but white space until the end of the number
    for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
    if(number[i] == *numberend){
        return sign*ival;
    }
    else {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int"); return OSINT_MAX;    }
}//end atoimod1

void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg){
    const int numErrorChar = 20;
    char errorArray[100] = "";
    strncpy(errorArray, ch, numErrorChar);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "PARSER ERROR:  Input is either invalid or ill-formed: "  + error;
    outStr << error << endl;
    outStr << "Here are " ;
    outStr << numErrorChar ;
    outStr << " characters currently being pointed to in the input string: ";
    outStr << errorArray;
    outStr << endl;
    outStr << "See line number: " << *osillineno << endl;  
    error = outStr.str();
    //osillex_destroy(scanner);
    throw ErrorClass( error);
}//end osilerror_wrapper

void osil_empty_vectors( OSiLParserData* parserData){
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
}//end osil_empty_vectors

