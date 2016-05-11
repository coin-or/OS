
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         osilparse
#define yylex           osillex
#define yyerror         osilerror
#define yylval          osillval
#define yychar          osilchar
#define yydebug         osildebug
#define yynerrs         osilnerrs
#define yylloc          osillloc

/* Copy the first part of user declarations.  */



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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     ITEMTEXT = 260,
     INTEGER = 261,
     DOUBLE = 262,
     QUOTE = 263,
     TWOQUOTES = 264,
     BOOLEAN = 265,
     ENDOFELEMENT = 266,
     GREATERTHAN = 267,
     EMPTYSEMIDEFINITENESSATT = 268,
     SEMIDEFINITENESSATT = 269,
     NUMBEROFQTERMSATT = 270,
     NUMBEROFCONESATT = 271,
     NUMBEROFSTAGESATT = 272,
     IDXONEATT = 273,
     IDXTWOATT = 274,
     HORIZONATT = 275,
     STARTATT = 276,
     STARTIDXATT = 277,
     MATRIXIDXATT = 278,
     LBMATRIXIDXATT = 279,
     LBCONEIDXATT = 280,
     UBMATRIXIDXATT = 281,
     UBCONEIDXATT = 282,
     TEMPLATEMATRIXIDXATT = 283,
     REFERENCEMATRIXIDXATT = 284,
     VARREFERENCEMATRIXIDXATT = 285,
     OBJREFERENCEMATRIXIDXATT = 286,
     CONREFERENCEMATRIXIDXATT = 287,
     ORDERCONEIDXATT = 288,
     CONSTANTMATRIXIDXATT = 289,
     NORMSCALEFACTORATT = 290,
     DISTORTIONMATRIXIDXATT = 291,
     AXISDIRECTIONATT = 292,
     FIRSTAXISDIRECTIONATT = 293,
     SECONDAXISDIRECTIONATT = 294,
     OSILEND = 295,
     INSTANCEDATAEND = 296,
     INSTANCEDATASTARTEND = 297,
     QUADRATICCOEFFICIENTSSTART = 298,
     QUADRATICCOEFFICIENTSEND = 299,
     QTERMSTART = 300,
     QTERMEND = 301,
     CONESSTART = 302,
     CONESEND = 303,
     NONNEGATIVECONESTART = 304,
     NONNEGATIVECONEEND = 305,
     NONPOSITIVECONESTART = 306,
     NONPOSITIVECONEEND = 307,
     ORTHANTCONESTART = 308,
     ORTHANTCONEEND = 309,
     POLYHEDRALCONESTART = 310,
     POLYHEDRALCONEEND = 311,
     QUADRATICCONESTART = 312,
     QUADRATICCONEEND = 313,
     ROTATEDQUADRATICCONESTART = 314,
     ROTATEDQUADRATICCONEEND = 315,
     SEMIDEFINITECONESTART = 316,
     SEMIDEFINITECONEEND = 317,
     PRODUCTCONESTART = 318,
     PRODUCTCONEEND = 319,
     INTERSECTIONCONESTART = 320,
     INTERSECTIONCONEEND = 321,
     DUALCONESTART = 322,
     DUALCONEEND = 323,
     POLARCONESTART = 324,
     POLARCONEEND = 325,
     DIRECTIONSTART = 326,
     DIRECTIONEND = 327,
     FACTORSSTART = 328,
     FACTORSEND = 329,
     COMPONENTSSTART = 330,
     COMPONENTSEND = 331,
     TIMEDOMAINSTART = 332,
     TIMEDOMAINEND = 333,
     STAGESSTART = 334,
     STAGESEND = 335,
     STAGESTART = 336,
     STAGEEND = 337,
     INTERVALSTART = 338,
     INTERVALEND = 339,
     HEADERSTART = 340,
     HEADEREND = 341,
     FILENAMESTART = 342,
     FILENAMEEND = 343,
     FILENAMEEMPTY = 344,
     FILENAMESTARTANDEND = 345,
     FILESOURCESTART = 346,
     FILESOURCEEND = 347,
     FILESOURCEEMPTY = 348,
     FILESOURCESTARTANDEND = 349,
     FILEDESCRIPTIONSTART = 350,
     FILEDESCRIPTIONEND = 351,
     FILEDESCRIPTIONEMPTY = 352,
     FILEDESCRIPTIONSTARTANDEND = 353,
     FILECREATORSTART = 354,
     FILECREATOREND = 355,
     FILECREATOREMPTY = 356,
     FILECREATORSTARTANDEND = 357,
     FILELICENCESTART = 358,
     FILELICENCEEND = 359,
     FILELICENCEEMPTY = 360,
     FILELICENCESTARTANDEND = 361,
     INDEXESSTART = 362,
     INDEXESEND = 363,
     VALUESSTART = 364,
     VALUESEND = 365,
     NONZEROSSTART = 366,
     NONZEROSEND = 367,
     ELSTART = 368,
     ELEND = 369,
     ENUMERATIONSTART = 370,
     ENUMERATIONEND = 371,
     ITEMEMPTY = 372,
     ITEMSTART = 373,
     ITEMEND = 374,
     ITEMSTARTANDEND = 375,
     BASE64START = 376,
     BASE64END = 377,
     NUMBEROFELATT = 378,
     NUMBEROFENUMERATIONSATT = 379,
     NUMBEROFITEMSATT = 380,
     EMPTYCATEGORYATT = 381,
     CATEGORYATT = 382,
     EMPTYDESCRIPTIONATT = 383,
     DESCRIPTIONATT = 384,
     EMPTYSOLVERATT = 385,
     SOLVERATT = 386,
     EMPTYNAMEATT = 387,
     NAMEATT = 388,
     EMPTYTYPEATT = 389,
     TYPEATT = 390,
     EMPTYENUMTYPEATT = 391,
     ENUMTYPEATT = 392,
     EMPTYSHAPEATT = 393,
     SHAPEATT = 394,
     EMPTYUNITATT = 395,
     UNITATT = 396,
     EMPTYVALUEATT = 397,
     VALUEATT = 398,
     EMPTYVALUETYPEATT = 399,
     VALUETYPEATT = 400,
     EMPTYCONTYPEATT = 401,
     CONTYPEATT = 402,
     EMPTYOBJTYPEATT = 403,
     OBJTYPEATT = 404,
     EMPTYVARTYPEATT = 405,
     VARTYPEATT = 406,
     EMPTYMATRIXCONTYPEATT = 407,
     MATRIXCONTYPEATT = 408,
     EMPTYMATRIXOBJTYPEATT = 409,
     MATRIXOBJTYPEATT = 410,
     EMPTYMATRIXVARTYPEATT = 411,
     MATRIXVARTYPEATT = 412,
     EMPTYMATRIXTYPEATT = 413,
     MATRIXTYPEATT = 414,
     EMPTYSYMMETRYATT = 415,
     SYMMETRYATT = 416,
     EMPTYROWMAJORATT = 417,
     ROWMAJORATT = 418,
     EMPTYBASETRANSPOSEATT = 419,
     BASETRANSPOSEATT = 420,
     NUMBEROFBLOCKSATT = 421,
     NUMBEROFCOLUMNSATT = 422,
     NUMBEROFROWSATT = 423,
     NUMBEROFMATRICESATT = 424,
     NUMBEROFVALUESATT = 425,
     NUMBEROFCONSTRAINTSATT = 426,
     NUMBEROFCONATT = 427,
     NUMBEROFCONIDXATT = 428,
     NUMBEROFOBJECTIVESATT = 429,
     NUMBEROFOBJATT = 430,
     NUMBEROFOBJIDXATT = 431,
     NUMBEROFVARIABLESATT = 432,
     NUMBEROFVARATT = 433,
     NUMBEROFVARIDXATT = 434,
     NUMBEROFMATRIXCONATT = 435,
     NUMBEROFMATRIXOBJATT = 436,
     NUMBEROFMATRIXVARATT = 437,
     BASEMATRIXIDXATT = 438,
     TARGETMATRIXFIRSTROWATT = 439,
     TARGETMATRIXFIRSTCOLATT = 440,
     BASEMATRIXSTARTROWATT = 441,
     BASEMATRIXSTARTCOLATT = 442,
     BASEMATRIXENDROWATT = 443,
     BASEMATRIXENDCOLATT = 444,
     SCALARMULTIPLIERATT = 445,
     BLOCKROWIDXATT = 446,
     BLOCKCOLIDXATT = 447,
     REATT = 448,
     IMATT = 449,
     MATRIXVARIDXATT = 450,
     MATRIXOBJIDXATT = 451,
     MATRIXCONIDXATT = 452,
     IDXATT = 453,
     INCRATT = 454,
     MULTATT = 455,
     SIZEOFATT = 456,
     COEFATT = 457,
     CONSTANTATT = 458,
     MATRICESSTART = 459,
     MATRICESEND = 460,
     MATRIXSTART = 461,
     MATRIXEND = 462,
     BASEMATRIXEND = 463,
     BASEMATRIXSTART = 464,
     BLOCKSSTART = 465,
     BLOCKSEND = 466,
     BLOCKSTART = 467,
     BLOCKEND = 468,
     COLOFFSETSTART = 469,
     COLOFFSETEND = 470,
     ROWOFFSETSTART = 471,
     ROWOFFSETEND = 472,
     ELEMENTSSTART = 473,
     ELEMENTSEND = 474,
     CONSTANTELEMENTSSTART = 475,
     CONSTANTELEMENTSEND = 476,
     COMPLEXELEMENTSSTART = 477,
     COMPLEXELEMENTSEND = 478,
     VARREFERENCEELEMENTSSTART = 479,
     VARREFERENCEELEMENTSEND = 480,
     LINEARELEMENTSSTART = 481,
     LINEARELEMENTSEND = 482,
     CONREFERENCEELEMENTSSTART = 483,
     CONREFERENCEELEMENTSEND = 484,
     OBJREFERENCEELEMENTSSTART = 485,
     OBJREFERENCEELEMENTSEND = 486,
     REALVALUEDEXPRESSIONSSTART = 487,
     REALVALUEDEXPRESSIONSSEND = 488,
     COMPLEXVALUEDEXPRESSIONSSTART = 489,
     COMPLEXVALUEDEXPRESSIONSSEND = 490,
     STRINGVALUEDELEMENTSSTART = 491,
     STRINGVALUEDELEMENTSEND = 492,
     STARTVECTORSTART = 493,
     STARTVECTOREND = 494,
     INDEXSTART = 495,
     INDEXEND = 496,
     VALUESTART = 497,
     VALUEEND = 498,
     VARIDXSTART = 499,
     VARIDXEND = 500,
     TRANSFORMATIONSTART = 501,
     TRANSFORMATIONEND = 502,
     MATRIXPROGRAMMINGSTART = 503,
     MATRIXPROGRAMMINGEND = 504,
     MATRIXVARIABLESSTART = 505,
     MATRIXVARIABLESEND = 506,
     MATRIXVARSTART = 507,
     MATRIXVAREND = 508,
     MATRIXOBJECTIVESSTART = 509,
     MATRIXOBJECTIVESEND = 510,
     MATRIXOBJSTART = 511,
     MATRIXOBJEND = 512,
     MATRIXCONSTRAINTSSTART = 513,
     MATRIXCONSTRAINTSEND = 514,
     MATRIXCONSTART = 515,
     MATRIXCONEND = 516,
     CONSTART = 517,
     CONEND = 518,
     CONSTRAINTSSTART = 519,
     CONSTRAINTSEND = 520,
     OBJSTART = 521,
     OBJEND = 522,
     OBJECTIVESSTART = 523,
     OBJECTIVESEND = 524,
     VARSTART = 525,
     VAREND = 526,
     VARIABLESSTART = 527,
     VARIABLESEND = 528,
     GENERALSTART = 529,
     GENERALEND = 530,
     SYSTEMSTART = 531,
     SYSTEMEND = 532,
     SERVICESTART = 533,
     SERVICEEND = 534,
     JOBSTART = 535,
     JOBEND = 536,
     OPTIMIZATIONSTART = 537,
     OPTIMIZATIONEND = 538,
     ATEQUALITYSTART = 539,
     ATEQUALITYEND = 540,
     ATLOWERSTART = 541,
     ATLOWEREND = 542,
     ATUPPERSTART = 543,
     ATUPPEREND = 544,
     BASICSTART = 545,
     BASICEND = 546,
     ISFREESTART = 547,
     ISFREEEND = 548,
     SUPERBASICSTART = 549,
     SUPERBASICEND = 550,
     UNKNOWNSTART = 551,
     UNKNOWNEND = 552,
     SERVICEURISTART = 553,
     SERVICEURIEND = 554,
     SERVICENAMESTART = 555,
     SERVICENAMEEND = 556,
     INSTANCENAMESTART = 557,
     INSTANCENAMEEND = 558,
     JOBIDSTART = 559,
     JOBIDEND = 560,
     OTHERSTART = 561,
     OTHEREND = 562,
     DUMMY = 563,
     NONLINEAREXPRESSIONSSTART = 564,
     NONLINEAREXPRESSIONSEND = 565,
     NUMBEROFNONLINEAREXPRESSIONS = 566,
     NLSTART = 567,
     NLEND = 568,
     MATRIXEXPRESSIONSSTART = 569,
     MATRIXEXPRESSIONSEND = 570,
     NUMBEROFEXPR = 571,
     EXPRSTART = 572,
     EXPREND = 573,
     NUMBEROFMATRIXTERMSATT = 574,
     MATRIXTERMSTART = 575,
     MATRIXTERMEND = 576,
     POWERSTART = 577,
     POWEREND = 578,
     PLUSSTART = 579,
     PLUSEND = 580,
     MINUSSTART = 581,
     MINUSEND = 582,
     DIVIDESTART = 583,
     DIVIDEEND = 584,
     LNSTART = 585,
     LNEND = 586,
     SQRTSTART = 587,
     SQRTEND = 588,
     SUMSTART = 589,
     SUMEND = 590,
     PRODUCTSTART = 591,
     PRODUCTEND = 592,
     EXPSTART = 593,
     EXPEND = 594,
     NEGATESTART = 595,
     NEGATEEND = 596,
     IFSTART = 597,
     IFEND = 598,
     SQUARESTART = 599,
     SQUAREEND = 600,
     COSSTART = 601,
     COSEND = 602,
     SINSTART = 603,
     SINEND = 604,
     VARIABLESTART = 605,
     VARIABLEEND = 606,
     ABSSTART = 607,
     ABSEND = 608,
     ERFSTART = 609,
     ERFEND = 610,
     MAXSTART = 611,
     MAXEND = 612,
     ALLDIFFSTART = 613,
     ALLDIFFEND = 614,
     MINSTART = 615,
     MINEND = 616,
     ESTART = 617,
     EEND = 618,
     PISTART = 619,
     PIEND = 620,
     TIMESSTART = 621,
     TIMESEND = 622,
     NUMBERSTART = 623,
     NUMBEREND = 624,
     MATRIXDETERMINANTSTART = 625,
     MATRIXDETERMINANTEND = 626,
     MATRIXTRACESTART = 627,
     MATRIXTRACEEND = 628,
     MATRIXTOSCALARSTART = 629,
     MATRIXTOSCALAREND = 630,
     MATRIXDIAGONALSTART = 631,
     MATRIXDIAGONALEND = 632,
     MATRIXDOTTIMESSTART = 633,
     MATRIXDOTTIMESEND = 634,
     MATRIXLOWERTRIANGLESTART = 635,
     MATRIXLOWERTRIANGLEEND = 636,
     MATRIXUPPERTRIANGLESTART = 637,
     MATRIXUPPERTRIANGLEEND = 638,
     MATRIXMERGESTART = 639,
     MATRIXMERGEEND = 640,
     MATRIXMINUSSTART = 641,
     MATRIXMINUSEND = 642,
     MATRIXNEGATESTART = 643,
     MATRIXNEGATEEND = 644,
     MATRIXPLUSSTART = 645,
     MATRIXPLUSEND = 646,
     MATRIXTIMESSTART = 647,
     MATRIXTIMESEND = 648,
     MATRIXPRODUCTSTART = 649,
     MATRIXPRODUCTEND = 650,
     MATRIXSCALARTIMESSTART = 651,
     MATRIXSCALARTIMESEND = 652,
     MATRIXSUBMATRIXATSTART = 653,
     MATRIXSUBMATRIXATEND = 654,
     MATRIXTRANSPOSESTART = 655,
     MATRIXTRANSPOSEEND = 656,
     MATRIXREFERENCESTART = 657,
     MATRIXREFERENCEEND = 658,
     IDENTITYMATRIXSTART = 659,
     IDENTITYMATRIXEND = 660,
     MATRIXINVERSESTART = 661,
     MATRIXINVERSEEND = 662,
     COMPLEXCONJUGATESTART = 663,
     COMPLEXCONJUGATEEND = 664,
     COMPLEXMINUSSTART = 665,
     COMPLEXMINUSEND = 666,
     COMPLEXNEGATESTART = 667,
     COMPLEXNEGATEEND = 668,
     COMPLEXNUMBERSTART = 669,
     COMPLEXNUMBEREND = 670,
     COMPLEXPLUSSTART = 671,
     COMPLEXPLUSEND = 672,
     COMPLEXSQUARESTART = 673,
     COMPLEXSQUAREEND = 674,
     COMPLEXSUMSTART = 675,
     COMPLEXSUMEND = 676,
     COMPLEXTIMESSTART = 677,
     COMPLEXTIMESEND = 678,
     CREATECOMPLEXSTART = 679,
     CREATECOMPLEXEND = 680,
     EMPTYINCLUDEDIAGONALATT = 681,
     INCLUDEDIAGONALATT = 682,
     EMPTYTRANSPOSEATT = 683,
     TRANSPOSEATT = 684,
     EMPTYIDATT = 685,
     IDATT = 686
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define ITEMTEXT 260
#define INTEGER 261
#define DOUBLE 262
#define QUOTE 263
#define TWOQUOTES 264
#define BOOLEAN 265
#define ENDOFELEMENT 266
#define GREATERTHAN 267
#define EMPTYSEMIDEFINITENESSATT 268
#define SEMIDEFINITENESSATT 269
#define NUMBEROFQTERMSATT 270
#define NUMBEROFCONESATT 271
#define NUMBEROFSTAGESATT 272
#define IDXONEATT 273
#define IDXTWOATT 274
#define HORIZONATT 275
#define STARTATT 276
#define STARTIDXATT 277
#define MATRIXIDXATT 278
#define LBMATRIXIDXATT 279
#define LBCONEIDXATT 280
#define UBMATRIXIDXATT 281
#define UBCONEIDXATT 282
#define TEMPLATEMATRIXIDXATT 283
#define REFERENCEMATRIXIDXATT 284
#define VARREFERENCEMATRIXIDXATT 285
#define OBJREFERENCEMATRIXIDXATT 286
#define CONREFERENCEMATRIXIDXATT 287
#define ORDERCONEIDXATT 288
#define CONSTANTMATRIXIDXATT 289
#define NORMSCALEFACTORATT 290
#define DISTORTIONMATRIXIDXATT 291
#define AXISDIRECTIONATT 292
#define FIRSTAXISDIRECTIONATT 293
#define SECONDAXISDIRECTIONATT 294
#define OSILEND 295
#define INSTANCEDATAEND 296
#define INSTANCEDATASTARTEND 297
#define QUADRATICCOEFFICIENTSSTART 298
#define QUADRATICCOEFFICIENTSEND 299
#define QTERMSTART 300
#define QTERMEND 301
#define CONESSTART 302
#define CONESEND 303
#define NONNEGATIVECONESTART 304
#define NONNEGATIVECONEEND 305
#define NONPOSITIVECONESTART 306
#define NONPOSITIVECONEEND 307
#define ORTHANTCONESTART 308
#define ORTHANTCONEEND 309
#define POLYHEDRALCONESTART 310
#define POLYHEDRALCONEEND 311
#define QUADRATICCONESTART 312
#define QUADRATICCONEEND 313
#define ROTATEDQUADRATICCONESTART 314
#define ROTATEDQUADRATICCONEEND 315
#define SEMIDEFINITECONESTART 316
#define SEMIDEFINITECONEEND 317
#define PRODUCTCONESTART 318
#define PRODUCTCONEEND 319
#define INTERSECTIONCONESTART 320
#define INTERSECTIONCONEEND 321
#define DUALCONESTART 322
#define DUALCONEEND 323
#define POLARCONESTART 324
#define POLARCONEEND 325
#define DIRECTIONSTART 326
#define DIRECTIONEND 327
#define FACTORSSTART 328
#define FACTORSEND 329
#define COMPONENTSSTART 330
#define COMPONENTSEND 331
#define TIMEDOMAINSTART 332
#define TIMEDOMAINEND 333
#define STAGESSTART 334
#define STAGESEND 335
#define STAGESTART 336
#define STAGEEND 337
#define INTERVALSTART 338
#define INTERVALEND 339
#define HEADERSTART 340
#define HEADEREND 341
#define FILENAMESTART 342
#define FILENAMEEND 343
#define FILENAMEEMPTY 344
#define FILENAMESTARTANDEND 345
#define FILESOURCESTART 346
#define FILESOURCEEND 347
#define FILESOURCEEMPTY 348
#define FILESOURCESTARTANDEND 349
#define FILEDESCRIPTIONSTART 350
#define FILEDESCRIPTIONEND 351
#define FILEDESCRIPTIONEMPTY 352
#define FILEDESCRIPTIONSTARTANDEND 353
#define FILECREATORSTART 354
#define FILECREATOREND 355
#define FILECREATOREMPTY 356
#define FILECREATORSTARTANDEND 357
#define FILELICENCESTART 358
#define FILELICENCEEND 359
#define FILELICENCEEMPTY 360
#define FILELICENCESTARTANDEND 361
#define INDEXESSTART 362
#define INDEXESEND 363
#define VALUESSTART 364
#define VALUESEND 365
#define NONZEROSSTART 366
#define NONZEROSEND 367
#define ELSTART 368
#define ELEND 369
#define ENUMERATIONSTART 370
#define ENUMERATIONEND 371
#define ITEMEMPTY 372
#define ITEMSTART 373
#define ITEMEND 374
#define ITEMSTARTANDEND 375
#define BASE64START 376
#define BASE64END 377
#define NUMBEROFELATT 378
#define NUMBEROFENUMERATIONSATT 379
#define NUMBEROFITEMSATT 380
#define EMPTYCATEGORYATT 381
#define CATEGORYATT 382
#define EMPTYDESCRIPTIONATT 383
#define DESCRIPTIONATT 384
#define EMPTYSOLVERATT 385
#define SOLVERATT 386
#define EMPTYNAMEATT 387
#define NAMEATT 388
#define EMPTYTYPEATT 389
#define TYPEATT 390
#define EMPTYENUMTYPEATT 391
#define ENUMTYPEATT 392
#define EMPTYSHAPEATT 393
#define SHAPEATT 394
#define EMPTYUNITATT 395
#define UNITATT 396
#define EMPTYVALUEATT 397
#define VALUEATT 398
#define EMPTYVALUETYPEATT 399
#define VALUETYPEATT 400
#define EMPTYCONTYPEATT 401
#define CONTYPEATT 402
#define EMPTYOBJTYPEATT 403
#define OBJTYPEATT 404
#define EMPTYVARTYPEATT 405
#define VARTYPEATT 406
#define EMPTYMATRIXCONTYPEATT 407
#define MATRIXCONTYPEATT 408
#define EMPTYMATRIXOBJTYPEATT 409
#define MATRIXOBJTYPEATT 410
#define EMPTYMATRIXVARTYPEATT 411
#define MATRIXVARTYPEATT 412
#define EMPTYMATRIXTYPEATT 413
#define MATRIXTYPEATT 414
#define EMPTYSYMMETRYATT 415
#define SYMMETRYATT 416
#define EMPTYROWMAJORATT 417
#define ROWMAJORATT 418
#define EMPTYBASETRANSPOSEATT 419
#define BASETRANSPOSEATT 420
#define NUMBEROFBLOCKSATT 421
#define NUMBEROFCOLUMNSATT 422
#define NUMBEROFROWSATT 423
#define NUMBEROFMATRICESATT 424
#define NUMBEROFVALUESATT 425
#define NUMBEROFCONSTRAINTSATT 426
#define NUMBEROFCONATT 427
#define NUMBEROFCONIDXATT 428
#define NUMBEROFOBJECTIVESATT 429
#define NUMBEROFOBJATT 430
#define NUMBEROFOBJIDXATT 431
#define NUMBEROFVARIABLESATT 432
#define NUMBEROFVARATT 433
#define NUMBEROFVARIDXATT 434
#define NUMBEROFMATRIXCONATT 435
#define NUMBEROFMATRIXOBJATT 436
#define NUMBEROFMATRIXVARATT 437
#define BASEMATRIXIDXATT 438
#define TARGETMATRIXFIRSTROWATT 439
#define TARGETMATRIXFIRSTCOLATT 440
#define BASEMATRIXSTARTROWATT 441
#define BASEMATRIXSTARTCOLATT 442
#define BASEMATRIXENDROWATT 443
#define BASEMATRIXENDCOLATT 444
#define SCALARMULTIPLIERATT 445
#define BLOCKROWIDXATT 446
#define BLOCKCOLIDXATT 447
#define REATT 448
#define IMATT 449
#define MATRIXVARIDXATT 450
#define MATRIXOBJIDXATT 451
#define MATRIXCONIDXATT 452
#define IDXATT 453
#define INCRATT 454
#define MULTATT 455
#define SIZEOFATT 456
#define COEFATT 457
#define CONSTANTATT 458
#define MATRICESSTART 459
#define MATRICESEND 460
#define MATRIXSTART 461
#define MATRIXEND 462
#define BASEMATRIXEND 463
#define BASEMATRIXSTART 464
#define BLOCKSSTART 465
#define BLOCKSEND 466
#define BLOCKSTART 467
#define BLOCKEND 468
#define COLOFFSETSTART 469
#define COLOFFSETEND 470
#define ROWOFFSETSTART 471
#define ROWOFFSETEND 472
#define ELEMENTSSTART 473
#define ELEMENTSEND 474
#define CONSTANTELEMENTSSTART 475
#define CONSTANTELEMENTSEND 476
#define COMPLEXELEMENTSSTART 477
#define COMPLEXELEMENTSEND 478
#define VARREFERENCEELEMENTSSTART 479
#define VARREFERENCEELEMENTSEND 480
#define LINEARELEMENTSSTART 481
#define LINEARELEMENTSEND 482
#define CONREFERENCEELEMENTSSTART 483
#define CONREFERENCEELEMENTSEND 484
#define OBJREFERENCEELEMENTSSTART 485
#define OBJREFERENCEELEMENTSEND 486
#define REALVALUEDEXPRESSIONSSTART 487
#define REALVALUEDEXPRESSIONSSEND 488
#define COMPLEXVALUEDEXPRESSIONSSTART 489
#define COMPLEXVALUEDEXPRESSIONSSEND 490
#define STRINGVALUEDELEMENTSSTART 491
#define STRINGVALUEDELEMENTSEND 492
#define STARTVECTORSTART 493
#define STARTVECTOREND 494
#define INDEXSTART 495
#define INDEXEND 496
#define VALUESTART 497
#define VALUEEND 498
#define VARIDXSTART 499
#define VARIDXEND 500
#define TRANSFORMATIONSTART 501
#define TRANSFORMATIONEND 502
#define MATRIXPROGRAMMINGSTART 503
#define MATRIXPROGRAMMINGEND 504
#define MATRIXVARIABLESSTART 505
#define MATRIXVARIABLESEND 506
#define MATRIXVARSTART 507
#define MATRIXVAREND 508
#define MATRIXOBJECTIVESSTART 509
#define MATRIXOBJECTIVESEND 510
#define MATRIXOBJSTART 511
#define MATRIXOBJEND 512
#define MATRIXCONSTRAINTSSTART 513
#define MATRIXCONSTRAINTSEND 514
#define MATRIXCONSTART 515
#define MATRIXCONEND 516
#define CONSTART 517
#define CONEND 518
#define CONSTRAINTSSTART 519
#define CONSTRAINTSEND 520
#define OBJSTART 521
#define OBJEND 522
#define OBJECTIVESSTART 523
#define OBJECTIVESEND 524
#define VARSTART 525
#define VAREND 526
#define VARIABLESSTART 527
#define VARIABLESEND 528
#define GENERALSTART 529
#define GENERALEND 530
#define SYSTEMSTART 531
#define SYSTEMEND 532
#define SERVICESTART 533
#define SERVICEEND 534
#define JOBSTART 535
#define JOBEND 536
#define OPTIMIZATIONSTART 537
#define OPTIMIZATIONEND 538
#define ATEQUALITYSTART 539
#define ATEQUALITYEND 540
#define ATLOWERSTART 541
#define ATLOWEREND 542
#define ATUPPERSTART 543
#define ATUPPEREND 544
#define BASICSTART 545
#define BASICEND 546
#define ISFREESTART 547
#define ISFREEEND 548
#define SUPERBASICSTART 549
#define SUPERBASICEND 550
#define UNKNOWNSTART 551
#define UNKNOWNEND 552
#define SERVICEURISTART 553
#define SERVICEURIEND 554
#define SERVICENAMESTART 555
#define SERVICENAMEEND 556
#define INSTANCENAMESTART 557
#define INSTANCENAMEEND 558
#define JOBIDSTART 559
#define JOBIDEND 560
#define OTHERSTART 561
#define OTHEREND 562
#define DUMMY 563
#define NONLINEAREXPRESSIONSSTART 564
#define NONLINEAREXPRESSIONSEND 565
#define NUMBEROFNONLINEAREXPRESSIONS 566
#define NLSTART 567
#define NLEND 568
#define MATRIXEXPRESSIONSSTART 569
#define MATRIXEXPRESSIONSEND 570
#define NUMBEROFEXPR 571
#define EXPRSTART 572
#define EXPREND 573
#define NUMBEROFMATRIXTERMSATT 574
#define MATRIXTERMSTART 575
#define MATRIXTERMEND 576
#define POWERSTART 577
#define POWEREND 578
#define PLUSSTART 579
#define PLUSEND 580
#define MINUSSTART 581
#define MINUSEND 582
#define DIVIDESTART 583
#define DIVIDEEND 584
#define LNSTART 585
#define LNEND 586
#define SQRTSTART 587
#define SQRTEND 588
#define SUMSTART 589
#define SUMEND 590
#define PRODUCTSTART 591
#define PRODUCTEND 592
#define EXPSTART 593
#define EXPEND 594
#define NEGATESTART 595
#define NEGATEEND 596
#define IFSTART 597
#define IFEND 598
#define SQUARESTART 599
#define SQUAREEND 600
#define COSSTART 601
#define COSEND 602
#define SINSTART 603
#define SINEND 604
#define VARIABLESTART 605
#define VARIABLEEND 606
#define ABSSTART 607
#define ABSEND 608
#define ERFSTART 609
#define ERFEND 610
#define MAXSTART 611
#define MAXEND 612
#define ALLDIFFSTART 613
#define ALLDIFFEND 614
#define MINSTART 615
#define MINEND 616
#define ESTART 617
#define EEND 618
#define PISTART 619
#define PIEND 620
#define TIMESSTART 621
#define TIMESEND 622
#define NUMBERSTART 623
#define NUMBEREND 624
#define MATRIXDETERMINANTSTART 625
#define MATRIXDETERMINANTEND 626
#define MATRIXTRACESTART 627
#define MATRIXTRACEEND 628
#define MATRIXTOSCALARSTART 629
#define MATRIXTOSCALAREND 630
#define MATRIXDIAGONALSTART 631
#define MATRIXDIAGONALEND 632
#define MATRIXDOTTIMESSTART 633
#define MATRIXDOTTIMESEND 634
#define MATRIXLOWERTRIANGLESTART 635
#define MATRIXLOWERTRIANGLEEND 636
#define MATRIXUPPERTRIANGLESTART 637
#define MATRIXUPPERTRIANGLEEND 638
#define MATRIXMERGESTART 639
#define MATRIXMERGEEND 640
#define MATRIXMINUSSTART 641
#define MATRIXMINUSEND 642
#define MATRIXNEGATESTART 643
#define MATRIXNEGATEEND 644
#define MATRIXPLUSSTART 645
#define MATRIXPLUSEND 646
#define MATRIXTIMESSTART 647
#define MATRIXTIMESEND 648
#define MATRIXPRODUCTSTART 649
#define MATRIXPRODUCTEND 650
#define MATRIXSCALARTIMESSTART 651
#define MATRIXSCALARTIMESEND 652
#define MATRIXSUBMATRIXATSTART 653
#define MATRIXSUBMATRIXATEND 654
#define MATRIXTRANSPOSESTART 655
#define MATRIXTRANSPOSEEND 656
#define MATRIXREFERENCESTART 657
#define MATRIXREFERENCEEND 658
#define IDENTITYMATRIXSTART 659
#define IDENTITYMATRIXEND 660
#define MATRIXINVERSESTART 661
#define MATRIXINVERSEEND 662
#define COMPLEXCONJUGATESTART 663
#define COMPLEXCONJUGATEEND 664
#define COMPLEXMINUSSTART 665
#define COMPLEXMINUSEND 666
#define COMPLEXNEGATESTART 667
#define COMPLEXNEGATEEND 668
#define COMPLEXNUMBERSTART 669
#define COMPLEXNUMBEREND 670
#define COMPLEXPLUSSTART 671
#define COMPLEXPLUSEND 672
#define COMPLEXSQUARESTART 673
#define COMPLEXSQUAREEND 674
#define COMPLEXSUMSTART 675
#define COMPLEXSUMEND 676
#define COMPLEXTIMESSTART 677
#define COMPLEXTIMESEND 678
#define CREATECOMPLEXSTART 679
#define CREATECOMPLEXEND 680
#define EMPTYINCLUDEDIAGONALATT 681
#define INCLUDEDIAGONALATT 682
#define EMPTYTRANSPOSEATT 683
#define TRANSPOSEATT 684
#define EMPTYIDATT 685
#define IDATT 686




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    double dval;
    int ival;
    char* sval;
    



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


