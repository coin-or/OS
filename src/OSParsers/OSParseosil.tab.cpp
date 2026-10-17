/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         osilparse
#define yylex           osillex
#define yyerror         osilerror
#define yydebug         osildebug
#define yynerrs         osilnerrs


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
//#define DEBUG

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
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);
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



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "OSParseosil.tab.hpp".  */
#ifndef YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED
# define YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int osildebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    SCALARIMAGINARYPARTATT = 446,
    BLOCKROWIDXATT = 447,
    BLOCKCOLIDXATT = 448,
    REATT = 449,
    IMATT = 450,
    MATRIXVARIDXATT = 451,
    MATRIXOBJIDXATT = 452,
    MATRIXCONIDXATT = 453,
    IDXATT = 454,
    INCRATT = 455,
    MULTATT = 456,
    SIZEOFATT = 457,
    COEFATT = 458,
    CONSTANTATT = 459,
    MATRICESSTART = 460,
    MATRICESEND = 461,
    MATRIXSTART = 462,
    MATRIXEND = 463,
    BASEMATRIXEND = 464,
    BASEMATRIXSTART = 465,
    BLOCKSSTART = 466,
    BLOCKSEND = 467,
    BLOCKSTART = 468,
    BLOCKEND = 469,
    COLOFFSETSTART = 470,
    COLOFFSETEND = 471,
    ROWOFFSETSTART = 472,
    ROWOFFSETEND = 473,
    ELEMENTSSTART = 474,
    ELEMENTSEND = 475,
    CONSTANTELEMENTSSTART = 476,
    CONSTANTELEMENTSEND = 477,
    COMPLEXELEMENTSSTART = 478,
    COMPLEXELEMENTSEND = 479,
    VARREFERENCEELEMENTSSTART = 480,
    VARREFERENCEELEMENTSEND = 481,
    LINEARELEMENTSSTART = 482,
    LINEARELEMENTSEND = 483,
    CONREFERENCEELEMENTSSTART = 484,
    CONREFERENCEELEMENTSEND = 485,
    OBJREFERENCEELEMENTSSTART = 486,
    OBJREFERENCEELEMENTSEND = 487,
    REALVALUEDEXPRESSIONSSTART = 488,
    REALVALUEDEXPRESSIONSSEND = 489,
    COMPLEXVALUEDEXPRESSIONSSTART = 490,
    COMPLEXVALUEDEXPRESSIONSSEND = 491,
    STRINGVALUEDELEMENTSSTART = 492,
    STRINGVALUEDELEMENTSEND = 493,
    STARTVECTORSTART = 494,
    STARTVECTOREND = 495,
    INDEXSTART = 496,
    INDEXEND = 497,
    VALUESTART = 498,
    VALUEEND = 499,
    VARIDXSTART = 500,
    VARIDXEND = 501,
    TRANSFORMATIONSTART = 502,
    TRANSFORMATIONEND = 503,
    MATRIXPROGRAMMINGSTART = 504,
    MATRIXPROGRAMMINGEND = 505,
    MATRIXVARIABLESSTART = 506,
    MATRIXVARIABLESEND = 507,
    MATRIXVARSTART = 508,
    MATRIXVAREND = 509,
    MATRIXOBJECTIVESSTART = 510,
    MATRIXOBJECTIVESEND = 511,
    MATRIXOBJSTART = 512,
    MATRIXOBJEND = 513,
    MATRIXCONSTRAINTSSTART = 514,
    MATRIXCONSTRAINTSEND = 515,
    MATRIXCONSTART = 516,
    MATRIXCONEND = 517,
    CONSTART = 518,
    CONEND = 519,
    CONSTRAINTSSTART = 520,
    CONSTRAINTSEND = 521,
    OBJSTART = 522,
    OBJEND = 523,
    OBJECTIVESSTART = 524,
    OBJECTIVESEND = 525,
    VARSTART = 526,
    VAREND = 527,
    VARIABLESSTART = 528,
    VARIABLESEND = 529,
    GENERALSTART = 530,
    GENERALEND = 531,
    SYSTEMSTART = 532,
    SYSTEMEND = 533,
    SERVICESTART = 534,
    SERVICEEND = 535,
    JOBSTART = 536,
    JOBEND = 537,
    OPTIMIZATIONSTART = 538,
    OPTIMIZATIONEND = 539,
    ATEQUALITYSTART = 540,
    ATEQUALITYEND = 541,
    ATLOWERSTART = 542,
    ATLOWEREND = 543,
    ATUPPERSTART = 544,
    ATUPPEREND = 545,
    BASICSTART = 546,
    BASICEND = 547,
    ISFREESTART = 548,
    ISFREEEND = 549,
    SUPERBASICSTART = 550,
    SUPERBASICEND = 551,
    UNKNOWNSTART = 552,
    UNKNOWNEND = 553,
    SERVICEURISTART = 554,
    SERVICEURIEND = 555,
    SERVICENAMESTART = 556,
    SERVICENAMEEND = 557,
    INSTANCENAMESTART = 558,
    INSTANCENAMEEND = 559,
    JOBIDSTART = 560,
    JOBIDEND = 561,
    OTHERSTART = 562,
    OTHEREND = 563,
    DUMMY = 564,
    NONLINEAREXPRESSIONSSTART = 565,
    NONLINEAREXPRESSIONSEND = 566,
    NUMBEROFNONLINEAREXPRESSIONS = 567,
    NLSTART = 568,
    NLEND = 569,
    MATRIXEXPRESSIONSSTART = 570,
    MATRIXEXPRESSIONSEND = 571,
    NUMBEROFEXPR = 572,
    EXPRSTART = 573,
    EXPREND = 574,
    NUMBEROFMATRIXTERMSATT = 575,
    MATRIXTERMSTART = 576,
    MATRIXTERMEND = 577,
    POWERSTART = 578,
    POWEREND = 579,
    PLUSSTART = 580,
    PLUSEND = 581,
    MINUSSTART = 582,
    MINUSEND = 583,
    DIVIDESTART = 584,
    DIVIDEEND = 585,
    LNSTART = 586,
    LNEND = 587,
    SQRTSTART = 588,
    SQRTEND = 589,
    SUMSTART = 590,
    SUMEND = 591,
    PRODUCTSTART = 592,
    PRODUCTEND = 593,
    EXPSTART = 594,
    EXPEND = 595,
    NEGATESTART = 596,
    NEGATEEND = 597,
    IFSTART = 598,
    IFEND = 599,
    SQUARESTART = 600,
    SQUAREEND = 601,
    COSSTART = 602,
    COSEND = 603,
    SINSTART = 604,
    SINEND = 605,
    VARIABLESTART = 606,
    VARIABLEEND = 607,
    ABSSTART = 608,
    ABSEND = 609,
    ERFSTART = 610,
    ERFEND = 611,
    MAXSTART = 612,
    MAXEND = 613,
    ALLDIFFSTART = 614,
    ALLDIFFEND = 615,
    MINSTART = 616,
    MINEND = 617,
    ESTART = 618,
    EEND = 619,
    PISTART = 620,
    PIEND = 621,
    TIMESSTART = 622,
    TIMESEND = 623,
    NUMBERSTART = 624,
    NUMBEREND = 625,
    MATRIXDETERMINANTSTART = 626,
    MATRIXDETERMINANTEND = 627,
    MATRIXTRACESTART = 628,
    MATRIXTRACEEND = 629,
    MATRIXTOSCALARSTART = 630,
    MATRIXTOSCALAREND = 631,
    MATRIXDIAGONALSTART = 632,
    MATRIXDIAGONALEND = 633,
    MATRIXDOTTIMESSTART = 634,
    MATRIXDOTTIMESEND = 635,
    MATRIXLOWERTRIANGLESTART = 636,
    MATRIXLOWERTRIANGLEEND = 637,
    MATRIXUPPERTRIANGLESTART = 638,
    MATRIXUPPERTRIANGLEEND = 639,
    MATRIXMERGESTART = 640,
    MATRIXMERGEEND = 641,
    MATRIXMINUSSTART = 642,
    MATRIXMINUSEND = 643,
    MATRIXNEGATESTART = 644,
    MATRIXNEGATEEND = 645,
    MATRIXPLUSSTART = 646,
    MATRIXPLUSEND = 647,
    MATRIXTIMESSTART = 648,
    MATRIXTIMESEND = 649,
    MATRIXSUMSTART = 650,
    MATRIXSUMEND = 651,
    MATRIXPRODUCTSTART = 652,
    MATRIXPRODUCTEND = 653,
    MATRIXSCALARTIMESSTART = 654,
    MATRIXSCALARTIMESEND = 655,
    MATRIXSUBMATRIXATSTART = 656,
    MATRIXSUBMATRIXATEND = 657,
    MATRIXTRANSPOSESTART = 658,
    MATRIXTRANSPOSEEND = 659,
    MATRIXREFERENCESTART = 660,
    MATRIXREFERENCEEND = 661,
    IDENTITYMATRIXSTART = 662,
    IDENTITYMATRIXEND = 663,
    MATRIXINVERSESTART = 664,
    MATRIXINVERSEEND = 665,
    COMPLEXCONJUGATESTART = 666,
    COMPLEXCONJUGATEEND = 667,
    COMPLEXMINUSSTART = 668,
    COMPLEXMINUSEND = 669,
    COMPLEXNEGATESTART = 670,
    COMPLEXNEGATEEND = 671,
    COMPLEXNUMBERSTART = 672,
    COMPLEXNUMBEREND = 673,
    COMPLEXPLUSSTART = 674,
    COMPLEXPLUSEND = 675,
    COMPLEXSQUARESTART = 676,
    COMPLEXSQUAREEND = 677,
    COMPLEXSUMSTART = 678,
    COMPLEXSUMEND = 679,
    COMPLEXTIMESSTART = 680,
    COMPLEXTIMESEND = 681,
    CREATECOMPLEXSTART = 682,
    CREATECOMPLEXEND = 683,
    EMPTYINCLUDEDIAGONALATT = 684,
    INCLUDEDIAGONALATT = 685,
    EMPTYTRANSPOSEATT = 686,
    TRANSPOSEATT = 687,
    EMPTYIDATT = 688,
    IDATT = 689
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
#define SCALARIMAGINARYPARTATT 446
#define BLOCKROWIDXATT 447
#define BLOCKCOLIDXATT 448
#define REATT 449
#define IMATT 450
#define MATRIXVARIDXATT 451
#define MATRIXOBJIDXATT 452
#define MATRIXCONIDXATT 453
#define IDXATT 454
#define INCRATT 455
#define MULTATT 456
#define SIZEOFATT 457
#define COEFATT 458
#define CONSTANTATT 459
#define MATRICESSTART 460
#define MATRICESEND 461
#define MATRIXSTART 462
#define MATRIXEND 463
#define BASEMATRIXEND 464
#define BASEMATRIXSTART 465
#define BLOCKSSTART 466
#define BLOCKSEND 467
#define BLOCKSTART 468
#define BLOCKEND 469
#define COLOFFSETSTART 470
#define COLOFFSETEND 471
#define ROWOFFSETSTART 472
#define ROWOFFSETEND 473
#define ELEMENTSSTART 474
#define ELEMENTSEND 475
#define CONSTANTELEMENTSSTART 476
#define CONSTANTELEMENTSEND 477
#define COMPLEXELEMENTSSTART 478
#define COMPLEXELEMENTSEND 479
#define VARREFERENCEELEMENTSSTART 480
#define VARREFERENCEELEMENTSEND 481
#define LINEARELEMENTSSTART 482
#define LINEARELEMENTSEND 483
#define CONREFERENCEELEMENTSSTART 484
#define CONREFERENCEELEMENTSEND 485
#define OBJREFERENCEELEMENTSSTART 486
#define OBJREFERENCEELEMENTSEND 487
#define REALVALUEDEXPRESSIONSSTART 488
#define REALVALUEDEXPRESSIONSSEND 489
#define COMPLEXVALUEDEXPRESSIONSSTART 490
#define COMPLEXVALUEDEXPRESSIONSSEND 491
#define STRINGVALUEDELEMENTSSTART 492
#define STRINGVALUEDELEMENTSEND 493
#define STARTVECTORSTART 494
#define STARTVECTOREND 495
#define INDEXSTART 496
#define INDEXEND 497
#define VALUESTART 498
#define VALUEEND 499
#define VARIDXSTART 500
#define VARIDXEND 501
#define TRANSFORMATIONSTART 502
#define TRANSFORMATIONEND 503
#define MATRIXPROGRAMMINGSTART 504
#define MATRIXPROGRAMMINGEND 505
#define MATRIXVARIABLESSTART 506
#define MATRIXVARIABLESEND 507
#define MATRIXVARSTART 508
#define MATRIXVAREND 509
#define MATRIXOBJECTIVESSTART 510
#define MATRIXOBJECTIVESEND 511
#define MATRIXOBJSTART 512
#define MATRIXOBJEND 513
#define MATRIXCONSTRAINTSSTART 514
#define MATRIXCONSTRAINTSEND 515
#define MATRIXCONSTART 516
#define MATRIXCONEND 517
#define CONSTART 518
#define CONEND 519
#define CONSTRAINTSSTART 520
#define CONSTRAINTSEND 521
#define OBJSTART 522
#define OBJEND 523
#define OBJECTIVESSTART 524
#define OBJECTIVESEND 525
#define VARSTART 526
#define VAREND 527
#define VARIABLESSTART 528
#define VARIABLESEND 529
#define GENERALSTART 530
#define GENERALEND 531
#define SYSTEMSTART 532
#define SYSTEMEND 533
#define SERVICESTART 534
#define SERVICEEND 535
#define JOBSTART 536
#define JOBEND 537
#define OPTIMIZATIONSTART 538
#define OPTIMIZATIONEND 539
#define ATEQUALITYSTART 540
#define ATEQUALITYEND 541
#define ATLOWERSTART 542
#define ATLOWEREND 543
#define ATUPPERSTART 544
#define ATUPPEREND 545
#define BASICSTART 546
#define BASICEND 547
#define ISFREESTART 548
#define ISFREEEND 549
#define SUPERBASICSTART 550
#define SUPERBASICEND 551
#define UNKNOWNSTART 552
#define UNKNOWNEND 553
#define SERVICEURISTART 554
#define SERVICEURIEND 555
#define SERVICENAMESTART 556
#define SERVICENAMEEND 557
#define INSTANCENAMESTART 558
#define INSTANCENAMEEND 559
#define JOBIDSTART 560
#define JOBIDEND 561
#define OTHERSTART 562
#define OTHEREND 563
#define DUMMY 564
#define NONLINEAREXPRESSIONSSTART 565
#define NONLINEAREXPRESSIONSEND 566
#define NUMBEROFNONLINEAREXPRESSIONS 567
#define NLSTART 568
#define NLEND 569
#define MATRIXEXPRESSIONSSTART 570
#define MATRIXEXPRESSIONSEND 571
#define NUMBEROFEXPR 572
#define EXPRSTART 573
#define EXPREND 574
#define NUMBEROFMATRIXTERMSATT 575
#define MATRIXTERMSTART 576
#define MATRIXTERMEND 577
#define POWERSTART 578
#define POWEREND 579
#define PLUSSTART 580
#define PLUSEND 581
#define MINUSSTART 582
#define MINUSEND 583
#define DIVIDESTART 584
#define DIVIDEEND 585
#define LNSTART 586
#define LNEND 587
#define SQRTSTART 588
#define SQRTEND 589
#define SUMSTART 590
#define SUMEND 591
#define PRODUCTSTART 592
#define PRODUCTEND 593
#define EXPSTART 594
#define EXPEND 595
#define NEGATESTART 596
#define NEGATEEND 597
#define IFSTART 598
#define IFEND 599
#define SQUARESTART 600
#define SQUAREEND 601
#define COSSTART 602
#define COSEND 603
#define SINSTART 604
#define SINEND 605
#define VARIABLESTART 606
#define VARIABLEEND 607
#define ABSSTART 608
#define ABSEND 609
#define ERFSTART 610
#define ERFEND 611
#define MAXSTART 612
#define MAXEND 613
#define ALLDIFFSTART 614
#define ALLDIFFEND 615
#define MINSTART 616
#define MINEND 617
#define ESTART 618
#define EEND 619
#define PISTART 620
#define PIEND 621
#define TIMESSTART 622
#define TIMESEND 623
#define NUMBERSTART 624
#define NUMBEREND 625
#define MATRIXDETERMINANTSTART 626
#define MATRIXDETERMINANTEND 627
#define MATRIXTRACESTART 628
#define MATRIXTRACEEND 629
#define MATRIXTOSCALARSTART 630
#define MATRIXTOSCALAREND 631
#define MATRIXDIAGONALSTART 632
#define MATRIXDIAGONALEND 633
#define MATRIXDOTTIMESSTART 634
#define MATRIXDOTTIMESEND 635
#define MATRIXLOWERTRIANGLESTART 636
#define MATRIXLOWERTRIANGLEEND 637
#define MATRIXUPPERTRIANGLESTART 638
#define MATRIXUPPERTRIANGLEEND 639
#define MATRIXMERGESTART 640
#define MATRIXMERGEEND 641
#define MATRIXMINUSSTART 642
#define MATRIXMINUSEND 643
#define MATRIXNEGATESTART 644
#define MATRIXNEGATEEND 645
#define MATRIXPLUSSTART 646
#define MATRIXPLUSEND 647
#define MATRIXTIMESSTART 648
#define MATRIXTIMESEND 649
#define MATRIXSUMSTART 650
#define MATRIXSUMEND 651
#define MATRIXPRODUCTSTART 652
#define MATRIXPRODUCTEND 653
#define MATRIXSCALARTIMESSTART 654
#define MATRIXSCALARTIMESEND 655
#define MATRIXSUBMATRIXATSTART 656
#define MATRIXSUBMATRIXATEND 657
#define MATRIXTRANSPOSESTART 658
#define MATRIXTRANSPOSEEND 659
#define MATRIXREFERENCESTART 660
#define MATRIXREFERENCEEND 661
#define IDENTITYMATRIXSTART 662
#define IDENTITYMATRIXEND 663
#define MATRIXINVERSESTART 664
#define MATRIXINVERSEEND 665
#define COMPLEXCONJUGATESTART 666
#define COMPLEXCONJUGATEEND 667
#define COMPLEXMINUSSTART 668
#define COMPLEXMINUSEND 669
#define COMPLEXNEGATESTART 670
#define COMPLEXNEGATEEND 671
#define COMPLEXNUMBERSTART 672
#define COMPLEXNUMBEREND 673
#define COMPLEXPLUSSTART 674
#define COMPLEXPLUSEND 675
#define COMPLEXSQUARESTART 676
#define COMPLEXSQUAREEND 677
#define COMPLEXSUMSTART 678
#define COMPLEXSUMEND 679
#define COMPLEXTIMESSTART 680
#define COMPLEXTIMESEND 681
#define CREATECOMPLEXSTART 682
#define CREATECOMPLEXEND 683
#define EMPTYINCLUDEDIAGONALATT 684
#define INCLUDEDIAGONALATT 685
#define EMPTYTRANSPOSEATT 686
#define TRANSPOSEATT 687
#define EMPTYIDATT 688
#define IDATT 689

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


    double   dval;
    OsXmlInt ival;
    char*    sval;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int osilparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);

