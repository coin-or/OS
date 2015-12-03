
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
     REATT = 447,
     IMATT = 448,
     MATRIXVARIDXATT = 449,
     MATRIXOBJIDXATT = 450,
     MATRIXCONIDXATT = 451,
     IDXATT = 452,
     INCRATT = 453,
     MULTATT = 454,
     SIZEOFATT = 455,
     COEFATT = 456,
     CONSTANTATT = 457,
     MATRICESSTART = 458,
     MATRICESEND = 459,
     MATRIXSTART = 460,
     MATRIXEND = 461,
     BASEMATRIXEND = 462,
     BASEMATRIXSTART = 463,
     BLOCKSSTART = 464,
     BLOCKSEND = 465,
     BLOCKSTART = 466,
     BLOCKEND = 467,
     COLOFFSETSTART = 468,
     COLOFFSETEND = 469,
     ROWOFFSETSTART = 470,
     ROWOFFSETEND = 471,
     ELEMENTSSTART = 472,
     ELEMENTSEND = 473,
     CONSTANTELEMENTSSTART = 474,
     CONSTANTELEMENTSEND = 475,
     COMPLEXELEMENTSSTART = 476,
     COMPLEXELEMENTSEND = 477,
     VARREFERENCEELEMENTSSTART = 478,
     VARREFERENCEELEMENTSEND = 479,
     LINEARELEMENTSSTART = 480,
     LINEARELEMENTSEND = 481,
     CONREFERENCEELEMENTSSTART = 482,
     CONREFERENCEELEMENTSEND = 483,
     OBJREFERENCEELEMENTSSTART = 484,
     OBJREFERENCEELEMENTSEND = 485,
     REALVALUEDEXPRESSIONSSTART = 486,
     REALVALUEDEXPRESSIONSSEND = 487,
     COMPLEXVALUEDEXPRESSIONSSTART = 488,
     COMPLEXVALUEDEXPRESSIONSSEND = 489,
     STRINGVALUEDELEMENTSSTART = 490,
     STRINGVALUEDELEMENTSEND = 491,
     STARTVECTORSTART = 492,
     STARTVECTOREND = 493,
     INDEXSTART = 494,
     INDEXEND = 495,
     VALUESTART = 496,
     VALUEEND = 497,
     VARIDXSTART = 498,
     VARIDXEND = 499,
     TRANSFORMATIONSTART = 500,
     TRANSFORMATIONEND = 501,
     MATRIXPROGRAMMINGSTART = 502,
     MATRIXPROGRAMMINGEND = 503,
     MATRIXVARIABLESSTART = 504,
     MATRIXVARIABLESEND = 505,
     MATRIXVARSTART = 506,
     MATRIXVAREND = 507,
     MATRIXOBJECTIVESSTART = 508,
     MATRIXOBJECTIVESEND = 509,
     MATRIXOBJSTART = 510,
     MATRIXOBJEND = 511,
     MATRIXCONSTRAINTSSTART = 512,
     MATRIXCONSTRAINTSEND = 513,
     MATRIXCONSTART = 514,
     MATRIXCONEND = 515,
     CONSTART = 516,
     CONEND = 517,
     CONSTRAINTSSTART = 518,
     CONSTRAINTSEND = 519,
     OBJSTART = 520,
     OBJEND = 521,
     OBJECTIVESSTART = 522,
     OBJECTIVESEND = 523,
     VARSTART = 524,
     VAREND = 525,
     VARIABLESSTART = 526,
     VARIABLESEND = 527,
     GENERALSTART = 528,
     GENERALEND = 529,
     SYSTEMSTART = 530,
     SYSTEMEND = 531,
     SERVICESTART = 532,
     SERVICEEND = 533,
     JOBSTART = 534,
     JOBEND = 535,
     OPTIMIZATIONSTART = 536,
     OPTIMIZATIONEND = 537,
     ATEQUALITYSTART = 538,
     ATEQUALITYEND = 539,
     ATLOWERSTART = 540,
     ATLOWEREND = 541,
     ATUPPERSTART = 542,
     ATUPPEREND = 543,
     BASICSTART = 544,
     BASICEND = 545,
     ISFREESTART = 546,
     ISFREEEND = 547,
     SUPERBASICSTART = 548,
     SUPERBASICEND = 549,
     UNKNOWNSTART = 550,
     UNKNOWNEND = 551,
     SERVICEURISTART = 552,
     SERVICEURIEND = 553,
     SERVICENAMESTART = 554,
     SERVICENAMEEND = 555,
     INSTANCENAMESTART = 556,
     INSTANCENAMEEND = 557,
     JOBIDSTART = 558,
     JOBIDEND = 559,
     OTHERSTART = 560,
     OTHEREND = 561,
     DUMMY = 562,
     NONLINEAREXPRESSIONSSTART = 563,
     NONLINEAREXPRESSIONSEND = 564,
     NUMBEROFNONLINEAREXPRESSIONS = 565,
     NLSTART = 566,
     NLEND = 567,
     MATRIXEXPRESSIONSSTART = 568,
     MATRIXEXPRESSIONSEND = 569,
     NUMBEROFEXPR = 570,
     EXPRSTART = 571,
     EXPREND = 572,
     NUMBEROFMATRIXTERMSATT = 573,
     MATRIXTERMSTART = 574,
     MATRIXTERMEND = 575,
     POWERSTART = 576,
     POWEREND = 577,
     PLUSSTART = 578,
     PLUSEND = 579,
     MINUSSTART = 580,
     MINUSEND = 581,
     DIVIDESTART = 582,
     DIVIDEEND = 583,
     LNSTART = 584,
     LNEND = 585,
     SQRTSTART = 586,
     SQRTEND = 587,
     SUMSTART = 588,
     SUMEND = 589,
     PRODUCTSTART = 590,
     PRODUCTEND = 591,
     EXPSTART = 592,
     EXPEND = 593,
     NEGATESTART = 594,
     NEGATEEND = 595,
     IFSTART = 596,
     IFEND = 597,
     SQUARESTART = 598,
     SQUAREEND = 599,
     COSSTART = 600,
     COSEND = 601,
     SINSTART = 602,
     SINEND = 603,
     VARIABLESTART = 604,
     VARIABLEEND = 605,
     ABSSTART = 606,
     ABSEND = 607,
     ERFSTART = 608,
     ERFEND = 609,
     MAXSTART = 610,
     MAXEND = 611,
     ALLDIFFSTART = 612,
     ALLDIFFEND = 613,
     MINSTART = 614,
     MINEND = 615,
     ESTART = 616,
     EEND = 617,
     PISTART = 618,
     PIEND = 619,
     TIMESSTART = 620,
     TIMESEND = 621,
     NUMBERSTART = 622,
     NUMBEREND = 623,
     MATRIXDETERMINANTSTART = 624,
     MATRIXDETERMINANTEND = 625,
     MATRIXTRACESTART = 626,
     MATRIXTRACEEND = 627,
     MATRIXTOSCALARSTART = 628,
     MATRIXTOSCALAREND = 629,
     MATRIXDIAGONALSTART = 630,
     MATRIXDIAGONALEND = 631,
     MATRIXDOTTIMESSTART = 632,
     MATRIXDOTTIMESEND = 633,
     MATRIXLOWERTRIANGLESTART = 634,
     MATRIXLOWERTRIANGLEEND = 635,
     MATRIXUPPERTRIANGLESTART = 636,
     MATRIXUPPERTRIANGLEEND = 637,
     MATRIXMERGESTART = 638,
     MATRIXMERGEEND = 639,
     MATRIXMINUSSTART = 640,
     MATRIXMINUSEND = 641,
     MATRIXNEGATESTART = 642,
     MATRIXNEGATEEND = 643,
     MATRIXPLUSSTART = 644,
     MATRIXPLUSEND = 645,
     MATRIXTIMESSTART = 646,
     MATRIXTIMESEND = 647,
     MATRIXPRODUCTSTART = 648,
     MATRIXPRODUCTEND = 649,
     MATRIXSCALARTIMESSTART = 650,
     MATRIXSCALARTIMESEND = 651,
     MATRIXSUBMATRIXATSTART = 652,
     MATRIXSUBMATRIXATEND = 653,
     MATRIXTRANSPOSESTART = 654,
     MATRIXTRANSPOSEEND = 655,
     MATRIXREFERENCESTART = 656,
     MATRIXREFERENCEEND = 657,
     IDENTITYMATRIXSTART = 658,
     IDENTITYMATRIXEND = 659,
     MATRIXINVERSESTART = 660,
     MATRIXINVERSEEND = 661,
     EMPTYINCLUDEDIAGONALATT = 662,
     INCLUDEDIAGONALATT = 663,
     EMPTYIDATT = 664,
     IDATT = 665
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
#define REATT 447
#define IMATT 448
#define MATRIXVARIDXATT 449
#define MATRIXOBJIDXATT 450
#define MATRIXCONIDXATT 451
#define IDXATT 452
#define INCRATT 453
#define MULTATT 454
#define SIZEOFATT 455
#define COEFATT 456
#define CONSTANTATT 457
#define MATRICESSTART 458
#define MATRICESEND 459
#define MATRIXSTART 460
#define MATRIXEND 461
#define BASEMATRIXEND 462
#define BASEMATRIXSTART 463
#define BLOCKSSTART 464
#define BLOCKSEND 465
#define BLOCKSTART 466
#define BLOCKEND 467
#define COLOFFSETSTART 468
#define COLOFFSETEND 469
#define ROWOFFSETSTART 470
#define ROWOFFSETEND 471
#define ELEMENTSSTART 472
#define ELEMENTSEND 473
#define CONSTANTELEMENTSSTART 474
#define CONSTANTELEMENTSEND 475
#define COMPLEXELEMENTSSTART 476
#define COMPLEXELEMENTSEND 477
#define VARREFERENCEELEMENTSSTART 478
#define VARREFERENCEELEMENTSEND 479
#define LINEARELEMENTSSTART 480
#define LINEARELEMENTSEND 481
#define CONREFERENCEELEMENTSSTART 482
#define CONREFERENCEELEMENTSEND 483
#define OBJREFERENCEELEMENTSSTART 484
#define OBJREFERENCEELEMENTSEND 485
#define REALVALUEDEXPRESSIONSSTART 486
#define REALVALUEDEXPRESSIONSSEND 487
#define COMPLEXVALUEDEXPRESSIONSSTART 488
#define COMPLEXVALUEDEXPRESSIONSSEND 489
#define STRINGVALUEDELEMENTSSTART 490
#define STRINGVALUEDELEMENTSEND 491
#define STARTVECTORSTART 492
#define STARTVECTOREND 493
#define INDEXSTART 494
#define INDEXEND 495
#define VALUESTART 496
#define VALUEEND 497
#define VARIDXSTART 498
#define VARIDXEND 499
#define TRANSFORMATIONSTART 500
#define TRANSFORMATIONEND 501
#define MATRIXPROGRAMMINGSTART 502
#define MATRIXPROGRAMMINGEND 503
#define MATRIXVARIABLESSTART 504
#define MATRIXVARIABLESEND 505
#define MATRIXVARSTART 506
#define MATRIXVAREND 507
#define MATRIXOBJECTIVESSTART 508
#define MATRIXOBJECTIVESEND 509
#define MATRIXOBJSTART 510
#define MATRIXOBJEND 511
#define MATRIXCONSTRAINTSSTART 512
#define MATRIXCONSTRAINTSEND 513
#define MATRIXCONSTART 514
#define MATRIXCONEND 515
#define CONSTART 516
#define CONEND 517
#define CONSTRAINTSSTART 518
#define CONSTRAINTSEND 519
#define OBJSTART 520
#define OBJEND 521
#define OBJECTIVESSTART 522
#define OBJECTIVESEND 523
#define VARSTART 524
#define VAREND 525
#define VARIABLESSTART 526
#define VARIABLESEND 527
#define GENERALSTART 528
#define GENERALEND 529
#define SYSTEMSTART 530
#define SYSTEMEND 531
#define SERVICESTART 532
#define SERVICEEND 533
#define JOBSTART 534
#define JOBEND 535
#define OPTIMIZATIONSTART 536
#define OPTIMIZATIONEND 537
#define ATEQUALITYSTART 538
#define ATEQUALITYEND 539
#define ATLOWERSTART 540
#define ATLOWEREND 541
#define ATUPPERSTART 542
#define ATUPPEREND 543
#define BASICSTART 544
#define BASICEND 545
#define ISFREESTART 546
#define ISFREEEND 547
#define SUPERBASICSTART 548
#define SUPERBASICEND 549
#define UNKNOWNSTART 550
#define UNKNOWNEND 551
#define SERVICEURISTART 552
#define SERVICEURIEND 553
#define SERVICENAMESTART 554
#define SERVICENAMEEND 555
#define INSTANCENAMESTART 556
#define INSTANCENAMEEND 557
#define JOBIDSTART 558
#define JOBIDEND 559
#define OTHERSTART 560
#define OTHEREND 561
#define DUMMY 562
#define NONLINEAREXPRESSIONSSTART 563
#define NONLINEAREXPRESSIONSEND 564
#define NUMBEROFNONLINEAREXPRESSIONS 565
#define NLSTART 566
#define NLEND 567
#define MATRIXEXPRESSIONSSTART 568
#define MATRIXEXPRESSIONSEND 569
#define NUMBEROFEXPR 570
#define EXPRSTART 571
#define EXPREND 572
#define NUMBEROFMATRIXTERMSATT 573
#define MATRIXTERMSTART 574
#define MATRIXTERMEND 575
#define POWERSTART 576
#define POWEREND 577
#define PLUSSTART 578
#define PLUSEND 579
#define MINUSSTART 580
#define MINUSEND 581
#define DIVIDESTART 582
#define DIVIDEEND 583
#define LNSTART 584
#define LNEND 585
#define SQRTSTART 586
#define SQRTEND 587
#define SUMSTART 588
#define SUMEND 589
#define PRODUCTSTART 590
#define PRODUCTEND 591
#define EXPSTART 592
#define EXPEND 593
#define NEGATESTART 594
#define NEGATEEND 595
#define IFSTART 596
#define IFEND 597
#define SQUARESTART 598
#define SQUAREEND 599
#define COSSTART 600
#define COSEND 601
#define SINSTART 602
#define SINEND 603
#define VARIABLESTART 604
#define VARIABLEEND 605
#define ABSSTART 606
#define ABSEND 607
#define ERFSTART 608
#define ERFEND 609
#define MAXSTART 610
#define MAXEND 611
#define ALLDIFFSTART 612
#define ALLDIFFEND 613
#define MINSTART 614
#define MINEND 615
#define ESTART 616
#define EEND 617
#define PISTART 618
#define PIEND 619
#define TIMESSTART 620
#define TIMESEND 621
#define NUMBERSTART 622
#define NUMBEREND 623
#define MATRIXDETERMINANTSTART 624
#define MATRIXDETERMINANTEND 625
#define MATRIXTRACESTART 626
#define MATRIXTRACEEND 627
#define MATRIXTOSCALARSTART 628
#define MATRIXTOSCALAREND 629
#define MATRIXDIAGONALSTART 630
#define MATRIXDIAGONALEND 631
#define MATRIXDOTTIMESSTART 632
#define MATRIXDOTTIMESEND 633
#define MATRIXLOWERTRIANGLESTART 634
#define MATRIXLOWERTRIANGLEEND 635
#define MATRIXUPPERTRIANGLESTART 636
#define MATRIXUPPERTRIANGLEEND 637
#define MATRIXMERGESTART 638
#define MATRIXMERGEEND 639
#define MATRIXMINUSSTART 640
#define MATRIXMINUSEND 641
#define MATRIXNEGATESTART 642
#define MATRIXNEGATEEND 643
#define MATRIXPLUSSTART 644
#define MATRIXPLUSEND 645
#define MATRIXTIMESSTART 646
#define MATRIXTIMESEND 647
#define MATRIXPRODUCTSTART 648
#define MATRIXPRODUCTEND 649
#define MATRIXSCALARTIMESSTART 650
#define MATRIXSCALARTIMESEND 651
#define MATRIXSUBMATRIXATSTART 652
#define MATRIXSUBMATRIXATEND 653
#define MATRIXTRANSPOSESTART 654
#define MATRIXTRANSPOSEEND 655
#define MATRIXREFERENCESTART 656
#define MATRIXREFERENCEEND 657
#define IDENTITYMATRIXSTART 658
#define IDENTITYMATRIXEND 659
#define MATRIXINVERSESTART 660
#define MATRIXINVERSEEND 661
#define EMPTYINCLUDEDIAGONALATT 662
#define INCLUDEDIAGONALATT 663
#define EMPTYIDATT 664
#define IDATT 665




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
#define YYLAST   1269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  415
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  678
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1018
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1575

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   665

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   412,
     414,     2,     2,   413,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   411,     2,     2,     2,     2,     2,     2,     2,
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
     405,   406,   407,   408,   409,   410
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
    1236,  1238,  1243,  1245,  1247,  1248,  1251,  1253,  1255,  1259,
    1260,  1263,  1266,  1268,  1270,  1272,  1274,  1278,  1280,  1283,
    1285,  1287,  1289,  1291,  1295,  1297,  1300,  1302,  1304,  1306,
    1308,  1312,  1314,  1319,  1321,  1323,  1324,  1327,  1329,  1331,
    1335,  1336,  1339,  1342,  1344,  1346,  1348,  1350,  1354,  1356,
    1361,  1363,  1365,  1366,  1369,  1371,  1373,  1377,  1378,  1381,
    1382,  1385,  1387,  1389,  1391,  1393,  1397,  1399,  1400,  1403,
    1407,  1409,  1411,  1412,  1415,  1417,  1419,  1421,  1423,  1425,
    1429,  1430,  1433,  1437,  1439,  1440,  1442,  1446,  1451,  1453,
    1455,  1456,  1459,  1461,  1463,  1467,  1468,  1471,  1472,  1475,
    1477,  1479,  1481,  1483,  1487,  1488,  1491,  1494,  1496,  1498,
    1500,  1502,  1506,  1511,  1513,  1515,  1516,  1519,  1521,  1523,
    1527,  1528,  1531,  1534,  1536,  1538,  1540,  1542,  1546,  1548,
    1553,  1555,  1557,  1558,  1561,  1563,  1565,  1569,  1570,  1573,
    1574,  1577,  1579,  1581,  1583,  1585,  1589,  1590,  1593,  1597,
    1599,  1600,  1603,  1605,  1607,  1609,  1613,  1618,  1620,  1622,
    1623,  1626,  1628,  1630,  1634,  1635,  1638,  1639,  1642,  1644,
    1646,  1648,  1650,  1654,  1655,  1658,  1662,  1664,  1665,  1668,
    1670,  1672,  1674,  1677,  1679,  1684,  1686,  1688,  1689,  1692,
    1694,  1696,  1700,  1701,  1704,  1707,  1709,  1711,  1713,  1715,
    1719,  1721,  1727,  1729,  1730,  1732,  1734,  1738,  1740,  1742,
    1748,  1750,  1754,  1756,  1758,  1760,  1762,  1764,  1768,  1770,
    1774,  1776,  1778,  1780,  1782,  1784,  1788,  1790,  1791,  1794,
    1798,  1800,  1802,  1803,  1806,  1808,  1810,  1812,  1814,  1816,
    1818,  1820,  1824,  1829,  1834,  1839,  1844,  1849,  1854,  1859,
    1864,  1869,  1874,  1879,  1884,  1889,  1894,  1899,  1904,  1909,
    1914,  1919,  1924,  1929,  1934,  1939,  1944,  1946,  1948,  1950,
    1954,  1956,  1958,  1960,  1964,  1966,  1968,  1970,  1974,  1976,
    1978,  1980,  1984,  1986,  1988,  1990,  1994,  1996,  1998,  2000,
    2004,  2006,  2008,  2010,  2014,  2016,  2018,  2020,  2024,  2026,
    2028,  2030,  2034,  2035,  2040,  2042,  2048,  2049,  2052,  2058,
    2060,  2062,  2063,  2066,  2068,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,
    2100,  2102,  2104,  2106,  2108,  2110,  2112,  2114,  2116,  2118,
    2120,  2122,  2124,  2125,  2129,  2131,  2134,  2135,  2139,  2141,
    2144,  2145,  2151,  2152,  2158,  2159,  2165,  2166,  2171,  2172,
    2178,  2179,  2185,  2186,  2191,  2192,  2197,  2198,  2203,  2204,
    2209,  2210,  2215,  2216,  2221,  2225,  2227,  2229,  2230,  2235,
    2236,  2243,  2244,  2249,  2250,  2255,  2256,  2261,  2265,  2267,
    2269,  2272,  2273,  2276,  2278,  2280,  2282,  2283,  2288,  2289,
    2294,  2296,  2299,  2300,  2305,  2306,  2309,  2311,  2313,  2318,
    2323,  2324,  2329,  2330,  2333,  2334,  2339,  2340,  2343,  2344,
    2349,  2350,  2353,  2354,  2359,  2360,  2363,  2364,  2369,  2370,
    2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,
    2415,  2417,  2419,  2422,  2427,  2431,  2433,  2435,  2438,  2443,
    2447,  2449,  2451,  2454,  2459,  2463,  2465,  2467,  2470,  2475,
    2478,  2480,  2483,  2486,  2488,  2492,  2495,  2497,  2500,  2503,
    2505,  2508,  2513,  2515,  2516,  2518,  2521,  2526,  2528,  2529,
    2531,  2534,  2538,  2541,  2543,  2545,  2548,  2551,  2553,  2557,
    2560,  2562,  2565,  2568,  2570,  2574,  2577,  2579,  2583,  2584,
    2589,  2590,  2593,  2596,  2598,  2602,  2605,  2607,  2614,  2617,
    2619,  2622,  2623,  2627,  2629,  2631,  2636,  2638,  2640,  2642,
    2646,  2647,  2650,  2656,  2658,  2660,  2661,  2664,  2666
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     416,     0,    -1,   420,   933,   433,   440,   530,   577,   417,
     418,    -1,    41,    -1,    40,    -1,   419,    -1,    39,    -1,
      -1,    -1,   421,   422,   423,    43,    -1,    42,    -1,    14,
       8,     6,     8,    11,    -1,    -1,   423,   424,    -1,   425,
     427,   426,    -1,    44,    -1,    10,    -1,    11,    45,    -1,
      -1,   427,   428,    -1,   429,    -1,   430,    -1,   431,    -1,
     432,    -1,    17,     8,     6,     8,    -1,    18,     8,     6,
       8,    -1,   201,     8,   656,     8,    -1,   197,     8,     6,
       8,    -1,    -1,   434,   435,   436,    -1,   203,    -1,   634,
      -1,   437,    -1,   438,    -1,    10,    -1,    11,   439,   204,
      -1,    -1,   439,   688,    -1,    -1,   441,   442,   443,    -1,
      46,    -1,   635,    -1,   444,    -1,   445,    -1,    10,    -1,
      11,   446,    47,    -1,    -1,   446,   447,    -1,   448,    -1,
     454,    -1,   460,    -1,   475,    -1,   482,    -1,   488,    -1,
     494,    -1,   500,    -1,   515,    -1,   449,   450,   453,    -1,
      48,    -1,   451,    -1,    -1,   451,   452,    -1,   885,    -1,
     883,    -1,   909,    -1,    10,    -1,    11,    49,    -1,   455,
     456,   459,    -1,    50,    -1,   457,    -1,    -1,   457,   458,
      -1,   885,    -1,   883,    -1,   909,    -1,    10,    -1,    11,
      51,    -1,   461,   462,   465,    -1,    52,    -1,   463,    -1,
      -1,   463,   464,    -1,   885,    -1,   883,    -1,   909,    -1,
      10,    -1,    11,   466,   474,    -1,   467,    -1,    -1,   467,
     468,    -1,   469,   470,   473,    -1,    70,    -1,   471,    -1,
      -1,   471,   472,    -1,   921,    -1,   898,    -1,    10,    -1,
      11,    71,    -1,    53,    -1,   476,   477,   481,    -1,    54,
      -1,   478,    -1,    -1,   478,   479,    -1,   885,    -1,   883,
      -1,   480,    -1,   909,    -1,    28,     8,     6,     8,    -1,
      10,    -1,    11,    55,    -1,   483,   484,   487,    -1,    56,
      -1,   485,    -1,    -1,   485,   486,    -1,   885,    -1,   883,
      -1,   909,    -1,   640,    -1,   639,    -1,   641,    -1,    10,
      -1,    11,    57,    -1,   489,   490,   493,    -1,    58,    -1,
     491,    -1,    -1,   491,   492,    -1,   885,    -1,   883,    -1,
     909,    -1,   640,    -1,   639,    -1,   642,    -1,   643,    -1,
      10,    -1,    11,    59,    -1,   495,   496,   499,    -1,    60,
      -1,   497,    -1,    -1,   497,   498,    -1,   885,    -1,   883,
      -1,   909,    -1,   644,    -1,    10,    -1,    11,    61,    -1,
     501,   502,   505,    -1,    62,    -1,   503,    -1,    -1,   503,
     504,    -1,   885,    -1,   883,    -1,   909,    -1,    11,   506,
     514,    -1,   507,   508,   509,    -1,    72,    -1,   884,    -1,
     510,    -1,   511,    -1,    10,    -1,    11,   512,   513,    -1,
     660,    -1,    73,    -1,    63,    -1,   516,   517,   520,    -1,
      64,    -1,   518,    -1,    -1,   518,   519,    -1,   885,    -1,
     883,    -1,   909,    -1,    11,   521,   529,    -1,   522,   523,
     524,    -1,    74,    -1,   884,    -1,   525,    -1,   526,    -1,
      10,    -1,    11,   527,   528,    -1,   660,    -1,    75,    -1,
      65,    -1,    -1,   531,   532,    -1,   247,    -1,   533,    -1,
     534,    -1,    10,    -1,    11,   535,   549,   563,  1080,   248,
      -1,    -1,   536,   537,   538,    -1,   249,    -1,   636,    -1,
     539,    -1,   540,    -1,    10,    -1,    11,   542,   541,    -1,
     250,    -1,    -1,   542,   543,    -1,   544,   545,   548,    -1,
     251,    -1,   546,    -1,    -1,   546,   547,    -1,   885,    -1,
     883,    -1,   649,    -1,   650,    -1,   646,    -1,   653,    -1,
     647,    -1,   654,    -1,   909,    -1,   930,    -1,   898,    -1,
      10,    -1,    11,   252,    -1,    -1,   550,   551,   552,    -1,
     253,    -1,   637,    -1,   553,    -1,   554,    -1,    10,    -1,
      11,   556,   555,    -1,   254,    -1,    -1,   556,   557,    -1,
     558,   559,   562,    -1,   255,    -1,   560,    -1,    -1,   560,
     561,    -1,   885,    -1,   883,    -1,   649,    -1,   651,    -1,
     655,    -1,   648,    -1,   909,    -1,   898,    -1,    10,    -1,
      11,   256,    -1,    -1,   564,   565,   566,    -1,   257,    -1,
     638,    -1,   567,    -1,   568,    -1,    10,    -1,    11,   570,
     569,    -1,   258,    -1,    -1,   570,   571,    -1,   572,   573,
     576,    -1,   259,    -1,   574,    -1,    -1,   574,   575,    -1,
     885,    -1,   883,    -1,   649,    -1,   652,    -1,   646,    -1,
     653,    -1,   647,    -1,   654,    -1,   909,    -1,    10,    -1,
      11,   260,    -1,    -1,   578,   579,    -1,    76,    -1,   580,
      -1,   581,    -1,    10,    -1,    11,    77,    -1,    11,   582,
      77,    -1,    11,   626,    77,    -1,   583,   584,   585,    79,
      -1,    78,    -1,    16,     8,     6,     8,    11,    -1,   586,
      -1,   585,   586,    -1,    -1,   587,    80,   588,   589,    -1,
      -1,   132,     3,     8,    -1,    10,    -1,    11,   590,    81,
      -1,   591,   603,   615,    -1,    -1,   271,   592,   596,    -1,
      -1,   592,   593,    -1,   594,    -1,   595,    -1,   176,     8,
       6,     8,    -1,    21,     8,     6,     8,    -1,   597,    -1,
      11,   598,   272,    -1,    10,    -1,    11,   272,    -1,   599,
      -1,   598,   599,    -1,    -1,   600,   269,   601,   602,    -1,
     197,     8,     6,     8,    -1,    10,    -1,    11,   270,    -1,
      -1,   263,   604,   608,    -1,    -1,   604,   605,    -1,   606,
      -1,   607,    -1,   170,     8,     6,     8,    -1,    21,     8,
       6,     8,    -1,   609,    -1,    11,   610,   264,    -1,    10,
      -1,    11,   264,    -1,   611,    -1,   610,   611,    -1,    -1,
     612,   261,   613,   614,    -1,   197,     8,     6,     8,    -1,
      10,    -1,    11,   262,    -1,    -1,   267,   616,   619,    -1,
      -1,   616,   617,    -1,   618,    -1,   631,    -1,   173,     8,
       6,     8,    -1,   620,    -1,    11,   621,   268,    -1,    10,
      -1,    11,   268,    -1,   622,    -1,   621,   622,    -1,    -1,
     623,   265,   624,   625,    -1,   197,     8,     6,     8,    -1,
      10,    -1,    11,   266,    -1,    -1,   627,    82,   629,   628,
      -1,    10,    -1,    11,    83,    -1,    -1,   629,   630,    -1,
     632,    -1,   633,    -1,    21,     8,     6,     8,    -1,    19,
       8,   656,     8,    -1,    20,     8,   656,     8,    -1,   168,
       8,     6,     8,    -1,    15,     8,     6,     8,    -1,   181,
       8,     6,     8,    -1,   180,     8,     6,     8,    -1,   179,
       8,     6,     8,    -1,    34,     8,   656,     8,    -1,    35,
       8,     6,     8,    -1,    36,     8,     6,     8,    -1,    37,
       8,     6,     8,    -1,    38,     8,     6,     8,    -1,    13,
       3,     8,    -1,    22,     8,     6,     8,    -1,    23,     8,
       6,     8,    -1,    25,     8,     6,     8,    -1,    33,     8,
       6,     8,    -1,    27,     8,     6,     8,    -1,    29,     8,
       6,     8,    -1,    30,     8,     6,     8,    -1,    31,     8,
       6,     8,    -1,    24,     8,     6,     8,    -1,    26,     8,
       6,     8,    -1,    32,     8,     6,     8,    -1,   658,     6,
     658,    -1,   658,     7,   658,    -1,   658,     8,    -1,    -1,
     658,   659,    -1,   411,    -1,   412,    -1,   413,    -1,   414,
      -1,   661,    -1,   668,    -1,    -1,   661,   662,    -1,   663,
     664,   667,    -1,   112,    -1,   665,    -1,    -1,   665,   666,
      -1,   898,    -1,   897,    -1,    11,     6,   113,    -1,   120,
     888,   669,    -1,   670,    -1,   671,    -1,    11,   121,    -1,
      10,    -1,    11,     4,   121,    -1,   673,    -1,   678,    -1,
      -1,   673,   674,    -1,   675,   676,   677,    -1,   112,    -1,
      -1,   898,    -1,    11,   656,   113,    -1,   120,   888,   679,
      -1,   680,    -1,   681,    -1,    11,   121,    -1,    10,    -1,
      11,     4,   121,    -1,   683,    -1,    -1,   683,   684,    -1,
     685,   686,   687,    -1,   112,    -1,    -1,   898,    -1,    11,
       4,   113,    -1,   689,   690,   693,    -1,   205,    -1,   691,
      -1,    -1,   691,   692,    -1,   918,    -1,   885,    -1,   883,
      -1,   909,    -1,   921,    -1,   694,    -1,   695,    -1,    10,
      -1,    11,   696,   206,    -1,   697,   703,    -1,    -1,   698,
     699,   702,    -1,   208,    -1,   700,    -1,    -1,   700,   701,
      -1,   889,    -1,   899,    -1,   900,    -1,   890,    -1,   891,
      -1,   892,    -1,   893,    -1,   906,    -1,   905,    -1,    11,
     207,    -1,    10,    -1,    -1,   703,   704,    -1,   705,    -1,
     730,    -1,   743,    -1,   770,    -1,   788,    -1,   801,    -1,
     819,    -1,   837,    -1,   850,    -1,   854,    -1,   706,   707,
      11,   710,    -1,   219,    -1,   708,    -1,    -1,   708,   709,
      -1,   886,    -1,   912,    -1,   712,   711,   220,    -1,    -1,
     718,   724,    -1,   713,   714,    -1,   237,    -1,   715,    -1,
     716,    -1,    10,    -1,    11,   717,   238,    -1,   660,    -1,
     719,   720,    -1,   239,    -1,   721,    -1,   722,    -1,    10,
      -1,    11,   723,   240,    -1,   660,    -1,   725,   726,    -1,
     241,    -1,   727,    -1,   728,    -1,    10,    -1,    11,   729,
     242,    -1,   672,    -1,   731,   732,    11,   735,    -1,   223,
      -1,   733,    -1,    -1,   733,   734,    -1,   886,    -1,   912,
      -1,   712,   736,   224,    -1,    -1,   718,   737,    -1,   738,
     739,    -1,   241,    -1,   740,    -1,   741,    -1,    10,    -1,
      11,   742,   242,    -1,   660,    -1,   744,   745,    11,   748,
      -1,   225,    -1,   746,    -1,    -1,   746,   747,    -1,   886,
      -1,   912,    -1,   712,   749,   226,    -1,    -1,   718,   750,
      -1,    -1,   751,   752,    -1,   241,    -1,   753,    -1,   754,
      -1,    10,    -1,    11,   755,   242,    -1,   756,    -1,    -1,
     756,   757,    -1,   758,   759,   762,    -1,   112,    -1,   760,
      -1,    -1,   760,   761,    -1,   887,    -1,   902,    -1,   763,
      -1,   764,    -1,    10,    -1,    11,   765,   113,    -1,    -1,
     765,   766,    -1,   767,   768,   769,    -1,   243,    -1,    -1,
     901,    -1,    11,     6,   244,    -1,   771,   772,    11,   775,
      -1,   231,    -1,   773,    -1,    -1,   773,   774,    -1,   886,
      -1,   912,    -1,   712,   776,   232,    -1,    -1,   718,   777,
      -1,    -1,   778,   779,    -1,   241,    -1,   780,    -1,   781,
      -1,    10,    -1,    11,   782,   242,    -1,    -1,   782,   783,
      -1,   784,   785,    -1,   112,    -1,   786,    -1,   787,    -1,
      10,    -1,    11,   942,   113,    -1,   789,   790,    11,   793,
      -1,   229,    -1,   791,    -1,    -1,   791,   792,    -1,   886,
      -1,   912,    -1,   712,   794,   230,    -1,    -1,   718,   795,
      -1,   796,   797,    -1,   241,    -1,   798,    -1,   799,    -1,
      10,    -1,    11,   800,   242,    -1,   660,    -1,   802,   803,
      11,   806,    -1,   227,    -1,   804,    -1,    -1,   804,   805,
      -1,   886,    -1,   912,    -1,   712,   807,   228,    -1,    -1,
     718,   808,    -1,    -1,   809,   810,    -1,   241,    -1,   811,
      -1,   812,    -1,    10,    -1,    11,   813,   242,    -1,    -1,
     813,   814,    -1,   815,   816,   818,    -1,   112,    -1,    -1,
     816,   817,    -1,   927,    -1,   898,    -1,   897,    -1,    11,
       6,   113,    -1,   820,   821,    11,   824,    -1,   221,    -1,
     822,    -1,    -1,   822,   823,    -1,   886,    -1,   912,    -1,
     712,   825,   222,    -1,    -1,   718,   826,    -1,    -1,   827,
     828,    -1,   241,    -1,   829,    -1,   830,    -1,    10,    -1,
      11,   831,   242,    -1,    -1,   831,   832,    -1,   833,   834,
     836,    -1,   112,    -1,    -1,   834,   835,    -1,   904,    -1,
     903,    -1,   898,    -1,    11,   113,    -1,    10,    -1,   838,
     839,    11,   842,    -1,   235,    -1,   840,    -1,    -1,   840,
     841,    -1,   886,    -1,   912,    -1,   712,   843,   236,    -1,
      -1,   718,   844,    -1,   845,   846,    -1,   241,    -1,   847,
      -1,   848,    -1,    10,    -1,    11,   849,   242,    -1,   682,
      -1,   851,   852,    11,  1016,   853,    -1,   245,    -1,    -1,
     915,    -1,   246,    -1,   855,   856,   857,    -1,   209,    -1,
     882,    -1,    11,   859,   866,   873,   858,    -1,   210,    -1,
     860,   861,   862,    -1,   213,    -1,   884,    -1,   863,    -1,
     864,    -1,    10,    -1,    11,   865,   214,    -1,   660,    -1,
     867,   868,   869,    -1,   215,    -1,   884,    -1,   870,    -1,
     871,    -1,    10,    -1,    11,   872,   216,    -1,   660,    -1,
      -1,   873,   874,    -1,   875,   876,   879,    -1,   211,    -1,
     877,    -1,    -1,   877,   878,    -1,   894,    -1,   895,    -1,
     918,    -1,   921,    -1,   880,    -1,   881,    -1,    10,    -1,
      11,   696,   212,    -1,   165,     8,     6,     8,    -1,   166,
       8,     6,     8,    -1,   122,     8,     6,     8,    -1,   167,
       8,     6,     8,    -1,   169,     8,     6,     8,    -1,   178,
       8,     6,     8,    -1,   200,     8,     6,     8,    -1,   182,
       8,     6,     8,    -1,   185,     8,     6,     8,    -1,   186,
       8,     6,     8,    -1,   187,     8,     6,     8,    -1,   188,
       8,     6,     8,    -1,   190,     8,     6,     8,    -1,   191,
       8,     6,     8,    -1,   197,     8,     6,     8,    -1,   198,
       8,     6,     8,    -1,   199,     8,     6,     8,    -1,   183,
       8,     6,     8,    -1,   184,     8,     6,     8,    -1,   201,
       8,   656,     8,    -1,   202,     8,   656,     8,    -1,   193,
       8,   656,     8,    -1,   192,     8,   656,     8,    -1,   189,
       8,   656,     8,    -1,   907,    -1,   908,    -1,   163,    -1,
     164,     3,   657,    -1,   910,    -1,   911,    -1,   131,    -1,
     132,     3,     8,    -1,   913,    -1,   914,    -1,   161,    -1,
     162,     3,     8,    -1,   916,    -1,   917,    -1,   137,    -1,
     138,     3,     8,    -1,   919,    -1,   920,    -1,   159,    -1,
     160,     3,     8,    -1,   922,    -1,   923,    -1,   133,    -1,
     134,     3,     8,    -1,   925,    -1,   926,    -1,   141,    -1,
     142,     3,     8,    -1,   928,    -1,   929,    -1,   143,    -1,
     144,     3,     8,    -1,   931,    -1,   932,    -1,   149,    -1,
     150,     3,     8,    -1,    -1,   934,   935,   936,   309,    -1,
     308,    -1,   310,     8,     6,     8,    11,    -1,    -1,   936,
     937,    -1,   938,   939,    11,   942,   312,    -1,   311,    -1,
     940,    -1,    -1,   940,   941,    -1,   896,    -1,   915,    -1,
     986,    -1,   993,    -1,   949,    -1,   951,    -1,  1001,    -1,
     953,    -1,   955,    -1,   957,    -1,   959,    -1,  1013,    -1,
     961,    -1,   963,    -1,   965,    -1,   969,    -1,   967,    -1,
     971,    -1,   978,    -1,   973,    -1,   976,    -1,  1007,    -1,
    1010,    -1,   943,    -1,   946,    -1,  1004,    -1,   980,    -1,
     982,    -1,   984,    -1,    -1,   361,   944,   945,    -1,    10,
      -1,    11,   362,    -1,    -1,   363,   947,   948,    -1,    10,
      -1,    11,   364,    -1,    -1,   365,   950,   942,   942,   366,
      -1,    -1,   323,   952,   942,   942,   324,    -1,    -1,   325,
     954,   942,   942,   326,    -1,    -1,   339,   956,   942,   340,
      -1,    -1,   327,   958,   942,   942,   328,    -1,    -1,   321,
     960,   942,   942,   322,    -1,    -1,   329,   962,   942,   330,
      -1,    -1,   331,   964,   942,   332,    -1,    -1,   343,   966,
     942,   344,    -1,    -1,   345,   968,   942,   346,    -1,    -1,
     347,   970,   942,   348,    -1,    -1,   337,   972,   942,   338,
      -1,   974,   942,   975,    -1,   351,    -1,   352,    -1,    -1,
     353,   977,   942,   354,    -1,    -1,   341,   979,   942,   942,
     942,   342,    -1,    -1,   369,   981,  1016,   370,    -1,    -1,
     371,   983,  1016,   372,    -1,    -1,   373,   985,  1016,   374,
      -1,   987,   989,   988,    -1,   367,    -1,    10,    -1,    11,
     368,    -1,    -1,   989,   990,    -1,   921,    -1,   924,    -1,
     991,    -1,    -1,   410,     3,   992,     8,    -1,    -1,   349,
     994,   997,   995,    -1,    10,    -1,    11,   350,    -1,    -1,
      11,   942,   996,   350,    -1,    -1,   997,   998,    -1,   999,
      -1,  1000,    -1,   201,     8,   656,     8,    -1,   197,     8,
       6,     8,    -1,    -1,   333,  1002,  1003,   334,    -1,    -1,
    1003,   942,    -1,    -1,   357,  1005,  1006,   358,    -1,    -1,
    1006,   942,    -1,    -1,   355,  1008,  1009,   356,    -1,    -1,
    1009,   942,    -1,    -1,   359,  1011,  1012,   360,    -1,    -1,
    1012,   942,    -1,    -1,   335,  1014,  1015,   336,    -1,    -1,
    1015,   942,    -1,  1017,    -1,  1020,    -1,  1024,    -1,  1028,
      -1,  1032,    -1,  1035,    -1,  1041,    -1,  1044,    -1,  1048,
      -1,  1053,    -1,  1056,    -1,  1059,    -1,  1062,    -1,  1065,
      -1,  1068,    -1,  1071,    -1,  1074,    -1,  1077,    -1,  1038,
      -1,  1018,   645,  1019,    -1,   401,    -1,    10,    -1,    11,
     402,    -1,   197,     8,     6,     8,    -1,  1021,  1023,  1022,
      -1,   251,    -1,    10,    -1,    11,   252,    -1,   197,     8,
       6,     8,    -1,  1025,  1027,  1026,    -1,   255,    -1,    10,
      -1,    11,   256,    -1,   197,     8,     6,     8,    -1,  1029,
    1031,  1030,    -1,   259,    -1,    10,    -1,    11,   260,    -1,
     197,     8,     6,     8,    -1,  1033,  1034,    -1,   375,    -1,
    1016,   376,    -1,  1036,  1037,    -1,   377,    -1,  1016,  1016,
     378,    -1,  1039,  1040,    -1,   403,    -1,   942,   404,    -1,
    1042,  1043,    -1,   405,    -1,  1016,   406,    -1,  1045,  1046,
      11,  1047,    -1,   379,    -1,    -1,  1052,    -1,  1016,   380,
      -1,  1049,  1050,    11,  1051,    -1,   381,    -1,    -1,  1052,
      -1,  1016,   382,    -1,   408,     3,     8,    -1,  1054,  1055,
      -1,   383,    -1,    10,    -1,    11,   384,    -1,  1057,  1058,
      -1,   385,    -1,  1016,  1016,   386,    -1,  1060,  1061,    -1,
     387,    -1,  1016,   388,    -1,  1063,  1064,    -1,   389,    -1,
    1016,  1016,   390,    -1,  1066,  1067,    -1,   391,    -1,  1016,
    1016,   392,    -1,    -1,   393,  1069,  1070,   394,    -1,    -1,
    1070,  1016,    -1,  1072,  1073,    -1,   395,    -1,   942,  1016,
     396,    -1,  1075,  1076,    -1,   397,    -1,   942,   942,   942,
     942,  1016,   398,    -1,  1078,  1079,    -1,   399,    -1,  1016,
     400,    -1,    -1,  1081,  1082,  1084,    -1,   313,    -1,  1083,
      -1,   315,     8,     6,     8,    -1,  1085,    -1,  1086,    -1,
      10,    -1,    11,  1087,   314,    -1,    -1,  1087,  1088,    -1,
    1089,  1090,    11,  1016,   317,    -1,   316,    -1,  1091,    -1,
      -1,  1091,  1092,    -1,   896,    -1,   915,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   431,   431,   434,   435,   437,   446,   447,   450,   451,
     455,   460,   470,   470,   472,   485,   491,   492,   495,   496,
     499,   502,   505,   508,   514,   521,   528,   536,   541,   541,
     549,   555,   567,   567,   569,   571,   578,   578,   581,   581,
     587,   593,   605,   605,   607,   609,   613,   613,   621,   622,
     623,   624,   625,   626,   628,   635,   636,   641,   643,   652,
     654,   654,   657,   662,   667,   672,   672,   674,   677,   686,
     688,   688,   691,   696,   701,   706,   706,   709,   711,   720,
     730,   730,   733,   738,   743,   749,   749,   755,   757,   757,
     759,   761,   768,   806,   807,   809,   809,   811,   811,   813,
     815,   817,   826,   828,   828,   831,   836,   841,   846,   851,
     862,   862,   866,   868,   880,   882,   882,   885,   890,   895,
     899,   904,   909,   916,   916,   918,   920,   933,   935,   935,
     938,   943,   948,   953,   958,   963,   968,   975,   975,   979,
     981,   991,   993,   993,   996,  1001,  1006,  1010,  1017,  1017,
    1031,  1033,  1042,  1044,  1044,  1047,  1052,  1057,  1062,  1064,
    1066,  1072,  1078,  1078,  1080,  1082,  1084,  1086,  1100,  1103,
    1105,  1114,  1116,  1116,  1119,  1124,  1129,  1134,  1136,  1138,
    1144,  1150,  1150,  1152,  1154,  1156,  1158,  1172,  1181,  1181,
    1183,  1188,  1188,  1190,  1193,  1195,  1195,  1202,  1207,  1217,
    1217,  1219,  1221,  1223,  1225,  1225,  1227,  1232,  1248,  1296,
    1296,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1312,  1313,  1315,  1315,  1321,  1326,  1336,  1336,
    1338,  1340,  1342,  1344,  1344,  1346,  1351,  1364,  1397,  1397,
    1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1410,  1411,
    1414,  1414,  1420,  1425,  1435,  1435,  1437,  1439,  1441,  1443,
    1443,  1445,  1450,  1465,  1504,  1504,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1518,  1519,  1562,  1562,  1564,
    1566,  1566,  1568,  1569,  1572,  1573,  1576,  1627,  1629,  1643,
    1644,  1646,  1646,  1670,  1671,  1674,  1675,  1677,  1679,  1680,
    1684,  1685,  1687,  1688,  1690,  1709,  1720,  1727,  1732,  1733,
    1735,  1736,  1738,  1738,  1741,  1753,  1754,  1756,  1757,  1761,
    1762,  1764,  1765,  1767,  1786,  1797,  1804,  1809,  1810,  1812,
    1813,  1815,  1815,  1818,  1830,  1831,  1833,  1843,  1847,  1848,
    1850,  1851,  1853,  1872,  1879,  1884,  1885,  1887,  1888,  1890,
    1890,  1893,  1905,  1906,  1911,  1911,  1919,  1920,  1922,  1923,
    1925,  1929,  1935,  1946,  1951,  1966,  1977,  1988,  1996,  2004,
    2023,  2034,  2045,  2057,  2068,  2079,  2091,  2102,  2114,  2126,
    2138,  2150,  2162,  2174,  2186,  2198,  2210,  2237,  2238,  2245,
    2247,  2247,  2249,  2250,  2251,  2252,  2416,  2424,  2426,  2426,
    2428,  2430,  2439,  2441,  2441,  2443,  2443,  2445,  2461,  2464,
    2464,  2466,  2466,  2469,  2500,  2508,  2510,  2510,  2512,  2514,
    2522,  2522,  2524,  2540,  2542,  2542,  2544,  2544,  2546,  2577,
    2587,  2587,  2589,  2591,  2599,  2599,  2601,  2870,  2921,  2944,
    2962,  2962,  2965,  2966,  2967,  2968,  2969,  3148,  3148,  3150,
    3152,  3192,  3194,  3194,  3199,  3217,  3244,  3244,  3247,  3248,
    3249,  3250,  3251,  3252,  3253,  3254,  3255,  3258,  3258,  3260,
    3260,  3265,  3265,  3265,  3265,  3266,  3266,  3267,  3267,  3268,
    3268,  3270,  3272,  3281,  3287,  3287,  3290,  3296,  3302,  3304,
    3304,  3310,  3320,  3330,  3330,  3332,  3334,  3336,  3339,  3350,
    3357,  3357,  3359,  3361,  3363,  3369,  3379,  3386,  3386,  3388,
    3390,  3392,  3395,  3397,  3406,  3412,  3412,  3415,  3421,  3427,
    3429,  3429,  3431,  3441,  3448,  3448,  3450,  3452,  3454,  3456,
    3458,  3467,  3473,  3473,  3476,  3482,  3488,  3490,  3490,  3493,
    3498,  3509,  3524,  3524,  3526,  3528,  3530,  3532,  3532,  3534,
    3541,  3548,  3561,  3561,  3564,  3565,  3567,  3567,  3569,  3571,
    3573,  3573,  3576,  3578,  3586,  3586,  3591,  3599,  3601,  3610,
    3616,  3616,  3619,  3625,  3632,  3634,  3634,  3637,  3641,  3652,
    3667,  3667,  3669,  3671,  3673,  3673,  3675,  3677,  3692,  3692,
    3694,  3696,  3705,  3707,  3716,  3722,  3722,  3725,  3731,  3737,
    3739,  3739,  3741,  3751,  3758,  3758,  3760,  3762,  3764,  3767,
    3769,  3778,  3784,  3784,  3787,  3793,  3799,  3801,  3801,  3804,
    3808,  3819,  3834,  3834,  3836,  3838,  3840,  3840,  3842,  3845,
    3857,  3857,  3860,  3861,  3862,  3864,  3896,  3898,  3908,  3914,
    3914,  3917,  3923,  3929,  3931,  3931,  3934,  3938,  3949,  3961,
    3961,  3963,  3965,  3967,  3967,  3969,  3996,  4007,  4007,  4010,
    4011,  4012,  4014,  4014,  4017,  4019,  4028,  4034,  4034,  4037,
    4043,  4049,  4051,  4051,  4053,  4063,  4070,  4070,  4072,  4074,
    4076,  4079,  4082,  4100,  4100,  4111,  4118,  4128,  4136,  4142,
    4144,  4158,  4170,  4176,  4182,  4182,  4184,  4186,  4188,  4190,
    4200,  4206,  4212,  4212,  4214,  4216,  4218,  4220,  4220,  4225,
    4230,  4242,  4244,  4244,  4247,  4248,  4249,  4257,  4264,  4264,
    4266,  4268,  4286,  4297,  4341,  4464,  4475,  4497,  4522,  4533,
    4547,  4562,  4577,  4589,  4601,  4621,  4641,  4651,  4688,  4699,
    4711,  4725,  4738,  4751,  4762,  4773,  4786,  4786,  4788,  4798,
    4960,  4960,  4962,  4969,  4996,  4996,  4998,  5007,  5021,  5021,
    5023,  5030,  5057,  5057,  5059,  5066,  5075,  5075,  5077,  5084,
    5111,  5111,  5115,  5123,  5132,  5132,  5134,  5141,  5150,  5150,
    5152,  5159,  5198,  5199,  5205,  5211,  5232,  5233,  5235,  5243,
    5262,  5269,  5269,  5272,  5278,  5288,  5289,  5290,  5291,  5292,
    5293,  5294,  5295,  5296,  5297,  5298,  5299,  5300,  5301,  5302,
    5303,  5304,  5305,  5306,  5307,  5308,  5309,  5310,  5311,  5313,
    5314,  5315,  5319,  5319,  5322,  5323,  5325,  5325,  5328,  5329,
    5333,  5333,  5338,  5338,  5343,  5343,  5348,  5348,  5353,  5353,
    5358,  5358,  5363,  5363,  5368,  5368,  5373,  5373,  5378,  5378,
    5383,  5383,  5388,  5388,  5393,  5395,  5401,  5408,  5408,  5414,
    5414,  5426,  5426,  5431,  5431,  5436,  5436,  5446,  5453,  5459,
    5460,  5462,  5463,  5466,  5470,  5474,  5478,  5477,  5496,  5495,
    5502,  5503,  5505,  5504,  5511,  5512,  5515,  5521,  5529,  5536,
    5554,  5554,  5565,  5565,  5568,  5568,  5582,  5583,  5586,  5586,
    5599,  5600,  5603,  5603,  5616,  5617,  5620,  5620,  5630,  5631,
    5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,
    5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,  5655,  5658,
    5663,  5670,  5671,  5673,  5681,  5686,  5693,  5694,  5696,  5703,
    5708,  5715,  5716,  5718,  5725,  5730,  5737,  5738,  5740,  5747,
    5749,  5755,  5757,  5759,  5765,  5767,  5769,  5775,  5777,  5779,
    5785,  5787,  5789,  5795,  5795,  5800,  5802,  5804,  5810,  5810,
    5815,  5817,  5826,  5828,  5833,  5833,  5835,  5837,  5843,  5846,
    5848,  5854,  5857,  5859,  5865,  5868,  5870,  5876,  5880,  5879,
    5891,  5891,  5898,  5900,  5906,  5908,  5910,  5916,  5919,  5921,
    5927,  5937,  5937,  5943,  5951,  5953,  5973,  5973,  5975,  5977,
    5979,  5979,  5981,  5991,  6010,  6016,  6016,  6019,  6027
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
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   415,   416,   417,   417,   418,   419,   419,   420,   420,
     421,   422,   423,   423,   424,   425,   426,   426,   427,   427,
     428,   428,   428,   428,   429,   430,   431,   432,   433,   433,
     434,   435,   436,   436,   437,   438,   439,   439,   440,   440,
     441,   442,   443,   443,   444,   445,   446,   446,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   448,   449,   450,
     451,   451,   452,   452,   452,   453,   453,   454,   455,   456,
     457,   457,   458,   458,   458,   459,   459,   460,   461,   462,
     463,   463,   464,   464,   464,   465,   465,   466,   467,   467,
     468,   469,   470,   471,   471,   472,   472,   473,   473,   474,
     475,   476,   477,   478,   478,   479,   479,   479,   479,   480,
     481,   481,   482,   483,   484,   485,   485,   486,   486,   486,
     486,   486,   486,   487,   487,   488,   489,   490,   491,   491,
     492,   492,   492,   492,   492,   492,   492,   493,   493,   494,
     495,   496,   497,   497,   498,   498,   498,   498,   499,   499,
     500,   501,   502,   503,   503,   504,   504,   504,   505,   506,
     507,   508,   509,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   518,   519,   519,   519,   520,   521,   522,
     523,   524,   524,   525,   526,   527,   528,   529,   530,   530,
     531,   532,   532,   533,   534,   535,   535,   536,   537,   538,
     538,   539,   540,   541,   542,   542,   543,   544,   545,   546,
     546,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   548,   548,   549,   549,   550,   551,   552,   552,
     553,   554,   555,   556,   556,   557,   558,   559,   560,   560,
     561,   561,   561,   561,   561,   561,   561,   561,   562,   562,
     563,   563,   564,   565,   566,   566,   567,   568,   569,   570,
     570,   571,   572,   573,   574,   574,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   576,   576,   577,   577,   578,
     579,   579,   580,   580,   581,   581,   582,   583,   584,   585,
     585,   587,   586,   588,   588,   589,   589,   590,   591,   591,
     592,   592,   593,   593,   594,   595,   596,   596,   597,   597,
     598,   598,   600,   599,   601,   602,   602,   603,   603,   604,
     604,   605,   605,   606,   607,   608,   608,   609,   609,   610,
     610,   612,   611,   613,   614,   614,   615,   615,   616,   616,
     617,   617,   618,   619,   619,   620,   620,   621,   621,   623,
     622,   624,   625,   625,   627,   626,   628,   628,   629,   629,
     630,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   656,   657,
     658,   658,   659,   659,   659,   659,   660,   660,   661,   661,
     662,   663,   664,   665,   665,   666,   666,   667,   668,   669,
     669,   670,   670,   671,   672,   672,   673,   673,   674,   675,
     676,   676,   677,   678,   679,   679,   680,   680,   681,   682,
     683,   683,   684,   685,   686,   686,   687,   688,   689,   690,
     691,   691,   692,   692,   692,   692,   692,   693,   693,   694,
     695,   696,   697,   697,   698,   699,   700,   700,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   702,   702,   703,
     703,   704,   704,   704,   704,   704,   704,   704,   704,   704,
     704,   705,   706,   707,   708,   708,   709,   709,   710,   711,
     711,   712,   713,   714,   714,   715,   716,   717,   718,   719,
     720,   720,   721,   722,   723,   724,   725,   726,   726,   727,
     728,   729,   730,   731,   732,   733,   733,   734,   734,   735,
     736,   736,   737,   738,   739,   739,   740,   741,   742,   743,
     744,   745,   746,   746,   747,   747,   748,   749,   749,   750,
     750,   751,   752,   752,   753,   754,   755,   756,   756,   757,
     758,   759,   760,   760,   761,   761,   762,   762,   763,   764,
     765,   765,   766,   767,   768,   768,   769,   770,   771,   772,
     773,   773,   774,   774,   775,   776,   776,   777,   777,   778,
     779,   779,   780,   781,   782,   782,   783,   784,   785,   785,
     786,   787,   788,   789,   790,   791,   791,   792,   792,   793,
     794,   794,   795,   796,   797,   797,   798,   799,   800,   801,
     802,   803,   804,   804,   805,   805,   806,   807,   807,   808,
     808,   809,   810,   810,   811,   812,   813,   813,   814,   815,
     816,   816,   817,   817,   817,   818,   819,   820,   821,   822,
     822,   823,   823,   824,   825,   825,   826,   826,   827,   828,
     828,   829,   830,   831,   831,   832,   833,   834,   834,   835,
     835,   835,   836,   836,   837,   838,   839,   840,   840,   841,
     841,   842,   843,   843,   844,   845,   846,   846,   847,   848,
     849,   850,   851,   852,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   862,   863,   864,   865,   866,
     867,   868,   869,   869,   870,   871,   872,   873,   873,   874,
     875,   876,   877,   877,   878,   878,   878,   878,   879,   879,
     880,   881,   882,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   899,
     900,   901,   902,   903,   904,   905,   906,   906,   907,   908,
     909,   909,   910,   911,   912,   912,   913,   914,   915,   915,
     916,   917,   918,   918,   919,   920,   921,   921,   922,   923,
     924,   924,   925,   926,   927,   927,   928,   929,   930,   930,
     931,   932,   933,   933,   934,   935,   936,   936,   937,   938,
     939,   940,   940,   941,   941,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   944,   943,   945,   945,   947,   946,   948,   948,
     950,   949,   952,   951,   954,   953,   956,   955,   958,   957,
     960,   959,   962,   961,   964,   963,   966,   965,   968,   967,
     970,   969,   972,   971,   973,   974,   975,   977,   976,   979,
     978,   981,   980,   983,   982,   985,   984,   986,   987,   988,
     988,   989,   989,   990,   990,   990,   992,   991,   994,   993,
     995,   995,   996,   995,   997,   997,   998,   998,   999,  1000,
    1002,  1001,  1003,  1003,  1005,  1004,  1006,  1006,  1008,  1007,
    1009,  1009,  1011,  1010,  1012,  1012,  1014,  1013,  1015,  1015,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1017,
    1018,  1019,  1019,   645,  1020,  1021,  1022,  1022,  1023,  1024,
    1025,  1026,  1026,  1027,  1028,  1029,  1030,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1046,  1047,  1048,  1049,  1050,  1050,
    1051,  1052,  1053,  1054,  1055,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1069,  1068,
    1070,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1080,  1081,  1082,  1083,  1084,  1084,  1085,  1086,
    1087,  1087,  1088,  1089,  1090,  1091,  1091,  1092,  1092
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
       1,     4,     1,     1,     0,     2,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     0,     2,     0,
       2,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     0,     2,     1,
       1,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     0,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     2,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     5,     1,     0,     1,     1,     3,     1,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     0,     4,     1,     5,     0,     2,     5,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     1,     2,     0,     3,     1,     2,
       0,     5,     0,     5,     0,     5,     0,     4,     0,     5,
       0,     5,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     1,     1,     0,     4,     0,
       6,     0,     4,     0,     4,     0,     4,     3,     1,     1,
       2,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       1,     2,     0,     4,     0,     2,     1,     1,     4,     4,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     4,     3,     1,     1,     2,     4,     3,
       1,     1,     2,     4,     3,     1,     1,     2,     4,     2,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       2,     4,     1,     0,     1,     2,     4,     1,     0,     1,
       2,     3,     2,     1,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     1,     3,     0,     4,
       0,     2,     2,     1,     3,     2,     1,     6,     2,     1,
       2,     0,     3,     1,     1,     4,     1,     1,     1,     3,
       0,     2,     5,     1,     1,     0,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   782,     0,     1,   784,    28,     0,     0,
      12,    30,    38,     0,     0,   786,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   783,   789,   787,   791,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   790,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   438,    37,   440,
     785,     0,   760,     0,     0,   793,   794,   758,   759,   792,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   439,   840,   832,   834,   838,   842,   844,   890,   906,
     852,   836,   859,   846,   848,   850,   878,   855,   857,   898,
     894,   902,   822,   826,   830,   868,   861,   863,   865,     0,
     816,   817,   797,   798,   800,   801,   802,   803,   805,   806,
     807,   809,   808,   810,   812,     0,   813,   811,   819,   820,
     821,   795,   871,   796,   799,   818,   814,   815,   804,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,  1001,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   449,   452,   437,   447,   448,   752,     0,   768,     0,
     764,     0,     0,     0,   441,   444,   443,   445,   750,   751,
     442,   762,   763,   446,   766,   767,     0,     0,     0,     0,
       0,     0,   892,   908,     0,     0,     0,     0,     0,     0,
     884,     0,   900,   896,   904,     0,     0,     0,     0,     0,
       0,   788,     0,     0,   761,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1003,     0,     0,     0,     0,   253,     0,   230,
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
       0,   824,     0,   823,   828,     0,   827,     0,   935,   940,
     945,   950,   953,   962,   967,   973,   977,   980,   983,   986,
     988,   993,   996,   999,   930,   956,   959,     0,   910,     0,
     911,     0,   912,     0,   913,     0,   914,     0,   915,     0,
     928,     0,   916,     0,   917,   963,   918,   968,   919,     0,
     920,     0,   921,     0,   922,     0,   923,     0,   924,   925,
       0,   926,     0,   927,     0,     0,     0,   856,   854,   869,
       0,   772,     0,     0,   873,   874,   770,   771,   867,   872,
     875,   736,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,  1004,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   450,   451,     0,   455,   753,
     769,   765,     0,     0,     0,     0,     0,     0,   843,   845,
     891,   893,   907,   909,   853,   837,     0,   847,   849,   851,
     880,     0,     0,     0,   879,   885,   886,   887,   858,   899,
     901,   895,   897,   903,   905,   825,   829,     0,   990,   862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,     0,   952,     0,   955,     0,   958,     0,     0,   964,
       0,   969,   974,     0,   972,     0,   976,     0,   979,     0,
     982,     0,   985,     0,   992,     0,   995,     0,   998,   864,
     866,   870,     0,   876,     0,     0,     0,   357,   390,   390,
       0,  1008,  1010,  1002,  1006,  1007,     0,     0,   368,   232,
     236,   231,   234,   238,     0,   208,    99,    86,    91,    89,
      93,     0,     0,     0,     0,     0,     0,   375,   168,   158,
       0,     0,   161,   187,   177,     0,   180,   687,   482,   637,
     513,   530,   610,   593,   568,   665,   682,   470,   471,   484,
     472,   515,   473,   532,   474,   570,   475,   595,   476,   612,
     477,   639,   478,   667,   479,   683,   480,     0,   468,     0,
     453,   748,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   457,   458,   461,   462,   463,   464,   459,   460,   466,
     465,   746,   747,   723,   725,   841,   833,   835,   839,     0,
     881,   882,     0,   390,   831,     0,     0,     0,   931,     0,
     929,     0,   936,     0,   934,     0,   941,     0,   939,     0,
     946,     0,   944,   951,     0,   957,   960,     0,     0,     0,
     975,     0,   981,     0,     0,     0,     0,  1000,   773,     0,
     288,     0,   295,   298,   292,     0,     0,     0,     0,   369,
     258,   262,   257,   260,   264,     0,   237,   222,     0,   206,
       0,     0,     0,     0,     0,     0,   780,     0,     0,   210,
     215,   217,   213,   214,   216,   218,   212,   211,   221,   219,
     220,   778,   779,     0,    92,   109,   370,   371,   372,   373,
     374,     0,   164,   398,   159,   162,   163,   183,   398,   178,
     181,   182,     0,   483,     0,   514,     0,   531,     0,   569,
       0,   594,     0,   611,     0,   638,     0,   666,     0,   684,
       0,     0,   688,   467,   390,     0,     0,     0,     0,     0,
       0,     0,   390,   860,     0,     0,     0,   989,   991,     0,
       0,   932,     0,   937,     0,   942,     0,   947,   954,   971,
       0,   961,     0,   966,   978,   984,   987,   994,     0,   877,
     294,   300,     0,   317,   363,   364,  1005,  1009,  1013,  1011,
    1015,     0,   263,   248,     0,   235,     0,     0,     0,   239,
     245,   242,   243,   244,   241,   240,   247,   246,   223,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,    90,
      94,    96,    95,     0,     0,     0,   166,   396,   397,     0,
     185,     0,   756,     0,     0,   485,   486,   487,   754,   755,
       0,   516,   517,   518,     0,   533,   534,   535,     0,   571,
     572,   573,     0,   596,   597,   598,     0,   613,   614,   615,
       0,   640,   641,   642,     0,   668,   669,   670,     0,     0,
       0,   686,   749,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   883,   889,   888,   376,   933,   938,   943,   948,
     965,   970,     0,     0,   296,   319,   336,     0,  1014,   275,
       0,   261,     0,   265,   270,   272,   268,   269,   271,   273,
     267,   266,   274,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   781,     0,    98,   724,     0,     0,   167,
     165,   401,   399,   403,   186,   184,   492,   481,   489,     0,
       0,     0,   520,   512,   537,   529,   575,   567,   600,   592,
     617,   609,   644,   636,   672,   664,     0,     0,   692,     0,
       0,   389,   729,   739,   740,   730,   731,   732,   733,   745,
       0,   308,   312,     0,     0,   301,   302,   303,   299,   306,
       0,   338,   297,     0,  1017,  1018,  1016,   276,     0,     0,
       0,     0,   377,   384,   378,   385,   380,   381,   738,     0,
     412,     0,   408,   409,   410,     0,   402,   499,     0,     0,
       0,   495,   398,   491,   493,   494,   757,     0,     0,     0,
     539,     0,   577,     0,     0,     0,   619,     0,   646,     0,
       0,     0,   685,   681,   722,   700,   707,     0,     0,   693,
     997,   309,   312,   310,     0,     0,     0,   327,   331,     0,
       0,   320,   321,   322,   318,   325,     0,     0,     0,   382,
     386,   379,     0,     0,   411,     0,   400,     0,   404,   406,
     405,   488,   506,   490,     0,   502,   398,   498,   500,   501,
     497,     0,   726,   523,   521,     0,   519,   541,   538,     0,
     536,   579,   576,     0,   574,   603,   601,     0,   599,   621,
     618,     0,   616,   648,   645,     0,   643,   675,   673,     0,
     671,     0,     0,   701,   696,   398,   691,   694,   695,   307,
     311,     0,     0,     0,   328,   331,   329,     0,     0,     0,
     345,   349,     0,     0,   339,   340,   337,   343,   341,  1012,
     383,   728,   413,     0,     0,   509,   416,   505,   507,   508,
     504,     0,   496,   526,   398,   522,   524,   525,   544,   547,
     540,   542,   543,   582,   584,   578,   580,   581,   606,   398,
     602,   604,   605,   624,   626,   620,   622,   623,   651,   653,
     647,   649,   650,   678,   430,   674,   676,   677,   690,   710,
     689,   708,   712,   704,   398,   699,   702,   703,   698,     0,
       0,     0,   305,   304,   326,   330,     0,     0,     0,   346,
     349,   347,     0,     0,     0,   407,     0,     0,   511,   414,
     415,     0,   503,   528,     0,     0,   546,     0,   608,     0,
       0,     0,   680,   429,     0,     0,   711,   706,     0,   697,
       0,   315,     0,   313,     0,     0,   324,   323,   344,   348,
       0,     0,     0,   737,     0,   419,   417,   420,   510,   527,
     545,   550,   548,   552,   587,   583,   585,     0,   607,   629,
     625,   627,   630,   656,   652,   654,   657,   433,   431,   434,
     679,   720,   452,   709,   718,   719,     0,     0,   713,   714,
     715,   716,   717,   705,     0,   316,     0,   334,     0,   332,
       0,     0,   362,   342,   427,     0,   423,   424,   425,     0,
     421,     0,   551,   590,     0,   586,   588,   589,     0,     0,
       0,   435,     0,     0,     0,   314,     0,   335,     0,   352,
       0,   350,     0,   426,   390,   418,   558,   560,   549,   556,
     557,     0,     0,   553,   554,   555,     0,     0,   776,     0,
     631,   628,   634,   633,   632,   774,   775,   663,     0,     0,
       0,   658,   655,   661,   660,   659,     0,   432,   721,     0,
       0,   333,     0,   353,   428,     0,     0,     0,   390,   591,
       0,     0,   662,   390,   390,     0,   734,   735,   351,   422,
     559,   563,   561,   564,     0,     0,   635,   777,     0,     0,
     436,     0,     0,   565,   727,   742,   744,   743,   390,     0,
     562,     0,     0,   741,   566
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   699,   700,   863,   864,   980,   979,   697,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   711,   874,   875,   876,   985,  1090,   709,
     158,   159,   259,   260,   419,   418,   583,   584,   715,   879,
     880,   881,   989,  1095,   714,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     694,   695,   849,   839,   125,   126,   235,   341,   342,   343,
     691,   557,   692,   693,   835,   836,   959,   955,   232,   233,
     336,   553,   554,   555,   832,   687,   833,   834,   951,   952,
    1063,  1061,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   676,   824,   942,   943,  1053,  1135,  1136,
    1137,  1138,  1139,  1202,  1203,  1204,  1361,  1403,  1056,  1140,
    1211,  1212,  1213,  1214,  1215,  1285,  1286,  1287,  1405,  1459,
    1142,  1216,  1294,  1295,  1296,  1297,  1370,  1371,  1372,  1461,
    1491,   122,   123,   542,   331,   543,  1298,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     632,   850,   851,   960,   852,   853,   962,  1067,   854,   855,
     963,   224,  1032,   225,   326,   986,   987,  1092,  1093,  1165,
    1166,  1228,  1226,   988,  1162,  1163,  1164,  1378,  1379,  1416,
    1417,  1469,  1495,  1380,  1466,  1467,  1468,  1392,  1393,  1438,
    1439,  1480,  1527,    98,    99,   160,   161,   274,   263,   264,
     265,   424,   425,   426,   587,   588,   761,   750,   586,   727,
     728,   729,   882,   883,   995,  1097,  1168,  1098,  1099,  1173,
    1174,  1175,  1241,  1169,  1170,  1237,  1238,  1239,  1311,  1233,
    1234,  1307,  1308,  1309,  1381,   730,   731,   884,   885,  1001,
    1103,  1179,  1244,  1245,  1315,  1316,  1317,  1384,   732,   733,
     886,   887,  1005,  1105,  1181,  1248,  1249,  1320,  1321,  1322,
    1385,  1386,  1422,  1423,  1471,  1472,  1503,  1498,  1499,  1500,
    1536,  1552,  1553,  1562,  1570,   734,   735,   888,   889,  1009,
    1107,  1183,  1252,  1253,  1325,  1326,  1327,  1387,  1426,  1427,
    1475,  1476,  1477,   736,   737,   890,   891,  1013,  1109,  1185,
    1256,  1257,  1330,  1331,  1332,  1389,   738,   739,   892,   893,
    1017,  1111,  1187,  1260,  1261,  1335,  1336,  1337,  1390,  1431,
    1432,  1478,  1510,  1511,   740,   741,   894,   895,  1021,  1113,
    1189,  1264,  1265,  1340,  1341,  1342,  1391,  1435,  1436,  1479,
    1521,  1522,   742,   743,   896,   897,  1025,  1115,  1191,  1268,
    1269,  1345,  1346,  1347,  1394,   744,   745,   898,  1193,   746,
     747,   901,  1031,  1350,  1119,  1120,  1198,  1276,  1277,  1278,
    1359,  1196,  1197,  1272,  1355,  1356,  1357,  1398,  1271,  1351,
    1352,  1395,  1396,  1448,  1443,  1444,  1445,   902,   275,   712,
     276,   996,  1504,  1088,   762,   763,   764,   765,   766,  1449,
    1450,   105,  1229,   858,   767,   768,  1563,  1505,  1524,  1525,
     769,   770,   771,   772,   277,   278,   279,   997,   998,   999,
     106,   107,   108,   280,   281,   282,   283,   284,   285,   525,
     526,   527,  1514,  1515,  1516,   860,   861,   862,     7,     8,
      15,    25,    46,    47,    67,    68,   109,   189,   190,   305,
     453,   191,   306,   456,   192,   307,   193,   287,   194,   288,
     195,   295,   196,   289,   197,   286,   198,   290,   199,   291,
     200,   297,   201,   298,   202,   299,   203,   294,   204,   205,
     518,   206,   301,   207,   296,   208,   308,   209,   309,   210,
     310,   211,   212,   528,   313,   529,   530,   819,   213,   300,
     614,   914,   446,   615,   616,   617,   214,   292,   438,   215,
     303,   449,   216,   302,   448,   217,   304,   450,   218,   293,
     439,   477,   478,   479,   790,   480,   481,   794,   634,   482,
     483,   798,   636,   484,   485,   802,   638,   486,   487,   640,
     488,   489,   642,   490,   491,   644,   492,   493,   646,   494,
     495,   648,   931,   496,   497,   650,   933,   649,   498,   499,
     654,   500,   501,   656,   502,   503,   658,   504,   505,   660,
     506,   507,   662,   508,   628,   785,   509,   510,   664,   511,
     512,   666,   513,   514,   668,   333,   334,   548,   549,   683,
     684,   685,   828,   949,   950,  1057,  1058,  1146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -849
