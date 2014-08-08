
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
     EMPTYNAMEATT = 271,
     EMPTYTYPEATT = 272,
     IDXATT = 273,
     IDXONEATT = 274,
     IDXTWOATT = 275,
     NAMEATT = 276,
     TYPEATT = 277,
     VALUEATT = 278,
     QUADRATICCOEFFICIENTSSTART = 279,
     QUADRATICCOEFFICIENTSEND = 280,
     NUMBEROFQTERMSATT = 281,
     QTERMSTART = 282,
     QTERMEND = 283,
     MATRICESSTART = 284,
     MATRICESEND = 285,
     NUMBEROFMATRICESATT = 286,
     CONESSTART = 287,
     CONESEND = 288,
     NUMBEROFCONESATT = 289,
     NONNEGATIVECONESTART = 290,
     NONNEGATIVECONEEND = 291,
     NONPOSITIVECONESTART = 292,
     NONPOSITIVECONEEND = 293,
     ORTHANTCONESTART = 294,
     ORTHANTCONEEND = 295,
     QUADRATICCONESTART = 296,
     QUADRATICCONEEND = 297,
     ROTATEDQUADRATICCONESTART = 298,
     ROTATEDQUADRATICCONEEND = 299,
     SEMIDEFINITECONESTART = 300,
     SEMIDEFINITECONEEND = 301,
     PRODUCTCONESTART = 302,
     PRODUCTCONEEND = 303,
     INTERSECTIONCONESTART = 304,
     INTERSECTIONCONEEND = 305,
     DUALCONESTART = 306,
     DUALCONEEND = 307,
     POLARCONESTART = 308,
     POLARCONEEND = 309,
     FACTORSSTART = 310,
     FACTORSEND = 311,
     COMPONENTSSTART = 312,
     COMPONENTSEND = 313,
     NORMSCALEFACTORATT = 314,
     DISTORTIONMATRIXIDXATT = 315,
     AXISDIRECTIONATT = 316,
     FIRSTAXISDIRECTIONATT = 317,
     SECONDAXISDIRECTIONATT = 318,
     EMPTYSEMIDEFINITENESSATT = 319,
     SEMIDEFINITENESSATT = 320,
     MATRIXPROGRAMMINGSTART = 321,
     MATRIXPROGRAMMINGEND = 322,
     MATRIXVARIABLESSTART = 323,
     MATRIXVARIABLESEND = 324,
     NUMBEROFMATRIXVARATT = 325,
     MATRIXVARSTART = 326,
     MATRIXVAREND = 327,
     MATRIXOBJECTIVESSTART = 328,
     MATRIXOBJECTIVESEND = 329,
     NUMBEROFMATRIXOBJATT = 330,
     MATRIXOBJSTART = 331,
     MATRIXOBJEND = 332,
     MATRIXCONSTRAINTSSTART = 333,
     MATRIXCONSTRAINTSEND = 334,
     NUMBEROFMATRIXCONATT = 335,
     MATRIXCONSTART = 336,
     MATRIXCONEND = 337,
     NUMBEROFMATRIXTERMSATT = 338,
     MATRIXTERMSTART = 339,
     MATRIXTERMEND = 340,
     MATRIXEXPRESSIONSSTART = 341,
     MATRIXEXPRESSIONSEND = 342,
     NUMBEROFMATRIXEXPRATT = 343,
     MATRIXEXPRSTART = 344,
     MATRIXEXPREND = 345,
     MATRIXIDXATT = 346,
     LBMATRIXIDXATT = 347,
     LBCONEIDXATT = 348,
     UBMATRIXIDXATT = 349,
     UBCONEIDXATT = 350,
     PATTERNMATRIXIDXATT = 351,
     ORDERCONEIDXATT = 352,
     CONSTANTMATRIXIDXATT = 353,
     SHAPEATT = 354,
     EMPTYSHAPEATT = 355,
     TIMEDOMAINSTART = 356,
     TIMEDOMAINEND = 357,
     STAGESSTART = 358,
     STAGESEND = 359,
     STAGESTART = 360,
     STAGEEND = 361,
     NUMBEROFSTAGESATT = 362,
     HORIZONATT = 363,
     STARTATT = 364,
     VARIABLESSTART = 365,
     CONSTRAINTSSTART = 366,
     OBJECTIVESSTART = 367,
     VARIABLESEND = 368,
     CONSTRAINTSEND = 369,
     OBJECTIVESEND = 370,
     NUMBEROFVARIABLESATT = 371,
     NUMBEROFCONSTRAINTSATT = 372,
     NUMBEROFOBJECTIVESATT = 373,
     STARTIDXATT = 374,
     VARSTART = 375,
     VAREND = 376,
     CONSTART = 377,
     CONEND = 378,
     OBJSTART = 379,
     OBJEND = 380,
     INTERVALSTART = 381,
     INTERVALEND = 382,
     HEADERSTART = 383,
     HEADEREND = 384,
     FILENAMESTART = 385,
     FILENAMEEND = 386,
     FILENAMEEMPTY = 387,
     FILENAMESTARTANDEND = 388,
     FILESOURCESTART = 389,
     FILESOURCEEND = 390,
     FILESOURCEEMPTY = 391,
     FILESOURCESTARTANDEND = 392,
     FILEDESCRIPTIONSTART = 393,
     FILEDESCRIPTIONEND = 394,
     FILEDESCRIPTIONEMPTY = 395,
     FILEDESCRIPTIONSTARTANDEND = 396,
     FILECREATORSTART = 397,
     FILECREATOREND = 398,
     FILECREATOREMPTY = 399,
     FILECREATORSTARTANDEND = 400,
     FILELICENCESTART = 401,
     FILELICENCEEND = 402,
     FILELICENCEEMPTY = 403,
     FILELICENCESTARTANDEND = 404,
     ENUMERATIONSTART = 405,
     ENUMERATIONEND = 406,
     NUMBEROFELATT = 407,
     ITEMEMPTY = 408,
     ITEMSTART = 409,
     ITEMEND = 410,
     ITEMSTARTANDEND = 411,
     BASE64START = 412,
     BASE64END = 413,
     INCRATT = 414,
     MULTATT = 415,
     SIZEOFATT = 416,
     ELSTART = 417,
     ELEND = 418,
     MATRIXSTART = 419,
     MATRIXEND = 420,
     BASEMATRIXEND = 421,
     BASEMATRIXSTART = 422,
     BLOCKSTART = 423,
     BLOCKEND = 424,
     BLOCKSSTART = 425,
     BLOCKSEND = 426,
     EMPTYSYMMETRYATT = 427,
     SYMMETRYATT = 428,
     EMPTYEXCLUDEATT = 429,
     EXCLUDEATT = 430,
     CONSTANTATT = 431,
     NUMBEROFBLOCKSATT = 432,
     NUMBEROFCOLUMNSATT = 433,
     NUMBEROFROWSATT = 434,
     NUMBEROFVARIDXATT = 435,
     BASEMATRIXIDXATT = 436,
     TARGETMATRIXFIRSTROWATT = 437,
     TARGETMATRIXFIRSTCOLATT = 438,
     BASEMATRIXSTARTROWATT = 439,
     BASEMATRIXSTARTCOLATT = 440,
     BASEMATRIXENDROWATT = 441,
     BASEMATRIXENDCOLATT = 442,
     SCALARMULTIPLIERATT = 443,
     EMPTYBASETRANSPOSEATT = 444,
     BASETRANSPOSEATT = 445,
     ELEMENTSSTART = 446,
     ELEMENTSEND = 447,
     CONSTANTELEMENTSSTART = 448,
     CONSTANTELEMENTSEND = 449,
     STARTVECTORSTART = 450,
     STARTVECTOREND = 451,
     NONZEROSSTART = 452,
     NONZEROSEND = 453,
     INDEXESSTART = 454,
     INDEXESEND = 455,
     VALUESSTART = 456,
     VALUESEND = 457,
     VARREFERENCEELEMENTSSTART = 458,
     VARREFERENCEELEMENTSEND = 459,
     LINEARELEMENTSSTART = 460,
     LINEARELEMENTSEND = 461,
     GENERALELEMENTSSTART = 462,
     GENERALELEMENTSEND = 463,
     CONREFERENCEELEMENTSSTART = 464,
     CONREFERENCEELEMENTSEND = 465,
     OBJREFERENCEELEMENTSSTART = 466,
     OBJREFERENCEELEMENTSEND = 467,
     PATTERNELEMENTSSTART = 468,
     PATTERNELEMENTSEND = 469,
     VARIDXSTART = 470,
     VARIDXEND = 471,
     TRANSFORMATIONSTART = 472,
     TRANSFORMATIONEND = 473,
     COLOFFSETSSTART = 474,
     COLOFFSETSEND = 475,
     ROWOFFSETSSTART = 476,
     ROWOFFSETSEND = 477,
     EMPTYROWMAJORATT = 478,
     ROWMAJORATT = 479,
     BLOCKROWIDXATT = 480,
     BLOCKCOLIDXATT = 481,
     DUMMY = 482,
     NONLINEAREXPRESSIONSSTART = 483,
     NONLINEAREXPRESSIONSEND = 484,
     NUMBEROFNONLINEAREXPRESSIONS = 485,
     NLSTART = 486,
     NLEND = 487,
     POWERSTART = 488,
     POWEREND = 489,
     PLUSSTART = 490,
     PLUSEND = 491,
     MINUSSTART = 492,
     MINUSEND = 493,
     DIVIDESTART = 494,
     DIVIDEEND = 495,
     LNSTART = 496,
     LNEND = 497,
     SQRTSTART = 498,
     SQRTEND = 499,
     SUMSTART = 500,
     SUMEND = 501,
     PRODUCTSTART = 502,
     PRODUCTEND = 503,
     EXPSTART = 504,
     EXPEND = 505,
     NEGATESTART = 506,
     NEGATEEND = 507,
     IFSTART = 508,
     IFEND = 509,
     SQUARESTART = 510,
     SQUAREEND = 511,
     COSSTART = 512,
     COSEND = 513,
     SINSTART = 514,
     SINEND = 515,
     VARIABLESTART = 516,
     VARIABLEEND = 517,
     ABSSTART = 518,
     ABSEND = 519,
     ERFSTART = 520,
     ERFEND = 521,
     MAXSTART = 522,
     MAXEND = 523,
     ALLDIFFSTART = 524,
     ALLDIFFEND = 525,
     MINSTART = 526,
     MINEND = 527,
     ESTART = 528,
     EEND = 529,
     PISTART = 530,
     PIEND = 531,
     TIMESSTART = 532,
     TIMESEND = 533,
     NUMBERSTART = 534,
     NUMBEREND = 535,
     MATRIXTRACESTART = 536,
     MATRIXTRACEEND = 537,
     MATRIXTOSCALARSTART = 538,
     MATRIXTOSCALAREND = 539,
     MATRIXDIAGONALSTART = 540,
     MATRIXDIAGONALEND = 541,
     MATRIXDOTTIMESSTART = 542,
     MATRIXDOTTIMESEND = 543,
     MATRIXIDENTITYSTART = 544,
     MATRIXIDENTITYEND = 545,
     MATRIXINVERSESTART = 546,
     MATRIXINVERSEEND = 547,
     MATRIXLOWERTRIANGLESTART = 548,
     MATRIXLOWERTRIANGLEEND = 549,
     MATRIXUPPERTRIANGLESTART = 550,
     MATRIXUPPERTRIANGLEEND = 551,
     MATRIXMERGESTART = 552,
     MATRIXMERGEEND = 553,
     MATRIXMINUSSTART = 554,
     MATRIXMINUSEND = 555,
     MATRIXPLUSSTART = 556,
     MATRIXPLUSEND = 557,
     MATRIXTIMESSTART = 558,
     MATRIXTIMESEND = 559,
     MATRIXSCALARTIMESSTART = 560,
     MATRIXSCALARTIMESEND = 561,
     MATRIXSUBMATRIXATSTART = 562,
     MATRIXSUBMATRIXATEND = 563,
     MATRIXTRANSPOSESTART = 564,
     MATRIXTRANSPOSEEND = 565,
     EMPTYINCLUDEDIAGONALATT = 566,
     INCLUDEDIAGONALATT = 567,
     IDATT = 568,
     COEFATT = 569
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
#define EMPTYNAMEATT 271
#define EMPTYTYPEATT 272
#define IDXATT 273
#define IDXONEATT 274
#define IDXTWOATT 275
#define NAMEATT 276
#define TYPEATT 277
#define VALUEATT 278
#define QUADRATICCOEFFICIENTSSTART 279
#define QUADRATICCOEFFICIENTSEND 280
#define NUMBEROFQTERMSATT 281
#define QTERMSTART 282
#define QTERMEND 283
#define MATRICESSTART 284
#define MATRICESEND 285
#define NUMBEROFMATRICESATT 286
#define CONESSTART 287
#define CONESEND 288
#define NUMBEROFCONESATT 289
#define NONNEGATIVECONESTART 290
#define NONNEGATIVECONEEND 291
#define NONPOSITIVECONESTART 292
#define NONPOSITIVECONEEND 293
#define ORTHANTCONESTART 294
#define ORTHANTCONEEND 295
#define QUADRATICCONESTART 296
#define QUADRATICCONEEND 297
#define ROTATEDQUADRATICCONESTART 298
#define ROTATEDQUADRATICCONEEND 299
#define SEMIDEFINITECONESTART 300
#define SEMIDEFINITECONEEND 301
#define PRODUCTCONESTART 302
#define PRODUCTCONEEND 303
#define INTERSECTIONCONESTART 304
#define INTERSECTIONCONEEND 305
#define DUALCONESTART 306
#define DUALCONEEND 307
#define POLARCONESTART 308
#define POLARCONEEND 309
#define FACTORSSTART 310
#define FACTORSEND 311
#define COMPONENTSSTART 312
#define COMPONENTSEND 313
#define NORMSCALEFACTORATT 314
#define DISTORTIONMATRIXIDXATT 315
#define AXISDIRECTIONATT 316
#define FIRSTAXISDIRECTIONATT 317
#define SECONDAXISDIRECTIONATT 318
#define EMPTYSEMIDEFINITENESSATT 319
#define SEMIDEFINITENESSATT 320
#define MATRIXPROGRAMMINGSTART 321
#define MATRIXPROGRAMMINGEND 322
#define MATRIXVARIABLESSTART 323
#define MATRIXVARIABLESEND 324
#define NUMBEROFMATRIXVARATT 325
#define MATRIXVARSTART 326
#define MATRIXVAREND 327
#define MATRIXOBJECTIVESSTART 328
#define MATRIXOBJECTIVESEND 329
#define NUMBEROFMATRIXOBJATT 330
#define MATRIXOBJSTART 331
#define MATRIXOBJEND 332
#define MATRIXCONSTRAINTSSTART 333
#define MATRIXCONSTRAINTSEND 334
#define NUMBEROFMATRIXCONATT 335
#define MATRIXCONSTART 336
#define MATRIXCONEND 337
#define NUMBEROFMATRIXTERMSATT 338
#define MATRIXTERMSTART 339
#define MATRIXTERMEND 340
#define MATRIXEXPRESSIONSSTART 341
#define MATRIXEXPRESSIONSEND 342
#define NUMBEROFMATRIXEXPRATT 343
#define MATRIXEXPRSTART 344
#define MATRIXEXPREND 345
#define MATRIXIDXATT 346
#define LBMATRIXIDXATT 347
#define LBCONEIDXATT 348
#define UBMATRIXIDXATT 349
#define UBCONEIDXATT 350
#define PATTERNMATRIXIDXATT 351
#define ORDERCONEIDXATT 352
#define CONSTANTMATRIXIDXATT 353
#define SHAPEATT 354
#define EMPTYSHAPEATT 355
#define TIMEDOMAINSTART 356
#define TIMEDOMAINEND 357
#define STAGESSTART 358
#define STAGESEND 359
#define STAGESTART 360
#define STAGEEND 361
#define NUMBEROFSTAGESATT 362
#define HORIZONATT 363
#define STARTATT 364
#define VARIABLESSTART 365
#define CONSTRAINTSSTART 366
#define OBJECTIVESSTART 367
#define VARIABLESEND 368
#define CONSTRAINTSEND 369
#define OBJECTIVESEND 370
#define NUMBEROFVARIABLESATT 371
#define NUMBEROFCONSTRAINTSATT 372
#define NUMBEROFOBJECTIVESATT 373
#define STARTIDXATT 374
#define VARSTART 375
#define VAREND 376
#define CONSTART 377
#define CONEND 378
#define OBJSTART 379
#define OBJEND 380
#define INTERVALSTART 381
#define INTERVALEND 382
#define HEADERSTART 383
#define HEADEREND 384
#define FILENAMESTART 385
#define FILENAMEEND 386
#define FILENAMEEMPTY 387
#define FILENAMESTARTANDEND 388
#define FILESOURCESTART 389
#define FILESOURCEEND 390
#define FILESOURCEEMPTY 391
#define FILESOURCESTARTANDEND 392
#define FILEDESCRIPTIONSTART 393
#define FILEDESCRIPTIONEND 394
#define FILEDESCRIPTIONEMPTY 395
#define FILEDESCRIPTIONSTARTANDEND 396
#define FILECREATORSTART 397
#define FILECREATOREND 398
#define FILECREATOREMPTY 399
#define FILECREATORSTARTANDEND 400
#define FILELICENCESTART 401
#define FILELICENCEEND 402
#define FILELICENCEEMPTY 403
#define FILELICENCESTARTANDEND 404
#define ENUMERATIONSTART 405
#define ENUMERATIONEND 406
#define NUMBEROFELATT 407
#define ITEMEMPTY 408
#define ITEMSTART 409
#define ITEMEND 410
#define ITEMSTARTANDEND 411
#define BASE64START 412
#define BASE64END 413
#define INCRATT 414
#define MULTATT 415
#define SIZEOFATT 416
#define ELSTART 417
#define ELEND 418
#define MATRIXSTART 419
#define MATRIXEND 420
#define BASEMATRIXEND 421
#define BASEMATRIXSTART 422
#define BLOCKSTART 423
#define BLOCKEND 424
#define BLOCKSSTART 425
#define BLOCKSEND 426
#define EMPTYSYMMETRYATT 427
#define SYMMETRYATT 428
#define EMPTYEXCLUDEATT 429
#define EXCLUDEATT 430
#define CONSTANTATT 431
#define NUMBEROFBLOCKSATT 432
#define NUMBEROFCOLUMNSATT 433
#define NUMBEROFROWSATT 434
#define NUMBEROFVARIDXATT 435
#define BASEMATRIXIDXATT 436
#define TARGETMATRIXFIRSTROWATT 437
#define TARGETMATRIXFIRSTCOLATT 438
#define BASEMATRIXSTARTROWATT 439
#define BASEMATRIXSTARTCOLATT 440
#define BASEMATRIXENDROWATT 441
#define BASEMATRIXENDCOLATT 442
#define SCALARMULTIPLIERATT 443
#define EMPTYBASETRANSPOSEATT 444
#define BASETRANSPOSEATT 445
#define ELEMENTSSTART 446
#define ELEMENTSEND 447
#define CONSTANTELEMENTSSTART 448
#define CONSTANTELEMENTSEND 449
#define STARTVECTORSTART 450
#define STARTVECTOREND 451
#define NONZEROSSTART 452
#define NONZEROSEND 453
#define INDEXESSTART 454
#define INDEXESEND 455
#define VALUESSTART 456
#define VALUESEND 457
#define VARREFERENCEELEMENTSSTART 458
#define VARREFERENCEELEMENTSEND 459
#define LINEARELEMENTSSTART 460
#define LINEARELEMENTSEND 461
#define GENERALELEMENTSSTART 462
#define GENERALELEMENTSEND 463
#define CONREFERENCEELEMENTSSTART 464
#define CONREFERENCEELEMENTSEND 465
#define OBJREFERENCEELEMENTSSTART 466
#define OBJREFERENCEELEMENTSEND 467
#define PATTERNELEMENTSSTART 468
#define PATTERNELEMENTSEND 469
#define VARIDXSTART 470
#define VARIDXEND 471
#define TRANSFORMATIONSTART 472
#define TRANSFORMATIONEND 473
#define COLOFFSETSSTART 474
#define COLOFFSETSEND 475
#define ROWOFFSETSSTART 476
#define ROWOFFSETSEND 477
#define EMPTYROWMAJORATT 478
#define ROWMAJORATT 479
#define BLOCKROWIDXATT 480
#define BLOCKCOLIDXATT 481
#define DUMMY 482
#define NONLINEAREXPRESSIONSSTART 483
#define NONLINEAREXPRESSIONSEND 484
#define NUMBEROFNONLINEAREXPRESSIONS 485
#define NLSTART 486
#define NLEND 487
#define POWERSTART 488
#define POWEREND 489
#define PLUSSTART 490
#define PLUSEND 491
#define MINUSSTART 492
#define MINUSEND 493
#define DIVIDESTART 494
#define DIVIDEEND 495
#define LNSTART 496
#define LNEND 497
#define SQRTSTART 498
#define SQRTEND 499
#define SUMSTART 500
#define SUMEND 501
#define PRODUCTSTART 502
#define PRODUCTEND 503
#define EXPSTART 504
#define EXPEND 505
#define NEGATESTART 506
#define NEGATEEND 507
#define IFSTART 508
#define IFEND 509
#define SQUARESTART 510
#define SQUAREEND 511
#define COSSTART 512
#define COSEND 513
#define SINSTART 514
#define SINEND 515
#define VARIABLESTART 516
#define VARIABLEEND 517
#define ABSSTART 518
#define ABSEND 519
#define ERFSTART 520
#define ERFEND 521
#define MAXSTART 522
#define MAXEND 523
#define ALLDIFFSTART 524
#define ALLDIFFEND 525
#define MINSTART 526
#define MINEND 527
#define ESTART 528
#define EEND 529
#define PISTART 530
#define PIEND 531
#define TIMESSTART 532
#define TIMESEND 533
#define NUMBERSTART 534
#define NUMBEREND 535
#define MATRIXTRACESTART 536
#define MATRIXTRACEEND 537
#define MATRIXTOSCALARSTART 538
#define MATRIXTOSCALAREND 539
#define MATRIXDIAGONALSTART 540
#define MATRIXDIAGONALEND 541
#define MATRIXDOTTIMESSTART 542
#define MATRIXDOTTIMESEND 543
#define MATRIXIDENTITYSTART 544
#define MATRIXIDENTITYEND 545
#define MATRIXINVERSESTART 546
#define MATRIXINVERSEEND 547
#define MATRIXLOWERTRIANGLESTART 548
#define MATRIXLOWERTRIANGLEEND 549
#define MATRIXUPPERTRIANGLESTART 550
#define MATRIXUPPERTRIANGLEEND 551
#define MATRIXMERGESTART 552
#define MATRIXMERGEEND 553
#define MATRIXMINUSSTART 554
#define MATRIXMINUSEND 555
#define MATRIXPLUSSTART 556
#define MATRIXPLUSEND 557
#define MATRIXTIMESSTART 558
#define MATRIXTIMESEND 559
#define MATRIXSCALARTIMESSTART 560
#define MATRIXSCALARTIMESEND 561
#define MATRIXSUBMATRIXATSTART 562
#define MATRIXSUBMATRIXATEND 563
#define MATRIXTRANSPOSESTART 564
#define MATRIXTRANSPOSEEND 565
#define EMPTYINCLUDEDIAGONALATT 566
#define INCLUDEDIAGONALATT 567
#define IDATT 568
#define COEFATT 569




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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  319
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  595
/* YYNRULES -- Number of rules.  */
#define YYNRULES  868
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1402

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   569

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   316,
     318,     2,     2,   317,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   315,     2,     2,     2,     2,     2,     2,     2,
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    16,    18,    20,    21,    22,
      27,    33,    34,    37,    41,    43,    45,    48,    49,    52,
      54,    56,    58,    60,    65,    70,    75,    80,    81,    85,
      87,    89,    91,    93,    95,    99,   100,   103,   104,   108,
     110,   112,   114,   116,   118,   122,   123,   126,   128,   130,
     132,   134,   136,   138,   140,   144,   146,   148,   149,   152,
     154,   156,   158,   160,   163,   167,   169,   171,   172,   175,
     177,   179,   181,   183,   186,   190,   192,   194,   195,   198,
     200,   202,   204,   206,   208,   210,   212,   215,   219,   221,
     223,   224,   227,   229,   231,   233,   235,   237,   239,   241,
     243,   246,   250,   252,   254,   255,   258,   260,   262,   264,
     266,   268,   271,   275,   277,   279,   280,   283,   285,   287,
     289,   292,   296,   298,   300,   303,   305,   307,   310,   312,
     315,   319,   321,   323,   324,   327,   329,   331,   333,   336,
     340,   342,   344,   347,   349,   351,   354,   356,   359,   360,
     364,   366,   367,   369,   371,   373,   380,   381,   385,   387,
     389,   392,   394,   397,   398,   401,   405,   407,   409,   410,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   432,
     433,   437,   439,   441,   444,   446,   449,   450,   453,   458,
     460,   462,   463,   466,   468,   470,   472,   474,   476,   478,
     480,   482,   484,   487,   488,   491,   495,   498,   500,   501,
     505,   507,   509,   512,   514,   517,   518,   521,   526,   528,
     530,   531,   534,   536,   538,   540,   542,   544,   546,   548,
     550,   552,   554,   556,   559,   560,   563,   567,   570,   572,
     574,   577,   581,   583,   585,   587,   589,   591,   595,   596,
     599,   604,   605,   608,   610,   612,   614,   616,   619,   623,
     627,   632,   634,   640,   642,   645,   646,   651,   652,   656,
     658,   662,   666,   667,   671,   672,   675,   677,   679,   684,
     689,   691,   695,   697,   700,   702,   705,   706,   711,   716,
     718,   721,   722,   726,   727,   730,   732,   734,   739,   744,
     746,   750,   752,   755,   757,   760,   761,   766,   771,   773,
     776,   777,   781,   782,   785,   787,   789,   794,   796,   800,
     802,   805,   807,   810,   811,   816,   821,   823,   826,   827,
     832,   834,   837,   838,   841,   843,   845,   850,   855,   860,
     865,   870,   875,   880,   885,   890,   895,   900,   905,   910,
     914,   918,   923,   928,   933,   938,   943,   947,   952,   957,
     962,   967,   972,   977,   982,   987,   991,   995,   998,   999,
    1002,  1004,  1006,  1008,  1010,  1012,  1014,  1015,  1018,  1022,
    1024,  1026,  1027,  1030,  1032,  1034,  1038,  1042,  1044,  1046,
    1049,  1051,  1055,  1056,  1059,  1063,  1065,  1066,  1068,  1072,
    1076,  1078,  1082,  1086,  1090,  1092,  1096,  1100,  1104,  1106,
    1108,  1109,  1112,  1114,  1116,  1118,  1120,  1122,  1126,  1130,
    1134,  1136,  1138,  1140,  1144,  1147,  1148,  1152,  1154,  1156,
    1157,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,  1176,
    1178,  1183,  1188,  1193,  1198,  1203,  1208,  1213,  1215,  1217,
    1219,  1221,  1225,  1230,  1233,  1235,  1236,  1239,  1241,  1243,
    1245,  1249,  1251,  1252,  1254,  1256,  1258,  1260,  1264,  1267,
    1269,  1278,  1281,  1282,  1285,  1287,  1290,  1293,  1295,  1297,
    1299,  1301,  1305,  1307,  1311,  1313,  1314,  1318,  1320,  1323,
    1326,  1328,  1330,  1332,  1334,  1338,  1340,  1344,  1346,  1347,
    1350,  1352,  1355,  1358,  1360,  1362,  1364,  1366,  1370,  1372,
    1376,  1378,  1380,  1384,  1387,  1388,  1391,  1393,  1395,  1397,
    1399,  1403,  1405,  1406,  1409,  1411,  1413,  1415,  1417,  1421,
    1422,  1425,  1429,  1431,  1433,  1434,  1437,  1439,  1441,  1446,
    1448,  1450,  1452,  1456,  1457,  1460,  1464,  1466,  1467,  1472,
    1476,  1477,  1480,  1482,  1485,  1488,  1490,  1492,  1494,  1496,
    1500,  1502,  1506,  1508,  1510,  1514,  1517,  1518,  1521,  1523,
    1525,  1527,  1529,  1533,  1535,  1536,  1539,  1541,  1543,  1545,
    1547,  1551,  1552,  1555,  1558,  1560,  1562,  1564,  1566,  1570,
    1571,  1575,  1577,  1580,  1583,  1585,  1587,  1589,  1591,  1595,
    1597,  1601,  1603,  1604,  1608,  1610,  1613,  1616,  1618,  1620,
    1622,  1624,  1628,  1630,  1634,  1636,  1637,  1642,  1644,  1645,
    1647,  1649,  1651,  1653,  1657,  1660,  1664,  1666,  1668,  1670,
    1672,  1674,  1678,  1680,  1684,  1686,  1690,  1692,  1694,  1698,
    1700,  1702,  1706,  1710,  1712,  1714,  1716,  1718,  1720,  1724,
    1726,  1730,  1732,  1734,  1736,  1738,  1740,  1744,  1746,  1747,
    1750,  1754,  1756,  1758,  1759,  1762,  1764,  1766,  1768,  1773,
    1778,  1780,  1782,  1785,  1787,  1791,  1794,  1799,  1804,  1809,
    1814,  1819,  1824,  1829,  1834,  1835,  1840,  1846,  1847,  1848,
    1856,  1858,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,
    1879,  1881,  1883,  1885,  1887,  1889,  1891,  1893,  1895,  1897,
    1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1914,  1920,
    1921,  1927,  1928,  1934,  1935,  1940,  1941,  1947,  1948,  1954,
    1955,  1960,  1961,  1964,  1965,  1970,  1971,  1974,  1975,  1980,
    1981,  1984,  1985,  1990,  1991,  1994,  1995,  2000,  2001,  2004,
    2005,  2010,  2011,  2016,  2017,  2022,  2023,  2028,  2029,  2034,
    2035,  2040,  2041,  2046,  2047,  2052,  2053,  2060,  2061,  2065,
    2067,  2070,  2071,  2075,  2077,  2080,  2081,  2086,  2088,  2091,
    2092,  2095,  2097,  2099,  2101,  2102,  2107,  2108,  2113,  2118,
    2119,  2124,  2126,  2127,  2132,  2135,  2136,  2139,  2141,  2143,
    2148,  2153,  2154,  2159,  2160,  2165,  2167,  2169,  2171,  2173,
    2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,
    2194,  2199,  2201,  2204,  2209,  2212,  2214,  2217,  2220,  2222,
    2226,  2229,  2231,  2234,  2237,  2239,  2242,  2246,  2248,  2249,
    2251,  2254,  2258,  2260,  2261,  2263,  2266,  2270,  2273,  2275,
    2277,  2280,  2283,  2285,  2289,  2292,  2294,  2298,  2301,  2303,
    2307,  2310,  2312,  2316,  2319,  2321,  2328,  2331,  2333
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     320,     0,    -1,   324,   789,   336,   343,   407,   463,   321,
     322,    -1,    14,    -1,    13,    -1,   323,    -1,    12,    -1,
      -1,    -1,    24,   325,   326,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   326,   327,    -1,   328,   330,   329,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   330,
     331,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     314,     3,   546,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   337,   338,   339,    -1,    29,    -1,   521,    -1,   340,
      -1,   341,    -1,    10,    -1,    11,   342,    30,    -1,    -1,
     342,   575,    -1,    -1,   344,   345,   346,    -1,    32,    -1,
     522,    -1,   347,    -1,   348,    -1,    10,    -1,    11,   349,
      33,    -1,    -1,   349,   350,    -1,   351,    -1,   357,    -1,
     363,    -1,   369,    -1,   375,    -1,   381,    -1,   394,    -1,
     352,   353,   356,    -1,    35,    -1,   354,    -1,    -1,   354,
     355,    -1,   523,    -1,   524,    -1,   530,    -1,    10,    -1,
      11,    36,    -1,   358,   359,   362,    -1,    37,    -1,   360,
      -1,    -1,   360,   361,    -1,   523,    -1,   524,    -1,   530,
      -1,    10,    -1,    11,    38,    -1,   364,   365,   368,    -1,
      41,    -1,   366,    -1,    -1,   366,   367,    -1,   523,    -1,
     524,    -1,   530,    -1,   533,    -1,   532,    -1,   534,    -1,
      10,    -1,    11,    42,    -1,   370,   371,   374,    -1,    43,
      -1,   372,    -1,    -1,   372,   373,    -1,   523,    -1,   524,
      -1,   530,    -1,   533,    -1,   532,    -1,   535,    -1,   536,
      -1,    10,    -1,    11,    44,    -1,   376,   377,   380,    -1,
      45,    -1,   378,    -1,    -1,   378,   379,    -1,   523,    -1,
     524,    -1,   530,    -1,   537,    -1,    10,    -1,    11,    46,
      -1,   382,   383,   386,    -1,    47,    -1,   384,    -1,    -1,
     384,   385,    -1,   523,    -1,   524,    -1,   530,    -1,   387,
     393,    -1,   388,   389,   390,    -1,    55,    -1,   520,    -1,
     391,   392,    -1,   550,    -1,    10,    -1,    11,    56,    -1,
      10,    -1,    11,    48,    -1,   395,   396,   399,    -1,    49,
      -1,   397,    -1,    -1,   397,   398,    -1,   523,    -1,   524,
      -1,   530,    -1,   400,   406,    -1,   401,   402,   403,    -1,
      57,    -1,   520,    -1,   404,   405,    -1,   550,    -1,    10,
      -1,    11,    58,    -1,    10,    -1,    11,    50,    -1,    -1,
     408,   409,   410,    -1,    66,    -1,    -1,   411,    -1,   412,
      -1,    10,    -1,    11,   413,   425,   442,   455,    67,    -1,
      -1,   414,   415,   416,    -1,    68,    -1,   525,    -1,   418,
     417,    -1,    10,    -1,    11,    69,    -1,    -1,   418,   419,
      -1,   420,   421,   424,    -1,    71,    -1,   422,    -1,    -1,
     422,   423,    -1,   538,    -1,   539,    -1,   541,    -1,   542,
      -1,   543,    -1,   545,    -1,   530,    -1,    10,    -1,    11,
      72,    -1,    -1,   426,   427,   428,    -1,    73,    -1,   526,
      -1,   430,   429,    -1,    10,    -1,    11,    74,    -1,    -1,
     430,   431,    -1,   432,   433,   436,   437,    -1,    76,    -1,
     434,    -1,    -1,   434,   435,    -1,   538,    -1,   544,    -1,
     540,    -1,   545,    -1,   530,    -1,   531,    -1,   528,    -1,
     438,    -1,    10,    -1,    11,    77,    -1,    -1,   438,   439,
      -1,   440,   868,   441,    -1,    84,    11,    -1,    85,    -1,
      -1,   443,   444,   445,    -1,    78,    -1,   527,    -1,   447,
     446,    -1,    10,    -1,    11,    79,    -1,    -1,   447,   448,
      -1,   449,   450,   453,   454,    -1,    81,    -1,   451,    -1,
      -1,   451,   452,    -1,   538,    -1,   539,    -1,   541,    -1,
     542,    -1,   543,    -1,   545,    -1,   530,    -1,   531,    -1,
     528,    -1,   438,    -1,    10,    -1,    11,    82,    -1,    -1,
     438,   439,    -1,   440,   868,   441,    -1,    84,    11,    -1,
      85,    -1,    10,    -1,    11,    82,    -1,   456,   457,   458,
      -1,    86,    -1,   529,    -1,   459,    -1,   460,    -1,    10,
      -1,    11,   461,    87,    -1,    -1,   461,   462,    -1,    89,
      11,   795,    90,    -1,    -1,   464,   465,    -1,   101,    -1,
     466,    -1,   467,    -1,    10,    -1,    11,   102,    -1,    11,
     468,   102,    -1,    11,   512,   102,    -1,   469,   470,   471,
     104,    -1,   103,    -1,   107,     3,     7,     3,    11,    -1,
     472,    -1,   471,   472,    -1,    -1,   473,   105,   474,   475,
      -1,    -1,    21,     4,     3,    -1,    10,    -1,    11,   476,
     106,    -1,   477,   489,   501,    -1,    -1,   110,   478,   482,
      -1,    -1,   478,   479,    -1,   480,    -1,   481,    -1,   116,
       3,     7,     3,    -1,   119,     3,     7,     3,    -1,   483,
      -1,    11,   484,   113,    -1,    10,    -1,    11,   113,    -1,
     485,    -1,   484,   485,    -1,    -1,   486,   120,   487,   488,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   121,
      -1,    -1,   111,   490,   494,    -1,    -1,   490,   491,    -1,
     492,    -1,   493,    -1,   117,     3,     7,     3,    -1,   119,
       3,     7,     3,    -1,   495,    -1,    11,   496,   114,    -1,
      10,    -1,    11,   114,    -1,   497,    -1,   496,   497,    -1,
      -1,   498,   122,   499,   500,    -1,    18,     3,     7,     3,
      -1,    10,    -1,    11,   123,    -1,    -1,   112,   502,   505,
      -1,    -1,   502,   503,    -1,   504,    -1,   517,    -1,   118,
       3,     7,     3,    -1,   506,    -1,    11,   507,   115,    -1,
      10,    -1,    11,   115,    -1,   508,    -1,   507,   508,    -1,
      -1,   509,   124,   510,   511,    -1,    18,     3,     7,     3,
      -1,    10,    -1,    11,   125,    -1,    -1,   513,   126,   515,
     514,    -1,    10,    -1,    11,   127,    -1,    -1,   515,   516,
      -1,   518,    -1,   519,    -1,   119,     3,     7,     3,    -1,
     108,     3,   546,     3,    -1,   109,     3,   546,     3,    -1,
     152,   547,     7,   547,    -1,    31,     3,     7,     3,    -1,
      34,     3,     7,     3,    -1,   179,     3,     7,     3,    -1,
     178,     3,     7,     3,    -1,    70,     3,     7,     3,    -1,
      75,     3,     7,     3,    -1,    80,     3,     7,     3,    -1,
      83,     3,     7,     3,    -1,    88,     3,     7,     3,    -1,
      21,     4,     3,    -1,    99,     4,     3,    -1,    59,     3,
     546,     3,    -1,    60,     3,     7,     3,    -1,    61,     3,
       7,     3,    -1,    62,     3,     7,     3,    -1,    63,     3,
       7,     3,    -1,    65,     4,     3,    -1,    91,     3,     7,
       3,    -1,    92,     3,     7,     3,    -1,    98,     3,     7,
       3,    -1,    93,     3,     7,     3,    -1,    94,     3,     7,
       3,    -1,    95,     3,     7,     3,    -1,    97,     3,     7,
       3,    -1,    96,     3,     7,     3,    -1,   548,     7,   548,
      -1,   548,     8,   548,    -1,   548,     3,    -1,    -1,   548,
     549,    -1,   315,    -1,   316,    -1,   317,    -1,   318,    -1,
     551,    -1,   558,    -1,    -1,   551,   552,    -1,   553,   554,
     557,    -1,   162,    -1,   555,    -1,    -1,   555,   556,    -1,
     788,    -1,   787,    -1,    11,     7,   163,    -1,   157,   786,
     559,    -1,   560,    -1,   561,    -1,    11,   158,    -1,    10,
      -1,    11,     5,   158,    -1,    -1,   562,   563,    -1,   564,
     565,   566,    -1,   162,    -1,    -1,   788,    -1,    11,   546,
     163,    -1,   568,   569,   570,    -1,   783,    -1,   199,   551,
     200,    -1,   201,   562,   202,    -1,   572,   573,   574,    -1,
     783,    -1,   199,   551,   200,    -1,   201,   551,   202,    -1,
     576,   577,   583,    -1,   164,    -1,   578,    -1,    -1,   578,
     579,    -1,   580,    -1,   784,    -1,   782,    -1,   581,    -1,
     582,    -1,   173,     4,     3,    -1,    21,     4,     3,    -1,
      22,     4,     3,    -1,   584,    -1,   585,    -1,    10,    -1,
      11,   586,   165,    -1,   587,   605,    -1,    -1,   588,   589,
     604,    -1,   167,    -1,   590,    -1,    -1,   590,   591,    -1,
     592,    -1,   593,    -1,   594,    -1,   595,    -1,   596,    -1,
     597,    -1,   598,    -1,   599,    -1,   603,    -1,   181,     3,
       7,     3,    -1,   182,     3,     7,     3,    -1,   183,     3,
       7,     3,    -1,   184,     3,     7,     3,    -1,   185,     3,
       7,     3,    -1,   186,     3,     7,     3,    -1,   187,     3,
       7,     3,    -1,   600,    -1,   601,    -1,   602,    -1,   189,
      -1,   190,     4,   547,    -1,   188,     3,   546,     3,    -1,
      11,   166,    -1,    10,    -1,    -1,   605,   606,    -1,   607,
      -1,   748,    -1,   751,    -1,   608,   609,   613,    -1,   191,
      -1,    -1,   610,    -1,   611,    -1,   612,    -1,   223,    -1,
     224,     4,   547,    -1,   614,   615,    -1,    10,    -1,   617,
     628,   639,   679,   710,   721,   732,   616,    -1,    11,   192,
      -1,    -1,   618,   619,    -1,   193,    -1,   620,   626,    -1,
     621,   622,    -1,   195,    -1,   623,    -1,   624,    -1,    10,
      -1,    11,   625,   196,    -1,   550,    -1,   627,   567,   198,
      -1,   197,    -1,    -1,   629,   630,   204,    -1,   203,    -1,
     631,   637,    -1,   632,   633,    -1,   195,    -1,   634,    -1,
     635,    -1,    10,    -1,    11,   636,   196,    -1,   550,    -1,
     638,   571,   198,    -1,   197,    -1,    -1,   640,   641,    -1,
     205,    -1,   642,   648,    -1,   643,   644,    -1,   195,    -1,
     645,    -1,   646,    -1,    10,    -1,    11,   647,   196,    -1,
     550,    -1,   649,   650,   651,    -1,   197,    -1,   783,    -1,
      11,   652,   198,    -1,   653,   659,    -1,    -1,   654,   655,
      -1,   199,    -1,   656,    -1,   657,    -1,    10,    -1,    11,
     658,   200,    -1,   550,    -1,    -1,   660,   661,    -1,   201,
      -1,   662,    -1,   663,    -1,    10,    -1,    11,   664,   202,
      -1,    -1,   664,   665,    -1,   666,   667,   671,    -1,   162,
      -1,   668,    -1,    -1,   668,   669,    -1,   785,    -1,   670,
      -1,   176,     3,   546,     3,    -1,   672,    -1,   673,    -1,
      10,    -1,    11,   674,   163,    -1,    -1,   674,   675,    -1,
     676,   677,   678,    -1,   215,    -1,    -1,   314,     3,   546,
       3,    -1,    11,     7,   216,    -1,    -1,   680,   681,    -1,
     207,    -1,   682,   688,    -1,   683,   684,    -1,   195,    -1,
     685,    -1,   686,    -1,    10,    -1,    11,   687,   196,    -1,
     550,    -1,   689,   690,   691,    -1,   197,    -1,   783,    -1,
      11,   692,   198,    -1,   693,   699,    -1,    -1,   694,   695,
      -1,   199,    -1,   696,    -1,   697,    -1,    10,    -1,    11,
     698,   200,    -1,   550,    -1,    -1,   700,   701,    -1,   201,
      -1,   702,    -1,   703,    -1,    10,    -1,    11,   704,   202,
      -1,    -1,   704,   705,    -1,   706,   707,    -1,   162,    -1,
     708,    -1,   709,    -1,    10,    -1,    11,   795,   163,    -1,
      -1,   711,   712,   210,    -1,   209,    -1,   713,   719,    -1,
     714,   715,    -1,   195,    -1,   716,    -1,   717,    -1,    10,
      -1,    11,   718,   196,    -1,   550,    -1,   720,   571,   198,
      -1,   197,    -1,    -1,   722,   723,   212,    -1,   211,    -1,
     724,   730,    -1,   725,   726,    -1,   195,    -1,   727,    -1,
     728,    -1,    10,    -1,    11,   729,   196,    -1,   550,    -1,
     731,   571,   198,    -1,   197,    -1,    -1,   733,   734,   738,
     214,    -1,   213,    -1,    -1,   735,    -1,   736,    -1,   737,
      -1,   174,    -1,   175,     4,   547,    -1,   739,   746,    -1,
     740,   741,   742,    -1,   195,    -1,   783,    -1,   743,    -1,
     744,    -1,    10,    -1,    11,   745,   196,    -1,   550,    -1,
     747,   571,   198,    -1,   197,    -1,   749,   868,   750,    -1,
     217,    -1,   218,    -1,   752,   753,   754,    -1,   170,    -1,
     781,    -1,   755,   762,   769,    -1,   756,   757,   758,    -1,
     219,    -1,   783,    -1,   759,    -1,   760,    -1,    10,    -1,
      11,   761,   220,    -1,   550,    -1,   763,   764,   765,    -1,
     221,    -1,   783,    -1,   766,    -1,   767,    -1,    10,    -1,
      11,   768,   222,    -1,   550,    -1,    -1,   769,   770,    -1,
     771,   772,   777,    -1,   168,    -1,   773,    -1,    -1,   773,
     774,    -1,   775,    -1,   776,    -1,   580,    -1,   225,   547,
       7,   547,    -1,   226,   547,     7,   547,    -1,   778,    -1,
     779,    -1,    11,   169,    -1,    10,    -1,    11,   780,   169,
      -1,   587,   605,    -1,   177,   547,     7,   547,    -1,   178,
       3,     7,     3,    -1,   152,     3,     7,     3,    -1,   179,
       3,     7,     3,    -1,   180,   547,     7,   547,    -1,   161,
       3,     7,     3,    -1,   159,     3,     7,     3,    -1,   160,
       3,     7,     3,    -1,    -1,   228,   790,   791,   229,    -1,
     230,     3,     7,     3,    11,    -1,    -1,    -1,   791,   793,
     794,    11,   795,   792,   232,    -1,   231,    -1,    18,     3,
       7,     3,    -1,   847,    -1,   857,    -1,   796,    -1,   798,
      -1,   808,    -1,   800,    -1,   802,    -1,   804,    -1,   806,
      -1,   820,    -1,   823,    -1,   825,    -1,   827,    -1,   831,
      -1,   829,    -1,   833,    -1,   839,    -1,   835,    -1,   837,
      -1,   814,    -1,   817,    -1,   841,    -1,   844,    -1,   811,
      -1,   865,    -1,    -1,   277,   797,   795,   795,   278,    -1,
      -1,   235,   799,   795,   795,   236,    -1,    -1,   237,   801,
     795,   795,   238,    -1,    -1,   251,   803,   795,   252,    -1,
      -1,   239,   805,   795,   795,   240,    -1,    -1,   233,   807,
     795,   795,   234,    -1,    -1,   245,   809,   810,   246,    -1,
      -1,   810,   795,    -1,    -1,   269,   812,   813,   270,    -1,
      -1,   813,   795,    -1,    -1,   267,   815,   816,   268,    -1,
      -1,   816,   795,    -1,    -1,   271,   818,   819,   272,    -1,
      -1,   819,   795,    -1,    -1,   247,   821,   822,   248,    -1,
      -1,   822,   795,    -1,    -1,   241,   824,   795,   242,    -1,
      -1,   243,   826,   795,   244,    -1,    -1,   255,   828,   795,
     256,    -1,    -1,   257,   830,   795,   258,    -1,    -1,   259,
     832,   795,   260,    -1,    -1,   249,   834,   795,   250,    -1,
      -1,   263,   836,   795,   264,    -1,    -1,   265,   838,   795,
     266,    -1,    -1,   253,   840,   795,   795,   795,   254,    -1,
      -1,   273,   842,   843,    -1,    10,    -1,    11,   274,    -1,
      -1,   275,   845,   846,    -1,    10,    -1,    11,   276,    -1,
      -1,   279,   848,   850,   849,    -1,    10,    -1,    11,   280,
      -1,    -1,   850,   851,    -1,   852,    -1,   856,    -1,   854,
      -1,    -1,    22,     4,   853,     3,    -1,    -1,   313,     4,
     855,     3,    -1,    23,     3,   546,     3,    -1,    -1,   261,
     858,   861,   859,    -1,    10,    -1,    -1,    11,   795,   860,
     262,    -1,    11,   262,    -1,    -1,   861,   862,    -1,   863,
      -1,   864,    -1,   314,     3,   546,     3,    -1,    18,     3,
       7,     3,    -1,    -1,   281,   866,   868,   282,    -1,    -1,
     283,   867,   868,   284,    -1,   869,    -1,   872,    -1,   875,
      -1,   878,    -1,   881,    -1,   884,    -1,   888,    -1,   893,
      -1,   896,    -1,   899,    -1,   902,    -1,   905,    -1,   908,
      -1,   911,    -1,    -1,   164,   870,   538,   871,    -1,    10,
      -1,    11,   165,    -1,    18,     3,     7,     3,    -1,   873,
     874,    -1,   285,    -1,   868,   286,    -1,   876,   877,    -1,
     287,    -1,   868,   868,   288,    -1,   879,   880,    -1,   289,
      -1,   795,   290,    -1,   882,   883,    -1,   291,    -1,   868,
     292,    -1,   885,   886,   887,    -1,   293,    -1,    -1,   892,
      -1,   868,   294,    -1,   889,   890,   891,    -1,   295,    -1,
      -1,   892,    -1,   868,   296,    -1,   312,     4,     3,    -1,
     894,   895,    -1,   297,    -1,    10,    -1,    11,   298,    -1,
     897,   898,    -1,   299,    -1,   868,   868,   300,    -1,   900,
     901,    -1,   301,    -1,   868,   868,   302,    -1,   903,   904,
      -1,   303,    -1,   868,   868,   304,    -1,   906,   907,    -1,
     305,    -1,   795,   868,   306,    -1,   909,   910,    -1,   307,
      -1,   868,   795,   795,   795,   795,   308,    -1,   912,   913,
      -1,   309,    -1,   795,   795,   310,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   385,   386,   388,   397,   398,   401,   402,
     407,   414,   414,   416,   429,   435,   436,   439,   440,   443,
     446,   449,   452,   458,   465,   472,   480,   485,   485,   487,
     494,   496,   496,   498,   500,   502,   502,   505,   505,   507,
     509,   511,   511,   513,   515,   517,   517,   519,   520,   522,
     523,   525,   532,   533,   538,   540,   542,   544,   544,   547,
     548,   549,   551,   551,   553,   555,   557,   559,   559,   562,
     563,   564,   566,   566,   570,   572,   574,   576,   576,   579,
     580,   581,   582,   583,   584,   587,   587,   589,   591,   593,
     595,   595,   598,   599,   600,   601,   602,   603,   604,   607,
     607,   611,   613,   615,   617,   617,   620,   621,   622,   623,
     626,   626,   640,   642,   644,   646,   646,   649,   650,   651,
     654,   656,   658,   660,   662,   664,   666,   666,   668,   668,
     670,   672,   674,   676,   676,   679,   680,   681,   684,   686,
     688,   690,   692,   694,   696,   696,   698,   698,   707,   707,
     709,   711,   713,   713,   715,   718,   720,   720,   722,   724,
     726,   728,   729,   731,   731,   733,   735,   737,   739,   739,
     742,   743,   744,   745,   746,   747,   748,   751,   752,   754,
     754,   756,   758,   760,   762,   763,   765,   765,   767,   769,
     771,   773,   773,   776,   777,   778,   779,   780,   781,   782,
     785,   787,   788,   790,   790,   792,   794,   796,   798,   798,
     800,   802,   804,   806,   807,   809,   809,   811,   813,   815,
     817,   817,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   831,   833,   834,   836,   836,   838,   840,   842,   844,
     845,   847,   849,   851,   853,   853,   855,   857,   859,   859,
     861,   864,   864,   866,   868,   868,   870,   871,   874,   875,
     878,   929,   931,   945,   946,   948,   948,   972,   973,   976,
     977,   979,   981,   982,   986,   987,   989,   990,   992,  1008,
    1016,  1023,  1028,  1029,  1031,  1032,  1034,  1034,  1037,  1046,
    1047,  1049,  1050,  1054,  1055,  1057,  1058,  1060,  1076,  1084,
    1091,  1096,  1097,  1099,  1100,  1102,  1102,  1105,  1114,  1115,
    1117,  1127,  1131,  1132,  1134,  1135,  1137,  1153,  1160,  1165,
    1166,  1168,  1169,  1171,  1171,  1174,  1183,  1184,  1189,  1189,
    1197,  1198,  1200,  1201,  1203,  1207,  1213,  1221,  1225,  1230,
    1239,  1250,  1261,  1272,  1283,  1291,  1299,  1307,  1315,  1324,
    1333,  1341,  1352,  1363,  1375,  1386,  1397,  1408,  1419,  1430,
    1441,  1452,  1463,  1474,  1485,  1499,  1500,  1507,  1509,  1509,
    1511,  1512,  1513,  1514,  1679,  1687,  1689,  1689,  1691,  1693,
    1702,  1704,  1704,  1706,  1706,  1708,  1724,  1727,  1727,  1729,
    1729,  1732,  1773,  1773,  1775,  1777,  1785,  1785,  1787,  1840,
    1844,  1855,  1857,  1865,  1869,  1880,  1882,  1888,  1890,  1895,
    1897,  1897,  1900,  1901,  1902,  1903,  1904,  1913,  1922,  1931,
    1940,  1940,  1942,  1944,  1946,  1948,  1948,  1950,  1952,  1954,
    1954,  1957,  1958,  1959,  1960,  1961,  1962,  1963,  1964,  1965,
    1967,  1977,  1987,  1997,  2007,  2017,  2027,  2037,  2044,  2044,
    2046,  2051,  2060,  2068,  2068,  2070,  2070,  2072,  2072,  2072,
    2074,  2076,  2078,  2078,  2080,  2080,  2082,  2087,  2096,  2098,
    2100,  2103,  2105,  2105,  2107,  2109,  2111,  2122,  2128,  2128,
    2130,  2132,  2134,  2136,  2149,  2156,  2156,  2158,  2160,  2162,
    2173,  2179,  2179,  2181,  2183,  2185,  2187,  2200,  2206,  2206,
    2208,  2210,  2212,  2223,  2229,  2229,  2231,  2233,  2235,  2237,
    2248,  2254,  2263,  2265,  2267,  2268,  2281,  2288,  2288,  2290,
    2292,  2294,  2296,  2297,  2299,  2305,  2305,  2307,  2309,  2311,
    2311,  2313,  2316,  2322,  2324,  2324,  2327,  2328,  2330,  2334,
    2334,  2336,  2338,  2340,  2340,  2343,  2345,  2351,  2351,  2355,
    2359,  2359,  2361,  2363,  2365,  2376,  2382,  2382,  2384,  2386,
    2388,  2390,  2401,  2407,  2416,  2418,  2420,  2421,  2434,  2441,
    2441,  2443,  2445,  2447,  2449,  2450,  2452,  2458,  2458,  2460,
    2462,  2464,  2464,  2466,  2468,  2474,  2474,  2476,  2478,  2481,
    2481,  2483,  2485,  2487,  2498,  2504,  2504,  2506,  2508,  2510,
    2512,  2525,  2531,  2531,  2533,  2535,  2537,  2548,  2554,  2554,
    2556,  2558,  2560,  2562,  2575,  2581,  2581,  2583,  2585,  2585,
    2587,  2587,  2589,  2594,  2603,  2605,  2616,  2622,  2629,  2629,
    2631,  2633,  2635,  2637,  2650,  2656,  2658,  2660,  2662,  2664,
    2666,  2668,  2670,  2681,  2687,  2694,  2694,  2696,  2698,  2700,
    2702,  2713,  2719,  2726,  2726,  2728,  2730,  2732,  2734,  2734,
    2736,  2738,  2740,  2742,  2742,  2745,  2746,  2747,  2754,  2763,
    2772,  2772,  2774,  2774,  2776,  2778,  2780,  2789,  2798,  2807,
    2816,  2825,  2830,  2838,  2879,  2880,  2884,  2893,  2895,  2894,
    2902,  2907,  2921,  2922,  2923,  2924,  2925,  2926,  2927,  2928,
    2929,  2930,  2931,  2932,  2933,  2934,  2935,  2936,  2937,  2938,
    2939,  2940,  2941,  2942,  2943,  2944,  2946,  2950,  2950,  2955,
    2955,  2960,  2960,  2965,  2965,  2970,  2970,  2975,  2975,  2980,
    2980,  2990,  2991,  2996,  2996,  3008,  3009,  3012,  3012,  3023,
    3024,  3026,  3026,  3037,  3038,  3041,  3041,  3051,  3052,  3055,
    3055,  3060,  3060,  3065,  3065,  3070,  3070,  3075,  3075,  3080,
    3080,  3085,  3085,  3092,  3092,  3098,  3098,  3105,  3105,  3108,
    3109,  3111,  3111,  3114,  3115,  3117,  3117,  3122,  3123,  3125,
    3126,  3128,  3130,  3132,  3136,  3136,  3140,  3140,  3145,  3155,
    3155,  3160,  3161,  3161,  3165,  3167,  3168,  3170,  3172,  3176,
    3185,  3192,  3192,  3197,  3197,  3202,  3203,  3204,  3205,  3206,
    3207,  3208,  3209,  3210,  3211,  3212,  3213,  3214,  3215,  3218,
    3217,  3223,  3224,  3226,  3234,  3236,  3242,  3244,  3246,  3252,
    3254,  3256,  3262,  3264,  3266,  3272,  3274,  3276,  3282,  3282,
    3284,  3286,  3288,  3294,  3294,  3296,  3298,  3305,  3307,  3312,
    3312,  3314,  3316,  3322,  3324,  3326,  3332,  3334,  3336,  3342,
    3344,  3346,  3352,  3354,  3356,  3362,  3364,  3366,  3372
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
  "EMPTYIDATT", "EMPTYNAMEATT", "EMPTYTYPEATT", "IDXATT", "IDXONEATT",
  "IDXTWOATT", "NAMEATT", "TYPEATT", "VALUEATT",
  "QUADRATICCOEFFICIENTSSTART", "QUADRATICCOEFFICIENTSEND",
  "NUMBEROFQTERMSATT", "QTERMSTART", "QTERMEND", "MATRICESSTART",
  "MATRICESEND", "NUMBEROFMATRICESATT", "CONESSTART", "CONESEND",
  "NUMBEROFCONESATT", "NONNEGATIVECONESTART", "NONNEGATIVECONEEND",
  "NONPOSITIVECONESTART", "NONPOSITIVECONEEND", "ORTHANTCONESTART",
  "ORTHANTCONEEND", "QUADRATICCONESTART", "QUADRATICCONEEND",
  "ROTATEDQUADRATICCONESTART", "ROTATEDQUADRATICCONEEND",
  "SEMIDEFINITECONESTART", "SEMIDEFINITECONEEND", "PRODUCTCONESTART",
  "PRODUCTCONEEND", "INTERSECTIONCONESTART", "INTERSECTIONCONEEND",
  "DUALCONESTART", "DUALCONEEND", "POLARCONESTART", "POLARCONEEND",
  "FACTORSSTART", "FACTORSEND", "COMPONENTSSTART", "COMPONENTSEND",
  "NORMSCALEFACTORATT", "DISTORTIONMATRIXIDXATT", "AXISDIRECTIONATT",
  "FIRSTAXISDIRECTIONATT", "SECONDAXISDIRECTIONATT",
  "EMPTYSEMIDEFINITENESSATT", "SEMIDEFINITENESSATT",
  "MATRIXPROGRAMMINGSTART", "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART",
  "MATRIXVARIABLESEND", "NUMBEROFMATRIXVARATT", "MATRIXVARSTART",
  "MATRIXVAREND", "MATRIXOBJECTIVESSTART", "MATRIXOBJECTIVESEND",
  "NUMBEROFMATRIXOBJATT", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "NUMBEROFMATRIXCONATT",
  "MATRIXCONSTART", "MATRIXCONEND", "NUMBEROFMATRIXTERMSATT",
  "MATRIXTERMSTART", "MATRIXTERMEND", "MATRIXEXPRESSIONSSTART",
  "MATRIXEXPRESSIONSEND", "NUMBEROFMATRIXEXPRATT", "MATRIXEXPRSTART",
  "MATRIXEXPREND", "MATRIXIDXATT", "LBMATRIXIDXATT", "LBCONEIDXATT",
  "UBMATRIXIDXATT", "UBCONEIDXATT", "PATTERNMATRIXIDXATT",
  "ORDERCONEIDXATT", "CONSTANTMATRIXIDXATT", "SHAPEATT", "EMPTYSHAPEATT",
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
  "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT",
  "SYMMETRYATT", "EMPTYEXCLUDEATT", "EXCLUDEATT", "CONSTANTATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "NUMBEROFVARIDXATT", "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT",
  "TARGETMATRIXFIRSTCOLATT", "BASEMATRIXSTARTROWATT",
  "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT", "BASEMATRIXENDCOLATT",
  "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "ELEMENTSSTART", "ELEMENTSEND", "CONSTANTELEMENTSSTART",
  "CONSTANTELEMENTSEND", "STARTVECTORSTART", "STARTVECTOREND",
  "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART", "INDEXESEND",
  "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND", "POWERSTART",
  "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND",
  "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND",
  "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "MATRIXTRACESTART", "MATRIXTRACEEND", "MATRIXTOSCALARSTART",
  "MATRIXTOSCALAREND", "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND",
  "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND", "MATRIXIDENTITYSTART",
  "MATRIXIDENTITYEND", "MATRIXINVERSESTART", "MATRIXINVERSEEND",
  "MATRIXLOWERTRIANGLESTART", "MATRIXLOWERTRIANGLEEND",
  "MATRIXUPPERTRIANGLESTART", "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART",
  "MATRIXMERGEEND", "MATRIXMINUSSTART", "MATRIXMINUSEND",
  "MATRIXPLUSSTART", "MATRIXPLUSEND", "MATRIXTIMESSTART", "MATRIXTIMESEND",
  "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osildoc", "theInstanceEnd", "osilEnd", "osilEnding",
  "quadraticCoefficients", "osilQuadnumberATT", "qTermlist", "qterm",
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
  "quadraticCone", "quadraticConeStart", "quadraticConeAttributes",
  "quadraticConeAttList", "quadraticConeAtt", "quadraticConeEnd",
  "rotatedQuadraticCone", "rotatedQuadraticConeStart",
  "rotatedQuadraticConeAttributes", "rotatedQuadraticConeAttList",
  "rotatedQuadraticConeAtt", "rotatedQuadraticConeEnd", "semidefiniteCone",
  "semidefiniteConeStart", "semidefiniteConeAttributes",
  "semidefiniteConeAttList", "semidefiniteConeAtt", "semidefiniteConeEnd",
  "productCone", "productConeStart", "productConeAttributes",
  "productConeAttList", "productConeAtt", "productConeContent",
  "productConeFactors", "productConeFactorsStart",
  "productConeFactorsAttributes", "productConeFactorsContent",
  "productConeFactorList", "productConeFactorsEnd", "productConeEnd",
  "intersectionCone", "intersectionConeStart",
  "intersectionConeAttributes", "intersectionConeAttList",
  "intersectionConeAtt", "intersectionConeContent",
  "intersectionConeComponents", "intersectionConeComponentsStart",
  "intersectionConeComponentsAttributes",
  "intersectionConeComponentsContent", "intersectionConeComponentList",
  "intersectionConeComponentsEnd", "intersectionConeEnd",
  "matrixProgramming", "matrixProgrammingStart",
  "matrixProgrammingAttributes", "matrixProgrammingContent",
  "matrixProgrammingEmpty", "matrixProgrammingLaden", "matrixVariables",
  "matrixVariablesStart", "matrixVariablesAttributes",
  "matrixVariablesContent", "matrixVariablesEnd", "matrixVarList",
  "matrixVar", "matrixVarStart", "matrixVarAttributes", "matrixVarAttList",
  "matrixVarAtt", "matrixVarEnd", "matrixObjectives",
  "matrixObjectivesStart", "matrixObjectivesAttributes",
  "matrixObjectivesContent", "matrixObjectivesEnd", "matrixObjList",
  "matrixObj", "matrixObjStart", "matrixObjAttributes", "matrixObjAttList",
  "matrixObjAtt", "matrixObjTerms", "matrixObjEnd", "matrixTermList",
  "matrixTerm", "matrixTermStart", "matrixTermEnd", "matrixConstraints",
  "matrixConstraintsStart", "matrixConstraintsAttributes",
  "matrixConstraintsContent", "matrixConstraintsEnd", "matrixConList",
  "matrixCon", "matrixConStart", "matrixConAttributes", "matrixConAttList",
  "matrixConAtt", "matrixConTerms", "matrixConEnd", "matrixExpressions",
  "matrixExpressionsStart", "matrixExpressionsAtt",
  "matrixExpressionsContent", "matrixExpressionsEmpty",
  "matrixExpressionsLaden", "matrixExprList", "matrixExpr", "timeDomain",
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
  "osilIntervalstartATT", "osilNumberOfElATT", "osilNumberOfMatricesATT",
  "osilNumberOfConesATT", "osilNumberOfRowsATT", "osilNumberOfColumnsATT",
  "numberOfMatrixVarATT", "numberOfMatrixObjATT", "numberOfMatrixConATT",
  "numberOfMatrixTermsATT", "numberOfMatrixExprATT", "osilNameATT",
  "osilShapeATT", "osilNormScaleFactorATT", "osilDistortionMatrixIdxATT",
  "osilAxisDirectionATT", "osilFirstAxisDirectionATT",
  "osilSecondAxisDirectionATT", "osilSemidefinitenessATT", "matrixIdxATT",
  "lbMatrixIdxATT", "constantMatrixIdxATT", "lbConeIdxATT",
  "ubMatrixIdxATT", "ubConeIdxATT", "orderConeIdxATT",
  "patternMatrixIdxATT", "aNumber", "quote", "xmlWhiteSpace",
  "xmlWhiteSpaceChar", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "osglIntVectorBase64Content",
  "osglIntVectorBase64Empty", "osglIntVectorBase64Laden",
  "osglDblVectorElArray", "osglDblVectorEl", "osglDblVectorElStart",
  "osglDblVectorElAttributes", "osglDblVectorElContent",
  "osglSparseVector", "osglSparseVectorNumberOfElATT",
  "osglSparseVectorIndexes", "osglSparseVectorValues",
  "osglSparseIntVector", "osglSparseIntVectorNumberOfElATT",
  "osglSparseIntVectorIndexes", "osglSparseIntVectorValues", "osglMatrix",
  "matrixStart", "matrixAttributes", "matrixAttributeList",
  "matrixAttribute", "osglSymmetryATT", "osglMatrixNameATT",
  "osglMatrixTypeATT", "matrixContent", "matrixEmpty", "matrixLaden",
  "matrixBody", "baseMatrix", "baseMatrixStart", "baseMatrixAttributes",
  "baseMatrixAttList", "baseMatrixAtt", "osglBaseMatrixIdxATT",
  "osglTargetMatrixFirstRowATT", "osglTargetMatrixFirstColATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "baseTransposeAttribute", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent",
  "osglScalarMultiplierATT", "baseMatrixEnd", "matrixConstructorList",
  "matrixConstructor", "matrixElements", "matrixElementsStart",
  "matrixElementsAttributes", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "matrixElementsContent", "matrixElementsEmpty",
  "matrixElementsLaden", "matrixElementsEnd", "constantElements",
  "constantElementsStart", "constantElementsContent",
  "constantElementsStartVector", "constantElementsStartVectorStart",
  "constantElementsStartVectorContent", "constantElementsStartVectorEmpty",
  "constantElementsStartVectorLaden", "constantElementsStartVectorBody",
  "constantElementsNonzeros", "constantElementsNonzerosStart",
  "varReferenceElements", "varReferenceElementsStart",
  "varReferenceElementsContent", "varReferenceElementsStartVector",
  "varReferenceElementsStartVectorStart",
  "varReferenceElementsStartVectorContent",
  "varReferenceElementsStartVectorEmpty",
  "varReferenceElementsStartVectorLaden",
  "varReferenceElementsStartVectorBody", "varReferenceElementsNonzeros",
  "varReferenceElementsNonzerosStart", "linearElements",
  "linearElementsStart", "linearElementsContent",
  "linearElementsStartVector", "linearElementsStartVectorStart",
  "linearElementsStartVectorContent", "linearElementsStartVectorEmpty",
  "linearElementsStartVectorLaden", "linearElementsStartVectorBody",
  "linearElementsNonzeros", "linearElementsNonzerosStart",
  "linearElementsNonzerosNumberOfElAttribute",
  "linearElementsNonzerosContent", "linearElementsNonzerosBody",
  "linearElementsNonzerosIndexes", "linearElementsNonzerosIndexesStart",
  "linearElementsNonzerosIndexesContent",
  "linearElementsNonzerosIndexesEmpty",
  "linearElementsNonzerosIndexesLaden",
  "linearElementsNonzerosIndexesBody", "linearElementsNonzerosValues",
  "linearElementsNonzerosValuesStart",
  "linearElementsNonzerosValuesContent",
  "linearElementsNonzerosValuesEmpty", "linearElementsNonzerosValuesLaden",
  "linearElementsNonzerosElList", "linearElementsNonzerosEl",
  "linearElementsNonzerosElStart", "linearElementsNonzerosElAttributes",
  "linearElementsNonzerosElAttList", "linearElementsNonzerosElAtt",
  "osglConstantATT", "linearElementsNonzerosElContent",
  "linearElementsNonzerosElEmpty", "linearElementsNonzerosElLaden",
  "linearElementsNonzerosVarIdxList", "linearElementsNonzerosVarIdx",
  "linearElementsNonzerosVarIdxStart",
  "osglLinearElementsNonzerosVarIdxCoefATT",
  "linearElementsNonzerosVarIdxContent", "generalElements",
  "generalElementsStart", "generalElementsContent",
  "generalElementsStartVector", "generalElementsStartVectorStart",
  "generalElementsStartVectorContent", "generalElementsStartVectorEmpty",
  "generalElementsStartVectorLaden", "generalElementsStartVectorBody",
  "generalElementsNonzeros", "generalElementsNonzerosStart",
  "generalElementsNonzerosNumberOfElAttribute",
  "generalElementsNonzerosContent", "generalElementsNonzerosBody",
  "generalElementsNonzerosIndexes", "generalElementsNonzerosIndexesStart",
  "generalElementsNonzerosIndexesContent",
  "generalElementsNonzerosIndexesEmpty",
  "generalElementsNonzerosIndexesLaden",
  "generalElementsNonzerosIndexesBody", "generalElementsNonzerosValues",
  "generalElementsNonzerosValuesStart",
  "generalElementsNonzerosValuesContent",
  "generalElementsNonzerosValuesEmpty",
  "generalElementsNonzerosValuesLaden", "generalElementsNonzerosElList",
  "generalElementsNonzerosEl", "generalElementsNonzerosElStart",
  "generalElementsNonzerosElContent", "generalElementsNonzerosElEmpty",
  "generalElementsNonzerosElLaden", "conReferenceElements",
  "conReferenceElementsStart", "conReferenceElementsContent",
  "conReferenceElementsStartVector",
  "conReferenceElementsStartVectorStart",
  "conReferenceElementsStartVectorContent",
  "conReferenceElementsStartVectorEmpty",
  "conReferenceElementsStartVectorLaden",
  "conReferenceElementsStartVectorBody", "conReferenceElementsNonzeros",
  "conReferenceElementsNonzerosStart", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsContent",
  "objReferenceElementsStartVector",
  "objReferenceElementsStartVectorStart",
  "objReferenceElementsStartVectorContent",
  "objReferenceElementsStartVectorEmpty",
  "objReferenceElementsStartVectorLaden",
  "objReferenceElementsStartVectorBody", "objReferenceElementsNonzeros",
  "objReferenceElementsNonzerosStart", "patternElements",
  "patternElementsStart", "patternElementsAttributes",
  "osglExcludeIfSetATT", "excludeIfSetAttEmpty", "excludeIfSetAttContent",
  "patternElementsContent", "patternElementsStartVector",
  "patternElementsStartVectorStart",
  "patternElementsStartVectorNumberOfElATT",
  "patternElementsStartVectorContent", "patternElementsStartVectorEmpty",
  "patternElementsStartVectorLaden", "patternElementsStartVectorBody",
  "patternElementsNonzeros", "patternElementsNonzerosStart",
  "matrixTransformation", "matrixTransformationStart",
  "matrixTransformationEnd", "matrixBlocks", "matrixBlocksStart",
  "matrixBlocksAttributes", "matrixBlocksContent", "colOffsets",
  "colOffsetsStart", "colOffsetsNumberOfElAttribute", "colOffsetsContent",
  "colOffsetsEmpty", "colOffsetsLaden", "colOffsetsBody", "rowOffsets",
  "rowOffsetsStart", "rowOffsetsNumberOfElAttribute", "rowOffsetsContent",
  "rowOffsetsEmpty", "rowOffsetsLaden", "rowOffsetsBody", "blockList",
  "matrixBlock", "matrixBlockStart", "matrixBlockAttributes",
  "matrixBlockAttList", "matrixBlockAtt", "osglBlockRowIdxATT",
  "osglBlockColIdxATT", "matrixBlockContent", "blockEmpty", "blockLaden",
  "blockBody", "osglNumberOfBlocksATT", "osglNumberOfColumnsATT",
  "osglNumberOfElATT", "osglNumberOfRowsATT", "osglNumberOfVarIdxATT",
  "osglBase64SizeATT", "osglIncrATT", "osglMultATT",
  "nonlinearExpressions", "nlnumberatt", "nlnodes", "$@6", "nlstart",
  "nlIdxATT", "nlnode", "times", "$@7", "plus", "$@8", "minus", "$@9",
  "negate", "$@10", "divide", "$@11", "power", "$@12", "sum", "$@13",
  "anothersumnlnode", "allDiff", "$@14", "anotherallDiffnlnode", "max",
  "$@15", "anothermaxnlnode", "min", "$@16", "anotherminnlnode", "product",
  "$@17", "anotherproductnlnode", "ln", "$@18", "sqrt", "$@19", "square",
  "$@20", "cos", "$@21", "sin", "$@22", "exp", "$@23", "abs", "$@24",
  "erf", "$@25", "if", "$@26", "E", "$@27", "eend", "PI", "$@28", "piend",
  "number", "$@29", "numberend", "anotherNumberATT", "numberATT",
  "numbertypeATT", "$@30", "numberidATT", "$@31", "numbervalueATT",
  "variable", "$@32", "variableend", "$@33", "anotherVariableATT",
  "variableATT", "variablecoefATT", "variableidxATT", "matrixTrace",
  "$@34", "$@35", "OSnLMNode", "matrixReference", "$@36",
  "matrixreferenceend", "matrixDiagonal", "matrixDiagonalStart",
  "matrixDiagonalContent", "matrixDotTimes", "matrixDotTimesStart",
  "matrixDotTimesContent", "matrixIdentity", "matrixIdentityStart",
  "matrixIdentityContent", "matrixInverse", "matrixInverseStart",
  "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixScalarTimes", "matrixScalarTimesStart",
  "matrixScalarTimesContent", "matrixSubMatrixAt",
  "matrixSubMatrixAtStart", "matrixSubMatrixAtContent", "matrixTranspose",
  "matrixTransposeStart", "matrixTransposeContent", 0
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
     565,   566,   567,   568,   569,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   319,   320,   321,   321,   322,   323,   323,   324,   324,
     325,   326,   326,   327,   328,   329,   329,   330,   330,   331,
     331,   331,   331,   332,   333,   334,   335,   336,   336,   337,
     338,   339,   339,   340,   341,   342,   342,   343,   343,   344,
     345,   346,   346,   347,   348,   349,   349,   350,   350,   350,
     350,   350,   350,   350,   351,   352,   353,   354,   354,   355,
     355,   355,   356,   356,   357,   358,   359,   360,   360,   361,
     361,   361,   362,   362,   363,   364,   365,   366,   366,   367,
     367,   367,   367,   367,   367,   368,   368,   369,   370,   371,
     372,   372,   373,   373,   373,   373,   373,   373,   373,   374,
     374,   375,   376,   377,   378,   378,   379,   379,   379,   379,
     380,   380,   381,   382,   383,   384,   384,   385,   385,   385,
     386,   387,   388,   389,   390,   391,   392,   392,   393,   393,
     394,   395,   396,   397,   397,   398,   398,   398,   399,   400,
     401,   402,   403,   404,   405,   405,   406,   406,   407,   407,
     408,   409,   410,   410,   411,   412,   413,   413,   414,   415,
     416,   417,   417,   418,   418,   419,   420,   421,   422,   422,
     423,   423,   423,   423,   423,   423,   423,   424,   424,   425,
     425,   426,   427,   428,   429,   429,   430,   430,   431,   432,
     433,   434,   434,   435,   435,   435,   435,   435,   435,   435,
     436,   437,   437,   438,   438,   439,   440,   441,   442,   442,
     443,   444,   445,   446,   446,   447,   447,   448,   449,   450,
     451,   451,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   453,   454,   454,   438,   438,   439,   440,   441,   454,
     454,   455,   456,   457,   458,   458,   459,   460,   461,   461,
     462,   463,   463,   464,   465,   465,   466,   466,   467,   467,
     468,   469,   470,   471,   471,   473,   472,   474,   474,   475,
     475,   476,   477,   477,   478,   478,   479,   479,   480,   481,
     482,   482,   483,   483,   484,   484,   486,   485,   487,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   493,   494,
     494,   495,   495,   496,   496,   498,   497,   499,   500,   500,
     501,   501,   502,   502,   503,   503,   504,   505,   505,   506,
     506,   507,   507,   509,   508,   510,   511,   511,   513,   512,
     514,   514,   515,   515,   516,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   546,   547,   548,   548,
     549,   549,   549,   549,   550,   550,   551,   551,   552,   553,
     554,   555,   555,   556,   556,   557,   558,   559,   559,   560,
     560,   561,   562,   562,   563,   564,   565,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   578,   579,   579,   579,   579,   579,   580,   581,   582,
     583,   583,   584,   585,   586,   587,   587,   588,   589,   590,
     590,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   600,
     601,   602,   603,   604,   604,   605,   605,   606,   606,   606,
     607,   608,   609,   609,   610,   610,   611,   612,   613,   614,
     615,   616,   617,   617,   618,   619,   620,   621,   622,   622,
     623,   624,   625,   626,   627,   628,   628,   629,   630,   631,
     632,   633,   633,   634,   635,   636,   637,   638,   639,   639,
     640,   641,   642,   643,   644,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   653,   654,   655,   655,   656,
     657,   658,   659,   659,   660,   661,   661,   662,   663,   664,
     664,   665,   666,   667,   668,   668,   669,   669,   670,   671,
     671,   672,   673,   674,   674,   675,   676,   677,   677,   678,
     679,   679,   680,   681,   682,   683,   684,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   693,   694,   695,
     695,   696,   697,   698,   699,   699,   700,   701,   701,   702,
     703,   704,   704,   705,   706,   707,   707,   708,   709,   710,
     710,   711,   712,   713,   714,   715,   715,   716,   717,   718,
     719,   720,   721,   721,   722,   723,   724,   725,   726,   726,
     727,   728,   729,   730,   731,   732,   732,   733,   734,   734,
     735,   735,   736,   737,   738,   739,   740,   741,   742,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   756,   757,   758,   758,   759,   760,   761,
     762,   763,   764,   765,   765,   766,   767,   768,   769,   769,
     770,   771,   772,   773,   773,   774,   774,   774,   775,   776,
     777,   777,   778,   778,   779,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   789,   789,   790,   791,   792,   791,
     793,   794,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   795,   797,   796,   799,
     798,   801,   800,   803,   802,   805,   804,   807,   806,   809,
     808,   810,   810,   812,   811,   813,   813,   815,   814,   816,
     816,   818,   817,   819,   819,   821,   820,   822,   822,   824,
     823,   826,   825,   828,   827,   830,   829,   832,   831,   834,
     833,   836,   835,   838,   837,   840,   839,   842,   841,   843,
     843,   845,   844,   846,   846,   848,   847,   849,   849,   850,
     850,   851,   851,   851,   853,   852,   855,   854,   856,   858,
     857,   859,   860,   859,   859,   861,   861,   862,   862,   863,
     864,   866,   865,   867,   865,   868,   868,   868,   868,   868,
     868,   868,   868,   868,   868,   868,   868,   868,   868,   870,
     869,   871,   871,   538,   872,   873,   874,   875,   876,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,   886,
     887,   888,   889,   890,   890,   891,   892,   893,   894,   895,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     0,     0,     4,
       5,     0,     2,     3,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     4,     4,     4,     4,     0,     3,     1,
       1,     1,     1,     1,     3,     0,     2,     0,     3,     1,
       1,     1,     1,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     3,     1,     1,     2,     1,     1,     2,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     3,
       1,     1,     2,     1,     1,     2,     1,     2,     0,     3,
       1,     0,     1,     1,     1,     6,     0,     3,     1,     1,
       2,     1,     2,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     1,     1,     2,     1,     2,     0,     2,     4,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     2,     3,     2,     1,     0,     3,
       1,     1,     2,     1,     2,     0,     2,     4,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     3,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     0,     2,
       4,     0,     2,     1,     1,     1,     1,     2,     3,     3,
       4,     1,     5,     1,     2,     0,     4,     0,     3,     1,
       3,     3,     0,     3,     0,     2,     1,     1,     4,     4,
       1,     3,     1,     2,     1,     2,     0,     4,     4,     1,
       2,     0,     3,     0,     2,     1,     1,     4,     4,     1,
       3,     1,     2,     1,     2,     0,     4,     4,     1,     2,
       0,     3,     0,     2,     1,     1,     4,     1,     3,     1,
       2,     1,     2,     0,     4,     4,     1,     2,     0,     4,
       1,     2,     0,     2,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     3,     3,     1,     1,     2,
       1,     3,     0,     2,     3,     1,     0,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     3,     2,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     3,     4,     2,     1,     0,     2,     1,     1,     1,
       3,     1,     0,     1,     1,     1,     1,     3,     2,     1,
       8,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     0,     3,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     3,     1,     0,     2,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     4,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     4,     3,
       0,     2,     1,     2,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       3,     0,     2,     2,     1,     1,     1,     1,     3,     0,
       3,     1,     2,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     0,     3,     1,     2,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     0,     4,     1,     0,     1,
       1,     1,     1,     3,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     4,     4,
       1,     1,     2,     1,     3,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     4,     5,     0,     0,     7,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       5,     0,     5,     0,     4,     0,     5,     0,     5,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     6,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     4,     1,     2,     0,
       2,     1,     1,     1,     0,     4,     0,     4,     4,     0,
       4,     1,     0,     4,     2,     0,     2,     1,     1,     4,
       4,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     2,     4,     2,     1,     2,     2,     1,     3,
       2,     1,     2,     2,     1,     2,     3,     1,     0,     1,
       2,     3,     1,     0,     1,     2,     3,     2,     1,     1,
       2,     2,     1,     3,     2,     1,     3,     2,     1,     3,
       2,     1,     3,     2,     1,     6,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   684,     0,    11,     1,     0,    27,     0,
       0,     0,   687,    29,    37,     0,     0,     9,    14,    12,
      17,     0,     0,    39,   148,     0,     0,     0,    30,     0,
       0,     0,   685,   690,     0,   150,   251,   151,     0,     0,
      40,     0,    33,    35,    28,    31,    32,    10,    15,     0,
       0,     0,     0,     0,    13,    18,    19,    20,    21,    22,
       0,     0,     0,   253,     0,     0,     0,     0,    43,    45,
      38,    41,    42,     0,     0,    16,     0,     0,     0,   368,
     686,     0,     0,     4,     3,     7,   256,   328,   252,   254,
     255,   154,   156,   149,   152,   153,     0,     0,   340,    34,
     408,    36,   410,     0,     0,     0,     0,     0,     0,   727,
     719,   721,   725,   749,   751,   729,   745,   759,   723,   765,
     753,   755,   757,   789,   761,   763,   737,   733,   741,   767,
     771,   717,   775,   801,   803,   688,   694,   695,   697,   698,
     699,   700,   696,   715,   711,   712,   701,   702,   703,   704,
     706,   705,   707,   709,   710,   708,   713,   714,   692,   693,
     716,     6,     2,     5,   257,   261,     0,     0,     0,     0,
     158,   179,     0,   341,    44,    55,    65,    75,    88,   102,
     113,   131,    46,    47,    57,    48,    67,    49,    77,    50,
      90,    51,   104,    52,   115,    53,   133,     0,   409,    26,
      23,    24,    25,   368,   368,   370,   371,   372,   373,   369,
     691,     0,     0,     0,     0,     0,     0,   731,   747,     0,
       0,     0,     0,     0,     0,   795,     0,     0,   739,   735,
     743,     0,     0,     0,   779,     0,     0,     0,   258,     0,
     265,   259,   332,   181,   208,     0,     0,   163,   159,     0,
      56,     0,    66,     0,    76,     0,    89,     0,   103,     0,
     114,     0,   132,   422,   425,   407,   420,   421,     0,     0,
       0,     0,     0,   411,   412,   415,   416,   414,   413,   365,
     366,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   769,     0,   768,   773,     0,   772,     0,     0,   819,
     825,   828,   831,   834,   837,   842,   848,   852,   855,   858,
     861,   864,   867,     0,   805,   806,     0,   807,     0,   808,
       0,   809,     0,   810,   838,   811,   843,   812,     0,   813,
       0,   814,     0,   815,     0,   816,     0,   817,     0,   818,
       0,     0,   689,     0,   265,   263,     0,     0,   210,     0,
       0,     0,   186,   182,     0,   157,     0,    62,     0,    54,
       0,     0,     0,    58,    59,    60,    61,    72,     0,    64,
      68,    69,    70,    71,    85,     0,    74,     0,     0,     0,
      78,    79,    80,    81,    83,    82,    84,    99,     0,    87,
       0,     0,    91,    92,    93,    94,    96,    95,    97,    98,
     110,     0,   101,     0,   105,   106,   107,   108,   109,   122,
     112,     0,     0,   116,   117,   118,   119,   140,   130,     0,
       0,   134,   135,   136,   137,   427,     0,   455,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,   752,
     730,   732,   746,   748,   760,   724,     0,   754,   756,   758,
     791,     0,     0,     0,   790,   796,   797,   798,   762,   764,
     738,   740,   734,   736,   742,   744,   770,   774,     0,   777,
       0,     0,     0,     0,   776,   780,   781,   783,   782,     0,
     802,     0,   824,     0,   827,     0,   830,     0,   833,     0,
       0,   839,     0,   844,   849,     0,   847,     0,   851,     0,
     854,     0,   857,     0,   860,     0,   863,     0,   866,   804,
       0,   260,   264,   267,   330,     0,     0,     0,   329,   333,
     334,   335,   242,     0,     0,     0,   215,   211,     0,   180,
       0,     0,   161,     0,   166,   160,   164,   168,    63,     0,
       0,     0,    73,    86,   368,     0,     0,   100,     0,     0,
     111,     0,   128,     0,   120,   368,   376,   123,   146,     0,
     138,   376,   141,   423,   424,     0,   428,   418,   419,   417,
       0,     0,   728,   720,   722,   726,     0,   794,   792,     0,
     368,   718,   778,   784,   368,   786,     0,     0,     0,   826,
       0,   832,   835,     0,     0,   836,     0,   841,   850,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   368,
     368,   155,     0,     0,   243,     0,   209,     0,     0,   184,
       0,   189,   183,   187,   191,   344,   162,     0,   167,   349,
       0,     0,     0,     0,     0,     0,     0,   356,   129,     0,
       0,     0,   121,     0,   125,   374,   375,   147,   139,     0,
     143,   639,   461,   636,   456,   457,   462,   458,     0,   459,
       0,   454,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,   450,     0,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   447,   448,   449,   439,   677,   679,   766,
       0,     0,     0,     0,     0,     0,     0,     0,   821,     0,
     820,   829,   846,   840,   845,   853,   856,   859,   862,     0,
     868,   262,     0,   269,   272,   266,     0,     0,     0,   246,
     248,   241,   244,   245,     0,   213,     0,   218,   212,   216,
     220,   345,   185,   203,   190,   177,     0,   165,     0,     0,
       0,     0,     0,   169,   176,   170,   171,   172,   173,   174,
     175,   343,   342,   351,   352,   353,   354,   355,   368,   367,
       0,     0,   126,     0,   124,   379,   377,   381,   144,     0,
     142,   466,     0,     0,   463,   464,   465,     0,   368,     0,
     640,   453,     0,     0,     0,     0,     0,     0,     0,   368,
     368,   793,   800,   799,   785,   788,   787,     0,     0,   822,
       0,   268,   274,     0,   291,   337,   338,     0,     0,   346,
     214,   203,   219,     0,   200,     0,     0,     0,     0,   192,
     199,   197,   198,   193,   195,   194,   196,   178,     0,     0,
       0,     0,     0,   339,     0,   390,     0,   386,   387,   388,
     127,     0,   380,   145,   368,   469,   460,   472,   637,   635,
       0,   643,   638,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   451,   823,   357,     0,     0,   270,   293,
     310,   348,   247,     0,   249,   231,     0,   221,   230,   228,
     229,   222,   223,   224,   225,   226,   227,   201,     0,   188,
       0,   204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,     0,   378,     0,     0,   382,
     384,   383,   467,   474,   468,   485,     0,   368,   651,   658,
       0,     0,     0,   644,   440,   441,   442,   443,   444,   445,
     446,   452,   865,   282,   286,     0,     0,   275,   276,   277,
     273,   280,     0,   312,   271,     0,   232,     0,   217,   202,
     206,     0,     0,     0,     0,   350,   358,   360,   361,   362,
     364,   681,   391,     0,     0,     0,   487,   498,     0,   477,
     473,     0,     0,   676,   641,     0,   652,     0,   647,   376,
     642,   645,   646,   283,   286,   284,     0,     0,     0,   301,
     305,     0,     0,   294,   295,   296,   292,   299,     0,     0,
     233,   207,   205,   347,   363,   359,   385,     0,     0,   500,
     550,     0,   490,     0,     0,     0,   484,   475,     0,   480,
     376,   476,   478,   479,   661,   659,   663,   655,   376,   650,
     653,   654,     0,   649,     0,   281,   285,     0,     0,     0,
     302,   305,   303,     0,     0,     0,   319,   323,     0,     0,
     313,   314,   311,   317,   315,   250,   682,   683,   552,   589,
       0,   503,   499,     0,     0,   486,   497,   488,     0,   493,
     376,   489,   491,   492,     0,     0,   400,   482,     0,     0,
     662,   657,     0,   678,   648,     0,     0,   278,   279,   300,
     304,     0,     0,     0,   320,   323,   321,     0,     0,     0,
     591,   602,     0,   555,   551,     0,     0,   510,   501,     0,
     506,   376,   502,   504,   505,     0,     0,   404,   495,     0,
     483,   376,     0,   481,   673,   425,   660,   670,   671,   368,
     368,   667,   664,   665,   666,   656,     0,   289,     0,   287,
       0,     0,   297,   298,   318,   322,     0,     0,     0,   604,
     615,     0,   594,     0,     0,     0,   562,   553,     0,   558,
     376,   554,   556,   557,     0,   511,   508,     0,   496,   376,
       0,   494,     0,   392,   399,   672,   455,     0,     0,     0,
       0,   290,     0,   308,     0,   306,     0,     0,   316,   336,
     617,     0,   618,   607,     0,     0,     0,   590,   601,   592,
       0,   597,   376,   593,   595,   596,     0,   563,   560,     0,
     514,   509,   507,     0,   376,   403,   401,     0,   675,   674,
     368,   368,   288,     0,   309,     0,   326,     0,   324,     0,
     470,   622,     0,     0,   619,   620,   621,   603,   614,   605,
       0,   610,   376,   606,   608,   609,     0,   599,     0,   566,
     561,   559,   516,     0,   522,     0,   405,     0,   395,   402,
     393,   396,   668,   669,   307,     0,   327,   471,   368,   626,
       0,     0,     0,     0,   612,     0,   600,   598,   568,     0,
     574,     0,   512,   524,   513,     0,   519,   376,   515,   517,
     518,   406,     0,   397,   325,   623,   616,   634,   624,     0,
       0,   627,   613,   611,   564,   576,   565,     0,   571,   376,
     567,   569,   570,   527,   529,   523,   525,   526,   521,     0,
     368,   394,     0,   630,   376,   625,   628,   629,   579,   581,
     575,   577,   578,   573,     0,     0,   520,     0,   633,   632,
       0,     0,   572,   532,   528,   530,   534,   398,   631,   584,
     580,   582,     0,     0,   533,   587,     0,   583,   585,   586,
     541,   543,   531,   539,   540,     0,   368,   535,   537,   536,
       0,     0,   368,     0,   588,   542,   546,   544,   547,     0,
     368,     0,     0,   538,   680,   368,     0,   545,     0,     0,
     548,   549
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    85,   162,   163,     3,     5,    10,    19,    20,
      54,    30,    55,    56,    57,    58,    59,    14,    15,    27,
      44,    45,    46,    74,    24,    25,    39,    70,    71,    72,
      97,   182,   183,   184,   249,   250,   373,   369,   185,   186,
     251,   252,   380,   379,   187,   188,   253,   254,   390,   386,
     189,   190,   255,   256,   402,   399,   191,   192,   257,   258,
     414,   412,   193,   194,   259,   260,   423,   420,   421,   422,
     566,   652,   653,   774,   564,   195,   196,   261,   262,   431,
     428,   429,   430,   571,   658,   659,   780,   570,    36,    37,
      66,    93,    94,    95,   171,   172,   247,   365,   545,   366,
     546,   547,   637,   638,   753,   747,   244,   245,   362,   539,
     632,   540,   633,   634,   743,   744,   829,   823,   899,   824,
     901,   902,  1012,   359,   360,   536,   626,   738,   627,   739,
     740,   821,   822,   887,   886,   958,   533,   534,   623,   731,
     732,   733,   818,   884,    64,    65,    88,    89,    90,   166,
     167,   240,   354,   355,   356,   617,   725,   813,   814,   877,
     947,   948,   949,   950,   951,   994,   995,   996,  1096,  1149,
     880,   952,  1003,  1004,  1005,  1006,  1007,  1051,  1052,  1053,
    1151,  1195,   954,  1008,  1060,  1061,  1062,  1063,  1105,  1106,
    1107,  1197,  1238,   168,   169,   528,   357,   529,  1064,   530,
     531,   567,    28,    40,   374,   375,   248,   363,   537,   830,
     624,   376,   832,   394,   395,   396,   408,   409,   418,   598,
     756,   834,   757,   758,   759,   835,   760,   106,   649,   650,
     209,   654,   655,   776,   777,   851,   852,   919,   916,   656,
     847,   848,   849,  1227,  1270,  1271,  1302,  1331,  1084,  1085,
    1132,  1184,  1125,  1126,  1180,  1225,   101,   102,   197,   198,
     273,   274,   275,   276,   265,   266,   267,   436,   437,   438,
     575,   576,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   673,   574,   664,   665,   666,
     783,   784,   785,   786,   856,   857,   924,  1240,   925,   926,
     980,   981,   982,  1031,  1032,  1033,  1088,  1027,  1028,   977,
     978,  1023,  1024,  1025,  1081,  1082,  1083,  1129,  1077,  1078,
    1020,  1021,  1072,  1073,  1074,  1122,  1123,  1124,  1177,  1118,
    1119,  1174,  1221,  1263,  1264,  1265,  1298,  1299,  1300,  1329,
    1294,  1295,  1325,  1326,  1327,  1345,  1355,  1356,  1363,  1364,
    1377,  1378,  1372,  1373,  1374,  1381,  1387,  1388,  1392,  1397,
    1069,  1070,  1114,  1115,  1116,  1171,  1172,  1173,  1219,  1167,
    1168,  1216,  1260,  1289,  1290,  1291,  1320,  1321,  1322,  1344,
    1316,  1317,  1340,  1341,  1342,  1351,  1361,  1362,  1367,  1368,
    1369,  1111,  1112,  1163,  1164,  1165,  1213,  1214,  1215,  1258,
    1209,  1210,  1160,  1161,  1204,  1205,  1206,  1253,  1254,  1255,
    1285,  1249,  1250,  1201,  1202,  1243,  1244,  1245,  1246,  1280,
    1281,  1282,  1310,  1335,  1336,  1337,  1350,  1308,  1309,   667,
     668,   859,   669,   670,   789,   862,   863,   864,   932,   990,
     991,   992,  1044,   929,   930,   985,  1039,  1040,  1041,  1092,
     984,  1035,  1036,  1089,  1090,  1142,  1143,  1144,  1136,  1137,
    1138,  1187,   790,   277,  1127,   278,  1379,   771,   920,   921,
       8,    12,    22,   237,    34,    62,   135,   136,   233,   137,
     212,   138,   213,   139,   220,   140,   214,   141,   211,   142,
     217,   287,   143,   229,   299,   144,   228,   298,   145,   230,
     300,   146,   218,   288,   147,   215,   148,   216,   149,   222,
     150,   223,   151,   224,   152,   219,   153,   226,   154,   227,
     155,   221,   156,   231,   303,   157,   232,   306,   158,   234,
     484,   308,   485,   486,   703,   487,   705,   488,   159,   225,
     464,   700,   295,   465,   466,   467,   160,   235,   236,   323,
     324,   489,   710,   325,   326,   492,   327,   328,   494,   329,
     330,   496,   331,   332,   498,   333,   334,   500,   605,   335,
     336,   502,   607,   501,   337,   338,   506,   339,   340,   508,
     341,   342,   510,   343,   344,   512,   345,   346,   514,   347,
     348,   516,   349,   350,   518
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1160
static const yytype_int16 yypact[] =
{
      85,    80,   114,  -106,   126, -1160, -1160,   -96,   116,   142,
      90,   138, -1160, -1160,   127,   132,   167, -1160, -1160, -1160,
   -1160,   188,   -45, -1160,   131,   169,   198,   165, -1160,   194,
      28,   214, -1160, -1160,   189, -1160,   118, -1160,   221,   237,
   -1160,   229, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   210,
     241,   246,   251,   256, -1160, -1160, -1160, -1160, -1160, -1160,
     250,   275,   269, -1160,   239,   266,   272,   233, -1160, -1160,
   -1160, -1160, -1160,   284,    -4, -1160,   282,   299,   315, -1160,
   -1160,   336,   687, -1160, -1160,   279, -1160,   182, -1160, -1160,
   -1160, -1160,   283, -1160, -1160, -1160,   378,   185, -1160, -1160,
   -1160, -1160, -1160,   380,   382,   384,   386,    29,   388, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160,   291,   290,   297,   281,
   -1160,   332,   331, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160,   293,    20, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160,   687,   687,   687,   687,   687,   687, -1160, -1160,   687,
     687,   687,   687,   687,   687, -1160,   687,   687, -1160, -1160,
   -1160,   298,   300,   687, -1160,   -64,   -64,   177, -1160,   410,
   -1160, -1160, -1160, -1160,   337,   342,   416, -1160, -1160,   302,
       3,   304,     3,   306,     9,   308,    36,   310,     0,   366,
       3,   370,     3, -1160,   262, -1160, -1160, -1160,   419,   427,
     460,   443,   462, -1160, -1160, -1160, -1160, -1160, -1160,  -126,
    -126,   687,   687,   687,   687,   225,   224,   149,   311,   219,
     220,   687,   217,   218,   222,    34,   213,   212,   364,   526,
     615, -1160,   205, -1160, -1160,   207, -1160,   687,    39, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160,   199, -1160, -1160,   -64, -1160,   -64, -1160,
     687, -1160,   -64, -1160,   168, -1160,   168, -1160,   314, -1160,
     -64, -1160,   -64, -1160,   -64, -1160,   687, -1160,   -64, -1160,
     687,   200, -1160,   478,   383, -1160,   381,    65, -1160,   402,
     409,   487, -1160, -1160,   484, -1160,    76, -1160,   456, -1160,
     489,   491,   492, -1160, -1160, -1160, -1160, -1160,   458, -1160,
   -1160, -1160, -1160, -1160, -1160,   455, -1160,   495,   496,   497,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   457, -1160,
     499,   500, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160,   459, -1160,   502, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160,   316,   352, -1160, -1160, -1160, -1160, -1160, -1160,   318,
     352, -1160, -1160, -1160, -1160, -1160,   347, -1160, -1160,   504,
     505,   507,   506,   512,   280,   285,   286,   287, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160,   687, -1160, -1160, -1160,
   -1160,   656,   517,   519, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   245, -1160,
     248,   521,   523,   525, -1160, -1160, -1160, -1160, -1160,    25,
   -1160,   244, -1160,   -64, -1160,   242, -1160,   243, -1160,   527,
     -64, -1160,   -64, -1160, -1160,   235, -1160,   -64, -1160,   -64,
   -1160,   -64, -1160,   -64, -1160,   687, -1160,   687, -1160, -1160,
     531, -1160, -1160,   515, -1160,   411,   534,   536, -1160, -1160,
   -1160, -1160, -1160,   475,   461,   540, -1160, -1160,   538, -1160,
      82,   544, -1160,   482, -1160, -1160, -1160, -1160, -1160,   550,
     548,   554, -1160, -1160, -1160,   556,   558, -1160,   560,   562,
   -1160,   568, -1160,   529, -1160, -1160,   418, -1160, -1160,   533,
   -1160,   418, -1160, -1160,   -52,   320,   112, -1160, -1160, -1160,
     570,   576, -1160, -1160, -1160, -1160,   327, -1160, -1160,   578,
   -1160, -1160, -1160, -1160, -1160, -1160,   584,   586,   326, -1160,
     303, -1160, -1160,   590,   324, -1160,   312, -1160, -1160,   296,
     322,   294,   334,   687,   292,   593,   606,   328, -1160, -1160,
   -1160, -1160,   609,   330, -1160,   607, -1160,    56,   617, -1160,
     552, -1160, -1160, -1160, -1160, -1160, -1160,   339,    61, -1160,
     619,   625,   631,   633,   635,   639,   641, -1160, -1160,   642,
      17,   485, -1160,   343, -1160,   488, -1160, -1160, -1160,   345,
   -1160, -1160, -1160, -1160, -1160, -1160,   134, -1160,   -64, -1160,
     474, -1160,   486, -1160,   650,   651,   652,   653,   654,   655,
     657,   658, -1160,   659, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
     397,   661,   662,   663,   664,   665,   666,   667, -1160,   510,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   687,
   -1160, -1160,   668, -1160,   559, -1160,   669,   673,   670, -1160,
   -1160, -1160, -1160, -1160,   675, -1160,   583, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160,   159, -1160,   598, -1160,   676,   677,
     679,   680,   681, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
     682,   349, -1160,   630, -1160, -1160, -1160, -1160, -1160,   629,
   -1160, -1160,   685,   683, -1160, -1160, -1160,   472, -1160,   473,
   -1160, -1160,   684,   688,   689,   690,   691,   692,   693, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160,   698,   699, -1160,
     687, -1160, -1160,   588,   592, -1160, -1160,   701,   107, -1160,
   -1160, -1160,   117,   351,   621,   703,   704,   705,   706, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   702,   707,
     708,   709,   710, -1160,   711, -1160,    27, -1160, -1160, -1160,
   -1160,   700,   204, -1160, -1160, -1160, -1160,   520, -1160, -1160,
     712, -1160, -1160,   501,   569,   720,   721,   722,   723,   724,
     725,   726,   727, -1160, -1160, -1160,   404,    45, -1160, -1160,
     620, -1160, -1160,   728, -1160,   621,   355, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   660, -1160,
     729, -1160,   -64,   731,   734,   735,   732,   733,   740,   741,
     743,   744,   745,   573, -1160,   742, -1160,   747,   748, -1160,
   -1160, -1160, -1160, -1160, -1160,   549,   539, -1160, -1160, -1160,
     569,   750,   357, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160,   643,   751,   754, -1160, -1160, -1160,
   -1160, -1160,    49, -1160, -1160,   687, -1160,   678, -1160, -1160,
   -1160,   695,   755,   759,   761, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160,   603,   765,   767, -1160,   563,   581, -1160,
   -1160,   585,   359, -1160,   610,   361, -1160,   777, -1160,   418,
   -1160, -1160, -1160, -1160,   697, -1160,   672,   779,   781, -1160,
     686,   787,   795, -1160, -1160, -1160, -1160, -1160,    53,   714,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160,   799,   803, -1160,
     601,   616, -1160,   608,   618,   363, -1160, -1160,   569, -1160,
     418, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   418, -1160,
   -1160, -1160,   810, -1160,   594, -1160, -1160,   798,   814,   815,
   -1160,   713, -1160,   715,   812,   813, -1160,   716,   818,   819,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   614,
     634, -1160, -1160,   627,   365, -1160, -1160, -1160,   569, -1160,
     418, -1160, -1160, -1160,   628,   626, -1160, -1160,   632,   367,
     -93, -1160,   611, -1160, -1160,   827,   423, -1160, -1160, -1160,
   -1160,   816,   829,   832, -1160,   730, -1160,   717,   831,   833,
   -1160,   636,   644, -1160, -1160,   645,   425, -1160, -1160,   569,
   -1160,   418, -1160, -1160, -1160,   638,   674, -1160, -1160,   647,
   -1160, -1160,   648, -1160, -1160,    35, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160,   837, -1160,   736, -1160,
     848,   428, -1160, -1160, -1160, -1160,   835,   852,   858, -1160,
     738,   719, -1160,   671,   746,   430, -1160, -1160,   569, -1160,
     418, -1160, -1160, -1160,   854, -1160, -1160,   749, -1160, -1160,
     752, -1160,   -49, -1160, -1160, -1160, -1160,   694,   860,   862,
     868, -1160,   870, -1160,   756, -1160,   872,   432, -1160, -1160,
   -1160,   874,   270, -1160,   696,   758,   438, -1160, -1160, -1160,
     569, -1160,   418, -1160, -1160, -1160,   889, -1160, -1160,   753,
     760, -1160, -1160,   -31, -1160, -1160, -1160,   -60,   -52, -1160,
   -1160, -1160, -1160,   880, -1160,   895, -1160,   785, -1160,   769,
   -1160, -1160,   900,   762, -1160, -1160, -1160, -1160, -1160, -1160,
     569, -1160,   418, -1160, -1160, -1160,   718, -1160,   771,   764,
   -1160, -1160, -1160,   773,   768,   440, -1160,   -59, -1160, -1160,
   -1160,   805, -1160, -1160, -1160,   903, -1160, -1160, -1160, -1160,
     763,   775,   569,   776, -1160,   780, -1160, -1160, -1160,   782,
     772,   442, -1160, -1160, -1160,   444, -1160,   418, -1160, -1160,
   -1160, -1160,   901, -1160, -1160, -1160, -1160, -1160, -1160,   569,
     446, -1160, -1160, -1160, -1160, -1160, -1160,   448, -1160,   418,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   778,
   -1160, -1160,   783, -1160,   418, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160,   784,   -58, -1160,   820, -1160, -1160,
     786,   -54, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160,   450,   452,   -50, -1160,   687, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160,   938, -1160, -1160, -1160, -1160,
     822,   -53, -1160,   940, -1160, -1160, -1160, -1160,   737,   972,
   -1160,   976,   975, -1160, -1160, -1160,   980, -1160,   985,   774,
   -1160, -1160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   170,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160,   640, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160,    -5, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,   -56, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,  -113,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160,   566, -1160, -1160,     8,    13, -1160, -1160, -1160,   171,
   -1160,  -227,   175,   757,   766, -1160, -1160, -1160, -1160,  -616,
     176, -1160,   178,   179,   180, -1160,  -710,  -536,  -760,   -79,
   -1160,  -564, -1078, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1159, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160,   -91, -1160, -1160, -1160, -1160, -1160, -1160,  -132, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160,  -182, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160,  -845, -1160, -1160, -1160, -1160,  -266,
   -1160, -1160, -1160, -1160, -1160, -1160,  -210, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,  -221,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160,   739, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160, -1160,
   -1160, -1160, -1160, -1160, -1160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     107,   281,   282,   283,   284,   285,   286,   660,   843,   289,
     290,   291,   292,   293,   294,   351,   296,   297,   642,   933,
     769,   370,   755,   307,   370,   383,    99,   393,   860,   405,
     370,   417,   913,   426,   836,   434,   203,   204,    48,    49,
     873,   268,   269,   596,   460,   461,    50,    51,    52,   479,
     480,  1256,   462,  1182,   702,   943,   944,   370,   704,   999,
    1000,   481,   482,  1056,  1057,   413,   735,   736,   387,   388,
     389,   444,   445,   446,   447,   524,   525,   451,   453,   596,
     270,   456,   370,   726,   727,   986,   542,   543,   471,   473,
     475,  1283,   629,   630,   922,   387,   388,   478,   400,   401,
     309,  1223,  1268,   775,  1353,   491,     4,   493,  1359,     1,
    1385,   497,   896,   775,     6,    17,   597,    18,   661,   507,
     495,   509,     7,   511,   279,   280,  1375,   515,   833,     9,
    1376,   775,  1139,  1140,    11,   596,   513,   737,   370,   662,
     517,    21,  1269,  1301,  1354,    13,  1267,   544,  1360,    16,
    1332,  1226,   597,   748,   749,   750,   751,   752,   631,    23,
     100,   945,  1386,    26,   946,   663,  1001,   983,  1002,  1266,
      29,  1058,  1059,   526,   527,    42,    43,   596,   371,   372,
     370,   371,   372,  1086,    32,   914,    33,   371,   372,   205,
     206,   207,   208,   270,   882,    31,   883,    35,   271,   272,
     825,    41,   435,    38,  1185,    47,   891,    61,   597,   748,
     749,   750,   751,   752,   371,   372,   828,    60,   174,    63,
     175,   310,   176,   311,    67,   312,   177,   313,   178,   314,
     179,   315,   180,   316,   181,   317,    73,   318,    75,   319,
      96,   320,   825,   321,    76,   322,   586,    68,    69,    77,
     597,   588,    83,    84,    78,   752,   826,   827,   828,    79,
     381,    80,   391,   872,   403,   382,   415,   392,   424,   404,
     432,   416,   600,   425,  1175,   433,    86,    87,    81,   604,
      82,   606,    91,    92,   164,   165,   609,    98,   610,   103,
     611,   161,   612,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   263,   264,   613,   104,   614,   301,   302,
     304,   305,   367,   368,   377,   378,   384,   385,   397,   398,
     410,   411,   105,  1217,   504,   505,   562,   563,   568,   569,
     671,   672,   205,   206,   207,   208,   708,   709,   723,   724,
     729,   730,    53,   108,   205,   206,   207,   208,   463,   745,
     746,   170,   483,   772,   773,   778,   779,   781,   782,   845,
     846,   897,   898,   917,   918,   956,   957,   988,   989,  1029,
    1030,  1037,  1038,  1079,  1080,  1120,  1121,  1134,  1135,  1188,
    1189,   173,   109,   199,   110,   200,   111,   201,   112,   202,
     113,   210,   114,   238,   115,   450,   116,   239,   117,   241,
     118,   246,   119,   719,   120,   243,   121,   242,   122,   352,
     123,   754,   124,   353,   125,   358,   126,   361,   127,   364,
     128,   419,   129,   439,   130,  1043,   131,   427,   132,   435,
     133,   440,   134,  1147,  1148,  1169,  1170,  1311,  1193,  1194,
    1211,  1212,  1236,  1237,  1241,  1242,   442,   787,  1251,  1252,
    1296,  1297,  1318,  1319,  1323,  1324,  1333,  1334,  1338,  1339,
    1365,  1366,  1370,  1371,   441,   443,  1087,   448,   449,   454,
    1272,  1273,   455,   457,  1091,   107,   458,   468,   469,   476,
     499,   490,   459,   477,   519,   520,   523,   521,   532,   535,
     538,   541,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   565,   560,   561,   577,   578,   810,
     579,   107,   573,   580,   582,   107,  1128,   831,  1305,   581,
     589,   583,   590,   591,   584,   593,   594,   585,   592,   595,
     599,   603,   601,   608,   615,   602,   616,   619,   618,   620,
     107,   107,   621,   625,   109,   628,   110,   635,   111,   622,
     112,   636,   113,   639,   114,   640,   115,  1176,   116,   452,
     117,   641,   118,   643,   119,   644,   120,   645,   121,   646,
     122,   647,   123,   697,   124,   651,   125,   648,   126,   698,
     127,   699,   128,   657,   129,   701,   130,   706,   131,   707,
     132,   711,   133,   712,   134,   889,   715,   109,   717,   110,
     876,   111,   720,   112,   721,   113,  1218,   114,   714,   115,
     722,   116,   728,   117,   734,   118,  1383,   119,   713,   120,
     741,   121,   761,   122,   716,   123,   742,   124,   762,   125,
    1394,   126,   470,   127,   763,   128,   764,   129,   765,   130,
     718,   131,   766,   132,   767,   133,   770,   134,  1257,   768,
     775,   788,   791,   792,   793,   794,   795,   796,   797,   801,
     798,   799,   820,   800,   802,   803,   804,   805,   806,   812,
     837,   811,   815,   807,   808,   809,   816,   817,   819,   838,
     839,   961,   840,   841,   842,   844,   850,   853,  1284,   854,
     858,   865,   861,   855,   878,   866,   867,   868,   869,   870,
     871,   874,   875,   879,   881,   900,   903,   904,   905,   907,
     906,   915,   942,   923,   908,   909,   910,   911,   912,   927,
     107,   931,   928,   934,   935,   936,   937,   938,   939,   940,
     941,   972,   953,  1328,   979,   965,   966,   959,   962,   955,
     960,   963,   964,   967,   968,  1009,   969,   970,   971,   973,
     974,   975,   976,   987,   997,  1343,   993,   998,  1013,   109,
    1010,   110,  1014,   111,  1015,   112,  1016,   113,  1019,   114,
    1349,   115,  1017,   116,  1018,   117,  1022,   118,  1034,   119,
    1011,   120,  1026,   121,  1042,   122,  1048,   123,  1049,   124,
    1054,   125,  1047,   126,  1347,   127,   472,   128,  1055,   129,
    1050,   130,  1066,   131,  1065,   132,  1067,   133,  1068,   134,
    1045,  1071,  1075,  1093,  1094,  1076,  1095,  1097,  1098,  1102,
    1103,  1108,  1109,  1110,  1117,  1131,  1130,  1099,  1133,  1113,
    1146,  1104,  1152,  1145,  1150,  1153,  1178,  1101,  1157,  1162,
    1158,  1156,  1166,  1181,  1190,  1154,  1389,  1159,   109,  1183,
     110,  1192,   111,  1196,   112,  1198,   113,  1191,   114,  1398,
     115,  1199,   116,  1229,   117,  1220,   118,  1230,   119,  1231,
     120,  1232,   121,  1179,   122,  1235,   123,  1233,   124,  1234,
     125,  1207,   126,  1274,   127,  1239,   128,   474,   129,   109,
     130,   110,   131,   111,   132,   112,   133,   113,   134,   114,
    1259,   115,  1275,   116,  1278,   117,  1304,   118,  1247,   119,
    1276,   120,  1330,   121,  1203,   122,  1286,   123,   587,   124,
     109,   125,   110,   126,   111,   127,   112,   128,   113,   129,
     114,   130,   115,   131,   116,   132,   117,   133,   118,   134,
     119,  1382,   120,  1208,   121,  1222,   122,  1390,   123,  1261,
     124,  1200,   125,  1224,   126,  1248,   127,  1279,   128,  1262,
     129,  1277,   130,  1288,   131,   918,   132,  1287,   133,  1293,
     134,  1292,  1307,  1315,  1312,  1393,  1313,  1306,  1346,  1395,
    1314,  1348,  1358,  1357,  1352,  1384,  1396,  1399,  1400,  1046,
    1401,   885,  1155,   888,   522,  1100,   572,   890,   892,  1141,
     893,   894,   895,  1186,  1228,  1303,     0,     0,     0,     0,
       0,     0,     0,   406,     0,     0,     0,     0,     0,     0,
       0,     0,   407,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1380,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
      79,   211,   212,   213,   214,   215,   216,   571,   768,   219,
     220,   221,   222,   223,   224,   236,   226,   227,   554,   864,
       3,    21,   638,   233,    21,   252,    30,   254,   788,   256,
      21,   258,     5,   260,   744,   262,     7,     8,    10,    11,
     800,    21,    22,    18,    10,    11,    18,    19,    20,    10,
      11,  1210,    18,  1131,   590,    10,    11,    21,   594,    10,
      11,    22,    23,    10,    11,    65,    10,    11,    59,    60,
      61,   281,   282,   283,   284,    10,    11,   287,   288,    18,
     173,   291,    21,   619,   620,   930,    10,    11,   298,   299,
     300,  1250,    10,    11,   854,    59,    60,   307,    62,    63,
     164,  1179,   162,   162,   162,   326,    26,   328,   162,    24,
     163,   332,   822,   162,     0,    25,    91,    27,   170,   340,
     330,   342,   228,   344,   203,   204,   176,   348,   744,     3,
     180,   162,   225,   226,   230,    18,   346,    81,    21,   191,
     350,     3,   202,   202,   202,    29,  1224,    71,   202,     7,
    1309,   200,    91,    92,    93,    94,    95,    96,    76,    32,
     164,   116,   215,    31,   119,   217,   117,   927,   119,   200,
       3,   118,   119,   108,   109,    10,    11,    18,   178,   179,
      21,   178,   179,  1028,   229,   158,   231,   178,   179,   315,
     316,   317,   318,   173,    87,     7,    89,    66,   178,   179,
      83,     3,   167,    34,   169,    11,   822,    18,    91,    92,
      93,    94,    95,    96,   178,   179,    99,     3,    33,   101,
      35,   285,    37,   287,     3,   289,    41,   291,    43,   293,
      45,   295,    47,   297,    49,   299,     7,   301,    28,   303,
       7,   305,    83,   307,     3,   309,   456,    10,    11,     3,
      91,   461,    13,    14,     3,    96,    97,    98,    99,     3,
     252,    11,   254,   799,   256,   252,   258,   254,   260,   256,
     262,   258,   493,   260,  1119,   262,    10,    11,     3,   500,
      11,   502,    10,    11,   102,   103,   507,     3,   509,     7,
     511,    12,   513,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    10,    11,   515,     7,   517,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     7,  1168,    10,    11,    10,    11,    10,    11,
      10,    11,   315,   316,   317,   318,    10,    11,    10,    11,
      10,    11,   314,     7,   315,   316,   317,   318,   314,    10,
      11,    68,   313,    10,    11,    10,    11,   223,   224,    10,
      11,    10,    11,   159,   160,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,  1139,
    1140,     3,   233,     3,   235,     3,   237,     3,   239,     3,
     241,     3,   243,   102,   245,   246,   247,   107,   249,   102,
     251,    70,   253,   613,   255,    73,   257,   126,   259,   232,
     261,   638,   263,     3,   265,    78,   267,    75,   269,     3,
     271,    55,   273,     4,   275,   989,   277,    57,   279,   167,
     281,     4,   283,    10,    11,    10,    11,  1282,    10,    11,
      10,    11,    10,    11,   174,   175,     3,   668,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     4,     3,  1030,   242,   244,   250,
    1230,  1231,   252,   256,  1038,   554,   258,   264,   266,   274,
     312,   282,   260,   276,   284,     7,   105,   104,    86,    80,
       3,     7,    36,     4,     3,     3,    38,    42,     3,     3,
       3,    44,     3,     3,   152,    46,     4,     3,     3,   719,
       3,   590,   165,     7,   234,   594,  1080,   744,  1278,     7,
       3,   236,     3,   278,   238,     4,     3,   240,   280,     4,
     286,     4,   290,   298,     3,   292,    21,     3,   127,     3,
     619,   620,    67,     3,   233,     7,   235,     3,   237,    88,
     239,    69,   241,     3,   243,     7,   245,  1121,   247,   248,
     249,     7,   251,     7,   253,     7,   255,     7,   257,     7,
     259,     3,   261,     3,   263,   157,   265,    48,   267,     3,
     269,   254,   271,    50,   273,     7,   275,     3,   277,     3,
     279,   288,   281,     3,   283,   822,   300,   233,   304,   235,
     810,   237,   310,   239,    11,   241,  1170,   243,   296,   245,
       4,   247,     3,   249,     7,   251,  1376,   253,   294,   255,
       3,   257,     3,   259,   302,   261,    74,   263,     3,   265,
    1390,   267,   268,   269,     3,   271,     3,   273,     3,   275,
     306,   277,     3,   279,     3,   281,   161,   283,  1212,     7,
     162,   177,   166,     3,     3,     3,     3,     3,     3,   262,
       3,     3,    79,     4,     3,     3,     3,     3,     3,   110,
      72,     3,     3,     7,     7,   165,     3,     7,     3,     3,
       3,   902,     3,     3,     3,     3,    56,    58,  1252,     4,
     218,     7,   219,    10,   106,     7,     7,     7,     7,     7,
       7,     3,     3,   111,     3,    84,     3,     3,     3,     7,
       4,    11,   308,   193,     7,     7,     7,     7,     7,     7,
     799,   152,   221,     3,     3,     3,     3,     3,     3,     3,
       3,   158,   112,  1297,   195,     3,     3,    77,     7,    11,
      11,     7,     7,     3,     3,   955,     3,     3,     3,     7,
       3,     3,   203,     3,     3,  1319,   113,     3,     3,   233,
      82,   235,     3,   237,     3,   239,   163,   241,   205,   243,
    1334,   245,     7,   247,     7,   249,   195,   251,   168,   253,
      85,   255,   197,   257,     7,   259,     7,   261,     7,   263,
       3,   265,   120,   267,  1330,   269,   270,   271,     3,   273,
     114,   275,     3,   277,    90,   279,     3,   281,   207,   283,
     113,   195,   204,     3,   220,   197,    18,     3,     3,     7,
       7,     3,     3,   209,   197,   199,   198,   114,   196,   195,
       3,   115,     3,   222,    18,     3,   198,   122,     7,   195,
       7,   124,   197,   196,     7,   115,  1382,   211,   233,   201,
     235,     3,   237,    18,   239,     3,   241,   121,   243,  1395,
     245,     3,   247,   169,   249,    11,   251,     7,   253,     7,
     255,     3,   257,   199,   259,     3,   261,     7,   263,   123,
     265,   210,   267,     3,   269,    11,   271,   272,   273,   233,
     275,   235,   277,   237,   279,   239,   281,   241,   283,   243,
      11,   245,     7,   247,     4,   249,     3,   251,   212,   253,
     125,   255,    11,   257,   195,   259,   198,   261,   262,   263,
     233,   265,   235,   267,   237,   269,   239,   271,   241,   273,
     243,   275,   245,   277,   247,   279,   249,   281,   251,   283,
     253,     3,   255,   197,   257,   196,   259,     7,   261,   196,
     263,   213,   265,   201,   267,   197,   269,   195,   271,   199,
     273,   192,   275,   199,   277,   160,   279,   196,   281,   201,
     283,   198,   197,   201,   198,     3,   196,   214,   200,     3,
     198,   198,   196,   163,   200,   163,    11,     7,     3,   994,
     216,   821,  1105,   822,   354,  1051,   430,   822,   822,  1090,
     822,   822,   822,  1135,  1186,  1271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1382,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1395
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   320,   324,    26,   325,     0,   228,   789,     3,
     326,   230,   790,    29,   336,   337,     7,    25,    27,   327,
     328,     3,   791,    32,   343,   344,    31,   338,   521,     3,
     330,     7,   229,   231,   793,    66,   407,   408,    34,   345,
     522,     3,    10,    11,   339,   340,   341,    11,    10,    11,
      18,    19,    20,   314,   329,   331,   332,   333,   334,   335,
       3,    18,   794,   101,   463,   464,   409,     3,    10,    11,
     346,   347,   348,     7,   342,    28,     3,     3,     3,     3,
      11,     3,    11,    13,    14,   321,    10,    11,   465,   466,
     467,    10,    11,   410,   411,   412,     7,   349,     3,    30,
     164,   575,   576,     7,     7,     7,   546,   548,     7,   233,
     235,   237,   239,   241,   243,   245,   247,   249,   251,   253,
     255,   257,   259,   261,   263,   265,   267,   269,   271,   273,
     275,   277,   279,   281,   283,   795,   796,   798,   800,   802,
     804,   806,   808,   811,   814,   817,   820,   823,   825,   827,
     829,   831,   833,   835,   837,   839,   841,   844,   847,   857,
     865,    12,   322,   323,   102,   103,   468,   469,   512,   513,
      68,   413,   414,     3,    33,    35,    37,    41,    43,    45,
      47,    49,   350,   351,   352,   357,   358,   363,   364,   369,
     370,   375,   376,   381,   382,   394,   395,   577,   578,     3,
       3,     3,     3,     7,     8,   315,   316,   317,   318,   549,
       3,   807,   799,   801,   805,   824,   826,   809,   821,   834,
     803,   840,   828,   830,   832,   858,   836,   838,   815,   812,
     818,   842,   845,   797,   848,   866,   867,   792,   102,   107,
     470,   102,   126,    73,   425,   426,    70,   415,   525,   353,
     354,   359,   360,   365,   366,   371,   372,   377,   378,   383,
     384,   396,   397,    10,    11,   583,   584,   585,    21,    22,
     173,   178,   179,   579,   580,   581,   582,   782,   784,   548,
     548,   795,   795,   795,   795,   795,   795,   810,   822,   795,
     795,   795,   795,   795,   795,   861,   795,   795,   816,   813,
     819,    10,    11,   843,    10,    11,   846,   795,   850,   164,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   307,   309,   868,   869,   872,   873,   875,   876,   878,
     879,   881,   882,   884,   885,   888,   889,   893,   894,   896,
     897,   899,   900,   902,   903,   905,   906,   908,   909,   911,
     912,   868,   232,     3,   471,   472,   473,   515,    78,   442,
     443,    75,   427,   526,     3,   416,   418,    10,    11,   356,
      21,   178,   179,   355,   523,   524,   530,    10,    11,   362,
     361,   523,   524,   530,    10,    11,   368,    59,    60,    61,
     367,   523,   524,   530,   532,   533,   534,    10,    11,   374,
      62,    63,   373,   523,   524,   530,   532,   533,   535,   536,
      10,    11,   380,    65,   379,   523,   524,   530,   537,    55,
     386,   387,   388,   385,   523,   524,   530,    57,   399,   400,
     401,   398,   523,   524,   530,   167,   586,   587,   588,     4,
       4,     4,     3,     3,   795,   795,   795,   795,   242,   244,
     246,   795,   248,   795,   250,   252,   795,   256,   258,   260,
      10,    11,    18,   314,   859,   862,   863,   864,   264,   266,
     268,   795,   270,   795,   272,   795,   274,   276,   795,    10,
      11,    22,    23,   313,   849,   851,   852,   854,   856,   870,
     282,   868,   874,   868,   877,   795,   880,   868,   883,   312,
     886,   892,   890,   892,    10,    11,   895,   868,   898,   868,
     901,   868,   904,   795,   907,   868,   910,   795,   913,   284,
       7,   104,   472,   105,    10,    11,   108,   109,   514,   516,
     518,   519,    86,   455,   456,    80,   444,   527,     3,   428,
     430,     7,    10,    11,    71,   417,   419,   420,    36,     4,
       3,     3,    38,    42,     3,     3,     3,    44,     3,     3,
      46,     4,    10,    11,   393,   152,   389,   520,    10,    11,
     406,   402,   520,   165,   605,   589,   590,     3,     3,     3,
       7,     7,   234,   236,   238,   240,   795,   262,   795,     3,
       3,   278,   280,     4,     3,     4,    18,    91,   538,   286,
     868,   290,   292,     4,   868,   887,   868,   891,   298,   868,
     868,   868,   868,   795,   795,     3,    21,   474,   127,     3,
       3,    67,    88,   457,   529,     3,   445,   447,     7,    10,
      11,    76,   429,   431,   432,     3,    69,   421,   422,     3,
       7,     7,   546,     7,     7,     7,     7,     3,    48,   547,
     548,   157,   390,   391,   550,   551,   558,    50,   403,   404,
     550,   170,   191,   217,   606,   607,   608,   748,   749,   751,
     752,    10,    11,   604,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,     3,     3,   254,
     860,     7,   546,   853,   546,   855,     3,     3,    10,    11,
     871,   288,     3,   294,   296,   300,   302,   304,   306,   795,
     310,    11,     4,    10,    11,   475,   546,   546,     3,    10,
      11,   458,   459,   460,     7,    10,    11,    81,   446,   448,
     449,     3,    74,   433,   434,    10,    11,   424,    92,    93,
      94,    95,    96,   423,   530,   538,   539,   541,   542,   543,
     545,     3,     3,     3,     3,     3,     3,     3,     7,     3,
     161,   786,    10,    11,   392,   162,   552,   553,    10,    11,
     405,   223,   224,   609,   610,   611,   612,   868,   177,   753,
     781,   166,     3,     3,     3,     3,     3,     3,     3,     3,
       4,   262,     3,     3,     3,     3,     3,     7,     7,   165,
     795,     3,   110,   476,   477,     3,     3,     7,   461,     3,
      79,   450,   451,   436,   438,    83,    97,    98,    99,   435,
     528,   530,   531,   538,   540,   544,   545,    72,     3,     3,
       3,     3,     3,   547,     3,    10,    11,   559,   560,   561,
      56,   554,   555,    58,     4,    10,   613,   614,   218,   750,
     547,   219,   754,   755,   756,     7,     7,     7,     7,     7,
       7,     7,   546,   547,     3,     3,   795,   478,   106,   111,
     489,     3,    87,    89,   462,   438,   453,   452,   528,   530,
     531,   538,   539,   541,   542,   543,   545,    10,    11,   437,
      84,   439,   440,     3,     3,     3,     4,     7,     7,     7,
       7,     7,     7,     5,   158,    11,   557,   159,   160,   556,
     787,   788,   547,   193,   615,   617,   618,     7,   221,   762,
     763,   152,   757,   783,     3,     3,     3,     3,     3,     3,
       3,     3,   308,    10,    11,   116,   119,   479,   480,   481,
     482,   483,   490,   112,   501,    11,    10,    11,   454,    77,
      11,   868,     7,     7,     7,     3,     3,     3,     3,     3,
       3,     3,   158,     7,     3,     3,   203,   628,   629,   195,
     619,   620,   621,   547,   769,   764,   783,     3,    10,    11,
     758,   759,   760,   113,   484,   485,   486,     3,     3,    10,
      11,   117,   119,   491,   492,   493,   494,   495,   502,   795,
      82,    85,   441,     3,     3,     3,   163,     7,     7,   205,
     639,   640,   195,   630,   631,   632,   197,   626,   627,    10,
      11,   622,   623,   624,   168,   770,   771,    10,    11,   765,
     766,   767,     7,   550,   761,   113,   485,   120,     7,     7,
     114,   496,   497,   498,     3,     3,    10,    11,   118,   119,
     503,   504,   505,   506,   517,    90,     3,     3,   207,   679,
     680,   195,   641,   642,   643,   204,   197,   637,   638,    10,
      11,   633,   634,   635,   567,   568,   783,   550,   625,   772,
     773,   550,   768,     3,   220,    18,   487,     3,     3,   114,
     497,   122,     7,     7,   115,   507,   508,   509,     3,     3,
     209,   710,   711,   195,   681,   682,   683,   197,   648,   649,
      10,    11,   644,   645,   646,   571,   572,   783,   550,   636,
     198,   199,   569,   196,    10,    11,   777,   778,   779,   225,
     226,   580,   774,   775,   776,   222,     3,    10,    11,   488,
      18,   499,     3,     3,   115,   508,   124,     7,     7,   211,
     721,   722,   195,   712,   713,   714,   197,   688,   689,    10,
      11,   684,   685,   686,   650,   783,   550,   647,   198,   199,
     573,   196,   551,   201,   570,   169,   587,   780,   547,   547,
       7,   121,     3,    10,    11,   500,    18,   510,     3,     3,
     213,   732,   733,   195,   723,   724,   725,   210,   197,   719,
     720,    10,    11,   715,   716,   717,   690,   783,   550,   687,
      11,   651,   196,   551,   201,   574,   200,   562,   605,   169,
       7,     7,     3,     7,   123,     3,    10,    11,   511,    11,
     616,   174,   175,   734,   735,   736,   737,   212,   197,   730,
     731,    10,    11,   726,   727,   728,   571,   550,   718,    11,
     691,   196,   199,   652,   653,   654,   200,   551,   162,   202,
     563,   564,   547,   547,     3,     7,   125,   192,     4,   195,
     738,   739,   740,   571,   550,   729,   198,   196,   199,   692,
     693,   694,   198,   201,   659,   660,    10,    11,   655,   656,
     657,   202,   565,   788,     3,   547,   214,   197,   746,   747,
     741,   783,   198,   196,   198,   201,   699,   700,    10,    11,
     695,   696,   697,    10,    11,   661,   662,   663,   550,   658,
      11,   566,   571,    10,    11,   742,   743,   744,    10,    11,
     701,   702,   703,   550,   698,   664,   200,   546,   198,   550,
     745,   704,   200,   162,   202,   665,   666,   163,   196,   162,
     202,   705,   706,   667,   668,    10,    11,   707,   708,   709,
      10,    11,   671,   672,   673,   176,   180,   669,   670,   785,
     795,   674,     3,   547,   163,   163,   215,   675,   676,   546,
       7,   314,   677,     3,   547,     3,    11,   678,   546,     7,
       3,   216
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
            parserData->parser_errors += ("\n\nOSiL input is either not valid or well formed.\n"); 
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
if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();}
    break;

  case 13:

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

  case 14:

    {
    if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= parserData->qtermcount )
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many QuadraticTerms");
}
    break;

  case 19:

    { if(parserData->qtermidxOneattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxOne attributes"); 
            parserData->qtermidxOneattON = true;  }
    break;

  case 20:

    { if(parserData->qtermidxTwoattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idxTwo attributes"); 
            parserData->qtermidxTwoattON = true;  }
    break;

  case 21:

    { if(parserData->qtermcoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm coef attributes"); 
            parserData->qtermcoefattON = true;  }
    break;

  case 22:

    { if(parserData->qtermidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many qTerm idx attributes"); 
            parserData->qtermidxattON = true;  }
    break;

  case 23:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 24:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 25:

    {if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = parserData->tempVal;}
    break;

  case 26:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 29:

    {
#ifdef DEBUG
    yydebug = 1;
#endif
}
    break;

  case 253:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 260:

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

  case 261:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 262:

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

  case 265:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 266:

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

  case 268:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 273:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 278:

    {
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

  case 279:

    {
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 280:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    break;

  case 281:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }
    break;

  case 286:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 288:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stagevarcount++;
}
    break;

  case 292:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 297:

    {
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

  case 298:

    {
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 299:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    break;

  case 300:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }
    break;

  case 305:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 307:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageconcount++;
}
    break;

  case 310:

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

  case 311:

    {
      parserData->stageObjectivesON = true;
    }
    break;

  case 316:

    {
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

  case 317:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    break;

  case 318:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }
    break;

  case 323:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 325:

    {
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageobjcount++;
}
    break;

  case 328:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 329:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}
    break;

  case 334:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    break;

  case 335:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }
    break;

  case 336:

    {
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 337:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 338:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}
    break;

  case 339:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOfEl = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 340:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    parserData->numberOfMatricesPresent = true;
    parserData->numberOfMatrices = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 341:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfConesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <cone> elements cannot be negative");
    parserData->numberOfConesPresent = true;
    parserData->numberOfCones = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 342:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of rows cannot be negative");
    parserData->numberOfRowsPresent = true;
    parserData->numberOfRows = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 343:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of columns cannot be negative");
    parserData->numberOfColumnsPresent = true;
    parserData->numberOfColumns = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 344:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 345:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 346:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 347:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix terms cannot be negative");
    parserData->numberOfMatrixTerms = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 348:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
    parserData->numberOfMatrixExpr = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 349:

    {
    if (parserData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->namePresent = true;
    parserData->name = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 350:

    {
    if (parserData->shapePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "shape attribute previously set");
    parserData->shapePresent = true;
    parserData->shape = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 351:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->normScaleFactorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "normScaleFactor attribute previously set");
    if (parserData->tempVal <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "scale factor must be positive");
    parserData->normScaleFactorPresent = true;
    parserData->normScaleFactor = parserData->tempVal; 
}
    break;

  case 352:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->distortionMatrixPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "distortionMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "distortion matrix index cannot be negative");
    parserData->distortionMatrixPresent = true;
    parserData->distortionMatrix = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 353:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->axisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->axisDirectionPresent = true;
    parserData->axisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 354:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->firstAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "firstAxisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->firstAxisDirectionPresent = true;
    parserData->firstAxisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 355:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->secondAxisDirectionPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "secondAxisDirection attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "axis direction index cannot be negative");
    parserData->secondAxisDirectionPresent = true;
    parserData->secondAxisDirection = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 356:

    {
    if (parserData->semidefinitenessPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->semidefinitenessPresent = true;
    if ((yyvsp[(2) - (3)].sval) != "true" && (yyvsp[(2) - (3)].sval) != "false")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "semidefiniteness must be either \"true\" or \"false \"");
    else
        parserData->semidefiniteness = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 357:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->matrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index cannot be negative");
    parserData->matrixIdxAttributePresent = true;
    parserData->matrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 358:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->lbMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lbMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lower bounding matrix index cannot be negative");
    parserData->lbMatrixIdxAttributePresent = true;
    parserData->lbMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 359:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->constantMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constantMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index cannot be negative");
    parserData->constantMatrixIdxAttributePresent = true;
    parserData->constantMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 360:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->lbConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lbConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lower bounding cone index cannot be negative");
    parserData->lbConeIdxAttributePresent = true;
    parserData->lbConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 361:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->ubMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "upper bounding matrix index cannot be negative");
    parserData->ubMatrixIdxAttributePresent = true;
    parserData->ubMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 362:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->ubConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "upper bounding cone index cannot be negative");
    parserData->ubConeIdxAttributePresent = true;
    parserData->ubConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 363:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->orderConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "order cone index cannot be negative");
    parserData->orderConeIdxAttributePresent = true;
    parserData->orderConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 364:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->patternMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "patternMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "pattern matrix index cannot be negative");
    parserData->patternMatrixIdxAttributePresent = true;
    parserData->patternMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 365:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 366:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 374:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 379:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 385:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
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
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 391:

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

  case 395:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 398:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
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
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 399:

    {
}
    break;

  case 400:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
    {
        osglData->osglIntArray = new    int[parserData->numberOf];
        osglData->osglDblArray = new double[parserData->numberOf];
    }
}
    break;

  case 403:

    {
}
    break;

  case 404:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
    {
        osglData->osglIntArray = new int[parserData->numberOf];
        osglData->osglValArray = new int[parserData->numberOf];
    }
}
    break;

  case 408:

    {
    //osglData->...;
}
    break;

  case 416:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        if (verifyMatrixType(osglData->matrixTypeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 417:

    { 
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 418:

    { 
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 419:

    { 
    if (osglData->matrixTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->matrixTypeAttributePresent = true;   
    osglData->matrixTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 440:

    { 
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    osglData->baseMatrixIdxAttributePresent = true;   
    osglData->baseMatrixIdxAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 441:

    { 
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 442:

    { 
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 443:

    { 
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 444:

    { 
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 445:

    { 
    if (osglData->baseMatrixEndRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row cannot be negative");
    osglData->baseMatrixEndRowAttributePresent = true;   
    osglData->baseMatrixEndRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 446:

    { 
    if (osglData->baseMatrixEndColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col cannot be negative");
    osglData->baseMatrixEndColAttributePresent = true;   
    osglData->baseMatrixEndColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 447:

    { 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
}
    break;

  case 450:

    {
    osglData->baseTransposeAttribute = true;
}
    break;

  case 451:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->baseTransposeAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->baseTransposeAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 452:

    {
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
}
    break;

  case 466:

    {
    osglData->rowMajorAttribute = true;
}
    break;

  case 467:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->rowMajorAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->rowMajorAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 476:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 477:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 483:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglDblArray;
    osglData->osglDblArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 484:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 489:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 490:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 496:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 497:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 502:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 503:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 509:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 510:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 511:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 515:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 516:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 524:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 532:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 538:

    {
}
    break;

  case 546:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
}
    break;

  case 548:

    {
}
    break;

  case 549:

    {
}
    break;

  case 554:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 555:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 561:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 562:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 563:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 567:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 568:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 576:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 584:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 593:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 594:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 600:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 601:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 606:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 607:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 613:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 614:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 622:

    {
    osglData->excludeIfSetAttribute = true;
}
    break;

  case 623:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->excludeIfSetAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->excludeIfSetAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->excludeIfSetAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "excludeIfSet attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 625:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 626:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 627:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 633:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    delete[] osglData->osglValArray;
    osglData->osglValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 634:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 642:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set <blocks> colOffsets failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 643:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 644:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 650:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set <blocks> rowOffsets failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 651:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 652:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 667:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 668:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
    osglData->blockRowIdxAttributePresent = true;        
    osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 669:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
    osglData->blockColIdxAttributePresent = true;        
    osglData->blockColIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 676:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 677:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 678:

    {
    if (osglData->numberOfElAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElAttributePresent = true;        
    osglData->numberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 679:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 680:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 681:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 682:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 683:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 685:

    {  if (osnlData->nlnodecount < osnlData->tmpnlcount)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   }
    break;

  case 686:

    { if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osnlData->tmpnlcount = (yyvsp[(3) - (5)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
    osinstance->instanceData->nonlinearExpressions->nl[ i] = new Nl();
}
}
    break;

  case 688:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
    osnlData->nlNodeVec[ 0]->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    osnlData->nlnodecount++;
}
    break;

  case 690:

    {
    if(osnlData->nlnodecount >= osnlData->tmpnlcount) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
}
    break;

  case 691:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
//osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
// clear the vectors of pointers
osnlData->nlNodeVec.clear();
osnlData->sumVec.clear();
//osnlData->allDiffVec.clear();
osnlData->maxVec.clear();
osnlData->minVec.clear();
osnlData->productVec.clear();
}
    break;

  case 717:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 719:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 721:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 723:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 725:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 727:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 729:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 730:

    {
    osnlData->sumVec.back()->m_mChildren = new OSnLNode*[ osnlData->sumVec.back()->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 732:

    { osnlData->sumVec.back()->inumberOfChildren++; }
    break;

  case 733:

    {
    
    osnlData->nlNodePoint =   new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 734:

    {
    osnlData->allDiffVec.back()->m_mChildren = new OSnLNode*[ osnlData->allDiffVec.back()->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 736:

    { osnlData->allDiffVec.back()->inumberOfChildren++; }
    break;

  case 737:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 738:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 740:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 741:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 742:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 744:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 745:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 746:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 748:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 749:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 751:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 753:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 755:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 757:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 759:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 761:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 762:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 763:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 764:

    {
}
    break;

  case 765:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 766:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 767:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 771:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 775:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 776:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 781:

    {if(osnlData->numbertypeattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
            osnlData->numbertypeattON = true; }
    break;

  case 782:

    {if(osnlData->numbervalueattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
            osnlData->numbervalueattON = true; }
    break;

  case 783:

    {if(osnlData->numberidattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
            osnlData->numberidattON = true; }
    break;

  case 784:

    {
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 786:

    {
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 788:

    {/*if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");*/
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 789:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 790:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 792:

    {
    osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
    osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 797:

    {if(osnlData->variablecoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; }
    break;

  case 798:

    {if(osnlData->variableidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
            }
    break;

  case 799:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 800:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 801:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 803:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 819:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->OSnLMNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 820:

    {osnlData->matrixidxattON = false;}
    break;

  case 823:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 825:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 828:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 831:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 834:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 837:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 842:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 846:

    { 
    osnlData->includeDiagonalAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 848:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 852:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 855:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 858:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 861:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 864:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 867:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
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

#if 0
void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, const char* errormsg ) {
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
	outStr << error << endl;
	outStr << endl; 
	outStr << "See line number: " << osilget_lineno( scanner) << endl; 
	outStr << "The offending text is: " << osilget_text ( scanner ) << endl; 
	error = outStr.str();
	//osillex_destroy(scanner);
	throw ErrorClass( error);
}//end osilerror()
#endif 

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
		 *	we have done so without bison and just moved the pointer on osil to point to what is past
		 *	the linear part	
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
	const char *endInstanceHeader = "</instanceHeader";
	const char *startName = "<name";
	const char *endName = "</name";
	const char *startSource = "<source";
	const char *endSource = "</source";
	const char *startDescription = "<description";
	const char *endDescription = "</description";
	const char *startFileCreator = "<fileCreator";
	const char *endFileCreator = "</fileCreator";
	const char *startLicence = "<licence";
	const char *endLicence = "</licence";
	const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
	char *pelementText = NULL;
	const char *ptemp = NULL;
	int elementSize;
	if(pinstanceHeadStart == NULL ) {
		const char *startInstanceData = "<instanceData";
		*p = strstr(pchar, startInstanceData);
		return true;
	}
	//if(pinstanceHeadStart == NULL) {  osilerror_wrapper( pchar,osillineno,"<instanceHeader> element missing"); return false;}
	// increment the line number counter if there are any newlines between the start of
	// the osil string and pinstanceHeadStart
	int	kount = pinstanceHeadStart - pchar;
	while( kount-- > 0) if(*(pchar++) == '\n') 	(*osillineno)++;
	// important! pchar now points to the '<' in <instanceHeader
	// that is both pinstanceHeadStart and pchar point to the same thing
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
	//
	//
	// process the <name> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <name element if there -- it is not required
	//remember where we are
	*p = pchar;
	while(*startName++  == *pchar) pchar++;
	if( (pchar - *p)  != 5) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a name element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
			pchar++;
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
			pchar++;
			// process <name> element text
			// there better be a </name
			ptemp = strstr( pchar, endName);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->name = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </name
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </name
			// move to first char after </name
			pchar += 6;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of name
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); return false;}
		}
	}// end of else after discovering a name element
	//done processing name element
	//
	//
	// process the <source> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <source element if there -- it is not required
	*p = pchar;
	while(*startSource++  == *pchar) pchar++;
	if(pchar - *p != 7) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a source element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); return false;}
			pchar++;
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); return false;}
			pchar++;
			// process <source> element text
			// there better be a </source
			ptemp = strstr( pchar, endSource);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->source = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </source
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </source
			// move to first char after </source
			pchar += 8;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of source
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); return false;}
		}
	}// end of else after discovering a source element
	//done processing <source> element
	//
	//
	//process the <description> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <description element if there -- it is not required
	*p = pchar;
	while(*startDescription++  == *pchar) pchar++;
	if( (pchar - *p) != 12) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a description element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); return false;}
			pchar++;
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); return false;}
			pchar++;
			// process <description> element text
			// there better be a </description
			ptemp = strstr( pchar, endDescription);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->description = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </description
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </description
			// move to first char after </description
			pchar += 13;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of </description>
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); return false;}
		}
	}// end of else after discovering a description element
	//done processing <description> element

	//
	//
	//process the <fileCreator> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <fileCreator element if there -- it is not required
	*p = pchar;
	while(*startFileCreator++  == *pchar) pchar++;
	if( (pchar - *p) != 12) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a fileCreator element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element"); return false;}
			pchar++;
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <fileCreator> element"); return false;}
			pchar++;
			// process <fileCreator> element text
			// there better be a </fileCreator
			ptemp = strstr( pchar, endFileCreator);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->fileCreator = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </description
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </fileCreator
			// move to first char after </fileCreator
			pchar += 13;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of </fileCreator>
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </fileCreator> element"); return false;}
		}
	}// end of else after discovering a fileCreator element
	//done processing <fileCreator> element
	//
	//
	//process the <licence> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <licence element if there -- it is not required
	*p = pchar;
	while(*startLicence++  == *pchar) pchar++;
	if( (pchar - *p) != 8) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a licence element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element"); return false;}
			pchar++;
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <licence> element"); return false;}
			pchar++;
			// process <licence> element text
			// there better be a </licence
			ptemp = strstr( pchar, endLicence);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->licence = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </licence
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </licence
			// move to first char after </licence
			pchar += 9;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of </description>
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </licence> element"); return false;}
		}
	}// end of else after discovering a licence element
	//done processing <licence> element


	//
	// if we are here there must be an </instanceHeader > element
	// burn the whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// we should be pointing to </instanceHeader
	*p = pchar;
	while(*endInstanceHeader++  == *pchar) pchar++;
	if( (pchar - *p) != 16) {  osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); return false;}	
	// pchar now points to the first character after </instanceHeader
	// get rid of white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); return false;}	
	pchar++;
	*p = pchar;
	return true;
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
		if( parseVariables( p, osinstance, osillineno) != true) {throw ErrorClass("error in parseVariables");}
		if( parseObjectives( p, osinstance, osillineno) != true)  throw ErrorClass("error in parseObjectives");
		if( parseConstraints( p, osinstance, osillineno) != true) throw ErrorClass("error in parseConstraints");
		if( parseLinearConstraintCoefficients( p, osinstance, osillineno) != true) throw ErrorClass("error in parseLinearConstraintCoefficients");
	}else{
		//osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); 
		return true;
	}
	//for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// we should be pointing to the '<' char in <variables>
	//*p = pchar;	
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
			varlbattON  = false;
			varubattON = false ;
			vartypeattON  = false;
			varnameattON = false ;
			//varinitattON = false ; 
			//varinitStringattON = false ;
			varmultattON = false;
			varmult = 1;
			foundVar = false;
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
					//printf("ATTRIBUTE = %s\n", attText);
					break;
					/*
				case 'i':
					*p = ch;
					while(*initString++  == *ch) ch++;
					// if i < 4 there is an error
					// if i = 4 we matched init
					// if i = 10 we matched initString
					if( ( (ch - *p) != 4)  && ( (ch - *p) != 10)) {  osilerror_wrapper( ch,osillineno,"error in variables init or initString attribute"); return false;}
					if((ch - *p) == 4){
						if(varinitattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable init attributes"); return false;}
						varinitattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->variables->var[varcount]->init=atofmod1( osillineno,attText, attTextEnd);
						delete [] attText;
						initString -= 5;
					}
					else{
						if(varinitStringattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable initString attributes"); return false;}
						varinitStringattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->variables->var[varcount]->initString=attText;
						delete [] attText;
						initString -= 11;
					}
					break;
					*/
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
					if (vt == ENUM_VARTYPE_BINARY) osinstance->instanceData->variables->var[varcount]->ub = 1.0;
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
					//printf("ATTRIBUTE = %s\n", attText);
					break;
				case 'u':
					ch++;
					if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables upper bound attribute"); return false;}
					if(varubattON == true) {  osilerror_wrapper( ch,osillineno,"too many variable ub attributes"); return false;}
					varubattON = true;
					GETATTRIBUTETEXT;
					osinstance->instanceData->variables->var[varcount]->ub = atofmod1( osillineno,attText, attTextEnd);
					delete [] attText;
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
	// find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
	// However if the  number attribute is missing assume it is	1 
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
						//printf("ATTRIBUTE = %s\n", attText);
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
						//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
						//printf("ATTRIBUTE = %s\n", attText);
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
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
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
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				if( ((ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {  osilerror_wrapper( ch,osillineno,"too many con constant attributes"); return false;}
				constant -= 9;
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
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
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in constraint ub attribute"); return false;}
				if(conubattON == true) {  osilerror_wrapper( ch,osillineno,"too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
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
				//printf("ATTRIBUTE = %s\n", attText);
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
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag");	return false;}
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
//	if( (parseColIdx( &ch, osinstance, osillineno) != true) && (parseRowIdx( &ch, osinstance, osillineno) != true)) return false;
//	if( (parseColIdx( &ch, osinstance, osillineno) == true) && (parseRowIdx( &ch, osinstance, osillineno) == true)) {osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); return false;}

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
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
			//printf("number = %s\n", *p);
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
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </start> tag");	return false;}
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
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
			//printf("number = %s\n", *p);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
			//printf("number = %s\n", *p);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
					//printf("ATTRIBUTE = %s\n", attText);
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
			//printf("number = %s\n", *p);
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
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </value> tag");	 return false;}
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
	if(numberOfObjCoef > 0)	{
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
		if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect <coef> element")	; return false;}	
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
		if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect </coef> element")	; return false;}
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
	/**
	double power;
	int i;
	int sign = 1;
	int expsign, exppower, exptest;
	int endWhiteSpace;
	// modified atof from Kernighan and Ritchie
	for(i = 0;  ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	endWhiteSpace = i;
	for(val = 0.0; ISDIGIT( number[ i]); i++){
		val = 10.0 *val + (number[ i] - '0') ;
	}
	if (number[ i] == '.') {
		i++;
		for (power = 1.0; ISDIGIT(number[ i]); i++){
			val = 10.0*val + (number[ i] - '0');
			power *= 10.0;
		}
		val = val/power;
	}
	if(i == endWhiteSpace) {
	// we better have INF or NaN
		switch (number[ i]){
		case 'I':
			i++;
			if(number[ i++] == 'N' && number[i++] == 'F'){
				val = OSDBL_MAX;
				break;
			}
			else{
				  
				osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNaN();
				break;
			}
			else{
				  
				osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
				
			}

		default:
			  
			osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
			
			break;
		}
	}
	else{
		if(number[i] == 'e' || number[i] == 'E' ){
			i++;
			// process exponential part of the term
			// we have ([eE][-+]?[0-9]+)?
			// we are not going to process a NAN or INF
			expsign = (number[ i] == '-') ? -1 : 1;
			if (number[ i] == '+' || number[ i] == '-') i++;
			// get the exponent power 
			//
			exptest = i;
			for(exppower = 0 ; ISDIGIT( number[ i]); i++){
				exppower = 10 *exppower + (number[ i] - '0') ;
			}
			if(i == exptest) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:double"); 	}
			val = val*pow(10.0, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	if(number[i] == *numberend){
		return sign*val;
	}
	else {  osilerror_wrapper( number,osillineno,"error in parsing an XSD:double"); 	return OSNaN();}
	*/
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
	if(i == endWhiteSpace) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int" ); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	if(number[i] == *numberend){
		return sign*ival;
	}
	else {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int"); return OSINT_MAX;	}
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


