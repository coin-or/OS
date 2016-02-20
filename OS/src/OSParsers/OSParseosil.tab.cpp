
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
     COMPLEXCONJUGATESTART = 662,
     COMPLEXCONJUGATEEND = 663,
     COMPLEXMINUSSTART = 664,
     COMPLEXMINUSEND = 665,
     COMPLEXNEGATESTART = 666,
     COMPLEXNEGATEEND = 667,
     COMPLEXNUMBERSTART = 668,
     COMPLEXNUMBEREND = 669,
     COMPLEXPLUSSTART = 670,
     COMPLEXPLUSEND = 671,
     COMPLEXSQUARESTART = 672,
     COMPLEXSQUAREEND = 673,
     COMPLEXSUMSTART = 674,
     COMPLEXSUMEND = 675,
     COMPLEXTIMESSTART = 676,
     COMPLEXTIMESEND = 677,
     CREATECOMPLEXSTART = 678,
     CREATECOMPLEXEND = 679,
     EMPTYINCLUDEDIAGONALATT = 680,
     INCLUDEDIAGONALATT = 681,
     EMPTYIDATT = 682,
     IDATT = 683
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
#define COMPLEXCONJUGATESTART 662
#define COMPLEXCONJUGATEEND 663
#define COMPLEXMINUSSTART 664
#define COMPLEXMINUSEND 665
#define COMPLEXNEGATESTART 666
#define COMPLEXNEGATEEND 667
#define COMPLEXNUMBERSTART 668
#define COMPLEXNUMBEREND 669
#define COMPLEXPLUSSTART 670
#define COMPLEXPLUSEND 671
#define COMPLEXSQUARESTART 672
#define COMPLEXSQUAREEND 673
#define COMPLEXSUMSTART 674
#define COMPLEXSUMEND 675
#define COMPLEXTIMESSTART 676
#define COMPLEXTIMESEND 677
#define CREATECOMPLEXSTART 678
#define CREATECOMPLEXEND 679
#define EMPTYINCLUDEDIAGONALATT 680
#define INCLUDEDIAGONALATT 681
#define EMPTYIDATT 682
#define IDATT 683




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
#define YYLAST   1482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  433
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  728
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1085
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1683

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   683

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   430,
     432,     2,     2,   431,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   429,     2,     2,     2,     2,     2,     2,     2,
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
     425,   426,   427,   428
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
    2467,  2469,  2473,  2475,  2477,  2480,  2485,  2489,  2491,  2493,
    2496,  2501,  2505,  2507,  2509,  2512,  2517,  2521,  2523,  2525,
    2528,  2533,  2536,  2538,  2541,  2544,  2546,  2550,  2553,  2555,
    2558,  2561,  2563,  2566,  2571,  2573,  2574,  2576,  2579,  2584,
    2586,  2587,  2589,  2592,  2596,  2599,  2601,  2603,  2606,  2609,
    2611,  2615,  2618,  2620,  2623,  2626,  2628,  2632,  2635,  2637,
    2641,  2642,  2647,  2648,  2651,  2654,  2656,  2660,  2663,  2665,
    2672,  2675,  2677,  2680,  2681,  2685,  2687,  2689,  2694,  2696,
    2698,  2700,  2704,  2705,  2708,  2714,  2716,  2718,  2719,  2722,
    2724,  2726,  2728,  2730,  2732,  2734,  2736,  2738,  2740,  2742,
    2744,  2746,  2748,  2752,  2754,  2756,  2759,  2761,  2762,  2765,
    2767,  2769,  2773,  2775,  2779,  2783,  2785,  2789,  2790,  2796,
    2797,  2800,  2804,  2806,  2810,  2814,  2816,  2819,  2823,  2825,
    2828,  2832,  2834,  2838,  2842,  2844
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     434,     0,    -1,   438,   969,   451,   458,   548,   595,   435,
     436,    -1,    41,    -1,    40,    -1,   437,    -1,    39,    -1,
      -1,    -1,   439,   440,   441,    43,    -1,    42,    -1,    14,
       8,     6,     8,    11,    -1,    -1,   441,   442,    -1,   443,
     445,   444,    -1,    44,    -1,    10,    -1,    11,    45,    -1,
      -1,   445,   446,    -1,   447,    -1,   448,    -1,   449,    -1,
     450,    -1,    17,     8,     6,     8,    -1,    18,     8,     6,
       8,    -1,   201,     8,   674,     8,    -1,   197,     8,     6,
       8,    -1,    -1,   452,   453,   454,    -1,   203,    -1,   652,
      -1,   455,    -1,   456,    -1,    10,    -1,    11,   457,   204,
      -1,    -1,   457,   706,    -1,    -1,   459,   460,   461,    -1,
      46,    -1,   653,    -1,   462,    -1,   463,    -1,    10,    -1,
      11,   464,    47,    -1,    -1,   464,   465,    -1,   466,    -1,
     472,    -1,   478,    -1,   493,    -1,   500,    -1,   506,    -1,
     512,    -1,   518,    -1,   533,    -1,   467,   468,   471,    -1,
      48,    -1,   469,    -1,    -1,   469,   470,    -1,   921,    -1,
     919,    -1,   945,    -1,    10,    -1,    11,    49,    -1,   473,
     474,   477,    -1,    50,    -1,   475,    -1,    -1,   475,   476,
      -1,   921,    -1,   919,    -1,   945,    -1,    10,    -1,    11,
      51,    -1,   479,   480,   483,    -1,    52,    -1,   481,    -1,
      -1,   481,   482,    -1,   921,    -1,   919,    -1,   945,    -1,
      10,    -1,    11,   484,   492,    -1,   485,    -1,    -1,   485,
     486,    -1,   487,   488,   491,    -1,    70,    -1,   489,    -1,
      -1,   489,   490,    -1,   957,    -1,   934,    -1,    10,    -1,
      11,    71,    -1,    53,    -1,   494,   495,   499,    -1,    54,
      -1,   496,    -1,    -1,   496,   497,    -1,   921,    -1,   919,
      -1,   498,    -1,   945,    -1,    28,     8,     6,     8,    -1,
      10,    -1,    11,    55,    -1,   501,   502,   505,    -1,    56,
      -1,   503,    -1,    -1,   503,   504,    -1,   921,    -1,   919,
      -1,   945,    -1,   658,    -1,   657,    -1,   659,    -1,    10,
      -1,    11,    57,    -1,   507,   508,   511,    -1,    58,    -1,
     509,    -1,    -1,   509,   510,    -1,   921,    -1,   919,    -1,
     945,    -1,   658,    -1,   657,    -1,   660,    -1,   661,    -1,
      10,    -1,    11,    59,    -1,   513,   514,   517,    -1,    60,
      -1,   515,    -1,    -1,   515,   516,    -1,   921,    -1,   919,
      -1,   945,    -1,   662,    -1,    10,    -1,    11,    61,    -1,
     519,   520,   523,    -1,    62,    -1,   521,    -1,    -1,   521,
     522,    -1,   921,    -1,   919,    -1,   945,    -1,    11,   524,
     532,    -1,   525,   526,   527,    -1,    72,    -1,   920,    -1,
     528,    -1,   529,    -1,    10,    -1,    11,   530,   531,    -1,
     678,    -1,    73,    -1,    63,    -1,   534,   535,   538,    -1,
      64,    -1,   536,    -1,    -1,   536,   537,    -1,   921,    -1,
     919,    -1,   945,    -1,    11,   539,   547,    -1,   540,   541,
     542,    -1,    74,    -1,   920,    -1,   543,    -1,   544,    -1,
      10,    -1,    11,   545,   546,    -1,   678,    -1,    75,    -1,
      65,    -1,    -1,   549,   550,    -1,   247,    -1,   551,    -1,
     552,    -1,    10,    -1,    11,   553,   567,   581,  1116,   248,
      -1,    -1,   554,   555,   556,    -1,   249,    -1,   654,    -1,
     557,    -1,   558,    -1,    10,    -1,    11,   560,   559,    -1,
     250,    -1,    -1,   560,   561,    -1,   562,   563,   566,    -1,
     251,    -1,   564,    -1,    -1,   564,   565,    -1,   921,    -1,
     919,    -1,   667,    -1,   668,    -1,   664,    -1,   671,    -1,
     665,    -1,   672,    -1,   945,    -1,   966,    -1,   934,    -1,
      10,    -1,    11,   252,    -1,    -1,   568,   569,   570,    -1,
     253,    -1,   655,    -1,   571,    -1,   572,    -1,    10,    -1,
      11,   574,   573,    -1,   254,    -1,    -1,   574,   575,    -1,
     576,   577,   580,    -1,   255,    -1,   578,    -1,    -1,   578,
     579,    -1,   921,    -1,   919,    -1,   667,    -1,   669,    -1,
     673,    -1,   666,    -1,   945,    -1,   934,    -1,    10,    -1,
      11,   256,    -1,    -1,   582,   583,   584,    -1,   257,    -1,
     656,    -1,   585,    -1,   586,    -1,    10,    -1,    11,   588,
     587,    -1,   258,    -1,    -1,   588,   589,    -1,   590,   591,
     594,    -1,   259,    -1,   592,    -1,    -1,   592,   593,    -1,
     921,    -1,   919,    -1,   667,    -1,   670,    -1,   664,    -1,
     671,    -1,   665,    -1,   672,    -1,   945,    -1,    10,    -1,
      11,   260,    -1,    -1,   596,   597,    -1,    76,    -1,   598,
      -1,   599,    -1,    10,    -1,    11,    77,    -1,    11,   600,
      77,    -1,    11,   644,    77,    -1,   601,   602,   603,    79,
      -1,    78,    -1,    16,     8,     6,     8,    11,    -1,   604,
      -1,   603,   604,    -1,    -1,   605,    80,   606,   607,    -1,
      -1,   132,     3,     8,    -1,    10,    -1,    11,   608,    81,
      -1,   609,   621,   633,    -1,    -1,   271,   610,   614,    -1,
      -1,   610,   611,    -1,   612,    -1,   613,    -1,   176,     8,
       6,     8,    -1,    21,     8,     6,     8,    -1,   615,    -1,
      11,   616,   272,    -1,    10,    -1,    11,   272,    -1,   617,
      -1,   616,   617,    -1,    -1,   618,   269,   619,   620,    -1,
     197,     8,     6,     8,    -1,    10,    -1,    11,   270,    -1,
      -1,   263,   622,   626,    -1,    -1,   622,   623,    -1,   624,
      -1,   625,    -1,   170,     8,     6,     8,    -1,    21,     8,
       6,     8,    -1,   627,    -1,    11,   628,   264,    -1,    10,
      -1,    11,   264,    -1,   629,    -1,   628,   629,    -1,    -1,
     630,   261,   631,   632,    -1,   197,     8,     6,     8,    -1,
      10,    -1,    11,   262,    -1,    -1,   267,   634,   637,    -1,
      -1,   634,   635,    -1,   636,    -1,   649,    -1,   173,     8,
       6,     8,    -1,   638,    -1,    11,   639,   268,    -1,    10,
      -1,    11,   268,    -1,   640,    -1,   639,   640,    -1,    -1,
     641,   265,   642,   643,    -1,   197,     8,     6,     8,    -1,
      10,    -1,    11,   266,    -1,    -1,   645,    82,   647,   646,
      -1,    10,    -1,    11,    83,    -1,    -1,   647,   648,    -1,
     650,    -1,   651,    -1,    21,     8,     6,     8,    -1,    19,
       8,   674,     8,    -1,    20,     8,   674,     8,    -1,   168,
       8,     6,     8,    -1,    15,     8,     6,     8,    -1,   181,
       8,     6,     8,    -1,   180,     8,     6,     8,    -1,   179,
       8,     6,     8,    -1,    34,     8,   674,     8,    -1,    35,
       8,     6,     8,    -1,    36,     8,     6,     8,    -1,    37,
       8,     6,     8,    -1,    38,     8,     6,     8,    -1,    13,
       3,     8,    -1,    22,     8,     6,     8,    -1,    23,     8,
       6,     8,    -1,    25,     8,     6,     8,    -1,    33,     8,
       6,     8,    -1,    27,     8,     6,     8,    -1,    29,     8,
       6,     8,    -1,    30,     8,     6,     8,    -1,    31,     8,
       6,     8,    -1,    24,     8,     6,     8,    -1,    26,     8,
       6,     8,    -1,    32,     8,     6,     8,    -1,   676,     6,
     676,    -1,   676,     7,   676,    -1,   676,     8,    -1,    -1,
     676,   677,    -1,   429,    -1,   430,    -1,   431,    -1,   432,
      -1,   679,    -1,   686,    -1,    -1,   679,   680,    -1,   681,
     682,   685,    -1,   112,    -1,   683,    -1,    -1,   683,   684,
      -1,   934,    -1,   933,    -1,    11,     6,   113,    -1,   120,
     924,   687,    -1,   688,    -1,   689,    -1,    11,   121,    -1,
      10,    -1,    11,     4,   121,    -1,   691,    -1,   696,    -1,
      -1,   691,   692,    -1,   693,   694,   695,    -1,   112,    -1,
      -1,   934,    -1,    11,   674,   113,    -1,   120,   924,   697,
      -1,   698,    -1,   699,    -1,    11,   121,    -1,    10,    -1,
      11,     4,   121,    -1,   701,    -1,    -1,   701,   702,    -1,
     703,   704,   705,    -1,   112,    -1,    -1,   934,    -1,    11,
       4,   113,    -1,   707,   708,   711,    -1,   205,    -1,   709,
      -1,    -1,   709,   710,    -1,   954,    -1,   921,    -1,   919,
      -1,   945,    -1,   957,    -1,   712,    -1,   713,    -1,    10,
      -1,    11,   714,   206,    -1,   715,   721,    -1,    -1,   716,
     717,   720,    -1,   208,    -1,   718,    -1,    -1,   718,   719,
      -1,   925,    -1,   935,    -1,   936,    -1,   926,    -1,   927,
      -1,   928,    -1,   929,    -1,   942,    -1,   941,    -1,    11,
     207,    -1,    10,    -1,    -1,   721,   722,    -1,   723,    -1,
     855,    -1,   873,    -1,   748,    -1,   824,    -1,   837,    -1,
     761,    -1,   788,    -1,   806,    -1,   886,    -1,   890,    -1,
     724,   725,    11,   728,    -1,   219,    -1,   726,    -1,    -1,
     726,   727,    -1,   922,    -1,   948,    -1,   730,   729,   220,
      -1,    -1,   736,   742,    -1,   731,   732,    -1,   237,    -1,
     733,    -1,   734,    -1,    10,    -1,    11,   735,   238,    -1,
     678,    -1,    -1,   737,   738,    -1,   239,    -1,   739,    -1,
     740,    -1,    10,    -1,    11,   741,   240,    -1,   678,    -1,
     743,   744,    -1,   241,    -1,   745,    -1,   746,    -1,    10,
      -1,    11,   747,   242,    -1,   690,    -1,   749,   750,    11,
     753,    -1,   223,    -1,   751,    -1,    -1,   751,   752,    -1,
     922,    -1,   948,    -1,   730,   754,   224,    -1,   736,   755,
      -1,    -1,   756,   757,    -1,   241,    -1,   758,    -1,   759,
      -1,    10,    -1,    11,   760,   242,    -1,   678,    -1,   762,
     763,    11,   766,    -1,   225,    -1,   764,    -1,    -1,   764,
     765,    -1,   922,    -1,   948,    -1,   730,   767,   226,    -1,
     736,   768,    -1,    -1,   769,   770,    -1,   241,    -1,   771,
      -1,   772,    -1,    10,    -1,    11,   773,   242,    -1,   774,
      -1,    -1,   774,   775,    -1,   776,   777,   780,    -1,   112,
      -1,   778,    -1,    -1,   778,   779,    -1,   923,    -1,   938,
      -1,   781,    -1,   782,    -1,    10,    -1,    11,   783,   113,
      -1,    -1,   783,   784,    -1,   785,   786,   787,    -1,   243,
      -1,    -1,   937,    -1,    11,     6,   244,    -1,   789,   790,
      11,   793,    -1,   231,    -1,   791,    -1,    -1,   791,   792,
      -1,   922,    -1,   948,    -1,   730,   794,   232,    -1,   736,
     795,    -1,    -1,   796,   797,    -1,   241,    -1,   798,    -1,
     799,    -1,    10,    -1,    11,   800,   242,    -1,    -1,   800,
     801,    -1,   802,   803,    -1,   112,    -1,   804,    -1,   805,
      -1,    10,    -1,    11,   978,   113,    -1,   807,   808,    11,
     811,    -1,   233,    -1,   809,    -1,    -1,   809,   810,    -1,
     922,    -1,   948,    -1,   730,   812,   234,    -1,   736,   813,
      -1,    -1,   814,   815,    -1,   241,    -1,   816,    -1,   817,
      -1,    10,    -1,    11,   818,   242,    -1,    -1,   818,   819,
      -1,   820,   821,    -1,   112,    -1,   822,    -1,   823,    -1,
      10,    -1,    11,  1130,   113,    -1,   825,   826,    11,   829,
      -1,   229,    -1,   827,    -1,    -1,   827,   828,    -1,   922,
      -1,   948,    -1,   730,   830,   230,    -1,   736,   831,    -1,
      -1,   832,   833,    -1,   241,    -1,   834,    -1,   835,    -1,
      10,    -1,    11,   836,   242,    -1,   678,    -1,   838,   839,
      11,   842,    -1,   227,    -1,   840,    -1,    -1,   840,   841,
      -1,   922,    -1,   948,    -1,   730,   843,   228,    -1,   736,
     844,    -1,    -1,   845,   846,    -1,   241,    -1,   847,    -1,
     848,    -1,    10,    -1,    11,   849,   242,    -1,    -1,   849,
     850,    -1,   851,   852,   854,    -1,   112,    -1,    -1,   852,
     853,    -1,   963,    -1,   934,    -1,   933,    -1,    11,     6,
     113,    -1,   856,   857,    11,   860,    -1,   221,    -1,   858,
      -1,    -1,   858,   859,    -1,   922,    -1,   948,    -1,   730,
     861,   222,    -1,   736,   862,    -1,    -1,   863,   864,    -1,
     241,    -1,   865,    -1,   866,    -1,    10,    -1,    11,   867,
     242,    -1,    -1,   867,   868,    -1,   869,   870,   872,    -1,
     112,    -1,    -1,   870,   871,    -1,   940,    -1,   939,    -1,
     934,    -1,    11,   113,    -1,    10,    -1,   874,   875,    11,
     878,    -1,   235,    -1,   876,    -1,    -1,   876,   877,    -1,
     922,    -1,   948,    -1,   730,   879,   236,    -1,   736,   880,
      -1,    -1,   881,   882,    -1,   241,    -1,   883,    -1,   884,
      -1,    10,    -1,    11,   885,   242,    -1,   700,    -1,   887,
     888,    11,  1052,   889,    -1,   245,    -1,    -1,   951,    -1,
     246,    -1,   891,   892,   893,    -1,   209,    -1,   918,    -1,
      11,   895,   902,   909,   894,    -1,   210,    -1,   896,   897,
     898,    -1,   213,    -1,   920,    -1,   899,    -1,   900,    -1,
      10,    -1,    11,   901,   214,    -1,   678,    -1,   903,   904,
     905,    -1,   215,    -1,   920,    -1,   906,    -1,   907,    -1,
      10,    -1,    11,   908,   216,    -1,   678,    -1,    -1,   909,
     910,    -1,   911,   912,   915,    -1,   211,    -1,   913,    -1,
      -1,   913,   914,    -1,   930,    -1,   931,    -1,   954,    -1,
     957,    -1,   916,    -1,   917,    -1,    10,    -1,    11,   714,
     212,    -1,   165,     8,     6,     8,    -1,   166,     8,     6,
       8,    -1,   122,     8,     6,     8,    -1,   167,     8,     6,
       8,    -1,   169,     8,     6,     8,    -1,   178,     8,     6,
       8,    -1,   200,     8,     6,     8,    -1,   182,     8,     6,
       8,    -1,   185,     8,     6,     8,    -1,   186,     8,     6,
       8,    -1,   187,     8,     6,     8,    -1,   188,     8,     6,
       8,    -1,   190,     8,     6,     8,    -1,   191,     8,     6,
       8,    -1,   197,     8,     6,     8,    -1,   198,     8,     6,
       8,    -1,   199,     8,     6,     8,    -1,   183,     8,     6,
       8,    -1,   184,     8,     6,     8,    -1,   201,     8,   674,
       8,    -1,   202,     8,   674,     8,    -1,   193,     8,   674,
       8,    -1,   192,     8,   674,     8,    -1,   189,     8,   674,
       8,    -1,   943,    -1,   944,    -1,   163,    -1,   164,     3,
     675,    -1,   946,    -1,   947,    -1,   131,    -1,   132,     3,
       8,    -1,   949,    -1,   950,    -1,   161,    -1,   162,     3,
       8,    -1,   952,    -1,   953,    -1,   137,    -1,   138,     3,
       8,    -1,   955,    -1,   956,    -1,   159,    -1,   160,     3,
       8,    -1,   958,    -1,   959,    -1,   133,    -1,   134,     3,
       8,    -1,   961,    -1,   962,    -1,   141,    -1,   142,     3,
       8,    -1,   964,    -1,   965,    -1,   143,    -1,   144,     3,
       8,    -1,   967,    -1,   968,    -1,   149,    -1,   150,     3,
       8,    -1,    -1,   970,   971,   972,   309,    -1,   308,    -1,
     310,     8,     6,     8,    11,    -1,    -1,   972,   973,    -1,
     974,   975,    11,   978,   312,    -1,   311,    -1,   976,    -1,
      -1,   976,   977,    -1,   932,    -1,   951,    -1,  1022,    -1,
    1029,    -1,   985,    -1,   987,    -1,  1037,    -1,   989,    -1,
     991,    -1,   993,    -1,   995,    -1,  1049,    -1,   997,    -1,
     999,    -1,  1001,    -1,  1005,    -1,  1003,    -1,  1007,    -1,
    1014,    -1,  1009,    -1,  1012,    -1,  1043,    -1,  1046,    -1,
     979,    -1,   982,    -1,  1040,    -1,  1016,    -1,  1018,    -1,
    1020,    -1,    -1,   361,   980,   981,    -1,    10,    -1,    11,
     362,    -1,    -1,   363,   983,   984,    -1,    10,    -1,    11,
     364,    -1,    -1,   365,   986,   978,   978,   366,    -1,    -1,
     323,   988,   978,   978,   324,    -1,    -1,   325,   990,   978,
     978,   326,    -1,    -1,   339,   992,   978,   340,    -1,    -1,
     327,   994,   978,   978,   328,    -1,    -1,   321,   996,   978,
     978,   322,    -1,    -1,   329,   998,   978,   330,    -1,    -1,
     331,  1000,   978,   332,    -1,    -1,   343,  1002,   978,   344,
      -1,    -1,   345,  1004,   978,   346,    -1,    -1,   347,  1006,
     978,   348,    -1,    -1,   337,  1008,   978,   338,    -1,  1010,
     978,  1011,    -1,   351,    -1,   352,    -1,    -1,   353,  1013,
     978,   354,    -1,    -1,   341,  1015,   978,   978,   978,   342,
      -1,    -1,   369,  1017,  1052,   370,    -1,    -1,   371,  1019,
    1052,   372,    -1,    -1,   373,  1021,  1052,   374,    -1,  1023,
    1025,  1024,    -1,   367,    -1,    10,    -1,    11,   368,    -1,
      -1,  1025,  1026,    -1,   957,    -1,   960,    -1,  1027,    -1,
      -1,   428,     3,  1028,     8,    -1,    -1,   349,  1030,  1033,
    1031,    -1,    10,    -1,    11,   350,    -1,    -1,    11,   978,
    1032,   350,    -1,    -1,  1033,  1034,    -1,  1035,    -1,  1036,
      -1,   201,     8,   674,     8,    -1,   197,     8,     6,     8,
      -1,    -1,   333,  1038,  1039,   334,    -1,    -1,  1039,   978,
      -1,    -1,   357,  1041,  1042,   358,    -1,    -1,  1042,   978,
      -1,    -1,   355,  1044,  1045,   356,    -1,    -1,  1045,   978,
      -1,    -1,   359,  1047,  1048,   360,    -1,    -1,  1048,   978,
      -1,    -1,   335,  1050,  1051,   336,    -1,    -1,  1051,   978,
      -1,  1053,    -1,  1056,    -1,  1060,    -1,  1064,    -1,  1068,
      -1,  1071,    -1,  1077,    -1,  1080,    -1,  1084,    -1,  1089,
      -1,  1092,    -1,  1095,    -1,  1098,    -1,  1101,    -1,  1104,
      -1,  1107,    -1,  1110,    -1,  1113,    -1,  1074,    -1,  1054,
     663,  1055,    -1,   401,    -1,    10,    -1,    11,   402,    -1,
     197,     8,     6,     8,    -1,  1057,  1059,  1058,    -1,   251,
      -1,    10,    -1,    11,   252,    -1,   197,     8,     6,     8,
      -1,  1061,  1063,  1062,    -1,   255,    -1,    10,    -1,    11,
     256,    -1,   197,     8,     6,     8,    -1,  1065,  1067,  1066,
      -1,   259,    -1,    10,    -1,    11,   260,    -1,   197,     8,
       6,     8,    -1,  1069,  1070,    -1,   375,    -1,  1052,   376,
      -1,  1072,  1073,    -1,   377,    -1,  1052,  1052,   378,    -1,
    1075,  1076,    -1,   403,    -1,   978,   404,    -1,  1078,  1079,
      -1,   405,    -1,  1052,   406,    -1,  1081,  1082,    11,  1083,
      -1,   379,    -1,    -1,  1088,    -1,  1052,   380,    -1,  1085,
    1086,    11,  1087,    -1,   381,    -1,    -1,  1088,    -1,  1052,
     382,    -1,   426,     3,     8,    -1,  1090,  1091,    -1,   383,
      -1,    10,    -1,    11,   384,    -1,  1093,  1094,    -1,   385,
      -1,  1052,  1052,   386,    -1,  1096,  1097,    -1,   387,    -1,
    1052,   388,    -1,  1099,  1100,    -1,   389,    -1,  1052,  1052,
     390,    -1,  1102,  1103,    -1,   391,    -1,  1052,  1052,   392,
      -1,    -1,   393,  1105,  1106,   394,    -1,    -1,  1106,  1052,
      -1,  1108,  1109,    -1,   395,    -1,  1052,  1129,   396,    -1,
    1111,  1112,    -1,   397,    -1,   978,   978,   978,   978,  1052,
     398,    -1,  1114,  1115,    -1,   399,    -1,  1052,   400,    -1,
      -1,  1117,  1118,  1120,    -1,   313,    -1,  1119,    -1,   315,
       8,     6,     8,    -1,  1121,    -1,  1122,    -1,    10,    -1,
      11,  1123,   314,    -1,    -1,  1123,  1124,    -1,  1125,  1126,
      11,  1052,   317,    -1,   316,    -1,  1127,    -1,    -1,  1127,
    1128,    -1,   932,    -1,   951,    -1,   978,    -1,  1130,    -1,
    1131,    -1,  1137,    -1,  1140,    -1,  1143,    -1,  1146,    -1,
    1149,    -1,  1152,    -1,  1155,    -1,  1158,    -1,  1132,  1134,
    1133,    -1,   413,    -1,    10,    -1,    11,   414,    -1,  1135,
      -1,    -1,  1135,  1136,    -1,   940,    -1,   939,    -1,  1138,
      11,  1139,    -1,   423,    -1,   978,   978,   424,    -1,  1141,
      11,  1142,    -1,   415,    -1,  1129,  1129,   416,    -1,    -1,
     419,    11,  1144,  1145,   420,    -1,    -1,  1145,  1129,    -1,
    1147,    11,  1148,    -1,   409,    -1,  1129,  1129,   410,    -1,
    1150,    11,  1151,    -1,   411,    -1,  1129,   412,    -1,  1153,
      11,  1154,    -1,   407,    -1,  1129,   408,    -1,  1156,    11,
    1157,    -1,   421,    -1,  1129,  1129,   422,    -1,  1159,    11,
    1160,    -1,   417,    -1,  1129,   418,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   437,   437,   440,   441,   443,   452,   453,   456,   457,
     461,   466,   476,   476,   478,   491,   497,   498,   501,   502,
     505,   508,   511,   514,   520,   527,   534,   542,   547,   547,
     555,   561,   573,   573,   575,   577,   584,   584,   587,   587,
     593,   599,   611,   611,   613,   615,   619,   619,   627,   628,
     629,   630,   631,   632,   634,   641,   642,   647,   649,   658,
     660,   660,   663,   668,   673,   678,   678,   680,   683,   692,
     694,   694,   697,   702,   707,   712,   712,   715,   717,   726,
     736,   736,   739,   744,   749,   755,   755,   761,   763,   763,
     765,   767,   774,   812,   813,   815,   815,   817,   817,   819,
     821,   823,   832,   834,   834,   837,   842,   847,   852,   857,
     868,   868,   872,   874,   886,   888,   888,   891,   896,   901,
     905,   910,   915,   922,   922,   924,   926,   939,   941,   941,
     944,   949,   954,   959,   964,   969,   974,   981,   981,   985,
     987,   997,   999,   999,  1002,  1007,  1012,  1016,  1023,  1023,
    1037,  1039,  1048,  1050,  1050,  1053,  1058,  1063,  1068,  1070,
    1072,  1078,  1084,  1084,  1086,  1088,  1090,  1092,  1106,  1109,
    1111,  1120,  1122,  1122,  1125,  1130,  1135,  1140,  1142,  1144,
    1150,  1156,  1156,  1158,  1160,  1162,  1164,  1178,  1187,  1187,
    1189,  1194,  1194,  1196,  1199,  1201,  1201,  1208,  1213,  1223,
    1223,  1225,  1227,  1229,  1231,  1231,  1233,  1238,  1254,  1302,
    1302,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1318,  1319,  1321,  1321,  1327,  1332,  1342,  1342,
    1344,  1346,  1348,  1350,  1350,  1352,  1357,  1370,  1403,  1403,
    1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1416,  1417,
    1420,  1420,  1426,  1431,  1441,  1441,  1443,  1445,  1447,  1449,
    1449,  1451,  1456,  1471,  1510,  1510,  1513,  1514,  1515,  1516,
    1517,  1518,  1519,  1520,  1521,  1524,  1525,  1568,  1568,  1570,
    1572,  1572,  1574,  1575,  1578,  1579,  1582,  1633,  1635,  1649,
    1650,  1652,  1652,  1676,  1677,  1680,  1681,  1683,  1685,  1686,
    1690,  1691,  1693,  1694,  1696,  1715,  1726,  1733,  1738,  1739,
    1741,  1742,  1744,  1744,  1747,  1759,  1760,  1762,  1763,  1767,
    1768,  1770,  1771,  1773,  1792,  1803,  1810,  1815,  1816,  1818,
    1819,  1821,  1821,  1824,  1836,  1837,  1839,  1849,  1853,  1854,
    1856,  1857,  1859,  1878,  1885,  1890,  1891,  1893,  1894,  1896,
    1896,  1899,  1911,  1912,  1917,  1917,  1925,  1926,  1928,  1929,
    1931,  1935,  1941,  1952,  1957,  1972,  1983,  1994,  2002,  2010,
    2029,  2040,  2051,  2063,  2074,  2085,  2097,  2108,  2120,  2132,
    2144,  2156,  2168,  2180,  2192,  2204,  2216,  2243,  2244,  2251,
    2253,  2253,  2255,  2256,  2257,  2258,  2422,  2430,  2432,  2432,
    2434,  2436,  2445,  2447,  2447,  2449,  2449,  2451,  2467,  2470,
    2470,  2472,  2472,  2475,  2506,  2514,  2516,  2516,  2518,  2520,
    2528,  2528,  2530,  2546,  2548,  2548,  2550,  2550,  2552,  2583,
    2593,  2593,  2595,  2597,  2605,  2605,  2607,  2876,  2927,  2950,
    2969,  2969,  2972,  2973,  2974,  2975,  2976,  3158,  3158,  3160,
    3162,  3202,  3204,  3204,  3209,  3227,  3254,  3254,  3257,  3258,
    3259,  3260,  3261,  3262,  3263,  3264,  3265,  3268,  3268,  3270,
    3270,  3275,  3275,  3275,  3276,  3276,  3276,  3277,  3277,  3277,
    3278,  3278,  3280,  3282,  3291,  3297,  3297,  3300,  3306,  3312,
    3314,  3314,  3320,  3330,  3340,  3340,  3342,  3344,  3346,  3349,
    3349,  3360,  3368,  3368,  3370,  3372,  3374,  3380,  3390,  3398,
    3398,  3400,  3402,  3404,  3407,  3409,  3418,  3424,  3424,  3427,
    3433,  3439,  3441,  3443,  3443,  3453,  3461,  3461,  3463,  3465,
    3467,  3470,  3472,  3481,  3487,  3487,  3490,  3496,  3502,  3504,
    3507,  3512,  3523,  3539,  3539,  3541,  3543,  3545,  3547,  3547,
    3549,  3556,  3563,  3582,  3582,  3585,  3586,  3588,  3588,  3590,
    3592,  3594,  3594,  3597,  3599,  3607,  3607,  3612,  3619,  3621,
    3630,  3636,  3636,  3639,  3646,  3653,  3655,  3658,  3662,  3673,
    3689,  3689,  3691,  3693,  3695,  3695,  3697,  3699,  3714,  3714,
    3716,  3718,  3727,  3729,  3738,  3744,  3744,  3747,  3754,  3761,
    3763,  3766,  3770,  3781,  3798,  3798,  3800,  3802,  3804,  3804,
    3806,  3808,  3823,  3823,  3825,  3827,  3836,  3838,  3847,  3853,
    3853,  3856,  3862,  3868,  3870,  3872,  3872,  3882,  3890,  3890,
    3892,  3894,  3896,  3899,  3901,  3910,  3916,  3916,  3919,  3925,
    3931,  3933,  3936,  3940,  3951,  3967,  3967,  3969,  3971,  3973,
    3973,  3975,  3978,  3990,  3990,  3993,  3994,  3995,  3997,  4030,
    4032,  4042,  4048,  4048,  4051,  4058,  4064,  4066,  4069,  4073,
    4084,  4097,  4097,  4099,  4101,  4103,  4103,  4105,  4132,  4143,
    4143,  4146,  4147,  4148,  4150,  4150,  4153,  4155,  4164,  4170,
    4170,  4173,  4179,  4185,  4187,  4189,  4189,  4199,  4207,  4207,
    4209,  4211,  4213,  4216,  4219,  4237,  4237,  4248,  4255,  4265,
    4273,  4279,  4281,  4295,  4307,  4313,  4319,  4319,  4321,  4323,
    4325,  4327,  4337,  4343,  4349,  4349,  4351,  4353,  4355,  4357,
    4357,  4362,  4367,  4379,  4381,  4381,  4384,  4385,  4386,  4394,
    4401,  4401,  4403,  4405,  4423,  4434,  4478,  4601,  4612,  4634,
    4659,  4670,  4684,  4699,  4714,  4726,  4738,  4758,  4778,  4788,
    4825,  4836,  4848,  4862,  4875,  4888,  4898,  4908,  4921,  4921,
    4923,  4933,  5095,  5095,  5097,  5104,  5131,  5131,  5133,  5142,
    5156,  5156,  5158,  5165,  5192,  5192,  5194,  5201,  5210,  5210,
    5212,  5219,  5246,  5246,  5250,  5258,  5267,  5267,  5269,  5276,
    5285,  5285,  5287,  5294,  5333,  5334,  5340,  5346,  5367,  5368,
    5370,  5378,  5398,  5405,  5405,  5408,  5414,  5424,  5425,  5426,
    5427,  5428,  5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,
    5437,  5438,  5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,
    5447,  5449,  5450,  5451,  5455,  5455,  5458,  5459,  5461,  5461,
    5464,  5465,  5469,  5469,  5474,  5474,  5479,  5479,  5484,  5484,
    5489,  5489,  5494,  5494,  5499,  5499,  5504,  5504,  5509,  5509,
    5514,  5514,  5519,  5519,  5524,  5524,  5529,  5531,  5537,  5544,
    5544,  5550,  5550,  5562,  5562,  5567,  5567,  5572,  5572,  5582,
    5589,  5595,  5596,  5598,  5599,  5602,  5606,  5610,  5614,  5613,
    5634,  5633,  5640,  5641,  5643,  5642,  5649,  5650,  5653,  5659,
    5667,  5674,  5692,  5692,  5703,  5703,  5706,  5706,  5720,  5721,
    5724,  5724,  5737,  5738,  5741,  5741,  5754,  5755,  5758,  5758,
    5768,  5769,  5775,  5776,  5777,  5778,  5779,  5780,  5781,  5782,
    5783,  5784,  5785,  5786,  5787,  5788,  5789,  5790,  5791,  5792,
    5793,  5796,  5801,  5808,  5809,  5811,  5819,  5824,  5831,  5832,
    5834,  5841,  5846,  5853,  5854,  5856,  5863,  5868,  5875,  5876,
    5878,  5885,  5887,  5893,  5895,  5897,  5903,  5905,  5907,  5913,
    5915,  5917,  5923,  5925,  5927,  5933,  5933,  5938,  5940,  5942,
    5948,  5948,  5953,  5955,  5964,  5966,  5971,  5971,  5973,  5975,
    5981,  5984,  5986,  5992,  5995,  5997,  6003,  6006,  6008,  6014,
    6018,  6017,  6029,  6029,  6036,  6038,  6044,  6046,  6048,  6054,
    6057,  6059,  6065,  6075,  6075,  6081,  6089,  6091,  6111,  6111,
    6113,  6115,  6117,  6117,  6119,  6129,  6148,  6154,  6154,  6157,
    6165,  6181,  6181,  6185,  6186,  6187,  6188,  6189,  6190,  6191,
    6192,  6193,  6197,  6201,  6210,  6211,  6213,  6220,  6220,  6223,
    6224,  6228,  6230,  6236,  6239,  6241,  6247,  6250,  6250,  6260,
    6261,  6267,  6269,  6275,  6278,  6280,  6286,  6289,  6291,  6297,
    6300,  6302,  6308,  6311,  6313,  6319
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
  "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART", "COMPLEXCONJUGATEEND",
  "COMPLEXMINUSSTART", "COMPLEXMINUSEND", "COMPLEXNEGATESTART",
  "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART", "COMPLEXNUMBEREND",
  "COMPLEXPLUSSTART", "COMPLEXPLUSEND", "COMPLEXSQUARESTART",
  "COMPLEXSQUAREEND", "COMPLEXSUMSTART", "COMPLEXSUMEND",
  "COMPLEXTIMESSTART", "COMPLEXTIMESEND", "CREATECOMPLEXSTART",
  "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
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
     675,   676,   677,   678,   679,   680,   681,   682,   683,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   433,   434,   435,   435,   436,   437,   437,   438,   438,
     439,   440,   441,   441,   442,   443,   444,   444,   445,   445,
     446,   446,   446,   446,   447,   448,   449,   450,   451,   451,
     452,   453,   454,   454,   455,   456,   457,   457,   458,   458,
     459,   460,   461,   461,   462,   463,   464,   464,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   466,   467,   468,
     469,   469,   470,   470,   470,   471,   471,   472,   473,   474,
     475,   475,   476,   476,   476,   477,   477,   478,   479,   480,
     481,   481,   482,   482,   482,   483,   483,   484,   485,   485,
     486,   487,   488,   489,   489,   490,   490,   491,   491,   492,
     493,   494,   495,   496,   496,   497,   497,   497,   497,   498,
     499,   499,   500,   501,   502,   503,   503,   504,   504,   504,
     504,   504,   504,   505,   505,   506,   507,   508,   509,   509,
     510,   510,   510,   510,   510,   510,   510,   511,   511,   512,
     513,   514,   515,   515,   516,   516,   516,   516,   517,   517,
     518,   519,   520,   521,   521,   522,   522,   522,   523,   524,
     525,   526,   527,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   536,   537,   537,   537,   538,   539,   540,
     541,   542,   542,   543,   544,   545,   546,   547,   548,   548,
     549,   550,   550,   551,   552,   553,   553,   554,   555,   556,
     556,   557,   558,   559,   560,   560,   561,   562,   563,   564,
     564,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   566,   566,   567,   567,   568,   569,   570,   570,
     571,   572,   573,   574,   574,   575,   576,   577,   578,   578,
     579,   579,   579,   579,   579,   579,   579,   579,   580,   580,
     581,   581,   582,   583,   584,   584,   585,   586,   587,   588,
     588,   589,   590,   591,   592,   592,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   594,   594,   595,   595,   596,
     597,   597,   598,   598,   599,   599,   600,   601,   602,   603,
     603,   605,   604,   606,   606,   607,   607,   608,   609,   609,
     610,   610,   611,   611,   612,   613,   614,   614,   615,   615,
     616,   616,   618,   617,   619,   620,   620,   621,   621,   622,
     622,   623,   623,   624,   625,   626,   626,   627,   627,   628,
     628,   630,   629,   631,   632,   632,   633,   633,   634,   634,
     635,   635,   636,   637,   637,   638,   638,   639,   639,   641,
     640,   642,   643,   643,   645,   644,   646,   646,   647,   647,
     648,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   674,   675,
     676,   676,   677,   677,   677,   677,   678,   678,   679,   679,
     680,   681,   682,   683,   683,   684,   684,   685,   686,   687,
     687,   688,   688,   689,   690,   690,   691,   691,   692,   693,
     694,   694,   695,   696,   697,   697,   698,   698,   699,   700,
     701,   701,   702,   703,   704,   704,   705,   706,   707,   708,
     709,   709,   710,   710,   710,   710,   710,   711,   711,   712,
     713,   714,   715,   715,   716,   717,   718,   718,   719,   719,
     719,   719,   719,   719,   719,   719,   719,   720,   720,   721,
     721,   722,   722,   722,   722,   722,   722,   722,   722,   722,
     722,   722,   723,   724,   725,   726,   726,   727,   727,   728,
     729,   729,   730,   731,   732,   732,   733,   734,   735,   736,
     736,   737,   738,   738,   739,   740,   741,   742,   743,   744,
     744,   745,   746,   747,   748,   749,   750,   751,   751,   752,
     752,   753,   754,   755,   755,   756,   757,   757,   758,   759,
     760,   761,   762,   763,   764,   764,   765,   765,   766,   767,
     768,   768,   769,   770,   770,   771,   772,   773,   774,   774,
     775,   776,   777,   778,   778,   779,   779,   780,   780,   781,
     782,   783,   783,   784,   785,   786,   786,   787,   788,   789,
     790,   791,   791,   792,   792,   793,   794,   795,   795,   796,
     797,   797,   798,   799,   800,   800,   801,   802,   803,   803,
     804,   805,   806,   807,   808,   809,   809,   810,   810,   811,
     812,   813,   813,   814,   815,   815,   816,   817,   818,   818,
     819,   820,   821,   821,   822,   823,   824,   825,   826,   827,
     827,   828,   828,   829,   830,   831,   831,   832,   833,   833,
     834,   835,   836,   837,   838,   839,   840,   840,   841,   841,
     842,   843,   844,   844,   845,   846,   846,   847,   848,   849,
     849,   850,   851,   852,   852,   853,   853,   853,   854,   855,
     856,   857,   858,   858,   859,   859,   860,   861,   862,   862,
     863,   864,   864,   865,   866,   867,   867,   868,   869,   870,
     870,   871,   871,   871,   872,   872,   873,   874,   875,   876,
     876,   877,   877,   878,   879,   880,   880,   881,   882,   882,
     883,   884,   885,   886,   887,   888,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   898,   899,   900,
     901,   902,   903,   904,   905,   905,   906,   907,   908,   909,
     909,   910,   911,   912,   913,   913,   914,   914,   914,   914,
     915,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   942,
     943,   944,   945,   945,   946,   947,   948,   948,   949,   950,
     951,   951,   952,   953,   954,   954,   955,   956,   957,   957,
     958,   959,   960,   960,   961,   962,   963,   963,   964,   965,
     966,   966,   967,   968,   969,   969,   970,   971,   972,   972,
     973,   974,   975,   976,   976,   977,   977,   978,   978,   978,
     978,   978,   978,   978,   978,   978,   978,   978,   978,   978,
     978,   978,   978,   978,   978,   978,   978,   978,   978,   978,
     978,   978,   978,   978,   980,   979,   981,   981,   983,   982,
     984,   984,   986,   985,   988,   987,   990,   989,   992,   991,
     994,   993,   996,   995,   998,   997,  1000,   999,  1002,  1001,
    1004,  1003,  1006,  1005,  1008,  1007,  1009,  1010,  1011,  1013,
    1012,  1015,  1014,  1017,  1016,  1019,  1018,  1021,  1020,  1022,
    1023,  1024,  1024,  1025,  1025,  1026,  1026,  1026,  1028,  1027,
    1030,  1029,  1031,  1031,  1032,  1031,  1033,  1033,  1034,  1034,
    1035,  1036,  1038,  1037,  1039,  1039,  1041,  1040,  1042,  1042,
    1044,  1043,  1045,  1045,  1047,  1046,  1048,  1048,  1050,  1049,
    1051,  1051,  1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,
    1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,
    1052,  1053,  1054,  1055,  1055,   663,  1056,  1057,  1058,  1058,
    1059,  1060,  1061,  1062,  1062,  1063,  1064,  1065,  1066,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1082,  1083,  1084,  1085,
    1086,  1086,  1087,  1088,  1089,  1090,  1091,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1105,  1104,  1106,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1116,  1117,  1118,  1119,  1120,  1120,
    1121,  1122,  1123,  1123,  1124,  1125,  1126,  1127,  1127,  1128,
    1128,  1129,  1129,  1130,  1130,  1130,  1130,  1130,  1130,  1130,
    1130,  1130,  1131,  1132,  1133,  1133,  1134,  1135,  1135,  1136,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1144,  1143,  1145,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160
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
       1,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     2,     1,     2,     2,     1,     3,     2,     1,     2,
       2,     1,     2,     4,     1,     0,     1,     2,     4,     1,
       0,     1,     2,     3,     2,     1,     1,     2,     2,     1,
       3,     2,     1,     2,     2,     1,     3,     2,     1,     3,
       0,     4,     0,     2,     2,     1,     3,     2,     1,     6,
       2,     1,     2,     0,     3,     1,     1,     4,     1,     1,
       1,     3,     0,     2,     5,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     2,     1,     0,     2,     1,
       1,     3,     1,     3,     3,     1,     3,     0,     5,     0,
       2,     3,     1,     3,     3,     1,     2,     3,     1,     2,
       3,     1,     3,     3,     1,     2
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
     358,   252,  1023,     0,     0,     0,   227,     0,   201,   204,
     196,   199,   200,     0,    59,     0,    69,     0,    79,     0,
     102,     0,   114,     0,   127,     0,   141,     0,   152,     0,
     171,   449,   452,   437,   447,   448,   774,     0,   790,     0,
     786,     0,     0,     0,   441,   444,   443,   445,   772,   773,
     442,   784,   785,   446,   788,   789,     0,     0,     0,     0,
       0,     0,   914,   930,     0,     0,     0,     0,     0,     0,
     906,     0,   922,   918,   926,     0,     0,     0,     0,     0,
       0,   810,     0,     0,   783,     0,    24,    25,    27,    26,
     390,   390,   392,   393,   394,   395,   391,     0,   291,   289,
       0,     0,  1025,     0,     0,     0,     0,   253,     0,   230,
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
       0,   846,     0,   845,   850,     0,   849,     0,   957,   962,
     967,   972,   975,   984,   989,   995,   999,  1002,  1005,  1008,
    1010,  1015,  1018,  1021,   952,   978,   981,     0,   932,     0,
     933,     0,   934,     0,   935,     0,   936,     0,   937,     0,
     950,     0,   938,     0,   939,   985,   940,   990,   941,     0,
     942,     0,   943,     0,   944,     0,   945,     0,   946,   947,
       0,   948,     0,   949,     0,     0,     0,   878,   876,   891,
       0,   794,     0,     0,   895,   896,   792,   793,   889,   894,
     897,   758,   387,   388,     0,   286,   290,   293,   356,     0,
       0,     0,   355,   359,   360,   361,   194,     0,     0,  1026,
       0,   256,   259,   251,   254,   255,     0,     0,   367,   203,
     207,   202,   205,   209,    66,    76,     0,    87,   111,     0,
     124,   390,     0,     0,   138,     0,     0,   149,     0,   160,
       0,     0,   179,     0,     0,   450,   451,     0,   455,   775,
     791,   787,     0,     0,     0,     0,     0,     0,   865,   867,
     913,   915,   929,   931,   875,   859,     0,   869,   871,   873,
     902,     0,     0,     0,   901,   907,   908,   909,   880,   921,
     923,   917,   919,   925,   927,   847,   851,     0,  1012,   884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     971,     0,   974,     0,   977,     0,   980,     0,     0,   986,
       0,   991,   996,     0,   994,     0,   998,     0,  1001,     0,
    1004,     0,  1007,     0,  1014,     0,  1017,     0,  1020,   886,
     888,   892,     0,   898,     0,     0,     0,   357,   390,   390,
       0,  1030,  1032,  1024,  1028,  1029,     0,     0,   368,   232,
     236,   231,   234,   238,     0,   208,    99,    86,    91,    89,
      93,     0,     0,     0,     0,     0,     0,   375,   168,   158,
       0,     0,   161,   187,   177,     0,   180,   709,   483,   660,
     515,   532,   634,   617,   569,   593,   687,   704,   470,   471,
     485,   474,   517,   477,   534,   478,   571,   479,   595,   475,
     619,   476,   636,   472,   662,   473,   689,   480,   705,   481,
       0,   468,     0,   453,   770,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   458,   461,   462,   463,   464,
     459,   460,   466,   465,   768,   769,   745,   747,   863,   855,
     857,   861,     0,   903,   904,     0,   390,   853,     0,     0,
       0,   953,     0,   951,     0,   958,     0,   956,     0,   963,
       0,   961,     0,   968,     0,   966,   973,     0,   979,   982,
       0,     0,     0,   997,     0,  1003,     0,     0,  1078,  1072,
    1075,  1053,  1065,  1084,     0,  1081,  1062,  1041,     0,  1042,
    1043,  1057,  1044,     0,  1045,     0,  1046,  1047,     0,  1048,
       0,  1049,     0,  1050,     0,  1051,     0,     0,  1022,   795,
       0,   288,     0,   295,   298,   292,     0,     0,     0,     0,
     369,   258,   262,   257,   260,   264,     0,   237,   222,     0,
     206,     0,     0,     0,     0,     0,     0,   802,     0,     0,
     210,   215,   217,   213,   214,   216,   218,   212,   211,   221,
     219,   220,   800,   801,     0,    92,   109,   370,   371,   372,
     373,   374,     0,   164,   398,   159,   162,   163,   183,   398,
     178,   181,   182,     0,   484,     0,   516,     0,   533,     0,
     570,     0,   594,     0,   618,     0,   635,     0,   661,     0,
     688,     0,   706,     0,     0,   710,   467,   390,     0,     0,
       0,     0,     0,     0,     0,   390,   882,     0,     0,     0,
    1011,  1013,     0,     0,   954,     0,   959,     0,   964,     0,
     969,   976,   993,     0,   983,     0,   988,  1000,  1006,  1009,
    1067,  1016,     0,  1056,     0,     0,     0,     0,     0,     0,
       0,     0,   899,   294,   300,     0,   317,   363,   364,  1027,
    1031,  1035,  1033,  1037,     0,   263,   248,     0,   235,     0,
       0,     0,   239,   245,   242,   243,   244,   241,   240,   247,
     246,   223,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,    90,    94,    96,    95,     0,     0,     0,   166,
     396,   397,     0,   185,     0,   778,     0,     0,   486,   487,
     488,   776,   777,     0,   518,   519,   520,     0,   535,   536,
     537,     0,   572,   573,   574,     0,   596,   597,   598,     0,
     620,   621,   622,     0,   637,   638,   639,     0,   663,   664,
     665,     0,   690,   691,   692,     0,     0,     0,   708,   771,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   905,
     911,   910,   376,   955,   960,   965,   970,   987,   992,  1069,
    1054,     0,  1052,     0,     0,  1060,  1059,  1058,     0,  1061,
       0,  1064,     0,  1071,     0,  1074,     0,  1077,     0,  1080,
       0,  1083,     0,     0,   296,   319,   336,     0,  1036,   275,
       0,   261,     0,   265,   270,   272,   268,   269,   271,   273,
     267,   266,   274,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   803,     0,    98,   746,     0,     0,   167,
     165,   401,   399,   403,   186,   184,   493,   482,   490,     0,
       0,     0,   499,   514,   499,   531,   499,   568,   499,   592,
     499,   616,   499,   633,   499,   659,   499,   686,     0,     0,
     714,     0,     0,   389,   751,   761,   762,   752,   753,   754,
     755,   767,     0,  1055,   390,   390,     0,     0,     0,  1076,
    1079,     0,  1085,     0,   308,   312,     0,     0,   301,   302,
     303,   299,   306,     0,   338,   297,     0,  1039,  1040,  1038,
     276,     0,     0,     0,     0,   377,   384,   378,   385,   380,
     381,   760,     0,   412,     0,   408,   409,   410,     0,   402,
     501,     0,     0,     0,   496,   398,   492,   494,   495,   779,
       0,   523,     0,   540,     0,   577,     0,   601,     0,   625,
       0,   642,     0,   668,     0,   695,     0,   707,   703,   744,
     722,   729,     0,     0,   715,  1068,  1070,     0,     0,  1063,
    1066,  1073,  1082,  1019,   309,   312,   310,     0,     0,     0,
     327,   331,     0,     0,   320,   321,   322,   318,   325,     0,
       0,     0,   382,   386,   379,     0,     0,   411,     0,   400,
       0,   404,   406,   405,   489,   508,   491,     0,   504,   398,
     500,   502,   503,   498,     0,   748,   525,   522,     0,   521,
     542,   539,     0,   538,   579,   576,     0,   575,   603,   600,
       0,   599,   627,   624,     0,   623,   644,   641,     0,   640,
     670,   667,     0,   666,   697,   694,     0,   693,     0,     0,
     723,   718,   398,   713,   716,   717,   766,   765,   307,   311,
       0,     0,     0,   328,   331,   329,     0,     0,     0,   345,
     349,     0,     0,   339,   340,   337,   343,   341,  1034,   383,
     750,   413,     0,     0,   511,   416,   507,   509,   510,   506,
       0,   497,   528,   398,   524,   526,   527,   545,   548,   541,
     543,   544,   582,   584,   578,   580,   581,   606,   608,   602,
     604,   605,   630,   398,   626,   628,   629,   647,   649,   643,
     645,   646,   673,   675,   669,   671,   672,   700,   430,   696,
     698,   699,   712,   732,   711,   730,   734,   726,   398,   721,
     724,   725,   720,     0,     0,     0,   305,   304,   326,   330,
       0,     0,     0,   346,   349,   347,     0,     0,     0,   407,
       0,     0,   513,   414,   415,     0,   505,   530,     0,     0,
     547,     0,     0,   632,     0,     0,     0,   702,   429,     0,
       0,   733,   728,     0,   719,     0,   315,     0,   313,     0,
       0,   324,   323,   344,   348,     0,     0,     0,   759,     0,
     419,   417,   420,   512,   529,   546,   551,   549,   553,   587,
     583,   585,     0,   611,   607,   609,     0,   631,   652,   648,
     650,   653,   678,   674,   676,   679,   433,   431,   434,   701,
     742,   452,   731,   740,   741,     0,     0,   735,   736,   737,
     738,   739,   727,     0,   316,     0,   334,     0,   332,     0,
       0,   362,   342,   427,     0,   423,   424,   425,     0,   421,
       0,   552,   590,     0,   586,   588,   589,   614,     0,   610,
     612,   613,     0,     0,     0,   435,     0,     0,     0,   314,
       0,   335,     0,   352,     0,   350,     0,   426,   390,   418,
     559,   561,   550,   557,   558,     0,     0,   554,   555,   556,
       0,     0,     0,   798,     0,   654,   651,   657,   656,   655,
     796,   797,   685,     0,   680,   677,   683,   682,   681,     0,
     432,   743,     0,     0,   333,     0,   353,   428,     0,     0,
       0,   390,   591,   615,     0,     0,   684,     0,   756,   757,
     351,   422,   560,   564,   562,   565,     0,     0,   658,   799,
     436,     0,     0,   566,   749,   764,   390,     0,   563,     0,
       0,   763,   567
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   116,   117,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   141,   142,   143,   243,   244,   349,   348,   144,
     145,   245,   246,   356,   355,   146,   147,   247,   248,   363,
     362,   566,   567,   699,   700,   894,   895,  1023,  1022,   697,
     148,   149,   249,   250,   371,   372,   369,   150,   151,   251,
     252,   382,   378,   152,   153,   253,   254,   394,   391,   154,
     155,   255,   256,   406,   404,   156,   157,   257,   258,   413,
     412,   580,   581,   711,   905,   906,   907,  1028,  1160,   709,
     158,   159,   259,   260,   419,   418,   583,   584,   715,   910,
     911,   912,  1032,  1165,   714,    32,    33,    55,    56,    57,
      91,    92,   128,   240,   241,   242,   561,   345,   562,   563,
     694,   695,   880,   870,   125,   126,   235,   341,   342,   343,
     691,   557,   692,   693,   866,   867,  1002,   998,   232,   233,
     336,   553,   554,   555,   863,   687,   864,   865,   994,   995,
    1133,  1131,    51,    52,    87,    88,    89,   120,   121,   228,
     328,   329,   330,   676,   855,   985,   986,  1123,  1218,  1219,
    1220,  1221,  1222,  1295,  1296,  1297,  1465,  1508,  1126,  1223,
    1304,  1305,  1306,  1307,  1308,  1384,  1385,  1386,  1510,  1568,
    1225,  1309,  1393,  1394,  1395,  1396,  1474,  1475,  1476,  1570,
    1605,   122,   123,   542,   331,   543,  1397,   544,   545,    23,
      36,   129,   236,   337,   383,   384,   385,   397,   398,   407,
     632,   881,   882,  1003,   883,   884,  1005,  1137,   885,   886,
    1006,   224,  1079,   225,   326,  1029,  1030,  1162,  1163,  1248,
    1249,  1321,  1319,  1031,  1245,  1246,  1247,  1482,  1483,  1521,
    1522,  1578,  1609,  1484,  1575,  1576,  1577,  1497,  1498,  1547,
    1548,  1594,  1640,    98,    99,   160,   161,   274,   263,   264,
     265,   424,   425,   426,   587,   588,   764,   753,   586,   728,
     729,   730,   913,   914,  1038,  1167,  1251,  1168,  1169,  1256,
    1257,  1258,  1334,  1252,  1253,  1330,  1331,  1332,  1410,  1326,
    1327,  1406,  1407,  1408,  1485,   731,   732,   915,   916,  1044,
    1173,  1262,  1337,  1338,  1414,  1415,  1416,  1488,   733,   734,
     917,   918,  1048,  1175,  1264,  1341,  1342,  1419,  1420,  1421,
    1489,  1490,  1527,  1528,  1580,  1581,  1617,  1612,  1613,  1614,
    1649,  1664,  1665,  1672,  1678,   735,   736,   919,   920,  1052,
    1177,  1266,  1345,  1346,  1424,  1425,  1426,  1491,  1531,  1532,
    1584,  1585,  1586,   737,   738,   921,   922,  1056,  1179,  1268,
    1349,  1350,  1429,  1430,  1431,  1492,  1535,  1536,  1589,  1590,
    1591,   739,   740,   923,   924,  1060,  1181,  1270,  1353,  1354,
    1434,  1435,  1436,  1494,   741,   742,   925,   926,  1064,  1183,
    1272,  1357,  1358,  1439,  1440,  1441,  1495,  1540,  1541,  1592,
    1625,  1626,   743,   744,   927,   928,  1068,  1185,  1274,  1361,
    1362,  1444,  1445,  1446,  1496,  1544,  1545,  1593,  1634,  1635,
     745,   746,   929,   930,  1072,  1187,  1276,  1365,  1366,  1449,
    1450,  1451,  1499,   747,   748,   931,  1278,   749,   750,   934,
    1078,  1454,  1191,  1192,  1283,  1373,  1374,  1375,  1463,  1281,
    1282,  1369,  1459,  1460,  1461,  1503,  1368,  1455,  1456,  1500,
    1501,  1557,  1552,  1553,  1554,   935,   275,   712,   276,  1039,
    1618,  1158,   765,   766,   767,   768,   769,  1558,  1559,   105,
    1322,   889,   770,   771,  1673,  1619,  1105,  1106,   772,   773,
     774,   775,   277,   278,   279,  1040,  1041,  1042,   106,   107,
     108,   280,   281,   282,   283,   284,   285,   525,   526,   527,
    1629,  1630,  1631,   891,   892,   893,     7,     8,    15,    25,
      46,    47,    67,    68,   109,   827,   190,   305,   453,   191,
     306,   456,   192,   307,   193,   287,   194,   288,   195,   295,
     196,   289,   197,   286,   198,   290,   199,   291,   200,   297,
     201,   298,   202,   299,   203,   294,   204,   205,   518,   206,
     301,   207,   296,   208,   308,   209,   309,   210,   310,   211,
     212,   528,   313,   529,   530,   850,   213,   300,   614,   947,
     446,   615,   616,   617,   214,   292,   438,   215,   303,   449,
     216,   302,   448,   217,   304,   450,   218,   293,   439,   477,
     478,   479,   793,   480,   481,   797,   634,   482,   483,   801,
     636,   484,   485,   805,   638,   486,   487,   640,   488,   489,
     642,   490,   491,   644,   492,   493,   646,   494,   495,   648,
     964,   496,   497,   650,   966,   649,   498,   499,   654,   500,
     501,   656,   502,   503,   658,   504,   505,   660,   506,   507,
     662,   508,   628,   788,   509,   510,   664,   511,   512,   666,
     513,   514,   668,   333,   334,   548,   549,   683,   684,   685,
     859,   992,   993,  1127,  1128,  1229,   828,   829,   830,   831,
    1102,   972,   973,  1107,   832,   833,  1109,   834,   835,  1111,
     836,  1099,  1202,   837,   838,  1113,   839,   840,  1115,   841,
     842,  1117,   843,   844,  1119,   845,   846,  1121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -910