int osillex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner );
void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg );
std::string addErrorMsg(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg ) ;
 
#define scanner parserData->scanner



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  436
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  731
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1090
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1689

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   686

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   433,
     435,     2,     2,   434,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   432,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    16,    18,    20,    21,    22,
      27,    29,    35,    36,    39,    43,    45,    47,    50,    51,
      54,    56,    58,    60,    62,    67,    72,    77,    82,    83,
      87,    89,    91,    93,    95,    97,   101,   102,   105,   106,
     110,   112,   114,   116,   118,   120,   124,   125,   128,   130,
     132,   134,   136,   138,   140,   142,   144,   146,   150,   152,
     154,   155,   158,   160,   162,   164,   166,   169,   173,   175,
     177,   178,   181,   183,   185,   187,   189,   192,   196,   198,
     200,   201,   204,   206,   208,   210,   212,   216,   218,   219,
     222,   226,   228,   230,   231,   234,   236,   238,   240,   243,
     245,   249,   251,   253,   254,   257,   259,   261,   263,   265,
     270,   272,   275,   279,   281,   283,   284,   287,   289,   291,
     293,   295,   297,   299,   301,   304,   308,   310,   312,   313,
     316,   318,   320,   322,   324,   326,   328,   330,   332,   335,
     339,   341,   343,   344,   347,   349,   351,   353,   355,   357,
     360,   364,   366,   368,   369,   372,   374,   376,   378,   382,
     386,   388,   390,   392,   394,   396,   400,   402,   404,   406,
     410,   412,   414,   415,   418,   420,   422,   424,   428,   432,
     434,   436,   438,   440,   442,   446,   448,   450,   452,   453,
     456,   458,   460,   462,   464,   471,   472,   476,   478,   480,
     482,   484,   486,   490,   492,   493,   496,   500,   502,   504,
     505,   508,   510,   512,   514,   516,   518,   520,   522,   524,
     526,   528,   530,   532,   535,   536,   540,   542,   544,   546,
     548,   550,   554,   556,   557,   560,   564,   566,   568,   569,
     572,   574,   576,   578,   580,   582,   584,   586,   588,   590,
     593,   594,   598,   600,   602,   604,   606,   608,   612,   614,
     615,   618,   622,   624,   626,   627,   630,   632,   634,   636,
     638,   640,   642,   644,   646,   648,   650,   653,   654,   657,
     659,   661,   663,   665,   668,   672,   676,   681,   683,   689,
     691,   694,   695,   700,   701,   705,   707,   711,   715,   716,
     720,   721,   724,   726,   728,   733,   738,   740,   744,   746,
     749,   751,   754,   755,   760,   765,   767,   770,   771,   775,
     776,   779,   781,   783,   788,   793,   795,   799,   801,   804,
     806,   809,   810,   815,   820,   822,   825,   826,   830,   831,
     834,   836,   838,   843,   845,   849,   851,   854,   856,   859,
     860,   865,   870,   872,   875,   876,   881,   883,   886,   887,
     890,   892,   894,   899,   904,   909,   914,   919,   924,   929,
     934,   939,   944,   949,   954,   959,   963,   968,   973,   978,
     983,   988,   993,   998,  1003,  1008,  1013,  1018,  1022,  1026,
    1029,  1030,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1046,
    1049,  1053,  1055,  1057,  1058,  1061,  1063,  1065,  1069,  1073,
    1075,  1077,  1080,  1082,  1086,  1088,  1090,  1091,  1094,  1098,
    1100,  1101,  1103,  1107,  1111,  1113,  1115,  1118,  1120,  1124,
    1126,  1127,  1130,  1134,  1136,  1137,  1139,  1143,  1147,  1149,
    1151,  1152,  1155,  1157,  1159,  1161,  1163,  1165,  1167,  1169,
    1171,  1175,  1178,  1179,  1183,  1185,  1187,  1188,  1191,  1193,
    1195,  1197,  1199,  1201,  1203,  1205,  1207,  1209,  1212,  1214,
    1215,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1245,  1247,  1249,  1250,  1253,  1255,  1257,
    1261,  1262,  1265,  1268,  1270,  1272,  1274,  1276,  1280,  1282,
    1283,  1286,  1288,  1290,  1292,  1294,  1298,  1300,  1303,  1305,
    1307,  1309,  1311,  1315,  1317,  1322,  1324,  1326,  1327,  1330,
    1332,  1334,  1338,  1341,  1342,  1345,  1347,  1349,  1351,  1353,
    1357,  1359,  1364,  1366,  1368,  1369,  1372,  1374,  1376,  1380,
    1383,  1384,  1387,  1389,  1391,  1393,  1395,  1399,  1401,  1402,
    1405,  1409,  1411,  1413,  1414,  1417,  1419,  1421,  1423,  1425,
    1427,  1431,  1432,  1435,  1439,  1441,  1442,  1444,  1448,  1453,
    1455,  1457,  1458,  1461,  1463,  1465,  1469,  1472,  1473,  1476,
    1478,  1480,  1482,  1484,  1488,  1489,  1492,  1495,  1497,  1499,
    1501,  1503,  1507,  1512,  1514,  1516,  1517,  1520,  1522,  1524,
    1528,  1531,  1532,  1535,  1537,  1539,  1541,  1543,  1547,  1548,
    1551,  1554,  1556,  1558,  1560,  1562,  1566,  1571,  1573,  1575,
    1576,  1579,  1581,  1583,  1587,  1590,  1591,  1594,  1596,  1598,
    1600,  1602,  1606,  1608,  1613,  1615,  1617,  1618,  1621,  1623,
    1625,  1629,  1632,  1633,  1636,  1638,  1640,  1642,  1644,  1648,
    1649,  1652,  1656,  1658,  1659,  1662,  1664,  1666,  1668,  1672,
    1677,  1679,  1681,  1682,  1685,  1687,  1689,  1693,  1696,  1697,
    1700,  1702,  1704,  1706,  1708,  1712,  1713,  1716,  1720,  1722,
    1723,  1726,  1728,  1730,  1732,  1735,  1737,  1742,  1744,  1746,
    1747,  1750,  1752,  1754,  1758,  1761,  1762,  1765,  1767,  1769,
    1771,  1773,  1777,  1779,  1785,  1787,  1788,  1790,  1792,  1796,
    1798,  1800,  1806,  1808,  1812,  1814,  1816,  1818,  1820,  1822,
    1826,  1828,  1832,  1834,  1836,  1838,  1840,  1842,  1846,  1848,
    1849,  1852,  1856,  1858,  1860,  1861,  1864,  1866,  1868,  1870,
    1872,  1874,  1876,  1878,  1882,  1887,  1892,  1897,  1902,  1907,
    1912,  1917,  1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,
    1962,  1967,  1972,  1977,  1982,  1987,  1992,  1997,  2002,  2004,
    2006,  2008,  2012,  2014,  2016,  2018,  2022,  2024,  2026,  2028,
    2032,  2034,  2036,  2038,  2042,  2044,  2046,  2048,  2052,  2054,
    2056,  2058,  2062,  2064,  2066,  2068,  2072,  2074,  2076,  2078,
    2082,  2084,  2086,  2088,  2092,  2093,  2098,  2100,  2106,  2107,
    2110,  2116,  2118,  2120,  2121,  2124,  2126,  2128,  2130,  2132,
    2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,  2152,
    2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,  2172,
    2174,  2176,  2178,  2180,  2182,  2183,  2187,  2189,  2192,  2193,
    2197,  2199,  2202,  2203,  2209,  2210,  2216,  2217,  2223,  2224,
    2229,  2230,  2236,  2237,  2243,  2244,  2249,  2250,  2255,  2256,
    2261,  2262,  2267,  2268,  2273,  2274,  2279,  2283,  2285,  2287,
    2288,  2293,  2294,  2301,  2302,  2307,  2308,  2313,  2314,  2319,
    2323,  2325,  2327,  2330,  2331,  2334,  2336,  2338,  2340,  2341,
    2346,  2347,  2352,  2354,  2357,  2358,  2363,  2364,  2367,  2369,
    2371,  2376,  2381,  2382,  2387,  2388,  2391,  2392,  2397,  2398,
    2401,  2402,  2407,  2408,  2411,  2412,  2417,  2418,  2421,  2422,
    2427,  2428,  2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,
    2447,  2449,  2451,  2453,  2455,  2457,  2459,  2461,  2463,  2465,
    2467,  2469,  2473,  2475,  2476,  2479,  2481,  2483,  2485,  2488,
    2493,  2497,  2501,  2503,  2505,  2508,  2513,  2517,  2519,  2521,
    2524,  2529,  2533,  2535,  2537,  2540,  2545,  2548,  2550,  2553,
    2556,  2558,  2562,  2565,  2567,  2570,  2573,  2575,  2578,  2583,
    2585,  2586,  2588,  2591,  2596,  2598,  2599,  2601,  2604,  2608,
    2611,  2613,  2615,  2618,  2621,  2623,  2627,  2630,  2632,  2635,
    2638,  2640,  2644,  2647,  2649,  2653,  2654,  2659,  2660,  2663,
    2666,  2668,  2672,  2675,  2677,  2684,  2687,  2689,  2692,  2693,
    2697,  2699,  2701,  2706,  2708,  2710,  2712,  2716,  2717,  2720,
    2726,  2728,  2730,  2731,  2734,  2736,  2738,  2740,  2742,  2744,
    2746,  2748,  2750,  2752,  2754,  2756,  2758,  2760,  2764,  2766,
    2768,  2771,  2773,  2774,  2777,  2779,  2781,  2785,  2787,  2791,
    2795,  2797,  2801,  2802,  2808,  2809,  2812,  2816,  2818,  2822,
    2826,  2828,  2831,  2835,  2837,  2840,  2844,  2846,  2850,  2854,
    2856
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     437,     0,    -1,   441,   972,   454,   461,   551,   598,   438,
     439,    -1,    42,    -1,    41,    -1,   440,    -1,    40,    -1,
      -1,    -1,   442,   443,   444,    44,    -1,    43,    -1,    15,
       8,     6,     8,    12,    -1,    -1,   444,   445,    -1,   446,
     448,   447,    -1,    45,    -1,    11,    -1,    12,    46,    -1,
      -1,   448,   449,    -1,   450,    -1,   451,    -1,   452,    -1,
     453,    -1,    18,     8,     6,     8,    -1,    19,     8,     6,
       8,    -1,   202,     8,   677,     8,    -1,   198,     8,     6,
       8,    -1,    -1,   455,   456,   457,    -1,   204,    -1,   655,
      -1,   458,    -1,   459,    -1,    11,    -1,    12,   460,   205,
      -1,    -1,   460,   709,    -1,    -1,   462,   463,   464,    -1,
      47,    -1,   656,    -1,   465,    -1,   466,    -1,    11,    -1,
      12,   467,    48,    -1,    -1,   467,   468,    -1,   469,    -1,
     475,    -1,   481,    -1,   496,    -1,   503,    -1,   509,    -1,
     515,    -1,   521,    -1,   536,    -1,   470,   471,   474,    -1,
      49,    -1,   472,    -1,    -1,   472,   473,    -1,   924,    -1,
     922,    -1,   948,    -1,    11,    -1,    12,    50,    -1,   476,
     477,   480,    -1,    51,    -1,   478,    -1,    -1,   478,   479,
      -1,   924,    -1,   922,    -1,   948,    -1,    11,    -1,    12,
      52,    -1,   482,   483,   486,    -1,    53,    -1,   484,    -1,
      -1,   484,   485,    -1,   924,    -1,   922,    -1,   948,    -1,
      11,    -1,    12,   487,   495,    -1,   488,    -1,    -1,   488,
     489,    -1,   490,   491,   494,    -1,    71,    -1,   492,    -1,
      -1,   492,   493,    -1,   960,    -1,   937,    -1,    11,    -1,
      12,    72,    -1,    54,    -1,   497,   498,   502,    -1,    55,
      -1,   499,    -1,    -1,   499,   500,    -1,   924,    -1,   922,
      -1,   501,    -1,   948,    -1,    29,     8,     6,     8,    -1,
      11,    -1,    12,    56,    -1,   504,   505,   508,    -1,    57,
      -1,   506,    -1,    -1,   506,   507,    -1,   924,    -1,   922,
      -1,   948,    -1,   661,    -1,   660,    -1,   662,    -1,    11,
      -1,    12,    58,    -1,   510,   511,   514,    -1,    59,    -1,
     512,    -1,    -1,   512,   513,    -1,   924,    -1,   922,    -1,
     948,    -1,   661,    -1,   660,    -1,   663,    -1,   664,    -1,
      11,    -1,    12,    60,    -1,   516,   517,   520,    -1,    61,
      -1,   518,    -1,    -1,   518,   519,    -1,   924,    -1,   922,
      -1,   948,    -1,   665,    -1,    11,    -1,    12,    62,    -1,
     522,   523,   526,    -1,    63,    -1,   524,    -1,    -1,   524,
     525,    -1,   924,    -1,   922,    -1,   948,    -1,    12,   527,
     535,    -1,   528,   529,   530,    -1,    73,    -1,   923,    -1,
     531,    -1,   532,    -1,    11,    -1,    12,   533,   534,    -1,
     681,    -1,    74,    -1,    64,    -1,   537,   538,   541,    -1,
      65,    -1,   539,    -1,    -1,   539,   540,    -1,   924,    -1,
     922,    -1,   948,    -1,    12,   542,   550,    -1,   543,   544,
     545,    -1,    75,    -1,   923,    -1,   546,    -1,   547,    -1,
      11,    -1,    12,   548,   549,    -1,   681,    -1,    76,    -1,
      66,    -1,    -1,   552,   553,    -1,   248,    -1,   554,    -1,
     555,    -1,    11,    -1,    12,   556,   570,   584,  1122,   249,
      -1,    -1,   557,   558,   559,    -1,   250,    -1,   657,    -1,
     560,    -1,   561,    -1,    11,    -1,    12,   563,   562,    -1,
     251,    -1,    -1,   563,   564,    -1,   565,   566,   569,    -1,
     252,    -1,   567,    -1,    -1,   567,   568,    -1,   924,    -1,
     922,    -1,   670,    -1,   671,    -1,   667,    -1,   674,    -1,
     668,    -1,   675,    -1,   948,    -1,   969,    -1,   937,    -1,
      11,    -1,    12,   253,    -1,    -1,   571,   572,   573,    -1,
     254,    -1,   658,    -1,   574,    -1,   575,    -1,    11,    -1,
      12,   577,   576,    -1,   255,    -1,    -1,   577,   578,    -1,
     579,   580,   583,    -1,   256,    -1,   581,    -1,    -1,   581,
     582,    -1,   924,    -1,   922,    -1,   670,    -1,   672,    -1,
     676,    -1,   669,    -1,   948,    -1,   937,    -1,    11,    -1,
      12,   257,    -1,    -1,   585,   586,   587,    -1,   258,    -1,
     659,    -1,   588,    -1,   589,    -1,    11,    -1,    12,   591,
     590,    -1,   259,    -1,    -1,   591,   592,    -1,   593,   594,
     597,    -1,   260,    -1,   595,    -1,    -1,   595,   596,    -1,
     924,    -1,   922,    -1,   670,    -1,   673,    -1,   667,    -1,
     674,    -1,   668,    -1,   675,    -1,   948,    -1,    11,    -1,
      12,   261,    -1,    -1,   599,   600,    -1,    77,    -1,   601,
      -1,   602,    -1,    11,    -1,    12,    78,    -1,    12,   603,
      78,    -1,    12,   647,    78,    -1,   604,   605,   606,    80,
      -1,    79,    -1,    17,     8,     6,     8,    12,    -1,   607,
      -1,   606,   607,    -1,    -1,   608,    81,   609,   610,    -1,
      -1,   133,     3,     8,    -1,    11,    -1,    12,   611,    82,
      -1,   612,   624,   636,    -1,    -1,   272,   613,   617,    -1,
      -1,   613,   614,    -1,   615,    -1,   616,    -1,   177,     8,
       6,     8,    -1,    22,     8,     6,     8,    -1,   618,    -1,
      12,   619,   273,    -1,    11,    -1,    12,   273,    -1,   620,
      -1,   619,   620,    -1,    -1,   621,   270,   622,   623,    -1,
     198,     8,     6,     8,    -1,    11,    -1,    12,   271,    -1,
      -1,   264,   625,   629,    -1,    -1,   625,   626,    -1,   627,
      -1,   628,    -1,   171,     8,     6,     8,    -1,    22,     8,
       6,     8,    -1,   630,    -1,    12,   631,   265,    -1,    11,
      -1,    12,   265,    -1,   632,    -1,   631,   632,    -1,    -1,
     633,   262,   634,   635,    -1,   198,     8,     6,     8,    -1,
      11,    -1,    12,   263,    -1,    -1,   268,   637,   640,    -1,
      -1,   637,   638,    -1,   639,    -1,   652,    -1,   174,     8,
       6,     8,    -1,   641,    -1,    12,   642,   269,    -1,    11,
      -1,    12,   269,    -1,   643,    -1,   642,   643,    -1,    -1,
     644,   266,   645,   646,    -1,   198,     8,     6,     8,    -1,
      11,    -1,    12,   267,    -1,    -1,   648,    83,   650,   649,
      -1,    11,    -1,    12,    84,    -1,    -1,   650,   651,    -1,
     653,    -1,   654,    -1,    22,     8,     6,     8,    -1,    20,
       8,   677,     8,    -1,    21,     8,   677,     8,    -1,   169,
       8,     6,     8,    -1,    16,     8,     6,     8,    -1,   182,
       8,     6,     8,    -1,   181,     8,     6,     8,    -1,   180,
       8,     6,     8,    -1,    35,     8,   677,     8,    -1,    36,
       8,     6,     8,    -1,    37,     8,     6,     8,    -1,    38,
       8,     6,     8,    -1,    39,     8,     6,     8,    -1,    14,
       3,     8,    -1,    23,     8,     6,     8,    -1,    24,     8,
       6,     8,    -1,    26,     8,     6,     8,    -1,    34,     8,
       6,     8,    -1,    28,     8,     6,     8,    -1,    30,     8,
       6,     8,    -1,    31,     8,     6,     8,    -1,    32,     8,
       6,     8,    -1,    25,     8,     6,     8,    -1,    27,     8,
       6,     8,    -1,    33,     8,     6,     8,    -1,   679,     6,
     679,    -1,   679,     7,   679,    -1,   679,     8,    -1,    -1,
     679,   680,    -1,   432,    -1,   433,    -1,   434,    -1,   435,
      -1,   682,    -1,   689,    -1,    -1,   682,   683,    -1,   684,
     685,   688,    -1,   113,    -1,   686,    -1,    -1,   686,   687,
      -1,   937,    -1,   936,    -1,    12,     6,   114,    -1,   121,
     927,   690,    -1,   691,    -1,   692,    -1,    12,   122,    -1,
      11,    -1,    12,     4,   122,    -1,   694,    -1,   699,    -1,
      -1,   694,   695,    -1,   696,   697,   698,    -1,   113,    -1,
      -1,   937,    -1,    12,   677,   114,    -1,   121,   927,   700,
      -1,   701,    -1,   702,    -1,    12,   122,    -1,    11,    -1,
      12,     4,   122,    -1,   704,    -1,    -1,   704,   705,    -1,
     706,   707,   708,    -1,   113,    -1,    -1,   937,    -1,    12,
       4,   114,    -1,   710,   711,   714,    -1,   206,    -1,   712,
      -1,    -1,   712,   713,    -1,   957,    -1,   924,    -1,   922,
      -1,   948,    -1,   960,    -1,   715,    -1,   716,    -1,    11,
      -1,    12,   717,   207,    -1,   718,   724,    -1,    -1,   719,
     720,   723,    -1,   209,    -1,   721,    -1,    -1,   721,   722,
      -1,   928,    -1,   938,    -1,   939,    -1,   929,    -1,   930,
      -1,   931,    -1,   932,    -1,   945,    -1,   944,    -1,    12,
     208,    -1,    11,    -1,    -1,   724,   725,    -1,   726,    -1,
     858,    -1,   876,    -1,   751,    -1,   827,    -1,   840,    -1,
     764,    -1,   791,    -1,   809,    -1,   889,    -1,   893,    -1,
     727,   728,    12,   731,    -1,   220,    -1,   729,    -1,    -1,
     729,   730,    -1,   925,    -1,   951,    -1,   733,   732,   221,
      -1,    -1,   739,   745,    -1,   734,   735,    -1,   238,    -1,
     736,    -1,   737,    -1,    11,    -1,    12,   738,   239,    -1,
     681,    -1,    -1,   740,   741,    -1,   240,    -1,   742,    -1,
     743,    -1,    11,    -1,    12,   744,   241,    -1,   681,    -1,
     746,   747,    -1,   242,    -1,   748,    -1,   749,    -1,    11,
      -1,    12,   750,   243,    -1,   693,    -1,   752,   753,    12,
     756,    -1,   224,    -1,   754,    -1,    -1,   754,   755,    -1,
     925,    -1,   951,    -1,   733,   757,   225,    -1,   739,   758,
      -1,    -1,   759,   760,    -1,   242,    -1,   761,    -1,   762,
      -1,    11,    -1,    12,   763,   243,    -1,   681,    -1,   765,
     766,    12,   769,    -1,   226,    -1,   767,    -1,    -1,   767,
     768,    -1,   925,    -1,   951,    -1,   733,   770,   227,    -1,
     739,   771,    -1,    -1,   772,   773,    -1,   242,    -1,   774,
      -1,   775,    -1,    11,    -1,    12,   776,   243,    -1,   777,
      -1,    -1,   777,   778,    -1,   779,   780,   783,    -1,   113,
      -1,   781,    -1,    -1,   781,   782,    -1,   926,    -1,   941,
      -1,   784,    -1,   785,    -1,    11,    -1,    12,   786,   114,
      -1,    -1,   786,   787,    -1,   788,   789,   790,    -1,   244,
      -1,    -1,   940,    -1,    12,     6,   245,    -1,   792,   793,
      12,   796,    -1,   232,    -1,   794,    -1,    -1,   794,   795,
      -1,   925,    -1,   951,    -1,   733,   797,   233,    -1,   739,
     798,    -1,    -1,   799,   800,    -1,   242,    -1,   801,    -1,
     802,    -1,    11,    -1,    12,   803,   243,    -1,    -1,   803,
     804,    -1,   805,   806,    -1,   113,    -1,   807,    -1,   808,
      -1,    11,    -1,    12,   981,   114,    -1,   810,   811,    12,
     814,    -1,   234,    -1,   812,    -1,    -1,   812,   813,    -1,
     925,    -1,   951,    -1,   733,   815,   235,    -1,   739,   816,
      -1,    -1,   817,   818,    -1,   242,    -1,   819,    -1,   820,
      -1,    11,    -1,    12,   821,   243,    -1,    -1,   821,   822,
      -1,   823,   824,    -1,   113,    -1,   825,    -1,   826,    -1,
      11,    -1,    12,  1136,   114,    -1,   828,   829,    12,   832,
      -1,   230,    -1,   830,    -1,    -1,   830,   831,    -1,   925,
      -1,   951,    -1,   733,   833,   231,    -1,   739,   834,    -1,
      -1,   835,   836,    -1,   242,    -1,   837,    -1,   838,    -1,
      11,    -1,    12,   839,   243,    -1,   681,    -1,   841,   842,
      12,   845,    -1,   228,    -1,   843,    -1,    -1,   843,   844,
      -1,   925,    -1,   951,    -1,   733,   846,   229,    -1,   739,
     847,    -1,    -1,   848,   849,    -1,   242,    -1,   850,    -1,
     851,    -1,    11,    -1,    12,   852,   243,    -1,    -1,   852,
     853,    -1,   854,   855,   857,    -1,   113,    -1,    -1,   855,
     856,    -1,   966,    -1,   937,    -1,   936,    -1,    12,     6,
     114,    -1,   859,   860,    12,   863,    -1,   222,    -1,   861,
      -1,    -1,   861,   862,    -1,   925,    -1,   951,    -1,   733,
     864,   223,    -1,   739,   865,    -1,    -1,   866,   867,    -1,
     242,    -1,   868,    -1,   869,    -1,    11,    -1,    12,   870,
     243,    -1,    -1,   870,   871,    -1,   872,   873,   875,    -1,
     113,    -1,    -1,   873,   874,    -1,   943,    -1,   942,    -1,
     937,    -1,    12,   114,    -1,    11,    -1,   877,   878,    12,
     881,    -1,   236,    -1,   879,    -1,    -1,   879,   880,    -1,
     925,    -1,   951,    -1,   733,   882,   237,    -1,   739,   883,
      -1,    -1,   884,   885,    -1,   242,    -1,   886,    -1,   887,
      -1,    11,    -1,    12,   888,   243,    -1,   703,    -1,   890,
     891,    12,  1055,   892,    -1,   246,    -1,    -1,   954,    -1,
     247,    -1,   894,   895,   896,    -1,   210,    -1,   921,    -1,
      12,   898,   905,   912,   897,    -1,   211,    -1,   899,   900,
     901,    -1,   214,    -1,   923,    -1,   902,    -1,   903,    -1,
      11,    -1,    12,   904,   215,    -1,   681,    -1,   906,   907,
     908,    -1,   216,    -1,   923,    -1,   909,    -1,   910,    -1,
      11,    -1,    12,   911,   217,    -1,   681,    -1,    -1,   912,
     913,    -1,   914,   915,   918,    -1,   212,    -1,   916,    -1,
      -1,   916,   917,    -1,   933,    -1,   934,    -1,   957,    -1,
     960,    -1,   919,    -1,   920,    -1,    11,    -1,    12,   717,
     213,    -1,   166,     8,     6,     8,    -1,   167,     8,     6,
       8,    -1,   123,     8,     6,     8,    -1,   168,     8,     6,
       8,    -1,   170,     8,     6,     8,    -1,   179,     8,     6,
       8,    -1,   201,     8,     6,     8,    -1,   183,     8,     6,
       8,    -1,   186,     8,     6,     8,    -1,   187,     8,     6,
       8,    -1,   188,     8,     6,     8,    -1,   189,     8,     6,
       8,    -1,   191,     8,     6,     8,    -1,   192,     8,     6,
       8,    -1,   198,     8,     6,     8,    -1,   199,     8,     6,
       8,    -1,   200,     8,     6,     8,    -1,   184,     8,     6,
       8,    -1,   185,     8,     6,     8,    -1,   202,     8,   677,
       8,    -1,   203,     8,   677,     8,    -1,   194,     8,   677,
       8,    -1,   193,     8,   677,     8,    -1,   190,     8,   677,
       8,    -1,   946,    -1,   947,    -1,   164,    -1,   165,     3,
     678,    -1,   949,    -1,   950,    -1,   132,    -1,   133,     3,
       8,    -1,   952,    -1,   953,    -1,   162,    -1,   163,     3,
       8,    -1,   955,    -1,   956,    -1,   138,    -1,   139,     3,
       8,    -1,   958,    -1,   959,    -1,   160,    -1,   161,     3,
       8,    -1,   961,    -1,   962,    -1,   134,    -1,   135,     3,
       8,    -1,   964,    -1,   965,    -1,   142,    -1,   143,     3,
       8,    -1,   967,    -1,   968,    -1,   144,    -1,   145,     3,
       8,    -1,   970,    -1,   971,    -1,   150,    -1,   151,     3,
       8,    -1,    -1,   973,   974,   975,   310,    -1,   309,    -1,
     311,     8,     6,     8,    12,    -1,    -1,   975,   976,    -1,
     977,   978,    12,   981,   313,    -1,   312,    -1,   979,    -1,
      -1,   979,   980,    -1,   935,    -1,   954,    -1,  1025,    -1,
    1032,    -1,   988,    -1,   990,    -1,  1040,    -1,   992,    -1,
     994,    -1,   996,    -1,   998,    -1,  1052,    -1,  1000,    -1,
    1002,    -1,  1004,    -1,  1008,    -1,  1006,    -1,  1010,    -1,
    1017,    -1,  1012,    -1,  1015,    -1,  1046,    -1,  1049,    -1,
     982,    -1,   985,    -1,  1043,    -1,  1019,    -1,  1021,    -1,
    1023,    -1,    -1,   362,   983,   984,    -1,    11,    -1,    12,
     363,    -1,    -1,   364,   986,   987,    -1,    11,    -1,    12,
     365,    -1,    -1,   366,   989,   981,   981,   367,    -1,    -1,
     324,   991,   981,   981,   325,    -1,    -1,   326,   993,   981,
     981,   327,    -1,    -1,   340,   995,   981,   341,    -1,    -1,
     328,   997,   981,   981,   329,    -1,    -1,   322,   999,   981,
     981,   323,    -1,    -1,   330,  1001,   981,   331,    -1,    -1,
     332,  1003,   981,   333,    -1,    -1,   344,  1005,   981,   345,
      -1,    -1,   346,  1007,   981,   347,    -1,    -1,   348,  1009,
     981,   349,    -1,    -1,   338,  1011,   981,   339,    -1,  1013,
     981,  1014,    -1,   352,    -1,   353,    -1,    -1,   354,  1016,
     981,   355,    -1,    -1,   342,  1018,   981,   981,   981,   343,
      -1,    -1,   370,  1020,  1055,   371,    -1,    -1,   372,  1022,
    1055,   373,    -1,    -1,   374,  1024,  1055,   375,    -1,  1026,
    1028,  1027,    -1,   368,    -1,    11,    -1,    12,   369,    -1,
      -1,  1028,  1029,    -1,   960,    -1,   963,    -1,  1030,    -1,
      -1,   431,     3,  1031,     8,    -1,    -1,   350,  1033,  1036,
    1034,    -1,    11,    -1,    12,   351,    -1,    -1,    12,   981,
    1035,   351,    -1,    -1,  1036,  1037,    -1,  1038,    -1,  1039,
      -1,   202,     8,   677,     8,    -1,   198,     8,     6,     8,
      -1,    -1,   334,  1041,  1042,   335,    -1,    -1,  1042,   981,
      -1,    -1,   358,  1044,  1045,   359,    -1,    -1,  1045,   981,
      -1,    -1,   356,  1047,  1048,   357,    -1,    -1,  1048,   981,
      -1,    -1,   360,  1050,  1051,   361,    -1,    -1,  1051,   981,
      -1,    -1,   336,  1053,  1054,   337,    -1,    -1,  1054,   981,
      -1,  1056,    -1,  1062,    -1,  1066,    -1,  1070,    -1,  1074,
      -1,  1077,    -1,  1083,    -1,  1086,    -1,  1090,    -1,  1095,
      -1,  1098,    -1,  1101,    -1,  1104,    -1,  1107,    -1,  1110,
      -1,  1113,    -1,  1116,    -1,  1119,    -1,  1080,    -1,  1057,
    1058,  1060,    -1,   402,    -1,    -1,  1058,  1059,    -1,   666,
      -1,  1061,    -1,    11,    -1,    12,   403,    -1,   198,     8,
       6,     8,    -1,   429,     3,     8,    -1,  1063,  1065,  1064,
      -1,   252,    -1,    11,    -1,    12,   253,    -1,   198,     8,
       6,     8,    -1,  1067,  1069,  1068,    -1,   256,    -1,    11,
      -1,    12,   257,    -1,   198,     8,     6,     8,    -1,  1071,
    1073,  1072,    -1,   260,    -1,    11,    -1,    12,   261,    -1,
     198,     8,     6,     8,    -1,  1075,  1076,    -1,   376,    -1,
    1055,   377,    -1,  1078,  1079,    -1,   378,    -1,  1055,  1055,
     379,    -1,  1081,  1082,    -1,   404,    -1,   981,   405,    -1,
    1084,  1085,    -1,   406,    -1,  1055,   407,    -1,  1087,  1088,
      12,  1089,    -1,   380,    -1,    -1,  1094,    -1,  1055,   381,
      -1,  1091,  1092,    12,  1093,    -1,   382,    -1,    -1,  1094,
      -1,  1055,   383,    -1,   427,     3,     8,    -1,  1096,  1097,
      -1,   384,    -1,    11,    -1,    12,   385,    -1,  1099,  1100,
      -1,   386,    -1,  1055,  1055,   387,    -1,  1102,  1103,    -1,
     388,    -1,  1055,   389,    -1,  1105,  1106,    -1,   390,    -1,
    1055,  1055,   391,    -1,  1108,  1109,    -1,   392,    -1,  1055,
    1055,   393,    -1,    -1,   394,  1111,  1112,   395,    -1,    -1,
    1112,  1055,    -1,  1114,  1115,    -1,   396,    -1,  1055,  1135,
     397,    -1,  1117,  1118,    -1,   398,    -1,   981,   981,   981,
     981,  1055,   399,    -1,  1120,  1121,    -1,   400,    -1,  1055,
     401,    -1,    -1,  1123,  1124,  1126,    -1,   314,    -1,  1125,
      -1,   316,     8,     6,     8,    -1,  1127,    -1,  1128,    -1,
      11,    -1,    12,  1129,   315,    -1,    -1,  1129,  1130,    -1,
    1131,  1132,    12,  1055,   318,    -1,   317,    -1,  1133,    -1,
      -1,  1133,  1134,    -1,   935,    -1,   954,    -1,   981,    -1,
    1136,    -1,  1137,    -1,  1143,    -1,  1146,    -1,  1149,    -1,
    1152,    -1,  1155,    -1,  1158,    -1,  1161,    -1,  1164,    -1,
    1138,  1140,  1139,    -1,   414,    -1,    11,    -1,    12,   415,
      -1,  1141,    -1,    -1,  1141,  1142,    -1,   943,    -1,   942,
      -1,  1144,    12,  1145,    -1,   424,    -1,   981,   981,   425,
      -1,  1147,    12,  1148,    -1,   416,    -1,  1135,  1135,   417,
      -1,    -1,   420,    12,  1150,  1151,   421,    -1,    -1,  1151,
    1135,    -1,  1153,    12,  1154,    -1,   410,    -1,  1135,  1135,
     411,    -1,  1156,    12,  1157,    -1,   412,    -1,  1135,   413,
      -1,  1159,    12,  1160,    -1,   408,    -1,  1135,   409,    -1,
    1162,    12,  1163,    -1,   422,    -1,  1135,  1135,   423,    -1,
    1165,    12,  1166,    -1,   418,    -1,  1135,   419,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   450,   450,   453,   454,   456,   465,   466,   469,   470,
     474,   479,   489,   489,   491,   504,   510,   511,   514,   515,
     518,   521,   524,   527,   533,   540,   547,   555,   560,   560,
     568,   574,   586,   586,   588,   590,   597,   597,   600,   600,
     606,   612,   624,   624,   626,   628,   632,   632,   640,   641,
     642,   643,   644,   645,   647,   654,   655,   660,   662,   671,
     673,   673,   676,   681,   686,   691,   691,   693,   696,   705,
     707,   707,   710,   715,   720,   725,   725,   728,   730,   739,
     749,   749,   752,   757,   762,   768,   768,   774,   776,   776,
     778,   780,   787,   825,   826,   828,   828,   830,   830,   832,
     834,   836,   845,   847,   847,   850,   855,   860,   865,   870,
     881,   881,   885,   887,   899,   901,   901,   904,   909,   914,
     918,   923,   928,   935,   935,   937,   939,   952,   954,   954,
     957,   962,   967,   972,   977,   982,   987,   994,   994,   998,
    1000,  1010,  1012,  1012,  1015,  1020,  1025,  1029,  1036,  1036,
    1050,  1052,  1061,  1063,  1063,  1066,  1071,  1076,  1081,  1083,
    1085,  1091,  1097,  1097,  1099,  1101,  1103,  1105,  1119,  1122,
    1124,  1133,  1135,  1135,  1138,  1143,  1148,  1153,  1155,  1157,
    1163,  1169,  1169,  1171,  1173,  1175,  1177,  1191,  1200,  1200,
    1202,  1207,  1207,  1209,  1212,  1214,  1214,  1221,  1226,  1236,
    1236,  1238,  1240,  1242,  1244,  1244,  1246,  1251,  1267,  1314,
    1314,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1330,  1331,  1333,  1333,  1339,  1344,  1354,  1354,
    1356,  1358,  1360,  1362,  1362,  1364,  1369,  1382,  1414,  1414,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1427,  1428,
    1431,  1431,  1437,  1442,  1452,  1452,  1454,  1456,  1458,  1460,
    1460,  1462,  1467,  1482,  1520,  1520,  1523,  1524,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1534,  1535,  1578,  1578,  1580,
    1582,  1582,  1584,  1585,  1588,  1589,  1592,  1643,  1645,  1659,
    1660,  1662,  1662,  1686,  1687,  1690,  1691,  1693,  1695,  1696,
    1700,  1701,  1703,  1704,  1706,  1725,  1736,  1743,  1748,  1749,
    1751,  1752,  1754,  1754,  1757,  1769,  1770,  1772,  1773,  1777,
    1778,  1780,  1781,  1783,  1802,  1813,  1820,  1825,  1826,  1828,
    1829,  1831,  1831,  1834,  1846,  1847,  1849,  1859,  1863,  1864,
    1866,  1867,  1869,  1888,  1895,  1900,  1901,  1903,  1904,  1906,
    1906,  1909,  1921,  1922,  1927,  1927,  1935,  1936,  1938,  1939,
    1941,  1945,  1951,  1962,  1967,  1982,  1993,  2004,  2012,  2020,
    2039,  2050,  2061,  2073,  2084,  2095,  2107,  2118,  2130,  2142,
    2154,  2166,  2178,  2190,  2202,  2214,  2226,  2253,  2254,  2261,
    2263,  2263,  2265,  2266,  2267,  2268,  2432,  2440,  2442,  2442,
    2444,  2446,  2455,  2457,  2457,  2459,  2459,  2461,  2477,  2480,
    2480,  2482,  2482,  2485,  2516,  2524,  2526,  2526,  2528,  2530,
    2538,  2538,  2540,  2556,  2558,  2558,  2560,  2560,  2562,  2593,
    2603,  2603,  2605,  2607,  2615,  2615,  2617,  2886,  2938,  2961,
    2980,  2980,  2983,  2984,  2985,  2986,  2987,  3169,  3169,  3171,
    3173,  3213,  3215,  3215,  3220,  3238,  3265,  3265,  3268,  3269,
    3270,  3271,  3272,  3273,  3274,  3275,  3276,  3279,  3279,  3281,
    3281,  3286,  3286,  3286,  3287,  3287,  3287,  3288,  3288,  3288,
    3289,  3289,  3291,  3293,  3302,  3308,  3308,  3311,  3315,  3321,
    3323,  3323,  3329,  3339,  3349,  3349,  3351,  3353,  3355,  3358,
    3358,  3369,  3377,  3377,  3379,  3381,  3383,  3389,  3399,  3407,
    3407,  3409,  3411,  3413,  3416,  3418,  3427,  3433,  3433,  3436,
    3440,  3446,  3448,  3450,  3450,  3460,  3468,  3468,  3470,  3472,
    3474,  3477,  3479,  3488,  3494,  3494,  3497,  3501,  3507,  3509,
    3512,  3517,  3528,  3544,  3544,  3546,  3548,  3550,  3552,  3552,
    3554,  3561,  3568,  3587,  3587,  3590,  3591,  3593,  3593,  3595,
    3597,  3599,  3599,  3602,  3604,  3612,  3612,  3617,  3624,  3626,
    3635,  3641,  3641,  3644,  3648,  3655,  3657,  3660,  3664,  3675,
    3691,  3691,  3693,  3695,  3697,  3697,  3699,  3701,  3716,  3716,
    3718,  3720,  3729,  3731,  3740,  3746,  3746,  3749,  3753,  3760,
    3762,  3765,  3769,  3780,  3797,  3797,  3799,  3801,  3803,  3803,
    3805,  3807,  3822,  3822,  3824,  3826,  3836,  3838,  3847,  3853,
    3853,  3856,  3860,  3866,  3868,  3870,  3870,  3880,  3888,  3888,
    3890,  3892,  3894,  3897,  3899,  3908,  3914,  3914,  3917,  3921,
    3927,  3929,  3932,  3936,  3947,  3963,  3963,  3965,  3967,  3969,
    3969,  3971,  3974,  3986,  3986,  3989,  3990,  3991,  3993,  4026,
    4028,  4038,  4044,  4044,  4047,  4051,  4057,  4059,  4062,  4066,
    4077,  4090,  4090,  4092,  4094,  4096,  4096,  4098,  4125,  4136,
    4136,  4139,  4140,  4141,  4143,  4143,  4146,  4148,  4157,  4163,
    4163,  4166,  4170,  4176,  4178,  4180,  4180,  4190,  4198,  4198,
    4200,  4202,  4204,  4207,  4210,  4228,  4228,  4239,  4246,  4256,
    4264,  4270,  4272,  4286,  4298,  4304,  4310,  4310,  4312,  4314,
    4316,  4318,  4328,  4334,  4340,  4340,  4342,  4344,  4346,  4348,
    4348,  4353,  4358,  4370,  4372,  4372,  4375,  4376,  4377,  4385,
    4392,  4392,  4394,  4396,  4414,  4425,  4469,  4592,  4603,  4625,
    4650,  4661,  4675,  4690,  4705,  4717,  4729,  4749,  4769,  4779,
    4816,  4827,  4839,  4853,  4866,  4879,  4889,  4899,  4912,  4912,
    4914,  4924,  5088,  5088,  5090,  5097,  5124,  5124,  5126,  5135,
    5151,  5151,  5153,  5160,  5187,  5187,  5189,  5196,  5205,  5205,
    5207,  5214,  5241,  5241,  5245,  5253,  5262,  5262,  5264,  5271,
    5280,  5280,  5282,  5289,  5328,  5329,  5335,  5341,  5362,  5363,
    5365,  5375,  5394,  5401,  5401,  5404,  5413,  5426,  5427,  5428,
    5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,
    5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,
    5449,  5451,  5452,  5453,  5457,  5457,  5460,  5461,  5463,  5463,
    5466,  5467,  5471,  5471,  5476,  5476,  5481,  5481,  5486,  5486,
    5491,  5491,  5496,  5496,  5501,  5501,  5506,  5506,  5511,  5511,
    5516,  5516,  5521,  5521,  5526,  5526,  5531,  5533,  5539,  5546,
    5546,  5552,  5552,  5564,  5564,  5569,  5569,  5574,  5574,  5584,
    5591,  5597,  5598,  5600,  5601,  5604,  5608,  5612,  5616,  5615,
    5636,  5635,  5642,  5643,  5645,  5644,  5651,  5652,  5655,  5661,
    5669,  5676,  5694,  5694,  5705,  5705,  5708,  5708,  5722,  5723,
    5726,  5726,  5739,  5740,  5743,  5743,  5756,  5757,  5760,  5760,
    5770,  5771,  5777,  5778,  5779,  5780,  5781,  5782,  5783,  5784,
    5785,  5786,  5787,  5788,  5789,  5790,  5791,  5792,  5793,  5794,
    5795,  5798,  5809,  5817,  5817,  5820,  5821,  5824,  5825,  5827,
    5837,  5851,  5856,  5863,  5864,  5866,  5873,  5878,  5885,  5886,
    5888,  5895,  5900,  5907,  5908,  5910,  5917,  5919,  5925,  5927,
    5929,  5935,  5937,  5939,  5945,  5947,  5949,  5955,  5957,  5959,
    5965,  5965,  5970,  5972,  5974,  5980,  5980,  5985,  5987,  5998,
    6000,  6005,  6005,  6007,  6009,  6015,  6018,  6020,  6026,  6029,
    6031,  6037,  6040,  6042,  6048,  6052,  6051,  6063,  6063,  6070,
    6072,  6078,  6080,  6082,  6088,  6091,  6093,  6099,  6109,  6109,
    6115,  6123,  6125,  6145,  6145,  6147,  6149,  6151,  6151,  6153,
    6165,  6183,  6189,  6189,  6192,  6200,  6216,  6216,  6220,  6221,
    6222,  6223,  6224,  6225,  6226,  6227,  6228,  6232,  6236,  6245,
    6246,  6248,  6255,  6255,  6258,  6259,  6263,  6265,  6271,  6274,
    6276,  6282,  6285,  6285,  6295,  6296,  6302,  6304,  6310,  6313,
    6315,  6321,  6324,  6326,  6332,  6335,  6337,  6343,  6346,  6348,
    6354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "BOOLEAN",
  "ENDOFELEMENT", "GREATERTHAN", "EMPTYSEMIDEFINITENESSATT",
  "SEMIDEFINITENESSATT", "NUMBEROFQTERMSATT", "NUMBEROFCONESATT",
  "NUMBEROFSTAGESATT", "IDXONEATT", "IDXTWOATT", "HORIZONATT", "STARTATT",
  "STARTIDXATT", "MATRIXIDXATT", "LBMATRIXIDXATT", "LBCONEIDXATT",
  "UBMATRIXIDXATT", "UBCONEIDXATT", "TEMPLATEMATRIXIDXATT",
  "REFERENCEMATRIXIDXATT", "VARREFERENCEMATRIXIDXATT",
  "OBJREFERENCEMATRIXIDXATT", "CONREFERENCEMATRIXIDXATT",
  "ORDERCONEIDXATT", "CONSTANTMATRIXIDXATT", "NORMSCALEFACTORATT",
  "DISTORTIONMATRIXIDXATT", "AXISDIRECTIONATT", "FIRSTAXISDIRECTIONATT",
  "SECONDAXISDIRECTIONATT", "OSILEND", "INSTANCEDATAEND",
  "INSTANCEDATASTARTEND", "QUADRATICCOEFFICIENTSSTART",
  "QUADRATICCOEFFICIENTSEND", "QTERMSTART", "QTERMEND", "CONESSTART",
  "CONESEND", "NONNEGATIVECONESTART", "NONNEGATIVECONEEND",
  "NONPOSITIVECONESTART", "NONPOSITIVECONEEND", "ORTHANTCONESTART",
  "ORTHANTCONEEND", "POLYHEDRALCONESTART", "POLYHEDRALCONEEND",
  "QUADRATICCONESTART", "QUADRATICCONEEND", "ROTATEDQUADRATICCONESTART",
  "ROTATEDQUADRATICCONEEND", "SEMIDEFINITECONESTART",
  "SEMIDEFINITECONEEND", "PRODUCTCONESTART", "PRODUCTCONEEND",
  "INTERSECTIONCONESTART", "INTERSECTIONCONEEND", "DUALCONESTART",
  "DUALCONEEND", "POLARCONESTART", "POLARCONEEND", "DIRECTIONSTART",
  "DIRECTIONEND", "FACTORSSTART", "FACTORSEND", "COMPONENTSSTART",
  "COMPONENTSEND", "TIMEDOMAINSTART", "TIMEDOMAINEND", "STAGESSTART",
  "STAGESEND", "STAGESTART", "STAGEEND", "INTERVALSTART", "INTERVALEND",
  "HEADERSTART", "HEADEREND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "INDEXESSTART", "INDEXESEND", "VALUESSTART", "VALUESEND",
  "NONZEROSSTART", "NONZEROSEND", "ELSTART", "ELEND", "ENUMERATIONSTART",
  "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "BASE64START", "BASE64END", "NUMBEROFELATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFITEMSATT", "EMPTYCATEGORYATT", "CATEGORYATT",
  "EMPTYDESCRIPTIONATT", "DESCRIPTIONATT", "EMPTYSOLVERATT", "SOLVERATT",
  "EMPTYNAMEATT", "NAMEATT", "EMPTYTYPEATT", "TYPEATT", "EMPTYENUMTYPEATT",
  "ENUMTYPEATT", "EMPTYSHAPEATT", "SHAPEATT", "EMPTYUNITATT", "UNITATT",
  "EMPTYVALUEATT", "VALUEATT", "EMPTYVALUETYPEATT", "VALUETYPEATT",
  "EMPTYCONTYPEATT", "CONTYPEATT", "EMPTYOBJTYPEATT", "OBJTYPEATT",
  "EMPTYVARTYPEATT", "VARTYPEATT", "EMPTYMATRIXCONTYPEATT",
  "MATRIXCONTYPEATT", "EMPTYMATRIXOBJTYPEATT", "MATRIXOBJTYPEATT",
  "EMPTYMATRIXVARTYPEATT", "MATRIXVARTYPEATT", "EMPTYMATRIXTYPEATT",
  "MATRIXTYPEATT", "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "NUMBEROFMATRICESATT", "NUMBEROFVALUESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFCONATT", "NUMBEROFCONIDXATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJIDXATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIDXATT", "NUMBEROFMATRIXCONATT",
  "NUMBEROFMATRIXOBJATT", "NUMBEROFMATRIXVARATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "BLOCKROWIDXATT",
  "BLOCKCOLIDXATT", "REATT", "IMATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT",
  "MATRIXCONIDXATT", "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT",
  "COEFATT", "CONSTANTATT", "MATRICESSTART", "MATRICESEND", "MATRIXSTART",
  "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSSTART",
  "BLOCKSEND", "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART", "COLOFFSETEND",
  "ROWOFFSETSTART", "ROWOFFSETEND", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "COMPLEXELEMENTSSTART",
  "COMPLEXELEMENTSEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "REALVALUEDEXPRESSIONSSTART", "REALVALUEDEXPRESSIONSSEND",
  "COMPLEXVALUEDEXPRESSIONSSTART", "COMPLEXVALUEDEXPRESSIONSSEND",
  "STRINGVALUEDELEMENTSSTART", "STRINGVALUEDELEMENTSEND",
  "STARTVECTORSTART", "STARTVECTOREND", "INDEXSTART", "INDEXEND",
  "VALUESTART", "VALUEEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "MATRIXPROGRAMMINGSTART",
  "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART", "MATRIXVARIABLESEND",
  "MATRIXVARSTART", "MATRIXVAREND", "MATRIXOBJECTIVESSTART",
  "MATRIXOBJECTIVESEND", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "MATRIXCONSTART",
  "MATRIXCONEND", "CONSTART", "CONEND", "CONSTRAINTSSTART",
  "CONSTRAINTSEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART",
  "OBJECTIVESEND", "VARSTART", "VAREND", "VARIABLESSTART", "VARIABLESEND",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "ATEQUALITYSTART", "ATEQUALITYEND", "ATLOWERSTART",
  "ATLOWEREND", "ATUPPERSTART", "ATUPPEREND", "BASICSTART", "BASICEND",
  "ISFREESTART", "ISFREEEND", "SUPERBASICSTART", "SUPERBASICEND",
  "UNKNOWNSTART", "UNKNOWNEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND", "OTHERSTART", "OTHEREND",
  "DUMMY", "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND",
  "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND", "NUMBEROFEXPR",
  "EXPRSTART", "EXPREND", "NUMBEROFMATRIXTERMSATT", "MATRIXTERMSTART",
  "MATRIXTERMEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND",
  "MINUSSTART", "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND",
  "SQRTSTART", "SQRTEND", "SUMSTART", "SUMEND", "PRODUCTSTART",
  "PRODUCTEND", "EXPSTART", "EXPEND", "NEGATESTART", "NEGATEEND",
  "IFSTART", "IFEND", "SQUARESTART", "SQUAREEND", "COSSTART", "COSEND",
  "SINSTART", "SINEND", "VARIABLESTART", "VARIABLEEND", "ABSSTART",
  "ABSEND", "ERFSTART", "ERFEND", "MAXSTART", "MAXEND", "ALLDIFFSTART",
  "ALLDIFFEND", "MINSTART", "MINEND", "ESTART", "EEND", "PISTART", "PIEND",
  "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND", "MATRIXTRACESTART",
  "MATRIXTRACEEND", "MATRIXTOSCALARSTART", "MATRIXTOSCALAREND",
  "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND", "MATRIXDOTTIMESSTART",
  "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
  "MATRIXLOWERTRIANGLEEND", "MATRIXUPPERTRIANGLESTART",
  "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART", "MATRIXMERGEEND",
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXNEGATESTART",
  "MATRIXNEGATEEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
  "MATRIXTIMESSTART", "MATRIXTIMESEND", "MATRIXPRODUCTSTART",
  "MATRIXPRODUCTEND", "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART", "MATRIXREFERENCEEND",
  "IDENTITYMATRIXSTART", "IDENTITYMATRIXEND", "MATRIXINVERSESTART",
  "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART", "COMPLEXCONJUGATEEND",
  "COMPLEXMINUSSTART", "COMPLEXMINUSEND", "COMPLEXNEGATESTART",
  "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART", "COMPLEXNUMBEREND",
  "COMPLEXPLUSSTART", "COMPLEXPLUSEND", "COMPLEXSQUARESTART",
  "COMPLEXSQUAREEND", "COMPLEXSUMSTART", "COMPLEXSUMEND",
  "COMPLEXTIMESSTART", "COMPLEXTIMESEND", "CREATECOMPLEXSTART",
  "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "EMPTYTRANSPOSEATT", "TRANSPOSEATT", "EMPTYIDATT", "IDATT", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osildoc", "theInstanceEnd",
  "osilEnd", "osilEnding", "quadraticCoefficients",
  "quadraticCoefficientsStart", "osilQuadnumberATT", "qTermlist", "qterm",
  "qtermStart", "qtermend", "anotherqTermATT", "qtermatt",
  "osilQtermidxOneATT", "osilQtermidxTwoATT", "osilQtermcoefATT",
  "osilQtermidxATT", "matrices", "matricesStart", "matricesAttributes",
  "matricesContent", "matricesEmpty", "matricesLaden", "matrixList",
  "cones", "conesStart", "conesAttributes", "conesContent", "conesEmpty",
  "conesLaden", "coneList", "cone", "nonnegativeCone",
  "nonnegativeConeStart", "nonnegativeConeAttributes",
  "nonnegativeConeAttList", "nonnegativeConeAtt", "nonnegativeConeEnd",
  "nonpositiveCone", "nonpositiveConeStart", "nonpositiveConeAttributes",
  "nonpositiveConeAttList", "nonpositiveConeAtt", "nonpositiveConeEnd",
  "generalOrthantCone", "generalOrthantConeStart",
  "generalOrthantConeAttributes", "generalOrthantConeAttList",
  "generalOrthantConeAtt", "generalOrthantConeContent",
  "generalOrthantConeDirectionList", "generalOrthantConeDirections",
  "generalOrthantConeDirection", "generalOrthantConeDirectionStart",
  "generalOrthantConeDirectionAttributes",
  "generalOrthantConeDirectionAttributeList",
  "generalOrthantConeDirectionAtt", "generalOrthantConeDirectionEnd",
  "generalOrthantConeEnd", "polyhedralCone", "polyhedralConeStart",
  "polyhedralConeAttributes", "polyhedralConeAttList", "polyhedralConeAtt",
  "referenceMatrixATT", "polyhedralConeEnd", "quadraticCone",
  "quadraticConeStart", "quadraticConeAttributes", "quadraticConeAttList",
  "quadraticConeAtt", "quadraticConeEnd", "rotatedQuadraticCone",
  "rotatedQuadraticConeStart", "rotatedQuadraticConeAttributes",
  "rotatedQuadraticConeAttList", "rotatedQuadraticConeAtt",
  "rotatedQuadraticConeEnd", "semidefiniteCone", "semidefiniteConeStart",
  "semidefiniteConeAttributes", "semidefiniteConeAttList",
  "semidefiniteConeAtt", "semidefiniteConeEnd", "productCone",
  "productConeStart", "productConeAttributes", "productConeAttList",
  "productConeAtt", "productConeContent", "productConeFactors",
  "productConeFactorsStart", "productConeFactorsAttributes",
  "productConeFactorsContent", "productConeFactorsEmpty",
  "productConeFactorsLaden", "productConeFactorList",
  "productConeFactorsEnd", "productConeEnd", "intersectionCone",
  "intersectionConeStart", "intersectionConeAttributes",
  "intersectionConeAttList", "intersectionConeAtt",
  "intersectionConeContent", "intersectionConeComponents",
  "intersectionConeComponentsStart",
  "intersectionConeComponentsAttributes",
  "intersectionConeComponentsContent", "intersectionConeComponentsEmpty",
  "intersectionConeComponentsLaden", "intersectionConeComponentList",
  "intersectionConeComponentsEnd", "intersectionConeEnd",
  "matrixProgramming", "matrixProgrammingStart",
  "matrixProgrammingContent", "matrixProgrammingEmpty",
  "matrixProgrammingLaden", "matrixVariables", "matrixVariablesStart",
  "matrixVariablesAttributes", "matrixVariablesContent",
  "matrixVariablesEmpty", "matrixVariablesLaden", "matrixVariablesEnd",
  "matrixVarList", "matrixVariable", "matrixVariableStart",
  "matrixVariableAttributes", "matrixVariableAttList", "matrixVariableAtt",
  "matrixVariableEnd", "matrixObjectives", "matrixObjectivesStart",
  "matrixObjectivesAttributes", "matrixObjectivesContent",
  "matrixObjectivesEmpty", "matrixObjectivesLaden", "matrixObjectivesEnd",
  "matrixObjList", "matrixObjective", "matrixObjectiveStart",
  "matrixObjectiveAttributes", "matrixObjectiveAttList",
  "matrixObjectiveAtt", "matrixObjectiveEnd", "matrixConstraints",
  "matrixConstraintsStart", "matrixConstraintsAttributes",
  "matrixConstraintsContent", "matrixConstraintsEmpty",
  "matrixConstraintsLaden", "matrixConstraintsEnd", "matrixConList",
  "matrixConstraint", "matrixConstraintStart",
  "matrixConstraintAttributes", "matrixConstraintAttList",
  "matrixConstraintAtt", "matrixConstraintEnd", "timeDomain",
  "timeDomainStart", "timeDomainContent", "timeDomainEmpty",
  "timeDomainLaden", "stages", "stagesstart", "osilNumberofstagesATT",
  "stagelist", "stage", "$@1", "osilStagenameATT", "stageend",
  "stagecontent", "stagevariables", "anotherstagevarATT", "stagevaratt",
  "osilNumberofstagevariablesATT", "osilStagevarstartidxATT",
  "restofstagevariables", "emptyvarlist", "stagevarlist", "stagevar",
  "$@2", "osilStagevaridxATT", "stagevarend", "stageconstraints",
  "anotherstageconATT", "stageconatt", "osilNumberofstageconstraintsATT",
  "osilStageconstartidxATT", "restofstageconstraints", "emptyconlist",
  "stageconlist", "stagecon", "$@3", "osilStageconidxATT", "stageconend",
  "stageobjectives", "anotherstageobjATT", "stageobjatt",
  "osilNumberofstageobjectivesATT", "restofstageobjectives",
  "emptyobjlist", "stageobjlist", "stageobj", "$@4", "osilStageobjidxATT",
  "stageobjend", "interval", "$@5", "intervalend", "anotherIntervalATT",
  "intervalatt", "osilStageobjstartidxATT", "osilIntervalhorizonATT",
  "osilIntervalstartATT", "numberOfMatricesATT", "numberOfConesATT",
  "numberOfMatrixVarATT", "numberOfMatrixObjATT", "numberOfMatrixConATT",
  "normScaleFactorATT", "distortionMatrixIdxATT", "axisDirectionATT",
  "firstAxisDirectionATT", "secondAxisDirectionATT", "semidefinitenessATT",
  "matrixIdxATT", "lbMatrixIdxATT", "ubMatrixIdxATT",
  "constantMatrixIdxATT", "templateMatrixIdxATT",
  "varReferenceMatrixIdxATT", "objReferenceMatrixIdxATT",
  "conReferenceMatrixIdxATT", "lbConeIdxATT", "ubConeIdxATT",
  "orderConeIdxATT", "aNumber", "quote", "xmlWhiteSpace",
  "xmlWhiteSpaceChar", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "osglIntVectorBase64Content",
  "osglIntVectorBase64Empty", "osglIntVectorBase64Laden",
  "osglDblArrayData", "osglDblVectorElArray", "osglDblVectorEl",
  "osglDblVectorElStart", "osglDblVectorElAttributes",
  "osglDblVectorElContent", "osglDblVectorBase64",
  "osglDblVectorBase64Content", "osglDblVectorBase64Empty",
  "osglDblVectorBase64Laden", "osglStrArrayData", "osglStrVectorElArray",
  "osglStrVectorEl", "osglStrVectorElStart", "osglStrVectorElAttributes",
  "osglStrVectorElContent", "osglMatrix", "matrixStart",
  "matrixAttributes", "matrixAttributeList", "matrixAttribute",
  "matrixContent", "matrixEmpty", "matrixLaden", "matrixOrBlockBody",
  "baseMatrix", "baseMatrixStart", "baseMatrixAttributes",
  "baseMatrixAttList", "baseMatrixAtt", "baseMatrixEnd",
  "matrixConstructorList", "matrixConstructor", "constantElements",
  "constantElementsStart", "constantElementsAttributes",
  "constantElementsAttList", "constantElementsAtt",
  "constantElementsContent", "constantElementsNonzeros",
  "matrixElementsStartVector", "matrixElementsStartVectorStart",
  "matrixElementsStartVectorContent", "matrixElementsStartVectorEmpty",
  "matrixElementsStartVectorLaden", "matrixElementsStartVectorBody",
  "matrixElementsIndexVector", "matrixElementsIndexStart",
  "matrixElementsIndexContent", "matrixElementsIndexEmpty",
  "matrixElementsIndexLaden", "matrixElementsIndexBody",
  "constantElementsValues", "constantElementsValueStart",
  "constantElementsValueContent", "constantElementsValueEmpty",
  "constantElementsValueLaden", "constantElementsValueBody",
  "varReferenceElements", "varReferenceElementsStart",
  "varReferenceElementsAttributes", "varReferenceElementsAttList",
  "varReferenceElementsAtt", "varReferenceElementsContent",
  "varReferenceElementsNonzeros", "varReferenceElementsValues",
  "varReferenceElementsValuesStart", "varReferenceElementsValuesContent",
  "varReferenceElementsValuesEmpty", "varReferenceElementsValuesLaden",
  "varReferenceElementsValuesBody", "linearElements",
  "linearElementsStart", "linearElementsAttributes",
  "linearElementsAttList", "linearElementsAtt", "linearElementsContent",
  "linearElementsNonzeros", "linearElementsValues",
  "linearElementsValuesStart", "linearElementsValuesContent",
  "linearElementsValuesEmpty", "linearElementsValuesLaden",
  "linearElementsValuesBody", "linearElementsValuesElList",
  "linearElementsValuesEl", "linearElementsValuesElStart",
  "linearElementsValuesElAttributes", "linearElementsValuesElAttList",
  "linearElementsValuesElAtt", "linearElementsValuesElContent",
  "linearElementsValuesElEmpty", "linearElementsValuesElLaden",
  "linearElementsValuesVarIdxList", "linearElementsValuesVarIdx",
  "linearElementsValuesVarIdxStart", "linearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "realValuedExpressions",
  "realValuedExpressionsStart", "realValuedExpressionsAttributes",
  "realValuedExpressionsAttList", "realValuedExpressionsAtt",
  "realValuedExpressionsContent", "realValuedExpressionsNonzeros",
  "realValuedExpressionsValues", "realValuedExpressionsValuesStart",
  "realValuedExpressionsValuesContent", "realValuedExpressionsValuesEmpty",
  "realValuedExpressionsValuesLaden", "realValuedExpressionsElList",
  "realValuedExpressionsEl", "realValuedExpressionsElStart",
  "realValuedExpressionsElContent", "realValuedExpressionsElEmpty",
  "realValuedExpressionsElLaden", "complexValuedExpressions",
  "complexValuedExpressionsStart", "complexValuedExpressionsAttributes",
  "complexValuedExpressionsAttList", "complexValuedExpressionsAtt",
  "complexValuedExpressionsContent", "complexValuedExpressionsNonzeros",
  "complexValuedExpressionsValues", "complexValuedExpressionsValuesStart",
  "complexValuedExpressionsValuesContent",
  "complexValuedExpressionsValuesEmpty",
  "complexValuedExpressionsValuesLaden", "complexValuedExpressionsElList",
  "complexValuedExpressionsEl", "complexValuedExpressionsElStart",
  "complexValuedExpressionsElContent", "complexValuedExpressionsElEmpty",
  "complexValuedExpressionsElLaden", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsAttributes",
  "objReferenceElementsAttList", "objReferenceElementsAtt",
  "objReferenceElementsContent", "objReferenceElementsNonzeros",
  "objReferenceElementsValues", "objReferenceElementsValuesStart",
  "objReferenceElementsValuesContent", "objReferenceElementsValuesEmpty",
  "objReferenceElementsValuesLaden", "objReferenceElementsValuesBody",
  "conReferenceElements", "conReferenceElementsStart",
  "conReferenceElementsAttributes", "conReferenceElementsAttList",
  "conReferenceElementsAtt", "conReferenceElementsContent",
  "conReferenceElementsNonzeros", "conReferenceElementsValues",
  "conReferenceElementsValuesStart", "conReferenceElementsValuesContent",
  "conReferenceElementsValuesEmpty", "conReferenceElementsValuesLaden",
  "conReferenceElementsElList", "conReferenceElementsEl",
  "conReferenceElementsElStart", "conReferenceElementsElAttributeList",
  "conReferenceElementsElAttribute", "conReferenceElementsElContent",
  "complexElements", "complexElementsStart", "complexElementsAttributes",
  "complexElementsAttList", "complexElementsAtt", "complexElementsContent",
  "complexElementsNonzeros", "complexElementsValues",
  "complexElementsValuesStart", "complexElementsValuesContent",
  "complexElementsValuesEmpty", "complexElementsValuesLaden",
  "complexElementsElList", "complexElementsEl", "complexElementsElStart",
  "complexElementsElAttributeList", "complexElementsElAttribute",
  "complexElementsElEnd", "stringValuedElements",
  "stringValuedElementsStart", "stringValuedElementsAttributes",
  "stringValuedElementsAttList", "stringValuedElementsAtt",
  "stringValuedElementsContent", "stringValuedElementsNonzeros",
  "stringValuedElementsValues", "stringValuedElementsValueStart",
  "stringValuedElementsValueContent", "stringValuedElementsValueEmpty",
  "stringValuedElementsValueLaden", "stringValuedElementsValueBody",
  "matrixTransformation", "matrixTransformationStart",
  "matrixTransformationShapeATT", "matrixTransformationEnd",
  "matrixBlocks", "matrixBlocksStart", "matrixBlocksAttributes",
  "matrixBlocksContent", "matrixBlocksEnd", "colOffsets", "colOffsetStart",
  "colOffsetNumberOfElAttribute", "colOffsetContent", "colOffsetEmpty",
  "colOffsetLaden", "colOffsetBody", "rowOffsets", "rowOffsetStart",
  "rowOffsetNumberOfElAttribute", "rowOffsetContent", "rowOffsetEmpty",
  "rowOffsetLaden", "rowOffsetBody", "blockList", "matrixBlock",
  "matrixBlockStart", "matrixBlockAttributes", "matrixBlockAttList",
  "matrixBlockAtt", "matrixBlockContent", "blockEmpty", "blockLaden",
  "osglNumberOfBlocksATT", "osglNumberOfColumnsATT", "osglNumberOfElATT",
  "osglNumberOfRowsATT", "osglNumberOfValuesATT", "osglNumberOfVarIdxATT",
  "osglBase64SizeATT", "osglBaseMatrixIdxATT", "osglBaseMatrixStartRowATT",
  "osglBaseMatrixStartColATT", "osglBaseMatrixEndRowATT",
  "osglBaseMatrixEndColATT", "osglBlockRowIdxATT", "osglBlockColIdxATT",
  "osglIdxATT", "osglIncrATT", "osglMultATT",
  "osglTargetMatrixFirstRowATT", "osglTargetMatrixFirstColATT",
  "osglCoefATT", "osglConstantATT", "osglImagPartATT", "osglRealPartATT",
  "osglScalarMultiplierATT", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent", "osglNameATT",
  "nameAttEmpty", "nameAttContent", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "osglShapeATT", "shapeAttEmpty", "shape",
  "osglSymmetryATT", "symmetryAttEmpty", "symmetryAttContent",
  "osglTypeATT", "typeAttEmpty", "typeAttContent", "osglValueATT",
  "valueAttEmpty", "valueAttContent", "osglValueTypeATT",
  "valueTypeAttEmpty", "valueTypeAttContent", "osglVarTypeATT",
  "varTypeAttEmpty", "varTypeAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "realValuedExpressionTree", "nlstart", "nlAttributes", "nlAttributeList",
  "nlAttribute", "nlnode", "E", "$@6", "eend", "PI", "$@7", "piend",
  "times", "$@8", "plus", "$@9", "minus", "$@10", "negate", "$@11",
  "divide", "$@12", "power", "$@13", "ln", "$@14", "sqrt", "$@15",
  "square", "$@16", "cos", "$@17", "sin", "$@18", "exp", "$@19", "abs",
  "absStart", "absEnd", "erf", "$@20", "if", "$@21", "matrixDeterminant",
  "$@22", "matrixTrace", "$@23", "matrixToScalar", "$@24", "number",
  "numberStart", "numberEnd", "numberAttributeList", "numberAttribute",
  "numberidATT", "$@25", "variable", "$@26", "variableend", "$@27",
  "anotherVariableATT", "variableATT", "variablecoefATT", "variableidxATT",
  "sum", "$@28", "anothersumnlnode", "allDiff", "$@29",
  "anotherallDiffnlnode", "max", "$@30", "anothermaxnlnode", "min", "$@31",
  "anotherminnlnode", "product", "$@32", "anotherproductnlnode",
  "OSnLMNode", "matrixReference", "matrixReferenceStart",
  "matrixRefAttributeList", "matrixRefAttribute", "matrixReferenceEnd",
  "matrixTransposeATT", "matrixVarReference", "matrixVarReferenceStart",
  "matrixVarReferenceEnd", "matrixVarIdxATT", "matrixObjReference",
  "matrixObjReferenceStart", "matrixObjReferenceEnd", "matrixObjIdxATT",
  "matrixConReference", "matrixConReferenceStart", "matrixConReferenceEnd",
  "matrixConIdxATT", "matrixDiagonal", "matrixDiagonalStart",
  "matrixDiagonalContent", "matrixDotTimes", "matrixDotTimesStart",
  "matrixDotTimesContent", "identityMatrix", "identityMatrixStart",
  "identityMatrixContent", "matrixInverse", "matrixInverseStart",
  "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixNegate", "matrixNegateStart",
  "matrixNegateContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@33",
  "anothermatrixproductnode", "matrixScalarTimes",
  "matrixScalarTimesStart", "matrixScalarTimesContent",
  "matrixSubMatrixAt", "matrixSubMatrixAtStart",
  "matrixSubMatrixAtContent", "matrixTranspose", "matrixTransposeStart",
  "matrixTransposeContent", "matrixExpressions", "matrixExpressionsStart",
  "matrixExpressionsAtt", "numberOfExprATT", "matrixExpressionsContent",
  "matrixExpressionsEmpty", "matrixExpressionsLaden", "matrixExprList",
  "matrixExpr", "matrixExprStart", "matrixExprAttributes",
  "matrixExprAttributeList", "exprAttribute", "scalarNode", "OSnLCNode",
  "complexNumber", "complexNumberStart", "complexNumberEnd",
  "complexNumberAttributes", "complexNumberAttList", "complexNumberAtt",
  "createComplex", "createComplexStart", "createComplexContent",
  "complexPlus", "complexPlusStart", "complexPlusContent", "complexSum",
  "$@34", "anothercsumnode", "complexMinus", "complexMinusStart",
  "complexMinusContent", "complexNegate", "complexNegateStart",
  "complexNegateContent", "complexConjugate", "complexConjugateStart",
  "complexConjugateContent", "complexTimes", "complexTimesStart",
  "complexTimesContent", "complexSquare", "complexSquareStart",
  "complexSquareContent", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   436,   437,   438,   438,   439,   440,   440,   441,   441,
     442,   443,   444,   444,   445,   446,   447,   447,   448,   448,
     449,   449,   449,   449,   450,   451,   452,   453,   454,   454,
     455,   456,   457,   457,   458,   459,   460,   460,   461,   461,
     462,   463,   464,   464,   465,   466,   467,   467,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   469,   470,   471,
     472,   472,   473,   473,   473,   474,   474,   475,   476,   477,
     478,   478,   479,   479,   479,   480,   480,   481,   482,   483,
     484,   484,   485,   485,   485,   486,   486,   487,   488,   488,
     489,   490,   491,   492,   492,   493,   493,   494,   494,   495,
     496,   497,   498,   499,   499,   500,   500,   500,   500,   501,
     502,   502,   503,   504,   505,   506,   506,   507,   507,   507,
     507,   507,   507,   508,   508,   509,   510,   511,   512,   512,
     513,   513,   513,   513,   513,   513,   513,   514,   514,   515,
     516,   517,   518,   518,   519,   519,   519,   519,   520,   520,
     521,   522,   523,   524,   524,   525,   525,   525,   526,   527,
     528,   529,   530,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   539,   540,   540,   540,   541,   542,   543,
     544,   545,   545,   546,   547,   548,   549,   550,   551,   551,
     552,   553,   553,   554,   555,   556,   556,   557,   558,   559,
     559,   560,   561,   562,   563,   563,   564,   565,   566,   567,
     567,   568,   568,   568,   568,   568,   568,   568,   568,   568,
     568,   568,   569,   569,   570,   570,   571,   572,   573,   573,
     574,   575,   576,   577,   577,   578,   579,   580,   581,   581,
     582,   582,   582,   582,   582,   582,   582,   582,   583,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   590,   591,
     591,   592,   593,   594,   595,   595,   596,   596,   596,   596,
     596,   596,   596,   596,   596,   597,   597,   598,   598,   599,
     600,   600,   601,   601,   602,   602,   603,   604,   605,   606,
     606,   608,   607,   609,   609,   610,   610,   611,   612,   612,
     613,   613,   614,   614,   615,   616,   617,   617,   618,   618,
     619,   619,   621,   620,   622,   623,   623,   624,   624,   625,
     625,   626,   626,   627,   628,   629,   629,   630,   630,   631,
     631,   633,   632,   634,   635,   635,   636,   636,   637,   637,
     638,   638,   639,   640,   640,   641,   641,   642,   642,   644,
     643,   645,   646,   646,   648,   647,   649,   649,   650,   650,
     651,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   677,   678,
     679,   679,   680,   680,   680,   680,   681,   681,   682,   682,
     683,   684,   685,   686,   686,   687,   687,   688,   689,   690,
     690,   691,   691,   692,   693,   693,   694,   694,   695,   696,
     697,   697,   698,   699,   700,   700,   701,   701,   702,   703,
     704,   704,   705,   706,   707,   707,   708,   709,   710,   711,
     712,   712,   713,   713,   713,   713,   713,   714,   714,   715,
     716,   717,   718,   718,   719,   720,   721,   721,   722,   722,
     722,   722,   722,   722,   722,   722,   722,   723,   723,   724,
     724,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,   725,   726,   727,   728,   729,   729,   730,   730,   731,
     732,   732,   733,   734,   735,   735,   736,   737,   738,   739,
     739,   740,   741,   741,   742,   743,   744,   745,   746,   747,
     747,   748,   749,   750,   751,   752,   753,   754,   754,   755,
     755,   756,   757,   758,   758,   759,   760,   760,   761,   762,
     763,   764,   765,   766,   767,   767,   768,   768,   769,   770,
     771,   771,   772,   773,   773,   774,   775,   776,   777,   777,
     778,   779,   780,   781,   781,   782,   782,   783,   783,   784,
     785,   786,   786,   787,   788,   789,   789,   790,   791,   792,
     793,   794,   794,   795,   795,   796,   797,   798,   798,   799,
     800,   800,   801,   802,   803,   803,   804,   805,   806,   806,
     807,   808,   809,   810,   811,   812,   812,   813,   813,   814,
     815,   816,   816,   817,   818,   818,   819,   820,   821,   821,
     822,   823,   824,   824,   825,   826,   827,   828,   829,   830,
     830,   831,   831,   832,   833,   834,   834,   835,   836,   836,
     837,   838,   839,   840,   841,   842,   843,   843,   844,   844,
     845,   846,   847,   847,   848,   849,   849,   850,   851,   852,
     852,   853,   854,   855,   855,   856,   856,   856,   857,   858,
     859,   860,   861,   861,   862,   862,   863,   864,   865,   865,
     866,   867,   867,   868,   869,   870,   870,   871,   872,   873,
     873,   874,   874,   874,   875,   875,   876,   877,   878,   879,
     879,   880,   880,   881,   882,   883,   883,   884,   885,   885,
     886,   887,   888,   889,   890,   891,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   901,   902,   903,
     904,   905,   906,   907,   908,   908,   909,   910,   911,   912,
     912,   913,   914,   915,   916,   916,   917,   917,   917,   917,
     918,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   945,
     946,   947,   948,   948,   949,   950,   951,   951,   952,   953,
     954,   954,   955,   956,   957,   957,   958,   959,   960,   960,
     961,   962,   963,   963,   964,   965,   966,   966,   967,   968,
     969,   969,   970,   971,   972,   972,   973,   974,   975,   975,
     976,   977,   978,   979,   979,   980,   980,   981,   981,   981,
     981,   981,   981,   981,   981,   981,   981,   981,   981,   981,
     981,   981,   981,   981,   981,   981,   981,   981,   981,   981,
     981,   981,   981,   981,   983,   982,   984,   984,   986,   985,
     987,   987,   989,   988,   991,   990,   993,   992,   995,   994,
     997,   996,   999,   998,  1001,  1000,  1003,  1002,  1005,  1004,
    1007,  1006,  1009,  1008,  1011,  1010,  1012,  1013,  1014,  1016,
    1015,  1018,  1017,  1020,  1019,  1022,  1021,  1024,  1023,  1025,
    1026,  1027,  1027,  1028,  1028,  1029,  1029,  1029,  1031,  1030,
    1033,  1032,  1034,  1034,  1035,  1034,  1036,  1036,  1037,  1037,
    1038,  1039,  1041,  1040,  1042,  1042,  1044,  1043,  1045,  1045,
    1047,  1046,  1048,  1048,  1050,  1049,  1051,  1051,  1053,  1052,
    1054,  1054,  1055,  1055,  1055,  1055,  1055,  1055,  1055,  1055,
    1055,  1055,  1055,  1055,  1055,  1055,  1055,  1055,  1055,  1055,
    1055,  1056,  1057,  1058,  1058,  1059,  1059,  1060,  1060,   666,
    1061,  1062,  1063,  1064,  1064,  1065,  1066,  1067,  1068,  1068,
    1069,  1070,  1071,  1072,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1088,  1089,  1090,  1091,  1092,  1092,  1093,  1094,  1095,
    1096,  1097,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1111,  1110,  1112,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1122,
    1123,  1124,  1125,  1126,  1126,  1127,  1128,  1129,  1129,  1130,
    1131,  1132,  1133,  1133,  1134,  1134,  1135,  1135,  1136,  1136,
    1136,  1136,  1136,  1136,  1136,  1136,  1136,  1137,  1138,  1139,
    1139,  1140,  1141,  1141,  1142,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1150,  1149,  1151,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     0,     0,     4,
       1,     5,     0,     2,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     1,     4,     4,     4,     4,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     2,     3,     3,     4,     1,     5,     1,
       2,     0,     4,     0,     3,     1,     3,     3,     0,     3,
       0,     2,     1,     1,     4,     4,     1,     3,     1,     2,
       1,     2,     0,     4,     4,     1,     2,     0,     3,     0,
       2,     1,     1,     4,     4,     1,     3,     1,     2,     1,
       2,     0,     4,     4,     1,     2,     0,     3,     0,     2,
       1,     1,     4,     1,     3,     1,     2,     1,     2,     0,
       4,     4,     1,     2,     0,     4,     1,     2,     0,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     2,     1,     3,     1,     1,     0,     2,     3,     1,
       0,     1,     3,     3,     1,     1,     2,     1,     3,     1,
       0,     2,     3,     1,     0,     1,     3,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       1,     4,     1,     1,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     1,     3,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     3,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     2,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     1,     5,     1,     0,     1,     1,     3,     1,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     0,     4,     1,     5,     0,     2,
       5,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     2,     0,     3,
       1,     2,     0,     5,     0,     5,     0,     5,     0,     4,
       0,     5,     0,     5,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     1,     1,     0,
       4,     0,     6,     0,     4,     0,     4,     0,     4,     3,
       1,     1,     2,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     1,     2,     0,     4,     0,     2,     1,     1,
       4,     4,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     1,     1,     1,     2,     4,
       3,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     2,     1,     2,     2,
       1,     3,     2,     1,     2,     2,     1,     2,     4,     1,
       0,     1,     2,     4,     1,     0,     1,     2,     3,     2,
       1,     1,     2,     2,     1,     3,     2,     1,     2,     2,
       1,     3,     2,     1,     3,     0,     4,     0,     2,     2,
       1,     3,     2,     1,     6,     2,     1,     2,     0,     3,
       1,     1,     4,     1,     1,     1,     3,     0,     2,     5,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     1,     0,     2,     1,     1,     3,     1,     3,     3,
       1,     3,     0,     5,     0,     2,     3,     1,     3,     3,
       1,     2,     3,     1,     2,     3,     1,     3,     3,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   804,     0,     1,   806,    28,     0,     0,
      12,    30,    38,     0,     0,   808,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   805,   811,   809,   813,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   812,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   438,    37,   440,
     807,     0,   782,     0,     0,   815,   816,   780,   781,   814,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   439,   862,   854,   856,   860,   864,   866,   912,   928,
     874,   858,   881,   868,   870,   872,   900,   877,   879,   920,
     916,   924,   844,   848,   852,   890,   883,   885,   887,     0,
     838,   839,   819,   820,   822,   823,   824,   825,   827,   828,
     829,   831,   830,   832,   834,     0,   835,   833,   841,   842,
     843,   817,   893,   818,   821,   840,   836,   837,   826,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,  1028,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   449,   452,   437,   447,   448,   774,     0,   790,     0,
     786,     0,     0,     0,   441,   444,   443,   445,   772,   773,
     442,   784,   785,   446,   788,   789,     0,     0,     0,     0,
       0,     0,   914,   930,     0,     0,     0,     0,     0,     0,
     906,     0,   922,   918,   926,     0,     0,     0,     0,     0,
       0,   810,     0,     0,   783,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1030,     0,     0,     0,     0,   253,     0,   230,
     233,   225,   228,   229,     0,     0,    65,     0,    57,    61,
      63,    62,    64,    75,     0,    67,    71,    73,    72,    74,
      85,    88,    77,    81,    83,    82,    84,   110,     0,   100,
       0,   104,   107,   106,   105,   108,   123,     0,   112,     0,
       0,     0,   116,   121,   120,   122,   118,   117,   119,   137,
       0,   125,     0,     0,   129,   134,   133,   135,   136,   131,
     130,   132,   148,     0,   139,     0,   143,   147,   145,   144,
     146,     0,   150,   154,   156,   155,   157,     0,   169,   173,
     175,   174,   176,   454,     0,   469,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   846,     0,   845,   850,     0,   849,     0,   962,   967,
     972,   977,   980,   989,   994,  1000,  1004,  1007,  1010,  1013,
    1015,  1020,  1023,  1026,   952,   983,   986,     0,   932,   953,
     933,     0,   934,     0,   935,     0,   936,     0,   937,     0,
     950,     0,   938,     0,   939,   990,   940,   995,   941,     0,
     942,     0,   943,     0,   944,     0,   945,     0,   946,   947,
       0,   948,     0,   949,     0,     0,     0,   878,   876,   891,
       0,   794,     0,     0,   895,   896,   792,   793,   889,   894,
     897,   758,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,  1031,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   450,   451,     0,   455,   775,
     791,   787,     0,     0,     0,     0,     0,     0,   865,   867,
     913,   915,   929,   931,   875,   859,     0,   869,   871,   873,
     902,     0,     0,     0,   901,   907,   908,   909,   880,   921,
     923,   917,   919,   925,   927,   847,   851,     0,  1017,   884,
       0,     0,     0,     0,     0,     0,     0,     0,   976,     0,
     979,     0,   982,     0,   985,     0,     0,   991,     0,   996,
    1001,     0,   999,     0,  1003,     0,  1006,     0,  1009,     0,
    1012,     0,  1019,     0,  1022,     0,  1025,   886,   888,   892,
       0,   898,     0,     0,     0,   357,   390,   390,     0,  1035,
    1037,  1029,  1033,  1034,     0,     0,   368,   232,   236,   231,
     234,   238,     0,   208,    99,    86,    91,    89,    93,     0,
       0,     0,     0,     0,     0,   375,   168,   158,     0,     0,
     161,   187,   177,     0,   180,   709,   483,   660,   515,   532,
     634,   617,   569,   593,   687,   704,   470,   471,   485,   474,
     517,   477,   534,   478,   571,   479,   595,   475,   619,   476,
     636,   472,   662,   473,   689,   480,   705,   481,     0,   468,
       0,   453,   770,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,   458,   461,   462,   463,   464,   459,   460,
     466,   465,   768,   769,   745,   747,   863,   855,   857,   861,
       0,   903,   904,     0,   390,   853,     0,   957,     0,     0,
       0,     0,   955,   954,   951,   956,     0,   963,     0,   961,
       0,   968,     0,   966,     0,   973,     0,   971,   978,     0,
     984,   987,     0,     0,     0,  1002,     0,  1008,     0,     0,
    1083,  1077,  1080,  1058,  1070,  1089,     0,  1086,  1067,  1046,
       0,  1047,  1048,  1062,  1049,     0,  1050,     0,  1051,  1052,
       0,  1053,     0,  1054,     0,  1055,     0,  1056,     0,     0,
    1027,   795,     0,   288,     0,   295,   298,   292,     0,     0,
       0,     0,   369,   258,   262,   257,   260,   264,     0,   237,
     222,     0,   206,     0,     0,     0,     0,     0,     0,   802,
       0,     0,   210,   215,   217,   213,   214,   216,   218,   212,
     211,   221,   219,   220,   800,   801,     0,    92,   109,   370,
     371,   372,   373,   374,     0,   164,   398,   159,   162,   163,
     183,   398,   178,   181,   182,     0,   484,     0,   516,     0,
     533,     0,   570,     0,   594,     0,   618,     0,   635,     0,
     661,     0,   688,     0,   706,     0,     0,   710,   467,   390,
       0,     0,     0,     0,     0,     0,     0,   390,   882,     0,
       0,     0,  1016,  1018,   958,     0,     0,     0,     0,   964,
       0,   969,     0,   974,   981,   998,     0,   988,     0,   993,
    1005,  1011,  1014,  1072,  1021,     0,  1061,     0,     0,     0,
       0,     0,     0,     0,     0,   899,   294,   300,     0,   317,
     363,   364,  1032,  1036,  1040,  1038,  1042,     0,   263,   248,
       0,   235,     0,     0,     0,   239,   245,   242,   243,   244,
     241,   240,   247,   246,   223,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,    90,    94,    96,    95,     0,
       0,     0,   166,   396,   397,     0,   185,     0,   778,     0,
       0,   486,   487,   488,   776,   777,     0,   518,   519,   520,
       0,   535,   536,   537,     0,   572,   573,   574,     0,   596,
     597,   598,     0,   620,   621,   622,     0,   637,   638,   639,
       0,   663,   664,   665,     0,   690,   691,   692,     0,     0,
       0,   708,   771,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   905,   911,   910,     0,     0,   960,   965,   970,
     975,   992,   997,  1074,  1059,     0,  1057,     0,     0,  1065,
    1064,  1063,     0,  1066,     0,  1069,     0,  1076,     0,  1079,
       0,  1082,     0,  1085,     0,  1088,     0,     0,   296,   319,
     336,     0,  1041,   275,     0,   261,     0,   265,   270,   272,
     268,   269,   271,   273,   267,   266,   274,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   803,     0,    98,
     746,     0,     0,   167,   165,   401,   399,   403,   186,   184,
     493,   482,   490,     0,     0,     0,   499,   514,   499,   531,
     499,   568,   499,   592,   499,   616,   499,   633,   499,   659,
     499,   686,     0,     0,   714,     0,     0,   389,   751,   761,
     762,   752,   753,   754,   755,   767,   376,   959,     0,  1060,
     390,   390,     0,     0,     0,  1081,  1084,     0,  1090,     0,
     308,   312,     0,     0,   301,   302,   303,   299,   306,     0,
     338,   297,     0,  1044,  1045,  1043,   276,     0,     0,     0,
       0,   377,   384,   378,   385,   380,   381,   760,     0,   412,
       0,   408,   409,   410,     0,   402,   501,     0,     0,     0,
     496,   398,   492,   494,   495,   779,     0,   523,     0,   540,
       0,   577,     0,   601,     0,   625,     0,   642,     0,   668,
       0,   695,     0,   707,   703,   744,   722,   729,     0,     0,
     715,  1073,  1075,     0,     0,  1068,  1071,  1078,  1087,  1024,
     309,   312,   310,     0,     0,     0,   327,   331,     0,     0,
     320,   321,   322,   318,   325,     0,     0,     0,   382,   386,
     379,     0,     0,   411,     0,   400,     0,   404,   406,   405,
     489,   508,   491,     0,   504,   398,   500,   502,   503,   498,
       0,   748,   525,   522,     0,   521,   542,   539,     0,   538,
     579,   576,     0,   575,   603,   600,     0,   599,   627,   624,
       0,   623,   644,   641,     0,   640,   670,   667,     0,   666,
     697,   694,     0,   693,     0,     0,   723,   718,   398,   713,
     716,   717,   766,   765,   307,   311,     0,     0,     0,   328,
     331,   329,     0,     0,     0,   345,   349,     0,     0,   339,
     340,   337,   343,   341,  1039,   383,   750,   413,     0,     0,
     511,   416,   507,   509,   510,   506,     0,   497,   528,   398,
     524,   526,   527,   545,   548,   541,   543,   544,   582,   584,
     578,   580,   581,   606,   608,   602,   604,   605,   630,   398,
     626,   628,   629,   647,   649,   643,   645,   646,   673,   675,
     669,   671,   672,   700,   430,   696,   698,   699,   712,   732,
     711,   730,   734,   726,   398,   721,   724,   725,   720,     0,
       0,     0,   305,   304,   326,   330,     0,     0,     0,   346,
     349,   347,     0,     0,     0,   407,     0,     0,   513,   414,
     415,     0,   505,   530,     0,     0,   547,     0,     0,   632,
       0,     0,     0,   702,   429,     0,     0,   733,   728,     0,
     719,     0,   315,     0,   313,     0,     0,   324,   323,   344,
     348,     0,     0,     0,   759,     0,   419,   417,   420,   512,
     529,   546,   551,   549,   553,   587,   583,   585,     0,   611,
     607,   609,     0,   631,   652,   648,   650,   653,   678,   674,
     676,   679,   433,   431,   434,   701,   742,   452,   731,   740,
     741,     0,     0,   735,   736,   737,   738,   739,   727,     0,
     316,     0,   334,     0,   332,     0,     0,   362,   342,   427,
       0,   423,   424,   425,     0,   421,     0,   552,   590,     0,
     586,   588,   589,   614,     0,   610,   612,   613,     0,     0,
       0,   435,     0,     0,     0,   314,     0,   335,     0,   352,
       0,   350,     0,   426,   390,   418,   559,   561,   550,   557,
     558,     0,     0,   554,   555,   556,     0,     0,     0,   798,
       0,   654,   651,   657,   656,   655,   796,   797,   685,     0,
     680,   677,   683,   682,   681,     0,   432,   743,     0,     0,
     333,     0,   353,   428,     0,     0,     0,   390,   591,   615,
       0,     0,   684,     0,   756,   757,   351,   422,   560,   564,
     562,   565,     0,     0,   658,   799,   436,     0,     0,   566,
     749,   764,   390,     0,   563,     0,     0,   763,   567
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   697,   698,   896,   897,  1026,  1025,   695,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   709,   907,   908,   909,  1031,  1164,   707,
     158,   159,   259,   260,   419,   418,   583,   584,   713,   912,
     913,   914,  1035,  1169,   712,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     692,   693,   882,   872,   125,   126,   235,   341,   342,   343,
     689,   557,   690,   691,   868,   869,  1005,  1001,   232,   233,
     336,   553,   554,   555,   865,   685,   866,   867,   997,   998,
    1137,  1135,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   674,   857,   988,   989,  1127,  1224,  1225,
    1226,  1227,  1228,  1301,  1302,  1303,  1471,  1514,  1130,  1229,
    1310,  1311,  1312,  1313,  1314,  1390,  1391,  1392,  1516,  1574,
    1231,  1315,  1399,  1400,  1401,  1402,  1480,  1481,  1482,  1576,
    1611,   122,   123,   542,   331,   543,  1403,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     792,   883,   884,  1006,   885,   886,  1008,  1141,   887,   888,
    1009,   224,  1082,   225,   326,  1032,  1033,  1166,  1167,  1254,
    1255,  1327,  1325,  1034,  1251,  1252,  1253,  1488,  1489,  1527,
    1528,  1584,  1615,  1490,  1581,  1582,  1583,  1503,  1504,  1553,
    1554,  1600,  1646,    98,    99,   160,   161,   274,   263,   264,
     265,   424,   425,   426,   587,   588,   762,   751,   586,   726,
     727,   728,   915,   916,  1041,  1171,  1257,  1172,  1173,  1262,
    1263,  1264,  1340,  1258,  1259,  1336,  1337,  1338,  1416,  1332,
    1333,  1412,  1413,  1414,  1491,   729,   730,   917,   918,  1047,
    1177,  1268,  1343,  1344,  1420,  1421,  1422,  1494,   731,   732,
     919,   920,  1051,  1179,  1270,  1347,  1348,  1425,  1426,  1427,
    1495,  1496,  1533,  1534,  1586,  1587,  1623,  1618,  1619,  1620,
    1655,  1670,  1671,  1678,  1684,   733,   734,   921,   922,  1055,
    1181,  1272,  1351,  1352,  1430,  1431,  1432,  1497,  1537,  1538,
    1590,  1591,  1592,   735,   736,   923,   924,  1059,  1183,  1274,
    1355,  1356,  1435,  1436,  1437,  1498,  1541,  1542,  1595,  1596,
    1597,   737,   738,   925,   926,  1063,  1185,  1276,  1359,  1360,
    1440,  1441,  1442,  1500,   739,   740,   927,   928,  1067,  1187,
    1278,  1363,  1364,  1445,  1446,  1447,  1501,  1546,  1547,  1598,
    1631,  1632,   741,   742,   929,   930,  1071,  1189,  1280,  1367,
    1368,  1450,  1451,  1452,  1502,  1550,  1551,  1599,  1640,  1641,
     743,   744,   931,   932,  1075,  1191,  1282,  1371,  1372,  1455,
    1456,  1457,  1505,   745,   746,   933,  1284,   747,   748,   936,
    1081,  1460,  1195,  1196,  1289,  1379,  1380,  1381,  1469,  1287,
    1288,  1375,  1465,  1466,  1467,  1509,  1374,  1461,  1462,  1506,
    1507,  1563,  1558,  1559,  1560,   937,   275,   710,   276,  1042,
    1624,  1162,   763,   764,   765,   766,   767,  1564,  1565,   105,
    1328,   891,   768,   769,  1679,  1625,  1109,  1110,   770,   771,
     772,   773,   277,   278,   279,  1043,  1044,  1045,   106,   107,
     108,   280,   281,   282,   283,   284,   285,   525,   526,   527,
    1635,  1636,  1637,   893,   894,   895,     7,     8,    15,    25,
      46,    47,    67,    68,   109,   829,   190,   305,   453,   191,
     306,   456,   192,   307,   193,   287,   194,   288,   195,   295,
     196,   289,   197,   286,   198,   290,   199,   291,   200,   297,
     201,   298,   202,   299,   203,   294,   204,   205,   518,   206,
     301,   207,   296,   208,   308,   209,   309,   210,   310,   211,
     212,   528,   313,   529,   530,   852,   213,   300,   614,   949,
     446,   615,   616,   617,   214,   292,   438,   215,   303,   449,
     216,   302,   448,   217,   304,   450,   218,   293,   439,   477,
     478,   479,   630,   793,   794,   795,   480,   481,   799,   632,
     482,   483,   803,   634,   484,   485,   807,   636,   486,   487,
     638,   488,   489,   640,   490,   491,   642,   492,   493,   644,
     494,   495,   646,   967,   496,   497,   648,   969,   647,   498,
     499,   652,   500,   501,   654,   502,   503,   656,   504,   505,
     658,   506,   507,   660,   508,   628,   786,   509,   510,   662,
     511,   512,   664,   513,   514,   666,   333,   334,   548,   549,
     681,   682,   683,   861,   995,   996,  1131,  1132,  1235,   830,
     831,   832,   833,  1106,   975,   976,  1111,   834,   835,  1113,
     836,   837,  1115,   838,  1103,  1208,   839,   840,  1117,   841,
     842,  1119,   843,   844,  1121,   845,   846,  1123,   847,   848,
    1125
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -914
static const yytype_int16 yypact[] =
{
      -2,  -914,    79,  -250,    47,  -914,  -914,   -90,  -222,   109,
    -914,  -914,    74,   -40,   130,  -914,   158,    50,  -914,   -92,
     152,   164,   122,  -914,   168,  -212,   176,  -914,  -914,  -914,
    -914,  -914,   128,   143,   191,   150,  -914,   215,  -914,  -914,
    -914,  -914,  -914,   220,  -914,  -914,  -914,  -914,   222,    42,
    -914,   182,   219,  -914,    -9,  -914,  -914,  -914,   239,  -914,
    -914,  -914,  -914,  -914,   241,    31,   240,   249,   -56,  -914,
    -914,   218,   261,   265,   269,   281,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,   256,  -914,   193,  -914,  -914,  -914,
    -914,    54,   138,   296,   332,  -914,  -914,  -914,  -914,  -914,
    -914,   799,  -914,   309,   318,  -914,  -914,  -914,  -914,  -914,
    -914,   336,   340,   346,  -914,  -914,  -914,  -914,  -914,  -914,
     246,   313,   280,   277,  -914,   104,   183,   358,   264,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
     268,   316,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,    71,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,   799,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   369,
     376,   378,   380,   384,   391,    39,  -914,   393,  -914,  -914,
    -914,  -914,    89,   225,   401,   317,  -914,   427,  -914,  -914,
    -914,  -914,  -914,   324,   -36,   328,   -36,   333,   -36,   339,
       8,   359,   123,   364,    80,   430,    15,   423,   -36,   425,
     -36,  -914,   230,  -914,  -914,  -914,  -914,   451,  -914,   465,
    -914,   467,   474,   478,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   799,   799,   799,   799,
     799,   799,  -914,  -914,   799,   799,   799,   799,   799,   799,
    -914,   799,  -914,  -914,  -914,   432,   434,   799,    18,    18,
      18,  -914,   135,    36,  -914,   495,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,   503,   447,  -914,
     449,    91,  -914,   301,   259,   588,   448,  -914,   591,  -914,
    -914,  -914,  -914,  -914,   590,   210,  -914,   550,  -914,  -914,
    -914,  -914,  -914,  -914,   551,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   546,  -914,
     593,  -914,  -914,  -914,  -914,  -914,  -914,   548,  -914,   596,
     597,   599,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
     539,  -914,   600,   601,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,   553,  -914,   607,  -914,  -914,  -914,  -914,
    -914,   538,  -914,  -914,  -914,  -914,  -914,   542,  -914,  -914,
    -914,  -914,  -914,  -914,   405,  -914,  -914,   605,   606,   608,
     612,   613,   799,   799,   799,   799,   289,   288,   563,   602,
     283,   282,   799,   279,   278,   284,    44,   271,   627,   664,
     725,  -914,   267,  -914,  -914,   262,  -914,   799,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,   260,  -914,  -914,
    -914,   437,  -914,   438,  -914,   439,  -914,    18,  -914,    18,
    -914,   799,  -914,    18,  -914,   205,  -914,   205,  -914,   452,
    -914,    18,  -914,    18,  -914,    18,  -914,    18,  -914,  -914,
      18,  -914,   799,  -914,    18,   266,   263,  -914,  -914,  -914,
     274,  -914,   637,   641,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -289,  -289,   638,  -914,  -914,   514,  -914,   561,
     640,   642,  -914,  -914,  -914,  -914,  -914,   644,   454,  -914,
     643,  -914,  -914,  -914,  -914,  -914,   645,   223,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   603,   584,  -914,   648,
    -914,  -914,   650,   652,  -914,   653,   654,  -914,   655,  -914,
     604,   544,  -914,   595,   544,  -914,   133,   469,    98,  -914,
    -914,  -914,   656,   657,   343,   344,   349,   341,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   799,  -914,  -914,  -914,
    -914,   768,   663,   666,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,   305,  -914,  -914,
      40,   670,   496,   674,   500,   676,   502,   311,  -914,    18,
    -914,   285,  -914,   287,  -914,   683,   680,  -914,   684,  -914,
    -914,   315,  -914,    18,  -914,   319,  -914,    18,  -914,    18,
    -914,   470,  -914,   799,  -914,   297,  -914,  -914,  -914,  -914,
     694,  -914,   692,   707,   504,  -914,  -914,  -914,   706,  -914,
    -914,  -914,  -914,  -914,   708,   258,  -914,  -914,  -914,  -914,
    -914,  -914,   508,   100,  -914,  -914,  -914,  -914,  -914,   710,
     712,   714,   716,   719,   720,  -914,  -914,  -914,   721,   510,
    -914,  -914,  -914,   512,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   387,  -914,   564,  -914,
     506,  -914,  -914,   728,   724,   726,   727,   729,   730,   731,
     732,   733,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
     390,  -914,  -914,   736,  -914,  -914,   -79,  -914,   342,   735,
     738,   741,  -914,  -914,  -914,  -914,   743,  -914,   483,  -914,
     746,  -914,   490,  -914,   747,  -914,   493,  -914,  -914,   377,
    -914,  -914,   752,    18,    18,  -914,   368,  -914,   371,   373,
    -914,  -914,  -914,  -914,  -914,  -914,   756,  -914,  -914,  -914,
     367,  -914,  -914,  -914,  -914,   758,  -914,   762,  -914,  -914,
     764,  -914,   765,  -914,   766,  -914,   767,  -914,   769,   799,
    -914,  -914,   774,  -914,   775,  -914,   513,  -914,   776,   778,
     779,  -195,  -914,  -914,  -914,  -914,  -914,  -914,   521,    59,
    -914,   535,  -914,   781,   782,   783,   787,   789,   791,  -914,
     798,   795,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   523,   -77,  -914,  -914,
    -914,  -914,  -914,  -914,   801,  -914,   688,  -914,  -914,  -914,
    -914,   688,  -914,  -914,  -914,   793,   -57,   803,   -57,   805,
     -57,   807,   -57,   809,   -57,   811,   -57,   813,   -57,   815,
     -57,   817,   -57,   819,  -914,   825,   823,  -914,  -914,  -914,
     831,   833,   837,   839,   840,   841,   842,  -914,  -914,   460,
     843,   844,  -914,  -914,  -914,   847,   848,   849,   850,  -914,
     851,  -914,   852,  -914,  -914,  -914,   468,  -914,   472,  -914,
    -914,  -914,  -914,  -914,  -914,   525,   345,   799,   470,   470,
     470,   470,   470,   470,   799,  -914,  -914,  -914,   780,   586,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,   529,   125,  -914,
     609,  -914,   853,   855,   856,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,   859,   861,   862,   863,   864,
     865,   866,   867,  -914,   784,  -914,  -914,  -914,  -914,   869,
     671,   739,  -914,   797,  -914,   820,  -914,   662,  -914,   872,
     871,  -914,  -914,  -914,  -914,  -914,   662,  -914,  -914,  -914,
     662,  -914,  -914,  -914,   662,  -914,  -914,  -914,   662,  -914,
    -914,  -914,   662,  -914,  -914,  -914,   662,  -914,  -914,  -914,
     662,  -914,  -914,  -914,   662,  -914,  -914,  -914,    18,   875,
     690,  -914,  -914,    23,   894,   898,   900,   904,   906,   908,
     910,   912,  -914,  -914,  -914,   914,   933,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,   528,  -914,   937,   970,  -914,
    -914,  -914,   799,  -914,   470,  -914,   470,  -914,   567,  -914,
     573,  -914,   470,  -914,   594,  -914,    18,    62,  -914,  -914,
     737,   991,   -56,  -914,   748,  -914,   999,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  1009,  1011,
    1013,  1017,  1019,  1021,  1023,  1025,  1027,  -914,  1029,  -914,
    -914,  1031,   531,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -103,   533,  1032,  1015,   802,  -914,   802,  -914,
     802,  -914,   802,  -914,   802,  -914,   802,  -914,   802,  -914,
     802,  -914,   794,  1035,  -914,   828,   544,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   351,  -914,
    -914,  -914,   621,   631,   639,  -914,  -914,   629,  -914,   659,
    -914,   830,  1046,  1048,  -914,  -914,  -914,  -914,  -914,    64,
    -914,  -914,    18,  -914,  -914,  -914,  -914,  1054,  1056,  1058,
    1060,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  1064,  -914,
      95,  -914,  -914,  -914,  1050,   347,  -914,   857,   832,   537,
    -914,   688,  -914,  -914,  -914,  -914,  1068,   838,   876,   873,
     845,   902,   874,   916,   870,   918,   878,   920,   882,   922,
     923,   924,   880,  -914,  -914,  -914,  -914,  -914,   544,   541,
    -914,  -914,  -914,  1074,  1076,  -914,  -914,  -914,  -914,  -914,
    -914,   877,  -914,   884,  1142,  1146,  -914,   891,  1160,  1162,
    -914,  -914,  -914,  -914,  -914,    69,   854,  1166,  -914,  -914,
    -914,  1167,  1055,  -914,  1170,  -914,  1171,  -914,  -914,  -914,
    -914,  -914,  -914,   543,  -914,   688,  -914,  -914,  -914,  -914,
     939,  -914,  -914,  -914,   545,  -914,  -914,  -914,   547,  -914,
    -914,  -914,   549,  -914,  -914,  -914,   552,  -914,  -914,  -914,
     554,  -914,  -914,  -914,   556,  -914,  -914,  -914,   558,  -914,
    -914,  -914,   560,  -914,   362,   566,  -914,  -914,   688,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,   982,  1173,  1174,  -914,
     919,  -914,   921,  1179,  1180,  -914,   925,  1181,  1182,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  1073,  1185,
    -914,  1067,  -914,  -914,  -914,  -914,   951,  -914,  -914,   688,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   688,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,   688,  -914,  -914,  -914,  -914,   978,
    1188,   568,  -914,  -914,  -914,  -914,  1000,  1189,  1191,  -914,
     931,  -914,   935,  1196,  1197,  -914,  1198,   671,  -914,  1091,
    -914,   962,  -914,  -914,   964,   965,  1096,   -80,   -78,  -914,
     967,   -74,   -63,  -914,  1098,   969,   570,   -25,  -914,   996,
    -914,  1208,  -914,   944,  -914,  1209,   572,  -914,  -914,  -914,
    -914,  1018,  1210,  1211,  -914,   575,  -914,  -914,  1020,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   577,  -914,
    -914,  -914,   579,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  1020,  -914,  -914,   230,  -914,  -914,
    -914,  1213,  1214,  -914,  -914,  -914,  -914,  -914,  -914,  1215,
    -914,  1218,  -914,   963,  -914,  1217,   581,  -914,  -914,  -914,
      97,  -914,  -914,  -914,  1216,  -914,   583,  -115,  -914,   799,
    -914,  -914,  -914,  -914,     7,  -914,  -914,  -914,    66,    60,
    1219,  -914,  1014,  1223,  1224,  -914,  1225,  -914,  1226,  -914,
     968,  -914,  1112,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  1228,  1229,  -914,  -914,  -914,  1124,  1125,  1234,  -914,
    1238,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  1128,
    -914,  -914,  -914,  -914,  -914,  1239,  -914,  -914,  1236,  1237,
    -914,  1240,  -914,  -914,  1132,   -37,  1241,  -914,  -914,  -914,
    1135,  1242,  -914,  1137,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  1051,  1244,  1246,  -914,  -914,  -914,  1247,  1245,  -914,
    -914,  -914,  -914,  1250,  -914,  1251,  1016,  -914,  -914
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,   930,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,   -41,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -128,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -217,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  1010,  1012,  -914,  -914,  -914,  -914,
    -914,   270,   272,  -914,  -784,  -914,  -914,  -914,   273,   275,
    -914,  -569,  -914,  -277,  -914,  -888,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -292,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -752,  -914,  -914,
    -914,  -914,  -914,  -750,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -241,  -562,  -240,  -433,
    -914,  -220,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   137,
    -326,  -848,  -914,  -914,  -914,  -914,  -325,  -324,  -914,  -914,
    -914,  -914,  -218,  -914,  -914,  -426,  -914,  -914,  -719,  -914,
    -914,  -231,  -914,  -914,  -312,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -101,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -285,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,   785,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -913,
    -317,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,  -914,
    -914
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -500
static const yytype_int16 yytable[] =
{
     189,   524,   700,   350,   351,   357,   358,   364,   365,   373,
     374,   386,   387,   399,   400,   408,   409,   414,   415,   420,
     421,  1012,   714,  1036,   515,   516,   352,   934,   359,   405,
     366,  1197,   375,  1535,   388,  1539,   401,   370,   410,  1544,
     416,     1,   422,   532,   533,   320,   321,   519,   520,  1027,
    1548,   787,   788,    70,    71,   610,   611,   268,   269,     6,
      72,    73,     9,   789,  1621,  1114,  1116,  1118,  1120,  1122,
    1124,  1638,  1639,  1220,  1221,  1306,  1307,  1668,  1628,     5,
    1395,  1396,   102,   103,  1222,  1007,  1308,   877,  1622,    14,
    1002,  1397,  1003,  1004,    27,    28,   266,   267,    44,  1322,
      45,  1612,   538,   539,   312,  1038,  1039,   858,   859,   268,
     269,   540,   541,  1040,    11,   379,   380,    16,   392,   393,
     993,    18,   994,   881,   873,   874,   875,   876,   877,    21,
     878,   272,   273,    38,    39,   270,   271,  1256,    24,  -499,
     266,   267,   104,   322,   323,   324,   325,   266,   267,   873,
     874,   875,   876,   877,    53,    54,    31,  1136,   379,   380,
     381,    59,    60,  1536,    26,  1540,  1561,  1562,    34,  1545,
     268,   269,    37,   458,    43,   272,   273,   459,   521,   522,
    1549,   460,   272,   273,    48,   432,   433,   434,   435,   436,
     437,   266,   267,   440,   441,   442,   443,   444,   445,    58,
     447,  1213,   637,  1214,   639,    50,   457,  1669,   643,  1217,
    1629,  1630,   266,   267,  1140,   951,   653,  1323,   655,  1613,
     657,    64,   659,    82,    83,   661,   272,   273,    66,   665,
      85,    86,   266,   267,    69,  1309,    96,    97,   790,  1223,
      74,    90,   612,  1398,    75,    93,   613,   272,   273,    95,
     879,   880,   100,  1107,  1108,   266,   267,   266,   267,   881,
     881,   101,   752,   753,   110,  1326,   881,   272,   273,   111,
     458,   118,   119,   112,   459,   238,   239,   113,   460,   261,
     262,   754,   755,   756,   757,   758,   759,   760,   761,   114,
     272,   273,   272,   273,  1176,  1292,   115,   461,  1178,   462,
     881,   463,  1180,   464,   130,   465,  1182,   466,   124,   467,
    1184,   468,   219,   469,  1186,   470,   952,   471,  1188,   472,
     127,   473,  1190,   474,   226,   475,   220,   476,   339,   340,
     227,   594,   595,   596,   597,   346,   347,   601,   603,   353,
     354,   606,   221,   715,   360,   361,   222,   620,   622,   624,
     367,   368,   223,   716,   809,   717,   627,   718,   229,   719,
     230,   720,   231,   721,   234,   722,   237,   723,   816,   724,
     376,   377,   818,  1339,   819,   389,   390,   314,  1091,   725,
     131,   132,   315,   133,   311,   134,   316,   135,   317,   136,
     641,   137,   318,   138,   461,   139,   462,   140,   463,   319,
     464,   327,   465,   332,   466,   335,   467,  1329,   468,   338,
     469,   663,   470,  1234,   471,   820,   472,   821,   473,   822,
     474,   823,   475,   824,   476,   825,  1267,   826,  1269,   827,
    1271,   828,  1273,   344,  1275,   411,  1277,   417,  1279,   423,
    1281,   402,   403,   451,   452,   454,   455,  1415,   266,   267,
     268,   269,   889,   890,   427,   322,   323,   324,   325,   551,
     552,   559,   560,   650,   651,   679,   680,   523,   428,   791,
     429,   322,   323,   324,   325,   892,   270,   271,   687,   688,
     749,   750,   430,   272,   273,  1048,   431,  1052,   517,  1056,
    1468,  1060,  1049,  1064,  1053,  1068,  1057,  1072,  1061,  1076,
    1065,   953,  1069,   531,  1073,   780,  1077,   797,   798,   534,
     782,   801,   802,   805,   806,   855,   856,   863,   864,   870,
     871,   905,   906,   910,   911,   102,   103,   535,   966,   968,
     537,  1493,   999,  1000,  1023,  1024,  1104,  1105,  1107,  1108,
    1133,  1134,  1249,  1250,  1260,  1261,  1326,   881,  1334,  1335,
     546,  1499,  1377,  1378,  1410,  1411,  1418,  1419,  1423,  1424,
    1428,  1429,   849,  1433,  1434,  1438,  1439,  1443,  1444,  1448,
    1449,  1453,  1454,  1458,  1459,   547,  1508,  1463,  1464,  1512,
    1513,  1556,  1557,  1572,  1573,  1028,  1579,  1580,  1588,  1589,
    1593,  1594,  1609,  1610,  1616,  1617,   550,   556,   558,   574,
     564,   569,   568,   565,   571,   572,   570,   573,   575,   576,
     578,   579,   585,   589,   590,   577,   591,   582,   592,   593,
     598,   599,   604,   605,   607,   608,   618,   626,  1010,  1011,
     625,   629,   645,   609,  1290,   631,   633,   635,   668,   667,
     670,  1293,  1294,   669,   671,   675,   672,   673,   676,   684,
     677,  1013,   678,   686,   699,   696,   701,   694,   702,   703,
     704,   711,  1083,   705,   774,   775,   776,   708,   706,   777,
     779,   783,   785,   162,   784,   163,   778,   164,   796,   165,
    1585,   166,   800,   167,   804,   168,   812,   169,   808,   170,
     810,   171,   813,   172,   811,   173,   814,   174,   850,   175,
     815,   176,   851,   177,   853,   178,  1601,   179,   817,   180,
     854,   181,   860,   182,   938,   183,   862,   184,   898,   185,
     899,   186,   900,   187,   901,   188,  1376,   902,   903,   904,
     935,   939,   940,   948,   941,   942,   959,   943,   944,   945,
     946,   947,   950,   955,   957,   954,   956,   961,   984,   958,
    1634,  1642,   960,   962,   963,   970,   964,  1144,  1145,   820,
     965,   821,   971,   822,   974,   823,   972,   824,   973,   825,
     977,   826,  1291,   827,   978,   828,   979,   980,   981,   982,
    1146,   983,   985,   986,   990,   987,   991,   992,  1014,  1015,
    1016,  1017,   162,  1192,   163,  1018,   164,  1019,   165,  1020,
     166,  1021,   167,  1022,   168,  1037,   169,  1029,   170,  1030,
     171,  1092,   172,  1163,   173,  1046,   174,  1050,   175,  1054,
     176,  1058,   177,  1062,   178,  1066,   179,  1070,   180,  1074,
     181,  1078,   182,  1079,   183,  1080,   184,  1084,   185,  1085,
     186,  1219,   187,  1086,   188,  1087,  1088,  1089,  1090,  1101,
    1129,  1093,  1094,  1095,  1096,  1102,  1159,  1097,  1098,  1099,
    1100,  1148,  1128,  1149,  1150,  1151,  1147,  1152,  1153,  1154,
    1155,  1156,  1161,  1158,  1157,  1174,  1112,  1160,   820,  1175,
     821,  1193,   822,  1126,   823,   162,   824,   163,   825,   164,
     826,   165,   827,   166,   828,   167,  1168,   168,   600,   169,
    1170,   170,  1198,   171,  1194,   172,  1199,   173,  1200,   174,
    1165,   175,  1201,   176,  1202,   177,  1203,   178,  1204,   179,
    1205,   180,  1206,   181,   162,   182,   163,   183,   164,   184,
     165,   185,   166,   186,   167,   187,   168,   188,   169,   602,
     170,  1207,   171,  1209,   172,  1210,   173,  1316,   174,   162,
     175,   163,   176,   164,   177,   165,   178,   166,   179,   167,
     180,   168,   181,   169,   182,   170,   183,   171,   184,   172,
     185,   173,   186,   174,   187,   175,   188,   176,  1211,   177,
    1215,   178,  1216,   179,   619,   180,   162,   181,   163,   182,
     164,   183,   165,   184,   166,   185,   167,   186,   168,   187,
     169,   188,   170,  1232,   171,  1230,   172,  1237,   173,  1236,
     174,  1212,   175,  1218,   176,  1238,   177,  1239,   178,  1240,
     179,  1266,   180,   621,   181,  1241,   182,  1242,   183,  1243,
     184,  1244,   185,  1245,   186,  1246,   187,  1247,   188,  1248,
    1265,  1283,  1256,  1285,  1286,  1654,  1295,   162,  1296,   163,
    1297,   164,  1298,   165,  1304,   166,  1305,   167,  1299,   168,
    1317,   169,  1324,   170,  1318,   171,  1319,   172,  1320,   173,
    1321,   174,  1349,   175,  1331,   176,  1341,   177,  1330,   178,
    1342,   179,  1382,   180,  1383,   181,   623,   182,  1673,   183,
     162,   184,   163,   185,   164,   186,   165,   187,   166,   188,
     167,  1345,   168,  1300,   169,  1357,   170,  1353,   171,  1361,
     172,  1365,   173,  1685,   174,  1346,   175,  1373,   176,   781,
     177,   162,   178,   163,   179,   164,   180,   165,   181,   166,
     182,   167,   183,   168,   184,   169,   185,   170,   186,   171,
     187,   172,   188,   173,  1350,   174,  1369,   175,  1387,   176,
    1384,   177,  1388,   178,  1386,   179,  1389,   180,  1354,   181,
    1358,   182,  1362,   183,  1366,   184,  1370,   185,  1393,   186,
    1394,   187,  1404,   188,  1405,  1406,  1408,  1407,  1417,  1409,
    1470,  1472,  1473,  1476,  1474,  1477,  1478,  1485,  1487,  1483,
    1484,  1486,  1492,  1510,  1479,  1567,  1511,  1517,  1515,  1518,
    1519,  1521,  1522,  1523,  1526,  1529,  1524,  1530,  1531,  1532,
    1543,  1552,  1555,  1568,  1569,  1570,  1575,  1571,  1577,  1578,
     881,  1603,  1604,  1605,  1606,  1608,  1607,  1647,  1614,  1648,
    1649,  1645,  1651,  1650,  1653,  1652,  1656,  1657,  1658,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1667,  1672,  1666,  1674,
    1675,  1676,  1680,  1677,  1681,  1682,  1686,  1683,   536,  1687,
    1385,  1688,  1475,  1520,   395,  1602,   396,  1525,  1138,  1233,
    1139,  1142,  1633,  1143,  1643,  1644,  1566,  1627,     0,     0,
       0,     0,   649,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1626
};

static const yytype_int16 yycheck[] =
{
     101,   313,   571,   244,   244,   246,   246,   248,   248,   250,
     250,   252,   252,   254,   254,   256,   256,   258,   258,   260,
     260,   869,   584,   911,   309,   310,   244,   746,   246,    14,
     248,     8,   250,   113,   252,   113,   254,    29,   256,   113,
     258,    43,   260,   320,   321,     6,     7,    11,    12,   897,
     113,    11,    12,    11,    12,    11,    12,   134,   135,   309,
      18,    19,    15,    23,   179,   978,   979,   980,   981,   982,
     983,    11,    12,    11,    12,    11,    12,   114,    12,     0,
      11,    12,   138,   139,    22,   869,    22,    28,   203,   311,
      31,    22,    33,    34,    44,    45,   132,   133,   310,     4,
     312,     4,    11,    12,   205,   162,   163,   676,   677,   134,
     135,    20,    21,   170,   204,    35,    36,     8,    38,    39,
     315,    47,   317,   200,    24,    25,    26,    27,    28,   169,
      30,   167,   168,    11,    12,   160,   161,   240,     8,   242,
     132,   133,   198,   432,   433,   434,   435,   132,   133,    24,
      25,    26,    27,    28,    11,    12,   248,    32,    35,    36,
      37,    11,    12,   243,     6,   243,   191,   192,    16,   243,
     134,   135,     8,   252,     6,   167,   168,   256,   142,   143,
     243,   260,   167,   168,     8,   286,   287,   288,   289,   290,
     291,   132,   133,   294,   295,   296,   297,   298,   299,     8,
     301,  1114,   487,  1116,   489,    77,   307,   244,   493,  1122,
     144,   145,   132,   133,   998,   784,   501,   122,   503,   122,
     505,     6,   507,    41,    42,   510,   167,   168,     8,   514,
      11,    12,   132,   133,    12,   171,   205,   206,   198,   177,
     198,   250,   198,   174,   202,     6,   202,   167,   168,     8,
     150,   151,    12,   193,   194,   132,   133,   132,   133,   200,
     200,    12,   164,   165,    46,   199,   200,   167,   168,     8,
     252,    78,    79,     8,   256,    11,    12,     8,   260,    11,
      12,   183,   184,   185,   186,   187,   188,   189,   190,     8,
     167,   168,   167,   168,  1046,  1208,    40,   376,  1050,   378,
     200,   380,  1054,   382,     8,   384,  1058,   386,   254,   388,
    1062,   390,     3,   392,  1066,   394,   395,   396,  1070,   398,
     182,   400,  1074,   402,    78,   404,     8,   406,    11,    12,
      17,   432,   433,   434,   435,    11,    12,   438,   439,    11,
      12,   442,     6,   210,    11,    12,     6,   448,   449,   450,
      11,    12,     6,   220,   639,   222,   457,   224,    78,   226,
      83,   228,   258,   230,   181,   232,     8,   234,   653,   236,
      11,    12,   657,  1261,   659,    11,    12,     8,   947,   246,
      48,    49,     6,    51,   313,    53,     8,    55,     8,    57,
     491,    59,     8,    61,   376,    63,   378,    65,   380,     8,
     382,     8,   384,   314,   386,   180,   388,  1255,   390,     8,
     392,   512,   394,  1132,   396,   408,   398,   410,   400,   412,
     402,   414,   404,   416,   406,   418,  1176,   420,  1178,   422,
    1180,   424,  1182,     6,  1184,    12,  1186,    12,  1188,   209,
    1190,    11,    12,    11,    12,    11,    12,  1335,   132,   133,
     134,   135,   693,   693,     3,   432,   433,   434,   435,    11,
      12,   251,   252,    11,    12,    11,    12,   431,     3,   429,
       3,   432,   433,   434,   435,   693,   160,   161,   255,   256,
      11,    12,     8,   167,   168,   918,     8,   920,   353,   922,
    1378,   924,   918,   926,   920,   928,   922,   930,   924,   932,
     926,   786,   928,     8,   930,   606,   932,    11,    12,     6,
     611,    11,    12,    11,    12,    11,    12,   259,   260,    11,
      12,    11,    12,    11,    12,   138,   139,    80,   813,   814,
      81,  1419,    11,    12,    11,    12,    11,    12,   193,   194,
      11,    12,    11,    12,    11,    12,   199,   200,    11,    12,
     249,  1439,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,   663,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,   211,   212,   316,  1464,    11,    12,    11,
      12,    11,    12,    11,    12,   897,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,     8,     6,     8,    60,
      50,     8,    56,    52,     8,     8,    58,     8,     8,     8,
       3,    73,   207,     8,     8,    62,     8,    75,     6,     6,
     331,   333,   339,   341,   345,   347,   355,   365,   869,   869,
     363,   371,   427,   349,  1196,   198,   198,   198,   375,   373,
       3,  1210,  1211,   369,     3,    84,     8,   133,     8,     6,
       8,   869,     8,     8,     6,    71,     6,    54,     6,     6,
       6,    66,   939,     8,     8,     8,   323,   123,    64,   325,
     329,     8,   367,   322,     8,   324,   327,   326,     8,   328,
    1528,   330,     8,   332,     8,   334,     3,   336,   377,   338,
     405,   340,    12,   342,   407,   344,    12,   346,   401,   348,
     385,   350,     8,   352,    12,   354,  1554,   356,   389,   358,
       3,   360,     6,   362,   208,   364,     8,   366,     8,   368,
       8,   370,     8,   372,     8,   374,  1288,     8,     8,     8,
     166,     3,     8,   343,     8,     8,   253,     8,     8,     8,
       8,     8,     6,     8,     3,   403,     8,   257,   849,     6,
    1598,  1599,     6,     6,   261,   387,   379,   998,   998,   408,
       8,   410,   391,   412,   397,   414,   393,   416,    12,   418,
      12,   420,   421,   422,    12,   424,    12,    12,    12,    12,
     998,    12,     8,     8,     8,   272,     8,     8,   253,     8,
       8,     8,   322,  1078,   324,     8,   326,     8,   328,     8,
     330,     3,   332,     8,   334,    12,   336,     6,   338,   121,
     340,   351,   342,    74,   344,    12,   346,    12,   348,    12,
     350,    12,   352,    12,   354,    12,   356,    12,   358,    12,
     360,    12,   362,     8,   364,    12,   366,     6,   368,     6,
     370,  1126,   372,     6,   374,     6,     6,     6,     6,   381,
     264,     8,     8,     6,     6,   383,    72,     8,     8,     8,
       8,     8,    82,     8,     8,     6,   257,     6,     6,     6,
       6,     6,   201,     6,     8,     3,   977,     8,   408,     8,
     410,     6,   412,   984,   414,   322,   416,   324,   418,   326,
     420,   328,   422,   330,   424,   332,    76,   334,   335,   336,
     238,   338,     8,   340,   214,   342,     8,   344,     8,   346,
     113,   348,     8,   350,     8,   352,     8,   354,     8,   356,
       8,   358,     8,   360,   322,   362,   324,   364,   326,   366,
     328,   368,   330,   370,   332,   372,   334,   374,   336,   337,
     338,     8,   340,   415,   342,     8,   344,  1232,   346,   322,
     348,   324,   350,   326,   352,   328,   354,   330,   356,   332,
     358,   334,   360,   336,   362,   338,   364,   340,   366,   342,
     368,   344,   370,   346,   372,   348,   374,   350,     8,   352,
     413,   354,   409,   356,   357,   358,   322,   360,   324,   362,
     326,   364,   328,   366,   330,   368,   332,   370,   334,   372,
     336,   374,   338,    12,   340,   268,   342,     8,   344,   261,
     346,  1112,   348,   419,   350,     6,   352,     6,   354,     6,
     356,     6,   358,   359,   360,     8,   362,     8,   364,     8,
     366,     8,   368,     8,   370,     8,   372,     8,   374,     8,
       8,   247,   240,     8,   216,  1614,   425,   322,   417,   324,
     411,   326,   423,   328,     8,   330,     8,   332,   399,   334,
       6,   336,    12,   338,     8,   340,     8,   342,     8,   344,
       6,   346,   227,   348,   242,   350,     8,   352,   221,   354,
     242,   356,     8,   358,     8,   360,   361,   362,  1657,   364,
     322,   366,   324,   368,   326,   370,   328,   372,   330,   374,
     332,   225,   334,   273,   336,   235,   338,   233,   340,   231,
     342,   229,   344,  1682,   346,   242,   348,   237,   350,   351,
     352,   322,   354,   324,   356,   326,   358,   328,   360,   330,
     362,   332,   364,   334,   366,   336,   368,   338,   370,   340,
     372,   342,   374,   344,   242,   346,   223,   348,     6,   350,
     273,   352,     6,   354,   270,   356,   265,   358,   242,   360,
     242,   362,   242,   364,   242,   366,   242,   368,     8,   370,
       8,   372,   318,   374,     8,     8,     6,   122,   239,     8,
     198,     8,     8,   262,   265,     6,     6,   114,   121,     8,
       8,     6,   241,   215,   269,  1507,     8,     8,   198,     8,
     269,   266,     6,     6,   113,   243,     8,   243,   243,   113,
     243,   113,   243,   217,     6,   271,   198,     8,     8,     8,
     200,     8,     8,     8,     6,     8,   263,   213,    12,     6,
       6,    12,     6,     8,   122,   267,     8,     8,   114,   114,
       6,     3,   114,     4,     8,     8,   114,     6,     8,   114,
       8,   114,     8,   202,     8,     8,     6,    12,   328,     8,
    1301,   245,  1390,  1480,   254,  1557,   254,  1487,   998,  1132,
     998,   998,  1598,   998,  1599,  1599,  1507,  1594,    -1,    -1,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1589
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    43,   437,   441,   442,     0,   309,   972,   973,    15,
     443,   204,   454,   455,   311,   974,     8,   444,    47,   461,
     462,   169,   456,   655,     8,   975,     6,    44,    45,   445,
     446,   248,   551,   552,    16,   463,   656,     8,    11,    12,
     457,   458,   459,     6,   310,   312,   976,   977,     8,   448,
      77,   598,   599,    11,    12,   553,   554,   555,     8,    11,
      12,   464,   465,   466,     6,   460,     8,   978,   979,    12,
      11,    12,    18,    19,   198,   202,   447,   449,   450,   451,
     452,   453,    41,    42,   438,    11,    12,   600,   601,   602,
     250,   556,   557,     6,   467,     8,   205,   206,   709,   710,
      12,    12,   138,   139,   198,   935,   954,   955,   956,   980,
      46,     8,     8,     8,     8,    40,   439,   440,    78,    79,
     603,   604,   647,   648,   254,   570,   571,   182,   558,   657,
       8,    48,    49,    51,    53,    55,    57,    59,    61,    63,
      65,   468,   469,   470,   475,   476,   481,   482,   496,   497,
     503,   504,   509,   510,   515,   516,   521,   522,   536,   537,
     711,   712,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   981,
     982,   985,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1010,  1012,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1026,  1032,  1040,  1043,  1046,  1049,  1052,     3,
       8,     6,     6,     6,   677,   679,    78,    17,   605,    78,
      83,   258,   584,   585,   181,   572,   658,     8,    11,    12,
     559,   560,   561,   471,   472,   477,   478,   483,   484,   498,
     499,   505,   506,   511,   512,   517,   518,   523,   524,   538,
     539,    11,    12,   714,   715,   716,   132,   133,   134,   135,
     160,   161,   167,   168,   713,   922,   924,   948,   949,   950,
     957,   958,   959,   960,   961,   962,   999,   991,   993,   997,
    1001,  1003,  1041,  1053,  1011,   995,  1018,  1005,  1007,  1009,
    1033,  1016,  1047,  1044,  1050,   983,   986,   989,  1020,  1022,
    1024,   313,   981,  1028,     8,     6,     8,     8,     8,     8,
       6,     7,   432,   433,   434,   435,   680,     8,   606,   607,
     608,   650,   314,  1122,  1123,   180,   586,   659,     8,    11,
      12,   573,   574,   575,     6,   563,    11,    12,   474,   473,
     922,   924,   948,    11,    12,   480,   479,   922,   924,   948,
      11,    12,   486,   485,   922,   924,   948,    11,    12,   502,
      29,   500,   501,   922,   924,   948,    11,    12,   508,    35,
      36,    37,   507,   660,   661,   662,   922,   924,   948,    11,
      12,   514,    38,    39,   513,   660,   661,   663,   664,   922,
     924,   948,    11,    12,   520,    14,   519,   665,   922,   924,
     948,    12,   526,   525,   922,   924,   948,    12,   541,   540,
     922,   924,   948,   209,   717,   718,   719,     3,     3,     3,
       8,     8,   981,   981,   981,   981,   981,   981,  1042,  1054,
     981,   981,   981,   981,   981,   981,  1036,   981,  1048,  1045,
    1051,    11,    12,   984,    11,    12,   987,   981,   252,   256,
     260,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,  1055,  1056,  1057,
    1062,  1063,  1066,  1067,  1070,  1071,  1074,  1075,  1077,  1078,
    1080,  1081,  1083,  1084,  1086,  1087,  1090,  1091,  1095,  1096,
    1098,  1099,  1101,  1102,  1104,  1105,  1107,  1108,  1110,  1113,
    1114,  1116,  1117,  1119,  1120,  1055,  1055,   353,  1014,    11,
      12,   142,   143,   431,   960,   963,   964,   965,  1027,  1029,
    1030,     8,   679,   679,     6,    80,   607,    81,    11,    12,
      20,    21,   649,   651,   653,   654,   249,   316,  1124,  1125,
       8,    11,    12,   587,   588,   589,     6,   577,     8,   251,
     252,   562,   564,   565,    50,    52,   487,   488,    56,     8,
      58,     8,     8,     8,    60,     8,     8,    62,     3,    73,
     527,   528,    75,   542,   543,   207,   724,   720,   721,     8,
       8,     8,     6,     6,   981,   981,   981,   981,   331,   333,
     335,   981,   337,   981,   339,   341,   981,   345,   347,   349,
      11,    12,   198,   202,  1034,  1037,  1038,  1039,   355,   357,
     981,   359,   981,   361,   981,   363,   365,   981,  1111,   371,
    1058,   198,  1065,   198,  1069,   198,  1073,  1055,  1076,  1055,
    1079,   981,  1082,  1055,  1085,   427,  1088,  1094,  1092,  1094,
      11,    12,  1097,  1055,  1100,  1055,  1103,  1055,  1106,  1055,
    1109,  1055,  1115,   981,  1118,  1055,  1121,   373,   375,   369,
       3,     3,     8,   133,   609,    84,     8,     8,     8,    11,
      12,  1126,  1127,  1128,     6,   591,     8,   255,   256,   576,
     578,   579,   566,   567,    54,   495,    71,   489,   490,     6,
     677,     6,     6,     6,     6,     8,    64,   535,   123,   529,
     923,    66,   550,   544,   923,   210,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   246,   725,   726,   727,   751,
     752,   764,   765,   791,   792,   809,   810,   827,   828,   840,
     841,   858,   859,   876,   877,   889,   890,   893,   894,    11,
      12,   723,   164,   165,   183,   184,   185,   186,   187,   188,
     189,   190,   722,   928,   929,   930,   931,   932,   938,   939,
     944,   945,   946,   947,     8,     8,   323,   325,   327,   329,
     981,   351,   981,     8,     8,   367,  1112,    11,    12,    23,
     198,   429,   666,  1059,  1060,  1061,     8,    11,    12,  1064,
       8,    11,    12,  1068,     8,    11,    12,  1072,   377,  1055,
     405,   407,     3,    12,    12,   385,  1055,   389,  1055,  1055,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   981,
    1135,  1136,  1137,  1138,  1143,  1144,  1146,  1147,  1149,  1152,
    1153,  1155,  1156,  1158,  1159,  1161,  1162,  1164,  1165,   981,
     401,     8,  1031,    12,     3,    11,    12,   610,   677,   677,
       6,  1129,     8,   259,   260,   590,   592,   593,   580,   581,
      11,    12,   569,    24,    25,    26,    27,    28,    30,   150,
     151,   200,   568,   667,   668,   670,   671,   674,   675,   922,
     924,   937,   948,   969,   970,   971,   491,   492,     8,     8,
       8,     8,     8,     8,     8,    11,    12,   530,   531,   532,
      11,    12,   545,   546,   547,   728,   729,   753,   754,   766,
     767,   793,   794,   811,   812,   829,   830,   842,   843,   860,
     861,   878,   879,   891,   954,   166,   895,   921,   208,     3,
       8,     8,     8,     8,     8,     8,     8,     8,   343,  1035,
       6,   677,   395,  1055,   403,     8,     8,     3,     6,   253,
       6,   257,     6,   261,   379,     8,  1055,  1089,  1055,  1093,
     387,   391,   393,    12,   397,  1140,  1141,    12,    12,    12,
      12,    12,    12,    12,   981,     8,     8,   272,   611,   612,
       8,     8,     8,   315,   317,  1130,  1131,   594,   595,    11,
      12,   583,    31,    33,    34,   582,   669,   670,   672,   676,
     922,   924,   937,   948,   253,     8,     8,     8,     8,     8,
       8,     3,     8,    11,    12,   494,   493,   937,   960,     6,
     121,   533,   681,   682,   689,   548,   681,    12,   162,   163,
     170,   730,   925,   951,   952,   953,    12,   755,   925,   951,
      12,   768,   925,   951,    12,   795,   925,   951,    12,   813,
     925,   951,    12,   831,   925,   951,    12,   844,   925,   951,
      12,   862,   925,   951,    12,   880,   925,   951,    12,     8,
      12,   896,   678,   679,     6,     6,     6,     6,     6,     6,
       6,   677,   351,     8,     8,     6,     6,     8,     8,     8,
       8,   381,   383,  1150,    11,    12,  1139,   193,   194,   942,
     943,  1142,   981,  1145,  1135,  1148,  1135,  1154,  1135,  1157,
    1135,  1160,  1135,  1163,  1135,  1166,   981,   613,    82,   264,
     624,  1132,  1133,    11,    12,   597,    32,   596,   667,   668,
     670,   673,   674,   675,   922,   924,   948,   257,     8,     8,
       8,     6,     6,     6,     6,     6,     6,     8,     6,    72,
       8,   201,   927,    74,   534,   113,   683,   684,    76,   549,
     238,   731,   733,   734,     3,     8,   733,   756,   733,   769,
     733,   796,   733,   814,   733,   832,   733,   845,   733,   863,
     733,   881,  1055,     6,   214,   898,   899,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,  1151,   415,
       8,     8,   981,  1135,  1135,   413,   409,  1135,   419,  1055,
      11,    12,    22,   177,   614,   615,   616,   617,   618,   625,
     268,   636,    12,   935,   954,  1134,   261,     8,     6,     6,
       6,     8,     8,     8,     8,     8,     8,     8,     8,    11,
      12,   690,   691,   692,   685,   686,   240,   732,   739,   740,
      11,    12,   735,   736,   737,     8,     6,   739,   757,   739,
     770,   739,   797,   739,   815,   739,   833,   739,   846,   739,
     864,   739,   882,   247,   892,     8,   216,   905,   906,   900,
     923,   421,  1135,   677,   677,   425,   417,   411,   423,   399,
     273,   619,   620,   621,     8,     8,    11,    12,    22,   171,
     626,   627,   628,   629,   630,   637,  1055,     6,     8,     8,
       8,     6,     4,   122,    12,   688,   199,   687,   936,   937,
     221,   242,   745,   746,    11,    12,   741,   742,   743,   681,
     738,     8,   242,   758,   759,   225,   242,   771,   772,   227,
     242,   798,   799,   233,   242,   816,   817,   235,   242,   834,
     835,   231,   242,   847,   848,   229,   242,   865,   866,   223,
     242,   883,   884,   237,   912,   907,   923,    11,    12,   901,
     902,   903,     8,     8,   273,   620,   270,     6,     6,   265,
     631,   632,   633,     8,     8,    11,    12,    22,   174,   638,
     639,   640,   641,   652,   318,     8,     8,   122,     6,     8,
      11,    12,   747,   748,   749,   681,   744,   239,    11,    12,
     760,   761,   762,    11,    12,   773,   774,   775,    11,    12,
     800,   801,   802,    11,    12,   818,   819,   820,    11,    12,
     836,   837,   838,    11,    12,   849,   850,   851,    11,    12,
     867,   868,   869,    11,    12,   885,   886,   887,   211,   212,
     897,   913,   914,    11,    12,   908,   909,   910,   681,   904,
     198,   622,     8,     8,   265,   632,   262,     6,     6,   269,
     642,   643,   644,     8,     8,   114,     6,   121,   693,   694,
     699,   750,   241,   681,   763,   776,   777,   803,   821,   681,
     839,   852,   870,   703,   704,   888,   915,   916,   681,   911,
     215,     8,    11,    12,   623,   198,   634,     8,     8,   269,
     643,   266,     6,     6,     8,   927,   113,   695,   696,   243,
     243,   243,   113,   778,   779,   113,   243,   804,   805,   113,
     243,   822,   823,   243,   113,   243,   853,   854,   113,   243,
     871,   872,   113,   705,   706,   243,    11,    12,   918,   919,
     920,   191,   192,   917,   933,   934,   957,   960,   217,     6,
     271,     8,    11,    12,   635,   198,   645,     8,     8,    11,
      12,   700,   701,   702,   697,   937,   780,   781,    11,    12,
     806,   807,   808,    11,    12,   824,   825,   826,   855,   873,
     707,   937,   717,     8,     8,     8,     6,   263,     8,    11,
      12,   646,     4,   122,    12,   698,    11,    12,   783,   784,
     785,   179,   203,   782,   926,   941,   981,  1136,    12,   144,
     145,   856,   857,   936,   937,   966,   967,   968,    11,    12,
     874,   875,   937,   942,   943,    12,   708,   213,     6,     6,
       8,     6,   267,   122,   677,   786,     8,     8,   114,   114,
       6,     3,   114,     4,     8,     8,     8,   114,   114,   244,
     787,   788,     6,   677,   114,     8,   114,   202,   789,   940,
       8,     8,     8,    12,   790,   677,     6,     8,   245
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, osinstance, parserData, osglData, osnlData); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osinstance);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osinstance, parserData, osglData, osnlData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSInstance *osinstance;
    OSiLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osinstance, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osinstance, parserData, osglData, osnlData); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osinstance);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