#endif /* !YY_OSIL_OS_SRC_OSPARSERS_OSPARSEOSIL_TAB_HPP_INCLUDED  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1500

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  439
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  736
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1098
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1701

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   689

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   436,
     438,     2,     2,   437,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   435,     2,     2,     2,     2,     2,     2,     2,
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   451,   451,   454,   455,   457,   466,   467,   470,   471,
     487,   492,   502,   502,   504,   517,   523,   524,   527,   528,
     531,   534,   537,   540,   546,   556,   566,   570,   581,   581,
     589,   595,   607,   607,   609,   611,   618,   618,   621,   621,
     627,   633,   645,   645,   647,   649,   653,   653,   661,   662,
     663,   664,   665,   666,   668,   675,   676,   682,   684,   695,
     708,   708,   711,   717,   723,   728,   728,   731,   733,   742,
     755,   755,   758,   763,   768,   773,   773,   776,   778,   787,
     805,   805,   808,   813,   818,   824,   824,   830,   832,   832,
     834,   836,   843,   882,   883,   885,   885,   887,   887,   889,
     892,   894,   904,   917,   917,   920,   925,   930,   935,   940,
     957,   957,   960,   962,   974,   999,   999,  1002,  1007,  1012,
    1016,  1021,  1026,  1033,  1033,  1036,  1038,  1051,  1090,  1090,
    1093,  1098,  1103,  1108,  1113,  1118,  1123,  1130,  1130,  1134,
    1136,  1147,  1159,  1159,  1162,  1167,  1172,  1176,  1183,  1183,
    1197,  1199,  1208,  1220,  1220,  1223,  1228,  1233,  1238,  1240,
    1242,  1248,  1254,  1254,  1256,  1258,  1260,  1270,  1284,  1287,
    1289,  1298,  1310,  1310,  1313,  1318,  1323,  1328,  1330,  1332,
    1338,  1344,  1344,  1346,  1348,  1350,  1360,  1374,  1385,  1385,
    1387,  1392,  1392,  1394,  1397,  1399,  1399,  1406,  1411,  1421,
    1421,  1423,  1425,  1427,  1429,  1429,  1431,  1436,  1452,  1499,
    1499,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1515,  1516,  1518,  1518,  1524,  1529,  1539,  1539,
    1541,  1543,  1545,  1547,  1547,  1549,  1554,  1567,  1599,  1599,
    1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1612,  1613,
    1616,  1616,  1622,  1627,  1637,  1637,  1639,  1641,  1643,  1645,
    1645,  1647,  1652,  1667,  1705,  1705,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,  1719,  1720,  1763,  1763,  1765,
    1767,  1767,  1769,  1770,  1773,  1774,  1777,  1828,  1830,  1844,
    1845,  1847,  1847,  1871,  1872,  1875,  1876,  1878,  1880,  1881,
    1885,  1886,  1888,  1889,  1891,  1910,  1921,  1928,  1933,  1934,
    1936,  1937,  1939,  1939,  1942,  1954,  1955,  1957,  1958,  1962,
    1963,  1965,  1966,  1968,  1987,  1998,  2005,  2010,  2011,  2013,
    2014,  2016,  2016,  2019,  2031,  2032,  2034,  2044,  2048,  2049,
    2051,  2052,  2054,  2073,  2080,  2085,  2086,  2088,  2089,  2091,
    2091,  2094,  2106,  2107,  2112,  2112,  2120,  2121,  2123,  2124,
    2126,  2130,  2136,  2147,  2152,  2167,  2178,  2189,  2197,  2205,
    2224,  2235,  2253,  2267,  2280,  2293,  2305,  2323,  2335,  2347,
    2359,  2371,  2383,  2395,  2407,  2419,  2431,  2458,  2459,  2466,
    2468,  2468,  2470,  2471,  2472,  2473,  2636,  2644,  2652,  2654,
    2654,  2656,  2658,  2667,  2669,  2669,  2671,  2671,  2673,  2682,
    2685,  2685,  2687,  2687,  2690,  2721,  2729,  2731,  2731,  2733,
    2735,  2743,  2743,  2745,  2754,  2756,  2756,  2758,  2758,  2760,
    2791,  2801,  2801,  2803,  2805,  2813,  2813,  2815,  3297,  3349,
    3372,  3396,  3396,  3399,  3400,  3401,  3402,  3403,  3603,  3603,
    3605,  3607,  3648,  3650,  3650,  3655,  3674,  3705,  3705,  3708,
    3709,  3710,  3711,  3712,  3713,  3714,  3715,  3716,  3717,  3720,
    3720,  3722,  3722,  3727,  3727,  3727,  3728,  3728,  3728,  3729,
    3729,  3729,  3730,  3730,  3732,  3734,  3743,  3749,  3749,  3752,
    3756,  3762,  3764,  3764,  3770,  3780,  3790,  3790,  3792,  3794,
    3810,  3813,  3813,  3827,  3835,  3835,  3837,  3839,  3841,  3847,
    3857,  3865,  3865,  3867,  3869,  3871,  3874,  3876,  3885,  3891,
    3891,  3894,  3898,  3904,  3906,  3908,  3908,  3918,  3926,  3926,
    3928,  3930,  3932,  3935,  3937,  3946,  3952,  3952,  3955,  3959,
    3965,  3967,  3970,  3975,  3986,  4002,  4002,  4004,  4006,  4008,
    4010,  4010,  4012,  4019,  4026,  4045,  4045,  4048,  4049,  4051,
    4051,  4053,  4055,  4057,  4057,  4060,  4062,  4070,  4070,  4075,
    4082,  4084,  4093,  4099,  4099,  4102,  4106,  4113,  4115,  4118,
    4122,  4133,  4149,  4149,  4151,  4153,  4155,  4155,  4157,  4159,
    4174,  4174,  4176,  4178,  4187,  4189,  4198,  4204,  4204,  4207,
    4211,  4218,  4220,  4223,  4227,  4238,  4255,  4255,  4257,  4259,
    4261,  4261,  4263,  4265,  4280,  4280,  4282,  4284,  4294,  4296,
    4305,  4311,  4311,  4314,  4318,  4324,  4326,  4328,  4328,  4338,
    4346,  4346,  4348,  4350,  4352,  4355,  4357,  4366,  4372,  4372,
    4375,  4379,  4385,  4387,  4390,  4394,  4405,  4421,  4421,  4423,
    4425,  4427,  4427,  4429,  4432,  4444,  4444,  4447,  4448,  4449,
    4451,  4484,  4486,  4496,  4502,  4502,  4505,  4509,  4515,  4517,
    4520,  4524,  4535,  4548,  4548,  4550,  4552,  4554,  4554,  4556,
    4583,  4594,  4594,  4597,  4598,  4599,  4601,  4601,  4604,  4606,
    4615,  4621,  4621,  4624,  4628,  4634,  4636,  4638,  4638,  4648,
    4656,  4656,  4658,  4660,  4662,  4665,  4668,  4686,  4686,  4697,
    4704,  4714,  4722,  4728,  4730,  4744,  4756,  4762,  4768,  4768,
    4770,  4772,  4774,  4776,  4786,  4792,  4798,  4798,  4800,  4802,
    4804,  4806,  4806,  4811,  4816,  4828,  4830,  4830,  4833,  4834,
    4835,  4845,  4852,  4852,  4854,  4856,  4874,  4885,  4929,  5039,
    5051,  5073,  5098,  5109,  5122,  5136,  5150,  5162,  5174,  5194,
    5214,  5224,  5264,  5275,  5287,  5301,  5314,  5327,  5337,  5347,
    5357,  5370,  5370,  5372,  5382,  5546,  5546,  5548,  5555,  5582,
    5582,  5584,  5593,  5609,  5609,  5611,  5618,  5645,  5645,  5647,
    5654,  5663,  5663,  5665,  5672,  5699,  5699,  5703,  5711,  5720,
    5720,  5722,  5729,  5738,  5738,  5740,  5747,  5787,  5788,  5802,
    5808,  5833,  5834,  5836,  5847,  5866,  5874,  5874,  5877,  5886,
    5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,  5907,  5908,
    5909,  5910,  5911,  5912,  5913,  5914,  5915,  5916,  5917,  5918,
    5919,  5920,  5921,  5922,  5924,  5925,  5926,  5930,  5930,  5933,
    5934,  5936,  5936,  5939,  5940,  5944,  5944,  5949,  5949,  5954,
    5954,  5959,  5959,  5964,  5964,  5969,  5969,  5974,  5974,  5979,
    5979,  5984,  5984,  5989,  5989,  5994,  5994,  5999,  5999,  6004,
    6006,  6012,  6019,  6019,  6025,  6025,  6037,  6037,  6042,  6042,
    6047,  6047,  6057,  6064,  6070,  6071,  6073,  6074,  6077,  6081,
    6085,  6089,  6088,  6109,  6108,  6115,  6116,  6118,  6117,  6124,
    6125,  6128,  6134,  6142,  6149,  6171,  6171,  6182,  6182,  6185,
    6185,  6199,  6200,  6203,  6203,  6216,  6217,  6220,  6220,  6233,
    6234,  6237,  6237,  6247,  6248,  6254,  6255,  6256,  6257,  6258,
    6259,  6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,
    6269,  6270,  6271,  6272,  6273,  6276,  6287,  6295,  6295,  6298,
    6299,  6302,  6303,  6305,  6317,  6331,  6336,  6343,  6344,  6346,
    6353,  6358,  6365,  6366,  6368,  6375,  6380,  6387,  6388,  6390,
    6397,  6399,  6405,  6407,  6409,  6415,  6417,  6419,  6425,  6427,
    6429,  6435,  6437,  6439,  6445,  6445,  6450,  6452,  6454,  6460,
    6460,  6465,  6467,  6478,  6480,  6485,  6485,  6487,  6489,  6495,
    6498,  6500,  6506,  6509,  6511,  6517,  6521,  6520,  6533,  6533,
    6540,  6542,  6548,  6552,  6551,  6563,  6563,  6569,  6571,  6577,
    6579,  6581,  6587,  6590,  6592,  6598,  6608,  6608,  6614,  6622,
    6624,  6644,  6644,  6646,  6648,  6650,  6650,  6652,  6664,  6682,
    6688,  6688,  6691,  6699,  6715,  6715,  6719,  6720,  6721,  6722,
    6723,  6724,  6725,  6726,  6727,  6731,  6735,  6744,  6745,  6747,
    6754,  6754,  6757,  6758,  6762,  6764,  6770,  6773,  6775,  6781,
    6784,  6784,  6794,  6795,  6801,  6803,  6809,  6812,  6814,  6820,
    6823,  6825,  6831,  6834,  6836,  6842,  6845,  6847,  6853
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "SCALARIMAGINARYPARTATT",
  "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "REATT", "IMATT", "MATRIXVARIDXATT",
  "MATRIXOBJIDXATT", "MATRIXCONIDXATT", "IDXATT", "INCRATT", "MULTATT",
  "SIZEOFATT", "COEFATT", "CONSTANTATT", "MATRICESSTART", "MATRICESEND",
  "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART",
  "BLOCKSSTART", "BLOCKSEND", "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART",
  "COLOFFSETEND", "ROWOFFSETSTART", "ROWOFFSETEND", "ELEMENTSSTART",
  "ELEMENTSEND", "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND",
  "COMPLEXELEMENTSSTART", "COMPLEXELEMENTSEND",
  "VARREFERENCEELEMENTSSTART", "VARREFERENCEELEMENTSEND",
  "LINEARELEMENTSSTART", "LINEARELEMENTSEND", "CONREFERENCEELEMENTSSTART",
  "CONREFERENCEELEMENTSEND", "OBJREFERENCEELEMENTSSTART",
  "OBJREFERENCEELEMENTSEND", "REALVALUEDEXPRESSIONSSTART",
  "REALVALUEDEXPRESSIONSSEND", "COMPLEXVALUEDEXPRESSIONSSTART",
  "COMPLEXVALUEDEXPRESSIONSSEND", "STRINGVALUEDELEMENTSSTART",
  "STRINGVALUEDELEMENTSEND", "STARTVECTORSTART", "STARTVECTOREND",
  "INDEXSTART", "INDEXEND", "VALUESTART", "VALUEEND", "VARIDXSTART",
  "VARIDXEND", "TRANSFORMATIONSTART", "TRANSFORMATIONEND",
  "MATRIXPROGRAMMINGSTART", "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART",
  "MATRIXVARIABLESEND", "MATRIXVARSTART", "MATRIXVAREND",
  "MATRIXOBJECTIVESSTART", "MATRIXOBJECTIVESEND", "MATRIXOBJSTART",
  "MATRIXOBJEND", "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND",
  "MATRIXCONSTART", "MATRIXCONEND", "CONSTART", "CONEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "OBJSTART", "OBJEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "VARSTART", "VAREND",
  "VARIABLESSTART", "VARIABLESEND", "GENERALSTART", "GENERALEND",
  "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART",
  "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND", "ATUPPERSTART",
  "ATUPPEREND", "BASICSTART", "BASICEND", "ISFREESTART", "ISFREEEND",
  "SUPERBASICSTART", "SUPERBASICEND", "UNKNOWNSTART", "UNKNOWNEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND",
  "OTHERSTART", "OTHEREND", "DUMMY", "NONLINEAREXPRESSIONSSTART",
  "NONLINEAREXPRESSIONSEND", "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART",
  "NLEND", "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND",
  "NUMBEROFEXPR", "EXPRSTART", "EXPREND", "NUMBEROFMATRIXTERMSATT",
  "MATRIXTERMSTART", "MATRIXTERMEND", "POWERSTART", "POWEREND",
  "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND", "DIVIDESTART",
  "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND", "SUMSTART",
  "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND",
  "MATRIXTRACESTART", "MATRIXTRACEEND", "MATRIXTOSCALARSTART",
  "MATRIXTOSCALAREND", "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND",
  "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
  "MATRIXLOWERTRIANGLEEND", "MATRIXUPPERTRIANGLESTART",
  "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART", "MATRIXMERGEEND",
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXNEGATESTART",
  "MATRIXNEGATEEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
  "MATRIXTIMESSTART", "MATRIXTIMESEND", "MATRIXSUMSTART", "MATRIXSUMEND",
  "MATRIXPRODUCTSTART", "MATRIXPRODUCTEND", "MATRIXSCALARTIMESSTART",
  "MATRIXSCALARTIMESEND", "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND",
  "MATRIXTRANSPOSESTART", "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART",
  "MATRIXREFERENCEEND", "IDENTITYMATRIXSTART", "IDENTITYMATRIXEND",
  "MATRIXINVERSESTART", "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART",
  "COMPLEXCONJUGATEEND", "COMPLEXMINUSSTART", "COMPLEXMINUSEND",
  "COMPLEXNEGATESTART", "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART",
  "COMPLEXNUMBEREND", "COMPLEXPLUSSTART", "COMPLEXPLUSEND",
  "COMPLEXSQUARESTART", "COMPLEXSQUAREEND", "COMPLEXSUMSTART",
  "COMPLEXSUMEND", "COMPLEXTIMESSTART", "COMPLEXTIMESEND",
  "CREATECOMPLEXSTART", "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT",
  "INCLUDEDIAGONALATT", "EMPTYTRANSPOSEATT", "TRANSPOSEATT", "EMPTYIDATT",
  "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osildoc",
  "theInstanceEnd", "osilEnd", "osilEnding", "quadraticCoefficients",
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
  "xmlWhiteSpaceChar", "osglNonNegativeIntArrayData", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "osglIntVectorBase64Content", "osglIntVectorBase64Empty",
  "osglIntVectorBase64Laden", "osglDblArrayData", "osglDblVectorElArray",
  "osglDblVectorEl", "osglDblVectorElStart", "osglDblVectorElAttributes",
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
  "osglScalarMultiplierATT", "osglScalarImaginaryPartATT",
  "osglBaseTransposeATT", "baseTransposeAttEmpty",
  "baseTransposeAttContent", "osglNameATT", "nameAttEmpty",
  "nameAttContent", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "osglShapeATT", "shapeAttEmpty", "shape",
  "osglSymmetryATT", "symmetryAttEmpty", "symmetryAttContent",
  "osglTypeATT", "typeAttEmpty", "typeAttContent", "osglValueATT",
  "valueAttEmpty", "valueAttContent", "osglValueTypeATT",
  "valueTypeAttEmpty", "valueTypeAttContent", "osglVarTypeATT",
  "varTypeAttEmpty", "varTypeAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "realValuedExpressionTree", "nlstart", "nlAttributes", "nlAttributeList",
  "nlAttribute", "nlnode", "E", "$@7", "eend", "PI", "$@8", "piend",
  "times", "$@9", "plus", "$@10", "minus", "$@11", "negate", "$@12",
  "divide", "$@13", "power", "$@14", "ln", "$@15", "sqrt", "$@16",
  "square", "$@17", "cos", "$@18", "sin", "$@19", "exp", "$@20", "abs",
  "absStart", "absEnd", "erf", "$@21", "if", "$@22", "matrixDeterminant",
  "$@23", "matrixTrace", "$@24", "matrixToScalar", "$@25", "number",
  "numberStart", "numberEnd", "numberAttributeList", "numberAttribute",
  "numberidATT", "$@26", "variable", "$@27", "variableend", "$@28",
  "anotherVariableATT", "variableATT", "variablecoefATT", "variableidxATT",
  "sum", "$@29", "anothersumnlnode", "allDiff", "$@30",
  "anotherallDiffnlnode", "max", "$@31", "anothermaxnlnode", "min", "$@32",
  "anotherminnlnode", "product", "$@33", "anotherproductnlnode",
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
  "matrixPlusContent", "matrixSum", "$@34", "anothermatrixsumnode",
  "matrixTimes", "matrixTimesStart", "matrixTimesContent", "matrixProduct",
  "$@35", "anothermatrixproductnode", "matrixScalarTimes",
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
  "$@36", "anothercsumnode", "complexMinus", "complexMinusStart",
  "complexMinusContent", "complexNegate", "complexNegateStart",
  "complexNegateContent", "complexConjugate", "complexConjugateStart",
  "complexConjugateContent", "complexTimes", "complexTimesStart",
  "complexTimesContent", "complexSquare", "complexSquareStart",
  "complexSquareContent", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     685,   686,   687,   688,   689,    32,     9,    13,    10
};
# endif

