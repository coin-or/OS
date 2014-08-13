
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
     MATRIXDETERMINANTSTART = 536,
     MATRIXDETERMINANTEND = 537,
     MATRIXTRACESTART = 538,
     MATRIXTRACEEND = 539,
     MATRIXTOSCALARSTART = 540,
     MATRIXTOSCALAREND = 541,
     MATRIXDIAGONALSTART = 542,
     MATRIXDIAGONALEND = 543,
     MATRIXDOTTIMESSTART = 544,
     MATRIXDOTTIMESEND = 545,
     MATRIXIDENTITYSTART = 546,
     MATRIXIDENTITYEND = 547,
     MATRIXINVERSESTART = 548,
     MATRIXINVERSEEND = 549,
     MATRIXLOWERTRIANGLESTART = 550,
     MATRIXLOWERTRIANGLEEND = 551,
     MATRIXUPPERTRIANGLESTART = 552,
     MATRIXUPPERTRIANGLEEND = 553,
     MATRIXMERGESTART = 554,
     MATRIXMERGEEND = 555,
     MATRIXMINUSSTART = 556,
     MATRIXMINUSEND = 557,
     MATRIXPLUSSTART = 558,
     MATRIXPLUSEND = 559,
     MATRIXTIMESSTART = 560,
     MATRIXTIMESEND = 561,
     MATRIXSCALARTIMESSTART = 562,
     MATRIXSCALARTIMESEND = 563,
     MATRIXSUBMATRIXATSTART = 564,
     MATRIXSUBMATRIXATEND = 565,
     MATRIXTRANSPOSESTART = 566,
     MATRIXTRANSPOSEEND = 567,
     MATRIXREFERENCESTART = 568,
     MATRIXREFERENCEEND = 569,
     EMPTYINCLUDEDIAGONALATT = 570,
     INCLUDEDIAGONALATT = 571,
     IDATT = 572,
     COEFATT = 573
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
#define MATRIXDETERMINANTSTART 536
#define MATRIXDETERMINANTEND 537
#define MATRIXTRACESTART 538
#define MATRIXTRACEEND 539
#define MATRIXTOSCALARSTART 540
#define MATRIXTOSCALAREND 541
#define MATRIXDIAGONALSTART 542
#define MATRIXDIAGONALEND 543
#define MATRIXDOTTIMESSTART 544
#define MATRIXDOTTIMESEND 545
#define MATRIXIDENTITYSTART 546
#define MATRIXIDENTITYEND 547
#define MATRIXINVERSESTART 548
#define MATRIXINVERSEEND 549
#define MATRIXLOWERTRIANGLESTART 550
#define MATRIXLOWERTRIANGLEEND 551
#define MATRIXUPPERTRIANGLESTART 552
#define MATRIXUPPERTRIANGLEEND 553
#define MATRIXMERGESTART 554
#define MATRIXMERGEEND 555
#define MATRIXMINUSSTART 556
#define MATRIXMINUSEND 557
#define MATRIXPLUSSTART 558
#define MATRIXPLUSEND 559
#define MATRIXTIMESSTART 560
#define MATRIXTIMESEND 561
#define MATRIXSCALARTIMESSTART 562
#define MATRIXSCALARTIMESEND 563
#define MATRIXSUBMATRIXATSTART 564
#define MATRIXSUBMATRIXATEND 565
#define MATRIXTRANSPOSESTART 566
#define MATRIXTRANSPOSEEND 567
#define MATRIXREFERENCESTART 568
#define MATRIXREFERENCEEND 569
#define EMPTYINCLUDEDIAGONALATT 570
#define INCLUDEDIAGONALATT 571
#define IDATT 572
#define COEFATT 573




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
#define YYLAST   1189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  323
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  614
/* YYNRULES -- Number of rules.  */
#define YYNRULES  881
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1445

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   573

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   320,
     322,     2,     2,   321,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   319,     2,     2,     2,     2,     2,     2,     2,
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
     315,   316,   317,   318
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
     289,   293,   297,   299,   301,   303,   305,   307,   311,   313,
     315,   317,   321,   323,   325,   326,   329,   331,   333,   335,
     339,   343,   345,   347,   349,   351,   353,   357,   359,   361,
     363,   364,   367,   369,   371,   373,   375,   382,   383,   387,
     389,   391,   393,   395,   397,   401,   403,   404,   407,   411,
     413,   415,   416,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   438,   439,   443,   445,   447,   449,   451,   453,
     457,   459,   460,   463,   467,   469,   471,   472,   475,   477,
     479,   481,   483,   485,   487,   489,   491,   493,   495,   499,
     501,   503,   504,   507,   511,   514,   516,   517,   521,   523,
     525,   527,   529,   531,   535,   537,   538,   541,   545,   547,
     549,   550,   553,   555,   557,   559,   561,   563,   565,   567,
     569,   571,   573,   575,   577,   581,   583,   585,   586,   590,
     592,   594,   596,   598,   600,   604,   605,   608,   614,   619,
     620,   623,   625,   627,   629,   631,   634,   638,   642,   647,
     649,   655,   657,   660,   661,   666,   667,   671,   673,   677,
     681,   682,   686,   687,   690,   692,   694,   699,   704,   706,
     710,   712,   715,   717,   720,   721,   726,   731,   733,   736,
     737,   741,   742,   745,   747,   749,   754,   759,   761,   765,
     767,   770,   772,   775,   776,   781,   786,   788,   791,   792,
     796,   797,   800,   802,   804,   809,   811,   815,   817,   820,
     822,   825,   826,   831,   836,   838,   841,   842,   847,   849,
     852,   853,   856,   858,   860,   865,   870,   875,   880,   885,
     890,   895,   900,   905,   910,   915,   920,   925,   929,   933,
     938,   943,   948,   953,   958,   962,   967,   972,   977,   982,
     987,   992,   997,  1002,  1006,  1010,  1013,  1014,  1017,  1019,
    1021,  1023,  1025,  1027,  1029,  1030,  1033,  1037,  1039,  1041,
    1042,  1045,  1047,  1049,  1053,  1057,  1059,  1061,  1064,  1066,
    1070,  1071,  1074,  1078,  1080,  1081,  1083,  1087,  1092,  1094,
    1099,  1104,  1109,  1111,  1116,  1121,  1125,  1127,  1129,  1130,
    1133,  1135,  1137,  1139,  1141,  1143,  1147,  1151,  1155,  1157,
    1159,  1161,  1165,  1168,  1169,  1173,  1175,  1177,  1178,  1181,
    1183,  1185,  1187,  1189,  1191,  1193,  1195,  1197,  1199,  1204,
    1209,  1214,  1219,  1224,  1229,  1234,  1236,  1238,  1240,  1242,
    1246,  1251,  1254,  1256,  1257,  1260,  1262,  1264,  1266,  1270,
    1272,  1273,  1275,  1277,  1279,  1281,  1285,  1287,  1289,  1291,
    1301,  1303,  1304,  1308,  1310,  1314,  1317,  1319,  1321,  1323,
    1325,  1329,  1331,  1335,  1337,  1338,  1342,  1344,  1348,  1351,
    1353,  1355,  1357,  1359,  1363,  1365,  1369,  1371,  1372,  1375,
    1377,  1382,  1385,  1387,  1389,  1391,  1393,  1397,  1399,  1403,
    1405,  1407,  1411,  1414,  1415,  1418,  1420,  1422,  1424,  1426,
    1430,  1432,  1433,  1436,  1438,  1440,  1442,  1444,  1448,  1449,
    1452,  1456,  1458,  1460,  1461,  1464,  1466,  1468,  1473,  1475,
    1477,  1479,  1483,  1484,  1487,  1491,  1493,  1494,  1499,  1503,
    1504,  1507,  1509,  1514,  1517,  1519,  1521,  1523,  1525,  1529,
    1531,  1535,  1537,  1539,  1543,  1546,  1547,  1550,  1552,  1554,
    1556,  1558,  1562,  1564,  1565,  1568,  1570,  1572,  1574,  1576,
    1580,  1581,  1584,  1587,  1589,  1591,  1593,  1595,  1599,  1600,
    1604,  1606,  1610,  1613,  1615,  1617,  1619,  1621,  1625,  1627,
    1631,  1633,  1634,  1638,  1640,  1644,  1647,  1649,  1651,  1653,
    1655,  1659,  1661,  1665,  1667,  1668,  1673,  1675,  1676,  1678,
    1680,  1682,  1684,  1688,  1692,  1695,  1697,  1699,  1701,  1703,
    1707,  1709,  1715,  1717,  1722,  1724,  1726,  1730,  1732,  1734,
    1740,  1742,  1746,  1748,  1750,  1752,  1754,  1756,  1760,  1762,
    1766,  1768,  1770,  1772,  1774,  1776,  1780,  1782,  1783,  1786,
    1790,  1792,  1794,  1795,  1798,  1800,  1802,  1804,  1809,  1814,
    1816,  1818,  1821,  1823,  1827,  1830,  1835,  1840,  1845,  1850,
    1855,  1860,  1865,  1870,  1871,  1876,  1882,  1883,  1884,  1892,
    1894,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1915,
    1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1954,
    1960,  1961,  1967,  1968,  1974,  1975,  1980,  1981,  1987,  1988,
    1994,  1995,  2000,  2001,  2004,  2005,  2010,  2011,  2014,  2015,
    2020,  2021,  2024,  2025,  2030,  2031,  2034,  2035,  2040,  2041,
    2044,  2045,  2050,  2051,  2056,  2057,  2062,  2063,  2068,  2069,
    2074,  2075,  2080,  2081,  2086,  2087,  2092,  2093,  2100,  2101,
    2105,  2107,  2110,  2111,  2115,  2117,  2120,  2121,  2126,  2128,
    2131,  2132,  2135,  2137,  2139,  2141,  2142,  2147,  2148,  2153,
    2158,  2159,  2164,  2166,  2167,  2172,  2175,  2176,  2179,  2181,
    2183,  2188,  2193,  2194,  2199,  2200,  2205,  2206,  2211,  2213,
    2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,
    2235,  2237,  2239,  2240,  2245,  2247,  2250,  2255,  2258,  2260,
    2263,  2266,  2268,  2272,  2275,  2277,  2280,  2283,  2285,  2288,
    2292,  2294,  2295,  2297,  2300,  2304,  2306,  2307,  2309,  2312,
    2316,  2319,  2321,  2323,  2326,  2329,  2331,  2335,  2338,  2340,
    2344,  2347,  2349,  2353,  2356,  2358,  2362,  2365,  2367,  2374,
    2377,  2379
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     324,     0,    -1,   328,   809,   340,   347,   415,   483,   325,
     326,    -1,    14,    -1,    13,    -1,   327,    -1,    12,    -1,
      -1,    -1,    24,   329,   330,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   330,   331,    -1,   332,   334,   333,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   334,
     335,    -1,   336,    -1,   337,    -1,   338,    -1,   339,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     318,     3,   566,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   341,   342,   343,    -1,    29,    -1,   541,    -1,   344,
      -1,   345,    -1,    10,    -1,    11,   346,    30,    -1,    -1,
     346,   595,    -1,    -1,   348,   349,   350,    -1,    32,    -1,
     542,    -1,   351,    -1,   352,    -1,    10,    -1,    11,   353,
      33,    -1,    -1,   353,   354,    -1,   355,    -1,   361,    -1,
     367,    -1,   373,    -1,   379,    -1,   385,    -1,   400,    -1,
     356,   357,   360,    -1,    35,    -1,   358,    -1,    -1,   358,
     359,    -1,   543,    -1,   544,    -1,   550,    -1,    10,    -1,
      11,    36,    -1,   362,   363,   366,    -1,    37,    -1,   364,
      -1,    -1,   364,   365,    -1,   543,    -1,   544,    -1,   550,
      -1,    10,    -1,    11,    38,    -1,   368,   369,   372,    -1,
      41,    -1,   370,    -1,    -1,   370,   371,    -1,   543,    -1,
     544,    -1,   550,    -1,   553,    -1,   552,    -1,   554,    -1,
      10,    -1,    11,    42,    -1,   374,   375,   378,    -1,    43,
      -1,   376,    -1,    -1,   376,   377,    -1,   543,    -1,   544,
      -1,   550,    -1,   553,    -1,   552,    -1,   555,    -1,   556,
      -1,    10,    -1,    11,    44,    -1,   380,   381,   384,    -1,
      45,    -1,   382,    -1,    -1,   382,   383,    -1,   543,    -1,
     544,    -1,   550,    -1,   557,    -1,    10,    -1,    11,    46,
      -1,   386,   387,   390,    -1,    47,    -1,   388,    -1,    -1,
     388,   389,    -1,   543,    -1,   544,    -1,   550,    -1,    11,
     391,   399,    -1,   392,   393,   394,    -1,    55,    -1,   540,
      -1,   395,    -1,   396,    -1,    10,    -1,    11,   397,   398,
      -1,   570,    -1,    56,    -1,    48,    -1,   401,   402,   405,
      -1,    49,    -1,   403,    -1,    -1,   403,   404,    -1,   543,
      -1,   544,    -1,   550,    -1,    11,   406,   414,    -1,   407,
     408,   409,    -1,    57,    -1,   540,    -1,   410,    -1,   411,
      -1,    10,    -1,    11,   412,   413,    -1,   570,    -1,    58,
      -1,    50,    -1,    -1,   416,   417,    -1,    66,    -1,   418,
      -1,   419,    -1,    10,    -1,    11,   420,   434,   456,   474,
      67,    -1,    -1,   421,   422,   423,    -1,    68,    -1,   545,
      -1,   424,    -1,   425,    -1,    10,    -1,    11,   427,   426,
      -1,    69,    -1,    -1,   427,   428,    -1,   429,   430,   433,
      -1,    71,    -1,   431,    -1,    -1,   431,   432,    -1,   558,
      -1,   559,    -1,   561,    -1,   562,    -1,   563,    -1,   565,
      -1,   550,    -1,    10,    -1,    11,    72,    -1,    -1,   435,
     436,   437,    -1,    73,    -1,   546,    -1,   438,    -1,   439,
      -1,    10,    -1,    11,   441,   440,    -1,    74,    -1,    -1,
     441,   442,    -1,   443,   444,   447,    -1,    76,    -1,   445,
      -1,    -1,   445,   446,    -1,   558,    -1,   564,    -1,   560,
      -1,   565,    -1,   550,    -1,   551,    -1,   548,    -1,   448,
      -1,   449,    -1,    10,    -1,    11,   450,   451,    -1,   452,
      -1,    77,    -1,    -1,   452,   453,    -1,   454,   891,   455,
      -1,    84,    11,    -1,    85,    -1,    -1,   457,   458,   459,
      -1,    78,    -1,   547,    -1,   460,    -1,   461,    -1,    10,
      -1,    11,   463,   462,    -1,    79,    -1,    -1,   463,   464,
      -1,   465,   466,   469,    -1,    81,    -1,   467,    -1,    -1,
     467,   468,    -1,   558,    -1,   559,    -1,   561,    -1,   562,
      -1,   563,    -1,   565,    -1,   550,    -1,   551,    -1,   548,
      -1,   470,    -1,   471,    -1,    10,    -1,    11,   472,   473,
      -1,   452,    -1,    82,    -1,    -1,   475,   476,   477,    -1,
      86,    -1,   549,    -1,   478,    -1,   479,    -1,    10,    -1,
      11,   480,    87,    -1,    -1,   480,   481,    -1,    89,   482,
      11,   815,    90,    -1,    18,     3,     7,     3,    -1,    -1,
     484,   485,    -1,   101,    -1,   486,    -1,   487,    -1,    10,
      -1,    11,   102,    -1,    11,   488,   102,    -1,    11,   532,
     102,    -1,   489,   490,   491,   104,    -1,   103,    -1,   107,
       3,     7,     3,    11,    -1,   492,    -1,   491,   492,    -1,
      -1,   493,   105,   494,   495,    -1,    -1,    21,     4,     3,
      -1,    10,    -1,    11,   496,   106,    -1,   497,   509,   521,
      -1,    -1,   110,   498,   502,    -1,    -1,   498,   499,    -1,
     500,    -1,   501,    -1,   116,     3,     7,     3,    -1,   119,
       3,     7,     3,    -1,   503,    -1,    11,   504,   113,    -1,
      10,    -1,    11,   113,    -1,   505,    -1,   504,   505,    -1,
      -1,   506,   120,   507,   508,    -1,    18,     3,     7,     3,
      -1,    10,    -1,    11,   121,    -1,    -1,   111,   510,   514,
      -1,    -1,   510,   511,    -1,   512,    -1,   513,    -1,   117,
       3,     7,     3,    -1,   119,     3,     7,     3,    -1,   515,
      -1,    11,   516,   114,    -1,    10,    -1,    11,   114,    -1,
     517,    -1,   516,   517,    -1,    -1,   518,   122,   519,   520,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   123,
      -1,    -1,   112,   522,   525,    -1,    -1,   522,   523,    -1,
     524,    -1,   537,    -1,   118,     3,     7,     3,    -1,   526,
      -1,    11,   527,   115,    -1,    10,    -1,    11,   115,    -1,
     528,    -1,   527,   528,    -1,    -1,   529,   124,   530,   531,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   125,
      -1,    -1,   533,   126,   535,   534,    -1,    10,    -1,    11,
     127,    -1,    -1,   535,   536,    -1,   538,    -1,   539,    -1,
     119,     3,     7,     3,    -1,   108,     3,   566,     3,    -1,
     109,     3,   566,     3,    -1,   152,   567,     7,   567,    -1,
      31,     3,     7,     3,    -1,    34,     3,     7,     3,    -1,
     179,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
      70,     3,     7,     3,    -1,    75,     3,     7,     3,    -1,
      80,     3,     7,     3,    -1,    83,     3,     7,     3,    -1,
      88,     3,     7,     3,    -1,    21,     4,     3,    -1,    99,
       4,     3,    -1,    59,     3,   566,     3,    -1,    60,     3,
       7,     3,    -1,    61,     3,     7,     3,    -1,    62,     3,
       7,     3,    -1,    63,     3,     7,     3,    -1,    65,     4,
       3,    -1,    91,     3,     7,     3,    -1,    92,     3,     7,
       3,    -1,    98,     3,     7,     3,    -1,    93,     3,     7,
       3,    -1,    94,     3,     7,     3,    -1,    95,     3,     7,
       3,    -1,    97,     3,     7,     3,    -1,    96,     3,     7,
       3,    -1,   568,     7,   568,    -1,   568,     8,   568,    -1,
     568,     3,    -1,    -1,   568,   569,    -1,   319,    -1,   320,
      -1,   321,    -1,   322,    -1,   571,    -1,   578,    -1,    -1,
     571,   572,    -1,   573,   574,   577,    -1,   162,    -1,   575,
      -1,    -1,   575,   576,    -1,   808,    -1,   807,    -1,    11,
       7,   163,    -1,   157,   806,   579,    -1,   580,    -1,   581,
      -1,    11,   158,    -1,    10,    -1,    11,     5,   158,    -1,
      -1,   582,   583,    -1,   584,   585,   586,    -1,   162,    -1,
      -1,   808,    -1,    11,   566,   163,    -1,   588,    11,   589,
     590,    -1,   803,    -1,   199,    11,   571,   200,    -1,   201,
      11,   582,   202,    -1,   592,    11,   593,   594,    -1,   803,
      -1,   199,    11,   571,   200,    -1,   201,    11,   571,   202,
      -1,   596,   597,   603,    -1,   164,    -1,   598,    -1,    -1,
     598,   599,    -1,   600,    -1,   804,    -1,   802,    -1,   601,
      -1,   602,    -1,   173,     4,     3,    -1,    21,     4,     3,
      -1,    22,     4,     3,    -1,   604,    -1,   605,    -1,    10,
      -1,    11,   606,   165,    -1,   607,   625,    -1,    -1,   608,
     609,   624,    -1,   167,    -1,   610,    -1,    -1,   610,   611,
      -1,   612,    -1,   613,    -1,   614,    -1,   615,    -1,   616,
      -1,   617,    -1,   618,    -1,   619,    -1,   623,    -1,   181,
       3,     7,     3,    -1,   182,     3,     7,     3,    -1,   183,
       3,     7,     3,    -1,   184,     3,     7,     3,    -1,   185,
       3,     7,     3,    -1,   186,     3,     7,     3,    -1,   187,
       3,     7,     3,    -1,   620,    -1,   621,    -1,   622,    -1,
     189,    -1,   190,     4,   567,    -1,   188,     3,   566,     3,
      -1,    11,   166,    -1,    10,    -1,    -1,   625,   626,    -1,
     627,    -1,   767,    -1,   770,    -1,   628,   629,   633,    -1,
     191,    -1,    -1,   630,    -1,   631,    -1,   632,    -1,   223,
      -1,   224,     4,   567,    -1,   634,    -1,   635,    -1,    10,
      -1,    11,   637,   648,   659,   699,   730,   741,   752,   636,
      -1,   192,    -1,    -1,   638,    11,   639,    -1,   193,    -1,
     640,   646,   194,    -1,   641,   642,    -1,   195,    -1,   643,
      -1,   644,    -1,    10,    -1,    11,   645,   196,    -1,   570,
      -1,   647,   587,   198,    -1,   197,    -1,    -1,   649,    11,
     650,    -1,   203,    -1,   651,   657,   204,    -1,   652,   653,
      -1,   195,    -1,   654,    -1,   655,    -1,    10,    -1,    11,
     656,   196,    -1,   570,    -1,   658,   591,   198,    -1,   197,
      -1,    -1,   660,   661,    -1,   205,    -1,    11,   662,   668,
     206,    -1,   663,   664,    -1,   195,    -1,   665,    -1,   666,
      -1,    10,    -1,    11,   667,   196,    -1,   570,    -1,   669,
     670,   671,    -1,   197,    -1,   803,    -1,    11,   672,   198,
      -1,   673,   679,    -1,    -1,   674,   675,    -1,   199,    -1,
     676,    -1,   677,    -1,    10,    -1,    11,   678,   200,    -1,
     570,    -1,    -1,   680,   681,    -1,   201,    -1,   682,    -1,
     683,    -1,    10,    -1,    11,   684,   202,    -1,    -1,   684,
     685,    -1,   686,   687,   691,    -1,   162,    -1,   688,    -1,
      -1,   688,   689,    -1,   805,    -1,   690,    -1,   176,     3,
     566,     3,    -1,   692,    -1,   693,    -1,    10,    -1,    11,
     694,   163,    -1,    -1,   694,   695,    -1,   696,   697,   698,
      -1,   215,    -1,    -1,   318,     3,   566,     3,    -1,    11,
       7,   216,    -1,    -1,   700,   701,    -1,   207,    -1,    11,
     702,   708,   208,    -1,   703,   704,    -1,   195,    -1,   705,
      -1,   706,    -1,    10,    -1,    11,   707,   196,    -1,   570,
      -1,   709,   710,   711,    -1,   197,    -1,   803,    -1,    11,
     712,   198,    -1,   713,   719,    -1,    -1,   714,   715,    -1,
     199,    -1,   716,    -1,   717,    -1,    10,    -1,    11,   718,
     200,    -1,   570,    -1,    -1,   720,   721,    -1,   201,    -1,
     722,    -1,   723,    -1,    10,    -1,    11,   724,   202,    -1,
      -1,   724,   725,    -1,   726,   727,    -1,   162,    -1,   728,
      -1,   729,    -1,    10,    -1,    11,   815,   163,    -1,    -1,
     731,   732,   210,    -1,   209,    -1,    11,   733,   739,    -1,
     734,   735,    -1,   195,    -1,   736,    -1,   737,    -1,    10,
      -1,    11,   738,   196,    -1,   570,    -1,   740,   591,   198,
      -1,   197,    -1,    -1,   742,   743,   212,    -1,   211,    -1,
      11,   744,   750,    -1,   745,   746,    -1,   195,    -1,   747,
      -1,   748,    -1,    10,    -1,    11,   749,   196,    -1,   570,
      -1,   751,   591,   198,    -1,   197,    -1,    -1,   753,   754,
     758,   214,    -1,   213,    -1,    -1,   755,    -1,   756,    -1,
     757,    -1,   174,    -1,   175,     4,   567,    -1,    11,   759,
     765,    -1,   760,   761,    -1,   195,    -1,   762,    -1,   763,
      -1,    10,    -1,    11,   764,   196,    -1,   570,    -1,   766,
     803,    11,   570,   198,    -1,   197,    -1,   768,    11,   891,
     769,    -1,   217,    -1,   218,    -1,   771,   772,   773,    -1,
     170,    -1,   801,    -1,    11,   775,   782,   789,   774,    -1,
     171,    -1,   776,   777,   778,    -1,   219,    -1,   803,    -1,
     779,    -1,   780,    -1,    10,    -1,    11,   781,   220,    -1,
     570,    -1,   783,   784,   785,    -1,   221,    -1,   803,    -1,
     786,    -1,   787,    -1,    10,    -1,    11,   788,   222,    -1,
     570,    -1,    -1,   789,   790,    -1,   791,   792,   797,    -1,
     168,    -1,   793,    -1,    -1,   793,   794,    -1,   795,    -1,
     796,    -1,   600,    -1,   225,   567,     7,   567,    -1,   226,
     567,     7,   567,    -1,   798,    -1,   799,    -1,    11,   169,
      -1,    10,    -1,    11,   800,   169,    -1,   607,   625,    -1,
     177,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
     152,     3,     7,     3,    -1,   179,     3,     7,     3,    -1,
     180,     3,     7,     3,    -1,   161,     3,     7,     3,    -1,
     159,     3,     7,     3,    -1,   160,     3,     7,     3,    -1,
      -1,   228,   810,   811,   229,    -1,   230,     3,     7,     3,
      11,    -1,    -1,    -1,   811,   813,   814,    11,   815,   812,
     232,    -1,   231,    -1,    18,     3,     7,     3,    -1,   867,
      -1,   877,    -1,   816,    -1,   818,    -1,   828,    -1,   820,
      -1,   822,    -1,   824,    -1,   826,    -1,   840,    -1,   843,
      -1,   845,    -1,   847,    -1,   851,    -1,   849,    -1,   853,
      -1,   859,    -1,   855,    -1,   857,    -1,   834,    -1,   837,
      -1,   861,    -1,   864,    -1,   831,    -1,   885,    -1,   887,
      -1,   889,    -1,    -1,   277,   817,   815,   815,   278,    -1,
      -1,   235,   819,   815,   815,   236,    -1,    -1,   237,   821,
     815,   815,   238,    -1,    -1,   251,   823,   815,   252,    -1,
      -1,   239,   825,   815,   815,   240,    -1,    -1,   233,   827,
     815,   815,   234,    -1,    -1,   245,   829,   830,   246,    -1,
      -1,   830,   815,    -1,    -1,   269,   832,   833,   270,    -1,
      -1,   833,   815,    -1,    -1,   267,   835,   836,   268,    -1,
      -1,   836,   815,    -1,    -1,   271,   838,   839,   272,    -1,
      -1,   839,   815,    -1,    -1,   247,   841,   842,   248,    -1,
      -1,   842,   815,    -1,    -1,   241,   844,   815,   242,    -1,
      -1,   243,   846,   815,   244,    -1,    -1,   255,   848,   815,
     256,    -1,    -1,   257,   850,   815,   258,    -1,    -1,   259,
     852,   815,   260,    -1,    -1,   249,   854,   815,   250,    -1,
      -1,   263,   856,   815,   264,    -1,    -1,   265,   858,   815,
     266,    -1,    -1,   253,   860,   815,   815,   815,   254,    -1,
      -1,   273,   862,   863,    -1,    10,    -1,    11,   274,    -1,
      -1,   275,   865,   866,    -1,    10,    -1,    11,   276,    -1,
      -1,   279,   868,   870,   869,    -1,    10,    -1,    11,   280,
      -1,    -1,   870,   871,    -1,   872,    -1,   876,    -1,   874,
      -1,    -1,    22,     4,   873,     3,    -1,    -1,   317,     4,
     875,     3,    -1,    23,     3,   566,     3,    -1,    -1,   261,
     878,   881,   879,    -1,    10,    -1,    -1,    11,   815,   880,
     262,    -1,    11,   262,    -1,    -1,   881,   882,    -1,   883,
      -1,   884,    -1,   318,     3,   566,     3,    -1,    18,     3,
       7,     3,    -1,    -1,   281,   886,   891,   282,    -1,    -1,
     283,   888,   891,   284,    -1,    -1,   285,   890,   891,   286,
      -1,   892,    -1,   895,    -1,   898,    -1,   901,    -1,   904,
      -1,   907,    -1,   911,    -1,   916,    -1,   919,    -1,   922,
      -1,   925,    -1,   928,    -1,   931,    -1,   934,    -1,    -1,
     313,   893,   558,   894,    -1,    10,    -1,    11,   314,    -1,
      18,     3,     7,     3,    -1,   896,   897,    -1,   287,    -1,
     891,   288,    -1,   899,   900,    -1,   289,    -1,   891,   891,
     290,    -1,   902,   903,    -1,   291,    -1,   815,   292,    -1,
     905,   906,    -1,   293,    -1,   891,   294,    -1,   908,   909,
     910,    -1,   295,    -1,    -1,   915,    -1,   891,   296,    -1,
     912,   913,   914,    -1,   297,    -1,    -1,   915,    -1,   891,
     298,    -1,   316,     4,     3,    -1,   917,   918,    -1,   299,
      -1,    10,    -1,    11,   300,    -1,   920,   921,    -1,   301,
      -1,   891,   891,   302,    -1,   923,   924,    -1,   303,    -1,
     891,   891,   304,    -1,   926,   927,    -1,   305,    -1,   891,
     891,   306,    -1,   929,   930,    -1,   307,    -1,   815,   891,
     308,    -1,   932,   933,    -1,   309,    -1,   891,   815,   815,
     815,   815,   310,    -1,   935,   936,    -1,   311,    -1,   891,
     312,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   383,   383,   386,   387,   389,   398,   399,   402,   403,
     408,   415,   415,   417,   430,   436,   437,   440,   441,   444,
     447,   450,   453,   459,   466,   473,   481,   486,   486,   488,
     495,   497,   497,   499,   501,   503,   503,   506,   506,   508,
     510,   512,   512,   514,   516,   518,   518,   520,   521,   523,
     524,   526,   533,   534,   539,   541,   543,   545,   545,   548,
     549,   550,   552,   552,   554,   556,   558,   560,   560,   563,
     564,   565,   567,   567,   571,   573,   575,   577,   577,   580,
     581,   582,   583,   584,   585,   588,   588,   590,   592,   594,
     596,   596,   599,   600,   601,   602,   603,   604,   605,   608,
     608,   612,   614,   616,   618,   618,   621,   622,   623,   624,
     627,   627,   641,   643,   645,   647,   647,   650,   651,   652,
     655,   657,   659,   661,   663,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   681,   684,   685,   686,   689,
     691,   693,   695,   697,   697,   699,   701,   703,   705,   707,
     716,   716,   718,   720,   720,   722,   725,   727,   727,   729,
     731,   733,   733,   735,   737,   739,   741,   741,   743,   745,
     747,   749,   749,   752,   753,   754,   755,   756,   757,   758,
     761,   762,   764,   764,   766,   768,   770,   770,   772,   774,
     776,   778,   778,   780,   782,   784,   786,   786,   789,   790,
     791,   792,   793,   794,   795,   798,   798,   800,   802,   804,
     806,   810,   810,   812,   814,   816,   819,   819,   821,   823,
     825,   825,   827,   829,   831,   833,   833,   835,   837,   839,
     841,   841,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   855,   855,   857,   859,   861,   863,   866,   866,   868,
     870,   872,   872,   874,   876,   878,   878,   880,   882,   884,
     884,   886,   888,   888,   890,   891,   894,   895,   898,   949,
     951,   965,   966,   968,   968,   992,   993,   996,   997,   999,
    1001,  1002,  1006,  1007,  1009,  1010,  1012,  1028,  1036,  1043,
    1048,  1049,  1051,  1052,  1054,  1054,  1057,  1066,  1067,  1069,
    1070,  1074,  1075,  1077,  1078,  1080,  1096,  1104,  1111,  1116,
    1117,  1119,  1120,  1122,  1122,  1125,  1134,  1135,  1137,  1147,
    1151,  1152,  1154,  1155,  1157,  1173,  1180,  1185,  1186,  1188,
    1189,  1191,  1191,  1194,  1203,  1204,  1209,  1209,  1217,  1218,
    1220,  1221,  1223,  1227,  1233,  1241,  1245,  1250,  1259,  1270,
    1281,  1292,  1303,  1311,  1319,  1327,  1335,  1344,  1353,  1361,
    1372,  1383,  1395,  1406,  1417,  1428,  1439,  1450,  1461,  1472,
    1483,  1494,  1505,  1519,  1520,  1527,  1529,  1529,  1531,  1532,
    1533,  1534,  1699,  1707,  1709,  1709,  1711,  1713,  1722,  1724,
    1724,  1726,  1726,  1728,  1744,  1747,  1747,  1749,  1749,  1752,
    1793,  1793,  1795,  1797,  1805,  1805,  1807,  1860,  1864,  1875,
    1877,  1885,  1889,  1900,  1902,  1908,  1910,  1915,  1917,  1917,
    1920,  1921,  1922,  1923,  1924,  1933,  1942,  1951,  1960,  1960,
    1962,  1964,  1966,  1968,  1968,  1970,  1972,  1974,  1974,  1977,
    1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1987,  1997,
    2007,  2017,  2027,  2037,  2047,  2057,  2064,  2064,  2066,  2071,
    2080,  2088,  2088,  2090,  2090,  2092,  2092,  2092,  2094,  2096,
    2098,  2098,  2100,  2100,  2102,  2107,  2116,  2116,  2118,  2120,
    2123,  2125,  2125,  2127,  2129,  2131,  2142,  2148,  2148,  2150,
    2152,  2154,  2156,  2169,  2176,  2176,  2178,  2180,  2182,  2193,
    2199,  2199,  2201,  2203,  2205,  2207,  2220,  2226,  2226,  2228,
    2230,  2232,  2243,  2249,  2249,  2251,  2253,  2255,  2257,  2268,
    2274,  2281,  2283,  2285,  2286,  2299,  2306,  2306,  2308,  2310,
    2312,  2314,  2315,  2317,  2323,  2323,  2325,  2327,  2329,  2329,
    2331,  2334,  2340,  2342,  2342,  2345,  2346,  2348,  2352,  2352,
    2354,  2356,  2358,  2358,  2361,  2363,  2369,  2369,  2373,  2377,
    2377,  2379,  2381,  2383,  2394,  2400,  2400,  2402,  2404,  2406,
    2408,  2419,  2425,  2432,  2434,  2436,  2437,  2450,  2457,  2457,
    2459,  2461,  2463,  2465,  2466,  2468,  2474,  2474,  2476,  2478,
    2480,  2480,  2482,  2484,  2490,  2490,  2492,  2494,  2497,  2497,
    2499,  2501,  2503,  2514,  2520,  2520,  2522,  2524,  2526,  2528,
    2541,  2547,  2547,  2549,  2551,  2553,  2564,  2570,  2570,  2572,
    2574,  2576,  2578,  2591,  2597,  2597,  2599,  2601,  2601,  2603,
    2603,  2605,  2610,  2619,  2621,  2632,  2645,  2645,  2647,  2649,
    2651,  2653,  2666,  2672,  2674,  2676,  2678,  2680,  2682,  2684,
    2686,  2688,  2699,  2705,  2712,  2712,  2714,  2716,  2718,  2720,
    2731,  2737,  2744,  2744,  2746,  2748,  2750,  2752,  2752,  2754,
    2756,  2758,  2760,  2760,  2763,  2764,  2765,  2772,  2781,  2790,
    2790,  2792,  2792,  2794,  2796,  2798,  2807,  2816,  2825,  2834,
    2843,  2848,  2856,  2897,  2898,  2902,  2911,  2913,  2912,  2920,
    2925,  2939,  2940,  2941,  2942,  2943,  2944,  2945,  2946,  2947,
    2948,  2949,  2950,  2951,  2952,  2953,  2954,  2955,  2956,  2957,
    2958,  2959,  2960,  2961,  2962,  2964,  2965,  2966,  2970,  2970,
    2975,  2975,  2980,  2980,  2985,  2985,  2990,  2990,  2995,  2995,
    3000,  3000,  3010,  3011,  3016,  3016,  3028,  3029,  3032,  3032,
    3043,  3044,  3046,  3046,  3057,  3058,  3061,  3061,  3071,  3072,
    3075,  3075,  3080,  3080,  3085,  3085,  3090,  3090,  3095,  3095,
    3100,  3100,  3105,  3105,  3112,  3112,  3118,  3118,  3125,  3125,
    3128,  3129,  3131,  3131,  3134,  3135,  3137,  3137,  3142,  3143,
    3145,  3146,  3148,  3150,  3152,  3156,  3156,  3160,  3160,  3165,
    3175,  3175,  3180,  3181,  3181,  3185,  3187,  3188,  3190,  3192,
    3196,  3205,  3212,  3212,  3217,  3217,  3222,  3222,  3227,  3228,
    3229,  3230,  3231,  3232,  3233,  3234,  3235,  3236,  3237,  3238,
    3239,  3240,  3243,  3242,  3248,  3249,  3251,  3259,  3261,  3267,
    3269,  3271,  3277,  3279,  3281,  3287,  3289,  3291,  3297,  3299,
    3301,  3307,  3307,  3309,  3311,  3313,  3319,  3319,  3321,  3323,
    3330,  3332,  3337,  3337,  3339,  3341,  3347,  3349,  3351,  3357,
    3359,  3361,  3367,  3369,  3371,  3377,  3379,  3381,  3387,  3389,
    3391,  3397
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
  "NUMBEREND", "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND",
  "MATRIXTRACESTART", "MATRIXTRACEEND", "MATRIXTOSCALARSTART",
  "MATRIXTOSCALAREND", "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND",
  "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND", "MATRIXIDENTITYSTART",
  "MATRIXIDENTITYEND", "MATRIXINVERSESTART", "MATRIXINVERSEEND",
  "MATRIXLOWERTRIANGLESTART", "MATRIXLOWERTRIANGLEEND",
  "MATRIXUPPERTRIANGLESTART", "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART",
  "MATRIXMERGEEND", "MATRIXMINUSSTART", "MATRIXMINUSEND",
  "MATRIXPLUSSTART", "MATRIXPLUSEND", "MATRIXTIMESSTART", "MATRIXTIMESEND",
  "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART", "MATRIXREFERENCEEND",
  "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT", "IDATT", "COEFATT",
  "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osildoc", "theInstanceEnd",
  "osilEnd", "osilEnding", "quadraticCoefficients", "osilQuadnumberATT",
  "qTermlist", "qterm", "qtermStart", "qtermend", "anotherqTermATT",
  "qtermatt", "osilQtermidxOneATT", "osilQtermidxTwoATT",
  "osilQtermcoefATT", "osilQtermidxATT", "matrices", "matricesStart",
  "matricesAttributes", "matricesContent", "matricesEmpty",
  "matricesLaden", "matrixList", "cones", "conesStart", "conesAttributes",
  "conesContent", "conesEmpty", "conesLaden", "coneList", "cone",
  "nonnegativeCone", "nonnegativeConeStart", "nonnegativeConeAttributes",
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
  "productConeFactorsEmpty", "productConeFactorsLaden",
  "productConeFactorList", "productConeFactorsEnd", "productConeEnd",
  "intersectionCone", "intersectionConeStart",
  "intersectionConeAttributes", "intersectionConeAttList",
  "intersectionConeAtt", "intersectionConeContent",
  "intersectionConeComponents", "intersectionConeComponentsStart",
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
  "matrixObjAtt", "matrixObjContent", "matrixObjEmpty", "matrixObjLaden",
  "matrixObjTerms", "matrixObjEnd", "matrixTermList", "matrixTerm",
  "matrixTermStart", "matrixTermEnd", "matrixConstraints",
  "matrixConstraintsStart", "matrixConstraintsAttributes",
  "matrixConstraintsContent", "matrixConstraintsEmpty",
  "matrixConstraintsLaden", "matrixConstraintsEnd", "matrixConList",
  "matrixCon", "matrixConStart", "matrixConAttributes", "matrixConAttList",
  "matrixConAtt", "matrixConContent", "matrixConEmpty", "matrixConLaden",
  "matrixConTerms", "matrixConEnd", "matrixExpressions",
  "matrixExpressionsStart", "matrixExpressionsAtt",
  "matrixExpressionsContent", "matrixExpressionsEmpty",
  "matrixExpressionsLaden", "matrixExprList", "matrixExpr",
  "matrixExprIdxATT", "timeDomain", "timeDomainStart", "timeDomainContent",
  "timeDomainEmpty", "timeDomainLaden", "stages", "stagesstart",
  "osilNumberofstagesATT", "stagelist", "stage", "$@1", "osilStagenameATT",
  "stageend", "stagecontent", "stagevariables", "anotherstagevarATT",
  "stagevaratt", "osilNumberofstagevariablesATT",
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
  "patternElementsStartVectorStart", "patternElementsStartVectorContent",
  "patternElementsStartVectorEmpty", "patternElementsStartVectorLaden",
  "patternElementsStartVectorBody", "patternElementsNonzeros",
  "patternElementsNonzerosStart", "matrixTransformation",
  "matrixTransformationStart", "matrixTransformationEnd", "matrixBlocks",
  "matrixBlocksStart", "matrixBlocksAttributes", "matrixBlocksContent",
  "matrixBlocksEnd", "colOffsets", "colOffsetsStart",
  "colOffsetsNumberOfElAttribute", "colOffsetsContent", "colOffsetsEmpty",
  "colOffsetsLaden", "colOffsetsBody", "rowOffsets", "rowOffsetsStart",
  "rowOffsetsNumberOfElAttribute", "rowOffsetsContent", "rowOffsetsEmpty",
  "rowOffsetsLaden", "rowOffsetsBody", "blockList", "matrixBlock",
  "matrixBlockStart", "matrixBlockAttributes", "matrixBlockAttList",
  "matrixBlockAtt", "osglBlockRowIdxATT", "osglBlockColIdxATT",
  "matrixBlockContent", "blockEmpty", "blockLaden", "blockBody",
  "osglNumberOfBlocksATT", "osglNumberOfColumnsATT", "osglNumberOfElATT",
  "osglNumberOfRowsATT", "osglNumberOfVarIdxATT", "osglBase64SizeATT",
  "osglIncrATT", "osglMultATT", "nonlinearExpressions", "nlnumberatt",
  "nlnodes", "$@6", "nlstart", "nlIdxATT", "nlnode", "times", "$@7",
  "plus", "$@8", "minus", "$@9", "negate", "$@10", "divide", "$@11",
  "power", "$@12", "sum", "$@13", "anothersumnlnode", "allDiff", "$@14",
  "anotherallDiffnlnode", "max", "$@15", "anothermaxnlnode", "min", "$@16",
  "anotherminnlnode", "product", "$@17", "anotherproductnlnode", "ln",
  "$@18", "sqrt", "$@19", "square", "$@20", "cos", "$@21", "sin", "$@22",
  "exp", "$@23", "abs", "$@24", "erf", "$@25", "if", "$@26", "E", "$@27",
  "eend", "PI", "$@28", "piend", "number", "$@29", "numberend",
  "anotherNumberATT", "numberATT", "numbertypeATT", "$@30", "numberidATT",
  "$@31", "numbervalueATT", "variable", "$@32", "variableend", "$@33",
  "anotherVariableATT", "variableATT", "variablecoefATT", "variableidxATT",
  "matrixDeterminant", "$@34", "matrixTrace", "$@35", "matrixToScalar",
  "$@36", "OSnLMNode", "matrixReference", "$@37", "matrixreferenceend",
  "matrixDiagonal", "matrixDiagonalStart", "matrixDiagonalContent",
  "matrixDotTimes", "matrixDotTimesStart", "matrixDotTimesContent",
  "matrixIdentity", "matrixIdentityStart", "matrixIdentityContent",
  "matrixInverse", "matrixInverseStart", "matrixInverseContent",
  "matrixLowerTriangle", "matrixLowerTriangleStart",
  "matrixLowerTriangleAttribute", "matrixLowerTriangleContent",
  "matrixUpperTriangle", "matrixUpperTriangleStart",
  "matrixUpperTriangleAttribute", "matrixUpperTriangleContent",
  "includeDiagonalATT", "matrixMerge", "matrixMergeStart",
  "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
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
     565,   566,   567,   568,   569,   570,   571,   572,   573,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   323,   324,   325,   325,   326,   327,   327,   328,   328,
     329,   330,   330,   331,   332,   333,   333,   334,   334,   335,
     335,   335,   335,   336,   337,   338,   339,   340,   340,   341,
     342,   343,   343,   344,   345,   346,   346,   347,   347,   348,
     349,   350,   350,   351,   352,   353,   353,   354,   354,   354,
     354,   354,   354,   354,   355,   356,   357,   358,   358,   359,
     359,   359,   360,   360,   361,   362,   363,   364,   364,   365,
     365,   365,   366,   366,   367,   368,   369,   370,   370,   371,
     371,   371,   371,   371,   371,   372,   372,   373,   374,   375,
     376,   376,   377,   377,   377,   377,   377,   377,   377,   378,
     378,   379,   380,   381,   382,   382,   383,   383,   383,   383,
     384,   384,   385,   386,   387,   388,   388,   389,   389,   389,
     390,   391,   392,   393,   394,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   403,   404,   404,   404,   405,
     406,   407,   408,   409,   409,   410,   411,   412,   413,   414,
     415,   415,   416,   417,   417,   418,   419,   420,   420,   421,
     422,   423,   423,   424,   425,   426,   427,   427,   428,   429,
     430,   431,   431,   432,   432,   432,   432,   432,   432,   432,
     433,   433,   434,   434,   435,   436,   437,   437,   438,   439,
     440,   441,   441,   442,   443,   444,   445,   445,   446,   446,
     446,   446,   446,   446,   446,   447,   447,   448,   449,   450,
     451,   452,   452,   453,   454,   455,   456,   456,   457,   458,
     459,   459,   460,   461,   462,   463,   463,   464,   465,   466,
     467,   467,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   469,   469,   470,   471,   472,   473,   474,   474,   475,
     476,   477,   477,   478,   479,   480,   480,   481,   482,   483,
     483,   484,   485,   485,   486,   486,   487,   487,   488,   489,
     490,   491,   491,   493,   492,   494,   494,   495,   495,   496,
     497,   497,   498,   498,   499,   499,   500,   501,   502,   502,
     503,   503,   504,   504,   506,   505,   507,   508,   508,   509,
     509,   510,   510,   511,   511,   512,   513,   514,   514,   515,
     515,   516,   516,   518,   517,   519,   520,   520,   521,   521,
     522,   522,   523,   523,   524,   525,   525,   526,   526,   527,
     527,   529,   528,   530,   531,   531,   533,   532,   534,   534,
     535,   535,   536,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   566,   567,   568,   568,   569,   569,
     569,   569,   570,   570,   571,   571,   572,   573,   574,   575,
     575,   576,   576,   577,   578,   579,   579,   580,   580,   581,
     582,   582,   583,   584,   585,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   598,
     599,   599,   599,   599,   599,   600,   601,   602,   603,   603,
     604,   605,   606,   607,   607,   608,   609,   610,   610,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   620,   621,   622,
     623,   624,   624,   625,   625,   626,   626,   626,   627,   628,
     629,   629,   630,   630,   631,   632,   633,   633,   634,   635,
     636,   637,   637,   638,   639,   640,   641,   642,   642,   643,
     644,   645,   646,   647,   648,   648,   649,   650,   651,   652,
     653,   653,   654,   655,   656,   657,   658,   659,   659,   660,
     661,   662,   663,   664,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   673,   674,   675,   675,   676,   677,
     678,   679,   679,   680,   681,   681,   682,   683,   684,   684,
     685,   686,   687,   688,   688,   689,   689,   690,   691,   691,
     692,   693,   694,   694,   695,   696,   697,   697,   698,   699,
     699,   700,   701,   702,   703,   704,   704,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   713,   714,   715,   715,
     716,   717,   718,   719,   719,   720,   721,   721,   722,   723,
     724,   724,   725,   726,   727,   727,   728,   729,   730,   730,
     731,   732,   733,   734,   735,   735,   736,   737,   738,   739,
     740,   741,   741,   742,   743,   744,   745,   746,   746,   747,
     748,   749,   750,   751,   752,   752,   753,   754,   754,   755,
     755,   756,   757,   758,   759,   760,   761,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   777,   778,   778,   779,   780,   781,   782,
     783,   784,   785,   785,   786,   787,   788,   789,   789,   790,
     791,   792,   793,   793,   794,   794,   794,   795,   796,   797,
     797,   798,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   809,   810,   811,   812,   811,   813,
     814,   815,   815,   815,   815,   815,   815,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   815,   817,   816,
     819,   818,   821,   820,   823,   822,   825,   824,   827,   826,
     829,   828,   830,   830,   832,   831,   833,   833,   835,   834,
     836,   836,   838,   837,   839,   839,   841,   840,   842,   842,
     844,   843,   846,   845,   848,   847,   850,   849,   852,   851,
     854,   853,   856,   855,   858,   857,   860,   859,   862,   861,
     863,   863,   865,   864,   866,   866,   868,   867,   869,   869,
     870,   870,   871,   871,   871,   873,   872,   875,   874,   876,
     878,   877,   879,   880,   879,   879,   881,   881,   882,   882,
     883,   884,   886,   885,   888,   887,   890,   889,   891,   891,
     891,   891,   891,   891,   891,   891,   891,   891,   891,   891,
     891,   891,   893,   892,   894,   894,   558,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   909,   910,   911,   912,   913,   913,   914,   915,
     916,   917,   918,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936
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
       3,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     6,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     2,     3,     2,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     0,     2,     5,     4,     0,
       2,     1,     1,     1,     1,     2,     3,     3,     4,     1,
       5,     1,     2,     0,     4,     0,     3,     1,     3,     3,
       0,     3,     0,     2,     1,     1,     4,     4,     1,     3,
       1,     2,     1,     2,     0,     4,     4,     1,     2,     0,
       3,     0,     2,     1,     1,     4,     4,     1,     3,     1,
       2,     1,     2,     0,     4,     4,     1,     2,     0,     3,
       0,     2,     1,     1,     4,     1,     3,     1,     2,     1,
       2,     0,     4,     4,     1,     2,     0,     4,     1,     2,
       0,     2,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     4,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     3,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     3,     3,     1,     1,     2,     1,     3,
       0,     2,     3,     1,     0,     1,     3,     4,     1,     4,
       4,     4,     1,     4,     4,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     3,
       4,     2,     1,     0,     2,     1,     1,     1,     3,     1,
       0,     1,     1,     1,     1,     3,     1,     1,     1,     9,
       1,     0,     3,     1,     3,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     0,     3,     1,     3,     2,     1,
       1,     1,     1,     3,     1,     3,     1,     0,     2,     1,
       4,     2,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     3,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     4,     1,     1,
       1,     3,     0,     2,     3,     1,     0,     4,     3,     0,
       2,     1,     4,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     1,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     0,     3,
       1,     3,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     0,     3,     1,     3,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     0,     4,     1,     0,     1,     1,
       1,     1,     3,     3,     2,     1,     1,     1,     1,     3,
       1,     5,     1,     4,     1,     1,     3,     1,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     4,     4,     1,
       1,     2,     1,     3,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     4,     5,     0,     0,     7,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       0,     5,     0,     5,     0,     4,     0,     5,     0,     5,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     6,     0,     3,
       1,     2,     0,     3,     1,     2,     0,     4,     1,     2,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     4,
       0,     4,     1,     0,     4,     2,     0,     2,     1,     1,
       4,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     2,     4,     2,     1,     2,
       2,     1,     3,     2,     1,     2,     2,     1,     2,     3,
       1,     0,     1,     2,     3,     1,     0,     1,     2,     3,
       2,     1,     1,     2,     2,     1,     3,     2,     1,     3,
       2,     1,     3,     2,     1,     3,     2,     1,     6,     2,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   693,     0,    11,     1,     0,    27,     0,
       0,     0,   696,    29,    37,     0,     0,     9,    14,    12,
      17,     0,     0,    39,   150,     0,     0,     0,    30,     0,
       0,     0,   694,   699,     0,   152,   259,     0,     0,     0,
      40,     0,    33,    35,    28,    31,    32,    10,    15,     0,
       0,     0,     0,     0,    13,    18,    19,    20,    21,    22,
       0,     0,     0,   261,     0,     0,   155,   157,   151,   153,
     154,     0,    43,    45,    38,    41,    42,     0,     0,    16,
       0,     0,     0,   376,   695,     0,     0,     4,     3,     7,
     264,   336,   260,   262,   263,   159,   182,     0,     0,     0,
     348,    34,   416,    36,   418,     0,     0,     0,     0,     0,
       0,   738,   730,   732,   736,   760,   762,   740,   756,   770,
     734,   776,   764,   766,   768,   800,   772,   774,   748,   744,
     752,   778,   782,   728,   786,   812,   814,   816,   697,   703,
     704,   706,   707,   708,   709,   705,   724,   720,   721,   710,
     711,   712,   713,   715,   714,   716,   718,   719,   717,   722,
     723,   701,   702,   725,   726,   727,     6,     2,     5,   265,
     269,     0,     0,     0,     0,   184,   216,     0,     0,     0,
     160,   349,    44,    55,    65,    75,    88,   102,   113,   132,
      46,    47,    57,    48,    67,    49,    77,    50,    90,    51,
     104,    52,   115,    53,   134,     0,   417,    26,    23,    24,
      25,   376,   376,   378,   379,   380,   381,   377,   700,     0,
       0,     0,     0,     0,     0,   742,   758,     0,     0,     0,
       0,     0,     0,   806,     0,     0,   750,   746,   754,     0,
       0,     0,   790,     0,     0,     0,     0,   266,     0,   273,
     267,   340,   218,   247,     0,     0,     0,   185,     0,   163,
     166,   158,   161,   162,     0,    56,     0,    66,     0,    76,
       0,    89,     0,   103,     0,   114,     0,   133,   430,   433,
     415,   428,   429,     0,     0,     0,     0,     0,   419,   420,
     423,   424,   422,   421,   373,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   780,     0,   779,   784,
       0,   783,     0,     0,   838,   841,   844,   847,   850,   855,
     861,   865,   868,   871,   874,   877,   880,   832,     0,   818,
     819,     0,   820,     0,   821,     0,   822,     0,   823,   851,
     824,   856,   825,     0,   826,     0,   827,     0,   828,     0,
     829,     0,   830,     0,   831,     0,     0,     0,   698,     0,
     273,   271,     0,     0,   249,     0,     0,     0,     0,   219,
       0,   188,   191,   183,   186,   187,     0,     0,    62,     0,
      54,     0,     0,     0,    58,    59,    60,    61,    72,     0,
      64,    68,    69,    70,    71,    85,     0,    74,     0,     0,
       0,    78,    79,    80,    81,    83,    82,    84,    99,     0,
      87,     0,     0,    91,    92,    93,    94,    96,    95,    97,
      98,   110,     0,   101,     0,   105,   106,   107,   108,   109,
       0,   112,   116,   117,   118,   119,     0,   131,   135,   136,
     137,   138,   435,     0,   463,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   761,   763,   741,   743,   757,
     759,   771,   735,     0,   765,   767,   769,   802,     0,     0,
       0,   801,   807,   808,   809,   773,   775,   749,   751,   745,
     747,   753,   755,   781,   785,     0,   788,     0,     0,     0,
       0,   787,   791,   792,   794,   793,     0,   813,     0,   837,
       0,   840,     0,   843,     0,   846,     0,     0,   852,     0,
     857,   862,     0,   860,     0,   864,     0,   867,     0,   870,
       0,   873,     0,   876,     0,   879,   815,   817,     0,   268,
     272,   275,   338,     0,     0,     0,   337,   341,   342,   343,
     156,     0,     0,   250,     0,   222,   225,   217,   220,   221,
       0,     0,   352,   165,   169,   164,   167,   171,    63,     0,
       0,     0,    73,    86,   376,     0,     0,   100,     0,     0,
     111,     0,   122,     0,     0,   141,     0,     0,   431,   432,
       0,   436,   426,   427,   425,     0,     0,   739,   731,   733,
     737,     0,   805,   803,     0,   376,   729,   789,   795,   376,
     797,     0,     0,     0,   839,     0,   845,   848,     0,     0,
     849,     0,   854,   863,     0,     0,     0,     0,     0,   881,
       0,     0,     0,   339,   376,   376,     0,   253,   255,   248,
     251,   252,     0,     0,   353,   190,   194,   189,   192,   196,
       0,   170,   357,     0,     0,     0,     0,     0,     0,     0,
     364,   130,   120,   376,     0,   123,   149,   139,     0,   142,
     647,   469,   644,   464,   465,   470,   466,     0,   467,     0,
     462,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,   458,     0,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   455,   456,   457,   447,   686,   688,   777,     0,
       0,     0,     0,     0,     0,     0,     0,   834,     0,   833,
     842,   859,   853,   858,   866,   869,   872,   875,     0,   270,
       0,   277,   280,   274,     0,     0,     0,     0,   354,   224,
     228,   223,   226,   230,     0,   195,   180,     0,   168,     0,
       0,     0,     0,     0,   172,   179,   173,   174,   175,   176,
     177,   178,   351,   350,   359,   360,   361,   362,   363,     0,
       0,   126,   384,   121,   124,   125,   145,   384,   140,   143,
     144,   474,     0,     0,   471,   472,   473,     0,     0,     0,
     648,   461,     0,     0,     0,     0,     0,     0,     0,   376,
     376,   804,   811,   810,   796,   799,   798,     0,     0,   835,
       0,   276,   282,     0,   299,   345,   346,   356,   254,     0,
     256,     0,   229,   207,   211,   193,   205,   206,     0,     0,
       0,     0,   197,   204,   202,   203,   198,   200,   199,   201,
     181,     0,     0,     0,     0,     0,   376,   375,     0,     0,
     128,   382,   383,     0,   147,   376,   478,   481,   468,   476,
     477,     0,     0,     0,   646,     0,     0,     0,     0,     0,
       0,     0,     0,   459,   836,   365,     0,     0,   278,   301,
     318,     0,     0,   243,   211,   227,   241,   242,   231,   240,
     238,   239,   232,   233,   234,   235,   236,   237,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,     0,   129,   127,   387,   385,   389,   148,   146,   475,
     483,   494,     0,   645,   643,     0,   652,     0,     0,   448,
     449,   450,   451,   452,   453,   454,   460,   878,   290,   294,
       0,     0,   283,   284,   285,   281,   288,     0,   320,   279,
       0,     0,   245,     0,   210,   208,     0,   212,     0,     0,
       0,     0,   358,   366,   368,   369,   370,   372,     0,   398,
       0,   394,   395,   396,     0,   388,   496,   507,     0,     0,
     685,   660,   667,     0,     0,     0,   653,   291,   294,   292,
       0,     0,     0,   309,   313,     0,     0,   302,   303,   304,
     300,   307,     0,     0,     0,   246,   244,   214,     0,   355,
     371,   367,     0,     0,   397,     0,   386,     0,     0,   390,
     392,   391,   509,   559,     0,     0,   486,   482,     0,     0,
       0,     0,   661,     0,   656,   384,   651,   654,   655,   289,
     293,     0,     0,     0,   310,   313,   311,     0,     0,     0,
     327,   331,     0,     0,   321,   322,   319,   325,   323,   258,
     257,   215,   213,   690,   399,     0,     0,     0,   561,   598,
       0,     0,   508,   499,   495,     0,     0,   493,     0,     0,
     489,   384,   485,   487,   488,   670,   650,   649,   668,   672,
     664,   384,   659,   662,   663,     0,   658,     0,     0,     0,
     286,   287,   308,   312,     0,     0,     0,   328,   331,   329,
       0,     0,     0,   393,     0,     0,   600,   611,     0,     0,
     560,   512,     0,     0,   506,     0,     0,   502,   384,   498,
     500,   501,   484,     0,     0,   408,   491,     0,     0,   671,
     666,     0,   687,   657,     0,   297,     0,   295,     0,     0,
     305,   306,   326,   330,     0,     0,     0,   691,   692,   613,
     624,     0,     0,     0,   564,     0,     0,   519,     0,     0,
     515,   384,   511,   513,   514,   497,     0,     0,   412,   504,
       0,   492,     0,   490,   682,   433,   669,   679,   680,   376,
     376,   676,   673,   674,   675,   665,     0,   298,     0,   316,
       0,   314,     0,     0,   324,   344,   626,     0,   627,     0,
       0,   603,     0,     0,   599,   571,     0,     0,   567,   384,
     563,   565,   566,   510,     0,   520,   517,     0,   505,     0,
     503,     0,     0,   681,   463,     0,     0,     0,   296,     0,
     317,     0,   334,     0,   332,   480,   479,   631,     0,     0,
     628,   629,   630,   616,     0,     0,   612,   610,   601,     0,
     606,   384,   602,   604,   605,   562,     0,   572,   569,     0,
     523,   518,   516,     0,     0,   384,     0,   407,   684,   683,
     376,   376,   315,     0,   335,   376,     0,     0,   623,   614,
       0,   619,   384,   615,   617,   618,     0,   608,     0,   575,
     570,   568,   525,     0,   531,     0,   384,     0,   411,     0,
     400,   677,   678,   333,   632,   635,     0,     0,   625,     0,
     621,     0,   609,   607,   577,     0,   583,     0,   521,   533,
     522,     0,   528,   384,   524,   526,   527,     0,   384,   409,
       0,   642,   633,     0,   638,   384,   634,   636,   637,   622,
     620,   573,   585,   574,     0,   580,   384,   576,   578,   579,
     536,   538,   532,   534,   535,   530,     0,   413,     0,   403,
     410,   401,   404,     0,   640,     0,   588,   590,   584,   586,
     587,   582,     0,     0,   529,   414,     0,   405,   384,   639,
       0,   581,   541,   537,   539,   543,   376,   402,     0,   593,
     589,   591,     0,     0,   542,     0,   641,   596,     0,   592,
     594,   595,   550,   552,   540,   548,   549,     0,     0,   544,
     546,   545,   406,     0,     0,   376,     0,   597,   551,   555,
     553,   556,     0,     0,     0,     0,   547,   689,   376,     0,
     554,     0,     0,   557,   558
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    89,   167,   168,     3,     5,    10,    19,    20,
      54,    30,    55,    56,    57,    58,    59,    14,    15,    27,
      44,    45,    46,    78,    24,    25,    39,    74,    75,    76,
      99,   190,   191,   192,   264,   265,   394,   390,   193,   194,
     266,   267,   401,   400,   195,   196,   268,   269,   411,   407,
     197,   198,   270,   271,   423,   420,   199,   200,   272,   273,
     435,   433,   201,   202,   274,   275,   442,   441,   583,   584,
     664,   773,   774,   775,   849,   913,   662,   203,   204,   276,
     277,   448,   447,   586,   587,   668,   778,   779,   780,   853,
     918,   667,    36,    37,    68,    69,    70,    96,    97,   179,
     261,   262,   263,   565,   387,   566,   567,   650,   651,   754,
     748,   176,   177,   256,   383,   384,   385,   647,   561,   648,
     649,   744,   745,   832,   825,   826,   827,   898,   955,   899,
     957,   958,  1062,   253,   254,   378,   557,   558,   559,   741,
     643,   742,   743,   821,   822,   888,   885,   886,   887,   953,
    1006,   375,   376,   552,   639,   640,   641,   737,   820,   882,
      64,    65,    92,    93,    94,   171,   172,   249,   370,   371,
     372,   632,   733,   813,   814,   877,   942,   943,   944,   945,
     946,   988,   989,   990,  1099,  1147,   880,   947,   997,   998,
     999,  1000,  1001,  1045,  1046,  1047,  1149,  1201,   949,  1002,
    1054,  1055,  1056,  1057,  1108,  1109,  1110,  1203,  1244,   173,
     174,   546,   373,   547,  1058,   548,   549,   665,    28,    40,
     395,   396,   180,   257,   379,   833,   553,   397,   835,   415,
     416,   417,   429,   430,   439,   613,   757,   837,   758,   759,
     760,   838,   761,   108,   769,   109,   217,   850,   851,   915,
     916,   974,   975,  1019,  1016,   852,   971,   972,   973,  1340,
    1371,  1372,  1386,  1397,  1133,  1134,  1232,  1277,  1176,  1177,
    1274,  1308,   103,   104,   205,   206,   288,   289,   290,   291,
     280,   281,   282,   453,   454,   455,   590,   591,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   682,   589,   673,   674,   675,   783,   784,   785,   786,
     858,   859,   860,  1246,   921,   922,  1027,  1028,  1029,  1082,
    1083,  1084,  1137,  1078,  1079,   977,   978,  1074,  1075,  1076,
    1129,  1130,  1131,  1180,  1125,  1126,  1023,  1024,  1072,  1122,
    1123,  1172,  1173,  1174,  1227,  1168,  1169,  1224,  1271,  1303,
    1304,  1305,  1334,  1335,  1336,  1366,  1330,  1331,  1362,  1363,
    1364,  1383,  1394,  1395,  1403,  1404,  1419,  1420,  1414,  1415,
    1416,  1424,  1430,  1431,  1435,  1440,  1069,  1070,  1120,  1165,
    1166,  1220,  1221,  1222,  1269,  1216,  1217,  1266,  1300,  1325,
    1326,  1327,  1357,  1358,  1359,  1382,  1353,  1354,  1378,  1379,
    1380,  1390,  1401,  1402,  1409,  1410,  1411,  1117,  1118,  1163,
    1212,  1213,  1262,  1263,  1264,  1298,  1258,  1259,  1160,  1161,
    1210,  1254,  1255,  1293,  1294,  1295,  1321,  1289,  1290,  1207,
    1208,  1249,  1250,  1251,  1252,  1287,  1316,  1317,  1346,  1347,
    1348,  1375,  1342,  1343,   676,   677,   924,   678,   679,   789,
     864,  1087,   927,   928,   985,  1036,  1037,  1038,  1097,   982,
     983,  1031,  1092,  1093,  1094,  1141,  1030,  1088,  1089,  1138,
    1139,  1192,  1193,  1194,  1186,  1187,  1188,  1235,   790,   292,
    1178,   293,  1421,   911,  1020,  1021,     8,    12,    22,   246,
      34,    62,   138,   139,   241,   140,   220,   141,   221,   142,
     228,   143,   222,   144,   219,   145,   225,   302,   146,   237,
     314,   147,   236,   313,   148,   238,   315,   149,   226,   303,
     150,   223,   151,   224,   152,   230,   153,   231,   154,   232,
     155,   227,   156,   234,   157,   235,   158,   229,   159,   239,
     318,   160,   240,   321,   161,   242,   501,   323,   502,   503,
     712,   504,   714,   505,   162,   233,   481,   709,   310,   482,
     483,   484,   163,   243,   164,   244,   165,   245,   338,   339,
     506,   719,   340,   341,   509,   342,   343,   511,   344,   345,
     513,   346,   347,   515,   348,   349,   517,   620,   350,   351,
     519,   622,   518,   352,   353,   523,   354,   355,   525,   356,
     357,   527,   358,   359,   529,   360,   361,   531,   362,   363,
     533,   364,   365,   535
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1214
static const yytype_int16 yypact[] =
{
      68,    79,   113,  -101,   159, -1214, -1214,   -64,   155,   185,
      84,   201, -1214, -1214,   174,   178,   209, -1214, -1214, -1214,
   -1214,   216,  -110, -1214,   161,   191,   226,   148, -1214,   220,
      24,   252, -1214, -1214,   239, -1214,   162,   160,   258,   168,
   -1214,   260, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   237,
     266,   270,   272,   288, -1214, -1214, -1214, -1214, -1214, -1214,
     287,   297,   291, -1214,   169,   204, -1214,   244, -1214, -1214,
   -1214,   311, -1214, -1214, -1214, -1214, -1214,   319,    26, -1214,
     325,   336,   401, -1214, -1214,   403,   665, -1214, -1214,   399,
   -1214,   114, -1214, -1214, -1214, -1214,   344,   342,   411,   200,
   -1214, -1214, -1214, -1214, -1214,   415,   416,   417,   418,    25,
     419, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214,   321,   317,   323,   301, -1214,   348,   353,   426,   240,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214,   242,    15, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   665,
     665,   665,   665,   665,   665, -1214, -1214,   665,   665,   665,
     665,   665,   665, -1214,   665,   665, -1214, -1214, -1214,   269,
     271,   665, -1214,   -65,   -65,   -65,   198, -1214,   428, -1214,
   -1214, -1214, -1214,   346,   354,   430,   274, -1214,   431, -1214,
   -1214, -1214, -1214, -1214,   276,    18,   278,    18,   283,    29,
     285,     7,   294,    32,   424,    18,   425,    18, -1214,   273,
   -1214, -1214, -1214,   433,   435,   437,   439,   440, -1214, -1214,
   -1214, -1214, -1214, -1214,  -119,  -119,   665,   665,   665,   665,
     202,   203,   280,   410,   196,   197,   665,   192,   193,   190,
      30,   188,   187,   429,   500,   539, -1214,   180, -1214, -1214,
     179, -1214,   665,    36, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   175, -1214,
   -1214,   -65, -1214,   -65, -1214,   665, -1214,   -65, -1214,   140,
   -1214,   140, -1214,   296, -1214,   -65, -1214,   -65, -1214,   -65,
   -1214,   665, -1214,   -65, -1214,   -65,   176,   177, -1214,   452,
     360, -1214,   357,    90, -1214,   398,   378,   464,   298, -1214,
     461, -1214, -1214, -1214, -1214, -1214,   466,    64, -1214,   434,
   -1214,   467,   469,   470, -1214, -1214, -1214, -1214, -1214,   436,
   -1214, -1214, -1214, -1214, -1214, -1214,   438, -1214,   472,   473,
     474, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   441,
   -1214,   475,   476, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214,   442, -1214,   477, -1214, -1214, -1214, -1214, -1214,
     427, -1214, -1214, -1214, -1214, -1214,   432, -1214, -1214, -1214,
   -1214, -1214, -1214,   322, -1214, -1214,   480,   481,   483,   484,
     485,   256,   257,   259,   254, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214,   665, -1214, -1214, -1214, -1214,   634,   492,
     493, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214,   222, -1214,   218,   497,   499,
     501, -1214, -1214, -1214, -1214, -1214,    46, -1214,   224, -1214,
     -65, -1214,   212, -1214,   214, -1214,   506,   -65, -1214,   -65,
   -1214, -1214,   228, -1214,   -65, -1214,   -65, -1214,   -65, -1214,
     -65, -1214,   665, -1214,   206, -1214, -1214, -1214,   511, -1214,
   -1214,   495, -1214,   395,   517,   521, -1214, -1214, -1214, -1214,
   -1214,   527,   300, -1214,   525, -1214, -1214, -1214, -1214, -1214,
     533,    65, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   535,
     537,   541, -1214, -1214, -1214,   543,   545, -1214,   547,   549,
   -1214,   555, -1214,   494,   388, -1214,   496,   388, -1214,  -105,
     304,   173, -1214, -1214, -1214,   559,   561, -1214, -1214, -1214,
   -1214,   312, -1214, -1214,   560, -1214, -1214, -1214, -1214, -1214,
   -1214,   565,   566,   306, -1214,   281, -1214, -1214,   567,   277,
   -1214,   279, -1214, -1214,   282,   268,   275,   284,   665, -1214,
     563,   574,   310, -1214, -1214, -1214,   572, -1214, -1214, -1214,
   -1214, -1214,   577,    73, -1214, -1214, -1214, -1214, -1214, -1214,
     314,    55, -1214,   579,   580,   582,   583,   585,   586,   587,
   -1214, -1214, -1214, -1214,   316, -1214, -1214, -1214,   318, -1214,
   -1214, -1214, -1214, -1214, -1214,   107, -1214,   588, -1214,   420,
   -1214,   443, -1214,   590,   591,   593,   597,   598,   599,   600,
     601, -1214,   602, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   343,
     604,   605,   607,   608,   609,   606,   610, -1214,   302, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   665, -1214,
     611, -1214,   505, -1214,   615,   616,   617,    78, -1214, -1214,
   -1214, -1214, -1214, -1214,   324,   122, -1214,   550, -1214,   618,
     620,   621,   622,   623, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   624,
      17, -1214,   471, -1214, -1214, -1214, -1214,   471, -1214, -1214,
   -1214, -1214,   625,   330, -1214, -1214, -1214,   -65,   629,   626,
   -1214, -1214,   627,   628,   631,   632,   633,   635,   637, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214,   630,   643, -1214,
     665, -1214, -1214,   530,   516, -1214, -1214, -1214, -1214,   636,
   -1214,   339,    81, -1214, -1214, -1214, -1214, -1214,   645,   649,
     653,   656, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214,   692,   694,   696,   698,   700, -1214, -1214,   548,   655,
   -1214,   551, -1214,   657, -1214, -1214, -1214,   523, -1214, -1214,
   -1214,   502,   710,   503, -1214,   715,   716,   718,   720,   721,
     722,   723,   724, -1214, -1214, -1214,   444,    41, -1214, -1214,
     638,   725,   719, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   652,   650,
     729,   731,   733,   739,   741,   743,   745,   749,   753, -1214,
     755,   341, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214,   557,   751, -1214, -1214,   761, -1214,   568,   614, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   674,
     765,   788, -1214, -1214, -1214, -1214, -1214,    44, -1214, -1214,
     786,   665,   650,   713, -1214, -1214,   790, -1214,   -65,   794,
     796,   800, -1214, -1214, -1214, -1214, -1214, -1214,   798, -1214,
      33, -1214, -1214, -1214,   802,   205, -1214,   612,   804,   639,
   -1214, -1214, -1214,   614,   806,   356, -1214, -1214,   706, -1214,
     687,   814,   816, -1214,   711,   823,   824, -1214, -1214, -1214,
   -1214, -1214,    50,   825,   740, -1214, -1214, -1214,   744, -1214,
   -1214, -1214,   828,   675, -1214,   830, -1214,   829,   832, -1214,
   -1214, -1214, -1214,   640,   827,   644, -1214, -1214,   646,   358,
     -15,   361, -1214,   833, -1214,   471, -1214, -1214, -1214, -1214,
   -1214,   826,   838,   839, -1214,   732, -1214,   726,   842,   843,
   -1214,   730,   848,   849, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214,   690,   847,   850, -1214,   647,
     844,   663, -1214, -1214, -1214,   662,   363, -1214,   666,   614,
   -1214,   471, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214,   471, -1214, -1214, -1214,   858, -1214,   642,   860,   365,
   -1214, -1214, -1214, -1214,   846,   863,   865, -1214,   757, -1214,
     746,   867,   869, -1214,   877,   879, -1214,   673,   875,   693,
   -1214, -1214,   695,   367, -1214,   686,   614, -1214,   471, -1214,
   -1214, -1214, -1214,   727,   883, -1214, -1214,   735,   369,  -102,
   -1214,   699, -1214, -1214,   916, -1214,   808, -1214,   924,   371,
   -1214, -1214, -1214, -1214,   915,   932,   934, -1214, -1214, -1214,
     728,   928,   748,   737, -1214,   752,   373, -1214,   747,   614,
   -1214,   471, -1214, -1214, -1214, -1214,   754,   940, -1214, -1214,
     758, -1214,   756, -1214, -1214,    20, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214,   942, -1214,   949, -1214,
     834, -1214,   955,   375, -1214, -1214, -1214,   767,   213,   766,
     750, -1214,   763,   379, -1214, -1214,   759,   614, -1214,   471,
   -1214, -1214, -1214, -1214,   952, -1214, -1214,   768, -1214,   769,
   -1214,   954,   770, -1214, -1214,   797,   962,   963, -1214,   969,
   -1214,   966, -1214,   851, -1214, -1214, -1214, -1214,   970,   964,
   -1214, -1214, -1214, -1214,   780,   381, -1214, -1214, -1214,   614,
   -1214,   471, -1214, -1214, -1214, -1214,   967, -1214, -1214,   783,
     781, -1214, -1214,   971,   782, -1214,   975, -1214,  -105, -1214,
   -1214, -1214, -1214,   978, -1214, -1214,   792,   774, -1214, -1214,
     614, -1214,   471, -1214, -1214, -1214,   791, -1214,   795,   793,
   -1214, -1214, -1214,   799,   789,   383, -1214,   982, -1214,   -55,
   -1214, -1214, -1214, -1214, -1214, -1214,   801,   385, -1214,   803,
   -1214,   807, -1214, -1214, -1214,   809,   805,   387, -1214, -1214,
   -1214,   389, -1214,   471, -1214, -1214, -1214,   -45, -1214, -1214,
     -94, -1214, -1214,   614, -1214,   471, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214,   391, -1214,   471, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214,   810, -1214,   -80, -1214,
   -1214, -1214,   835,   983, -1214,   812, -1214, -1214, -1214, -1214,
   -1214, -1214,   811,   -71, -1214, -1214,   985, -1214,   471, -1214,
     -58, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   815, -1214,
   -1214, -1214,   393,   396,   -70,   836, -1214, -1214,   665, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214,   997,   999, -1214,
   -1214, -1214, -1214,   841,  -100, -1214,   998, -1214, -1214, -1214,
   -1214,   691,  1009,  1011,  1012,  1005, -1214, -1214, -1214,  1010,
   -1214,  1015,   813, -1214, -1214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   135,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,   651,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214,    34, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214,   -25, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214,   -85, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214,   445, -1214, -1214,
     -11,     1, -1214, -1214, -1214,   208, -1214,  -246,   211,   760,
     764, -1214, -1214, -1214, -1214,  -627,   215, -1214,   217,   219,
     221, -1214,  -688,  -560,  -774,  -205, -1214,  -758, -1213, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1161, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214,  -115, -1214, -1214,
   -1214, -1214, -1214, -1214,  -160, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214,  -208, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
    -898, -1214, -1214, -1214, -1214,  -345, -1214, -1214, -1214, -1214,
   -1214, -1214,  -219, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,  -227, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214,   677, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214, -1214,
   -1214, -1214, -1214, -1214
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     296,   297,   298,   299,   300,   301,   294,   295,   304,   305,
     306,   307,   308,   309,   655,   311,   312,   366,   367,   854,
     847,   404,   322,   414,   756,   426,   873,   438,   391,   445,
     986,   451,   211,   212,    48,    49,   283,   284,  1013,   391,
     477,   478,    50,    51,    52,   711,   496,   497,   479,   713,
     391,   938,   939,   391,   993,   994,   101,   839,   498,   499,
    1050,  1051,  1309,  1428,   611,   670,   408,   409,  1369,   421,
     422,   285,   909,   611,   734,   735,   391,   461,   462,   463,
     464,   919,   914,   468,   470,  1032,   671,   473,   408,   409,
     410,  1392,     1,  1337,   488,   490,   492,   434,  1296,   611,
     542,   543,   391,   495,  1399,     4,  1417,   914,  1370,    17,
    1418,    18,   672,     6,   508,  1429,   510,   914,   836,    32,
     514,    33,  1385,  1189,  1190,  1368,   512,     7,   524,  1319,
     526,  1393,   528,   563,   897,   564,   532,   612,   534,   645,
     611,   646,   530,   391,  1400,  1339,   612,   749,   750,   751,
     752,   753,   739,  1085,   740,  1367,  1086,   940,    42,    43,
     941,   995,     9,   996,   828,   818,    11,   819,  1052,  1053,
      66,    67,   612,   749,   750,   751,   752,   753,    72,    73,
     831,  1135,    87,    88,    13,   392,   393,   452,   285,  1233,
     102,  1014,    16,   286,   287,   892,   392,   393,   544,   545,
     213,   214,   215,   216,    21,   828,    23,   392,   393,    26,
     392,   393,    29,   612,    90,    91,   169,   170,   753,   829,
     830,   831,   324,    31,   325,    38,   326,    35,   327,    41,
     328,    47,   329,   182,   330,   183,   331,   184,   332,   872,
     333,   185,   334,   186,   335,   187,   336,   188,   337,   189,
     259,   260,   278,   279,   601,    60,   402,    61,   412,   603,
     424,    71,   436,    63,   443,    79,   449,    77,   403,    80,
     413,  1225,   425,    81,   437,    82,   444,  1096,   450,   316,
     317,   319,   320,   615,   381,   382,   388,   389,   398,   399,
     619,    83,   621,   405,   406,   418,   419,   624,    84,   625,
      85,   626,    86,   627,   431,   432,   521,   522,   555,   556,
     637,   638,    95,   628,   680,   681,   717,   718,    98,  1267,
     731,   732,   100,  1136,   746,   747,   771,   772,   776,   777,
     781,   782,   105,  1140,   823,   824,   213,   214,   215,   216,
     856,   857,    53,   106,   213,   214,   215,   216,   480,   883,
     884,   969,   970,   500,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,  1017,  1018,  1034,  1035,  1080,  1081,
    1179,  1090,  1091,  1127,  1128,  1145,  1146,  1170,  1171,  1184,
    1185,  1199,  1200,  1218,  1219,  1242,  1243,  1247,  1248,  1260,
    1261,  1291,  1292,  1332,  1333,  1344,  1345,  1355,  1356,  1360,
    1361,  1376,  1377,  1407,  1408,   755,  1412,  1413,   107,   728,
     110,   166,   178,  1226,   181,  1236,  1237,   175,   207,   208,
     209,   210,   218,   247,   248,   250,   252,   251,   255,   258,
     368,   369,   374,   380,   377,   440,   446,   456,   386,   457,
     452,   458,   459,   460,   465,  1373,   471,   466,   474,   472,
     476,   475,   485,   486,   493,   494,   516,   507,   770,   538,
     536,  1268,   541,   537,   539,   550,   551,   554,   560,   562,
     568,   569,   570,   571,   572,   574,   575,   576,   578,   579,
     573,   581,   582,   592,   593,   577,   594,   588,   580,   585,
     597,   595,   596,   598,   600,   604,   605,   599,   607,   834,
     606,   608,   609,  1297,   616,   610,  1311,  1312,   617,   810,
     618,  1314,   614,   111,   630,   112,   631,   113,   629,   114,
     634,   115,   633,   116,   635,   117,   467,   118,   623,   119,
     636,   120,   642,   121,  1320,   122,   644,   123,   652,   124,
     663,   125,   661,   126,   653,   127,   666,   128,   654,   129,
     656,   130,   657,   131,   658,   132,   659,   133,   660,   134,
     861,   135,   706,   136,   707,   137,   708,   710,   715,   716,
     721,   720,   725,   722,   729,  1365,   890,   723,   730,   736,
     738,   726,   762,   763,   724,   764,   765,  1374,   766,   767,
     768,   876,   727,   792,   793,   770,   794,   788,  1381,   787,
     795,   796,   797,   798,   799,   801,   800,   802,   803,   791,
     804,   805,   806,   807,   811,   812,   809,   808,   815,   816,
     817,   841,   840,   842,   843,   844,   845,   879,   848,   855,
    1398,   846,   862,   874,   865,   866,   878,   863,   867,   868,
     869,   770,   870,   111,   871,   112,   875,   113,   900,   114,
     770,   115,   901,   116,   881,   117,   902,   118,   469,   119,
     903,   120,   111,   121,   112,   122,   113,   123,   114,   124,
     115,   125,   116,   126,   117,   127,   118,   128,   119,   129,
     120,   130,   121,   131,   122,   132,   123,   133,   124,   134,
     125,   135,   126,   136,   127,   137,   128,   487,   129,   904,
     130,   905,   131,   906,   132,   907,   133,   908,   134,   910,
     135,   912,   136,   914,   137,   917,   920,   925,   929,   930,
     923,   931,   926,   932,   933,   934,   935,   936,   950,   954,
     951,  1008,  1004,   111,   956,   112,   959,   113,   960,   114,
     961,   115,   962,   116,   963,   117,   964,   118,   965,   119,
     948,   120,   966,   121,   937,   122,   967,   123,   968,   124,
     976,   125,   979,   126,   980,   127,   984,   128,   991,   129,
     489,   130,   111,   131,   112,   132,   113,   133,   114,   134,
     115,   135,   116,   136,   117,   137,   118,   987,   119,   981,
     120,   992,   121,  1003,   122,  1005,   123,  1009,   124,  1010,
     125,  1007,   126,  1011,   127,  1012,   128,  1041,   129,  1033,
     130,   491,   131,  1015,   132,  1025,   133,  1022,   134,  1039,
     135,  1042,   136,  1043,   137,  1044,  1048,  1049,  1059,  1061,
    1060,  1063,  1066,  1064,  1026,  1067,  1405,  1065,  1071,  1073,
    1095,  1100,  1101,  1077,  1098,  1107,  1102,  1068,  1104,  1105,
    1106,  1111,  1112,  1113,  1114,  1119,  1116,  1115,  1121,  1124,
    1132,  1142,  1143,  1144,  1148,  1432,  1150,   111,  1151,   112,
    1154,   113,  1152,   114,  1155,   115,  1156,   116,  1441,   117,
    1157,   118,  1158,   119,  1159,   120,  1162,   121,  1164,   122,
    1175,   123,  1167,   124,  1182,   125,   602,   126,   111,   127,
     112,   128,   113,   129,   114,   130,   115,   131,   116,   132,
     117,   133,   118,   134,   119,   135,   120,   136,   121,   137,
     122,  1195,   123,  1196,   124,  1181,   125,  1198,   126,  1197,
     127,  1183,   128,  1202,   129,  1204,   130,  1205,   131,  1209,
     132,  1206,   133,  1211,   134,  1238,   135,  1214,   136,  1215,
     137,  1229,  1228,  1223,  1230,  1231,  1239,  1240,  1241,  1245,
    1257,  1253,  1256,  1270,  1272,  1275,  1279,  1265,  1273,  1280,
    1281,  1276,  1282,  1283,  1285,  1286,  1284,  1288,  1299,  1301,
    1302,  1313,  1306,  1307,   770,   770,  1310,  1315,  1318,  1322,
    1329,  1323,  1324,  1338,  1388,  1018,  1396,  1328,  1341,  1422,
    1425,  1349,  1426,  1350,  1427,  1433,  1352,  1351,  1389,  1434,
    1384,  1391,  1436,  1406,  1437,  1438,  1439,  1442,  1443,   952,
    1103,   540,  1040,  1153,  1191,  1234,  1278,  1387,   520,  1444,
     889,   427,   669,   891,     0,   428,     0,   893,     0,   894,
       0,   895,     0,   896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   770,   770,     0,     0,     0,
     770,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1423
};

