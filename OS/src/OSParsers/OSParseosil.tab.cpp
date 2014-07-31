
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
     TIMEDOMAINSTART = 310,
     TIMEDOMAINEND = 311,
     STAGESSTART = 312,
     STAGESEND = 313,
     STAGESTART = 314,
     STAGEEND = 315,
     NUMBEROFSTAGESATT = 316,
     HORIZONATT = 317,
     STARTATT = 318,
     VARIABLESSTART = 319,
     CONSTRAINTSSTART = 320,
     OBJECTIVESSTART = 321,
     VARIABLESEND = 322,
     CONSTRAINTSEND = 323,
     OBJECTIVESEND = 324,
     NUMBEROFVARIABLESATT = 325,
     NUMBEROFCONSTRAINTSATT = 326,
     NUMBEROFOBJECTIVESATT = 327,
     STARTIDXATT = 328,
     VARSTART = 329,
     VAREND = 330,
     CONSTART = 331,
     CONEND = 332,
     OBJSTART = 333,
     OBJEND = 334,
     INTERVALSTART = 335,
     INTERVALEND = 336,
     HEADERSTART = 337,
     HEADEREND = 338,
     FILENAMESTART = 339,
     FILENAMEEND = 340,
     FILENAMEEMPTY = 341,
     FILENAMESTARTANDEND = 342,
     FILESOURCESTART = 343,
     FILESOURCEEND = 344,
     FILESOURCEEMPTY = 345,
     FILESOURCESTARTANDEND = 346,
     FILEDESCRIPTIONSTART = 347,
     FILEDESCRIPTIONEND = 348,
     FILEDESCRIPTIONEMPTY = 349,
     FILEDESCRIPTIONSTARTANDEND = 350,
     FILECREATORSTART = 351,
     FILECREATOREND = 352,
     FILECREATOREMPTY = 353,
     FILECREATORSTARTANDEND = 354,
     FILELICENCESTART = 355,
     FILELICENCEEND = 356,
     FILELICENCEEMPTY = 357,
     FILELICENCESTARTANDEND = 358,
     ENUMERATIONSTART = 359,
     ENUMERATIONEND = 360,
     NUMBEROFELATT = 361,
     ITEMEMPTY = 362,
     ITEMSTART = 363,
     ITEMEND = 364,
     ITEMSTARTANDEND = 365,
     BASE64START = 366,
     BASE64END = 367,
     INCRATT = 368,
     MULTATT = 369,
     SIZEOFATT = 370,
     ELSTART = 371,
     ELEND = 372,
     MATRIXSTART = 373,
     MATRIXEND = 374,
     BASEMATRIXEND = 375,
     BASEMATRIXSTART = 376,
     BLOCKSTART = 377,
     BLOCKEND = 378,
     BLOCKSSTART = 379,
     BLOCKSEND = 380,
     EMPTYSYMMETRYATT = 381,
     SYMMETRYATT = 382,
     EMPTYEXCLUDEATT = 383,
     EXCLUDEATT = 384,
     CONSTANTATT = 385,
     NUMBEROFBLOCKSATT = 386,
     NUMBEROFCOLUMNSATT = 387,
     NUMBEROFROWSATT = 388,
     NUMBEROFVARIDXATT = 389,
     BASEMATRIXIDXATT = 390,
     TARGETMATRIXFIRSTROWATT = 391,
     TARGETMATRIXFIRSTCOLATT = 392,
     BASEMATRIXSTARTROWATT = 393,
     BASEMATRIXSTARTCOLATT = 394,
     BASEMATRIXENDROWATT = 395,
     BASEMATRIXENDCOLATT = 396,
     SCALARMULTIPLIERATT = 397,
     EMPTYBASETRANSPOSEATT = 398,
     BASETRANSPOSEATT = 399,
     ELEMENTSSTART = 400,
     ELEMENTSEND = 401,
     CONSTANTELEMENTSSTART = 402,
     CONSTANTELEMENTSEND = 403,
     STARTVECTORSTART = 404,
     STARTVECTOREND = 405,
     NONZEROSSTART = 406,
     NONZEROSEND = 407,
     INDEXESSTART = 408,
     INDEXESEND = 409,
     VALUESSTART = 410,
     VALUESEND = 411,
     VARREFERENCEELEMENTSSTART = 412,
     VARREFERENCEELEMENTSEND = 413,
     LINEARELEMENTSSTART = 414,
     LINEARELEMENTSEND = 415,
     GENERALELEMENTSSTART = 416,
     GENERALELEMENTSEND = 417,
     CONREFERENCEELEMENTSSTART = 418,
     CONREFERENCEELEMENTSEND = 419,
     OBJREFERENCEELEMENTSSTART = 420,
     OBJREFERENCEELEMENTSEND = 421,
     PATTERNELEMENTSSTART = 422,
     PATTERNELEMENTSEND = 423,
     VARIDXSTART = 424,
     VARIDXEND = 425,
     TRANSFORMATIONSTART = 426,
     TRANSFORMATIONEND = 427,
     COLOFFSETSSTART = 428,
     COLOFFSETSEND = 429,
     ROWOFFSETSSTART = 430,
     ROWOFFSETSEND = 431,
     EMPTYROWMAJORATT = 432,
     ROWMAJORATT = 433,
     BLOCKROWIDXATT = 434,
     BLOCKCOLIDXATT = 435,
     DUMMY = 436,
     NONLINEAREXPRESSIONSSTART = 437,
     NONLINEAREXPRESSIONSEND = 438,
     NUMBEROFNONLINEAREXPRESSIONS = 439,
     NLSTART = 440,
     NLEND = 441,
     POWERSTART = 442,
     POWEREND = 443,
     PLUSSTART = 444,
     PLUSEND = 445,
     MINUSSTART = 446,
     MINUSEND = 447,
     DIVIDESTART = 448,
     DIVIDEEND = 449,
     LNSTART = 450,
     LNEND = 451,
     SQRTSTART = 452,
     SQRTEND = 453,
     SUMSTART = 454,
     SUMEND = 455,
     PRODUCTSTART = 456,
     PRODUCTEND = 457,
     EXPSTART = 458,
     EXPEND = 459,
     NEGATESTART = 460,
     NEGATEEND = 461,
     IFSTART = 462,
     IFEND = 463,
     SQUARESTART = 464,
     SQUAREEND = 465,
     COSSTART = 466,
     COSEND = 467,
     SINSTART = 468,
     SINEND = 469,
     VARIABLESTART = 470,
     VARIABLEEND = 471,
     ABSSTART = 472,
     ABSEND = 473,
     ERFSTART = 474,
     ERFEND = 475,
     MAXSTART = 476,
     MAXEND = 477,
     ALLDIFFSTART = 478,
     ALLDIFFEND = 479,
     MINSTART = 480,
     MINEND = 481,
     ESTART = 482,
     EEND = 483,
     PISTART = 484,
     PIEND = 485,
     TIMESSTART = 486,
     TIMESEND = 487,
     NUMBERSTART = 488,
     NUMBEREND = 489,
     MATRIXTRACESTART = 490,
     MATRIXTRACEEND = 491,
     MATRIXTOSCALARSTART = 492,
     MATRIXTOSCALAREND = 493,
     IDATT = 494,
     COEFATT = 495
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
#define TIMEDOMAINSTART 310
#define TIMEDOMAINEND 311
#define STAGESSTART 312
#define STAGESEND 313
#define STAGESTART 314
#define STAGEEND 315
#define NUMBEROFSTAGESATT 316
#define HORIZONATT 317
#define STARTATT 318
#define VARIABLESSTART 319
#define CONSTRAINTSSTART 320
#define OBJECTIVESSTART 321
#define VARIABLESEND 322
#define CONSTRAINTSEND 323
#define OBJECTIVESEND 324
#define NUMBEROFVARIABLESATT 325
#define NUMBEROFCONSTRAINTSATT 326
#define NUMBEROFOBJECTIVESATT 327
#define STARTIDXATT 328
#define VARSTART 329
#define VAREND 330
#define CONSTART 331
#define CONEND 332
#define OBJSTART 333
#define OBJEND 334
#define INTERVALSTART 335
#define INTERVALEND 336
#define HEADERSTART 337
#define HEADEREND 338
#define FILENAMESTART 339
#define FILENAMEEND 340
#define FILENAMEEMPTY 341
#define FILENAMESTARTANDEND 342
#define FILESOURCESTART 343
#define FILESOURCEEND 344
#define FILESOURCEEMPTY 345
#define FILESOURCESTARTANDEND 346
#define FILEDESCRIPTIONSTART 347
#define FILEDESCRIPTIONEND 348
#define FILEDESCRIPTIONEMPTY 349
#define FILEDESCRIPTIONSTARTANDEND 350
#define FILECREATORSTART 351
#define FILECREATOREND 352
#define FILECREATOREMPTY 353
#define FILECREATORSTARTANDEND 354
#define FILELICENCESTART 355
#define FILELICENCEEND 356
#define FILELICENCEEMPTY 357
#define FILELICENCESTARTANDEND 358
#define ENUMERATIONSTART 359
#define ENUMERATIONEND 360
#define NUMBEROFELATT 361
#define ITEMEMPTY 362
#define ITEMSTART 363
#define ITEMEND 364
#define ITEMSTARTANDEND 365
#define BASE64START 366
#define BASE64END 367
#define INCRATT 368
#define MULTATT 369
#define SIZEOFATT 370
#define ELSTART 371
#define ELEND 372
#define MATRIXSTART 373
#define MATRIXEND 374
#define BASEMATRIXEND 375
#define BASEMATRIXSTART 376
#define BLOCKSTART 377
#define BLOCKEND 378
#define BLOCKSSTART 379
#define BLOCKSEND 380
#define EMPTYSYMMETRYATT 381
#define SYMMETRYATT 382
#define EMPTYEXCLUDEATT 383
#define EXCLUDEATT 384
#define CONSTANTATT 385
#define NUMBEROFBLOCKSATT 386
#define NUMBEROFCOLUMNSATT 387
#define NUMBEROFROWSATT 388
#define NUMBEROFVARIDXATT 389
#define BASEMATRIXIDXATT 390
#define TARGETMATRIXFIRSTROWATT 391
#define TARGETMATRIXFIRSTCOLATT 392
#define BASEMATRIXSTARTROWATT 393
#define BASEMATRIXSTARTCOLATT 394
#define BASEMATRIXENDROWATT 395
#define BASEMATRIXENDCOLATT 396
#define SCALARMULTIPLIERATT 397
#define EMPTYBASETRANSPOSEATT 398
#define BASETRANSPOSEATT 399
#define ELEMENTSSTART 400
#define ELEMENTSEND 401
#define CONSTANTELEMENTSSTART 402
#define CONSTANTELEMENTSEND 403
#define STARTVECTORSTART 404
#define STARTVECTOREND 405
#define NONZEROSSTART 406
#define NONZEROSEND 407
#define INDEXESSTART 408
#define INDEXESEND 409
#define VALUESSTART 410
#define VALUESEND 411
#define VARREFERENCEELEMENTSSTART 412
#define VARREFERENCEELEMENTSEND 413
#define LINEARELEMENTSSTART 414
#define LINEARELEMENTSEND 415
#define GENERALELEMENTSSTART 416
#define GENERALELEMENTSEND 417
#define CONREFERENCEELEMENTSSTART 418
#define CONREFERENCEELEMENTSEND 419
#define OBJREFERENCEELEMENTSSTART 420
#define OBJREFERENCEELEMENTSEND 421
#define PATTERNELEMENTSSTART 422
#define PATTERNELEMENTSEND 423
#define VARIDXSTART 424
#define VARIDXEND 425
#define TRANSFORMATIONSTART 426
#define TRANSFORMATIONEND 427
#define COLOFFSETSSTART 428
#define COLOFFSETSEND 429
#define ROWOFFSETSSTART 430
#define ROWOFFSETSEND 431
#define EMPTYROWMAJORATT 432
#define ROWMAJORATT 433
#define BLOCKROWIDXATT 434
#define BLOCKCOLIDXATT 435
#define DUMMY 436
#define NONLINEAREXPRESSIONSSTART 437
#define NONLINEAREXPRESSIONSEND 438
#define NUMBEROFNONLINEAREXPRESSIONS 439
#define NLSTART 440
#define NLEND 441
#define POWERSTART 442
#define POWEREND 443
#define PLUSSTART 444
#define PLUSEND 445
#define MINUSSTART 446
#define MINUSEND 447
#define DIVIDESTART 448
#define DIVIDEEND 449
#define LNSTART 450
#define LNEND 451
#define SQRTSTART 452
#define SQRTEND 453
#define SUMSTART 454
#define SUMEND 455
#define PRODUCTSTART 456
#define PRODUCTEND 457
#define EXPSTART 458
#define EXPEND 459
#define NEGATESTART 460
#define NEGATEEND 461
#define IFSTART 462
#define IFEND 463
#define SQUARESTART 464
#define SQUAREEND 465
#define COSSTART 466
#define COSEND 467
#define SINSTART 468
#define SINEND 469
#define VARIABLESTART 470
#define VARIABLEEND 471
#define ABSSTART 472
#define ABSEND 473
#define ERFSTART 474
#define ERFEND 475
#define MAXSTART 476
#define MAXEND 477
#define ALLDIFFSTART 478
#define ALLDIFFEND 479
#define MINSTART 480
#define MINEND 481
#define ESTART 482
#define EEND 483
#define PISTART 484
#define PIEND 485
#define TIMESSTART 486
#define TIMESEND 487
#define NUMBERSTART 488
#define NUMBEREND 489
#define MATRIXTRACESTART 490
#define MATRIXTRACEEND 491
#define MATRIXTOSCALARSTART 492
#define MATRIXTOSCALAREND 493
#define IDATT 494
#define COEFATT 495




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
#define YYLAST   933

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  245
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  448
/* YYNRULES -- Number of rules.  */
#define YYNRULES  649
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1003

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   242,
     244,     2,     2,   243,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   241,     2,     2,     2,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    16,    18,    20,    21,    22,
      27,    33,    35,    38,    42,    44,    46,    49,    50,    53,
      55,    57,    59,    61,    66,    71,    76,    81,    82,    86,
      88,    90,    92,    94,    96,   100,   101,   104,   105,   109,
     111,   113,   115,   117,   119,   123,   124,   127,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
     153,   155,   157,   159,   163,   167,   171,   175,   179,   183,
     187,   191,   195,   199,   203,   207,   211,   215,   219,   223,
     224,   225,   228,   230,   231,   233,   237,   241,   243,   246,
     251,   253,   259,   261,   264,   265,   270,   271,   275,   277,
     281,   285,   286,   290,   291,   294,   296,   298,   303,   308,
     310,   314,   316,   319,   321,   324,   325,   330,   335,   337,
     340,   341,   345,   346,   349,   351,   353,   358,   363,   365,
     369,   371,   374,   376,   379,   380,   385,   390,   392,   395,
     396,   400,   401,   404,   406,   408,   413,   418,   420,   424,
     426,   429,   431,   434,   435,   440,   445,   447,   450,   451,
     456,   458,   461,   462,   465,   467,   469,   474,   479,   484,
     489,   494,   498,   502,   505,   506,   509,   511,   513,   515,
     517,   519,   521,   522,   525,   529,   531,   533,   534,   537,
     539,   541,   545,   549,   554,   556,   558,   561,   563,   567,
     572,   577,   578,   581,   585,   587,   588,   590,   594,   599,
     601,   603,   606,   608,   612,   616,   618,   622,   626,   630,
     632,   636,   640,   644,   646,   647,   649,   651,   653,   655,
     657,   661,   665,   669,   671,   673,   676,   678,   682,   685,
     686,   690,   692,   694,   695,   698,   700,   702,   704,   706,
     708,   710,   712,   714,   716,   721,   726,   731,   736,   741,
     746,   751,   753,   755,   757,   759,   763,   768,   771,   773,
     774,   777,   779,   781,   783,   787,   789,   790,   792,   794,
     796,   798,   802,   810,   811,   814,   816,   819,   823,   825,
     827,   829,   831,   833,   837,   839,   843,   845,   846,   850,
     852,   855,   859,   861,   863,   865,   867,   869,   873,   875,
     879,   881,   882,   885,   887,   890,   894,   896,   898,   900,
     902,   904,   908,   910,   914,   916,   918,   922,   925,   926,
     929,   931,   933,   935,   937,   941,   943,   944,   947,   949,
     951,   953,   955,   959,   960,   963,   967,   969,   971,   972,
     975,   977,   979,   984,   986,   988,   990,   994,   995,   998,
    1002,  1004,  1005,  1010,  1014,  1015,  1018,  1020,  1023,  1027,
    1029,  1031,  1033,  1035,  1037,  1041,  1043,  1047,  1049,  1051,
    1055,  1058,  1059,  1062,  1064,  1066,  1068,  1070,  1074,  1076,
    1077,  1080,  1082,  1084,  1086,  1088,  1092,  1093,  1096,  1099,
    1101,  1103,  1105,  1107,  1111,  1112,  1116,  1118,  1121,  1125,
    1127,  1129,  1131,  1133,  1135,  1139,  1141,  1145,  1147,  1148,
    1152,  1154,  1157,  1161,  1163,  1165,  1167,  1169,  1171,  1175,
    1177,  1181,  1183,  1184,  1189,  1191,  1192,  1194,  1196,  1198,
    1200,  1204,  1207,  1211,  1213,  1215,  1217,  1219,  1221,  1225,
    1227,  1231,  1233,  1237,  1239,  1241,  1245,  1247,  1249,  1253,
    1257,  1259,  1261,  1263,  1265,  1267,  1271,  1273,  1277,  1279,
    1281,  1283,  1285,  1287,  1291,  1293,  1294,  1297,  1301,  1303,
    1305,  1307,  1310,  1312,  1314,  1316,  1321,  1326,  1328,  1330,
    1333,  1335,  1339,  1342,  1347,  1352,  1357,  1362,  1363,  1368,
    1374,  1375,  1376,  1384,  1386,  1391,  1393,  1395,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,  1419,
    1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,
    1441,  1442,  1448,  1449,  1455,  1456,  1462,  1463,  1468,  1469,
    1475,  1476,  1482,  1483,  1488,  1489,  1492,  1493,  1498,  1499,
    1502,  1503,  1508,  1509,  1512,  1513,  1518,  1519,  1522,  1523,
    1528,  1529,  1532,  1533,  1538,  1539,  1544,  1545,  1550,  1551,
    1556,  1557,  1562,  1563,  1568,  1569,  1574,  1575,  1580,  1581,
    1588,  1589,  1593,  1595,  1598,  1599,  1603,  1605,  1608,  1609,
    1614,  1616,  1619,  1620,  1623,  1625,  1627,  1629,  1630,  1635,
    1636,  1641,  1646,  1647,  1652,  1654,  1655,  1660,  1663,  1664,
    1667,  1669,  1671,  1676,  1681,  1682,  1687,  1688,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1722,  1727,  1729,  1732,  1737,  1738,  1739,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     246,     0,    -1,   250,   596,   262,   269,   293,   294,   247,
     248,    -1,    14,    -1,    13,    -1,   249,    -1,    12,    -1,
      -1,    -1,    24,   251,   252,    25,    -1,    26,     3,     7,
       3,    11,    -1,   253,    -1,   252,   253,    -1,   254,   256,
     255,    -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,
     256,   257,    -1,   258,    -1,   259,    -1,   260,    -1,   261,
      -1,    19,     3,     7,     3,    -1,    20,     3,     7,     3,
      -1,   240,     3,   353,     3,    -1,    18,     3,     7,     3,
      -1,    -1,   263,   264,   265,    -1,    29,    -1,   351,    -1,
     266,    -1,   267,    -1,    10,    -1,    11,   268,    30,    -1,
      -1,   268,   385,    -1,    -1,   270,   271,   272,    -1,    32,
      -1,   352,    -1,   273,    -1,   274,    -1,    10,    -1,    11,
     275,    33,    -1,    -1,   275,   276,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   281,    -1,   282,    -1,   283,
      -1,   284,    -1,   285,    -1,   286,    -1,   287,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   270,
     271,   272,    -1,   270,   271,   272,    -1,   270,   271,   272,
      -1,   270,   271,   272,    -1,   270,   271,   272,    -1,   270,
     271,   272,    -1,   270,   271,   272,    -1,   270,   271,   272,
      -1,   270,   271,   272,    -1,   270,   271,   272,    -1,   270,
     271,   272,    -1,   270,   271,   272,    -1,   270,   271,   272,
      -1,   270,   271,   272,    -1,   270,   271,   272,    -1,   270,
     271,   272,    -1,    -1,    -1,   295,   296,    -1,    55,    -1,
      -1,   297,    -1,    11,   298,    56,    -1,    11,   343,    56,
      -1,    10,    -1,    11,    56,    -1,   299,   300,   301,    58,
      -1,    57,    -1,    61,     3,     7,     3,    11,    -1,   302,
      -1,   301,   302,    -1,    -1,   303,    59,   304,   305,    -1,
      -1,    21,     4,     3,    -1,    10,    -1,    11,   306,    60,
      -1,   307,   319,   331,    -1,    -1,    64,   308,   312,    -1,
      -1,   308,   309,    -1,   310,    -1,   311,    -1,    70,     3,
       7,     3,    -1,    73,     3,     7,     3,    -1,   313,    -1,
      11,   314,    67,    -1,    10,    -1,    11,    67,    -1,   315,
      -1,   314,   315,    -1,    -1,   316,    74,   317,   318,    -1,
      18,     3,     7,     3,    -1,    10,    -1,    11,    75,    -1,
      -1,    65,   320,   324,    -1,    -1,   320,   321,    -1,   322,
      -1,   323,    -1,    71,     3,     7,     3,    -1,    73,     3,
       7,     3,    -1,   325,    -1,    11,   326,    68,    -1,    10,
      -1,    11,    68,    -1,   327,    -1,   326,   327,    -1,    -1,
     328,    76,   329,   330,    -1,    18,     3,     7,     3,    -1,
      10,    -1,    11,    77,    -1,    -1,    66,   332,   336,    -1,
      -1,   332,   333,    -1,   334,    -1,   335,    -1,    72,     3,
       7,     3,    -1,    73,     3,     7,     3,    -1,   337,    -1,
      11,   338,    69,    -1,    10,    -1,    11,    69,    -1,   339,
      -1,   338,   339,    -1,    -1,   340,    78,   341,   342,    -1,
      18,     3,     7,     3,    -1,    10,    -1,    11,    79,    -1,
      -1,   344,    80,   346,   345,    -1,    10,    -1,    11,    81,
      -1,    -1,   346,   347,    -1,   348,    -1,   349,    -1,    62,
       3,   353,     3,    -1,    63,     3,   353,     3,    -1,   106,
     354,     7,   354,    -1,    31,     3,     7,     3,    -1,    34,
       3,     7,     3,    -1,   355,     7,   355,    -1,   355,     8,
     355,    -1,   355,     3,    -1,    -1,   355,   356,    -1,   241,
      -1,   242,    -1,   243,    -1,   244,    -1,   358,    -1,   365,
      -1,    -1,   358,   359,    -1,   360,   361,   364,    -1,   116,
      -1,   362,    -1,    -1,   362,   363,    -1,   371,    -1,   370,
      -1,    11,     7,   117,    -1,   111,   366,   367,    -1,   115,
     354,     7,   354,    -1,   368,    -1,   369,    -1,    11,   112,
      -1,    10,    -1,    11,     5,   112,    -1,   113,   354,     7,
     354,    -1,   114,   354,     7,   354,    -1,    -1,   372,   373,
      -1,   374,   375,   376,    -1,   116,    -1,    -1,   371,    -1,
      11,   353,   117,    -1,   115,   354,     7,   354,    -1,   368,
      -1,   369,    -1,    11,   112,    -1,    10,    -1,    11,     5,
     112,    -1,   378,   379,   380,    -1,   350,    -1,   153,   358,
     154,    -1,   155,   372,   156,    -1,   382,   383,   384,    -1,
     350,    -1,   153,   358,   154,    -1,   155,   358,   156,    -1,
     386,   387,   391,    -1,   118,    -1,    -1,   388,    -1,   594,
      -1,   593,    -1,   389,    -1,   390,    -1,   127,     4,     3,
      -1,    21,     4,     3,    -1,    22,     4,     3,    -1,   392,
      -1,   393,    -1,    11,   119,    -1,    10,    -1,    11,   394,
     119,    -1,   395,   413,    -1,    -1,   396,   397,   412,    -1,
     121,    -1,   398,    -1,    -1,   398,   399,    -1,   400,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   407,    -1,   411,    -1,   135,     3,     7,     3,
      -1,   136,     3,     7,     3,    -1,   137,     3,     7,     3,
      -1,   138,     3,     7,     3,    -1,   139,     3,     7,     3,
      -1,   140,     3,     7,     3,    -1,   141,     3,     7,     3,
      -1,   408,    -1,   409,    -1,   410,    -1,   143,    -1,   144,
       4,   354,    -1,   142,     3,   353,     3,    -1,    11,   120,
      -1,    10,    -1,    -1,   413,   414,    -1,   415,    -1,   559,
      -1,   562,    -1,   416,   417,   421,    -1,   145,    -1,    -1,
     418,    -1,   419,    -1,   420,    -1,   177,    -1,   178,     4,
     354,    -1,   422,   434,   446,   487,   519,   531,   543,    -1,
      -1,   423,   424,    -1,   147,    -1,   425,   432,    -1,   426,
     427,   428,    -1,   149,    -1,   350,    -1,   429,    -1,   430,
      -1,    10,    -1,    11,   431,   150,    -1,   357,    -1,   433,
     377,   152,    -1,   151,    -1,    -1,   435,   436,   158,    -1,
     157,    -1,   437,   444,    -1,   438,   439,   440,    -1,   149,
      -1,   350,    -1,   441,    -1,   442,    -1,    10,    -1,    11,
     443,   150,    -1,   357,    -1,   445,   381,   152,    -1,   151,
      -1,    -1,   447,   448,    -1,   159,    -1,   449,   456,    -1,
     450,   451,   452,    -1,   149,    -1,   350,    -1,   453,    -1,
     454,    -1,    10,    -1,    11,   455,   150,    -1,   357,    -1,
     457,   458,   459,    -1,   151,    -1,   350,    -1,    11,   460,
     152,    -1,   461,   467,    -1,    -1,   462,   463,    -1,   153,
      -1,   464,    -1,   465,    -1,    10,    -1,    11,   466,   154,
      -1,   357,    -1,    -1,   468,   469,    -1,   155,    -1,   470,
      -1,   471,    -1,    10,    -1,    11,   472,   156,    -1,    -1,
     472,   473,    -1,   474,   475,   479,    -1,   116,    -1,   476,
      -1,    -1,   476,   477,    -1,   595,    -1,   478,    -1,   130,
       3,   353,     3,    -1,   480,    -1,   481,    -1,    10,    -1,
      11,   482,   117,    -1,    -1,   482,   483,    -1,   484,   485,
     486,    -1,   169,    -1,    -1,   240,     3,   353,     3,    -1,
      11,     7,   170,    -1,    -1,   488,   489,    -1,   161,    -1,
     490,   497,    -1,   491,   492,   493,    -1,   149,    -1,   350,
      -1,   494,    -1,   495,    -1,    10,    -1,    11,   496,   150,
      -1,   357,    -1,   498,   499,   500,    -1,   151,    -1,   350,
      -1,    11,   501,   152,    -1,   502,   508,    -1,    -1,   503,
     504,    -1,   153,    -1,   505,    -1,   506,    -1,    10,    -1,
      11,   507,   154,    -1,   357,    -1,    -1,   509,   510,    -1,
     155,    -1,   511,    -1,   512,    -1,    10,    -1,    11,   513,
     156,    -1,    -1,   513,   514,    -1,   515,   516,    -1,   116,
      -1,   517,    -1,   518,    -1,    10,    -1,    11,   602,   117,
      -1,    -1,   520,   521,   164,    -1,   163,    -1,   522,   529,
      -1,   523,   524,   525,    -1,   149,    -1,   350,    -1,   526,
      -1,   527,    -1,    10,    -1,    11,   528,   150,    -1,   357,
      -1,   530,   381,   152,    -1,   151,    -1,    -1,   532,   533,
     166,    -1,   165,    -1,   534,   541,    -1,   535,   536,   537,
      -1,   149,    -1,   350,    -1,   538,    -1,   539,    -1,    10,
      -1,    11,   540,   150,    -1,   357,    -1,   542,   381,   152,
      -1,   151,    -1,    -1,   544,   545,   549,   168,    -1,   167,
      -1,    -1,   546,    -1,   547,    -1,   548,    -1,   128,    -1,
     129,     4,   354,    -1,   550,   557,    -1,   551,   552,   553,
      -1,   149,    -1,   350,    -1,   554,    -1,   555,    -1,    10,
      -1,    11,   556,   150,    -1,   357,    -1,   558,   381,   152,
      -1,   151,    -1,   560,   675,   561,    -1,   171,    -1,   172,
      -1,   563,   564,   565,    -1,   124,    -1,   592,    -1,   566,
     573,   580,    -1,   567,   568,   569,    -1,   173,    -1,   350,
      -1,   570,    -1,   571,    -1,    10,    -1,    11,   572,   174,
      -1,   357,    -1,   574,   575,   576,    -1,   175,    -1,   350,
      -1,   577,    -1,   578,    -1,    10,    -1,    11,   579,   176,
      -1,   357,    -1,    -1,   580,   581,    -1,   582,   583,   588,
      -1,   122,    -1,   584,    -1,   585,    -1,   584,   585,    -1,
     586,    -1,   587,    -1,   388,    -1,   179,   354,     7,   354,
      -1,   180,   354,     7,   354,    -1,   589,    -1,   590,    -1,
      11,   123,    -1,    10,    -1,    11,   591,   123,    -1,   395,
     413,    -1,   131,   354,     7,   354,    -1,   132,   354,     7,
     354,    -1,   133,   354,     7,   354,    -1,   134,   354,     7,
     354,    -1,    -1,   182,   597,   598,   183,    -1,   184,     3,
       7,     3,    11,    -1,    -1,    -1,   598,   600,   601,    11,
     602,   599,   186,    -1,   185,    -1,    18,     3,     7,     3,
      -1,   654,    -1,   664,    -1,   603,    -1,   605,    -1,   615,
      -1,   607,    -1,   609,    -1,   611,    -1,   613,    -1,   627,
      -1,   630,    -1,   632,    -1,   634,    -1,   638,    -1,   636,
      -1,   640,    -1,   646,    -1,   642,    -1,   644,    -1,   621,
      -1,   624,    -1,   648,    -1,   651,    -1,   618,    -1,   672,
      -1,    -1,   231,   604,   602,   602,   232,    -1,    -1,   189,
     606,   602,   602,   190,    -1,    -1,   191,   608,   602,   602,
     192,    -1,    -1,   205,   610,   602,   206,    -1,    -1,   193,
     612,   602,   602,   194,    -1,    -1,   187,   614,   602,   602,
     188,    -1,    -1,   199,   616,   617,   200,    -1,    -1,   617,
     602,    -1,    -1,   223,   619,   620,   224,    -1,    -1,   620,
     602,    -1,    -1,   221,   622,   623,   222,    -1,    -1,   623,
     602,    -1,    -1,   225,   625,   626,   226,    -1,    -1,   626,
     602,    -1,    -1,   201,   628,   629,   202,    -1,    -1,   629,
     602,    -1,    -1,   195,   631,   602,   196,    -1,    -1,   197,
     633,   602,   198,    -1,    -1,   209,   635,   602,   210,    -1,
      -1,   211,   637,   602,   212,    -1,    -1,   213,   639,   602,
     214,    -1,    -1,   203,   641,   602,   204,    -1,    -1,   217,
     643,   602,   218,    -1,    -1,   219,   645,   602,   220,    -1,
      -1,   207,   647,   602,   602,   602,   208,    -1,    -1,   227,
     649,   650,    -1,    10,    -1,    11,   228,    -1,    -1,   229,
     652,   653,    -1,    10,    -1,    11,   230,    -1,    -1,   233,
     655,   657,   656,    -1,    10,    -1,    11,   234,    -1,    -1,
     657,   658,    -1,   659,    -1,   663,    -1,   661,    -1,    -1,
      22,     4,   660,     3,    -1,    -1,   239,     4,   662,     3,
      -1,    23,     3,   353,     3,    -1,    -1,   215,   665,   668,
     666,    -1,    10,    -1,    -1,    11,   602,   667,   216,    -1,
      11,   216,    -1,    -1,   668,   669,    -1,   670,    -1,   671,
      -1,   240,     3,   353,     3,    -1,    18,     3,     7,     3,
      -1,    -1,   235,   673,   675,   236,    -1,    -1,   237,   674,
     675,   238,    -1,   676,    -1,   680,    -1,   681,    -1,   682,
      -1,   683,    -1,   684,    -1,   685,    -1,   686,    -1,   687,
      -1,   688,    -1,   689,    -1,   690,    -1,   691,    -1,   692,
      -1,    -1,   118,   677,   679,   678,    -1,    10,    -1,    11,
     119,    -1,    18,     3,     7,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   357,   357,   360,   361,   363,   372,   373,   376,   377,
     382,   389,   390,   392,   405,   412,   413,   416,   417,   421,
     424,   427,   430,   436,   443,   450,   458,   463,   463,   465,
     467,   469,   469,   471,   473,   475,   475,   478,   478,   480,
     482,   484,   484,   486,   488,   490,   490,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   547,
     552,   552,   554,   556,   557,   558,   559,   561,   562,   564,
     615,   617,   631,   632,   634,   634,   658,   659,   662,   663,
     665,   667,   668,   672,   673,   675,   676,   678,   694,   702,
     709,   714,   715,   717,   718,   720,   720,   723,   732,   733,
     735,   736,   740,   741,   743,   744,   746,   762,   770,   777,
     782,   783,   785,   786,   788,   788,   791,   800,   801,   803,
     813,   817,   818,   820,   821,   823,   839,   847,   854,   859,
     860,   862,   863,   865,   865,   868,   877,   878,   883,   883,
     891,   892,   894,   895,   897,   901,   906,   910,   915,   924,
     935,   980,   981,   988,   990,   990,   992,   993,   994,   995,
    1160,  1168,  1170,  1170,  1172,  1174,  1183,  1185,  1185,  1187,
    1187,  1189,  1205,  1207,  1212,  1212,  1214,  1214,  1217,  1243,
    1251,  1276,  1276,  1278,  1280,  1288,  1288,  1290,  1308,  1313,
    1313,  1315,  1315,  1317,  1348,  1352,  1360,  1362,  1370,  1374,
    1382,  1384,  1390,  1392,  1397,  1398,  1399,  1400,  1401,  1402,
    1411,  1421,  1430,  1439,  1439,  1441,  1441,  1443,  1445,  1447,
    1447,  1449,  1451,  1453,  1453,  1456,  1457,  1458,  1459,  1460,
    1461,  1462,  1463,  1464,  1466,  1476,  1486,  1496,  1506,  1516,
    1526,  1536,  1543,  1543,  1545,  1550,  1559,  1567,  1567,  1569,
    1569,  1571,  1571,  1571,  1573,  1575,  1577,  1577,  1579,  1579,
    1581,  1586,  1595,  1598,  1598,  1600,  1602,  1604,  1615,  1621,
    1628,  1628,  1630,  1632,  1634,  1636,  1649,  1655,  1655,  1657,
    1659,  1661,  1672,  1678,  1685,  1685,  1687,  1689,  1691,  1693,
    1706,  1712,  1712,  1714,  1716,  1718,  1729,  1735,  1742,  1742,
    1744,  1746,  1748,  1750,  1761,  1767,  1776,  1778,  1780,  1781,
    1794,  1801,  1801,  1803,  1805,  1807,  1809,  1810,  1812,  1818,
    1818,  1820,  1822,  1824,  1824,  1826,  1829,  1835,  1837,  1837,
    1840,  1841,  1843,  1847,  1847,  1849,  1851,  1853,  1853,  1856,
    1858,  1864,  1864,  1868,  1872,  1872,  1874,  1876,  1878,  1889,
    1895,  1902,  1902,  1904,  1906,  1908,  1910,  1921,  1927,  1936,
    1938,  1940,  1941,  1954,  1961,  1961,  1963,  1965,  1967,  1969,
    1970,  1972,  1978,  1978,  1980,  1982,  1984,  1984,  1986,  1988,
    1994,  1994,  1996,  1998,  2001,  2001,  2003,  2005,  2007,  2018,
    2024,  2031,  2031,  2033,  2035,  2037,  2039,  2052,  2058,  2058,
    2060,  2062,  2064,  2075,  2081,  2088,  2088,  2090,  2092,  2094,
    2096,  2109,  2115,  2115,  2117,  2119,  2119,  2121,  2121,  2123,
    2128,  2137,  2139,  2150,  2156,  2163,  2163,  2165,  2167,  2169,
    2171,  2184,  2190,  2192,  2194,  2196,  2198,  2200,  2202,  2204,
    2215,  2221,  2228,  2228,  2230,  2232,  2234,  2236,  2247,  2253,
    2260,  2260,  2262,  2264,  2266,  2268,  2268,  2270,  2272,  2274,
    2276,  2276,  2279,  2280,  2281,  2288,  2297,  2306,  2306,  2308,
    2308,  2310,  2312,  2314,  2323,  2332,  2341,  2381,  2382,  2386,
    2395,  2397,  2396,  2404,  2409,  2423,  2424,  2425,  2426,  2427,
    2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,  2446,  2448,
    2452,  2452,  2457,  2457,  2462,  2462,  2467,  2467,  2472,  2472,
    2477,  2477,  2482,  2482,  2492,  2493,  2498,  2498,  2510,  2511,
    2514,  2514,  2525,  2526,  2528,  2528,  2539,  2540,  2543,  2543,
    2553,  2554,  2557,  2557,  2562,  2562,  2567,  2567,  2572,  2572,
    2577,  2577,  2582,  2582,  2587,  2587,  2594,  2594,  2600,  2600,
    2607,  2607,  2610,  2611,  2613,  2613,  2616,  2617,  2619,  2619,
    2624,  2625,  2627,  2628,  2630,  2632,  2634,  2638,  2638,  2642,
    2642,  2647,  2657,  2657,  2662,  2663,  2663,  2667,  2669,  2670,
    2672,  2674,  2678,  2687,  2694,  2694,  2699,  2699,  2704,  2705,
    2706,  2707,  2708,  2709,  2710,  2711,  2712,  2713,  2714,  2715,
    2716,  2717,  2720,  2719,  2725,  2726,  2728,  2737,  2738,  2739,
    2740,  2741,  2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749
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
  "MATRIXTOSCALAREND", "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'",
  "'\\n'", "$accept", "osildoc", "theInstanceEnd", "osilEnd", "osilEnding",
  "quadraticCoefficients", "quadnumberatt", "qTermlist", "qterm",
  "qtermStart", "qtermend", "anotherqTermATT", "qtermatt",
  "qtermidxOneatt", "qtermidxTwoatt", "qtermcoefatt", "qtermidxatt",
  "matrices", "matricesStart", "matricesAttributes", "matricesContent",
  "matricesEmpty", "matricesLaden", "matrixList", "cones", "conesStart",
  "conesAttributes", "conesContent", "conesEmpty", "conesLaden",
  "coneList", "cone", "nonpositiveCone", "generalOrthantCone",
  "quadraticCone", "rotatedQuadraticCone", "normedCone",
  "semidefiniteCone", "copositiveMatricesCone",
  "completelyPositiveMatricesCone", "hyperbolicityCone",
  "nonnegativePolynomialsCone", "sumOfSquaresPolynomialsCone",
  "momentsCone", "productCone", "intersectionCone", "dualCone",
  "polarCone", "matrixProgramming", "timeDomain", "timedomainstart",
  "timedomain", "timedomainend", "stages", "stagesstart",
  "numberofstagesatt", "stagelist", "stage", "$@1", "stagenameATT",
  "stageend", "stagecontent", "stagevariables", "anotherstagevarATT",
  "stagevaratt", "numberofstagevariablesatt", "stagevarstartidxATT",
  "restofstagevariables", "emptyvarlist", "stagevarlist", "stagevar",
  "$@2", "stagevaridxATT", "stagevarend", "stageconstraints",
  "anotherstageconATT", "stageconatt", "numberofstageconstraintsatt",
  "stageconstartidxATT", "restofstageconstraints", "emptyconlist",
  "stageconlist", "stagecon", "$@3", "stageconidxATT", "stageconend",
  "stageobjectives", "anotherstageobjATT", "stageobjatt",
  "numberofstageobjectivesatt", "stageobjstartidxATT",
  "restofstageobjectives", "emptyobjlist", "stageobjlist", "stageobj",
  "$@4", "stageobjidxATT", "stageobjend", "interval", "$@5", "intervalend",
  "anotherIntervalATT", "intervalatt", "intervalhorizonatt",
  "intervalstartatt", "numberOfElAttribute", "numberOfMatricesATT",
  "numberOfConesATT", "aNumber", "quote", "xmlWhiteSpace",
  "xmlWhiteSpaceChar", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute",
  "osglDblVectorElArray", "osglDblVectorEl", "osglDblVectorElStart",
  "osglDblVectorElAttributes", "osglDblVectorElContent",
  "osglSparseVector", "osglSparseVectorNumberOfElATT",
  "osglSparseVectorIndexes", "osglSparseVectorValues",
  "osglSparseIntVector", "osglSparseIntVectorNumberOfElATT",
  "osglSparseIntVectorIndexes", "osglSparseIntVectorValues", "osglMatrix",
  "matrixStart", "matrixAttributes", "symmetryAttribute",
  "matrixNameAttribute", "matrixTypeAttribute", "matrixContent",
  "matrixEmpty", "matrixLaden", "matrixBody", "baseMatrix",
  "baseMatrixStart", "baseMatrixAttributes", "baseMatrixAttList",
  "baseMatrixAtt", "baseMatrixIdxAttribute",
  "targetMatrixFirstRowAttribute", "targetMatrixFirstColAttribute",
  "baseMatrixStartRowAttribute", "baseMatrixStartColAttribute",
  "baseMatrixEndRowAttribute", "baseMatrixEndColAttribute",
  "baseTransposeAttribute", "baseTransposeAtt", "baseTransposeAttEmpty",
  "baseTransposeAttContent", "scalarMultiplierAttribute", "baseMatrixEnd",
  "matrixConstructorList", "matrixConstructor", "matrixElements",
  "matrixElementsStart", "matrixElementsAttributes", "rowMajorAtt",
  "rowMajorAttEmpty", "rowMajorAttContent", "matrixElementsContent",
  "constantElements", "constantElementsStart", "constantElementsContent",
  "constantElementsStartVector", "constantElementsStartVectorStart",
  "constantElementsStartVectorNumberOfElATT",
  "constantElementsStartVectorContent", "constantElementsStartVectorEmpty",
  "constantElementsStartVectorLaden", "constantElementsStartVectorBody",
  "constantElementsNonzeros", "constantElementsNonzerosStart",
  "varReferenceElements", "varReferenceElementsStart",
  "varReferenceElementsContent", "varReferenceElementsStartVector",
  "varReferenceElementsStartVectorStart",
  "varReferenceElementsStartVectorNumberOfElATT",
  "varReferenceElementsStartVectorContent",
  "varReferenceElementsStartVectorEmpty",
  "varReferenceElementsStartVectorLaden",
  "varReferenceElementsStartVectorBody", "varReferenceElementsNonzeros",
  "varReferenceElementsNonzerosStart", "linearElements",
  "linearElementsStart", "linearElementsContent",
  "linearElementsStartVector", "linearElementsStartVectorStart",
  "linearElementsStartVectorNumberOfElATT",
  "linearElementsStartVectorContent", "linearElementsStartVectorEmpty",
  "linearElementsStartVectorLaden", "linearElementsStartVectorBody",
  "linearElementsNonzeros", "linearElementsNonzerosStart",
  "linearElementsNonzerosNumberOfElATT", "linearElementsNonzerosContent",
  "linearElementsNonzerosBody", "linearElementsNonzerosIndexes",
  "linearElementsNonzerosIndexesStart",
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
  "constantAttribute", "linearElementsNonzerosElContent",
  "linearElementsNonzerosElEmpty", "linearElementsNonzerosElLaden",
  "linearElementsNonzerosVarIdxList", "linearElementsNonzerosVarIdx",
  "linearElementsNonzerosVarIdxStart",
  "linearElementsNonzerosVarIdxCoefATT",
  "linearElementsNonzerosVarIdxContent", "generalElements",
  "generalElementsStart", "generalElementsContent",
  "generalElementsStartVector", "generalElementsStartVectorStart",
  "generalElementsStartVectorNumberOfElATT",
  "generalElementsStartVectorContent", "generalElementsStartVectorEmpty",
  "generalElementsStartVectorLaden", "generalElementsStartVectorBody",
  "generalElementsNonzeros", "generalElementsNonzerosStart",
  "generalElementsNonzerosNumberOfElATT", "generalElementsNonzerosContent",
  "generalElementsNonzerosBody", "generalElementsNonzerosIndexes",
  "generalElementsNonzerosIndexesStart",
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
  "conReferenceElementsStartVectorNumberOfElATT",
  "conReferenceElementsStartVectorContent",
  "conReferenceElementsStartVectorEmpty",
  "conReferenceElementsStartVectorLaden",
  "conReferenceElementsStartVectorBody", "conReferenceElementsNonzeros",
  "conReferenceElementsNonzerosStart", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsContent",
  "objReferenceElementsStartVector",
  "objReferenceElementsStartVectorStart",
  "objReferenceElementsStartVectorNumberOfElATT",
  "objReferenceElementsStartVectorContent",
  "objReferenceElementsStartVectorEmpty",
  "objReferenceElementsStartVectorLaden",
  "objReferenceElementsStartVectorBody", "objReferenceElementsNonzeros",
  "objReferenceElementsNonzerosStart", "patternElements",
  "patternElementsStart", "patternElementsAttributes", "excludeIfSetAtt",
  "excludeIfSetAttEmpty", "excludeIfSetAttContent",
  "patternElementsContent", "patternElementsStartVector",
  "patternElementsStartVectorStart",
  "patternElementsStartVectorNumberOfElATT",
  "patternElementsStartVectorContent", "patternElementsStartVectorEmpty",
  "patternElementsStartVectorLaden", "patternElementsStartVectorBody",
  "patternElementsNonzeros", "patternElementsNonzerosStart",
  "matrixTransformation", "matrixTransformationStart",
  "matrixTransformationEnd", "matrixBlocks", "matrixBlocksStart",
  "matrixBlocksAttributes", "matrixBlocksContent", "colOffsets",
  "colOffsetsStart", "colOffsetsNumberOfElATT", "colOffsetsContent",
  "colOffsetsEmpty", "colOffsetsLaden", "colOffsetsBody", "rowOffsets",
  "rowOffsetsStart", "rowOffsetsNumberOfElATT", "rowOffsetsContent",
  "rowOffsetsEmpty", "rowOffsetsLaden", "rowOffsetsBody", "blockList",
  "matrixBlock", "matrixBlockStart", "matrixBlockAttributes",
  "matrixBlockAttList", "matrixBlockAtt", "blockRowIdxAtt",
  "blockColIdxAtt", "matrixBlockContent", "blockEmpty", "blockLaden",
  "blockBody", "numberOfBlocksAttribute", "numberOfColumnsAttribute",
  "numberOfRowsAttribute", "numberOfVarIdxAttribute",
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
  "matrixreferenceend", "matrixIdxATT", "matrixDiagonal", "matrixDotTimes",
  "matrixIdentity", "matrixInverse", "matrixLowerTriangle",
  "matrixUpperTriangle", "matrixMerge", "matrixMinus", "matrixPlus",
  "matrixTimes", "matrixScalarTimes", "matrixSubMatrixAt",
  "matrixTranspose", 0
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
     495,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   245,   246,   247,   247,   248,   249,   249,   250,   250,
     251,   252,   252,   253,   254,   255,   255,   256,   256,   257,
     257,   257,   257,   258,   259,   260,   261,   262,   262,   263,
     264,   265,   265,   266,   267,   268,   268,   269,   269,   270,
     271,   272,   272,   273,   274,   275,   275,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   294,   295,   296,   296,   296,   296,   297,   297,   298,
     299,   300,   301,   301,   303,   302,   304,   304,   305,   305,
     306,   307,   307,   308,   308,   309,   309,   310,   311,   312,
     312,   313,   313,   314,   314,   316,   315,   317,   318,   318,
     319,   319,   320,   320,   321,   321,   322,   323,   324,   324,
     325,   325,   326,   326,   328,   327,   329,   330,   330,   331,
     331,   332,   332,   333,   333,   334,   335,   336,   336,   337,
     337,   338,   338,   340,   339,   341,   342,   342,   344,   343,
     345,   345,   346,   346,   347,   347,   348,   349,   350,   351,
     352,   353,   353,   354,   355,   355,   356,   356,   356,   356,
     357,   357,   358,   358,   359,   360,   361,   362,   362,   363,
     363,   364,   365,   366,   367,   367,   368,   368,   369,   370,
     371,   372,   372,   373,   374,   375,   375,   376,   366,   367,
     367,   368,   368,   369,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   387,   387,   387,   387,   387,
     388,   389,   390,   391,   391,   392,   392,   393,   394,   395,
     395,   396,   397,   398,   398,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   408,   409,   410,   411,   412,   412,   413,
     413,   414,   414,   414,   415,   416,   417,   417,   418,   418,
     419,   420,   421,   422,   422,   423,   424,   425,   426,   427,
     428,   428,   429,   430,   431,   432,   433,   434,   434,   435,
     436,   437,   438,   439,   440,   440,   441,   442,   443,   444,
     445,   446,   446,   447,   448,   449,   450,   451,   452,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   461,
     462,   463,   463,   464,   465,   466,   467,   467,   468,   469,
     469,   470,   471,   472,   472,   473,   474,   475,   476,   476,
     477,   477,   478,   479,   479,   480,   481,   482,   482,   483,
     484,   485,   485,   486,   487,   487,   488,   489,   490,   491,
     492,   493,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   502,   503,   504,   504,   505,   506,   507,   508,
     508,   509,   510,   510,   511,   512,   513,   513,   514,   515,
     516,   516,   517,   518,   519,   519,   520,   521,   522,   523,
     524,   525,   525,   526,   527,   528,   529,   530,   531,   531,
     532,   533,   534,   535,   536,   537,   537,   538,   539,   540,
     541,   542,   543,   543,   544,   545,   545,   546,   546,   547,
     548,   549,   550,   551,   552,   553,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   569,   570,   571,   572,   573,   574,   575,
     576,   576,   577,   578,   579,   580,   580,   581,   582,   583,
     584,   584,   585,   585,   585,   586,   587,   588,   588,   589,
     589,   590,   591,   592,   593,   594,   595,   596,   596,   597,
     598,   599,   598,   600,   601,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   602,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   602,   602,   602,   602,   602,   602,
     604,   603,   606,   605,   608,   607,   610,   609,   612,   611,
     614,   613,   616,   615,   617,   617,   619,   618,   620,   620,
     622,   621,   623,   623,   625,   624,   626,   626,   628,   627,
     629,   629,   631,   630,   633,   632,   635,   634,   637,   636,
     639,   638,   641,   640,   643,   642,   645,   644,   647,   646,
     649,   648,   650,   650,   652,   651,   653,   653,   655,   654,
     656,   656,   657,   657,   658,   658,   658,   660,   659,   662,
     661,   663,   665,   664,   666,   667,   666,   666,   668,   668,
     669,   669,   670,   671,   673,   672,   674,   672,   675,   675,
     675,   675,   675,   675,   675,   675,   675,   675,   675,   675,
     675,   675,   677,   676,   678,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     0,     0,     4,
       5,     1,     2,     3,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     4,     4,     4,     4,     0,     3,     1,
       1,     1,     1,     1,     3,     0,     2,     0,     3,     1,
       1,     1,     1,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       0,     2,     1,     0,     1,     3,     3,     1,     2,     4,
       1,     5,     1,     2,     0,     4,     0,     3,     1,     3,
       3,     0,     3,     0,     2,     1,     1,     4,     4,     1,
       3,     1,     2,     1,     2,     0,     4,     4,     1,     2,
       0,     3,     0,     2,     1,     1,     4,     4,     1,     3,
       1,     2,     1,     2,     0,     4,     4,     1,     2,     0,
       3,     0,     2,     1,     1,     4,     4,     1,     3,     1,
       2,     1,     2,     0,     4,     4,     1,     2,     0,     4,
       1,     2,     0,     2,     1,     1,     4,     4,     4,     4,
       4,     3,     3,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     4,     1,     1,     2,     1,     3,     4,
       4,     0,     2,     3,     1,     0,     1,     3,     4,     1,
       1,     2,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     2,     1,     3,     2,     0,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     1,     1,     1,     1,     3,     4,     2,     1,     0,
       2,     1,     1,     1,     3,     1,     0,     1,     1,     1,
       1,     3,     7,     0,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     0,     3,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     0,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     4,     1,     1,     1,     3,     0,     2,     3,
       1,     0,     4,     3,     0,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     0,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     0,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     0,     4,     1,     0,     1,     1,     1,     1,
       3,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     3,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       1,     2,     1,     1,     1,     4,     4,     1,     1,     2,
       1,     3,     2,     4,     4,     4,     4,     0,     4,     5,
       0,     0,     7,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     0,     5,     0,     4,     0,     5,
       0,     5,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     6,
       0,     3,     1,     2,     0,     3,     1,     2,     0,     4,
       1,     2,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     4,     0,     4,     1,     0,     4,     2,     0,     2,
       1,     1,     4,     4,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     2,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   497,     0,     0,     1,     0,    27,     0,
      14,     0,    11,    17,     0,   500,    29,    37,     0,     0,
       9,    12,     0,     0,     0,    39,    79,     0,     0,     0,
      30,     0,    15,     0,     0,     0,     0,     0,    13,    18,
      19,    20,    21,    22,     0,   498,   503,     0,    80,     0,
       0,    40,     0,    33,    35,    28,    31,    32,    10,    16,
       0,     0,     0,   174,     0,     0,     0,    82,     0,    83,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,     4,     3,     7,    87,
     158,    81,    84,     0,     0,   169,    34,   223,    36,   224,
      26,    23,    24,    25,   174,   174,   176,   177,   178,   179,
     175,     0,   540,   532,   534,   538,   562,   564,   542,   558,
     572,   536,   578,   566,   568,   570,   602,   574,   576,   550,
     546,   554,   580,   584,   530,   588,   614,   616,   501,   507,
     508,   510,   511,   512,   513,   509,   528,   524,   525,   514,
     515,   516,   517,   519,   518,   520,   522,   523,   521,   526,
     527,   505,   506,   529,     6,     2,     5,    88,    90,     0,
       0,     0,     0,   170,    44,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,   174,   174,     0,   225,
     228,   229,   227,   226,   171,   172,   504,     0,     0,     0,
       0,     0,     0,   544,   560,     0,     0,     0,     0,     0,
       0,   608,     0,     0,   552,   548,   556,     0,     0,     0,
     592,   637,   637,     0,    85,     0,    94,    86,   162,     0,
       0,     0,     0,     0,     0,     0,   236,   239,   222,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   582,     0,   581,   586,     0,   585,     0,     0,   632,
       0,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,     0,   502,     0,    94,    92,
       0,     0,    63,   231,   232,   230,   174,   173,   174,   235,
     241,     0,   269,   243,     0,     0,     0,     0,   563,   565,
     543,   545,   559,   561,   573,   537,     0,   567,   569,   571,
     604,     0,     0,     0,   603,   609,   610,   611,   575,   577,
     551,   553,   547,   549,   555,   557,   583,   587,     0,   590,
       0,     0,     0,     0,   589,   593,   594,   596,   595,     0,
     615,   617,     0,    89,    93,    96,   160,     0,     0,     0,
     159,   163,   164,   165,   494,   495,   237,   238,     0,   242,
     541,   533,   535,   539,     0,   607,   605,     0,   174,   531,
     591,   597,   174,   599,     0,     0,     0,     0,     0,   161,
     174,   174,   456,   275,   453,   270,   271,   276,   272,   637,
     273,     0,   268,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   261,   262,   263,   253,   579,     0,
       0,     0,     0,     0,     0,     0,   634,     0,   633,    91,
       0,    98,   101,    95,     0,     0,   280,     0,   283,   277,
     278,   279,     0,   174,     0,   457,   267,     0,     0,     0,
       0,     0,     0,     0,   174,   174,   606,   613,   612,   598,
     601,   600,     0,   635,    97,   103,     0,   120,   166,   167,
     174,   285,   274,   297,     0,   454,   452,     0,   460,   455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   636,     0,    99,   122,   139,   281,   299,   311,     0,
     288,   284,     0,     0,   174,   468,   475,     0,   174,   461,
       0,   254,   255,   256,   257,   258,   259,   260,   266,   111,
     115,     0,     0,   104,   105,   106,   102,   109,     0,   141,
     100,   313,   364,     0,   302,     0,     0,     0,   296,   286,
       0,   289,     0,   493,   458,   469,     0,     0,   464,   182,
     459,   462,   463,   112,   115,   113,     0,     0,     0,   130,
     134,     0,     0,   123,   124,   125,   121,   128,     0,   366,
     404,     0,   316,   312,     0,     0,   298,   310,   300,     0,
     303,     0,   215,     0,     0,   292,   182,   287,   290,   291,
     478,   476,     0,   472,   182,   467,   470,   471,   174,     0,
     466,   180,   181,     0,   110,   114,     0,     0,     0,   131,
     134,   132,     0,     0,     0,   149,   153,     0,     0,   142,
     143,   144,   140,   147,   406,   418,     0,   369,   365,     0,
       0,   324,   314,     0,   317,     0,   219,     0,     0,   306,
     182,   301,   304,   305,   295,   182,     0,   294,     0,   174,
     174,   484,     0,   479,   480,   482,   483,   474,     0,   168,
     174,     0,   185,   183,   187,   465,     0,     0,   107,   108,
     129,   133,     0,     0,     0,   150,   153,   151,     0,     0,
       0,   420,   432,     0,   409,     0,     0,     0,   377,   367,
       0,   370,     0,   325,     0,   320,   182,   315,   318,   319,
     309,   182,     0,   308,     0,     0,   201,   214,   293,     0,
       0,   490,   239,   477,   487,   488,   481,   473,     0,   197,
       0,   192,   194,   195,     0,   186,     0,   118,     0,   116,
       0,     0,   126,   127,   148,   152,     0,     0,     0,   434,
     282,   435,   423,     0,     0,     0,   405,   417,   407,     0,
     410,     0,   378,     0,   373,   182,   368,   371,   372,   328,
     323,   322,     0,     0,   182,   218,   307,   216,     0,   174,
     174,   489,   269,     0,   174,     0,   196,     0,   184,   174,
     174,   188,   190,   189,     0,   119,     0,   137,     0,   135,
       0,     0,   145,   146,   439,     0,     0,   436,   437,   438,
     419,   431,   421,     0,   424,     0,     0,   413,   182,   408,
     411,   412,   381,   376,   375,     0,   330,     0,   336,     0,
     321,   220,     0,   204,   217,   202,   205,   485,   486,   492,
     491,   193,   198,     0,     0,     0,   117,     0,   138,     0,
     156,     0,   154,   174,   443,     0,     0,     0,     0,   427,
     182,   422,   425,   426,   416,   415,     0,   383,     0,   389,
       0,   374,   326,   338,   327,     0,   333,   182,   329,   331,
     332,   221,   206,     0,   191,   174,   174,   136,     0,   157,
     440,   433,   451,   441,     0,   444,     0,   430,   429,     0,
     414,   379,   391,   380,     0,   386,   182,   382,   384,   385,
     341,   343,   337,   339,   340,   335,     0,   174,   203,   199,
     200,   155,     0,   447,   182,   442,   445,   446,   428,   394,
     396,   390,   392,   393,   388,     0,     0,   334,     0,   450,
     449,     0,     0,   387,   346,   342,   344,   348,   207,   448,
     399,   395,   397,     0,     0,   347,   402,     0,   398,   400,
     401,   355,   357,   345,   353,   354,     0,   174,   349,   351,
     350,     0,     0,   174,     0,   403,   356,   360,   358,   361,
       0,   174,     0,     0,   352,   496,   174,     0,   359,     0,
       0,   362,   363
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,   165,   166,     3,     5,    11,    12,    13,
      38,    22,    39,    40,    41,    42,    43,    17,    18,    29,
      55,    56,    57,    77,    26,    27,    50,    73,    74,    75,
      94,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    48,    68,
      69,    91,    92,   169,   170,   236,   298,   299,   300,   398,
     453,   486,   487,   512,   543,   544,   545,   546,   547,   574,
     575,   576,   687,   749,   515,   548,   583,   584,   585,   586,
     587,   630,   631,   632,   751,   809,   550,   588,   639,   640,
     641,   642,   643,   696,   697,   698,   811,   862,   171,   172,
     370,   301,   371,   372,   373,   656,    30,    51,    81,   243,
     244,   110,   620,   621,   683,   684,   744,   745,   801,   798,
     622,   681,   741,   742,   743,   802,   803,   788,   845,   846,
     893,   928,   603,   604,   666,   727,   657,   658,   722,   785,
      98,    99,   198,   671,   200,   201,   248,   249,   250,   311,
     312,   313,   378,   379,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   414,   377,   405,
     406,   407,   458,   459,   460,   461,   492,   493,   494,   521,
     522,   523,   562,   607,   608,   609,   668,   559,   560,   518,
     519,   555,   556,   557,   601,   661,   662,   663,   724,   598,
     599,   552,   553,   593,   594,   595,   655,   717,   718,   719,
     782,   652,   653,   714,   780,   837,   838,   839,   888,   889,
     890,   926,   884,   885,   922,   923,   924,   946,   956,   957,
     964,   965,   978,   979,   973,   974,   975,   982,   988,   989,
     993,   998,   590,   591,   648,   649,   650,   712,   776,   777,
     778,   835,   709,   710,   773,   833,   878,   879,   880,   917,
     918,   919,   945,   913,   914,   941,   942,   943,   952,   962,
     963,   968,   969,   970,   645,   646,   705,   706,   707,   771,
     829,   830,   831,   876,   768,   769,   702,   703,   763,   764,
     765,   825,   871,   872,   873,   909,   822,   823,   760,   761,
     816,   817,   818,   819,   865,   866,   867,   906,   935,   936,
     937,   951,   903,   904,   408,   409,   496,   410,   411,   464,
     499,   500,   501,   530,   570,   571,   572,   623,   526,   527,
     566,   615,   616,   617,   678,   564,   611,   612,   672,   673,
     674,   675,   676,   733,   734,   735,   793,   465,   202,   203,
     980,     8,    15,    24,   233,    47,    66,   138,   139,   229,
     140,   208,   141,   209,   142,   216,   143,   210,   144,   207,
     145,   213,   257,   146,   225,   269,   147,   224,   268,   148,
     226,   270,   149,   214,   258,   150,   211,   151,   212,   152,
     218,   153,   219,   154,   220,   155,   215,   156,   222,   157,
     223,   158,   217,   159,   227,   273,   160,   228,   276,   161,
     230,   354,   278,   355,   356,   442,   357,   444,   358,   162,
     221,   334,   439,   265,   335,   336,   337,   163,   231,   232,
     280,   281,   359,   448,   395,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -751
