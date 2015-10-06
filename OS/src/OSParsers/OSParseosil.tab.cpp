
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
char *parseBase64( const char **p, int *dataSize, int* osillineno);

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
	if( *ch != '=') {  osilerror_wrapper( ch, osillineno, "found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;	\
	if(*ch == '\"'){ \
		ch++; \
	    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
	    *p = ch; \
	    for( ; *ch != '\"'; ch++); \
	}\
	else{\
	    if(*ch == '\'') { \
	    	ch++; \
	        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
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
     ENDOFELEMENT = 265,
     GREATERTHAN = 266,
     EMPTYSEMIDEFINITENESSATT = 267,
     SEMIDEFINITENESSATT = 268,
     NUMBEROFQTERMSATT = 269,
     NUMBEROFCONESATT = 270,
     NUMBEROFSTAGESATT = 271,
     IDXONEATT = 272,
     IDXTWOATT = 273,
     HORIZONATT = 274,
     STARTATT = 275,
     STARTIDXATT = 276,
     MATRIXIDXATT = 277,
     LBMATRIXIDXATT = 278,
     LBCONEIDXATT = 279,
     UBMATRIXIDXATT = 280,
     UBCONEIDXATT = 281,
     TEMPLATEMATRIXIDXATT = 282,
     REFERENCEMATRIXIDXATT = 283,
     VARREFERENCEMATRIXIDXATT = 284,
     OBJREFERENCEMATRIXIDXATT = 285,
     CONREFERENCEMATRIXIDXATT = 286,
     ORDERCONEIDXATT = 287,
     CONSTANTMATRIXIDXATT = 288,
     NORMSCALEFACTORATT = 289,
     DISTORTIONMATRIXIDXATT = 290,
     AXISDIRECTIONATT = 291,
     FIRSTAXISDIRECTIONATT = 292,
     SECONDAXISDIRECTIONATT = 293,
     OSILEND = 294,
     INSTANCEDATAEND = 295,
     INSTANCEDATASTARTEND = 296,
     QUADRATICCOEFFICIENTSSTART = 297,
     QUADRATICCOEFFICIENTSEND = 298,
     QTERMSTART = 299,
     QTERMEND = 300,
     CONESSTART = 301,
     CONESEND = 302,
     NONNEGATIVECONESTART = 303,
     NONNEGATIVECONEEND = 304,
     NONPOSITIVECONESTART = 305,
     NONPOSITIVECONEEND = 306,
     ORTHANTCONESTART = 307,
     ORTHANTCONEEND = 308,
     POLYHEDRALCONESTART = 309,
     POLYHEDRALCONEEND = 310,
     QUADRATICCONESTART = 311,
     QUADRATICCONEEND = 312,
     ROTATEDQUADRATICCONESTART = 313,
     ROTATEDQUADRATICCONEEND = 314,
     SEMIDEFINITECONESTART = 315,
     SEMIDEFINITECONEEND = 316,
     PRODUCTCONESTART = 317,
     PRODUCTCONEEND = 318,
     INTERSECTIONCONESTART = 319,
     INTERSECTIONCONEEND = 320,
     DUALCONESTART = 321,
     DUALCONEEND = 322,
     POLARCONESTART = 323,
     POLARCONEEND = 324,
     DIRECTIONSTART = 325,
     DIRECTIONEND = 326,
     FACTORSSTART = 327,
     FACTORSEND = 328,
     COMPONENTSSTART = 329,
     COMPONENTSEND = 330,
     TIMEDOMAINSTART = 331,
     TIMEDOMAINEND = 332,
     STAGESSTART = 333,
     STAGESEND = 334,
     STAGESTART = 335,
     STAGEEND = 336,
     INTERVALSTART = 337,
     INTERVALEND = 338,
     HEADERSTART = 339,
     HEADEREND = 340,
     FILENAMESTART = 341,
     FILENAMEEND = 342,
     FILENAMEEMPTY = 343,
     FILENAMESTARTANDEND = 344,
     FILESOURCESTART = 345,
     FILESOURCEEND = 346,
     FILESOURCEEMPTY = 347,
     FILESOURCESTARTANDEND = 348,
     FILEDESCRIPTIONSTART = 349,
     FILEDESCRIPTIONEND = 350,
     FILEDESCRIPTIONEMPTY = 351,
     FILEDESCRIPTIONSTARTANDEND = 352,
     FILECREATORSTART = 353,
     FILECREATOREND = 354,
     FILECREATOREMPTY = 355,
     FILECREATORSTARTANDEND = 356,
     FILELICENCESTART = 357,
     FILELICENCEEND = 358,
     FILELICENCEEMPTY = 359,
     FILELICENCESTARTANDEND = 360,
     INDEXESSTART = 361,
     INDEXESEND = 362,
     VALUESSTART = 363,
     VALUESEND = 364,
     NONZEROSSTART = 365,
     NONZEROSEND = 366,
     ELSTART = 367,
     ELEND = 368,
     ENUMERATIONSTART = 369,
     ENUMERATIONEND = 370,
     ITEMEMPTY = 371,
     ITEMSTART = 372,
     ITEMEND = 373,
     ITEMSTARTANDEND = 374,
     BASE64START = 375,
     BASE64END = 376,
     NUMBEROFELATT = 377,
     NUMBEROFENUMERATIONSATT = 378,
     NUMBEROFITEMSATT = 379,
     EMPTYCATEGORYATT = 380,
     CATEGORYATT = 381,
     EMPTYDESCRIPTIONATT = 382,
     DESCRIPTIONATT = 383,
     EMPTYSOLVERATT = 384,
     SOLVERATT = 385,
     EMPTYNAMEATT = 386,
     NAMEATT = 387,
     EMPTYTYPEATT = 388,
     TYPEATT = 389,
     EMPTYENUMTYPEATT = 390,
     ENUMTYPEATT = 391,
     EMPTYSHAPEATT = 392,
     SHAPEATT = 393,
     EMPTYUNITATT = 394,
     UNITATT = 395,
     EMPTYVALUEATT = 396,
     VALUEATT = 397,
     EMPTYVALUETYPEATT = 398,
     VALUETYPEATT = 399,
     EMPTYCONTYPEATT = 400,
     CONTYPEATT = 401,
     EMPTYOBJTYPEATT = 402,
     OBJTYPEATT = 403,
     EMPTYVARTYPEATT = 404,
     VARTYPEATT = 405,
     EMPTYMATRIXCONTYPEATT = 406,
     MATRIXCONTYPEATT = 407,
     EMPTYMATRIXOBJTYPEATT = 408,
     MATRIXOBJTYPEATT = 409,
     EMPTYMATRIXVARTYPEATT = 410,
     MATRIXVARTYPEATT = 411,
     EMPTYMATRIXTYPEATT = 412,
     MATRIXTYPEATT = 413,
     EMPTYSYMMETRYATT = 414,
     SYMMETRYATT = 415,
     EMPTYROWMAJORATT = 416,
     ROWMAJORATT = 417,
     EMPTYBASETRANSPOSEATT = 418,
     BASETRANSPOSEATT = 419,
     NUMBEROFBLOCKSATT = 420,
     NUMBEROFCOLUMNSATT = 421,
     NUMBEROFROWSATT = 422,
     NUMBEROFMATRICESATT = 423,
     NUMBEROFVALUESATT = 424,
     NUMBEROFCONSTRAINTSATT = 425,
     NUMBEROFCONATT = 426,
     NUMBEROFCONIDXATT = 427,
     NUMBEROFOBJECTIVESATT = 428,
     NUMBEROFOBJATT = 429,
     NUMBEROFOBJIDXATT = 430,
     NUMBEROFVARIABLESATT = 431,
     NUMBEROFVARATT = 432,
     NUMBEROFVARIDXATT = 433,
     NUMBEROFMATRIXCONATT = 434,
     NUMBEROFMATRIXOBJATT = 435,
     NUMBEROFMATRIXVARATT = 436,
     BASEMATRIXIDXATT = 437,
     TARGETMATRIXFIRSTROWATT = 438,
     TARGETMATRIXFIRSTCOLATT = 439,
     BASEMATRIXSTARTROWATT = 440,
     BASEMATRIXSTARTCOLATT = 441,
     BASEMATRIXENDROWATT = 442,
     BASEMATRIXENDCOLATT = 443,
     SCALARMULTIPLIERATT = 444,
     BLOCKROWIDXATT = 445,
     BLOCKCOLIDXATT = 446,
     MATRIXVARIDXATT = 447,
     MATRIXOBJIDXATT = 448,
     MATRIXCONIDXATT = 449,
     IDXATT = 450,
     INCRATT = 451,
     MULTATT = 452,
     SIZEOFATT = 453,
     COEFATT = 454,
     CONSTANTATT = 455,
     MATRICESSTART = 456,
     MATRICESEND = 457,
     MATRIXSTART = 458,
     MATRIXEND = 459,
     BASEMATRIXEND = 460,
     BASEMATRIXSTART = 461,
     BLOCKSSTART = 462,
     BLOCKSEND = 463,
     BLOCKSTART = 464,
     BLOCKEND = 465,
     COLOFFSETSTART = 466,
     COLOFFSETEND = 467,
     ROWOFFSETSTART = 468,
     ROWOFFSETEND = 469,
     ELEMENTSSTART = 470,
     ELEMENTSEND = 471,
     CONSTANTELEMENTSSTART = 472,
     CONSTANTELEMENTSEND = 473,
     COMPLEXELEMENTSSTART = 474,
     COMPLEXELEMENTSEND = 475,
     VARREFERENCEELEMENTSSTART = 476,
     VARREFERENCEELEMENTSEND = 477,
     LINEARELEMENTSSTART = 478,
     LINEARELEMENTSEND = 479,
     CONREFERENCEELEMENTSSTART = 480,
     CONREFERENCEELEMENTSEND = 481,
     OBJREFERENCEELEMENTSSTART = 482,
     OBJREFERENCEELEMENTSEND = 483,
     REALVALUEDEXPRESSIONSSTART = 484,
     REALVALUEDEXPRESSIONSSEND = 485,
     COMPLEXVALUEDEXPRESSIONSSTART = 486,
     COMPLEXVALUEDEXPRESSIONSSEND = 487,
     STRINGVALUEDELEMENTSSTART = 488,
     STRINGVALUEDELEMENTSEND = 489,
     STARTVECTORSTART = 490,
     STARTVECTOREND = 491,
     INDEXSTART = 492,
     INDEXEND = 493,
     VALUESTART = 494,
     VALUEEND = 495,
     VARIDXSTART = 496,
     VARIDXEND = 497,
     TRANSFORMATIONSTART = 498,
     TRANSFORMATIONEND = 499,
     MATRIXPROGRAMMINGSTART = 500,
     MATRIXPROGRAMMINGEND = 501,
     MATRIXVARIABLESSTART = 502,
     MATRIXVARIABLESEND = 503,
     MATRIXVARSTART = 504,
     MATRIXVAREND = 505,
     MATRIXOBJECTIVESSTART = 506,
     MATRIXOBJECTIVESEND = 507,
     MATRIXOBJSTART = 508,
     MATRIXOBJEND = 509,
     MATRIXCONSTRAINTSSTART = 510,
     MATRIXCONSTRAINTSEND = 511,
     MATRIXCONSTART = 512,
     MATRIXCONEND = 513,
     CONSTART = 514,
     CONEND = 515,
     CONSTRAINTSSTART = 516,
     CONSTRAINTSEND = 517,
     OBJSTART = 518,
     OBJEND = 519,
     OBJECTIVESSTART = 520,
     OBJECTIVESEND = 521,
     VARSTART = 522,
     VAREND = 523,
     VARIABLESSTART = 524,
     VARIABLESEND = 525,
     GENERALSTART = 526,
     GENERALEND = 527,
     SYSTEMSTART = 528,
     SYSTEMEND = 529,
     SERVICESTART = 530,
     SERVICEEND = 531,
     JOBSTART = 532,
     JOBEND = 533,
     OPTIMIZATIONSTART = 534,
     OPTIMIZATIONEND = 535,
     ATEQUALITYSTART = 536,
     ATEQUALITYEND = 537,
     ATLOWERSTART = 538,
     ATLOWEREND = 539,
     ATUPPERSTART = 540,
     ATUPPEREND = 541,
     BASICSTART = 542,
     BASICEND = 543,
     ISFREESTART = 544,
     ISFREEEND = 545,
     SUPERBASICSTART = 546,
     SUPERBASICEND = 547,
     UNKNOWNSTART = 548,
     UNKNOWNEND = 549,
     SERVICEURISTART = 550,
     SERVICEURIEND = 551,
     SERVICENAMESTART = 552,
     SERVICENAMEEND = 553,
     INSTANCENAMESTART = 554,
     INSTANCENAMEEND = 555,
     JOBIDSTART = 556,
     JOBIDEND = 557,
     OTHERSTART = 558,
     OTHEREND = 559,
     DUMMY = 560,
     NONLINEAREXPRESSIONSSTART = 561,
     NONLINEAREXPRESSIONSEND = 562,
     NUMBEROFNONLINEAREXPRESSIONS = 563,
     NLSTART = 564,
     NLEND = 565,
     MATRIXEXPRESSIONSSTART = 566,
     MATRIXEXPRESSIONSEND = 567,
     NUMBEROFEXPR = 568,
     EXPRSTART = 569,
     EXPREND = 570,
     NUMBEROFMATRIXTERMSATT = 571,
     MATRIXTERMSTART = 572,
     MATRIXTERMEND = 573,
     POWERSTART = 574,
     POWEREND = 575,
     PLUSSTART = 576,
     PLUSEND = 577,
     MINUSSTART = 578,
     MINUSEND = 579,
     DIVIDESTART = 580,
     DIVIDEEND = 581,
     LNSTART = 582,
     LNEND = 583,
     SQRTSTART = 584,
     SQRTEND = 585,
     SUMSTART = 586,
     SUMEND = 587,
     PRODUCTSTART = 588,
     PRODUCTEND = 589,
     EXPSTART = 590,
     EXPEND = 591,
     NEGATESTART = 592,
     NEGATEEND = 593,
     IFSTART = 594,
     IFEND = 595,
     SQUARESTART = 596,
     SQUAREEND = 597,
     COSSTART = 598,
     COSEND = 599,
     SINSTART = 600,
     SINEND = 601,
     VARIABLESTART = 602,
     VARIABLEEND = 603,
     ABSSTART = 604,
     ABSEND = 605,
     ERFSTART = 606,
     ERFEND = 607,
     MAXSTART = 608,
     MAXEND = 609,
     ALLDIFFSTART = 610,
     ALLDIFFEND = 611,
     MINSTART = 612,
     MINEND = 613,
     ESTART = 614,
     EEND = 615,
     PISTART = 616,
     PIEND = 617,
     TIMESSTART = 618,
     TIMESEND = 619,
     NUMBERSTART = 620,
     NUMBEREND = 621,
     MATRIXDETERMINANTSTART = 622,
     MATRIXDETERMINANTEND = 623,
     MATRIXTRACESTART = 624,
     MATRIXTRACEEND = 625,
     MATRIXTOSCALARSTART = 626,
     MATRIXTOSCALAREND = 627,
     MATRIXDIAGONALSTART = 628,
     MATRIXDIAGONALEND = 629,
     MATRIXDOTTIMESSTART = 630,
     MATRIXDOTTIMESEND = 631,
     MATRIXLOWERTRIANGLESTART = 632,
     MATRIXLOWERTRIANGLEEND = 633,
     MATRIXUPPERTRIANGLESTART = 634,
     MATRIXUPPERTRIANGLEEND = 635,
     MATRIXMERGESTART = 636,
     MATRIXMERGEEND = 637,
     MATRIXMINUSSTART = 638,
     MATRIXMINUSEND = 639,
     MATRIXNEGATESTART = 640,
     MATRIXNEGATEEND = 641,
     MATRIXPLUSSTART = 642,
     MATRIXPLUSEND = 643,
     MATRIXTIMESSTART = 644,
     MATRIXTIMESEND = 645,
     MATRIXPRODUCTSTART = 646,
     MATRIXPRODUCTEND = 647,
     MATRIXSCALARTIMESSTART = 648,
     MATRIXSCALARTIMESEND = 649,
     MATRIXSUBMATRIXATSTART = 650,
     MATRIXSUBMATRIXATEND = 651,
     MATRIXTRANSPOSESTART = 652,
     MATRIXTRANSPOSEEND = 653,
     MATRIXREFERENCESTART = 654,
     MATRIXREFERENCEEND = 655,
     IDENTITYMATRIXSTART = 656,
     IDENTITYMATRIXEND = 657,
     MATRIXINVERSESTART = 658,
     MATRIXINVERSEEND = 659,
     EMPTYINCLUDEDIAGONALATT = 660,
     INCLUDEDIAGONALATT = 661,
     EMPTYIDATT = 662,
     IDATT = 663
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
#define ENDOFELEMENT 265
#define GREATERTHAN 266
#define EMPTYSEMIDEFINITENESSATT 267
#define SEMIDEFINITENESSATT 268
#define NUMBEROFQTERMSATT 269
#define NUMBEROFCONESATT 270
#define NUMBEROFSTAGESATT 271
#define IDXONEATT 272
#define IDXTWOATT 273
#define HORIZONATT 274
#define STARTATT 275
#define STARTIDXATT 276
#define MATRIXIDXATT 277
#define LBMATRIXIDXATT 278
#define LBCONEIDXATT 279
#define UBMATRIXIDXATT 280
#define UBCONEIDXATT 281
#define TEMPLATEMATRIXIDXATT 282
#define REFERENCEMATRIXIDXATT 283
#define VARREFERENCEMATRIXIDXATT 284
#define OBJREFERENCEMATRIXIDXATT 285
#define CONREFERENCEMATRIXIDXATT 286
#define ORDERCONEIDXATT 287
#define CONSTANTMATRIXIDXATT 288
#define NORMSCALEFACTORATT 289
#define DISTORTIONMATRIXIDXATT 290
#define AXISDIRECTIONATT 291
#define FIRSTAXISDIRECTIONATT 292
#define SECONDAXISDIRECTIONATT 293
#define OSILEND 294
#define INSTANCEDATAEND 295
#define INSTANCEDATASTARTEND 296
#define QUADRATICCOEFFICIENTSSTART 297
#define QUADRATICCOEFFICIENTSEND 298
#define QTERMSTART 299
#define QTERMEND 300
#define CONESSTART 301
#define CONESEND 302
#define NONNEGATIVECONESTART 303
#define NONNEGATIVECONEEND 304
#define NONPOSITIVECONESTART 305
#define NONPOSITIVECONEEND 306
#define ORTHANTCONESTART 307
#define ORTHANTCONEEND 308
#define POLYHEDRALCONESTART 309
#define POLYHEDRALCONEEND 310
#define QUADRATICCONESTART 311
#define QUADRATICCONEEND 312
#define ROTATEDQUADRATICCONESTART 313
#define ROTATEDQUADRATICCONEEND 314
#define SEMIDEFINITECONESTART 315
#define SEMIDEFINITECONEEND 316
#define PRODUCTCONESTART 317
#define PRODUCTCONEEND 318
#define INTERSECTIONCONESTART 319
#define INTERSECTIONCONEEND 320
#define DUALCONESTART 321
#define DUALCONEEND 322
#define POLARCONESTART 323
#define POLARCONEEND 324
#define DIRECTIONSTART 325
#define DIRECTIONEND 326
#define FACTORSSTART 327
#define FACTORSEND 328
#define COMPONENTSSTART 329
#define COMPONENTSEND 330
#define TIMEDOMAINSTART 331
#define TIMEDOMAINEND 332
#define STAGESSTART 333
#define STAGESEND 334
#define STAGESTART 335
#define STAGEEND 336
#define INTERVALSTART 337
#define INTERVALEND 338
#define HEADERSTART 339
#define HEADEREND 340
#define FILENAMESTART 341
#define FILENAMEEND 342
#define FILENAMEEMPTY 343
#define FILENAMESTARTANDEND 344
#define FILESOURCESTART 345
#define FILESOURCEEND 346
#define FILESOURCEEMPTY 347
#define FILESOURCESTARTANDEND 348
#define FILEDESCRIPTIONSTART 349
#define FILEDESCRIPTIONEND 350
#define FILEDESCRIPTIONEMPTY 351
#define FILEDESCRIPTIONSTARTANDEND 352
#define FILECREATORSTART 353
#define FILECREATOREND 354
#define FILECREATOREMPTY 355
#define FILECREATORSTARTANDEND 356
#define FILELICENCESTART 357
#define FILELICENCEEND 358
#define FILELICENCEEMPTY 359
#define FILELICENCESTARTANDEND 360
#define INDEXESSTART 361
#define INDEXESEND 362
#define VALUESSTART 363
#define VALUESEND 364
#define NONZEROSSTART 365
#define NONZEROSEND 366
#define ELSTART 367
#define ELEND 368
#define ENUMERATIONSTART 369
#define ENUMERATIONEND 370
#define ITEMEMPTY 371
#define ITEMSTART 372
#define ITEMEND 373
#define ITEMSTARTANDEND 374
#define BASE64START 375
#define BASE64END 376
#define NUMBEROFELATT 377
#define NUMBEROFENUMERATIONSATT 378
#define NUMBEROFITEMSATT 379
#define EMPTYCATEGORYATT 380
#define CATEGORYATT 381
#define EMPTYDESCRIPTIONATT 382
#define DESCRIPTIONATT 383
#define EMPTYSOLVERATT 384
#define SOLVERATT 385
#define EMPTYNAMEATT 386
#define NAMEATT 387
#define EMPTYTYPEATT 388
#define TYPEATT 389
#define EMPTYENUMTYPEATT 390
#define ENUMTYPEATT 391
#define EMPTYSHAPEATT 392
#define SHAPEATT 393
#define EMPTYUNITATT 394
#define UNITATT 395
#define EMPTYVALUEATT 396
#define VALUEATT 397
#define EMPTYVALUETYPEATT 398
#define VALUETYPEATT 399
#define EMPTYCONTYPEATT 400
#define CONTYPEATT 401
#define EMPTYOBJTYPEATT 402
#define OBJTYPEATT 403
#define EMPTYVARTYPEATT 404
#define VARTYPEATT 405
#define EMPTYMATRIXCONTYPEATT 406
#define MATRIXCONTYPEATT 407
#define EMPTYMATRIXOBJTYPEATT 408
#define MATRIXOBJTYPEATT 409
#define EMPTYMATRIXVARTYPEATT 410
#define MATRIXVARTYPEATT 411
#define EMPTYMATRIXTYPEATT 412
#define MATRIXTYPEATT 413
#define EMPTYSYMMETRYATT 414
#define SYMMETRYATT 415
#define EMPTYROWMAJORATT 416
#define ROWMAJORATT 417
#define EMPTYBASETRANSPOSEATT 418
#define BASETRANSPOSEATT 419
#define NUMBEROFBLOCKSATT 420
#define NUMBEROFCOLUMNSATT 421
#define NUMBEROFROWSATT 422
#define NUMBEROFMATRICESATT 423
#define NUMBEROFVALUESATT 424
#define NUMBEROFCONSTRAINTSATT 425
#define NUMBEROFCONATT 426
#define NUMBEROFCONIDXATT 427
#define NUMBEROFOBJECTIVESATT 428
#define NUMBEROFOBJATT 429
#define NUMBEROFOBJIDXATT 430
#define NUMBEROFVARIABLESATT 431
#define NUMBEROFVARATT 432
#define NUMBEROFVARIDXATT 433
#define NUMBEROFMATRIXCONATT 434
#define NUMBEROFMATRIXOBJATT 435
#define NUMBEROFMATRIXVARATT 436
#define BASEMATRIXIDXATT 437
#define TARGETMATRIXFIRSTROWATT 438
#define TARGETMATRIXFIRSTCOLATT 439
#define BASEMATRIXSTARTROWATT 440
#define BASEMATRIXSTARTCOLATT 441
#define BASEMATRIXENDROWATT 442
#define BASEMATRIXENDCOLATT 443
#define SCALARMULTIPLIERATT 444
#define BLOCKROWIDXATT 445
#define BLOCKCOLIDXATT 446
#define MATRIXVARIDXATT 447
#define MATRIXOBJIDXATT 448
#define MATRIXCONIDXATT 449
#define IDXATT 450
#define INCRATT 451
#define MULTATT 452
#define SIZEOFATT 453
#define COEFATT 454
#define CONSTANTATT 455
#define MATRICESSTART 456
#define MATRICESEND 457
#define MATRIXSTART 458
#define MATRIXEND 459
#define BASEMATRIXEND 460
#define BASEMATRIXSTART 461
#define BLOCKSSTART 462
#define BLOCKSEND 463
#define BLOCKSTART 464
#define BLOCKEND 465
#define COLOFFSETSTART 466
#define COLOFFSETEND 467
#define ROWOFFSETSTART 468
#define ROWOFFSETEND 469
#define ELEMENTSSTART 470
#define ELEMENTSEND 471
#define CONSTANTELEMENTSSTART 472
#define CONSTANTELEMENTSEND 473
#define COMPLEXELEMENTSSTART 474
#define COMPLEXELEMENTSEND 475
#define VARREFERENCEELEMENTSSTART 476
#define VARREFERENCEELEMENTSEND 477
#define LINEARELEMENTSSTART 478
#define LINEARELEMENTSEND 479
#define CONREFERENCEELEMENTSSTART 480
#define CONREFERENCEELEMENTSEND 481
#define OBJREFERENCEELEMENTSSTART 482
#define OBJREFERENCEELEMENTSEND 483
#define REALVALUEDEXPRESSIONSSTART 484
#define REALVALUEDEXPRESSIONSSEND 485
#define COMPLEXVALUEDEXPRESSIONSSTART 486
#define COMPLEXVALUEDEXPRESSIONSSEND 487
#define STRINGVALUEDELEMENTSSTART 488
#define STRINGVALUEDELEMENTSEND 489
#define STARTVECTORSTART 490
#define STARTVECTOREND 491
#define INDEXSTART 492
#define INDEXEND 493
#define VALUESTART 494
#define VALUEEND 495
#define VARIDXSTART 496
#define VARIDXEND 497
#define TRANSFORMATIONSTART 498
#define TRANSFORMATIONEND 499
#define MATRIXPROGRAMMINGSTART 500
#define MATRIXPROGRAMMINGEND 501
#define MATRIXVARIABLESSTART 502
#define MATRIXVARIABLESEND 503
#define MATRIXVARSTART 504
#define MATRIXVAREND 505
#define MATRIXOBJECTIVESSTART 506
#define MATRIXOBJECTIVESEND 507
#define MATRIXOBJSTART 508
#define MATRIXOBJEND 509
#define MATRIXCONSTRAINTSSTART 510
#define MATRIXCONSTRAINTSEND 511
#define MATRIXCONSTART 512
#define MATRIXCONEND 513
#define CONSTART 514
#define CONEND 515
#define CONSTRAINTSSTART 516
#define CONSTRAINTSEND 517
#define OBJSTART 518
#define OBJEND 519
#define OBJECTIVESSTART 520
#define OBJECTIVESEND 521
#define VARSTART 522
#define VAREND 523
#define VARIABLESSTART 524
#define VARIABLESEND 525
#define GENERALSTART 526
#define GENERALEND 527
#define SYSTEMSTART 528
#define SYSTEMEND 529
#define SERVICESTART 530
#define SERVICEEND 531
#define JOBSTART 532
#define JOBEND 533
#define OPTIMIZATIONSTART 534
#define OPTIMIZATIONEND 535
#define ATEQUALITYSTART 536
#define ATEQUALITYEND 537
#define ATLOWERSTART 538
#define ATLOWEREND 539
#define ATUPPERSTART 540
#define ATUPPEREND 541
#define BASICSTART 542
#define BASICEND 543
#define ISFREESTART 544
#define ISFREEEND 545
#define SUPERBASICSTART 546
#define SUPERBASICEND 547
#define UNKNOWNSTART 548
#define UNKNOWNEND 549
#define SERVICEURISTART 550
#define SERVICEURIEND 551
#define SERVICENAMESTART 552
#define SERVICENAMEEND 553
#define INSTANCENAMESTART 554
#define INSTANCENAMEEND 555
#define JOBIDSTART 556
#define JOBIDEND 557
#define OTHERSTART 558
#define OTHEREND 559
#define DUMMY 560
#define NONLINEAREXPRESSIONSSTART 561
#define NONLINEAREXPRESSIONSEND 562
#define NUMBEROFNONLINEAREXPRESSIONS 563
#define NLSTART 564
#define NLEND 565
#define MATRIXEXPRESSIONSSTART 566
#define MATRIXEXPRESSIONSEND 567
#define NUMBEROFEXPR 568
#define EXPRSTART 569
#define EXPREND 570
#define NUMBEROFMATRIXTERMSATT 571
#define MATRIXTERMSTART 572
#define MATRIXTERMEND 573
#define POWERSTART 574
#define POWEREND 575
#define PLUSSTART 576
#define PLUSEND 577
#define MINUSSTART 578
#define MINUSEND 579
#define DIVIDESTART 580
#define DIVIDEEND 581
#define LNSTART 582
#define LNEND 583
#define SQRTSTART 584
#define SQRTEND 585
#define SUMSTART 586
#define SUMEND 587
#define PRODUCTSTART 588
#define PRODUCTEND 589
#define EXPSTART 590
#define EXPEND 591
#define NEGATESTART 592
#define NEGATEEND 593
#define IFSTART 594
#define IFEND 595
#define SQUARESTART 596
#define SQUAREEND 597
#define COSSTART 598
#define COSEND 599
#define SINSTART 600
#define SINEND 601
#define VARIABLESTART 602
#define VARIABLEEND 603
#define ABSSTART 604
#define ABSEND 605
#define ERFSTART 606
#define ERFEND 607
#define MAXSTART 608
#define MAXEND 609
#define ALLDIFFSTART 610
#define ALLDIFFEND 611
#define MINSTART 612
#define MINEND 613
#define ESTART 614
#define EEND 615
#define PISTART 616
#define PIEND 617
#define TIMESSTART 618
#define TIMESEND 619
#define NUMBERSTART 620
#define NUMBEREND 621
#define MATRIXDETERMINANTSTART 622
#define MATRIXDETERMINANTEND 623
#define MATRIXTRACESTART 624
#define MATRIXTRACEEND 625
#define MATRIXTOSCALARSTART 626
#define MATRIXTOSCALAREND 627
#define MATRIXDIAGONALSTART 628
#define MATRIXDIAGONALEND 629
#define MATRIXDOTTIMESSTART 630
#define MATRIXDOTTIMESEND 631
#define MATRIXLOWERTRIANGLESTART 632
#define MATRIXLOWERTRIANGLEEND 633
#define MATRIXUPPERTRIANGLESTART 634
#define MATRIXUPPERTRIANGLEEND 635
#define MATRIXMERGESTART 636
#define MATRIXMERGEEND 637
#define MATRIXMINUSSTART 638
#define MATRIXMINUSEND 639
#define MATRIXNEGATESTART 640
#define MATRIXNEGATEEND 641
#define MATRIXPLUSSTART 642
#define MATRIXPLUSEND 643
#define MATRIXTIMESSTART 644
#define MATRIXTIMESEND 645
#define MATRIXPRODUCTSTART 646
#define MATRIXPRODUCTEND 647
#define MATRIXSCALARTIMESSTART 648
#define MATRIXSCALARTIMESEND 649
#define MATRIXSUBMATRIXATSTART 650
#define MATRIXSUBMATRIXATEND 651
#define MATRIXTRANSPOSESTART 652
#define MATRIXTRANSPOSEEND 653
#define MATRIXREFERENCESTART 654
#define MATRIXREFERENCEEND 655
#define IDENTITYMATRIXSTART 656
#define IDENTITYMATRIXEND 657
#define MATRIXINVERSESTART 658
#define MATRIXINVERSEEND 659
#define EMPTYINCLUDEDIAGONALATT 660
#define INCLUDEDIAGONALATT 661
#define EMPTYIDATT 662
#define IDATT 663




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
#define YYLAST   1213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  413
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  640
/* YYNRULES -- Number of rules.  */
#define YYNRULES  965
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1498

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   663

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   410,
     412,     2,     2,   411,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   409,     2,     2,     2,     2,     2,     2,     2,
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
     405,   406,   407,   408
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
    1128,  1130,  1132,  1133,  1136,  1138,  1140,  1142,  1144,  1146,
    1148,  1150,  1152,  1154,  1156,  1158,  1162,  1165,  1166,  1170,
    1172,  1174,  1175,  1178,  1180,  1182,  1184,  1186,  1188,  1190,
    1192,  1194,  1196,  1199,  1201,  1202,  1205,  1207,  1209,  1211,
    1213,  1215,  1217,  1219,  1221,  1226,  1228,  1230,  1231,  1234,
    1236,  1238,  1242,  1243,  1246,  1249,  1251,  1253,  1255,  1257,
    1261,  1263,  1266,  1268,  1270,  1272,  1274,  1278,  1280,  1283,
    1285,  1287,  1289,  1291,  1295,  1297,  1302,  1304,  1306,  1307,
    1310,  1312,  1314,  1318,  1319,  1322,  1325,  1327,  1329,  1331,
    1333,  1337,  1339,  1344,  1346,  1348,  1349,  1352,  1354,  1356,
    1360,  1361,  1364,  1365,  1368,  1370,  1372,  1374,  1376,  1380,
    1382,  1383,  1386,  1390,  1392,  1394,  1395,  1398,  1400,  1402,
    1404,  1406,  1408,  1412,  1413,  1416,  1420,  1422,  1423,  1425,
    1429,  1434,  1436,  1438,  1439,  1442,  1444,  1446,  1450,  1451,
    1454,  1455,  1458,  1460,  1462,  1464,  1466,  1470,  1471,  1474,
    1477,  1479,  1481,  1483,  1485,  1489,  1494,  1496,  1498,  1499,
    1502,  1504,  1506,  1510,  1511,  1514,  1517,  1519,  1521,  1523,
    1525,  1529,  1531,  1536,  1538,  1540,  1541,  1544,  1546,  1548,
    1552,  1553,  1556,  1557,  1560,  1562,  1564,  1566,  1568,  1572,
    1573,  1576,  1580,  1582,  1583,  1586,  1588,  1590,  1592,  1596,
    1602,  1604,  1605,  1607,  1609,  1613,  1615,  1617,  1623,  1625,
    1629,  1631,  1633,  1635,  1637,  1639,  1643,  1645,  1649,  1651,
    1653,  1655,  1657,  1659,  1663,  1665,  1666,  1669,  1673,  1675,
    1677,  1678,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,
    1699,  1702,  1707,  1712,  1717,  1722,  1727,  1732,  1737,  1742,
    1747,  1752,  1757,  1762,  1767,  1772,  1777,  1782,  1787,  1792,
    1797,  1802,  1807,  1812,  1814,  1816,  1818,  1822,  1824,  1826,
    1828,  1832,  1834,  1836,  1838,  1842,  1844,  1846,  1848,  1852,
    1854,  1856,  1858,  1862,  1864,  1866,  1868,  1872,  1874,  1876,
    1878,  1882,  1884,  1886,  1888,  1892,  1894,  1896,  1898,  1902,
    1903,  1908,  1910,  1916,  1917,  1920,  1926,  1928,  1930,  1931,
    1934,  1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,
    1954,  1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,  1972,
    1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1992,
    1993,  1997,  1999,  2002,  2003,  2007,  2009,  2012,  2013,  2019,
    2020,  2026,  2027,  2033,  2034,  2039,  2040,  2046,  2047,  2053,
    2054,  2059,  2060,  2065,  2066,  2071,  2072,  2077,  2078,  2083,
    2084,  2089,  2093,  2095,  2097,  2098,  2103,  2104,  2111,  2112,
    2117,  2118,  2123,  2124,  2129,  2133,  2135,  2137,  2140,  2141,
    2144,  2146,  2148,  2150,  2151,  2156,  2157,  2162,  2164,  2167,
    2168,  2173,  2174,  2177,  2179,  2181,  2186,  2191,  2192,  2197,
    2198,  2201,  2202,  2207,  2208,  2211,  2212,  2217,  2218,  2221,
    2222,  2227,  2228,  2231,  2232,  2237,  2238,  2241,  2243,  2245,
    2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,
    2267,  2269,  2271,  2273,  2275,  2277,  2279,  2283,  2285,  2287,
    2290,  2295,  2299,  2301,  2303,  2306,  2311,  2315,  2317,  2319,
    2322,  2327,  2331,  2333,  2335,  2338,  2343,  2346,  2348,  2351,
    2354,  2356,  2360,  2363,  2365,  2368,  2371,  2373,  2376,  2381,
    2383,  2384,  2386,  2389,  2394,  2396,  2397,  2399,  2402,  2406,
    2409,  2411,  2413,  2416,  2419,  2421,  2425,  2428,  2430,  2433,
    2436,  2438,  2442,  2445,  2447,  2451,  2452,  2457,  2458,  2461,
    2464,  2466,  2470,  2473,  2475,  2482,  2485,  2487,  2490,  2491,
    2495,  2497,  2499,  2504,  2506,  2508,  2510,  2514,  2515,  2518,
    2524,  2526,  2528,  2529,  2532,  2534
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     414,     0,    -1,   418,   893,   431,   438,   528,   575,   415,
     416,    -1,    41,    -1,    40,    -1,   417,    -1,    39,    -1,
      -1,    -1,   419,   420,   421,    43,    -1,    42,    -1,    14,
       8,     6,     8,    11,    -1,    -1,   421,   422,    -1,   423,
     425,   424,    -1,    44,    -1,    10,    -1,    11,    45,    -1,
      -1,   425,   426,    -1,   427,    -1,   428,    -1,   429,    -1,
     430,    -1,    17,     8,     6,     8,    -1,    18,     8,     6,
       8,    -1,   199,     8,   654,     8,    -1,   195,     8,     6,
       8,    -1,    -1,   432,   433,   434,    -1,   201,    -1,   632,
      -1,   435,    -1,   436,    -1,    10,    -1,    11,   437,   202,
      -1,    -1,   437,   680,    -1,    -1,   439,   440,   441,    -1,
      46,    -1,   633,    -1,   442,    -1,   443,    -1,    10,    -1,
      11,   444,    47,    -1,    -1,   444,   445,    -1,   446,    -1,
     452,    -1,   458,    -1,   473,    -1,   480,    -1,   486,    -1,
     492,    -1,   498,    -1,   513,    -1,   447,   448,   451,    -1,
      48,    -1,   449,    -1,    -1,   449,   450,    -1,   847,    -1,
     845,    -1,   869,    -1,    10,    -1,    11,    49,    -1,   453,
     454,   457,    -1,    50,    -1,   455,    -1,    -1,   455,   456,
      -1,   847,    -1,   845,    -1,   869,    -1,    10,    -1,    11,
      51,    -1,   459,   460,   463,    -1,    52,    -1,   461,    -1,
      -1,   461,   462,    -1,   847,    -1,   845,    -1,   869,    -1,
      10,    -1,    11,   464,   472,    -1,   465,    -1,    -1,   465,
     466,    -1,   467,   468,   471,    -1,    70,    -1,   469,    -1,
      -1,   469,   470,    -1,   881,    -1,   862,    -1,    10,    -1,
      11,    71,    -1,    53,    -1,   474,   475,   479,    -1,    54,
      -1,   476,    -1,    -1,   476,   477,    -1,   847,    -1,   845,
      -1,   478,    -1,   869,    -1,    28,     8,     6,     8,    -1,
      10,    -1,    11,    55,    -1,   481,   482,   485,    -1,    56,
      -1,   483,    -1,    -1,   483,   484,    -1,   847,    -1,   845,
      -1,   869,    -1,   638,    -1,   637,    -1,   639,    -1,    10,
      -1,    11,    57,    -1,   487,   488,   491,    -1,    58,    -1,
     489,    -1,    -1,   489,   490,    -1,   847,    -1,   845,    -1,
     869,    -1,   638,    -1,   637,    -1,   640,    -1,   641,    -1,
      10,    -1,    11,    59,    -1,   493,   494,   497,    -1,    60,
      -1,   495,    -1,    -1,   495,   496,    -1,   847,    -1,   845,
      -1,   869,    -1,   642,    -1,    10,    -1,    11,    61,    -1,
     499,   500,   503,    -1,    62,    -1,   501,    -1,    -1,   501,
     502,    -1,   847,    -1,   845,    -1,   869,    -1,    11,   504,
     512,    -1,   505,   506,   507,    -1,    72,    -1,   846,    -1,
     508,    -1,   509,    -1,    10,    -1,    11,   510,   511,    -1,
     658,    -1,    73,    -1,    63,    -1,   514,   515,   518,    -1,
      64,    -1,   516,    -1,    -1,   516,   517,    -1,   847,    -1,
     845,    -1,   869,    -1,    11,   519,   527,    -1,   520,   521,
     522,    -1,    74,    -1,   846,    -1,   523,    -1,   524,    -1,
      10,    -1,    11,   525,   526,    -1,   658,    -1,    75,    -1,
      65,    -1,    -1,   529,   530,    -1,   245,    -1,   531,    -1,
     532,    -1,    10,    -1,    11,   533,   547,   561,  1040,   246,
      -1,    -1,   534,   535,   536,    -1,   247,    -1,   634,    -1,
     537,    -1,   538,    -1,    10,    -1,    11,   540,   539,    -1,
     248,    -1,    -1,   540,   541,    -1,   542,   543,   546,    -1,
     249,    -1,   544,    -1,    -1,   544,   545,    -1,   847,    -1,
     845,    -1,   647,    -1,   648,    -1,   644,    -1,   651,    -1,
     645,    -1,   652,    -1,   869,    -1,   890,    -1,   862,    -1,
      10,    -1,    11,   250,    -1,    -1,   548,   549,   550,    -1,
     251,    -1,   635,    -1,   551,    -1,   552,    -1,    10,    -1,
      11,   554,   553,    -1,   252,    -1,    -1,   554,   555,    -1,
     556,   557,   560,    -1,   253,    -1,   558,    -1,    -1,   558,
     559,    -1,   847,    -1,   845,    -1,   647,    -1,   649,    -1,
     653,    -1,   646,    -1,   869,    -1,   862,    -1,    10,    -1,
      11,   254,    -1,    -1,   562,   563,   564,    -1,   255,    -1,
     636,    -1,   565,    -1,   566,    -1,    10,    -1,    11,   568,
     567,    -1,   256,    -1,    -1,   568,   569,    -1,   570,   571,
     574,    -1,   257,    -1,   572,    -1,    -1,   572,   573,    -1,
     847,    -1,   845,    -1,   647,    -1,   650,    -1,   644,    -1,
     651,    -1,   645,    -1,   652,    -1,   869,    -1,    10,    -1,
      11,   258,    -1,    -1,   576,   577,    -1,    76,    -1,   578,
      -1,   579,    -1,    10,    -1,    11,    77,    -1,    11,   580,
      77,    -1,    11,   624,    77,    -1,   581,   582,   583,    79,
      -1,    78,    -1,    16,     8,     6,     8,    11,    -1,   584,
      -1,   583,   584,    -1,    -1,   585,    80,   586,   587,    -1,
      -1,   132,     3,     8,    -1,    10,    -1,    11,   588,    81,
      -1,   589,   601,   613,    -1,    -1,   269,   590,   594,    -1,
      -1,   590,   591,    -1,   592,    -1,   593,    -1,   176,     8,
       6,     8,    -1,    21,     8,     6,     8,    -1,   595,    -1,
      11,   596,   270,    -1,    10,    -1,    11,   270,    -1,   597,
      -1,   596,   597,    -1,    -1,   598,   267,   599,   600,    -1,
     195,     8,     6,     8,    -1,    10,    -1,    11,   268,    -1,
      -1,   261,   602,   606,    -1,    -1,   602,   603,    -1,   604,
      -1,   605,    -1,   170,     8,     6,     8,    -1,    21,     8,
       6,     8,    -1,   607,    -1,    11,   608,   262,    -1,    10,
      -1,    11,   262,    -1,   609,    -1,   608,   609,    -1,    -1,
     610,   259,   611,   612,    -1,   195,     8,     6,     8,    -1,
      10,    -1,    11,   260,    -1,    -1,   265,   614,   617,    -1,
      -1,   614,   615,    -1,   616,    -1,   629,    -1,   173,     8,
       6,     8,    -1,   618,    -1,    11,   619,   266,    -1,    10,
      -1,    11,   266,    -1,   620,    -1,   619,   620,    -1,    -1,
     621,   263,   622,   623,    -1,   195,     8,     6,     8,    -1,
      10,    -1,    11,   264,    -1,    -1,   625,    82,   627,   626,
      -1,    10,    -1,    11,    83,    -1,    -1,   627,   628,    -1,
     630,    -1,   631,    -1,    21,     8,     6,     8,    -1,    19,
       8,   654,     8,    -1,    20,     8,   654,     8,    -1,   168,
       8,     6,     8,    -1,    15,     8,     6,     8,    -1,   181,
       8,     6,     8,    -1,   180,     8,     6,     8,    -1,   179,
       8,     6,     8,    -1,    34,     8,   654,     8,    -1,    35,
       8,     6,     8,    -1,    36,     8,     6,     8,    -1,    37,
       8,     6,     8,    -1,    38,     8,     6,     8,    -1,    13,
       3,     8,    -1,    22,     8,     6,     8,    -1,    23,     8,
       6,     8,    -1,    25,     8,     6,     8,    -1,    33,     8,
       6,     8,    -1,    27,     8,     6,     8,    -1,    29,     8,
       6,     8,    -1,    30,     8,     6,     8,    -1,    31,     8,
       6,     8,    -1,    24,     8,     6,     8,    -1,    26,     8,
       6,     8,    -1,    32,     8,     6,     8,    -1,   656,     6,
     656,    -1,   656,     7,   656,    -1,   656,     8,    -1,    -1,
     656,   657,    -1,   409,    -1,   410,    -1,   411,    -1,   412,
      -1,   659,    -1,   666,    -1,    -1,   659,   660,    -1,   661,
     662,   665,    -1,   112,    -1,   663,    -1,    -1,   663,   664,
      -1,   862,    -1,   861,    -1,    11,     6,   113,    -1,   120,
     850,   667,    -1,   668,    -1,   669,    -1,    11,   121,    -1,
      10,    -1,    11,     4,   121,    -1,   671,    -1,   676,    -1,
      -1,   671,   672,    -1,   673,   674,   675,    -1,   112,    -1,
      -1,   862,    -1,    11,   654,   113,    -1,   120,   850,   677,
      -1,   678,    -1,   679,    -1,    11,   121,    -1,    10,    -1,
      11,     4,   121,    -1,   681,   682,   685,    -1,   203,    -1,
     683,    -1,    -1,   683,   684,    -1,   878,    -1,   847,    -1,
     845,    -1,   869,    -1,   881,    -1,   249,    -1,   253,    -1,
     257,    -1,   686,    -1,   687,    -1,    10,    -1,    11,   688,
     204,    -1,   689,   695,    -1,    -1,   690,   691,   694,    -1,
     206,    -1,   692,    -1,    -1,   692,   693,    -1,   851,    -1,
     864,    -1,   865,    -1,   852,    -1,   853,    -1,   854,    -1,
     855,    -1,   866,    -1,   863,    -1,    11,   205,    -1,    10,
      -1,    -1,   695,   696,    -1,   697,    -1,   722,    -1,   735,
      -1,   762,    -1,   780,    -1,   793,    -1,   811,    -1,   815,
      -1,   698,   699,    11,   702,    -1,   217,    -1,   700,    -1,
      -1,   700,   701,    -1,   848,    -1,   872,    -1,   704,   703,
     218,    -1,    -1,   710,   716,    -1,   705,   706,    -1,   235,
      -1,   707,    -1,   708,    -1,    10,    -1,    11,   709,   236,
      -1,   658,    -1,   711,   712,    -1,   237,    -1,   713,    -1,
     714,    -1,    10,    -1,    11,   715,   238,    -1,   658,    -1,
     717,   718,    -1,   239,    -1,   719,    -1,   720,    -1,    10,
      -1,    11,   721,   240,    -1,   670,    -1,   723,   724,    11,
     727,    -1,   221,    -1,   725,    -1,    -1,   725,   726,    -1,
     848,    -1,   872,    -1,   704,   728,   222,    -1,    -1,   710,
     729,    -1,   730,   731,    -1,   239,    -1,   732,    -1,   733,
      -1,    10,    -1,    11,   734,   240,    -1,   658,    -1,   736,
     737,    11,   740,    -1,   223,    -1,   738,    -1,    -1,   738,
     739,    -1,   848,    -1,   872,    -1,   704,   741,   224,    -1,
      -1,   710,   742,    -1,    -1,   743,   744,    -1,   239,    -1,
     745,    -1,   746,    -1,    10,    -1,    11,   747,   240,    -1,
     748,    -1,    -1,   748,   749,    -1,   750,   751,   754,    -1,
     112,    -1,   752,    -1,    -1,   752,   753,    -1,   849,    -1,
     859,    -1,   755,    -1,   756,    -1,    10,    -1,    11,   757,
     113,    -1,    -1,   757,   758,    -1,   759,   760,   761,    -1,
     241,    -1,    -1,   858,    -1,    11,     6,   242,    -1,   763,
     764,    11,   767,    -1,   229,    -1,   765,    -1,    -1,   765,
     766,    -1,   848,    -1,   872,    -1,   704,   768,   230,    -1,
      -1,   710,   769,    -1,    -1,   770,   771,    -1,   239,    -1,
     772,    -1,   773,    -1,    10,    -1,    11,   774,   240,    -1,
      -1,   774,   775,    -1,   776,   777,    -1,   112,    -1,   778,
      -1,   779,    -1,    10,    -1,    11,   902,   113,    -1,   781,
     782,    11,   785,    -1,   227,    -1,   783,    -1,    -1,   783,
     784,    -1,   848,    -1,   872,    -1,   704,   786,   228,    -1,
      -1,   710,   787,    -1,   788,   789,    -1,   239,    -1,   790,
      -1,   791,    -1,    10,    -1,    11,   792,   240,    -1,   658,
      -1,   794,   795,    11,   798,    -1,   225,    -1,   796,    -1,
      -1,   796,   797,    -1,   848,    -1,   872,    -1,   704,   799,
     226,    -1,    -1,   710,   800,    -1,    -1,   801,   802,    -1,
     239,    -1,   803,    -1,   804,    -1,    10,    -1,    11,   805,
     240,    -1,    -1,   805,   806,    -1,   807,   808,   810,    -1,
     112,    -1,    -1,   808,   809,    -1,   887,    -1,   862,    -1,
     861,    -1,    11,     6,   113,    -1,   812,   813,    11,   976,
     814,    -1,   243,    -1,    -1,   875,    -1,   244,    -1,   816,
     817,   818,    -1,   207,    -1,   844,    -1,    11,   820,   827,
     834,   819,    -1,   208,    -1,   821,   822,   823,    -1,   211,
      -1,   846,    -1,   824,    -1,   825,    -1,    10,    -1,    11,
     826,   212,    -1,   658,    -1,   828,   829,   830,    -1,   213,
      -1,   846,    -1,   831,    -1,   832,    -1,    10,    -1,    11,
     833,   214,    -1,   658,    -1,    -1,   834,   835,    -1,   836,
     837,   840,    -1,   209,    -1,   838,    -1,    -1,   838,   839,
      -1,   856,    -1,   857,    -1,   878,    -1,   881,    -1,   841,
      -1,   842,    -1,    10,    -1,    11,   843,   210,    -1,   689,
     695,    -1,   165,     8,     6,     8,    -1,   166,     8,     6,
       8,    -1,   122,     8,     6,     8,    -1,   167,     8,     6,
       8,    -1,   169,     8,     6,     8,    -1,   178,     8,     6,
       8,    -1,   198,     8,     6,     8,    -1,   182,     8,     6,
       8,    -1,   185,     8,     6,     8,    -1,   186,     8,     6,
       8,    -1,   187,     8,     6,     8,    -1,   188,     8,     6,
       8,    -1,   190,   655,     6,   655,    -1,   191,   655,     6,
     655,    -1,   199,     8,   654,     8,    -1,   200,     8,   654,
       8,    -1,   195,     8,     6,     8,    -1,   196,     8,     6,
       8,    -1,   197,     8,     6,     8,    -1,   189,     8,   654,
       8,    -1,   183,     8,     6,     8,    -1,   184,     8,     6,
       8,    -1,   867,    -1,   868,    -1,   163,    -1,   164,     3,
     655,    -1,   870,    -1,   871,    -1,   131,    -1,   132,     3,
       8,    -1,   873,    -1,   874,    -1,   161,    -1,   162,     3,
       8,    -1,   876,    -1,   877,    -1,   137,    -1,   138,     3,
       8,    -1,   879,    -1,   880,    -1,   159,    -1,   160,     3,
       8,    -1,   882,    -1,   883,    -1,   133,    -1,   134,     3,
       8,    -1,   885,    -1,   886,    -1,   141,    -1,   142,     3,
       8,    -1,   888,    -1,   889,    -1,   143,    -1,   144,     3,
       8,    -1,   891,    -1,   892,    -1,   149,    -1,   150,     3,
       8,    -1,    -1,   894,   895,   896,   307,    -1,   306,    -1,
     308,     8,     6,     8,    11,    -1,    -1,   896,   897,    -1,
     898,   899,    11,   902,   310,    -1,   309,    -1,   900,    -1,
      -1,   900,   901,    -1,   860,    -1,   875,    -1,   946,    -1,
     953,    -1,   909,    -1,   911,    -1,   961,    -1,   913,    -1,
     915,    -1,   917,    -1,   919,    -1,   973,    -1,   921,    -1,
     923,    -1,   925,    -1,   929,    -1,   927,    -1,   931,    -1,
     938,    -1,   933,    -1,   936,    -1,   967,    -1,   970,    -1,
     903,    -1,   906,    -1,   964,    -1,   940,    -1,   942,    -1,
     944,    -1,    -1,   359,   904,   905,    -1,    10,    -1,    11,
     360,    -1,    -1,   361,   907,   908,    -1,    10,    -1,    11,
     362,    -1,    -1,   363,   910,   902,   902,   364,    -1,    -1,
     321,   912,   902,   902,   322,    -1,    -1,   323,   914,   902,
     902,   324,    -1,    -1,   337,   916,   902,   338,    -1,    -1,
     325,   918,   902,   902,   326,    -1,    -1,   319,   920,   902,
     902,   320,    -1,    -1,   327,   922,   902,   328,    -1,    -1,
     329,   924,   902,   330,    -1,    -1,   341,   926,   902,   342,
      -1,    -1,   343,   928,   902,   344,    -1,    -1,   345,   930,
     902,   346,    -1,    -1,   335,   932,   902,   336,    -1,   934,
     902,   935,    -1,   349,    -1,   350,    -1,    -1,   351,   937,
     902,   352,    -1,    -1,   339,   939,   902,   902,   902,   340,
      -1,    -1,   367,   941,   976,   368,    -1,    -1,   369,   943,
     976,   370,    -1,    -1,   371,   945,   976,   372,    -1,   947,
     949,   948,    -1,   365,    -1,    10,    -1,    11,   366,    -1,
      -1,   949,   950,    -1,   881,    -1,   884,    -1,   951,    -1,
      -1,   408,     3,   952,     8,    -1,    -1,   347,   954,   957,
     955,    -1,    10,    -1,    11,   348,    -1,    -1,    11,   902,
     956,   348,    -1,    -1,   957,   958,    -1,   959,    -1,   960,
      -1,   199,     8,   654,     8,    -1,   195,     8,     6,     8,
      -1,    -1,   331,   962,   963,   332,    -1,    -1,   963,   902,
      -1,    -1,   355,   965,   966,   356,    -1,    -1,   966,   902,
      -1,    -1,   353,   968,   969,   354,    -1,    -1,   969,   902,
      -1,    -1,   357,   971,   972,   358,    -1,    -1,   972,   902,
      -1,    -1,   333,   974,   975,   334,    -1,    -1,   975,   902,
      -1,   977,    -1,   980,    -1,   984,    -1,   988,    -1,   992,
      -1,   995,    -1,  1001,    -1,  1004,    -1,  1008,    -1,  1013,
      -1,  1016,    -1,  1019,    -1,  1022,    -1,  1025,    -1,  1028,
      -1,  1031,    -1,  1034,    -1,  1037,    -1,   998,    -1,   978,
     643,   979,    -1,   399,    -1,    10,    -1,    11,   400,    -1,
     195,     8,     6,     8,    -1,   981,   983,   982,    -1,   249,
      -1,    10,    -1,    11,   250,    -1,   195,     8,     6,     8,
      -1,   985,   987,   986,    -1,   253,    -1,    10,    -1,    11,
     254,    -1,   195,     8,     6,     8,    -1,   989,   991,   990,
      -1,   257,    -1,    10,    -1,    11,   258,    -1,   195,     8,
       6,     8,    -1,   993,   994,    -1,   373,    -1,   976,   374,
      -1,   996,   997,    -1,   375,    -1,   976,   976,   376,    -1,
     999,  1000,    -1,   401,    -1,   902,   402,    -1,  1002,  1003,
      -1,   403,    -1,   976,   404,    -1,  1005,  1006,    11,  1007,
      -1,   377,    -1,    -1,  1012,    -1,   976,   378,    -1,  1009,
    1010,    11,  1011,    -1,   379,    -1,    -1,  1012,    -1,   976,
     380,    -1,   406,     3,     8,    -1,  1014,  1015,    -1,   381,
      -1,    10,    -1,    11,   382,    -1,  1017,  1018,    -1,   383,
      -1,   976,   976,   384,    -1,  1020,  1021,    -1,   385,    -1,
     976,   386,    -1,  1023,  1024,    -1,   387,    -1,   976,   976,
     388,    -1,  1026,  1027,    -1,   389,    -1,   976,   976,   390,
      -1,    -1,   391,  1029,  1030,   392,    -1,    -1,  1030,   976,
      -1,  1032,  1033,    -1,   393,    -1,   902,   976,   394,    -1,
    1035,  1036,    -1,   395,    -1,   902,   902,   902,   902,   976,
     396,    -1,  1038,  1039,    -1,   397,    -1,   976,   398,    -1,
      -1,  1041,  1042,  1044,    -1,   311,    -1,  1043,    -1,   313,
       8,     6,     8,    -1,  1045,    -1,  1046,    -1,    10,    -1,
      11,  1047,   312,    -1,    -1,  1047,  1048,    -1,  1049,  1050,
      11,   976,   315,    -1,   314,    -1,  1051,    -1,    -1,  1051,
    1052,    -1,   860,    -1,   875,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   429,   429,   432,   433,   435,   444,   445,   448,   449,
     453,   458,   468,   468,   470,   483,   489,   490,   493,   494,
     497,   500,   503,   506,   512,   519,   526,   534,   539,   539,
     547,   553,   565,   565,   567,   569,   576,   576,   579,   579,
     585,   591,   603,   603,   605,   607,   611,   611,   619,   620,
     621,   622,   623,   624,   626,   633,   634,   639,   641,   650,
     652,   652,   655,   660,   665,   670,   670,   672,   675,   684,
     686,   686,   689,   694,   699,   704,   704,   707,   709,   718,
     728,   728,   731,   736,   741,   747,   747,   753,   755,   755,
     757,   759,   766,   804,   805,   807,   807,   809,   809,   811,
     813,   815,   824,   826,   826,   829,   834,   839,   844,   849,
     860,   860,   864,   866,   878,   880,   880,   883,   888,   893,
     897,   902,   907,   914,   914,   916,   918,   931,   933,   933,
     936,   941,   946,   951,   956,   961,   966,   973,   973,   977,
     979,   989,   991,   991,   994,   999,  1004,  1008,  1015,  1015,
    1029,  1031,  1040,  1042,  1042,  1045,  1050,  1055,  1060,  1062,
    1064,  1070,  1076,  1076,  1078,  1080,  1082,  1084,  1098,  1101,
    1103,  1112,  1114,  1114,  1117,  1122,  1127,  1132,  1134,  1136,
    1142,  1148,  1148,  1150,  1152,  1154,  1156,  1170,  1179,  1179,
    1181,  1186,  1186,  1188,  1191,  1193,  1193,  1200,  1205,  1215,
    1215,  1217,  1219,  1221,  1223,  1223,  1225,  1230,  1246,  1294,
    1294,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1310,  1311,  1313,  1313,  1319,  1324,  1334,  1334,
    1336,  1338,  1340,  1342,  1342,  1344,  1349,  1362,  1395,  1395,
    1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,  1408,  1409,
    1412,  1412,  1418,  1423,  1433,  1433,  1435,  1437,  1439,  1441,
    1441,  1443,  1448,  1463,  1502,  1502,  1505,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1516,  1517,  1560,  1560,  1562,
    1564,  1564,  1566,  1567,  1570,  1571,  1574,  1625,  1627,  1641,
    1642,  1644,  1644,  1668,  1669,  1672,  1673,  1675,  1677,  1678,
    1682,  1683,  1685,  1686,  1688,  1707,  1718,  1725,  1730,  1731,
    1733,  1734,  1736,  1736,  1739,  1751,  1752,  1754,  1755,  1759,
    1760,  1762,  1763,  1765,  1784,  1795,  1802,  1807,  1808,  1810,
    1811,  1813,  1813,  1816,  1828,  1829,  1831,  1841,  1845,  1846,
    1848,  1849,  1851,  1870,  1877,  1882,  1883,  1885,  1886,  1888,
    1888,  1891,  1903,  1904,  1909,  1909,  1917,  1918,  1920,  1921,
    1923,  1927,  1933,  1944,  1949,  1964,  1975,  1986,  1994,  2002,
    2021,  2032,  2043,  2055,  2066,  2077,  2089,  2100,  2112,  2124,
    2136,  2148,  2160,  2172,  2184,  2196,  2208,  2235,  2236,  2243,
    2245,  2245,  2247,  2248,  2249,  2250,  2414,  2422,  2424,  2424,
    2426,  2428,  2437,  2439,  2439,  2441,  2441,  2443,  2459,  2462,
    2462,  2464,  2464,  2467,  2498,  2506,  2508,  2508,  2510,  2512,
    2520,  2520,  2522,  2538,  2540,  2540,  2542,  2542,  2544,  2821,
    2872,  2895,  2913,  2913,  2916,  2917,  2918,  2919,  2920,  2924,
    2982,  3040,  3099,  3099,  3101,  3103,  3143,  3145,  3145,  3150,
    3168,  3195,  3195,  3198,  3199,  3200,  3201,  3202,  3203,  3204,
    3205,  3206,  3209,  3209,  3211,  3211,  3216,  3216,  3216,  3216,
    3217,  3217,  3217,  3217,  3219,  3221,  3230,  3236,  3236,  3239,
    3245,  3251,  3253,  3253,  3259,  3269,  3279,  3279,  3281,  3283,
    3285,  3288,  3299,  3306,  3306,  3308,  3310,  3312,  3318,  3328,
    3335,  3335,  3337,  3339,  3341,  3344,  3346,  3355,  3361,  3361,
    3364,  3370,  3376,  3378,  3378,  3380,  3390,  3397,  3397,  3399,
    3401,  3403,  3405,  3407,  3416,  3422,  3422,  3425,  3431,  3437,
    3439,  3439,  3442,  3447,  3458,  3473,  3473,  3475,  3477,  3479,
    3481,  3481,  3483,  3490,  3497,  3510,  3510,  3513,  3514,  3516,
    3516,  3518,  3520,  3522,  3522,  3525,  3527,  3535,  3535,  3540,
    3547,  3549,  3558,  3564,  3564,  3567,  3573,  3580,  3582,  3582,
    3584,  3585,  3587,  3602,  3602,  3604,  3606,  3608,  3608,  3610,
    3612,  3627,  3627,  3629,  3631,  3641,  3643,  3652,  3658,  3658,
    3661,  3667,  3673,  3675,  3675,  3677,  3687,  3694,  3694,  3696,
    3698,  3700,  3703,  3705,  3714,  3720,  3720,  3723,  3729,  3735,
    3737,  3737,  3740,  3745,  3756,  3771,  3771,  3773,  3775,  3777,
    3777,  3779,  3787,  3799,  3799,  3802,  3803,  3804,  3822,  3855,
    3858,  3876,  3876,  3887,  3894,  3904,  3912,  3918,  3920,  3934,
    3946,  3952,  3958,  3958,  3960,  3962,  3964,  3966,  3976,  3982,
    3988,  3988,  3990,  3992,  3994,  3996,  3996,  4001,  4006,  4018,
    4020,  4020,  4023,  4024,  4025,  4033,  4040,  4040,  4042,  4044,
    4050,  4064,  4075,  4119,  4242,  4253,  4275,  4299,  4310,  4324,
    4339,  4354,  4366,  4378,  4396,  4414,  4427,  4440,  4450,  4487,
    4498,  4508,  4520,  4534,  4534,  4536,  4546,  4708,  4708,  4710,
    4717,  4744,  4744,  4746,  4755,  4769,  4769,  4771,  4778,  4805,
    4805,  4807,  4814,  4823,  4823,  4825,  4832,  4859,  4859,  4863,
    4871,  4880,  4880,  4882,  4889,  4898,  4898,  4900,  4907,  4946,
    4947,  4953,  4959,  4980,  4981,  4983,  4991,  5010,  5017,  5017,
    5020,  5026,  5036,  5037,  5038,  5039,  5040,  5041,  5042,  5043,
    5044,  5045,  5046,  5047,  5048,  5049,  5050,  5051,  5052,  5053,
    5054,  5055,  5056,  5057,  5058,  5059,  5061,  5062,  5063,  5067,
    5067,  5070,  5071,  5073,  5073,  5076,  5077,  5081,  5081,  5086,
    5086,  5091,  5091,  5096,  5096,  5101,  5101,  5106,  5106,  5111,
    5111,  5116,  5116,  5121,  5121,  5126,  5126,  5131,  5131,  5136,
    5136,  5141,  5143,  5149,  5156,  5156,  5162,  5162,  5174,  5174,
    5179,  5179,  5184,  5184,  5194,  5201,  5207,  5208,  5210,  5211,
    5214,  5218,  5222,  5226,  5225,  5244,  5243,  5250,  5251,  5253,
    5252,  5259,  5260,  5263,  5269,  5277,  5284,  5302,  5302,  5313,
    5313,  5316,  5316,  5330,  5331,  5334,  5334,  5347,  5348,  5351,
    5351,  5364,  5365,  5368,  5368,  5378,  5379,  5385,  5386,  5387,
    5388,  5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,  5397,
    5398,  5399,  5400,  5401,  5402,  5403,  5406,  5411,  5418,  5419,
    5421,  5429,  5434,  5441,  5442,  5444,  5451,  5456,  5463,  5464,
    5466,  5473,  5478,  5485,  5486,  5488,  5495,  5497,  5503,  5505,
    5507,  5513,  5515,  5517,  5523,  5525,  5527,  5533,  5535,  5537,
    5543,  5543,  5548,  5550,  5552,  5558,  5558,  5563,  5565,  5574,
    5576,  5581,  5581,  5583,  5585,  5591,  5594,  5596,  5602,  5605,
    5607,  5613,  5616,  5618,  5624,  5628,  5627,  5639,  5639,  5646,
    5648,  5654,  5656,  5658,  5664,  5667,  5669,  5675,  5685,  5685,
    5691,  5699,  5701,  5721,  5721,  5723,  5725,  5727,  5727,  5729,
    5739,  5758,  5764,  5764,  5767,  5775
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "ENDOFELEMENT",
  "GREATERTHAN", "EMPTYSEMIDEFINITENESSATT", "SEMIDEFINITENESSATT",
  "NUMBEROFQTERMSATT", "NUMBEROFCONESATT", "NUMBEROFSTAGESATT",
  "IDXONEATT", "IDXTWOATT", "HORIZONATT", "STARTATT", "STARTIDXATT",
  "MATRIXIDXATT", "LBMATRIXIDXATT", "LBCONEIDXATT", "UBMATRIXIDXATT",
  "UBCONEIDXATT", "TEMPLATEMATRIXIDXATT", "REFERENCEMATRIXIDXATT",
  "VARREFERENCEMATRIXIDXATT", "OBJREFERENCEMATRIXIDXATT",
  "CONREFERENCEMATRIXIDXATT", "ORDERCONEIDXATT", "CONSTANTMATRIXIDXATT",
  "NORMSCALEFACTORATT", "DISTORTIONMATRIXIDXATT", "AXISDIRECTIONATT",
  "FIRSTAXISDIRECTIONATT", "SECONDAXISDIRECTIONATT", "OSILEND",
  "INSTANCEDATAEND", "INSTANCEDATASTARTEND", "QUADRATICCOEFFICIENTSSTART",
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
  "BLOCKCOLIDXATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT",
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
  "MATRIXINVERSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "EMPTYIDATT", "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osildoc", "theInstanceEnd", "osilEnd", "osilEnding",
  "quadraticCoefficients", "quadraticCoefficientsStart",
  "osilQuadnumberATT", "qTermlist", "qterm", "qtermStart", "qtermend",
  "anotherqTermATT", "qtermatt", "osilQtermidxOneATT",
  "osilQtermidxTwoATT", "osilQtermcoefATT", "osilQtermidxATT", "matrices",
  "matricesStart", "matricesAttributes", "matricesContent",
  "matricesEmpty", "matricesLaden", "matrixList", "cones", "conesStart",
  "conesAttributes", "conesContent", "conesEmpty", "conesLaden",
  "coneList", "cone", "nonnegativeCone", "nonnegativeConeStart",
  "nonnegativeConeAttributes", "nonnegativeConeAttList",
  "nonnegativeConeAtt", "nonnegativeConeEnd", "nonpositiveCone",
  "nonpositiveConeStart", "nonpositiveConeAttributes",
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
  "matrixVarList", "matrixVar", "matrixVarStart", "matrixVarAttributes",
  "matrixVarAttList", "matrixVarAtt", "matrixVarEnd", "matrixObjectives",
  "matrixObjectivesStart", "matrixObjectivesAttributes",
  "matrixObjectivesContent", "matrixObjectivesEmpty",
  "matrixObjectivesLaden", "matrixObjectivesEnd", "matrixObjList",
  "matrixObj", "matrixObjStart", "matrixObjAttributes", "matrixObjAttList",
  "matrixObjAtt", "matrixObjEnd", "matrixConstraints",
  "matrixConstraintsStart", "matrixConstraintsAttributes",
  "matrixConstraintsContent", "matrixConstraintsEmpty",
  "matrixConstraintsLaden", "matrixConstraintsEnd", "matrixConList",
  "matrixCon", "matrixConStart", "matrixConAttributes", "matrixConAttList",
  "matrixConAtt", "matrixConEnd", "timeDomain", "timeDomainStart",
  "timeDomainContent", "timeDomainEmpty", "timeDomainLaden", "stages",
  "stagesstart", "osilNumberofstagesATT", "stagelist", "stage", "$@1",
  "osilStagenameATT", "stageend", "stagecontent", "stagevariables",
  "anotherstagevarATT", "stagevaratt", "osilNumberofstagevariablesATT",
  "osilStagevarstartidxATT", "restofstagevariables", "emptyvarlist",
  "stagevarlist", "stagevar", "$@2", "osilStagevaridxATT", "stagevarend",
  "stageconstraints", "anotherstageconATT", "stageconatt",
  "osilNumberofstageconstraintsATT", "osilStageconstartidxATT",
  "restofstageconstraints", "emptyconlist", "stageconlist", "stagecon",
  "$@3", "osilStageconidxATT", "stageconend", "stageobjectives",
  "anotherstageobjATT", "stageobjatt", "osilNumberofstageobjectivesATT",
  "restofstageobjectives", "emptyobjlist", "stageobjlist", "stageobj",
  "$@4", "osilStageobjidxATT", "stageobjend", "interval", "$@5",
  "intervalend", "anotherIntervalATT", "intervalatt",
  "osilStageobjstartidxATT", "osilIntervalhorizonATT",
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
  "osglDblVectorBase64Laden", "osglMatrix", "matrixStart",
  "matrixAttributes", "matrixAttributeList", "matrixAttribute",
  "matrixContent", "matrixEmpty", "matrixLaden", "matrixBody",
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
  "linearElementsValuesVarIdxStart", "LinearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "realValuedExpressions",
  "realValuedExpressionsStart", "realValuedExpressionsAttributes",
  "realValuedExpressionsAttList", "realValuedExpressionsAtt",
  "realValuedExpressionsContent", "realValuedExpressionsNonzeros",
  "realValuedExpressionsValues", "realValuedExpressionsValuesStart",
  "realValuedExpressionsValuesContent", "realValuedExpressionsValuesEmpty",
  "realValuedExpressionsValuesLaden", "realValuedExpressionsElList",
  "realValuedExpressionsEl", "realValuedExpressionsElStart",
  "realValuedExpressionsElContent", "realValuedExpressionsElEmpty",
  "realValuedExpressionsElLaden", "objReferenceElements",
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
  "blockBody", "osglNumberOfBlocksATT", "osglNumberOfColumnsATT",
  "osglNumberOfElATT", "osglNumberOfRowsATT", "osglNumberOfValuesATT",
  "osglNumberOfVarIdxATT", "osglBase64SizeATT", "osglBaseMatrixIdxATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "osglBlockRowIdxATT", "osglBlockColIdxATT", "osglCoefATT",
  "osglConstantATT", "osglIdxATT", "osglIncrATT", "osglMultATT",
  "osglScalarMultiplierATT", "osglTargetMatrixFirstRowATT",
  "osglTargetMatrixFirstColATT", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent", "osglNameATT",
  "nameAttEmpty", "nameAttContent", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "osglShapeATT", "shapeAttEmpty", "shape",
  "osglSymmetryATT", "symmetryAttEmpty", "symmetryAttContent",
  "osglTypeATT", "typeAttEmpty", "typeAttContent", "osglValueATT",
  "valueAttEmpty", "valueAttContent", "osglValueTypeATT",
  "valueTypeAttEmpty", "valueTypeAttContent", "osglVarTypeATT",
  "varTypeAttEmpty", "varTypeAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "scalarExpressionTree", "nlstart", "nlAttributes", "nlAttributeList",
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
  "matrixReferenceEnd", "matrixVarReference", "matrixVarReferenceStart",
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
  "matrixExprAttributeList", "exprAttribute", 0
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
     655,   656,   657,   658,   659,   660,   661,   662,   663,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   413,   414,   415,   415,   416,   417,   417,   418,   418,
     419,   420,   421,   421,   422,   423,   424,   424,   425,   425,
     426,   426,   426,   426,   427,   428,   429,   430,   431,   431,
     432,   433,   434,   434,   435,   436,   437,   437,   438,   438,
     439,   440,   441,   441,   442,   443,   444,   444,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   446,   447,   448,
     449,   449,   450,   450,   450,   451,   451,   452,   453,   454,
     455,   455,   456,   456,   456,   457,   457,   458,   459,   460,
     461,   461,   462,   462,   462,   463,   463,   464,   465,   465,
     466,   467,   468,   469,   469,   470,   470,   471,   471,   472,
     473,   474,   475,   476,   476,   477,   477,   477,   477,   478,
     479,   479,   480,   481,   482,   483,   483,   484,   484,   484,
     484,   484,   484,   485,   485,   486,   487,   488,   489,   489,
     490,   490,   490,   490,   490,   490,   490,   491,   491,   492,
     493,   494,   495,   495,   496,   496,   496,   496,   497,   497,
     498,   499,   500,   501,   501,   502,   502,   502,   503,   504,
     505,   506,   507,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   516,   517,   517,   517,   518,   519,   520,
     521,   522,   522,   523,   524,   525,   526,   527,   528,   528,
     529,   530,   530,   531,   532,   533,   533,   534,   535,   536,
     536,   537,   538,   539,   540,   540,   541,   542,   543,   544,
     544,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   546,   546,   547,   547,   548,   549,   550,   550,
     551,   552,   553,   554,   554,   555,   556,   557,   558,   558,
     559,   559,   559,   559,   559,   559,   559,   559,   560,   560,
     561,   561,   562,   563,   564,   564,   565,   566,   567,   568,
     568,   569,   570,   571,   572,   572,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   574,   574,   575,   575,   576,
     577,   577,   578,   578,   579,   579,   580,   581,   582,   583,
     583,   585,   584,   586,   586,   587,   587,   588,   589,   589,
     590,   590,   591,   591,   592,   593,   594,   594,   595,   595,
     596,   596,   598,   597,   599,   600,   600,   601,   601,   602,
     602,   603,   603,   604,   605,   606,   606,   607,   607,   608,
     608,   610,   609,   611,   612,   612,   613,   613,   614,   614,
     615,   615,   616,   617,   617,   618,   618,   619,   619,   621,
     620,   622,   623,   623,   625,   624,   626,   626,   627,   627,
     628,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   654,   655,
     656,   656,   657,   657,   657,   657,   658,   658,   659,   659,
     660,   661,   662,   663,   663,   664,   664,   665,   666,   667,
     667,   668,   668,   669,   670,   670,   671,   671,   672,   673,
     674,   674,   675,   676,   677,   677,   678,   678,   679,   680,
     681,   682,   683,   683,   684,   684,   684,   684,   684,   542,
     556,   570,   685,   685,   686,   687,   688,   689,   689,   690,
     691,   692,   692,   693,   693,   693,   693,   693,   693,   693,
     693,   693,   694,   694,   695,   695,   696,   696,   696,   696,
     696,   696,   696,   696,   697,   698,   699,   700,   700,   701,
     701,   702,   703,   703,   704,   705,   706,   706,   707,   708,
     709,   710,   711,   712,   712,   713,   714,   715,   716,   717,
     718,   718,   719,   720,   721,   722,   723,   724,   725,   725,
     726,   726,   727,   728,   728,   729,   730,   731,   731,   732,
     733,   734,   735,   736,   737,   738,   738,   739,   739,   740,
     741,   741,   742,   742,   743,   744,   744,   745,   746,   747,
     748,   748,   749,   750,   751,   752,   752,   753,   753,   754,
     754,   755,   756,   757,   757,   758,   759,   760,   760,   761,
     762,   763,   764,   765,   765,   766,   766,   767,   768,   768,
     769,   769,   770,   771,   771,   772,   773,   774,   774,   775,
     776,   777,   777,   778,   779,   780,   781,   782,   783,   783,
     784,   784,   785,   786,   786,   787,   788,   789,   789,   790,
     791,   792,   793,   794,   795,   796,   796,   797,   797,   798,
     799,   799,   800,   800,   801,   802,   802,   803,   804,   805,
     805,   806,   807,   808,   808,   809,   809,   809,   810,   811,
     812,   813,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   823,   824,   825,   826,   827,   828,   829,
     830,   830,   831,   832,   833,   834,   834,   835,   836,   837,
     838,   838,   839,   839,   839,   839,   840,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   866,   867,   868,   869,   869,   870,
     871,   872,   872,   873,   874,   875,   875,   876,   877,   878,
     878,   879,   880,   881,   881,   882,   883,   884,   884,   885,
     886,   887,   887,   888,   889,   890,   890,   891,   892,   893,
     893,   894,   895,   896,   896,   897,   898,   899,   900,   900,
     901,   901,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   902,   902,   902,   902,   902,   902,   904,
     903,   905,   905,   907,   906,   908,   908,   910,   909,   912,
     911,   914,   913,   916,   915,   918,   917,   920,   919,   922,
     921,   924,   923,   926,   925,   928,   927,   930,   929,   932,
     931,   933,   934,   935,   937,   936,   939,   938,   941,   940,
     943,   942,   945,   944,   946,   947,   948,   948,   949,   949,
     950,   950,   950,   952,   951,   954,   953,   955,   955,   956,
     955,   957,   957,   958,   958,   959,   960,   962,   961,   963,
     963,   965,   964,   966,   966,   968,   967,   969,   969,   971,
     970,   972,   972,   974,   973,   975,   975,   976,   976,   976,
     976,   976,   976,   976,   976,   976,   976,   976,   976,   976,
     976,   976,   976,   976,   976,   976,   977,   978,   979,   979,
     643,   980,   981,   982,   982,   983,   984,   985,   986,   986,
     987,   988,   989,   990,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1006,  1007,  1008,  1009,  1010,  1010,  1011,  1012,  1013,
    1014,  1015,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1029,  1028,  1030,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1040,
    1041,  1042,  1043,  1044,  1044,  1045,  1046,  1047,  1047,  1048,
    1049,  1050,  1051,  1051,  1052,  1052
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
       0,     1,     3,     3,     1,     1,     2,     1,     3,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     0,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       0,     2,     1,     1,     1,     1,     3,     0,     2,     2,
       1,     1,     1,     1,     3,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     3,     5,
       1,     0,     1,     1,     3,     1,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     0,
       4,     1,     5,     0,     2,     5,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     0,     3,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     4,     0,     5,     0,     5,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     3,     1,     1,     0,     4,     0,     6,     0,     4,
       0,     4,     0,     4,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     0,     4,     0,     4,     1,     2,     0,
       4,     0,     2,     1,     1,     4,     4,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     2,     1,     2,     2,
       1,     3,     2,     1,     2,     2,     1,     2,     4,     1,
       0,     1,     2,     4,     1,     0,     1,     2,     3,     2,
       1,     1,     2,     2,     1,     3,     2,     1,     2,     2,
       1,     3,     2,     1,     3,     0,     4,     0,     2,     2,
       1,     3,     2,     1,     6,     2,     1,     2,     0,     3,
       1,     1,     4,     1,     1,     1,     3,     0,     2,     5,
       1,     1,     0,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   729,     0,     1,   731,    28,     0,     0,
      12,    30,    38,     0,     0,   733,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   730,   736,   734,   738,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   737,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   430,    37,   432,
     732,     0,   707,     0,     0,   740,   741,   705,   706,   739,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   431,   787,   779,   781,   785,   789,   791,   837,   853,
     799,   783,   806,   793,   795,   797,   825,   802,   804,   845,
     841,   849,   769,   773,   777,   815,   808,   810,   812,     0,
     763,   764,   744,   745,   747,   748,   749,   750,   752,   753,
     754,   756,   755,   757,   759,     0,   760,   758,   766,   767,
     768,   742,   818,   743,   746,   765,   761,   762,   751,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,   948,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   444,   447,   429,   442,   443,   699,     0,   715,     0,
     711,     0,     0,     0,   433,   436,   435,   437,   697,   698,
     434,   709,   710,   438,   713,   714,     0,     0,     0,     0,
       0,     0,   839,   855,     0,     0,     0,     0,     0,     0,
     831,     0,   847,   843,   851,     0,     0,     0,     0,     0,
       0,   735,     0,     0,   708,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,   950,     0,     0,     0,     0,   253,     0,   230,
     233,   225,   228,   229,     0,     0,    65,     0,    57,    61,
      63,    62,    64,    75,     0,    67,    71,    73,    72,    74,
      85,    88,    77,    81,    83,    82,    84,   110,     0,   100,
       0,   104,   107,   106,   105,   108,   123,     0,   112,     0,
       0,     0,   116,   121,   120,   122,   118,   117,   119,   137,
       0,   125,     0,     0,   129,   134,   133,   135,   136,   131,
     130,   132,   148,     0,   139,     0,   143,   147,   145,   144,
     146,     0,   150,   154,   156,   155,   157,     0,   169,   173,
     175,   174,   176,   449,     0,   464,   451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   771,     0,   770,   775,     0,   774,     0,   882,   887,
     892,   897,   900,   909,   914,   920,   924,   927,   930,   933,
     935,   940,   943,   946,   877,   903,   906,     0,   857,     0,
     858,     0,   859,     0,   860,     0,   861,     0,   862,     0,
     875,     0,   863,     0,   864,   910,   865,   915,   866,     0,
     867,     0,   868,     0,   869,     0,   870,     0,   871,   872,
       0,   873,     0,   874,     0,     0,     0,   803,   801,   816,
       0,   719,     0,     0,   820,   821,   717,   718,   814,   819,
     822,   687,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,   951,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   445,   446,     0,   450,   700,
     716,   712,     0,     0,     0,     0,     0,     0,   790,   792,
     838,   840,   854,   856,   800,   784,     0,   794,   796,   798,
     827,     0,     0,     0,   826,   832,   833,   834,   805,   846,
     848,   842,   844,   850,   852,   772,   776,     0,   937,   809,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     896,     0,   899,     0,   902,     0,   905,     0,     0,   911,
       0,   916,   921,     0,   919,     0,   923,     0,   926,     0,
     929,     0,   932,     0,   939,     0,   942,     0,   945,   811,
     813,   817,     0,   823,     0,     0,     0,   357,   390,   390,
       0,   955,   957,   949,   953,   954,     0,     0,   368,   232,
     236,   231,   234,   238,     0,   208,    99,    86,    91,    89,
      93,     0,     0,     0,     0,     0,     0,   375,   168,   158,
       0,     0,   161,   187,   177,     0,   180,   635,   475,   506,
     523,   603,   586,   561,   630,   465,   466,   477,   467,   508,
     468,   525,   469,   563,   470,   588,   471,   605,   472,   631,
     473,     0,   463,     0,   448,   695,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   453,   456,   457,   458,
     459,   461,   454,   455,   460,   693,   694,   672,   674,   788,
     780,   782,   786,     0,   828,   829,     0,   390,   778,     0,
       0,     0,   878,     0,   876,     0,   883,     0,   881,     0,
     888,     0,   886,     0,   893,     0,   891,   898,     0,   904,
     907,     0,     0,     0,   922,     0,   928,     0,     0,     0,
       0,   947,   720,     0,   288,     0,   295,   298,   292,     0,
       0,     0,     0,   369,   258,   262,   257,   260,   264,     0,
     237,   222,     0,   206,     0,     0,     0,     0,     0,     0,
     727,     0,     0,   210,   215,   217,   213,   214,   216,   218,
     212,   211,   221,   219,   220,   725,   726,     0,    92,   109,
     370,   371,   372,   373,   374,     0,   164,   398,   159,   162,
     163,   183,   398,   178,   181,   182,     0,   476,     0,   507,
       0,   524,     0,   562,     0,   587,     0,   604,     0,   632,
       0,     0,   636,   462,   390,     0,     0,     0,     0,     0,
       0,     0,   390,   807,     0,     0,     0,   936,   938,     0,
       0,   879,     0,   884,     0,   889,     0,   894,   901,   918,
       0,   908,     0,   913,   925,   931,   934,   941,     0,   824,
     294,   300,     0,   317,   363,   364,   952,   956,   960,   958,
     962,     0,   263,   248,     0,   235,     0,     0,     0,   239,
     245,   242,   243,   244,   241,   240,   247,   246,   223,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,    90,
      94,    96,    95,     0,     0,     0,   166,   396,   397,     0,
     185,     0,   703,     0,     0,   478,   479,   480,   701,   702,
       0,   509,   510,   511,     0,   526,   527,   528,     0,   564,
     565,   566,     0,   589,   590,   591,     0,   606,   607,   608,
       0,     0,     0,   634,   696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   830,   836,   835,   376,   880,   885,
     890,   895,   912,   917,     0,     0,   296,   319,   336,     0,
     961,   275,     0,   261,     0,   265,   270,   272,   268,   269,
     271,   273,   267,   266,   274,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   728,     0,    98,   673,     0,
       0,   167,   165,   401,   399,   403,   186,   184,   485,   474,
     482,     0,     0,     0,   513,   505,   530,   522,   568,   560,
     593,   585,   610,   602,     0,     0,   640,     0,     0,   389,
     678,   691,   692,   679,   680,   681,   682,   690,     0,   308,
     312,     0,     0,   301,   302,   303,   299,   306,     0,   338,
     297,     0,   964,   965,   963,   276,     0,     0,     0,     0,
     377,   384,   378,   385,   380,   381,   689,     0,   412,     0,
     408,   409,   410,     0,   402,   492,     0,     0,     0,   488,
     398,   484,   486,   487,   704,     0,     0,     0,   532,     0,
     570,     0,     0,     0,   612,     0,   633,   629,   671,   648,
     655,     0,     0,   641,   944,   309,   312,   310,     0,     0,
       0,   327,   331,     0,     0,   320,   321,   322,   318,   325,
       0,     0,     0,   382,   386,   379,     0,     0,   411,     0,
     400,     0,   404,   406,   405,   481,   499,   483,     0,   495,
     398,   491,   493,   494,   490,     0,   675,   516,   514,     0,
     512,   534,   531,     0,   529,   572,   569,     0,   567,   596,
     594,     0,   592,   614,   611,     0,   609,     0,     0,   649,
     644,   398,   639,   642,   643,   307,   311,     0,     0,     0,
     328,   331,   329,     0,     0,     0,   345,   349,     0,     0,
     339,   340,   337,   343,   341,   959,   383,   677,   413,     0,
       0,   502,   416,   498,   500,   501,   497,     0,   489,   519,
     398,   515,   517,   518,   537,   540,   533,   535,   536,   575,
     577,   571,   573,   574,   599,   398,   595,   597,   598,   617,
     619,   613,   615,   616,   638,   658,   637,   656,   660,   652,
     398,   647,   650,   651,   646,     0,     0,     0,   305,   304,
     326,   330,     0,     0,     0,   346,   349,   347,     0,     0,
       0,   407,     0,     0,   504,   414,   415,     0,   496,   521,
       0,     0,   539,     0,   601,     0,     0,     0,   659,   654,
       0,   645,     0,   315,     0,   313,     0,     0,   324,   323,
     344,   348,     0,     0,     0,   688,     0,   419,   417,   420,
     503,   520,   538,   543,   541,   545,   580,   576,   578,     0,
     600,   622,   618,   620,   623,   668,   447,   657,   666,   667,
     390,   390,   661,   662,   663,   664,   665,   653,     0,   316,
       0,   334,     0,   332,     0,     0,   362,   342,   427,     0,
     423,   424,   425,     0,   421,     0,   544,   583,     0,   579,
     581,   582,     0,   464,     0,     0,     0,   314,     0,   335,
       0,   352,     0,   350,     0,   426,   390,   418,   551,   553,
     542,   549,   550,     0,     0,   546,   547,   548,     0,     0,
     723,     0,   624,   621,   627,   626,   625,   721,   722,   670,
     669,   390,   390,   333,     0,   353,   428,     0,     0,     0,
     390,   584,     0,     0,   683,   684,   351,   422,   552,   556,
     554,   557,     0,     0,   628,   724,     0,     0,   558,   676,
     686,   390,     0,   555,     0,     0,   685,   559
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   699,   700,   857,   858,   970,   969,   697,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   711,   868,   869,   870,   975,  1072,   709,
     158,   159,   259,   260,   419,   418,   583,   584,   715,   873,
     874,   875,   979,  1077,   714,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     694,   695,   843,   833,   125,   126,   235,   341,   342,   343,
     691,   557,   692,   693,   829,   830,   949,   945,   232,   233,
     336,   553,   554,   555,   826,   687,   827,   828,   941,   942,
    1045,  1043,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   676,   818,   932,   933,  1035,  1113,  1114,
    1115,  1116,  1117,  1176,  1177,  1178,  1317,  1355,  1038,  1118,
    1185,  1186,  1187,  1188,  1189,  1251,  1252,  1253,  1357,  1403,
    1120,  1190,  1260,  1261,  1262,  1263,  1326,  1327,  1328,  1405,
    1433,   122,   123,   542,   331,   543,  1264,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     632,   844,   845,   950,   846,   847,   952,  1049,   848,   849,
     953,   224,  1014,   225,   326,   976,   977,  1074,  1075,  1143,
    1144,  1202,  1200,   978,  1140,  1141,  1142,  1334,  1335,  1368,
    1369,  1413,  1437,  1336,  1410,  1411,  1412,    98,    99,   160,
     161,   274,   263,   264,   265,   424,   425,   426,   587,   588,
     755,   744,   586,   725,   726,   727,   876,   877,   985,  1079,
    1146,  1080,  1081,  1151,  1152,  1153,  1215,  1147,  1148,  1211,
    1212,  1213,  1277,  1207,  1208,  1273,  1274,  1275,  1337,   728,
     729,   878,   879,   991,  1085,  1157,  1218,  1219,  1281,  1282,
    1283,  1340,   730,   731,   880,   881,   995,  1087,  1159,  1222,
    1223,  1286,  1287,  1288,  1341,  1342,  1374,  1375,  1415,  1416,
    1445,  1440,  1441,  1442,  1468,  1480,  1481,  1487,  1493,   732,
     733,   882,   883,   999,  1089,  1161,  1226,  1227,  1291,  1292,
    1293,  1343,  1378,  1379,  1419,  1420,  1421,   734,   735,   884,
     885,  1003,  1091,  1163,  1230,  1231,  1296,  1297,  1298,  1345,
     736,   737,   886,   887,  1007,  1093,  1165,  1234,  1235,  1301,
    1302,  1303,  1346,  1383,  1384,  1422,  1452,  1453,   738,   739,
     888,  1167,   740,   741,   891,  1013,  1306,  1097,  1098,  1172,
    1242,  1243,  1244,  1315,  1170,  1171,  1238,  1311,  1312,  1313,
    1350,  1237,  1307,  1308,  1347,  1348,  1392,  1387,  1388,  1389,
    1424,   892,   275,   712,   276,   986,  1446,  1070,   756,   757,
     758,   759,   760,  1393,  1394,  1488,  1447,   105,  1203,   852,
     761,   762,   763,   764,   765,   766,   277,   278,   279,   987,
     988,   989,   106,   107,   108,   280,   281,   282,   283,   284,
     285,   525,   526,   527,  1456,  1457,  1458,   854,   855,   856,
       7,     8,    15,    25,    46,    47,    67,    68,   109,   189,
     190,   305,   453,   191,   306,   456,   192,   307,   193,   287,
     194,   288,   195,   295,   196,   289,   197,   286,   198,   290,
     199,   291,   200,   297,   201,   298,   202,   299,   203,   294,
     204,   205,   518,   206,   301,   207,   296,   208,   308,   209,
     309,   210,   310,   211,   212,   528,   313,   529,   530,   813,
     213,   300,   614,   904,   446,   615,   616,   617,   214,   292,
     438,   215,   303,   449,   216,   302,   448,   217,   304,   450,
     218,   293,   439,   477,   478,   479,   784,   480,   481,   788,
     634,   482,   483,   792,   636,   484,   485,   796,   638,   486,
     487,   640,   488,   489,   642,   490,   491,   644,   492,   493,
     646,   494,   495,   648,   921,   496,   497,   650,   923,   649,
     498,   499,   654,   500,   501,   656,   502,   503,   658,   504,
     505,   660,   506,   507,   662,   508,   628,   779,   509,   510,
     664,   511,   512,   666,   513,   514,   668,   333,   334,   548,
     549,   683,   684,   685,   822,   939,   940,  1039,  1040,  1124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1314
static const yytype_int16 yypact[] =
{
      -1, -1314,    67,  -203,   106, -1314, -1314,   -93,  -171,   136,
   -1314, -1314,   100,    -9,   155, -1314,   159,    63, -1314,   -74,
     158,   169,   144, -1314,   175,  -212,   177, -1314, -1314, -1314,
   -1314, -1314,   107,   181,   185,   195, -1314,   191, -1314, -1314,
   -1314, -1314, -1314,   199, -1314, -1314, -1314, -1314,   192,    37,
   -1314,   213,   267, -1314,   -38, -1314, -1314, -1314,   206, -1314,
   -1314, -1314, -1314, -1314,   209,    77,   208,   214,   -50, -1314,
   -1314,   193,   234,   238,   241,   249, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314,   235, -1314,   207, -1314, -1314, -1314,
   -1314,    30,   130,   289,   301, -1314, -1314, -1314, -1314, -1314,
   -1314,   617, -1314,   306,   305, -1314, -1314, -1314, -1314, -1314,
   -1314,   309,   320,   322, -1314, -1314, -1314, -1314, -1314, -1314,
     257,   328,   273,   272, -1314,   124,   182,   379,   280, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
     282,   129, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,    73,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314,   617, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   425,
     396,   438,   446,   467,   482,    39, -1314,   483, -1314, -1314,
   -1314, -1314,    53,   231,   484,   290, -1314,   410, -1314, -1314,
   -1314, -1314, -1314,   292,   -16,   326,   -16,   329,   -16,   331,
      21,   335,    89,   356,    84,   358,    47,   429,   -16,   450,
     -16, -1314,   287, -1314, -1314, -1314, -1314,   491, -1314,   492,
   -1314,   493,   489,   490, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,   617,   617,   617,   617,
     617,   617, -1314, -1314,   617,   617,   617,   617,   617,   617,
   -1314,   617, -1314, -1314, -1314,   360,   362,   617,   154,   154,
     154, -1314,   151,    33, -1314,   494, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,   497,   426, -1314,
     427,    94, -1314,   263,   198,   505,   364, -1314,   509, -1314,
   -1314, -1314, -1314, -1314,   513,   128, -1314,   487, -1314, -1314,
   -1314, -1314, -1314, -1314,   466, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   485, -1314,
     517, -1314, -1314, -1314, -1314, -1314, -1314,   481, -1314,   534,
     536,   538, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
     495, -1314,   542,   544, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314,   498, -1314,   553, -1314, -1314, -1314, -1314,
   -1314,   486, -1314, -1314, -1314, -1314, -1314,   488, -1314, -1314,
   -1314, -1314, -1314, -1314,   357, -1314, -1314,   552,   555,   556,
     559,   560,   617,   617,   617,   617,   239,   240,   295,   334,
     233,   236,   617,   229,   228,   227,    40,   224,   407,   444,
     501, -1314,   217, -1314, -1314,   216, -1314,   617, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,   211, -1314,    13,
   -1314,   386, -1314,   388, -1314,   390, -1314,   154, -1314,   154,
   -1314,   617, -1314,   154, -1314,   174, -1314,   174, -1314,   371,
   -1314,   154, -1314,   154, -1314,   154, -1314,   154, -1314, -1314,
     617, -1314,   617, -1314,   154,   212,   215, -1314, -1314, -1314,
     218, -1314,   583,   585, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314,  -281,  -281,   581, -1314, -1314,   458, -1314,   508,
     587,   588, -1314, -1314, -1314, -1314, -1314,   590,   375, -1314,
     593, -1314, -1314, -1314, -1314, -1314,   592,   137, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,   540,   531, -1314,   596,
   -1314, -1314,   597,   598, -1314,   600,   601, -1314,   602, -1314,
     545,   503, -1314,   546,   503, -1314,    87,   381,   135, -1314,
   -1314, -1314,   605,   607,   297,   307,   285,   293, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,   617, -1314, -1314, -1314,
   -1314,   586,   615,   623, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,   269, -1314, -1314,
     627,   629,   383,   631,   385,   633,   387,   635,   389,   271,
   -1314,   154, -1314,   245, -1314,   247, -1314,   646,   659, -1314,
     661, -1314, -1314,   294, -1314,   154, -1314,   288, -1314,   154,
   -1314,   154, -1314,   154, -1314,   617, -1314,   284, -1314, -1314,
   -1314, -1314,   670, -1314,   669,   681,   394, -1314, -1314, -1314,
     680, -1314, -1314, -1314, -1314, -1314,   682,   152, -1314, -1314,
   -1314, -1314, -1314, -1314,   402,   109, -1314, -1314, -1314, -1314,
   -1314,   684,   686,   688,   690,   692,   694, -1314, -1314, -1314,
     696,   404, -1314, -1314, -1314,   408, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   283,
   -1314,   523, -1314,   506, -1314, -1314,   705,   702,   704,   706,
     707,   708,   709,   710,   711, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314,   373, -1314, -1314,   714, -1314, -1314,   131,
     715,   716, -1314,   325, -1314,   721, -1314,   479, -1314,   727,
   -1314,   499, -1314,   729, -1314,   522, -1314, -1314,   361, -1314,
   -1314,   731,   154,   154, -1314,   359, -1314,   353,   355,   363,
     617, -1314, -1314,   739, -1314,   741, -1314,   515, -1314,   743,
     747,   751,  -238, -1314, -1314, -1314, -1314, -1314, -1314,   412,
      29, -1314,   532, -1314,   778,   780,   782,   784,   786,   788,
   -1314,   795,   794, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,   414,   -35, -1314,
   -1314, -1314, -1314, -1314, -1314,   798, -1314,   697, -1314, -1314,
   -1314, -1314,   697, -1314, -1314, -1314,   797,   -52,   799,   -52,
     801,   -52,   803,   -52,   805,   -52,   808,   -52,   810, -1314,
     815,   814, -1314, -1314, -1314,   800,   821,   823,   825,   827,
     829,   831, -1314, -1314,   507,   833,   835, -1314, -1314,   837,
     839, -1314,   841, -1314,   843, -1314,   845, -1314, -1314, -1314,
     496, -1314,   459, -1314, -1314, -1314, -1314, -1314,   617, -1314,
   -1314, -1314,   776,   604, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314,   416,   116, -1314,   609, -1314,   853,   859,   863, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   867,
     869,   870,   871,   872,   873,   874,   875, -1314,   809, -1314,
   -1314, -1314, -1314,   876,   685,   812, -1314,   774, -1314,   813,
   -1314,   652, -1314,   886,   882, -1314, -1314, -1314, -1314, -1314,
     652, -1314, -1314, -1314,   652, -1314, -1314, -1314,   652, -1314,
   -1314, -1314,   652, -1314, -1314, -1314,   652, -1314, -1314, -1314,
     154,   885,   683, -1314, -1314,    25,   884,   887,   888,   889,
     890,   891,   892,   893, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314,   154,    42, -1314, -1314,   628,   895,
     -50, -1314,   644, -1314,   896, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,   902,   904,   906,   908,
     910,   912,   914,   918,   920, -1314,   922, -1314, -1314,   924,
     418, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
     677,   420,   951,   955,   677, -1314,   677, -1314,   677, -1314,
     677, -1314,   677, -1314,   719,   957, -1314,   754,   503, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   573, -1314,
     701,   965,   967, -1314, -1314, -1314, -1314, -1314,    54, -1314,
   -1314,   154, -1314, -1314, -1314, -1314,   971,   973,   975,   977,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,   981, -1314,    35,
   -1314, -1314, -1314,   968,   242, -1314,   771,   752,   432, -1314,
     697, -1314, -1314, -1314, -1314,   982,   753,   772,   756,   769,
     757,   767,   759,   773,   760,   777, -1314, -1314, -1314, -1314,
   -1314,   503,   434, -1314, -1314, -1314,   730, -1314,   735,   998,
     999, -1314,   744,  1000,  1001, -1314, -1314, -1314, -1314, -1314,
      58,   695,  1003, -1314, -1314, -1314,  1004,   894, -1314,  1007,
   -1314,  1006, -1314, -1314, -1314, -1314, -1314, -1314,   442, -1314,
     697, -1314, -1314, -1314, -1314,   781, -1314, -1314, -1314,   445,
   -1314, -1314, -1314,   447, -1314, -1314, -1314,   453, -1314, -1314,
   -1314,   455, -1314, -1314, -1314,   457, -1314,   261,   461, -1314,
   -1314,   697, -1314, -1314, -1314, -1314, -1314,   824,  1008,  1010,
   -1314,   745, -1314,   761,  1015,  1016, -1314,   758,  1017,  1018,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   915,
    1021, -1314,   903, -1314, -1314, -1314, -1314,   791, -1314, -1314,
     697, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314,   697, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
     697, -1314, -1314, -1314, -1314,   818,  1023,   463, -1314, -1314,
   -1314, -1314,   838,  1024,  1026, -1314,   770, -1314,   779,  1029,
    1031, -1314,  1032,   685, -1314,   927, -1314,   804, -1314, -1314,
     806,   807,   929,   -46, -1314,   811,   -41,   468,   -33, -1314,
     834, -1314,  1037, -1314,   785, -1314,  1041,   470, -1314, -1314,
   -1314, -1314,   850,  1042,  1044, -1314,   472, -1314, -1314,   857,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   474,
   -1314, -1314, -1314, -1314, -1314, -1314,   287, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,  1047, -1314,
    1050, -1314,   802, -1314,  1049,   476, -1314, -1314, -1314,    68,
   -1314, -1314, -1314,  1048, -1314,   478,  -120, -1314,   617, -1314,
   -1314, -1314,    26, -1314,   848,  1054,  1055, -1314,  1056, -1314,
    1057, -1314,   816, -1314,   944, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314,  1058,  1059, -1314, -1314, -1314,   956,  1062,
   -1314,  1067, -1314, -1314, -1314, -1314, -1314, -1314, -1314,    87,
   -1314, -1314, -1314, -1314,  1065, -1314, -1314,   961,   -40,  1069,
   -1314, -1314,   963,  1070, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314,   878,  1071,  1073, -1314, -1314,  1074,  1072, -1314, -1314,
   -1314, -1314,  1078, -1314,  1077,   844, -1314, -1314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314,   762, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314,   -89, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,  -163, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,  -237, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314,   840,   842, -1314, -1314, -1314, -1314,
   -1314,   149,   150, -1314,  -760, -1314, -1314, -1314,   153,   156,
   -1314,  -567, -1313,  -319, -1314,  -863, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314,  -293, -1314, -1314, -1314,
   -1314, -1314,  -326, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314,  -826, -1314, -1314, -1314, -1314, -1314,  -820, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314,  -236,  -579,  -233,  -614, -1314,  -234, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314,    60,  -321,  -801,
   -1314, -1314, -1314, -1314, -1314, -1314,  -218, -1314, -1314,  -554,
   -1314, -1314,  -708, -1314, -1314,  -246, -1314, -1314,  -310, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,  -205,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314,  -303, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,   606,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314,
   -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314, -1314
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     312,   532,   533,   524,   702,   716,   515,   516,   350,   980,
     357,   351,   364,   358,   373,   365,   386,   374,   399,   387,
     408,   400,   414,   409,   420,   415,   352,   421,   359,   956,
     366,   889,   375,  1099,   388,   630,   401,  1449,   410,  1197,
     416,     1,   422,   519,   520,   320,   321,    70,    71,   370,
     610,   611,  1109,  1110,    72,    73,   838,   971,  1443,   946,
     405,   947,   948,  1111,  1181,  1182,  1376,     5,  1256,  1257,
     951,  1381,  1434,  1478,   937,  1183,   938,  1425,  1426,  1258,
    1444,   432,   433,   434,   435,   436,   437,   102,   103,   440,
     441,   442,   443,   444,   445,    44,   447,    45,   268,   269,
     268,   269,   457,     6,   538,   539,    27,    28,    11,   982,
     983,   819,   820,   540,   541,   266,   267,   984,   379,   380,
       9,   392,   393,   379,   380,   381,   270,   271,   322,   323,
     324,   325,   834,   835,   836,   837,   838,    14,   839,   834,
     835,   836,   837,   838,    16,   104,    18,  1044,  1474,  1475,
     272,   273,   266,   267,    38,    39,  1198,  1390,  1391,    21,
     266,   267,   842,    24,  1084,    26,   268,   269,  1086,  1450,
    1451,    31,  1088,    34,   521,   522,  1090,    37,   266,   267,
    1092,    43,  1048,    50,   639,    48,   641,   272,   273,  1435,
     645,    53,    54,    58,  1377,   272,   273,    64,   655,  1382,
     657,  1479,   659,    69,   661,    59,    60,    66,   631,    90,
     906,   667,    93,   272,   273,   266,   267,    95,  1112,   100,
     266,   267,  1201,   842,  1184,   101,   842,   594,   595,   596,
     597,  1259,    74,   601,   603,   612,    75,   606,   110,   613,
     266,   267,   111,   620,   622,   624,   112,   266,   267,   113,
     272,   273,   627,    82,    83,   272,   273,   114,   840,   841,
     266,   267,   268,   269,  1156,   992,  1158,   996,  1160,  1000,
    1162,  1004,  1164,  1008,   115,   272,   273,    85,    86,    96,
      97,   124,   272,   273,   118,   119,   643,  1214,   270,   271,
     238,   239,   261,   262,   717,   272,   273,   130,   745,   746,
     339,   340,   346,   347,   718,   663,   842,   665,   719,   219,
     720,   127,   721,   220,   722,   221,   723,   747,   748,   749,
     750,   751,   752,   753,   754,   993,   222,   997,   223,  1001,
     724,  1005,  1123,  1009,   226,  1023,   353,   354,   798,   360,
     361,   367,   368,  1204,   227,   376,   377,  1276,   131,   132,
     229,   133,   805,   134,   230,   135,   807,   136,   808,   137,
     809,   138,   234,   139,   332,   140,   389,   390,   402,   403,
     451,   452,   454,   455,   551,   552,   559,   560,  1314,   231,
     458,   652,   653,   311,   459,   681,   682,   237,   460,   689,
     690,   742,   743,   782,   783,   786,   787,   790,   791,   794,
     795,   773,   315,   458,   816,   817,   775,   459,   824,   825,
     335,   460,   831,   832,   866,   867,   344,  1339,   871,   872,
     102,   103,   943,   944,   967,   968,  1041,  1042,  1138,  1139,
    1149,  1150,  1344,   314,   322,   323,   324,   325,  1201,   842,
     411,   523,  1209,  1210,  1240,  1241,   316,  1349,   322,   323,
     324,   325,  1271,  1272,   317,  1279,  1280,  1284,  1285,   850,
     810,   417,   851,  1289,  1290,  1294,  1295,  1299,  1300,  1304,
    1305,  1309,  1310,  1353,  1354,   318,   908,   853,  1385,  1386,
    1401,  1402,  1408,  1409,  1417,  1418,  1431,  1432,  1438,  1439,
     319,   327,   338,   423,   427,   428,   429,   430,   431,   920,
     922,   517,   531,   534,   461,   535,   462,   537,   463,   546,
     464,   547,   465,   550,   466,   556,   467,   565,   468,  1173,
     469,   558,   470,   907,   471,   569,   472,   461,   473,   462,
     474,   463,   475,   464,   476,   465,   564,   466,   570,   467,
     568,   468,   571,   469,   572,   470,   573,   471,   972,   472,
     575,   473,   576,   474,   574,   475,   578,   476,   579,   577,
     589,   585,   582,   590,   591,   592,   593,   598,  1414,   604,
     599,   607,   608,   609,   605,  1015,   618,   625,   626,   629,
     647,   633,   669,   635,   671,   637,   672,   670,   673,   674,
     675,   677,  1239,   696,   954,   678,   679,   955,   680,   686,
     688,   698,   701,   703,   704,   928,   705,   706,   708,   771,
     707,   713,   957,   767,   162,   768,   163,   769,   164,   772,
     165,  1455,   166,   776,   167,   710,   168,   600,   169,   770,
     170,   777,   171,   778,   172,   780,   173,   781,   174,   785,
     175,   789,   176,   793,   177,   797,   178,   799,   179,   801,
     180,   800,   181,   162,   182,   163,   183,   164,   184,   165,
     185,   166,   186,   167,   187,   168,   188,   169,   602,   170,
     802,   171,   803,   172,   806,   173,   804,   174,   812,   175,
     814,   176,   811,   177,   815,   178,   821,   179,   890,   180,
     823,   181,   859,   182,   860,   183,   861,   184,   862,   185,
     863,   186,   864,   187,   865,   188,  1052,  1094,   894,  1053,
     895,   893,   896,   903,   897,   898,   899,   900,   901,   902,
     905,   909,   910,  1034,  1054,   911,   162,   912,   163,   913,
     164,  1108,   165,   914,   166,   916,   167,   918,   168,   919,
     169,   925,   170,   924,   171,   926,   172,   929,   173,   930,
     174,   934,   175,   915,   176,   935,   177,   927,   178,   936,
     179,   619,   180,   162,   181,   163,   182,   164,   183,   165,
     184,   166,   185,   167,   186,   168,   187,   169,   188,   170,
     917,   171,   958,   172,   931,   173,   959,   174,   960,   175,
     961,   176,   962,   177,   963,   178,   964,   179,   965,   180,
     621,   181,   966,   182,   973,   183,  1016,   184,   981,   185,
     990,   186,   994,   187,   998,   188,  1002,   974,  1191,  1006,
     162,  1010,   163,  1011,   164,  1012,   165,  1017,   166,  1018,
     167,  1019,   168,  1020,   169,  1021,   170,  1022,   171,  1033,
     172,  1025,   173,  1026,   174,  1027,   175,  1028,   176,  1029,
     177,  1030,   178,  1031,   179,  1024,   180,  1036,   181,   623,
     182,  1056,   183,  1055,   184,  1037,   185,  1057,   186,  1467,
     187,  1058,   188,  1059,  1032,  1060,  1061,  1062,  1063,  1064,
    1067,  1066,  1065,  1069,  1068,  1071,  1073,  1078,  1076,  1082,
    1083,  1095,  1100,  1119,  1096,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1125,  1483,  1126,   162,  1121,   163,  1127,   164,
    1128,   165,  1129,   166,  1145,   167,  1130,   168,  1131,   169,
    1132,   170,  1133,   171,  1494,   172,  1134,   173,  1135,   174,
    1136,   175,  1137,   176,   774,   177,   162,   178,   163,   179,
     164,   180,   165,   181,   166,   182,   167,   183,   168,   184,
     169,   185,   170,   186,   171,   187,   172,   188,   173,  1154,
     174,  1155,   175,  1166,   176,  1168,   177,  1169,   178,  1174,
     179,  1175,   180,  1179,   181,  1180,   182,  1192,   183,  1199,
     184,  1193,   185,  1194,   186,  1195,   187,  1196,   188,  1205,
    1216,  1206,  1217,  1224,  1220,  1221,  1225,  1228,  1229,  1233,
    1245,  1232,  1247,  1236,  1248,  1249,  1250,  1320,  1254,  1255,
    1265,  1266,  1267,  1269,  1270,  1268,  1318,  1278,  1319,  1316,
    1322,  1323,  1324,  1333,  1325,  1329,  1330,  1332,  1331,  1338,
    1351,  1352,  1358,  1356,  1359,  1363,  1360,  1364,  1396,  1367,
    1365,  1373,  1362,  1398,  1370,  1404,  1371,  1372,  1397,  1400,
    1406,  1380,  1407,  1399,   842,  1427,  1428,  1430,  1460,  1436,
    1461,  1462,  1429,  1464,  1463,  1466,  1469,  1470,  1472,  1471,
    1473,  1015,  1015,  1476,  1477,  1482,  1484,  1486,  1485,  1489,
    1465,  1490,  1491,  1492,  1495,  1496,  1497,  1246,  1321,  1361,
     536,  1046,  1047,  1423,   395,  1050,   396,  1459,  1051,  1366,
    1122,  1454,  1395,   651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1015,  1015,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1448
};

static const yytype_int16 yycheck[] =
{
     205,   320,   321,   313,   571,   584,   309,   310,   244,   872,
     246,   244,   248,   246,   250,   248,   252,   250,   254,   252,
     256,   254,   258,   256,   260,   258,   244,   260,   246,   830,
     248,   739,   250,     8,   252,    22,   254,    11,   256,     4,
     258,    42,   260,    10,    11,     6,     7,    10,    11,    28,
      10,    11,    10,    11,    17,    18,    27,   858,   178,    30,
      13,    32,    33,    21,    10,    11,   112,     0,    10,    11,
     830,   112,     4,   113,   312,    21,   314,  1390,  1391,    21,
     200,   286,   287,   288,   289,   290,   291,   137,   138,   294,
     295,   296,   297,   298,   299,   307,   301,   309,   133,   134,
     133,   134,   307,   306,    10,    11,    43,    44,   201,   161,
     162,   678,   679,    19,    20,   131,   132,   169,    34,    35,
      14,    37,    38,    34,    35,    36,   159,   160,   409,   410,
     411,   412,    23,    24,    25,    26,    27,   308,    29,    23,
      24,    25,    26,    27,     8,   195,    46,    31,  1461,  1462,
     166,   167,   131,   132,    10,    11,   121,   190,   191,   168,
     131,   132,   197,     8,   990,     6,   133,   134,   994,   143,
     144,   245,   998,    15,   141,   142,  1002,     8,   131,   132,
    1006,     6,   942,    76,   487,     8,   489,   166,   167,   121,
     493,    10,    11,     8,   240,   166,   167,     6,   501,   240,
     503,   241,   505,    11,   507,    10,    11,     8,   195,   247,
     777,   514,     6,   166,   167,   131,   132,     8,   176,    11,
     131,   132,   196,   197,   170,    11,   197,   432,   433,   434,
     435,   173,   195,   438,   439,   195,   199,   442,    45,   199,
     131,   132,     8,   448,   449,   450,     8,   131,   132,     8,
     166,   167,   457,    40,    41,   166,   167,     8,   149,   150,
     131,   132,   133,   134,  1084,   879,  1086,   881,  1088,   883,
    1090,   885,  1092,   887,    39,   166,   167,    10,    11,   202,
     203,   251,   166,   167,    77,    78,   491,  1150,   159,   160,
      10,    11,    10,    11,   207,   166,   167,     8,   163,   164,
      10,    11,    10,    11,   217,   510,   197,   512,   221,     3,
     223,   181,   225,     8,   227,     6,   229,   182,   183,   184,
     185,   186,   187,   188,   189,   879,     6,   881,     6,   883,
     243,   885,  1040,   887,    77,   902,    10,    11,   641,    10,
      11,    10,    11,  1144,    16,    10,    11,  1210,    47,    48,
      77,    50,   655,    52,    82,    54,   659,    56,   661,    58,
     663,    60,   180,    62,   311,    64,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   248,   249,  1241,   255,
     249,    10,    11,   310,   253,    10,    11,     8,   257,   252,
     253,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   606,     6,   249,    10,    11,   611,   253,   256,   257,
     179,   257,    10,    11,    10,    11,     6,  1280,    10,    11,
     137,   138,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,  1295,     8,   409,   410,   411,   412,   196,   197,
      11,   408,    10,    11,    10,    11,     8,  1310,   409,   410,
     411,   412,    10,    11,     8,    10,    11,    10,    11,   695,
     665,    11,   695,    10,    11,    10,    11,    10,    11,   208,
     209,    10,    11,    10,    11,     8,   779,   695,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       8,     8,     8,   206,     3,     3,     3,     8,     8,   802,
     803,   350,     8,     6,   373,    79,   375,    80,   377,   246,
     379,   313,   381,     8,   383,     6,   385,    51,   387,  1098,
     389,     8,   391,   392,   393,     8,   395,   373,   397,   375,
     399,   377,   401,   379,   403,   381,    49,   383,    57,   385,
      55,   387,     8,   389,     8,   391,     8,   393,   858,   395,
       8,   397,     8,   399,    59,   401,     3,   403,    72,    61,
       8,   204,    74,     8,     8,     6,     6,   328,  1369,   336,
     330,   342,   344,   346,   338,   894,   352,   360,   362,   368,
     406,   195,   370,   195,   366,   195,     3,   372,     3,     8,
     132,    83,  1171,    53,   830,     8,     8,   830,     8,     6,
       8,    70,     6,     6,     6,   810,     6,     6,    63,   324,
       8,    65,   830,     8,   319,     8,   321,   320,   323,   326,
     325,  1422,   327,     8,   329,   122,   331,   332,   333,   322,
     335,     8,   337,   364,   339,     8,   341,     8,   343,     8,
     345,     8,   347,     8,   349,   374,   351,   402,   353,     3,
     355,   404,   357,   319,   359,   321,   361,   323,   363,   325,
     365,   327,   367,   329,   369,   331,   371,   333,   334,   335,
      11,   337,    11,   339,   386,   341,   382,   343,     8,   345,
      11,   347,   398,   349,     3,   351,     6,   353,   165,   355,
       8,   357,     8,   359,     8,   361,     8,   363,     8,   365,
       8,   367,     8,   369,     8,   371,   942,  1010,     3,   942,
       8,   205,     8,   340,     8,     8,     8,     8,     8,     8,
       6,     6,     6,   928,   942,   400,   319,     6,   321,   250,
     323,  1034,   325,     6,   327,     6,   329,   376,   331,     8,
     333,   388,   335,   384,   337,   390,   339,     8,   341,     8,
     343,     8,   345,   254,   347,     8,   349,   394,   351,     8,
     353,   354,   355,   319,   357,   321,   359,   323,   361,   325,
     363,   327,   365,   329,   367,   331,   369,   333,   371,   335,
     258,   337,   250,   339,   269,   341,     8,   343,     8,   345,
       8,   347,     8,   349,     8,   351,     8,   353,     3,   355,
     356,   357,     8,   359,     6,   361,     6,   363,    11,   365,
      11,   367,    11,   369,    11,   371,    11,   120,  1121,    11,
     319,    11,   321,     8,   323,    11,   325,     6,   327,     6,
     329,     6,   331,     6,   333,     6,   335,     6,   337,   380,
     339,     8,   341,     8,   343,     8,   345,     8,   347,     8,
     349,     8,   351,     8,   353,   348,   355,    81,   357,   358,
     359,     8,   361,   254,   363,   261,   365,     8,   367,  1436,
     369,     8,   371,     6,   378,     6,     6,     6,     6,     6,
      71,     6,     8,   198,     8,    73,   112,   235,    75,     3,
       8,     6,     8,   265,   211,     8,     8,     8,     8,     8,
       8,     8,   258,  1470,     8,   319,    11,   321,     6,   323,
       6,   325,     6,   327,   237,   329,     8,   331,     8,   333,
       8,   335,     8,   337,  1491,   339,     8,   341,     8,   343,
       8,   345,     8,   347,   348,   349,   319,   351,   321,   353,
     323,   355,   325,   357,   327,   359,   329,   361,   331,   363,
     333,   365,   335,   367,   337,   369,   339,   371,   341,     8,
     343,     6,   345,   244,   347,     8,   349,   213,   351,   396,
     353,   270,   355,     8,   357,     8,   359,     6,   361,    11,
     363,     8,   365,     8,   367,     8,   369,     6,   371,   218,
       8,   239,   239,   224,   222,   239,   239,   230,   239,   239,
     270,   228,   267,   226,     6,     6,   262,   262,     8,     8,
     315,     8,     8,     6,     8,   121,     8,   236,     8,   195,
     259,     6,     6,   120,   266,     8,     8,     6,   113,   238,
     212,     8,     8,   195,     8,     6,   266,     6,  1348,   112,
       8,   112,   263,     6,   240,   195,   240,   240,   214,     8,
       8,   240,     8,   268,   197,     8,     6,     8,   210,    11,
       6,     6,   260,     6,     8,   121,     8,     8,     6,   113,
       3,  1390,  1391,     8,   113,     6,   113,   199,     8,     8,
     264,     8,     8,    11,     6,     8,   242,  1176,  1251,  1326,
     328,   942,   942,  1386,   254,   942,   254,  1423,   942,  1333,
    1040,  1422,  1348,   497,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1461,  1462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1418
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    42,   414,   418,   419,     0,   306,   893,   894,    14,
     420,   201,   431,   432,   308,   895,     8,   421,    46,   438,
     439,   168,   433,   632,     8,   896,     6,    43,    44,   422,
     423,   245,   528,   529,    15,   440,   633,     8,    10,    11,
     434,   435,   436,     6,   307,   309,   897,   898,     8,   425,
      76,   575,   576,    10,    11,   530,   531,   532,     8,    10,
      11,   441,   442,   443,     6,   437,     8,   899,   900,    11,
      10,    11,    17,    18,   195,   199,   424,   426,   427,   428,
     429,   430,    40,    41,   415,    10,    11,   577,   578,   579,
     247,   533,   534,     6,   444,     8,   202,   203,   680,   681,
      11,    11,   137,   138,   195,   860,   875,   876,   877,   901,
      45,     8,     8,     8,     8,    39,   416,   417,    77,    78,
     580,   581,   624,   625,   251,   547,   548,   181,   535,   634,
       8,    47,    48,    50,    52,    54,    56,    58,    60,    62,
      64,   445,   446,   447,   452,   453,   458,   459,   473,   474,
     480,   481,   486,   487,   492,   493,   498,   499,   513,   514,
     682,   683,   319,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   353,
     355,   357,   359,   361,   363,   365,   367,   369,   371,   902,
     903,   906,   909,   911,   913,   915,   917,   919,   921,   923,
     925,   927,   929,   931,   933,   934,   936,   938,   940,   942,
     944,   946,   947,   953,   961,   964,   967,   970,   973,     3,
       8,     6,     6,     6,   654,   656,    77,    16,   582,    77,
      82,   255,   561,   562,   180,   549,   635,     8,    10,    11,
     536,   537,   538,   448,   449,   454,   455,   460,   461,   475,
     476,   482,   483,   488,   489,   494,   495,   500,   501,   515,
     516,    10,    11,   685,   686,   687,   131,   132,   133,   134,
     159,   160,   166,   167,   684,   845,   847,   869,   870,   871,
     878,   879,   880,   881,   882,   883,   920,   912,   914,   918,
     922,   924,   962,   974,   932,   916,   939,   926,   928,   930,
     954,   937,   968,   965,   971,   904,   907,   910,   941,   943,
     945,   310,   902,   949,     8,     6,     8,     8,     8,     8,
       6,     7,   409,   410,   411,   412,   657,     8,   583,   584,
     585,   627,   311,  1040,  1041,   179,   563,   636,     8,    10,
      11,   550,   551,   552,     6,   540,    10,    11,   451,   450,
     845,   847,   869,    10,    11,   457,   456,   845,   847,   869,
      10,    11,   463,   462,   845,   847,   869,    10,    11,   479,
      28,   477,   478,   845,   847,   869,    10,    11,   485,    34,
      35,    36,   484,   637,   638,   639,   845,   847,   869,    10,
      11,   491,    37,    38,   490,   637,   638,   640,   641,   845,
     847,   869,    10,    11,   497,    13,   496,   642,   845,   847,
     869,    11,   503,   502,   845,   847,   869,    11,   518,   517,
     845,   847,   869,   206,   688,   689,   690,     3,     3,     3,
       8,     8,   902,   902,   902,   902,   902,   902,   963,   975,
     902,   902,   902,   902,   902,   902,   957,   902,   969,   966,
     972,    10,    11,   905,    10,    11,   908,   902,   249,   253,
     257,   373,   375,   377,   379,   381,   383,   385,   387,   389,
     391,   393,   395,   397,   399,   401,   403,   976,   977,   978,
     980,   981,   984,   985,   988,   989,   992,   993,   995,   996,
     998,   999,  1001,  1002,  1004,  1005,  1008,  1009,  1013,  1014,
    1016,  1017,  1019,  1020,  1022,  1023,  1025,  1026,  1028,  1031,
    1032,  1034,  1035,  1037,  1038,   976,   976,   350,   935,    10,
      11,   141,   142,   408,   881,   884,   885,   886,   948,   950,
     951,     8,   656,   656,     6,    79,   584,    80,    10,    11,
      19,    20,   626,   628,   630,   631,   246,   313,  1042,  1043,
       8,    10,    11,   564,   565,   566,     6,   554,     8,   248,
     249,   539,   541,   542,    49,    51,   464,   465,    55,     8,
      57,     8,     8,     8,    59,     8,     8,    61,     3,    72,
     504,   505,    74,   519,   520,   204,   695,   691,   692,     8,
       8,     8,     6,     6,   902,   902,   902,   902,   328,   330,
     332,   902,   334,   902,   336,   338,   902,   342,   344,   346,
      10,    11,   195,   199,   955,   958,   959,   960,   352,   354,
     902,   356,   902,   358,   902,   360,   362,   902,  1029,   368,
      22,   195,   643,   195,   983,   195,   987,   195,   991,   976,
     994,   976,   997,   902,  1000,   976,  1003,   406,  1006,  1012,
    1010,  1012,    10,    11,  1015,   976,  1018,   976,  1021,   976,
    1024,   976,  1027,   902,  1033,   902,  1036,   976,  1039,   370,
     372,   366,     3,     3,     8,   132,   586,    83,     8,     8,
       8,    10,    11,  1044,  1045,  1046,     6,   568,     8,   252,
     253,   553,   555,   556,   543,   544,    53,   472,    70,   466,
     467,     6,   654,     6,     6,     6,     6,     8,    63,   512,
     122,   506,   846,    65,   527,   521,   846,   207,   217,   221,
     223,   225,   227,   229,   243,   696,   697,   698,   722,   723,
     735,   736,   762,   763,   780,   781,   793,   794,   811,   812,
     815,   816,    10,    11,   694,   163,   164,   182,   183,   184,
     185,   186,   187,   188,   189,   693,   851,   852,   853,   854,
     855,   863,   864,   865,   866,   867,   868,     8,     8,   320,
     322,   324,   326,   902,   348,   902,     8,     8,   364,  1030,
       8,     8,    10,    11,   979,     8,    10,    11,   982,     8,
      10,    11,   986,     8,    10,    11,   990,   374,   976,   402,
     404,     3,    11,    11,   382,   976,   386,   976,   976,   976,
     902,   398,     8,   952,    11,     3,    10,    11,   587,   654,
     654,     6,  1047,     8,   256,   257,   567,   569,   570,   557,
     558,    10,    11,   546,    23,    24,    25,    26,    27,    29,
     149,   150,   197,   545,   644,   645,   647,   648,   651,   652,
     845,   847,   862,   869,   890,   891,   892,   468,   469,     8,
       8,     8,     8,     8,     8,     8,    10,    11,   507,   508,
     509,    10,    11,   522,   523,   524,   699,   700,   724,   725,
     737,   738,   764,   765,   782,   783,   795,   796,   813,   875,
     165,   817,   844,   205,     3,     8,     8,     8,     8,     8,
       8,     8,     8,   340,   956,     6,   654,   392,   976,     6,
       6,   400,     6,   250,     6,   254,     6,   258,   376,     8,
     976,  1007,   976,  1011,   384,   388,   390,   394,   902,     8,
       8,   269,   588,   589,     8,     8,     8,   312,   314,  1048,
    1049,   571,   572,    10,    11,   560,    30,    32,    33,   559,
     646,   647,   649,   653,   845,   847,   862,   869,   250,     8,
       8,     8,     8,     8,     8,     3,     8,    10,    11,   471,
     470,   862,   881,     6,   120,   510,   658,   659,   666,   525,
     658,    11,   161,   162,   169,   701,   848,   872,   873,   874,
      11,   726,   848,   872,    11,   739,   848,   872,    11,   766,
     848,   872,    11,   784,   848,   872,    11,   797,   848,   872,
      11,     8,    11,   818,   655,   656,     6,     6,     6,     6,
       6,     6,     6,   654,   348,     8,     8,     8,     8,     8,
       8,     8,   378,   380,   902,   590,    81,   261,   601,  1050,
    1051,    10,    11,   574,    31,   573,   644,   645,   647,   650,
     651,   652,   845,   847,   869,   254,     8,     8,     8,     6,
       6,     6,     6,     6,     6,     8,     6,    71,     8,   198,
     850,    73,   511,   112,   660,   661,    75,   526,   235,   702,
     704,   705,     3,     8,   704,   727,   704,   740,   704,   767,
     704,   785,   704,   798,   976,     6,   211,   820,   821,     8,
       8,     8,     8,     8,     8,     8,     8,     8,   976,    10,
      11,    21,   176,   591,   592,   593,   594,   595,   602,   265,
     613,    11,   860,   875,  1052,   258,     8,     6,     6,     6,
       8,     8,     8,     8,     8,     8,     8,     8,    10,    11,
     667,   668,   669,   662,   663,   237,   703,   710,   711,    10,
      11,   706,   707,   708,     8,     6,   710,   728,   710,   741,
     710,   768,   710,   786,   710,   799,   244,   814,     8,   213,
     827,   828,   822,   846,   396,   270,   596,   597,   598,     8,
       8,    10,    11,    21,   170,   603,   604,   605,   606,   607,
     614,   976,     6,     8,     8,     8,     6,     4,   121,    11,
     665,   196,   664,   861,   862,   218,   239,   716,   717,    10,
      11,   712,   713,   714,   658,   709,     8,   239,   729,   730,
     222,   239,   742,   743,   224,   239,   769,   770,   230,   239,
     787,   788,   228,   239,   800,   801,   226,   834,   829,   846,
      10,    11,   823,   824,   825,   270,   597,   267,     6,     6,
     262,   608,   609,   610,     8,     8,    10,    11,    21,   173,
     615,   616,   617,   618,   629,   315,     8,     8,   121,     6,
       8,    10,    11,   718,   719,   720,   658,   715,   236,    10,
      11,   731,   732,   733,    10,    11,   744,   745,   746,    10,
      11,   771,   772,   773,    10,    11,   789,   790,   791,    10,
      11,   802,   803,   804,   208,   209,   819,   835,   836,    10,
      11,   830,   831,   832,   658,   826,   195,   599,     8,     8,
     262,   609,   259,     6,     6,   266,   619,   620,   621,     8,
       8,   113,     6,   120,   670,   671,   676,   721,   238,   658,
     734,   747,   748,   774,   658,   792,   805,   837,   838,   658,
     833,   212,     8,    10,    11,   600,   195,   611,     8,     8,
     266,   620,   263,     6,     6,     8,   850,   112,   672,   673,
     240,   240,   240,   112,   749,   750,   112,   240,   775,   776,
     240,   112,   240,   806,   807,    10,    11,   840,   841,   842,
     190,   191,   839,   856,   857,   878,   881,   214,     6,   268,
       8,    10,    11,   612,   195,   622,     8,     8,    10,    11,
     677,   678,   679,   674,   862,   751,   752,    10,    11,   777,
     778,   779,   808,   689,   843,   655,   655,     8,     6,   260,
       8,    10,    11,   623,     4,   121,    11,   675,    10,    11,
     754,   755,   756,   178,   200,   753,   849,   859,   902,    11,
     143,   144,   809,   810,   861,   862,   887,   888,   889,   695,
     210,     6,     6,     8,     6,   264,   121,   654,   757,     8,
       8,   113,     6,     3,   655,   655,     8,   113,   113,   241,
     758,   759,     6,   654,   113,     8,   199,   760,   858,     8,
       8,     8,    11,   761,   654,     6,     8,   242
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
    if (parserData->coneCounter > parserData->numberOfCones) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "encountered more cones than specified");
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
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixVar greater than number attribute");
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
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj greater than number attribute");
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
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon greater than number attribute");
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
    if ((yyvsp[(2) - (3)].sval) != "positive" && (yyvsp[(2) - (3)].sval) != "negative")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "semidefiniteness must be either \"positive\" or \"negative\"");
    else
        parserData->semidefiniteness = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
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
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 430:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
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

  case 431:

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
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}
    break;

  case 439:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrixVar)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
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
}
    break;

  case 440:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrixObj)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
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
}
    break;

  case 441:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrixCon)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
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
}
    break;

  case 445:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 448:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 449:

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

  case 450:

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

  case 465:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 475:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 476:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 479:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 480:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 484:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 485:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 491:

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

  case 492:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 498:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 499:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 506:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 507:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 510:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 511:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 515:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 516:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 523:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 524:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 527:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 528:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 532:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 533:

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

  case 534:

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
}
    break;

  case 542:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 543:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 544:

    {
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
        = osglData->constant;
    osglData->osglCounter = 0;
}
    break;

  case 556:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 558:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 559:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 561:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 562:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 565:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
    break;

  case 566:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 572:

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
}
    break;

  case 580:

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

  case 584:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 586:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 587:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 590:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
    break;

  case 591:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 595:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 596:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 603:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 604:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 607:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 608:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 612:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 613:

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

  case 614:

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
}
    break;

  case 621:

    {
//    osglData->nonzeroCounter++;
//    if (osglData->nonzeroCounter > osglData->osglNumberOfNonzeros)
//        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReference matrix elements: too many nonzeros");
}
    break;

  case 622:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = ""; //ENUM_CONREFERENCE_VALUETYPE_value;
    }
    break;

  case 628:

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
                "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
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

  case 630:

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

  case 632:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 633:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 634:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 635:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 636:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 638:

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

  case 639:

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

  case 640:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 641:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 647:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 648:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 649:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 656:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 657:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 658:

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

  case 664:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 665:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 669:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 671:

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

  case 672:

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

  case 673:

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

  case 674:

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

  case 675:

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

  case 676:

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

  case 677:

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

  case 678:

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

  case 679:

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

  case 680:

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

  case 681:

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

  case 682:

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

  case 683:

    {
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

  case 684:

    {
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

  case 685:

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

  case 686:

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

  case 687:

    { 
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        osglData->idx = (yyvsp[(3) - (4)].ival);
    }
    break;

  case 688:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 689:

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

  case 690:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 691:

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

  case 692:

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

  case 695:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 696:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 699:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 700:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 703:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 704:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajor = true;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 707:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 708:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 711:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 712:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 715:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 716:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 719:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 720:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 723:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 724:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 727:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 728:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 730:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 731:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 732:

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

  case 735:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 736:

    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
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

  case 737:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 740:

    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new RealValuedExpressionTree();
    }
    break;

  case 741:

    {
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape 
                = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    }
    break;

  case 769:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 773:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 777:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 779:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 781:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 783:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 785:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 787:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 789:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 791:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 793:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 795:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 797:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 799:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 802:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 803:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 804:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 805:

    {
}
    break;

  case 806:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 807:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 808:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 810:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 812:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 814:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 815:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 820:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 821:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 823:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 825:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 826:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 829:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 833:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 834:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 835:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 836:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 837:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 838:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 840:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 841:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 842:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 844:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 845:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 846:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 848:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 849:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 850:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 852:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 853:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 854:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 856:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 876:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 877:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 880:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 881:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 882:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 885:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 886:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 887:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 890:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 891:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 892:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 895:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 897:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 900:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 903:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 906:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 909:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 911:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 914:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 916:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 918:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 920:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 924:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 927:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 930:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 933:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 935:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 936:

    {
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 938:

    { 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
}
    break;

  case 940:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 943:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 946:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 949:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 950:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }
    break;

  case 952:

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

  case 959:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }
    break;

  case 960:

    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions greater than number attribute");
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

  case 961:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 964:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    break;

  case 965:

    {
    #ifdef OSINSTANCE_AVAILABLE
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->matrixProgramming->matrixExpressions
                ->expr[ osnlData->tmpnlcount]->shape 
                    = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    #endif
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
    int elementSize;

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
    int    kount = pinstanceHeadStart - pchar;
    while( kount-- > 0) if(*(pchar++) == '\n') (*osillineno)++;
    // important! pchar now points to the '<' in <instanceHeader
    // that is, both pinstanceHeadStart and pchar point to the same thing
     // 
     // move to the end of <instanceHeader
     pchar+=15;
    // burn any whitespace
    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
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
        // first burn any whitespace
        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
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
                    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
                for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
    // burn the white space
    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
    // pchar should be point to a '<', if not there is an error
    if(*pchar != '<'){  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData element"); return false;}
    // make sure the element is <instanceData    
    *p = pchar;
    while(*startInstanceData++  == *pchar) pchar++;
    if( (pchar - *p) != 13) {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); return false;}    
    // now burn whitespace
    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
    // pchar must point to '>' or there is an error
    if(*pchar == '>'){
        pchar++;
        // we are now pointing to the first char after <instanceData>
        // burn any whitespace
        for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;    
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
    int ki, numChar;
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
    //const char *initString = "initString";
    const char *type = "type";
    const char *mult = "mult";
    // others
    int i;
    int varcount = 0;
    int vt;
    int numberOfVariables = 0;
// variable attribute boolean variables
    bool varlbattON  = false;
    bool varubattON = false ;
    bool vartypeattON  = false;
    bool varnameattON = false ;
    //bool varinitattON = false ;
    //bool varinitStringattON = false ;
    bool varmultattON = false;
    bool foundVar = false;
    int varmult; 
    //
    // start parsing -- okay not to have variables 
    // burn white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    *p = ch;
    while(*startVariables++  == *ch) ch++;
    //if( (ch - *p) != 10) {  osilerror_wrapper( ch,osillineno,"incorrect <variables tag>"); return false;}
    if( (ch - *p) != 10) {   return true;}

    osinstance->instanceData->variables = new Variables();

    // find numberOfVariables attribute
    // eat the white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    *p = ch;
    while(*c_numberOfVariables++  == *ch) ch++;
    if( (ch - *p) != 17) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfVariables attribute in <variables tag>"); return false;}    
    // buf_index should be pointing to the first character after numberOfVariables
    GETATTRIBUTETEXT;
    ch++;
    numberOfVariables = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    if(numberOfVariables <  0) {
        osilerror_wrapper( ch,osillineno,"there must be a nonnegative number of variables"); return false;
    }
    osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
    if(numberOfVariables > 0){
        osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
        for(i = 0; i < numberOfVariables; i++){
            osinstance->instanceData->variables->var[ i] = new Variable();
        } 
    }
    // get rid of white space after the numberOfVariables element
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;                    
    // since there must be at least one variable,  this element must end with > 
    if(numberOfVariables > 0){
        // better have an > sign or not valid
        if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"variables element does not have a proper closing >"); return false;}
        ch++;
        // get rid of white space
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
        // now loop over the var element when the numberOfVariables is strictly positive
        *p = ch;
        while(*startVar++  == *ch) ch++;
        if( (ch - *p) ==  4) foundVar = true;
            else {  osilerror_wrapper( ch,osillineno,"there must be at least one <var> element"); return false;}
        startVar -= 5;
        while(foundVar){
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
            for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            while(*ch != '/' && *ch != '>'){
                switch (*ch) {
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
            if( *ch != '/' && *ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <var> element"); return false;}
            if(*ch == '/'){
                ch++;
                if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <var> element"); return false;}
                // get rid of whitespace
                ch++;
                for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4) {
                    foundVar = true;
                    startVar -= 5;
                }
                else {
                    foundVar = false;
                    ch = *p;
                }
            }
            else{
                // the buf_index is the > at the end of the var element 
                // double check to make sure it really is a >
                if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <var> element"); return false;}
                // look for </var
                // fist get rid of white space
                ch++;
                for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
                // we should be at </var or there is an error
                *p = ch;
                while(*endVar++  == *ch) ch++;
                endVar -= 6;
                if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</var> element missing"); return false;}
                // burn off the whitespace
                for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
                // better have an > to end </var
                if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</var> element missing >"); return false;}
                // look for a new <var> element
                // get rid of whitespace
                ch++;
                for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
                // either have another <var> element or foundVar = false;
                *p = ch;
                while(*startVar++  == *ch) ch++;
                if( (ch - *p) == 4) {
                    foundVar = true;
                    startVar -= 5;
                }
                else {
                    foundVar = false;
                    ch = *p;
                }
            }
            if( ((varcount+varmult) == numberOfVariables) && (foundVar == true) ) {   osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is less than actual number found");  return false;}
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
            varcount += varmult;
        }// end while(foundVar)
        if(varcount < numberOfVariables) {  osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is greater than actual number found");   return false;}
        // get the </variables> tag
        *p = ch;
        while(*endVariables++  == *ch) ch++;
        if( (ch - *p) != 11) {   osilerror_wrapper( ch,osillineno,"cannot find </variables> tag"); return false;}
        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
        // better have >
        if(*ch != '>') {   osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag"); return false;}
        ch++;
    }else {//end if(numberOfVariables > 0)
        // error if the number is negative
        if(numberOfVariables < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of variables"); return false;}
        // if we are here we have numberOfVariables = 0
        // must close with /> or </variables>
        // get rid of white space
        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
        if( *ch == '/'){
            // better have a >
            ch++;
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed variables tag"); return false;}
            ch++;
        }
        else{
            // if we are here we must have an '>' and then  </constraints> tag
            if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed variables tag"); return false;}
            ch++;
            // burn white space
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            *p = ch;
            while( *endVariables++  == *ch) ch++;
            if( (ch - *p) != 11) {  osilerror_wrapper( ch,osillineno, "cannot find </variables> tag"); return false; }
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
            // better have >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag"); return false;}    
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
    // burn white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // if, present we should be pointing to <objectives element if there -- it is not required
    *p = ch;
    while( *startObjectives++  == *ch) ch++;
    if( (ch - *p) != 11) {
        //  note if we are here even though ch > *p we want to return *p
        return true;
    }

    osinstance->instanceData->objectives = new Objectives();

    // find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
    // However if the  number attribute is missing assume it is    1 
    // eat the white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // we just ate the white space. If numberOfObjectives is missing we assume it is 1
    // we therefore must have > char
    if(*ch == '>'){
        numberOfObjectives = 1;
        //ch++;
    }
    else{
        *p = ch;
        while( *c_numberOfObjectives++  == *ch) ch++;
        if( (ch - *p) != 18) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfObjectives attribute in <objectives> tag"); return false;}    
        GETATTRIBUTETEXT;
        numberOfObjectives = atoimod1( osillineno, attText, attTextEnd);
        delete [] attText;
        ch++;
    }
    if(numberOfObjectives > 0){
        // get rid of white space after the numberOfObjectives attribute
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    // get rid of white space after the <objectives> element
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
        // assume we are pointing to the first character after the r in <obj
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
            // get rid of whitespace
            ch++;
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        else{
            // the ch is the > at the end of the obj element
            // double check to make sure it really is a >
            if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <obj> element"); return false;}
            // look for </obj
            // fist get rid of white space
            ch++;
            // first get the <coef> elements
            parseObjCoef(&ch,  objcount, osinstance, osillineno);
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // we should be at </obj or there is an error
            for(i = 0; endObj[i]  == *ch; i++, ch++);
            if(i != 5) {  osilerror_wrapper( ch,osillineno,"</obj> element missing"); return false;}
            // burn off the whitespace
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // better have an > to end </obj
            if(*ch++ != '>'){   osilerror_wrapper( ch,osillineno,"</obj> element missing"); return false;}
            // look for a new <obj> element
            // get rid of whitespace
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // either have another <obj> element or foundObj = false;
            for(i = 0; startObj[i]  == *ch; i++, ch++);
            if(i == 4) foundObj = true;
                else foundObj = false;
        }
        if( ((objcount+objmult) == numberOfObjectives) && (foundObj == true)) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is less than actual number found"); return false;}
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
                osinstance->instanceData->objectives->obj[objcount+k]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
                for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)
                {
                    osinstance->instanceData->objectives->obj[objcount+k]->coef[i] = new ObjCoef();
                    osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->idx = 
                      osinstance->instanceData->objectives->obj[objcount]->coef[i]->idx;
                    osinstance->instanceData->objectives->obj[objcount+k]->coef[i]->value = 
                      osinstance->instanceData->objectives->obj[objcount]->coef[i]->value;
                }
            }
        }
        objcount += objmult;
    }
    if(objcount < numberOfObjectives) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is greater than actual number found"); return false;}
    ch -= i;
    // get the </objectives> tag
    for(i = 0; endObjectives[i]  == *ch; i++, ch++);
    if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            // burn white space
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            for(i = 0; endObjectives[i]  == *ch; i++, ch++);
            if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    //  we better have an > 
    if( *ch++ != '>') {   osilerror_wrapper( ch,osillineno,"the constraints element does not have a proper closing"); return false;} 
    // get rid of white space after the <constraints> element
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // we should be at </con or there is an error
            *p = ch;
            while( *endCon++  == *ch) ch++;
            if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</con> element missing"); return false;}
            endCon -= 6;
            // burn off the whitespace
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            // better have an > to end </con
            if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</con> element missing >"); return false;}
            // look for a new <con> element
            // get rid of whitespace
            ch++;
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
        if( ((concount+conmult) == numberOfConstraints) && (foundCon == true) ) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is less than actual number found"); return false;}
        for (int k=1; k < conmult; k++)
        {
            osinstance->instanceData->constraints->con[concount+k]->name
            = osinstance->instanceData->constraints->con[concount]->name ;
            osinstance->instanceData->constraints->con[concount+k]->constant
            = osinstance->instanceData->constraints->con[concount]->constant ;
            osinstance->instanceData->constraints->con[concount+k]->lb
            = osinstance->instanceData->constraints->con[concount]->lb ;
            osinstance->instanceData->constraints->con[concount+k]->ub
            = osinstance->instanceData->constraints->con[concount]->ub ;
        }
        concount += conmult;
    }
    if(concount < numberOfConstraints) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is greater than actual number found"); return false;}
    // get the </constraints> tag
    *p = ch;
    while( *endConstraints++  == *ch) ch++;
    if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false;}
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            *p = ch;
            while( *endConstraints++  == *ch) ch++;
            if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false; }
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    // burn white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    // get rid of white space after the <linearConstraintCoefficients> element
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // get the </linearConstraintCoefficients> tag
    *p = ch;
    while( *endlinearConstraintCoefficients++  == *ch) ch++;
    if( (ch - *p) != 30) {  osilerror_wrapper( ch,osillineno, "cannot find </linearConstraintCoefficients> tag"); return false;}
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // if, present we should be pointing to <start element 
    *p = ch;
    while( *startStart++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <start
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <start> element"); return false;}
    ch++;
    // get rid of white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        int dataSize = 0;
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
            for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // if, present we should be pointing to <rowIdx element 
    *p = ch;
    while( *startRowIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <rowIdx
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <rowIdx> element"); return false;}
    ch++;
    // get rid of white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        int dataSize = 0;
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
            for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // mung white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // if, present we should be pointing to <colIdx element 
    *p = ch;
    while( *startColIdx++  == *ch) ch++;
    if( (ch - *p) != 7) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <colIdx
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <colIdx> element"); return false;}
    ch++;
    // get rid of white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        int dataSize = 0;
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
            for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );    
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
    int ki, numChar;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
    // if present we should be pointing to <value element 
    *p = ch;
    while( *startValue++  == *ch) ch++;
    if( (ch - *p) != 6) {
        //reset ch
        ch = *p;
        return false;
    }
    // get rid of white space after <value
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
    // we should have either an >
    if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <value> element"); return false;}
    ch++;
    // get rid of white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
    // look for an <el> -- if none present must have b64 data
    *p = ch;
    while( *startEl++  == *ch) ch++;
    startEl -= 4;
    if( (ch - *p) != 3) {
        //reset ch
        ch = *p;
        // call base64 parse here
        int dataSize = 0;
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
            for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
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
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
            if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
            // eat white space again,
            for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
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
    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );    
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
    int ki, numChar;
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
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
        // if, present we should be pointing to <coef element 
        *p = ch;
        while( *startCoef++  == *ch) ch++;
        if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"improper <coef> element"); return false;}
        startCoef -= 6;
        // get the idx attribute
        // eat the white space after <coef
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
        for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
        // if we don't have a > there is an error
        if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect </coef> element")    ; return false;}
    }
    }// end if(numberOfObjCoef > 0)
    *p = ch;
    return true;
}//end parseObjCoef

char *parseBase64(const char **p, int *dataSize, int* osillineno ){
    int ki, numChar;
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
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    for(i = 0; sizeOf[i]  == *ch; i++, ch++);
    if(i != 6) {  osilerror_wrapper( ch,osillineno,"incorrect sizeOf attribute in <base64BinaryData> element"); return false;}    
    // ch should be pointing to the first character after sizeOf
    GETATTRIBUTETEXT;
    ch++;
    *dataSize = atoimod1( osillineno, attText, attTextEnd);
    delete [] attText;
    // since the element must contain b64 data,  this element must end with > 
    // eat the white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    int b64len = b64textend - b64textstart;
    b64string = new char[ b64len + 1]; 
    for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
    b64string[ki] = '\0';    
    // burn the white space
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
    // better have an > sign or not valid
    if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"</base64BinaryData> element does not have a proper closing >"); return false;}
    ch++;
    for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
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
    error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
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