static const yytype_int16 yycheck[] =
{
     219,   220,   221,   222,   223,   224,   211,   212,   227,   228,
     229,   230,   231,   232,   574,   234,   235,   244,   245,   777,
       3,   267,   241,   269,   651,   271,   800,   273,    21,   275,
     928,   277,     7,     8,    10,    11,    21,    22,     5,    21,
      10,    11,    18,    19,    20,   605,    10,    11,    18,   609,
      21,    10,    11,    21,    10,    11,    30,   745,    22,    23,
      10,    11,  1275,   163,    18,   170,    59,    60,   162,    62,
      63,   173,   846,    18,   634,   635,    21,   296,   297,   298,
     299,   855,   162,   302,   303,   983,   191,   306,    59,    60,
      61,   162,    24,  1306,   313,   314,   315,    65,  1259,    18,
      10,    11,    21,   322,   162,    26,   176,   162,   202,    25,
     180,    27,   217,     0,   341,   215,   343,   162,   745,   229,
     347,   231,   202,   225,   226,  1338,   345,   228,   355,  1290,
     357,   202,   359,    69,   822,    71,   363,    91,   365,    74,
      18,    76,   361,    21,   202,   200,    91,    92,    93,    94,
      95,    96,    79,   168,    81,   200,   171,   116,    10,    11,
     119,   117,     3,   119,    83,    87,   230,    89,   118,   119,
      10,    11,    91,    92,    93,    94,    95,    96,    10,    11,
      99,  1079,    13,    14,    29,   178,   179,   167,   173,   169,
     164,   158,     7,   178,   179,   822,   178,   179,   108,   109,
     319,   320,   321,   322,     3,    83,    32,   178,   179,    31,
     178,   179,     3,    91,    10,    11,   102,   103,    96,    97,
      98,    99,   287,     7,   289,    34,   291,    66,   293,     3,
     295,    11,   297,    33,   299,    35,   301,    37,   303,   799,
     305,    41,   307,    43,   309,    45,   311,    47,   313,    49,
      10,    11,    10,    11,   473,     3,   267,    18,   269,   478,
     271,     3,   273,   101,   275,    28,   277,     7,   267,     3,
     269,  1169,   271,     3,   273,     3,   275,  1035,   277,    10,
      11,    10,    11,   510,    10,    11,    10,    11,    10,    11,
     517,     3,   519,    10,    11,    10,    11,   524,    11,   526,
       3,   528,    11,   530,    10,    11,    10,    11,    10,    11,
      10,    11,    68,   532,    10,    11,    10,    11,     7,  1217,
      10,    11,     3,  1081,    10,    11,    10,    11,    10,    11,
     223,   224,     7,  1091,    10,    11,   319,   320,   321,   322,
      10,    11,   318,     7,   319,   320,   321,   322,   318,    10,
      11,    10,    11,   317,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   159,   160,    10,    11,    10,    11,
    1128,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   174,   175,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   651,    10,    11,     7,   628,
       7,    12,    70,  1171,     3,  1189,  1190,    73,     3,     3,
       3,     3,     3,   102,   107,   102,    78,   126,    75,     3,
     232,     3,    86,     3,    80,    11,    11,     4,     7,     4,
     167,     4,     3,     3,   242,  1343,   250,   244,   256,   252,
     260,   258,   264,   266,   274,   276,   316,   282,   663,     7,
     284,  1219,   105,   286,   104,    67,    88,     3,     7,     3,
      36,     4,     3,     3,    38,     3,     3,     3,     3,     3,
      42,     4,    55,     3,     3,    44,     3,   165,    46,    57,
     234,     7,     7,   236,   240,     3,     3,   238,   280,   745,
     278,     4,     3,  1261,   292,     4,  1280,  1281,   294,   728,
       4,  1285,   288,   233,     3,   235,    21,   237,   312,   239,
       3,   241,   127,   243,     3,   245,   246,   247,   300,   249,
       3,   251,     7,   253,  1292,   255,     3,   257,     3,   259,
     152,   261,    48,   263,     7,   265,    50,   267,     7,   269,
       7,   271,     7,   273,     7,   275,     7,   277,     3,   279,
     787,   281,     3,   283,     3,   285,   254,     7,     3,     3,
       3,   290,   304,   296,    11,  1333,   822,   298,     4,     7,
       3,   306,     3,     3,   302,     3,     3,  1345,     3,     3,
       3,   810,   308,     3,     3,   800,     3,   177,  1356,    11,
       3,     3,     3,     3,     3,   262,     4,     3,     3,   166,
       3,     3,     3,     7,     3,   110,   314,     7,     3,     3,
       3,     3,    72,     3,     3,     3,     3,   111,   157,     4,
    1388,     7,     3,     3,     7,     7,   106,    11,     7,     7,
       7,   846,     7,   233,     7,   235,     3,   237,     3,   239,
     855,   241,     3,   243,    18,   245,     3,   247,   248,   249,
       4,   251,   233,   253,   235,   255,   237,   257,   239,   259,
     241,   261,   243,   263,   245,   265,   247,   267,   249,   269,
     251,   271,   253,   273,   255,   275,   257,   277,   259,   279,
     261,   281,   263,   283,   265,   285,   267,   268,   269,     7,
     271,     7,   273,     7,   275,     7,   277,     7,   279,   161,
     281,    56,   283,   162,   285,    58,   193,     7,     3,     3,
     218,     3,   219,     3,     3,     3,     3,     3,     3,    77,
      11,   958,   951,   233,    84,   235,     7,   237,     7,   239,
       7,   241,     3,   243,     3,   245,     3,   247,     3,   249,
     112,   251,     3,   253,   310,   255,     3,   257,     3,   259,
     203,   261,    11,   263,     3,   265,   152,   267,     3,   269,
     270,   271,   233,   273,   235,   275,   237,   277,   239,   279,
     241,   281,   243,   283,   245,   285,   247,   113,   249,   221,
     251,     3,   253,     7,   255,    82,   257,     3,   259,     3,
     261,    11,   263,     3,   265,     7,   267,   120,   269,     3,
     271,   272,   273,    11,   275,    11,   277,   205,   279,   113,
     281,     7,   283,     7,   285,   114,     3,     3,     3,    85,
      90,     3,     3,   158,   195,     3,  1396,     7,    11,   195,
       7,     3,     3,   197,    18,   115,   114,   207,   122,     7,
       7,     3,     3,   163,     7,    11,   209,     7,   195,   197,
     194,     3,   220,     3,    18,  1425,     3,   233,     3,   235,
     124,   237,   115,   239,     7,   241,     7,   243,  1438,   245,
       3,   247,     3,   249,   211,   251,    11,   253,   195,   255,
     204,   257,   197,   259,    11,   261,   262,   263,   233,   265,
     235,   267,   237,   269,   239,   271,   241,   273,   243,   275,
     245,   277,   247,   279,   249,   281,   251,   283,   253,   285,
     255,   222,   257,     7,   259,   198,   261,     3,   263,   121,
     265,   196,   267,    18,   269,     3,   271,     3,   273,    11,
     275,   213,   277,   195,   279,     3,   281,   210,   283,   197,
     285,    11,   198,   206,   196,   199,     7,   123,     3,   192,
     197,   195,   212,    11,   196,    11,   169,   208,   199,     7,
       7,   201,     3,     7,     4,    11,   125,   197,    11,   196,
     199,     3,    11,   201,  1189,  1190,    11,   195,   214,   198,
     201,   196,   199,    11,    11,   160,    11,   198,   197,   163,
       3,   198,     3,   196,   163,     7,   201,   198,   196,   318,
     200,   200,     3,   198,     3,     3,    11,     7,     3,   884,
    1045,   370,   988,  1108,  1139,  1185,  1234,  1372,   351,   216,
     822,   271,   587,   822,    -1,   271,    -1,   822,    -1,   822,
      -1,   822,    -1,   822,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1280,  1281,    -1,    -1,    -1,
    1285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1408
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   324,   328,    26,   329,     0,   228,   809,     3,
     330,   230,   810,    29,   340,   341,     7,    25,    27,   331,
     332,     3,   811,    32,   347,   348,    31,   342,   541,     3,
     334,     7,   229,   231,   813,    66,   415,   416,    34,   349,
     542,     3,    10,    11,   343,   344,   345,    11,    10,    11,
      18,    19,    20,   318,   333,   335,   336,   337,   338,   339,
       3,    18,   814,   101,   483,   484,    10,    11,   417,   418,
     419,     3,    10,    11,   350,   351,   352,     7,   346,    28,
       3,     3,     3,     3,    11,     3,    11,    13,    14,   325,
      10,    11,   485,   486,   487,    68,   420,   421,     7,   353,
       3,    30,   164,   595,   596,     7,     7,     7,   566,   568,
       7,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   253,   255,   257,   259,   261,   263,   265,   267,   269,
     271,   273,   275,   277,   279,   281,   283,   285,   815,   816,
     818,   820,   822,   824,   826,   828,   831,   834,   837,   840,
     843,   845,   847,   849,   851,   853,   855,   857,   859,   861,
     864,   867,   877,   885,   887,   889,    12,   326,   327,   102,
     103,   488,   489,   532,   533,    73,   434,   435,    70,   422,
     545,     3,    33,    35,    37,    41,    43,    45,    47,    49,
     354,   355,   356,   361,   362,   367,   368,   373,   374,   379,
     380,   385,   386,   400,   401,   597,   598,     3,     3,     3,
       3,     7,     8,   319,   320,   321,   322,   569,     3,   827,
     819,   821,   825,   844,   846,   829,   841,   854,   823,   860,
     848,   850,   852,   878,   856,   858,   835,   832,   838,   862,
     865,   817,   868,   886,   888,   890,   812,   102,   107,   490,
     102,   126,    78,   456,   457,    75,   436,   546,     3,    10,
      11,   423,   424,   425,   357,   358,   363,   364,   369,   370,
     375,   376,   381,   382,   387,   388,   402,   403,    10,    11,
     603,   604,   605,    21,    22,   173,   178,   179,   599,   600,
     601,   602,   802,   804,   568,   568,   815,   815,   815,   815,
     815,   815,   830,   842,   815,   815,   815,   815,   815,   815,
     881,   815,   815,   836,   833,   839,    10,    11,   863,    10,
      11,   866,   815,   870,   287,   289,   291,   293,   295,   297,
     299,   301,   303,   305,   307,   309,   311,   313,   891,   892,
     895,   896,   898,   899,   901,   902,   904,   905,   907,   908,
     911,   912,   916,   917,   919,   920,   922,   923,   925,   926,
     928,   929,   931,   932,   934,   935,   891,   891,   232,     3,
     491,   492,   493,   535,    86,   474,   475,    80,   458,   547,
       3,    10,    11,   437,   438,   439,     7,   427,    10,    11,
     360,    21,   178,   179,   359,   543,   544,   550,    10,    11,
     366,   365,   543,   544,   550,    10,    11,   372,    59,    60,
      61,   371,   543,   544,   550,   552,   553,   554,    10,    11,
     378,    62,    63,   377,   543,   544,   550,   552,   553,   555,
     556,    10,    11,   384,    65,   383,   543,   544,   550,   557,
      11,   390,   389,   543,   544,   550,    11,   405,   404,   543,
     544,   550,   167,   606,   607,   608,     4,     4,     4,     3,
       3,   815,   815,   815,   815,   242,   244,   246,   815,   248,
     815,   250,   252,   815,   256,   258,   260,    10,    11,    18,
     318,   879,   882,   883,   884,   264,   266,   268,   815,   270,
     815,   272,   815,   274,   276,   815,    10,    11,    22,    23,
     317,   869,   871,   872,   874,   876,   893,   282,   891,   897,
     891,   900,   815,   903,   891,   906,   316,   909,   915,   913,
     915,    10,    11,   918,   891,   921,   891,   924,   891,   927,
     815,   930,   891,   933,   891,   936,   284,   286,     7,   104,
     492,   105,    10,    11,   108,   109,   534,   536,   538,   539,
      67,    88,   476,   549,     3,    10,    11,   459,   460,   461,
       7,   441,     3,    69,    71,   426,   428,   429,    36,     4,
       3,     3,    38,    42,     3,     3,     3,    44,     3,     3,
      46,     4,    55,   391,   392,    57,   406,   407,   165,   625,
     609,   610,     3,     3,     3,     7,     7,   234,   236,   238,
     240,   815,   262,   815,     3,     3,   278,   280,     4,     3,
       4,    18,    91,   558,   288,   891,   292,   294,     4,   891,
     910,   891,   914,   300,   891,   891,   891,   891,   815,   312,
       3,    21,   494,   127,     3,     3,     3,    10,    11,   477,
     478,   479,     7,   463,     3,    74,    76,   440,   442,   443,
     430,   431,     3,     7,     7,   566,     7,     7,     7,     7,
       3,    48,   399,   152,   393,   540,    50,   414,   408,   540,
     170,   191,   217,   626,   627,   628,   767,   768,   770,   771,
      10,    11,   624,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,     3,     3,   254,   880,
       7,   566,   873,   566,   875,     3,     3,    10,    11,   894,
     290,     3,   296,   298,   302,   304,   306,   308,   815,    11,
       4,    10,    11,   495,   566,   566,     7,   480,     3,    79,
      81,   462,   464,   465,   444,   445,    10,    11,   433,    92,
      93,    94,    95,    96,   432,   550,   558,   559,   561,   562,
     563,   565,     3,     3,     3,     3,     3,     3,     3,   567,
     568,    10,    11,   394,   395,   396,    10,    11,   409,   410,
     411,   223,   224,   629,   630,   631,   632,    11,   177,   772,
     801,   166,     3,     3,     3,     3,     3,     3,     3,     3,
       4,   262,     3,     3,     3,     3,     3,     7,     7,   314,
     815,     3,   110,   496,   497,     3,     3,     3,    87,    89,
     481,   466,   467,    10,    11,   447,   448,   449,    83,    97,
      98,    99,   446,   548,   550,   551,   558,   560,   564,   565,
      72,     3,     3,     3,     3,     3,     7,     3,   157,   397,
     570,   571,   578,   412,   570,     4,    10,    11,   633,   634,
     635,   891,     3,    11,   773,     7,     7,     7,     7,     7,
       7,     7,   566,   567,     3,     3,   815,   498,   106,   111,
     509,    18,   482,    10,    11,   469,   470,   471,   468,   548,
     550,   551,   558,   559,   561,   562,   563,   565,   450,   452,
       3,     3,     3,     4,     7,     7,     7,     7,     7,   567,
     161,   806,    56,   398,   162,   572,   573,    58,   413,   567,
     193,   637,   638,   218,   769,     7,   219,   775,   776,     3,
       3,     3,     3,     3,     3,     3,     3,   310,    10,    11,
     116,   119,   499,   500,   501,   502,   503,   510,   112,   521,
       3,    11,   452,   472,    77,   451,    84,   453,   454,     7,
       7,     7,     3,     3,     3,     3,     3,     3,     3,    10,
      11,   579,   580,   581,   574,   575,   203,   648,   649,    11,
       3,   221,   782,   783,   152,   777,   803,   113,   504,   505,
     506,     3,     3,    10,    11,   117,   119,   511,   512,   513,
     514,   515,   522,     7,   815,    82,   473,    11,   891,     3,
       3,     3,     7,     5,   158,    11,   577,   159,   160,   576,
     807,   808,   205,   659,   660,    11,   195,   639,   640,   641,
     789,   784,   803,     3,    10,    11,   778,   779,   780,   113,
     505,   120,     7,     7,   114,   516,   517,   518,     3,     3,
      10,    11,   118,   119,   523,   524,   525,   526,   537,     3,
      90,    85,   455,     3,   158,     7,     3,     3,   207,   699,
     700,    11,   661,   195,   650,   651,   652,   197,   646,   647,
      10,    11,   642,   643,   644,   168,   171,   774,   790,   791,
      10,    11,   785,   786,   787,     7,   570,   781,    18,   507,
       3,     3,   114,   517,   122,     7,     7,   115,   527,   528,
     529,     3,     3,   163,     7,     7,   209,   730,   731,    11,
     701,   195,   662,   663,   197,   657,   658,    10,    11,   653,
     654,   655,   194,   587,   588,   803,   570,   645,   792,   793,
     570,   788,     3,   220,     3,    10,    11,   508,    18,   519,
       3,     3,   115,   528,   124,     7,     7,     3,     3,   211,
     741,   742,    11,   732,   195,   702,   703,   197,   668,   669,
      10,    11,   664,   665,   666,   204,   591,   592,   803,   570,
     656,   198,    11,   196,    10,    11,   797,   798,   799,   225,
     226,   600,   794,   795,   796,   222,     7,   121,     3,    10,
      11,   520,    18,   530,     3,     3,   213,   752,   753,    11,
     743,   195,   733,   734,   210,   197,   708,   709,    10,    11,
     704,   705,   706,   206,   670,   803,   570,   667,   198,    11,
     196,   199,   589,   169,   607,   800,   567,   567,     3,     7,
     123,     3,    10,    11,   531,   192,   636,   174,   175,   754,
     755,   756,   757,   195,   744,   745,   212,   197,   739,   740,
      10,    11,   735,   736,   737,   208,   710,   803,   570,   707,
      11,   671,   196,   199,   593,    11,   201,   590,   625,   169,
       7,     7,     3,     7,   125,     4,    11,   758,   197,   750,
     751,    10,    11,   746,   747,   748,   591,   570,   738,    11,
     711,   196,   199,   672,   673,   674,    11,   201,   594,   571,
      11,   567,   567,     3,   567,   195,   759,   760,   214,   591,
     570,   749,   198,   196,   199,   712,   713,   714,   198,   201,
     679,   680,    10,    11,   675,   676,   677,   571,    11,   200,
     582,   197,   765,   766,    10,    11,   761,   762,   763,   198,
     196,   198,   201,   719,   720,    10,    11,   715,   716,   717,
      10,    11,   681,   682,   683,   570,   678,   200,   571,   162,
     202,   583,   584,   803,   570,   764,    10,    11,   721,   722,
     723,   570,   718,   684,   200,   202,   585,   808,    11,   196,
     724,   200,   162,   202,   685,   686,    11,   586,   570,   162,
     202,   725,   726,   687,   688,   566,   198,    10,    11,   727,
     728,   729,    10,    11,   691,   692,   693,   176,   180,   689,
     690,   805,   163,   815,   694,     3,     3,   163,   163,   215,
     695,   696,   566,     7,   318,   697,     3,     3,     3,    11,
     698,   566,     7,     3,   216
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

  case 261:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 268:

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

  case 269:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 270:

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

  case 273:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 274:

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

  case 276:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 281:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 286:

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

  case 287:

    {
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 288:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    break;

  case 289:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }
    break;

  case 294:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 296:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stagevarcount++;
}
    break;

  case 300:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 305:

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

  case 306:

    {
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 307:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    break;

  case 308:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }
    break;

  case 313:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 315:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageconcount++;
}
    break;

  case 318:

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

  case 319:

    {
      parserData->stageObjectivesON = true;
    }
    break;

  case 324:

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

  case 325:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    break;

  case 326:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }
    break;

  case 331:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 333:

    {
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageobjcount++;
}
    break;

  case 336:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 337:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}
    break;

  case 342:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    break;

  case 343:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }
    break;

  case 344:

    {
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 345:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 346:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}
    break;

  case 347:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOfEl = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 348:

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

  case 349:

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

  case 350:

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

  case 351:

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

  case 352:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 353:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 354:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 355:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix terms cannot be negative");
    parserData->numberOfMatrixTerms = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 356:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
    parserData->numberOfMatrixExpr = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 357:

    {
    if (parserData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->namePresent = true;
    parserData->name = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 358:

    {
    if (parserData->shapePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "shape attribute previously set");
    parserData->shapePresent = true;
    parserData->shape = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 359:

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

  case 360:

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

  case 361:

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

  case 362:

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

  case 363:

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

  case 364:

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

  case 365:

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

  case 366:

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

  case 367:

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

  case 368:

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

  case 369:

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

  case 370:

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

  case 371:

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

  case 372:

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

  case 373:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 374:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 382:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 387:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 393:

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

  case 399:

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

  case 403:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 406:

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

  case 407:

    {
}
    break;

  case 408:

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

  case 411:

    {
}
    break;

  case 412:

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

  case 416:

    {
    //osglData->...;
}
    break;

  case 424:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        if (verifyMatrixType(osglData->matrixTypeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 425:

    { 
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 426:

    { 
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 427:

    { 
    if (osglData->matrixTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->matrixTypeAttributePresent = true;   
    osglData->matrixTypeAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 448:

    { 
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    osglData->baseMatrixIdxAttributePresent = true;   
    osglData->baseMatrixIdxAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 449:

    { 
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 450:

    { 
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 451:

    { 
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 452:

    { 
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 453:

    { 
    if (osglData->baseMatrixEndRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row cannot be negative");
    osglData->baseMatrixEndRowAttributePresent = true;   
    osglData->baseMatrixEndRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 454:

    { 
    if (osglData->baseMatrixEndColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col cannot be negative");
    osglData->baseMatrixEndColAttributePresent = true;   
    osglData->baseMatrixEndColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 455:

    { 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
}
    break;

  case 458:

    {
    osglData->baseTransposeAttribute = true;
}
    break;

  case 459:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->baseTransposeAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->baseTransposeAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
//    free($2);
}
    break;

  case 460:

    {
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
}
    break;

  case 474:

    {
    osglData->rowMajorAttribute = true;
}
    break;

  case 475:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->rowMajorAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->rowMajorAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 485:

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

  case 486:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 492:

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

  case 493:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 498:

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

  case 499:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 505:

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

  case 506:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 511:

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

  case 512:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 518:

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

  case 519:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 520:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 524:

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

  case 525:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 533:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 541:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 547:

    {
}
    break;

  case 555:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
}
    break;

  case 557:

    {
}
    break;

  case 558:

    {
}
    break;

  case 563:

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

  case 564:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 570:

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

  case 571:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 572:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 576:

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

  case 577:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 585:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 593:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 602:

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

  case 603:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 609:

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

  case 610:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 615:

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

  case 616:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 622:

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

  case 623:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 631:

    {
    osglData->excludeIfSetAttribute = true;
}
    break;

  case 632:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->excludeIfSetAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->excludeIfSetAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->excludeIfSetAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "excludeIfSet attribute in <baseMatrix> element must be \"true\" or \"false\"");
//    free($2);
}
    break;

  case 634:

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

  case 635:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 641:

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

  case 642:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 651:

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

  case 652:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 653:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 659:

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

  case 660:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 661:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 676:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 677:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
    osglData->blockRowIdxAttributePresent = true;        
    osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 678:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
    osglData->blockColIdxAttributePresent = true;        
    osglData->blockColIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 685:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 686:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 687:

    {
    if (osglData->numberOfElAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElAttributePresent = true;        
    osglData->numberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 688:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 689:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 690:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 691:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 692:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 694:

    {  if (osnlData->nlnodecount < osnlData->tmpnlcount)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   }
    break;

  case 695:

    { if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osnlData->tmpnlcount = (yyvsp[(3) - (5)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
    osinstance->instanceData->nonlinearExpressions->nl[ i] = new Nl();
}
}
    break;

  case 697:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
    osnlData->nlNodeVec[ 0]->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    osnlData->nlnodecount++;
}
    break;

  case 699:

    {
    if(osnlData->nlnodecount >= osnlData->tmpnlcount) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
}
    break;

  case 700:

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

  case 728:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 730:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 732:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 734:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 736:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 738:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 740:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 741:

    {
    osnlData->sumVec.back()->m_mChildren = new OSnLNode*[ osnlData->sumVec.back()->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 743:

    { osnlData->sumVec.back()->inumberOfChildren++; }
    break;

  case 744:

    {
    
    osnlData->nlNodePoint =   new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 745:

    {
    osnlData->allDiffVec.back()->m_mChildren = new OSnLNode*[ osnlData->allDiffVec.back()->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 747:

    { osnlData->allDiffVec.back()->inumberOfChildren++; }
    break;

  case 748:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 749:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 751:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 752:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 753:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 755:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 756:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 757:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 759:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 760:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 762:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 764:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 766:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 768:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 770:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 772:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 773:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 774:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 775:

    {
}
    break;

  case 776:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 777:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 778:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 782:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 786:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 787:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 792:

    {if(osnlData->numbertypeattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
            osnlData->numbertypeattON = true; }
    break;

  case 793:

    {if(osnlData->numbervalueattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
            osnlData->numbervalueattON = true; }
    break;

  case 794:

    {if(osnlData->numberidattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
            osnlData->numberidattON = true; }
    break;

  case 795:

    {
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 797:

    {
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 799:

    {/*if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");*/
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 800:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 801:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 803:

    {
    osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
    osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 808:

    {if(osnlData->variablecoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; }
    break;

  case 809:

    {if(osnlData->variableidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
            }
    break;

  case 810:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 811:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 812:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 814:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 816:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 832:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->OSnLMNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 833:

    {osnlData->matrixidxattON = false;}
    break;

  case 836:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 838:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 841:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 844:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 847:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 850:

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

  case 859:

    { 
    osnlData->includeDiagonalAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 861:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 865:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 868:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 871:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 874:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 877:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 880:

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


