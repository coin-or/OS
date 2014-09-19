
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
     MATRIXLOWERTRIANGLESTART = 546,
     MATRIXLOWERTRIANGLEEND = 547,
     MATRIXUPPERTRIANGLESTART = 548,
     MATRIXUPPERTRIANGLEEND = 549,
     MATRIXMERGESTART = 550,
     MATRIXMERGEEND = 551,
     MATRIXMINUSSTART = 552,
     MATRIXMINUSEND = 553,
     MATRIXPLUSSTART = 554,
     MATRIXPLUSEND = 555,
     MATRIXTIMESSTART = 556,
     MATRIXTIMESEND = 557,
     MATRIXPRODUCTSTART = 558,
     MATRIXPRODUCTEND = 559,
     MATRIXSCALARTIMESSTART = 560,
     MATRIXSCALARTIMESEND = 561,
     MATRIXSUBMATRIXATSTART = 562,
     MATRIXSUBMATRIXATEND = 563,
     MATRIXTRANSPOSESTART = 564,
     MATRIXTRANSPOSEEND = 565,
     MATRIXREFERENCESTART = 566,
     MATRIXREFERENCEEND = 567,
     IDENTITYMATRIXSTART = 568,
     IDENTITYMATRIXEND = 569,
     MATRIXINVERSESTART = 570,
     MATRIXINVERSEEND = 571,
     EMPTYINCLUDEDIAGONALATT = 572,
     INCLUDEDIAGONALATT = 573,
     IDATT = 574,
     COEFATT = 575
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
#define MATRIXLOWERTRIANGLESTART 546
#define MATRIXLOWERTRIANGLEEND 547
#define MATRIXUPPERTRIANGLESTART 548
#define MATRIXUPPERTRIANGLEEND 549
#define MATRIXMERGESTART 550
#define MATRIXMERGEEND 551
#define MATRIXMINUSSTART 552
#define MATRIXMINUSEND 553
#define MATRIXPLUSSTART 554
#define MATRIXPLUSEND 555
#define MATRIXTIMESSTART 556
#define MATRIXTIMESEND 557
#define MATRIXPRODUCTSTART 558
#define MATRIXPRODUCTEND 559
#define MATRIXSCALARTIMESSTART 560
#define MATRIXSCALARTIMESEND 561
#define MATRIXSUBMATRIXATSTART 562
#define MATRIXSUBMATRIXATEND 563
#define MATRIXTRANSPOSESTART 564
#define MATRIXTRANSPOSEEND 565
#define MATRIXREFERENCESTART 566
#define MATRIXREFERENCEEND 567
#define IDENTITYMATRIXSTART 568
#define IDENTITYMATRIXEND 569
#define MATRIXINVERSESTART 570
#define MATRIXINVERSEEND 571
#define EMPTYINCLUDEDIAGONALATT 572
#define INCLUDEDIAGONALATT 573
#define IDATT 574
#define COEFATT 575




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
#define YYLAST   1147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  325
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  618
/* YYNRULES -- Number of rules.  */
#define YYNRULES  887
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1452

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   575

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   322,
     324,     2,     2,   323,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   321,     2,     2,     2,     2,     2,     2,     2,
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
     315,   316,   317,   318,   319,   320
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
    1855,  1860,  1865,  1870,  1871,  1876,  1878,  1884,  1885,  1888,
    1894,  1896,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1915,
    1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,
    1956,  1960,  1962,  1965,  1966,  1970,  1972,  1975,  1976,  1982,
    1983,  1989,  1990,  1996,  1997,  2002,  2003,  2009,  2010,  2016,
    2017,  2022,  2023,  2028,  2029,  2034,  2035,  2040,  2041,  2046,
    2047,  2052,  2053,  2058,  2059,  2064,  2065,  2072,  2073,  2078,
    2079,  2084,  2085,  2090,  2091,  2096,  2098,  2101,  2102,  2105,
    2107,  2109,  2111,  2112,  2117,  2118,  2123,  2128,  2129,  2134,
    2136,  2139,  2140,  2145,  2146,  2149,  2151,  2153,  2158,  2163,
    2164,  2169,  2170,  2173,  2174,  2179,  2180,  2183,  2184,  2189,
    2190,  2193,  2194,  2199,  2200,  2203,  2204,  2209,  2210,  2213,
    2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,
    2235,  2237,  2239,  2241,  2243,  2244,  2249,  2251,  2254,  2259,
    2262,  2264,  2267,  2270,  2272,  2276,  2279,  2281,  2284,  2287,
    2289,  2292,  2296,  2298,  2299,  2301,  2304,  2308,  2310,  2311,
    2313,  2316,  2320,  2323,  2325,  2327,  2330,  2333,  2335,  2339,
    2342,  2344,  2348,  2351,  2353,  2357,  2358,  2363,  2364,  2367,
    2370,  2372,  2376,  2379,  2381,  2388,  2391,  2393
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     326,     0,    -1,   330,   811,   342,   349,   417,   485,   327,
     328,    -1,    14,    -1,    13,    -1,   329,    -1,    12,    -1,
      -1,    -1,    24,   331,   332,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   332,   333,    -1,   334,   336,   335,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   336,
     337,    -1,   338,    -1,   339,    -1,   340,    -1,   341,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     320,     3,   568,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   343,   344,   345,    -1,    29,    -1,   543,    -1,   346,
      -1,   347,    -1,    10,    -1,    11,   348,    30,    -1,    -1,
     348,   597,    -1,    -1,   350,   351,   352,    -1,    32,    -1,
     544,    -1,   353,    -1,   354,    -1,    10,    -1,    11,   355,
      33,    -1,    -1,   355,   356,    -1,   357,    -1,   363,    -1,
     369,    -1,   375,    -1,   381,    -1,   387,    -1,   402,    -1,
     358,   359,   362,    -1,    35,    -1,   360,    -1,    -1,   360,
     361,    -1,   545,    -1,   546,    -1,   552,    -1,    10,    -1,
      11,    36,    -1,   364,   365,   368,    -1,    37,    -1,   366,
      -1,    -1,   366,   367,    -1,   545,    -1,   546,    -1,   552,
      -1,    10,    -1,    11,    38,    -1,   370,   371,   374,    -1,
      41,    -1,   372,    -1,    -1,   372,   373,    -1,   545,    -1,
     546,    -1,   552,    -1,   555,    -1,   554,    -1,   556,    -1,
      10,    -1,    11,    42,    -1,   376,   377,   380,    -1,    43,
      -1,   378,    -1,    -1,   378,   379,    -1,   545,    -1,   546,
      -1,   552,    -1,   555,    -1,   554,    -1,   557,    -1,   558,
      -1,    10,    -1,    11,    44,    -1,   382,   383,   386,    -1,
      45,    -1,   384,    -1,    -1,   384,   385,    -1,   545,    -1,
     546,    -1,   552,    -1,   559,    -1,    10,    -1,    11,    46,
      -1,   388,   389,   392,    -1,    47,    -1,   390,    -1,    -1,
     390,   391,    -1,   545,    -1,   546,    -1,   552,    -1,    11,
     393,   401,    -1,   394,   395,   396,    -1,    55,    -1,   542,
      -1,   397,    -1,   398,    -1,    10,    -1,    11,   399,   400,
      -1,   572,    -1,    56,    -1,    48,    -1,   403,   404,   407,
      -1,    49,    -1,   405,    -1,    -1,   405,   406,    -1,   545,
      -1,   546,    -1,   552,    -1,    11,   408,   416,    -1,   409,
     410,   411,    -1,    57,    -1,   542,    -1,   412,    -1,   413,
      -1,    10,    -1,    11,   414,   415,    -1,   572,    -1,    58,
      -1,    50,    -1,    -1,   418,   419,    -1,    66,    -1,   420,
      -1,   421,    -1,    10,    -1,    11,   422,   436,   458,   476,
      67,    -1,    -1,   423,   424,   425,    -1,    68,    -1,   547,
      -1,   426,    -1,   427,    -1,    10,    -1,    11,   429,   428,
      -1,    69,    -1,    -1,   429,   430,    -1,   431,   432,   435,
      -1,    71,    -1,   433,    -1,    -1,   433,   434,    -1,   560,
      -1,   561,    -1,   563,    -1,   564,    -1,   565,    -1,   567,
      -1,   552,    -1,    10,    -1,    11,    72,    -1,    -1,   437,
     438,   439,    -1,    73,    -1,   548,    -1,   440,    -1,   441,
      -1,    10,    -1,    11,   443,   442,    -1,    74,    -1,    -1,
     443,   444,    -1,   445,   446,   449,    -1,    76,    -1,   447,
      -1,    -1,   447,   448,    -1,   560,    -1,   566,    -1,   562,
      -1,   567,    -1,   552,    -1,   553,    -1,   550,    -1,   450,
      -1,   451,    -1,    10,    -1,    11,   452,   453,    -1,   454,
      -1,    77,    -1,    -1,   454,   455,    -1,   456,   894,   457,
      -1,    84,    11,    -1,    85,    -1,    -1,   459,   460,   461,
      -1,    78,    -1,   549,    -1,   462,    -1,   463,    -1,    10,
      -1,    11,   465,   464,    -1,    79,    -1,    -1,   465,   466,
      -1,   467,   468,   471,    -1,    81,    -1,   469,    -1,    -1,
     469,   470,    -1,   560,    -1,   561,    -1,   563,    -1,   564,
      -1,   565,    -1,   567,    -1,   552,    -1,   553,    -1,   550,
      -1,   472,    -1,   473,    -1,    10,    -1,    11,   474,   475,
      -1,   454,    -1,    82,    -1,    -1,   477,   478,   479,    -1,
      86,    -1,   551,    -1,   480,    -1,   481,    -1,    10,    -1,
      11,   482,    87,    -1,    -1,   482,   483,    -1,    89,   484,
      11,   818,    90,    -1,    18,     3,     7,     3,    -1,    -1,
     486,   487,    -1,   101,    -1,   488,    -1,   489,    -1,    10,
      -1,    11,   102,    -1,    11,   490,   102,    -1,    11,   534,
     102,    -1,   491,   492,   493,   104,    -1,   103,    -1,   107,
       3,     7,     3,    11,    -1,   494,    -1,   493,   494,    -1,
      -1,   495,   105,   496,   497,    -1,    -1,    21,     4,     3,
      -1,    10,    -1,    11,   498,   106,    -1,   499,   511,   523,
      -1,    -1,   110,   500,   504,    -1,    -1,   500,   501,    -1,
     502,    -1,   503,    -1,   116,     3,     7,     3,    -1,   119,
       3,     7,     3,    -1,   505,    -1,    11,   506,   113,    -1,
      10,    -1,    11,   113,    -1,   507,    -1,   506,   507,    -1,
      -1,   508,   120,   509,   510,    -1,    18,     3,     7,     3,
      -1,    10,    -1,    11,   121,    -1,    -1,   111,   512,   516,
      -1,    -1,   512,   513,    -1,   514,    -1,   515,    -1,   117,
       3,     7,     3,    -1,   119,     3,     7,     3,    -1,   517,
      -1,    11,   518,   114,    -1,    10,    -1,    11,   114,    -1,
     519,    -1,   518,   519,    -1,    -1,   520,   122,   521,   522,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   123,
      -1,    -1,   112,   524,   527,    -1,    -1,   524,   525,    -1,
     526,    -1,   539,    -1,   118,     3,     7,     3,    -1,   528,
      -1,    11,   529,   115,    -1,    10,    -1,    11,   115,    -1,
     530,    -1,   529,   530,    -1,    -1,   531,   124,   532,   533,
      -1,    18,     3,     7,     3,    -1,    10,    -1,    11,   125,
      -1,    -1,   535,   126,   537,   536,    -1,    10,    -1,    11,
     127,    -1,    -1,   537,   538,    -1,   540,    -1,   541,    -1,
     119,     3,     7,     3,    -1,   108,     3,   568,     3,    -1,
     109,     3,   568,     3,    -1,   152,   569,     7,   569,    -1,
      31,     3,     7,     3,    -1,    34,     3,     7,     3,    -1,
     179,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
      70,     3,     7,     3,    -1,    75,     3,     7,     3,    -1,
      80,     3,     7,     3,    -1,    83,     3,     7,     3,    -1,
      88,     3,     7,     3,    -1,    21,     4,     3,    -1,    99,
       4,     3,    -1,    59,     3,   568,     3,    -1,    60,     3,
       7,     3,    -1,    61,     3,     7,     3,    -1,    62,     3,
       7,     3,    -1,    63,     3,     7,     3,    -1,    65,     4,
       3,    -1,    91,     3,     7,     3,    -1,    92,     3,     7,
       3,    -1,    98,     3,     7,     3,    -1,    93,     3,     7,
       3,    -1,    94,     3,     7,     3,    -1,    95,     3,     7,
       3,    -1,    97,     3,     7,     3,    -1,    96,     3,     7,
       3,    -1,   570,     7,   570,    -1,   570,     8,   570,    -1,
     570,     3,    -1,    -1,   570,   571,    -1,   321,    -1,   322,
      -1,   323,    -1,   324,    -1,   573,    -1,   580,    -1,    -1,
     573,   574,    -1,   575,   576,   579,    -1,   162,    -1,   577,
      -1,    -1,   577,   578,    -1,   810,    -1,   809,    -1,    11,
       7,   163,    -1,   157,   808,   581,    -1,   582,    -1,   583,
      -1,    11,   158,    -1,    10,    -1,    11,     5,   158,    -1,
      -1,   584,   585,    -1,   586,   587,   588,    -1,   162,    -1,
      -1,   810,    -1,    11,   568,   163,    -1,   590,    11,   591,
     592,    -1,   805,    -1,   199,    11,   573,   200,    -1,   201,
      11,   584,   202,    -1,   594,    11,   595,   596,    -1,   805,
      -1,   199,    11,   573,   200,    -1,   201,    11,   573,   202,
      -1,   598,   599,   605,    -1,   164,    -1,   600,    -1,    -1,
     600,   601,    -1,   602,    -1,   806,    -1,   804,    -1,   603,
      -1,   604,    -1,   173,     4,     3,    -1,    21,     4,     3,
      -1,    22,     4,     3,    -1,   606,    -1,   607,    -1,    10,
      -1,    11,   608,   165,    -1,   609,   627,    -1,    -1,   610,
     611,   626,    -1,   167,    -1,   612,    -1,    -1,   612,   613,
      -1,   614,    -1,   615,    -1,   616,    -1,   617,    -1,   618,
      -1,   619,    -1,   620,    -1,   621,    -1,   625,    -1,   181,
       3,     7,     3,    -1,   182,     3,     7,     3,    -1,   183,
       3,     7,     3,    -1,   184,     3,     7,     3,    -1,   185,
       3,     7,     3,    -1,   186,     3,     7,     3,    -1,   187,
       3,     7,     3,    -1,   622,    -1,   623,    -1,   624,    -1,
     189,    -1,   190,     4,   569,    -1,   188,     3,   568,     3,
      -1,    11,   166,    -1,    10,    -1,    -1,   627,   628,    -1,
     629,    -1,   769,    -1,   772,    -1,   630,   631,   635,    -1,
     191,    -1,    -1,   632,    -1,   633,    -1,   634,    -1,   223,
      -1,   224,     4,   569,    -1,   636,    -1,   637,    -1,    10,
      -1,    11,   639,   650,   661,   701,   732,   743,   754,   638,
      -1,   192,    -1,    -1,   640,    11,   641,    -1,   193,    -1,
     642,   648,   194,    -1,   643,   644,    -1,   195,    -1,   645,
      -1,   646,    -1,    10,    -1,    11,   647,   196,    -1,   572,
      -1,   649,   589,   198,    -1,   197,    -1,    -1,   651,    11,
     652,    -1,   203,    -1,   653,   659,   204,    -1,   654,   655,
      -1,   195,    -1,   656,    -1,   657,    -1,    10,    -1,    11,
     658,   196,    -1,   572,    -1,   660,   593,   198,    -1,   197,
      -1,    -1,   662,   663,    -1,   205,    -1,    11,   664,   670,
     206,    -1,   665,   666,    -1,   195,    -1,   667,    -1,   668,
      -1,    10,    -1,    11,   669,   196,    -1,   572,    -1,   671,
     672,   673,    -1,   197,    -1,   805,    -1,    11,   674,   198,
      -1,   675,   681,    -1,    -1,   676,   677,    -1,   199,    -1,
     678,    -1,   679,    -1,    10,    -1,    11,   680,   200,    -1,
     572,    -1,    -1,   682,   683,    -1,   201,    -1,   684,    -1,
     685,    -1,    10,    -1,    11,   686,   202,    -1,    -1,   686,
     687,    -1,   688,   689,   693,    -1,   162,    -1,   690,    -1,
      -1,   690,   691,    -1,   807,    -1,   692,    -1,   176,     3,
     568,     3,    -1,   694,    -1,   695,    -1,    10,    -1,    11,
     696,   163,    -1,    -1,   696,   697,    -1,   698,   699,   700,
      -1,   215,    -1,    -1,   320,     3,   568,     3,    -1,    11,
       7,   216,    -1,    -1,   702,   703,    -1,   207,    -1,    11,
     704,   710,   208,    -1,   705,   706,    -1,   195,    -1,   707,
      -1,   708,    -1,    10,    -1,    11,   709,   196,    -1,   572,
      -1,   711,   712,   713,    -1,   197,    -1,   805,    -1,    11,
     714,   198,    -1,   715,   721,    -1,    -1,   716,   717,    -1,
     199,    -1,   718,    -1,   719,    -1,    10,    -1,    11,   720,
     200,    -1,   572,    -1,    -1,   722,   723,    -1,   201,    -1,
     724,    -1,   725,    -1,    10,    -1,    11,   726,   202,    -1,
      -1,   726,   727,    -1,   728,   729,    -1,   162,    -1,   730,
      -1,   731,    -1,    10,    -1,    11,   818,   163,    -1,    -1,
     733,   734,   210,    -1,   209,    -1,    11,   735,   741,    -1,
     736,   737,    -1,   195,    -1,   738,    -1,   739,    -1,    10,
      -1,    11,   740,   196,    -1,   572,    -1,   742,   593,   198,
      -1,   197,    -1,    -1,   744,   745,   212,    -1,   211,    -1,
      11,   746,   752,    -1,   747,   748,    -1,   195,    -1,   749,
      -1,   750,    -1,    10,    -1,    11,   751,   196,    -1,   572,
      -1,   753,   593,   198,    -1,   197,    -1,    -1,   755,   756,
     760,   214,    -1,   213,    -1,    -1,   757,    -1,   758,    -1,
     759,    -1,   174,    -1,   175,     4,   569,    -1,    11,   761,
     767,    -1,   762,   763,    -1,   195,    -1,   764,    -1,   765,
      -1,    10,    -1,    11,   766,   196,    -1,   572,    -1,   768,
     805,    11,   572,   198,    -1,   197,    -1,   770,    11,   894,
     771,    -1,   217,    -1,   218,    -1,   773,   774,   775,    -1,
     170,    -1,   803,    -1,    11,   777,   784,   791,   776,    -1,
     171,    -1,   778,   779,   780,    -1,   219,    -1,   805,    -1,
     781,    -1,   782,    -1,    10,    -1,    11,   783,   220,    -1,
     572,    -1,   785,   786,   787,    -1,   221,    -1,   805,    -1,
     788,    -1,   789,    -1,    10,    -1,    11,   790,   222,    -1,
     572,    -1,    -1,   791,   792,    -1,   793,   794,   799,    -1,
     168,    -1,   795,    -1,    -1,   795,   796,    -1,   797,    -1,
     798,    -1,   602,    -1,   225,   569,     7,   569,    -1,   226,
     569,     7,   569,    -1,   800,    -1,   801,    -1,    11,   169,
      -1,    10,    -1,    11,   802,   169,    -1,   609,   627,    -1,
     177,     3,     7,     3,    -1,   178,     3,     7,     3,    -1,
     152,     3,     7,     3,    -1,   179,     3,     7,     3,    -1,
     180,     3,     7,     3,    -1,   161,     3,     7,     3,    -1,
     159,     3,     7,     3,    -1,   160,     3,     7,     3,    -1,
      -1,   812,   813,   814,   229,    -1,   228,    -1,   230,     3,
       7,     3,    11,    -1,    -1,   814,   815,    -1,   816,   817,
      11,   818,   232,    -1,   231,    -1,    18,     3,     7,     3,
      -1,   861,    -1,   871,    -1,   825,    -1,   827,    -1,   879,
      -1,   829,    -1,   831,    -1,   833,    -1,   835,    -1,   891,
      -1,   837,    -1,   839,    -1,   841,    -1,   845,    -1,   843,
      -1,   847,    -1,   853,    -1,   849,    -1,   851,    -1,   885,
      -1,   888,    -1,   819,    -1,   822,    -1,   882,    -1,   855,
      -1,   857,    -1,   859,    -1,    -1,   273,   820,   821,    -1,
      10,    -1,    11,   274,    -1,    -1,   275,   823,   824,    -1,
      10,    -1,    11,   276,    -1,    -1,   277,   826,   818,   818,
     278,    -1,    -1,   235,   828,   818,   818,   236,    -1,    -1,
     237,   830,   818,   818,   238,    -1,    -1,   251,   832,   818,
     252,    -1,    -1,   239,   834,   818,   818,   240,    -1,    -1,
     233,   836,   818,   818,   234,    -1,    -1,   241,   838,   818,
     242,    -1,    -1,   243,   840,   818,   244,    -1,    -1,   255,
     842,   818,   256,    -1,    -1,   257,   844,   818,   258,    -1,
      -1,   259,   846,   818,   260,    -1,    -1,   249,   848,   818,
     250,    -1,    -1,   263,   850,   818,   264,    -1,    -1,   265,
     852,   818,   266,    -1,    -1,   253,   854,   818,   818,   818,
     254,    -1,    -1,   281,   856,   894,   282,    -1,    -1,   283,
     858,   894,   284,    -1,    -1,   285,   860,   894,   286,    -1,
      -1,   279,   862,   864,   863,    -1,    10,    -1,    11,   280,
      -1,    -1,   864,   865,    -1,   866,    -1,   870,    -1,   868,
      -1,    -1,    22,     4,   867,     3,    -1,    -1,   319,     4,
     869,     3,    -1,    23,     3,   568,     3,    -1,    -1,   261,
     872,   875,   873,    -1,    10,    -1,    11,   262,    -1,    -1,
      11,   818,   874,   262,    -1,    -1,   875,   876,    -1,   877,
      -1,   878,    -1,   320,     3,   568,     3,    -1,    18,     3,
       7,     3,    -1,    -1,   245,   880,   881,   246,    -1,    -1,
     881,   818,    -1,    -1,   269,   883,   884,   270,    -1,    -1,
     884,   818,    -1,    -1,   267,   886,   887,   268,    -1,    -1,
     887,   818,    -1,    -1,   271,   889,   890,   272,    -1,    -1,
     890,   818,    -1,    -1,   247,   892,   893,   248,    -1,    -1,
     893,   818,    -1,   895,    -1,   898,    -1,   901,    -1,   907,
      -1,   910,    -1,   914,    -1,   919,    -1,   922,    -1,   925,
      -1,   928,    -1,   931,    -1,   934,    -1,   937,    -1,   940,
      -1,   904,    -1,    -1,   311,   896,   560,   897,    -1,    10,
      -1,    11,   312,    -1,    18,     3,     7,     3,    -1,   899,
     900,    -1,   287,    -1,   894,   288,    -1,   902,   903,    -1,
     289,    -1,   894,   894,   290,    -1,   905,   906,    -1,   313,
      -1,   818,   314,    -1,   908,   909,    -1,   315,    -1,   894,
     316,    -1,   911,   912,   913,    -1,   291,    -1,    -1,   918,
      -1,   894,   292,    -1,   915,   916,   917,    -1,   293,    -1,
      -1,   918,    -1,   894,   294,    -1,   318,     4,     3,    -1,
     920,   921,    -1,   295,    -1,    10,    -1,    11,   296,    -1,
     923,   924,    -1,   297,    -1,   894,   894,   298,    -1,   926,
     927,    -1,   299,    -1,   894,   894,   300,    -1,   929,   930,
      -1,   301,    -1,   894,   894,   302,    -1,    -1,   303,   932,
     933,   304,    -1,    -1,   933,   894,    -1,   935,   936,    -1,
     305,    -1,   818,   894,   306,    -1,   938,   939,    -1,   307,
      -1,   894,   818,   818,   818,   818,   308,    -1,   941,   942,
      -1,   309,    -1,   894,   310,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   383,   383,   386,   387,   389,   398,   399,   402,   403,
     408,   415,   415,   417,   430,   436,   437,   440,   441,   444,
     447,   450,   453,   459,   466,   473,   481,   486,   486,   492,
     497,   510,   510,   512,   514,   521,   521,   524,   524,   526,
     528,   530,   530,   532,   534,   536,   536,   538,   539,   541,
     542,   544,   551,   552,   557,   559,   561,   563,   563,   566,
     567,   568,   570,   570,   572,   574,   576,   578,   578,   581,
     582,   583,   585,   585,   589,   591,   593,   595,   595,   598,
     599,   600,   601,   602,   603,   606,   606,   608,   610,   612,
     614,   614,   617,   618,   619,   620,   621,   622,   623,   626,
     626,   630,   632,   634,   636,   636,   639,   640,   641,   642,
     645,   645,   659,   661,   663,   665,   665,   668,   669,   670,
     673,   675,   677,   679,   681,   681,   683,   685,   687,   689,
     691,   693,   695,   697,   699,   699,   702,   703,   704,   707,
     709,   711,   713,   715,   715,   717,   719,   721,   723,   725,
     734,   734,   736,   738,   738,   740,   743,   745,   745,   747,
     749,   751,   751,   753,   755,   757,   759,   759,   761,   763,
     765,   767,   767,   770,   771,   772,   773,   774,   775,   776,
     779,   780,   782,   782,   784,   786,   788,   788,   790,   792,
     794,   796,   796,   798,   800,   802,   804,   804,   807,   808,
     809,   810,   811,   812,   813,   816,   816,   818,   820,   822,
     824,   828,   828,   830,   832,   834,   837,   837,   839,   841,
     843,   843,   845,   847,   849,   851,   851,   853,   855,   857,
     859,   859,   862,   863,   864,   865,   866,   867,   868,   869,
     870,   873,   873,   875,   877,   879,   881,   884,   884,   886,
     888,   890,   890,   892,   894,   896,   896,   898,   900,   902,
     902,   904,   906,   906,   908,   909,   912,   913,   916,   967,
     969,   983,   984,   986,   986,  1010,  1011,  1014,  1015,  1017,
    1019,  1020,  1024,  1025,  1027,  1028,  1030,  1046,  1054,  1061,
    1066,  1067,  1069,  1070,  1072,  1072,  1075,  1084,  1085,  1087,
    1088,  1092,  1093,  1095,  1096,  1098,  1114,  1122,  1129,  1134,
    1135,  1137,  1138,  1140,  1140,  1143,  1152,  1153,  1155,  1165,
    1169,  1170,  1172,  1173,  1175,  1191,  1198,  1203,  1204,  1206,
    1207,  1209,  1209,  1212,  1221,  1222,  1227,  1227,  1235,  1236,
    1238,  1239,  1241,  1245,  1251,  1259,  1263,  1268,  1277,  1288,
    1299,  1310,  1321,  1329,  1337,  1345,  1353,  1362,  1371,  1379,
    1390,  1401,  1413,  1424,  1435,  1446,  1457,  1468,  1479,  1490,
    1501,  1512,  1523,  1537,  1538,  1545,  1547,  1547,  1549,  1550,
    1551,  1552,  1717,  1725,  1727,  1727,  1729,  1731,  1740,  1742,
    1742,  1744,  1744,  1746,  1762,  1765,  1765,  1767,  1767,  1770,
    1811,  1811,  1813,  1815,  1823,  1823,  1825,  1878,  1882,  1893,
    1895,  1903,  1907,  1918,  1920,  1931,  1940,  1961,  1979,  1979,
    1982,  1983,  1984,  1985,  1986,  1989,  1998,  2007,  2016,  2016,
    2018,  2020,  2029,  2031,  2031,  2036,  2054,  2078,  2078,  2081,
    2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2091,  2105,
    2115,  2125,  2135,  2145,  2157,  2169,  2176,  2176,  2178,  2183,
    2192,  2200,  2200,  2202,  2202,  2207,  2207,  2207,  2209,  2215,
    2221,  2221,  2223,  2223,  2225,  2230,  2239,  2239,  2241,  2243,
    2246,  2248,  2248,  2250,  2255,  2257,  2268,  2276,  2276,  2278,
    2280,  2282,  2284,  2299,  2306,  2306,  2308,  2310,  2312,  2323,
    2329,  2329,  2331,  2333,  2335,  2337,  2350,  2356,  2356,  2358,
    2360,  2362,  2373,  2379,  2379,  2381,  2383,  2385,  2387,  2398,
    2404,  2411,  2413,  2415,  2416,  2429,  2436,  2436,  2438,  2440,
    2442,  2444,  2445,  2447,  2453,  2453,  2455,  2457,  2459,  2459,
    2461,  2464,  2470,  2472,  2472,  2475,  2476,  2478,  2482,  2482,
    2484,  2486,  2488,  2488,  2491,  2493,  2499,  2499,  2503,  2507,
    2507,  2509,  2511,  2513,  2524,  2530,  2530,  2532,  2534,  2536,
    2538,  2549,  2555,  2562,  2564,  2566,  2567,  2580,  2587,  2587,
    2589,  2591,  2593,  2595,  2596,  2598,  2604,  2604,  2606,  2608,
    2610,  2610,  2612,  2614,  2620,  2620,  2622,  2624,  2627,  2627,
    2629,  2631,  2633,  2644,  2650,  2650,  2652,  2654,  2656,  2658,
    2671,  2677,  2677,  2679,  2681,  2683,  2694,  2700,  2700,  2702,
    2704,  2706,  2708,  2721,  2727,  2727,  2729,  2731,  2731,  2733,
    2733,  2735,  2740,  2749,  2751,  2762,  2775,  2775,  2777,  2779,
    2781,  2783,  2796,  2802,  2807,  2813,  2815,  2817,  2824,  2826,
    2831,  2833,  2844,  2850,  2857,  2857,  2859,  2861,  2863,  2865,
    2876,  2882,  2889,  2889,  2891,  2893,  2895,  2897,  2897,  2899,
    2901,  2903,  2905,  2905,  2908,  2909,  2910,  2917,  2926,  2935,
    2935,  2937,  2937,  2939,  2941,  2943,  2952,  2961,  2970,  2979,
    2988,  2993,  3001,  3042,  3043,  3049,  3054,  3073,  3074,  3076,
    3084,  3098,  3108,  3109,  3110,  3111,  3112,  3113,  3114,  3115,
    3116,  3117,  3118,  3119,  3120,  3121,  3122,  3123,  3124,  3125,
    3126,  3127,  3128,  3129,  3130,  3131,  3133,  3134,  3135,  3139,
    3139,  3142,  3143,  3145,  3145,  3148,  3149,  3153,  3153,  3158,
    3158,  3163,  3163,  3168,  3168,  3173,  3173,  3178,  3178,  3183,
    3183,  3188,  3188,  3193,  3193,  3198,  3198,  3203,  3203,  3208,
    3208,  3213,  3213,  3220,  3220,  3226,  3226,  3235,  3235,  3240,
    3240,  3245,  3245,  3255,  3255,  3260,  3261,  3263,  3264,  3266,
    3267,  3268,  3272,  3271,  3280,  3279,  3287,  3297,  3296,  3303,
    3304,  3306,  3305,  3312,  3313,  3316,  3322,  3330,  3337,  3357,
    3357,  3368,  3368,  3371,  3371,  3383,  3384,  3387,  3387,  3398,
    3399,  3402,  3402,  3413,  3414,  3417,  3417,  3427,  3428,  3434,
    3435,  3436,  3437,  3438,  3439,  3440,  3441,  3442,  3443,  3444,
    3445,  3446,  3447,  3448,  3452,  3451,  3458,  3459,  3461,  3469,
    3471,  3477,  3479,  3481,  3487,  3489,  3491,  3497,  3499,  3501,
    3507,  3509,  3511,  3517,  3517,  3519,  3521,  3523,  3529,  3529,
    3531,  3533,  3540,  3542,  3547,  3547,  3549,  3551,  3557,  3559,
    3561,  3567,  3569,  3571,  3577,  3580,  3580,  3590,  3591,  3595,
    3597,  3603,  3605,  3607,  3613,  3615,  3617,  3623
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
  "osglIncrATT", "osglMultATT", "nonlinearExpressions",
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
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
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
     575,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   325,   326,   327,   327,   328,   329,   329,   330,   330,
     331,   332,   332,   333,   334,   335,   335,   336,   336,   337,
     337,   337,   337,   338,   339,   340,   341,   342,   342,   343,
     344,   345,   345,   346,   347,   348,   348,   349,   349,   350,
     351,   352,   352,   353,   354,   355,   355,   356,   356,   356,
     356,   356,   356,   356,   357,   358,   359,   360,   360,   361,
     361,   361,   362,   362,   363,   364,   365,   366,   366,   367,
     367,   367,   368,   368,   369,   370,   371,   372,   372,   373,
     373,   373,   373,   373,   373,   374,   374,   375,   376,   377,
     378,   378,   379,   379,   379,   379,   379,   379,   379,   380,
     380,   381,   382,   383,   384,   384,   385,   385,   385,   385,
     386,   386,   387,   388,   389,   390,   390,   391,   391,   391,
     392,   393,   394,   395,   396,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   405,   406,   406,   406,   407,
     408,   409,   410,   411,   411,   412,   413,   414,   415,   416,
     417,   417,   418,   419,   419,   420,   421,   422,   422,   423,
     424,   425,   425,   426,   427,   428,   429,   429,   430,   431,
     432,   433,   433,   434,   434,   434,   434,   434,   434,   434,
     435,   435,   436,   436,   437,   438,   439,   439,   440,   441,
     442,   443,   443,   444,   445,   446,   447,   447,   448,   448,
     448,   448,   448,   448,   448,   449,   449,   450,   451,   452,
     453,   454,   454,   455,   456,   457,   458,   458,   459,   460,
     461,   461,   462,   463,   464,   465,   465,   466,   467,   468,
     469,   469,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   471,   471,   472,   473,   474,   475,   476,   476,   477,
     478,   479,   479,   480,   481,   482,   482,   483,   484,   485,
     485,   486,   487,   487,   488,   488,   489,   489,   490,   491,
     492,   493,   493,   495,   494,   496,   496,   497,   497,   498,
     499,   499,   500,   500,   501,   501,   502,   503,   504,   504,
     505,   505,   506,   506,   508,   507,   509,   510,   510,   511,
     511,   512,   512,   513,   513,   514,   515,   516,   516,   517,
     517,   518,   518,   520,   519,   521,   522,   522,   523,   523,
     524,   524,   525,   525,   526,   527,   527,   528,   528,   529,
     529,   531,   530,   532,   533,   533,   535,   534,   536,   536,
     537,   537,   538,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   568,   569,   570,   570,   571,   571,
     571,   571,   572,   572,   573,   573,   574,   575,   576,   577,
     577,   578,   578,   579,   580,   581,   581,   582,   582,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   600,
     601,   601,   601,   601,   601,   602,   603,   604,   605,   605,
     606,   607,   608,   609,   609,   610,   611,   612,   612,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   622,   623,   624,
     625,   626,   626,   627,   627,   628,   628,   628,   629,   630,
     631,   631,   632,   632,   633,   634,   635,   635,   636,   637,
     638,   639,   639,   640,   641,   642,   643,   644,   644,   645,
     646,   647,   648,   649,   650,   650,   651,   652,   653,   654,
     655,   655,   656,   657,   658,   659,   660,   661,   661,   662,
     663,   664,   665,   666,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   675,   676,   677,   677,   678,   679,
     680,   681,   681,   682,   683,   683,   684,   685,   686,   686,
     687,   688,   689,   690,   690,   691,   691,   692,   693,   693,
     694,   695,   696,   696,   697,   698,   699,   699,   700,   701,
     701,   702,   703,   704,   705,   706,   706,   707,   708,   709,
     710,   711,   712,   713,   714,   715,   715,   716,   717,   717,
     718,   719,   720,   721,   721,   722,   723,   723,   724,   725,
     726,   726,   727,   728,   729,   729,   730,   731,   732,   732,
     733,   734,   735,   736,   737,   737,   738,   739,   740,   741,
     742,   743,   743,   744,   745,   746,   747,   748,   748,   749,
     750,   751,   752,   753,   754,   754,   755,   756,   756,   757,
     757,   758,   759,   760,   761,   762,   763,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   773,   774,   775,
     776,   777,   778,   779,   780,   780,   781,   782,   783,   784,
     785,   786,   787,   787,   788,   789,   790,   791,   791,   792,
     793,   794,   795,   795,   796,   796,   796,   797,   798,   799,
     799,   800,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   811,   812,   813,   814,   814,   815,
     816,   817,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   818,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   818,   818,   818,   818,   818,   818,   818,   818,   820,
     819,   821,   821,   823,   822,   824,   824,   826,   825,   828,
     827,   830,   829,   832,   831,   834,   833,   836,   835,   838,
     837,   840,   839,   842,   841,   844,   843,   846,   845,   848,
     847,   850,   849,   852,   851,   854,   853,   856,   855,   858,
     857,   860,   859,   862,   861,   863,   863,   864,   864,   865,
     865,   865,   867,   866,   869,   868,   870,   872,   871,   873,
     873,   874,   873,   875,   875,   876,   876,   877,   878,   880,
     879,   881,   881,   883,   882,   884,   884,   886,   885,   887,
     887,   889,   888,   890,   890,   892,   891,   893,   893,   894,
     894,   894,   894,   894,   894,   894,   894,   894,   894,   894,
     894,   894,   894,   894,   896,   895,   897,   897,   560,   898,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   912,   913,   914,   915,   916,   916,
     917,   918,   919,   920,   921,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   932,   931,   933,   933,   934,
     935,   936,   937,   938,   939,   940,   941,   942
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
       4,     4,     4,     0,     4,     1,     5,     0,     2,     5,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     0,     3,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     4,     0,     5,     0,     5,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     6,     0,     4,     0,
       4,     0,     4,     0,     4,     1,     2,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     4,     0,     4,     1,
       2,     0,     4,     0,     2,     1,     1,     4,     4,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     2,     4,     2,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       2,     3,     1,     0,     1,     2,     3,     1,     0,     1,
       2,     3,     2,     1,     1,     2,     2,     1,     3,     2,
       1,     3,     2,     1,     3,     0,     4,     0,     2,     2,
       1,     3,     2,     1,     6,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   693,     0,    11,     1,   695,    27,     0,
       0,     0,    29,    37,     0,     0,   697,     0,     9,    14,
      12,    17,    39,   150,     0,     0,     0,    30,     0,     0,
       0,     0,   152,   259,     0,     0,     0,    40,     0,    33,
      35,    28,    31,    32,     0,   694,   700,   698,     0,    10,
      15,     0,     0,     0,     0,     0,    13,    18,    19,    20,
      21,    22,   261,     0,     0,   155,   157,   151,   153,   154,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   376,     4,     3,     7,   264,
     336,   260,   262,   263,   159,   182,     0,     0,     0,   348,
      34,   416,    36,   418,   696,     0,     0,     0,     0,     0,
       0,     0,     6,     2,     5,   265,   269,     0,     0,     0,
       0,   184,   216,     0,     0,     0,   160,   349,    44,    55,
      65,    75,    88,   102,   113,   132,    46,    47,    57,    48,
      67,    49,    77,    50,    90,    51,   104,    52,   115,    53,
     134,     0,   417,     0,   747,   739,   741,   745,   749,   751,
     799,   815,   759,   743,   765,   753,   755,   757,   787,   761,
     763,   807,   803,   811,   729,   733,   737,   773,   767,   769,
     771,     0,   723,   724,   704,   705,   707,   708,   709,   710,
     712,   713,   714,   716,   715,   717,   719,   720,   718,   726,
     727,   728,   702,   703,   706,   725,   721,   722,   711,    26,
      23,    24,    25,   376,   376,   378,   379,   380,   381,   377,
     266,     0,   273,   267,   340,   218,   247,     0,     0,     0,
     185,     0,   163,   166,   158,   161,   162,     0,    56,     0,
      66,     0,    76,     0,    89,     0,   103,     0,   114,     0,
     133,   430,   433,   415,   428,   429,     0,     0,     0,     0,
       0,   419,   420,   423,   424,   422,   421,   701,     0,     0,
       0,     0,     0,     0,   801,   817,     0,     0,     0,     0,
       0,     0,   793,     0,     0,   809,   805,   813,     0,     0,
       0,   777,     0,     0,     0,   699,   373,   374,     0,   273,
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
     731,     0,   730,   735,     0,   734,     0,     0,   840,   843,
     852,   857,   863,   867,   870,   873,   875,   880,   883,   886,
     834,   846,   849,     0,   819,   820,     0,   821,     0,   833,
       0,   822,     0,   823,   853,   824,   858,   825,     0,   826,
       0,   827,     0,   828,     0,   829,   830,     0,   831,     0,
     832,     0,     0,     0,     0,   268,   272,   275,   338,     0,
       0,     0,   337,   341,   342,   343,   156,     0,     0,   250,
       0,   222,   225,   217,   220,   221,     0,     0,   352,   165,
     169,   164,   167,   171,    63,     0,     0,     0,    73,    86,
     376,     0,     0,   100,     0,     0,   111,     0,   122,     0,
       0,   141,     0,     0,   431,   432,     0,   436,   426,   427,
     425,     0,     0,     0,     0,     0,     0,   750,   752,   800,
     802,   816,   818,   760,   744,     0,   754,   756,   758,   789,
       0,     0,     0,   788,   794,   795,   796,   762,   764,   808,
     810,   804,   806,   812,   814,   732,   736,     0,   775,     0,
       0,     0,     0,   774,   778,   779,   781,   780,   877,     0,
     768,     0,   839,     0,   842,     0,   845,     0,   848,     0,
       0,   854,     0,   859,   864,     0,   862,     0,   866,     0,
     869,     0,   872,     0,   879,     0,   882,     0,   885,   770,
     772,     0,     0,     0,   339,   376,   376,     0,   253,   255,
     248,   251,   252,     0,     0,   353,   190,   194,   189,   192,
     196,     0,   170,   357,     0,     0,     0,     0,     0,     0,
       0,   364,   130,   120,   376,     0,   123,   149,   139,     0,
     142,   647,   469,   644,   464,   465,   470,   466,     0,   467,
       0,   462,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,   458,     0,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   455,   456,   457,   447,   686,   688,   748,
     740,   742,   746,     0,   790,   791,     0,   376,   738,   776,
     782,   376,   784,     0,     0,     0,     0,   841,     0,   847,
     850,     0,     0,   851,     0,   856,   865,     0,     0,     0,
       0,     0,   887,   270,     0,   277,   280,   274,     0,     0,
       0,     0,   354,   224,   228,   223,   226,   230,     0,   195,
     180,     0,   168,     0,     0,     0,     0,     0,   172,   179,
     173,   174,   175,   176,   177,   178,   351,   350,   359,   360,
     361,   362,   363,     0,     0,   126,   384,   121,   124,   125,
     145,   384,   140,   143,   144,   474,     0,     0,   471,   472,
     473,     0,     0,     0,   648,   461,     0,     0,     0,     0,
       0,     0,     0,   376,   376,   766,     0,     0,     0,     0,
       0,     0,   876,   878,     0,     0,   836,     0,   835,   844,
     861,   855,   860,   868,   871,   874,   881,     0,   276,   282,
       0,   299,   345,   346,   356,   254,     0,   256,     0,   229,
     207,   211,   193,   205,   206,     0,     0,     0,     0,   197,
     204,   202,   203,   198,   200,   199,   201,   181,     0,     0,
       0,     0,     0,   376,   375,     0,     0,   128,   382,   383,
       0,   147,   376,   478,   481,   468,   476,   477,     0,     0,
       0,   646,     0,     0,     0,     0,     0,     0,     0,     0,
     459,   792,   798,   797,   783,   786,   785,     0,     0,   837,
       0,     0,   278,   301,   318,     0,     0,   243,   211,   227,
     241,   242,   231,   240,   238,   239,   232,   233,   234,   235,
     236,   237,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,   129,   127,   387,   385,
     389,   148,   146,   475,   483,   494,     0,   645,   643,     0,
     652,     0,     0,   448,   449,   450,   451,   452,   453,   454,
     460,   838,   365,     0,   290,   294,     0,     0,   283,   284,
     285,   281,   288,     0,   320,   279,     0,     0,   245,     0,
     210,   208,     0,   212,     0,     0,     0,     0,   358,   366,
     368,   369,   370,   372,     0,   398,     0,   394,   395,   396,
       0,   388,   496,   507,     0,     0,   685,   660,   667,     0,
       0,     0,   653,   884,   291,   294,   292,     0,     0,     0,
     309,   313,     0,     0,   302,   303,   304,   300,   307,     0,
       0,     0,   246,   244,   214,     0,   355,   371,   367,     0,
       0,   397,     0,   386,     0,     0,   390,   392,   391,   509,
     559,     0,     0,   486,   482,     0,     0,     0,     0,   661,
       0,   656,   384,   651,   654,   655,   289,   293,     0,     0,
       0,   310,   313,   311,     0,     0,     0,   327,   331,     0,
       0,   321,   322,   319,   325,   323,   258,   257,   215,   213,
     690,   399,     0,     0,     0,   561,   598,     0,     0,   508,
     499,   495,     0,     0,   493,     0,     0,   489,   384,   485,
     487,   488,   670,   650,   649,   668,   672,   664,   384,   659,
     662,   663,     0,   658,     0,     0,     0,   286,   287,   308,
     312,     0,     0,     0,   328,   331,   329,     0,     0,     0,
     393,     0,     0,   600,   611,     0,     0,   560,   512,     0,
       0,   506,     0,     0,   502,   384,   498,   500,   501,   484,
       0,     0,   408,   491,     0,     0,   671,   666,     0,   687,
     657,     0,   297,     0,   295,     0,     0,   305,   306,   326,
     330,     0,     0,     0,   691,   692,   613,   624,     0,     0,
       0,   564,     0,     0,   519,     0,     0,   515,   384,   511,
     513,   514,   497,     0,     0,   412,   504,     0,   492,     0,
     490,   682,   433,   669,   679,   680,   376,   376,   676,   673,
     674,   675,   665,     0,   298,     0,   316,     0,   314,     0,
       0,   324,   344,   626,     0,   627,     0,     0,   603,     0,
       0,   599,   571,     0,     0,   567,   384,   563,   565,   566,
     510,     0,   520,   517,     0,   505,     0,   503,     0,     0,
     681,   463,     0,     0,     0,   296,     0,   317,     0,   334,
       0,   332,   480,   479,   631,     0,     0,   628,   629,   630,
     616,     0,     0,   612,   610,   601,     0,   606,   384,   602,
     604,   605,   562,     0,   572,   569,     0,   523,   518,   516,
       0,     0,   384,     0,   407,   684,   683,   376,   376,   315,
       0,   335,   376,     0,     0,   623,   614,     0,   619,   384,
     615,   617,   618,     0,   608,     0,   575,   570,   568,   525,
       0,   531,     0,   384,     0,   411,     0,   400,   677,   678,
     333,   632,   635,     0,     0,   625,     0,   621,     0,   609,
     607,   577,     0,   583,     0,   521,   533,   522,     0,   528,
     384,   524,   526,   527,     0,   384,   409,     0,   642,   633,
       0,   638,   384,   634,   636,   637,   622,   620,   573,   585,
     574,     0,   580,   384,   576,   578,   579,   536,   538,   532,
     534,   535,   530,     0,   413,     0,   403,   410,   401,   404,
       0,   640,     0,   588,   590,   584,   586,   587,   582,     0,
       0,   529,   414,     0,   405,   384,   639,     0,   581,   541,
     537,   539,   543,   376,   402,     0,   593,   589,   591,     0,
       0,   542,     0,   641,   596,     0,   592,   594,   595,   550,
     552,   540,   548,   549,     0,     0,   544,   546,   545,   406,
       0,     0,   376,     0,   597,   551,   555,   553,   556,     0,
       0,     0,     0,   547,   689,   376,     0,   554,     0,     0,
     557,   558
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
     635,   757,   758,   759,   846,   917,   633,   149,   150,   249,
     250,   377,   376,   512,   513,   639,   762,   763,   764,   850,
     922,   638,    33,    34,    67,    68,    69,    95,    96,   125,
     234,   235,   236,   491,   316,   492,   493,   621,   622,   738,
     732,   122,   123,   229,   312,   313,   314,   618,   487,   619,
     620,   728,   729,   829,   822,   823,   824,   902,   961,   903,
     963,   964,  1069,   226,   227,   307,   483,   484,   485,   725,
     614,   726,   727,   818,   819,   892,   889,   890,   891,   959,
    1013,   304,   305,   478,   610,   611,   612,   721,   817,   886,
      63,    64,    91,    92,    93,   117,   118,   222,   299,   300,
     301,   603,   717,   810,   811,   881,   948,   949,   950,   951,
     952,   995,   996,   997,  1106,  1154,   884,   953,  1004,  1005,
    1006,  1007,  1008,  1052,  1053,  1054,  1156,  1208,   955,  1009,
    1061,  1062,  1063,  1064,  1115,  1116,  1117,  1210,  1251,   119,
     120,   472,   302,   473,  1065,   474,   475,   636,    27,    37,
     324,   325,   126,   230,   308,   830,   479,   326,   832,   344,
     345,   346,   358,   359,   368,   696,   741,   834,   742,   743,
     744,   835,   745,   110,   753,   111,   219,   847,   848,   919,
     920,   980,   981,  1026,  1023,   849,   977,   978,   979,  1347,
    1378,  1379,  1393,  1404,  1140,  1141,  1239,  1284,  1183,  1184,
    1281,  1315,   102,   103,   151,   152,   261,   262,   263,   264,
     253,   254,   255,   382,   383,   384,   516,   517,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   653,   515,   644,   645,   646,   767,   768,   769,   770,
     855,   856,   857,  1253,   925,   926,  1034,  1035,  1036,  1089,
    1090,  1091,  1144,  1085,  1086,   983,   984,  1081,  1082,  1083,
    1136,  1137,  1138,  1187,  1132,  1133,  1030,  1031,  1079,  1129,
    1130,  1179,  1180,  1181,  1234,  1175,  1176,  1231,  1278,  1310,
    1311,  1312,  1341,  1342,  1343,  1373,  1337,  1338,  1369,  1370,
    1371,  1390,  1401,  1402,  1410,  1411,  1426,  1427,  1421,  1422,
    1423,  1431,  1437,  1438,  1442,  1447,  1076,  1077,  1127,  1172,
    1173,  1227,  1228,  1229,  1276,  1223,  1224,  1273,  1307,  1332,
    1333,  1334,  1364,  1365,  1366,  1389,  1360,  1361,  1385,  1386,
    1387,  1397,  1408,  1409,  1416,  1417,  1418,  1124,  1125,  1170,
    1219,  1220,  1269,  1270,  1271,  1305,  1265,  1266,  1167,  1168,
    1217,  1261,  1262,  1300,  1301,  1302,  1328,  1296,  1297,  1214,
    1215,  1256,  1257,  1258,  1259,  1294,  1323,  1324,  1353,  1354,
    1355,  1382,  1349,  1350,   647,   648,   928,   649,   650,   773,
     861,  1094,   931,   932,   991,  1043,  1044,  1045,  1104,   988,
     989,  1038,  1099,  1100,  1101,  1148,  1037,  1095,  1096,  1145,
    1146,  1199,  1200,  1201,  1193,  1194,  1195,  1242,   774,   265,
    1185,   266,  1428,   915,  1027,  1028,     8,     9,    16,    29,
      47,    48,    80,   181,   182,   288,   412,   183,   289,   415,
     184,   290,   185,   269,   186,   270,   187,   277,   188,   271,
     189,   268,   190,   272,   191,   273,   192,   279,   193,   280,
     194,   281,   195,   276,   196,   283,   197,   284,   198,   278,
     199,   292,   200,   293,   201,   294,   202,   291,   563,   417,
     564,   565,   789,   566,   791,   567,   203,   282,   543,   786,
     404,   544,   545,   546,   204,   274,   396,   205,   286,   408,
     206,   285,   407,   207,   287,   409,   208,   275,   397,   433,
     434,   569,   798,   435,   436,   572,   437,   438,   574,   439,
     440,   576,   441,   442,   578,   443,   444,   580,   703,   445,
     446,   582,   705,   581,   447,   448,   586,   449,   450,   588,
     451,   452,   590,   453,   454,   592,   455,   568,   693,   456,
     457,   594,   458,   459,   596,   460,   461,   598
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1231
static const yytype_int16 yypact[] =
{
      61,    62,   112,  -134,   113, -1231, -1231, -1231,    92,   -92,
     123,    70, -1231,   115,   119,   152, -1231,   167, -1231, -1231,
   -1231, -1231, -1231,   111,   148,   201,    88, -1231,   203,   -95,
     202,    22, -1231,   127,   116,   229,   150, -1231,   227, -1231,
   -1231, -1231, -1231, -1231,   233, -1231, -1231, -1231,   220, -1231,
   -1231,   231,   258,   260,   262,   273, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   180,   187, -1231,   210, -1231, -1231, -1231,
     289, -1231, -1231, -1231, -1231, -1231,   277,     5,   296,   311,
     305, -1231,   336,   338,   350, -1231, -1231, -1231,   347, -1231,
      97, -1231, -1231, -1231, -1231,   245,   291,   360,   207, -1231,
   -1231, -1231, -1231, -1231, -1231,   358,   606,   364,   366,   370,
     372,    29, -1231, -1231, -1231, -1231, -1231,   275,   272,   279,
     257, -1231,   307,   312,   386,   192, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231,   259,    17,   390, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231,   163, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231,   394, -1231, -1231, -1231, -1231,   319,   321,   396,   282,
   -1231,   400, -1231, -1231, -1231, -1231, -1231,   284,    33,   290,
      33,   292,    30,   294,    13,   299,    28,   398,    33,   415,
      33, -1231,   283, -1231, -1231, -1231,   440,   442,   448,   451,
     453, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   606,   606,
     606,   606,   606,   606, -1231, -1231,   606,   606,   606,   606,
     606,   606, -1231,   606,   606, -1231, -1231, -1231,   301,   310,
     606, -1231,   158,   158,   158, -1231,  -217,  -217,   455,   354,
   -1231,   355,    45, -1231,   397,   378,   465,   313, -1231,   463,
   -1231, -1231, -1231, -1231, -1231,   469,    66, -1231,   467, -1231,
     498,   501,   502, -1231, -1231, -1231, -1231, -1231,   470, -1231,
   -1231, -1231, -1231, -1231, -1231,   471, -1231,   503,   504,   506,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   472, -1231,
     508,   509, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231,   474, -1231,   510, -1231, -1231, -1231, -1231, -1231,   460,
   -1231, -1231, -1231, -1231, -1231,   461, -1231, -1231, -1231, -1231,
   -1231, -1231,   352, -1231, -1231,   516,   520,   522,   524,   526,
     606,   606,   606,   606,   285,   293,   125,   295,   297,   309,
     606,   303,   271,   281,    35,   287,   269,   458,   495,   534,
   -1231,   308, -1231, -1231,   314, -1231,   606,    37, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   267, -1231, -1231,   158, -1231,   158, -1231,
     606, -1231,   158, -1231,   235, -1231,   235, -1231,   315, -1231,
     158, -1231,   158, -1231,   158, -1231, -1231,   606, -1231,   158,
   -1231,   158,   261,   298,   554, -1231, -1231,   542, -1231,   438,
     564,   566, -1231, -1231, -1231, -1231, -1231,   568,   318, -1231,
     572, -1231, -1231, -1231, -1231, -1231,   570,    91, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,   578,   576,   579, -1231, -1231,
   -1231,   580,   581, -1231,   582,   584, -1231,   589, -1231,   527,
     433, -1231,   543,   433, -1231,  -107,   320,   101, -1231, -1231,
   -1231,   591,   592,   363,   362,   361,   365, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,   606, -1231, -1231, -1231, -1231,
     575,   598,   599, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   325, -1231,   327,
     600,   603,   605, -1231, -1231, -1231, -1231, -1231, -1231,    26,
   -1231,   323, -1231,   158, -1231,   300, -1231,   302, -1231,   609,
     158, -1231,   158, -1231, -1231,   329, -1231,   158, -1231,   158,
   -1231,   158, -1231,   158, -1231,   606, -1231,   316, -1231, -1231,
   -1231,   604,   612,   322, -1231, -1231, -1231,   610, -1231, -1231,
   -1231, -1231, -1231,   607,    65, -1231, -1231, -1231, -1231, -1231,
   -1231,   324,   124, -1231,   617,   618,   619,   620,   621,   624,
     625, -1231, -1231, -1231, -1231,   326, -1231, -1231, -1231,   328,
   -1231, -1231, -1231, -1231, -1231, -1231,   117, -1231,   622, -1231,
     452, -1231,   476, -1231,   627,   628,   629,   631,   632,   634,
     635,   636, -1231,   637, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   389, -1231, -1231,   633, -1231, -1231, -1231,
   -1231, -1231, -1231,   -58,   641,   643,   401, -1231,   357, -1231,
   -1231,   645,   367, -1231,   356, -1231, -1231,   351,   353,   359,
     346,   606, -1231, -1231,   651, -1231,   545, -1231,   653,   654,
     655,    94, -1231, -1231, -1231, -1231, -1231, -1231,   403,    60,
   -1231,   588, -1231,   659,   660,   661,   662,   663, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   664,    25, -1231,   511, -1231, -1231, -1231,
   -1231,   511, -1231, -1231, -1231, -1231,   665,   405, -1231, -1231,
   -1231,   158,   667,   656, -1231, -1231,   666,   668,   669,   670,
     671,   672,   673, -1231, -1231, -1231,   412,   678,   679,   680,
     681,   682, -1231, -1231,   685,   687, -1231,   374, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   606, -1231, -1231,
     590,   561, -1231, -1231, -1231, -1231,   684, -1231,   407,   131,
   -1231, -1231, -1231, -1231, -1231,   695,   697,   701,   683, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   699,   703,
     705,   707,   709, -1231, -1231,   547,   689, -1231,   556, -1231,
     630, -1231, -1231, -1231,   529, -1231, -1231, -1231,   531,   713,
     505, -1231,   744,   748,   750,   752,   754,   756,   758,   760,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   779,   781, -1231,
     606,    47, -1231, -1231,   674,   785,   783, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,   715,   706,   789,   791,   793,   799,   801,   818,
     820,   822,   824, -1231,   826,   410, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,   675,   851, -1231, -1231,   828,
   -1231,   614,   712, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   525, -1231,   753,   865,   867, -1231, -1231,
   -1231, -1231, -1231,    54, -1231, -1231,   869,   606,   706,   790,
   -1231, -1231,   863, -1231,   158,   877,   879,   881, -1231, -1231,
   -1231, -1231, -1231, -1231,   883, -1231,    21, -1231, -1231, -1231,
     875,   263, -1231,   688,   884,   693, -1231, -1231, -1231,   712,
     889,   414, -1231, -1231, -1231,   784, -1231,   774,   891,   892,
   -1231,   782,   897,   898, -1231, -1231, -1231, -1231, -1231,    56,
     899,   813, -1231, -1231, -1231,   819, -1231, -1231, -1231,   902,
     749, -1231,   901, -1231,   903,   906, -1231, -1231, -1231, -1231,
     704,   904,   717, -1231, -1231,   716,   418,   -89,   422, -1231,
     907, -1231,   511, -1231, -1231, -1231, -1231, -1231,   900,   913,
     916, -1231,   796, -1231,   798,   914,   915, -1231,   808,   921,
     922, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,   763,   920,   923, -1231,   719,   918,   736, -1231,
   -1231, -1231,   735,   425, -1231,   739,   712, -1231,   511, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   511, -1231,
   -1231, -1231,   931, -1231,   718,   932,   427, -1231, -1231, -1231,
   -1231,   919,   933,   936, -1231,   825, -1231,   817,   935,   937,
   -1231,   940,   942, -1231,   737,   938,   755, -1231, -1231,   757,
     429, -1231,   743,   712, -1231,   511, -1231, -1231, -1231, -1231,
     759,   941, -1231, -1231,   762,   431,  -123, -1231,   729, -1231,
   -1231,   946, -1231,   834, -1231,   953,   464, -1231, -1231, -1231,
   -1231,   943,   957,   959, -1231, -1231, -1231,   751,   952,   770,
     761, -1231,   769,   466, -1231,   764,   712, -1231,   511, -1231,
   -1231, -1231, -1231,   771,   956, -1231, -1231,   772, -1231,   773,
   -1231, -1231,    19, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   970, -1231,   967, -1231,   852, -1231,   973,
     468, -1231, -1231, -1231,   786,   306,   787,   765, -1231,   788,
     473, -1231, -1231,   775,   712, -1231,   511, -1231, -1231, -1231,
   -1231,   968, -1231, -1231,   792, -1231,   794, -1231,   969,   780,
   -1231, -1231,   815,   979,   980, -1231,   988, -1231,   985, -1231,
     870, -1231, -1231, -1231, -1231,   990,   986, -1231, -1231, -1231,
   -1231,   802,   475, -1231, -1231, -1231,   712, -1231,   511, -1231,
   -1231, -1231, -1231,   987, -1231, -1231,   800,   803, -1231, -1231,
     989,   804, -1231,   992, -1231,  -107, -1231, -1231, -1231, -1231,
     998, -1231, -1231,   809,   795, -1231, -1231,   712, -1231,   511,
   -1231, -1231, -1231,   810, -1231,   811,   807, -1231, -1231, -1231,
     812,   814,   477, -1231,  1000, -1231,  -100, -1231, -1231, -1231,
   -1231, -1231, -1231,   816,   479, -1231,   821, -1231,   827, -1231,
   -1231, -1231,   823,   829,   481, -1231, -1231, -1231,   483, -1231,
     511, -1231, -1231, -1231,   -82, -1231, -1231,   -94, -1231, -1231,
     712, -1231,   511, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231,   485, -1231,   511, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   831, -1231,   -93, -1231, -1231, -1231,   854,
    1001, -1231,   830, -1231, -1231, -1231, -1231, -1231, -1231,   832,
     -91, -1231, -1231,  1005, -1231,   511, -1231,   -88, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,   835, -1231, -1231, -1231,   488,
     490,   -84,   855, -1231, -1231,   606, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231,  1014,  1017, -1231, -1231, -1231, -1231,
     859,  -102, -1231,  1018, -1231, -1231, -1231, -1231,   708,  1021,
    1024,  1026,  1023, -1231, -1231, -1231,  1028, -1231,  1033,   833,
   -1231, -1231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   149,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,   740,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,    43, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231,   -12, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231,   -74, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   530, -1231, -1231,
      18,    31, -1231, -1231, -1231,   223, -1231,  -219,   225,   806,
     838, -1231, -1231, -1231, -1231,  -598,   226, -1231,   228,   232,
     234, -1231,  -686,  -486,  -766,  -207, -1231,  -744, -1230, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1196, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231,   -98, -1231, -1231,
   -1231, -1231, -1231, -1231,  -146, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231,  -189, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
    -902, -1231, -1231, -1231, -1231,  -325, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,  -268, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,  -274,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231,   611, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231,
   -1231, -1231, -1231, -1231, -1231, -1231, -1231, -1231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     390,   391,   392,   393,   394,   395,   296,   297,   398,   399,
     400,   401,   402,   403,   626,   405,   406,   851,   870,   462,
     463,   333,   416,   343,   740,   355,  1020,   367,   844,   374,
     992,   380,    50,    51,   320,   100,   213,   214,   256,   257,
      52,    53,    54,   836,   694,   539,   540,   558,   559,   320,
     258,   320,  1316,   541,   320,   468,   469,   944,   945,   560,
     561,  1435,   918,   641,  1000,  1001,  1057,  1058,  1376,   918,
    1303,  1399,   337,   338,  1406,   350,   351,   913,   694,  1092,
     918,   320,  1093,  1344,   642,     1,   923,  1039,     4,   337,
     338,   339,  1424,   363,     7,    18,  1425,    19,    39,    40,
    1346,  1326,  1196,  1197,   215,   216,   217,   218,  1377,  1392,
     643,  1400,     6,  1436,  1407,  1375,    10,   695,  1374,   718,
     719,    12,   523,   524,   525,   526,    65,    66,   530,   532,
      17,   833,   535,   901,    45,   489,    46,   490,    15,   550,
     552,   554,   694,   825,   723,   320,   724,    22,   557,   694,
      25,   695,   320,   470,   471,    28,   737,   826,   827,   828,
      71,    72,   571,   946,   573,   616,   947,   617,   577,   101,
      30,  1002,   575,  1003,  1059,  1060,   587,    32,   589,  1021,
     591,   815,    35,   816,  1142,   595,   381,   597,  1240,   593,
     258,   321,   322,    86,    87,   259,   260,    89,    90,   115,
     116,   788,   232,   233,    38,   790,   321,   322,   321,   322,
      44,   321,   322,    49,   825,   695,   733,   734,   735,   736,
     737,   896,   695,   733,   734,   735,   736,   737,    62,   418,
     828,   419,    70,   420,    76,   421,    78,   422,    79,   423,
     128,   424,   129,   425,   130,   426,   792,   427,   131,   428,
     132,   429,   133,   430,   134,   431,   135,   432,   331,    81,
     341,    82,   353,    83,   365,    84,   372,   683,   378,   251,
     252,   332,   685,   342,  1232,   354,    85,   366,    94,   373,
      99,   379,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   310,   311,   317,   318,    97,   869,  1103,   698,
     327,   328,   334,   335,   347,   348,   702,   104,   704,   360,
     361,   410,   411,   707,   105,   708,   106,   709,   121,   710,
     413,   414,  1274,   481,   482,   584,   585,   711,   608,   609,
     651,   652,   715,   716,   730,   731,   755,   756,   760,   761,
     765,   766,    55,   107,  1143,   108,   215,   216,   217,   218,
     215,   216,   217,   218,  1147,   542,   562,   109,   154,   112,
     155,   124,   156,   127,   157,   153,   158,   209,   159,   210,
     160,   529,   161,   211,   162,   212,   163,   220,   164,   221,
     165,   223,   166,   224,   167,   225,   168,   228,   169,   231,
     170,  1186,   171,   267,   172,   295,   173,   298,   174,   309,
     175,   306,   176,   739,   177,   303,   178,   315,   179,   369,
     180,   796,   797,   820,   821,   853,   854,   887,   888,   793,
     975,   976,  1024,  1025,  1041,  1042,   375,   754,  1087,  1088,
    1243,  1244,  1097,  1098,  1233,  1134,  1135,  1152,  1153,  1177,
    1178,  1191,  1192,   807,   385,   418,   386,   419,  1380,   420,
     381,   421,   387,   422,   388,   423,   389,   424,   465,   425,
     467,   426,   464,   427,   476,   428,   477,   429,   480,   430,
     486,   431,   488,   432,  1206,  1207,  1225,  1226,  1249,  1250,
    1254,  1255,  1275,  1267,  1268,  1298,  1299,  1339,  1340,  1351,
    1352,  1362,  1363,  1367,  1368,  1383,  1384,   858,  1414,  1415,
    1419,  1420,   495,   494,   496,   497,   500,   501,   498,   502,
     831,   504,   505,   499,   507,   508,   503,   514,   511,   518,
     506,  1318,  1319,   519,  1304,   520,  1321,   527,   154,   537,
     155,   521,   156,   522,   157,   548,   158,   528,   159,   880,
     160,   538,   161,   531,   162,   599,   163,   533,   164,   570,
     165,   547,   166,   579,   167,  1327,   168,   601,   169,   536,
     170,   534,   171,   602,   172,   604,   173,   605,   174,   606,
     175,   607,   176,   615,   177,   632,   178,   754,   179,   613,
     180,   623,   555,   624,   600,   634,   625,   627,   628,   629,
     556,   630,   631,   637,   677,   678,  1372,   679,   680,   681,
     894,   686,   687,   688,   690,   682,   691,   689,  1381,   692,
     722,   697,   943,   701,   699,   713,   714,   720,   700,  1388,
     746,   747,   748,   749,   750,   706,   712,   751,   752,   772,
     776,   777,   778,   771,   779,   780,   754,   781,   782,   783,
     787,   784,   775,   785,   794,   754,   795,   799,   800,   803,
     802,  1405,   806,   804,   808,   809,   812,   813,   814,   801,
     837,   805,   838,   839,   840,   841,   842,   860,   845,   852,
     859,   843,   883,   862,   871,   863,   864,   865,   866,   867,
     868,   872,   873,   874,   875,   876,   879,   907,   921,  1011,
    1015,   154,   877,   155,   878,   156,   882,   157,   904,   158,
     905,   159,   885,   160,   906,   161,   908,   162,   914,   163,
     909,   164,   910,   165,   911,   166,   912,   167,   918,   168,
     929,   169,   924,   170,   930,   171,   549,   172,   154,   173,
     155,   174,   156,   175,   157,   176,   158,   177,   159,   178,
     160,   179,   161,   180,   162,   916,   163,   933,   164,   927,
     165,   934,   166,   935,   167,   936,   168,   937,   169,   938,
     170,   939,   171,   940,   172,   551,   173,   154,   174,   155,
     175,   156,   176,   157,   177,   158,   178,   159,   179,   160,
     180,   161,   941,   162,   942,   163,   954,   164,   956,   165,
     962,   166,   960,   167,   957,   168,   965,   169,   966,   170,
     967,   171,   968,   172,   969,   173,   553,   174,   154,   175,
     155,   176,   156,   177,   157,   178,   158,   179,   159,   180,
     160,   970,   161,   971,   162,   972,   163,   973,   164,   974,
     165,   986,   166,   993,   167,   987,   168,   684,   169,   154,
     170,   155,   171,   156,   172,   157,   173,   158,   174,   159,
     175,   160,   176,   161,   177,   162,   178,   163,   179,   164,
     180,   165,   985,   166,   990,   167,   994,   168,   998,   169,
     999,   170,  1012,   171,  1014,   172,  1010,   173,   982,   174,
    1016,   175,  1017,   176,  1018,   177,  1022,   178,  1033,   179,
    1019,   180,  1040,  1029,  1048,  1032,  1051,  1046,  1049,  1050,
    1055,  1056,  1066,  1067,  1068,  1070,  1073,  1071,  1072,  1074,
    1109,  1075,  1080,  1084,  1102,  1078,  1107,  1412,  1105,  1108,
    1111,  1112,  1113,  1114,  1118,  1119,  1120,  1121,  1123,  1126,
    1122,  1128,  1131,  1139,  1149,  1151,  1157,  1155,  1150,  1158,
    1159,  1161,  1162,  1164,  1163,  1165,  1439,  1182,  1166,  1169,
    1171,  1202,  1189,  1203,  1174,  1204,  1205,  1188,  1190,  1448,
    1211,  1209,  1212,  1216,  1213,  1218,  1222,  1236,  1237,  1235,
    1230,  1221,  1238,  1245,  1246,  1247,  1248,  1263,  1252,  1277,
    1282,  1283,  1260,  1272,  1286,  1264,  1287,  1288,  1279,   754,
     754,  1289,  1290,  1280,  1292,  1291,  1308,  1293,  1306,  1295,
    1313,  1320,  1309,  1317,  1322,  1314,  1331,  1330,  1329,  1325,
    1335,  1345,  1395,  1348,  1025,  1336,  1403,  1432,  1429,  1356,
    1433,  1358,  1434,  1357,  1443,  1440,  1396,  1444,  1441,  1445,
    1359,  1391,  1398,  1413,  1446,  1449,  1450,   958,  1047,   466,
    1110,  1160,   893,   640,   895,   897,  1241,   898,  1198,  1451,
     356,   899,  1285,   900,  1394,     0,     0,   583,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,   754,   357,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1430
};