#define YYPACT_NINF -1336

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1336)))

#define YYTABLE_NINF -502

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13, -1336,    80,  -226,    75, -1336, -1336,  -109,  -209,   112,
   -1336, -1336,    64,   -63,   119, -1336,   129,    55, -1336,  -117,
     141,   151,   103, -1336,   157,  -192,   153, -1336, -1336, -1336,
   -1336, -1336,    88,   128,   165,   133, -1336,   174, -1336, -1336,
   -1336, -1336, -1336,   216, -1336, -1336, -1336, -1336,   214,    40,
   -1336,   114,   158, -1336,   -17, -1336, -1336, -1336,   234, -1336,
   -1336, -1336, -1336, -1336,   236,   -25,   230,   245,   -52, -1336,
   -1336,   223,   274,   293,   297,   299, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,   269, -1336,   105, -1336, -1336, -1336,
   -1336,    21,   131,   303,   460, -1336, -1336, -1336, -1336, -1336,
   -1336,   465, -1336,   312,   322, -1336, -1336, -1336, -1336, -1336,
   -1336,   340,   346,   351, -1336, -1336, -1336, -1336, -1336, -1336,
     239,   349,   285,   287, -1336,   113,   209,   393,   210, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     221,   300, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,    78,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336,   465, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   395,
     405,   406,   410,   412,   414,    41, -1336,   416, -1336, -1336,
   -1336, -1336,   111,   265,   420,   244, -1336,   424, -1336, -1336,
   -1336, -1336, -1336,   248,   -38,   250,   -38,   261,   -38,   263,
     -15,   309,   242,   311,   232,   313,     4,   437,   -38,   457,
     -38, -1336,   270, -1336, -1336, -1336, -1336,   470, -1336,   503,
   -1336,   507,   506,   508, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   465,   465,   465,   465,
     465,   465, -1336, -1336,   465,   465,   465,   465,   465,   465,
   -1336,   465, -1336, -1336, -1336,   315,   317,   465,   189,   189,
     189, -1336,   164,    32, -1336,   514, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,   518,   471, -1336,
     474,    81, -1336,   307,   246,   551,   324, -1336,   555, -1336,
   -1336, -1336, -1336, -1336,   575,    90, -1336,   535, -1336, -1336,
   -1336, -1336, -1336, -1336,   537, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   531, -1336,
     592, -1336, -1336, -1336, -1336, -1336, -1336,   544, -1336,   596,
     598,   616, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     576, -1336,   627,   629, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336,   577, -1336,   635, -1336, -1336, -1336, -1336,
   -1336,   567, -1336, -1336, -1336, -1336, -1336,   566, -1336, -1336,
   -1336, -1336, -1336, -1336,   434, -1336, -1336,   636,   637,   638,
     641,   642,   465,   465,   465,   465,   318,   321,   634,   701,
     316,   301,   465,   314,   310,   319,    42,   305,   734,   777,
     816, -1336,   295, -1336, -1336,   283, -1336,   465, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   290, -1336,
   -1336, -1336,   458, -1336,   464, -1336,   466, -1336,   189, -1336,
     189, -1336,   465, -1336,   189, -1336,   237, -1336,   237, -1336,
     328, -1336,   189, -1336,   189, -1336,   189, -1336, -1336,   189,
   -1336, -1336,   189, -1336,   465, -1336,   189,   294,   288, -1336,
   -1336, -1336,   302, -1336,   667,   668, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,  -259,  -259,   665, -1336, -1336,   541,
   -1336,   591,   670,   671, -1336, -1336, -1336, -1336, -1336,   672,
     339, -1336,   675, -1336, -1336, -1336, -1336, -1336,   674,   104,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   622,   612,
   -1336,   678, -1336, -1336,   679,   680, -1336,   681,   682, -1336,
     683, -1336,   625,   569, -1336,   624,   569, -1336,   194,   343,
     298, -1336, -1336, -1336,   685,   686,   371,   370,   372,   368,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   465, -1336,
   -1336, -1336, -1336,   857,   689,   691, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   333,
   -1336, -1336, -1336,    38,   694,   357,   696,   367,   697,   369,
     329, -1336,   189, -1336,   304, -1336,   296, -1336,   705,   698,
   -1336,   699, -1336, -1336,   323, -1336,   189, -1336,   325, -1336,
     189, -1336,   189, -1336,   581, -1336,   465, -1336,   320, -1336,
   -1336, -1336, -1336,   706, -1336,   704,   710,   373, -1336, -1336,
   -1336,   711, -1336, -1336, -1336, -1336, -1336,   712,   126, -1336,
   -1336, -1336, -1336, -1336, -1336,   377,    98, -1336, -1336, -1336,
   -1336, -1336,   713,   714,   715,   717,   718,   719, -1336, -1336,
   -1336,   720,   384, -1336, -1336, -1336,   386, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   268,
   -1336,   553, -1336,   520, -1336, -1336,   727,   723,   724,   725,
     726,   728,   729,   730,   731,   732, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336,   391, -1336, -1336,   735, -1336,
   -1336,   -93,   155, -1336,   336,   736,   737,   740, -1336, -1336,
   -1336, -1336,   743, -1336,   492, -1336,   744, -1336,   494, -1336,
     745, -1336,   491, -1336, -1336,   375, -1336, -1336,   748,   189,
     189, -1336,   374, -1336,   365,   364, -1336, -1336, -1336, -1336,
   -1336, -1336,   747, -1336, -1336, -1336,   360, -1336, -1336, -1336,
   -1336,   749, -1336,   751, -1336, -1336,   752, -1336,   753, -1336,
     755, -1336,   756, -1336,   757,   465, -1336, -1336,   762, -1336,
     763, -1336,   499, -1336,   765,   766,   767,  -185, -1336, -1336,
   -1336, -1336, -1336, -1336,   432,    79, -1336,   522, -1336,   769,
     770,   771,   772,   773,   774, -1336,   780,   776, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336,   436,   -58, -1336, -1336, -1336, -1336, -1336, -1336,
     781, -1336,   676, -1336, -1336, -1336, -1336,   676, -1336, -1336,
   -1336,   779,   -65,   783,   -65,   830,   -65,   832,   -65,   834,
     -65,   838,   -65,   840,   -65,   842,   -65,   843,   -65,   844,
   -1336,   785,   845, -1336, -1336, -1336,   852,   853,   854,   855,
     856,   858,   859, -1336, -1336, -1336,   511,   860,   861, -1336,
   -1336, -1336, -1336, -1336,   864,   865,   866,   867, -1336,   868,
   -1336,   869, -1336, -1336, -1336,   407, -1336,   482, -1336, -1336,
   -1336, -1336, -1336, -1336,   440,   259,   465,   581,   581,   581,
     581,   581,   581,   465, -1336, -1336, -1336,   790,   602, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   445,   226, -1336,   620,
   -1336,   871,   872,   873, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,   876,   877,   878,   880,   881,   882,
     886,   884, -1336,   801, -1336, -1336, -1336, -1336,   888,   707,
     824, -1336, -1336,   787, -1336,   831, -1336,   684, -1336,   908,
     905, -1336, -1336, -1336, -1336, -1336,   684, -1336, -1336, -1336,
     684, -1336, -1336, -1336,   684, -1336, -1336, -1336,   684, -1336,
   -1336, -1336,   684, -1336, -1336, -1336,   684, -1336, -1336, -1336,
     684, -1336, -1336, -1336,   684, -1336, -1336, -1336,   189,   909,
     702, -1336, -1336,     2,   911,   913,   917,   919,   921,   923,
     925,   927,   929, -1336, -1336, -1336,   931,   933, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   525, -1336,   937,   939,
   -1336, -1336, -1336,   465, -1336,   581, -1336,   581, -1336,   533,
   -1336,   539, -1336,   581, -1336,   536, -1336,   189,    59, -1336,
   -1336,   693,   941,   -52, -1336,   716, -1336,   952, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   958,
     960,   962,   964,   966,   968,   972,   974,   976, -1336,   978,
   -1336, -1336,   980,   447, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336,   -92,   453,   982,  1004,   775, -1336,   775,
   -1336,   775, -1336,   775, -1336,   775, -1336,   775, -1336,   775,
   -1336,   775, -1336,   764,  1003, -1336,   796,   569, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     478, -1336, -1336, -1336,   586,   595,   604, -1336, -1336,   593,
   -1336,   618, -1336,   759,  1009,  1013, -1336, -1336, -1336, -1336,
   -1336,    67, -1336, -1336,   189, -1336, -1336, -1336, -1336,  1017,
    1019,  1021,  1023, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
    1029, -1336,    70, -1336, -1336, -1336,  1025,   271, -1336,   803,
     798,   479, -1336,   676, -1336, -1336, -1336, -1336,  1035,   802,
     821,   806,   823,   810,   846,   835,   848,   839,   862,   847,
     883,   874,   887,   890,   850, -1336, -1336, -1336, -1336, -1336,
     569,   481, -1336, -1336, -1336,  1078,  1088, -1336, -1336, -1336,
   -1336, -1336, -1336,   841, -1336,   885,  1113,  1115, -1336,   863,
    1117,  1119, -1336, -1336, -1336, -1336, -1336,    51,   812,  1127,
   -1336, -1336, -1336,  1146,  1036, -1336,  1154, -1336,  1156, -1336,
   -1336, -1336, -1336, -1336, -1336,   483, -1336,   676, -1336, -1336,
   -1336, -1336,   922, -1336, -1336, -1336,   485, -1336, -1336, -1336,
     487, -1336, -1336, -1336,   489, -1336, -1336, -1336,   493, -1336,
   -1336, -1336,   515, -1336, -1336, -1336,   517, -1336, -1336, -1336,
     597, -1336, -1336, -1336,   599, -1336,   400,   603, -1336, -1336,
     676, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   967,  1160,
    1162, -1336,   906, -1336,   930,  1168,  1170, -1336,   935,  1187,
    1189, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
    1085,  1195, -1336,  1082, -1336, -1336, -1336, -1336,   969, -1336,
   -1336,   676, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,   676, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   676, -1336, -1336, -1336,
   -1336,   997,  1207,   605, -1336, -1336, -1336, -1336,  1018,  1211,
    1213, -1336,   953, -1336,   970,  1219,  1221, -1336,  1223,   707,
   -1336,  1116, -1336,   989, -1336, -1336,   990,   991,  1123,   -53,
     -41, -1336,   994,   -30,   -28, -1336,  1126,   996,   607,   184,
   -1336,  1024, -1336,  1235, -1336,   971, -1336,  1236,   609, -1336,
   -1336, -1336, -1336,  1046,  1238,  1239, -1336,   611, -1336, -1336,
    1047, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     615, -1336, -1336, -1336,   617, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,  1047, -1336, -1336,   270,
   -1336, -1336, -1336,  1241,  1242, -1336, -1336, -1336, -1336, -1336,
   -1336,  1243, -1336,  1246, -1336,   992, -1336,  1245,   619, -1336,
   -1336, -1336,    87, -1336, -1336, -1336,  1247, -1336,   621,  -122,
   -1336,   465, -1336, -1336, -1336, -1336,   122, -1336, -1336, -1336,
      63,    34,  1248, -1336,  1040,  1249,  1251, -1336,  1250, -1336,
    1255, -1336,   995, -1336,  1140, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336,  1256,  1257, -1336, -1336, -1336,  1152,  1153,
    1262, -1336,  1266, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,  1157, -1336, -1336, -1336, -1336, -1336,  1268, -1336, -1336,
    1265,  1267, -1336,  1269, -1336, -1336,  1164,   -26,  1264, -1336,
   -1336, -1336,  1165,  1272, -1336,  1167, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336,  1071,  1274,  1275, -1336, -1336, -1336,  1276,
    1273, -1336, -1336, -1336, -1336,  1270, -1336,  1278,  1041, -1336,
   -1336
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   807,     0,     1,   809,    28,     0,     0,
      12,    30,    38,     0,     0,   811,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   808,   814,   812,   816,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   815,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   439,    37,   441,
     810,     0,   785,     0,     0,   818,   819,   783,   784,   817,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   440,   865,   857,   859,   863,   867,   869,   915,   931,
     877,   861,   884,   871,   873,   875,   903,   880,   882,   923,
     919,   927,   847,   851,   855,   893,   886,   888,   890,     0,
     841,   842,   822,   823,   825,   826,   827,   828,   830,   831,
     832,   834,   833,   835,   837,     0,   838,   836,   844,   845,
     846,   820,   896,   821,   824,   843,   839,   840,   829,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,  1036,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   450,   453,   438,   448,   449,   777,     0,   793,     0,
     789,     0,     0,     0,   442,   445,   444,   446,   775,   776,
     443,   787,   788,   447,   791,   792,     0,     0,     0,     0,
       0,     0,   917,   933,     0,     0,     0,     0,     0,     0,
     909,     0,   925,   921,   929,     0,     0,     0,     0,     0,
       0,   813,     0,     0,   786,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1038,     0,     0,     0,     0,   253,     0,   230,
     233,   225,   228,   229,     0,     0,    65,     0,    57,    61,
      63,    62,    64,    75,     0,    67,    71,    73,    72,    74,
      85,    88,    77,    81,    83,    82,    84,   110,     0,   100,
       0,   104,   107,   106,   105,   108,   123,     0,   112,     0,
       0,     0,   116,   121,   120,   122,   118,   117,   119,   137,
       0,   125,     0,     0,   129,   134,   133,   135,   136,   131,
     130,   132,   148,     0,   139,     0,   143,   147,   145,   144,
     146,     0,   150,   154,   156,   155,   157,     0,   169,   173,
     175,   174,   176,   455,     0,   471,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   849,     0,   848,   853,     0,   852,     0,   966,   971,
     976,   981,   984,   993,   998,  1004,  1008,  1011,  1014,  1021,
    1016,  1023,  1028,  1031,  1034,   956,   987,   990,     0,   935,
     957,   936,     0,   937,     0,   938,     0,   939,     0,   940,
       0,   954,     0,   941,     0,   942,   994,   943,   999,   944,
       0,   945,     0,   946,     0,   947,     0,   948,   949,     0,
     950,   951,     0,   952,     0,   953,     0,     0,     0,   881,
     879,   894,     0,   797,     0,     0,   898,   899,   795,   796,
     892,   897,   900,   760,   387,   388,     0,   286,   290,   293,
     356,     0,     0,     0,   355,   359,   360,   361,   194,     0,
       0,  1039,     0,   256,   259,   251,   254,   255,     0,     0,
     367,   203,   207,   202,   205,   209,    66,    76,     0,    87,
     111,     0,   124,   390,     0,     0,   138,     0,     0,   149,
       0,   160,     0,     0,   179,     0,     0,   451,   452,     0,
     456,   778,   794,   790,     0,     0,     0,     0,     0,     0,
     868,   870,   916,   918,   932,   934,   878,   862,     0,   872,
     874,   876,   905,     0,     0,     0,   904,   910,   911,   912,
     883,   924,   926,   920,   922,   928,   930,   850,   854,     0,
    1018,  1025,   887,     0,     0,     0,     0,     0,     0,     0,
       0,   980,     0,   983,     0,   986,     0,   989,     0,     0,
     995,     0,  1000,  1005,     0,  1003,     0,  1007,     0,  1010,
       0,  1013,     0,  1020,     0,  1027,     0,  1030,     0,  1033,
     889,   891,   895,     0,   901,     0,     0,     0,   357,   390,
     390,     0,  1043,  1045,  1037,  1041,  1042,     0,     0,   368,
     232,   236,   231,   234,   238,     0,   208,    99,    86,    91,
      89,    93,     0,     0,     0,     0,     0,     0,   375,   168,
     158,     0,     0,   161,   187,   177,     0,   180,   711,   485,
     662,   517,   534,   636,   619,   571,   595,   689,   706,   472,
     473,   487,   476,   519,   479,   536,   480,   573,   481,   597,
     477,   621,   478,   638,   474,   664,   475,   691,   482,   707,
     483,     0,   470,     0,   454,   773,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,   459,   462,   463,
     464,   465,   460,   461,   467,   468,   466,   771,   772,   747,
     749,   866,   858,   860,   864,     0,   906,   907,     0,   390,
     856,     0,     0,   961,     0,     0,     0,     0,   959,   958,
     955,   960,     0,   967,     0,   965,     0,   972,     0,   970,
       0,   977,     0,   975,   982,     0,   988,   991,     0,     0,
       0,  1006,     0,  1012,     0,     0,  1091,  1085,  1088,  1066,
    1078,  1097,     0,  1094,  1075,  1054,     0,  1055,  1056,  1070,
    1057,     0,  1058,     0,  1059,  1060,     0,  1061,     0,  1062,
       0,  1063,     0,  1064,     0,     0,  1035,   798,     0,   288,
       0,   295,   298,   292,     0,     0,     0,     0,   369,   258,
     262,   257,   260,   264,     0,   237,   222,     0,   206,     0,
       0,     0,     0,     0,     0,   805,     0,     0,   210,   215,
     217,   213,   214,   216,   218,   212,   211,   221,   219,   220,
     803,   804,     0,    92,   109,   370,   371,   372,   373,   374,
       0,   164,   399,   159,   162,   163,   183,   399,   178,   181,
     182,     0,   486,     0,   518,     0,   535,     0,   572,     0,
     596,     0,   620,     0,   637,     0,   663,     0,   690,     0,
     708,     0,     0,   712,   469,   390,     0,     0,     0,     0,
       0,     0,     0,   390,   390,   885,     0,     0,     0,  1017,
    1019,  1024,  1026,   962,     0,     0,     0,     0,   968,     0,
     973,     0,   978,   985,  1002,     0,   992,     0,   997,  1009,
    1015,  1022,  1080,  1029,     0,  1069,     0,     0,     0,     0,
       0,     0,     0,     0,   902,   294,   300,     0,   317,   363,
     364,  1040,  1044,  1048,  1046,  1050,     0,   263,   248,     0,
     235,     0,     0,     0,   239,   245,   242,   243,   244,   241,
     240,   247,   246,   223,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,    90,    94,    96,    95,     0,     0,
       0,   166,   396,   397,   398,     0,   185,     0,   781,     0,
       0,   488,   489,   490,   779,   780,     0,   520,   521,   522,
       0,   537,   538,   539,     0,   574,   575,   576,     0,   598,
     599,   600,     0,   622,   623,   624,     0,   639,   640,   641,
       0,   665,   666,   667,     0,   692,   693,   694,     0,     0,
       0,   710,   774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   908,   914,   913,     0,     0,   964,   969,
     974,   979,   996,  1001,  1082,  1067,     0,  1065,     0,     0,
    1073,  1072,  1071,     0,  1074,     0,  1077,     0,  1084,     0,
    1087,     0,  1090,     0,  1093,     0,  1096,     0,     0,   296,
     319,   336,     0,  1049,   275,     0,   261,     0,   265,   270,
     272,   268,   269,   271,   273,   267,   266,   274,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   806,     0,
      98,   748,     0,     0,   167,   165,   402,   400,   404,   186,
     184,   495,   484,   492,     0,     0,     0,   501,   516,   501,
     533,   501,   570,   501,   594,   501,   618,   501,   635,   501,
     661,   501,   688,     0,     0,   716,     0,     0,   389,   753,
     763,   764,   754,   755,   756,   757,   769,   770,   376,   963,
       0,  1068,   390,   390,     0,     0,     0,  1089,  1092,     0,
    1098,     0,   308,   312,     0,     0,   301,   302,   303,   299,
     306,     0,   338,   297,     0,  1052,  1053,  1051,   276,     0,
       0,     0,     0,   377,   384,   378,   385,   380,   381,   762,
       0,   413,     0,   409,   410,   411,     0,   403,   503,     0,
       0,     0,   498,   399,   494,   496,   497,   782,     0,   525,
       0,   542,     0,   579,     0,   603,     0,   627,     0,   644,
       0,   670,     0,   697,     0,   709,   705,   746,   724,   731,
       0,     0,   717,  1081,  1083,     0,     0,  1076,  1079,  1086,
    1095,  1032,   309,   312,   310,     0,     0,     0,   327,   331,
       0,     0,   320,   321,   322,   318,   325,     0,     0,     0,
     382,   386,   379,     0,     0,   412,     0,   401,     0,   405,
     407,   406,   491,   510,   493,     0,   506,   399,   502,   504,
     505,   500,     0,   750,   527,   524,     0,   523,   544,   541,
       0,   540,   581,   578,     0,   577,   605,   602,     0,   601,
     629,   626,     0,   625,   646,   643,     0,   642,   672,   669,
       0,   668,   699,   696,     0,   695,     0,     0,   725,   720,
     399,   715,   718,   719,   768,   767,   307,   311,     0,     0,
       0,   328,   331,   329,     0,     0,     0,   345,   349,     0,
       0,   339,   340,   337,   343,   341,  1047,   383,   752,   414,
       0,     0,   513,   417,   509,   511,   512,   508,     0,   499,
     530,   399,   526,   528,   529,   547,   550,   543,   545,   546,
     584,   586,   580,   582,   583,   608,   610,   604,   606,   607,
     632,   399,   628,   630,   631,   649,   651,   645,   647,   648,
     675,   677,   671,   673,   674,   702,   431,   698,   700,   701,
     714,   734,   713,   732,   736,   728,   399,   723,   726,   727,
     722,     0,     0,     0,   305,   304,   326,   330,     0,     0,
       0,   346,   349,   347,     0,     0,     0,   408,     0,     0,
     515,   415,   416,     0,   507,   532,     0,     0,   549,     0,
       0,   634,     0,     0,     0,   704,   430,     0,     0,   735,
     730,     0,   721,     0,   315,     0,   313,     0,     0,   324,
     323,   344,   348,     0,     0,     0,   761,     0,   420,   418,
     421,   514,   531,   548,   553,   551,   555,   589,   585,   587,
       0,   613,   609,   611,     0,   633,   654,   650,   652,   655,
     680,   676,   678,   681,   434,   432,   435,   703,   744,   453,
     733,   742,   743,     0,     0,   737,   738,   739,   740,   741,
     729,     0,   316,     0,   334,     0,   332,     0,     0,   362,
     342,   428,     0,   424,   425,   426,     0,   422,     0,   554,
     592,     0,   588,   590,   591,   616,     0,   612,   614,   615,
       0,     0,     0,   436,     0,     0,     0,   314,     0,   335,
       0,   352,     0,   350,     0,   427,   390,   419,   561,   563,
     552,   559,   560,     0,     0,   556,   557,   558,     0,     0,
       0,   801,     0,   656,   653,   659,   658,   657,   799,   800,
     687,     0,   682,   679,   685,   684,   683,     0,   433,   745,
       0,     0,   333,     0,   353,   429,     0,     0,     0,   390,
     593,   617,     0,     0,   686,     0,   758,   759,   351,   423,
     562,   566,   564,   567,     0,     0,   660,   802,   437,     0,
       0,   568,   751,   766,   390,     0,   565,     0,     0,   765,
     569
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,   961, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,   -23, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,  -114, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,  -201, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,  1038,  1039, -1336, -1336, -1336, -1336,
   -1336,   289,   291, -1336,  -859, -1336, -1336, -1336,   292,   306,
   -1336,  -571, -1336,  -279, -1336,  -911, -1335, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336,  -275, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,  -922, -1336,
   -1336, -1336, -1336, -1336,  -906, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,  -241,  -582,  -222,
    -357, -1336,  -204, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     154,  -310,  -863, -1336, -1336, -1336, -1336,  -309,  -308, -1336,
   -1336, -1336, -1336, -1336,  -221, -1336, -1336,  -331, -1336, -1336,
    -741, -1336, -1336,  -218, -1336, -1336,  -312, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,  -101, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,  -289, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     807, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,  -923,  -302, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   568,   569,   700,   701,   902,   903,  1035,  1034,   698,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   582,   583,   712,   913,   914,   915,  1040,  1175,   710,
     158,   159,   259,   260,   419,   418,   585,   586,   716,   918,
     919,   920,  1045,  1180,   715,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   563,   345,   564,   565,
     695,   696,   888,   878,   125,   126,   235,   341,   342,   343,
     692,   559,   693,   694,   874,   875,  1014,  1010,   232,   233,
     336,   555,   556,   557,   871,   688,   872,   873,  1006,  1007,
    1148,  1146,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   677,   863,   997,   998,  1138,  1236,  1237,
    1238,  1239,  1240,  1313,  1314,  1315,  1483,  1526,  1141,  1241,
    1322,  1323,  1324,  1325,  1326,  1402,  1403,  1404,  1528,  1586,
    1243,  1327,  1411,  1412,  1413,  1414,  1492,  1493,  1494,  1588,
    1623,   122,   123,   544,   331,   545,  1415,   546,   547,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     798,   889,   890,  1015,   891,   892,  1017,  1152,   893,   894,
    1018,   224,  1092,   225,   326,  1041,  1042,  1043,  1177,  1178,
    1266,  1267,  1339,  1337,  1044,  1263,  1264,  1265,  1500,  1501,
    1539,  1540,  1596,  1627,  1502,  1593,  1594,  1595,  1515,  1516,
    1565,  1566,  1612,  1658,    98,    99,   160,   161,   274,   263,
     264,   265,   424,   425,   426,   589,   590,   766,   754,   588,
     729,   730,   731,   921,   922,  1051,  1182,  1269,  1183,  1184,
    1274,  1275,  1276,  1352,  1270,  1271,  1348,  1349,  1350,  1428,
    1344,  1345,  1424,  1425,  1426,  1503,   732,   733,   923,   924,
    1057,  1188,  1280,  1355,  1356,  1432,  1433,  1434,  1506,   734,
     735,   925,   926,  1061,  1190,  1282,  1359,  1360,  1437,  1438,
    1439,  1507,  1508,  1545,  1546,  1598,  1599,  1635,  1630,  1631,
    1632,  1667,  1682,  1683,  1690,  1696,   736,   737,   927,   928,
    1065,  1192,  1284,  1363,  1364,  1442,  1443,  1444,  1509,  1549,
    1550,  1602,  1603,  1604,   738,   739,   929,   930,  1069,  1194,
    1286,  1367,  1368,  1447,  1448,  1449,  1510,  1553,  1554,  1607,
    1608,  1609,   740,   741,   931,   932,  1073,  1196,  1288,  1371,
    1372,  1452,  1453,  1454,  1512,   742,   743,   933,   934,  1077,
    1198,  1290,  1375,  1376,  1457,  1458,  1459,  1513,  1558,  1559,
    1610,  1643,  1644,   744,   745,   935,   936,  1081,  1200,  1292,
    1379,  1380,  1462,  1463,  1464,  1514,  1562,  1563,  1611,  1652,
    1653,   746,   747,   937,   938,  1085,  1202,  1294,  1383,  1384,
    1467,  1468,  1469,  1517,   748,   749,   939,  1296,   750,   751,
     942,  1091,  1472,  1206,  1207,  1301,  1391,  1392,  1393,  1481,
    1299,  1300,  1387,  1477,  1478,  1479,  1521,  1386,  1473,  1474,
    1518,  1519,  1575,  1570,  1571,  1572,   943,   275,   713,   276,
    1052,  1636,  1173,   767,   768,   769,   770,   771,  1576,  1577,
     105,  1340,   897,   772,   773,  1691,  1637,  1120,  1121,   774,
     775,   776,   777,   778,   277,   278,   279,  1053,  1054,  1055,
     106,   107,   108,   280,   281,   282,   283,   284,   285,   527,
     528,   529,  1647,  1648,  1649,   899,   900,   901,     7,     8,
      15,    25,    46,    47,    67,    68,   109,   835,   190,   305,
     453,   191,   306,   456,   192,   307,   193,   287,   194,   288,
     195,   295,   196,   289,   197,   286,   198,   290,   199,   291,
     200,   297,   201,   298,   202,   299,   203,   294,   204,   205,
     520,   206,   301,   207,   296,   208,   308,   209,   309,   210,
     310,   211,   212,   530,   313,   531,   532,   858,   213,   300,
     616,   956,   446,   617,   618,   619,   214,   292,   438,   215,
     303,   449,   216,   302,   448,   217,   304,   450,   218,   293,
     439,   478,   479,   480,   633,   799,   800,   801,   481,   482,
     805,   635,   483,   484,   809,   637,   485,   486,   813,   639,
     487,   488,   641,   489,   490,   643,   491,   492,   645,   493,
     494,   647,   495,   496,   649,   976,   497,   498,   651,   978,
     650,   499,   500,   655,   501,   502,   657,   503,   504,   659,
     505,   506,   661,   507,   630,   791,   508,   509,   663,   510,
     631,   792,   511,   512,   665,   513,   514,   667,   515,   516,
     669,   333,   334,   550,   551,   684,   685,   686,   867,  1004,
    1005,  1142,  1143,  1247,   836,   837,   838,   839,  1117,   984,
     985,  1122,   840,   841,  1124,   842,   843,  1126,   844,  1114,
    1220,   845,   846,  1128,   847,   848,  1130,   849,   850,  1132,
     851,   852,  1134,   853,   854,  1136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     189,   526,   703,   350,   717,   357,  1046,   364,   940,   373,
    1208,   386,  1021,   399,   370,   408,  1016,   414,   405,   420,
     517,   518,   351,   352,   358,   359,   365,   366,   374,   375,
     387,   388,   400,   401,   409,   410,   415,   416,   421,   422,
    1036,   534,   535,   521,   522,  1650,  1651,   320,   321,   793,
     794,    70,    71,   612,   613,  1480,     1,  1633,    72,    73,
    1547,   795,  1407,  1408,  1125,  1127,  1129,  1131,  1133,  1135,
    1232,  1233,  1551,  1409,  1334,  1640,   268,   269,  1318,  1319,
       5,  1234,  1634,  1556,     6,  1560,   102,   103,  1680,  1320,
       9,  1624,   540,   541,   266,   267,    11,  1048,  1049,    27,
      28,   542,   543,    14,   312,  1050,    21,   883,   864,   865,
    1011,    18,  1012,  1013,    38,    39,  1511,   266,   267,    44,
      16,    45,   879,   880,   881,   882,   883,    24,   884,   272,
     273,  1002,    31,  1003,  1187,    26,   266,   267,  1189,    53,
      54,  1520,  1191,   887,    59,    60,  1193,   104,  1151,  1268,
    1195,  -501,   272,   273,  1197,    82,    83,    34,  1199,    37,
     458,    48,  1201,    43,   459,    50,   268,   269,   460,    85,
      86,   272,   273,    58,   523,   524,   322,   323,   324,   325,
      64,    96,    97,   118,   119,   432,   433,   434,   435,   436,
     437,  1548,  1335,   440,   441,   442,   443,   444,   445,   640,
     447,   642,  1225,  1552,  1226,   646,   457,  1641,  1642,  1625,
    1229,   266,   267,   656,  1557,   658,  1561,   660,   958,  1681,
     662,   238,   239,   664,    66,  1410,    69,   668,  1118,  1119,
     266,   267,   261,   262,    90,   887,  1235,   796,  1321,    74,
      93,   614,   100,    75,    95,   615,   272,   273,   885,   886,
     879,   880,   881,   882,   883,   339,   340,   101,  1147,   346,
     347,   353,   354,  1338,   887,   272,   273,   379,   380,   110,
     392,   393,   360,   361,   367,   368,   124,   379,   380,   381,
     887,  1279,   111,  1281,   461,  1283,   462,  1285,   463,  1287,
     464,  1289,   465,  1291,   466,  1293,   467,  1304,   468,   887,
     469,   112,   470,   959,   471,   113,   472,   114,   473,   115,
     474,   130,   475,   127,   476,   219,   477,   226,   268,   269,
     376,   377,   389,   390,   402,   403,   451,   452,   454,   455,
     220,   596,   597,   598,   599,   553,   554,   603,   605,   653,
     654,   608,   561,   562,   270,   271,   221,   622,   624,   626,
     682,   683,   222,   815,   752,   753,   629,   223,   266,   267,
     690,   691,  1351,   229,   266,   267,   227,   822,   803,   804,
     230,   824,   231,   825,   266,   267,  1573,  1574,   807,   808,
     811,   812,  1101,  1102,   861,   862,   869,   870,   876,   877,
     234,   644,   311,   272,   273,   911,   912,   916,   917,   272,
     273,   237,  1246,   314,  1341,   718,   102,   103,   458,   272,
     273,   315,   459,   666,   316,   719,   460,   720,   317,   721,
     318,   722,   319,   723,   327,   724,   332,   725,   338,   726,
     344,   727,   266,   267,   268,   269,  1427,   322,   323,   324,
     325,   728,   458,  1008,  1009,   335,   459,  1032,  1033,   411,
     460,  1115,  1116,  1118,  1119,   895,  1144,  1145,  1261,  1262,
     270,   271,   755,   756,  1272,  1273,   525,   272,   273,   417,
     797,  1338,   887,   427,   896,   898,   322,   323,   324,   325,
     423,   757,   758,   759,   760,   761,   762,   763,   764,   765,
    1346,  1347,  1389,  1390,  1422,  1423,  1430,  1431,  1435,  1436,
    1440,  1441,   960,   962,  1445,  1446,   428,   785,   131,   132,
     429,   133,   787,   134,   430,   135,   431,   136,   519,   137,
    1505,   138,   533,   139,   536,   140,  1450,  1451,  1455,  1456,
     975,   977,   461,   826,   462,   827,   463,   828,   464,   829,
     465,   830,   466,   831,   467,   832,   468,   833,   469,   834,
     470,   537,   471,   961,   472,   539,   473,   548,   474,   552,
     475,   558,   476,   549,   477,   855,   461,  1058,   462,  1062,
     463,  1066,   464,  1070,   465,  1074,   466,  1078,   467,  1082,
     468,  1086,   469,   560,   470,   566,   471,   570,   472,   567,
     473,  1037,   474,  1059,   475,  1063,   476,  1067,   477,  1071,
     571,  1075,   572,  1079,   573,  1083,   574,  1087,  1460,  1461,
    1465,  1466,  1470,  1471,  1475,  1476,  1524,  1525,  1568,  1569,
    1584,  1585,  1591,  1592,   575,  1302,  1600,  1601,  1605,  1606,
    1621,  1622,  1628,  1629,  1019,   577,   576,   578,   580,   579,
     581,   584,   587,   607,   591,   592,   593,   594,   595,   628,
     600,  1305,  1306,  1020,  1022,   601,   606,   634,   610,   627,
     609,   620,   632,   636,   671,   638,  1093,   648,   670,   611,
     673,   674,   672,   675,   676,   678,   697,  1597,   679,   680,
     681,   687,   689,   699,   702,   704,   705,   706,   707,   709,
     714,   708,   711,   779,   780,   781,   782,   788,   784,   789,
     783,   790,   802,  1613,   806,   810,   817,   814,   818,   821,
     819,   820,   816,   860,   857,   823,   859,   866,  1388,   941,
     868,   904,   905,   906,   856,   907,   908,   909,   910,   944,
     945,   946,   947,   948,   949,   955,   950,   951,   952,   953,
     954,   957,   963,   966,   964,   965,   968,  1646,  1654,   967,
     969,   971,   970,   972,   993,   973,   974,   980,   981,   982,
     983,   986,   979,   987,   988,   989,  1155,   990,   991,   992,
     994,   995,   996,   999,  1000,  1001,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1156,  1157,  1038,   162,  1112,
     163,  1047,   164,  1089,   165,  1056,   166,  1039,   167,  1203,
     168,   162,   169,   163,   170,   164,   171,   165,   172,   166,
     173,   167,   174,   168,   175,   169,   176,   170,   177,   171,
     178,   172,   179,   173,   180,   174,   181,   175,   182,   176,
     183,   177,   184,   178,   185,   179,   186,   180,   187,   181,
     188,   182,  1060,   183,  1064,   184,  1068,   185,  1231,   186,
    1072,   187,  1076,   188,  1080,  1084,  1088,  1090,  1094,  1095,
    1096,  1097,  1098,  1103,  1099,  1100,  1113,  1140,  1104,  1105,
    1106,  1107,  1139,  1170,  1108,  1109,  1110,  1111,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1123,  1165,  1166,  1167,   826,
    1169,   827,  1137,   828,  1168,   829,  1171,   830,  1174,   831,
    1176,   832,  1303,   833,   162,   834,   163,  1179,   164,  1172,
     165,  1185,   166,  1186,   167,  1204,   168,  1205,   169,  1209,
     170,  1210,   171,  1181,   172,  1211,   173,  1212,   174,  1213,
     175,  1214,   176,  1215,   177,  1216,   178,  1217,   179,  1218,
     180,  1219,   181,  1221,   182,  1222,   183,  1223,   184,  1227,
     185,  1228,   186,  1244,   187,  1328,   188,   162,  1230,   163,
    1249,   164,  1242,   165,  1250,   166,  1251,   167,  1252,   168,
     602,   169,  1253,   170,  1254,   171,  1255,   172,  1248,   173,
    1256,   174,  1257,   175,  1258,   176,  1259,   177,  1260,   178,
    1277,   179,   826,   180,   827,   181,   828,   182,   829,   183,
     830,   184,   831,   185,   832,   186,   833,   187,   834,   188,
    1278,  1297,  1295,  1298,  1307,  1308,  1268,  1316,  1309,  1310,
    1311,  1317,  1224,  1329,   162,  1342,   163,  1330,   164,  1331,
     165,  1332,   166,  1312,   167,  1333,   168,  1336,   169,   604,
     170,  1343,   171,  1353,   172,  1354,   173,  1357,   174,  1358,
     175,  1361,   176,  1362,   177,  1666,   178,   162,   179,   163,
     180,   164,   181,   165,   182,   166,   183,   167,   184,   168,
     185,   169,   186,   170,   187,   171,   188,   172,  1366,   173,
    1365,   174,  1370,   175,  1369,   176,  1394,   177,  1385,   178,
    1374,   179,   621,   180,  1373,   181,  1395,   182,  1685,   183,
     162,   184,   163,   185,   164,   186,   165,   187,   166,   188,
     167,  1381,   168,  1377,   169,  1396,   170,  1378,   171,  1399,
     172,  1400,   173,  1697,   174,  1405,   175,  1406,   176,  1401,
     177,  1416,   178,  1382,   179,  1417,   180,   623,   181,   162,
     182,   163,   183,   164,   184,   165,   185,   166,   186,   167,
     187,   168,   188,   169,  1418,   170,  1398,   171,  1419,   172,
    1420,   173,  1429,   174,  1421,   175,  1482,   176,  1484,   177,
    1485,   178,  1486,   179,  1489,   180,  1490,   181,   625,   182,
     162,   183,   163,   184,   164,   185,   165,   186,   166,   187,
     167,   188,   168,  1488,   169,  1495,   170,  1496,   171,  1497,
     172,  1498,   173,  1499,   174,  1491,   175,  1579,   176,   786,
     177,  1504,   178,  1522,   179,  1523,   180,  1527,   181,  1529,
     182,  1530,   183,  1531,   184,  1534,   185,  1535,   186,  1538,
     187,  1536,   188,  1541,  1542,  1543,  1544,  1533,  1555,  1564,
    1567,  1581,  1580,  1582,  1583,  1587,  1589,  1590,   887,  1615,
    1616,  1617,  1618,  1620,  1659,  1660,  1619,  1661,  1662,  1626,
    1657,  1663,  1665,  1664,  1668,  1669,  1670,  1671,  1672,  1673,
    1684,  1674,  1675,  1676,  1689,  1677,  1698,  1678,  1679,  1686,
    1687,  1688,  1692,  1693,  1694,  1695,  1699,  1700,  1487,   538,
    1397,  1532,   395,   396,  1614,  1537,  1149,  1245,  1150,  1153,
    1645,  1578,  1655,  1656,  1639,   652,     0,     0,     0,     0,
       0,     0,     0,  1154,     0,     0,     0,     0,     0,     0,
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
    1638
};