int
yyparse (osinstance, parserData, osglData, osnlData)
    OSInstance *osinstance;
    OSiLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSiL input is either invalid or not well-formed.\n"); 
            osilerror( NULL, osinstance, parserData, osglData, osnlData, parserData->parser_errors);
        }
    }
    break;

  case 7:

    { parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unexpected end of file, expecting </osil>");}
    break;

  case 9:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > parserData->qtermcount ) 
    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of qterms less than numberOfQuadraticTerms");}
    break;

  case 10:

    {
    osinstance->instanceData->quadraticCoefficients = new QuadraticCoefficients();
}
    break;

  case 11:

    { 
if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
parserData->qtermcount = 0;
}
    break;

  case 14:

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
}
    break;

  case 15:

    {
    if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= parserData->qtermcount )
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many QuadraticTerms");
}
    break;

  case 20:

    { if(parserData->qtermidxOneattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxOne attributes"); 
            parserData->qtermidxOneattON = true;  }
    break;

  case 21:

    { if(parserData->qtermidxTwoattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxTwo attributes"); 
            parserData->qtermidxTwoattON = true;  }
    break;

  case 22:

    { if(parserData->qtermcoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm coef attributes"); 
            parserData->qtermcoefattON = true;  }
    break;

  case 23:

    { if(parserData->qtermidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idx attributes"); 
            parserData->qtermidxattON = true;  }
    break;

  case 24:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 25:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 26:

    {if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = parserData->tempVal;}
    break;

  case 27:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 29:

    {
    if (osglData->matrixCounter < osglData->numberOfMatrices) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
    osinstance->instanceData->matrices->numberOfMatrices = osglData->numberOfMatrices;
    osinstance->instanceData->matrices->matrix = osglData->matrix;
}
    break;

  case 30:

    {
    osinstance->instanceData->matrices = new Matrices();
    osglData->numberOfMatricesPresent = false;
}
    break;

  case 31:

    {
    if (osglData->numberOfMatrices < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
    {
        osglData->matrix = new OSMatrix*[osglData->numberOfMatrices];
        for (int i=0; i < osglData->numberOfMatrices; i++)
            osglData->matrix[i] = NULL;
    }
}
    break;

  case 39:

    {
    if (parserData->coneCounter < parserData->numberOfCones) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer cones than specified");
}
    break;

  case 40:

    {
    osinstance->instanceData->cones = new Cones();
    parserData->coneCounter = 0;
}
    break;

  case 41:

    {
    if (parserData->numberOfCones < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones cannot be negative");
    else
    {
        osinstance->instanceData->cones->cone = new Cone*[parserData->numberOfCones];
        for (int i=0; i < parserData->numberOfCones; i++)
            osinstance->instanceData->cones->cone[i] = NULL;
    }
}
    break;

  case 45:

    {
}
    break;

  case 47:

    {
    parserData->coneCounter++;
    if (parserData->coneCounter > parserData->numberOfCones) 
        throw ErrorClass("encountered more cones than specified");
    osinstance->instanceData->cones->numberOfCones = parserData->coneCounter;
}
    break;

  case 58:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonnegativeCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonnegative;    
}
    break;

  case 62:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 63:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 64:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 68:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonpositiveCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonpositive;    
}
    break;

  case 72:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 73:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 74:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 78:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new OrthantCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_orthant;
}
    break;

  case 79:

    {
    osglData->numberOfEl = (osglData->numberOfRows)*(osglData->numberOfColumns);
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub 
        = new double[osglData->numberOfEl];  
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb
        = new double[osglData->numberOfEl];   
    osglData->osglCounter = 0;
}
    break;

  case 82:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 83:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 84:

    {
            ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 86:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of directions does not match");
}
    break;

  case 91:

    {
    osglData->typePresent = false;
    osglData->multPresent = false;
    osglData->mult = 1;
}
    break;

  case 92:

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
    for (int i=0; i < osglData->mult; i++)
    {
        ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub[osglData->osglCounter+i] = ubt;
        ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb[osglData->osglCounter+i] = lbt;
    }
    osglData->osglCounter += osglData->mult;
}
    break;

  case 101:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new PolyhedralCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_polyhedral;    
}
    break;

  case 105:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 106:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 107:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->referenceMatrixIdx
                = parserData->referenceMatrixIdx;
        }
    break;

  case 108:

    {
            ((PolyhedralCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 109:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->referenceMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "polyhedral cone referenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "polyhedral cone reference matrix index cannot be negative");
    parserData->referenceMatrixIdxPresent = true;
    parserData->referenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 113:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->axisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new QuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_quadratic;    
}
    break;

  case 117:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 118:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 119:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 120:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    break;

  case 121:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    break;

  case 122:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->axisDirection
                = parserData->axisDirection;
        }
    break;

  case 126:

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
}
    break;

  case 130:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 131:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 132:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name
                = osglData->name;
        }
    break;

  case 133:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    break;

  case 134:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    break;

  case 135:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->firstAxisDirection
                = parserData->firstAxisDirection;
        }
    break;

  case 136:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->secondAxisDirection
                = parserData->secondAxisDirection;
        }
    break;

  case 140:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->semidefinitenessPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new SemidefiniteCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_semidefinite;    
}
    break;

  case 144:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 145:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 146:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 147:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->semidefiniteness
                = parserData->semidefiniteness;
        }
    break;

  case 151:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new ProductCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_product;    
}
    break;

  case 155:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 156:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 157:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 160:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 161:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 167:

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
}
    break;

  case 170:

    {
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new IntersectionCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_intersection;    
}
    break;

  case 174:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }
    break;

  case 175:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = osglData->numberOfColumns;
        }
    break;

  case 176:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = osglData->name;
        }
    break;

  case 179:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 180:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 186:

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
}
    break;

  case 190:

    {
    osinstance->instanceData->matrixProgramming = new MatrixProgramming();
}
    break;

  case 196:

    {  
        if (parserData->kounter < parserData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixVar less than number attribute");   
    }
    break;

  case 197:

    {
    osinstance->instanceData->matrixProgramming->matrixVariables = new MatrixVariables(); 
}
    break;

  case 198:

    {
    osinstance->instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar = parserData->numberOfMatrixVar;
    osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar
        = new MatrixVar*[parserData->numberOfMatrixVar];
    for (int i=0; i < parserData->numberOfMatrixVar; i++)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i] = new MatrixVar();
    parserData->kounter = 0;
}
    break;

  case 206:

    {
    parserData->kounter += osglData->mult;
}
    break;

  case 207:

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
}
    break;

  case 208:

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
}
    break;

  case 225:

    {  
        if (parserData->kounter < parserData->numberOfMatrixObj)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj less than number attribute");
    }
    break;

  case 226:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives = new MatrixObjectives(); 
}
    break;

  case 227:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj = parserData->numberOfMatrixObj;
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj
        = new MatrixObj*[parserData->numberOfMatrixObj];
    for (int i=0; i < parserData->numberOfMatrixObj; i++)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i] = new MatrixObj();
    parserData->kounter = 0;
}
    break;

  case 235:

    {
    parserData->kounter += osglData->mult;
}
    break;

  case 236:

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
}
    break;

  case 237:

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
}
    break;

  case 251:

    {  
        if (parserData->kounter < parserData->numberOfMatrixCon)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon less than number attribute");   
    }
    break;

  case 252:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints = new MatrixConstraints(); 
}
    break;

  case 253:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon = parserData->numberOfMatrixCon;
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon
        = new MatrixCon*[parserData->numberOfMatrixCon];
    for (int i=0; i < parserData->numberOfMatrixCon; i++)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i] = new MatrixCon();
    parserData->kounter = 0;
}
    break;

  case 261:

    {
    parserData->kounter += osglData->mult;
}
    break;

  case 262:

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
}
    break;

  case 263:

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
}
    break;

  case 279:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 286:

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
}
    break;

  case 287:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 288:

    {
    if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[(3) - (5)].ival) < 1) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of stages must be positive");
    osinstance->instanceData->timeDomain->stages->numberOfStages = (yyvsp[(3) - (5)].ival);
    if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
        osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ (yyvsp[(3) - (5)].ival) ];
    for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) 
    {    osinstance->instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
        osinstance->instanceData->timeDomain->stages->stage[i]->variables   = new TimeDomainStageVariables();
        osinstance->instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        osinstance->instanceData->timeDomain->stages->stage[i]->objectives  = new TimeDomainStageObjectives();
    }
}
    break;

  case 291:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 292:

    { /* set defaults for next stage */
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
}
    break;

  case 294:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 299:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 304:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of variables cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");         
    if ((yyvsp[(3) - (4)].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfVariables");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var = new TimeDomainStageVar*[ (yyvsp[(3) - (4)].ival) ];
        for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
        }
    };
}
    break;

  case 305:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 306:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    break;

  case 307:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }
    break;

  case 312:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 314:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stagevarcount++;
}
    break;

  case 318:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 323:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of constraints cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");         
    if ((yyvsp[(3) - (4)].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfConstraints");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con = new TimeDomainStageCon*[ (yyvsp[(3) - (4)].ival) ];
        for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
        }
    };
}
    break;

  case 324:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 325:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    break;

  case 326:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }
    break;

  case 331:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 333:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageconcount++;
}
    break;

  case 336:

    { /* By default, an objective belongs to every stage */
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 
                osinstance->instanceData->objectives->numberOfObjectives;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = 
                new TimeDomainStageObj*[ osinstance->instanceData->objectives->numberOfObjectives ];
            for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++) 
            {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
                osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = -(i+1); 
            }
    }
    break;

  case 337:

    {
      parserData->stageObjectivesON = true;
    }
    break;

  case 342:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of objectives cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->objectives->numberOfObjectives)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");         
    if ((yyvsp[(3) - (4)].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfObjectives");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = new TimeDomainStageObj*[ (yyvsp[(3) - (4)].ival) ];
        for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = 0; 
        }
    };
}
    break;

  case 343:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    break;

  case 344:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }
    break;

  case 349:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 351:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) >= 0 || (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageobjcount++;
}
    break;

  case 354:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 355:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}
    break;

  case 360:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    break;

  case 361:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }
    break;

  case 362:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 363:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 364:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}
    break;

  case 365:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    osglData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = (yyvsp[(3) - (4)].ival);
}
    break;

  case 366:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfConesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <cone> elements cannot be negative");
    parserData->numberOfConesPresent = true;
    parserData->numberOfCones = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 367:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 368:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 369:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 370:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->normScaleFactorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "normScaleFactor attribute previously set");
    if (parserData->tempVal <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "scale factor must be positive");
    parserData->normScaleFactorPresent = true;
    parserData->normScaleFactor = parserData->tempVal; 
}
    break;

  case 371:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->distortionMatrixPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "distortionMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "distortion matrix index cannot be negative");
    parserData->distortionMatrixPresent = true;
    parserData->distortionMatrix = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 372:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->axisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->axisDirectionPresent = true;
    parserData->axisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 373:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->firstAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "firstAxisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->firstAxisDirectionPresent = true;
    parserData->firstAxisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 374:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->secondAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "secondAxisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->secondAxisDirectionPresent = true;
    parserData->secondAxisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 375:

    {
    if (parserData->semidefinitenessPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->semidefinitenessPresent = true;
    parserData->semidefiniteness = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
    if (parserData->semidefiniteness != "positive" && parserData->semidefiniteness != "negative")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "semidefiniteness must be either \"positive\" or \"negative\"");
}
    break;

  case 376:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->matrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index cannot be negative");
    parserData->matrixIdxPresent = true;
    parserData->matrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 377:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbMatrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbMatrix attribute");
    parserData->lbMatrixIdxPresent = true;
    parserData->lbMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 378:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubMatrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubMatrix attribute");
    parserData->ubMatrixIdxPresent = true;
    parserData->ubMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 379:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->constantMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one constant matrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for constant matrix attribute");
    parserData->constantMatrixIdxPresent = true;
    parserData->constantMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 380:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "template matrix index cannot be negative");
    parserData->templateMatrixIdxPresent = true;
    parserData->templateMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 381:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->varReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one varReference matrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for varReference matrix attribute");
    parserData->varReferenceMatrixIdxPresent = true;
    parserData->varReferenceMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 382:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->objReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one objReference matrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for objReference matrix attribute");
    parserData->objReferenceMatrixIdxPresent = true;
    parserData->objReferenceMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 383:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->conReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one conReference matrix attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for conReference matrix attribute");
    parserData->conReferenceMatrixIdxPresent = true;
    parserData->conReferenceMatrixIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 384:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbCone attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbCone attribute");
    parserData->lbConeIdxPresent = true;
    parserData->lbConeIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 385:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubCone attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubCone attribute");
    parserData->ubConeIdxPresent = true;
    parserData->ubConeIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 386:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->orderConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one orderCone attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0 || (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for orderCone attribute");
    parserData->orderConeIdxPresent = true;
    parserData->orderConeIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 387:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 388:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 396:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 401:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}
    break;

  case 407:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->incr;    
}
    break;

  case 413:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
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
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 414:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 419:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 422:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 428:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
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
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 429:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 433:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 436:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));    
}
    break;

  case 437:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 438:

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
}
    break;

  case 439:

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
}
    break;

  case 450:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 453:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 454:

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
}
    break;

  case 455:

    {
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
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
}
    break;

  case 470:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 483:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 484:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 487:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 488:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 492:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 493:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 500:

    {
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 501:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 507:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 508:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 515:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 516:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 519:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 520:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 524:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 525:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 532:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 533:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 536:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 537:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 540:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 541:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 542:

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
}
    break;

  case 550:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 551:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 552:

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
}
    break;

  case 564:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 566:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 567:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 569:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 570:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 573:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 574:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 577:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 578:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 579:

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
}
    break;

  case 587:

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
    }
    break;

  case 591:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 593:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 594:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 597:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 598:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 601:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 602:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 603:

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
}
    break;

  case 611:

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
    }
    break;

  case 615:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 617:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 618:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 621:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 622:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 626:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 627:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 634:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 635:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 638:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 639:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 642:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 643:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 644:

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
}
    break;

  case 652:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = "";
    }
    break;

  case 658:

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
                    = (yyvsp[(2) - (3)].ival) + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 660:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 661:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 664:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 665:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 668:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 669:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 670:

    {
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues> 0)
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
}
    break;

  case 677:

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
}
    break;

  case 678:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }
    break;

  case 687:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 688:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 691:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 692:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 696:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 697:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 704:

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
}
    break;

  case 706:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 707:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 708:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 709:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 710:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 712:

    {
    if ( ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren != 
                           osglData->nBlocksVec.back())
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
}
    break;

  case 713:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 714:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 715:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 721:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 722:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 723:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 730:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 731:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 732:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back((MatrixBlock*)osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}
    break;

  case 738:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 739:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 743:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 744:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 745:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 746:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 747:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 748:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 749:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 750:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[(3) - (4)].ival);
}
    break;

  case 751:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 752:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 753:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 754:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 755:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 756:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}
    break;

  case 757:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = (yyvsp[(3) - (4)].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}
    break;

  case 758:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 759:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 760:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 761:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 762:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 763:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
}
    break;

  case 764:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
}
    break;

  case 765:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 766:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 767:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 770:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 771:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 774:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 775:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 778:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 779:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 782:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 783:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 786:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 787:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 790:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 791:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 794:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 795:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 798:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 799:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 802:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 803:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 805:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 806:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 807:

    { 
        if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        if ((yyvsp[(3) - (5)].ival) < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[(3) - (5)].ival);
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
        for (int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[i] = new Nl();
        }
    }
    break;

  case 810:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->nonlinearExpressions
                    ->nl[osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 811:

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
    }
    break;

  case 812:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 815:

    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
                = new RealValuedExpressionTree();