static const yytype_int16 yypact[] =
{
      67,    72,   104,   -53,   116,    95,  -751,   -46,   115,   174,
    -751,    63,  -751,  -751,   146,  -751,  -751,   193,   160,   223,
    -751,  -751,    25,   220,   -86,  -751,  -751,   194,   227,    70,
    -751,   218,  -751,   204,   228,   230,   231,   232,  -751,  -751,
    -751,  -751,  -751,  -751,   233,  -751,  -751,   219,   186,   235,
      97,  -751,   236,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     237,   243,   244,  -751,   229,   249,   242,  -751,   111,   124,
     252,  -751,  -751,  -751,  -751,  -751,   257,     0,   258,   259,
     260,   261,    14,  -751,   262,   577,  -751,  -751,   254,  -751,
      84,  -751,  -751,   265,   110,  -751,  -751,  -751,  -751,    18,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   267,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   215,
     212,   216,   196,  -751,  -751,   194,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,   270,   271,   273,  -751,  -751,   137,  -751,
    -751,  -751,  -751,  -751,  -148,  -148,  -751,   577,   577,   577,
     577,   577,   577,  -751,  -751,   577,   577,   577,   577,   577,
     577,  -751,   577,   577,  -751,  -751,  -751,   142,   155,   577,
    -751,   163,   163,    92,  -751,   279,  -751,  -751,  -751,    97,
     280,   281,   282,   283,     5,   284,  -751,   -16,  -751,  -751,
    -751,   577,   577,   577,   577,    90,    91,   153,   226,    88,
      82,   577,    83,    87,    81,    40,    78,    80,   288,   325,
     426,  -751,    73,  -751,  -751,    68,  -751,   577,    15,  -751,
      66,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,    65,  -751,   298,   248,  -751,
     250,    74,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   188,  -751,  -751,   120,   121,   118,   119,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   577,  -751,  -751,  -751,
    -751,   514,   309,   311,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,    85,  -751,
      89,   312,   315,   316,  -751,  -751,  -751,  -751,  -751,   297,
    -751,  -751,   318,  -751,  -751,   301,  -751,   238,   321,   323,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   -70,   157,    20,
    -751,  -751,  -751,  -751,   122,  -751,  -751,   320,  -751,  -751,
    -751,  -751,  -751,  -751,   328,   159,   324,   330,   161,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,    -4,  -751,   163,
    -751,   208,  -751,   221,  -751,   333,   340,   342,   344,   346,
     352,   354,   356,  -751,   357,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   147,
     362,   364,   366,   368,   370,   372,  -751,   256,  -751,  -751,
     374,  -751,   317,  -751,   380,   382,  -751,   383,   245,  -751,
    -751,  -751,   217,  -751,   222,  -751,  -751,   384,   386,   387,
     389,   390,   391,   393,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,   398,  -751,  -751,  -751,   343,   337,  -751,  -751,
    -751,  -751,  -751,   247,   263,  -751,  -751,   399,  -751,  -751,
     234,   299,   404,   405,   407,   411,   413,   415,   417,   421,
    -751,  -751,    50,  -751,  -751,   360,  -751,  -751,   275,   287,
    -751,  -751,   289,   299,  -751,  -751,  -751,   299,  -751,  -751,
     165,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     363,   429,   435,  -751,  -751,  -751,  -751,  -751,    57,  -751,
    -751,  -751,   285,   293,  -751,   286,   303,   299,  -751,  -751,
     299,  -751,   167,  -751,   326,  -751,   169,   443,  -751,   341,
    -751,  -751,  -751,  -751,   395,  -751,   392,   449,   451,  -751,
     396,   457,   462,  -751,  -751,  -751,  -751,  -751,    59,  -751,
     304,   319,  -751,  -751,   327,   299,  -751,  -751,  -751,   299,
    -751,   173,  -751,   334,   329,  -751,   341,  -751,  -751,  -751,
    -751,  -751,   -93,  -751,   341,  -751,  -751,  -751,  -751,   355,
    -751,   353,  -751,   302,  -751,  -751,   453,   469,   477,  -751,
     420,  -751,   414,   485,   487,  -751,   427,   495,   497,  -751,
    -751,  -751,  -751,  -751,  -751,   339,   359,  -751,  -751,   351,
     299,  -751,  -751,   299,  -751,   177,  -751,   375,   376,  -751,
     341,  -751,  -751,  -751,  -751,  -751,   378,  -751,   381,  -751,
    -751,  -751,   179,   -93,  -751,  -751,  -751,  -751,   361,  -751,
    -751,   183,  -751,  -751,  -751,  -751,   503,   185,  -751,  -751,
    -751,  -751,   517,   536,   538,  -751,   474,  -751,   467,   540,
     544,  -751,   394,   408,  -751,   400,   402,   299,  -751,  -751,
     299,  -751,   187,  -751,   548,  -751,   341,  -751,  -751,  -751,
    -751,  -751,   410,  -751,   416,   -54,  -751,  -751,  -751,   556,
     560,  -751,    -8,  -751,  -751,  -751,  -751,  -751,   561,  -751,
      27,  -751,  -751,  -751,   558,    86,   563,  -751,   496,  -751,
     569,   191,  -751,  -751,  -751,  -751,   555,   571,   572,  -751,
    -751,    75,  -751,   412,   425,   299,  -751,  -751,  -751,   299,
    -751,   195,  -751,   566,  -751,   341,  -751,  -751,  -751,   428,
    -751,  -751,   430,   -37,  -751,  -751,  -751,  -751,   -50,  -751,
    -751,  -751,  -751,   456,  -751,   470,  -751,   576,  -751,  -751,
    -751,  -751,  -751,  -751,   581,  -751,   578,  -751,   509,  -751,
     584,   197,  -751,  -751,  -751,   585,   439,  -751,  -751,  -751,
    -751,  -751,  -751,   299,  -751,   199,   438,  -751,   341,  -751,
    -751,  -751,   442,  -751,  -751,   441,  -751,   440,   444,   201,
    -751,  -751,   -45,  -751,  -751,  -751,   482,  -751,  -751,   -70,
    -751,  -751,  -751,   480,   593,   594,  -751,   599,  -751,   598,
    -751,   527,  -751,  -751,  -751,   446,   458,   299,   455,  -751,
     341,  -751,  -751,  -751,  -751,  -751,   460,  -751,   464,   463,
     203,  -751,  -751,  -751,  -751,   205,  -751,   341,  -751,  -751,
    -751,  -751,  -751,   597,  -751,  -751,  -751,  -751,   609,  -751,
    -751,  -751,  -751,  -751,   299,  -751,   207,  -751,  -751,   472,
    -751,  -751,  -751,  -751,   209,  -751,   341,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   466,  -751,  -751,  -751,
    -751,  -751,   476,  -751,   341,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   478,   -42,  -751,   513,  -751,
    -751,   484,   -40,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,   211,   213,   -52,  -751,   577,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   623,  -751,  -751,  -751,
    -751,   519,   -60,  -751,   631,  -751,  -751,  -751,  -751,   406,
     637,  -751,   639,   633,  -751,  -751,  -751,   641,  -751,   647,
     486,  -751,  -751
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   643,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,   564,   489,   423,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   367,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
      94,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,    30,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,   -30,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -468,  -751,  -751,  -372,  -196,
     -63,  -751,  -583,  -638,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -177,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -750,  -751,  -751,  -751,
    -751,  -751,  -751,   573,  -751,  -751,  -751,  -751,  -751,  -751,
     -62,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -121,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
       1,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -205,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -223,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      82,   245,   251,   252,   253,   254,   255,   256,   307,   295,
     259,   260,   261,   262,   263,   264,   441,   266,   267,   826,
     443,   104,   105,   667,   277,   349,   350,   725,   454,   455,
      96,   677,   795,   529,   195,    32,    33,   351,   352,   193,
     194,   204,   205,    34,    35,    36,   314,   315,   316,   317,
     330,   331,   321,   323,   402,   561,   326,   986,   332,   565,
     539,   540,   682,   341,   343,   345,   843,   579,   580,   635,
     636,   682,   348,   868,   954,   403,   960,   723,   976,   682,
      53,    54,   977,   783,   366,   367,   669,   670,    20,   600,
      10,     1,   602,   106,   107,   108,   109,    45,     4,    46,
     787,   404,   509,   309,     6,   310,   844,    71,    72,   987,
     374,   891,   375,   310,   955,   791,   961,   841,    97,     9,
     541,   384,    10,   542,    86,    87,   386,   654,   581,     7,
     582,   637,   638,   781,    89,    90,   368,   369,    14,   796,
     167,   168,    25,   174,    16,   195,   842,   246,   247,    23,
     196,   197,   271,   272,   932,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   274,   275,   412,   413,   446,
     447,   451,   452,   456,   457,   568,   569,   605,   606,   613,
     614,    19,   711,   659,   660,   713,   462,   715,   716,   731,
     732,    28,   834,   739,   740,   747,   748,   774,   775,   799,
     800,   807,   808,   814,   815,   827,   828,   860,   861,   869,
     870,   886,   887,   915,   916,   920,   921,   933,   934,   939,
     940,   966,   967,   971,   972,    25,    31,    44,    49,    58,
      52,    60,    59,    61,    62,    63,    64,    65,    70,   770,
      83,    67,   772,    76,    78,   875,   106,   107,   108,   109,
      79,    80,    84,    85,   353,   106,   107,   108,   109,    93,
      95,   100,   101,   102,   103,    37,   164,   497,   173,   111,
     206,   234,   237,   235,   240,   241,   238,   242,   296,   510,
     333,   279,   297,   303,   304,   305,   318,   908,   325,   319,
     306,   308,   324,   327,   516,   329,   338,   824,   347,   328,
     339,   346,   360,   361,   925,   362,   363,   376,   380,   365,
     382,   381,   387,   383,   388,   394,   391,   389,   392,   399,
     393,   396,   397,   390,   400,    82,   401,   440,   563,    82,
     438,   445,   567,   944,   450,   449,   467,    82,    82,   463,
     112,   466,   113,   468,   114,   469,   115,   470,   116,   471,
     117,   950,   118,   320,   119,   472,   120,   473,   121,   474,
     122,   475,   123,   476,   124,   477,   125,   478,   126,   479,
     127,   480,   128,   481,   129,   483,   130,   484,   131,   482,
     132,   485,   133,   488,   134,   489,   135,   490,   136,   495,
     137,   502,   491,   503,   504,   498,   505,   506,   507,   905,
     508,   511,   514,   513,   517,   528,   524,   531,   532,   525,
     533,    82,   520,   112,   534,   113,   535,   114,   536,   115,
     537,   116,   679,   117,   538,   118,   549,   119,   322,   120,
     573,   121,   577,   122,   551,   123,   554,   124,   578,   125,
     558,   126,   592,   127,   596,   128,   589,   129,   610,   130,
     618,   131,   619,   132,   597,   133,   627,   134,   628,   135,
     633,   136,   624,   137,   629,   634,   626,   644,   647,   682,
     680,   686,   688,   729,   730,   112,   685,   113,   651,   114,
     689,   115,   665,   116,   738,   117,   664,   118,   690,   119,
     692,   120,   693,   121,   694,   122,   695,   123,   699,   124,
     700,   125,   708,   126,   701,   127,   746,   128,   704,   129,
     340,   130,   112,   131,   113,   132,   114,   133,   115,   134,
     116,   135,   117,   136,   118,   137,   119,   720,   120,   721,
     121,   728,   122,   726,   123,   750,   124,   737,   125,   752,
     126,   753,   127,   754,   128,   756,   129,   757,   130,   342,
     131,   758,   132,   767,   133,   948,   134,   762,   135,   779,
     136,   759,   137,   789,   766,   784,   786,   790,   794,   797,
     804,   805,   806,   810,   812,   813,   821,   832,   820,   850,
     840,   836,   852,   853,   856,   857,   858,   859,   864,   863,
     874,   881,   882,   847,   848,   877,   800,   894,   851,   883,
     895,   896,   897,   854,   855,   898,   899,   907,   927,   902,
     910,   990,   931,   112,   901,   113,   911,   114,   912,   115,
     947,   116,   938,   117,   999,   118,   983,   119,   949,   120,
     958,   121,   953,   122,   959,   123,   985,   124,   991,   125,
     994,   126,   996,   127,   997,   128,   992,   129,  1000,   130,
    1001,   131,   344,   132,    21,   133,  1002,   134,   175,   135,
     691,   136,   302,   137,   239,   364,   755,   900,   625,   892,
     792,   849,   199,     0,   736,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   929,
     930,   112,     0,   113,     0,   114,     0,   115,     0,   116,
       0,   117,     0,   118,     0,   119,     0,   120,     0,   121,
       0,   122,     0,   123,     0,   124,     0,   125,     0,   126,
     385,   127,     0,   128,     0,   129,     0,   130,     0,   131,
       0,   132,     0,   133,     0,   134,     0,   135,     0,   136,
       0,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   981,     0,   112,     0,   113,     0,   114,     0,
     115,     0,   116,     0,   117,     0,   118,     0,   119,     0,
     120,   984,   121,     0,   122,     0,   123,     0,   124,     0,
     125,     0,   126,     0,   127,   995,   128,     0,   129,     0,
     130,     0,   131,     0,   132,     0,   133,     0,   134,     0,
     135,     0,   136,     0,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      63,   197,   207,   208,   209,   210,   211,   212,     3,   232,
     215,   216,   217,   218,   219,   220,   388,   222,   223,   769,
     392,     7,     8,   606,   229,    10,    11,   665,   400,   401,
      30,   614,     5,   501,   127,    10,    11,    22,    23,    21,
      22,   104,   105,    18,    19,    20,   251,   252,   253,   254,
      10,    11,   257,   258,   124,   523,   261,   117,    18,   527,
      10,    11,   116,   268,   269,   270,   116,    10,    11,    10,
      11,   116,   277,   823,   116,   145,   116,   660,   130,   116,
      10,    11,   134,   721,    10,    11,   179,   180,    25,   557,
      27,    24,   560,   241,   242,   243,   244,   183,    26,   185,
     154,   171,   474,   119,     0,   121,   156,    10,    11,   169,
     306,   156,   308,   121,   156,   123,   156,   154,   118,     3,
      70,   326,    27,    73,    13,    14,   331,   595,    71,   182,
      73,    72,    73,   716,    10,    11,    62,    63,   184,   112,
      56,    57,    32,    33,    29,   127,   784,    10,    11,     3,
     132,   133,    10,    11,   904,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    10,    11,    10,    11,    10,
      11,    10,    11,   177,   178,    10,    11,    10,    11,    10,
      11,     7,   650,    10,    11,   653,   409,    10,    11,    10,
      11,    31,   775,    10,    11,    10,    11,    10,    11,   113,
     114,    10,    11,   128,   129,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    32,     3,     7,    34,    11,
       3,     3,    28,     3,     3,     3,     3,    18,     3,   707,
      11,    55,   710,     7,     7,   828,   241,   242,   243,   244,
       7,     7,     3,    11,   239,   241,   242,   243,   244,     7,
       3,     3,     3,     3,     3,   240,    12,   463,     3,     7,
       3,    56,    56,    61,     4,     4,    80,     4,   186,   475,
     240,   118,     3,     3,     3,     3,   196,   870,   206,   198,
       7,     7,   204,   210,   490,   214,   218,   765,   230,   212,
     220,   228,   236,   238,   887,     7,    58,   119,   188,    59,
     192,   190,     3,   194,     3,    18,     4,   232,     3,    81,
       4,     3,    21,   234,     3,   388,     3,     7,   524,   392,
     208,     3,   528,   916,     4,    11,     3,   400,   401,   131,
     187,   120,   189,     3,   191,     3,   193,     3,   195,     3,
     197,   934,   199,   200,   201,     3,   203,     3,   205,     3,
     207,     4,   209,   216,   211,     3,   213,     3,   215,     3,
     217,     3,   219,     3,   221,   119,   223,     3,   225,     7,
     227,    64,   229,     3,   231,     3,   233,     4,   235,   172,
     237,     7,   147,     7,     7,   173,     7,     7,     7,   867,
       7,     3,    65,    60,   157,   106,     7,     3,     3,   175,
       3,   474,   149,   187,     3,   189,     3,   191,     3,   193,
       3,   195,   618,   197,     3,   199,    66,   201,   202,   203,
      67,   205,     3,   207,   159,   209,   149,   211,     3,   213,
     151,   215,   149,   217,   158,   219,   161,   221,   122,   223,
       7,   225,   111,   227,   151,   229,     7,   231,     7,   233,
       3,   235,    67,   237,    68,     3,    74,   163,   149,   116,
     115,    18,     3,   669,   670,   187,   174,   189,   151,   191,
       3,   193,   153,   195,   680,   197,   152,   199,    68,   201,
      76,   203,     7,   205,     7,   207,    69,   209,     3,   211,
       3,   213,   151,   215,   165,   217,     3,   219,   149,   221,
     222,   223,   187,   225,   189,   227,   191,   229,   193,   231,
     195,   233,   197,   235,   199,   237,   201,   152,   203,   153,
     205,   150,   207,   155,   209,    18,   211,   176,   213,     3,
     215,     3,   217,    69,   219,    78,   221,     7,   223,   224,
     225,     7,   227,   151,   229,   927,   231,   149,   233,    11,
     235,   167,   237,     7,   164,   155,   150,     7,     7,    11,
       7,    75,     3,    18,     3,     3,   151,    11,   166,   123,
     150,   153,   112,     7,     3,     7,    77,     3,   149,     4,
     152,   150,   152,   789,   790,   153,   114,   117,   794,   155,
       7,     7,     3,   799,   800,     7,    79,   152,    11,   151,
     150,   983,     3,   187,   168,   189,   152,   191,   155,   193,
     154,   195,   150,   197,   996,   199,     3,   201,   152,   203,
     117,   205,   154,   207,   150,   209,   117,   211,     7,   213,
       3,   215,     3,   217,    11,   219,   240,   221,     7,   223,
       3,   225,   226,   227,    11,   229,   170,   231,    94,   233,
     630,   235,   239,   237,   175,   298,   696,   863,   574,   846,
     732,   792,    99,    -1,   673,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,
     896,   187,    -1,   189,    -1,   191,    -1,   193,    -1,   195,
      -1,   197,    -1,   199,    -1,   201,    -1,   203,    -1,   205,
      -1,   207,    -1,   209,    -1,   211,    -1,   213,    -1,   215,
     216,   217,    -1,   219,    -1,   221,    -1,   223,    -1,   225,
      -1,   227,    -1,   229,    -1,   231,    -1,   233,    -1,   235,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   967,    -1,   187,    -1,   189,    -1,   191,    -1,
     193,    -1,   195,    -1,   197,    -1,   199,    -1,   201,    -1,
     203,   977,   205,    -1,   207,    -1,   209,    -1,   211,    -1,
     213,    -1,   215,    -1,   217,   991,   219,    -1,   221,    -1,
     223,    -1,   225,    -1,   227,    -1,   229,    -1,   231,    -1,
     233,    -1,   235,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   927,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   996
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   246,   250,    26,   251,     0,   182,   596,     3,
      27,   252,   253,   254,   184,   597,    29,   262,   263,     7,
      25,   253,   256,     3,   598,    32,   269,   270,    31,   264,
     351,     3,    10,    11,    18,    19,    20,   240,   255,   257,
     258,   259,   260,   261,     7,   183,   185,   600,   293,    34,
     271,   352,     3,    10,    11,   265,   266,   267,    11,    28,
       3,     3,     3,     3,     3,    18,   601,    55,   294,   295,
       3,    10,    11,   272,   273,   274,     7,   268,     7,     7,
       7,   353,   355,    11,     3,    11,    13,    14,   247,    10,
      11,   296,   297,     7,   275,     3,    30,   118,   385,   386,
       3,     3,     3,     3,     7,     8,   241,   242,   243,   244,
     356,     7,   187,   189,   191,   193,   195,   197,   199,   201,
     203,   205,   207,   209,   211,   213,   215,   217,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   237,   602,   603,
     605,   607,   609,   611,   613,   615,   618,   621,   624,   627,
     630,   632,   634,   636,   638,   640,   642,   644,   646,   648,
     651,   654,   664,   672,    12,   248,   249,    56,    57,   298,
     299,   343,   344,     3,    33,   270,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,    21,    22,   127,   132,   133,   387,   388,
     389,   390,   593,   594,   355,   355,     3,   614,   606,   608,
     612,   631,   633,   616,   628,   641,   610,   647,   635,   637,
     639,   665,   643,   645,   622,   619,   625,   649,   652,   604,
     655,   673,   674,   599,    56,    61,   300,    56,    80,   271,
       4,     4,     4,   354,   355,   354,    10,    11,   391,   392,
     393,   602,   602,   602,   602,   602,   602,   617,   629,   602,
     602,   602,   602,   602,   602,   668,   602,   602,   623,   620,
     626,    10,    11,   650,    10,    11,   653,   602,   657,   118,
     675,   676,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,   675,   186,     3,   301,   302,
     303,   346,   272,     3,     3,     3,     7,     3,     7,   119,
     121,   394,   395,   396,   602,   602,   602,   602,   196,   198,
     200,   602,   202,   602,   204,   206,   602,   210,   212,   214,
      10,    11,    18,   240,   666,   669,   670,   671,   218,   220,
     222,   602,   224,   602,   226,   602,   228,   230,   602,    10,
      11,    22,    23,   239,   656,   658,   659,   661,   663,   677,
     236,   238,     7,    58,   302,    59,    10,    11,    62,    63,
     345,   347,   348,   349,   354,   354,   119,   413,   397,   398,
     188,   190,   192,   194,   602,   216,   602,     3,     3,   232,
     234,     4,     3,     4,    18,   679,     3,    21,   304,    81,
       3,     3,   124,   145,   171,   414,   415,   416,   559,   560,
     562,   563,    10,    11,   412,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   208,   667,
       7,   353,   660,   353,   662,     3,    10,    11,   678,    11,
       4,    10,    11,   305,   353,   353,   177,   178,   417,   418,
     419,   420,   675,   131,   564,   592,   120,     3,     3,     3,
       3,     3,     3,     3,     3,     4,   216,     3,     3,     3,
       3,     3,     7,   119,     3,    64,   306,   307,     3,     3,
       4,   147,   421,   422,   423,   172,   561,   354,   173,   565,
     566,   567,     7,     7,     7,     7,     7,     7,     7,   353,
     354,     3,   308,    60,    65,   319,   354,   157,   434,   435,
     149,   424,   425,   426,     7,   175,   573,   574,   106,   350,
     568,     3,     3,     3,     3,     3,     3,     3,     3,    10,
      11,    70,    73,   309,   310,   311,   312,   313,   320,    66,
     331,   159,   446,   447,   149,   436,   437,   438,   151,   432,
     433,   350,   427,   354,   580,   350,   575,   354,    10,    11,
     569,   570,   571,    67,   314,   315,   316,     3,     3,    10,
      11,    71,    73,   321,   322,   323,   324,   325,   332,   161,
     487,   488,   149,   448,   449,   450,   158,   151,   444,   445,
     350,   439,   350,   377,   378,    10,    11,   428,   429,   430,
     122,   581,   582,    10,    11,   576,   577,   578,     7,   111,
     357,   358,   365,   572,    67,   315,    74,     7,     7,    68,
     326,   327,   328,     3,     3,    10,    11,    72,    73,   333,
     334,   335,   336,   337,   163,   519,   520,   149,   489,   490,
     491,   151,   456,   457,   350,   451,   350,   381,   382,    10,
      11,   440,   441,   442,   152,   153,   379,   357,   431,   179,
     180,   388,   583,   584,   585,   586,   587,   357,   579,   354,
     115,   366,   116,   359,   360,   174,    18,   317,     3,     3,
      68,   327,    76,     7,     7,    69,   338,   339,   340,     3,
       3,   165,   531,   532,   149,   521,   522,   523,   151,   497,
     498,   350,   492,   350,   458,    10,    11,   452,   453,   454,
     152,   153,   383,   357,   443,   358,   155,   380,   150,   354,
     354,    10,    11,   588,   589,   590,   585,   176,   354,    10,
      11,   367,   368,   369,   361,   362,     3,    10,    11,   318,
      18,   329,     3,     3,    69,   339,    78,     7,     7,   167,
     543,   544,   149,   533,   534,   535,   164,   151,   529,   530,
     350,   524,   350,   499,    10,    11,   493,   494,   495,    11,
     459,   357,   455,   358,   155,   384,   150,   154,   372,     7,
       7,   123,   395,   591,     7,     5,   112,    11,   364,   113,
     114,   363,   370,   371,     7,    75,     3,    10,    11,   330,
      18,   341,     3,     3,   128,   129,   545,   546,   547,   548,
     166,   151,   541,   542,   350,   536,   381,    10,    11,   525,
     526,   527,    11,   500,   357,   496,   153,   460,   461,   462,
     150,   154,   358,   116,   156,   373,   374,   354,   354,   413,
     123,   354,   112,     7,   354,   354,     3,     7,    77,     3,
      10,    11,   342,     4,   149,   549,   550,   551,   381,    10,
      11,   537,   538,   539,   152,   357,   528,   153,   501,   502,
     503,   150,   152,   155,   467,   468,    10,    11,   463,   464,
     465,   156,   371,   375,   117,     7,     7,     3,     7,    79,
     354,   168,   151,   557,   558,   350,   552,   152,   357,   540,
     150,   152,   155,   508,   509,    10,    11,   504,   505,   506,
      10,    11,   469,   470,   471,   357,   466,    11,   376,   354,
     354,     3,   381,    10,    11,   553,   554,   555,   150,    10,
      11,   510,   511,   512,   357,   507,   472,   154,   353,   152,
     357,   556,   513,   154,   116,   156,   473,   474,   117,   150,
     116,   156,   514,   515,   475,   476,    10,    11,   516,   517,
     518,    10,    11,   479,   480,   481,   130,   134,   477,   478,
     595,   602,   482,     3,   354,   117,   117,   169,   483,   484,
     353,     7,   240,   485,     3,   354,     3,    11,   486,   353,
       7,     3,   170
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

  case 82:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 89:

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

  case 90:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 91:

    {
	if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
	if ((yyvsp[(3) - (5)].ival) < 1) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of stages must be positive");
	osinstance->instanceData->timeDomain->stages->numberOfStages = (yyvsp[(3) - (5)].ival);
	if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
		osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ (yyvsp[(3) - (5)].ival) ];
	for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) 
	{	osinstance->instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
		osinstance->instanceData->timeDomain->stages->stage[i]->variables   = new TimeDomainStageVariables();
		osinstance->instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
		osinstance->instanceData->timeDomain->stages->stage[i]->objectives  = new TimeDomainStageObjectives();
	}
}
    break;

  case 94:

    {
	if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 95:

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

  case 97:

    {
		  osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 102:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 107:

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
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
		}
	};
}
    break;

  case 108:

    {
	if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
	parserData->stageVariablesOrdered = true;
	parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 109:

    {
	if ((parserData->stageVariablesOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
		  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
	}
    break;

  case 110:

    {
	  if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
	      parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
	  }
    break;

  case 115:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 117:

    {
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");		 
	if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
	    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stagevarcount++;
}
    break;

  case 121:

    {
        parserData->stageConstraintsON = true;
	}
    break;

  case 126:

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
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
		}
	};
}
    break;

  case 127:

    {
	if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
	parserData->stageConstraintsOrdered = true;
	parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 128:

    {
	if ((parserData->stageConstraintsOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
		  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
	}
    break;

  case 129:

    {
	  if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
	      parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
	  }
    break;

  case 134:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 136:

    {
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");		 
	if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
	    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stageconcount++;
}
    break;

  case 139:

    { /* By default, an objective belongs to every stage */
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 
				osinstance->instanceData->objectives->numberOfObjectives;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = 
				new TimeDomainStageObj*[ osinstance->instanceData->objectives->numberOfObjectives ];
			for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++) 
			{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
				osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = -(i+1); 
			}
	}
    break;

  case 140:

    {
	  parserData->stageObjectivesON = true;
	}
    break;

  case 145:

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
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = 0; 
		}
	};
}
    break;

  case 146:

    {
	if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
	parserData->stageObjectivesOrdered = true;
	parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 147:

    {
	if ((parserData->stageObjectivesOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
		  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
	}
    break;

  case 148:

    {
	  if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
	      parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
	}
    break;

  case 153:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 155:

    {
	if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
		parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");		 
	if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
	    parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stageobjcount++;
}
    break;

  case 158:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 159:

    {
		parserData->intervalhorizonON = false;
		parserData->intervalstartON = false;
		printf("Interval not yet supported.\n\n");
}
    break;

  case 164:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
		parserData->intervalhorizonON = true; }
    break;

  case 165:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
		parserData->intervalstartON = true; }
    break;

  case 166:

    {
		if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
		parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 167:

    {
		if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
		parserData->intervalstart = parserData->tempVal;}
    break;

  case 168:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOfEl = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 169:

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

  case 170:

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

  case 171:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 172:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 180:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 185:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 191:

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

  case 193:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 198:

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

  case 199:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 200:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 204:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 207:

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

  case 208:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 213:

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

  case 214:

    {
}
    break;

  case 215:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new    int[parserData->numberOf];
    osglData->osglDblArray = new double[parserData->numberOf];
}
    break;

  case 218:

    {
}
    break;

  case 219:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
    osglData->osglValArray = new int[parserData->numberOf];
}
    break;

  case 223:

    {
    //osglData->...;
}
    break;

  case 229:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        if (verifyMatrixType(osglData->matrixTypeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 230:

    { 
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 231:

    { 
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 232:

    { 
    if (osglData->matrixTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->matrixTypeAttributePresent = true;   
    osglData->matrixTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 254:

    { 
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    osglData->baseMatrixIdxAttributePresent = true;   
    osglData->baseMatrixIdxAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 255:

    { 
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 256:

    { 
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 257:

    { 
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 258:

    { 
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 259:

    { 
    if (osglData->baseMatrixEndRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last row cannot be negative");
    osglData->baseMatrixEndRowAttributePresent = true;   
    osglData->baseMatrixEndRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 260:

    { 
    if (osglData->baseMatrixEndColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix last col cannot be negative");
    osglData->baseMatrixEndColAttributePresent = true;   
    osglData->baseMatrixEndColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 261:

    { 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
}
    break;

  case 264:

    {
    osglData->baseTransposeAttribute = true;
}
    break;

  case 265:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->baseTransposeAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->baseTransposeAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 266:

    {
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
}
    break;

  case 280:

    {
    osglData->rowMajorAttribute = true;
}
    break;

  case 281:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->rowMajorAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->rowMajorAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 287:

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

  case 288:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 289:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 295:

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

  case 296:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 301:

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

  case 302:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 303:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 309:

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

  case 310:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 315:

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

  case 316:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 317:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 323:

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

  case 324:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 325:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 329:

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

  case 330:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 338:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 346:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 352:

    {
}
    break;

  case 360:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
}
    break;

  case 362:

    {
}
    break;

  case 363:

    {
}
    break;

  case 368:

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

  case 369:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 370:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 376:

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

  case 377:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 378:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 382:

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

  case 383:

    {
//    osglData->osglNumberOfEl = 0;
//    osglData->osglNumberOfElPresent = false;
}
    break;

  case 391:

    {
//    osglData->osglNumberOfVarIdxPresent = false;
//    osglData->osglConstantPresent = false;
}
    break;

  case 399:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 408:

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

  case 409:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 410:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 416:

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

  case 417:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 422:

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

  case 423:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 424:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 430:

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

  case 431:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 439:

    {
    osglData->excludeIfSetAttribute = true;
}
    break;

  case 440:

    { 
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->excludeIfSetAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->excludeIfSetAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->excludeIfSetAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "excludeIfSet attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 442:

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

  case 443:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 444:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 450:

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

  case 451:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 459:

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

  case 460:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 461:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 467:

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

  case 468:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 469:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 484:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 485:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
    osglData->blockRowIdxAttributePresent = true;        
    osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 486:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
    osglData->blockColIdxAttributePresent = true;        
    osglData->blockColIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 493:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 494:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 495:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 496:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 498:

    {  if (osnlData->nlnodecount < osnlData->tmpnlcount)  parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   }
    break;

  case 499:

    { if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
osnlData->tmpnlcount = (yyvsp[(3) - (5)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
    osinstance->instanceData->nonlinearExpressions->nl[ i] = new Nl();
}
}
    break;

  case 501:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
    osnlData->nlNodeVec[ 0]->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
    osnlData->nlnodecount++;
}
    break;

  case 503:

    {
    if(osnlData->nlnodecount >= osnlData->tmpnlcount) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
}
    break;

  case 504:

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

  case 530:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 532:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 534:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 536:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 538:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 540:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 542:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 543:

    {
    osnlData->sumVec.back()->m_mChildren = new OSnLNode*[ osnlData->sumVec.back()->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 545:

    { osnlData->sumVec.back()->inumberOfChildren++; }
    break;

  case 546:

    {
    
    osnlData->nlNodePoint =   new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 547:

    {
    osnlData->allDiffVec.back()->m_mChildren = new OSnLNode*[ osnlData->allDiffVec.back()->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 549:

    { osnlData->allDiffVec.back()->inumberOfChildren++; }
    break;

  case 550:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 551:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 553:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 554:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 555:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 557:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 558:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 559:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 561:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 562:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 564:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 566:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 568:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 570:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 572:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 574:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 575:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 576:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 577:

    {
}
    break;

  case 578:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 579:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 580:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 584:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 588:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 589:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 594:

    {if(osnlData->numbertypeattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
            osnlData->numbertypeattON = true; }
    break;

  case 595:

    {if(osnlData->numbervalueattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
            osnlData->numbervalueattON = true; }
    break;

  case 596:

    {if(osnlData->numberidattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
            osnlData->numberidattON = true; }
    break;

  case 597:

    {
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 599:

    {
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 601:

    {/*if ( *$2 != *$4 ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");*/
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 602:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 603:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 605:

    {
    osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
    osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 610:

    {if(osnlData->variablecoefattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; }
    break;

  case 611:

    {if(osnlData->variableidxattON) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
            }
    break;

  case 612:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 613:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
     }
}
    break;

  case 614:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 616:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 632:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->OSnLMNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 633:

    {osnlData->matrixidxattON = false;}
    break;

  case 636:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
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


