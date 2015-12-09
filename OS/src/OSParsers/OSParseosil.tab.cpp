
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
#define YYLAST   1301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  415
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  696
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1044
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1609

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
    1236,  1238,  1240,  1245,  1247,  1249,  1250,  1253,  1255,  1257,
    1261,  1262,  1265,  1268,  1270,  1272,  1274,  1276,  1280,  1282,
    1285,  1287,  1289,  1291,  1293,  1297,  1299,  1302,  1304,  1306,
    1308,  1310,  1314,  1316,  1321,  1323,  1325,  1326,  1329,  1331,
    1333,  1337,  1338,  1341,  1344,  1346,  1348,  1350,  1352,  1356,
    1358,  1363,  1365,  1367,  1368,  1371,  1373,  1375,  1379,  1380,
    1383,  1384,  1387,  1389,  1391,  1393,  1395,  1399,  1401,  1402,
    1405,  1409,  1411,  1413,  1414,  1417,  1419,  1421,  1423,  1425,
    1427,  1431,  1432,  1435,  1439,  1441,  1442,  1444,  1448,  1453,
    1455,  1457,  1458,  1461,  1463,  1465,  1469,  1470,  1473,  1474,
    1477,  1479,  1481,  1483,  1485,  1489,  1490,  1493,  1496,  1498,
    1500,  1502,  1504,  1508,  1513,  1515,  1517,  1518,  1521,  1523,
    1525,  1529,  1530,  1533,  1534,  1537,  1539,  1541,  1543,  1545,
    1549,  1550,  1553,  1556,  1558,  1560,  1562,  1564,  1568,  1573,
    1575,  1577,  1578,  1581,  1583,  1585,  1589,  1590,  1593,  1596,
    1598,  1600,  1602,  1604,  1608,  1610,  1615,  1617,  1619,  1620,
    1623,  1625,  1627,  1631,  1632,  1635,  1636,  1639,  1641,  1643,
    1645,  1647,  1651,  1652,  1655,  1659,  1661,  1662,  1665,  1667,
    1669,  1671,  1675,  1680,  1682,  1684,  1685,  1688,  1690,  1692,
    1696,  1697,  1700,  1701,  1704,  1706,  1708,  1710,  1712,  1716,
    1717,  1720,  1724,  1726,  1727,  1730,  1732,  1734,  1736,  1739,
    1741,  1746,  1748,  1750,  1751,  1754,  1756,  1758,  1762,  1763,
    1766,  1769,  1771,  1773,  1775,  1777,  1781,  1783,  1789,  1791,
    1792,  1794,  1796,  1800,  1802,  1804,  1810,  1812,  1816,  1818,
    1820,  1822,  1824,  1826,  1830,  1832,  1836,  1838,  1840,  1842,
    1844,  1846,  1850,  1852,  1853,  1856,  1860,  1862,  1864,  1865,
    1868,  1870,  1872,  1874,  1876,  1878,  1880,  1882,  1886,  1891,
    1896,  1901,  1906,  1911,  1916,  1921,  1926,  1931,  1936,  1941,
    1946,  1951,  1956,  1961,  1966,  1971,  1976,  1981,  1986,  1991,
    1996,  2001,  2006,  2008,  2010,  2012,  2016,  2018,  2020,  2022,
    2026,  2028,  2030,  2032,  2036,  2038,  2040,  2042,  2046,  2048,
    2050,  2052,  2056,  2058,  2060,  2062,  2066,  2068,  2070,  2072,
    2076,  2078,  2080,  2082,  2086,  2088,  2090,  2092,  2096,  2097,
    2102,  2104,  2110,  2111,  2114,  2120,  2122,  2124,  2125,  2128,
    2130,  2132,  2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,
    2150,  2152,  2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,
    2170,  2172,  2174,  2176,  2178,  2180,  2182,  2184,  2186,  2187,
    2191,  2193,  2196,  2197,  2201,  2203,  2206,  2207,  2213,  2214,
    2220,  2221,  2227,  2228,  2233,  2234,  2240,  2241,  2247,  2248,
    2253,  2254,  2259,  2260,  2265,  2266,  2271,  2272,  2277,  2278,
    2283,  2287,  2289,  2291,  2292,  2297,  2298,  2305,  2306,  2311,
    2312,  2317,  2318,  2323,  2327,  2329,  2331,  2334,  2335,  2338,
    2340,  2342,  2344,  2345,  2350,  2351,  2356,  2358,  2361,  2362,
    2367,  2368,  2371,  2373,  2375,  2380,  2385,  2386,  2391,  2392,
    2395,  2396,  2401,  2402,  2405,  2406,  2411,  2412,  2415,  2416,
    2421,  2422,  2425,  2426,  2431,  2432,  2435,  2437,  2439,  2441,
    2443,  2445,  2447,  2449,  2451,  2453,  2455,  2457,  2459,  2461,
    2463,  2465,  2467,  2469,  2471,  2473,  2477,  2479,  2481,  2484,
    2489,  2493,  2495,  2497,  2500,  2505,  2509,  2511,  2513,  2516,
    2521,  2525,  2527,  2529,  2532,  2537,  2540,  2542,  2545,  2548,
    2550,  2554,  2557,  2559,  2562,  2565,  2567,  2570,  2575,  2577,
    2578,  2580,  2583,  2588,  2590,  2591,  2593,  2596,  2600,  2603,
    2605,  2607,  2610,  2613,  2615,  2619,  2622,  2624,  2627,  2630,
    2632,  2636,  2639,  2641,  2645,  2646,  2651,  2652,  2655,  2658,
    2660,  2664,  2667,  2669,  2676,  2679,  2681,  2684,  2685,  2689,
    2691,  2693,  2698,  2700,  2702,  2704,  2708,  2709,  2712,  2718,
    2720,  2722,  2723,  2726,  2728
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     416,     0,    -1,   420,   951,   433,   440,   530,   577,   417,
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
      48,    -1,   451,    -1,    -1,   451,   452,    -1,   903,    -1,
     901,    -1,   927,    -1,    10,    -1,    11,    49,    -1,   455,
     456,   459,    -1,    50,    -1,   457,    -1,    -1,   457,   458,
      -1,   903,    -1,   901,    -1,   927,    -1,    10,    -1,    11,
      51,    -1,   461,   462,   465,    -1,    52,    -1,   463,    -1,
      -1,   463,   464,    -1,   903,    -1,   901,    -1,   927,    -1,
      10,    -1,    11,   466,   474,    -1,   467,    -1,    -1,   467,
     468,    -1,   469,   470,   473,    -1,    70,    -1,   471,    -1,
      -1,   471,   472,    -1,   939,    -1,   916,    -1,    10,    -1,
      11,    71,    -1,    53,    -1,   476,   477,   481,    -1,    54,
      -1,   478,    -1,    -1,   478,   479,    -1,   903,    -1,   901,
      -1,   480,    -1,   927,    -1,    28,     8,     6,     8,    -1,
      10,    -1,    11,    55,    -1,   483,   484,   487,    -1,    56,
      -1,   485,    -1,    -1,   485,   486,    -1,   903,    -1,   901,
      -1,   927,    -1,   640,    -1,   639,    -1,   641,    -1,    10,
      -1,    11,    57,    -1,   489,   490,   493,    -1,    58,    -1,
     491,    -1,    -1,   491,   492,    -1,   903,    -1,   901,    -1,
     927,    -1,   640,    -1,   639,    -1,   642,    -1,   643,    -1,
      10,    -1,    11,    59,    -1,   495,   496,   499,    -1,    60,
      -1,   497,    -1,    -1,   497,   498,    -1,   903,    -1,   901,
      -1,   927,    -1,   644,    -1,    10,    -1,    11,    61,    -1,
     501,   502,   505,    -1,    62,    -1,   503,    -1,    -1,   503,
     504,    -1,   903,    -1,   901,    -1,   927,    -1,    11,   506,
     514,    -1,   507,   508,   509,    -1,    72,    -1,   902,    -1,
     510,    -1,   511,    -1,    10,    -1,    11,   512,   513,    -1,
     660,    -1,    73,    -1,    63,    -1,   516,   517,   520,    -1,
      64,    -1,   518,    -1,    -1,   518,   519,    -1,   903,    -1,
     901,    -1,   927,    -1,    11,   521,   529,    -1,   522,   523,
     524,    -1,    74,    -1,   902,    -1,   525,    -1,   526,    -1,
      10,    -1,    11,   527,   528,    -1,   660,    -1,    75,    -1,
      65,    -1,    -1,   531,   532,    -1,   247,    -1,   533,    -1,
     534,    -1,    10,    -1,    11,   535,   549,   563,  1098,   248,
      -1,    -1,   536,   537,   538,    -1,   249,    -1,   636,    -1,
     539,    -1,   540,    -1,    10,    -1,    11,   542,   541,    -1,
     250,    -1,    -1,   542,   543,    -1,   544,   545,   548,    -1,
     251,    -1,   546,    -1,    -1,   546,   547,    -1,   903,    -1,
     901,    -1,   649,    -1,   650,    -1,   646,    -1,   653,    -1,
     647,    -1,   654,    -1,   927,    -1,   948,    -1,   916,    -1,
      10,    -1,    11,   252,    -1,    -1,   550,   551,   552,    -1,
     253,    -1,   637,    -1,   553,    -1,   554,    -1,    10,    -1,
      11,   556,   555,    -1,   254,    -1,    -1,   556,   557,    -1,
     558,   559,   562,    -1,   255,    -1,   560,    -1,    -1,   560,
     561,    -1,   903,    -1,   901,    -1,   649,    -1,   651,    -1,
     655,    -1,   648,    -1,   927,    -1,   916,    -1,    10,    -1,
      11,   256,    -1,    -1,   564,   565,   566,    -1,   257,    -1,
     638,    -1,   567,    -1,   568,    -1,    10,    -1,    11,   570,
     569,    -1,   258,    -1,    -1,   570,   571,    -1,   572,   573,
     576,    -1,   259,    -1,   574,    -1,    -1,   574,   575,    -1,
     903,    -1,   901,    -1,   649,    -1,   652,    -1,   646,    -1,
     653,    -1,   647,    -1,   654,    -1,   927,    -1,    10,    -1,
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
      -1,   916,    -1,   915,    -1,    11,     6,   113,    -1,   120,
     906,   669,    -1,   670,    -1,   671,    -1,    11,   121,    -1,
      10,    -1,    11,     4,   121,    -1,   673,    -1,   678,    -1,
      -1,   673,   674,    -1,   675,   676,   677,    -1,   112,    -1,
      -1,   916,    -1,    11,   656,   113,    -1,   120,   906,   679,
      -1,   680,    -1,   681,    -1,    11,   121,    -1,    10,    -1,
      11,     4,   121,    -1,   683,    -1,    -1,   683,   684,    -1,
     685,   686,   687,    -1,   112,    -1,    -1,   916,    -1,    11,
       4,   113,    -1,   689,   690,   693,    -1,   205,    -1,   691,
      -1,    -1,   691,   692,    -1,   936,    -1,   903,    -1,   901,
      -1,   927,    -1,   939,    -1,   694,    -1,   695,    -1,    10,
      -1,    11,   696,   206,    -1,   697,   703,    -1,    -1,   698,
     699,   702,    -1,   208,    -1,   700,    -1,    -1,   700,   701,
      -1,   907,    -1,   917,    -1,   918,    -1,   908,    -1,   909,
      -1,   910,    -1,   911,    -1,   924,    -1,   923,    -1,    11,
     207,    -1,    10,    -1,    -1,   703,   704,    -1,   705,    -1,
     730,    -1,   743,    -1,   770,    -1,   806,    -1,   819,    -1,
     837,    -1,   788,    -1,   855,    -1,   868,    -1,   872,    -1,
     706,   707,    11,   710,    -1,   219,    -1,   708,    -1,    -1,
     708,   709,    -1,   904,    -1,   930,    -1,   712,   711,   220,
      -1,    -1,   718,   724,    -1,   713,   714,    -1,   237,    -1,
     715,    -1,   716,    -1,    10,    -1,    11,   717,   238,    -1,
     660,    -1,   719,   720,    -1,   239,    -1,   721,    -1,   722,
      -1,    10,    -1,    11,   723,   240,    -1,   660,    -1,   725,
     726,    -1,   241,    -1,   727,    -1,   728,    -1,    10,    -1,
      11,   729,   242,    -1,   672,    -1,   731,   732,    11,   735,
      -1,   223,    -1,   733,    -1,    -1,   733,   734,    -1,   904,
      -1,   930,    -1,   712,   736,   224,    -1,    -1,   718,   737,
      -1,   738,   739,    -1,   241,    -1,   740,    -1,   741,    -1,
      10,    -1,    11,   742,   242,    -1,   660,    -1,   744,   745,
      11,   748,    -1,   225,    -1,   746,    -1,    -1,   746,   747,
      -1,   904,    -1,   930,    -1,   712,   749,   226,    -1,    -1,
     718,   750,    -1,    -1,   751,   752,    -1,   241,    -1,   753,
      -1,   754,    -1,    10,    -1,    11,   755,   242,    -1,   756,
      -1,    -1,   756,   757,    -1,   758,   759,   762,    -1,   112,
      -1,   760,    -1,    -1,   760,   761,    -1,   905,    -1,   920,
      -1,   763,    -1,   764,    -1,    10,    -1,    11,   765,   113,
      -1,    -1,   765,   766,    -1,   767,   768,   769,    -1,   243,
      -1,    -1,   919,    -1,    11,     6,   244,    -1,   771,   772,
      11,   775,    -1,   231,    -1,   773,    -1,    -1,   773,   774,
      -1,   904,    -1,   930,    -1,   712,   776,   232,    -1,    -1,
     718,   777,    -1,    -1,   778,   779,    -1,   241,    -1,   780,
      -1,   781,    -1,    10,    -1,    11,   782,   242,    -1,    -1,
     782,   783,    -1,   784,   785,    -1,   112,    -1,   786,    -1,
     787,    -1,    10,    -1,    11,   960,   113,    -1,   789,   790,
      11,   793,    -1,   233,    -1,   791,    -1,    -1,   791,   792,
      -1,   904,    -1,   930,    -1,   712,   794,   234,    -1,    -1,
     718,   795,    -1,    -1,   796,   797,    -1,   241,    -1,   798,
      -1,   799,    -1,    10,    -1,    11,   800,   242,    -1,    -1,
     800,   801,    -1,   802,   803,    -1,   112,    -1,   804,    -1,
     805,    -1,    10,    -1,    11,   960,   113,    -1,   807,   808,
      11,   811,    -1,   229,    -1,   809,    -1,    -1,   809,   810,
      -1,   904,    -1,   930,    -1,   712,   812,   230,    -1,    -1,
     718,   813,    -1,   814,   815,    -1,   241,    -1,   816,    -1,
     817,    -1,    10,    -1,    11,   818,   242,    -1,   660,    -1,
     820,   821,    11,   824,    -1,   227,    -1,   822,    -1,    -1,
     822,   823,    -1,   904,    -1,   930,    -1,   712,   825,   228,
      -1,    -1,   718,   826,    -1,    -1,   827,   828,    -1,   241,
      -1,   829,    -1,   830,    -1,    10,    -1,    11,   831,   242,
      -1,    -1,   831,   832,    -1,   833,   834,   836,    -1,   112,
      -1,    -1,   834,   835,    -1,   945,    -1,   916,    -1,   915,
      -1,    11,     6,   113,    -1,   838,   839,    11,   842,    -1,
     221,    -1,   840,    -1,    -1,   840,   841,    -1,   904,    -1,
     930,    -1,   712,   843,   222,    -1,    -1,   718,   844,    -1,
      -1,   845,   846,    -1,   241,    -1,   847,    -1,   848,    -1,
      10,    -1,    11,   849,   242,    -1,    -1,   849,   850,    -1,
     851,   852,   854,    -1,   112,    -1,    -1,   852,   853,    -1,
     922,    -1,   921,    -1,   916,    -1,    11,   113,    -1,    10,
      -1,   856,   857,    11,   860,    -1,   235,    -1,   858,    -1,
      -1,   858,   859,    -1,   904,    -1,   930,    -1,   712,   861,
     236,    -1,    -1,   718,   862,    -1,   863,   864,    -1,   241,
      -1,   865,    -1,   866,    -1,    10,    -1,    11,   867,   242,
      -1,   682,    -1,   869,   870,    11,  1034,   871,    -1,   245,
      -1,    -1,   933,    -1,   246,    -1,   873,   874,   875,    -1,
     209,    -1,   900,    -1,    11,   877,   884,   891,   876,    -1,
     210,    -1,   878,   879,   880,    -1,   213,    -1,   902,    -1,
     881,    -1,   882,    -1,    10,    -1,    11,   883,   214,    -1,
     660,    -1,   885,   886,   887,    -1,   215,    -1,   902,    -1,
     888,    -1,   889,    -1,    10,    -1,    11,   890,   216,    -1,
     660,    -1,    -1,   891,   892,    -1,   893,   894,   897,    -1,
     211,    -1,   895,    -1,    -1,   895,   896,    -1,   912,    -1,
     913,    -1,   936,    -1,   939,    -1,   898,    -1,   899,    -1,
      10,    -1,    11,   696,   212,    -1,   165,     8,     6,     8,
      -1,   166,     8,     6,     8,    -1,   122,     8,     6,     8,
      -1,   167,     8,     6,     8,    -1,   169,     8,     6,     8,
      -1,   178,     8,     6,     8,    -1,   200,     8,     6,     8,
      -1,   182,     8,     6,     8,    -1,   185,     8,     6,     8,
      -1,   186,     8,     6,     8,    -1,   187,     8,     6,     8,
      -1,   188,     8,     6,     8,    -1,   190,     8,     6,     8,
      -1,   191,     8,     6,     8,    -1,   197,     8,     6,     8,
      -1,   198,     8,     6,     8,    -1,   199,     8,     6,     8,
      -1,   183,     8,     6,     8,    -1,   184,     8,     6,     8,
      -1,   201,     8,   656,     8,    -1,   202,     8,   656,     8,
      -1,   193,     8,   656,     8,    -1,   192,     8,   656,     8,
      -1,   189,     8,   656,     8,    -1,   925,    -1,   926,    -1,
     163,    -1,   164,     3,   657,    -1,   928,    -1,   929,    -1,
     131,    -1,   132,     3,     8,    -1,   931,    -1,   932,    -1,
     161,    -1,   162,     3,     8,    -1,   934,    -1,   935,    -1,
     137,    -1,   138,     3,     8,    -1,   937,    -1,   938,    -1,
     159,    -1,   160,     3,     8,    -1,   940,    -1,   941,    -1,
     133,    -1,   134,     3,     8,    -1,   943,    -1,   944,    -1,
     141,    -1,   142,     3,     8,    -1,   946,    -1,   947,    -1,
     143,    -1,   144,     3,     8,    -1,   949,    -1,   950,    -1,
     149,    -1,   150,     3,     8,    -1,    -1,   952,   953,   954,
     309,    -1,   308,    -1,   310,     8,     6,     8,    11,    -1,
      -1,   954,   955,    -1,   956,   957,    11,   960,   312,    -1,
     311,    -1,   958,    -1,    -1,   958,   959,    -1,   914,    -1,
     933,    -1,  1004,    -1,  1011,    -1,   967,    -1,   969,    -1,
    1019,    -1,   971,    -1,   973,    -1,   975,    -1,   977,    -1,
    1031,    -1,   979,    -1,   981,    -1,   983,    -1,   987,    -1,
     985,    -1,   989,    -1,   996,    -1,   991,    -1,   994,    -1,
    1025,    -1,  1028,    -1,   961,    -1,   964,    -1,  1022,    -1,
     998,    -1,  1000,    -1,  1002,    -1,    -1,   361,   962,   963,
      -1,    10,    -1,    11,   362,    -1,    -1,   363,   965,   966,
      -1,    10,    -1,    11,   364,    -1,    -1,   365,   968,   960,
     960,   366,    -1,    -1,   323,   970,   960,   960,   324,    -1,
      -1,   325,   972,   960,   960,   326,    -1,    -1,   339,   974,
     960,   340,    -1,    -1,   327,   976,   960,   960,   328,    -1,
      -1,   321,   978,   960,   960,   322,    -1,    -1,   329,   980,
     960,   330,    -1,    -1,   331,   982,   960,   332,    -1,    -1,
     343,   984,   960,   344,    -1,    -1,   345,   986,   960,   346,
      -1,    -1,   347,   988,   960,   348,    -1,    -1,   337,   990,
     960,   338,    -1,   992,   960,   993,    -1,   351,    -1,   352,
      -1,    -1,   353,   995,   960,   354,    -1,    -1,   341,   997,
     960,   960,   960,   342,    -1,    -1,   369,   999,  1034,   370,
      -1,    -1,   371,  1001,  1034,   372,    -1,    -1,   373,  1003,
    1034,   374,    -1,  1005,  1007,  1006,    -1,   367,    -1,    10,
      -1,    11,   368,    -1,    -1,  1007,  1008,    -1,   939,    -1,
     942,    -1,  1009,    -1,    -1,   410,     3,  1010,     8,    -1,
      -1,   349,  1012,  1015,  1013,    -1,    10,    -1,    11,   350,
      -1,    -1,    11,   960,  1014,   350,    -1,    -1,  1015,  1016,
      -1,  1017,    -1,  1018,    -1,   201,     8,   656,     8,    -1,
     197,     8,     6,     8,    -1,    -1,   333,  1020,  1021,   334,
      -1,    -1,  1021,   960,    -1,    -1,   357,  1023,  1024,   358,
      -1,    -1,  1024,   960,    -1,    -1,   355,  1026,  1027,   356,
      -1,    -1,  1027,   960,    -1,    -1,   359,  1029,  1030,   360,
      -1,    -1,  1030,   960,    -1,    -1,   335,  1032,  1033,   336,
      -1,    -1,  1033,   960,    -1,  1035,    -1,  1038,    -1,  1042,
      -1,  1046,    -1,  1050,    -1,  1053,    -1,  1059,    -1,  1062,
      -1,  1066,    -1,  1071,    -1,  1074,    -1,  1077,    -1,  1080,
      -1,  1083,    -1,  1086,    -1,  1089,    -1,  1092,    -1,  1095,
      -1,  1056,    -1,  1036,   645,  1037,    -1,   401,    -1,    10,
      -1,    11,   402,    -1,   197,     8,     6,     8,    -1,  1039,
    1041,  1040,    -1,   251,    -1,    10,    -1,    11,   252,    -1,
     197,     8,     6,     8,    -1,  1043,  1045,  1044,    -1,   255,
      -1,    10,    -1,    11,   256,    -1,   197,     8,     6,     8,
      -1,  1047,  1049,  1048,    -1,   259,    -1,    10,    -1,    11,
     260,    -1,   197,     8,     6,     8,    -1,  1051,  1052,    -1,
     375,    -1,  1034,   376,    -1,  1054,  1055,    -1,   377,    -1,
    1034,  1034,   378,    -1,  1057,  1058,    -1,   403,    -1,   960,
     404,    -1,  1060,  1061,    -1,   405,    -1,  1034,   406,    -1,
    1063,  1064,    11,  1065,    -1,   379,    -1,    -1,  1070,    -1,
    1034,   380,    -1,  1067,  1068,    11,  1069,    -1,   381,    -1,
      -1,  1070,    -1,  1034,   382,    -1,   408,     3,     8,    -1,
    1072,  1073,    -1,   383,    -1,    10,    -1,    11,   384,    -1,
    1075,  1076,    -1,   385,    -1,  1034,  1034,   386,    -1,  1078,
    1079,    -1,   387,    -1,  1034,   388,    -1,  1081,  1082,    -1,
     389,    -1,  1034,  1034,   390,    -1,  1084,  1085,    -1,   391,
      -1,  1034,  1034,   392,    -1,    -1,   393,  1087,  1088,   394,
      -1,    -1,  1088,  1034,    -1,  1090,  1091,    -1,   395,    -1,
     960,  1034,   396,    -1,  1093,  1094,    -1,   397,    -1,   960,
     960,   960,   960,  1034,   398,    -1,  1096,  1097,    -1,   399,
      -1,  1034,   400,    -1,    -1,  1099,  1100,  1102,    -1,   313,
      -1,  1101,    -1,   315,     8,     6,     8,    -1,  1103,    -1,
    1104,    -1,    10,    -1,    11,  1105,   314,    -1,    -1,  1105,
    1106,    -1,  1107,  1108,    11,  1034,   317,    -1,   316,    -1,
    1109,    -1,    -1,  1109,  1110,    -1,   914,    -1,   933,    -1
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
    3260,  3265,  3265,  3265,  3265,  3266,  3266,  3267,  3267,  3267,
    3268,  3268,  3270,  3272,  3281,  3287,  3287,  3290,  3296,  3302,
    3304,  3304,  3310,  3320,  3330,  3330,  3332,  3334,  3336,  3339,
    3350,  3357,  3357,  3359,  3361,  3363,  3369,  3379,  3386,  3386,
    3388,  3390,  3392,  3395,  3397,  3406,  3412,  3412,  3415,  3421,
    3427,  3429,  3429,  3431,  3441,  3448,  3448,  3450,  3452,  3454,
    3456,  3458,  3467,  3473,  3473,  3476,  3482,  3488,  3490,  3490,
    3493,  3498,  3509,  3524,  3524,  3526,  3528,  3530,  3532,  3532,
    3534,  3541,  3548,  3561,  3561,  3564,  3565,  3567,  3567,  3569,
    3571,  3573,  3573,  3576,  3578,  3586,  3586,  3591,  3599,  3601,
    3610,  3616,  3616,  3619,  3625,  3632,  3634,  3634,  3637,  3641,
    3652,  3667,  3667,  3669,  3671,  3673,  3673,  3675,  3677,  3692,
    3692,  3694,  3696,  3705,  3707,  3716,  3722,  3722,  3725,  3732,
    3739,  3741,  3741,  3744,  3748,  3759,  3775,  3775,  3777,  3779,
    3781,  3781,  3783,  3785,  3800,  3800,  3802,  3804,  3813,  3815,
    3824,  3830,  3830,  3833,  3839,  3845,  3847,  3847,  3849,  3859,
    3866,  3866,  3868,  3870,  3872,  3875,  3877,  3886,  3892,  3892,
    3895,  3901,  3907,  3909,  3909,  3912,  3916,  3927,  3942,  3942,
    3944,  3946,  3948,  3948,  3950,  3953,  3965,  3965,  3968,  3969,
    3970,  3972,  4004,  4006,  4016,  4022,  4022,  4025,  4031,  4037,
    4039,  4039,  4042,  4046,  4057,  4069,  4069,  4071,  4073,  4075,
    4075,  4077,  4104,  4115,  4115,  4118,  4119,  4120,  4122,  4122,
    4125,  4127,  4136,  4142,  4142,  4145,  4151,  4157,  4159,  4159,
    4161,  4171,  4178,  4178,  4180,  4182,  4184,  4187,  4190,  4208,
    4208,  4219,  4226,  4236,  4244,  4250,  4252,  4266,  4278,  4284,
    4290,  4290,  4292,  4294,  4296,  4298,  4308,  4314,  4320,  4320,
    4322,  4324,  4326,  4328,  4328,  4333,  4338,  4350,  4352,  4352,
    4355,  4356,  4357,  4365,  4372,  4372,  4374,  4376,  4394,  4405,
    4449,  4572,  4583,  4605,  4630,  4641,  4655,  4670,  4685,  4697,
    4709,  4729,  4749,  4759,  4796,  4807,  4819,  4833,  4846,  4859,
    4870,  4881,  4894,  4894,  4896,  4906,  5068,  5068,  5070,  5077,
    5104,  5104,  5106,  5115,  5129,  5129,  5131,  5138,  5165,  5165,
    5167,  5174,  5183,  5183,  5185,  5192,  5219,  5219,  5223,  5231,
    5240,  5240,  5242,  5249,  5258,  5258,  5260,  5267,  5306,  5307,
    5313,  5319,  5340,  5341,  5343,  5351,  5370,  5377,  5377,  5380,
    5386,  5396,  5397,  5398,  5399,  5400,  5401,  5402,  5403,  5404,
    5405,  5406,  5407,  5408,  5409,  5410,  5411,  5412,  5413,  5414,
    5415,  5416,  5417,  5418,  5419,  5421,  5422,  5423,  5427,  5427,
    5430,  5431,  5433,  5433,  5436,  5437,  5441,  5441,  5446,  5446,
    5451,  5451,  5456,  5456,  5461,  5461,  5466,  5466,  5471,  5471,
    5476,  5476,  5481,  5481,  5486,  5486,  5491,  5491,  5496,  5496,
    5501,  5503,  5509,  5516,  5516,  5522,  5522,  5534,  5534,  5539,
    5539,  5544,  5544,  5554,  5561,  5567,  5568,  5570,  5571,  5574,
    5578,  5582,  5586,  5585,  5604,  5603,  5610,  5611,  5613,  5612,
    5619,  5620,  5623,  5629,  5637,  5644,  5662,  5662,  5673,  5673,
    5676,  5676,  5690,  5691,  5694,  5694,  5707,  5708,  5711,  5711,
    5724,  5725,  5728,  5728,  5738,  5739,  5745,  5746,  5747,  5748,
    5749,  5750,  5751,  5752,  5753,  5754,  5755,  5756,  5757,  5758,
    5759,  5760,  5761,  5762,  5763,  5766,  5771,  5778,  5779,  5781,
    5789,  5794,  5801,  5802,  5804,  5811,  5816,  5823,  5824,  5826,
    5833,  5838,  5845,  5846,  5848,  5855,  5857,  5863,  5865,  5867,
    5873,  5875,  5877,  5883,  5885,  5887,  5893,  5895,  5897,  5903,
    5903,  5908,  5910,  5912,  5918,  5918,  5923,  5925,  5934,  5936,
    5941,  5941,  5943,  5945,  5951,  5954,  5956,  5962,  5965,  5967,
    5973,  5976,  5978,  5984,  5988,  5987,  5999,  5999,  6006,  6008,
    6014,  6016,  6018,  6024,  6027,  6029,  6035,  6045,  6045,  6051,
    6059,  6061,  6081,  6081,  6083,  6085,  6087,  6087,  6089,  6099,
    6118,  6124,  6124,  6127,  6135
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
     704,   704,   705,   706,   707,   708,   708,   709,   709,   710,
     711,   711,   712,   713,   714,   714,   715,   716,   717,   718,
     719,   720,   720,   721,   722,   723,   724,   725,   726,   726,
     727,   728,   729,   730,   731,   732,   733,   733,   734,   734,
     735,   736,   736,   737,   738,   739,   739,   740,   741,   742,
     743,   744,   745,   746,   746,   747,   747,   748,   749,   749,
     750,   750,   751,   752,   752,   753,   754,   755,   756,   756,
     757,   758,   759,   760,   760,   761,   761,   762,   762,   763,
     764,   765,   765,   766,   767,   768,   768,   769,   770,   771,
     772,   773,   773,   774,   774,   775,   776,   776,   777,   777,
     778,   779,   779,   780,   781,   782,   782,   783,   784,   785,
     785,   786,   787,   788,   789,   790,   791,   791,   792,   792,
     793,   794,   794,   795,   795,   796,   797,   797,   798,   799,
     800,   800,   801,   802,   803,   803,   804,   805,   806,   807,
     808,   809,   809,   810,   810,   811,   812,   812,   813,   814,
     815,   815,   816,   817,   818,   819,   820,   821,   822,   822,
     823,   823,   824,   825,   825,   826,   826,   827,   828,   828,
     829,   830,   831,   831,   832,   833,   834,   834,   835,   835,
     835,   836,   837,   838,   839,   840,   840,   841,   841,   842,
     843,   843,   844,   844,   845,   846,   846,   847,   848,   849,
     849,   850,   851,   852,   852,   853,   853,   853,   854,   854,
     855,   856,   857,   858,   858,   859,   859,   860,   861,   861,
     862,   863,   864,   864,   865,   866,   867,   868,   869,   870,
     870,   871,   872,   873,   874,   875,   876,   877,   878,   879,
     880,   880,   881,   882,   883,   884,   885,   886,   887,   887,
     888,   889,   890,   891,   891,   892,   893,   894,   895,   895,
     896,   896,   896,   896,   897,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   924,   925,   926,   927,   927,   928,   929,
     930,   930,   931,   932,   933,   933,   934,   935,   936,   936,
     937,   938,   939,   939,   940,   941,   942,   942,   943,   944,
     945,   945,   946,   947,   948,   948,   949,   950,   951,   951,
     952,   953,   954,   954,   955,   956,   957,   958,   958,   959,
     959,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   962,   961,
     963,   963,   965,   964,   966,   966,   968,   967,   970,   969,
     972,   971,   974,   973,   976,   975,   978,   977,   980,   979,
     982,   981,   984,   983,   986,   985,   988,   987,   990,   989,
     991,   992,   993,   995,   994,   997,   996,   999,   998,  1001,
    1000,  1003,  1002,  1004,  1005,  1006,  1006,  1007,  1007,  1008,
    1008,  1008,  1010,  1009,  1012,  1011,  1013,  1013,  1014,  1013,
    1015,  1015,  1016,  1016,  1017,  1018,  1020,  1019,  1021,  1021,
    1023,  1022,  1024,  1024,  1026,  1025,  1027,  1027,  1029,  1028,
    1030,  1030,  1032,  1031,  1033,  1033,  1034,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1034,  1035,  1036,  1037,  1037,   645,
    1038,  1039,  1040,  1040,  1041,  1042,  1043,  1044,  1044,  1045,
    1046,  1047,  1048,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1064,  1065,  1066,  1067,  1068,  1068,  1069,  1070,  1071,  1072,
    1073,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1087,  1086,  1088,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1098,  1099,
    1100,  1101,  1102,  1102,  1103,  1104,  1105,  1105,  1106,  1107,
    1108,  1109,  1109,  1110,  1110
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
       0,     2,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     2,     1,     1,     1,     1,     3,     1,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       0,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     1,     3,     4,     1,
       1,     0,     2,     1,     1,     3,     0,     2,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     4,     1,
       1,     0,     2,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     0,     2,     1,     1,     1,
       1,     3,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     2,     1,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     1,     5,     1,     0,
       1,     1,     3,     1,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     0,     4,
       1,     5,     0,     2,     5,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     2,     0,     3,     1,     2,     0,     5,     0,     5,
       0,     5,     0,     4,     0,     5,     0,     5,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     1,     1,     0,     4,     0,     6,     0,     4,     0,
       4,     0,     4,     3,     1,     1,     2,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     1,     2,     0,     4,
       0,     2,     1,     1,     4,     4,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     4,
       3,     1,     1,     2,     4,     3,     1,     1,     2,     4,
       3,     1,     1,     2,     4,     2,     1,     2,     2,     1,
       3,     2,     1,     2,     2,     1,     2,     4,     1,     0,
       1,     2,     4,     1,     0,     1,     2,     3,     2,     1,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       3,     2,     1,     3,     0,     4,     0,     2,     2,     1,
       3,     2,     1,     6,     2,     1,     2,     0,     3,     1,
       1,     4,     1,     1,     1,     3,     0,     2,     5,     1,
       1,     0,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   808,     0,     1,   810,    28,     0,     0,
      12,    30,    38,     0,     0,   812,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   277,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   809,   815,   813,   817,     0,     0,
     279,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   816,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   282,   354,   278,   280,   281,
     197,   224,     0,     0,     0,   365,    35,   438,    37,   440,
     811,     0,   786,     0,     0,   819,   820,   784,   785,   818,
      17,     0,     0,     0,   390,     6,     2,     5,   283,   287,
       0,     0,     0,     0,   226,   250,     0,     0,     0,   198,
     366,    45,    58,    68,    78,   101,   113,   126,   140,   151,
     170,    47,    48,    60,    49,    70,    50,    80,    51,   103,
      52,   115,    53,   128,    54,   142,    55,   153,    56,   172,
       0,   439,   866,   858,   860,   864,   868,   870,   916,   932,
     878,   862,   885,   872,   874,   876,   904,   881,   883,   924,
     920,   928,   848,   852,   856,   894,   887,   889,   891,     0,
     842,   843,   823,   824,   826,   827,   828,   829,   831,   832,
     833,   835,   834,   836,   838,     0,   839,   837,   845,   846,
     847,   821,   897,   822,   825,   844,   840,   841,   830,     0,
       0,     0,     0,     0,     0,     0,   284,     0,   291,   285,
     358,   252,  1027,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   449,   452,   437,   447,   448,   778,     0,   794,     0,
     790,     0,     0,     0,   441,   444,   443,   445,   776,   777,
     442,   788,   789,   446,   792,   793,     0,     0,     0,     0,
       0,     0,   918,   934,     0,     0,     0,     0,     0,     0,
     910,     0,   926,   922,   930,     0,     0,     0,     0,     0,
       0,   814,     0,     0,   787,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1029,     0,     0,     0,     0,   253,     0,   230,
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
       0,   850,     0,   849,   854,     0,   853,     0,   961,   966,
     971,   976,   979,   988,   993,   999,  1003,  1006,  1009,  1012,
    1014,  1019,  1022,  1025,   956,   982,   985,     0,   936,     0,
     937,     0,   938,     0,   939,     0,   940,     0,   941,     0,
     954,     0,   942,     0,   943,   989,   944,   994,   945,     0,
     946,     0,   947,     0,   948,     0,   949,     0,   950,   951,
       0,   952,     0,   953,     0,     0,     0,   882,   880,   895,
       0,   798,     0,     0,   899,   900,   796,   797,   893,   898,
     901,   762,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,  1030,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   450,   451,     0,   455,   779,
     795,   791,     0,     0,     0,     0,     0,     0,   869,   871,
     917,   919,   933,   935,   879,   863,     0,   873,   875,   877,
     906,     0,     0,     0,   905,   911,   912,   913,   884,   925,
     927,   921,   923,   929,   931,   851,   855,     0,  1016,   888,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     975,     0,   978,     0,   981,     0,   984,     0,     0,   990,
       0,   995,  1000,     0,   998,     0,  1002,     0,  1005,     0,
    1008,     0,  1011,     0,  1018,     0,  1021,     0,  1024,   890,
     892,   896,     0,   902,     0,     0,     0,   357,   390,   390,
       0,  1034,  1036,  1028,  1032,  1033,     0,     0,   368,   232,
     236,   231,   234,   238,     0,   208,    99,    86,    91,    89,
      93,     0,     0,     0,     0,     0,     0,   375,   168,   158,
       0,     0,   161,   187,   177,     0,   180,   713,   483,   663,
     514,   531,   636,   619,   569,   594,   691,   708,   470,   471,
     485,   472,   516,   473,   533,   474,   571,   478,   596,   475,
     621,   476,   638,   477,   665,   479,   693,   480,   709,   481,
       0,   468,     0,   453,   774,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   458,   461,   462,   463,   464,
     459,   460,   466,   465,   772,   773,   749,   751,   867,   859,
     861,   865,     0,   907,   908,     0,   390,   857,     0,     0,
       0,   957,     0,   955,     0,   962,     0,   960,     0,   967,
       0,   965,     0,   972,     0,   970,   977,     0,   983,   986,
       0,     0,     0,  1001,     0,  1007,     0,     0,     0,     0,
    1026,   799,     0,   288,     0,   295,   298,   292,     0,     0,
       0,     0,   369,   258,   262,   257,   260,   264,     0,   237,
     222,     0,   206,     0,     0,     0,     0,     0,     0,   806,
       0,     0,   210,   215,   217,   213,   214,   216,   218,   212,
     211,   221,   219,   220,   804,   805,     0,    92,   109,   370,
     371,   372,   373,   374,     0,   164,   398,   159,   162,   163,
     183,   398,   178,   181,   182,     0,   484,     0,   515,     0,
     532,     0,   570,     0,   595,     0,   620,     0,   637,     0,
     664,     0,   692,     0,   710,     0,     0,   714,   467,   390,
       0,     0,     0,     0,     0,     0,     0,   390,   886,     0,
       0,     0,  1015,  1017,     0,     0,   958,     0,   963,     0,
     968,     0,   973,   980,   997,     0,   987,     0,   992,  1004,
    1010,  1013,  1020,     0,   903,   294,   300,     0,   317,   363,
     364,  1031,  1035,  1039,  1037,  1041,     0,   263,   248,     0,
     235,     0,     0,     0,   239,   245,   242,   243,   244,   241,
     240,   247,   246,   223,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,    90,    94,    96,    95,     0,     0,
       0,   166,   396,   397,     0,   185,     0,   782,     0,     0,
     486,   487,   488,   780,   781,     0,   517,   518,   519,     0,
     534,   535,   536,     0,   572,   573,   574,     0,   597,   598,
     599,     0,   622,   623,   624,     0,   639,   640,   641,     0,
     666,   667,   668,     0,   694,   695,   696,     0,     0,     0,
     712,   775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   909,   915,   914,   376,   959,   964,   969,   974,   991,
     996,     0,     0,   296,   319,   336,     0,  1040,   275,     0,
     261,     0,   265,   270,   272,   268,   269,   271,   273,   267,
     266,   274,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   807,     0,    98,   750,     0,     0,   167,   165,
     401,   399,   403,   186,   184,   493,   482,   490,     0,     0,
       0,   521,   513,   538,   530,   576,   568,   601,   593,   626,
     618,   643,   635,   670,   662,   698,   690,     0,     0,   718,
       0,     0,   389,   755,   765,   766,   756,   757,   758,   759,
     771,     0,   308,   312,     0,     0,   301,   302,   303,   299,
     306,     0,   338,   297,     0,  1043,  1044,  1042,   276,     0,
       0,     0,     0,   377,   384,   378,   385,   380,   381,   764,
       0,   412,     0,   408,   409,   410,     0,   402,   500,     0,
       0,     0,   496,   398,   492,   494,   495,   783,     0,     0,
       0,   540,     0,   578,     0,   603,     0,     0,     0,   645,
       0,   672,     0,     0,     0,   711,   707,   748,   726,   733,
       0,     0,   719,  1023,   309,   312,   310,     0,     0,     0,
     327,   331,     0,     0,   320,   321,   322,   318,   325,     0,
       0,     0,   382,   386,   379,     0,     0,   411,     0,   400,
       0,   404,   406,   405,   489,   507,   491,     0,   503,   398,
     499,   501,   502,   498,     0,   752,   524,   522,     0,   520,
     542,   539,     0,   537,   580,   577,     0,   575,   605,   602,
       0,   600,   629,   627,     0,   625,   647,   644,     0,   642,
     674,   671,     0,   669,   701,   699,     0,   697,     0,     0,
     727,   722,   398,   717,   720,   721,   307,   311,     0,     0,
       0,   328,   331,   329,     0,     0,     0,   345,   349,     0,
       0,   339,   340,   337,   343,   341,  1038,   383,   754,   413,
       0,     0,   510,   416,   506,   508,   509,   505,     0,   497,
     527,   398,   523,   525,   526,   545,   548,   541,   543,   544,
     583,   585,   579,   581,   582,   608,   610,   604,   606,   607,
     632,   398,   628,   630,   631,   650,   652,   646,   648,   649,
     677,   679,   673,   675,   676,   704,   430,   700,   702,   703,
     716,   736,   715,   734,   738,   730,   398,   725,   728,   729,
     724,     0,     0,     0,   305,   304,   326,   330,     0,     0,
       0,   346,   349,   347,     0,     0,     0,   407,     0,     0,
     512,   414,   415,     0,   504,   529,     0,     0,   547,     0,
       0,   634,     0,     0,     0,   706,   429,     0,     0,   737,
     732,     0,   723,     0,   315,     0,   313,     0,     0,   324,
     323,   344,   348,     0,     0,     0,   763,     0,   419,   417,
     420,   511,   528,   546,   551,   549,   553,   588,   584,   586,
       0,   613,   609,   611,     0,   633,   655,   651,   653,   656,
     682,   678,   680,   683,   433,   431,   434,   705,   746,   452,
     735,   744,   745,     0,     0,   739,   740,   741,   742,   743,
     731,     0,   316,     0,   334,     0,   332,     0,     0,   362,
     342,   427,     0,   423,   424,   425,     0,   421,     0,   552,
     591,     0,   587,   589,   590,   616,     0,   612,   614,   615,
       0,     0,     0,   435,     0,     0,     0,   314,     0,   335,
       0,   352,     0,   350,     0,   426,   390,   418,   559,   561,
     550,   557,   558,     0,     0,   554,   555,   556,     0,     0,
       0,   802,     0,   657,   654,   660,   659,   658,   800,   801,
     689,     0,     0,     0,   684,   681,   687,   686,   685,     0,
     432,   747,     0,     0,   333,     0,   353,   428,     0,     0,
       0,   390,   592,   617,     0,     0,   688,   390,   390,     0,
     760,   761,   351,   422,   560,   564,   562,   565,     0,     0,
     661,   803,     0,     0,   436,     0,     0,   566,   753,   768,
     770,   769,   390,     0,   563,     0,     0,   767,   567
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   699,   700,   866,   867,   985,   984,   697,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   711,   877,   878,   879,   990,  1099,   709,
     158,   159,   259,   260,   419,   418,   583,   584,   715,   882,
     883,   884,   994,  1104,   714,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     694,   695,   852,   842,   125,   126,   235,   341,   342,   343,
     691,   557,   692,   693,   838,   839,   964,   960,   232,   233,
     336,   553,   554,   555,   835,   687,   836,   837,   956,   957,
    1072,  1070,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   676,   827,   947,   948,  1062,  1146,  1147,
    1148,  1149,  1150,  1215,  1216,  1217,  1383,  1426,  1065,  1151,
    1224,  1225,  1226,  1227,  1228,  1302,  1303,  1304,  1428,  1486,
    1153,  1229,  1311,  1312,  1313,  1314,  1392,  1393,  1394,  1488,
    1523,   122,   123,   542,   331,   543,  1315,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     632,   853,   854,   965,   855,   856,   967,  1076,   857,   858,
     968,   224,  1041,   225,   326,   991,   992,  1101,  1102,  1176,
    1177,  1241,  1239,   993,  1173,  1174,  1175,  1400,  1401,  1439,
    1440,  1496,  1527,  1402,  1493,  1494,  1495,  1415,  1416,  1465,
    1466,  1512,  1560,    98,    99,   160,   161,   274,   263,   264,
     265,   424,   425,   426,   587,   588,   764,   753,   586,   728,
     729,   730,   885,   886,  1000,  1106,  1179,  1107,  1108,  1184,
    1185,  1186,  1254,  1180,  1181,  1250,  1251,  1252,  1328,  1246,
    1247,  1324,  1325,  1326,  1403,   731,   732,   887,   888,  1006,
    1112,  1190,  1257,  1258,  1332,  1333,  1334,  1406,   733,   734,
     889,   890,  1010,  1114,  1192,  1261,  1262,  1337,  1338,  1339,
    1407,  1408,  1445,  1446,  1498,  1499,  1535,  1530,  1531,  1532,
    1569,  1586,  1587,  1596,  1604,   735,   736,   891,   892,  1014,
    1116,  1194,  1265,  1266,  1342,  1343,  1344,  1409,  1449,  1450,
    1502,  1503,  1504,   737,   738,   893,   894,  1018,  1118,  1196,
    1269,  1270,  1347,  1348,  1349,  1410,  1453,  1454,  1507,  1508,
    1509,   739,   740,   895,   896,  1022,  1120,  1198,  1273,  1274,
    1352,  1353,  1354,  1412,   741,   742,   897,   898,  1026,  1122,
    1200,  1277,  1278,  1357,  1358,  1359,  1413,  1458,  1459,  1510,
    1543,  1544,   743,   744,   899,   900,  1030,  1124,  1202,  1281,
    1282,  1362,  1363,  1364,  1414,  1462,  1463,  1511,  1554,  1555,
     745,   746,   901,   902,  1034,  1126,  1204,  1285,  1286,  1367,
    1368,  1369,  1417,   747,   748,   903,  1206,   749,   750,   906,
    1040,  1372,  1130,  1131,  1211,  1293,  1294,  1295,  1381,  1209,
    1210,  1289,  1377,  1378,  1379,  1421,  1288,  1373,  1374,  1418,
    1419,  1475,  1470,  1471,  1472,   907,   275,   712,   276,  1001,
    1536,  1097,   765,   766,   767,   768,   769,  1476,  1477,   105,
    1242,   861,   770,   771,  1597,  1537,  1557,  1558,   772,   773,
     774,   775,   277,   278,   279,  1002,  1003,  1004,   106,   107,
     108,   280,   281,   282,   283,   284,   285,   525,   526,   527,
    1547,  1548,  1549,   863,   864,   865,     7,     8,    15,    25,
      46,    47,    67,    68,   109,   189,   190,   305,   453,   191,
     306,   456,   192,   307,   193,   287,   194,   288,   195,   295,
     196,   289,   197,   286,   198,   290,   199,   291,   200,   297,
     201,   298,   202,   299,   203,   294,   204,   205,   518,   206,
     301,   207,   296,   208,   308,   209,   309,   210,   310,   211,
     212,   528,   313,   529,   530,   822,   213,   300,   614,   919,
     446,   615,   616,   617,   214,   292,   438,   215,   303,   449,
     216,   302,   448,   217,   304,   450,   218,   293,   439,   477,
     478,   479,   793,   480,   481,   797,   634,   482,   483,   801,
     636,   484,   485,   805,   638,   486,   487,   640,   488,   489,
     642,   490,   491,   644,   492,   493,   646,   494,   495,   648,
     936,   496,   497,   650,   938,   649,   498,   499,   654,   500,
     501,   656,   502,   503,   658,   504,   505,   660,   506,   507,
     662,   508,   628,   788,   509,   510,   664,   511,   512,   666,
     513,   514,   668,   333,   334,   548,   549,   683,   684,   685,
     831,   954,   955,  1066,  1067,  1157
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -854
static const yytype_int16 yypact[] =
{
      15,  -854,   111,  -175,   121,  -854,  -854,   -64,  -169,   135,
    -854,  -854,    99,     1,   165,  -854,   188,    64,  -854,   -51,
     183,   196,    67,  -854,   201,  -236,   204,  -854,  -854,  -854,
    -854,  -854,   146,   107,   224,   137,  -854,   230,  -854,  -854,
    -854,  -854,  -854,   234,  -854,  -854,  -854,  -854,   238,    38,
    -854,   120,   175,  -854,   -11,  -854,  -854,  -854,   245,  -854,
    -854,  -854,  -854,  -854,   256,    -2,   242,   258,   -25,  -854,
    -854,   222,   263,   276,   291,   293,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   264,  -854,   133,  -854,  -854,  -854,
    -854,    56,   130,   305,   218,  -854,  -854,  -854,  -854,  -854,
    -854,   605,  -854,   312,   311,  -854,  -854,  -854,  -854,  -854,
    -854,   315,   317,   319,  -854,  -854,  -854,  -854,  -854,  -854,
     250,   313,   259,   262,  -854,    83,   170,   344,   208,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     280,   243,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,    42,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   605,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   348,
     361,   370,   397,   399,   406,    36,  -854,   410,  -854,  -854,
    -854,  -854,    82,   283,   414,   286,  -854,   423,  -854,  -854,
    -854,  -854,  -854,   321,    -8,   323,    -8,   328,    -8,   336,
      48,   353,   227,   355,   128,   360,    23,   444,    -8,   453,
      -8,  -854,   260,  -854,  -854,  -854,  -854,   463,  -854,   467,
    -854,   469,   468,   472,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   605,   605,   605,   605,
     605,   605,  -854,  -854,   605,   605,   605,   605,   605,   605,
    -854,   605,  -854,  -854,  -854,   362,   377,   605,    86,    86,
      86,  -854,   132,    34,  -854,   478,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   493,   409,  -854,
     424,    95,  -854,   261,   192,   503,   379,  -854,   507,  -854,
    -854,  -854,  -854,  -854,   509,   141,  -854,   466,  -854,  -854,
    -854,  -854,  -854,  -854,   439,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   464,  -854,
     535,  -854,  -854,  -854,  -854,  -854,  -854,   488,  -854,   539,
     541,   543,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     498,  -854,   545,   576,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   480,  -854,   556,  -854,  -854,  -854,  -854,
    -854,   527,  -854,  -854,  -854,  -854,  -854,   547,  -854,  -854,
    -854,  -854,  -854,  -854,   417,  -854,  -854,   607,   614,   616,
     620,   621,   605,   605,   605,   605,   298,   299,   187,   421,
     292,   294,   605,   288,   287,   289,    49,   281,   440,   494,
     533,  -854,   274,  -854,  -854,   275,  -854,   605,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   268,  -854,    12,
    -854,   445,  -854,   446,  -854,   447,  -854,    86,  -854,    86,
    -854,   605,  -854,    86,  -854,   232,  -854,   232,  -854,   387,
    -854,    86,  -854,    86,  -854,    86,  -854,    86,  -854,  -854,
     605,  -854,   605,  -854,    86,   269,   271,  -854,  -854,  -854,
     278,  -854,   644,   645,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -286,  -286,   641,  -854,  -854,   518,  -854,   571,
     647,   648,  -854,  -854,  -854,  -854,  -854,   649,   416,  -854,
     652,  -854,  -854,  -854,  -854,  -854,   651,   176,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   608,   590,  -854,   656,
    -854,  -854,   657,   658,  -854,   659,   660,  -854,   661,  -854,
     604,   531,  -854,   603,   531,  -854,   -89,   427,   197,  -854,
    -854,  -854,   662,   663,   350,   349,   351,   346,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   605,  -854,  -854,  -854,
    -854,   574,   667,   668,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   314,  -854,  -854,
     670,   671,   430,   673,   432,   674,   435,   675,   441,   308,
    -854,    86,  -854,   282,  -854,   279,  -854,   684,   677,  -854,
     678,  -854,  -854,   306,  -854,    86,  -854,   303,  -854,    86,
    -854,    86,  -854,    86,  -854,   605,  -854,   297,  -854,  -854,
    -854,  -854,   685,  -854,   681,   691,   443,  -854,  -854,  -854,
     692,  -854,  -854,  -854,  -854,  -854,   693,   200,  -854,  -854,
    -854,  -854,  -854,  -854,   482,    74,  -854,  -854,  -854,  -854,
    -854,   694,   695,   696,   697,   698,   699,  -854,  -854,  -854,
     700,   484,  -854,  -854,  -854,   486,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   363,  -854,
     534,  -854,   502,  -854,  -854,   707,   703,   704,   705,   706,
     708,   709,   712,   713,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,   358,  -854,  -854,   716,  -854,  -854,   -77,   717,
     718,  -854,   324,  -854,   719,  -854,   475,  -854,   722,  -854,
     459,  -854,   723,  -854,   470,  -854,  -854,   354,  -854,  -854,
     725,    86,    86,  -854,   357,  -854,   345,   342,   341,   605,
    -854,  -854,   731,  -854,   732,  -854,   474,  -854,   733,   739,
     741,  -185,  -854,  -854,  -854,  -854,  -854,  -854,   492,    89,
    -854,   499,  -854,   745,   751,   790,   792,   794,   796,  -854,
     803,   800,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   551,   -62,  -854,  -854,
    -854,  -854,  -854,  -854,   804,  -854,   702,  -854,  -854,  -854,
    -854,   702,  -854,  -854,  -854,   801,   -74,   805,   -74,   807,
     -74,   809,   -74,   813,   -74,   815,   -74,   817,   -74,   819,
     -74,   821,   -74,   823,  -854,   806,   825,  -854,  -854,  -854,
     832,   834,   836,   838,   840,   844,   863,  -854,  -854,   521,
     865,   867,  -854,  -854,   869,   871,  -854,   873,  -854,   875,
    -854,   877,  -854,  -854,  -854,   511,  -854,   505,  -854,  -854,
    -854,  -854,  -854,   605,  -854,  -854,  -854,   808,   653,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   553,   126,  -854,   654,
    -854,   900,   904,   906,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   912,   914,   916,   943,   945,   947,
     951,   949,  -854,   890,  -854,  -854,  -854,  -854,   955,   765,
     894,  -854,   857,  -854,   896,  -854,   736,  -854,   972,   969,
    -854,  -854,  -854,  -854,  -854,   736,  -854,  -854,  -854,   736,
    -854,  -854,  -854,   736,  -854,  -854,  -854,   736,  -854,  -854,
    -854,   736,  -854,  -854,  -854,   736,  -854,  -854,  -854,   736,
    -854,  -854,  -854,   736,  -854,  -854,  -854,    86,   973,   767,
    -854,  -854,    22,   974,   975,   976,   977,   978,   979,   980,
     981,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,    86,    40,  -854,  -854,   714,   982,   -25,  -854,   730,
    -854,   983,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   986,   988,   989,   990,   991,   992,   993,
     995,   996,  -854,   997,  -854,  -854,   998,   555,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   757,   557,   999,
    1004,   757,  -854,   757,  -854,   757,  -854,   757,  -854,   757,
    -854,   757,  -854,   757,  -854,   757,  -854,   766,  1003,  -854,
     782,   531,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   615,  -854,   742,  1007,  1008,  -854,  -854,  -854,  -854,
    -854,    43,  -854,  -854,    86,  -854,  -854,  -854,  -854,  1011,
    1010,  1012,  1013,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    1016,  -854,    63,  -854,  -854,  -854,  1014,   371,  -854,   799,
     783,   561,  -854,   702,  -854,  -854,  -854,  -854,  1015,   785,
     810,   786,   802,   788,   798,   791,   797,   795,   811,   812,
     814,   816,   818,   820,   822,  -854,  -854,  -854,  -854,  -854,
     531,   564,  -854,  -854,  -854,   763,  -854,   768,  1032,  1033,
    -854,   779,  1036,  1037,  -854,  -854,  -854,  -854,  -854,    58,
     729,  1039,  -854,  -854,  -854,  1040,   928,  -854,  1044,  -854,
    1043,  -854,  -854,  -854,  -854,  -854,  -854,   566,  -854,   702,
    -854,  -854,  -854,  -854,   824,  -854,  -854,  -854,   568,  -854,
    -854,  -854,   570,  -854,  -854,  -854,   572,  -854,  -854,  -854,
     575,  -854,  -854,  -854,   577,  -854,  -854,  -854,   579,  -854,
    -854,  -854,   581,  -854,  -854,  -854,   583,  -854,   385,   587,
    -854,  -854,   702,  -854,  -854,  -854,  -854,  -854,   855,  1046,
    1047,  -854,   826,  -854,   827,  1050,  1053,  -854,   828,  1052,
    1055,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     952,  1058,  -854,   946,  -854,  -854,  -854,  -854,   829,  -854,
    -854,   702,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   702,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   702,  -854,  -854,  -854,
    -854,   853,  1060,   592,  -854,  -854,  -854,  -854,   874,  1062,
    1064,  -854,   830,  -854,   835,  1067,  1068,  -854,  1069,   765,
    -854,   963,  -854,   837,  -854,  -854,   839,   841,   964,   -65,
     -54,  -854,   842,   -50,   -49,  -854,   966,   843,   594,   209,
    -854,   864,  -854,  1076,  -854,   831,  -854,  1078,   596,  -854,
    -854,  -854,  -854,   892,  1079,  1083,  -854,   598,  -854,  -854,
     893,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     600,  -854,  -854,  -854,   602,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   893,  -854,  -854,   260,
    -854,  -854,  -854,  1085,  1086,  -854,  -854,  -854,  -854,  -854,
    -854,  1087,  -854,  1091,  -854,   846,  -854,  1094,   606,  -854,
    -854,  -854,    70,  -854,  -854,  -854,  1088,  -854,   609,   -98,
    -854,   605,  -854,  -854,  -854,  -854,   605,  -854,  -854,  -854,
      27,    55,  1092,  -854,   897,  1098,  1099,  -854,  1102,  -854,
    1100,  -854,   845,  -854,   994,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  1104,  1105,  -854,  -854,  -854,  1001,  1005,
    1110,  -854,  1114,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  1006,  1112,  1113,  -854,  -854,  -854,  -854,  -854,  1118,
    -854,  -854,  1115,  1116,  -854,  1117,  -854,  -854,  1017,   -43,
    1120,  -854,  -854,  -854,  1018,  1119,  -854,  -854,  -854,  1019,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   927,  1121,  1125,
    -854,  -854,  1126,  1127,  -854,  1128,  1129,  -854,  -854,  -854,
    -854,  -854,  -854,  1131,  -854,  1130,   895,  -854,  -854
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   833,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   -73,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -161,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -249,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   891,   898,  -854,  -854,  -854,  -854,
    -854,   189,   190,  -854,  -793,  -854,  -854,  -854,   191,   193,
    -854,  -569,  -854,  -280,  -854,  -853,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -325,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -601,  -854,  -854,
    -854,  -854,  -854,  -836,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -239,  -558,  -238,  -477,
    -854,  -250,  -854,  -854,  -854,  -854,  -854,  -854,  -854,    84,
    -357,  -815,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -221,  -854,  -854,  -363,  -854,  -854,  -716,  -854,
    -854,  -265,  -854,  -854,  -312,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -205,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -306,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   665,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854
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
     415,   420,   421,   352,   971,   359,   716,   366,   995,   375,
    1132,   388,   904,   401,   630,   410,   405,   416,  1540,   422,
     532,   533,   320,   321,   519,   520,   966,  1447,    70,    71,
    1142,  1143,   986,  1220,  1221,    72,    73,     1,  1451,   610,
     611,  1144,  1456,  1460,  1222,  1550,  1551,  1236,  1307,  1308,
    1584,   268,   269,    44,  1524,    45,   370,    38,    39,  1309,
    1533,   432,   433,   434,   435,   436,   437,   997,   998,   440,
     441,   442,   443,   444,   445,   999,   447,   843,   844,   845,
     846,   847,   457,   848,  1534,   538,   539,    27,    28,   828,
     829,     5,   102,   103,   540,   541,   847,    53,    54,   961,
     717,   962,   963,   266,   267,   322,   323,   324,   325,   952,
     718,   953,   719,     6,   720,     9,   721,   851,   722,    11,
     723,    14,   724,    16,   725,    18,   726,    59,    60,   843,
     844,   845,   846,   847,   266,   267,   727,  1071,   272,   273,
      82,    83,   379,   380,  1075,   392,   393,   268,   269,    21,
    1541,  1542,   104,    24,   458,   521,   522,  1448,   459,   266,
     267,   639,   460,   641,  1237,    85,    86,   645,  1452,   272,
     273,  1525,  1457,  1461,    26,   655,    31,   657,    34,   659,
    1585,   661,    96,    97,    37,   266,   267,    43,   667,   631,
     118,   119,    48,  1223,   272,   273,  1145,   921,   238,   239,
     266,   267,    50,   849,   850,  1240,   851,   594,   595,   596,
     597,  1310,    58,   601,   603,    74,    64,   606,    90,    75,
     272,   273,    66,   620,   622,   624,   612,  1552,  1553,    69,
     613,    93,   627,   100,   851,   272,   273,   266,   267,   266,
     267,   379,   380,   381,    95,   131,   132,   110,   133,   101,
     134,   111,   135,   851,   136,  1189,   137,  1191,   138,  1193,
     139,  1195,   140,  1197,   112,  1199,   643,  1201,   851,  1203,
     261,   262,   272,   273,   272,   273,   339,   340,   461,   113,
     462,   114,   463,   115,   464,   663,   465,   665,   466,   124,
     467,   127,   468,   130,   469,   219,   470,   922,   471,   220,
     472,   221,   473,   222,   474,   223,   475,   226,   476,   227,
    1253,   346,   347,   353,   354,   807,   229,   458,   360,   361,
     231,   459,   268,   269,   230,   460,   367,   368,  1050,   814,
     234,  1156,   237,   816,   311,   817,   314,   818,   266,   267,
     754,   755,  1243,   376,   377,   389,   390,   315,   270,   271,
     402,   403,   451,   452,   266,   267,   268,   269,   316,   756,
     757,   758,   759,   760,   761,   762,   763,   454,   455,   551,
     552,   559,   560,   272,   273,   332,  1327,   652,   653,  1473,
    1474,   782,   270,   271,  1111,   317,   784,   318,  1113,   272,
     273,  1007,  1115,  1011,   319,  1015,  1117,  1019,   327,  1023,
    1119,  1027,   338,  1031,  1121,  1035,   681,   682,  1123,   344,
     689,   690,  1125,   322,   323,   324,   325,   751,   752,  1380,
     791,   792,   795,   796,   523,   799,   800,   322,   323,   324,
     325,   803,   804,   825,   826,   411,   859,   860,   833,   834,
     819,   461,   335,   462,   417,   463,   427,   464,   423,   465,
     428,   466,   429,   467,   862,   468,   430,   469,  1405,   470,
     431,   471,   923,   472,   517,   473,   531,   474,   535,   475,
     565,   476,   840,   841,   875,   876,   880,   881,  1411,   534,
     102,   103,   958,   959,   537,   935,   937,   547,   162,   546,
     163,   550,   164,   556,   165,   564,   166,   558,   167,   568,
     168,   600,   169,  1420,   170,  1008,   171,  1012,   172,  1016,
     173,  1020,   174,  1024,   175,  1028,   176,  1032,   177,  1036,
     178,   577,   179,   569,   180,   570,   181,   571,   182,   572,
     183,   573,   184,   575,   185,   987,   186,   574,   187,   578,
     188,   982,   983,  1068,  1069,  1171,  1172,  1182,  1183,  1240,
     851,  1248,  1249,  1212,  1291,  1292,  1322,  1323,  1330,  1331,
    1335,  1336,  1340,  1341,   576,  1345,  1346,  1350,  1351,  1355,
    1356,  1360,  1361,  1365,  1366,  1370,  1371,  1375,  1376,   579,
     969,   970,  1424,  1425,  1468,  1469,  1484,  1485,  1491,  1492,
    1500,  1501,  1505,  1506,   943,   589,  1521,  1522,   972,  1528,
    1529,   582,   590,   585,   591,  1497,   592,   593,   598,  1042,
     604,   599,   607,   608,   605,   618,   625,   609,   629,   626,
     647,   669,   633,   635,   637,   670,   671,   672,   673,   674,
     675,  1513,  1290,   710,   677,   678,   679,   680,   686,   688,
     698,   696,   701,   703,   704,   705,   706,   708,   713,   707,
     776,   777,   778,   779,   781,   785,   786,   780,   789,   790,
     787,   794,   798,   802,   806,   809,   808,   810,   811,   812,
     813,   815,   823,   821,   824,  1546,  1556,   820,   830,   905,
     918,   832,   868,   869,   870,   871,   872,   873,   874,   908,
     909,   910,   911,   912,   913,   930,   914,   915,  1079,  1080,
     916,   917,   920,   924,   925,   927,   926,   928,   929,   931,
     932,  1127,   933,   934,   941,   940,  1081,   942,  1061,   944,
     945,   949,   162,   939,   163,   946,   164,   950,   165,   951,
     166,   973,   167,   974,   168,  1141,   169,   602,   170,   975,
     171,   162,   172,   163,   173,   164,   174,   165,   175,   166,
     176,   167,   177,   168,   178,   169,   179,   170,   180,   171,
     181,   172,   182,   173,   183,   174,   184,   175,   185,   176,
     186,   177,   187,   178,   188,   179,   619,   180,   976,   181,
     977,   182,   978,   183,   979,   184,   980,   185,   981,   186,
     988,   187,   996,   188,  1038,   162,  1005,   163,  1009,   164,
    1013,   165,   989,   166,  1017,   167,  1021,   168,  1025,   169,
    1029,   170,  1033,   171,  1037,   172,  1039,   173,  1043,   174,
    1044,   175,  1045,   176,  1046,   177,  1047,   178,  1230,   179,
    1048,   180,   621,   181,   162,   182,   163,   183,   164,   184,
     165,   185,   166,   186,   167,   187,   168,   188,   169,  1049,
     170,  1051,   171,  1052,   172,  1053,   173,  1054,   174,  1055,
     175,  1056,   176,  1057,   177,  1058,   178,  1060,   179,  1063,
     180,  1059,   181,   623,   182,   162,   183,   163,   184,   164,
     185,   165,   186,   166,   187,   167,   188,   168,  1083,   169,
    1082,   170,  1084,   171,  1085,   172,  1064,   173,  1086,   174,
    1087,   175,  1088,   176,   783,   177,   162,   178,   163,   179,
     164,   180,   165,   181,   166,   182,   167,   183,   168,   184,
     169,   185,   170,   186,   171,   187,   172,   188,   173,  1089,
     174,  1090,   175,  1091,   176,  1093,   177,  1568,   178,  1092,
     179,  1094,   180,  1095,   181,  1096,   182,  1098,   183,  1100,
     184,  1103,   185,  1105,   186,  1109,   187,  1110,   188,  1128,
    1129,  1152,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,
    1158,  1159,  1160,  1154,  1161,  1162,  1178,  1208,  1163,  1164,
    1165,  1166,  1589,  1167,  1168,  1169,  1170,  1187,  1592,  1593,
    1188,  1207,  1205,  1213,  1214,  1218,  1219,  1231,  1232,  1244,
    1233,  1234,  1235,  1255,  1245,  1238,  1256,  1260,  1263,  1264,
    1267,  1271,  1268,  1605,  1259,  1296,  1272,  1298,  1299,  1300,
    1283,  1275,  1279,  1301,  1305,  1306,  1316,  1317,  1318,  1319,
    1320,  1321,  1382,  1276,  1384,  1385,  1389,  1280,  1287,  1390,
    1395,  1284,  1329,  1396,  1398,  1397,  1399,  1422,  1423,  1404,
    1429,  1427,  1430,  1434,  1435,  1438,  1444,  1436,  1464,  1441,
    1480,  1442,  1481,  1443,  1455,  1467,  1483,  1489,  1388,  1487,
    1386,  1490,   851,  1515,  1516,  1517,  1391,  1518,  1431,  1526,
    1433,  1482,  1520,  1559,  1562,  1563,  1565,  1479,  1519,  1561,
    1564,  1566,  1570,  1571,  1572,  1567,  1574,  1575,  1573,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1588,  1591,  1595,  1598,
    1583,  1590,  1594,  1599,  1600,  1601,  1602,  1606,  1607,  1608,
    1603,  1387,  1297,  1432,  1514,   395,  1073,  1074,  1077,  1437,
    1078,  1155,   396,  1545,  1478,     0,     0,     0,     0,     0,
       0,   536,   651,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,  1538,     0,     0,     0,
       0,  1539
};