static const yytype_int16 yypact[] =
{
       5,  -849,    67,  -213,   101,  -849,  -849,   -83,  -178,   135,
    -849,  -849,    90,   -20,   158,  -849,   156,   103,  -849,   -78,
     165,   178,   107,  -849,   176,  -231,   186,  -849,  -849,  -849,
    -849,  -849,   120,   148,   190,   150,  -849,   198,  -849,  -849,
    -849,  -849,  -849,   199,  -849,  -849,  -849,  -849,   204,    38,
    -849,   124,   174,  -849,   -39,  -849,  -849,  -849,   213,  -849,
    -849,  -849,  -849,  -849,   214,   -32,   221,   225,   -64,  -849,
    -849,   193,   234,   241,   243,   245,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   224,  -849,   140,  -849,  -849,  -849,
    -849,    19,    95,   270,   313,  -849,  -849,  -849,  -849,  -849,
    -849,   686,  -849,   277,   274,  -849,  -849,  -849,  -849,  -849,
    -849,   278,   294,   296,  -849,  -849,  -849,  -849,  -849,  -849,
     229,   292,   235,   238,  -849,    59,   145,   325,   256,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
     280,   137,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,    24,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,   686,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   331,
     335,   339,   343,   348,   384,    36,  -849,   416,  -849,  -849,
    -849,  -849,    63,   201,   422,   288,  -849,   378,  -849,  -849,
    -849,  -849,  -849,   318,   -55,   321,   -55,   368,   -55,   372,
     128,   376,   143,   380,   227,   385,    23,   405,   -55,   409,
     -55,  -849,   247,  -849,  -849,  -849,  -849,   440,  -849,   460,
    -849,   470,   496,   500,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,   686,   686,   686,   686,
     686,   686,  -849,  -849,   686,   686,   686,   686,   686,   686,
    -849,   686,  -849,  -849,  -849,   387,   389,   686,   162,   162,
     162,  -849,   160,    34,  -849,   502,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   508,   401,  -849,
     436,   192,  -849,   272,   203,   514,   392,  -849,   520,  -849,
    -849,  -849,  -849,  -849,   522,   154,  -849,   479,  -849,  -849,
    -849,  -849,  -849,  -849,   481,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   483,  -849,
     526,  -849,  -849,  -849,  -849,  -849,  -849,   485,  -849,   528,
     532,   536,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
     487,  -849,   540,   542,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,   493,  -849,   553,  -849,  -849,  -849,  -849,
    -849,   486,  -849,  -849,  -849,  -849,  -849,   492,  -849,  -849,
    -849,  -849,  -849,  -849,   354,  -849,  -849,   556,   572,   573,
     576,   577,   686,   686,   686,   686,   254,   253,   414,   453,
     248,   249,   686,   244,   246,   239,    49,   236,   507,   544,
     583,  -849,   231,  -849,  -849,   230,  -849,   686,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   226,  -849,    12,
    -849,   394,  -849,   398,  -849,   402,  -849,   162,  -849,   162,
    -849,   686,  -849,   162,  -849,   194,  -849,   194,  -849,   397,
    -849,   162,  -849,   162,  -849,   162,  -849,   162,  -849,  -849,
     686,  -849,   686,  -849,   162,   228,   232,  -849,  -849,  -849,
     233,  -849,   600,   601,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -273,  -273,   599,  -849,  -849,   477,  -849,   525,
     602,   604,  -849,  -849,  -849,  -849,  -849,   605,   399,  -849,
     608,  -849,  -849,  -849,  -849,  -849,   609,   157,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,   563,   548,  -849,   613,
    -849,  -849,   614,   615,  -849,   616,   617,  -849,   618,  -849,
     565,   503,  -849,   567,   503,  -849,    92,   404,   -59,  -849,
    -849,  -849,   621,   622,   309,   310,   307,   308,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,   686,  -849,  -849,  -849,
    -849,   655,   627,   629,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   275,  -849,  -849,
     630,   632,   408,   634,   412,   635,   415,   636,   418,   269,
    -849,   162,  -849,   242,  -849,   250,  -849,   644,   637,  -849,
     638,  -849,  -849,   266,  -849,   162,  -849,   263,  -849,   162,
    -849,   162,  -849,   162,  -849,   686,  -849,   252,  -849,  -849,
    -849,  -849,   645,  -849,   643,   652,   425,  -849,  -849,  -849,
     651,  -849,  -849,  -849,  -849,  -849,   650,   179,  -849,  -849,
    -849,  -849,  -849,  -849,   429,    74,  -849,  -849,  -849,  -849,
    -849,   653,   654,   656,   657,   660,   661,  -849,  -849,  -849,
     662,   431,  -849,  -849,  -849,   435,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,   314,  -849,   494,  -849,   456,
    -849,  -849,   668,   664,   665,   666,   667,   669,   670,   671,
     672,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   334,
    -849,  -849,   675,  -849,  -849,   130,   676,   677,  -849,   258,
    -849,   678,  -849,   433,  -849,   680,  -849,   432,  -849,   681,
    -849,   430,  -849,  -849,   311,  -849,  -849,   683,   162,   162,
    -849,   306,  -849,   303,   302,   299,   686,  -849,  -849,   688,
    -849,   689,  -849,   427,  -849,   691,   692,   693,  -208,  -849,
    -849,  -849,  -849,  -849,  -849,   443,    89,  -849,   450,  -849,
     695,   696,   697,   698,   699,   700,  -849,   706,   702,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,   448,   -62,  -849,  -849,  -849,  -849,  -849,
    -849,   705,  -849,   592,  -849,  -849,  -849,  -849,   592,  -849,
    -849,  -849,   704,   -27,   707,   -27,   708,   -27,   709,   -27,
     710,   -27,   712,   -27,   713,   -27,   714,   -27,   715,  -849,
     719,   717,  -849,  -849,  -849,   711,   723,   724,   726,   728,
     730,   732,  -849,  -849,   366,   734,   736,  -849,  -849,   742,
     744,  -849,   746,  -849,   748,  -849,   750,  -849,  -849,  -849,
     360,  -849,   382,  -849,  -849,  -849,  -849,  -849,   686,  -849,
    -849,  -849,   679,   499,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,   451,   126,  -849,   510,  -849,   760,   762,   764,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   785,
     787,   789,   791,   793,   795,   797,   801,  -849,   738,  -849,
    -849,  -849,  -849,   803,   603,   740,  -849,   703,  -849,   752,
    -849,   580,  -849,   816,   813,  -849,  -849,  -849,  -849,  -849,
     580,  -849,  -849,  -849,   580,  -849,  -849,  -849,   580,  -849,
    -849,  -849,   580,  -849,  -849,  -849,   580,  -849,  -849,  -849,
     580,  -849,  -849,  -849,   580,  -849,  -849,  -849,   162,   817,
     612,  -849,  -849,    20,   821,   823,   825,   827,   831,   833,
     835,   837,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,   162,    40,  -849,  -849,   582,   836,   -64,  -849,
     591,  -849,   845,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   849,   851,   853,   874,   876,   878,
     880,   882,   884,  -849,   886,  -849,  -849,   888,   454,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   659,   457,
     892,   855,   659,  -849,   659,  -849,   659,  -849,   659,  -849,
     659,  -849,   659,  -849,   659,  -849,   673,   913,  -849,   716,
     503,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
     529,  -849,   663,   915,   921,  -849,  -849,  -849,  -849,  -849,
      43,  -849,  -849,   162,  -849,  -849,  -849,  -849,   927,   929,
     931,   933,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   939,
    -849,    42,  -849,  -849,  -849,   936,   271,  -849,   729,   718,
     461,  -849,   592,  -849,  -849,  -849,  -849,   943,   720,   731,
     721,   727,   722,   725,   754,   735,   756,   739,   799,   749,
     805,   737,  -849,  -849,  -849,  -849,  -849,   503,   465,  -849,
    -849,  -849,   694,  -849,   701,   952,   954,  -849,   766,   956,
     960,  -849,  -849,  -849,  -849,  -849,    58,   674,   964,  -849,
    -849,  -849,   969,   858,  -849,   975,  -849,   977,  -849,  -849,
    -849,  -849,  -849,  -849,   467,  -849,   592,  -849,  -849,  -849,
    -849,   745,  -849,  -849,  -849,   472,  -849,  -849,  -849,   474,
    -849,  -849,  -849,   476,  -849,  -849,  -849,   478,  -849,  -849,
    -849,   480,  -849,  -849,  -849,   482,  -849,  -849,  -849,   484,
    -849,   286,   488,  -849,  -849,   592,  -849,  -849,  -849,  -849,
    -849,   790,   981,   985,  -849,   768,  -849,   773,   995,   997,
    -849,   770,  1028,  1034,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,   935,  1038,  -849,   930,  -849,  -849,  -849,
    -849,   812,  -849,  -849,   592,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   592,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   592,  -849,  -849,  -849,  -849,   840,
    1048,   490,  -849,  -849,  -849,  -849,   861,  1052,  1053,  -849,
     794,  -849,   798,  1058,  1059,  -849,  1060,   603,  -849,   955,
    -849,   824,  -849,  -849,   828,   829,   957,   -54,  -849,   830,
     -50,   -49,  -849,   961,   832,   558,   -46,  -849,   859,  -849,
    1070,  -849,   807,  -849,  1071,   560,  -849,  -849,  -849,  -849,
     881,  1072,  1073,  -849,   562,  -849,  -849,   883,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   564,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   883,
    -849,  -849,   247,  -849,  -849,  -849,  1075,  1077,  -849,  -849,
    -849,  -849,  -849,  -849,  1078,  -849,  1081,  -849,   826,  -849,
    1082,   566,  -849,  -849,  -849,    53,  -849,  -849,  -849,  1080,
    -849,   568,   -71,  -849,   686,  -849,  -849,  -849,    27,    55,
    1083,  -849,   877,  1086,  1087,  -849,  1088,  -849,  1089,  -849,
     834,  -849,   976,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  1090,  1091,  -849,  -849,  -849,   988,  1096,  -849,  1100,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   991,  1097,
    1098,  -849,  -849,  -849,  -849,  -849,  1103,  -849,  -849,  1101,
    1102,  -849,  1104,  -849,  -849,   998,   -43,  1107,  -849,  -849,
    1001,  1108,  -849,  -849,  -849,  1002,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,   907,  1109,  1110,  -849,  -849,  1111,  1112,
    -849,  1113,  1114,  -849,  -849,  -849,  -849,  -849,  -849,  1116,
    -849,  1115,   885,  -849,  -849
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,   796,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   -76,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -158,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -242,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   879,   887,  -849,  -849,  -849,  -849,
    -849,   180,   182,  -849,  -761,  -849,  -849,  -849,   183,   184,
    -849,  -569,  -849,  -280,  -849,  -848,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -311,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -686,  -849,  -849,
    -849,  -849,  -849,  -825,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -239,  -558,
    -238,  -545,  -849,  -247,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,    79,  -340,  -812,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -221,  -849,  -849,  -523,  -849,  -849,
    -713,  -849,  -849,  -257,  -849,  -849,  -312,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -205,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -306,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   646,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     312,   524,   702,   515,   516,   350,   351,   357,   358,   364,
     365,   373,   374,   386,   387,   399,   400,   408,   409,   414,
     415,   420,   421,   352,   966,   359,   716,   366,  1121,   375,
     990,   388,   899,   401,   630,   410,   405,   416,  1507,   422,
     532,   533,   320,   321,   519,   520,  1223,     1,    70,    71,
    1131,  1132,   981,  1207,  1208,    72,    73,  1492,  1424,   610,
     611,  1133,  1429,  1433,  1209,  1517,  1518,     5,  1290,  1291,
    1550,   268,   269,   102,   103,   961,   266,   267,    44,  1292,
      45,   432,   433,   434,   435,   436,   437,   268,   269,   440,
     441,   442,   443,   444,   445,     6,   447,   840,   841,   842,
     843,   844,   457,   845,   751,   752,   947,  1501,   948,   825,
     826,   272,   273,   270,   271,     9,   844,    38,    39,   956,
      11,   957,   958,   753,   754,   755,   756,   757,   758,   759,
     760,  1502,    14,   104,   992,   993,    18,   848,   322,   323,
     324,   325,   994,    16,  1446,  1447,    27,    28,    21,   840,
     841,   842,   843,   844,   266,   267,   370,  1062,    53,    54,
      59,    60,    26,  1224,    82,    83,    24,   268,   269,    31,
    1508,  1509,    96,    97,  1493,   521,   522,   379,   380,   381,
      34,   639,    43,   641,    85,    86,    37,   645,  1425,   272,
     273,  1066,  1430,  1434,    48,   655,    50,   657,    58,   659,
    1551,   661,   538,   539,    64,   266,   267,    66,   667,   631,
      90,   540,   541,  1210,   916,    69,  1134,   118,   119,    93,
     266,   267,    95,   846,   847,  1227,   848,   594,   595,   596,
     597,  1293,   100,   601,   603,    74,   101,   606,   110,    75,
     272,   273,   111,   620,   622,   624,   612,  1519,  1520,   112,
     613,   113,   627,   114,   848,   272,   273,   266,   267,   266,
     267,   379,   380,   115,   392,   393,   238,   239,   266,   267,
     268,   269,   124,   848,   266,   267,   127,  1178,   130,  1180,
     219,  1182,   220,  1184,   221,  1186,   643,  1188,   848,  1190,
     261,   262,   272,   273,   272,   273,   270,   271,   339,   340,
     222,   717,   223,   272,   273,   663,   226,   665,   227,   272,
     273,   718,   229,   719,  1102,   720,   231,   721,  1104,   722,
     230,   723,  1106,   724,  1240,   234,  1108,   725,   346,   347,
    1110,   353,   354,   237,  1112,   804,   311,   726,  1114,   314,
    1002,   315,  1006,  1041,  1010,  1145,  1014,   316,  1018,   811,
    1022,   317,  1026,   813,  1230,   814,   318,   815,   266,   267,
     131,   132,  1003,   133,  1007,   134,  1011,   135,  1015,   136,
    1019,   137,  1023,   138,  1027,   139,   332,   140,   360,   361,
     335,   458,   367,   368,   344,   459,   376,   377,  1310,   460,
     389,   390,   319,   272,   273,   402,   403,   451,   452,   454,
     455,   779,   551,   552,   559,   560,   781,   652,   653,   681,
     682,   689,   690,   458,   748,   749,   411,   459,   788,   789,
     417,   460,   792,   793,   327,   796,   797,  1358,   800,   801,
     338,   322,   323,   324,   325,   822,   823,   830,   831,   837,
     838,   872,   873,   427,   523,   877,   878,   322,   323,   324,
     325,   102,   103,   953,   954,   423,   856,   857,   977,   978,
     816,  1059,  1060,   428,  1160,  1161,  1383,  1171,  1172,  1227,
     848,  1235,  1236,   429,   859,  1274,  1275,  1305,  1306,   918,
     535,  1388,  1313,  1314,  1318,  1319,  1323,  1324,  1328,  1329,
    1333,  1334,  1338,  1339,  1343,  1344,  1348,  1349,  1353,  1354,
    1401,  1402,   930,   932,   430,   461,  1397,   462,   431,   463,
     531,   464,   517,   465,   534,   466,   537,   467,   547,   468,
     546,   469,   550,   470,   917,   471,   556,   472,   564,   473,
     558,   474,   565,   475,   569,   476,   571,   461,   568,   462,
     572,   463,   570,   464,   573,   465,   574,   466,   575,   467,
     576,   468,   982,   469,   577,   470,   578,   471,   579,   472,
     585,   473,  1199,   474,   589,   475,   582,   476,  1441,  1442,
    1457,  1458,  1464,  1465,  1473,  1474,  1489,  1490,  1496,  1497,
     590,   591,   592,   593,   598,   599,   604,   609,   607,   605,
     618,   633,   608,   625,   626,   635,   629,   964,   965,   637,
     669,   671,   647,   672,   673,  1470,   670,   674,   677,   675,
     678,   938,   679,   680,   686,   967,   696,   688,   698,   701,
     703,   704,   705,   706,  1033,   710,   707,  1481,   708,   773,
     774,   775,   713,   777,   776,   782,   778,   783,   786,  1273,
     787,   784,   791,   795,   799,   803,   805,   807,   808,   809,
     810,   812,   817,   818,   820,   821,   806,   827,   829,   900,
     921,   865,   866,   903,   867,   868,  1513,  1523,   869,   870,
     871,   904,   905,   906,   907,   908,   913,   909,   910,   911,
     912,   915,   919,   920,   922,   923,   924,   926,   925,   928,
     927,   929,   934,   935,   936,   937,   939,   940,   941,   944,
     945,   946,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   983,   984,  1070,  1071,   991,  1042,  1034,  1000,  1004,
    1008,  1012,  1116,  1016,  1020,  1024,  1028,  1029,  1030,  1035,
    1036,  1072,  1037,  1052,  1038,   162,  1039,   163,  1040,   164,
    1050,   165,  1043,   166,  1044,   167,  1130,   168,   600,   169,
    1045,   170,  1046,   171,  1047,   172,  1048,   173,  1049,   174,
    1054,   175,  1055,   176,  1051,   177,  1073,   178,  1074,   179,
    1075,   180,  1076,   181,   162,   182,   163,   183,   164,   184,
     165,   185,   166,   186,   167,   187,   168,   188,   169,   602,
     170,  1077,   171,  1078,   172,  1079,   173,  1080,   174,  1081,
     175,  1082,   176,  1087,   177,  1083,   178,  1084,   179,  1085,
     180,  1086,   181,  1089,   182,  1091,   183,  1096,   184,  1100,
     185,  1101,   186,  1117,   187,  1118,   188,  1094,   162,  1122,
     163,  1123,   164,  1124,   165,  1125,   166,  1217,   167,  1126,
     168,  1127,   169,  1128,   170,  1129,   171,  1143,   172,  1141,
     173,  1147,   174,  1148,   175,  1149,   176,  1150,   177,  1151,
     178,  1177,   179,   619,   180,   162,   181,   163,   182,   164,
     183,   165,   184,   166,   185,   167,   186,   168,   187,   169,
     188,   170,  1152,   171,  1153,   172,  1154,   173,  1155,   174,
    1156,   175,  1157,   176,  1158,   177,  1159,   178,  1167,   179,
    1176,   180,   621,   181,   162,   182,   163,   183,   164,   184,
     165,   185,   166,   186,   167,   187,   168,   188,   169,  1192,
     170,  1194,   171,  1205,   172,  1535,   173,  1200,   174,  1206,
     175,  1195,   176,  1218,   177,  1201,   178,  1219,   179,  1220,
     180,  1221,   181,   623,   182,  1222,   183,  1225,   184,  1231,
     185,  1242,   186,  1250,   187,  1246,   188,  1254,  1282,  1232,
    1283,  1243,  1247,  1251,  1288,  1258,  1279,  1262,  1289,  1555,
    1281,  1266,  1300,  1270,  1558,  1559,   162,  1301,   163,  1302,
     164,  1303,   165,  1312,   166,  1304,   167,  1360,   168,  1362,
     169,  1299,   170,  1363,   171,  1255,   172,  1259,   173,  1571,
     174,  1367,   175,  1368,   176,   780,   177,   162,   178,   163,
     179,   164,   180,   165,   181,   166,   182,   167,   183,   168,
     184,   169,   185,   170,   186,   171,   187,   172,   188,   173,
    1284,   174,  1364,   175,  1366,   176,  1373,   177,  1369,   178,
    1263,   179,  1374,   180,  1376,   181,  1267,   182,  1375,   183,
    1377,   184,  1382,   185,  1399,   186,  1400,   187,  1404,   188,
    1406,  1407,  1408,  1410,  1411,  1412,  1418,  1415,  1413,  1421,
    1419,  1420,  1428,  1437,  1440,  1453,  1454,  1455,  1460,  1456,
    1462,  1463,   848,  1483,  1452,  1484,  1485,  1486,  1487,  1528,
    1488,  1494,  1529,  1530,  1526,  1532,  1531,  1534,  1537,  1538,
    1533,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1561,  1546,
    1547,  1549,  1548,  1554,  1556,  1560,  1557,  1564,  1565,  1566,
    1567,  1568,  1572,  1573,   536,  1569,  1280,  1365,  1409,  1574,
    1414,  1482,  1064,   395,  1065,  1068,  1069,  1144,  1512,  1451,
       0,   396,     0,   651,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1506
};