static const yytype_int16 yycheck[] =
{
     101,   313,   573,   244,   586,   246,   917,   248,   749,   250,
       8,   252,   875,   254,    29,   256,   875,   258,    14,   260,
     309,   310,   244,   244,   246,   246,   248,   248,   250,   250,
     252,   252,   254,   254,   256,   256,   258,   258,   260,   260,
     903,   320,   321,    11,    12,    11,    12,     6,     7,    11,
      12,    11,    12,    11,    12,  1390,    43,   179,    18,    19,
     113,    23,    11,    12,   987,   988,   989,   990,   991,   992,
      11,    12,   113,    22,     4,    12,   134,   135,    11,    12,
       0,    22,   204,   113,   310,   113,   138,   139,   114,    22,
      15,     4,    11,    12,   132,   133,   205,   162,   163,    44,
      45,    20,    21,   312,   205,   170,   169,    28,   679,   680,
      31,    47,    33,    34,    11,    12,  1451,   132,   133,   311,
       8,   313,    24,    25,    26,    27,    28,     8,    30,   167,
     168,   316,   249,   318,  1056,     6,   132,   133,  1060,    11,
      12,  1476,  1064,   201,    11,    12,  1068,   199,  1007,   241,
    1072,   243,   167,   168,  1076,    41,    42,    16,  1080,     8,
     253,     8,  1084,     6,   257,    77,   134,   135,   261,    11,
      12,   167,   168,     8,   142,   143,   435,   436,   437,   438,
       6,   206,   207,    78,    79,   286,   287,   288,   289,   290,
     291,   244,   122,   294,   295,   296,   297,   298,   299,   488,
     301,   490,  1125,   244,  1127,   494,   307,   144,   145,   122,
    1133,   132,   133,   502,   244,   504,   244,   506,   789,   245,
     509,    11,    12,   512,     8,   174,    12,   516,   194,   195,
     132,   133,    11,    12,   251,   201,   177,   199,   171,   199,
       6,   199,    12,   203,     8,   203,   167,   168,   150,   151,
      24,    25,    26,    27,    28,    11,    12,    12,    32,    11,
      12,    11,    12,   200,   201,   167,   168,    35,    36,    46,
      38,    39,    11,    12,    11,    12,   255,    35,    36,    37,
     201,  1187,     8,  1189,   377,  1191,   379,  1193,   381,  1195,
     383,  1197,   385,  1199,   387,  1201,   389,  1220,   391,   201,
     393,     8,   395,   396,   397,     8,   399,     8,   401,    40,
     403,     8,   405,   182,   407,     3,   409,    78,   134,   135,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
       8,   432,   433,   434,   435,    11,    12,   438,   439,    11,
      12,   442,   252,   253,   160,   161,     6,   448,   449,   450,
      11,    12,     6,   642,    11,    12,   457,     6,   132,   133,
     256,   257,  1273,    78,   132,   133,    17,   656,    11,    12,
      83,   660,   259,   662,   132,   133,   192,   193,    11,    12,
      11,    12,   953,   954,    11,    12,   260,   261,    11,    12,
     181,   492,   314,   167,   168,    11,    12,    11,    12,   167,
     168,     8,  1143,     8,  1267,   211,   138,   139,   253,   167,
     168,     6,   257,   514,     8,   221,   261,   223,     8,   225,
       8,   227,     8,   229,     8,   231,   315,   233,     8,   235,
       6,   237,   132,   133,   134,   135,  1347,   435,   436,   437,
     438,   247,   253,    11,    12,   180,   257,    11,    12,    12,
     261,    11,    12,   194,   195,   696,    11,    12,    11,    12,
     160,   161,   164,   165,    11,    12,   434,   167,   168,    12,
     432,   200,   201,     3,   696,   696,   435,   436,   437,   438,
     210,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,   791,   792,    11,    12,     3,   608,    48,    49,
       3,    51,   613,    53,     8,    55,     8,    57,   354,    59,
    1431,    61,     8,    63,     6,    65,    11,    12,    11,    12,
     819,   820,   377,   411,   379,   413,   381,   415,   383,   417,
     385,   419,   387,   421,   389,   423,   391,   425,   393,   427,
     395,    80,   397,   398,   399,    81,   401,   250,   403,     8,
     405,     6,   407,   317,   409,   666,   377,   924,   379,   926,
     381,   928,   383,   930,   385,   932,   387,   934,   389,   936,
     391,   938,   393,     8,   395,    50,   397,    56,   399,    52,
     401,   903,   403,   924,   405,   926,   407,   928,   409,   930,
       8,   932,    58,   934,     8,   936,     8,   938,    11,    12,
      11,    12,   212,   213,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,     8,  1207,    11,    12,    11,    12,
      11,    12,    11,    12,   875,     8,    60,     8,     3,    62,
      73,    75,   208,   342,     8,     8,     8,     6,     6,   366,
     332,  1222,  1223,   875,   875,   334,   340,   199,   348,   364,
     346,   356,   372,   199,   376,   199,   945,   430,   374,   350,
       3,     3,   370,     8,   133,    84,    54,  1540,     8,     8,
       8,     6,     8,    71,     6,     6,     6,     6,     6,    64,
      66,     8,   123,     8,     8,   324,   326,     8,   330,     8,
     328,   368,     8,  1566,     8,     8,   410,   378,     3,   386,
      12,    12,   408,     3,     8,   390,    12,     6,  1300,   166,
       8,     8,     8,     8,   404,     8,     8,     8,     8,   209,
       3,     8,     8,     8,     8,   344,     8,     8,     8,     8,
       8,     6,   406,     3,     8,     8,   254,  1610,  1611,     6,
       6,     6,   258,   262,   855,   380,     8,   392,   394,    12,
     400,    12,   388,    12,    12,    12,  1007,    12,    12,    12,
       8,     8,   273,     8,     8,     8,   254,     8,     8,     8,
       8,     8,     8,     3,     8,  1007,  1007,     6,   323,   382,
     325,    12,   327,     8,   329,    12,   331,   121,   333,  1088,
     335,   323,   337,   325,   339,   327,   341,   329,   343,   331,
     345,   333,   347,   335,   349,   337,   351,   339,   353,   341,
     355,   343,   357,   345,   359,   347,   361,   349,   363,   351,
     365,   353,   367,   355,   369,   357,   371,   359,   373,   361,
     375,   363,    12,   365,    12,   367,    12,   369,  1137,   371,
      12,   373,    12,   375,    12,    12,    12,    12,     6,     6,
       6,     6,     6,   352,     6,     6,   384,   265,     8,     8,
       6,     6,    82,    72,     8,     8,     8,     8,   258,     8,
       8,     8,     6,     6,     6,   986,     6,     6,     6,   411,
       6,   413,   993,   415,     8,   417,     8,   419,    74,   421,
     113,   423,   424,   425,   323,   427,   325,    76,   327,   202,
     329,     3,   331,     8,   333,     6,   335,   215,   337,     8,
     339,     8,   341,   239,   343,     8,   345,     8,   347,     8,
     349,     8,   351,     8,   353,     8,   355,     8,   357,     8,
     359,     8,   361,   418,   363,     8,   365,     8,   367,   416,
     369,   412,   371,    12,   373,  1244,   375,   323,   422,   325,
       8,   327,   269,   329,     6,   331,     6,   333,     6,   335,
     336,   337,     8,   339,     8,   341,     8,   343,   262,   345,
       8,   347,     8,   349,     8,   351,     8,   353,     8,   355,
       8,   357,   411,   359,   413,   361,   415,   363,   417,   365,
     419,   367,   421,   369,   423,   371,   425,   373,   427,   375,
       6,     8,   248,   217,   428,   420,   241,     8,   414,   426,
     402,     8,  1123,     6,   323,   222,   325,     8,   327,     8,
     329,     8,   331,   274,   333,     6,   335,    12,   337,   338,
     339,   243,   341,     8,   343,   243,   345,   226,   347,   243,
     349,   228,   351,   243,   353,  1626,   355,   323,   357,   325,
     359,   327,   361,   329,   363,   331,   365,   333,   367,   335,
     369,   337,   371,   339,   373,   341,   375,   343,   243,   345,
     234,   347,   243,   349,   236,   351,     8,   353,   238,   355,
     243,   357,   358,   359,   232,   361,     8,   363,  1669,   365,
     323,   367,   325,   369,   327,   371,   329,   373,   331,   375,
     333,   224,   335,   230,   337,   274,   339,   243,   341,     6,
     343,     6,   345,  1694,   347,     8,   349,     8,   351,   266,
     353,   319,   355,   243,   357,     8,   359,   360,   361,   323,
     363,   325,   365,   327,   367,   329,   369,   331,   371,   333,
     373,   335,   375,   337,     8,   339,   271,   341,   122,   343,
       6,   345,   240,   347,     8,   349,   199,   351,     8,   353,
       8,   355,   266,   357,     6,   359,     6,   361,   362,   363,
     323,   365,   325,   367,   327,   369,   329,   371,   331,   373,
     333,   375,   335,   263,   337,     8,   339,     8,   341,   114,
     343,     6,   345,   121,   347,   270,   349,  1519,   351,   352,
     353,   242,   355,   216,   357,     8,   359,   199,   361,     8,
     363,     8,   365,   270,   367,     6,   369,     6,   371,   113,
     373,     8,   375,   244,   244,   244,   113,   267,   244,   113,
     244,     6,   218,   272,     8,   199,     8,     8,   201,     8,
       8,     8,     6,     8,   214,     6,   264,     6,     8,    12,
      12,     6,   122,   268,     8,     8,   114,   114,     6,     3,
       6,   114,     4,     8,   203,     8,     6,     8,   114,   114,
       8,   114,     8,     8,     8,    12,     8,   246,  1402,   328,
    1313,  1492,   254,   254,  1569,  1499,  1007,  1143,  1007,  1007,
    1610,  1519,  1611,  1611,  1606,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,    -1,    -1,
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
    1601
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    43,   440,   444,   445,     0,   310,   977,   978,    15,
     446,   205,   457,   458,   312,   979,     8,   447,    47,   464,
     465,   169,   459,   658,     8,   980,     6,    44,    45,   448,
     449,   249,   554,   555,    16,   466,   659,     8,    11,    12,
     460,   461,   462,     6,   311,   313,   981,   982,     8,   451,
      77,   601,   602,    11,    12,   556,   557,   558,     8,    11,
      12,   467,   468,   469,     6,   463,     8,   983,   984,    12,
      11,    12,    18,    19,   199,   203,   450,   452,   453,   454,
     455,   456,    41,    42,   441,    11,    12,   603,   604,   605,
     251,   559,   560,     6,   470,     8,   206,   207,   713,   714,
      12,    12,   138,   139,   199,   939,   959,   960,   961,   985,
      46,     8,     8,     8,     8,    40,   442,   443,    78,    79,
     606,   607,   650,   651,   255,   573,   574,   182,   561,   660,
       8,    48,    49,    51,    53,    55,    57,    59,    61,    63,
      65,   471,   472,   473,   478,   479,   484,   485,   499,   500,
     506,   507,   512,   513,   518,   519,   524,   525,   539,   540,
     715,   716,   323,   325,   327,   329,   331,   333,   335,   337,
     339,   341,   343,   345,   347,   349,   351,   353,   355,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   986,
     987,   990,   993,   995,   997,   999,  1001,  1003,  1005,  1007,
    1009,  1011,  1013,  1015,  1017,  1018,  1020,  1022,  1024,  1026,
    1028,  1030,  1031,  1037,  1045,  1048,  1051,  1054,  1057,     3,
       8,     6,     6,     6,   680,   682,    78,    17,   608,    78,
      83,   259,   587,   588,   181,   575,   661,     8,    11,    12,
     562,   563,   564,   474,   475,   480,   481,   486,   487,   501,
     502,   508,   509,   514,   515,   520,   521,   526,   527,   541,
     542,    11,    12,   718,   719,   720,   132,   133,   134,   135,
     160,   161,   167,   168,   717,   926,   928,   953,   954,   955,
     962,   963,   964,   965,   966,   967,  1004,   996,   998,  1002,
    1006,  1008,  1046,  1058,  1016,  1000,  1023,  1010,  1012,  1014,
    1038,  1021,  1052,  1049,  1055,   988,   991,   994,  1025,  1027,
    1029,   314,   986,  1033,     8,     6,     8,     8,     8,     8,
       6,     7,   435,   436,   437,   438,   683,     8,   609,   610,
     611,   653,   315,  1130,  1131,   180,   589,   662,     8,    11,
      12,   576,   577,   578,     6,   566,    11,    12,   477,   476,
     926,   928,   953,    11,    12,   483,   482,   926,   928,   953,
      11,    12,   489,   488,   926,   928,   953,    11,    12,   505,
      29,   503,   504,   926,   928,   953,    11,    12,   511,    35,
      36,    37,   510,   663,   664,   665,   926,   928,   953,    11,
      12,   517,    38,    39,   516,   663,   664,   666,   667,   926,
     928,   953,    11,    12,   523,    14,   522,   668,   926,   928,
     953,    12,   529,   528,   926,   928,   953,    12,   544,   543,
     926,   928,   953,   210,   721,   722,   723,     3,     3,     3,
       8,     8,   986,   986,   986,   986,   986,   986,  1047,  1059,
     986,   986,   986,   986,   986,   986,  1041,   986,  1053,  1050,
    1056,    11,    12,   989,    11,    12,   992,   986,   253,   257,
     261,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,   399,   401,   403,   405,   407,   409,  1060,  1061,
    1062,  1067,  1068,  1071,  1072,  1075,  1076,  1079,  1080,  1082,
    1083,  1085,  1086,  1088,  1089,  1091,  1092,  1095,  1096,  1100,
    1101,  1103,  1104,  1106,  1107,  1109,  1110,  1112,  1115,  1116,
    1118,  1121,  1122,  1124,  1125,  1127,  1128,  1060,  1060,   354,
    1019,    11,    12,   142,   143,   434,   965,   968,   969,   970,
    1032,  1034,  1035,     8,   682,   682,     6,    80,   610,    81,
      11,    12,    20,    21,   652,   654,   656,   657,   250,   317,
    1132,  1133,     8,    11,    12,   590,   591,   592,     6,   580,
       8,   252,   253,   565,   567,   568,    50,    52,   490,   491,
      56,     8,    58,     8,     8,     8,    60,     8,     8,    62,
       3,    73,   530,   531,    75,   545,   546,   208,   728,   724,
     725,     8,     8,     8,     6,     6,   986,   986,   986,   986,
     332,   334,   336,   986,   338,   986,   340,   342,   986,   346,
     348,   350,    11,    12,   199,   203,  1039,  1042,  1043,  1044,
     356,   358,   986,   360,   986,   362,   986,   364,   366,   986,
    1113,  1119,   372,  1063,   199,  1070,   199,  1074,   199,  1078,
    1060,  1081,  1060,  1084,   986,  1087,  1060,  1090,   430,  1093,
    1099,  1097,  1099,    11,    12,  1102,  1060,  1105,  1060,  1108,
    1060,  1111,  1060,  1117,  1060,  1123,   986,  1126,  1060,  1129,
     374,   376,   370,     3,     3,     8,   133,   612,    84,     8,
       8,     8,    11,    12,  1134,  1135,  1136,     6,   594,     8,
     256,   257,   579,   581,   582,   569,   570,    54,   498,    71,
     492,   493,     6,   680,     6,     6,     6,     6,     8,    64,
     538,   123,   532,   927,    66,   553,   547,   927,   211,   221,
     223,   225,   227,   229,   231,   233,   235,   237,   247,   729,
     730,   731,   755,   756,   768,   769,   795,   796,   813,   814,
     831,   832,   844,   845,   862,   863,   880,   881,   893,   894,
     897,   898,    11,    12,   727,   164,   165,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   726,   932,   933,   934,
     935,   936,   942,   943,   948,   949,   950,   951,   952,     8,
       8,   324,   326,   328,   330,   986,   352,   986,     8,     8,
     368,  1114,  1120,    11,    12,    23,   199,   432,   669,  1064,
    1065,  1066,     8,    11,    12,  1069,     8,    11,    12,  1073,
       8,    11,    12,  1077,   378,  1060,   408,   410,     3,    12,
      12,   386,  1060,   390,  1060,  1060,   411,   413,   415,   417,
     419,   421,   423,   425,   427,   986,  1143,  1144,  1145,  1146,
    1151,  1152,  1154,  1155,  1157,  1160,  1161,  1163,  1164,  1166,
    1167,  1169,  1170,  1172,  1173,   986,   404,     8,  1036,    12,
       3,    11,    12,   613,   680,   680,     6,  1137,     8,   260,
     261,   593,   595,   596,   583,   584,    11,    12,   572,    24,
      25,    26,    27,    28,    30,   150,   151,   201,   571,   670,
     671,   673,   674,   677,   678,   926,   928,   941,   953,   974,
     975,   976,   494,   495,     8,     8,     8,     8,     8,     8,
       8,    11,    12,   533,   534,   535,    11,    12,   548,   549,
     550,   732,   733,   757,   758,   770,   771,   797,   798,   815,
     816,   833,   834,   846,   847,   864,   865,   882,   883,   895,
     959,   166,   899,   925,   209,     3,     8,     8,     8,     8,
       8,     8,     8,     8,     8,   344,  1040,     6,   680,   396,
    1060,   398,  1060,   406,     8,     8,     3,     6,   254,     6,
     258,     6,   262,   380,     8,  1060,  1094,  1060,  1098,   388,
     392,   394,    12,   400,  1148,  1149,    12,    12,    12,    12,
      12,    12,    12,   986,     8,     8,   273,   614,   615,     8,
       8,     8,   316,   318,  1138,  1139,   597,   598,    11,    12,
     586,    31,    33,    34,   585,   672,   673,   675,   679,   926,
     928,   941,   953,   254,     8,     8,     8,     8,     8,     8,
       3,     8,    11,    12,   497,   496,   941,   965,     6,   121,
     536,   684,   685,   686,   693,   551,   684,    12,   162,   163,
     170,   734,   929,   956,   957,   958,    12,   759,   929,   956,
      12,   772,   929,   956,    12,   799,   929,   956,    12,   817,
     929,   956,    12,   835,   929,   956,    12,   848,   929,   956,
      12,   866,   929,   956,    12,   884,   929,   956,    12,     8,
      12,   900,   681,   682,     6,     6,     6,     6,     6,     6,
       6,   680,   680,   352,     8,     8,     6,     6,     8,     8,
       8,     8,   382,   384,  1158,    11,    12,  1147,   194,   195,
     946,   947,  1150,   986,  1153,  1143,  1156,  1143,  1162,  1143,
    1165,  1143,  1168,  1143,  1171,  1143,  1174,   986,   616,    82,
     265,   627,  1140,  1141,    11,    12,   600,    32,   599,   670,
     671,   673,   676,   677,   678,   926,   928,   953,   258,     8,
       8,     8,     6,     6,     6,     6,     6,     6,     8,     6,
      72,     8,   202,   931,    74,   537,   113,   687,   688,    76,
     552,   239,   735,   737,   738,     3,     8,   737,   760,   737,
     773,   737,   800,   737,   818,   737,   836,   737,   849,   737,
     867,   737,   885,  1060,     6,   215,   902,   903,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
    1159,   418,     8,     8,   986,  1143,  1143,   416,   412,  1143,
     422,  1060,    11,    12,    22,   177,   617,   618,   619,   620,
     621,   628,   269,   639,    12,   939,   959,  1142,   262,     8,
       6,     6,     6,     8,     8,     8,     8,     8,     8,     8,
       8,    11,    12,   694,   695,   696,   689,   690,   241,   736,
     743,   744,    11,    12,   739,   740,   741,     8,     6,   743,
     761,   743,   774,   743,   801,   743,   819,   743,   837,   743,
     850,   743,   868,   743,   886,   248,   896,     8,   217,   909,
     910,   904,   927,   424,  1143,   680,   680,   428,   420,   414,
     426,   402,   274,   622,   623,   624,     8,     8,    11,    12,
      22,   171,   629,   630,   631,   632,   633,   640,  1060,     6,
       8,     8,     8,     6,     4,   122,    12,   692,   200,   691,
     940,   941,   222,   243,   749,   750,    11,    12,   745,   746,
     747,   684,   742,     8,   243,   762,   763,   226,   243,   775,
     776,   228,   243,   802,   803,   234,   243,   820,   821,   236,
     243,   838,   839,   232,   243,   851,   852,   230,   243,   869,
     870,   224,   243,   887,   888,   238,   916,   911,   927,    11,
      12,   905,   906,   907,     8,     8,   274,   623,   271,     6,
       6,   266,   634,   635,   636,     8,     8,    11,    12,    22,
     174,   641,   642,   643,   644,   655,   319,     8,     8,   122,
       6,     8,    11,    12,   751,   752,   753,   684,   748,   240,
      11,    12,   764,   765,   766,    11,    12,   777,   778,   779,
      11,    12,   804,   805,   806,    11,    12,   822,   823,   824,
      11,    12,   840,   841,   842,    11,    12,   853,   854,   855,
      11,    12,   871,   872,   873,    11,    12,   889,   890,   891,
     212,   213,   901,   917,   918,    11,    12,   912,   913,   914,
     685,   908,   199,   625,     8,     8,   266,   635,   263,     6,
       6,   270,   645,   646,   647,     8,     8,   114,     6,   121,
     697,   698,   703,   754,   242,   684,   767,   780,   781,   807,
     825,   685,   843,   856,   874,   707,   708,   892,   919,   920,
     685,   915,   216,     8,    11,    12,   626,   199,   637,     8,
       8,   270,   646,   267,     6,     6,     8,   931,   113,   699,
     700,   244,   244,   244,   113,   782,   783,   113,   244,   808,
     809,   113,   244,   826,   827,   244,   113,   244,   857,   858,
     113,   244,   875,   876,   113,   709,   710,   244,    11,    12,
     922,   923,   924,   192,   193,   921,   937,   938,   962,   965,
     218,     6,   272,     8,    11,    12,   638,   199,   648,     8,
       8,    11,    12,   704,   705,   706,   701,   941,   784,   785,
      11,    12,   810,   811,   812,    11,    12,   828,   829,   830,
     859,   877,   711,   941,   721,     8,     8,     8,     6,   264,
       8,    11,    12,   649,     4,   122,    12,   702,    11,    12,
     787,   788,   789,   179,   204,   786,   930,   945,   986,  1144,
      12,   144,   145,   860,   861,   940,   941,   971,   972,   973,
      11,    12,   878,   879,   941,   946,   947,    12,   712,   214,
       6,     6,     8,     6,   268,   122,   680,   790,     8,     8,
     114,   114,     6,     3,   114,     4,     8,     8,     8,   114,
     114,   245,   791,   792,     6,   680,   114,     8,   114,   203,
     793,   944,     8,     8,     8,    12,   794,   680,     6,     8,
     246
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   439,   440,   441,   441,   442,   443,   443,   444,   444,
     445,   446,   447,   447,   448,   449,   450,   450,   451,   451,
     452,   452,   452,   452,   453,   454,   455,   456,   457,   457,
     458,   459,   460,   460,   461,   462,   463,   463,   464,   464,
     465,   466,   467,   467,   468,   469,   470,   470,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   472,   473,   474,
     475,   475,   476,   476,   476,   477,   477,   478,   479,   480,
     481,   481,   482,   482,   482,   483,   483,   484,   485,   486,
     487,   487,   488,   488,   488,   489,   489,   490,   491,   491,
     492,   493,   494,   495,   495,   496,   496,   497,   497,   498,
     499,   500,   501,   502,   502,   503,   503,   503,   503,   504,
     505,   505,   506,   507,   508,   509,   509,   510,   510,   510,
     510,   510,   510,   511,   511,   512,   513,   514,   515,   515,
     516,   516,   516,   516,   516,   516,   516,   517,   517,   518,
     519,   520,   521,   521,   522,   522,   522,   522,   523,   523,
     524,   525,   526,   527,   527,   528,   528,   528,   529,   530,
     531,   532,   533,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   542,   543,   543,   543,   544,   545,   546,
     547,   548,   548,   549,   550,   551,   552,   553,   554,   554,
     555,   556,   556,   557,   558,   559,   559,   560,   561,   562,
     562,   563,   564,   565,   566,   566,   567,   568,   569,   570,
     570,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   572,   572,   573,   573,   574,   575,   576,   576,
     577,   578,   579,   580,   580,   581,   582,   583,   584,   584,
     585,   585,   585,   585,   585,   585,   585,   585,   586,   586,
     587,   587,   588,   589,   590,   590,   591,   592,   593,   594,
     594,   595,   596,   597,   598,   598,   599,   599,   599,   599,
     599,   599,   599,   599,   599,   600,   600,   601,   601,   602,
     603,   603,   604,   604,   605,   605,   606,   607,   608,   609,
     609,   611,   610,   612,   612,   613,   613,   614,   615,   615,
     616,   616,   617,   617,   618,   619,   620,   620,   621,   621,
     622,   622,   624,   623,   625,   626,   626,   627,   627,   628,
     628,   629,   629,   630,   631,   632,   632,   633,   633,   634,
     634,   636,   635,   637,   638,   638,   639,   639,   640,   640,
     641,   641,   642,   643,   643,   644,   644,   645,   645,   647,
     646,   648,   649,   649,   651,   650,   652,   652,   653,   653,
     654,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   680,   681,
     682,   682,   683,   683,   683,   683,   684,   685,   685,   686,
     686,   687,   688,   689,   690,   690,   691,   691,   692,   693,
     694,   694,   695,   695,   696,   697,   697,   698,   698,   699,
     700,   701,   701,   702,   703,   704,   704,   705,   705,   706,
     707,   708,   708,   709,   710,   711,   711,   712,   713,   714,
     715,   716,   716,   717,   717,   717,   717,   717,   718,   718,
     719,   720,   721,   722,   722,   723,   724,   725,   725,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   726,   727,
     727,   728,   728,   729,   729,   729,   729,   729,   729,   729,
     729,   729,   729,   729,   730,   731,   732,   733,   733,   734,
     734,   735,   736,   736,   737,   738,   739,   739,   740,   741,
     742,   743,   743,   744,   745,   745,   746,   747,   748,   749,
     750,   751,   751,   752,   753,   754,   755,   756,   757,   758,
     758,   759,   759,   760,   761,   762,   762,   763,   764,   764,
     765,   766,   767,   768,   769,   770,   771,   771,   772,   772,
     773,   774,   775,   775,   776,   777,   777,   778,   779,   780,
     781,   781,   782,   783,   784,   785,   785,   786,   786,   787,
     787,   788,   789,   790,   790,   791,   792,   793,   793,   794,
     795,   796,   797,   798,   798,   799,   799,   800,   801,   802,
     802,   803,   804,   804,   805,   806,   807,   807,   808,   809,
     810,   810,   811,   812,   813,   814,   815,   816,   816,   817,
     817,   818,   819,   820,   820,   821,   822,   822,   823,   824,
     825,   825,   826,   827,   828,   828,   829,   830,   831,   832,
     833,   834,   834,   835,   835,   836,   837,   838,   838,   839,
     840,   840,   841,   842,   843,   844,   845,   846,   847,   847,
     848,   848,   849,   850,   851,   851,   852,   853,   853,   854,
     855,   856,   856,   857,   858,   859,   859,   860,   860,   860,
     861,   862,   863,   864,   865,   865,   866,   866,   867,   868,
     869,   869,   870,   871,   871,   872,   873,   874,   874,   875,
     876,   877,   877,   878,   878,   878,   879,   879,   880,   881,
     882,   883,   883,   884,   884,   885,   886,   887,   887,   888,
     889,   889,   890,   891,   892,   893,   894,   895,   895,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   905,   905,
     906,   907,   908,   909,   910,   911,   912,   912,   913,   914,
     915,   916,   916,   917,   918,   919,   920,   920,   921,   921,
     921,   921,   922,   922,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   950,   951,   952,   953,   953,   954,   955,   956,
     956,   957,   958,   959,   959,   960,   961,   962,   962,   963,
     964,   965,   965,   966,   967,   968,   968,   969,   970,   971,
     971,   972,   973,   974,   974,   975,   976,   977,   977,   978,
     979,   980,   980,   981,   982,   983,   984,   984,   985,   985,
     986,   986,   986,   986,   986,   986,   986,   986,   986,   986,
     986,   986,   986,   986,   986,   986,   986,   986,   986,   986,
     986,   986,   986,   986,   986,   986,   986,   988,   987,   989,
     989,   991,   990,   992,   992,   994,   993,   996,   995,   998,
     997,  1000,   999,  1002,  1001,  1004,  1003,  1006,  1005,  1008,
    1007,  1010,  1009,  1012,  1011,  1014,  1013,  1016,  1015,  1017,
    1018,  1019,  1021,  1020,  1023,  1022,  1025,  1024,  1027,  1026,
    1029,  1028,  1030,  1031,  1032,  1032,  1033,  1033,  1034,  1034,
    1034,  1036,  1035,  1038,  1037,  1039,  1039,  1040,  1039,  1041,
    1041,  1042,  1042,  1043,  1044,  1046,  1045,  1047,  1047,  1049,
    1048,  1050,  1050,  1052,  1051,  1053,  1053,  1055,  1054,  1056,
    1056,  1058,  1057,  1059,  1059,  1060,  1060,  1060,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1061,  1062,  1063,  1063,  1064,
    1064,  1065,  1065,   669,  1066,  1067,  1068,  1069,  1069,  1070,
    1071,  1072,  1073,  1073,  1074,  1075,  1076,  1077,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1093,  1094,  1095,  1096,  1097,
    1097,  1098,  1099,  1100,  1101,  1102,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1113,  1112,  1114,  1114,
    1115,  1116,  1117,  1119,  1118,  1120,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1130,  1131,  1132,
    1133,  1134,  1134,  1135,  1136,  1137,  1137,  1138,  1139,  1140,
    1141,  1141,  1142,  1142,  1143,  1143,  1144,  1144,  1144,  1144,
    1144,  1144,  1144,  1144,  1144,  1145,  1146,  1147,  1147,  1148,
    1149,  1149,  1150,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1158,  1157,  1159,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       0,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     2,     1,     3,     1,     1,     0,     2,     3,
       1,     0,     1,     3,     3,     1,     1,     2,     1,     3,
       1,     0,     2,     3,     1,     0,     1,     3,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       3,     4,     1,     1,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     3,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     2,     1,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     1,     5,     1,     0,     1,     1,
       3,     1,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     0,     4,     1,
       5,     0,     2,     5,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       1,     1,     0,     4,     0,     6,     0,     4,     0,     4,
       0,     4,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     0,     4,     0,     4,     1,     2,     0,     4,     0,
       2,     1,     1,     4,     4,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       1,     1,     2,     4,     3,     3,     1,     1,     2,     4,
       3,     1,     1,     2,     4,     3,     1,     1,     2,     4,
       2,     1,     2,     2,     1,     3,     2,     1,     2,     2,
       1,     2,     4,     1,     0,     1,     2,     4,     1,     0,
       1,     2,     3,     2,     1,     1,     2,     2,     1,     3,
       2,     1,     2,     2,     1,     3,     0,     4,     0,     2,
       2,     1,     3,     0,     4,     0,     2,     2,     1,     3,
       2,     1,     6,     2,     1,     2,     0,     3,     1,     1,
       4,     1,     1,     1,     3,     0,     2,     5,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     1,
       0,     2,     1,     1,     3,     1,     3,     3,     1,     3,
       0,     5,     0,     2,     3,     1,     3,     3,     1,     2,
       3,     1,     2,     3,     1,     3,     3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, osinstance, parserData, osglData, osnlData); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (osinstance);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData, osglData, osnlData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , osinstance, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, osinstance, parserData, osglData, osnlData); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (OSInstance *osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
    }

    break;

  case 10:

    {
    osinstance->instanceData->quadraticCoefficients = new QuadraticCoefficients();
}

    break;

  case 11:

    { 
if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[-2].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[-2].ival) ];
for(int i = 0; i < (yyvsp[-2].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
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
        throw ErrorClass("encountered more quadratic terms than specified");
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

    {  if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ((yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
}

    break;

  case 25:

    { if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) < 0)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index cannot be negative");
    if ((yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "variable index exceeds number of variables");
}

    break;

  case 26:

    {if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = parserData->tempVal;
}

    break;

  case 27:

    {  if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = (yyvsp[-1].ival);
    if ((yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term exceeds number of constraints");
    if ((yyvsp[-1].ival) < -osinstance->instanceData->objectives->numberOfObjectives)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "row index for quadratic term refers to nonexisting objective");
}

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
std::cout << "Start nonnegative cone" << std::endl;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonnegativeCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_nonnegative;    
}

    break;

  case 59:

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
}

    break;

  case 62:

    {
std::cout << "Number of rows attribute" << std::endl;
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = osglData->numberOfRows;
        }

    break;

  case 63:

    {
std::cout << "Number of columns attribute" << std::endl;
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

  case 69:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
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
    else
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
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_polyhedral;    
}

    break;

  case 102:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->referenceMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "polyhedral cone referenceMatrixIdx attribute previously set");
    parserData->referenceMatrixIdxPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "polyhedral cone reference matrix index cannot be negative");
    else parserData->referenceMatrixIdx = (yyvsp[-1].ival); 
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

  case 114:

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

  case 127:

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
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType
        = ENUM_CONE_TYPE_semidefinite;    
}

    break;

  case 141:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
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

  case 152:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
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

  case 166:

    {
    // factors must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "product cone factor has illegal index");
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

  case 171:

    {
    if (!osglData->numberOfRowsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfRows is missing");
    if (!osglData->numberOfColumnsPresent)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "mandatory attribute numberOfColumns is missing");
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

  case 185:

    {
    // components must appear earlier in the list of cones to rule out circular references
    for (int i=0; i < osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] >= parserData->coneCounter) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                    "intersection cone component has illegal index");
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
    if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-2].ival) < 1) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of stages must be positive");
    osinstance->instanceData->timeDomain->stages->numberOfStages = (yyvsp[-2].ival);
    if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
        osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ (yyvsp[-2].ival) ];
    for(int i = 0; i < (yyvsp[-2].ival); i++) 
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
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[-1].sval); free((yyvsp[-1].sval));}

    break;

  case 299:

    {
        parserData->stageVariablesON = true;
        }

    break;

  case 304:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of variables cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfVariables");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var = new TimeDomainStageVar*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
        }
    };
}

    break;

  case 305:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) < 0 && (yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[-1].ival);
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[-1].ival);
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of constraints cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfConstraints");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con = new TimeDomainStageCon*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
        {    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
            osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
        }
    };
}

    break;

  case 324:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) < 0 && (yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[-1].ival);
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[-1].ival);
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of objectives cannot be negative");
    if ((yyvsp[-1].ival) > osinstance->instanceData->objectives->numberOfObjectives)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");         
    if ((yyvsp[-1].ival) > 0) {
        if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute numberOfObjectives");
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = (yyvsp[-1].ival);
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = new TimeDomainStageObj*[ (yyvsp[-1].ival) ];
        for (int i = 0; i < (yyvsp[-1].ival); i++) 
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) >= 0 || (yyvsp[-1].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[-1].ival);
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[-1].ival) >= 0 || (yyvsp[-1].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[-1].ival);
}

    break;

  case 363:

    {
        if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}

    break;

  case 364:

    {
        if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}

    break;

  case 365:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (osglData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    osglData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = (yyvsp[-1].ival);
}

    break;

  case 366:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfConesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <cone> elements cannot be negative");
    parserData->numberOfConesPresent = true;
    parserData->numberOfCones = (yyvsp[-1].ival); 
}

    break;

  case 367:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[-1].ival); 
}

    break;

  case 368:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[-1].ival); 
}

    break;

  case 369:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[-1].ival); 
}

    break;

  case 370:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
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
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->distortionMatrixPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortionMatrixIdx attribute previously set");
    parserData->distortionMatrixPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "distortion matrix index cannot be negative");
    else parserData->distortionMatrix = (yyvsp[-1].ival); 
}

    break;

  case 372:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->axisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "axisDirection attribute previously set");
    parserData->axisDirectionPresent = true;
    parserData->axisDirection = (yyvsp[-1].ival);