static const yytype_int16 yypact[] =
{
       2,  -910,    57,  -248,    72,  -910,  -910,  -105,  -208,    97,
    -910,  -910,    77,   -60,   122,  -910,   128,    84,  -910,   -97,
     127,   148,   138,  -910,   146,  -226,   151,  -910,  -910,  -910,
    -910,  -910,    86,   144,   159,   155,  -910,   165,  -910,  -910,
    -910,  -910,  -910,   168,  -910,  -910,  -910,  -910,   180,    38,
    -910,   218,   253,  -910,   -50,  -910,  -910,  -910,   173,  -910,
    -910,  -910,  -910,  -910,   194,    62,   193,   197,   -44,  -910,
    -910,   167,   206,   210,   223,   226,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,   207,  -910,   192,  -910,  -910,  -910,
    -910,     0,    79,   257,   250,  -910,  -910,  -910,  -910,  -910,
    -910,   763,  -910,   265,   275,  -910,  -910,  -910,  -910,  -910,
    -910,   289,   293,   320,  -910,  -910,  -910,  -910,  -910,  -910,
     239,   314,   269,   279,  -910,   108,   183,   359,   263,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
     308,   191,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,    59,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,   763,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   361,
     369,   372,   374,   376,   378,    19,  -910,   384,  -910,  -910,
    -910,  -910,    75,   215,   397,   310,  -910,   402,  -910,  -910,
    -910,  -910,  -910,   318,   -31,   325,   -31,   329,   -31,   332,
       6,   334,   105,   342,   123,   344,   118,   385,   -31,   404,
     -31,  -910,   211,  -910,  -910,  -910,  -910,   418,  -910,   420,
    -910,   422,   419,   421,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   763,   763,   763,   763,
     763,   763,  -910,  -910,   763,   763,   763,   763,   763,   763,
    -910,   763,  -910,  -910,  -910,   388,   390,   763,   158,   158,
     158,  -910,    92,    36,  -910,   438,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   447,   377,  -910,
     396,   106,  -910,   220,   157,   475,   392,  -910,   481,  -910,
    -910,  -910,  -910,  -910,   483,   156,  -910,   444,  -910,  -910,
    -910,  -910,  -910,  -910,   458,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   479,  -910,
     530,  -910,  -910,  -910,  -910,  -910,  -910,   485,  -910,   532,
     536,   538,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
     495,  -910,   540,   542,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   497,  -910,   549,  -910,  -910,  -910,  -910,
    -910,   488,  -910,  -910,  -910,  -910,  -910,   499,  -910,  -910,
    -910,  -910,  -910,  -910,   356,  -910,  -910,   559,   561,   563,
     569,   571,   763,   763,   763,   763,   255,   259,   461,   554,
     241,   261,   763,   243,   251,   245,    41,   235,   480,   608,
     649,  -910,   233,  -910,  -910,   264,  -910,   763,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   229,  -910,    16,
    -910,   406,  -910,   408,  -910,   410,  -910,   158,  -910,   158,
    -910,   763,  -910,   158,  -910,   185,  -910,   185,  -910,   452,
    -910,   158,  -910,   158,  -910,   158,  -910,   158,  -910,  -910,
     158,  -910,   763,  -910,   158,   237,   260,  -910,  -910,  -910,
     271,  -910,   610,   612,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -317,  -317,   609,  -910,  -910,   523,  -910,   568,
     611,   617,  -910,  -910,  -910,  -910,  -910,   645,   456,  -910,
     651,  -910,  -910,  -910,  -910,  -910,   653,   216,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   606,   593,  -910,   659,
    -910,  -910,   663,   665,  -910,   667,   669,  -910,   671,  -910,
     618,   565,  -910,   624,   565,  -910,    82,   464,    93,  -910,
    -910,  -910,   675,   677,   371,   367,   373,   379,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   763,  -910,  -910,  -910,
    -910,   703,   687,   689,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   335,  -910,  -910,
     697,   701,   468,   705,   487,   707,   489,   709,   491,   345,
    -910,   158,  -910,   307,  -910,   317,  -910,   742,   745,  -910,
     746,  -910,  -910,   375,  -910,   158,  -910,   365,  -910,   158,
    -910,   158,  -910,   351,  -910,   763,  -910,   363,  -910,  -910,
    -910,  -910,   753,  -910,   754,   764,   493,  -910,  -910,  -910,
     765,  -910,  -910,  -910,  -910,  -910,   761,   249,  -910,  -910,
    -910,  -910,  -910,  -910,   501,    95,  -910,  -910,  -910,  -910,
    -910,   767,   768,   769,   770,   771,   773,  -910,  -910,  -910,
     775,   503,  -910,  -910,  -910,   505,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   380,  -910,
     626,  -910,   566,  -910,  -910,   782,   779,   781,   789,   791,
     830,   834,   836,   838,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   506,  -910,  -910,   844,  -910,  -910,    37,   846,
     848,  -910,   453,  -910,   850,  -910,   605,  -910,   852,  -910,
     603,  -910,   854,  -910,   601,  -910,  -910,   484,  -910,  -910,
     855,   158,   158,  -910,   478,  -910,   476,   473,  -910,  -910,
    -910,  -910,  -910,  -910,   856,  -910,  -910,  -910,   472,  -910,
    -910,  -910,  -910,   858,  -910,   859,  -910,  -910,   860,  -910,
     861,  -910,   863,  -910,   865,  -910,   867,   763,  -910,  -910,
     874,  -910,   876,  -910,   615,  -910,   880,   884,   886,  -225,
    -910,  -910,  -910,  -910,  -910,  -910,   509,    49,  -910,   644,
    -910,   890,   892,   894,   896,   898,   900,  -910,   907,   904,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,   511,   -70,  -910,  -910,  -910,  -910,
    -910,  -910,   908,  -910,   796,  -910,  -910,  -910,  -910,   796,
    -910,  -910,  -910,   909,   -66,   911,   -66,   913,   -66,   915,
     -66,   917,   -66,   919,   -66,   921,   -66,   923,   -66,   925,
     -66,   927,  -910,   910,   929,  -910,  -910,  -910,   936,   940,
     942,   944,   946,   948,   950,  -910,  -910,   614,   952,   954,
    -910,  -910,   960,   975,  -910,   977,  -910,   979,  -910,   981,
    -910,  -910,  -910,   578,  -910,   619,  -910,  -910,  -910,  -910,
    -910,  -910,   513,   333,   763,   351,   351,   351,   351,   351,
     351,   763,  -910,  -910,  -910,   912,   728,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,   517,   120,  -910,   743,  -910,   987,
     989,   995,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   999,  1005,  1007,  1009,  1011,  1013,  1015,  1019,
    -910,   956,  -910,  -910,  -910,  -910,  1021,   821,   958,  -910,
     931,  -910,   962,  -910,   798,  -910,  1030,  1033,  -910,  -910,
    -910,  -910,  -910,   798,  -910,  -910,  -910,   798,  -910,  -910,
    -910,   798,  -910,  -910,  -910,   798,  -910,  -910,  -910,   798,
    -910,  -910,  -910,   798,  -910,  -910,  -910,   798,  -910,  -910,
    -910,   798,  -910,  -910,  -910,   158,  1039,   842,  -910,  -910,
      28,  1041,  1043,  1049,  1051,  1053,  1055,  1057,  1059,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,   655,  -910,  1063,  1065,  -910,  -910,  -910,   763,  -910,
     351,  -910,   351,  -910,   666,  -910,   672,  -910,   351,  -910,
     629,  -910,   158,    67,  -910,  -910,   808,  1066,   -44,  -910,
     819,  -910,  1073,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  1077,  1079,  1081,  1083,  1085,  1087,
    1089,  1091,  1093,  -910,  1095,  -910,  -910,  1097,   521,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -142,   555,
    1101,  1105,   878,  -910,   878,  -910,   878,  -910,   878,  -910,
     878,  -910,   878,  -910,   878,  -910,   878,  -910,   843,  1107,
    -910,   906,   565,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   247,  -910,  -910,  -910,   695,   711,   713,  -910,
    -910,   691,  -910,   735,  -910,   853,  1121,  1123,  -910,  -910,
    -910,  -910,  -910,    63,  -910,  -910,   158,  -910,  -910,  -910,
    -910,  1129,  1130,  1131,  1132,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  1135,  -910,    61,  -910,  -910,  -910,  1126,   423,
    -910,   922,   902,   613,  -910,   796,  -910,  -910,  -910,  -910,
    1136,   905,   924,   914,   926,   916,   918,   920,   928,   930,
     933,   932,   937,   934,   938,   935,   941,  -910,  -910,  -910,
    -910,  -910,   565,   620,  -910,  -910,  -910,  1137,  1139,  -910,
    -910,  -910,  -910,  -910,  -910,   877,  -910,   882,  1147,  1148,
    -910,   895,  1150,  1156,  -910,  -910,  -910,  -910,  -910,    51,
     839,  1158,  -910,  -910,  -910,  1159,  1047,  -910,  1163,  -910,
    1162,  -910,  -910,  -910,  -910,  -910,  -910,   622,  -910,   796,
    -910,  -910,  -910,  -910,   943,  -910,  -910,  -910,   627,  -910,
    -910,  -910,   631,  -910,  -910,  -910,   633,  -910,  -910,  -910,
     635,  -910,  -910,  -910,   637,  -910,  -910,  -910,   639,  -910,
    -910,  -910,   715,  -910,  -910,  -910,   717,  -910,   519,   721,
    -910,  -910,   796,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
     982,  1164,  1166,  -910,   939,  -910,   945,  1172,  1174,  -910,
     947,  1175,  1176,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  1069,  1179,  -910,  1067,  -910,  -910,  -910,  -910,
     951,  -910,  -910,   796,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   796,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   796,  -910,
    -910,  -910,  -910,   972,  1180,   723,  -910,  -910,  -910,  -910,
     993,  1184,  1185,  -910,   949,  -910,   953,  1188,  1189,  -910,
    1190,   821,  -910,  1084,  -910,   955,  -910,  -910,   957,   959,
    1088,   -59,   -58,  -910,   963,   -32,   -22,  -910,  1090,   965,
     725,   -27,  -910,   988,  -910,  1202,  -910,   961,  -910,  1201,
     727,  -910,  -910,  -910,  -910,  1014,  1204,  1205,  -910,   729,
    -910,  -910,  1017,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   731,  -910,  -910,  -910,   733,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  1017,  -910,
    -910,   211,  -910,  -910,  -910,  1206,  1211,  -910,  -910,  -910,
    -910,  -910,  -910,  1212,  -910,  1215,  -910,   964,  -910,  1214,
     739,  -910,  -910,  -910,    71,  -910,  -910,  -910,  1199,  -910,
     741,   -91,  -910,   763,  -910,  -910,  -910,  -910,   -26,  -910,
    -910,  -910,    31,    48,  1213,  -910,  1016,  1217,  1219,  -910,
    1221,  -910,  1224,  -910,   966,  -910,  1106,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  1225,  1226,  -910,  -910,  -910,
    1122,  1124,  1230,  -910,  1235,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  1127,  -910,  -910,  -910,  -910,  -910,  1237,
    -910,  -910,  1231,  1234,  -910,  1236,  -910,  -910,  1133,   -21,
    1239,  -910,  -910,  -910,  1134,  1240,  -910,  1138,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  1042,  1241,  1242,  -910,  -910,
    -910,  1244,  1243,  -910,  -910,  -910,  -910,  1247,  -910,  1248,
    1018,  -910,  -910
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,   967,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,   -40,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -127,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -216,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  1006,  1010,  -910,  -910,  -910,  -910,
    -910,   266,   268,  -910,  -827,  -910,  -910,  -910,   270,   272,
    -910,  -569,  -910,  -297,  -910,  -877,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -292,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -582,  -910,  -910,
    -910,  -910,  -910,  -812,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -241,  -563,  -240,  -483,
    -910,  -213,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   141,
    -326,  -845,  -910,  -910,  -910,  -910,  -323,  -322,  -910,  -910,
    -910,  -910,  -215,  -910,  -910,  -434,  -910,  -910,  -718,  -910,
    -910,  -229,  -910,  -910,  -312,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -101,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -282,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,   776,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -909,  -314,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -500
static const yytype_int16 yytable[] =
{
     189,   524,   702,   350,   351,   357,   358,   364,   365,   373,
     374,   386,   387,   399,   400,   408,   409,   414,   415,   420,
     421,   716,  1009,   532,   533,   320,   321,   515,   516,   352,
     932,   359,  1033,   366,   370,   375,  1193,   388,   630,   401,
    1004,   410,  1622,   416,     1,   422,   519,   520,    70,    71,
    1024,   610,   611,  1529,  1533,    72,    73,     5,  1632,  1633,
       6,  1389,  1390,   268,   269,  1316,  1110,  1112,  1114,  1116,
    1118,  1120,  1391,  1300,  1301,  1606,   875,  1214,  1215,   999,
    1538,  1000,  1001,    44,  1302,    45,     9,  1615,  1216,   990,
    1542,   991,  1662,   102,   103,  1035,  1036,  1250,    11,  -499,
     266,   267,    14,  1037,   312,    16,   268,   269,    21,   856,
     857,  1616,   322,   323,   324,   325,   538,   539,   871,   872,
     873,   874,   875,    18,   876,   540,   541,    27,    28,   879,
      24,   405,   270,   271,    26,   272,   273,   266,   267,   379,
     380,   381,    34,   871,   872,   873,   874,   875,    38,    39,
      31,  1132,    43,   104,    53,    54,    37,   379,   380,    48,
     392,   393,    50,  1555,  1556,    59,    60,    58,  1136,   268,
     269,    64,   272,   273,  1623,  1624,    66,   521,   522,    93,
     266,   267,  1317,  1530,  1534,   432,   433,   434,   435,   436,
     437,    69,  1607,   440,   441,   442,   443,   444,   445,    90,
     447,  1207,    95,  1208,   100,   639,   457,   641,   101,  1211,
    1539,   645,   110,   631,   111,   272,   273,   949,   112,   655,
    1543,   657,  1663,   659,  1392,   661,   266,   267,   663,  1320,
     879,   113,   667,  1303,   114,    74,   266,   267,   612,    75,
    1103,  1104,   613,  1217,   877,   878,   115,   879,   879,   266,
     267,   266,   267,   124,   266,   267,   754,   755,    82,    83,
     127,   272,   273,    85,    86,   130,    96,    97,   219,   118,
     119,   272,   273,   238,   239,   756,   757,   758,   759,   760,
     761,   762,   763,   220,   272,   273,   272,   273,   458,   272,
     273,   717,   459,  1286,   879,   221,   460,   131,   132,   222,
     133,   718,   134,   719,   135,   720,   136,   721,   137,   722,
     138,   723,   139,   724,   140,   725,   226,   726,   261,   262,
     339,   340,   266,   267,   268,   269,   223,   727,   346,   347,
     227,   594,   595,   596,   597,   353,   354,   601,   603,   360,
     361,   606,   367,   368,   376,   377,   229,   620,   622,   624,
     270,   271,   389,   390,   402,   403,   627,   272,   273,   807,
    1261,   230,  1263,   234,  1265,   231,  1267,   237,  1269,   314,
    1271,   311,  1273,   814,  1275,   315,  1088,   816,  1333,   817,
     316,   818,   317,   819,   318,   820,   319,   821,   332,   822,
     643,   823,   327,   824,   335,   825,   411,   826,   451,   452,
     454,   455,   551,   552,  1323,   338,   559,   560,   344,   458,
    1228,   665,   461,   459,   462,   417,   463,   460,   464,   423,
     465,   427,   466,   428,   467,   429,   468,   430,   469,   431,
     470,   950,   471,  1045,   472,  1049,   473,  1053,   474,  1057,
     475,  1061,   476,  1065,   517,  1069,   531,  1073,   322,   323,
     324,   325,  1409,   534,   887,   888,   535,   322,   323,   324,
     325,  1172,   652,   653,   523,  1174,   681,   682,   546,  1176,
     689,   690,   547,  1178,   751,   752,   537,  1180,   791,   792,
     890,  1182,  1046,   550,  1050,  1184,  1054,   556,  1058,  1186,
    1062,   558,  1066,   564,  1070,  1462,  1074,   795,   796,   799,
     800,   803,   804,   853,   854,   782,   951,   861,   862,   565,
     784,   868,   869,   903,   904,   908,   909,   102,   103,   996,
     997,  1020,  1021,  1100,  1101,  1103,  1104,  1129,  1130,   963,
     965,  1243,  1244,   461,   568,   462,  1487,   463,   569,   464,
     571,   465,   570,   466,   572,   467,   573,   468,   575,   469,
     576,   470,   578,   471,   574,   472,  1493,   473,   577,   474,
     579,   475,   585,   476,   847,  1254,  1255,   589,   162,   590,
     163,   591,   164,   582,   165,   592,   166,   593,   167,   604,
     168,  1502,   169,  1025,   170,   598,   171,   607,   172,   618,
     173,   599,   174,   609,   175,   625,   176,   608,   177,   629,
     178,   605,   179,   633,   180,   635,   181,   637,   182,   669,
     183,   647,   184,   672,   185,   673,   186,   674,   187,   678,
     188,  1320,   879,  1328,  1329,   679,  1007,  1008,   626,  1284,
    1371,  1372,  1404,  1405,   670,  1287,  1288,  1412,  1413,   671,
    1080,  1417,  1418,  1422,  1423,  1427,  1428,  1432,  1433,  1437,
    1438,   677,  1010,   680,   818,   675,   819,   686,   820,   696,
     821,   688,   822,   698,   823,   701,   824,  1285,   825,   703,
     826,   704,   162,   705,   163,   706,   164,  1579,   165,   707,
     166,   708,   167,   776,   168,   777,   169,   710,   170,   713,
     171,   779,   172,   778,   173,   785,   174,   786,   175,   780,
     176,   787,   177,  1595,   178,   789,   179,   781,   180,   790,
     181,   808,   182,   794,   183,   798,   184,   802,   185,  1370,
     186,   806,   187,   809,   188,  1442,  1443,  1447,  1448,  1452,
    1453,  1457,  1458,  1506,  1507,  1550,  1551,  1566,  1567,  1573,
    1574,  1582,  1583,  1587,  1588,   810,   981,  1628,  1636,  1603,
    1604,  1610,  1611,   815,  1140,  1141,   811,   812,   818,   813,
     819,   849,   820,   848,   821,   851,   822,   852,   823,   860,
     824,   858,   825,   936,   826,   896,   897,   898,   899,   900,
    1142,   901,   162,   902,   163,   937,   164,   938,   165,   939,
     166,   933,   167,  1188,   168,   600,   169,   940,   170,   941,
     171,   162,   172,   163,   173,   164,   174,   165,   175,   166,
     176,   167,   177,   168,   178,   169,   179,   170,   180,   171,
     181,   172,   182,   173,   183,   174,   184,   175,   185,   176,
     186,   177,   187,   178,   188,   179,   619,   180,   942,   181,
    1213,   182,   943,   183,   944,   184,   945,   185,   946,   186,
     948,   187,   952,   188,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   967,   969,   968,   970,   971,   974,
     975,   976,   977,  1108,   978,   162,   979,   163,   980,   164,
    1122,   165,   982,   166,   983,   167,   984,   168,   987,   169,
     602,   170,   988,   171,   989,   172,  1011,   173,  1012,   174,
    1013,   175,  1014,   176,  1015,   177,  1016,   178,  1017,   179,
    1018,   180,  1019,   181,  1026,   182,  1027,   183,  1076,   184,
    1034,   185,  1043,   186,  1047,   187,  1051,   188,  1055,   162,
    1059,   163,  1063,   164,  1067,   165,  1071,   166,  1075,   167,
    1077,   168,  1081,   169,  1310,   170,  1082,   171,  1083,   172,
    1084,   173,  1085,   174,  1086,   175,  1087,   176,  1097,   177,
    1090,   178,  1091,   179,  1089,   180,   621,   181,  1092,   182,
     162,   183,   163,   184,   164,   185,   165,   186,   166,   187,
     167,   188,   168,  1093,   169,  1094,   170,  1095,   171,  1096,
     172,  1125,   173,  1124,   174,  1144,   175,  1145,   176,  1143,
     177,  1098,   178,  1146,   179,  1147,   180,  1206,   181,   623,
     182,  1148,   183,  1149,   184,  1150,   185,  1151,   186,  1152,
     187,  1157,   188,  1153,   162,  1154,   163,  1155,   164,  1156,
     165,  1159,   166,  1170,   167,  1166,   168,  1164,   169,  1648,
     170,  1171,   171,  1161,   172,  1189,   173,  1212,   174,  1194,
     175,  1195,   176,   783,   177,  1190,   178,  1196,   179,  1197,
     180,  1198,   181,  1199,   182,  1200,   183,  1201,   184,  1203,
     185,  1204,   186,  1205,   187,  1224,   188,  1226,  1209,  1230,
    1210,  1231,  1667,  1232,   162,  1233,   163,  1234,   164,  1277,
     165,  1235,   166,  1236,   167,  1237,   168,  1238,   169,  1239,
     170,  1240,   171,  1241,   172,  1242,   173,  1679,   174,  1259,
     175,  1260,   176,  1292,   177,  1279,   178,  1250,   179,  1289,
     180,  1280,   181,  1291,   182,  1294,   183,  1290,   184,  1298,
     185,  1299,   186,  1293,   187,  1311,   188,  1318,  1312,  1313,
    1314,  1315,  1324,  1325,  1335,  1376,  1336,  1377,  1339,  1378,
    1347,  1380,  1343,  1381,  1382,  1340,  1398,  1344,  1387,  1383,
    1363,  1348,  1351,  1355,  1388,  1359,  1399,  1400,  1401,  1402,
    1403,  1352,  1466,  1356,  1467,  1360,  1364,  1367,  1471,  1464,
    1472,  1411,  1479,  1477,  1478,  1480,  1504,  1481,  1505,  1561,
    1509,  1486,  1511,  1512,  1516,  1517,  1520,  1523,  1518,  1524,
    1526,  1525,  1546,  1468,  1562,  1537,  1470,  1549,  1563,  1565,
    1608,  1569,  1571,  1572,  1597,  1473,   879,  1513,  1515,  1598,
    1599,  1600,  1602,  1642,  1639,  1643,  1601,  1647,  1641,  1644,
    1645,  1564,  1646,  1650,  1651,  1652,  1654,  1653,  1655,  1658,
    1656,  1657,  1659,  1671,  1660,  1666,  1661,  1668,  1669,  1674,
    1675,  1670,  1676,  1680,  1677,  1379,  1681,  1469,  1514,  1596,
     395,  1134,  1682,  1135,   396,  1138,  1627,  1139,  1519,  1227,
    1637,  1638,  1560,   651,  1621,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
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
       0,     0,  1620
};

static const yytype_int16 yycheck[] =
{
     101,   313,   571,   244,   244,   246,   246,   248,   248,   250,
     250,   252,   252,   254,   254,   256,   256,   258,   258,   260,
     260,   584,   867,   320,   321,     6,     7,   309,   310,   244,
     748,   246,   909,   248,    28,   250,     8,   252,    22,   254,
     867,   256,    11,   258,    42,   260,    10,    11,    10,    11,
     895,    10,    11,   112,   112,    17,    18,     0,    10,    11,
     308,    10,    11,   133,   134,     4,   975,   976,   977,   978,
     979,   980,    21,    10,    11,     4,    27,    10,    11,    30,
     112,    32,    33,   309,    21,   311,    14,   178,    21,   314,
     112,   316,   113,   137,   138,   161,   162,   239,   203,   241,
     131,   132,   310,   169,   205,     8,   133,   134,   168,   678,
     679,   202,   429,   430,   431,   432,    10,    11,    23,    24,
      25,    26,    27,    46,    29,    19,    20,    43,    44,   199,
       8,    13,   159,   160,     6,   166,   167,   131,   132,    34,
      35,    36,    15,    23,    24,    25,    26,    27,    10,    11,
     247,    31,     6,   197,    10,    11,     8,    34,    35,     8,
      37,    38,    76,   190,   191,    10,    11,     8,   995,   133,
     134,     6,   166,   167,   143,   144,     8,   141,   142,     6,
     131,   132,   121,   242,   242,   286,   287,   288,   289,   290,
     291,    11,   121,   294,   295,   296,   297,   298,   299,   249,
     301,  1110,     8,  1112,    11,   487,   307,   489,    11,  1118,
     242,   493,    45,   197,     8,   166,   167,   786,     8,   501,
     242,   503,   243,   505,   173,   507,   131,   132,   510,   198,
     199,     8,   514,   170,     8,   197,   131,   132,   197,   201,
     192,   193,   201,   176,   149,   150,    39,   199,   199,   131,
     132,   131,   132,   253,   131,   132,   163,   164,    40,    41,
     181,   166,   167,    10,    11,     8,   204,   205,     3,    77,
      78,   166,   167,    10,    11,   182,   183,   184,   185,   186,
     187,   188,   189,     8,   166,   167,   166,   167,   251,   166,
     167,   209,   255,  1202,   199,     6,   259,    47,    48,     6,
      50,   219,    52,   221,    54,   223,    56,   225,    58,   227,
      60,   229,    62,   231,    64,   233,    77,   235,    10,    11,
      10,    11,   131,   132,   133,   134,     6,   245,    10,    11,
      16,   432,   433,   434,   435,    10,    11,   438,   439,    10,
      11,   442,    10,    11,    10,    11,    77,   448,   449,   450,
     159,   160,    10,    11,    10,    11,   457,   166,   167,   641,
    1172,    82,  1174,   180,  1176,   257,  1178,     8,  1180,     8,
    1182,   312,  1184,   655,  1186,     6,   945,   659,  1255,   661,
       8,   407,     8,   409,     8,   411,     8,   413,   313,   415,
     491,   417,     8,   419,   179,   421,    11,   423,    10,    11,
      10,    11,    10,    11,  1249,     8,   250,   251,     6,   251,
    1128,   512,   375,   255,   377,    11,   379,   259,   381,   208,
     383,     3,   385,     3,   387,     3,   389,     8,   391,     8,
     393,   394,   395,   916,   397,   918,   399,   920,   401,   922,
     403,   924,   405,   926,   352,   928,     8,   930,   429,   430,
     431,   432,  1329,     6,   695,   695,    79,   429,   430,   431,
     432,  1043,    10,    11,   428,  1047,    10,    11,   248,  1051,
     254,   255,   315,  1055,    10,    11,    80,  1059,    10,    11,
     695,  1063,   916,     8,   918,  1067,   920,     6,   922,  1071,
     924,     8,   926,    49,   928,  1372,   930,    10,    11,    10,
      11,    10,    11,    10,    11,   606,   788,   258,   259,    51,
     611,    10,    11,    10,    11,    10,    11,   137,   138,    10,
      11,    10,    11,    10,    11,   192,   193,    10,    11,   811,
     812,    10,    11,   375,    55,   377,  1413,   379,     8,   381,
       8,   383,    57,   385,     8,   387,     8,   389,     8,   391,
       8,   393,     3,   395,    59,   397,  1433,   399,    61,   401,
      72,   403,   206,   405,   665,    10,    11,     8,   321,     8,
     323,     8,   325,    74,   327,     6,   329,     6,   331,   338,
     333,  1458,   335,   895,   337,   330,   339,   344,   341,   354,
     343,   332,   345,   348,   347,   362,   349,   346,   351,   370,
     353,   340,   355,   197,   357,   197,   359,   197,   361,   372,
     363,   426,   365,     3,   367,     3,   369,     8,   371,     8,
     373,   198,   199,    10,    11,     8,   867,   867,   364,  1192,
      10,    11,    10,    11,   374,  1204,  1205,    10,    11,   368,
     937,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    83,   867,     8,   407,   132,   409,     6,   411,    53,
     413,     8,   415,    70,   417,     6,   419,   420,   421,     6,
     423,     6,   321,     6,   323,     6,   325,  1522,   327,     8,
     329,    63,   331,     8,   333,     8,   335,   122,   337,    65,
     339,   324,   341,   322,   343,     8,   345,     8,   347,   326,
     349,   366,   351,  1548,   353,     8,   355,   328,   357,     8,
     359,   404,   361,     8,   363,     8,   365,     8,   367,  1282,
     369,   376,   371,   406,   373,    10,    11,    10,    11,   210,
     211,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     3,   847,  1592,  1593,    10,
      11,    10,    11,   388,   995,   995,    11,    11,   407,   384,
     409,     8,   411,   400,   413,    11,   415,     3,   417,     8,
     419,     6,   421,   207,   423,     8,     8,     8,     8,     8,
     995,     8,   321,     8,   323,     3,   325,     8,   327,     8,
     329,   165,   331,  1075,   333,   334,   335,     8,   337,     8,
     339,   321,   341,   323,   343,   325,   345,   327,   347,   329,
     349,   331,   351,   333,   353,   335,   355,   337,   357,   339,
     359,   341,   361,   343,   363,   345,   365,   347,   367,   349,
     369,   351,   371,   353,   373,   355,   356,   357,     8,   359,
    1122,   361,     8,   363,     8,   365,     8,   367,   342,   369,
       6,   371,     6,   373,     6,   402,     6,   252,     6,   256,
       6,   260,   378,     8,   386,   392,   390,    11,   396,    11,
      11,    11,    11,   974,    11,   321,    11,   323,    11,   325,
     981,   327,     8,   329,     8,   331,   271,   333,     8,   335,
     336,   337,     8,   339,     8,   341,   252,   343,     8,   345,
       8,   347,     8,   349,     8,   351,     8,   353,     8,   355,
       3,   357,     8,   359,     6,   361,   120,   363,     8,   365,
      11,   367,    11,   369,    11,   371,    11,   373,    11,   321,
      11,   323,    11,   325,    11,   327,    11,   329,    11,   331,
      11,   333,     6,   335,  1226,   337,     6,   339,     6,   341,
       6,   343,     6,   345,     6,   347,     6,   349,   380,   351,
       8,   353,     8,   355,   350,   357,   358,   359,     8,   361,
     321,   363,   323,   365,   325,   367,   327,   369,   329,   371,
     331,   373,   333,     8,   335,     8,   337,     8,   339,     8,
     341,   263,   343,    81,   345,     8,   347,     8,   349,   256,
     351,   382,   353,     8,   355,     6,   357,  1108,   359,   360,
     361,     6,   363,     6,   365,     6,   367,     6,   369,     6,
     371,   200,   373,     8,   321,     6,   323,    71,   325,     8,
     327,    73,   329,     3,   331,   237,   333,    75,   335,  1608,
     337,     8,   339,   112,   341,     6,   343,   418,   345,     8,
     347,     8,   349,   350,   351,   213,   353,     8,   355,     8,
     357,     8,   359,     8,   361,     8,   363,     8,   365,   414,
     367,     8,   369,     8,   371,   267,   373,    11,   412,   260,
     408,     8,  1651,     6,   321,     6,   323,     6,   325,   246,
     327,     8,   329,     8,   331,     8,   333,     8,   335,     8,
     337,     8,   339,     8,   341,     8,   343,  1676,   345,     8,
     347,     6,   349,   422,   351,     8,   353,   239,   355,   424,
     357,   215,   359,   410,   361,   272,   363,   416,   365,     8,
     367,     8,   369,   398,   371,     6,   373,    11,     8,     8,
       8,     6,   220,   241,     8,     8,   241,     8,   224,   272,
     232,   269,   226,     6,     6,   241,   317,   241,     8,   264,
     222,   241,   234,   230,     8,   228,     8,     8,   121,     6,
       8,   241,     8,   241,     8,   241,   241,   236,     6,   197,
       6,   238,   113,     8,     8,     6,   214,   120,     8,  1501,
     197,   240,     8,     8,     6,     6,   112,   242,     8,   242,
     112,   242,   112,   264,   216,   242,   261,   242,     6,     8,
      11,   197,     8,     8,     8,   268,   199,   268,   265,     8,
       8,     6,     8,     6,    11,     6,   262,   121,   212,     8,
       6,   270,   266,     8,     8,   113,     6,   113,     3,     8,
     113,     4,     8,   201,     8,     6,   113,   113,     8,     8,
       8,   113,     8,     6,    11,  1295,     8,  1384,  1474,  1551,
     254,   995,   244,   995,   254,   995,  1592,   995,  1481,  1128,
    1593,  1593,  1501,   497,  1588,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,
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
      -1,    -1,  1583
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    42,   434,   438,   439,     0,   308,   969,   970,    14,
     440,   203,   451,   452,   310,   971,     8,   441,    46,   458,
     459,   168,   453,   652,     8,   972,     6,    43,    44,   442,
     443,   247,   548,   549,    15,   460,   653,     8,    10,    11,
     454,   455,   456,     6,   309,   311,   973,   974,     8,   445,
      76,   595,   596,    10,    11,   550,   551,   552,     8,    10,
      11,   461,   462,   463,     6,   457,     8,   975,   976,    11,
      10,    11,    17,    18,   197,   201,   444,   446,   447,   448,
     449,   450,    40,    41,   435,    10,    11,   597,   598,   599,
     249,   553,   554,     6,   464,     8,   204,   205,   706,   707,
      11,    11,   137,   138,   197,   932,   951,   952,   953,   977,
      45,     8,     8,     8,     8,    39,   436,   437,    77,    78,
     600,   601,   644,   645,   253,   567,   568,   181,   555,   654,
       8,    47,    48,    50,    52,    54,    56,    58,    60,    62,
      64,   465,   466,   467,   472,   473,   478,   479,   493,   494,
     500,   501,   506,   507,   512,   513,   518,   519,   533,   534,
     708,   709,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   978,
     979,   982,   985,   987,   989,   991,   993,   995,   997,   999,
    1001,  1003,  1005,  1007,  1009,  1010,  1012,  1014,  1016,  1018,
    1020,  1022,  1023,  1029,  1037,  1040,  1043,  1046,  1049,     3,
       8,     6,     6,     6,   674,   676,    77,    16,   602,    77,
      82,   257,   581,   582,   180,   569,   655,     8,    10,    11,
     556,   557,   558,   468,   469,   474,   475,   480,   481,   495,
     496,   502,   503,   508,   509,   514,   515,   520,   521,   535,
     536,    10,    11,   711,   712,   713,   131,   132,   133,   134,
     159,   160,   166,   167,   710,   919,   921,   945,   946,   947,
     954,   955,   956,   957,   958,   959,   996,   988,   990,   994,
     998,  1000,  1038,  1050,  1008,   992,  1015,  1002,  1004,  1006,
    1030,  1013,  1044,  1041,  1047,   980,   983,   986,  1017,  1019,
    1021,   312,   978,  1025,     8,     6,     8,     8,     8,     8,
       6,     7,   429,   430,   431,   432,   677,     8,   603,   604,
     605,   647,   313,  1116,  1117,   179,   583,   656,     8,    10,
      11,   570,   571,   572,     6,   560,    10,    11,   471,   470,
     919,   921,   945,    10,    11,   477,   476,   919,   921,   945,
      10,    11,   483,   482,   919,   921,   945,    10,    11,   499,
      28,   497,   498,   919,   921,   945,    10,    11,   505,    34,
      35,    36,   504,   657,   658,   659,   919,   921,   945,    10,
      11,   511,    37,    38,   510,   657,   658,   660,   661,   919,
     921,   945,    10,    11,   517,    13,   516,   662,   919,   921,
     945,    11,   523,   522,   919,   921,   945,    11,   538,   537,
     919,   921,   945,   208,   714,   715,   716,     3,     3,     3,
       8,     8,   978,   978,   978,   978,   978,   978,  1039,  1051,
     978,   978,   978,   978,   978,   978,  1033,   978,  1045,  1042,
    1048,    10,    11,   981,    10,    11,   984,   978,   251,   255,
     259,   375,   377,   379,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,  1052,  1053,  1054,
    1056,  1057,  1060,  1061,  1064,  1065,  1068,  1069,  1071,  1072,
    1074,  1075,  1077,  1078,  1080,  1081,  1084,  1085,  1089,  1090,
    1092,  1093,  1095,  1096,  1098,  1099,  1101,  1102,  1104,  1107,
    1108,  1110,  1111,  1113,  1114,  1052,  1052,   352,  1011,    10,
      11,   141,   142,   428,   957,   960,   961,   962,  1024,  1026,
    1027,     8,   676,   676,     6,    79,   604,    80,    10,    11,
      19,    20,   646,   648,   650,   651,   248,   315,  1118,  1119,
       8,    10,    11,   584,   585,   586,     6,   574,     8,   250,
     251,   559,   561,   562,    49,    51,   484,   485,    55,     8,
      57,     8,     8,     8,    59,     8,     8,    61,     3,    72,
     524,   525,    74,   539,   540,   206,   721,   717,   718,     8,
       8,     8,     6,     6,   978,   978,   978,   978,   330,   332,
     334,   978,   336,   978,   338,   340,   978,   344,   346,   348,
      10,    11,   197,   201,  1031,  1034,  1035,  1036,   354,   356,
     978,   358,   978,   360,   978,   362,   364,   978,  1105,   370,
      22,   197,   663,   197,  1059,   197,  1063,   197,  1067,  1052,
    1070,  1052,  1073,   978,  1076,  1052,  1079,   426,  1082,  1088,
    1086,  1088,    10,    11,  1091,  1052,  1094,  1052,  1097,  1052,
    1100,  1052,  1103,  1052,  1109,   978,  1112,  1052,  1115,   372,
     374,   368,     3,     3,     8,   132,   606,    83,     8,     8,
       8,    10,    11,  1120,  1121,  1122,     6,   588,     8,   254,
     255,   573,   575,   576,   563,   564,    53,   492,    70,   486,
     487,     6,   674,     6,     6,     6,     6,     8,    63,   532,
     122,   526,   920,    65,   547,   541,   920,   209,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   245,   722,   723,
     724,   748,   749,   761,   762,   788,   789,   806,   807,   824,
     825,   837,   838,   855,   856,   873,   874,   886,   887,   890,
     891,    10,    11,   720,   163,   164,   182,   183,   184,   185,
     186,   187,   188,   189,   719,   925,   926,   927,   928,   929,
     935,   936,   941,   942,   943,   944,     8,     8,   322,   324,
     326,   328,   978,   350,   978,     8,     8,   366,  1106,     8,
       8,    10,    11,  1055,     8,    10,    11,  1058,     8,    10,
      11,  1062,     8,    10,    11,  1066,   376,  1052,   404,   406,
       3,    11,    11,   384,  1052,   388,  1052,  1052,   407,   409,
     411,   413,   415,   417,   419,   421,   423,   978,  1129,  1130,
    1131,  1132,  1137,  1138,  1140,  1141,  1143,  1146,  1147,  1149,
    1150,  1152,  1153,  1155,  1156,  1158,  1159,   978,   400,     8,
    1028,    11,     3,    10,    11,   607,   674,   674,     6,  1123,
       8,   258,   259,   587,   589,   590,   577,   578,    10,    11,
     566,    23,    24,    25,    26,    27,    29,   149,   150,   199,
     565,   664,   665,   667,   668,   671,   672,   919,   921,   934,
     945,   966,   967,   968,   488,   489,     8,     8,     8,     8,
       8,     8,     8,    10,    11,   527,   528,   529,    10,    11,
     542,   543,   544,   725,   726,   750,   751,   763,   764,   790,
     791,   808,   809,   826,   827,   839,   840,   857,   858,   875,
     876,   888,   951,   165,   892,   918,   207,     3,     8,     8,
       8,     8,     8,     8,     8,     8,   342,  1032,     6,   674,
     394,  1052,     6,     6,   402,     6,   252,     6,   256,     6,
     260,   378,     8,  1052,  1083,  1052,  1087,   386,   390,   392,
      11,   396,  1134,  1135,    11,    11,    11,    11,    11,    11,
      11,   978,     8,     8,   271,   608,   609,     8,     8,     8,
     314,   316,  1124,  1125,   591,   592,    10,    11,   580,    30,
      32,    33,   579,   666,   667,   669,   673,   919,   921,   934,
     945,   252,     8,     8,     8,     8,     8,     8,     3,     8,
      10,    11,   491,   490,   934,   957,     6,   120,   530,   678,
     679,   686,   545,   678,    11,   161,   162,   169,   727,   922,
     948,   949,   950,    11,   752,   922,   948,    11,   765,   922,
     948,    11,   792,   922,   948,    11,   810,   922,   948,    11,
     828,   922,   948,    11,   841,   922,   948,    11,   859,   922,
     948,    11,   877,   922,   948,    11,     8,    11,   893,   675,
     676,     6,     6,     6,     6,     6,     6,     6,   674,   350,
       8,     8,     8,     8,     8,     8,     8,   380,   382,  1144,
      10,    11,  1133,   192,   193,   939,   940,  1136,   978,  1139,
    1129,  1142,  1129,  1148,  1129,  1151,  1129,  1154,  1129,  1157,
    1129,  1160,   978,   610,    81,   263,   621,  1126,  1127,    10,
      11,   594,    31,   593,   664,   665,   667,   670,   671,   672,
     919,   921,   945,   256,     8,     8,     8,     6,     6,     6,
       6,     6,     6,     8,     6,    71,     8,   200,   924,    73,
     531,   112,   680,   681,    75,   546,   237,   728,   730,   731,
       3,     8,   730,   753,   730,   766,   730,   793,   730,   811,
     730,   829,   730,   842,   730,   860,   730,   878,  1052,     6,
     213,   895,   896,     8,     8,     8,     8,     8,     8,     8,
       8,     8,  1145,   414,     8,     8,   978,  1129,  1129,   412,
     408,  1129,   418,  1052,    10,    11,    21,   176,   611,   612,
     613,   614,   615,   622,   267,   633,    11,   932,   951,  1128,
     260,     8,     6,     6,     6,     8,     8,     8,     8,     8,
       8,     8,     8,    10,    11,   687,   688,   689,   682,   683,
     239,   729,   736,   737,    10,    11,   732,   733,   734,     8,
       6,   736,   754,   736,   767,   736,   794,   736,   812,   736,
     830,   736,   843,   736,   861,   736,   879,   246,   889,     8,
     215,   902,   903,   897,   920,   420,  1129,   674,   674,   424,
     416,   410,   422,   398,   272,   616,   617,   618,     8,     8,
      10,    11,    21,   170,   623,   624,   625,   626,   627,   634,
    1052,     6,     8,     8,     8,     6,     4,   121,    11,   685,
     198,   684,   933,   934,   220,   241,   742,   743,    10,    11,
     738,   739,   740,   678,   735,     8,   241,   755,   756,   224,
     241,   768,   769,   226,   241,   795,   796,   232,   241,   813,
     814,   234,   241,   831,   832,   230,   241,   844,   845,   228,
     241,   862,   863,   222,   241,   880,   881,   236,   909,   904,
     920,    10,    11,   898,   899,   900,     8,     8,   272,   617,
     269,     6,     6,   264,   628,   629,   630,     8,     8,    10,
      11,    21,   173,   635,   636,   637,   638,   649,   317,     8,
       8,   121,     6,     8,    10,    11,   744,   745,   746,   678,
     741,   238,    10,    11,   757,   758,   759,    10,    11,   770,
     771,   772,    10,    11,   797,   798,   799,    10,    11,   815,
     816,   817,    10,    11,   833,   834,   835,    10,    11,   846,
     847,   848,    10,    11,   864,   865,   866,    10,    11,   882,
     883,   884,   210,   211,   894,   910,   911,    10,    11,   905,
     906,   907,   678,   901,   197,   619,     8,     8,   264,   629,
     261,     6,     6,   268,   639,   640,   641,     8,     8,   113,
       6,   120,   690,   691,   696,   747,   240,   678,   760,   773,
     774,   800,   818,   678,   836,   849,   867,   700,   701,   885,
     912,   913,   678,   908,   214,     8,    10,    11,   620,   197,
     631,     8,     8,   268,   640,   265,     6,     6,     8,   924,
     112,   692,   693,   242,   242,   242,   112,   775,   776,   112,
     242,   801,   802,   112,   242,   819,   820,   242,   112,   242,
     850,   851,   112,   242,   868,   869,   112,   702,   703,   242,
      10,    11,   915,   916,   917,   190,   191,   914,   930,   931,
     954,   957,   216,     6,   270,     8,    10,    11,   632,   197,
     642,     8,     8,    10,    11,   697,   698,   699,   694,   934,
     777,   778,    10,    11,   803,   804,   805,    10,    11,   821,
     822,   823,   852,   870,   704,   934,   714,     8,     8,     8,
       6,   262,     8,    10,    11,   643,     4,   121,    11,   695,
      10,    11,   780,   781,   782,   178,   202,   779,   923,   938,
     978,  1130,    11,   143,   144,   853,   854,   933,   934,   963,
     964,   965,    10,    11,   871,   872,   934,   939,   940,    11,
     705,   212,     6,     6,     8,     6,   266,   121,   674,   783,
       8,     8,   113,   113,     6,     3,   113,     4,     8,     8,
       8,   113,   113,   243,   784,   785,     6,   674,   113,     8,
     113,   201,   786,   937,     8,     8,     8,    11,   787,   674,
       6,     8,   244
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_constant;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_varReference;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_linear;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType
                = ENUM_MATRIX_TYPE_realValuedExpressions;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType
                = ENUM_MATRIX_TYPE_complexValuedExpressions;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_objReference;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_conReference;
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
        osglData->valueType = ""; //ENUM_CONREFERENCE_VALUETYPE_value;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType
                = ENUM_MATRIX_TYPE_complexConstant;
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
//        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->inferredMatrixType = ENUM_MATRIX_TYPE_string;
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
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 811:

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
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new RealValuedExpressionTree();
    }
    break;

  case 816:

    {
        if (returnNlExprShape(osglData->shape) > 0)
            osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape 
                = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
        else
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
                "unknown shape specified in matrix transformation");
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
}
    break;

  case 952:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 955:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 956:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 957:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 960:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 961:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 962:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 965:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 966:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 967:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 970:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 972:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 975:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 978:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 981:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 984:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 986:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 989:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 991:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 993:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 995:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 999:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1002:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1005:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1008:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1010:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1011:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1013:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1015:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1018:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1021:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1024:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 1025:

    {               
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    #endif
    }
    break;

  case 1027:

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

  case 1034:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    #endif
        osnlData->tmpnlcount++;
    }
    break;

  case 1035:

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

  case 1036:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 1039:

    {
    #ifdef OSINSTANCE_AVAILABLE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    #endif
    }
    break;

  case 1040:

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

  case 1052:

    {
}
    break;

  case 1053:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1056:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}
    break;

  case 1062:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1065:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1067:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1068:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1070:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1072:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1075:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1078:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1081:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1084:

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
    long int ki;
    long int numChar;
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
    long int b64len = b64textend - b64textstart;
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