static const yytype_int16 yycheck[] =
{
     205,   313,   571,   309,   310,   244,   244,   246,   246,   248,
     248,   250,   250,   252,   252,   254,   254,   256,   256,   258,
     258,   260,   260,   244,   836,   246,   584,   248,     8,   250,
     878,   252,   745,   254,    22,   256,    13,   258,    11,   260,
     320,   321,     6,     7,    10,    11,     4,    42,    10,    11,
      10,    11,   864,    10,    11,    17,    18,     4,   112,    10,
      11,    21,   112,   112,    21,    10,    11,     0,    10,    11,
     113,   133,   134,   137,   138,   836,   131,   132,   309,    21,
     311,   286,   287,   288,   289,   290,   291,   133,   134,   294,
     295,   296,   297,   298,   299,   308,   301,    23,    24,    25,
      26,    27,   307,    29,   163,   164,   314,   178,   316,   678,
     679,   166,   167,   159,   160,    14,    27,    10,    11,    30,
     203,    32,    33,   182,   183,   184,   185,   186,   187,   188,
     189,   202,   310,   197,   161,   162,    46,   199,   411,   412,
     413,   414,   169,     8,   190,   191,    43,    44,   168,    23,
      24,    25,    26,    27,   131,   132,    28,    31,    10,    11,
      10,    11,     6,   121,    40,    41,     8,   133,   134,   247,
     143,   144,   204,   205,   121,   141,   142,    34,    35,    36,
      15,   487,     6,   489,    10,    11,     8,   493,   242,   166,
     167,   952,   242,   242,     8,   501,    76,   503,     8,   505,
     243,   507,    10,    11,     6,   131,   132,     8,   514,   197,
     249,    19,    20,   170,   783,    11,   176,    77,    78,     6,
     131,   132,     8,   149,   150,   198,   199,   432,   433,   434,
     435,   173,    11,   438,   439,   197,    11,   442,    45,   201,
     166,   167,     8,   448,   449,   450,   197,   192,   193,     8,
     201,     8,   457,     8,   199,   166,   167,   131,   132,   131,
     132,    34,    35,    39,    37,    38,    10,    11,   131,   132,
     133,   134,   253,   199,   131,   132,   181,  1102,     8,  1104,
       3,  1106,     8,  1108,     6,  1110,   491,  1112,   199,  1114,
      10,    11,   166,   167,   166,   167,   159,   160,    10,    11,
       6,   209,     6,   166,   167,   510,    77,   512,    16,   166,
     167,   219,    77,   221,  1000,   223,   257,   225,  1004,   227,
      82,   229,  1008,   231,  1172,   180,  1012,   235,    10,    11,
    1016,    10,    11,     8,  1020,   641,   312,   245,  1024,     8,
     885,     6,   887,   912,   889,  1058,   891,     8,   893,   655,
     895,     8,   897,   659,  1166,   661,     8,   663,   131,   132,
      47,    48,   885,    50,   887,    52,   889,    54,   891,    56,
     893,    58,   895,    60,   897,    62,   313,    64,    10,    11,
     179,   251,    10,    11,     6,   255,    10,    11,  1236,   259,
      10,    11,     8,   166,   167,    10,    11,    10,    11,    10,
      11,   606,    10,    11,   250,   251,   611,    10,    11,    10,
      11,   254,   255,   251,    10,    11,    11,   255,    10,    11,
      11,   259,    10,    11,     8,    10,    11,  1275,    10,    11,
       8,   411,   412,   413,   414,    10,    11,   258,   259,    10,
      11,    10,    11,     3,   410,    10,    11,   411,   412,   413,
     414,   137,   138,    10,    11,   208,   695,   695,    10,    11,
     665,    10,    11,     3,    10,    11,  1314,    10,    11,   198,
     199,    10,    11,     3,   695,    10,    11,    10,    11,   785,
      79,  1329,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   210,   211,    10,    11,
      10,    11,   808,   809,     8,   375,  1354,   377,     8,   379,
       8,   381,   352,   383,     6,   385,    80,   387,   315,   389,
     248,   391,     8,   393,   394,   395,     6,   397,    49,   399,
       8,   401,    51,   403,     8,   405,     8,   375,    55,   377,
       8,   379,    57,   381,     8,   383,    59,   385,     8,   387,
       8,   389,   864,   391,    61,   393,     3,   395,    72,   397,
     206,   399,  1120,   401,     8,   403,    74,   405,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       8,     8,     6,     6,   330,   332,   338,   348,   344,   340,
     354,   197,   346,   362,   364,   197,   370,   836,   836,   197,
     372,   368,   408,     3,     3,  1417,   374,     8,    83,   132,
       8,   816,     8,     8,     6,   836,    53,     8,    70,     6,
       6,     6,     6,     6,   904,   122,     8,  1439,    63,     8,
       8,   322,    65,   326,   324,     8,   328,     8,     8,  1197,
       8,   366,     8,     8,     8,   376,   404,     3,    11,    11,
     384,   388,   400,     8,    11,     3,   406,     6,     8,   165,
     402,     8,     8,   207,     8,     8,  1478,  1479,     8,     8,
       8,     3,     8,     8,     8,     8,   342,     8,     8,     8,
       8,     6,     6,     6,     6,   252,     6,     6,   256,   378,
     260,     8,   386,   390,   392,   396,     8,     8,   271,     8,
       8,     8,   252,     8,     8,     8,     8,     8,     8,     3,
       8,     6,   120,   952,   952,    11,   350,     6,    11,    11,
      11,    11,  1028,    11,    11,    11,    11,     8,    11,     6,
       6,   952,     6,   938,     6,   321,     6,   323,     6,   325,
     380,   327,     8,   329,     8,   331,  1052,   333,   334,   335,
       8,   337,     8,   339,     8,   341,     8,   343,     8,   345,
      81,   347,   263,   349,   382,   351,   256,   353,     8,   355,
       8,   357,     8,   359,   321,   361,   323,   363,   325,   365,
     327,   367,   329,   369,   331,   371,   333,   373,   335,   336,
     337,     6,   339,     6,   341,     6,   343,     6,   345,     6,
     347,     6,   349,   200,   351,     8,   353,     6,   355,    71,
     357,     8,   359,    73,   361,   112,   363,   237,   365,     3,
     367,     8,   369,     6,   371,   213,   373,    75,   321,     8,
     323,     8,   325,     8,   327,     8,   329,  1143,   331,     8,
     333,     8,   335,     8,   337,     8,   339,    11,   341,   267,
     343,   260,   345,     8,   347,     6,   349,     6,   351,     6,
     353,     6,   355,   356,   357,   321,   359,   323,   361,   325,
     363,   327,   365,   329,   367,   331,   369,   333,   371,   335,
     373,   337,     8,   339,     8,   341,     8,   343,     8,   345,
       8,   347,     8,   349,     8,   351,     8,   353,   239,   355,
       8,   357,   358,   359,   321,   361,   323,   363,   325,   365,
     327,   367,   329,   369,   331,   371,   333,   373,   335,   246,
     337,     8,   339,     8,   341,  1494,   343,   398,   345,     8,
     347,   215,   349,     6,   351,   272,   353,     8,   355,     8,
     357,     8,   359,   360,   361,     6,   363,    11,   365,   220,
     367,     8,   369,   226,   371,   224,   373,   232,     6,   241,
       6,   241,   241,   241,     8,   230,   272,   228,     8,  1538,
     269,   222,     8,   236,  1543,  1544,   321,     8,   323,   121,
     325,     6,   327,   238,   329,     8,   331,   197,   333,     8,
     335,   317,   337,     8,   339,   241,   341,   241,   343,  1568,
     345,     6,   347,     6,   349,   350,   351,   321,   353,   323,
     355,   325,   357,   327,   359,   329,   361,   331,   363,   333,
     365,   335,   367,   337,   369,   339,   371,   341,   373,   343,
     264,   345,   264,   347,   261,   349,     8,   351,   268,   353,
     241,   355,     8,   357,     6,   359,   241,   361,   113,   363,
     120,   365,   240,   367,   214,   369,     8,   371,   197,   373,
       8,     8,   268,   265,     6,     6,   242,   112,     8,   112,
     242,   242,   242,   112,   242,   216,     6,   270,   197,     8,
       8,     8,   199,     8,  1396,     8,     8,     6,   262,   212,
       8,    11,     6,     6,    11,     6,     8,   121,     8,     8,
     266,   113,     6,     3,   113,     8,     8,     4,   201,     8,
       8,   113,     8,     6,   113,   113,     8,     8,     8,     8,
       8,     8,     6,     8,   328,    11,  1202,  1285,  1370,   244,
    1377,  1442,   952,   254,   952,   952,   952,  1058,  1478,  1396,
      -1,   254,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1474
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    42,   416,   420,   421,     0,   308,   933,   934,    14,
     422,   203,   433,   434,   310,   935,     8,   423,    46,   440,
     441,   168,   435,   634,     8,   936,     6,    43,    44,   424,
     425,   247,   530,   531,    15,   442,   635,     8,    10,    11,
     436,   437,   438,     6,   309,   311,   937,   938,     8,   427,
      76,   577,   578,    10,    11,   532,   533,   534,     8,    10,
      11,   443,   444,   445,     6,   439,     8,   939,   940,    11,
      10,    11,    17,    18,   197,   201,   426,   428,   429,   430,
     431,   432,    40,    41,   417,    10,    11,   579,   580,   581,
     249,   535,   536,     6,   446,     8,   204,   205,   688,   689,
      11,    11,   137,   138,   197,   896,   915,   916,   917,   941,
      45,     8,     8,     8,     8,    39,   418,   419,    77,    78,
     582,   583,   626,   627,   253,   549,   550,   181,   537,   636,
       8,    47,    48,    50,    52,    54,    56,    58,    60,    62,
      64,   447,   448,   449,   454,   455,   460,   461,   475,   476,
     482,   483,   488,   489,   494,   495,   500,   501,   515,   516,
     690,   691,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   942,
     943,   946,   949,   951,   953,   955,   957,   959,   961,   963,
     965,   967,   969,   971,   973,   974,   976,   978,   980,   982,
     984,   986,   987,   993,  1001,  1004,  1007,  1010,  1013,     3,
       8,     6,     6,     6,   656,   658,    77,    16,   584,    77,
      82,   257,   563,   564,   180,   551,   637,     8,    10,    11,
     538,   539,   540,   450,   451,   456,   457,   462,   463,   477,
     478,   484,   485,   490,   491,   496,   497,   502,   503,   517,
     518,    10,    11,   693,   694,   695,   131,   132,   133,   134,
     159,   160,   166,   167,   692,   883,   885,   909,   910,   911,
     918,   919,   920,   921,   922,   923,   960,   952,   954,   958,
     962,   964,  1002,  1014,   972,   956,   979,   966,   968,   970,
     994,   977,  1008,  1005,  1011,   944,   947,   950,   981,   983,
     985,   312,   942,   989,     8,     6,     8,     8,     8,     8,
       6,     7,   411,   412,   413,   414,   659,     8,   585,   586,
     587,   629,   313,  1080,  1081,   179,   565,   638,     8,    10,
      11,   552,   553,   554,     6,   542,    10,    11,   453,   452,
     883,   885,   909,    10,    11,   459,   458,   883,   885,   909,
      10,    11,   465,   464,   883,   885,   909,    10,    11,   481,
      28,   479,   480,   883,   885,   909,    10,    11,   487,    34,
      35,    36,   486,   639,   640,   641,   883,   885,   909,    10,
      11,   493,    37,    38,   492,   639,   640,   642,   643,   883,
     885,   909,    10,    11,   499,    13,   498,   644,   883,   885,
     909,    11,   505,   504,   883,   885,   909,    11,   520,   519,
     883,   885,   909,   208,   696,   697,   698,     3,     3,     3,
       8,     8,   942,   942,   942,   942,   942,   942,  1003,  1015,
     942,   942,   942,   942,   942,   942,   997,   942,  1009,  1006,
    1012,    10,    11,   945,    10,    11,   948,   942,   251,   255,
     259,   375,   377,   379,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,  1016,  1017,  1018,
    1020,  1021,  1024,  1025,  1028,  1029,  1032,  1033,  1035,  1036,
    1038,  1039,  1041,  1042,  1044,  1045,  1048,  1049,  1053,  1054,
    1056,  1057,  1059,  1060,  1062,  1063,  1065,  1066,  1068,  1071,
    1072,  1074,  1075,  1077,  1078,  1016,  1016,   352,   975,    10,
      11,   141,   142,   410,   921,   924,   925,   926,   988,   990,
     991,     8,   658,   658,     6,    79,   586,    80,    10,    11,
      19,    20,   628,   630,   632,   633,   248,   315,  1082,  1083,
       8,    10,    11,   566,   567,   568,     6,   556,     8,   250,
     251,   541,   543,   544,    49,    51,   466,   467,    55,     8,
      57,     8,     8,     8,    59,     8,     8,    61,     3,    72,
     506,   507,    74,   521,   522,   206,   703,   699,   700,     8,
       8,     8,     6,     6,   942,   942,   942,   942,   330,   332,
     334,   942,   336,   942,   338,   340,   942,   344,   346,   348,
      10,    11,   197,   201,   995,   998,   999,  1000,   354,   356,
     942,   358,   942,   360,   942,   362,   364,   942,  1069,   370,
      22,   197,   645,   197,  1023,   197,  1027,   197,  1031,  1016,
    1034,  1016,  1037,   942,  1040,  1016,  1043,   408,  1046,  1052,
    1050,  1052,    10,    11,  1055,  1016,  1058,  1016,  1061,  1016,
    1064,  1016,  1067,   942,  1073,   942,  1076,  1016,  1079,   372,
     374,   368,     3,     3,     8,   132,   588,    83,     8,     8,
       8,    10,    11,  1084,  1085,  1086,     6,   570,     8,   254,
     255,   555,   557,   558,   545,   546,    53,   474,    70,   468,
     469,     6,   656,     6,     6,     6,     6,     8,    63,   514,
     122,   508,   884,    65,   529,   523,   884,   209,   219,   221,
     223,   225,   227,   229,   231,   235,   245,   704,   705,   706,
     730,   731,   743,   744,   770,   771,   788,   789,   801,   802,
     819,   820,   837,   838,   850,   851,   854,   855,    10,    11,
     702,   163,   164,   182,   183,   184,   185,   186,   187,   188,
     189,   701,   889,   890,   891,   892,   893,   899,   900,   905,
     906,   907,   908,     8,     8,   322,   324,   326,   328,   942,
     350,   942,     8,     8,   366,  1070,     8,     8,    10,    11,
    1019,     8,    10,    11,  1022,     8,    10,    11,  1026,     8,
      10,    11,  1030,   376,  1016,   404,   406,     3,    11,    11,
     384,  1016,   388,  1016,  1016,  1016,   942,   400,     8,   992,
      11,     3,    10,    11,   589,   656,   656,     6,  1087,     8,
     258,   259,   569,   571,   572,   559,   560,    10,    11,   548,
      23,    24,    25,    26,    27,    29,   149,   150,   199,   547,
     646,   647,   649,   650,   653,   654,   883,   885,   898,   909,
     930,   931,   932,   470,   471,     8,     8,     8,     8,     8,
       8,     8,    10,    11,   509,   510,   511,    10,    11,   524,
     525,   526,   707,   708,   732,   733,   745,   746,   772,   773,
     790,   791,   803,   804,   821,   822,   839,   840,   852,   915,
     165,   856,   882,   207,     3,     8,     8,     8,     8,     8,
       8,     8,     8,   342,   996,     6,   656,   394,  1016,     6,
       6,   402,     6,   252,     6,   256,     6,   260,   378,     8,
    1016,  1047,  1016,  1051,   386,   390,   392,   396,   942,     8,
       8,   271,   590,   591,     8,     8,     8,   314,   316,  1088,
    1089,   573,   574,    10,    11,   562,    30,    32,    33,   561,
     648,   649,   651,   655,   883,   885,   898,   909,   252,     8,
       8,     8,     8,     8,     8,     3,     8,    10,    11,   473,
     472,   898,   921,     6,   120,   512,   660,   661,   668,   527,
     660,    11,   161,   162,   169,   709,   886,   912,   913,   914,
      11,   734,   886,   912,    11,   747,   886,   912,    11,   774,
     886,   912,    11,   792,   886,   912,    11,   805,   886,   912,
      11,   823,   886,   912,    11,   841,   886,   912,    11,     8,
      11,   857,   657,   658,     6,     6,     6,     6,     6,     6,
       6,   656,   350,     8,     8,     8,     8,     8,     8,     8,
     380,   382,   942,   592,    81,   263,   603,  1090,  1091,    10,
      11,   576,    31,   575,   646,   647,   649,   652,   653,   654,
     883,   885,   909,   256,     8,     8,     8,     6,     6,     6,
       6,     6,     6,     8,     6,    71,     8,   200,   888,    73,
     513,   112,   662,   663,    75,   528,   237,   710,   712,   713,
       3,     8,   712,   735,   712,   748,   712,   775,   712,   793,
     712,   806,   712,   824,   712,   842,  1016,     6,   213,   859,
     860,     8,     8,     8,     8,     8,     8,     8,     8,     8,
    1016,    10,    11,    21,   176,   593,   594,   595,   596,   597,
     604,   267,   615,    11,   896,   915,  1092,   260,     8,     6,
       6,     6,     8,     8,     8,     8,     8,     8,     8,     8,
      10,    11,   669,   670,   671,   664,   665,   239,   711,   718,
     719,    10,    11,   714,   715,   716,     8,     6,   718,   736,
     718,   749,   718,   776,   718,   794,   718,   807,   718,   825,
     718,   843,   246,   853,     8,   215,   866,   867,   861,   884,
     398,   272,   598,   599,   600,     8,     8,    10,    11,    21,
     170,   605,   606,   607,   608,   609,   616,  1016,     6,     8,
       8,     8,     6,     4,   121,    11,   667,   198,   666,   897,
     898,   220,   241,   724,   725,    10,    11,   720,   721,   722,
     660,   717,     8,   241,   737,   738,   224,   241,   750,   751,
     226,   241,   777,   778,   232,   241,   795,   796,   230,   241,
     808,   809,   228,   241,   826,   827,   222,   241,   844,   845,
     236,   873,   868,   884,    10,    11,   862,   863,   864,   272,
     599,   269,     6,     6,   264,   610,   611,   612,     8,     8,
      10,    11,    21,   173,   617,   618,   619,   620,   631,   317,
       8,     8,   121,     6,     8,    10,    11,   726,   727,   728,
     660,   723,   238,    10,    11,   739,   740,   741,    10,    11,
     752,   753,   754,    10,    11,   779,   780,   781,    10,    11,
     797,   798,   799,    10,    11,   810,   811,   812,    10,    11,
     828,   829,   830,    10,    11,   846,   847,   848,   210,   211,
     858,   874,   875,    10,    11,   869,   870,   871,   660,   865,
     197,   601,     8,     8,   264,   611,   261,     6,     6,   268,
     621,   622,   623,     8,     8,   113,     6,   120,   672,   673,
     678,   729,   240,   660,   742,   755,   756,   782,   660,   800,
     813,   831,   682,   683,   849,   876,   877,   660,   872,   214,
       8,    10,    11,   602,   197,   613,     8,     8,   268,   622,
     265,     6,     6,     8,   888,   112,   674,   675,   242,   242,
     242,   112,   757,   758,   112,   242,   783,   784,   242,   112,
     242,   814,   815,   112,   242,   832,   833,   112,   684,   685,
     242,    10,    11,   879,   880,   881,   190,   191,   878,   894,
     895,   918,   921,   216,     6,   270,     8,    10,    11,   614,
     197,   624,     8,     8,    10,    11,   679,   680,   681,   676,
     898,   759,   760,    10,    11,   785,   786,   787,   816,   834,
     686,   898,   696,     8,     8,     8,     6,   262,     8,    10,
      11,   625,     4,   121,    11,   677,    10,    11,   762,   763,
     764,   178,   202,   761,   887,   902,   942,    11,   143,   144,
     817,   818,   897,   898,   927,   928,   929,    10,    11,   192,
     193,   835,   836,   898,   903,   904,    11,   687,   212,     6,
       6,     8,     6,   266,   121,   656,   765,     8,     8,   113,
       6,     3,   113,     8,     8,     4,     8,     8,     8,   113,
     113,   243,   766,   767,     6,   656,   113,     8,   656,   656,
     113,   201,   768,   901,     8,     8,     8,     8,     8,    11,
     769,   656,     6,     8,   244
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

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);std::cout << "matched integer" << (yyvsp[(2) - (3)].ival) << std::endl;}
    break;

  case 388:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);std::cout << "matched double" << (yyvsp[(2) - (3)].dval) << std::endl;}
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
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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

  case 482:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 483:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 486:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 487:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 491:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 492:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 498:

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

  case 499:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 505:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 506:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 513:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 514:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 517:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 518:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 522:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 523:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 530:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 531:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 534:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 535:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 539:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 540:

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

  case 541:

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

  case 549:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 550:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 551:

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

  case 563:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 565:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 566:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 568:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 569:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 572:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
    break;

  case 573:

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
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
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
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 594:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 597:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
    break;

  case 598:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 602:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 603:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 610:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 611:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 614:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 615:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 619:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 620:

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

  case 621:

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

  case 629:

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

  case 635:

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

  case 637:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 638:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 641:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_complexConstant;
    }
    break;

  case 642:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 646:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 647:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");