std::cout << "found axis direction = " << parserData->axisDirection << std::endl;
}

    break;

  case 373:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,     
            "mismatched quotes");
    if (parserData->firstAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "firstAxisDirection attribute previously set");
    parserData->firstAxisDirectionPresent = true;
    parserData->firstAxisDirection = (yyvsp[-1].ival); 
std::cout << "found first axis direction = " << parserData->firstAxisDirection << std::endl;
}

    break;

  case 374:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->secondAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "secondAxisDirection attribute previously set");
    parserData->secondAxisDirectionPresent = true;
    parserData->secondAxisDirection = (yyvsp[-1].ival); 
std::cout << "found second axis direction = " << parserData->secondAxisDirection << std::endl;
}

    break;

  case 375:

    {
    if (parserData->semidefinitenessPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->semidefinitenessPresent = true;
    parserData->semidefiniteness = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
    if (parserData->semidefiniteness != "positive" && parserData->semidefiniteness != "negative")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "semidefiniteness must be either \"positive\" or \"negative\"");
}

    break;

  case 376:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mismatched quotes");
    if (parserData->matrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrixIdx attribute previously set");
    parserData->matrixIdxPresent = true;
    if ((yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index exceeds number of matrices");
    else if ((yyvsp[-1].ival) < 0) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "matrix index cannot be negative");
    else parserData->matrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 377:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbMatrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbMatrix attribute");
    parserData->lbMatrixIdxPresent = true;
    parserData->lbMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 378:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubMatrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubMatrix attribute");
    parserData->ubMatrixIdxPresent = true;
    parserData->ubMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 379:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->constantMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one constant matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for constant matrix attribute");
    parserData->constantMatrixIdxPresent = true;
    parserData->constantMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 380:

    {
    if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for template matrix index");
    parserData->templateMatrixIdxPresent = true;
    parserData->templateMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 381:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->varReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one varReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for varReference matrix attribute");
    parserData->varReferenceMatrixIdxPresent = true;
    parserData->varReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 382:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->objReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one objReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for objReference matrix attribute");
    parserData->objReferenceMatrixIdxPresent = true;
    parserData->objReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 383:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->conReferenceMatrixIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one conReference matrix attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->matrices->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for conReference matrix attribute");
    parserData->conReferenceMatrixIdxPresent = true;
    parserData->conReferenceMatrixIdx = (yyvsp[-1].ival);
}

    break;

  case 384:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->lbConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one lbCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for lbCone attribute");
    parserData->lbConeIdxPresent = true;
    parserData->lbConeIdx = (yyvsp[-1].ival);
}

    break;

  case 385:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->ubConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one ubCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for ubCone attribute");
    parserData->ubConeIdxPresent = true;
    parserData->ubConeIdx = (yyvsp[-1].ival);
}

    break;

  case 386:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (parserData->orderConeIdxPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one orderCone attribute allowed");
    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= osinstance->instanceData->cones->numberOfCones)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "illegal value for orderCone attribute");
    parserData->orderConeIdxPresent = true;
    parserData->orderConeIdx = (yyvsp[-1].ival);
}

    break;

  case 387:

    {parserData->tempVal = (yyvsp[-1].ival);}

    break;

  case 388:

    {parserData->tempVal = (yyvsp[-1].dval);}

    break;

  case 396:

    {
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray[i] < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
}

    break;

  case 397:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 402:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}

    break;

  case 408:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[-1].ival) + i*osglData->incr;    
}

    break;

  case 414:

    {
    char* b64string = (yyvsp[-1].sval);
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
    free((yyvsp[-1].sval));
}

    break;

  case 415:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 420:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 423:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL DblVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}

    break;

  case 429:

    {
    char* b64string = (yyvsp[-1].sval);
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
    free((yyvsp[-1].sval));
}

    break;

  case 430:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 434:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 437:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));    
}

    break;

  case 438:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}

    break;

  case 439:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        throw ErrorClass("more matrices than specified");
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->symmetryPresent = false;
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

  case 440:

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
    {
//        if (osglData->symmetry == "unknown")
//            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}

    break;

  case 451:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 454:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}

    break;

  case 455:

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
    osglData->scalarImaginaryPartPresent = false;
    osglData->baseMatrixEndRow = -1;
    osglData->baseMatrixEndCol = -1;
}

    break;

  case 456:

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
    if (osglData->scalarImaginaryPartPresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarImaginaryPart = osglData->scalarImaginaryPart;
}

    break;

  case 472:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}

    break;

  case 485:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 486:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}

    break;

  case 489:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 490:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 494:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 495:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 499:

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
}

    break;

  case 502:

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
}

    break;

  case 503:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 509:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 510:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 517:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 518:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 521:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 522:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 526:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 527:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 534:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 535:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}

    break;

  case 538:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 539:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 542:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 543:

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

  case 544:

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

  case 552:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}

    break;

  case 553:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}

    break;

  case 554:

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

  case 566:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}

    break;

  case 568:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}

    break;

  case 569:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[-1].ival);
    osglData->osglCounter++;
}

    break;

  case 571:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 572:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 575:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 576:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 579:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 580:

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

  case 581:

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

  case 589:

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

  case 593:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 595:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 596:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 599:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 600:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 603:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 604:

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

  case 605:

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

  case 613:

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

  case 617:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 619:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 620:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 623:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 624:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 628:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 629:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 636:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 637:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 640:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 641:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 644:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 645:

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

  case 646:

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

  case 654:

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

  case 660:

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
                    = (yyvsp[-1].ival) + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}

    break;

  case 662:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 663:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}

    break;

  case 666:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 667:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 670:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 671:

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

  case 672:

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

  case 679:

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

  case 680:

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

  case 689:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 690:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}

    break;

  case 693:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 694:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 698:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 699:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 706:

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

  case 708:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}

    break;

  case 709:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}

    break;

  case 710:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}

    break;

  case 711:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}

    break;

  case 712:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}

    break;

  case 714:

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

  case 715:

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

  case 716:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 717:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 723:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 724:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 725:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 732:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}

    break;

  case 733:

    {
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 734:

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

  case 740:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        if (osglData->symmetry == "none")
            osglData->symmetry =  "unknown";
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }

    break;

  case 741:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }

    break;

  case 745:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}

    break;

  case 746:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[-1].ival);
}

    break;

  case 747:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[-1].ival);
}

    break;

  case 748:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[-1].ival);
}

    break;

  case 749:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[-1].ival);
}

    break;

  case 750:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[-1].ival);
}

    break;

  case 751:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[-1].ival);
}

    break;

  case 752:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[-1].ival);
}

    break;

  case 753:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("baseMatrix idx cannot be negative");
    if ((yyvsp[-1].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 754:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[-1].ival); 
}

    break;

  case 755:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[-1].ival); 
}

    break;

  case 756:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[-1].ival); 
}

    break;

  case 757:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[-1].ival); 
}

    break;

  case 758:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = (yyvsp[-1].ival);
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}

    break;

  case 759:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = (yyvsp[-1].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}

    break;

  case 760:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[-1].ival);
}

    break;

  case 761:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[-1].ival);
}

    break;

  case 762:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[-1].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[-1].ival);
}

    break;

  case 763:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[-1].ival); 
}

    break;

  case 764:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[-1].ival); 
}

    break;

  case 765:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
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

  case 766:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
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

  case 767:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}

    break;

  case 768:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}

    break;

  case 769:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}

    break;

  case 770:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarImaginaryPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier imaginary part attribute in <baseMatrix> element");
    osglData->scalarImaginaryPartPresent = true;   
    osglData->scalarImaginaryPart = parserData->tempVal;
}

    break;

  case 773:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}

    break;

  case 774:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 777:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}

    break;

  case 778:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 781:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}

    break;

  case 782:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 785:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}

    break;

  case 786:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 789:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}

    break;

  case 790:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 793:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}

    break;

  case 794:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 797:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}

    break;

  case 798:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 801:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}

    break;

  case 802:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 805:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}

    break;

  case 806:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 808:

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
    }

    break;

  case 809:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }

    break;

  case 810:

    { 
        if ( *(yyvsp[-3].sval) != *(yyvsp[-1].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "start and end quotes are not the same");
        if ((yyvsp[-2].ival) < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[-2].ival);
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[-2].ival);  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[-2].ival) ];
        for (int i = 0; 
                 i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; 
                 i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[i] = new Nl();
        }
    }

    break;

  case 813:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
            osinstance->instanceData->nonlinearExpressions
                    ->nl[osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
                ((OSnLNode*)
                    osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }

    break;

  case 814:

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

  case 815:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "mandatory attribute idx is missing");    
}

    break;

  case 818:

    {
//        if (osnlData->tmpnlcount < osnlData->nlnodenumber) 
//        {
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
                = new RealValuedExpressionTree();
//        }
    }

    break;

  case 819:

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

  case 847:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 851:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 855:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 857:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 859:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 861:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 863:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 865:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 867:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 869:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 871:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 873:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 875:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 877:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 880:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 881:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 882:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 883:

    {
}

    break;

  case 884:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 885:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 886:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 888:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 890:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 892:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}

    break;

  case 893:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}

    break;

  case 898:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }

    break;

  case 899:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }

    break;

  case 901:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[0].sval);
    free((yyvsp[0].sval));
}

    break;

  case 903:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}

    break;

  case 904:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}

    break;

  case 907:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }

    break;

  case 911:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }

    break;

  case 912:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }

    break;

  case 913:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}

    break;

  case 914:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index cannot be negative");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[-1].ival);
}

    break;

  case 915:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 916:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}

    break;

  case 918:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }

    break;

  case 919:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 920:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 922:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }

    break;

  case 923:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 924:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 926:

    { osnlData->maxVec.back()->inumberOfChildren++; }

    break;

  case 927:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 928:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 930:

    { osnlData->minVec.back()->inumberOfChildren++; }

    break;

  case 931:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 932:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}

    break;

  case 934:

    { osnlData->productVec.back()->inumberOfChildren++; }

    break;

  case 955:

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

  case 956:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}

    break;

  case 963:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[-1].ival);
    osnlData->idxAttributePresent = true;
}

    break;

  case 964:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
    osnlData->transposeAttributePresent = true;
}

    break;

  case 965:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 966:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}

    break;

  case 969:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[-1].ival);
}

    break;

  case 970:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 971:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}

    break;

  case 974:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[-1].ival);
}

    break;

  case 975:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 976:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}

    break;

  case 979:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[-1].ival);
}

    break;

  case 981:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 984:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 987:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 990:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 993:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 995:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 998:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1000:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 1002:

    {
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
}

    break;

  case 1004:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}

    break;

  case 1008:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1011:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1014:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1016:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixSumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1017:

    {
    osnlData->matrixSumVec.back()->m_mChildren 
        = new ExprNode*[ osnlData->matrixSumVec.back()->inumberOfChildren];
    osnlData->matrixSumVec.pop_back();
}

    break;

  case 1019:

    {
    osnlData->matrixSumVec.back()->inumberOfChildren++;
}

    break;

  case 1021:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1023:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1024:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}

    break;

  case 1026:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}

    break;

  case 1028:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1031:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1034:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1037:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }

    break;

  case 1038:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }

    break;

  case 1040:

    {
    #ifdef OSINSTANCE_AVAILABLE
        if (*(yyvsp[-2].sval) != *(yyvsp[0].sval)) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
        if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[-1].ival);
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = (yyvsp[-1].ival);  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr
                = new MatrixExpression*[ (yyvsp[-1].ival) ];
        for (int i = 0; 
                 i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr;
                 i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i]
                = new MatrixExpression();
    #endif
    }

    break;

  case 1047:

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

  case 1048:

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

  case 1049:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}

    break;

  case 1052:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }

    break;

  case 1053:

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

  case 1065:

    {
}

    break;

  case 1066:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}

    break;

  case 1069:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}

    break;

  case 1075:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1078:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1080:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1081:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}

    break;

  case 1083:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}

    break;

  case 1085:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1088:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1091:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1094:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1097:

    {
    osnlData->nlNodePoint = new OSnLCNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, osinstance, parserData, osglData, osnlData, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, osinstance, parserData, osglData, osnlData, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, osinstance, parserData, osglData, osnlData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, osinstance, parserData, osglData, osnlData);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
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