static const yytype_int16 yycheck[] =
{
     268,   269,   270,   271,   272,   273,   213,   214,   276,   277,
     278,   279,   280,   281,   500,   283,   284,   761,   784,   293,
     294,   240,   290,   242,   622,   244,     5,   246,     3,   248,
     932,   250,    10,    11,    21,    30,     7,     8,    21,    22,
      18,    19,    20,   729,    18,    10,    11,    10,    11,    21,
     173,    21,  1282,    18,    21,    10,    11,    10,    11,    22,
      23,   163,   162,   170,    10,    11,    10,    11,   162,   162,
    1266,   162,    59,    60,   162,    62,    63,   843,    18,   168,
     162,    21,   171,  1313,   191,    24,   852,   989,    26,    59,
      60,    61,   176,    65,   228,    25,   180,    27,    10,    11,
     200,  1297,   225,   226,   321,   322,   323,   324,   202,   202,
     217,   202,     0,   215,   202,  1345,     3,    91,   200,   605,
     606,    29,   390,   391,   392,   393,    10,    11,   396,   397,
       7,   729,   400,   819,   229,    69,   231,    71,   230,   407,
     408,   409,    18,    83,    79,    21,    81,    32,   416,    18,
      31,    91,    21,   108,   109,     3,    96,    97,    98,    99,
      10,    11,   436,   116,   438,    74,   119,    76,   442,   164,
       3,   117,   440,   119,   118,   119,   450,    66,   452,   158,
     454,    87,    34,    89,  1086,   459,   167,   461,   169,   457,
     173,   178,   179,    13,    14,   178,   179,    10,    11,   102,
     103,   687,    10,    11,     3,   691,   178,   179,   178,   179,
       7,   178,   179,    11,    83,    91,    92,    93,    94,    95,
      96,   819,    91,    92,    93,    94,    95,    96,   101,   287,
      99,   289,     3,   291,     7,   293,     3,   295,    18,   297,
      33,   299,    35,   301,    37,   303,   304,   305,    41,   307,
      43,   309,    45,   311,    47,   313,    49,   315,   240,    28,
     242,     3,   244,     3,   246,     3,   248,   535,   250,    10,
      11,   240,   540,   242,  1176,   244,     3,   246,    68,   248,
       3,   250,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    10,    11,    10,    11,     7,   783,  1042,   573,
      10,    11,    10,    11,    10,    11,   580,    11,   582,    10,
      11,    10,    11,   587,     3,   589,    11,   591,    73,   593,
      10,    11,  1224,    10,    11,    10,    11,   595,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     223,   224,   320,     7,  1088,     7,   321,   322,   323,   324,
     321,   322,   323,   324,  1098,   320,   319,     7,   233,    12,
     235,    70,   237,     3,   239,     7,   241,     3,   243,     3,
     245,   246,   247,     3,   249,     3,   251,   102,   253,   107,
     255,   102,   257,   126,   259,    78,   261,    75,   263,     3,
     265,  1135,   267,     3,   269,   232,   271,     3,   273,     3,
     275,    80,   277,   622,   279,    86,   281,     7,   283,    11,
     285,    10,    11,    10,    11,    10,    11,    10,    11,   693,
      10,    11,   159,   160,    10,    11,    11,   634,    10,    11,
    1196,  1197,    10,    11,  1178,    10,    11,    10,    11,    10,
      11,    10,    11,   711,     4,   287,     4,   289,  1350,   291,
     167,   293,     4,   295,     3,   297,     3,   299,   104,   301,
     105,   303,     7,   305,    67,   307,    88,   309,     3,   311,
       7,   313,     3,   315,    10,    11,    10,    11,    10,    11,
     174,   175,  1226,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   771,    10,    11,
      10,    11,     4,    36,     3,     3,     3,     3,    38,     3,
     729,     3,     3,    42,     4,    55,    44,   165,    57,     3,
      46,  1287,  1288,     3,  1268,     3,  1292,   242,   233,   258,
     235,     7,   237,     7,   239,   266,   241,   244,   243,   807,
     245,   260,   247,   248,   249,   284,   251,   250,   253,   282,
     255,   264,   257,   318,   259,  1299,   261,     3,   263,   256,
     265,   252,   267,    21,   269,   127,   271,     3,   273,     3,
     275,     3,   277,     3,   279,    48,   281,   784,   283,     7,
     285,     3,   274,     7,   286,   152,     7,     7,     7,     7,
     276,     7,     3,    50,     3,     3,  1340,   234,   236,   238,
     819,     3,     3,   278,     4,   240,     3,   280,  1352,     4,
       3,   288,   880,     4,   314,    11,     4,     7,   316,  1363,
       3,     3,     3,     3,     3,   296,   310,     3,     3,   177,
       3,     3,     3,    11,     3,     3,   843,     3,     3,     3,
       7,     4,   166,   254,     3,   852,     3,   290,     3,   298,
     294,  1395,   306,   300,     3,   110,     3,     3,     3,   292,
      72,   302,     3,     3,     3,     3,     3,    11,   157,     4,
       3,     7,   111,     7,   262,     7,     7,     7,     7,     7,
       7,     3,     3,     3,     3,     3,   312,     4,    58,   957,
     964,   233,     7,   235,     7,   237,   106,   239,     3,   241,
       3,   243,    18,   245,     3,   247,     7,   249,   161,   251,
       7,   253,     7,   255,     7,   257,     7,   259,   162,   261,
       7,   263,   193,   265,   219,   267,   268,   269,   233,   271,
     235,   273,   237,   275,   239,   277,   241,   279,   243,   281,
     245,   283,   247,   285,   249,    56,   251,     3,   253,   218,
     255,     3,   257,     3,   259,     3,   261,     3,   263,     3,
     265,     3,   267,     3,   269,   270,   271,   233,   273,   235,
     275,   237,   277,   239,   279,   241,   281,   243,   283,   245,
     285,   247,     3,   249,     3,   251,   112,   253,     3,   255,
      84,   257,    77,   259,    11,   261,     7,   263,     7,   265,
       7,   267,     3,   269,     3,   271,   272,   273,   233,   275,
     235,   277,   237,   279,   239,   281,   241,   283,   243,   285,
     245,     3,   247,     3,   249,     3,   251,     3,   253,     3,
     255,     3,   257,   308,   259,   221,   261,   262,   263,   233,
     265,   235,   267,   237,   269,   239,   271,   241,   273,   243,
     275,   245,   277,   247,   279,   249,   281,   251,   283,   253,
     285,   255,    11,   257,   152,   259,   113,   261,     3,   263,
       3,   265,    82,   267,    11,   269,     7,   271,   203,   273,
       3,   275,     3,   277,     3,   279,    11,   281,   195,   283,
       7,   285,     3,   205,   120,    11,   114,   113,     7,     7,
       3,     3,     3,    90,    85,     3,     3,   158,     7,     3,
     114,   207,   195,   197,     7,    11,     3,  1403,    18,     3,
     122,     7,     7,   115,     3,     3,   163,     7,   209,    11,
       7,   195,   197,   194,     3,     3,     3,    18,   220,     3,
     115,   124,     7,     3,     7,     3,  1432,   204,   211,    11,
     195,   222,    11,     7,   197,   121,     3,   198,   196,  1445,
       3,    18,     3,    11,   213,   195,   197,    11,   196,   198,
     206,   210,   199,     3,     7,   123,     3,   212,   192,    11,
      11,   201,   195,   208,   169,   197,     7,     7,   196,  1196,
    1197,     3,     7,   199,     4,   125,   196,    11,    11,   197,
      11,     3,   199,    11,   195,   201,   199,   196,   198,   214,
     198,    11,    11,   197,   160,   201,    11,     3,   163,   198,
       3,   198,   163,   196,     3,     7,   196,     3,   320,     3,
     201,   200,   200,   198,    11,     7,     3,   888,   995,   299,
    1052,  1115,   819,   513,   819,   819,  1192,   819,  1146,   216,
     244,   819,  1241,   819,  1379,    -1,    -1,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,  1288,   244,    -1,    -1,  1292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   326,   330,    26,   331,     0,   228,   811,   812,
       3,   332,    29,   342,   343,   230,   813,     7,    25,    27,
     333,   334,    32,   349,   350,    31,   344,   543,     3,   814,
       3,   336,    66,   417,   418,    34,   351,   544,     3,    10,
      11,   345,   346,   347,     7,   229,   231,   815,   816,    11,
      10,    11,    18,    19,    20,   320,   335,   337,   338,   339,
     340,   341,   101,   485,   486,    10,    11,   419,   420,   421,
       3,    10,    11,   352,   353,   354,     7,   348,     3,    18,
     817,    28,     3,     3,     3,     3,    13,    14,   327,    10,
      11,   487,   488,   489,    68,   422,   423,     7,   355,     3,
      30,   164,   597,   598,    11,     3,    11,     7,     7,     7,
     568,   570,    12,   328,   329,   102,   103,   490,   491,   534,
     535,    73,   436,   437,    70,   424,   547,     3,    33,    35,
      37,    41,    43,    45,    47,    49,   356,   357,   358,   363,
     364,   369,   370,   375,   376,   381,   382,   387,   388,   402,
     403,   599,   600,     7,   233,   235,   237,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   818,   819,   822,   825,   827,   829,   831,   833,   835,
     837,   839,   841,   843,   845,   847,   849,   851,   853,   855,
     857,   859,   861,   871,   879,   882,   885,   888,   891,     3,
       3,     3,     3,     7,     8,   321,   322,   323,   324,   571,
     102,   107,   492,   102,   126,    78,   458,   459,    75,   438,
     548,     3,    10,    11,   425,   426,   427,   359,   360,   365,
     366,   371,   372,   377,   378,   383,   384,   389,   390,   404,
     405,    10,    11,   605,   606,   607,    21,    22,   173,   178,
     179,   601,   602,   603,   604,   804,   806,     3,   836,   828,
     830,   834,   838,   840,   880,   892,   848,   832,   854,   842,
     844,   846,   872,   850,   852,   886,   883,   889,   820,   823,
     826,   862,   856,   858,   860,   232,   570,   570,     3,   493,
     494,   495,   537,    86,   476,   477,    80,   460,   549,     3,
      10,    11,   439,   440,   441,     7,   429,    10,    11,   362,
      21,   178,   179,   361,   545,   546,   552,    10,    11,   368,
     367,   545,   546,   552,    10,    11,   374,    59,    60,    61,
     373,   545,   546,   552,   554,   555,   556,    10,    11,   380,
      62,    63,   379,   545,   546,   552,   554,   555,   557,   558,
      10,    11,   386,    65,   385,   545,   546,   552,   559,    11,
     392,   391,   545,   546,   552,    11,   407,   406,   545,   546,
     552,   167,   608,   609,   610,     4,     4,     4,     3,     3,
     818,   818,   818,   818,   818,   818,   881,   893,   818,   818,
     818,   818,   818,   818,   875,   818,   818,   887,   884,   890,
      10,    11,   821,    10,    11,   824,   818,   864,   287,   289,
     291,   293,   295,   297,   299,   301,   303,   305,   307,   309,
     311,   313,   315,   894,   895,   898,   899,   901,   902,   904,
     905,   907,   908,   910,   911,   914,   915,   919,   920,   922,
     923,   925,   926,   928,   929,   931,   934,   935,   937,   938,
     940,   941,   894,   894,     7,   104,   494,   105,    10,    11,
     108,   109,   536,   538,   540,   541,    67,    88,   478,   551,
       3,    10,    11,   461,   462,   463,     7,   443,     3,    69,
      71,   428,   430,   431,    36,     4,     3,     3,    38,    42,
       3,     3,     3,    44,     3,     3,    46,     4,    55,   393,
     394,    57,   408,   409,   165,   627,   611,   612,     3,     3,
       3,     7,     7,   818,   818,   818,   818,   242,   244,   246,
     818,   248,   818,   250,   252,   818,   256,   258,   260,    10,
      11,    18,   320,   873,   876,   877,   878,   264,   266,   268,
     818,   270,   818,   272,   818,   274,   276,   818,    10,    11,
      22,    23,   319,   863,   865,   866,   868,   870,   932,   896,
     282,   894,   900,   894,   903,   818,   906,   894,   909,   318,
     912,   918,   916,   918,    10,    11,   921,   894,   924,   894,
     927,   894,   930,   818,   936,   894,   939,   894,   942,   284,
     286,     3,    21,   496,   127,     3,     3,     3,    10,    11,
     479,   480,   481,     7,   465,     3,    74,    76,   442,   444,
     445,   432,   433,     3,     7,     7,   568,     7,     7,     7,
       7,     3,    48,   401,   152,   395,   542,    50,   416,   410,
     542,   170,   191,   217,   628,   629,   630,   769,   770,   772,
     773,    10,    11,   626,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,     3,     3,   234,
     236,   238,   240,   818,   262,   818,     3,     3,   278,   280,
       4,     3,     4,   933,    18,    91,   560,   288,   894,   314,
     316,     4,   894,   913,   894,   917,   296,   894,   894,   894,
     894,   818,   310,    11,     4,    10,    11,   497,   568,   568,
       7,   482,     3,    79,    81,   464,   466,   467,   446,   447,
      10,    11,   435,    92,    93,    94,    95,    96,   434,   552,
     560,   561,   563,   564,   565,   567,     3,     3,     3,     3,
       3,     3,     3,   569,   570,    10,    11,   396,   397,   398,
      10,    11,   411,   412,   413,   223,   224,   631,   632,   633,
     634,    11,   177,   774,   803,   166,     3,     3,     3,     3,
       3,     3,     3,     3,     4,   254,   874,     7,   568,   867,
     568,   869,   304,   894,     3,     3,    10,    11,   897,   290,
       3,   292,   294,   298,   300,   302,   306,   818,     3,   110,
     498,   499,     3,     3,     3,    87,    89,   483,   468,   469,
      10,    11,   449,   450,   451,    83,    97,    98,    99,   448,
     550,   552,   553,   560,   562,   566,   567,    72,     3,     3,
       3,     3,     3,     7,     3,   157,   399,   572,   573,   580,
     414,   572,     4,    10,    11,   635,   636,   637,   894,     3,
      11,   775,     7,     7,     7,     7,     7,     7,     7,   568,
     569,   262,     3,     3,     3,     3,     3,     7,     7,   312,
     818,   500,   106,   111,   511,    18,   484,    10,    11,   471,
     472,   473,   470,   550,   552,   553,   560,   561,   563,   564,
     565,   567,   452,   454,     3,     3,     3,     4,     7,     7,
       7,     7,     7,   569,   161,   808,    56,   400,   162,   574,
     575,    58,   415,   569,   193,   639,   640,   218,   771,     7,
     219,   777,   778,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   818,    10,    11,   116,   119,   501,   502,
     503,   504,   505,   512,   112,   523,     3,    11,   454,   474,
      77,   453,    84,   455,   456,     7,     7,     7,     3,     3,
       3,     3,     3,     3,     3,    10,    11,   581,   582,   583,
     576,   577,   203,   650,   651,    11,     3,   221,   784,   785,
     152,   779,   805,   308,   113,   506,   507,   508,     3,     3,
      10,    11,   117,   119,   513,   514,   515,   516,   517,   524,
       7,   818,    82,   475,    11,   894,     3,     3,     3,     7,
       5,   158,    11,   579,   159,   160,   578,   809,   810,   205,
     661,   662,    11,   195,   641,   642,   643,   791,   786,   805,
       3,    10,    11,   780,   781,   782,   113,   507,   120,     7,
       7,   114,   518,   519,   520,     3,     3,    10,    11,   118,
     119,   525,   526,   527,   528,   539,     3,    90,    85,   457,
       3,   158,     7,     3,     3,   207,   701,   702,    11,   663,
     195,   652,   653,   654,   197,   648,   649,    10,    11,   644,
     645,   646,   168,   171,   776,   792,   793,    10,    11,   787,
     788,   789,     7,   572,   783,    18,   509,     3,     3,   114,
     519,   122,     7,     7,   115,   529,   530,   531,     3,     3,
     163,     7,     7,   209,   732,   733,    11,   703,   195,   664,
     665,   197,   659,   660,    10,    11,   655,   656,   657,   194,
     589,   590,   805,   572,   647,   794,   795,   572,   790,     3,
     220,     3,    10,    11,   510,    18,   521,     3,     3,   115,
     530,   124,     7,     7,     3,     3,   211,   743,   744,    11,
     734,   195,   704,   705,   197,   670,   671,    10,    11,   666,
     667,   668,   204,   593,   594,   805,   572,   658,   198,    11,
     196,    10,    11,   799,   800,   801,   225,   226,   602,   796,
     797,   798,   222,     7,   121,     3,    10,    11,   522,    18,
     532,     3,     3,   213,   754,   755,    11,   745,   195,   735,
     736,   210,   197,   710,   711,    10,    11,   706,   707,   708,
     206,   672,   805,   572,   669,   198,    11,   196,   199,   591,
     169,   609,   802,   569,   569,     3,     7,   123,     3,    10,
      11,   533,   192,   638,   174,   175,   756,   757,   758,   759,
     195,   746,   747,   212,   197,   741,   742,    10,    11,   737,
     738,   739,   208,   712,   805,   572,   709,    11,   673,   196,
     199,   595,    11,   201,   592,   627,   169,     7,     7,     3,
       7,   125,     4,    11,   760,   197,   752,   753,    10,    11,
     748,   749,   750,   593,   572,   740,    11,   713,   196,   199,
     674,   675,   676,    11,   201,   596,   573,    11,   569,   569,
       3,   569,   195,   761,   762,   214,   593,   572,   751,   198,
     196,   199,   714,   715,   716,   198,   201,   681,   682,    10,
      11,   677,   678,   679,   573,    11,   200,   584,   197,   767,
     768,    10,    11,   763,   764,   765,   198,   196,   198,   201,
     721,   722,    10,    11,   717,   718,   719,    10,    11,   683,
     684,   685,   572,   680,   200,   573,   162,   202,   585,   586,
     805,   572,   766,    10,    11,   723,   724,   725,   572,   720,
     686,   200,   202,   587,   810,    11,   196,   726,   200,   162,
     202,   687,   688,    11,   588,   572,   162,   202,   727,   728,
     689,   690,   568,   198,    10,    11,   729,   730,   731,    10,
      11,   693,   694,   695,   176,   180,   691,   692,   807,   163,
     818,   696,     3,     3,   163,   163,   215,   697,   698,   568,
       7,   320,   699,     3,     3,     3,    11,   700,   568,     7,
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
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
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
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryAttributePresent = false;
    osglData->matrixTypeAttributePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
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
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
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
    osglData->baseMatrixEndRowAttribute = osglData->matrix->numberOfRows;
    osglData->baseMatrixEndColAttribute = osglData->matrix->numberOfColumns;
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
    osglData->matrix->matrixType  = mergeMatrixType(osglData->matrix->matrixType,
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
    if ((yyvsp[(3) - (4)].ival) > osglData->matrix->numberOfRows)
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
    if ((yyvsp[(3) - (4)].ival) > osglData->matrix->numberOfColumns)
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
}
    break;

  case 474:

    {
    ((MatrixElements*)osglData->tempC)->rowMajor = true;
}
    break;

  case 475:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") ((MatrixElements*)osglData->tempC)->rowMajor = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  ((MatrixElements*)osglData->tempC)->rowMajor = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      ((MatrixElements*)osglData->tempC)->rowMajor = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute in <elements> must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 483:

    {
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
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
    if (osglData->rowMajorAttribute == true)
        osglData->osglNumberOfEl = osglData->matrix->numberOfColumns;
    else
        osglData->osglNumberOfEl = osglData->matrix->numberOfRows;
}
    break;

  case 492:

    {
    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set variables basic failed");    
//    delete[] osglData->osglIntArray;
//    osglData->osglIntArray = NULL;
//    delete[] osglData->osglDblArray;
//    osglData->osglDblArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
//    if (osglData->numberOfEl > 0)
//        osglData->tempC->matrixType  = mergeMatrixType(osglData->tempC->matrixType, ENUM_MATRIX_TYPE_constant);
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

  case 643:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 644:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 647:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 649:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
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

    {  
        if (osnlData->nlnodecount < osnlData->tmpnlcount)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 695:

    {               
    osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
}
    break;

  case 696:

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

  case 699:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->nlnodecount++;
    }
    break;

  case 700:

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

  case 701:

    { 
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        //osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
    }
    break;

  case 729:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 733:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 737:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 739:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 741:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 743:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 745:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 747:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
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

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 769:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 771:

    {
//    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 773:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 774:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 782:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 784:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 786:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 787:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 788:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 791:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 795:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 796:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 797:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 798:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 799:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 800:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 802:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 803:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 804:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 806:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 807:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 808:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 810:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 811:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 812:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 814:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 815:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 816:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 818:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 834:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 835:

    {osnlData->matrixidxattON = false;}
    break;

  case 838:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 840:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 843:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 846:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 849:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 852:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 857:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 861:

    { 
    osnlData->includeDiagonalAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 863:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 867:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 870:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 873:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 875:

    {
//    osnlData->nlNodePoint = new OSnLNodeProduct();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
//    osnlData->mtxProdVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 876:

    {
//    osnlData->mtxProdVec.back()->m_mChildren = new OSnLNode*[ osnlData->mtxProdVec.back()->inumberOfMatrixChildren];
//    osnlData->mtxProdVec.pop_back();
}
    break;

  case 878:

    { /*osnlData->mtxProdVec.back()->inumberOfMatrixChildren++; */}
    break;

  case 880:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 883:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 886:

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


