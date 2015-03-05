
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

//#define CHECK_PARSE_TIME

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
     QUOTE = 258,
     ATTRIBUTETEXT = 259,
     ELEMENTTEXT = 260,
     ITEMTEXT = 261,
     INTEGER = 262,
     DOUBLE = 263,
     TWOQUOTES = 264,
     ENDOFELEMENT = 265,
     GREATERTHAN = 266,
     OSILEND = 267,
     INSTANCEDATAEND = 268,
     INSTANCEDATASTARTEND = 269,
     EMPTYIDATT = 270,
     IDXONEATT = 271,
     IDXTWOATT = 272,
     VALUEATT = 273,
     QUADRATICCOEFFICIENTSSTART = 274,
     QUADRATICCOEFFICIENTSEND = 275,
     NUMBEROFQTERMSATT = 276,
     QTERMSTART = 277,
     QTERMEND = 278,
     MATRICESSTART = 279,
     MATRICESEND = 280,
     NUMBEROFMATRICESATT = 281,
     CONESSTART = 282,
     CONESEND = 283,
     NUMBEROFCONESATT = 284,
     NONNEGATIVECONESTART = 285,
     NONNEGATIVECONEEND = 286,
     NONPOSITIVECONESTART = 287,
     NONPOSITIVECONEEND = 288,
     ORTHANTCONESTART = 289,
     ORTHANTCONEEND = 290,
     POLYHEDRALCONESTART = 291,
     POLYHEDRALCONEEND = 292,
     QUADRATICCONESTART = 293,
     QUADRATICCONEEND = 294,
     ROTATEDQUADRATICCONESTART = 295,
     ROTATEDQUADRATICCONEEND = 296,
     SEMIDEFINITECONESTART = 297,
     SEMIDEFINITECONEEND = 298,
     PRODUCTCONESTART = 299,
     PRODUCTCONEEND = 300,
     INTERSECTIONCONESTART = 301,
     INTERSECTIONCONEEND = 302,
     DUALCONESTART = 303,
     DUALCONEEND = 304,
     POLARCONESTART = 305,
     POLARCONEEND = 306,
     DIRECTIONSTART = 307,
     DIRECTIONEND = 308,
     FACTORSSTART = 309,
     FACTORSEND = 310,
     COMPONENTSSTART = 311,
     COMPONENTSEND = 312,
     NORMSCALEFACTORATT = 313,
     DISTORTIONMATRIXIDXATT = 314,
     AXISDIRECTIONATT = 315,
     FIRSTAXISDIRECTIONATT = 316,
     SECONDAXISDIRECTIONATT = 317,
     EMPTYSEMIDEFINITENESSATT = 318,
     SEMIDEFINITENESSATT = 319,
     REFERENCEMATRIXIDXATT = 320,
     MATRIXPROGRAMMINGSTART = 321,
     MATRIXPROGRAMMINGEND = 322,
     VARTYPEATT = 323,
     MATRIXVARIABLESSTART = 324,
     MATRIXVARIABLESEND = 325,
     NUMBEROFMATRIXVARATT = 326,
     MATRIXVARSTART = 327,
     MATRIXVAREND = 328,
     MATRIXOBJECTIVESSTART = 329,
     MATRIXOBJECTIVESEND = 330,
     NUMBEROFMATRIXOBJATT = 331,
     MATRIXOBJSTART = 332,
     MATRIXOBJEND = 333,
     MATRIXCONSTRAINTSSTART = 334,
     MATRIXCONSTRAINTSEND = 335,
     NUMBEROFMATRIXCONATT = 336,
     MATRIXCONSTART = 337,
     MATRIXCONEND = 338,
     MATRIXIDXATT = 339,
     LBMATRIXIDXATT = 340,
     LBCONEIDXATT = 341,
     UBMATRIXIDXATT = 342,
     UBCONEIDXATT = 343,
     TEMPLATEMATRIXIDXATT = 344,
     VARREFERENCEMATRIXIDXATT = 345,
     OBJREFERENCEMATRIXIDXATT = 346,
     CONREFERENCEMATRIXIDXATT = 347,
     ORDERCONEIDXATT = 348,
     CONSTANTMATRIXIDXATT = 349,
     TIMEDOMAINSTART = 350,
     TIMEDOMAINEND = 351,
     STAGESSTART = 352,
     STAGESEND = 353,
     STAGESTART = 354,
     STAGEEND = 355,
     NUMBEROFSTAGESATT = 356,
     HORIZONATT = 357,
     STARTATT = 358,
     VARIABLESSTART = 359,
     CONSTRAINTSSTART = 360,
     OBJECTIVESSTART = 361,
     VARIABLESEND = 362,
     CONSTRAINTSEND = 363,
     OBJECTIVESEND = 364,
     NUMBEROFVARIABLESATT = 365,
     NUMBEROFCONSTRAINTSATT = 366,
     NUMBEROFOBJECTIVESATT = 367,
     STARTIDXATT = 368,
     VARSTART = 369,
     VAREND = 370,
     CONSTART = 371,
     CONEND = 372,
     OBJSTART = 373,
     OBJEND = 374,
     INTERVALSTART = 375,
     INTERVALEND = 376,
     HEADERSTART = 377,
     HEADEREND = 378,
     FILENAMESTART = 379,
     FILENAMEEND = 380,
     FILENAMEEMPTY = 381,
     FILENAMESTARTANDEND = 382,
     FILESOURCESTART = 383,
     FILESOURCEEND = 384,
     FILESOURCEEMPTY = 385,
     FILESOURCESTARTANDEND = 386,
     FILEDESCRIPTIONSTART = 387,
     FILEDESCRIPTIONEND = 388,
     FILEDESCRIPTIONEMPTY = 389,
     FILEDESCRIPTIONSTARTANDEND = 390,
     FILECREATORSTART = 391,
     FILECREATOREND = 392,
     FILECREATOREMPTY = 393,
     FILECREATORSTARTANDEND = 394,
     FILELICENCESTART = 395,
     FILELICENCEEND = 396,
     FILELICENCEEMPTY = 397,
     FILELICENCESTARTANDEND = 398,
     ENUMERATIONSTART = 399,
     ENUMERATIONEND = 400,
     NUMBEROFELATT = 401,
     ITEMEMPTY = 402,
     ITEMSTART = 403,
     ITEMEND = 404,
     ITEMSTARTANDEND = 405,
     BASE64START = 406,
     BASE64END = 407,
     INCRATT = 408,
     MULTATT = 409,
     SIZEOFATT = 410,
     ELSTART = 411,
     ELEND = 412,
     MATRIXSTART = 413,
     MATRIXEND = 414,
     BASEMATRIXEND = 415,
     BASEMATRIXSTART = 416,
     BLOCKSTART = 417,
     BLOCKEND = 418,
     BLOCKSSTART = 419,
     BLOCKSEND = 420,
     EMPTYNAMEATT = 421,
     NAMEATT = 422,
     EMPTYTYPEATT = 423,
     TYPEATT = 424,
     EMPTYSHAPEATT = 425,
     SHAPEATT = 426,
     EMPTYSYMMETRYATT = 427,
     SYMMETRYATT = 428,
     EMPTYNEGATIVEPATTERNATT = 429,
     NEGATIVEPATTERNATT = 430,
     CONSTANTATT = 431,
     NUMBEROFBLOCKSATT = 432,
     NUMBEROFCOLUMNSATT = 433,
     NUMBEROFROWSATT = 434,
     NUMBEROFVALUESATT = 435,
     NUMBEROFVARIDXATT = 436,
     IDXATT = 437,
     COEFATT = 438,
     BASEMATRIXIDXATT = 439,
     TARGETMATRIXFIRSTROWATT = 440,
     TARGETMATRIXFIRSTCOLATT = 441,
     BASEMATRIXSTARTROWATT = 442,
     BASEMATRIXSTARTCOLATT = 443,
     BASEMATRIXENDROWATT = 444,
     BASEMATRIXENDCOLATT = 445,
     SCALARMULTIPLIERATT = 446,
     EMPTYBASETRANSPOSEATT = 447,
     BASETRANSPOSEATT = 448,
     ELEMENTSSTART = 449,
     ELEMENTSEND = 450,
     CONSTANTELEMENTSSTART = 451,
     CONSTANTELEMENTSEND = 452,
     STARTVECTORSTART = 453,
     STARTVECTOREND = 454,
     NONZEROSSTART = 455,
     NONZEROSEND = 456,
     INDEXESSTART = 457,
     INDEXESEND = 458,
     VALUESSTART = 459,
     VALUESEND = 460,
     VARREFERENCEELEMENTSSTART = 461,
     VARREFERENCEELEMENTSEND = 462,
     LINEARELEMENTSSTART = 463,
     LINEARELEMENTSEND = 464,
     GENERALELEMENTSSTART = 465,
     GENERALELEMENTSEND = 466,
     CONREFERENCEELEMENTSSTART = 467,
     CONREFERENCEELEMENTSEND = 468,
     VALUETYPEATT = 469,
     OBJREFERENCEELEMENTSSTART = 470,
     OBJREFERENCEELEMENTSEND = 471,
     PATTERNELEMENTSSTART = 472,
     PATTERNELEMENTSEND = 473,
     VARIDXSTART = 474,
     VARIDXEND = 475,
     TRANSFORMATIONSTART = 476,
     TRANSFORMATIONEND = 477,
     COLOFFSETSSTART = 478,
     COLOFFSETSEND = 479,
     ROWOFFSETSSTART = 480,
     ROWOFFSETSEND = 481,
     EMPTYROWMAJORATT = 482,
     ROWMAJORATT = 483,
     BLOCKROWIDXATT = 484,
     BLOCKCOLIDXATT = 485,
     DUMMY = 486,
     NONLINEAREXPRESSIONSSTART = 487,
     NONLINEAREXPRESSIONSEND = 488,
     NUMBEROFNONLINEAREXPRESSIONS = 489,
     NLSTART = 490,
     NLEND = 491,
     MATRIXEXPRESSIONSSTART = 492,
     MATRIXEXPRESSIONSEND = 493,
     NUMBEROFEXPR = 494,
     EXPRSTART = 495,
     EXPREND = 496,
     NUMBEROFMATRIXTERMSATT = 497,
     MATRIXTERMSTART = 498,
     MATRIXTERMEND = 499,
     POWERSTART = 500,
     POWEREND = 501,
     PLUSSTART = 502,
     PLUSEND = 503,
     MINUSSTART = 504,
     MINUSEND = 505,
     DIVIDESTART = 506,
     DIVIDEEND = 507,
     LNSTART = 508,
     LNEND = 509,
     SQRTSTART = 510,
     SQRTEND = 511,
     SUMSTART = 512,
     SUMEND = 513,
     PRODUCTSTART = 514,
     PRODUCTEND = 515,
     EXPSTART = 516,
     EXPEND = 517,
     NEGATESTART = 518,
     NEGATEEND = 519,
     IFSTART = 520,
     IFEND = 521,
     SQUARESTART = 522,
     SQUAREEND = 523,
     COSSTART = 524,
     COSEND = 525,
     SINSTART = 526,
     SINEND = 527,
     VARIABLESTART = 528,
     VARIABLEEND = 529,
     ABSSTART = 530,
     ABSEND = 531,
     ERFSTART = 532,
     ERFEND = 533,
     MAXSTART = 534,
     MAXEND = 535,
     ALLDIFFSTART = 536,
     ALLDIFFEND = 537,
     MINSTART = 538,
     MINEND = 539,
     ESTART = 540,
     EEND = 541,
     PISTART = 542,
     PIEND = 543,
     TIMESSTART = 544,
     TIMESEND = 545,
     NUMBERSTART = 546,
     NUMBEREND = 547,
     MATRIXDETERMINANTSTART = 548,
     MATRIXDETERMINANTEND = 549,
     MATRIXTRACESTART = 550,
     MATRIXTRACEEND = 551,
     MATRIXTOSCALARSTART = 552,
     MATRIXTOSCALAREND = 553,
     MATRIXDIAGONALSTART = 554,
     MATRIXDIAGONALEND = 555,
     MATRIXDOTTIMESSTART = 556,
     MATRIXDOTTIMESEND = 557,
     MATRIXLOWERTRIANGLESTART = 558,
     MATRIXLOWERTRIANGLEEND = 559,
     MATRIXUPPERTRIANGLESTART = 560,
     MATRIXUPPERTRIANGLEEND = 561,
     MATRIXMERGESTART = 562,
     MATRIXMERGEEND = 563,
     MATRIXMINUSSTART = 564,
     MATRIXMINUSEND = 565,
     MATRIXNEGATESTART = 566,
     MATRIXNEGATEEND = 567,
     MATRIXPLUSSTART = 568,
     MATRIXPLUSEND = 569,
     MATRIXTIMESSTART = 570,
     MATRIXTIMESEND = 571,
     MATRIXPRODUCTSTART = 572,
     MATRIXPRODUCTEND = 573,
     MATRIXSCALARTIMESSTART = 574,
     MATRIXSCALARTIMESEND = 575,
     MATRIXSUBMATRIXATSTART = 576,
     MATRIXSUBMATRIXATEND = 577,
     MATRIXTRANSPOSESTART = 578,
     MATRIXTRANSPOSEEND = 579,
     MATRIXREFERENCESTART = 580,
     MATRIXREFERENCEEND = 581,
     IDENTITYMATRIXSTART = 582,
     IDENTITYMATRIXEND = 583,
     MATRIXINVERSESTART = 584,
     MATRIXINVERSEEND = 585,
     EMPTYINCLUDEDIAGONALATT = 586,
     INCLUDEDIAGONALATT = 587,
     IDATT = 588
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define ELEMENTTEXT 260
#define ITEMTEXT 261
#define INTEGER 262
#define DOUBLE 263
#define TWOQUOTES 264
#define ENDOFELEMENT 265
#define GREATERTHAN 266
#define OSILEND 267
#define INSTANCEDATAEND 268
#define INSTANCEDATASTARTEND 269
#define EMPTYIDATT 270
#define IDXONEATT 271
#define IDXTWOATT 272
#define VALUEATT 273
#define QUADRATICCOEFFICIENTSSTART 274
#define QUADRATICCOEFFICIENTSEND 275
#define NUMBEROFQTERMSATT 276
#define QTERMSTART 277
#define QTERMEND 278
#define MATRICESSTART 279
#define MATRICESEND 280
#define NUMBEROFMATRICESATT 281
#define CONESSTART 282
#define CONESEND 283
#define NUMBEROFCONESATT 284
#define NONNEGATIVECONESTART 285
#define NONNEGATIVECONEEND 286
#define NONPOSITIVECONESTART 287
#define NONPOSITIVECONEEND 288
#define ORTHANTCONESTART 289
#define ORTHANTCONEEND 290
#define POLYHEDRALCONESTART 291
#define POLYHEDRALCONEEND 292
#define QUADRATICCONESTART 293
#define QUADRATICCONEEND 294
#define ROTATEDQUADRATICCONESTART 295
#define ROTATEDQUADRATICCONEEND 296
#define SEMIDEFINITECONESTART 297
#define SEMIDEFINITECONEEND 298
#define PRODUCTCONESTART 299
#define PRODUCTCONEEND 300
#define INTERSECTIONCONESTART 301
#define INTERSECTIONCONEEND 302
#define DUALCONESTART 303
#define DUALCONEEND 304
#define POLARCONESTART 305
#define POLARCONEEND 306
#define DIRECTIONSTART 307
#define DIRECTIONEND 308
#define FACTORSSTART 309
#define FACTORSEND 310
#define COMPONENTSSTART 311
#define COMPONENTSEND 312
#define NORMSCALEFACTORATT 313
#define DISTORTIONMATRIXIDXATT 314
#define AXISDIRECTIONATT 315
#define FIRSTAXISDIRECTIONATT 316
#define SECONDAXISDIRECTIONATT 317
#define EMPTYSEMIDEFINITENESSATT 318
#define SEMIDEFINITENESSATT 319
#define REFERENCEMATRIXIDXATT 320
#define MATRIXPROGRAMMINGSTART 321
#define MATRIXPROGRAMMINGEND 322
#define VARTYPEATT 323
#define MATRIXVARIABLESSTART 324
#define MATRIXVARIABLESEND 325
#define NUMBEROFMATRIXVARATT 326
#define MATRIXVARSTART 327
#define MATRIXVAREND 328
#define MATRIXOBJECTIVESSTART 329
#define MATRIXOBJECTIVESEND 330
#define NUMBEROFMATRIXOBJATT 331
#define MATRIXOBJSTART 332
#define MATRIXOBJEND 333
#define MATRIXCONSTRAINTSSTART 334
#define MATRIXCONSTRAINTSEND 335
#define NUMBEROFMATRIXCONATT 336
#define MATRIXCONSTART 337
#define MATRIXCONEND 338
#define MATRIXIDXATT 339
#define LBMATRIXIDXATT 340
#define LBCONEIDXATT 341
#define UBMATRIXIDXATT 342
#define UBCONEIDXATT 343
#define TEMPLATEMATRIXIDXATT 344
#define VARREFERENCEMATRIXIDXATT 345
#define OBJREFERENCEMATRIXIDXATT 346
#define CONREFERENCEMATRIXIDXATT 347
#define ORDERCONEIDXATT 348
#define CONSTANTMATRIXIDXATT 349
#define TIMEDOMAINSTART 350
#define TIMEDOMAINEND 351
#define STAGESSTART 352
#define STAGESEND 353
#define STAGESTART 354
#define STAGEEND 355
#define NUMBEROFSTAGESATT 356
#define HORIZONATT 357
#define STARTATT 358
#define VARIABLESSTART 359
#define CONSTRAINTSSTART 360
#define OBJECTIVESSTART 361
#define VARIABLESEND 362
#define CONSTRAINTSEND 363
#define OBJECTIVESEND 364
#define NUMBEROFVARIABLESATT 365
#define NUMBEROFCONSTRAINTSATT 366
#define NUMBEROFOBJECTIVESATT 367
#define STARTIDXATT 368
#define VARSTART 369
#define VAREND 370
#define CONSTART 371
#define CONEND 372
#define OBJSTART 373
#define OBJEND 374
#define INTERVALSTART 375
#define INTERVALEND 376
#define HEADERSTART 377
#define HEADEREND 378
#define FILENAMESTART 379
#define FILENAMEEND 380
#define FILENAMEEMPTY 381
#define FILENAMESTARTANDEND 382
#define FILESOURCESTART 383
#define FILESOURCEEND 384
#define FILESOURCEEMPTY 385
#define FILESOURCESTARTANDEND 386
#define FILEDESCRIPTIONSTART 387
#define FILEDESCRIPTIONEND 388
#define FILEDESCRIPTIONEMPTY 389
#define FILEDESCRIPTIONSTARTANDEND 390
#define FILECREATORSTART 391
#define FILECREATOREND 392
#define FILECREATOREMPTY 393
#define FILECREATORSTARTANDEND 394
#define FILELICENCESTART 395
#define FILELICENCEEND 396
#define FILELICENCEEMPTY 397
#define FILELICENCESTARTANDEND 398
#define ENUMERATIONSTART 399
#define ENUMERATIONEND 400
#define NUMBEROFELATT 401
#define ITEMEMPTY 402
#define ITEMSTART 403
#define ITEMEND 404
#define ITEMSTARTANDEND 405
#define BASE64START 406
#define BASE64END 407
#define INCRATT 408
#define MULTATT 409
#define SIZEOFATT 410
#define ELSTART 411
#define ELEND 412
#define MATRIXSTART 413
#define MATRIXEND 414
#define BASEMATRIXEND 415
#define BASEMATRIXSTART 416
#define BLOCKSTART 417
#define BLOCKEND 418
#define BLOCKSSTART 419
#define BLOCKSEND 420
#define EMPTYNAMEATT 421
#define NAMEATT 422
#define EMPTYTYPEATT 423
#define TYPEATT 424
#define EMPTYSHAPEATT 425
#define SHAPEATT 426
#define EMPTYSYMMETRYATT 427
#define SYMMETRYATT 428
#define EMPTYNEGATIVEPATTERNATT 429
#define NEGATIVEPATTERNATT 430
#define CONSTANTATT 431
#define NUMBEROFBLOCKSATT 432
#define NUMBEROFCOLUMNSATT 433
#define NUMBEROFROWSATT 434
#define NUMBEROFVALUESATT 435
#define NUMBEROFVARIDXATT 436
#define IDXATT 437
#define COEFATT 438
#define BASEMATRIXIDXATT 439
#define TARGETMATRIXFIRSTROWATT 440
#define TARGETMATRIXFIRSTCOLATT 441
#define BASEMATRIXSTARTROWATT 442
#define BASEMATRIXSTARTCOLATT 443
#define BASEMATRIXENDROWATT 444
#define BASEMATRIXENDCOLATT 445
#define SCALARMULTIPLIERATT 446
#define EMPTYBASETRANSPOSEATT 447
#define BASETRANSPOSEATT 448
#define ELEMENTSSTART 449
#define ELEMENTSEND 450
#define CONSTANTELEMENTSSTART 451
#define CONSTANTELEMENTSEND 452
#define STARTVECTORSTART 453
#define STARTVECTOREND 454
#define NONZEROSSTART 455
#define NONZEROSEND 456
#define INDEXESSTART 457
#define INDEXESEND 458
#define VALUESSTART 459
#define VALUESEND 460
#define VARREFERENCEELEMENTSSTART 461
#define VARREFERENCEELEMENTSEND 462
#define LINEARELEMENTSSTART 463
#define LINEARELEMENTSEND 464
#define GENERALELEMENTSSTART 465
#define GENERALELEMENTSEND 466
#define CONREFERENCEELEMENTSSTART 467
#define CONREFERENCEELEMENTSEND 468
#define VALUETYPEATT 469
#define OBJREFERENCEELEMENTSSTART 470
#define OBJREFERENCEELEMENTSEND 471
#define PATTERNELEMENTSSTART 472
#define PATTERNELEMENTSEND 473
#define VARIDXSTART 474
#define VARIDXEND 475
#define TRANSFORMATIONSTART 476
#define TRANSFORMATIONEND 477
#define COLOFFSETSSTART 478
#define COLOFFSETSEND 479
#define ROWOFFSETSSTART 480
#define ROWOFFSETSEND 481
#define EMPTYROWMAJORATT 482
#define ROWMAJORATT 483
#define BLOCKROWIDXATT 484
#define BLOCKCOLIDXATT 485
#define DUMMY 486
#define NONLINEAREXPRESSIONSSTART 487
#define NONLINEAREXPRESSIONSEND 488
#define NUMBEROFNONLINEAREXPRESSIONS 489
#define NLSTART 490
#define NLEND 491
#define MATRIXEXPRESSIONSSTART 492
#define MATRIXEXPRESSIONSEND 493
#define NUMBEROFEXPR 494
#define EXPRSTART 495
#define EXPREND 496
#define NUMBEROFMATRIXTERMSATT 497
#define MATRIXTERMSTART 498
#define MATRIXTERMEND 499
#define POWERSTART 500
#define POWEREND 501
#define PLUSSTART 502
#define PLUSEND 503
#define MINUSSTART 504
#define MINUSEND 505
#define DIVIDESTART 506
#define DIVIDEEND 507
#define LNSTART 508
#define LNEND 509
#define SQRTSTART 510
#define SQRTEND 511
#define SUMSTART 512
#define SUMEND 513
#define PRODUCTSTART 514
#define PRODUCTEND 515
#define EXPSTART 516
#define EXPEND 517
#define NEGATESTART 518
#define NEGATEEND 519
#define IFSTART 520
#define IFEND 521
#define SQUARESTART 522
#define SQUAREEND 523
#define COSSTART 524
#define COSEND 525
#define SINSTART 526
#define SINEND 527
#define VARIABLESTART 528
#define VARIABLEEND 529
#define ABSSTART 530
#define ABSEND 531
#define ERFSTART 532
#define ERFEND 533
#define MAXSTART 534
#define MAXEND 535
#define ALLDIFFSTART 536
#define ALLDIFFEND 537
#define MINSTART 538
#define MINEND 539
#define ESTART 540
#define EEND 541
#define PISTART 542
#define PIEND 543
#define TIMESSTART 544
#define TIMESEND 545
#define NUMBERSTART 546
#define NUMBEREND 547
#define MATRIXDETERMINANTSTART 548
#define MATRIXDETERMINANTEND 549
#define MATRIXTRACESTART 550
#define MATRIXTRACEEND 551
#define MATRIXTOSCALARSTART 552
#define MATRIXTOSCALAREND 553
#define MATRIXDIAGONALSTART 554
#define MATRIXDIAGONALEND 555
#define MATRIXDOTTIMESSTART 556
#define MATRIXDOTTIMESEND 557
#define MATRIXLOWERTRIANGLESTART 558
#define MATRIXLOWERTRIANGLEEND 559
#define MATRIXUPPERTRIANGLESTART 560
#define MATRIXUPPERTRIANGLEEND 561
#define MATRIXMERGESTART 562
#define MATRIXMERGEEND 563
#define MATRIXMINUSSTART 564
#define MATRIXMINUSEND 565
#define MATRIXNEGATESTART 566
#define MATRIXNEGATEEND 567
#define MATRIXPLUSSTART 568
#define MATRIXPLUSEND 569
#define MATRIXTIMESSTART 570
#define MATRIXTIMESEND 571
#define MATRIXPRODUCTSTART 572
#define MATRIXPRODUCTEND 573
#define MATRIXSCALARTIMESSTART 574
#define MATRIXSCALARTIMESEND 575
#define MATRIXSUBMATRIXATSTART 576
#define MATRIXSUBMATRIXATEND 577
#define MATRIXTRANSPOSESTART 578
#define MATRIXTRANSPOSEEND 579
#define MATRIXREFERENCESTART 580
#define MATRIXREFERENCEEND 581
#define IDENTITYMATRIXSTART 582
#define IDENTITYMATRIXEND 583
#define MATRIXINVERSESTART 584
#define MATRIXINVERSEEND 585
#define EMPTYINCLUDEDIAGONALATT 586
#define INCLUDEDIAGONALATT 587
#define IDATT 588




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
#define YYLAST   1244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  338
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  689
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1012
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1585

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   588

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   335,
     337,     2,     2,   336,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   334,     2,     2,     2,     2,     2,     2,     2,
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
     325,   326,   327,   328,   329,   330,   331,   332,   333
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
     526,   528,   530,   533,   534,   538,   540,   542,   544,   546,
     548,   552,   554,   555,   558,   562,   564,   566,   567,   570,
     572,   574,   576,   578,   580,   582,   584,   586,   589,   590,
     594,   596,   598,   600,   602,   604,   608,   610,   611,   614,
     618,   620,   622,   623,   626,   628,   630,   632,   634,   636,
     638,   640,   642,   644,   646,   649,   650,   653,   655,   657,
     659,   661,   664,   668,   672,   677,   679,   685,   687,   690,
     691,   696,   697,   701,   703,   707,   711,   712,   716,   717,
     720,   722,   724,   729,   734,   736,   740,   742,   745,   747,
     750,   751,   756,   761,   763,   766,   767,   771,   772,   775,
     777,   779,   784,   789,   791,   795,   797,   800,   802,   805,
     806,   811,   816,   818,   821,   822,   826,   827,   830,   832,
     834,   839,   841,   845,   847,   850,   852,   855,   856,   861,
     866,   868,   871,   872,   877,   879,   882,   883,   886,   888,
     890,   895,   900,   905,   910,   915,   920,   925,   930,   935,
     940,   945,   950,   955,   959,   964,   969,   974,   979,   984,
     989,   994,   999,  1004,  1009,  1014,  1018,  1022,  1026,  1029,
    1030,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1046,  1049,
    1053,  1055,  1057,  1058,  1061,  1063,  1065,  1069,  1073,  1075,
    1077,  1080,  1082,  1086,  1088,  1090,  1091,  1094,  1098,  1100,
    1101,  1103,  1107,  1111,  1113,  1115,  1118,  1120,  1124,  1128,
    1130,  1132,  1133,  1136,  1138,  1140,  1142,  1144,  1146,  1150,
    1154,  1158,  1160,  1162,  1164,  1168,  1171,  1172,  1176,  1178,
    1180,  1181,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,
    1200,  1202,  1207,  1212,  1217,  1222,  1227,  1232,  1237,  1239,
    1241,  1243,  1245,  1249,  1254,  1257,  1259,  1260,  1263,  1265,
    1267,  1269,  1271,  1273,  1275,  1277,  1279,  1284,  1286,  1288,
    1289,  1292,  1294,  1296,  1300,  1301,  1304,  1307,  1309,  1311,
    1313,  1315,  1319,  1321,  1324,  1326,  1328,  1330,  1332,  1336,
    1338,  1341,  1343,  1345,  1347,  1349,  1353,  1355,  1360,  1362,
    1364,  1365,  1368,  1370,  1372,  1376,  1377,  1380,  1383,  1385,
    1387,  1389,  1391,  1395,  1397,  1400,  1402,  1404,  1406,  1408,
    1412,  1414,  1417,  1419,  1421,  1423,  1425,  1429,  1431,  1436,
    1438,  1440,  1441,  1444,  1446,  1448,  1452,  1453,  1456,  1459,
    1461,  1463,  1465,  1467,  1471,  1473,  1476,  1478,  1480,  1482,
    1484,  1488,  1490,  1491,  1494,  1496,  1498,  1500,  1502,  1506,
    1508,  1509,  1512,  1516,  1518,  1520,  1521,  1524,  1526,  1528,
    1533,  1535,  1537,  1539,  1543,  1544,  1547,  1551,  1553,  1554,
    1559,  1563,  1568,  1570,  1572,  1573,  1576,  1578,  1580,  1584,
    1585,  1588,  1591,  1593,  1595,  1597,  1599,  1603,  1605,  1608,
    1610,  1612,  1614,  1616,  1620,  1622,  1623,  1626,  1628,  1630,
    1632,  1634,  1638,  1639,  1642,  1645,  1647,  1649,  1651,  1653,
    1657,  1662,  1664,  1666,  1667,  1670,  1672,  1674,  1678,  1679,
    1682,  1685,  1687,  1689,  1691,  1693,  1697,  1699,  1702,  1704,
    1706,  1708,  1710,  1714,  1716,  1717,  1720,  1722,  1724,  1726,
    1728,  1732,  1733,  1736,  1740,  1742,  1743,  1746,  1748,  1750,
    1752,  1756,  1760,  1765,  1767,  1769,  1770,  1773,  1775,  1777,
    1781,  1782,  1785,  1788,  1790,  1792,  1794,  1796,  1800,  1802,
    1805,  1807,  1809,  1811,  1813,  1817,  1819,  1822,  1824,  1826,
    1828,  1830,  1834,  1836,  1842,  1844,  1845,  1847,  1849,  1853,
    1855,  1857,  1863,  1865,  1869,  1871,  1873,  1875,  1877,  1879,
    1883,  1885,  1889,  1891,  1893,  1895,  1897,  1899,  1903,  1905,
    1906,  1909,  1913,  1915,  1917,  1918,  1921,  1923,  1925,  1927,
    1929,  1934,  1939,  1941,  1943,  1945,  1949,  1952,  1957,  1962,
    1967,  1972,  1977,  1982,  1987,  1992,  1997,  2001,  2005,  2010,
    2014,  2016,  2018,  2020,  2024,  2025,  2030,  2032,  2038,  2039,
    2042,  2048,  2050,  2052,  2053,  2056,  2058,  2060,  2062,  2064,
    2066,  2068,  2070,  2072,  2074,  2076,  2078,  2080,  2082,  2084,
    2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,  2104,
    2106,  2108,  2110,  2112,  2114,  2115,  2119,  2121,  2124,  2125,
    2129,  2131,  2134,  2135,  2141,  2142,  2148,  2149,  2155,  2156,
    2161,  2162,  2168,  2169,  2175,  2176,  2181,  2182,  2187,  2188,
    2193,  2194,  2199,  2200,  2205,  2206,  2211,  2212,  2217,  2218,
    2223,  2224,  2231,  2232,  2237,  2238,  2243,  2244,  2249,  2250,
    2255,  2257,  2260,  2261,  2264,  2266,  2268,  2270,  2271,  2276,
    2277,  2282,  2287,  2288,  2293,  2295,  2298,  2299,  2304,  2305,
    2308,  2310,  2312,  2317,  2322,  2323,  2328,  2329,  2332,  2333,
    2338,  2339,  2342,  2343,  2348,  2349,  2352,  2353,  2358,  2359,
    2362,  2363,  2368,  2369,  2372,  2374,  2376,  2378,  2380,  2382,
    2384,  2386,  2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,
    2404,  2406,  2408,  2410,  2414,  2416,  2418,  2421,  2426,  2430,
    2432,  2434,  2437,  2442,  2446,  2448,  2450,  2453,  2458,  2462,
    2464,  2466,  2469,  2474,  2477,  2479,  2482,  2485,  2487,  2491,
    2494,  2496,  2499,  2502,  2504,  2507,  2512,  2514,  2515,  2517,
    2520,  2525,  2527,  2528,  2530,  2533,  2537,  2540,  2542,  2544,
    2547,  2550,  2552,  2556,  2559,  2561,  2564,  2567,  2569,  2573,
    2576,  2578,  2582,  2583,  2588,  2589,  2592,  2595,  2597,  2601,
    2604,  2606,  2613,  2616,  2618,  2621,  2622,  2626,  2628,  2630,
    2635,  2637,  2639,  2641,  2645,  2646,  2649,  2655,  2657,  2659,
    2660,  2663,  2665
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     339,     0,    -1,   343,   865,   356,   363,   453,   500,   340,
     341,    -1,    14,    -1,    13,    -1,   342,    -1,    12,    -1,
      -1,    -1,   344,   345,   346,    20,    -1,    19,    -1,    21,
       3,     7,     3,    11,    -1,    -1,   346,   347,    -1,   348,
     350,   349,    -1,    22,    -1,    10,    -1,    11,    23,    -1,
      -1,   350,   351,    -1,   352,    -1,   353,    -1,   354,    -1,
     355,    -1,    16,     3,     7,     3,    -1,    17,     3,     7,
       3,    -1,   183,     3,   580,     3,    -1,   182,     3,     7,
       3,    -1,    -1,   357,   358,   359,    -1,    24,    -1,   557,
      -1,   360,    -1,   361,    -1,    10,    -1,    11,   362,    25,
      -1,    -1,   362,   606,    -1,    -1,   364,   365,   366,    -1,
      27,    -1,   558,    -1,   367,    -1,   368,    -1,    10,    -1,
      11,   369,    28,    -1,    -1,   369,   370,    -1,   371,    -1,
     377,    -1,   383,    -1,   398,    -1,   405,    -1,   411,    -1,
     417,    -1,   423,    -1,   438,    -1,   372,   373,   376,    -1,
      30,    -1,   374,    -1,    -1,   374,   375,    -1,   852,    -1,
     850,    -1,   858,    -1,    10,    -1,    11,    31,    -1,   378,
     379,   382,    -1,    32,    -1,   380,    -1,    -1,   380,   381,
      -1,   852,    -1,   850,    -1,   858,    -1,    10,    -1,    11,
      33,    -1,   384,   385,   388,    -1,    34,    -1,   386,    -1,
      -1,   386,   387,    -1,   852,    -1,   850,    -1,   858,    -1,
      10,    -1,    11,   389,   397,    -1,   390,    -1,    -1,   390,
     391,    -1,   392,   393,   396,    -1,    52,    -1,   394,    -1,
      -1,   394,   395,    -1,   859,    -1,   857,    -1,    10,    -1,
      11,    53,    -1,    35,    -1,   399,   400,   404,    -1,    36,
      -1,   401,    -1,    -1,   401,   402,    -1,   852,    -1,   850,
      -1,   403,    -1,   858,    -1,    65,     3,     7,     3,    -1,
      10,    -1,    11,    37,    -1,   406,   407,   410,    -1,    38,
      -1,   408,    -1,    -1,   408,   409,    -1,   852,    -1,   850,
      -1,   858,    -1,   563,    -1,   562,    -1,   564,    -1,    10,
      -1,    11,    39,    -1,   412,   413,   416,    -1,    40,    -1,
     414,    -1,    -1,   414,   415,    -1,   852,    -1,   850,    -1,
     858,    -1,   563,    -1,   562,    -1,   565,    -1,   566,    -1,
      10,    -1,    11,    41,    -1,   418,   419,   422,    -1,    42,
      -1,   420,    -1,    -1,   420,   421,    -1,   852,    -1,   850,
      -1,   858,    -1,   567,    -1,    10,    -1,    11,    43,    -1,
     424,   425,   428,    -1,    44,    -1,   426,    -1,    -1,   426,
     427,    -1,   852,    -1,   850,    -1,   858,    -1,    11,   429,
     437,    -1,   430,   431,   432,    -1,    54,    -1,   851,    -1,
     433,    -1,   434,    -1,    10,    -1,    11,   435,   436,    -1,
     584,    -1,    55,    -1,    45,    -1,   439,   440,   443,    -1,
      46,    -1,   441,    -1,    -1,   441,   442,    -1,   852,    -1,
     850,    -1,   858,    -1,    11,   444,   452,    -1,   445,   446,
     447,    -1,    56,    -1,   851,    -1,   448,    -1,   449,    -1,
      10,    -1,    11,   450,   451,    -1,   584,    -1,    57,    -1,
      47,    -1,    -1,   454,   455,    -1,    66,    -1,   456,    -1,
     457,    -1,    10,    -1,    11,   458,   472,   486,  1014,    67,
      -1,    -1,   459,   460,   461,    -1,    69,    -1,   559,    -1,
     462,    -1,   463,    -1,    10,    -1,    11,   465,   464,    -1,
      70,    -1,    -1,   465,   466,    -1,   467,   468,   471,    -1,
      72,    -1,   469,    -1,    -1,   469,   470,    -1,   852,    -1,
     850,    -1,   572,    -1,   573,    -1,   569,    -1,   576,    -1,
     570,    -1,   577,    -1,   858,    -1,   579,    -1,    10,    -1,
      11,    73,    -1,    -1,   473,   474,   475,    -1,    74,    -1,
     560,    -1,   476,    -1,   477,    -1,    10,    -1,    11,   479,
     478,    -1,    75,    -1,    -1,   479,   480,    -1,   481,   482,
     485,    -1,    77,    -1,   483,    -1,    -1,   483,   484,    -1,
     852,    -1,   850,    -1,   572,    -1,   574,    -1,   578,    -1,
     571,    -1,   858,    -1,    10,    -1,    11,    78,    -1,    -1,
     487,   488,   489,    -1,    79,    -1,   561,    -1,   490,    -1,
     491,    -1,    10,    -1,    11,   493,   492,    -1,    80,    -1,
      -1,   493,   494,    -1,   495,   496,   499,    -1,    82,    -1,
     497,    -1,    -1,   497,   498,    -1,   852,    -1,   850,    -1,
     572,    -1,   575,    -1,   569,    -1,   576,    -1,   570,    -1,
     577,    -1,   858,    -1,    10,    -1,    11,    83,    -1,    -1,
     501,   502,    -1,    95,    -1,   503,    -1,   504,    -1,    10,
      -1,    11,    96,    -1,    11,   505,    96,    -1,    11,   549,
      96,    -1,   506,   507,   508,    98,    -1,    97,    -1,   101,
       3,     7,     3,    11,    -1,   509,    -1,   508,   509,    -1,
      -1,   510,    99,   511,   512,    -1,    -1,   167,     4,     3,
      -1,    10,    -1,    11,   513,   100,    -1,   514,   526,   538,
      -1,    -1,   104,   515,   519,    -1,    -1,   515,   516,    -1,
     517,    -1,   518,    -1,   110,     3,     7,     3,    -1,   113,
       3,     7,     3,    -1,   520,    -1,    11,   521,   107,    -1,
      10,    -1,    11,   107,    -1,   522,    -1,   521,   522,    -1,
      -1,   523,   114,   524,   525,    -1,   182,     3,     7,     3,
      -1,    10,    -1,    11,   115,    -1,    -1,   105,   527,   531,
      -1,    -1,   527,   528,    -1,   529,    -1,   530,    -1,   111,
       3,     7,     3,    -1,   113,     3,     7,     3,    -1,   532,
      -1,    11,   533,   108,    -1,    10,    -1,    11,   108,    -1,
     534,    -1,   533,   534,    -1,    -1,   535,   116,   536,   537,
      -1,   182,     3,     7,     3,    -1,    10,    -1,    11,   117,
      -1,    -1,   106,   539,   542,    -1,    -1,   539,   540,    -1,
     541,    -1,   554,    -1,   112,     3,     7,     3,    -1,   543,
      -1,    11,   544,   109,    -1,    10,    -1,    11,   109,    -1,
     545,    -1,   544,   545,    -1,    -1,   546,   118,   547,   548,
      -1,   182,     3,     7,     3,    -1,    10,    -1,    11,   119,
      -1,    -1,   550,   120,   552,   551,    -1,    10,    -1,    11,
     121,    -1,    -1,   552,   553,    -1,   555,    -1,   556,    -1,
     113,     3,     7,     3,    -1,   102,     3,   580,     3,    -1,
     103,     3,   580,     3,    -1,    26,     3,     7,     3,    -1,
      29,     3,     7,     3,    -1,    71,     3,     7,     3,    -1,
      76,     3,     7,     3,    -1,    81,     3,     7,     3,    -1,
      58,     3,   580,     3,    -1,    59,     3,     7,     3,    -1,
      60,     3,     7,     3,    -1,    61,     3,     7,     3,    -1,
      62,     3,     7,     3,    -1,    64,     4,     3,    -1,    84,
       3,     7,     3,    -1,    85,     3,     7,     3,    -1,    87,
       3,     7,     3,    -1,    94,     3,     7,     3,    -1,    89,
       3,     7,     3,    -1,    90,     3,     7,     3,    -1,    91,
       3,     7,     3,    -1,    92,     3,     7,     3,    -1,    86,
       3,     7,     3,    -1,    88,     3,     7,     3,    -1,    93,
       3,     7,     3,    -1,    68,     4,     3,    -1,   582,     7,
     582,    -1,   582,     8,   582,    -1,   582,     3,    -1,    -1,
     582,   583,    -1,   334,    -1,   335,    -1,   336,    -1,   337,
      -1,   585,    -1,   592,    -1,    -1,   585,   586,    -1,   587,
     588,   591,    -1,   156,    -1,   589,    -1,    -1,   589,   590,
      -1,   857,    -1,   856,    -1,    11,     7,   157,    -1,   151,
     855,   593,    -1,   594,    -1,   595,    -1,    11,   152,    -1,
      10,    -1,    11,     5,   152,    -1,   597,    -1,   602,    -1,
      -1,   597,   598,    -1,   599,   600,   601,    -1,   156,    -1,
      -1,   857,    -1,    11,   580,   157,    -1,   151,   855,   603,
      -1,   604,    -1,   605,    -1,    11,   152,    -1,    10,    -1,
      11,     5,   152,    -1,   607,   608,   614,    -1,   158,    -1,
     609,    -1,    -1,   609,   610,    -1,   611,    -1,   852,    -1,
     850,    -1,   612,    -1,   613,    -1,   173,     4,     3,    -1,
     167,     4,     3,    -1,   169,     4,     3,    -1,   615,    -1,
     616,    -1,    10,    -1,    11,   617,   159,    -1,   618,   636,
      -1,    -1,   619,   620,   635,    -1,   161,    -1,   621,    -1,
      -1,   621,   622,    -1,   623,    -1,   624,    -1,   625,    -1,
     626,    -1,   627,    -1,   628,    -1,   629,    -1,   630,    -1,
     634,    -1,   184,     3,     7,     3,    -1,   185,     3,     7,
       3,    -1,   186,     3,     7,     3,    -1,   187,     3,     7,
       3,    -1,   188,     3,     7,     3,    -1,   189,     3,     7,
       3,    -1,   190,     3,     7,     3,    -1,   631,    -1,   632,
      -1,   633,    -1,   192,    -1,   193,     4,   581,    -1,   191,
       3,   580,     3,    -1,    11,   160,    -1,    10,    -1,    -1,
     636,   637,    -1,   638,    -1,   663,    -1,   688,    -1,   728,
      -1,   789,    -1,   758,    -1,   814,    -1,   818,    -1,   639,
     640,    11,   643,    -1,   196,    -1,   641,    -1,    -1,   641,
     642,    -1,   853,    -1,   862,    -1,   645,   644,   197,    -1,
      -1,   651,   657,    -1,   646,   647,    -1,   198,    -1,   648,
      -1,   649,    -1,    10,    -1,    11,   650,   199,    -1,   584,
      -1,   652,   653,    -1,   202,    -1,   654,    -1,   655,    -1,
      10,    -1,    11,   656,   203,    -1,   584,    -1,   658,   659,
      -1,   204,    -1,   660,    -1,   661,    -1,    10,    -1,    11,
     662,   205,    -1,   596,    -1,   664,   665,    11,   668,    -1,
     206,    -1,   666,    -1,    -1,   666,   667,    -1,   853,    -1,
     862,    -1,   670,   669,   207,    -1,    -1,   676,   682,    -1,
     671,   672,    -1,   198,    -1,   673,    -1,   674,    -1,    10,
      -1,    11,   675,   199,    -1,   584,    -1,   677,   678,    -1,
     202,    -1,   679,    -1,   680,    -1,    10,    -1,    11,   681,
     203,    -1,   584,    -1,   683,   684,    -1,   204,    -1,   685,
      -1,   686,    -1,    10,    -1,    11,   687,   205,    -1,   584,
      -1,   689,   690,    11,   693,    -1,   208,    -1,   691,    -1,
      -1,   691,   692,    -1,   853,    -1,   862,    -1,   695,   694,
     209,    -1,    -1,   701,   707,    -1,   696,   697,    -1,   198,
      -1,   698,    -1,   699,    -1,    10,    -1,    11,   700,   199,
      -1,   584,    -1,   702,   703,    -1,   202,    -1,   704,    -1,
     705,    -1,    10,    -1,    11,   706,   203,    -1,   584,    -1,
      -1,   708,   709,    -1,   204,    -1,   710,    -1,   711,    -1,
      10,    -1,    11,   712,   205,    -1,   713,    -1,    -1,   713,
     714,    -1,   715,   716,   720,    -1,   156,    -1,   717,    -1,
      -1,   717,   718,    -1,   854,    -1,   719,    -1,   176,     3,
     580,     3,    -1,   721,    -1,   722,    -1,    10,    -1,    11,
     723,   157,    -1,    -1,   723,   724,    -1,   725,   726,   727,
      -1,   219,    -1,    -1,   183,     3,   580,     3,    -1,    11,
       7,   220,    -1,   729,   730,    11,   733,    -1,   210,    -1,
     731,    -1,    -1,   731,   732,    -1,   853,    -1,   862,    -1,
     735,   734,   211,    -1,    -1,   741,   747,    -1,   736,   737,
      -1,   198,    -1,   738,    -1,   739,    -1,    10,    -1,    11,
     740,   199,    -1,   584,    -1,   742,   743,    -1,   202,    -1,
     744,    -1,   745,    -1,    10,    -1,    11,   746,   203,    -1,
     584,    -1,    -1,   748,   749,    -1,   204,    -1,   750,    -1,
     751,    -1,    10,    -1,    11,   752,   205,    -1,    -1,   752,
     753,    -1,   754,   755,    -1,   156,    -1,   756,    -1,   757,
      -1,    10,    -1,    11,   874,   157,    -1,   759,   760,    11,
     763,    -1,   212,    -1,   761,    -1,    -1,   761,   762,    -1,
     853,    -1,   862,    -1,   765,   764,   213,    -1,    -1,   771,
     777,    -1,   766,   767,    -1,   198,    -1,   768,    -1,   769,
      -1,    10,    -1,    11,   770,   199,    -1,   584,    -1,   772,
     773,    -1,   202,    -1,   774,    -1,   775,    -1,    10,    -1,
      11,   776,   203,    -1,   584,    -1,    -1,   778,   779,    -1,
     204,    -1,   780,    -1,   781,    -1,    10,    -1,    11,   782,
     205,    -1,    -1,   782,   783,    -1,   784,   785,   788,    -1,
     156,    -1,    -1,   785,   786,    -1,   787,    -1,   857,    -1,
     856,    -1,   214,     4,     3,    -1,    11,     7,   157,    -1,
     790,   791,    11,   794,    -1,   215,    -1,   792,    -1,    -1,
     792,   793,    -1,   853,    -1,   862,    -1,   796,   795,   216,
      -1,    -1,   802,   808,    -1,   797,   798,    -1,   198,    -1,
     799,    -1,   800,    -1,    10,    -1,    11,   801,   199,    -1,
     584,    -1,   803,   804,    -1,   202,    -1,   805,    -1,   806,
      -1,    10,    -1,    11,   807,   203,    -1,   584,    -1,   809,
     810,    -1,   204,    -1,   811,    -1,   812,    -1,    10,    -1,
      11,   813,   205,    -1,   584,    -1,   815,   816,    11,   950,
     817,    -1,   221,    -1,    -1,   861,    -1,   222,    -1,   819,
     820,   821,    -1,   164,    -1,   849,    -1,    11,   823,   830,
     837,   822,    -1,   165,    -1,   824,   825,   826,    -1,   223,
      -1,   851,    -1,   827,    -1,   828,    -1,    10,    -1,    11,
     829,   224,    -1,   584,    -1,   831,   832,   833,    -1,   225,
      -1,   851,    -1,   834,    -1,   835,    -1,    10,    -1,    11,
     836,   226,    -1,   584,    -1,    -1,   837,   838,    -1,   839,
     840,   845,    -1,   162,    -1,   841,    -1,    -1,   841,   842,
      -1,   843,    -1,   844,    -1,   611,    -1,   613,    -1,   229,
     581,     7,   581,    -1,   230,   581,     7,   581,    -1,   846,
      -1,   847,    -1,    10,    -1,    11,   848,   163,    -1,   618,
     636,    -1,   177,     3,     7,     3,    -1,   178,     3,     7,
       3,    -1,   146,     3,     7,     3,    -1,   179,     3,     7,
       3,    -1,   180,     3,     7,     3,    -1,   181,     3,     7,
       3,    -1,   155,     3,     7,     3,    -1,   153,     3,     7,
       3,    -1,   154,     3,     7,     3,    -1,   167,     4,     3,
      -1,   169,     4,     3,    -1,   182,     3,     7,     3,    -1,
     171,     4,     3,    -1,   863,    -1,   864,    -1,   227,    -1,
     228,     4,     3,    -1,    -1,   866,   867,   868,   233,    -1,
     232,    -1,   234,     3,     7,     3,    11,    -1,    -1,   868,
     869,    -1,   870,   871,    11,   874,   236,    -1,   235,    -1,
     872,    -1,    -1,   872,   873,    -1,   860,    -1,   861,    -1,
     917,    -1,   927,    -1,   881,    -1,   883,    -1,   935,    -1,
     885,    -1,   887,    -1,   889,    -1,   891,    -1,   947,    -1,
     893,    -1,   895,    -1,   897,    -1,   901,    -1,   899,    -1,
     903,    -1,   909,    -1,   905,    -1,   907,    -1,   941,    -1,
     944,    -1,   875,    -1,   878,    -1,   938,    -1,   911,    -1,
     913,    -1,   915,    -1,    -1,   285,   876,   877,    -1,    10,
      -1,    11,   286,    -1,    -1,   287,   879,   880,    -1,    10,
      -1,    11,   288,    -1,    -1,   289,   882,   874,   874,   290,
      -1,    -1,   247,   884,   874,   874,   248,    -1,    -1,   249,
     886,   874,   874,   250,    -1,    -1,   263,   888,   874,   264,
      -1,    -1,   251,   890,   874,   874,   252,    -1,    -1,   245,
     892,   874,   874,   246,    -1,    -1,   253,   894,   874,   254,
      -1,    -1,   255,   896,   874,   256,    -1,    -1,   267,   898,
     874,   268,    -1,    -1,   269,   900,   874,   270,    -1,    -1,
     271,   902,   874,   272,    -1,    -1,   261,   904,   874,   262,
      -1,    -1,   275,   906,   874,   276,    -1,    -1,   277,   908,
     874,   278,    -1,    -1,   265,   910,   874,   874,   874,   266,
      -1,    -1,   293,   912,   950,   294,    -1,    -1,   295,   914,
     950,   296,    -1,    -1,   297,   916,   950,   298,    -1,    -1,
     291,   918,   920,   919,    -1,    10,    -1,    11,   292,    -1,
      -1,   920,   921,    -1,   922,    -1,   926,    -1,   924,    -1,
      -1,   169,     4,   923,     3,    -1,    -1,   333,     4,   925,
       3,    -1,    18,     3,   580,     3,    -1,    -1,   273,   928,
     931,   929,    -1,    10,    -1,    11,   274,    -1,    -1,    11,
     874,   930,   274,    -1,    -1,   931,   932,    -1,   933,    -1,
     934,    -1,   183,     3,   580,     3,    -1,   182,     3,     7,
       3,    -1,    -1,   257,   936,   937,   258,    -1,    -1,   937,
     874,    -1,    -1,   281,   939,   940,   282,    -1,    -1,   940,
     874,    -1,    -1,   279,   942,   943,   280,    -1,    -1,   943,
     874,    -1,    -1,   283,   945,   946,   284,    -1,    -1,   946,
     874,    -1,    -1,   259,   948,   949,   260,    -1,    -1,   949,
     874,    -1,   951,    -1,   954,    -1,   958,    -1,   962,    -1,
     966,    -1,   969,    -1,   975,    -1,   978,    -1,   982,    -1,
     987,    -1,   990,    -1,   993,    -1,   996,    -1,   999,    -1,
    1002,    -1,  1005,    -1,  1008,    -1,  1011,    -1,   972,    -1,
     952,   568,   953,    -1,   325,    -1,    10,    -1,    11,   326,
      -1,   182,     3,     7,     3,    -1,   955,   957,   956,    -1,
      72,    -1,    10,    -1,    11,    73,    -1,   182,     3,     7,
       3,    -1,   959,   961,   960,    -1,    77,    -1,    10,    -1,
      11,    78,    -1,   182,     3,     7,     3,    -1,   963,   965,
     964,    -1,    82,    -1,    10,    -1,    11,    83,    -1,   182,
       3,     7,     3,    -1,   967,   968,    -1,   299,    -1,   950,
     300,    -1,   970,   971,    -1,   301,    -1,   950,   950,   302,
      -1,   973,   974,    -1,   327,    -1,   874,   328,    -1,   976,
     977,    -1,   329,    -1,   950,   330,    -1,   979,   980,    11,
     981,    -1,   303,    -1,    -1,   986,    -1,   950,   304,    -1,
     983,   984,    11,   985,    -1,   305,    -1,    -1,   986,    -1,
     950,   306,    -1,   332,     4,     3,    -1,   988,   989,    -1,
     307,    -1,    10,    -1,    11,   308,    -1,   991,   992,    -1,
     309,    -1,   950,   950,   310,    -1,   994,   995,    -1,   311,
      -1,   950,   312,    -1,   997,   998,    -1,   313,    -1,   950,
     950,   314,    -1,  1000,  1001,    -1,   315,    -1,   950,   950,
     316,    -1,    -1,   317,  1003,  1004,   318,    -1,    -1,  1004,
     950,    -1,  1006,  1007,    -1,   319,    -1,   874,   950,   320,
      -1,  1009,  1010,    -1,   321,    -1,   874,   874,   874,   874,
     950,   322,    -1,  1012,  1013,    -1,   323,    -1,   950,   324,
      -1,    -1,  1015,  1016,  1018,    -1,   237,    -1,  1017,    -1,
     239,     3,     7,     3,    -1,  1019,    -1,  1020,    -1,    10,
      -1,    11,  1021,   238,    -1,    -1,  1021,  1022,    -1,  1023,
    1024,    11,   950,   241,    -1,   240,    -1,  1025,    -1,    -1,
    1025,  1026,    -1,   860,    -1,   861,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   389,   389,   392,   393,   395,   404,   405,   408,   409,
     413,   418,   428,   428,   430,   443,   449,   450,   453,   454,
     457,   460,   463,   466,   472,   479,   486,   494,   499,   499,
     507,   512,   520,   520,   522,   524,   531,   531,   534,   534,
     540,   546,   554,   554,   556,   558,   562,   562,   570,   571,
     572,   573,   574,   575,   577,   584,   585,   590,   592,   601,
     603,   603,   606,   611,   616,   621,   621,   623,   626,   635,
     637,   637,   640,   645,   650,   655,   655,   658,   660,   669,
     679,   679,   682,   687,   692,   698,   698,   704,   706,   706,
     708,   710,   717,   759,   760,   762,   762,   764,   764,   766,
     768,   770,   779,   781,   781,   784,   789,   794,   799,   804,
     815,   815,   819,   821,   833,   835,   835,   838,   843,   848,
     852,   857,   862,   869,   869,   871,   873,   886,   888,   888,
     891,   896,   901,   906,   911,   916,   921,   928,   928,   932,
     934,   944,   946,   946,   949,   954,   959,   963,   970,   970,
     984,   986,   995,   997,   997,  1000,  1005,  1010,  1015,  1017,
    1019,  1025,  1031,  1031,  1033,  1035,  1037,  1039,  1052,  1055,
    1057,  1066,  1068,  1068,  1071,  1076,  1081,  1086,  1088,  1090,
    1096,  1102,  1102,  1104,  1106,  1108,  1110,  1123,  1132,  1132,
    1134,  1139,  1139,  1141,  1144,  1146,  1146,  1153,  1158,  1168,
    1168,  1170,  1172,  1174,  1176,  1176,  1178,  1183,  1200,  1236,
    1236,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,
    1248,  1251,  1252,  1254,  1254,  1260,  1265,  1275,  1275,  1277,
    1279,  1281,  1283,  1283,  1285,  1290,  1304,  1330,  1330,  1333,
    1334,  1335,  1336,  1337,  1338,  1339,  1342,  1343,  1346,  1346,
    1352,  1357,  1367,  1367,  1369,  1371,  1373,  1375,  1375,  1377,
    1382,  1398,  1431,  1431,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1445,  1446,  1489,  1489,  1491,  1493,  1493,
    1495,  1496,  1499,  1500,  1503,  1554,  1556,  1570,  1571,  1573,
    1573,  1597,  1598,  1601,  1602,  1604,  1606,  1607,  1611,  1612,
    1614,  1615,  1617,  1636,  1647,  1654,  1659,  1660,  1662,  1663,
    1665,  1665,  1668,  1680,  1681,  1683,  1684,  1688,  1689,  1691,
    1692,  1694,  1713,  1724,  1731,  1736,  1737,  1739,  1740,  1742,
    1742,  1745,  1757,  1758,  1760,  1770,  1774,  1775,  1777,  1778,
    1780,  1799,  1806,  1811,  1812,  1814,  1815,  1817,  1817,  1820,
    1832,  1833,  1838,  1838,  1846,  1847,  1849,  1850,  1852,  1856,
    1862,  1873,  1878,  1893,  1904,  1915,  1923,  1931,  1950,  1961,
    1972,  1984,  1995,  2006,  2018,  2029,  2041,  2053,  2065,  2077,
    2089,  2101,  2113,  2125,  2137,  2150,  2164,  2165,  2172,  2174,
    2174,  2176,  2177,  2178,  2179,  2344,  2353,  2355,  2355,  2357,
    2359,  2368,  2370,  2370,  2372,  2372,  2374,  2391,  2394,  2394,
    2396,  2396,  2399,  2430,  2438,  2440,  2440,  2442,  2444,  2452,
    2452,  2454,  2471,  2473,  2473,  2475,  2475,  2477,  2571,  2580,
    2603,  2621,  2621,  2624,  2625,  2626,  2627,  2628,  2631,  2640,
    2649,  2658,  2658,  2660,  2662,  2670,  2672,  2672,  2678,  2696,
    2723,  2723,  2726,  2727,  2728,  2729,  2730,  2731,  2732,  2733,
    2734,  2736,  2752,  2764,  2776,  2788,  2800,  2814,  2828,  2835,
    2835,  2837,  2842,  2850,  2860,  2860,  2862,  2862,  2869,  2869,
    2869,  2869,  2870,  2870,  2870,  2870,  2872,  2874,  2883,  2889,
    2889,  2892,  2898,  2904,  2906,  2906,  2908,  2918,  2928,  2928,
    2930,  2932,  2934,  2937,  2948,  2955,  2955,  2957,  2959,  2961,
    2964,  2974,  2981,  2981,  2983,  2985,  2987,  2990,  2992,  3001,
    3007,  3007,  3010,  3016,  3022,  3024,  3024,  3026,  3036,  3046,
    3046,  3048,  3050,  3052,  3054,  3064,  3071,  3071,  3073,  3075,
    3077,  3080,  3090,  3097,  3097,  3099,  3101,  3103,  3105,  3107,
    3116,  3122,  3122,  3125,  3131,  3137,  3139,  3139,  3141,  3151,
    3162,  3162,  3164,  3166,  3168,  3171,  3181,  3188,  3188,  3190,
    3192,  3194,  3197,  3202,  3213,  3228,  3228,  3230,  3232,  3234,
    3236,  3236,  3238,  3245,  3251,  3262,  3262,  3265,  3266,  3268,
    3282,  3282,  3284,  3286,  3288,  3288,  3291,  3293,  3301,  3301,
    3308,  3315,  3317,  3326,  3332,  3332,  3335,  3341,  3347,  3349,
    3349,  3351,  3361,  3372,  3372,  3374,  3376,  3378,  3381,  3391,
    3398,  3398,  3400,  3402,  3404,  3406,  3407,  3409,  3424,  3424,
    3426,  3428,  3430,  3430,  3432,  3434,  3449,  3449,  3451,  3453,
    3463,  3465,  3474,  3480,  3480,  3483,  3489,  3495,  3497,  3497,
    3499,  3509,  3520,  3520,  3522,  3524,  3526,  3528,  3538,  3545,
    3545,  3547,  3549,  3551,  3555,  3560,  3571,  3587,  3587,  3589,
    3591,  3593,  3593,  3595,  3603,  3615,  3615,  3618,  3619,  3620,
    3622,  3637,  3661,  3663,  3672,  3678,  3678,  3681,  3687,  3693,
    3695,  3695,  3697,  3707,  3718,  3718,  3720,  3722,  3724,  3727,
    3737,  3744,  3744,  3746,  3748,  3750,  3753,  3763,  3770,  3770,
    3772,  3774,  3776,  3779,  3782,  3800,  3800,  3806,  3813,  3822,
    3829,  3836,  3838,  3840,  3852,  3858,  3864,  3864,  3866,  3868,
    3870,  3872,  3882,  3888,  3894,  3894,  3896,  3898,  3900,  3902,
    3902,  3904,  3910,  3923,  3925,  3925,  3928,  3929,  3930,  3938,
    3945,  3963,  3981,  3981,  3983,  3985,  3991,  3993,  4004,  4015,
    4026,  4037,  4048,  4059,  4066,  4076,  4087,  4096,  4105,  4115,
    4124,  4124,  4126,  4135,  4180,  4181,  4187,  4193,  4214,  4215,
    4217,  4225,  4244,  4251,  4251,  4254,  4260,  4265,  4266,  4267,
    4268,  4269,  4270,  4271,  4272,  4273,  4274,  4275,  4276,  4277,
    4278,  4279,  4280,  4281,  4282,  4283,  4284,  4285,  4286,  4287,
    4288,  4290,  4291,  4292,  4296,  4296,  4299,  4300,  4302,  4302,
    4305,  4306,  4310,  4310,  4315,  4315,  4320,  4320,  4325,  4325,
    4330,  4330,  4335,  4335,  4340,  4340,  4345,  4345,  4350,  4350,
    4355,  4355,  4360,  4360,  4365,  4365,  4370,  4370,  4377,  4377,
    4383,  4383,  4392,  4392,  4397,  4397,  4402,  4402,  4412,  4412,
    4417,  4418,  4420,  4421,  4423,  4424,  4425,  4429,  4428,  4438,
    4437,  4446,  4456,  4455,  4462,  4463,  4465,  4464,  4471,  4472,
    4475,  4481,  4489,  4496,  4516,  4516,  4527,  4527,  4530,  4530,
    4542,  4543,  4546,  4546,  4557,  4558,  4561,  4561,  4572,  4573,
    4576,  4576,  4586,  4587,  4593,  4594,  4595,  4596,  4597,  4598,
    4599,  4600,  4601,  4602,  4603,  4604,  4605,  4606,  4607,  4608,
    4609,  4610,  4611,  4614,  4619,  4626,  4627,  4629,  4637,  4642,
    4649,  4650,  4652,  4659,  4664,  4671,  4672,  4674,  4681,  4686,
    4693,  4694,  4696,  4703,  4705,  4711,  4713,  4715,  4721,  4723,
    4725,  4731,  4733,  4735,  4741,  4743,  4745,  4751,  4751,  4756,
    4758,  4760,  4766,  4766,  4771,  4773,  4782,  4784,  4789,  4789,
    4791,  4793,  4799,  4802,  4804,  4810,  4813,  4815,  4821,  4824,
    4826,  4832,  4836,  4835,  4847,  4847,  4854,  4856,  4862,  4864,
    4866,  4872,  4875,  4877,  4883,  4893,  4893,  4899,  4905,  4907,
    4922,  4922,  4924,  4926,  4928,  4928,  4930,  4938,  4957,  4963,
    4963,  4966,  4972
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUOTE", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "TWOQUOTES", "ENDOFELEMENT",
  "GREATERTHAN", "OSILEND", "INSTANCEDATAEND", "INSTANCEDATASTARTEND",
  "EMPTYIDATT", "IDXONEATT", "IDXTWOATT", "VALUEATT",
  "QUADRATICCOEFFICIENTSSTART", "QUADRATICCOEFFICIENTSEND",
  "NUMBEROFQTERMSATT", "QTERMSTART", "QTERMEND", "MATRICESSTART",
  "MATRICESEND", "NUMBEROFMATRICESATT", "CONESSTART", "CONESEND",
  "NUMBEROFCONESATT", "NONNEGATIVECONESTART", "NONNEGATIVECONEEND",
  "NONPOSITIVECONESTART", "NONPOSITIVECONEEND", "ORTHANTCONESTART",
  "ORTHANTCONEEND", "POLYHEDRALCONESTART", "POLYHEDRALCONEEND",
  "QUADRATICCONESTART", "QUADRATICCONEEND", "ROTATEDQUADRATICCONESTART",
  "ROTATEDQUADRATICCONEEND", "SEMIDEFINITECONESTART",
  "SEMIDEFINITECONEEND", "PRODUCTCONESTART", "PRODUCTCONEEND",
  "INTERSECTIONCONESTART", "INTERSECTIONCONEEND", "DUALCONESTART",
  "DUALCONEEND", "POLARCONESTART", "POLARCONEEND", "DIRECTIONSTART",
  "DIRECTIONEND", "FACTORSSTART", "FACTORSEND", "COMPONENTSSTART",
  "COMPONENTSEND", "NORMSCALEFACTORATT", "DISTORTIONMATRIXIDXATT",
  "AXISDIRECTIONATT", "FIRSTAXISDIRECTIONATT", "SECONDAXISDIRECTIONATT",
  "EMPTYSEMIDEFINITENESSATT", "SEMIDEFINITENESSATT",
  "REFERENCEMATRIXIDXATT", "MATRIXPROGRAMMINGSTART",
  "MATRIXPROGRAMMINGEND", "VARTYPEATT", "MATRIXVARIABLESSTART",
  "MATRIXVARIABLESEND", "NUMBEROFMATRIXVARATT", "MATRIXVARSTART",
  "MATRIXVAREND", "MATRIXOBJECTIVESSTART", "MATRIXOBJECTIVESEND",
  "NUMBEROFMATRIXOBJATT", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "NUMBEROFMATRIXCONATT",
  "MATRIXCONSTART", "MATRIXCONEND", "MATRIXIDXATT", "LBMATRIXIDXATT",
  "LBCONEIDXATT", "UBMATRIXIDXATT", "UBCONEIDXATT", "TEMPLATEMATRIXIDXATT",
  "VARREFERENCEMATRIXIDXATT", "OBJREFERENCEMATRIXIDXATT",
  "CONREFERENCEMATRIXIDXATT", "ORDERCONEIDXATT", "CONSTANTMATRIXIDXATT",
  "TIMEDOMAINSTART", "TIMEDOMAINEND", "STAGESSTART", "STAGESEND",
  "STAGESTART", "STAGEEND", "NUMBEROFSTAGESATT", "HORIZONATT", "STARTATT",
  "VARIABLESSTART", "CONSTRAINTSSTART", "OBJECTIVESSTART", "VARIABLESEND",
  "CONSTRAINTSEND", "OBJECTIVESEND", "NUMBEROFVARIABLESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOBJECTIVESATT", "STARTIDXATT",
  "VARSTART", "VAREND", "CONSTART", "CONEND", "OBJSTART", "OBJEND",
  "INTERVALSTART", "INTERVALEND", "HEADERSTART", "HEADEREND",
  "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND",
  "FILESOURCESTART", "FILESOURCEEND", "FILESOURCEEMPTY",
  "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND",
  "FILEDESCRIPTIONEMPTY", "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART",
  "FILECREATOREND", "FILECREATOREMPTY", "FILECREATORSTARTANDEND",
  "FILELICENCESTART", "FILELICENCEEND", "FILELICENCEEMPTY",
  "FILELICENCESTARTANDEND", "ENUMERATIONSTART", "ENUMERATIONEND",
  "NUMBEROFELATT", "ITEMEMPTY", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "BASE64START", "BASE64END", "INCRATT", "MULTATT", "SIZEOFATT", "ELSTART",
  "ELEND", "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART",
  "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYNAMEATT",
  "NAMEATT", "EMPTYTYPEATT", "TYPEATT", "EMPTYSHAPEATT", "SHAPEATT",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT",
  "NEGATIVEPATTERNATT", "CONSTANTATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFVALUESATT",
  "NUMBEROFVARIDXATT", "IDXATT", "COEFATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND", "VALUETYPEATT",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
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
  "orderConeIdxATT", "varTypeATT", "aNumber", "quote", "xmlWhiteSpace",
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
  "osglSymmetryATT", "osglMatrixNameATT", "osglMatrixTypeATT",
  "matrixContent", "matrixEmpty", "matrixLaden", "matrixBody",
  "baseMatrix", "baseMatrixStart", "baseMatrixAttributes",
  "baseMatrixAttList", "baseMatrixAtt", "osglBaseMatrixIdxATT",
  "osglTargetMatrixFirstRowATT", "osglTargetMatrixFirstColATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "baseTransposeAttribute", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent",
  "osglScalarMultiplierATT", "baseMatrixEnd", "matrixConstructorList",
  "matrixConstructor", "constantElements", "constantElementsStart",
  "constantElementsAttributes", "constantElementsAttList",
  "constantElementsAtt", "constantElementsContent",
  "constantElementsNonzeros", "constantElementsStartVector",
  "constantElementsStartVectorStart", "constantElementsStartVectorContent",
  "constantElementsStartVectorEmpty", "constantElementsStartVectorLaden",
  "constantElementsStartVectorBody", "constantElementsIndexes",
  "constantElementsIndexesStart", "constantElementsIndexesContent",
  "constantElementsIndexesEmpty", "constantElementsIndexesLaden",
  "constantElementsIndexesBody", "constantElementsValues",
  "constantElementsValuesStart", "constantElementsValuesContent",
  "constantElementsValuesEmpty", "constantElementsValuesLaden",
  "constantElementsValuesBody", "varReferenceElements",
  "varReferenceElementsStart", "varReferenceElementsAttributes",
  "varReferenceElementsAttList", "varReferenceElementsAtt",
  "varReferenceElementsContent", "varReferenceElementsNonzeros",
  "varReferenceElementsStartVector",
  "varReferenceElementsStartVectorStart",
  "varReferenceElementsStartVectorContent",
  "varReferenceElementsStartVectorEmpty",
  "varReferenceElementsStartVectorLaden",
  "varReferenceElementsStartVectorBody", "varReferenceElementsIndexes",
  "varReferenceElementsIndexesStart", "varReferenceElementsIndexesContent",
  "varReferenceElementsIndexesEmpty", "varReferenceElementsIndexesLaden",
  "varReferenceElementsIndexesBody", "varReferenceElementsValues",
  "varReferenceElementsValuesStart", "varReferenceElementsValuesContent",
  "varReferenceElementsValuesEmpty", "varReferenceElementsValuesLaden",
  "varReferenceElementsValuesBody", "linearElements",
  "linearElementsStart", "linearElementsAttributes",
  "linearElementsAttList", "linearElementsAtt", "linearElementsContent",
  "linearElementsNonzeros", "linearElementsStartVector",
  "linearElementsStartVectorStart", "linearElementsStartVectorContent",
  "linearElementsStartVectorEmpty", "linearElementsStartVectorLaden",
  "linearElementsStartVectorBody", "linearElementsIndexes",
  "linearElementsIndexesStart", "linearElementsIndexesContent",
  "linearElementsIndexesEmpty", "linearElementsIndexesLaden",
  "linearElementsIndexesBody", "linearElementsValues",
  "linearElementsValuesStart", "linearElementsValuesContent",
  "linearElementsValuesEmpty", "linearElementsValuesLaden",
  "linearElementsValuesBody", "linearElementsValuesElList",
  "linearElementsValuesEl", "linearElementsValuesElStart",
  "linearElementsValuesElAttributes", "linearElementsValuesElAttList",
  "linearElementsValuesElAtt", "osglConstantATT",
  "linearElementsValuesElContent", "linearElementsValuesElEmpty",
  "linearElementsValuesElLaden", "linearElementsValuesVarIdxList",
  "linearElementsValuesVarIdx", "linearElementsValuesVarIdxStart",
  "osglLinearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "generalElements",
  "generalElementsStart", "generalElementsAttributes",
  "generalElementsAttList", "generalElementsAtt", "generalElementsContent",
  "generalElementsNonzeros", "generalElementsStartVector",
  "generalElementsStartVectorStart", "generalElementsStartVectorContent",
  "generalElementsStartVectorEmpty", "generalElementsStartVectorLaden",
  "generalElementsStartVectorBody", "generalElementsIndexes",
  "generalElementsIndexesStart", "generalElementsIndexesContent",
  "generalElementsIndexesEmpty", "generalElementsIndexesLaden",
  "generalElementsIndexesBody", "generalElementsValues",
  "generalElementsValuesStart", "generalElementsValuesContent",
  "generalElementsValuesEmpty", "generalElementsValuesLaden",
  "generalElementsElList", "generalElementsEl", "generalElementsElStart",
  "generalElementsElContent", "generalElementsElEmpty",
  "generalElementsElLaden", "conReferenceElements",
  "conReferenceElementsStart", "conReferenceElementsAttributes",
  "conReferenceElementsAttList", "conReferenceElementsAtt",
  "conReferenceElementsContent", "conReferenceElementsNonzeros",
  "conReferenceElementsStartVector",
  "conReferenceElementsStartVectorStart",
  "conReferenceElementsStartVectorContent",
  "conReferenceElementsStartVectorEmpty",
  "conReferenceElementsStartVectorLaden",
  "conReferenceElementsStartVectorBody", "conReferenceElementsIndexes",
  "conReferenceElementsIndexesStart", "conReferenceElementsIndexesContent",
  "conReferenceElementsIndexesEmpty", "conReferenceElementsIndexesLaden",
  "conReferenceElementsIndexesBody", "conReferenceElementsValues",
  "conReferenceElementsValuesStart", "conReferenceElementsValuesContent",
  "conReferenceElementsValuesEmpty", "conReferenceElementsValuesLaden",
  "conReferenceElementsElList", "conReferenceElementsEl",
  "conReferenceElementsElStart", "conReferenceElementsElAttributeList",
  "conReferenceElementsElAttribute", "conReferenceElementsElValueTypeATT",
  "conReferenceElementsElContent", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsAttributes",
  "objReferenceElementsAttList", "objReferenceElementsAtt",
  "objReferenceElementsContent", "objReferenceElementsNonzeros",
  "objReferenceElementsStartVector",
  "objReferenceElementsStartVectorStart",
  "objReferenceElementsStartVectorContent",
  "objReferenceElementsStartVectorEmpty",
  "objReferenceElementsStartVectorLaden",
  "objReferenceElementsStartVectorBody", "objReferenceElementsIndexes",
  "objReferenceElementsIndexesStart", "objReferenceElementsIndexesContent",
  "objReferenceElementsIndexesEmpty", "objReferenceElementsIndexesLaden",
  "objReferenceElementsIndexesBody", "objReferenceElementsValues",
  "objReferenceElementsValuesStart", "objReferenceElementsValuesContent",
  "objReferenceElementsValuesEmpty", "objReferenceElementsValuesLaden",
  "objReferenceElementsValuesBody", "matrixTransformation",
  "matrixTransformationStart", "matrixTransformationShapeATT",
  "matrixTransformationEnd", "matrixBlocks", "matrixBlocksStart",
  "matrixBlocksAttributes", "matrixBlocksContent", "matrixBlocksEnd",
  "colOffsets", "colOffsetsStart", "colOffsetsNumberOfElAttribute",
  "colOffsetsContent", "colOffsetsEmpty", "colOffsetsLaden",
  "colOffsetsBody", "rowOffsets", "rowOffsetsStart",
  "rowOffsetsNumberOfElAttribute", "rowOffsetsContent", "rowOffsetsEmpty",
  "rowOffsetsLaden", "rowOffsetsBody", "blockList", "matrixBlock",
  "matrixBlockStart", "matrixBlockAttributes", "matrixBlockAttList",
  "matrixBlockAtt", "osglBlockRowIdxATT", "osglBlockColIdxATT",
  "matrixBlockContent", "blockEmpty", "blockLaden", "blockBody",
  "osglNumberOfBlocksATT", "osglNumberOfColumnsATT", "osglNumberOfElATT",
  "osglNumberOfRowsATT", "osglNumberOfValuesATT", "osglNumberOfVarIdxATT",
  "osglBase64SizeATT", "osglIncrATT", "osglMultATT", "osglNameATT",
  "osglTypeATT", "osglIdxATT", "osglShapeATT", "osglRowMajorATT",
  "rowMajorAttEmpty", "rowMajorAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "scalarExpressionTree", "nlstart", "nlAttributes", "nlAttributeList",
  "nlAttribute", "nlnode", "E", "$@6", "eend", "PI", "$@7", "piend",
  "times", "$@8", "plus", "$@9", "minus", "$@10", "negate", "$@11",
  "divide", "$@12", "power", "$@13", "ln", "$@14", "sqrt", "$@15",
  "square", "$@16", "cos", "$@17", "sin", "$@18", "exp", "$@19", "abs",
  "$@20", "erf", "$@21", "if", "$@22", "matrixDeterminant", "$@23",
  "matrixTrace", "$@24", "matrixToScalar", "$@25", "number", "$@26",
  "numberend", "anotherNumberATT", "numberATT", "numbertypeATT", "$@27",
  "numberidATT", "$@28", "numbervalueATT", "variable", "$@29",
  "variableend", "$@30", "anotherVariableATT", "variableATT",
  "variablecoefATT", "variableidxATT", "sum", "$@31", "anothersumnlnode",
  "allDiff", "$@32", "anotherallDiffnlnode", "max", "$@33",
  "anothermaxnlnode", "min", "$@34", "anotherminnlnode", "product", "$@35",
  "anotherproductnlnode", "OSnLMNode", "matrixReference",
  "matrixReferenceStart", "matrixReferenceEnd", "matrixVarReference",
  "matrixVarReferenceStart", "matrixVarReferenceEnd", "matrixVarIdxATT",
  "matrixObjReference", "matrixObjReferenceStart", "matrixObjReferenceEnd",
  "matrixObjIdxATT", "matrixConReference", "matrixConReferenceStart",
  "matrixConReferenceEnd", "matrixConIdxATT", "matrixDiagonal",
  "matrixDiagonalStart", "matrixDiagonalContent", "matrixDotTimes",
  "matrixDotTimesStart", "matrixDotTimesContent", "identityMatrix",
  "identityMatrixStart", "identityMatrixContent", "matrixInverse",
  "matrixInverseStart", "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixNegate", "matrixNegateStart",
  "matrixNegateContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@36",
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
     585,   586,   587,   588,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   338,   339,   340,   340,   341,   342,   342,   343,   343,
     344,   345,   346,   346,   347,   348,   349,   349,   350,   350,
     351,   351,   351,   351,   352,   353,   354,   355,   356,   356,
     357,   358,   359,   359,   360,   361,   362,   362,   363,   363,
     364,   365,   366,   366,   367,   368,   369,   369,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   371,   372,   373,
     374,   374,   375,   375,   375,   376,   376,   377,   378,   379,
     380,   380,   381,   381,   381,   382,   382,   383,   384,   385,
     386,   386,   387,   387,   387,   388,   388,   389,   390,   390,
     391,   392,   393,   394,   394,   395,   395,   396,   396,   397,
     398,   399,   400,   401,   401,   402,   402,   402,   402,   403,
     404,   404,   405,   406,   407,   408,   408,   409,   409,   409,
     409,   409,   409,   410,   410,   411,   412,   413,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   416,   416,   417,
     418,   419,   420,   420,   421,   421,   421,   421,   422,   422,
     423,   424,   425,   426,   426,   427,   427,   427,   428,   429,
     430,   431,   432,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   441,   442,   442,   442,   443,   444,   445,
     446,   447,   447,   448,   449,   450,   451,   452,   453,   453,
     454,   455,   455,   456,   457,   458,   458,   459,   460,   461,
     461,   462,   463,   464,   465,   465,   466,   467,   468,   469,
     469,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   471,   471,   472,   472,   473,   474,   475,   475,   476,
     477,   478,   479,   479,   480,   481,   482,   483,   483,   484,
     484,   484,   484,   484,   484,   484,   485,   485,   486,   486,
     487,   488,   489,   489,   490,   491,   492,   493,   493,   494,
     495,   496,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   499,   499,   500,   500,   501,   502,   502,
     503,   503,   504,   504,   505,   506,   507,   508,   508,   510,
     509,   511,   511,   512,   512,   513,   514,   514,   515,   515,
     516,   516,   517,   518,   519,   519,   520,   520,   521,   521,
     523,   522,   524,   525,   525,   526,   526,   527,   527,   528,
     528,   529,   530,   531,   531,   532,   532,   533,   533,   535,
     534,   536,   537,   537,   538,   538,   539,   539,   540,   540,
     541,   542,   542,   543,   543,   544,   544,   546,   545,   547,
     548,   548,   550,   549,   551,   551,   552,   552,   553,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   580,   581,   582,
     582,   583,   583,   583,   583,   584,   584,   585,   585,   586,
     587,   588,   589,   589,   590,   590,   591,   592,   593,   593,
     594,   594,   595,   596,   596,   597,   597,   598,   599,   600,
     600,   601,   602,   603,   603,   604,   604,   605,   606,   607,
     608,   609,   609,   610,   610,   610,   610,   610,   611,   612,
     613,   614,   614,   615,   616,   617,   618,   618,   619,   620,
     621,   621,   622,   622,   622,   622,   622,   622,   622,   622,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     631,   632,   633,   634,   635,   635,   636,   636,   637,   637,
     637,   637,   637,   637,   637,   637,   638,   639,   640,   641,
     641,   642,   642,   643,   644,   644,   645,   646,   647,   647,
     648,   649,   650,   651,   652,   653,   653,   654,   655,   656,
     657,   658,   659,   659,   660,   661,   662,   663,   664,   665,
     666,   666,   667,   667,   668,   669,   669,   670,   671,   672,
     672,   673,   674,   675,   676,   677,   678,   678,   679,   680,
     681,   682,   683,   684,   684,   685,   686,   687,   688,   689,
     690,   691,   691,   692,   692,   693,   694,   694,   695,   696,
     697,   697,   698,   699,   700,   701,   702,   703,   703,   704,
     705,   706,   707,   707,   708,   709,   709,   710,   711,   712,
     713,   713,   714,   715,   716,   717,   717,   718,   718,   719,
     720,   720,   721,   722,   723,   723,   724,   725,   726,   726,
     727,   728,   729,   730,   731,   731,   732,   732,   733,   734,
     734,   735,   736,   737,   737,   738,   739,   740,   741,   742,
     743,   743,   744,   745,   746,   747,   747,   748,   749,   749,
     750,   751,   752,   752,   753,   754,   755,   755,   756,   757,
     758,   759,   760,   761,   761,   762,   762,   763,   764,   764,
     765,   766,   767,   767,   768,   769,   770,   771,   772,   773,
     773,   774,   775,   776,   777,   777,   778,   779,   779,   780,
     781,   782,   782,   783,   784,   785,   785,   786,   786,   786,
     787,   788,   789,   790,   791,   792,   792,   793,   793,   794,
     795,   795,   796,   797,   798,   798,   799,   800,   801,   802,
     803,   804,   804,   805,   806,   807,   808,   809,   810,   810,
     811,   812,   813,   814,   815,   816,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   826,   827,   828,
     829,   830,   831,   832,   833,   833,   834,   835,   836,   837,
     837,   838,   839,   840,   841,   841,   842,   842,   842,   842,
     843,   844,   845,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   862,   863,   864,   865,   865,   866,   867,   868,   868,
     869,   870,   871,   872,   872,   873,   873,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   874,   874,   874,   874,
     874,   874,   874,   874,   876,   875,   877,   877,   879,   878,
     880,   880,   882,   881,   884,   883,   886,   885,   888,   887,
     890,   889,   892,   891,   894,   893,   896,   895,   898,   897,
     900,   899,   902,   901,   904,   903,   906,   905,   908,   907,
     910,   909,   912,   911,   914,   913,   916,   915,   918,   917,
     919,   919,   920,   920,   921,   921,   921,   923,   922,   925,
     924,   926,   928,   927,   929,   929,   930,   929,   931,   931,
     932,   932,   933,   934,   936,   935,   937,   937,   939,   938,
     940,   940,   942,   941,   943,   943,   945,   944,   946,   946,
     948,   947,   949,   949,   950,   950,   950,   950,   950,   950,
     950,   950,   950,   950,   950,   950,   950,   950,   950,   950,
     950,   950,   950,   951,   952,   953,   953,   568,   954,   955,
     956,   956,   957,   958,   959,   960,   960,   961,   962,   963,
     964,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   980,   980,   981,
     982,   983,   984,   984,   985,   986,   987,   988,   989,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1003,  1002,  1004,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1014,  1015,  1016,  1017,
    1018,  1018,  1019,  1020,  1021,  1021,  1022,  1023,  1024,  1025,
    1025,  1026,  1026
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
       1,     1,     2,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     1,     1,     1,
       1,     2,     3,     3,     4,     1,     5,     1,     2,     0,
       4,     0,     3,     1,     3,     3,     0,     3,     0,     2,
       1,     1,     4,     4,     1,     3,     1,     2,     1,     2,
       0,     4,     4,     1,     2,     0,     3,     0,     2,     1,
       1,     4,     4,     1,     3,     1,     2,     1,     2,     0,
       4,     4,     1,     2,     0,     3,     0,     2,     1,     1,
       4,     1,     3,     1,     2,     1,     2,     0,     4,     4,
       1,     2,     0,     4,     1,     2,     0,     2,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       2,     1,     3,     1,     1,     0,     2,     3,     1,     0,
       1,     3,     3,     1,     1,     2,     1,     3,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     1,     1,     3,     2,     0,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     3,     4,     2,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     4,     1,
       1,     0,     2,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     4,
       1,     1,     1,     3,     0,     2,     3,     1,     0,     4,
       3,     4,     1,     1,     0,     2,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       3,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     1,     5,     1,     0,     1,     1,     3,     1,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       4,     4,     1,     1,     1,     3,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     3,     4,     3,
       1,     1,     1,     3,     0,     4,     1,     5,     0,     2,
       5,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     2,     0,     3,
       1,     2,     0,     5,     0,     5,     0,     5,     0,     4,
       0,     5,     0,     5,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     6,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     2,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     4,     0,     4,     1,     2,     0,     4,     0,     2,
       1,     1,     4,     4,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     4,     3,     1,
       1,     2,     4,     3,     1,     1,     2,     4,     3,     1,
       1,     2,     4,     2,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     2,     4,     1,     0,     1,     2,
       4,     1,     0,     1,     2,     3,     2,     1,     1,     2,
       2,     1,     3,     2,     1,     2,     2,     1,     3,     2,
       1,     3,     0,     4,     0,     2,     2,     1,     3,     2,
       1,     6,     2,     1,     2,     0,     3,     1,     1,     4,
       1,     1,     1,     3,     0,     2,     5,     1,     1,     0,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,    10,     0,   774,     0,     1,   776,    28,     0,     0,
      12,    30,    38,     0,     0,   778,     0,     0,    40,   188,
       0,     0,     0,    31,     0,     0,     0,     9,    15,    13,
      18,   190,   275,     0,     0,     0,    41,     0,    34,    36,
      29,    32,    33,     0,   775,   781,   779,   783,     0,     0,
     277,     0,     0,   193,   195,   189,   191,   192,     0,    44,
      46,    39,    42,    43,     0,     0,     0,     0,   782,    11,
      16,     0,     0,     0,     0,     0,    14,    19,    20,    21,
      22,    23,     4,     3,     7,   280,   352,   276,   278,   279,
     197,   223,     0,     0,     0,   363,    35,   429,    37,   431,
     777,     0,     0,     0,   785,   786,   784,    17,     0,     0,
       0,   389,     6,     2,     5,   281,   285,     0,     0,     0,
       0,   225,   248,     0,     0,     0,   198,   364,    45,    58,
      68,    78,   101,   113,   126,   140,   151,   170,    47,    48,
      60,    49,    70,    50,    80,    51,   103,    52,   115,    53,
     128,    54,   142,    55,   153,    56,   172,     0,   430,   832,
     824,   826,   830,   834,   836,   884,   900,   844,   828,   850,
     838,   840,   842,   872,   846,   848,   892,   888,   896,   814,
     818,   822,   858,   852,   854,   856,     0,   808,   809,   789,
     790,   792,   793,   794,   795,   797,   798,   799,   801,   800,
     802,   804,   805,   803,   811,   812,   813,   787,   788,   791,
     810,   806,   807,   796,     0,     0,     0,     0,     0,     0,
       0,   282,     0,   289,   283,   356,   250,   995,     0,     0,
       0,   226,     0,   201,   204,   196,   199,   200,     0,    59,
       0,    69,     0,    79,     0,   102,     0,   114,     0,   127,
       0,   141,     0,   152,     0,   171,   443,   446,   428,   441,
     442,     0,     0,     0,     0,     0,   432,   433,   436,   437,
     435,   434,     0,     0,     0,     0,     0,     0,   886,   902,
       0,     0,     0,     0,     0,     0,   878,     0,     0,   894,
     890,   898,     0,     0,     0,   862,     0,     0,     0,   780,
     769,     0,    24,    25,    27,    26,   389,   389,   391,   392,
     393,   394,   390,     0,   289,   287,     0,     0,   997,     0,
       0,     0,     0,   251,     0,   229,   232,   224,   227,   228,
       0,     0,    65,     0,    57,     0,    61,    63,    62,    64,
      75,     0,    67,    71,    73,    72,    74,    85,    88,    77,
      81,    83,    82,    84,   110,     0,   100,     0,   104,   107,
     106,   105,   108,   123,     0,   112,     0,     0,     0,   116,
     121,   120,   122,   118,   117,   119,   137,     0,   125,     0,
       0,   129,   134,   133,   135,   136,   131,   130,   132,   148,
       0,   139,     0,   143,   147,   145,   144,   146,     0,   150,
     154,   156,   155,   157,     0,   169,   173,   175,   174,   176,
     448,     0,   476,   450,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   816,
       0,   815,   820,     0,   819,     0,     0,   929,   934,   939,
     944,   947,   956,   961,   967,   971,   974,   977,   980,   982,
     987,   990,   993,   924,   950,   953,     0,   904,     0,   905,
       0,   906,     0,   907,     0,   908,     0,   909,     0,   922,
       0,   910,     0,   911,   957,   912,   962,   913,     0,   914,
       0,   915,     0,   916,     0,   917,     0,   918,   919,     0,
     920,     0,   921,     0,     0,     0,   768,   386,   387,     0,
     284,   288,   291,   354,     0,     0,     0,   353,   357,   358,
     359,   194,     0,     0,   998,     0,   254,   257,   249,   252,
     253,     0,     0,   365,   203,   207,   202,   205,   209,    66,
       0,    76,     0,    87,   111,     0,   124,   389,     0,     0,
     138,     0,     0,   149,     0,   160,     0,     0,   179,     0,
       0,   444,   445,     0,   449,   439,   440,   438,     0,     0,
       0,     0,     0,     0,   835,   837,   885,   887,   901,   903,
     845,   829,     0,   839,   841,   843,   874,     0,     0,     0,
     873,   879,   880,   881,   847,   849,   893,   895,   889,   891,
     897,   899,   817,   821,     0,   860,     0,     0,     0,     0,
     859,   863,   864,   866,   865,   984,   853,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   943,     0,   946,
       0,   949,     0,   952,     0,     0,   958,     0,   963,   968,
       0,   966,     0,   970,     0,   973,     0,   976,     0,   979,
       0,   986,     0,   989,     0,   992,   855,   857,     0,     0,
       0,   355,   389,   389,     0,  1002,  1004,   996,  1000,  1001,
       0,     0,   366,   231,   235,   230,   233,   237,     0,   208,
     766,    99,    86,    91,    89,    93,     0,     0,     0,     0,
       0,     0,   373,   168,   158,     0,     0,   161,   187,   177,
       0,   180,   719,   487,   518,   549,   602,   641,   683,   714,
     477,   478,   489,   479,   520,   480,   551,   481,   604,   483,
     643,   482,   685,   484,   715,   485,     0,   475,     0,   447,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   468,
     469,   470,   460,   758,   760,   833,   825,   827,   831,     0,
     875,   876,     0,   389,   823,   861,   389,   867,   869,     0,
       0,     0,   925,     0,   923,     0,   930,     0,   928,     0,
     935,     0,   933,     0,   940,     0,   938,   945,     0,   951,
     954,     0,     0,     0,   969,     0,   975,     0,     0,     0,
       0,   994,   286,     0,   293,   296,   290,     0,     0,     0,
       0,   367,   256,   260,   255,   258,   262,     0,   236,   221,
       0,   206,     0,     0,     0,     0,     0,     0,     0,   210,
     215,   217,   213,   214,   216,   218,   220,   212,   211,   219,
       0,    92,   109,   368,   369,   370,   371,   372,     0,   164,
     397,   159,   162,   163,   183,   397,   178,   181,   182,     0,
     488,     0,   519,     0,   550,     0,   603,     0,   642,     0,
     684,     0,   716,     0,     0,   720,   474,     0,     0,     0,
       0,     0,     0,     0,   389,   389,   851,     0,     0,     0,
       0,     0,     0,   983,   985,     0,     0,   926,     0,   931,
       0,   936,     0,   941,   948,   965,     0,   955,     0,   960,
     972,   978,   981,   988,     0,   292,   298,     0,   315,   361,
     362,   999,  1003,  1007,  1005,  1009,     0,   261,   246,     0,
     234,     0,     0,     0,   238,   244,   241,   242,   243,   240,
     239,   245,   222,     0,     0,     0,     0,     0,     0,     0,
      97,     0,    90,     0,     0,    94,    96,    95,     0,     0,
       0,   166,   395,   396,     0,   185,     0,     0,   772,     0,
     490,   491,   492,   770,   771,     0,   521,   522,   523,     0,
     552,   553,   554,     0,   605,   606,   607,     0,   644,   645,
     646,     0,   686,   687,   688,     0,     0,     0,   718,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,   877,
     883,   882,   871,   868,   870,   374,   927,   932,   937,   942,
     959,   964,     0,     0,   294,   317,   334,     0,  1008,   273,
       0,   259,     0,   263,   268,   270,   266,   267,   269,   271,
     265,   264,   272,   247,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,    98,     0,     0,   759,     0,     0,
     167,   165,   400,   398,   402,   186,   184,   497,   486,   494,
       0,     0,     0,   528,   517,   525,     0,   559,   548,   556,
       0,   612,   601,   609,     0,   651,   640,   648,     0,   693,
     682,   690,     0,     0,     0,   724,     0,     0,   461,   462,
     463,   464,   465,   466,   467,   473,   388,     0,   306,   310,
       0,     0,   299,   300,   301,   297,   304,     0,   336,   295,
       0,  1011,  1012,  1010,   274,     0,     0,     0,     0,   375,
     382,   376,   383,   378,   379,     0,   767,     0,   411,     0,
     407,   408,   409,     0,   401,   504,     0,     0,     0,   500,
     397,   496,   498,   499,     0,   773,   535,     0,     0,     0,
     531,   397,   527,   529,   530,   566,     0,   572,     0,   562,
     397,   558,   560,   561,   619,     0,   625,     0,   615,   397,
     611,   613,   614,   658,     0,   664,     0,   654,   397,   650,
     652,   653,   700,     0,     0,     0,   696,   397,   692,   694,
     695,   717,   713,   757,   732,   739,     0,     0,   725,   991,
     307,   310,   308,     0,     0,     0,   325,   329,     0,     0,
     318,   319,   320,   316,   323,     0,     0,     0,   380,   384,
     377,   765,     0,     0,   410,     0,   399,     0,   403,   405,
     404,   493,   511,   495,     0,   507,   397,   503,   505,   506,
     502,     0,   761,   524,   542,   526,     0,   538,   397,   534,
     536,   537,   533,     0,   555,   574,   557,     0,   569,   397,
     565,   567,   568,   564,     0,   608,   627,   610,     0,   622,
     397,   618,   620,   621,   617,     0,   647,   666,   649,     0,
     661,   397,   657,   659,   660,   656,     0,   689,   707,   691,
       0,   703,   397,   699,   701,   702,   698,     0,     0,     0,
     733,   728,   397,   723,   726,   727,   305,   309,     0,     0,
       0,   326,   329,   327,     0,     0,     0,   343,   347,     0,
       0,   337,   338,   335,   341,   339,  1006,   381,   763,   412,
       0,     0,   514,   415,   510,   512,   513,   509,     0,   501,
     545,   397,   541,   543,   544,   540,     0,   532,   577,   580,
     573,   575,   576,   571,     0,   563,   630,   632,   626,   628,
     629,   624,     0,   616,   669,   671,   665,   667,   668,   663,
       0,   655,   710,   397,   706,   708,   709,   705,     0,   697,
     742,   722,   721,   740,   744,   736,   397,   731,   734,   735,
     730,     0,     0,     0,   302,   303,   324,   328,     0,     0,
       0,   344,   347,   345,     0,     0,     0,   406,     0,     0,
     516,   413,   414,     0,   508,   547,     0,   539,     0,   579,
     570,     0,   623,     0,   662,   712,     0,   704,     0,   743,
     738,     0,   729,     0,   313,     0,   311,     0,     0,   321,
     322,   342,   346,     0,     0,     0,   764,     0,   418,   416,
     419,   515,   546,   578,   583,   581,   585,   635,   631,   633,
       0,   674,   670,   672,   675,   711,   754,   446,   741,   752,
     753,   389,   389,   748,   749,   745,   746,   747,   737,     0,
     314,     0,   332,     0,   330,     0,     0,   340,   360,   426,
       0,   422,   423,   424,     0,   420,     0,   584,   638,     0,
     634,   636,   637,     0,   476,     0,     0,     0,   312,     0,
     333,     0,   350,     0,   348,     0,   425,   389,   417,   592,
     594,   582,   590,   591,     0,     0,   586,   588,   587,     0,
       0,     0,   676,   677,   673,   679,   678,   756,   755,   389,
     389,   331,     0,   351,   427,     0,     0,   389,     0,   639,
       0,     0,   750,   751,   349,   421,   593,   597,   595,   598,
       0,     0,   681,   680,     0,     0,   589,   762,   389,     0,
     596,     0,     0,   599,   600
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    84,   113,   114,     3,     4,    10,    17,    29,
      30,    76,    49,    77,    78,    79,    80,    81,    12,    13,
      22,    40,    41,    42,    65,    19,    20,    35,    61,    62,
      63,    94,   138,   139,   140,   238,   239,   336,   334,   141,
     142,   240,   241,   343,   342,   143,   144,   242,   243,   350,
     349,   542,   543,   684,   685,   840,   841,   955,   952,   682,
     145,   146,   244,   245,   358,   359,   356,   147,   148,   246,
     247,   369,   365,   149,   150,   248,   249,   381,   378,   151,
     152,   250,   251,   393,   391,   153,   154,   252,   253,   400,
     399,   556,   557,   696,   851,   852,   853,   960,  1061,   694,
     155,   156,   254,   255,   406,   405,   559,   560,   700,   856,
     857,   858,   964,  1066,   699,    32,    33,    55,    56,    57,
      91,    92,   125,   235,   236,   237,   536,   331,   537,   538,
     678,   679,   829,   821,   122,   123,   230,   327,   328,   329,
     675,   532,   676,   677,   817,   818,   934,   930,   227,   228,
     322,   528,   529,   530,   814,   671,   815,   816,   926,   927,
    1033,  1031,    51,    52,    87,    88,    89,   117,   118,   223,
     314,   315,   316,   660,   806,   917,   918,  1023,  1112,  1113,
    1114,  1115,  1116,  1211,  1212,  1213,  1403,  1446,  1026,  1117,
    1220,  1221,  1222,  1223,  1224,  1322,  1323,  1324,  1448,  1494,
    1119,  1225,  1331,  1332,  1333,  1334,  1412,  1413,  1414,  1496,
    1524,   119,   120,   517,   317,   518,  1335,   519,   520,    23,
      36,   126,   231,   323,   370,   371,   372,   384,   385,   394,
     619,   830,   831,   935,   832,   833,   937,  1037,   834,   835,
     938,   836,   219,  1007,   220,   312,   961,   962,  1063,  1064,
    1143,  1144,  1238,  1236,   963,  1140,  1141,  1142,  1420,  1421,
    1459,  1460,  1504,  1528,  1422,  1501,  1502,  1503,    98,    99,
     157,   158,   266,   267,   268,   269,   258,   259,   260,   411,
     412,   413,   563,   564,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   729,   562,   710,
     711,   712,   859,   860,   970,  1068,  1146,  1069,  1070,  1151,
    1152,  1153,  1251,  1147,  1148,  1247,  1248,  1249,  1348,  1243,
    1244,  1344,  1345,  1346,  1423,   713,   714,   861,   862,   976,
    1074,  1157,  1075,  1076,  1162,  1163,  1164,  1263,  1158,  1159,
    1259,  1260,  1261,  1356,  1255,  1256,  1352,  1353,  1354,  1426,
     715,   716,   863,   864,   980,  1078,  1166,  1079,  1080,  1171,
    1172,  1173,  1274,  1167,  1168,  1270,  1271,  1272,  1364,  1266,
    1267,  1360,  1361,  1362,  1428,  1429,  1465,  1466,  1506,  1507,
    1536,  1537,  1531,  1532,  1533,  1556,  1568,  1569,  1575,  1580,
     717,   718,   865,   866,   984,  1082,  1175,  1083,  1084,  1180,
    1181,  1182,  1285,  1176,  1177,  1281,  1282,  1283,  1372,  1277,
    1278,  1368,  1369,  1370,  1431,  1469,  1470,  1510,  1511,  1512,
     719,   720,   867,   868,   988,  1086,  1184,  1087,  1088,  1189,
    1190,  1191,  1296,  1185,  1186,  1292,  1293,  1294,  1380,  1288,
    1289,  1376,  1377,  1378,  1433,  1473,  1474,  1513,  1542,  1543,
    1544,   721,   722,   869,   870,   992,  1090,  1193,  1091,  1092,
    1198,  1199,  1200,  1307,  1194,  1195,  1303,  1304,  1305,  1388,
    1299,  1300,  1384,  1385,  1386,  1436,   723,   724,   871,  1202,
     725,   726,   874,   998,  1392,  1096,  1097,  1207,  1313,  1314,
    1315,  1401,  1205,  1206,  1309,  1397,  1398,  1399,  1441,  1308,
    1393,  1394,  1438,  1439,  1485,  1486,  1487,  1478,  1479,  1480,
    1515,   875,   270,   697,   271,   971,  1538,  1059,  1239,   956,
     339,   957,   104,   105,   972,   973,   974,     7,     8,    15,
      25,    46,    47,    67,    68,   106,   186,   187,   292,   441,
     188,   293,   444,   189,   294,   190,   273,   191,   274,   192,
     281,   193,   275,   194,   272,   195,   276,   196,   277,   197,
     283,   198,   284,   199,   285,   200,   280,   201,   287,   202,
     288,   203,   282,   204,   296,   205,   297,   206,   298,   207,
     295,   610,   446,   611,   612,   891,   613,   892,   614,   208,
     286,   590,   887,   433,   591,   592,   593,   209,   278,   425,
     210,   290,   437,   211,   289,   436,   212,   291,   438,   213,
     279,   426,   466,   467,   468,   774,   469,   470,   778,   621,
     471,   472,   782,   623,   473,   474,   786,   625,   475,   476,
     627,   477,   478,   629,   479,   480,   631,   481,   482,   633,
     483,   484,   635,   907,   485,   486,   637,   909,   636,   487,
     488,   641,   489,   490,   643,   491,   492,   645,   493,   494,
     647,   495,   496,   649,   497,   615,   769,   498,   499,   651,
     500,   501,   653,   502,   503,   655,   319,   320,   523,   524,
     667,   668,   669,   810,   924,   925,  1027,  1028,  1123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1403