void  yygetOSInstance( const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) {
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
    if(i != 6) {  osilerror_wrapper( ch,osillineno,"incorrect sizeOf attribute in <base64BinaryData> element"); return NULL;}    
    // ch should be pointing to the first character after sizeOf

    // the code here is very similar to the replacement macro GETATTRIBUTETEXT,
    // but this is the only routine that returns NULL instead of false in case of error
    BURNWHITESPACE( ch );
    if( *ch != '=') {  osilerror_wrapper( ch, osillineno, "found an attribute not defined"); return NULL;}
    ch++;
    BURNWHITESPACE( ch );
    if(*ch == '\"'){
        ch++;
        BURNWHITESPACE( ch );
        *p = ch; \
        for( ; *ch != '\"'; ch++);
    }
    else{
        if(*ch == '\'') {
            ch++;
            BURNWHITESPACE( ch );
            *p = ch;
            for( ; *ch != '\''; ch++);
        }
        else {  osilerror_wrapper( ch, osillineno,"missing quote on attribute"); return NULL;}
    }
    numChar = ch - *p;
    attText = new char[numChar + 1];
    for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++);
    attText[ki] = '\0';
    attTextEnd = &attText[ki]; 

    ch++;
    *dataSize = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // since the element must contain b64 data,  this element must end with > 
    // eat the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"<base64BinaryData> element does not have a proper closing >"); return NULL;}
    ch++;
    // we are now pointing start of the data
    const char *b64textstart = ch;
    // eat characters until we get to the </base64BinaryData element
    for(; *ch != '<' && *ch != EOF; ch++);
    const char *b64textend = ch;
    // we should be pointing to </base64BinaryData>
    for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
    if(i != 18) { osilerror_wrapper( ch,osillineno," problem with <base64BinaryData> element"); return NULL;}
    long int b64len = b64textend - b64textstart;
    b64string = new char[ b64len + 1]; 
    for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
    b64string[ki] = '\0';    
    // burn the white space
    BURNWHITESPACE( ch );
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"</base64BinaryData> element does not have a proper closing >"); return NULL;}
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