//        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 648:

    {
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
}
    break;

  case 655:

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
                = (osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 656:

    {
std::cout << "matched <complexElements> <values> <el; next should be \"Re=\"" << std::endl;
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }
    break;

  case 665:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 666:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 669:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_string;
    }
    break;

  case 670:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 674:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 675:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 682:

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

  case 684:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 685:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 686:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 687:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 688:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 690:

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

  case 691:

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

  case 692:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 693:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 699:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 700:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 701:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 708:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 709:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 710:

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

  case 716:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 717:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 721:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 722:

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

  case 723:

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

  case 724:

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

  case 725:

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

  case 726:

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

  case 727:

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

  case 728:

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

  case 729:

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

  case 730:

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

  case 731:

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

  case 732:

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

  case 733:

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

  case 734:

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

  case 735:

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

  case 736:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 737:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 738:

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

  case 739:

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

  case 740:

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

  case 741:

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

  case 742:

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

  case 743:

    {
std::cout << "matched \"Im\"; value = " << parserData->tempVal << std::cout;
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 744:

    {
std::cout << "matched \"Re\"; value = " << parserData->tempVal << std::cout;
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 745:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 748:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 749:

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

  case 752:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 753:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 756:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 757:

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

  case 760:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 761:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 764:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 765:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 768:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 769:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 772:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 773:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 776:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 777:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 780:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 781:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 783:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 784:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 785:

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

  case 788:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 789:

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

  case 790:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 793:

    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new RealValuedExpressionTree();
    }
    break;

  case 794:

    {
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape 
                = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    }
    break;

  case 822:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 826:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 830:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 832:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 834:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 836:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 838:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 840:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 842:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 844:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 846:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 848:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 850:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 852:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 855:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 856:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 857:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 858:

    {
}
    break;

  case 859:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 860:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 861:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 863:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 865:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 867:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 868:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 873:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 874:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 876:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 878:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 879:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 882:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 886:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 887:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 888:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 889:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 890:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 891:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 893:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 894:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 895:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 897:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 898:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 899:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 901:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 902:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 903:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 905:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 906:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 907:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 909:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 929:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 930:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 933:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 934:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 935:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 938:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 939:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 940:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 943:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 944:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 945:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 948:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 950:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 953:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 956:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 959:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 962:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 964:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 967:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 969:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 971:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 973:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 977:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 980:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 983:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 986:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 988:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 989:

    {
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 991:

    { 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
}
    break;

  case 993:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 996:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 999:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1002:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 1003:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }
    break;

  case 1005:

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

  case 1012:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }
    break;

  case 1013:

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

  case 1014:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 1017:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    break;

  case 1018:

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