static const yytype_int16 yypact[] =
{
      76, -1403,    98,  -130,   136, -1403, -1403,    85,  -113,   158,
   -1403, -1403,   138,   145,   175, -1403,   174,   109, -1403,   120,
     176,   206,   135, -1403,   208,  -100,   235, -1403, -1403, -1403,
   -1403, -1403,   156,   212,   250,   233, -1403,   248, -1403, -1403,
   -1403, -1403, -1403,   254, -1403, -1403, -1403, -1403,   252,    51,
   -1403,   232,   237, -1403,   192, -1403, -1403, -1403,   271, -1403,
   -1403, -1403, -1403, -1403,   277,    29,   273,   275,   -81, -1403,
   -1403,   259,   285,   287,   289,   291, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   290, -1403,   217, -1403, -1403, -1403,
   -1403,   234,   245,   303,   230, -1403, -1403, -1403, -1403, -1403,
   -1403,   664,   335,   327, -1403, -1403, -1403, -1403,   341,   344,
     350, -1403, -1403, -1403, -1403, -1403, -1403,   229,   262,   301,
     249, -1403,   288,   295,   396,   308, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,   310,   131, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   165, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   400,   398,   406,   408,   410,   412,
      49, -1403,   414, -1403, -1403, -1403, -1403,   184,   342,   422,
     313, -1403,   455, -1403, -1403, -1403, -1403, -1403,   318,   -79,
     322,   -79,   324,   -79,   326,    13,   331,    23,   333,    15,
     336,     5,   418,   -79,   465,   -79, -1403,   329, -1403, -1403,
   -1403,   488,   507,   509,   523,   524, -1403, -1403, -1403, -1403,
   -1403, -1403,   664,   664,   664,   664,   664,   664, -1403, -1403,
     664,   664,   664,   664,   664,   664, -1403,   664,   664, -1403,
   -1403, -1403,   343,   345,   664, -1403,    97,    97,    97, -1403,
   -1403,   525, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403,   522,   433, -1403,   435,    74, -1403,   466,
     293,   532,   349, -1403,   529, -1403, -1403, -1403, -1403, -1403,
     534,    88, -1403,   511, -1403,   535, -1403, -1403, -1403, -1403,
   -1403,   505, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403,   503, -1403,   540, -1403, -1403,
   -1403, -1403, -1403, -1403,   502, -1403,   542,   544,   545, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,   513, -1403,   546,
     547, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     515, -1403,   548, -1403, -1403, -1403, -1403, -1403,   516, -1403,
   -1403, -1403, -1403, -1403,   500, -1403, -1403, -1403, -1403, -1403,
   -1403,   392, -1403, -1403,   550,   552,   556,   553,   554,   664,
     664,   664,   664,   309,   306,   401,   482,   302,   304,   664,
     297,   296,   299,    53,   298,   294,   501,   538,   592, -1403,
     281, -1403, -1403,   292, -1403,   664,    48, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   279, -1403,   -19, -1403,
     387, -1403,   393, -1403,   394, -1403,    97, -1403,    97, -1403,
     664, -1403,    97, -1403,   246, -1403,   246, -1403,   351, -1403,
      97, -1403,    97, -1403,    97, -1403,    97, -1403, -1403,   664,
   -1403,   664, -1403,    97,   286,   283, -1403,  -193,  -193,   574,
   -1403, -1403,   416, -1403,   463,   582,   583, -1403, -1403, -1403,
   -1403, -1403,   584,   355, -1403,   581, -1403, -1403, -1403, -1403,
   -1403,   586,    87, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     587, -1403,   557,   539, -1403,   588, -1403, -1403,   589,   590,
   -1403,   591,   594, -1403,   596, -1403,   549,   456, -1403,   559,
     456, -1403,    44,   363,   247, -1403, -1403, -1403,   600,   601,
     347,   359,   358,   357, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403,   664, -1403, -1403, -1403, -1403,   633,   607,   608,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   323, -1403,   320,   611,   613,   614,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,   612,   616,   369,
     617,   377,   618,   379,   619,   382,   325, -1403,    97, -1403,
     300, -1403,   305, -1403,   620,   615, -1403,   621, -1403, -1403,
     315, -1403,    97, -1403,   317, -1403,    97, -1403,    97, -1403,
      97, -1403,   664, -1403,   307, -1403, -1403, -1403,   622,   623,
     384, -1403, -1403, -1403,   627, -1403, -1403, -1403, -1403, -1403,
     634,   146, -1403, -1403, -1403, -1403, -1403, -1403,   417,    18,
   -1403, -1403, -1403, -1403, -1403, -1403,   635,   636,   637,   638,
     639,   640, -1403, -1403, -1403,   642,   432, -1403, -1403, -1403,
     434, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   480, -1403,   453, -1403,   517, -1403,
     644,   646,   650,   654,   658,   660,   662,   666, -1403,   632,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   405,
   -1403, -1403,   668, -1403, -1403, -1403, -1403, -1403, -1403,   -22,
     672,   674, -1403,   361, -1403,   676, -1403,   624, -1403,   678,
   -1403,   595, -1403,   682, -1403,   610, -1403, -1403,   365, -1403,
   -1403,   688,    97,    97, -1403,   385, -1403,   386,   383,   381,
     664, -1403, -1403,   699, -1403,   599, -1403,   701,   702,   703,
      -8, -1403, -1403, -1403, -1403, -1403, -1403,   436,   148, -1403,
     643, -1403,   704,   707,   708,   709,   710,   712,   715, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     438,   -42, -1403, -1403, -1403, -1403, -1403, -1403,   700, -1403,
     568, -1403, -1403, -1403, -1403,   568, -1403, -1403, -1403,   711,
     -88,   713,   -88,   717,   -88,   719,   -88,   721,   -88,   723,
     -88,   725, -1403,   718,   727, -1403, -1403,   716,   733,   793,
     795,   797,   799,   801, -1403, -1403, -1403,   446,   807,   809,
     811,   813,   815, -1403, -1403,   819,   821, -1403,   823, -1403,
     825, -1403,   827, -1403, -1403, -1403,   528, -1403,   420, -1403,
   -1403, -1403, -1403, -1403,   664, -1403, -1403,   734,   731, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   440,    28, -1403,   760,
   -1403,   837,   841,   843, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403,   845,   847,   849,   851,   853,   855,   857,
   -1403,   817, -1403,   863,   846, -1403, -1403, -1403,   865,   697,
     836, -1403,   737, -1403,   838, -1403,   705,   869, -1403,   870,
   -1403, -1403, -1403, -1403, -1403,   736, -1403, -1403, -1403,   738,
   -1403, -1403, -1403,   740, -1403, -1403, -1403,   742, -1403, -1403,
   -1403,   744, -1403, -1403, -1403,    97,   890,   729, -1403,   896,
     898,   902,   929,   941,   943,   945,   947, -1403,    41, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403,    97,    60, -1403, -1403,   848,   949,   -81, -1403,
     873, -1403,   955, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   956,   957,   958, -1403,   959,   963,
     964,   965,   966,   967, -1403,   968,   969, -1403,   970,   443,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   769,
     445,   971,   973, -1403, -1403,   772,   447, -1403, -1403,   775,
     449, -1403, -1403,   777,   454, -1403, -1403,   778,   457, -1403,
   -1403,   779,   459,   761,   979, -1403,   759,   456, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,   663, -1403,   879,
     984,   986, -1403, -1403, -1403, -1403, -1403,   100, -1403, -1403,
      97, -1403, -1403, -1403, -1403,   983,   988,   989,   990, -1403,
   -1403, -1403, -1403, -1403, -1403,   991, -1403,   992, -1403,    47,
   -1403, -1403, -1403,   985,   321, -1403,   798,   794,   461, -1403,
     568, -1403, -1403, -1403,   994, -1403, -1403,   796,   800,   468,
   -1403,   568, -1403, -1403, -1403, -1403,   791,   802,   470, -1403,
     568, -1403, -1403, -1403, -1403,   790,   803,   472, -1403,   568,
   -1403, -1403, -1403, -1403,   789,   804,   474, -1403,   568, -1403,
   -1403, -1403, -1403,   805,   806,   476, -1403,   568, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   456,   478, -1403, -1403,
   -1403,   904, -1403,   891,  1002,  1005, -1403,   905,  1011,  1012,
   -1403, -1403, -1403, -1403, -1403,   108,   776,  1013, -1403, -1403,
   -1403, -1403,  1016,   868, -1403,  1015, -1403,  1020, -1403, -1403,
   -1403, -1403, -1403, -1403,   483, -1403,   568, -1403, -1403, -1403,
   -1403,   826, -1403, -1403, -1403, -1403,   485, -1403,   568, -1403,
   -1403, -1403, -1403,   828, -1403, -1403, -1403,   487, -1403,   568,
   -1403, -1403, -1403, -1403,   829, -1403, -1403, -1403,   489, -1403,
     568, -1403, -1403, -1403, -1403,   830, -1403, -1403, -1403,   491,
   -1403,   568, -1403, -1403, -1403, -1403,   831, -1403, -1403, -1403,
     493, -1403,   568, -1403, -1403, -1403, -1403,   832,   -40,   495,
   -1403, -1403,   568, -1403, -1403, -1403, -1403, -1403,   842,  1023,
    1029, -1403,   925, -1403,   918,  1028,  1030, -1403,   927,  1035,
    1037, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     884,  1036, -1403,   893, -1403, -1403, -1403, -1403,   839, -1403,
   -1403,   568, -1403, -1403, -1403, -1403,   844, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   850, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403,   852, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     854, -1403, -1403,   568, -1403, -1403, -1403, -1403,   856, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   568, -1403, -1403, -1403,
   -1403,   822,  1042,   497, -1403, -1403, -1403, -1403,   866,  1046,
    1047, -1403,   942, -1403,   934,  1049,  1051, -1403,  1057,   697,
   -1403,   906, -1403,   858, -1403, -1403,   859, -1403,   860,   910,
   -1403,   -69, -1403,   -67, -1403, -1403,   862, -1403,   499,   -76,
   -1403,   835, -1403,  1061, -1403,   939, -1403,  1066,   506, -1403,
   -1403, -1403, -1403,   888,  1068,  1069, -1403,   508, -1403, -1403,
     919, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
     510, -1403, -1403, -1403, -1403, -1403, -1403,   329, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,  1071,
   -1403,  1070, -1403,   961, -1403,  1072,   512, -1403, -1403, -1403,
      67, -1403, -1403, -1403,  1065, -1403,   514,   -85, -1403,   664,
   -1403, -1403, -1403,    35, -1403,   916,  1073,  1074, -1403,  1079,
   -1403,  1076, -1403,   972, -1403,   932, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,  1082,  1083, -1403, -1403, -1403,   930,
    1081,  1085, -1403, -1403, -1403, -1403, -1403,    44, -1403, -1403,
   -1403, -1403,  1087, -1403, -1403,   935,   -82, -1403,  1086, -1403,
     937,  1092, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   913,
    1094,  1095, -1403, -1403,  1096,  1089, -1403, -1403, -1403,  1097,
   -1403,  1098,   882, -1403, -1403
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403,   792, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,  -108, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,  -217, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,  -305, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   861,   864, -1403, -1403, -1403, -1403,
   -1403,   181,   182, -1403,  -724, -1403, -1403, -1403,   185,   187,
   -1403, -1403,  -539, -1402,  -306, -1403,  -839, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403,  -328, -1403,  -324, -1403, -1403, -1403, -1403,
    -361, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,  -397, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403,  -218,  -551,  -213,  -736, -1403,  -301,  -394, -1122,
    -202, -1403,    92,  -676,  -595, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,  -270, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403,  -278, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   641, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     507,   508,   419,   420,   421,   422,   423,   424,   687,   701,
     427,   428,   429,   430,   431,   432,   965,   434,   435,   504,
     505,   337,  1240,   344,   445,   351,   338,   360,   345,   373,
     352,   386,   361,   395,   374,   401,   387,   407,   396,   346,
     402,   353,   408,   362,  1106,   375,  1540,   388,   872,   397,
     447,   403,  1233,   409,    96,   448,   306,   307,   605,   606,
     449,    70,    71,   586,   587,   617,   607,    72,    73,   392,
    1108,  1109,  1525,   366,   367,  1566,   379,   380,   357,  1516,
    1517,   366,   367,   368,   513,   514,   822,  1467,   335,  1471,
     102,  1534,   967,   262,   936,     1,  1535,   263,     5,   264,
     265,   103,     6,   823,   824,   825,   826,   827,   828,    11,
    1216,  1217,   953,   823,   824,   825,   826,   827,  1327,  1328,
    1032,    14,  1390,   807,   808,  1391,   977,   954,   981,    27,
     985,    28,   989,    44,   993,    45,  1468,  1567,  1472,   968,
     969,   308,   309,   310,   311,    38,    39,  1562,  1563,   570,
     571,   572,   573,  1481,  1482,   577,   579,     9,   534,   582,
     535,    16,   673,   618,   674,    18,   597,   599,   601,   447,
    1110,    21,   335,  1111,   448,   604,   515,   516,    24,   449,
     335,    26,   335,   264,   265,   335,    31,    97,  1237,   953,
     335,   264,   265,   264,   265,   335,   264,   265,   626,  1234,
     628,   264,   265,  1036,   632,    34,   264,   265,   702,    37,
     630,  1218,   642,  1219,   644,    43,   646,   608,   648,  1526,
    1329,  1330,    53,    54,   889,   654,   812,   890,   813,   650,
     922,   652,   923,    74,    75,   588,   589,   827,    48,   931,
     703,   932,   933,    59,    60,    82,    83,    85,    86,  1541,
     704,    50,   705,    58,   706,    64,   707,    66,   128,   708,
     129,    90,   130,    69,   131,   709,   132,   978,   133,   982,
     134,   986,   135,   990,   136,   994,   137,   450,    93,   451,
      95,   452,   107,   453,   100,   454,   101,   455,   108,   456,
     109,   457,   110,   458,   111,   459,   893,   460,   261,   461,
     262,   462,   112,   463,   263,   464,   127,   465,   121,   264,
     265,  1250,   759,   115,   116,   335,   124,   761,   233,   234,
     256,   257,  1262,   325,   326,   221,   264,   265,   332,   333,
     215,  1273,   340,   341,   347,   348,   354,   355,  1505,   214,
    1284,   363,   364,   376,   377,  1006,   389,   390,   216,  1295,
     788,   217,  1122,   439,   440,   442,   443,   218,  1306,   526,
     527,   639,   640,   222,   795,   665,   666,   226,   797,   225,
     798,   229,   799,   727,   728,   308,   309,   310,   311,   772,
     773,   609,   800,   308,   309,   310,   311,   776,   777,   780,
     781,  1546,   784,   785,   804,   805,   450,   224,   451,   232,
     452,   299,   453,   300,   454,   301,   455,  1347,   456,   302,
     457,   303,   458,   304,   459,   305,   460,   313,   461,  1355,
     462,   318,   463,   321,   464,   324,   465,   819,   820,   398,
    1363,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,  1371,   849,   850,   854,   855,   928,   929,   950,   951,
    1029,  1030,  1379,  1138,  1139,  1149,  1150,  1160,  1161,  1169,
    1170,   837,   330,  1387,  1178,  1179,   838,  1187,  1188,  1196,
    1197,  1245,  1246,  1400,  1237,   953,   404,   839,  1257,  1258,
    1268,  1269,  1279,  1280,  1290,  1291,  1301,  1302,  1311,  1312,
     410,   894,   414,  1342,  1343,  1350,  1351,  1358,  1359,  1366,
    1367,  1374,  1375,  1382,  1383,  1395,  1396,  1444,  1445,  1476,
    1477,   415,  1425,   416,   906,   908,  1492,  1493,  1499,  1500,
    1508,  1509,  1522,  1523,  1529,  1530,   417,   418,   506,   509,
     914,   510,   522,   521,   512,   525,   531,   533,   541,   540,
     544,   546,   539,   545,  1435,   547,  1208,   548,   549,   551,
     552,   561,   554,   565,   550,   566,   558,  1440,   553,   567,
     568,   569,   575,   574,   580,   583,   584,   602,   581,   620,
     555,   585,   595,   616,   594,   622,   624,   658,   634,  1008,
     603,   657,   656,   659,   661,   662,   663,   664,   670,   672,
     680,   683,   681,   755,   693,   686,   688,   689,   690,   692,
     939,   691,   695,   753,   754,   940,   698,   756,   757,   758,
     762,   763,   765,   764,   766,   770,   941,   767,   768,   771,
     775,   779,   783,   794,   791,   787,   792,   803,   789,   796,
     873,   801,   793,   802,   809,   790,   885,   811,   842,   843,
     844,   845,   846,   847,  1022,   848,   159,   877,   160,   878,
     161,   102,   162,   879,   163,  1310,   164,   880,   165,   576,
     166,   881,   167,   882,   168,   883,   169,   904,   170,   884,
     171,   886,   172,   901,   173,   888,   174,   876,   175,   895,
     176,   896,   177,   898,   178,   900,   179,   897,   180,   902,
     181,   905,   182,   903,   183,   910,   184,   899,   185,   912,
     911,   913,   915,   916,   919,   920,   921,   958,   943,  1040,
     944,   945,   946,   947,  1041,   948,   942,  1093,   949,   959,
    1009,   996,   966,   999,   975,  1042,  1021,   159,   979,   160,
     983,   161,   987,   162,   991,   163,   995,   164,   997,   165,
    1000,   166,   578,   167,  1107,   168,   159,   169,   160,   170,
     161,   171,   162,   172,   163,   173,   164,   174,   165,   175,
     166,   176,   167,   177,   168,   178,   169,   179,   170,   180,
     171,   181,   172,   182,   173,   183,   174,   184,   175,   185,
     176,   596,   177,   159,   178,   160,   179,   161,   180,   162,
     181,   163,   182,   164,   183,   165,   184,   166,   185,   167,
    1001,   168,  1002,   169,  1003,   170,  1004,   171,  1005,   172,
    1010,   173,  1011,   174,  1012,   175,  1013,   176,  1014,   177,
     598,   178,  1015,   179,  1016,   180,  1017,   181,  1018,   182,
    1019,   183,  1020,   184,  1024,   185,  1025,   159,  1043,   160,
    1044,   161,  1226,   162,  1045,   163,  1046,   164,  1047,   165,
    1056,   166,  1058,   167,  1048,   168,  1049,   169,  1050,   170,
    1051,   171,  1052,   172,  1053,   173,  1055,   174,  1057,   175,
    1054,   176,  1071,   177,  1072,   178,   600,   179,   159,   180,
     160,   181,   161,   182,   162,   183,   163,   184,   164,   185,
     165,  1060,   166,  1062,   167,  1065,   168,  1094,   169,  1098,
     170,  1099,   171,  1067,   172,  1100,   173,   760,   174,   159,
     175,   160,   176,   161,   177,   162,   178,   163,   179,   164,
     180,   165,   181,   166,   182,   167,   183,   168,   184,   169,
     185,   170,  1101,   171,  1073,   172,  1077,   173,  1081,   174,
    1085,   175,  1089,   176,  1102,   177,  1103,   178,  1104,   179,
    1105,   180,  1095,   181,  1118,   182,  1124,   183,  1125,   184,
    1120,   185,  1129,  1126,  1127,  1128,  1130,  1131,  1132,  1133,
    1134,  1145,  1136,  1137,  1156,  1135,  1155,  1165,  1154,  1174,
    1183,  1192,  1203,  1201,  1204,  1209,  1210,  1214,  1555,  1215,
    1227,  1228,  1229,  1230,  1231,  1241,  1235,  1252,  1242,  1232,
    1264,  1275,  1286,  1253,  1254,  1318,  1265,  1276,  1287,  1319,
    1298,  1316,  1320,  1321,  1325,  1326,  1337,  1336,  1570,  1338,
    1339,  1297,  1340,  1341,  1402,  1349,  1404,  1357,  1365,  1373,
    1381,  1389,  1405,  1406,  1408,  1409,  1411,  1410,  1415,  1581,
    1416,  1417,  1424,  1418,  1419,  1443,  1442,  1427,  1447,  1449,
    1450,  1451,  1453,  1430,  1490,  1432,  1454,  1434,  1455,  1437,
    1456,  1488,  1458,  1461,  1462,  1463,  1464,  1475,  1489,  1491,
    1495,  1497,  1498,   953,  1518,  1521,  1527,  1519,  1520,  1548,
    1549,  1550,  1551,  1552,  1554,  1557,  1558,  1559,  1560,  1561,
    1564,  1553,  1565,  1571,  1572,  1573,  1574,  1576,  1577,  1578,
    1579,  1583,  1584,  1317,  1582,  1407,   511,  1452,  1034,  1035,
     382,  1483,  1038,   383,  1039,  1484,  1514,  1547,  1457,  1545,
    1121,     0,     0,     0,     0,     0,     0,   638,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1008,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1539,
       0,     0,     0,  1008,  1008
};

