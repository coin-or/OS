
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
     EMPTYNEGATIVEPATTERNATT = 429,
     NEGATIVEPATTERNATT = 430,
     CONSTANTATT = 431,
     NUMBEROFBLOCKSATT = 432,
     NUMBEROFCOLUMNSATT = 433,
     NUMBEROFROWSATT = 434,
     NUMBEROFVALUESATT = 435,
     NUMBEROFVARIDXATT = 436,
     BASEMATRIXIDXATT = 437,
     TARGETMATRIXFIRSTROWATT = 438,
     TARGETMATRIXFIRSTCOLATT = 439,
     BASEMATRIXSTARTROWATT = 440,
     BASEMATRIXSTARTCOLATT = 441,
     BASEMATRIXENDROWATT = 442,
     BASEMATRIXENDCOLATT = 443,
     SCALARMULTIPLIERATT = 444,
     EMPTYBASETRANSPOSEATT = 445,
     BASETRANSPOSEATT = 446,
     ELEMENTSSTART = 447,
     ELEMENTSEND = 448,
     CONSTANTELEMENTSSTART = 449,
     CONSTANTELEMENTSEND = 450,
     STARTVECTORSTART = 451,
     STARTVECTOREND = 452,
     NONZEROSSTART = 453,
     NONZEROSEND = 454,
     INDEXESSTART = 455,
     INDEXESEND = 456,
     VALUESSTART = 457,
     VALUESEND = 458,
     VARREFERENCEELEMENTSSTART = 459,
     VARREFERENCEELEMENTSEND = 460,
     LINEARELEMENTSSTART = 461,
     LINEARELEMENTSEND = 462,
     GENERALELEMENTSSTART = 463,
     GENERALELEMENTSEND = 464,
     CONREFERENCEELEMENTSSTART = 465,
     CONREFERENCEELEMENTSEND = 466,
     OBJREFERENCEELEMENTSSTART = 467,
     OBJREFERENCEELEMENTSEND = 468,
     PATTERNELEMENTSSTART = 469,
     PATTERNELEMENTSEND = 470,
     VARIDXSTART = 471,
     VARIDXEND = 472,
     TRANSFORMATIONSTART = 473,
     TRANSFORMATIONEND = 474,
     COLOFFSETSSTART = 475,
     COLOFFSETSEND = 476,
     ROWOFFSETSSTART = 477,
     ROWOFFSETSEND = 478,
     EMPTYROWMAJORATT = 479,
     ROWMAJORATT = 480,
     BLOCKROWIDXATT = 481,
     BLOCKCOLIDXATT = 482,
     DUMMY = 483,
     NONLINEAREXPRESSIONSSTART = 484,
     NONLINEAREXPRESSIONSEND = 485,
     NUMBEROFNONLINEAREXPRESSIONS = 486,
     NLSTART = 487,
     NLEND = 488,
     POWERSTART = 489,
     POWEREND = 490,
     PLUSSTART = 491,
     PLUSEND = 492,
     MINUSSTART = 493,
     MINUSEND = 494,
     DIVIDESTART = 495,
     DIVIDEEND = 496,
     LNSTART = 497,
     LNEND = 498,
     SQRTSTART = 499,
     SQRTEND = 500,
     SUMSTART = 501,
     SUMEND = 502,
     PRODUCTSTART = 503,
     PRODUCTEND = 504,
     EXPSTART = 505,
     EXPEND = 506,
     NEGATESTART = 507,
     NEGATEEND = 508,
     IFSTART = 509,
     IFEND = 510,
     SQUARESTART = 511,
     SQUAREEND = 512,
     COSSTART = 513,
     COSEND = 514,
     SINSTART = 515,
     SINEND = 516,
     VARIABLESTART = 517,
     VARIABLEEND = 518,
     ABSSTART = 519,
     ABSEND = 520,
     ERFSTART = 521,
     ERFEND = 522,
     MAXSTART = 523,
     MAXEND = 524,
     ALLDIFFSTART = 525,
     ALLDIFFEND = 526,
     MINSTART = 527,
     MINEND = 528,
     ESTART = 529,
     EEND = 530,
     PISTART = 531,
     PIEND = 532,
     TIMESSTART = 533,
     TIMESEND = 534,
     NUMBERSTART = 535,
     NUMBEREND = 536,
     MATRIXDETERMINANTSTART = 537,
     MATRIXDETERMINANTEND = 538,
     MATRIXTRACESTART = 539,
     MATRIXTRACEEND = 540,
     MATRIXTOSCALARSTART = 541,
     MATRIXTOSCALAREND = 542,
     MATRIXDIAGONALSTART = 543,
     MATRIXDIAGONALEND = 544,
     MATRIXDOTTIMESSTART = 545,
     MATRIXDOTTIMESEND = 546,
     MATRIXLOWERTRIANGLESTART = 547,
     MATRIXLOWERTRIANGLEEND = 548,
     MATRIXUPPERTRIANGLESTART = 549,
     MATRIXUPPERTRIANGLEEND = 550,
     MATRIXMERGESTART = 551,
     MATRIXMERGEEND = 552,
     MATRIXMINUSSTART = 553,
     MATRIXMINUSEND = 554,
     MATRIXPLUSSTART = 555,
     MATRIXPLUSEND = 556,
     MATRIXTIMESSTART = 557,
     MATRIXTIMESEND = 558,
     MATRIXPRODUCTSTART = 559,
     MATRIXPRODUCTEND = 560,
     MATRIXSCALARTIMESSTART = 561,
     MATRIXSCALARTIMESEND = 562,
     MATRIXSUBMATRIXATSTART = 563,
     MATRIXSUBMATRIXATEND = 564,
     MATRIXTRANSPOSESTART = 565,
     MATRIXTRANSPOSEEND = 566,
     MATRIXREFERENCESTART = 567,
     MATRIXREFERENCEEND = 568,
     IDENTITYMATRIXSTART = 569,
     IDENTITYMATRIXEND = 570,
     MATRIXINVERSESTART = 571,
     MATRIXINVERSEEND = 572,
     EMPTYINCLUDEDIAGONALATT = 573,
     INCLUDEDIAGONALATT = 574,
     IDATT = 575,
     COEFATT = 576
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
#define EMPTYNEGATIVEPATTERNATT 429
#define NEGATIVEPATTERNATT 430
#define CONSTANTATT 431
#define NUMBEROFBLOCKSATT 432
#define NUMBEROFCOLUMNSATT 433
#define NUMBEROFROWSATT 434
#define NUMBEROFVALUESATT 435
#define NUMBEROFVARIDXATT 436
#define BASEMATRIXIDXATT 437
#define TARGETMATRIXFIRSTROWATT 438
#define TARGETMATRIXFIRSTCOLATT 439
#define BASEMATRIXSTARTROWATT 440
#define BASEMATRIXSTARTCOLATT 441
#define BASEMATRIXENDROWATT 442
#define BASEMATRIXENDCOLATT 443
#define SCALARMULTIPLIERATT 444
#define EMPTYBASETRANSPOSEATT 445
#define BASETRANSPOSEATT 446
#define ELEMENTSSTART 447
#define ELEMENTSEND 448
#define CONSTANTELEMENTSSTART 449
#define CONSTANTELEMENTSEND 450
#define STARTVECTORSTART 451
#define STARTVECTOREND 452
#define NONZEROSSTART 453
#define NONZEROSEND 454
#define INDEXESSTART 455
#define INDEXESEND 456
#define VALUESSTART 457
#define VALUESEND 458
#define VARREFERENCEELEMENTSSTART 459
#define VARREFERENCEELEMENTSEND 460
#define LINEARELEMENTSSTART 461
#define LINEARELEMENTSEND 462
#define GENERALELEMENTSSTART 463
#define GENERALELEMENTSEND 464
#define CONREFERENCEELEMENTSSTART 465
#define CONREFERENCEELEMENTSEND 466
#define OBJREFERENCEELEMENTSSTART 467
#define OBJREFERENCEELEMENTSEND 468
#define PATTERNELEMENTSSTART 469
#define PATTERNELEMENTSEND 470
#define VARIDXSTART 471
#define VARIDXEND 472
#define TRANSFORMATIONSTART 473
#define TRANSFORMATIONEND 474
#define COLOFFSETSSTART 475
#define COLOFFSETSEND 476
#define ROWOFFSETSSTART 477
#define ROWOFFSETSEND 478
#define EMPTYROWMAJORATT 479
#define ROWMAJORATT 480
#define BLOCKROWIDXATT 481
#define BLOCKCOLIDXATT 482
#define DUMMY 483
#define NONLINEAREXPRESSIONSSTART 484
#define NONLINEAREXPRESSIONSEND 485
#define NUMBEROFNONLINEAREXPRESSIONS 486
#define NLSTART 487
#define NLEND 488
#define POWERSTART 489
#define POWEREND 490
#define PLUSSTART 491
#define PLUSEND 492
#define MINUSSTART 493
#define MINUSEND 494
#define DIVIDESTART 495
#define DIVIDEEND 496
#define LNSTART 497
#define LNEND 498
#define SQRTSTART 499
#define SQRTEND 500
#define SUMSTART 501
#define SUMEND 502
#define PRODUCTSTART 503
#define PRODUCTEND 504
#define EXPSTART 505
#define EXPEND 506
#define NEGATESTART 507
#define NEGATEEND 508
#define IFSTART 509
#define IFEND 510
#define SQUARESTART 511
#define SQUAREEND 512
#define COSSTART 513
#define COSEND 514
#define SINSTART 515
#define SINEND 516
#define VARIABLESTART 517
#define VARIABLEEND 518
#define ABSSTART 519
#define ABSEND 520
#define ERFSTART 521
#define ERFEND 522
#define MAXSTART 523
#define MAXEND 524
#define ALLDIFFSTART 525
#define ALLDIFFEND 526
#define MINSTART 527
#define MINEND 528
#define ESTART 529
#define EEND 530
#define PISTART 531
#define PIEND 532
#define TIMESSTART 533
#define TIMESEND 534
#define NUMBERSTART 535
#define NUMBEREND 536
#define MATRIXDETERMINANTSTART 537
#define MATRIXDETERMINANTEND 538
#define MATRIXTRACESTART 539
#define MATRIXTRACEEND 540
#define MATRIXTOSCALARSTART 541
#define MATRIXTOSCALAREND 542
#define MATRIXDIAGONALSTART 543
#define MATRIXDIAGONALEND 544
#define MATRIXDOTTIMESSTART 545
#define MATRIXDOTTIMESEND 546
#define MATRIXLOWERTRIANGLESTART 547
#define MATRIXLOWERTRIANGLEEND 548
#define MATRIXUPPERTRIANGLESTART 549
#define MATRIXUPPERTRIANGLEEND 550
#define MATRIXMERGESTART 551
#define MATRIXMERGEEND 552
#define MATRIXMINUSSTART 553
#define MATRIXMINUSEND 554
#define MATRIXPLUSSTART 555
#define MATRIXPLUSEND 556
#define MATRIXTIMESSTART 557
#define MATRIXTIMESEND 558
#define MATRIXPRODUCTSTART 559
#define MATRIXPRODUCTEND 560
#define MATRIXSCALARTIMESSTART 561
#define MATRIXSCALARTIMESEND 562
#define MATRIXSUBMATRIXATSTART 563
#define MATRIXSUBMATRIXATEND 564
#define MATRIXTRANSPOSESTART 565
#define MATRIXTRANSPOSEEND 566
#define MATRIXREFERENCESTART 567
#define MATRIXREFERENCEEND 568
#define IDENTITYMATRIXSTART 569
#define IDENTITYMATRIXEND 570
#define MATRIXINVERSESTART 571
#define MATRIXINVERSEEND 572
#define EMPTYINCLUDEDIAGONALATT 573
#define INCLUDEDIAGONALATT 574
#define IDATT 575
#define COEFATT 576




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
#define YYLAST   1215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  326
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  655
/* YYNRULES -- Number of rules.  */
#define YYNRULES  945
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1500

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   576

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   323,
     325,     2,     2,   324,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   322,     2,     2,     2,     2,     2,     2,     2,
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
     315,   316,   317,   318,   319,   320,   321
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
    1070,  1072,  1074,  1075,  1078,  1082,  1084,  1085,  1087,  1091,
    1095,  1097,  1099,  1102,  1104,  1108,  1112,  1114,  1116,  1117,
    1120,  1122,  1124,  1126,  1128,  1130,  1134,  1138,  1142,  1144,
    1146,  1148,  1152,  1155,  1156,  1160,  1162,  1164,  1165,  1168,
    1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,  1186,  1191,
    1196,  1201,  1206,  1211,  1216,  1221,  1223,  1225,  1227,  1229,
    1233,  1238,  1241,  1243,  1244,  1247,  1249,  1251,  1253,  1256,
    1258,  1260,  1262,  1264,  1273,  1275,  1276,  1281,  1283,  1285,
    1286,  1289,  1291,  1293,  1298,  1301,  1303,  1305,  1307,  1309,
    1313,  1315,  1318,  1320,  1322,  1324,  1326,  1330,  1332,  1335,
    1337,  1339,  1341,  1343,  1347,  1349,  1350,  1355,  1357,  1359,
    1360,  1363,  1365,  1367,  1372,  1375,  1377,  1379,  1381,  1383,
    1387,  1389,  1392,  1394,  1396,  1398,  1400,  1404,  1406,  1409,
    1411,  1413,  1415,  1417,  1421,  1423,  1424,  1429,  1431,  1433,
    1434,  1437,  1439,  1441,  1446,  1449,  1451,  1453,  1455,  1457,
    1461,  1463,  1466,  1468,  1470,  1472,  1474,  1478,  1480,  1481,
    1484,  1486,  1488,  1490,  1492,  1496,  1498,  1499,  1502,  1506,
    1508,  1510,  1511,  1514,  1516,  1518,  1523,  1525,  1527,  1529,
    1533,  1534,  1537,  1541,  1543,  1544,  1549,  1553,  1554,  1558,
    1560,  1562,  1563,  1566,  1568,  1570,  1575,  1578,  1580,  1582,
    1584,  1586,  1590,  1592,  1596,  1598,  1600,  1604,  1607,  1608,
    1611,  1613,  1615,  1617,  1619,  1623,  1625,  1626,  1629,  1631,
    1633,  1635,  1637,  1641,  1642,  1645,  1648,  1650,  1652,  1654,
    1656,  1660,  1661,  1666,  1668,  1670,  1671,  1674,  1676,  1678,
    1683,  1686,  1688,  1690,  1692,  1694,  1698,  1700,  1702,  1704,
    1706,  1710,  1712,  1715,  1717,  1719,  1721,  1723,  1727,  1729,
    1732,  1734,  1736,  1738,  1740,  1744,  1746,  1747,  1752,  1754,
    1756,  1757,  1760,  1762,  1764,  1769,  1772,  1774,  1776,  1778,
    1780,  1784,  1786,  1789,  1791,  1793,  1795,  1797,  1801,  1803,
    1806,  1808,  1810,  1812,  1814,  1818,  1820,  1825,  1827,  1829,
    1833,  1835,  1837,  1843,  1845,  1849,  1851,  1853,  1855,  1857,
    1859,  1863,  1865,  1869,  1871,  1873,  1875,  1877,  1879,  1883,
    1885,  1886,  1889,  1893,  1895,  1897,  1898,  1901,  1903,  1905,
    1907,  1912,  1917,  1919,  1921,  1923,  1927,  1930,  1935,  1940,
    1945,  1950,  1955,  1960,  1965,  1970,  1975,  1977,  1979,  1981,
    1985,  1986,  1991,  1993,  1999,  2000,  2003,  2009,  2011,  2016,
    2018,  2020,  2022,  2024,  2026,  2028,  2030,  2032,  2034,  2036,
    2038,  2040,  2042,  2044,  2046,  2048,  2050,  2052,  2054,  2056,
    2058,  2060,  2062,  2064,  2066,  2068,  2070,  2071,  2075,  2077,
    2080,  2081,  2085,  2087,  2090,  2091,  2097,  2098,  2104,  2105,
    2111,  2112,  2117,  2118,  2124,  2125,  2131,  2132,  2137,  2138,
    2143,  2144,  2149,  2150,  2155,  2156,  2161,  2162,  2167,  2168,
    2173,  2174,  2179,  2180,  2187,  2188,  2193,  2194,  2199,  2200,
    2205,  2206,  2211,  2213,  2216,  2217,  2220,  2222,  2224,  2226,
    2227,  2232,  2233,  2238,  2243,  2244,  2249,  2251,  2254,  2255,
    2260,  2261,  2264,  2266,  2268,  2273,  2278,  2279,  2284,  2285,
    2288,  2289,  2294,  2295,  2298,  2299,  2304,  2305,  2308,  2309,
    2314,  2315,  2318,  2319,  2324,  2325,  2328,  2330,  2332,  2334,
    2336,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2359,  2364,  2366,  2369,  2374,  2377,  2379,  2382,
    2385,  2387,  2391,  2394,  2396,  2399,  2402,  2404,  2407,  2412,
    2414,  2415,  2417,  2420,  2425,  2427,  2428,  2430,  2433,  2435,
    2439,  2442,  2444,  2446,  2449,  2452,  2454,  2458,  2461,  2463,
    2467,  2470,  2472,  2476,  2477,  2482,  2483,  2486,  2489,  2491,
    2495,  2498,  2500,  2507,  2510,  2512
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     327,     0,    -1,   331,   848,   343,   350,   418,   486,   328,
     329,    -1,    14,    -1,    13,    -1,   330,    -1,    12,    -1,
      -1,    -1,    24,   332,   333,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   333,   334,    -1,   335,   337,   336,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   337,
     338,    -1,   339,    -1,   340,    -1,   341,    -1,   342,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     321,     3,   569,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   344,   345,   346,    -1,    29,    -1,   544,    -1,   347,
      -1,   348,    -1,    10,    -1,    11,   349,    30,    -1,    -1,
     349,   595,    -1,    -1,   351,   352,   353,    -1,    32,    -1,
     545,    -1,   354,    -1,   355,    -1,    10,    -1,    11,   356,
      33,    -1,    -1,   356,   357,    -1,   358,    -1,   364,    -1,
     370,    -1,   376,    -1,   382,    -1,   388,    -1,   403,    -1,
     359,   360,   363,    -1,    35,    -1,   361,    -1,    -1,   361,
     362,    -1,   546,    -1,   547,    -1,   553,    -1,    10,    -1,
      11,    36,    -1,   365,   366,   369,    -1,    37,    -1,   367,
      -1,    -1,   367,   368,    -1,   546,    -1,   547,    -1,   553,
      -1,    10,    -1,    11,    38,    -1,   371,   372,   375,    -1,
      41,    -1,   373,    -1,    -1,   373,   374,    -1,   546,    -1,
     547,    -1,   553,    -1,   556,    -1,   555,    -1,   557,    -1,
      10,    -1,    11,    42,    -1,   377,   378,   381,    -1,    43,
      -1,   379,    -1,    -1,   379,   380,    -1,   546,    -1,   547,
      -1,   553,    -1,   556,    -1,   555,    -1,   558,    -1,   559,
      -1,    10,    -1,    11,    44,    -1,   383,   384,   387,    -1,
      45,    -1,   385,    -1,    -1,   385,   386,    -1,   546,    -1,
     547,    -1,   553,    -1,   560,    -1,    10,    -1,    11,    46,
      -1,   389,   390,   393,    -1,    47,    -1,   391,    -1,    -1,
     391,   392,    -1,   546,    -1,   547,    -1,   553,    -1,    11,
     394,   402,    -1,   395,   396,   397,    -1,    55,    -1,   543,
      -1,   398,    -1,   399,    -1,    10,    -1,    11,   400,   401,
      -1,   573,    -1,    56,    -1,    48,    -1,   404,   405,   408,
      -1,    49,    -1,   406,    -1,    -1,   406,   407,    -1,   546,
      -1,   547,    -1,   553,    -1,    11,   409,   417,    -1,   410,
     411,   412,    -1,    57,    -1,   543,    -1,   413,    -1,   414,
      -1,    10,    -1,    11,   415,   416,    -1,   573,    -1,    58,
      -1,    50,    -1,    -1,   419,   420,    -1,    66,    -1,   421,
      -1,   422,    -1,    10,    -1,    11,   423,   437,   459,   477,
      67,    -1,    -1,   424,   425,   426,    -1,    68,    -1,   548,
      -1,   427,    -1,   428,    -1,    10,    -1,    11,   430,   429,
      -1,    69,    -1,    -1,   430,   431,    -1,   432,   433,   436,
      -1,    71,    -1,   434,    -1,    -1,   434,   435,    -1,   561,
      -1,   562,    -1,   564,    -1,   565,    -1,   566,    -1,   568,
      -1,   553,    -1,    10,    -1,    11,    72,    -1,    -1,   438,
     439,   440,    -1,    73,    -1,   549,    -1,   441,    -1,   442,
      -1,    10,    -1,    11,   444,   443,    -1,    74,    -1,    -1,
     444,   445,    -1,   446,   447,   450,    -1,    76,    -1,   448,
      -1,    -1,   448,   449,    -1,   561,    -1,   567,    -1,   563,
      -1,   568,    -1,   553,    -1,   554,    -1,   551,    -1,   451,
      -1,   452,    -1,    10,    -1,    11,   453,   454,    -1,   455,
      -1,    77,    -1,    -1,   455,   456,    -1,   457,   931,   458,
      -1,    84,    11,    -1,    85,    -1,    -1,   460,   461,   462,
      -1,    78,    -1,   550,    -1,   463,    -1,   464,    -1,    10,
      -1,    11,   466,   465,    -1,    79,    -1,    -1,   466,   467,
      -1,   468,   469,   472,    -1,    81,    -1,   470,    -1,    -1,
     470,   471,    -1,   561,    -1,   562,    -1,   564,    -1,   565,
      -1,   566,    -1,   568,    -1,   553,    -1,   554,    -1,   551,
      -1,   473,    -1,   474,    -1,    10,    -1,    11,   475,   476,
      -1,   455,    -1,    82,    -1,    -1,   478,   479,   480,    -1,
      86,    -1,   552,    -1,   481,    -1,   482,    -1,    10,    -1,
      11,   483,    87,    -1,    -1,   483,   484,    -1,    89,   485,
      11,   855,    90,    -1,    18,     3,     7,     3,    -1,    -1,
     487,   488,    -1,   101,    -1,   489,    -1,   490,    -1,    10,
      -1,    11,   102,    -1,    11,   491,   102,    -1,    11,   535,
     102,    -1,   492,   493,   494,   104,    -1,   103,    -1,   107,
       3,     7,     3,    11,    -1,   495,    -1,   494,   495,    -1,
      -1,   496,   105,   497,   498,    -1,    -1,    21,     4,     3,
      -1,    10,    -1,    11,   499,   106,    -1,   500,   512,   524,
      -1,    -1,   110,   501,   505,    -1,    -1,   501,   502,    -1,
     503,    -1,   504,    -1,   116,     3,     7,     3,    -1,   119,
       3,     7,     3,    -1,   506,    -1,    11,   507,   113,    -1,
      10,    -1,    11,   113,    -1,   508,    -1,   507,   508,    -1,
      -1,   509,   120,   510,   511,    -1,    18,     3,     7,     3,
      -1,    10,    -1,    11,   121,    -1,    -1,   111,   513,   517,
      -1,    -1,   513,   514,    -1,   515,    -1,   516,    -1,   117,
       3,     7,     3,    -1,   119,     3,     7,     3,    -1,   518,
      -1,    11,   519,   114,    -1,    10,    -1,    11,   114,    -1,
     520,    -1,   519,   520,    -1,    -1,   521,   122,   522,   523,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   123,
      -1,    -1,   112,   525,   528,    -1,    -1,   525,   526,    -1,
     527,    -1,   540,    -1,   118,     3,     7,     3,    -1,   529,
      -1,    11,   530,   115,    -1,    10,    -1,    11,   115,    -1,
     531,    -1,   530,   531,    -1,    -1,   532,   124,   533,   534,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   125,
      -1,    -1,   536,   126,   538,   537,    -1,    10,    -1,    11,
     127,    -1,    -1,   538,   539,    -1,   541,    -1,   542,    -1,
     119,     3,     7,     3,    -1,   108,     3,   569,     3,    -1,
     109,     3,   569,     3,    -1,   152,   570,     7,   570,    -1,
      31,     3,     7,     3,    -1,    34,     3,     7,     3,    -1,
     179,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
      70,     3,     7,     3,    -1,    75,     3,     7,     3,    -1,
      80,     3,     7,     3,    -1,    83,     3,     7,     3,    -1,
      88,     3,     7,     3,    -1,    21,     4,     3,    -1,    99,
       4,     3,    -1,    59,     3,   569,     3,    -1,    60,     3,
       7,     3,    -1,    61,     3,     7,     3,    -1,    62,     3,
       7,     3,    -1,    63,     3,     7,     3,    -1,    65,     4,
       3,    -1,    91,     3,     7,     3,    -1,    92,     3,     7,
       3,    -1,    98,     3,     7,     3,    -1,    93,     3,     7,
       3,    -1,    94,     3,     7,     3,    -1,    95,     3,     7,
       3,    -1,    97,     3,     7,     3,    -1,    96,     3,     7,
       3,    -1,   571,     7,   571,    -1,   571,     8,   571,    -1,
     571,     3,    -1,    -1,   571,   572,    -1,   322,    -1,   323,
      -1,   324,    -1,   325,    -1,   574,    -1,   581,    -1,    -1,
     574,   575,    -1,   576,   577,   580,    -1,   162,    -1,   578,
      -1,    -1,   578,   579,    -1,   844,    -1,   843,    -1,    11,
       7,   163,    -1,   157,   842,   582,    -1,   583,    -1,   584,
      -1,    11,   158,    -1,    10,    -1,    11,     5,   158,    -1,
     586,    -1,   591,    -1,    -1,   586,   587,    -1,   588,   589,
     590,    -1,   162,    -1,    -1,   844,    -1,    11,   569,   163,
      -1,   157,   842,   592,    -1,   593,    -1,   594,    -1,    11,
     158,    -1,    10,    -1,    11,     5,   158,    -1,   596,   597,
     603,    -1,   164,    -1,   598,    -1,    -1,   598,   599,    -1,
     600,    -1,   839,    -1,   837,    -1,   601,    -1,   602,    -1,
     173,     4,     3,    -1,    21,     4,     3,    -1,    22,     4,
       3,    -1,   604,    -1,   605,    -1,    10,    -1,    11,   606,
     165,    -1,   607,   625,    -1,    -1,   608,   609,   624,    -1,
     167,    -1,   610,    -1,    -1,   610,   611,    -1,   612,    -1,
     613,    -1,   614,    -1,   615,    -1,   616,    -1,   617,    -1,
     618,    -1,   619,    -1,   623,    -1,   182,     3,     7,     3,
      -1,   183,     3,     7,     3,    -1,   184,     3,     7,     3,
      -1,   185,     3,     7,     3,    -1,   186,     3,     7,     3,
      -1,   187,     3,     7,     3,    -1,   188,     3,     7,     3,
      -1,   620,    -1,   621,    -1,   622,    -1,   190,    -1,   191,
       4,   570,    -1,   189,     3,   569,     3,    -1,    11,   166,
      -1,    10,    -1,    -1,   625,   626,    -1,   627,    -1,   802,
      -1,   805,    -1,   628,   629,    -1,   192,    -1,   630,    -1,
     631,    -1,    10,    -1,    11,   633,   657,   681,   720,   754,
     778,   632,    -1,   193,    -1,    -1,   634,   635,    11,   638,
      -1,   194,    -1,   636,    -1,    -1,   636,   637,    -1,   840,
      -1,   845,    -1,   639,   645,   651,   195,    -1,   640,   641,
      -1,   196,    -1,   642,    -1,   643,    -1,    10,    -1,    11,
     644,   197,    -1,   573,    -1,   646,   647,    -1,   200,    -1,
     648,    -1,   649,    -1,    10,    -1,    11,   650,   201,    -1,
     573,    -1,   652,   653,    -1,   202,    -1,   654,    -1,   655,
      -1,    10,    -1,    11,   656,   203,    -1,   585,    -1,    -1,
     658,   659,    11,   662,    -1,   204,    -1,   660,    -1,    -1,
     660,   661,    -1,   840,    -1,   845,    -1,   663,   669,   675,
     205,    -1,   664,   665,    -1,   196,    -1,   666,    -1,   667,
      -1,    10,    -1,    11,   668,   197,    -1,   573,    -1,   670,
     671,    -1,   200,    -1,   672,    -1,   673,    -1,    10,    -1,
      11,   674,   201,    -1,   573,    -1,   676,   677,    -1,   202,
      -1,   678,    -1,   679,    -1,    10,    -1,    11,   680,   203,
      -1,   573,    -1,    -1,   682,   683,    11,   686,    -1,   206,
      -1,   684,    -1,    -1,   684,   685,    -1,   840,    -1,   845,
      -1,   687,   693,   699,   207,    -1,   688,   689,    -1,   196,
      -1,   690,    -1,   691,    -1,    10,    -1,    11,   692,   197,
      -1,   573,    -1,   694,   695,    -1,   200,    -1,   696,    -1,
     697,    -1,    10,    -1,    11,   698,   201,    -1,   573,    -1,
      -1,   700,   701,    -1,   202,    -1,   702,    -1,   703,    -1,
      10,    -1,    11,   704,   203,    -1,   705,    -1,    -1,   705,
     706,    -1,   707,   708,   712,    -1,   162,    -1,   709,    -1,
      -1,   709,   710,    -1,   841,    -1,   711,    -1,   176,     3,
     569,     3,    -1,   713,    -1,   714,    -1,    10,    -1,    11,
     715,   163,    -1,    -1,   715,   716,    -1,   717,   718,   719,
      -1,   216,    -1,    -1,   321,     3,   569,     3,    -1,    11,
       7,   217,    -1,    -1,   721,   722,   725,    -1,   208,    -1,
     723,    -1,    -1,   723,   724,    -1,   840,    -1,   845,    -1,
      11,   726,   732,   209,    -1,   727,   728,    -1,   196,    -1,
     729,    -1,   730,    -1,    10,    -1,    11,   731,   197,    -1,
     573,    -1,   733,   734,   735,    -1,   198,    -1,   838,    -1,
      11,   736,   199,    -1,   737,   743,    -1,    -1,   738,   739,
      -1,   200,    -1,   740,    -1,   741,    -1,    10,    -1,    11,
     742,   201,    -1,   573,    -1,    -1,   744,   745,    -1,   202,
      -1,   746,    -1,   747,    -1,    10,    -1,    11,   748,   203,
      -1,    -1,   748,   749,    -1,   750,   751,    -1,   162,    -1,
     752,    -1,   753,    -1,    10,    -1,    11,   855,   163,    -1,
      -1,   755,   756,    11,   759,    -1,   210,    -1,   757,    -1,
      -1,   757,   758,    -1,   840,    -1,   845,    -1,   760,   766,
     772,   211,    -1,   761,   762,    -1,   196,    -1,   763,    -1,
     764,    -1,    10,    -1,    11,   765,   197,    -1,   573,    -1,
     763,    -1,   764,    -1,    10,    -1,    11,   765,   197,    -1,
     573,    -1,   767,   768,    -1,   200,    -1,   769,    -1,   770,
      -1,    10,    -1,    11,   771,   201,    -1,   573,    -1,   773,
     774,    -1,   202,    -1,   775,    -1,   776,    -1,    10,    -1,
      11,   777,   203,    -1,   573,    -1,    -1,   779,   780,    11,
     783,    -1,   212,    -1,   781,    -1,    -1,   781,   782,    -1,
     840,    -1,   845,    -1,   784,   790,   796,   213,    -1,   785,
     786,    -1,   196,    -1,   787,    -1,   788,    -1,    10,    -1,
      11,   789,   197,    -1,   573,    -1,   791,   792,    -1,   200,
      -1,   793,    -1,   794,    -1,    10,    -1,    11,   795,   201,
      -1,   573,    -1,   797,   798,    -1,   202,    -1,   799,    -1,
     800,    -1,    10,    -1,    11,   801,   203,    -1,   573,    -1,
     803,    11,   931,   804,    -1,   218,    -1,   219,    -1,   806,
     807,   808,    -1,   170,    -1,   836,    -1,    11,   810,   817,
     824,   809,    -1,   171,    -1,   811,   812,   813,    -1,   220,
      -1,   838,    -1,   814,    -1,   815,    -1,    10,    -1,    11,
     816,   221,    -1,   573,    -1,   818,   819,   820,    -1,   222,
      -1,   838,    -1,   821,    -1,   822,    -1,    10,    -1,    11,
     823,   223,    -1,   573,    -1,    -1,   824,   825,    -1,   826,
     827,   832,    -1,   168,    -1,   828,    -1,    -1,   828,   829,
      -1,   830,    -1,   831,    -1,   600,    -1,   226,   570,     7,
     570,    -1,   227,   570,     7,   570,    -1,   833,    -1,   834,
      -1,    10,    -1,    11,   835,   169,    -1,   607,   625,    -1,
     177,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
     152,     3,     7,     3,    -1,   179,     3,     7,     3,    -1,
     180,     3,     7,     3,    -1,   181,     3,     7,     3,    -1,
     161,     3,     7,     3,    -1,   159,     3,     7,     3,    -1,
     160,     3,     7,     3,    -1,   846,    -1,   847,    -1,   224,
      -1,   225,     4,   570,    -1,    -1,   849,   850,   851,   230,
      -1,   229,    -1,   231,     3,     7,     3,    11,    -1,    -1,
     851,   852,    -1,   853,   854,    11,   855,   233,    -1,   232,
      -1,    18,     3,     7,     3,    -1,   898,    -1,   908,    -1,
     862,    -1,   864,    -1,   916,    -1,   866,    -1,   868,    -1,
     870,    -1,   872,    -1,   928,    -1,   874,    -1,   876,    -1,
     878,    -1,   882,    -1,   880,    -1,   884,    -1,   890,    -1,
     886,    -1,   888,    -1,   922,    -1,   925,    -1,   856,    -1,
     859,    -1,   919,    -1,   892,    -1,   894,    -1,   896,    -1,
      -1,   274,   857,   858,    -1,    10,    -1,    11,   275,    -1,
      -1,   276,   860,   861,    -1,    10,    -1,    11,   277,    -1,
      -1,   278,   863,   855,   855,   279,    -1,    -1,   236,   865,
     855,   855,   237,    -1,    -1,   238,   867,   855,   855,   239,
      -1,    -1,   252,   869,   855,   253,    -1,    -1,   240,   871,
     855,   855,   241,    -1,    -1,   234,   873,   855,   855,   235,
      -1,    -1,   242,   875,   855,   243,    -1,    -1,   244,   877,
     855,   245,    -1,    -1,   256,   879,   855,   257,    -1,    -1,
     258,   881,   855,   259,    -1,    -1,   260,   883,   855,   261,
      -1,    -1,   250,   885,   855,   251,    -1,    -1,   264,   887,
     855,   265,    -1,    -1,   266,   889,   855,   267,    -1,    -1,
     254,   891,   855,   855,   855,   255,    -1,    -1,   282,   893,
     931,   283,    -1,    -1,   284,   895,   931,   285,    -1,    -1,
     286,   897,   931,   287,    -1,    -1,   280,   899,   901,   900,
      -1,    10,    -1,    11,   281,    -1,    -1,   901,   902,    -1,
     903,    -1,   907,    -1,   905,    -1,    -1,    22,     4,   904,
       3,    -1,    -1,   320,     4,   906,     3,    -1,    23,     3,
     569,     3,    -1,    -1,   262,   909,   912,   910,    -1,    10,
      -1,    11,   263,    -1,    -1,    11,   855,   911,   263,    -1,
      -1,   912,   913,    -1,   914,    -1,   915,    -1,   321,     3,
     569,     3,    -1,    18,     3,     7,     3,    -1,    -1,   246,
     917,   918,   247,    -1,    -1,   918,   855,    -1,    -1,   270,
     920,   921,   271,    -1,    -1,   921,   855,    -1,    -1,   268,
     923,   924,   269,    -1,    -1,   924,   855,    -1,    -1,   272,
     926,   927,   273,    -1,    -1,   927,   855,    -1,    -1,   248,
     929,   930,   249,    -1,    -1,   930,   855,    -1,   932,    -1,
     935,    -1,   938,    -1,   944,    -1,   947,    -1,   951,    -1,
     957,    -1,   960,    -1,   963,    -1,   966,    -1,   969,    -1,
     972,    -1,   975,    -1,   978,    -1,   941,    -1,    -1,   312,
     933,   561,   934,    -1,    10,    -1,    11,   313,    -1,    18,
       3,     7,     3,    -1,   936,   937,    -1,   288,    -1,   931,
     289,    -1,   939,   940,    -1,   290,    -1,   931,   931,   291,
      -1,   942,   943,    -1,   314,    -1,   855,   315,    -1,   945,
     946,    -1,   316,    -1,   931,   317,    -1,   948,   949,    11,
     950,    -1,   292,    -1,    -1,   955,    -1,   931,   293,    -1,
     952,   953,    11,   954,    -1,   294,    -1,    -1,   955,    -1,
     931,   295,    -1,   956,    -1,   319,     4,     3,    -1,   958,
     959,    -1,   296,    -1,    10,    -1,    11,   297,    -1,   961,
     962,    -1,   298,    -1,   931,   931,   299,    -1,   964,   965,
      -1,   300,    -1,   931,   931,   301,    -1,   967,   968,    -1,
     302,    -1,   931,   931,   303,    -1,    -1,   304,   970,   971,
     305,    -1,    -1,   971,   931,    -1,   973,   974,    -1,   306,
      -1,   855,   931,   307,    -1,   976,   977,    -1,   308,    -1,
     931,   855,   855,   855,   855,   309,    -1,   979,   980,    -1,
     310,    -1,   931,   311,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   384,   384,   387,   388,   390,   399,   400,   403,   404,
     409,   416,   416,   418,   431,   437,   438,   441,   442,   445,
     448,   451,   454,   460,   467,   474,   482,   487,   487,   493,
     498,   511,   511,   513,   515,   522,   522,   525,   525,   527,
     529,   531,   531,   533,   535,   537,   537,   539,   540,   542,
     543,   545,   552,   553,   558,   560,   562,   564,   564,   567,
     568,   569,   571,   571,   573,   575,   577,   579,   579,   582,
     583,   584,   586,   586,   590,   592,   594,   596,   596,   599,
     600,   601,   602,   603,   604,   607,   607,   609,   611,   613,
     615,   615,   618,   619,   620,   621,   622,   623,   624,   627,
     627,   631,   633,   635,   637,   637,   640,   641,   642,   643,
     646,   646,   660,   662,   664,   666,   666,   669,   670,   671,
     674,   676,   678,   680,   682,   682,   684,   686,   688,   690,
     692,   694,   696,   698,   700,   700,   703,   704,   705,   708,
     710,   712,   714,   716,   716,   718,   720,   722,   724,   726,
     735,   735,   737,   739,   739,   741,   744,   746,   746,   748,
     750,   752,   752,   754,   756,   758,   760,   760,   762,   764,
     766,   768,   768,   771,   772,   773,   774,   775,   776,   777,
     780,   781,   783,   783,   785,   787,   789,   789,   791,   793,
     795,   797,   797,   799,   801,   803,   805,   805,   808,   809,
     810,   811,   812,   813,   814,   817,   817,   819,   821,   823,
     825,   829,   829,   831,   833,   835,   838,   838,   840,   842,
     844,   844,   846,   848,   850,   852,   852,   854,   856,   858,
     860,   860,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   874,   874,   876,   878,   880,   882,   885,   885,   887,
     889,   891,   891,   893,   895,   897,   897,   899,   901,   903,
     903,   905,   907,   907,   909,   910,   913,   914,   917,   968,
     970,   984,   985,   987,   987,  1011,  1012,  1015,  1016,  1018,
    1020,  1021,  1025,  1026,  1028,  1029,  1031,  1047,  1055,  1062,
    1067,  1068,  1070,  1071,  1073,  1073,  1076,  1085,  1086,  1088,
    1089,  1093,  1094,  1096,  1097,  1099,  1115,  1123,  1130,  1135,
    1136,  1138,  1139,  1141,  1141,  1144,  1153,  1154,  1156,  1166,
    1170,  1171,  1173,  1174,  1176,  1192,  1199,  1204,  1205,  1207,
    1208,  1210,  1210,  1213,  1222,  1223,  1228,  1228,  1236,  1237,
    1239,  1240,  1242,  1246,  1252,  1260,  1264,  1269,  1278,  1289,
    1300,  1311,  1322,  1330,  1338,  1346,  1354,  1363,  1372,  1380,
    1391,  1402,  1414,  1425,  1436,  1447,  1458,  1469,  1480,  1491,
    1502,  1513,  1524,  1538,  1539,  1546,  1548,  1548,  1550,  1551,
    1552,  1553,  1718,  1727,  1729,  1729,  1731,  1733,  1742,  1744,
    1744,  1746,  1746,  1748,  1765,  1768,  1768,  1770,  1770,  1773,
    1804,  1812,  1814,  1814,  1816,  1818,  1826,  1826,  1828,  1845,
    1847,  1847,  1849,  1849,  1851,  1947,  1956,  1978,  1996,  1996,
    1999,  2000,  2001,  2002,  2003,  2006,  2015,  2024,  2033,  2033,
    2035,  2037,  2046,  2048,  2048,  2053,  2071,  2095,  2095,  2098,
    2099,  2100,  2101,  2102,  2103,  2104,  2105,  2106,  2108,  2123,
    2133,  2143,  2153,  2163,  2175,  2187,  2194,  2194,  2196,  2201,
    2210,  2218,  2218,  2220,  2220,  2225,  2225,  2225,  2227,  2233,
    2243,  2243,  2245,  2247,  2250,  2252,  2252,  2254,  2263,  2269,
    2269,  2272,  2276,  2282,  2284,  2293,  2304,  2304,  2306,  2308,
    2310,  2313,  2322,  2330,  2330,  2332,  2334,  2336,  2339,  2348,
    2356,  2356,  2358,  2360,  2362,  2383,  2383,  2385,  2392,  2398,
    2398,  2401,  2405,  2411,  2413,  2422,  2433,  2433,  2435,  2437,
    2439,  2441,  2450,  2458,  2458,  2460,  2462,  2464,  2467,  2476,
    2484,  2484,  2486,  2488,  2490,  2519,  2519,  2521,  2528,  2534,
    2534,  2537,  2541,  2547,  2549,  2558,  2570,  2570,  2572,  2574,
    2576,  2579,  2588,  2596,  2596,  2598,  2600,  2602,  2661,  2666,
    2678,  2689,  2689,  2691,  2693,  2695,  2697,  2697,  2699,  2707,
    2717,  2727,  2727,  2730,  2731,  2733,  2745,  2745,  2747,  2749,
    2751,  2751,  2754,  2756,  2764,  2764,  2769,  2775,  2775,  2777,
    2784,  2790,  2790,  2793,  2797,  2803,  2805,  2819,  2831,  2831,
    2833,  2835,  2837,  2839,  2850,  2856,  2863,  2865,  2867,  2868,
    2881,  2888,  2888,  2890,  2892,  2894,  2896,  2897,  2899,  2905,
    2905,  2907,  2909,  2911,  2911,  2913,  2915,  2921,  2921,  2923,
    2925,  2928,  2928,  2930,  2937,  2943,  2943,  2946,  2950,  2956,
    2958,  2967,  2979,  2979,  2981,  2983,  2985,  2987,  2987,  2989,
    2991,  2993,  2995,  3004,  3012,  3012,  3014,  3016,  3018,  3021,
    3030,  3038,  3038,  3040,  3042,  3044,  3073,  3073,  3075,  3082,
    3088,  3088,  3091,  3095,  3101,  3103,  3112,  3124,  3124,  3126,
    3128,  3130,  3133,  3142,  3150,  3150,  3152,  3154,  3156,  3159,
    3168,  3176,  3176,  3178,  3180,  3182,  3290,  3295,  3301,  3303,
    3305,  3311,  3316,  3321,  3323,  3337,  3343,  3349,  3349,  3351,
    3353,  3355,  3357,  3371,  3377,  3383,  3383,  3385,  3387,  3389,
    3391,  3391,  3393,  3395,  3397,  3399,  3399,  3402,  3403,  3404,
    3411,  3420,  3429,  3429,  3431,  3433,  3435,  3437,  3446,  3455,
    3464,  3473,  3482,  3491,  3496,  3504,  3513,  3513,  3515,  3524,
    3569,  3570,  3576,  3581,  3600,  3601,  3603,  3611,  3625,  3635,
    3636,  3637,  3638,  3639,  3640,  3641,  3642,  3643,  3644,  3645,
    3646,  3647,  3648,  3649,  3650,  3651,  3652,  3653,  3654,  3655,
    3656,  3657,  3658,  3660,  3661,  3662,  3666,  3666,  3669,  3670,
    3672,  3672,  3675,  3676,  3680,  3680,  3685,  3685,  3690,  3690,
    3695,  3695,  3700,  3700,  3705,  3705,  3710,  3710,  3715,  3715,
    3720,  3720,  3725,  3725,  3730,  3730,  3735,  3735,  3740,  3740,
    3747,  3747,  3753,  3753,  3762,  3762,  3767,  3767,  3772,  3772,
    3782,  3782,  3787,  3788,  3790,  3791,  3793,  3794,  3795,  3799,
    3798,  3807,  3806,  3814,  3824,  3823,  3830,  3831,  3833,  3832,
    3839,  3840,  3843,  3849,  3857,  3864,  3884,  3884,  3895,  3895,
    3898,  3898,  3910,  3911,  3914,  3914,  3925,  3926,  3929,  3929,
    3940,  3941,  3944,  3944,  3954,  3955,  3961,  3962,  3963,  3964,
    3965,  3966,  3967,  3968,  3969,  3970,  3971,  3972,  3973,  3974,
    3975,  3979,  3978,  3985,  3986,  3988,  3996,  3998,  4004,  4006,
    4008,  4014,  4016,  4018,  4024,  4026,  4028,  4034,  4036,  4038,
    4044,  4044,  4046,  4048,  4050,  4056,  4056,  4058,  4060,  4067,
    4077,  4079,  4084,  4084,  4086,  4088,  4094,  4096,  4098,  4104,
    4106,  4108,  4114,  4117,  4117,  4127,  4128,  4132,  4134,  4140,
    4142,  4144,  4150,  4152,  4154,  4160
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
  "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT", "NEGATIVEPATTERNATT",
  "CONSTANTATT", "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT",
  "NUMBEROFROWSATT", "NUMBEROFVALUESATT", "NUMBEROFVARIDXATT",
  "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
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
  "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
  "MATRIXLOWERTRIANGLEEND", "MATRIXUPPERTRIANGLESTART",
  "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART", "MATRIXMERGEEND",
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
  "MATRIXTIMESSTART", "MATRIXTIMESEND", "MATRIXPRODUCTSTART",
  "MATRIXPRODUCTEND", "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART", "MATRIXREFERENCEEND",
  "IDENTITYMATRIXSTART", "IDENTITYMATRIXEND", "MATRIXINVERSESTART",
  "MATRIXINVERSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
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
  "matrixConstructor", "matrixElements", "matrixElementsStart",
  "matrixElementsContent", "matrixElementsEmpty", "matrixElementsLaden",
  "matrixElementsEnd", "constantElements", "constantElementsStart",
  "constantElementsAttributes", "constantElementsAttList",
  "constantElementsAtt", "constantElementsContent",
  "constantElementsStartVector", "constantElementsStartVectorStart",
  "constantElementsStartVectorContent", "constantElementsStartVectorEmpty",
  "constantElementsStartVectorLaden", "constantElementsStartVectorBody",
  "constantElementsIndexes", "constantElementsIndexesStart",
  "constantElementsIndexesContent", "constantElementsIndexesEmpty",
  "constantElementsIndexesLaden", "constantElementsIndexesBody",
  "constantElementsValues", "constantElementsValuesStart",
  "constantElementsValuesContent", "constantElementsValuesEmpty",
  "constantElementsValuesLaden", "constantElementsValuesBody",
  "varReferenceElements", "varReferenceElementsStart",
  "varReferenceElementsAttributes", "varReferenceElementsAttList",
  "varReferenceElementsAtt", "varReferenceElementsContent",
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
  "linearElementsStartVector", "linearElementsStartVectorStart",
  "linearElementsStartVectorContent", "linearElementsStartVectorEmpty",
  "linearElementsStartVectorLaden", "linearElementsStartVectorBody",
  "linearElementsIndexes", "linearElementsIndexesStart",
  "linearElementsIndexesContent", "linearElementsIndexesEmpty",
  "linearElementsIndexesLaden", "linearElementsIndexesBody",
  "linearElementsValues", "linearElementsValuesStart",
  "linearElementsValuesContent", "linearElementsValuesEmpty",
  "linearElementsValuesLaden", "linearElementsValuesBody",
  "linearElementsValuesElList", "linearElementsValuesEl",
  "linearElementsValuesElStart", "linearElementsValuesElAttributes",
  "linearElementsValuesElAttList", "linearElementsValuesElAtt",
  "osglConstantATT", "linearElementsValuesElContent",
  "linearElementsValuesElEmpty", "linearElementsValuesElLaden",
  "linearElementsValuesVarIdxList", "linearElementsValuesVarIdx",
  "linearElementsValuesVarIdxStart",
  "osglLinearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "generalElements",
  "generalElementsStart", "generalElementsAttributes",
  "generalElementsAttList", "generalElementsAtt", "generalElementsContent",
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
  "conReferenceElementsStart", "conReferenceElementsAttributes",
  "conReferenceElementsAttList", "conReferenceElementsAtt",
  "conReferenceElementsContent", "conReferenceElementsStartVector",
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
  "conReferenceElementsValuesBody", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsAttributes",
  "objReferenceElementsAttList", "objReferenceElementsAtt",
  "objReferenceElementsContent", "objReferenceElementsStartVector",
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
  "osglNumberOfRowsATT", "osglNumberOfValuesATT", "osglNumberOfVarIdxATT",
  "osglBase64SizeATT", "osglIncrATT", "osglMultATT", "osglRowMajorATT",
  "rowMajorAttEmpty", "rowMajorAttContent", "nonlinearExpressions",
  "nonlinearExpressionsStart", "nlnumberatt", "nlnodes",
  "scalarExpressionTree", "nlstart", "nlIdxATT", "nlnode", "E", "$@6",
  "eend", "PI", "$@7", "piend", "times", "$@8", "plus", "$@9", "minus",
  "$@10", "negate", "$@11", "divide", "$@12", "power", "$@13", "ln",
  "$@14", "sqrt", "$@15", "square", "$@16", "cos", "$@17", "sin", "$@18",
  "exp", "$@19", "abs", "$@20", "erf", "$@21", "if", "$@22",
  "matrixDeterminant", "$@23", "matrixTrace", "$@24", "matrixToScalar",
  "$@25", "number", "$@26", "numberend", "anotherNumberATT", "numberATT",
  "numbertypeATT", "$@27", "numberidATT", "$@28", "numbervalueATT",
  "variable", "$@29", "variableend", "$@30", "anotherVariableATT",
  "variableATT", "variablecoefATT", "variableidxATT", "sum", "$@31",
  "anothersumnlnode", "allDiff", "$@32", "anotherallDiffnlnode", "max",
  "$@33", "anothermaxnlnode", "min", "$@34", "anotherminnlnode", "product",
  "$@35", "anotherproductnlnode", "OSnLMNode", "matrixReference", "$@36",
  "matrixreferenceend", "matrixDiagonal", "matrixDiagonalStart",
  "matrixDiagonalContent", "matrixDotTimes", "matrixDotTimesStart",
  "matrixDotTimesContent", "identityMatrix", "identityMatrixStart",
  "identityMatrixContent", "matrixInverse", "matrixInverseStart",
  "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT",
  "includeDiagonalAttContent", "matrixMerge", "matrixMergeStart",
  "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@37",
  "anothermatrixproductnode", "matrixScalarTimes",
  "matrixScalarTimesStart", "matrixScalarTimesContent",
  "matrixSubMatrixAt", "matrixSubMatrixAtStart",
  "matrixSubMatrixAtContent", "matrixTranspose", "matrixTransposeStart",
  "matrixTransposeContent", 0
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
     575,   576,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   326,   327,   328,   328,   329,   330,   330,   331,   331,
     332,   333,   333,   334,   335,   336,   336,   337,   337,   338,
     338,   338,   338,   339,   340,   341,   342,   343,   343,   344,
     345,   346,   346,   347,   348,   349,   349,   350,   350,   351,
     352,   353,   353,   354,   355,   356,   356,   357,   357,   357,
     357,   357,   357,   357,   358,   359,   360,   361,   361,   362,
     362,   362,   363,   363,   364,   365,   366,   367,   367,   368,
     368,   368,   369,   369,   370,   371,   372,   373,   373,   374,
     374,   374,   374,   374,   374,   375,   375,   376,   377,   378,
     379,   379,   380,   380,   380,   380,   380,   380,   380,   381,
     381,   382,   383,   384,   385,   385,   386,   386,   386,   386,
     387,   387,   388,   389,   390,   391,   391,   392,   392,   392,
     393,   394,   395,   396,   397,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   406,   407,   407,   407,   408,
     409,   410,   411,   412,   412,   413,   414,   415,   416,   417,
     418,   418,   419,   420,   420,   421,   422,   423,   423,   424,
     425,   426,   426,   427,   428,   429,   430,   430,   431,   432,
     433,   434,   434,   435,   435,   435,   435,   435,   435,   435,
     436,   436,   437,   437,   438,   439,   440,   440,   441,   442,
     443,   444,   444,   445,   446,   447,   448,   448,   449,   449,
     449,   449,   449,   449,   449,   450,   450,   451,   452,   453,
     454,   455,   455,   456,   457,   458,   459,   459,   460,   461,
     462,   462,   463,   464,   465,   466,   466,   467,   468,   469,
     470,   470,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   472,   472,   473,   474,   475,   476,   477,   477,   478,
     479,   480,   480,   481,   482,   483,   483,   484,   485,   486,
     486,   487,   488,   488,   489,   489,   490,   490,   491,   492,
     493,   494,   494,   496,   495,   497,   497,   498,   498,   499,
     500,   500,   501,   501,   502,   502,   503,   504,   505,   505,
     506,   506,   507,   507,   509,   508,   510,   511,   511,   512,
     512,   513,   513,   514,   514,   515,   516,   517,   517,   518,
     518,   519,   519,   521,   520,   522,   523,   523,   524,   524,
     525,   525,   526,   526,   527,   528,   528,   529,   529,   530,
     530,   532,   531,   533,   534,   534,   536,   535,   537,   537,
     538,   538,   539,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   569,   570,   571,   571,   572,   572,
     572,   572,   573,   573,   574,   574,   575,   576,   577,   578,
     578,   579,   579,   580,   581,   582,   582,   583,   583,   584,
     585,   585,   586,   586,   587,   588,   589,   589,   590,   591,
     592,   592,   593,   593,   594,   595,   596,   597,   598,   598,
     599,   599,   599,   599,   599,   600,   601,   602,   603,   603,
     604,   605,   606,   607,   607,   608,   609,   610,   610,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   620,   621,   622,
     623,   624,   624,   625,   625,   626,   626,   626,   627,   628,
     629,   629,   630,   631,   632,   633,   633,   634,   635,   636,
     636,   637,   637,   638,   639,   640,   641,   641,   642,   643,
     644,   645,   646,   647,   647,   648,   649,   650,   651,   652,
     653,   653,   654,   655,   656,   657,   657,   658,   659,   660,
     660,   661,   661,   662,   663,   664,   665,   665,   666,   667,
     668,   669,   670,   671,   671,   672,   673,   674,   675,   676,
     677,   677,   678,   679,   680,   681,   681,   682,   683,   684,
     684,   685,   685,   686,   687,   688,   689,   689,   690,   691,
     692,   693,   694,   695,   695,   696,   697,   698,   699,   699,
     700,   701,   701,   702,   703,   704,   705,   705,   706,   707,
     708,   709,   709,   710,   710,   711,   712,   712,   713,   714,
     715,   715,   716,   717,   718,   718,   719,   720,   720,   721,
     722,   723,   723,   724,   724,   725,   726,   727,   728,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   737,
     738,   739,   739,   740,   741,   742,   743,   743,   744,   745,
     745,   746,   747,   748,   748,   749,   750,   751,   751,   752,
     753,   754,   754,   755,   756,   757,   757,   758,   758,   759,
     760,   761,   762,   762,   763,   764,   765,   762,   762,   763,
     764,   765,   766,   767,   768,   768,   769,   770,   771,   772,
     773,   774,   774,   775,   776,   777,   778,   778,   779,   780,
     781,   781,   782,   782,   783,   784,   785,   786,   786,   787,
     788,   789,   790,   791,   792,   792,   793,   794,   795,   796,
     797,   798,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   813,   814,
     815,   816,   817,   818,   819,   820,   820,   821,   822,   823,
     824,   824,   825,   826,   827,   828,   828,   829,   829,   829,
     830,   831,   832,   832,   833,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   845,   846,   847,
     848,   848,   849,   850,   851,   851,   852,   853,   854,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   857,   856,   858,   858,
     860,   859,   861,   861,   863,   862,   865,   864,   867,   866,
     869,   868,   871,   870,   873,   872,   875,   874,   877,   876,
     879,   878,   881,   880,   883,   882,   885,   884,   887,   886,
     889,   888,   891,   890,   893,   892,   895,   894,   897,   896,
     899,   898,   900,   900,   901,   901,   902,   902,   902,   904,
     903,   906,   905,   907,   909,   908,   910,   910,   911,   910,
     912,   912,   913,   913,   914,   915,   917,   916,   918,   918,
     920,   919,   921,   921,   923,   922,   924,   924,   926,   925,
     927,   927,   929,   928,   930,   930,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   931,   931,
     931,   933,   932,   934,   934,   561,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   949,   950,   951,   952,   953,   953,   954,   955,   956,
     957,   958,   959,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,   970,   969,   971,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980
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
       1,     1,     0,     2,     3,     1,     0,     1,     3,     3,
       1,     1,     2,     1,     3,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     3,
       4,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     8,     1,     0,     4,     1,     1,     0,
       2,     1,     1,     4,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     4,     1,     1,     0,
       2,     1,     1,     4,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     4,     1,     1,     0,
       2,     1,     1,     4,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     4,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     4,     3,     0,     3,     1,
       1,     0,     2,     1,     1,     4,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     0,     4,     1,     1,     0,     2,     1,     1,     4,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     0,     4,     1,     1,
       0,     2,     1,     1,     4,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     3,
       1,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       4,     4,     1,     1,     1,     3,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       0,     4,     1,     5,     0,     2,     5,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     1,     2,
       0,     3,     1,     2,     0,     5,     0,     5,     0,     5,
       0,     4,     0,     5,     0,     5,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     6,     0,     4,     0,     4,     0,     4,
       0,     4,     1,     2,     0,     2,     1,     1,     1,     0,
       4,     0,     4,     4,     0,     4,     1,     2,     0,     4,
       0,     2,     1,     1,     4,     4,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     2,     4,     2,     1,     2,     2,
       1,     3,     2,     1,     2,     2,     1,     2,     4,     1,
       0,     1,     2,     4,     1,     0,     1,     2,     1,     3,
       2,     1,     1,     2,     2,     1,     3,     2,     1,     3,
       2,     1,     3,     0,     4,     0,     2,     2,     1,     3,
       2,     1,     6,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   750,     0,    11,     1,   752,    27,     0,
       0,     0,    29,    37,     0,     0,   754,     0,     9,    14,
      12,    17,    39,   150,     0,     0,     0,    30,     0,     0,
       0,     0,   152,   259,     0,     0,     0,    40,     0,    33,
      35,    28,    31,    32,     0,   751,   757,   755,     0,    10,
      15,     0,     0,     0,     0,     0,    13,    18,    19,    20,
      21,    22,   261,     0,     0,   155,   157,   151,   153,   154,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   376,     4,     3,     7,   264,
     336,   260,   262,   263,   159,   182,     0,     0,     0,   348,
      34,   416,    36,   418,   753,     0,     0,     0,     0,     0,
       0,     0,     6,     2,     5,   265,   269,     0,     0,     0,
       0,   184,   216,     0,     0,     0,   160,   349,    44,    55,
      65,    75,    88,   102,   113,   132,    46,    47,    57,    48,
      67,    49,    77,    50,    90,    51,   104,    52,   115,    53,
     134,     0,   417,     0,   804,   796,   798,   802,   806,   808,
     856,   872,   816,   800,   822,   810,   812,   814,   844,   818,
     820,   864,   860,   868,   786,   790,   794,   830,   824,   826,
     828,     0,   780,   781,   761,   762,   764,   765,   766,   767,
     769,   770,   771,   773,   772,   774,   776,   777,   775,   783,
     784,   785,   759,   760,   763,   782,   778,   779,   768,    26,
      23,    24,    25,   376,   376,   378,   379,   380,   381,   377,
     266,     0,   273,   267,   340,   218,   247,     0,     0,     0,
     185,     0,   163,   166,   158,   161,   162,     0,    56,     0,
      66,     0,    76,     0,    89,     0,   103,     0,   114,     0,
     133,   430,   433,   415,   428,   429,     0,     0,     0,     0,
       0,   419,   420,   423,   424,   422,   421,   758,     0,     0,
       0,     0,     0,     0,   858,   874,     0,     0,     0,     0,
       0,     0,   850,     0,     0,   866,   862,   870,     0,     0,
       0,   834,     0,     0,     0,   756,   373,   374,     0,   273,
     271,     0,     0,   249,     0,     0,     0,     0,   219,     0,
     188,   191,   183,   186,   187,     0,     0,    62,     0,    54,
       0,     0,     0,    58,    59,    60,    61,    72,     0,    64,
      68,    69,    70,    71,    85,     0,    74,     0,     0,     0,
      78,    79,    80,    81,    83,    82,    84,    99,     0,    87,
       0,     0,    91,    92,    93,    94,    96,    95,    97,    98,
     110,     0,   101,     0,   105,   106,   107,   108,   109,     0,
     112,   116,   117,   118,   119,     0,   131,   135,   136,   137,
     138,   435,     0,   463,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     788,     0,   787,   792,     0,   791,     0,     0,   897,   900,
     909,   914,   921,   925,   928,   931,   933,   938,   941,   944,
     891,   903,   906,     0,   876,   877,     0,   878,     0,   890,
       0,   879,     0,   880,   910,   881,   915,   882,     0,   883,
       0,   884,     0,   885,     0,   886,   887,     0,   888,     0,
     889,     0,     0,     0,     0,   268,   272,   275,   338,     0,
       0,     0,   337,   341,   342,   343,   156,     0,     0,   250,
       0,   222,   225,   217,   220,   221,     0,     0,   352,   165,
     169,   164,   167,   171,    63,     0,     0,     0,    73,    86,
     376,     0,     0,   100,     0,     0,   111,     0,   122,     0,
       0,   141,     0,     0,   431,   432,     0,   436,   426,   427,
     425,     0,     0,     0,     0,     0,     0,   807,   809,   857,
     859,   873,   875,   817,   801,     0,   811,   813,   815,   846,
       0,     0,     0,   845,   851,   852,   853,   819,   821,   865,
     867,   861,   863,   869,   871,   789,   793,     0,   832,     0,
       0,     0,     0,   831,   835,   836,   838,   837,   935,     0,
     825,     0,   896,     0,   899,     0,   902,     0,   905,     0,
       0,   911,   918,     0,   916,   922,     0,   920,     0,   924,
       0,   927,     0,   930,     0,   937,     0,   940,     0,   943,
     827,   829,     0,     0,     0,   339,   376,   376,     0,   253,
     255,   248,   251,   252,     0,     0,   353,   190,   194,   189,
     192,   196,     0,   170,   357,     0,     0,     0,     0,     0,
       0,     0,   364,   130,   120,   376,     0,   123,   149,   139,
       0,   142,   700,   469,   697,   464,   465,     0,   466,     0,
     467,     0,   462,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,   458,     0,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   455,   456,   457,   447,   738,   740,
     805,   797,   799,   803,     0,   847,   848,     0,   376,   795,
     833,   839,   376,   841,     0,     0,     0,     0,   898,     0,
     904,   907,     0,     0,     0,   923,     0,     0,     0,     0,
       0,   945,   270,     0,   277,   280,   274,     0,     0,     0,
       0,   354,   224,   228,   223,   226,   230,     0,   195,   180,
       0,   168,     0,     0,     0,     0,     0,   172,   179,   173,
     174,   175,   176,   177,   178,   351,   350,   359,   360,   361,
     362,   363,     0,     0,   126,   384,   121,   124,   125,   145,
     384,   140,   143,   144,   472,   475,   468,   470,   471,     0,
       0,     0,   701,   461,     0,     0,     0,     0,     0,     0,
       0,   376,   376,   823,     0,     0,     0,     0,     0,     0,
     934,   936,     0,     0,   893,     0,   892,   901,   919,     0,
     908,     0,   913,   926,   929,   932,   939,     0,   276,   282,
       0,   299,   345,   346,   356,   254,     0,   256,     0,   229,
     207,   211,   193,   205,   206,     0,     0,     0,     0,   197,
     204,   202,   203,   198,   200,   199,   201,   181,     0,     0,
       0,     0,     0,   376,   375,     0,     0,   128,   382,   383,
       0,   147,   477,   505,   479,     0,     0,     0,   699,     0,
       0,     0,     0,     0,     0,     0,     0,   459,   849,   855,
     854,   840,   843,   842,     0,     0,   894,   912,   917,     0,
       0,   278,   301,   318,     0,     0,   243,   211,   227,   241,
     242,   231,   240,   238,   239,   232,   233,   234,   235,   236,
     237,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,     0,     0,   129,   127,   387,   385,   389,
     148,   146,   507,   535,   509,     0,   478,   698,   696,     0,
     705,     0,     0,   448,   449,   450,   451,   452,   453,   454,
     460,   895,   365,     0,   290,   294,     0,     0,   283,   284,
     285,   281,   288,     0,   320,   279,     0,     0,   245,     0,
     210,   208,     0,   212,     0,     0,     0,     0,   358,   366,
     368,   369,   370,   372,     0,   398,     0,   394,   395,   396,
       0,   388,   537,   587,   539,     0,   508,     0,     0,   748,
       0,   480,   481,   482,   746,   747,   737,   713,   720,     0,
       0,     0,   706,   942,   291,   294,   292,     0,     0,     0,
     309,   313,     0,     0,   302,   303,   304,   300,   307,     0,
       0,     0,   246,   244,   214,     0,   355,   371,   367,     0,
       0,   397,     0,   386,     0,     0,   390,   392,   391,   589,
     631,   591,     0,   538,     0,   510,   511,   512,   485,   476,
       0,     0,     0,   376,     0,     0,   714,     0,   709,   384,
     704,   707,   708,   289,   293,     0,     0,     0,   310,   313,
     311,     0,     0,     0,   327,   331,     0,     0,   321,   322,
     319,   325,   323,   258,   257,   215,   213,   743,   399,     0,
       0,     0,   633,   666,   635,     0,   590,     0,   540,   541,
     542,   515,   506,     0,     0,   492,     0,     0,   488,   384,
     484,   486,   487,     0,   749,   723,   703,   702,   721,   725,
     717,   384,   712,   715,   716,     0,   711,     0,     0,     0,
     286,   287,   308,   312,     0,     0,     0,   328,   331,   329,
       0,     0,     0,   393,     0,     0,   668,     0,   670,     0,
     634,     0,   588,   592,   593,   594,   545,   536,     0,     0,
     522,     0,     0,   518,   384,   514,   516,   517,   499,     0,
       0,   495,   384,   491,   493,   494,   490,     0,   741,     0,
     724,   719,     0,   739,   710,     0,   297,     0,   295,     0,
       0,   305,   306,   326,   330,     0,     0,     0,   744,   745,
     474,   473,     0,   669,     0,   636,   637,   638,   597,     0,
       0,   552,   558,     0,   548,   384,   544,   546,   547,   529,
       0,     0,   525,   384,   521,   523,   524,   520,     0,   483,
     502,   402,   498,   500,   501,   497,     0,   489,   734,   433,
     722,   732,   733,   376,   376,   729,   726,   727,   728,   718,
       0,   298,     0,   316,     0,   314,     0,     0,   324,   344,
       0,   671,   672,   673,   641,   632,     0,     0,   604,     0,
       0,   600,   384,   596,   598,   599,   560,     0,     0,   555,
     384,   551,   553,   554,   550,     0,   513,   532,   384,   528,
     530,   531,   527,     0,   519,     0,   504,   400,   401,     0,
     496,   463,     0,     0,     0,   296,     0,   317,     0,   334,
       0,   332,   676,   667,     0,     0,   653,     0,     0,   644,
     384,   640,   642,   643,   595,     0,   605,   602,     0,   543,
     563,   566,   559,   561,   562,   557,     0,   549,   534,     0,
     526,     0,   405,   403,   406,   503,   736,   735,   376,   376,
     315,     0,   335,   683,     0,     0,   679,   384,   675,   677,
     678,   660,     0,     0,   656,   384,   652,   654,   655,   646,
       0,   608,   603,   601,     0,   565,   556,   533,   413,     0,
     409,   410,   411,     0,   407,   730,   731,   333,   690,     0,
       0,   686,   384,   682,   684,   685,   681,     0,   639,   663,
     384,   659,   661,   662,   658,     0,   645,   610,     0,   616,
       0,   564,   569,   567,   571,     0,   412,   376,   404,   674,
     693,   384,   689,   691,   692,   688,     0,   680,   665,     0,
     657,   606,   618,   607,     0,   613,   384,   609,   611,   612,
       0,   570,   414,     0,   695,     0,   687,   664,   621,   623,
     617,   619,   620,   615,     0,   578,   580,   568,   576,   577,
       0,     0,   572,   574,   573,   408,   694,     0,   614,     0,
     376,     0,   626,   622,   624,     0,   579,   583,   581,   584,
       0,     0,   629,     0,   625,   627,   628,     0,     0,   575,
     742,     0,   376,     0,   582,   630,     0,     0,   585,   586
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,   113,   114,     3,     5,    11,    20,    21,
      56,    31,    57,    58,    59,    60,    61,    13,    14,    26,
      41,    42,    43,    77,    23,    24,    36,    73,    74,    75,
      98,   136,   137,   138,   237,   238,   323,   319,   139,   140,
     239,   240,   330,   329,   141,   142,   241,   242,   340,   336,
     143,   144,   243,   244,   352,   349,   145,   146,   245,   246,
     364,   362,   147,   148,   247,   248,   371,   370,   509,   510,
     636,   756,   757,   758,   846,   916,   634,   149,   150,   249,
     250,   377,   376,   512,   513,   640,   761,   762,   763,   850,
     921,   639,    33,    34,    67,    68,    69,    95,    96,   125,
     234,   235,   236,   491,   316,   492,   493,   622,   623,   737,
     731,   122,   123,   229,   312,   313,   314,   619,   487,   620,
     621,   727,   728,   829,   822,   823,   824,   901,   961,   902,
     963,   964,  1086,   226,   227,   307,   483,   484,   485,   724,
     615,   725,   726,   818,   819,   891,   888,   889,   890,   959,
    1023,   304,   305,   478,   611,   612,   613,   720,   817,   885,
      63,    64,    91,    92,    93,   117,   118,   222,   299,   300,
     301,   604,   716,   810,   811,   880,   948,   949,   950,   951,
     952,  1005,  1006,  1007,  1129,  1188,   883,   953,  1014,  1015,
    1016,  1017,  1018,  1069,  1070,  1071,  1190,  1255,   955,  1019,
    1078,  1079,  1080,  1081,  1138,  1139,  1140,  1257,  1311,   119,
     120,   472,   302,   473,  1082,   474,   475,   637,    27,    37,
     324,   325,   126,   230,   308,   830,   479,   326,   832,   344,
     345,   346,   358,   359,   368,   697,   740,   834,   741,   742,
     743,   835,   744,   110,   752,   111,   219,   847,   848,   918,
     919,   980,   981,  1036,  1033,   849,   977,   978,   979,  1296,
    1297,  1343,  1344,  1383,  1418,  1298,  1380,  1381,  1382,   102,
     103,   151,   152,   261,   262,   263,   264,   253,   254,   255,
     382,   383,   384,   516,   517,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   654,   515,
     645,   646,   647,   766,   767,   768,  1201,   853,   854,   925,
     926,   991,  1049,  1050,  1051,  1110,  1111,  1112,  1177,  1106,
    1107,  1173,  1174,  1175,  1236,  1169,  1170,  1232,  1233,  1234,
    1299,   923,   924,   985,   986,  1045,  1102,  1103,  1104,  1165,
    1166,  1167,  1228,  1161,  1162,  1224,  1225,  1226,  1293,  1220,
    1221,  1289,  1290,  1291,  1339,   983,   984,  1042,  1043,  1098,
    1157,  1158,  1159,  1216,  1217,  1218,  1285,  1212,  1213,  1281,
    1282,  1283,  1336,  1277,  1278,  1332,  1333,  1334,  1374,  1375,
    1413,  1414,  1440,  1441,  1462,  1463,  1457,  1458,  1459,  1469,
    1478,  1479,  1488,  1494,  1040,  1041,  1095,  1096,  1153,  1152,
    1209,  1210,  1273,  1274,  1275,  1328,  1269,  1270,  1325,  1372,
    1408,  1409,  1410,  1437,  1438,  1439,  1454,  1433,  1434,  1450,
    1451,  1452,  1467,  1474,  1475,  1484,  1485,  1486,  1093,  1094,
    1149,  1150,  1205,  1265,  1266,  1267,  1321,  1322,  1323,  1370,
    1317,  1318,  1366,  1367,  1368,  1405,  1362,  1363,  1401,  1402,
    1403,  1429,  1147,  1148,  1202,  1203,  1261,  1313,  1314,  1315,
    1358,  1359,  1360,  1397,  1354,  1355,  1393,  1394,  1395,  1426,
    1389,  1390,  1422,  1423,  1424,  1445,   648,   649,   928,   650,
     651,   771,   858,  1117,   931,   932,  1001,  1060,  1061,  1062,
    1127,   998,   999,  1055,  1122,  1123,  1124,  1182,  1054,  1118,
    1119,  1179,  1180,  1246,  1247,  1248,  1240,  1241,  1242,  1302,
     772,   265,  1002,   266,   992,  1464,   914,  1037,  1038,   993,
     994,   995,     8,     9,    16,    29,    47,    48,    80,   181,
     182,   288,   412,   183,   289,   415,   184,   290,   185,   269,
     186,   270,   187,   277,   188,   271,   189,   268,   190,   272,
     191,   273,   192,   279,   193,   280,   194,   281,   195,   276,
     196,   283,   197,   284,   198,   278,   199,   292,   200,   293,
     201,   294,   202,   291,   563,   417,   564,   565,   787,   566,
     789,   567,   203,   282,   543,   784,   404,   544,   545,   546,
     204,   274,   396,   205,   286,   408,   206,   285,   407,   207,
     287,   409,   208,   275,   397,   433,   434,   569,   796,   435,
     436,   572,   437,   438,   574,   439,   440,   576,   441,   442,
     578,   443,   444,   580,   800,   445,   446,   583,   802,   581,
     582,   447,   448,   587,   449,   450,   589,   451,   452,   591,
     453,   454,   593,   455,   568,   694,   456,   457,   595,   458,
     459,   597,   460,   461,   599
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -981
static const yytype_int16 yypact[] =
{
      59,    90,   127,   -64,   202,  -981,  -981,  -981,   184,     3,
     229,    52,  -981,   206,   211,   243,  -981,   245,  -981,  -981,
    -981,  -981,  -981,   192,   231,   260,    63,  -981,   264,  -113,
     262,    29,  -981,   185,    78,   272,   120,  -981,   287,  -981,
    -981,  -981,  -981,  -981,   312,  -981,  -981,  -981,   302,  -981,
    -981,   294,   346,   348,   355,   359,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   139,   160,  -981,   256,  -981,  -981,  -981,
     357,  -981,  -981,  -981,  -981,  -981,   365,    14,   361,   367,
     363,  -981,   369,   373,   375,  -981,  -981,  -981,   372,  -981,
      74,  -981,  -981,  -981,  -981,   347,   338,   421,   219,  -981,
    -981,  -981,  -981,  -981,  -981,   433,   628,   438,   440,   441,
     442,    30,  -981,  -981,  -981,  -981,  -981,   344,   340,   349,
     322,  -981,   371,   377,   447,   193,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   197,    20,   450,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   221,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   452,  -981,  -981,  -981,  -981,   370,   379,   454,   208,
    -981,   451,  -981,  -981,  -981,  -981,  -981,   210,    33,   212,
      33,   215,    36,   217,    31,   259,    22,   449,    33,   453,
      33,  -981,   296,  -981,  -981,  -981,   457,   458,   461,   463,
     464,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   628,   628,
     628,   628,   628,   628,  -981,  -981,   628,   628,   628,   628,
     628,   628,  -981,   628,   628,  -981,  -981,  -981,   278,   282,
     628,  -981,    69,    69,    69,  -981,  -212,  -212,   462,   364,
    -981,   366,    54,  -981,   403,   385,   471,   286,  -981,   468,
    -981,  -981,  -981,  -981,  -981,   473,    67,  -981,   443,  -981,
     474,   480,   481,  -981,  -981,  -981,  -981,  -981,   439,  -981,
    -981,  -981,  -981,  -981,  -981,   444,  -981,   482,   484,   485,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   445,  -981,
     487,   488,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   446,  -981,   489,  -981,  -981,  -981,  -981,  -981,   455,
    -981,  -981,  -981,  -981,  -981,   437,  -981,  -981,  -981,  -981,
    -981,  -981,   330,  -981,  -981,   493,   494,   495,   492,   496,
     628,   628,   628,   628,   258,   257,   284,   448,   253,   252,
     628,   249,   248,   247,    35,   244,   246,   467,   504,   543,
    -981,   236,  -981,  -981,   235,  -981,   628,    40,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   232,  -981,  -981,    69,  -981,    69,  -981,
     628,  -981,    69,  -981,   198,  -981,   198,  -981,   288,  -981,
      69,  -981,    69,  -981,    69,  -981,  -981,   628,  -981,    69,
    -981,    69,   234,   238,   513,  -981,  -981,   500,  -981,   414,
     520,   524,  -981,  -981,  -981,  -981,  -981,   530,   290,  -981,
     528,  -981,  -981,  -981,  -981,  -981,   540,   112,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,   544,   542,   546,  -981,  -981,
    -981,   548,   550,  -981,   552,   554,  -981,   560,  -981,   503,
     413,  -981,   517,   413,  -981,  -100,   292,   -84,  -981,  -981,
    -981,   566,   568,   339,   336,   341,   342,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,   628,  -981,  -981,  -981,  -981,
     597,   569,   573,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,   300,  -981,   304,
     574,   578,   580,  -981,  -981,  -981,  -981,  -981,  -981,    17,
    -981,   293,  -981,    69,  -981,   273,  -981,   274,  -981,   585,
     579,  -981,  -981,   581,  -981,  -981,   298,  -981,    69,  -981,
      69,  -981,    69,  -981,    69,  -981,   628,  -981,   283,  -981,
    -981,  -981,   582,   592,   295,  -981,  -981,  -981,   590,  -981,
    -981,  -981,  -981,  -981,   595,   115,  -981,  -981,  -981,  -981,
    -981,  -981,   297,    64,  -981,   596,   598,   599,   600,   601,
     603,   604,  -981,  -981,  -981,  -981,   299,  -981,  -981,  -981,
     301,  -981,  -981,  -981,  -981,  -981,  -981,   303,  -981,   589,
    -981,   431,  -981,   459,  -981,   606,   607,   609,   610,   612,
     613,   614,   615,  -981,   616,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   368,  -981,  -981,   617,  -981,  -981,
    -981,  -981,  -981,  -981,   -55,   618,   623,   307,  -981,   328,
    -981,  -981,   624,    69,    69,  -981,   329,   332,   326,   323,
     628,  -981,  -981,   629,  -981,   521,  -981,   631,   632,   634,
     108,  -981,  -981,  -981,  -981,  -981,  -981,   316,   133,  -981,
     567,  -981,   635,   637,   638,   639,   640,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,   641,    15,  -981,   490,  -981,  -981,  -981,  -981,
     490,  -981,  -981,  -981,  -981,   456,  -981,  -981,  -981,    69,
     642,   633,  -981,  -981,   644,   645,   646,   647,   648,   649,
     651,  -981,  -981,  -981,   383,   656,   657,   658,   659,   660,
    -981,  -981,   661,   662,  -981,   351,  -981,  -981,  -981,   374,
    -981,   381,  -981,  -981,  -981,  -981,  -981,   628,  -981,  -981,
     559,   555,  -981,  -981,  -981,  -981,   652,  -981,   319,    51,
    -981,  -981,  -981,  -981,  -981,   668,   669,   670,   671,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   667,   672,
     673,   674,   676,  -981,  -981,   516,   643,  -981,   523,  -981,
     697,  -981,  -981,   483,  -981,   472,   750,   539,  -981,   758,
     760,   762,   764,   766,   768,   770,   789,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   791,   793,  -981,  -981,  -981,   628,
      45,  -981,  -981,   686,   797,   795,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   725,   720,   801,   803,   805,   811,   815,   817,   819,
     821,   823,  -981,   825,   321,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   626,  -981,   827,   -45,  -981,  -981,   831,
    -981,   608,   684,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   531,  -981,   729,   841,   845,  -981,  -981,
    -981,  -981,  -981,    49,  -981,  -981,   843,   628,   720,   772,
    -981,  -981,   847,  -981,    69,   849,   853,   882,  -981,  -981,
    -981,  -981,  -981,  -981,   880,  -981,    24,  -981,  -981,  -981,
     878,   174,  -981,   683,  -981,   884,   -45,   701,   890,  -981,
     895,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   684,
     898,   325,  -981,  -981,  -981,   790,  -981,   785,   900,   902,
    -981,   799,   908,   912,  -981,  -981,  -981,  -981,  -981,    56,
     913,   828,  -981,  -981,  -981,   832,  -981,  -981,  -981,   916,
     763,  -981,   915,  -981,   917,   920,  -981,  -981,  -981,  -981,
     714,  -981,   914,   -45,   730,  -981,  -981,  -981,  -981,  -981,
     727,   331,   921,  -981,   -93,   333,  -981,   922,  -981,   490,
    -981,  -981,  -981,  -981,  -981,   918,   927,   929,  -981,   820,
    -981,   813,   926,   930,  -981,   824,   935,   937,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   778,
     936,   938,  -981,   732,  -981,   931,   -45,   751,  -981,  -981,
    -981,  -981,  -981,   746,   335,  -981,   747,   337,  -981,   490,
    -981,  -981,  -981,   945,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   490,  -981,  -981,  -981,   947,  -981,   731,   948,   376,
    -981,  -981,  -981,  -981,   939,   950,   951,  -981,   840,  -981,
     834,   949,   952,  -981,   957,   958,  -981,   769,  -981,   953,
     -45,   767,  -981,  -981,  -981,  -981,  -981,  -981,   765,   378,
    -981,   771,   380,  -981,   490,  -981,  -981,  -981,  -981,   773,
     382,  -981,   490,  -981,  -981,  -981,  -981,   774,  -981,   384,
    -112,  -981,   743,  -981,  -981,   960,  -981,   848,  -981,   967,
     386,  -981,  -981,  -981,  -981,   954,   971,   972,  -981,  -981,
    -981,  -981,   965,   -45,   781,  -981,  -981,  -981,  -981,   780,
     388,  -981,   777,   390,  -981,   490,  -981,  -981,  -981,  -981,
     775,   392,  -981,   490,  -981,  -981,  -981,  -981,   784,  -981,
    -981,   826,  -981,  -981,  -981,  -981,   786,  -981,  -981,   296,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     979,  -981,   978,  -981,   863,  -981,   985,   394,  -981,  -981,
     794,  -981,  -981,  -981,  -981,  -981,   792,   396,  -981,   782,
     684,  -981,   490,  -981,  -981,  -981,  -981,   787,   400,  -981,
     490,  -981,  -981,  -981,  -981,   796,  -981,  -981,   490,  -981,
    -981,  -981,  -981,   788,  -981,   516,  -981,   833,  -981,   798,
    -981,  -981,   829,   989,   990,  -981,   996,  -981,   993,  -981,
     877,  -981,  -981,  -981,   804,   402,  -981,   806,   404,  -981,
     490,  -981,  -981,  -981,  -981,   992,  -981,  -981,   808,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,   809,  -981,  -981,   810,
    -981,   406,  -981,  -981,   851,  -981,  -100,  -981,  -981,  -981,
    -981,  1004,  -981,  -981,   807,   408,  -981,   490,  -981,  -981,
    -981,  -981,   812,   412,  -981,   490,  -981,  -981,  -981,  -981,
     818,   814,  -981,  -981,   816,   850,  -981,  -981,  -981,    26,
    -981,  -981,  -981,  1005,  -981,  -981,  -981,  -981,  -981,   822,
     416,  -981,   490,  -981,  -981,  -981,  -981,   830,  -981,  -981,
     490,  -981,  -981,  -981,  -981,   837,  -981,  -981,   835,   838,
     420,  -981,  -981,  -981,  -981,   859,  -981,  -981,  -981,  -981,
    -981,   490,  -981,  -981,  -981,  -981,   842,  -981,  -981,   836,
    -981,  -981,  -981,  -981,   422,  -981,   490,  -981,  -981,  -981,
     426,  -105,  -981,   855,  -981,   839,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   844,  -981,  -981,  -981,  -981,  -981,
    1017,  1018,  -981,  -981,  -981,  -981,  -981,   -94,  -981,  -130,
    -981,  1015,  -981,  -981,  -981,   428,  -981,  -981,  -981,   703,
    1022,  1023,  -981,   628,  -981,  -981,  -981,  1025,  1019,  -981,
    -981,   866,  -981,  1024,  -981,  -981,  1029,   846,  -981,  -981
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   146,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   742,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,    39,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   -23,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,   -91,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,   535,  -981,  -981,
      34,    37,  -981,  -981,  -981,   230,  -981,  -214,   233,   852,
     854,  -981,  -981,  -981,  -981,  -602,   237,  -981,   239,   240,
     241,  -981,  -670,  -486,  -762,  -207,  -981,  -743,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -129,  -981,  -981,  -981,  -981,  -981,
    -981,  -189,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -248,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -980,  -981,  -963,  -981,  -241,  -981,  -289,  -959,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -268,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -269,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   611,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     390,   391,   392,   393,   394,   395,   296,   297,   398,   399,
     400,   401,   402,   403,   627,   405,   406,   851,   844,  1056,
     867,   739,   416,  1046,   462,   463,   333,  1047,   343,  1030,
     355,  1415,   367,  1476,   374,   695,   380,   213,   214,    50,
      51,   256,   257,   320,   100,   539,   540,    52,    53,    54,
     558,   559,   320,   541,   320,   944,   945,   320,   836,  1010,
    1011,   258,   560,   561,   468,   469,  1074,  1075,  1472,   695,
     642,  1460,   320,    39,    40,  1115,  1461,    18,  1116,    19,
    1099,   912,   695,     1,  1100,   320,  1477,   363,    65,    66,
     337,   338,   643,   350,   351,   337,   338,   339,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   696,  1473,
     215,   216,   217,   218,  1243,  1244,     4,    45,   644,    46,
     717,   718,   523,   524,   525,   526,   833,     6,   530,   532,
      71,    72,   535,  1154,   825,   988,   489,  1155,   490,   550,
     552,   554,   696,   732,   733,   734,   735,   736,   557,   900,
     828,   695,    86,    87,   320,   696,   732,   733,   734,   735,
     736,   946,   470,   471,   947,     7,  1012,   571,  1013,   573,
      89,    90,   575,   577,  1076,  1077,   115,   116,   101,   989,
     990,   588,  1031,   590,  1416,   592,   617,  1206,   618,   594,
     596,  1207,   598,   258,   722,   815,   723,   816,   259,   260,
     321,   322,   786,   232,   233,    10,   788,   251,   252,   321,
     322,   321,   322,    12,   321,   322,   825,   895,   310,   311,
     317,   318,   327,   328,   696,   334,   335,   347,   348,   736,
     826,   827,   828,   418,    15,   419,    17,   420,    22,   421,
    1262,   422,    25,   423,  1263,   424,    28,   425,    30,   426,
     790,   427,   128,   428,   129,   429,   130,   430,    32,   431,
     131,   432,   132,    38,   133,    35,   134,   684,   135,   360,
     361,    44,   686,    49,   331,    70,   341,   332,   353,   342,
     365,   354,   372,   366,   378,   373,    62,   379,   410,   411,
    1326,  1114,   413,   414,    76,   866,   481,   482,   585,   586,
     609,   610,   652,   653,   699,   714,   715,   729,   730,   754,
     755,   759,   760,   764,   765,    78,  1126,   794,   795,   706,
      79,   707,    81,   708,    94,   709,   820,   821,   710,   886,
     887,   975,   976,  1034,  1035,  1058,  1059,   215,   216,   217,
     218,  1108,  1109,  1120,  1121,  1163,  1164,  1171,  1172,    82,
      55,    83,   215,   216,   217,   218,   542,   418,    84,   419,
     562,   420,    85,   421,    97,   422,  1176,   423,    99,   424,
     105,   425,   104,   426,   106,   427,   107,   428,  1181,   429,
     108,   430,   109,   431,   112,   432,  1186,  1187,  1214,  1215,
    1222,  1223,  1230,  1231,  1238,  1239,  1253,  1254,  1271,  1272,
    1279,  1280,  1287,  1288,  1309,  1310,  1319,  1320,   124,   738,
    1330,  1331,  1356,  1357,  1364,  1365,  1378,  1379,  1391,  1392,
     121,  1227,  1399,  1400,   127,   791,  1420,  1421,   753,  1235,
    1435,  1436,  1448,  1449,   799,   801,  1455,  1456,  1482,  1483,
     153,   209,   807,   210,   211,   212,   220,   221,   224,   225,
     231,   223,   228,   267,   295,   298,   303,   309,   315,   306,
     369,   385,   386,   381,   375,   387,   388,   389,   465,   464,
     476,   467,  1284,   477,   480,   486,   488,   498,   495,   494,
    1292,  1303,  1304,   496,   497,   500,   499,   501,   502,   503,
     504,   505,   506,   507,   511,   514,   518,   519,   520,   521,
     855,   527,   528,   522,   533,   534,   536,   537,   538,   547,
     508,   555,   556,   548,   831,   570,   602,   579,   154,   600,
     155,   603,   156,   606,   157,   601,   158,   607,   159,  1327,
     160,   529,   161,   608,   162,   614,   163,  1335,   164,   879,
     165,   605,   166,   616,   167,  1338,   168,   624,   169,   625,
     170,   633,   171,   626,   172,   628,   173,   629,   174,   630,
     175,   631,   176,   632,   177,   635,   178,   638,   179,   678,
     180,   679,   687,   681,   680,   753,   688,  1369,   691,   689,
     682,   692,   698,   683,   693,   690,  1385,  1386,   700,   702,
     703,   701,   704,   712,   711,   705,   713,   719,   721,   745,
     769,   746,   747,   748,   749,   893,   750,   751,   770,   774,
     775,   943,   776,   777,  1396,   778,   779,   780,   781,   797,
     782,   792,  1404,   783,   785,   773,   793,   798,   803,   805,
     806,   809,   808,   804,   812,   813,   753,   814,   838,   837,
     839,   840,   841,   842,   857,   856,   868,   845,   843,  1425,
     852,   859,   860,   861,   862,   863,   864,  1428,   865,   869,
     870,   871,   872,   873,   876,   881,   882,   877,   874,   875,
     884,   903,   904,   905,   907,   906,   878,   913,  1444,   908,
     909,   910,   154,   911,   155,   917,   156,   922,   157,  1021,
     158,   927,   159,  1453,   160,  1025,   161,   531,   162,   915,
     163,   154,   164,   155,   165,   156,   166,   157,   167,   158,
     168,   159,   169,   160,   170,   161,   171,   162,   172,   163,
     173,   164,   174,   165,   175,   166,   176,   167,   177,   168,
     178,   169,   179,   170,   180,   171,   549,   172,   154,   173,
     155,   174,   156,   175,   157,   176,   158,   177,   159,   178,
     160,   179,   161,   180,   162,   920,   163,   929,   164,   930,
     165,   933,   166,   934,   167,   935,   168,   936,   169,   937,
     170,   938,   171,   939,   172,   551,   173,   154,   174,   155,
     175,   156,   176,   157,   177,   158,   178,   159,   179,   160,
     180,   161,   940,   162,   941,   163,   942,   164,   954,   165,
     956,   166,   960,   167,   962,   168,   957,   169,   965,   170,
     966,   171,   967,   172,   968,   173,   553,   174,   969,   175,
     970,   176,   971,   177,   972,   178,   973,   179,   974,   180,
     997,   154,   982,   155,   996,   156,  1000,   157,   987,   158,
    1003,   159,  1004,   160,  1008,   161,   753,   162,  1009,   163,
    1020,   164,  1026,   165,  1022,   166,  1027,   167,  1024,   168,
     685,   169,   154,   170,   155,   171,   156,   172,   157,   173,
     158,   174,   159,   175,   160,   176,   161,   177,   162,   178,
     163,   179,   164,   180,   165,  1028,   166,  1029,   167,  1032,
     168,  1039,   169,  1052,   170,  1044,   171,  1048,   172,  1053,
     173,  1057,   174,  1063,   175,  1065,   176,  1066,   177,  1067,
     178,  1072,   179,  1068,   180,  1073,  1083,  1085,  1084,  1087,
    1090,  1088,  1089,  1091,  1092,  1097,  1101,  1105,  1113,  1125,
    1130,  1443,  1131,  1135,  1132,  1134,  1128,  1136,  1141,  1137,
    1142,  1143,  1151,  1144,  1146,  1145,  1160,  1156,  1178,  1168,
    1183,  1185,  1184,  1191,  1192,  1193,  1196,  1189,  1195,  1197,
    1198,  1199,  1200,  1208,  1204,  1211,  1249,  1250,  1229,  1251,
    1252,  1237,  1256,  1219,  1258,  1259,  1260,  1264,  1268,  1276,
    1286,  1294,  1305,  1295,  1480,  1306,  1307,  1300,  1308,  1340,
    1312,  1324,  1316,  1337,  1329,  1342,  1348,  1349,  1347,  1350,
    1351,  1345,  1352,  1371,  1353,  1373,  1496,  1387,  1361,  1388,
    1376,  1035,  1412,  1377,  1407,  1406,  1417,  1442,  1465,  1411,
    1470,  1471,  1481,  1398,  1487,  1489,  1490,  1427,  1492,  1495,
    1493,  1497,  1498,   958,  1431,  1419,   753,   753,  1430,  1447,
    1432,   466,  1466,  1446,  1064,  1468,  1133,  1194,   641,   892,
    1301,  1245,   894,  1346,  1341,  1384,   896,   584,   897,   898,
     899,     0,     0,  1499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   753,   753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1491
};