//        }
    }
    break;

  case 816:

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
    }
    break;

  case 844:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 848:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 852:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 854:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 856:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 858:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 860:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 862:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 864:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 866:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 868:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 870:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 872:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 874:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 877:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 878:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 879:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 880:

    {
}
    break;

  case 881:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 882:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 883:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 885:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 887:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 889:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 890:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 895:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 896:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 898:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 900:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 901:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 904:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 908:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 909:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 910:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 911:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 912:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 913:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 915:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 916:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 917:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 919:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 920:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 921:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 923:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 924:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 925:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 927:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 928:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 929:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 931:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 951:

    {
    osnlData->matrixidxattON = false;
    if (osnlData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory idx attribute missing");
    if (osnlData->transposeAttributePresent == true)
        osnlData->nlMNodeMatrixRef->transpose = osnlData->matrixTransposeAttribute;
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 952:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 959:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    osnlData->idxAttributePresent = true;
}
    break;

  case 960:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
    osnlData->transposeAttributePresent = true;
}
    break;

  case 961:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 962:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 965:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 966:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 967:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 970:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 971:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 972:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 975:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 977:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 980:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 983:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 986:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 989:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 991:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 994:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 996:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 998:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1000:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1004:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1007:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1010:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1013:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1015:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1016:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1018:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1020:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1023:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1026:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1029:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 1030:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }
    break;

  case 1032:

    {
    #ifdef OSINSTANCE_AVAILABLE
        if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = (yyvsp[(3) - (4)].ival);  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr
                = new MatrixExpression*[ (yyvsp[(3) - (4)].ival) ];
        for (int i = 0; 
                 i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr;
                 i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i]
                = new MatrixExpression();
    #endif
    }
    break;

  case 1039:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->
                    expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
                ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }
    break;

  case 1040:

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
    }
    break;

  case 1041:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 1044:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    break;

  case 1045:

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
    }
    break;

  case 1057:

    {
}
    break;

  case 1058:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1061:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}
    break;

  case 1067:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1070:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1072:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1073:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1075:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1077:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1080:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1083:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1086:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1089:

    {
    osnlData->nlNodePoint = new OSnLCNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, osinstance, parserData, osglData, osnlData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, osinstance, parserData, osglData, osnlData);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, osinstance, parserData, osglData, osnlData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osinstance, parserData, osglData, osnlData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osinstance, parserData, osglData, osnlData);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}






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
    // if, present we should be pointing to <objectives element if there -- it is not required
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
        for (i = 0; i < (base64decodeddatalength/dataSize); i++){
            osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
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
            if(kount +elmult > std::max(osinstance->instanceData->constraints->numberOfConstraints,
                                        osinstance->instanceData->variables->numberOfVariables) + 1 )
            {
                 osilerror_wrapper( ch, osillineno,"number of start elements exceeds the maximum number of rows or columns plus  1");            
            }
            osinstance->instanceData->linearConstraintCoefficients->start->el[kount] = atoimod1( osillineno, *p, ch);
            for (int k=1; k < elmult; k++)
            {
                osinstance->instanceData->linearConstraintCoefficients->start->el[ kount+k]
                = osinstance->instanceData->linearConstraintCoefficients->start->el[ kount] + k*elincr;
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
        for(i = 0; i < numberOfEl; i++){
            osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = *(intvec++);
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
            }
            osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount] = atoimod1( osillineno, *p, ch);
            for (int k=1; k < elmult; k++)
            {
                osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount+k] 
                = osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount] + k*elincr;
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
        for(i = 0; i < numberOfEl; i++){
            osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = *(intvec++);
            kount++;
        }
        delete [] b64string;
    }
    else{
        foundEl = true;
        // if we are here we are storing the problem by row
        // this means the number of start elements must equal the number of rows
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
            }
            osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount] = atoimod1( osillineno, *p, ch);
            for (int k=1; k < elmult; k++)
            {
                osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount+k] 
                = osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount] + k*elincr;
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
        osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod1( osillineno, attText, attTextEnd);
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