static const yytype_int16 yycheck[] =
{
     205,   313,   571,   309,   310,   244,   244,   246,   246,   248,
     248,   250,   250,   252,   252,   254,   254,   256,   256,   258,
     258,   260,   260,   244,   839,   246,   584,   248,   881,   250,
       8,   252,   748,   254,    22,   256,    13,   258,    11,   260,
     320,   321,     6,     7,    10,    11,   839,   112,    10,    11,
      10,    11,   867,    10,    11,    17,    18,    42,   112,    10,
      11,    21,   112,   112,    21,    10,    11,     4,    10,    11,
     113,   133,   134,   309,     4,   311,    28,    10,    11,    21,
     178,   286,   287,   288,   289,   290,   291,   161,   162,   294,
     295,   296,   297,   298,   299,   169,   301,    23,    24,    25,
      26,    27,   307,    29,   202,    10,    11,    43,    44,   678,
     679,     0,   137,   138,    19,    20,    27,    10,    11,    30,
     209,    32,    33,   131,   132,   411,   412,   413,   414,   314,
     219,   316,   221,   308,   223,    14,   225,   199,   227,   203,
     229,   310,   231,     8,   233,    46,   235,    10,    11,    23,
      24,    25,    26,    27,   131,   132,   245,    31,   166,   167,
      40,    41,    34,    35,   957,    37,    38,   133,   134,   168,
     143,   144,   197,     8,   251,   141,   142,   242,   255,   131,
     132,   487,   259,   489,   121,    10,    11,   493,   242,   166,
     167,   121,   242,   242,     6,   501,   247,   503,    15,   505,
     243,   507,   204,   205,     8,   131,   132,     6,   514,   197,
      77,    78,     8,   170,   166,   167,   176,   786,    10,    11,
     131,   132,    76,   149,   150,   198,   199,   432,   433,   434,
     435,   173,     8,   438,   439,   197,     6,   442,   249,   201,
     166,   167,     8,   448,   449,   450,   197,   192,   193,    11,
     201,     6,   457,    11,   199,   166,   167,   131,   132,   131,
     132,    34,    35,    36,     8,    47,    48,    45,    50,    11,
      52,     8,    54,   199,    56,  1111,    58,  1113,    60,  1115,
      62,  1117,    64,  1119,     8,  1121,   491,  1123,   199,  1125,
      10,    11,   166,   167,   166,   167,    10,    11,   375,     8,
     377,     8,   379,    39,   381,   510,   383,   512,   385,   253,
     387,   181,   389,     8,   391,     3,   393,   394,   395,     8,
     397,     6,   399,     6,   401,     6,   403,    77,   405,    16,
    1183,    10,    11,    10,    11,   641,    77,   251,    10,    11,
     257,   255,   133,   134,    82,   259,    10,    11,   917,   655,
     180,  1067,     8,   659,   312,   661,     8,   663,   131,   132,
     163,   164,  1177,    10,    11,    10,    11,     6,   159,   160,
      10,    11,    10,    11,   131,   132,   133,   134,     8,   182,
     183,   184,   185,   186,   187,   188,   189,    10,    11,    10,
      11,   250,   251,   166,   167,   313,  1249,    10,    11,   190,
     191,   606,   159,   160,  1005,     8,   611,     8,  1009,   166,
     167,   888,  1013,   890,     8,   892,  1017,   894,     8,   896,
    1021,   898,     8,   900,  1025,   902,    10,    11,  1029,     6,
     254,   255,  1033,   411,   412,   413,   414,    10,    11,  1292,
      10,    11,    10,    11,   410,    10,    11,   411,   412,   413,
     414,    10,    11,    10,    11,    11,   695,   695,   258,   259,
     665,   375,   179,   377,    11,   379,     3,   381,   208,   383,
       3,   385,     3,   387,   695,   389,     8,   391,  1331,   393,
       8,   395,   788,   397,   352,   399,     8,   401,    79,   403,
      51,   405,    10,    11,    10,    11,    10,    11,  1351,     6,
     137,   138,    10,    11,    80,   811,   812,   315,   321,   248,
     323,     8,   325,     6,   327,    49,   329,     8,   331,    55,
     333,   334,   335,  1376,   337,   888,   339,   890,   341,   892,
     343,   894,   345,   896,   347,   898,   349,   900,   351,   902,
     353,    61,   355,     8,   357,    57,   359,     8,   361,     8,
     363,     8,   365,     8,   367,   867,   369,    59,   371,     3,
     373,    10,    11,    10,    11,    10,    11,    10,    11,   198,
     199,    10,    11,  1131,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     8,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   210,   211,    10,    11,    72,
     839,   839,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   819,     8,    10,    11,   839,    10,
      11,    74,     8,   206,     8,  1440,     6,     6,   330,   909,
     338,   332,   344,   346,   340,   354,   362,   348,   370,   364,
     408,   372,   197,   197,   197,   374,   368,     3,     3,     8,
     132,  1466,  1210,   122,    83,     8,     8,     8,     6,     8,
      70,    53,     6,     6,     6,     6,     6,    63,    65,     8,
       8,     8,   322,   324,   328,     8,     8,   326,     8,     8,
     366,     8,     8,     8,   376,   406,   404,     3,    11,    11,
     384,   388,    11,     8,     3,  1510,  1511,   400,     6,   165,
     342,     8,     8,     8,     8,     8,     8,     8,     8,   207,
       3,     8,     8,     8,     8,   256,     8,     8,   957,   957,
       8,     8,     6,     6,     6,     6,   402,   252,     6,     6,
     260,  1037,   378,     8,   392,   390,   957,   396,   943,     8,
       8,     8,   321,   386,   323,   271,   325,     8,   327,     8,
     329,   252,   331,     8,   333,  1061,   335,   336,   337,     8,
     339,   321,   341,   323,   343,   325,   345,   327,   347,   329,
     349,   331,   351,   333,   353,   335,   355,   337,   357,   339,
     359,   341,   361,   343,   363,   345,   365,   347,   367,   349,
     369,   351,   371,   353,   373,   355,   356,   357,     8,   359,
       8,   361,     8,   363,     8,   365,     3,   367,     8,   369,
       6,   371,    11,   373,     8,   321,    11,   323,    11,   325,
      11,   327,   120,   329,    11,   331,    11,   333,    11,   335,
      11,   337,    11,   339,    11,   341,    11,   343,     6,   345,
       6,   347,     6,   349,     6,   351,     6,   353,  1154,   355,
       6,   357,   358,   359,   321,   361,   323,   363,   325,   365,
     327,   367,   329,   369,   331,   371,   333,   373,   335,     6,
     337,   350,   339,     8,   341,     8,   343,     8,   345,     8,
     347,     8,   349,     8,   351,     8,   353,   382,   355,    81,
     357,   380,   359,   360,   361,   321,   363,   323,   365,   325,
     367,   327,   369,   329,   371,   331,   373,   333,     8,   335,
     256,   337,     8,   339,     8,   341,   263,   343,     6,   345,
       6,   347,     6,   349,   350,   351,   321,   353,   323,   355,
     325,   357,   327,   359,   329,   361,   331,   363,   333,   365,
     335,   367,   337,   369,   339,   371,   341,   373,   343,     6,
     345,     6,   347,     6,   349,     6,   351,  1526,   353,     8,
     355,    71,   357,     8,   359,   200,   361,    73,   363,   112,
     365,    75,   367,   237,   369,     3,   371,     8,   373,     6,
     213,   267,     8,     8,     8,     8,     8,     8,     8,     8,
     260,     8,     6,    11,     6,     6,   239,   215,     8,     8,
       8,     8,  1571,     8,     8,     8,     8,     8,  1577,  1578,
       6,     8,   246,   398,   272,     8,     8,     6,     8,   220,
       8,     8,     6,     8,   241,    11,   241,   241,   226,   241,
     232,   234,   241,  1602,   224,   272,   241,   269,     6,     6,
     222,   230,   228,   264,     8,     8,   317,     8,     8,   121,
       6,     8,   197,   241,     8,     8,     6,   241,   236,     6,
       8,   241,   238,     8,     6,   113,   120,   214,     8,   240,
       8,   197,     8,     6,     6,   112,   112,     8,   112,   242,
     216,   242,     6,   242,   242,   242,     8,     8,   261,   197,
     264,     8,   199,     8,     8,     8,   268,     6,   268,    11,
     265,   270,     8,    11,     6,     6,     6,  1419,   262,   212,
       8,   266,     8,     8,   113,   121,     6,     3,   113,   113,
       8,     8,     4,     8,     8,     8,     6,     8,   201,     8,
     113,   113,   113,     8,     8,     8,     8,     6,     8,   244,
      11,  1302,  1215,  1392,  1469,   254,   957,   957,   957,  1399,
     957,  1067,   254,  1510,  1419,    -1,    -1,    -1,    -1,    -1,
      -1,   328,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,
      -1,  1506
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    42,   416,   420,   421,     0,   308,   951,   952,    14,
     422,   203,   433,   434,   310,   953,     8,   423,    46,   440,
     441,   168,   435,   634,     8,   954,     6,    43,    44,   424,
     425,   247,   530,   531,    15,   442,   635,     8,    10,    11,
     436,   437,   438,     6,   309,   311,   955,   956,     8,   427,
      76,   577,   578,    10,    11,   532,   533,   534,     8,    10,
      11,   443,   444,   445,     6,   439,     8,   957,   958,    11,
      10,    11,    17,    18,   197,   201,   426,   428,   429,   430,
     431,   432,    40,    41,   417,    10,    11,   579,   580,   581,
     249,   535,   536,     6,   446,     8,   204,   205,   688,   689,
      11,    11,   137,   138,   197,   914,   933,   934,   935,   959,
      45,     8,     8,     8,     8,    39,   418,   419,    77,    78,
     582,   583,   626,   627,   253,   549,   550,   181,   537,   636,
       8,    47,    48,    50,    52,    54,    56,    58,    60,    62,
      64,   447,   448,   449,   454,   455,   460,   461,   475,   476,
     482,   483,   488,   489,   494,   495,   500,   501,   515,   516,
     690,   691,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   960,
     961,   964,   967,   969,   971,   973,   975,   977,   979,   981,
     983,   985,   987,   989,   991,   992,   994,   996,   998,  1000,
    1002,  1004,  1005,  1011,  1019,  1022,  1025,  1028,  1031,     3,
       8,     6,     6,     6,   656,   658,    77,    16,   584,    77,
      82,   257,   563,   564,   180,   551,   637,     8,    10,    11,
     538,   539,   540,   450,   451,   456,   457,   462,   463,   477,
     478,   484,   485,   490,   491,   496,   497,   502,   503,   517,
     518,    10,    11,   693,   694,   695,   131,   132,   133,   134,
     159,   160,   166,   167,   692,   901,   903,   927,   928,   929,
     936,   937,   938,   939,   940,   941,   978,   970,   972,   976,
     980,   982,  1020,  1032,   990,   974,   997,   984,   986,   988,
    1012,   995,  1026,  1023,  1029,   962,   965,   968,   999,  1001,
    1003,   312,   960,  1007,     8,     6,     8,     8,     8,     8,
       6,     7,   411,   412,   413,   414,   659,     8,   585,   586,
     587,   629,   313,  1098,  1099,   179,   565,   638,     8,    10,
      11,   552,   553,   554,     6,   542,    10,    11,   453,   452,
     901,   903,   927,    10,    11,   459,   458,   901,   903,   927,
      10,    11,   465,   464,   901,   903,   927,    10,    11,   481,
      28,   479,   480,   901,   903,   927,    10,    11,   487,    34,
      35,    36,   486,   639,   640,   641,   901,   903,   927,    10,
      11,   493,    37,    38,   492,   639,   640,   642,   643,   901,
     903,   927,    10,    11,   499,    13,   498,   644,   901,   903,
     927,    11,   505,   504,   901,   903,   927,    11,   520,   519,
     901,   903,   927,   208,   696,   697,   698,     3,     3,     3,
       8,     8,   960,   960,   960,   960,   960,   960,  1021,  1033,
     960,   960,   960,   960,   960,   960,  1015,   960,  1027,  1024,
    1030,    10,    11,   963,    10,    11,   966,   960,   251,   255,
     259,   375,   377,   379,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,  1034,  1035,  1036,
    1038,  1039,  1042,  1043,  1046,  1047,  1050,  1051,  1053,  1054,
    1056,  1057,  1059,  1060,  1062,  1063,  1066,  1067,  1071,  1072,
    1074,  1075,  1077,  1078,  1080,  1081,  1083,  1084,  1086,  1089,
    1090,  1092,  1093,  1095,  1096,  1034,  1034,   352,   993,    10,
      11,   141,   142,   410,   939,   942,   943,   944,  1006,  1008,
    1009,     8,   658,   658,     6,    79,   586,    80,    10,    11,
      19,    20,   628,   630,   632,   633,   248,   315,  1100,  1101,
       8,    10,    11,   566,   567,   568,     6,   556,     8,   250,
     251,   541,   543,   544,    49,    51,   466,   467,    55,     8,
      57,     8,     8,     8,    59,     8,     8,    61,     3,    72,
     506,   507,    74,   521,   522,   206,   703,   699,   700,     8,
       8,     8,     6,     6,   960,   960,   960,   960,   330,   332,
     334,   960,   336,   960,   338,   340,   960,   344,   346,   348,
      10,    11,   197,   201,  1013,  1016,  1017,  1018,   354,   356,
     960,   358,   960,   360,   960,   362,   364,   960,  1087,   370,
      22,   197,   645,   197,  1041,   197,  1045,   197,  1049,  1034,
    1052,  1034,  1055,   960,  1058,  1034,  1061,   408,  1064,  1070,
    1068,  1070,    10,    11,  1073,  1034,  1076,  1034,  1079,  1034,
    1082,  1034,  1085,   960,  1091,   960,  1094,  1034,  1097,   372,
     374,   368,     3,     3,     8,   132,   588,    83,     8,     8,
       8,    10,    11,  1102,  1103,  1104,     6,   570,     8,   254,
     255,   555,   557,   558,   545,   546,    53,   474,    70,   468,
     469,     6,   656,     6,     6,     6,     6,     8,    63,   514,
     122,   508,   902,    65,   529,   523,   902,   209,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   245,   704,   705,
     706,   730,   731,   743,   744,   770,   771,   788,   789,   806,
     807,   819,   820,   837,   838,   855,   856,   868,   869,   872,
     873,    10,    11,   702,   163,   164,   182,   183,   184,   185,
     186,   187,   188,   189,   701,   907,   908,   909,   910,   911,
     917,   918,   923,   924,   925,   926,     8,     8,   322,   324,
     326,   328,   960,   350,   960,     8,     8,   366,  1088,     8,
       8,    10,    11,  1037,     8,    10,    11,  1040,     8,    10,
      11,  1044,     8,    10,    11,  1048,   376,  1034,   404,   406,
       3,    11,    11,   384,  1034,   388,  1034,  1034,  1034,   960,
     400,     8,  1010,    11,     3,    10,    11,   589,   656,   656,
       6,  1105,     8,   258,   259,   569,   571,   572,   559,   560,
      10,    11,   548,    23,    24,    25,    26,    27,    29,   149,
     150,   199,   547,   646,   647,   649,   650,   653,   654,   901,
     903,   916,   927,   948,   949,   950,   470,   471,     8,     8,
       8,     8,     8,     8,     8,    10,    11,   509,   510,   511,
      10,    11,   524,   525,   526,   707,   708,   732,   733,   745,
     746,   772,   773,   790,   791,   808,   809,   821,   822,   839,
     840,   857,   858,   870,   933,   165,   874,   900,   207,     3,
       8,     8,     8,     8,     8,     8,     8,     8,   342,  1014,
       6,   656,   394,  1034,     6,     6,   402,     6,   252,     6,
     256,     6,   260,   378,     8,  1034,  1065,  1034,  1069,   386,
     390,   392,   396,   960,     8,     8,   271,   590,   591,     8,
       8,     8,   314,   316,  1106,  1107,   573,   574,    10,    11,
     562,    30,    32,    33,   561,   648,   649,   651,   655,   901,
     903,   916,   927,   252,     8,     8,     8,     8,     8,     8,
       3,     8,    10,    11,   473,   472,   916,   939,     6,   120,
     512,   660,   661,   668,   527,   660,    11,   161,   162,   169,
     709,   904,   930,   931,   932,    11,   734,   904,   930,    11,
     747,   904,   930,    11,   774,   904,   930,    11,   792,   904,
     930,    11,   810,   904,   930,    11,   823,   904,   930,    11,
     841,   904,   930,    11,   859,   904,   930,    11,     8,    11,
     875,   657,   658,     6,     6,     6,     6,     6,     6,     6,
     656,   350,     8,     8,     8,     8,     8,     8,     8,   380,
     382,   960,   592,    81,   263,   603,  1108,  1109,    10,    11,
     576,    31,   575,   646,   647,   649,   652,   653,   654,   901,
     903,   927,   256,     8,     8,     8,     6,     6,     6,     6,
       6,     6,     8,     6,    71,     8,   200,   906,    73,   513,
     112,   662,   663,    75,   528,   237,   710,   712,   713,     3,
       8,   712,   735,   712,   748,   712,   775,   712,   793,   712,
     811,   712,   824,   712,   842,   712,   860,  1034,     6,   213,
     877,   878,     8,     8,     8,     8,     8,     8,     8,     8,
       8,  1034,    10,    11,    21,   176,   593,   594,   595,   596,
     597,   604,   267,   615,    11,   914,   933,  1110,   260,     8,
       6,     6,     6,     8,     8,     8,     8,     8,     8,     8,
       8,    10,    11,   669,   670,   671,   664,   665,   239,   711,
     718,   719,    10,    11,   714,   715,   716,     8,     6,   718,
     736,   718,   749,   718,   776,   718,   794,   718,   812,   718,
     825,   718,   843,   718,   861,   246,   871,     8,   215,   884,
     885,   879,   902,   398,   272,   598,   599,   600,     8,     8,
      10,    11,    21,   170,   605,   606,   607,   608,   609,   616,
    1034,     6,     8,     8,     8,     6,     4,   121,    11,   667,
     198,   666,   915,   916,   220,   241,   724,   725,    10,    11,
     720,   721,   722,   660,   717,     8,   241,   737,   738,   224,
     241,   750,   751,   226,   241,   777,   778,   232,   241,   795,
     796,   234,   241,   813,   814,   230,   241,   826,   827,   228,
     241,   844,   845,   222,   241,   862,   863,   236,   891,   886,
     902,    10,    11,   880,   881,   882,   272,   599,   269,     6,
       6,   264,   610,   611,   612,     8,     8,    10,    11,    21,
     173,   617,   618,   619,   620,   631,   317,     8,     8,   121,
       6,     8,    10,    11,   726,   727,   728,   660,   723,   238,
      10,    11,   739,   740,   741,    10,    11,   752,   753,   754,
      10,    11,   779,   780,   781,    10,    11,   797,   798,   799,
      10,    11,   815,   816,   817,    10,    11,   828,   829,   830,
      10,    11,   846,   847,   848,    10,    11,   864,   865,   866,
     210,   211,   876,   892,   893,    10,    11,   887,   888,   889,
     660,   883,   197,   601,     8,     8,   264,   611,   261,     6,
       6,   268,   621,   622,   623,     8,     8,   113,     6,   120,
     672,   673,   678,   729,   240,   660,   742,   755,   756,   782,
     800,   660,   818,   831,   849,   682,   683,   867,   894,   895,
     660,   890,   214,     8,    10,    11,   602,   197,   613,     8,
       8,   268,   622,   265,     6,     6,     8,   906,   112,   674,
     675,   242,   242,   242,   112,   757,   758,   112,   242,   783,
     784,   112,   242,   801,   802,   242,   112,   242,   832,   833,
     112,   242,   850,   851,   112,   684,   685,   242,    10,    11,
     897,   898,   899,   190,   191,   896,   912,   913,   936,   939,
     216,     6,   270,     8,    10,    11,   614,   197,   624,     8,
       8,    10,    11,   679,   680,   681,   676,   916,   759,   760,
      10,    11,   785,   786,   787,    10,    11,   803,   804,   805,
     834,   852,   686,   916,   696,     8,     8,     8,     6,   262,
       8,    10,    11,   625,     4,   121,    11,   677,    10,    11,
     762,   763,   764,   178,   202,   761,   905,   920,   960,   960,
      11,   143,   144,   835,   836,   915,   916,   945,   946,   947,
      10,    11,   192,   193,   853,   854,   916,   921,   922,    11,
     687,   212,     6,     6,     8,     6,   266,   121,   656,   765,
       8,     8,   113,   113,     6,     3,   113,     8,     8,     4,
       8,     8,     8,   113,   113,   243,   766,   767,     6,   656,
     113,     8,   656,   656,   113,   201,   768,   919,     8,     8,
       8,     8,     8,    11,   769,   656,     6,     8,   244
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
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
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

  case 499:

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

  case 500:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 506:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 507:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 514:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 515:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 518:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 519:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 523:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 524:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 531:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 532:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 535:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 536:

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
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
    break;

  case 574:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 578:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 579:

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

  case 580:

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

  case 588:

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

  case 592:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 594:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 595:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 598:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType =
                ENUM_MATRIX_TYPE_complexValuedExpressions;
    }
    break;

  case 599:

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
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
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
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
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
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 641:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 645:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 646:

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

  case 647:

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

  case 655:

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

  case 661:

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

  case 663:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 664:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 667:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_complexConstant;
    }
    break;

  case 668:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 672:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 673:

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

  case 674:

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

  case 681:

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

  case 682:

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

  case 691:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 692:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 695:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_string;
    }
    break;

  case 696:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 700:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 701:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 708:

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

  case 710:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 711:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 712:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 713:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 714:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 716:

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

  case 717:

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

  case 718:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 719:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 725:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 726:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 727:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 734:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 735:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 736:

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

  case 742:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 743:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 747:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 748:

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

  case 749:

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

  case 750:

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

  case 751:

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

  case 752:

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

  case 753:

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

  case 754:

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

  case 755:

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

  case 756:

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

  case 757:

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

  case 758:

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

  case 759:

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

  case 760:

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

  case 761:

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

  case 762:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 763:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 764:

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

  case 765:

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

  case 766:

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

  case 767:

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

  case 768:

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

  case 769:

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

  case 770:

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

  case 771:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 774:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 775:

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

  case 778:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 779:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 782:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 783:

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

  case 786:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 787:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 790:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 791:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 794:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 795:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 798:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 799:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 802:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 803:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 806:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 807:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 809:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 810:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 811:

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

  case 814:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 815:

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

  case 816:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 819:

    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new RealValuedExpressionTree();
    }
    break;

  case 820:

    {
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape 
                = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
    }
    break;

  case 848:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 852:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 856:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 858:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 860:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 862:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 864:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 866:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 868:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 870:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 872:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 874:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 876:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 878:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 881:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
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
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 884:

    {
}
    break;

  case 885:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 886:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 887:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 889:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 891:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 893:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 894:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 899:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 900:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 902:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 904:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 905:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 908:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 912:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 913:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 914:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 915:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 916:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 917:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 919:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 920:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 921:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 923:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 924:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 925:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 927:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 928:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 929:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 931:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 932:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 933:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 935:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 955:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 956:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 959:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 960:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 961:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 964:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 965:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 966:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 969:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 970:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 971:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 974:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 976:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 979:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 982:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 985:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 988:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 990:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 993:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 995:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 997:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 999:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1003:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1006:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1009:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1012:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1014:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1015:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1017:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1019:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1022:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1025:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1028:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 1029:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }
    break;

  case 1031:

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

  case 1038:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }
    break;

  case 1039:

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

  case 1040:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 1043:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    break;

  case 1044:

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