static const yytype_int16 yycheck[] =
{
     268,   269,   270,   271,   272,   273,   213,   214,   276,   277,
     278,   279,   280,   281,   500,   283,   284,   760,     3,   999,
     782,   623,   290,   986,   293,   294,   240,   986,   242,     5,
     244,     5,   246,   163,   248,    18,   250,     7,     8,    10,
      11,    21,    22,    21,    30,    10,    11,    18,    19,    20,
      10,    11,    21,    18,    21,    10,    11,    21,   728,    10,
      11,   173,    22,    23,    10,    11,    10,    11,   162,    18,
     170,   176,    21,    10,    11,   168,   181,    25,   171,    27,
    1043,   843,    18,    24,  1043,    21,   216,    65,    10,    11,
      59,    60,   192,    62,    63,    59,    60,    61,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    91,   203,
     322,   323,   324,   325,   226,   227,    26,   230,   218,   232,
     606,   607,   390,   391,   392,   393,   728,     0,   396,   397,
      10,    11,   400,  1096,    83,   180,    69,  1096,    71,   407,
     408,   409,    91,    92,    93,    94,    95,    96,   416,   819,
      99,    18,    13,    14,    21,    91,    92,    93,    94,    95,
      96,   116,   108,   109,   119,   229,   117,   436,   119,   438,
      10,    11,   440,   442,   118,   119,   102,   103,   164,   224,
     225,   450,   158,   452,   158,   454,    74,  1150,    76,   457,
     459,  1150,   461,   173,    79,    87,    81,    89,   178,   179,
     178,   179,   688,    10,    11,     3,   692,    10,    11,   178,
     179,   178,   179,    29,   178,   179,    83,   819,    10,    11,
      10,    11,    10,    11,    91,    10,    11,    10,    11,    96,
      97,    98,    99,   288,   231,   290,     7,   292,    32,   294,
    1203,   296,    31,   298,  1203,   300,     3,   302,     3,   304,
     305,   306,    33,   308,    35,   310,    37,   312,    66,   314,
      41,   316,    43,     3,    45,    34,    47,   535,    49,    10,
      11,     7,   540,    11,   240,     3,   242,   240,   244,   242,
     246,   244,   248,   246,   250,   248,   101,   250,    10,    11,
    1270,  1053,    10,    11,     7,   781,    10,    11,    10,    11,
      10,    11,    10,    11,   573,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     3,  1059,    10,    11,   588,
      18,   590,    28,   592,    68,   594,    10,    11,   596,    10,
      11,    10,    11,   159,   160,    10,    11,   322,   323,   324,
     325,    10,    11,    10,    11,    10,    11,    10,    11,     3,
     321,     3,   322,   323,   324,   325,   321,   288,     3,   290,
     320,   292,     3,   294,     7,   296,  1109,   298,     3,   300,
       3,   302,    11,   304,    11,   306,     7,   308,  1121,   310,
       7,   312,     7,   314,    12,   316,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    70,   623,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      73,  1164,    10,    11,     3,   694,    10,    11,   635,  1172,
      10,    11,    10,    11,   703,   704,    10,    11,    10,    11,
       7,     3,   710,     3,     3,     3,   102,   107,   126,    78,
       3,   102,    75,     3,   233,     3,    86,     3,     7,    80,
      11,     4,     4,   167,    11,     4,     3,     3,   104,     7,
      67,   105,  1215,    88,     3,     7,     3,    38,     4,    36,
    1223,  1243,  1244,     3,     3,     3,    42,     3,     3,    44,
       3,     3,    46,     4,    57,   165,     3,     3,     3,     7,
     769,   243,   245,     7,   251,   253,   257,   259,   261,   265,
      55,   275,   277,   267,   728,   283,     3,   319,   234,   285,
     236,    21,   238,     3,   240,   287,   242,     3,   244,  1272,
     246,   247,   248,     3,   250,     7,   252,  1280,   254,   807,
     256,   127,   258,     3,   260,  1288,   262,     3,   264,     7,
     266,    48,   268,     7,   270,     7,   272,     7,   274,     7,
     276,     7,   278,     3,   280,   152,   282,    50,   284,     3,
     286,     3,     3,   237,   235,   782,     3,  1320,     4,   279,
     239,     3,   289,   241,     4,   281,  1348,  1349,   315,     4,
      11,   317,    11,    11,   311,   297,     4,     7,     3,     3,
      11,     3,     3,     3,     3,   819,     3,     3,   177,     3,
       3,   879,     3,     3,  1357,     3,     3,     3,     3,   291,
       4,     3,  1365,   255,     7,   166,     3,     3,   299,   303,
     307,   110,     3,   301,     3,     3,   843,     3,     3,    72,
       3,     3,     3,     3,    11,     3,   263,   157,     7,  1392,
     194,     7,     7,     7,     7,     7,     7,  1400,     7,     3,
       3,     3,     3,     3,   313,   106,   111,   293,     7,     7,
      18,     3,     3,     3,     7,     4,   295,   161,  1421,     7,
       7,     7,   234,     7,   236,   162,   238,   204,   240,   957,
     242,   219,   244,  1436,   246,   964,   248,   249,   250,    56,
     252,   234,   254,   236,   256,   238,   258,   240,   260,   242,
     262,   244,   264,   246,   266,   248,   268,   250,   270,   252,
     272,   254,   274,   256,   276,   258,   278,   260,   280,   262,
     282,   264,   284,   266,   286,   268,   269,   270,   234,   272,
     236,   274,   238,   276,   240,   278,   242,   280,   244,   282,
     246,   284,   248,   286,   250,    58,   252,     7,   254,   220,
     256,     3,   258,     3,   260,     3,   262,     3,   264,     3,
     266,     3,   268,     3,   270,   271,   272,   234,   274,   236,
     276,   238,   278,   240,   280,   242,   282,   244,   284,   246,
     286,   248,     3,   250,     3,   252,     3,   254,   112,   256,
       3,   258,    77,   260,    84,   262,    11,   264,     7,   266,
       7,   268,     7,   270,     3,   272,   273,   274,     3,   276,
       3,   278,     3,   280,     3,   282,     3,   284,     3,   286,
     222,   234,   206,   236,     3,   238,   152,   240,    11,   242,
     309,   244,   113,   246,     3,   248,  1053,   250,     3,   252,
       7,   254,     3,   256,    82,   258,     3,   260,    11,   262,
     263,   264,   234,   266,   236,   268,   238,   270,   240,   272,
     242,   274,   244,   276,   246,   278,   248,   280,   250,   282,
     252,   284,   254,   286,   256,     3,   258,     7,   260,    11,
     262,   208,   264,     3,   266,    11,   268,   196,   270,     4,
     272,     3,   274,   113,   276,   120,   278,     7,   280,     7,
     282,     3,   284,   114,   286,     3,     3,    85,    90,     3,
       3,   158,     7,     3,   210,    11,   196,   200,     7,     7,
       3,  1417,     3,     7,   114,   122,    18,     7,     3,   115,
       3,   163,    11,     7,   212,     7,   200,   196,     3,   202,
       3,     3,   221,     3,     3,   115,     7,    18,   124,     7,
       3,     3,   193,   196,    11,   200,   223,     7,   195,   121,
       3,   197,    18,   202,     3,     3,    11,   196,   198,   202,
     205,   197,     3,   157,  1470,     7,   123,   201,     3,   201,
     196,   209,   200,   197,   207,   162,     7,     7,   169,     3,
       7,   203,   125,    11,   200,   197,  1492,     3,   202,   202,
     201,   160,   162,   203,   200,   197,    11,   158,   163,   203,
       3,     3,     7,   211,   321,     3,     3,   197,     3,   163,
      11,     7,     3,   887,   199,   213,  1243,  1244,   201,   203,
     202,   299,   203,   201,  1005,   201,  1069,  1138,   513,   819,
    1239,  1180,   819,  1301,  1295,  1344,   819,   446,   819,   819,
     819,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1348,  1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1483
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   327,   331,    26,   332,     0,   229,   848,   849,
       3,   333,    29,   343,   344,   231,   850,     7,    25,    27,
     334,   335,    32,   350,   351,    31,   345,   544,     3,   851,
       3,   337,    66,   418,   419,    34,   352,   545,     3,    10,
      11,   346,   347,   348,     7,   230,   232,   852,   853,    11,
      10,    11,    18,    19,    20,   321,   336,   338,   339,   340,
     341,   342,   101,   486,   487,    10,    11,   420,   421,   422,
       3,    10,    11,   353,   354,   355,     7,   349,     3,    18,
     854,    28,     3,     3,     3,     3,    13,    14,   328,    10,
      11,   488,   489,   490,    68,   423,   424,     7,   356,     3,
      30,   164,   595,   596,    11,     3,    11,     7,     7,     7,
     569,   571,    12,   329,   330,   102,   103,   491,   492,   535,
     536,    73,   437,   438,    70,   425,   548,     3,    33,    35,
      37,    41,    43,    45,    47,    49,   357,   358,   359,   364,
     365,   370,   371,   376,   377,   382,   383,   388,   389,   403,
     404,   597,   598,     7,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   282,   284,
     286,   855,   856,   859,   862,   864,   866,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   886,   888,   890,   892,
     894,   896,   898,   908,   916,   919,   922,   925,   928,     3,
       3,     3,     3,     7,     8,   322,   323,   324,   325,   572,
     102,   107,   493,   102,   126,    78,   459,   460,    75,   439,
     549,     3,    10,    11,   426,   427,   428,   360,   361,   366,
     367,   372,   373,   378,   379,   384,   385,   390,   391,   405,
     406,    10,    11,   603,   604,   605,    21,    22,   173,   178,
     179,   599,   600,   601,   602,   837,   839,     3,   873,   865,
     867,   871,   875,   877,   917,   929,   885,   869,   891,   879,
     881,   883,   909,   887,   889,   923,   920,   926,   857,   860,
     863,   899,   893,   895,   897,   233,   571,   571,     3,   494,
     495,   496,   538,    86,   477,   478,    80,   461,   550,     3,
      10,    11,   440,   441,   442,     7,   430,    10,    11,   363,
      21,   178,   179,   362,   546,   547,   553,    10,    11,   369,
     368,   546,   547,   553,    10,    11,   375,    59,    60,    61,
     374,   546,   547,   553,   555,   556,   557,    10,    11,   381,
      62,    63,   380,   546,   547,   553,   555,   556,   558,   559,
      10,    11,   387,    65,   386,   546,   547,   553,   560,    11,
     393,   392,   546,   547,   553,    11,   408,   407,   546,   547,
     553,   167,   606,   607,   608,     4,     4,     4,     3,     3,
     855,   855,   855,   855,   855,   855,   918,   930,   855,   855,
     855,   855,   855,   855,   912,   855,   855,   924,   921,   927,
      10,    11,   858,    10,    11,   861,   855,   901,   288,   290,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     312,   314,   316,   931,   932,   935,   936,   938,   939,   941,
     942,   944,   945,   947,   948,   951,   952,   957,   958,   960,
     961,   963,   964,   966,   967,   969,   972,   973,   975,   976,
     978,   979,   931,   931,     7,   104,   495,   105,    10,    11,
     108,   109,   537,   539,   541,   542,    67,    88,   479,   552,
       3,    10,    11,   462,   463,   464,     7,   444,     3,    69,
      71,   429,   431,   432,    36,     4,     3,     3,    38,    42,
       3,     3,     3,    44,     3,     3,    46,     4,    55,   394,
     395,    57,   409,   410,   165,   625,   609,   610,     3,     3,
       3,     7,     7,   855,   855,   855,   855,   243,   245,   247,
     855,   249,   855,   251,   253,   855,   257,   259,   261,    10,
      11,    18,   321,   910,   913,   914,   915,   265,   267,   269,
     855,   271,   855,   273,   855,   275,   277,   855,    10,    11,
      22,    23,   320,   900,   902,   903,   905,   907,   970,   933,
     283,   931,   937,   931,   940,   855,   943,   931,   946,   319,
     949,   955,   956,   953,   955,    10,    11,   959,   931,   962,
     931,   965,   931,   968,   855,   974,   931,   977,   931,   980,
     285,   287,     3,    21,   497,   127,     3,     3,     3,    10,
      11,   480,   481,   482,     7,   466,     3,    74,    76,   443,
     445,   446,   433,   434,     3,     7,     7,   569,     7,     7,
       7,     7,     3,    48,   402,   152,   396,   543,    50,   417,
     411,   543,   170,   192,   218,   626,   627,   628,   802,   803,
     805,   806,    10,    11,   624,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,     3,     3,
     235,   237,   239,   241,   855,   263,   855,     3,     3,   279,
     281,     4,     3,     4,   971,    18,    91,   561,   289,   931,
     315,   317,     4,    11,    11,   297,   931,   931,   931,   931,
     855,   311,    11,     4,    10,    11,   498,   569,   569,     7,
     483,     3,    79,    81,   465,   467,   468,   447,   448,    10,
      11,   436,    92,    93,    94,    95,    96,   435,   553,   561,
     562,   564,   565,   566,   568,     3,     3,     3,     3,     3,
       3,     3,   570,   571,    10,    11,   397,   398,   399,    10,
      11,   412,   413,   414,    10,    11,   629,   630,   631,    11,
     177,   807,   836,   166,     3,     3,     3,     3,     3,     3,
       3,     3,     4,   255,   911,     7,   569,   904,   569,   906,
     305,   931,     3,     3,    10,    11,   934,   291,     3,   931,
     950,   931,   954,   299,   301,   303,   307,   855,     3,   110,
     499,   500,     3,     3,     3,    87,    89,   484,   469,   470,
      10,    11,   450,   451,   452,    83,    97,    98,    99,   449,
     551,   553,   554,   561,   563,   567,   568,    72,     3,     3,
       3,     3,     3,     7,     3,   157,   400,   573,   574,   581,
     415,   573,   194,   633,   634,   931,     3,    11,   808,     7,
       7,     7,     7,     7,     7,     7,   569,   570,   263,     3,
       3,     3,     3,     3,     7,     7,   313,   293,   295,   855,
     501,   106,   111,   512,    18,   485,    10,    11,   472,   473,
     474,   471,   551,   553,   554,   561,   562,   564,   565,   566,
     568,   453,   455,     3,     3,     3,     4,     7,     7,     7,
       7,     7,   570,   161,   842,    56,   401,   162,   575,   576,
      58,   416,   204,   657,   658,   635,   636,   219,   804,     7,
     220,   810,   811,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   855,    10,    11,   116,   119,   502,   503,
     504,   505,   506,   513,   112,   524,     3,    11,   455,   475,
      77,   454,    84,   456,   457,     7,     7,     7,     3,     3,
       3,     3,     3,     3,     3,    10,    11,   582,   583,   584,
     577,   578,   206,   681,   682,   659,   660,    11,   180,   224,
     225,   637,   840,   845,   846,   847,     3,   222,   817,   818,
     152,   812,   838,   309,   113,   507,   508,   509,     3,     3,
      10,    11,   117,   119,   514,   515,   516,   517,   518,   525,
       7,   855,    82,   476,    11,   931,     3,     3,     3,     7,
       5,   158,    11,   580,   159,   160,   579,   843,   844,   208,
     720,   721,   683,   684,    11,   661,   840,   845,   196,   638,
     639,   640,     3,     4,   824,   819,   838,     3,    10,    11,
     813,   814,   815,   113,   508,   120,     7,     7,   114,   519,
     520,   521,     3,     3,    10,    11,   118,   119,   526,   527,
     528,   529,   540,     3,    90,    85,   458,     3,   158,     7,
       3,     3,   210,   754,   755,   722,   723,    11,   685,   840,
     845,   196,   662,   663,   664,   200,   645,   646,    10,    11,
     641,   642,   643,     7,   570,   168,   171,   809,   825,   826,
      10,    11,   820,   821,   822,     7,   573,   816,    18,   510,
       3,     3,   114,   520,   122,     7,     7,   115,   530,   531,
     532,     3,     3,   163,     7,     7,   212,   778,   779,   756,
     757,    11,   725,   724,   840,   845,   196,   686,   687,   688,
     200,   669,   670,    10,    11,   665,   666,   667,   202,   651,
     652,    10,    11,   647,   648,   649,   573,   644,     3,   827,
     828,   573,   823,     3,   221,     3,    10,    11,   511,    18,
     522,     3,     3,   115,   531,   124,     7,     7,     3,     3,
     193,   632,   780,   781,    11,   758,   840,   845,   196,   726,
     727,   200,   693,   694,    10,    11,   689,   690,   691,   202,
     675,   676,    10,    11,   671,   672,   673,   573,   668,   195,
      10,    11,   653,   654,   655,   573,   650,   197,    10,    11,
     832,   833,   834,   226,   227,   600,   829,   830,   831,   223,
       7,   121,     3,    10,    11,   523,    18,   533,     3,     3,
      11,   782,   840,   845,   196,   759,   760,   761,   198,   732,
     733,    10,    11,   728,   729,   730,   202,   699,   700,    10,
      11,   695,   696,   697,   573,   692,   205,    10,    11,   677,
     678,   679,   573,   674,   197,   157,   585,   586,   591,   656,
     201,   607,   835,   570,   570,     3,     7,   123,     3,    10,
      11,   534,   196,   783,   784,   785,   200,   766,   767,    10,
      11,   762,   763,   764,   209,   734,   838,   573,   731,   207,
      10,    11,   701,   702,   703,   573,   698,   197,   573,   680,
     201,   842,   162,   587,   588,   203,   625,   169,     7,     7,
       3,     7,   125,   200,   790,   791,    10,    11,   786,   787,
     788,   202,   772,   773,    10,    11,   768,   769,   770,   573,
     765,    11,   735,   197,   704,   705,   201,   203,    10,    11,
     592,   593,   594,   589,   844,   570,   570,     3,   202,   796,
     797,    10,    11,   792,   793,   794,   573,   789,   211,    10,
      11,   774,   775,   776,   573,   771,   197,   200,   736,   737,
     738,   203,   162,   706,   707,     5,   158,    11,   590,   213,
      10,    11,   798,   799,   800,   573,   795,   197,   573,   777,
     201,   199,   202,   743,   744,    10,    11,   739,   740,   741,
     708,   709,   158,   569,   573,   801,   201,   203,    10,    11,
     745,   746,   747,   573,   742,    10,    11,   712,   713,   714,
     176,   181,   710,   711,   841,   163,   203,   748,   201,   715,
       3,     3,   162,   203,   749,   750,   163,   216,   716,   717,
     569,     7,    10,    11,   751,   752,   753,   321,   718,     3,
       3,   855,     3,    11,   719,   163,   569,     7,     3,   217
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

  case 28:

    {
    if (osglData->matrixCounter < osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
}
    break;

  case 29:

    {
    osinstance->instanceData->matrices = new Matrices();
}
    break;

  case 30:

    {
    osinstance->instanceData->matrices->numberOfMatrices = osglData->numberOfMatrices;
    if (osglData->numberOfMatrices < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
    {
        osinstance->instanceData->matrices->matrix = new OSMatrix*[osglData->numberOfMatrices];
        for (int i=0; i < osglData->numberOfMatrices; i++)
            osinstance->instanceData->matrices->matrix[i] = new OSMatrix();
    }
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
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    parserData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = (yyvsp[(3) - (4)].ival); 
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
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
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

  case 400:

    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 405:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 408:

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

  case 414:

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

  case 415:

    {
//	IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osinstance->instanceData->matrices->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osinstance->instanceData->matrices->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 416:

    {
std::cout << "starting work on matrix " << osglData->matrixCounter << std::endl;
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryAttributePresent = false;
    osglData->matrixTypeAttributePresent = false;
    osglData->numberOfRowsAttributePresent = false;
    osglData->numberOfColumnsAttributePresent = false;
    osglData->matrixNameAttributePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlkVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);
}
    break;

  case 417:

    {
    if (osglData->numberOfRowsAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryAttributePresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetryAttribute);
    if (osglData->matrixNameAttributePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->matrixNameAttribute;
    if (osglData->matrixTypeAttributePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->matrixTypeAttribute);
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

  case 431:

    {
//    ((MatrixConstructor*)osglData->mtxBlkVec.back())->m_mChildren = 
//        new MatrixConstructor*[((MatrixConstructor*)osglData->mtxBlkVec.back())->inumberOfChildren];
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 434:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 435:

    {
    osglData->tempC = new BaseMatrix();
    osglData->mtxConstructorVec.push_back(osglData->tempC);

    osglData->baseMatrixIdxAttributePresent = false;
    osglData->targetMatrixFirstRowAttributePresent = false;
    osglData->targetMatrixFirstColAttributePresent = false;
    osglData->baseMatrixStartRowAttributePresent = false;
    osglData->baseMatrixStartColAttributePresent = false;
    osglData->baseMatrixEndRowAttributePresent = false;
    osglData->baseMatrixEndColAttributePresent = false;
    osglData->baseTransposeAttributePresent = false;
    osglData->scalarMultiplierAttributePresent = false;
    osglData->baseMatrixEndRowAttribute = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows;
    osglData->baseMatrixEndColAttribute = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns;
}
    break;

  case 436:

    {
    if (osglData->baseMatrixIdxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
        ((BaseMatrix*)osglData->tempC)->baseMatrixIdx = osglData->baseMatrixIdxAttribute;
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstRow = osglData->targetMatrixFirstRowAttribute;
    if (osglData->targetMatrixFirstColAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstCol = osglData->targetMatrixFirstColAttribute;
    if (osglData->baseMatrixStartRowAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartRow = osglData->baseMatrixStartRowAttribute;
    if (osglData->baseMatrixStartColAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartCol = osglData->baseMatrixStartColAttribute;
    if (osglData->baseMatrixEndRowAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndRow = osglData->baseMatrixEndRowAttribute;
    if (osglData->baseMatrixEndColAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndCol = osglData->baseMatrixEndColAttribute;
    if (osglData->baseTransposeAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseTranspose = osglData->baseTransposeAttribute;
    if (osglData->scalarMultiplierAttributePresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarMultiplier = osglData->scalarMultiplierAttribute;
}
    break;

  case 448:

    { 
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    ((MatrixType*)osglData->mtxBlkVec.back())->matrixType  = 
        mergeMatrixType(((MatrixType*)osglData->mtxBlkVec.back())->matrixType,
                   osinstance->instanceData->matrices->matrix[(yyvsp[(3) - (4)].ival)]->matrixType);
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
    if ((yyvsp[(3) - (4)].ival) > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row exceeds matrix dimensions");
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
    if ((yyvsp[(3) - (4)].ival) > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col exceeds matrix dimensions");
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

  case 464:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 468:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 469:

    {
    osglData->tempC = new MatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
//    osglData->rowMajorAttribute = false;
}
    break;

  case 477:

    {
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 478:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 481:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 482:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 484:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 485:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 491:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 492:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 498:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->values = new DoubleVector();
    ((MatrixElements*)osglData->tempC)->constantElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->values->el = osglData->osglDblArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 499:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 507:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements = new VarReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 508:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 511:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 512:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 514:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 515:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 521:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 522:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 528:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 529:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 537:

    {
    ((MatrixElements*)osglData->tempC)->linearElements = new LinearMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 538:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 541:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 542:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 544:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 545:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 551:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 552:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 558:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <values> element");
    }
    break;

  case 559:

    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many <el> elements");        
        ((MatrixElements*)osglData->tempC)->linearElements->values->numberOfEl = osglData->osglNumberOfEl;
//        ((MatrixElements*)osglData->tempC)->linearElements->values->el = osglData->osglDblArray;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 560:

    {
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglNonzeroCounter = 0;
    ((MatrixElements*)osglData->tempC)->linearElements->values = 
                new LinearMatrixValues();
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 568:

    {
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
        
}
    break;

  case 569:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
    ((MatrixElements*)osglData->tempC)->linearElements->values->numberOfEl
        = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;    
    ((MatrixElements*)osglData->tempC)->linearElements->values->el
        = new LinearMatrixElement*[((MatrixElements*)osglData->tempC)->linearElements->numberOfValues];    
}
    break;

  case 570:

    {
    if (!osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
}
    break;

  case 575:

    {
    if (osglData->osglConstantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->constant
             = parserData->tempVal;
        osglData->osglConstantPresent = true;
    }
}
    break;

  case 583:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 585:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 586:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = parserData->tempVal;
}
    break;

  case 589:

    {
    ((MatrixElements*)osglData->tempC)->generalElements = new GeneralMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 590:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 593:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 594:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 596:

    {
//    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
//    delete[] osglData->osglIntArray;
//    osglData->osglIntArray = NULL;
    ((MatrixElements*)osglData->tempC)->generalElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 597:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 603:

    {
//    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 604:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 605:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 609:

    {
//    if (!parserData->ignoreDataAfterErrors)
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
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 618:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 626:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 633:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements = new ConReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 634:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 637:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 638:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 640:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 641:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 652:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 653:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 659:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 660:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 668:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements = new ObjReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 669:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 672:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 673:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 675:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 676:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 682:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 683:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 689:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 690:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 696:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 697:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 700:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 701:

    {
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks = osglData->numberOfBlocks;
}
    break;

  case 702:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 704:

    {
//    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set <blocks> colOffsets failed");    
//    delete[] osglData->osglIntArray;
//    osglData->osglIntArray = NULL;
    ((MatrixBlocks*)osglData->tempC)->colOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffsets->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 705:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 706:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 712:

    {
//    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set <blocks> rowOffsets failed");    
//    delete[] osglData->osglIntArray;
//    osglData->osglIntArray = NULL;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 713:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 714:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 729:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 730:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
    osglData->blockRowIdxAttributePresent = true;        
    osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 731:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
    osglData->blockColIdxAttributePresent = true;        
    osglData->blockColIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 737:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 738:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 739:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 740:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 741:

    {
    if (osglData->numberOfValuesAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesAttributePresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 742:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 743:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 744:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 745:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 748:

    {
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajorAttribute = true;
    osglData->rowMajorAttributePresent = true;
}
    break;

  case 749:

    { 
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;
        else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->rowMajorAttribute = true;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorAttributePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 751:

    {  
        if (osnlData->nlnodecount < osnlData->tmpnlcount)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 752:

    {               
    osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
}
    break;

  case 753:

    { 
        if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        osnlData->tmpnlcount = (yyvsp[(3) - (5)].ival);
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
        for (int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[ i] = new Nl();
        }
    }
    break;

  case 756:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->nlnodecount++;
    }
    break;

  case 757:

    {
        if (osnlData->nlnodecount >= osnlData->tmpnlcount) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        //osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
    }
    break;

  case 758:

    { 
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        //osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
    }
    break;

  case 786:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 790:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 794:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 796:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 798:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 800:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 802:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 804:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 806:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 808:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 810:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 812:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 814:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 816:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 818:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 819:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 820:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 821:

    {
}
    break;

  case 822:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 823:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 824:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 826:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 828:

    {
//    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 830:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 831:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 839:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 841:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 843:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 844:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 845:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 848:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 852:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 853:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 854:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 855:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 856:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 857:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 859:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 860:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 861:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 863:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 864:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 865:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 867:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 868:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 869:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 871:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 872:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 873:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 875:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 891:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 892:

    {osnlData->matrixidxattON = false;}
    break;

  case 895:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 897:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 900:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 903:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 906:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 909:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 914:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 919:

    {
    if ((yyvsp[(2) - (3)].sval) != "false" && (yyvsp[(2) - (3)].sval) != "true")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "includeDiagonal attribute must be \"true\" or \"false\"");
    else 
        osnlData->includeDiagonalAttribute = (yyvsp[(2) - (3)].sval);
//    free($2);
}
    break;

  case 921:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 925:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 928:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 931:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 933:

    {
//    osnlData->nlNodePoint = new OSnLNodeProduct();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
//    osnlData->mtxProdVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 934:

    {
//    osnlData->mtxProdVec.back()->m_mChildren = new OSnLNode*[ osnlData->mtxProdVec.back()->inumberOfMatrixChildren];
//    osnlData->mtxProdVec.pop_back();
}
    break;

  case 936:

    { /*osnlData->mtxProdVec.back()->inumberOfMatrixChildren++; */}
    break;

  case 938:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 941:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 944:

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
    //if(pinstanceHeadStart == NULL) {  osilerror_wrapper( pchar,osillineno,"<instanceHeader> element missing"); return false;}
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
                {osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
        }
    }

#if 0
    // process the <name> element which is optional
    //
    // first burn any whitespace
    for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
    // if present, we should be pointing to <name element if there -- it is not required
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
    // if present, we should be pointing to <source element if there -- it is not required
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
    // if present, we should be pointing to <description element if there -- it is not required
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
    // if present, we should be pointing to <fileCreator element if there -- it is not required
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
    // if present, we should be pointing to <licence element if there -- it is not required
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
#endif
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
            if(i == exptest) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");     }
            val = val*pow(10.0, expsign*exppower);
            //printf("number = %f\n", val);
        }
    }
    // if we are here we should having nothing but white space until the end of the number
    for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
    if(number[i] == *numberend){
        return sign*val;
    }
    else {  osilerror_wrapper( number,osillineno,"error in parsing an XSD:double");     return OSNaN();}
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