static const yytype_int16 yycheck[] =
{
     306,   307,   272,   273,   274,   275,   276,   277,   547,   560,
     280,   281,   282,   283,   284,   285,   855,   287,   288,   297,
     298,   239,  1144,   241,   294,   243,   239,   245,   241,   247,
     243,   249,   245,   251,   247,   253,   249,   255,   251,   241,
     253,   243,   255,   245,     3,   247,    11,   249,   724,   251,
      72,   253,     5,   255,    25,    77,     7,     8,    10,    11,
      82,    10,    11,    10,    11,    84,    18,    16,    17,    64,
      10,    11,     5,    58,    59,   157,    61,    62,    65,  1481,
    1482,    58,    59,    60,    10,    11,    68,   156,   167,   156,
     171,   176,   180,   169,   818,    19,   181,   173,     0,   178,
     179,   182,   232,    85,    86,    87,    88,    89,    90,    24,
      10,    11,   154,    85,    86,    87,    88,    89,    10,    11,
      92,   234,   162,   662,   663,   165,   862,   169,   864,    20,
     866,    22,   868,   233,   870,   235,   205,   219,   205,   227,
     228,   334,   335,   336,   337,    10,    11,  1549,  1550,   419,
     420,   421,   422,   229,   230,   425,   426,    21,    70,   429,
      72,     3,    75,   182,    77,    27,   436,   437,   438,    72,
     110,    26,   167,   113,    77,   445,   102,   103,     3,    82,
     167,     7,   167,   178,   179,   167,    66,   158,   153,   154,
     167,   178,   179,   178,   179,   167,   178,   179,   476,   152,
     478,   178,   179,   927,   482,    29,   178,   179,   164,     3,
     480,   111,   490,   113,   492,     7,   494,   169,   496,   152,
     112,   113,    10,    11,   763,   503,    80,   766,    82,   499,
     238,   501,   240,   182,   183,   182,   183,    89,     3,    91,
     196,    93,    94,    10,    11,    13,    14,    10,    11,   214,
     206,    95,   208,     3,   210,     7,   212,     3,    28,   215,
      30,    69,    32,    11,    34,   221,    36,   862,    38,   864,
      40,   866,    42,   868,    44,   870,    46,   299,     7,   301,
       3,   303,    23,   305,    11,   307,    11,   309,     3,   311,
       3,   313,     3,   315,     3,   317,   318,   319,   167,   321,
     169,   323,    12,   325,   173,   327,     3,   329,    74,   178,
     179,  1150,   582,    96,    97,   167,    71,   587,    10,    11,
      10,    11,  1161,    10,    11,    96,   178,   179,    10,    11,
       3,  1170,    10,    11,    10,    11,    10,    11,  1460,     4,
    1179,    10,    11,    10,    11,   884,    10,    11,     7,  1188,
     628,     7,  1028,    10,    11,    10,    11,     7,  1197,    10,
      11,    10,    11,   101,   642,    10,    11,    79,   646,   120,
     648,    76,   650,    10,    11,   334,   335,   336,   337,    10,
      11,   333,   652,   334,   335,   336,   337,    10,    11,    10,
      11,  1513,    10,    11,    10,    11,   299,    96,   301,     3,
     303,   236,   305,     3,   307,     7,   309,  1246,   311,     3,
     313,     3,   315,     3,   317,     3,   319,     3,   321,  1258,
     323,   237,   325,    81,   327,     3,   329,    10,    11,    11,
    1269,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,  1280,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,  1291,    10,    11,    10,    11,    10,    11,    10,
      11,   679,     7,  1302,    10,    11,   679,    10,    11,    10,
      11,    10,    11,  1312,   153,   154,    11,   679,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     161,   769,     4,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     4,  1351,     4,   792,   793,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     3,     3,     3,     7,
     800,    98,   239,    67,    99,     3,     7,     3,    33,     4,
      37,    39,    31,     3,  1383,     3,  1097,     3,     3,     3,
       3,   159,     4,     3,    41,     3,    56,  1396,    43,     3,
       7,     7,   256,   254,   262,   268,   270,   286,   264,   182,
      54,   272,   278,   294,   276,   182,   182,     3,   332,   885,
     288,   298,   296,   167,   121,     3,     3,     3,     7,     3,
       3,    52,    35,   246,    45,     7,     7,     7,     7,     3,
     818,     7,   146,     3,     3,   818,    47,   248,   250,   252,
       3,     3,   292,   290,     3,     3,   818,     4,     4,     3,
       3,     3,     3,   308,     4,   300,    11,     4,   328,   312,
     177,   324,    11,    11,     7,   330,     4,     3,     3,     3,
       3,     3,     3,     3,   914,     3,   245,     3,   247,     3,
     249,   171,   251,     3,   253,  1206,   255,     3,   257,   258,
     259,     3,   261,     3,   263,     3,   265,   302,   267,     3,
     269,   266,   271,    78,   273,     7,   275,   160,   277,     7,
     279,     7,   281,     7,   283,     7,   285,   326,   287,     7,
     289,     3,   291,    83,   293,   310,   295,    73,   297,   316,
     314,   320,     3,   104,     3,     3,     3,     7,     4,   927,
       3,     3,     3,     3,   927,     3,    73,   995,     3,   151,
     274,     3,    11,     7,    11,   927,   306,   245,    11,   247,
      11,   249,    11,   251,    11,   253,    11,   255,    11,   257,
       7,   259,   260,   261,  1022,   263,   245,   265,   247,   267,
     249,   269,   251,   271,   253,   273,   255,   275,   257,   277,
     259,   279,   261,   281,   263,   283,   265,   285,   267,   287,
     269,   289,   271,   291,   273,   293,   275,   295,   277,   297,
     279,   280,   281,   245,   283,   247,   285,   249,   287,   251,
     289,   253,   291,   255,   293,   257,   295,   259,   297,   261,
       7,   263,     7,   265,     7,   267,     7,   269,     7,   271,
       3,   273,     3,   275,     3,   277,     3,   279,     3,   281,
     282,   283,     3,   285,     3,   287,     3,   289,     3,   291,
       3,   293,   304,   295,   100,   297,   105,   245,    78,   247,
       3,   249,  1120,   251,     3,   253,     3,   255,     3,   257,
       4,   259,   155,   261,     7,   263,     7,   265,     7,   267,
       7,   269,     7,   271,     7,   273,     3,   275,     3,   277,
      53,   279,     3,   281,     4,   283,   284,   285,   245,   287,
     247,   289,   249,   291,   251,   293,   253,   295,   255,   297,
     257,    55,   259,   156,   261,    57,   263,     7,   265,     3,
     267,     3,   269,   198,   271,     3,   273,   274,   275,   245,
     277,   247,   279,   249,   281,   251,   283,   253,   285,   255,
     287,   257,   289,   259,   291,   261,   293,   263,   295,   265,
     297,   267,     3,   269,   198,   271,   198,   273,   198,   275,
     198,   277,   198,   279,     3,   281,     3,   283,     3,   285,
       3,   287,   223,   289,   106,   291,    83,   293,     3,   295,
      11,   297,     3,     7,     7,     7,     3,     3,     3,     3,
       3,   202,     3,     3,   202,     7,     3,   202,     7,   202,
     202,   202,     3,   222,   225,   322,   107,     3,  1527,     3,
       7,     3,     3,     3,     3,   197,    11,     3,   204,     7,
     209,   211,   213,   207,   204,   114,   204,   204,   204,     7,
     204,   107,     7,   108,     3,     3,     3,   241,  1557,     3,
     152,   216,     7,     3,   182,   199,     3,   199,   199,   199,
     199,   199,     3,   108,   116,     7,   109,     7,     3,  1578,
       3,   157,   203,     7,   151,     3,   224,   203,   182,     3,
       3,   109,   118,   203,   115,   203,     7,   203,     7,   203,
       3,   226,   156,   205,   205,   205,   156,   205,     7,     3,
     182,     3,     3,   154,     3,     3,    11,     7,   117,   163,
       7,     7,     3,     7,   152,     3,     3,   157,     7,     4,
       3,   119,   157,     7,   157,     3,   183,     3,     3,     3,
      11,     3,   220,  1211,     7,  1322,   314,  1412,   927,   927,
     249,  1439,   927,   249,   927,  1439,  1477,  1514,  1419,  1513,
    1028,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1481,  1482,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1509,
      -1,    -1,    -1,  1549,  1550
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    19,   339,   343,   344,     0,   232,   865,   866,    21,
     345,    24,   356,   357,   234,   867,     3,   346,    27,   363,
     364,    26,   358,   557,     3,   868,     7,    20,    22,   347,
     348,    66,   453,   454,    29,   365,   558,     3,    10,    11,
     359,   360,   361,     7,   233,   235,   869,   870,     3,   350,
      95,   500,   501,    10,    11,   455,   456,   457,     3,    10,
      11,   366,   367,   368,     7,   362,     3,   871,   872,    11,
      10,    11,    16,    17,   182,   183,   349,   351,   352,   353,
     354,   355,    13,    14,   340,    10,    11,   502,   503,   504,
      69,   458,   459,     7,   369,     3,    25,   158,   606,   607,
      11,    11,   171,   182,   860,   861,   873,    23,     3,     3,
       3,     3,    12,   341,   342,    96,    97,   505,   506,   549,
     550,    74,   472,   473,    71,   460,   559,     3,    28,    30,
      32,    34,    36,    38,    40,    42,    44,    46,   370,   371,
     372,   377,   378,   383,   384,   398,   399,   405,   406,   411,
     412,   417,   418,   423,   424,   438,   439,   608,   609,   245,
     247,   249,   251,   253,   255,   257,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   277,   279,   281,   283,   285,
     287,   289,   291,   293,   295,   297,   874,   875,   878,   881,
     883,   885,   887,   889,   891,   893,   895,   897,   899,   901,
     903,   905,   907,   909,   911,   913,   915,   917,   927,   935,
     938,   941,   944,   947,     4,     3,     7,     7,     7,   580,
     582,    96,   101,   507,    96,   120,    79,   486,   487,    76,
     474,   560,     3,    10,    11,   461,   462,   463,   373,   374,
     379,   380,   385,   386,   400,   401,   407,   408,   413,   414,
     419,   420,   425,   426,   440,   441,    10,    11,   614,   615,
     616,   167,   169,   173,   178,   179,   610,   611,   612,   613,
     850,   852,   892,   884,   886,   890,   894,   896,   936,   948,
     904,   888,   910,   898,   900,   902,   928,   906,   908,   942,
     939,   945,   876,   879,   882,   918,   912,   914,   916,   236,
       3,     7,     3,     3,     3,     3,     7,     8,   334,   335,
     336,   337,   583,     3,   508,   509,   510,   552,   237,  1014,
    1015,    81,   488,   561,     3,    10,    11,   475,   476,   477,
       7,   465,    10,    11,   376,   167,   375,   850,   852,   858,
      10,    11,   382,   381,   850,   852,   858,    10,    11,   388,
     387,   850,   852,   858,    10,    11,   404,    65,   402,   403,
     850,   852,   858,    10,    11,   410,    58,    59,    60,   409,
     562,   563,   564,   850,   852,   858,    10,    11,   416,    61,
      62,   415,   562,   563,   565,   566,   850,   852,   858,    10,
      11,   422,    64,   421,   567,   850,   852,   858,    11,   428,
     427,   850,   852,   858,    11,   443,   442,   850,   852,   858,
     161,   617,   618,   619,     4,     4,     4,     3,     3,   874,
     874,   874,   874,   874,   874,   937,   949,   874,   874,   874,
     874,   874,   874,   931,   874,   874,   943,   940,   946,    10,
      11,   877,    10,    11,   880,   874,   920,    72,    77,    82,
     299,   301,   303,   305,   307,   309,   311,   313,   315,   317,
     319,   321,   323,   325,   327,   329,   950,   951,   952,   954,
     955,   958,   959,   962,   963,   966,   967,   969,   970,   972,
     973,   975,   976,   978,   979,   982,   983,   987,   988,   990,
     991,   993,   994,   996,   997,   999,  1000,  1002,  1005,  1006,
    1008,  1009,  1011,  1012,   950,   950,     3,   582,   582,     7,
      98,   509,    99,    10,    11,   102,   103,   551,   553,   555,
     556,    67,   239,  1016,  1017,     3,    10,    11,   489,   490,
     491,     7,   479,     3,    70,    72,   464,   466,   467,    31,
       4,    33,   389,   390,    37,     3,    39,     3,     3,     3,
      41,     3,     3,    43,     4,    54,   429,   430,    56,   444,
     445,   159,   636,   620,   621,     3,     3,     3,     7,     7,
     874,   874,   874,   874,   254,   256,   258,   874,   260,   874,
     262,   264,   874,   268,   270,   272,    10,    11,   182,   183,
     929,   932,   933,   934,   276,   278,   280,   874,   282,   874,
     284,   874,   286,   288,   874,    10,    11,    18,   169,   333,
     919,   921,   922,   924,   926,  1003,   294,    84,   182,   568,
     182,   957,   182,   961,   182,   965,   950,   968,   950,   971,
     874,   974,   950,   977,   332,   980,   986,   984,   986,    10,
      11,   989,   950,   992,   950,   995,   950,   998,   950,  1001,
     874,  1007,   874,  1010,   950,  1013,   296,   298,     3,   167,
     511,   121,     3,     3,     3,    10,    11,  1018,  1019,  1020,
       7,   493,     3,    75,    77,   478,   480,   481,   468,   469,
       3,    35,   397,    52,   391,   392,     7,   580,     7,     7,
       7,     7,     3,    45,   437,   146,   431,   851,    47,   452,
     446,   851,   164,   196,   206,   208,   210,   212,   215,   221,
     637,   638,   639,   663,   664,   688,   689,   728,   729,   758,
     759,   789,   790,   814,   815,   818,   819,    10,    11,   635,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,     3,     3,   246,   248,   250,   252,   874,
     274,   874,     3,     3,   290,   292,     3,     4,     4,  1004,
       3,     3,    10,    11,   953,     3,    10,    11,   956,     3,
      10,    11,   960,     3,    10,    11,   964,   300,   950,   328,
     330,     4,    11,    11,   308,   950,   312,   950,   950,   950,
     874,   324,    11,     4,    10,    11,   512,   580,   580,     7,
    1021,     3,    80,    82,   492,   494,   495,   482,   483,    10,
      11,   471,    68,    85,    86,    87,    88,    89,    90,   470,
     569,   570,   572,   573,   576,   577,   579,   850,   852,   858,
     393,   394,     3,     3,     3,     3,     3,     3,     3,    10,
      11,   432,   433,   434,    10,    11,   447,   448,   449,   640,
     641,   665,   666,   690,   691,   730,   731,   760,   761,   791,
     792,   816,   861,   177,   820,   849,   160,     3,     3,     3,
       3,     3,     3,     3,     3,     4,   266,   930,     7,   580,
     580,   923,   925,   318,   950,     7,     7,   326,     7,    73,
       7,    78,     7,    83,   302,     3,   950,   981,   950,   985,
     310,   314,   316,   320,   874,     3,   104,   513,   514,     3,
       3,     3,   238,   240,  1022,  1023,   496,   497,    10,    11,
     485,    91,    93,    94,   484,   571,   572,   574,   578,   850,
     852,   858,    73,     4,     3,     3,     3,     3,     3,     3,
      10,    11,   396,   154,   169,   395,   857,   859,     7,   151,
     435,   584,   585,   592,   450,   584,    11,   180,   227,   228,
     642,   853,   862,   863,   864,    11,   667,   853,   862,    11,
     692,   853,   862,    11,   732,   853,   862,    11,   762,   853,
     862,    11,   793,   853,   862,    11,     3,    11,   821,     7,
       7,     7,     7,     7,     7,     7,   580,   581,   582,   274,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     304,   306,   874,   515,   100,   105,   526,  1024,  1025,    10,
      11,   499,    92,   498,   569,   570,   572,   575,   576,   577,
     850,   852,   858,    78,     3,     3,     3,     3,     7,     7,
       7,     7,     7,     7,    53,     3,     4,     3,   155,   855,
      55,   436,   156,   586,   587,    57,   451,   198,   643,   645,
     646,     3,     4,   198,   668,   670,   671,   198,   693,   695,
     696,   198,   733,   735,   736,   198,   763,   765,   766,   198,
     794,   796,   797,   950,     7,   223,   823,   824,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   950,    10,    11,
     110,   113,   516,   517,   518,   519,   520,   527,   106,   538,
      11,   860,   861,  1026,    83,     3,     7,     7,     7,     3,
       3,     3,     3,     3,     3,     7,     3,     3,    10,    11,
     593,   594,   595,   588,   589,   202,   644,   651,   652,    10,
      11,   647,   648,   649,     7,     3,   202,   669,   676,   677,
      10,    11,   672,   673,   674,   202,   694,   701,   702,    10,
      11,   697,   698,   699,   202,   734,   741,   742,    10,    11,
     737,   738,   739,   202,   764,   771,   772,    10,    11,   767,
     768,   769,   202,   795,   802,   803,    10,    11,   798,   799,
     800,   222,   817,     3,   225,   830,   831,   825,   851,   322,
     107,   521,   522,   523,     3,     3,    10,    11,   111,   113,
     528,   529,   530,   531,   532,   539,   950,     7,     3,     3,
       3,     3,     7,     5,   152,    11,   591,   153,   590,   856,
     857,   197,   204,   657,   658,    10,    11,   653,   654,   655,
     584,   650,     3,   207,   204,   682,   683,    10,    11,   678,
     679,   680,   584,   675,   209,   204,   707,   708,    10,    11,
     703,   704,   705,   584,   700,   211,   204,   747,   748,    10,
      11,   743,   744,   745,   584,   740,   213,   204,   777,   778,
      10,    11,   773,   774,   775,   584,   770,   216,   204,   808,
     809,    10,    11,   804,   805,   806,   584,   801,   837,   832,
     851,    10,    11,   826,   827,   828,   107,   522,   114,     7,
       7,   108,   533,   534,   535,     3,     3,    10,    11,   112,
     113,   540,   541,   542,   543,   554,   241,     3,     3,   152,
       7,     3,    10,    11,   659,   660,   661,   584,   656,   199,
      10,    11,   684,   685,   686,   584,   681,   199,    10,    11,
     709,   710,   711,   584,   706,   199,    10,    11,   749,   750,
     751,   584,   746,   199,    10,    11,   779,   780,   781,   584,
     776,   199,    10,    11,   810,   811,   812,   584,   807,   199,
     162,   165,   822,   838,   839,    10,    11,   833,   834,   835,
     584,   829,   182,   524,     3,     3,   108,   534,   116,     7,
       7,   109,   544,   545,   546,     3,     3,   157,     7,   151,
     596,   597,   602,   662,   203,   584,   687,   203,   712,   713,
     203,   752,   203,   782,   203,   584,   813,   203,   840,   841,
     584,   836,   224,     3,    10,    11,   525,   182,   536,     3,
       3,   109,   545,   118,     7,     7,     3,   855,   156,   598,
     599,   205,   205,   205,   156,   714,   715,   156,   205,   753,
     754,   156,   205,   783,   784,   205,    10,    11,   845,   846,
     847,   229,   230,   611,   613,   842,   843,   844,   226,     7,
     115,     3,    10,    11,   537,   182,   547,     3,     3,    10,
      11,   603,   604,   605,   600,   857,   716,   717,    10,    11,
     755,   756,   757,   785,   618,   848,   581,   581,     3,     7,
     117,     3,    10,    11,   548,     5,   152,    11,   601,    10,
      11,   720,   721,   722,   176,   181,   718,   719,   854,   874,
      11,   214,   786,   787,   788,   856,   857,   636,   163,     7,
       7,     3,     7,   119,   152,   580,   723,     3,     3,   157,
       7,     4,   581,   581,     3,   157,   157,   219,   724,   725,
     580,     7,   157,     3,   183,   726,     3,     3,     3,    11,
     727,   580,     7,     3,   220
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
    if (osglData->matrixCounter < parserData->numberOfMatrices) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
    osinstance->instanceData->matrices->numberOfMatrices = parserData->numberOfMatrices;
    osinstance->instanceData->matrices->matrix = osglData->matrix;
}
    break;

  case 30:

    {
    osinstance->instanceData->matrices = new Matrices();
}
    break;

  case 31:

    {
    if (parserData->numberOfMatrices < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
        osglData->matrix = new OSMatrix*[parserData->numberOfMatrices];
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
        osinstance->instanceData->cones->cone = new Cone*[parserData->numberOfCones];
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
    osglData->osglNumberOfEl = (osglData->numberOfRows)*(osglData->numberOfColumns);
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub 
        = new double[osglData->osglNumberOfEl];  
    ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb
        = new double[osglData->osglNumberOfEl];   
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
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of directions does not match");
}
    break;

  case 91:

    {
    osglData->typePresent = false;
    osglData->osglMultPresent = false;
    osglData->osglMult = 1;
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
std::cout << "found nonnegative direction in orthant cone" << std::endl; 
    }
    else if (osglData->type == "nonpositive")
    {
        ubt = 0.0;
        lbt = -OSDBL_MAX;
std::cout << "found nonpositive direction in orthant cone" << std::endl; 
    }
    else if (osglData->type == "free")
    {
        ubt =  OSDBL_MAX;
        lbt = -OSDBL_MAX;
std::cout << "found free direction in orthant cone" << std::endl; 
    }
    else if (osglData->type == "zero")
    {
        ubt = 0.0;
        lbt = 0.0;
std::cout << "found zero direction in orthant cone" << std::endl; 
    }
    else
    {
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "unrecognized direction type");
        osglData->osglMult = 0;
std::cout << "found unrecognized direction: " << osglData->type << std::endl;
    }
    for (int i=0; i < osglData->osglMult; i++)
    {
        ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->ub[osglData->osglCounter+i] = ubt;
        ((OrthantCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->lb[osglData->osglCounter+i] = lbt;
    }
    osglData->osglCounter += osglData->osglMult;
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
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 161:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 167:

    {
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of factors does not match numberOfEl");
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors = new IntVector();
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors->numberOfEl
        = osglData->osglNumberOfEl;
    ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->factors ->el 
        = osglData->osglIntArray;
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
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 180:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 186:

    {
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of components does not match numberOfEl");
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components = new IntVector();
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components->numberOfEl
        = osglData->osglNumberOfEl;
    ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->components ->el 
        = osglData->osglIntArray;
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
    parserData->kounter++;
}
    break;

  case 207:

    {
    if (parserData->kounter >= parserData->numberOfMatrixVar) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixVar greater than number attribute");
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->templateMatrixIdxPresent = false;
    parserData->varReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
    parserData->varTypePresent = false;
}
    break;

  case 208:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->numberOfRows
        = osglData->numberOfRows;
    osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->numberOfColumns
        = osglData->numberOfColumns;
    if (osglData->namePresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->name
            = osglData->name;
    if (parserData->templateMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->templateMatrixIdx
            = parserData->templateMatrixIdx;
    if (parserData->varReferenceMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->varReferenceMatrixIdx
            = parserData->varReferenceMatrixIdx;
    if (parserData->lbMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->lbMatrixIdx
            = parserData->lbMatrixIdx;
    if (parserData->lbConeIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->lbConeIdx
            = parserData->lbConeIdx;
    if (parserData->ubMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->ubMatrixIdx
            = parserData->ubMatrixIdx;
    if (parserData->ubConeIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->ubConeIdx
            = parserData->ubConeIdx;
    if (parserData->varTypePresent)
        osinstance->instanceData->matrixProgramming->matrixVariables->matrixVar[parserData->kounter]->varType
            = parserData->varType;
}
    break;

  case 224:

    {  
        if (parserData->kounter < parserData->numberOfMatrixObj)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj less than number attribute");
    }
    break;

  case 225:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives = new MatrixObjectives(); 
}
    break;

  case 226:

    {
    osinstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj = parserData->numberOfMatrixObj;
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj
        = new MatrixObj*[parserData->numberOfMatrixObj];
    for (int i=0; i < parserData->numberOfMatrixObj; i++)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i] = new MatrixObj();
    parserData->kounter = 0;
}
    break;

  case 234:

    {
    parserData->kounter++;
}
    break;

  case 235:

    {
    if (parserData->kounter >= parserData->numberOfMatrixObj) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixObj greater than number attribute");
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->templateMatrixIdxPresent = false;
    parserData->objReferenceMatrixIdxPresent = false;
    parserData->orderConeIdxPresent = false;
    parserData->constantMatrixIdxPresent = false;
}
    break;

  case 236:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->numberOfRows
        = osglData->numberOfRows;
    osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->numberOfColumns
            = osglData->numberOfColumns;
    if (osglData->namePresent)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->name
            = osglData->name;
    if (parserData->templateMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->templateMatrixIdx
            = parserData->templateMatrixIdx;
    if (parserData->objReferenceMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->objReferenceMatrixIdx
            = parserData->objReferenceMatrixIdx;
    if (parserData->orderConeIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->orderConeIdx
            = parserData->orderConeIdx;
    if (parserData->constantMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[parserData->kounter]->constantMatrixIdx
            = parserData->constantMatrixIdx;
}
    break;

  case 249:

    {  
        if (parserData->kounter < parserData->numberOfMatrixCon)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon less than number attribute");   
    }
    break;

  case 250:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints = new MatrixConstraints(); 
}
    break;

  case 251:

    {
    osinstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon = parserData->numberOfMatrixCon;
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon
        = new MatrixCon*[parserData->numberOfMatrixCon];
    for (int i=0; i < parserData->numberOfMatrixCon; i++)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i] = new MatrixCon();
    parserData->kounter = 0;
}
    break;

  case 259:

    {
    parserData->kounter++;
}
    break;

  case 260:

    {
    if (parserData->kounter >= parserData->numberOfMatrixCon) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrixCon greater than number attribute");
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    parserData->templateMatrixIdxPresent = false;
    parserData->conReferenceMatrixIdxPresent = false;
    parserData->lbMatrixIdxPresent = false;
    parserData->lbConeIdxPresent = false;
    parserData->ubMatrixIdxPresent = false;
    parserData->ubConeIdxPresent = false;
}
    break;

  case 261:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfRows\" missing");
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute \"numberOfColumns\" missing");
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->numberOfRows
        = osglData->numberOfRows;
    osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->numberOfColumns
        = osglData->numberOfColumns;
    if (osglData->namePresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->name
            = osglData->name;
    if (parserData->templateMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->templateMatrixIdx
            = parserData->templateMatrixIdx;
    if (parserData->conReferenceMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->conReferenceMatrixIdx
            = parserData->conReferenceMatrixIdx;
    if (parserData->lbMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->lbMatrixIdx
            = parserData->lbMatrixIdx;
    if (parserData->lbConeIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->lbConeIdx
            = parserData->lbConeIdx;
    if (parserData->ubMatrixIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->ubMatrixIdx
            = parserData->ubMatrixIdx;
    if (parserData->ubConeIdxPresent)
        osinstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[parserData->kounter]->ubConeIdx
            = parserData->ubConeIdx;
}
    break;

  case 277:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 284:

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

  case 285:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 286:

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

  case 289:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 290:

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

  case 292:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 297:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 302:

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

  case 303:

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

  case 304:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    break;

  case 305:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }
    break;

  case 310:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 312:

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

  case 316:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 321:

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

  case 322:

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

  case 323:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    break;

  case 324:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }
    break;

  case 329:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 331:

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

  case 334:

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

  case 335:

    {
      parserData->stageObjectivesON = true;
    }
    break;

  case 340:

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

  case 341:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    break;

  case 342:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }
    break;

  case 347:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 349:

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

  case 352:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 353:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}
    break;

  case 358:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    break;

  case 359:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }
    break;

  case 360:

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

  case 361:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 362:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}
    break;

  case 363:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    parserData->numberOfMatricesPresent = true;
    parserData->numberOfMatrices = (yyvsp[(3) - (4)].ival);
}
    break;

  case 364:

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

  case 365:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 366:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 367:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 368:

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

  case 369:

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

  case 370:

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

  case 371:

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

  case 372:

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

  case 373:

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

  case 374:

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

  case 375:

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

  case 376:

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

  case 377:

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

  case 378:

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

  case 379:

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

  case 380:

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

  case 381:

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

  case 382:

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

  case 383:

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

  case 384:

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

  case 385:

    { 
    if (parserData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one varType attribute");
    parserData->varTypePresent = true;
    if (returnVarType((yyvsp[(2) - (3)].sval)[0]) > 0)  
        parserData->varType = returnVarType((yyvsp[(2) - (3)].sval)[0]); 
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType must be one of C, B, I, S, D, J");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 386:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 387:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 395:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 400:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 406:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
std::cout << "IntVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 412:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 413:

    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 418:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 421:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
std::cout << "DblVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 427:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 428:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 429:

    {
    if (osglData->matrixCounter >= parserData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlkVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back((OSMatrix*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrix*)osglData->tempC);
std::cout << "push back a matrix" << std::endl;

}
    break;

  case 430:

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

  case 438:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 439:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 440:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 444:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
std::cout << "pop back mtxBlkVec" << std::endl;
}
    break;

  case 447:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
std::cout << "record a baseMatrix" << std::endl;
}
    break;

  case 448:

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
    osglData->baseMatrixEndRow = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows;
    osglData->baseMatrixEndCol = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns;
}
    break;

  case 449:

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

  case 461:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    ((MatrixType*)osglData->mtxBlkVec.back())->matrixType  = 
        mergeMatrixType(((MatrixType*)osglData->mtxBlkVec.back())->matrixType, osglData->matrix[(yyvsp[(3) - (4)].ival)]->matrixType);
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 462:

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

  case 463:

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

  case 464:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 465:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 466:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row exceeds matrix dimensions");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 467:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col exceeds matrix dimensions");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 468:

    { 
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposePresent = true;   
}
    break;

  case 471:

    {
    osglData->baseTranspose = true;
}
    break;

  case 472:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 473:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 477:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
std::cout << "add another child; numberOfChildren now " << osglData->mtxBlkVec.back()->inumberOfChildren << std::endl;
if (osglData->mtxBlkVec.back()->inumberOfChildren > 1000) return(100);
}
    break;

  case 487:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 488:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 491:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 492:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 496:

    {
    ((ConstantMatrixElements*)osglData->tempC)->start = new IntVector();
    ((ConstantMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 497:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 503:

    {
    ((ConstantMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((ConstantMatrixElements*)osglData->tempC)->indexes->numberOfEl
        = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    ((ConstantMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 504:

    {
    osglData->osglNumberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 510:

    {
    ((ConstantMatrixElements*)osglData->tempC)->values = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->values->numberOfEl = osglData->osglNumberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->values->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 511:

    {
    osglData->osglNumberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 518:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 519:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 522:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varref;
    }
    break;

  case 523:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 527:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->start = new IntVector();
    ((VarReferenceMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 528:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 534:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((VarReferenceMatrixElements*)osglData->tempC)->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 535:

    {
    osglData->osglNumberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 541:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->values = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->values->numberOfEl = osglData->osglNumberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 542:

    {
    osglData->osglNumberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 549:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 550:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 553:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 554:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 558:

    {
    ((LinearMatrixElements*)osglData->tempC)->start = new IntVector();
    ((LinearMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((LinearMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 559:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 565:

    {
    ((LinearMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((LinearMatrixElements*)osglData->tempC)->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((LinearMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 566:

    {
    osglData->osglNumberOfEl = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 572:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <values> element");
    }
    break;

  case 573:

    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((LinearMatrixElements*)osglData->tempC)->values->numberOfEl = osglData->osglNumberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 574:

    {
    osglData->osglNumberOfNonzeros = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglNonzeroCounter = 0;
    ((LinearMatrixElements*)osglData->tempC)->values = new LinearMatrixValues();
    ((LinearMatrixElements*)osglData->tempC)->values->numberOfEl
        = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;    
    ((LinearMatrixElements*)osglData->tempC)->values->el
        = new LinearMatrixElement*[((LinearMatrixElements*)osglData->tempC)->numberOfValues]; 
    for (int i=0; i < ((LinearMatrixElements*)osglData->tempC)->numberOfValues; i++)
        ((LinearMatrixElements*)osglData->tempC)->values->el[i] = new LinearMatrixElement(); 
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxPresent = false;
}
    break;

  case 582:

    {
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 583:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 584:

    {
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    osglData->osglCounter = 0;
}
    break;

  case 589:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglConstantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->constant
             = parserData->tempVal;
        osglData->osglConstantPresent = true;
    }
}
    break;

  case 597:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 599:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 600:

    {
    ((LinearMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 602:

    {
    osglData->tempC = new GeneralMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 603:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 606:

    {
        ((GeneralMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_general;
    }
    break;

  case 607:

    {
        ((GeneralMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 611:

    {
    ((GeneralMatrixElements*)osglData->tempC)->start = new IntVector();
    ((GeneralMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((GeneralMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 612:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 618:

    {
    ((GeneralMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((GeneralMatrixElements*)osglData->tempC)->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((GeneralMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 619:

    {
    osglData->osglNumberOfEl = ((GeneralMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 627:

    {
    osglData->osglNonzeroCounter = 0;
    osglData->osglNumberOfNonzeros = ((GeneralMatrixElements*)osglData->tempC)->numberOfValues;

    ((GeneralMatrixElements*)osglData->tempC)->values = new GeneralMatrixValues();
    ((GeneralMatrixElements*)osglData->tempC)->values->numberOfEl
        = osglData->osglNumberOfNonzeros;
    ((GeneralMatrixElements*)osglData->tempC)->values->el
        = new ScalarExpressionTree*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((GeneralMatrixElements*)osglData->tempC)->values->el[i] = new ScalarExpressionTree();
}
    break;

  case 635:

    {
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
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

  case 639:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((GeneralMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->osglNonzeroCounter++;
    }
    break;

  case 641:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 642:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 645:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conref;
    }
    break;

  case 646:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 650:

    {
    ((ConReferenceMatrixElements*)osglData->tempC)->start = new IntVector();
    ((ConReferenceMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((ConReferenceMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 651:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 657:

    {
    ((ConReferenceMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((ConReferenceMatrixElements*)osglData->tempC)->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((ConReferenceMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 658:

    {
    osglData->osglNumberOfEl = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 664:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <values> element");
    }
    break;

  case 665:

    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->values->numberOfEl = osglData->osglNumberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 666:

    {
    osglData->osglNumberOfNonzeros = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglNonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->values = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->values->numberOfEl
        = osglData->osglNumberOfNonzeros;
std::cout << "new conreference elements of size " << osglData->osglNumberOfNonzeros << std::endl;
    ((ConReferenceMatrixElements*)osglData->tempC)->values->el
        = new ConReferenceMatrixElement*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->values->el[i] = new ConReferenceMatrixElement();
}
    break;

  case 673:

    {
//    osglData->osglNonzeroCounter++;
//    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
//        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReference matrix elements: too many nonzeros");
}
    break;

  case 674:

    {
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->osglMultPresent = false;
        osglData->osglIncrPresent = false;
        osglData->osglMult = 1;
        osglData->osglIncr = 0;
        osglData->valueType = ENUM_CONREFERENCE_VALUETYPE_value;
    }
    break;

  case 680:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "only one valueType attribute allowed");

    std::string tmpStr = (yyvsp[(2) - (3)].sval); 
    if (returnConReferenceValueType(tmpStr) > 0)  
        osglData->valueType = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(tmpStr); 
    else
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,
            "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 681:

    {
    if (osglData->osglNonzeroCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
        {
std::cout << "Add a conreference element" << std::endl;
            ((ConReferenceMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter + i]->conReference
                = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;
            ((ConReferenceMatrixElements*)osglData->tempC)->values->el[osglData->osglNonzeroCounter]->valueType
                = osglData->valueType; 
        }
        osglData->osglNonzeroCounter += osglData->osglMult;
    }
    break;

  case 683:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 684:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 687:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objref;
    }
    break;

  case 688:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 692:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->start = new IntVector();
    ((ObjReferenceMatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 693:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 699:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->indexes = new IntVector();
    ((ObjReferenceMatrixElements*)osglData->tempC)->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 700:

    {
    osglData->osglNumberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 706:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->values = new IntVector();
    ((ObjReferenceMatrixElements*)osglData->tempC)->values->numberOfEl = osglData->osglNumberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 707:

    {
    osglData->osglNumberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 714:

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

  case 716:

    {
    ((MatrixTransformation*)osglData->tempC)->shape = osglData->shape;
}
    break;

  case 717:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 718:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;
    osglData->colOffsets.back() = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 719:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 720:

    {
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks    = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->m_mChildren       = new MatrixNode*[osglData->numberOfBlocks];
}
    break;

  case 723:

    {
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffsets->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 724:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 725:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 731:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 732:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 733:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 741:

    {
std::cout << "pop back mtxBlkVec" << std::endl;
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 742:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back((MatrixBlock*)osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);
std::cout << "push back a block" << std::endl;

    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}
    break;

  case 748:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 749:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 750:

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

  case 751:

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

  case 755:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 757:

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

  case 758:

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

  case 759:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 760:

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

  case 761:

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

  case 762:

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

  case 763:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 764:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 765:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 766:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 767:

    { 
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 768:

    { 
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        osglData->idx = (yyvsp[(3) - (4)].ival);
    }
    break;

  case 769:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (ENUM_NL_EXPR_SHAPE)returnNlExprShape((yyvsp[(2) - (3)].sval));
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 772:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 773:

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

  case 775:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 776:

    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 777:

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

  case 780:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 781:

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

  case 782:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 785:

    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new ScalarExpressionTree();
    }
    break;

  case 786:

    {
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape = osglData->shape;
    }
    break;

  case 814:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 818:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 822:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 824:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 826:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 828:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 830:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 832:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 834:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 836:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 838:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 840:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 842:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 844:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 846:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 847:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 848:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 849:

    {
}
    break;

  case 850:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 851:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 852:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 854:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 856:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 858:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 859:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 867:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 869:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 871:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 872:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 873:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 876:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 880:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 881:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 882:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 883:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 884:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 885:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 887:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 888:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 889:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 891:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 892:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 893:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 895:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 896:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 897:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 899:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 900:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 901:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 903:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 923:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 924:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 927:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 928:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 929:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 932:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 933:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 934:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 937:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 938:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 939:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 942:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 944:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 947:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 950:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 953:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 956:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 958:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 961:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 963:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 965:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 967:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 971:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 974:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 977:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 980:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 982:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 983:

    {
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 985:

    { 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
}
    break;

  case 987:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 990:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 993:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 996:

    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    }
    break;

  case 997:

    {               
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    }
    break;

  case 999:

    {
        if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "mismatched quotes");
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = (yyvsp[(3) - (4)].ival);  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr = new MatrixExpression*[ (yyvsp[(3) - (4)].ival) ];
        for (int i = 0; i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr; i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i] = new MatrixExpression();
}
    break;

  case 1006:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    }
    break;

  case 1007:

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

  case 1008:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
}
    break;

  case 1011:

    { 
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    }
    break;

  case 1012:

    {
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->shape = osglData->shape;
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


