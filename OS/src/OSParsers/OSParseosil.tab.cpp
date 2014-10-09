
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
     NUMBEROFMATRIXTERMSATT = 339,
     MATRIXTERMSTART = 340,
     MATRIXTERMEND = 341,
     MATRIXEXPRESSIONSSTART = 342,
     MATRIXEXPRESSIONSEND = 343,
     NUMBEROFMATRIXEXPRATT = 344,
     MATRIXEXPRSTART = 345,
     MATRIXEXPREND = 346,
     MATRIXIDXATT = 347,
     LBMATRIXIDXATT = 348,
     LBCONEIDXATT = 349,
     UBMATRIXIDXATT = 350,
     UBCONEIDXATT = 351,
     TEMPLATEMATRIXIDXATT = 352,
     VARREFERENCEMATRIXIDXATT = 353,
     OBJREFERENCEMATRIXIDXATT = 354,
     CONREFERENCEMATRIXIDXATT = 355,
     ORDERCONEIDXATT = 356,
     CONSTANTMATRIXIDXATT = 357,
     SHAPEATT = 358,
     EMPTYSHAPEATT = 359,
     TIMEDOMAINSTART = 360,
     TIMEDOMAINEND = 361,
     STAGESSTART = 362,
     STAGESEND = 363,
     STAGESTART = 364,
     STAGEEND = 365,
     NUMBEROFSTAGESATT = 366,
     HORIZONATT = 367,
     STARTATT = 368,
     VARIABLESSTART = 369,
     CONSTRAINTSSTART = 370,
     OBJECTIVESSTART = 371,
     VARIABLESEND = 372,
     CONSTRAINTSEND = 373,
     OBJECTIVESEND = 374,
     NUMBEROFVARIABLESATT = 375,
     NUMBEROFCONSTRAINTSATT = 376,
     NUMBEROFOBJECTIVESATT = 377,
     STARTIDXATT = 378,
     VARSTART = 379,
     VAREND = 380,
     CONSTART = 381,
     CONEND = 382,
     OBJSTART = 383,
     OBJEND = 384,
     INTERVALSTART = 385,
     INTERVALEND = 386,
     HEADERSTART = 387,
     HEADEREND = 388,
     FILENAMESTART = 389,
     FILENAMEEND = 390,
     FILENAMEEMPTY = 391,
     FILENAMESTARTANDEND = 392,
     FILESOURCESTART = 393,
     FILESOURCEEND = 394,
     FILESOURCEEMPTY = 395,
     FILESOURCESTARTANDEND = 396,
     FILEDESCRIPTIONSTART = 397,
     FILEDESCRIPTIONEND = 398,
     FILEDESCRIPTIONEMPTY = 399,
     FILEDESCRIPTIONSTARTANDEND = 400,
     FILECREATORSTART = 401,
     FILECREATOREND = 402,
     FILECREATOREMPTY = 403,
     FILECREATORSTARTANDEND = 404,
     FILELICENCESTART = 405,
     FILELICENCEEND = 406,
     FILELICENCEEMPTY = 407,
     FILELICENCESTARTANDEND = 408,
     ENUMERATIONSTART = 409,
     ENUMERATIONEND = 410,
     NUMBEROFELATT = 411,
     ITEMEMPTY = 412,
     ITEMSTART = 413,
     ITEMEND = 414,
     ITEMSTARTANDEND = 415,
     BASE64START = 416,
     BASE64END = 417,
     INCRATT = 418,
     MULTATT = 419,
     SIZEOFATT = 420,
     ELSTART = 421,
     ELEND = 422,
     MATRIXSTART = 423,
     MATRIXEND = 424,
     BASEMATRIXEND = 425,
     BASEMATRIXSTART = 426,
     BLOCKSTART = 427,
     BLOCKEND = 428,
     BLOCKSSTART = 429,
     BLOCKSEND = 430,
     EMPTYSYMMETRYATT = 431,
     SYMMETRYATT = 432,
     EMPTYNEGATIVEPATTERNATT = 433,
     NEGATIVEPATTERNATT = 434,
     CONSTANTATT = 435,
     NUMBEROFBLOCKSATT = 436,
     NUMBEROFCOLUMNSATT = 437,
     NUMBEROFROWSATT = 438,
     NUMBEROFVALUESATT = 439,
     NUMBEROFVARIDXATT = 440,
     BASEMATRIXIDXATT = 441,
     TARGETMATRIXFIRSTROWATT = 442,
     TARGETMATRIXFIRSTCOLATT = 443,
     BASEMATRIXSTARTROWATT = 444,
     BASEMATRIXSTARTCOLATT = 445,
     BASEMATRIXENDROWATT = 446,
     BASEMATRIXENDCOLATT = 447,
     SCALARMULTIPLIERATT = 448,
     EMPTYBASETRANSPOSEATT = 449,
     BASETRANSPOSEATT = 450,
     ELEMENTSSTART = 451,
     ELEMENTSEND = 452,
     CONSTANTELEMENTSSTART = 453,
     CONSTANTELEMENTSEND = 454,
     STARTVECTORSTART = 455,
     STARTVECTOREND = 456,
     NONZEROSSTART = 457,
     NONZEROSEND = 458,
     INDEXESSTART = 459,
     INDEXESEND = 460,
     VALUESSTART = 461,
     VALUESEND = 462,
     VARREFERENCEELEMENTSSTART = 463,
     VARREFERENCEELEMENTSEND = 464,
     LINEARELEMENTSSTART = 465,
     LINEARELEMENTSEND = 466,
     GENERALELEMENTSSTART = 467,
     GENERALELEMENTSEND = 468,
     CONREFERENCEELEMENTSSTART = 469,
     CONREFERENCEELEMENTSEND = 470,
     OBJREFERENCEELEMENTSSTART = 471,
     OBJREFERENCEELEMENTSEND = 472,
     PATTERNELEMENTSSTART = 473,
     PATTERNELEMENTSEND = 474,
     VARIDXSTART = 475,
     VARIDXEND = 476,
     TRANSFORMATIONSTART = 477,
     TRANSFORMATIONEND = 478,
     COLOFFSETSSTART = 479,
     COLOFFSETSEND = 480,
     ROWOFFSETSSTART = 481,
     ROWOFFSETSEND = 482,
     EMPTYROWMAJORATT = 483,
     ROWMAJORATT = 484,
     BLOCKROWIDXATT = 485,
     BLOCKCOLIDXATT = 486,
     DUMMY = 487,
     NONLINEAREXPRESSIONSSTART = 488,
     NONLINEAREXPRESSIONSEND = 489,
     NUMBEROFNONLINEAREXPRESSIONS = 490,
     NLSTART = 491,
     NLEND = 492,
     POWERSTART = 493,
     POWEREND = 494,
     PLUSSTART = 495,
     PLUSEND = 496,
     MINUSSTART = 497,
     MINUSEND = 498,
     DIVIDESTART = 499,
     DIVIDEEND = 500,
     LNSTART = 501,
     LNEND = 502,
     SQRTSTART = 503,
     SQRTEND = 504,
     SUMSTART = 505,
     SUMEND = 506,
     PRODUCTSTART = 507,
     PRODUCTEND = 508,
     EXPSTART = 509,
     EXPEND = 510,
     NEGATESTART = 511,
     NEGATEEND = 512,
     IFSTART = 513,
     IFEND = 514,
     SQUARESTART = 515,
     SQUAREEND = 516,
     COSSTART = 517,
     COSEND = 518,
     SINSTART = 519,
     SINEND = 520,
     VARIABLESTART = 521,
     VARIABLEEND = 522,
     ABSSTART = 523,
     ABSEND = 524,
     ERFSTART = 525,
     ERFEND = 526,
     MAXSTART = 527,
     MAXEND = 528,
     ALLDIFFSTART = 529,
     ALLDIFFEND = 530,
     MINSTART = 531,
     MINEND = 532,
     ESTART = 533,
     EEND = 534,
     PISTART = 535,
     PIEND = 536,
     TIMESSTART = 537,
     TIMESEND = 538,
     NUMBERSTART = 539,
     NUMBEREND = 540,
     MATRIXDETERMINANTSTART = 541,
     MATRIXDETERMINANTEND = 542,
     MATRIXTRACESTART = 543,
     MATRIXTRACEEND = 544,
     MATRIXTOSCALARSTART = 545,
     MATRIXTOSCALAREND = 546,
     MATRIXDIAGONALSTART = 547,
     MATRIXDIAGONALEND = 548,
     MATRIXDOTTIMESSTART = 549,
     MATRIXDOTTIMESEND = 550,
     MATRIXLOWERTRIANGLESTART = 551,
     MATRIXLOWERTRIANGLEEND = 552,
     MATRIXUPPERTRIANGLESTART = 553,
     MATRIXUPPERTRIANGLEEND = 554,
     MATRIXMERGESTART = 555,
     MATRIXMERGEEND = 556,
     MATRIXMINUSSTART = 557,
     MATRIXMINUSEND = 558,
     MATRIXPLUSSTART = 559,
     MATRIXPLUSEND = 560,
     MATRIXTIMESSTART = 561,
     MATRIXTIMESEND = 562,
     MATRIXPRODUCTSTART = 563,
     MATRIXPRODUCTEND = 564,
     MATRIXSCALARTIMESSTART = 565,
     MATRIXSCALARTIMESEND = 566,
     MATRIXSUBMATRIXATSTART = 567,
     MATRIXSUBMATRIXATEND = 568,
     MATRIXTRANSPOSESTART = 569,
     MATRIXTRANSPOSEEND = 570,
     MATRIXREFERENCESTART = 571,
     MATRIXREFERENCEEND = 572,
     IDENTITYMATRIXSTART = 573,
     IDENTITYMATRIXEND = 574,
     MATRIXINVERSESTART = 575,
     MATRIXINVERSEEND = 576,
     EMPTYINCLUDEDIAGONALATT = 577,
     INCLUDEDIAGONALATT = 578,
     IDATT = 579,
     COEFATT = 580
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
#define NUMBEROFMATRIXTERMSATT 339
#define MATRIXTERMSTART 340
#define MATRIXTERMEND 341
#define MATRIXEXPRESSIONSSTART 342
#define MATRIXEXPRESSIONSEND 343
#define NUMBEROFMATRIXEXPRATT 344
#define MATRIXEXPRSTART 345
#define MATRIXEXPREND 346
#define MATRIXIDXATT 347
#define LBMATRIXIDXATT 348
#define LBCONEIDXATT 349
#define UBMATRIXIDXATT 350
#define UBCONEIDXATT 351
#define TEMPLATEMATRIXIDXATT 352
#define VARREFERENCEMATRIXIDXATT 353
#define OBJREFERENCEMATRIXIDXATT 354
#define CONREFERENCEMATRIXIDXATT 355
#define ORDERCONEIDXATT 356
#define CONSTANTMATRIXIDXATT 357
#define SHAPEATT 358
#define EMPTYSHAPEATT 359
#define TIMEDOMAINSTART 360
#define TIMEDOMAINEND 361
#define STAGESSTART 362
#define STAGESEND 363
#define STAGESTART 364
#define STAGEEND 365
#define NUMBEROFSTAGESATT 366
#define HORIZONATT 367
#define STARTATT 368
#define VARIABLESSTART 369
#define CONSTRAINTSSTART 370
#define OBJECTIVESSTART 371
#define VARIABLESEND 372
#define CONSTRAINTSEND 373
#define OBJECTIVESEND 374
#define NUMBEROFVARIABLESATT 375
#define NUMBEROFCONSTRAINTSATT 376
#define NUMBEROFOBJECTIVESATT 377
#define STARTIDXATT 378
#define VARSTART 379
#define VAREND 380
#define CONSTART 381
#define CONEND 382
#define OBJSTART 383
#define OBJEND 384
#define INTERVALSTART 385
#define INTERVALEND 386
#define HEADERSTART 387
#define HEADEREND 388
#define FILENAMESTART 389
#define FILENAMEEND 390
#define FILENAMEEMPTY 391
#define FILENAMESTARTANDEND 392
#define FILESOURCESTART 393
#define FILESOURCEEND 394
#define FILESOURCEEMPTY 395
#define FILESOURCESTARTANDEND 396
#define FILEDESCRIPTIONSTART 397
#define FILEDESCRIPTIONEND 398
#define FILEDESCRIPTIONEMPTY 399
#define FILEDESCRIPTIONSTARTANDEND 400
#define FILECREATORSTART 401
#define FILECREATOREND 402
#define FILECREATOREMPTY 403
#define FILECREATORSTARTANDEND 404
#define FILELICENCESTART 405
#define FILELICENCEEND 406
#define FILELICENCEEMPTY 407
#define FILELICENCESTARTANDEND 408
#define ENUMERATIONSTART 409
#define ENUMERATIONEND 410
#define NUMBEROFELATT 411
#define ITEMEMPTY 412
#define ITEMSTART 413
#define ITEMEND 414
#define ITEMSTARTANDEND 415
#define BASE64START 416
#define BASE64END 417
#define INCRATT 418
#define MULTATT 419
#define SIZEOFATT 420
#define ELSTART 421
#define ELEND 422
#define MATRIXSTART 423
#define MATRIXEND 424
#define BASEMATRIXEND 425
#define BASEMATRIXSTART 426
#define BLOCKSTART 427
#define BLOCKEND 428
#define BLOCKSSTART 429
#define BLOCKSEND 430
#define EMPTYSYMMETRYATT 431
#define SYMMETRYATT 432
#define EMPTYNEGATIVEPATTERNATT 433
#define NEGATIVEPATTERNATT 434
#define CONSTANTATT 435
#define NUMBEROFBLOCKSATT 436
#define NUMBEROFCOLUMNSATT 437
#define NUMBEROFROWSATT 438
#define NUMBEROFVALUESATT 439
#define NUMBEROFVARIDXATT 440
#define BASEMATRIXIDXATT 441
#define TARGETMATRIXFIRSTROWATT 442
#define TARGETMATRIXFIRSTCOLATT 443
#define BASEMATRIXSTARTROWATT 444
#define BASEMATRIXSTARTCOLATT 445
#define BASEMATRIXENDROWATT 446
#define BASEMATRIXENDCOLATT 447
#define SCALARMULTIPLIERATT 448
#define EMPTYBASETRANSPOSEATT 449
#define BASETRANSPOSEATT 450
#define ELEMENTSSTART 451
#define ELEMENTSEND 452
#define CONSTANTELEMENTSSTART 453
#define CONSTANTELEMENTSEND 454
#define STARTVECTORSTART 455
#define STARTVECTOREND 456
#define NONZEROSSTART 457
#define NONZEROSEND 458
#define INDEXESSTART 459
#define INDEXESEND 460
#define VALUESSTART 461
#define VALUESEND 462
#define VARREFERENCEELEMENTSSTART 463
#define VARREFERENCEELEMENTSEND 464
#define LINEARELEMENTSSTART 465
#define LINEARELEMENTSEND 466
#define GENERALELEMENTSSTART 467
#define GENERALELEMENTSEND 468
#define CONREFERENCEELEMENTSSTART 469
#define CONREFERENCEELEMENTSEND 470
#define OBJREFERENCEELEMENTSSTART 471
#define OBJREFERENCEELEMENTSEND 472
#define PATTERNELEMENTSSTART 473
#define PATTERNELEMENTSEND 474
#define VARIDXSTART 475
#define VARIDXEND 476
#define TRANSFORMATIONSTART 477
#define TRANSFORMATIONEND 478
#define COLOFFSETSSTART 479
#define COLOFFSETSEND 480
#define ROWOFFSETSSTART 481
#define ROWOFFSETSEND 482
#define EMPTYROWMAJORATT 483
#define ROWMAJORATT 484
#define BLOCKROWIDXATT 485
#define BLOCKCOLIDXATT 486
#define DUMMY 487
#define NONLINEAREXPRESSIONSSTART 488
#define NONLINEAREXPRESSIONSEND 489
#define NUMBEROFNONLINEAREXPRESSIONS 490
#define NLSTART 491
#define NLEND 492
#define POWERSTART 493
#define POWEREND 494
#define PLUSSTART 495
#define PLUSEND 496
#define MINUSSTART 497
#define MINUSEND 498
#define DIVIDESTART 499
#define DIVIDEEND 500
#define LNSTART 501
#define LNEND 502
#define SQRTSTART 503
#define SQRTEND 504
#define SUMSTART 505
#define SUMEND 506
#define PRODUCTSTART 507
#define PRODUCTEND 508
#define EXPSTART 509
#define EXPEND 510
#define NEGATESTART 511
#define NEGATEEND 512
#define IFSTART 513
#define IFEND 514
#define SQUARESTART 515
#define SQUAREEND 516
#define COSSTART 517
#define COSEND 518
#define SINSTART 519
#define SINEND 520
#define VARIABLESTART 521
#define VARIABLEEND 522
#define ABSSTART 523
#define ABSEND 524
#define ERFSTART 525
#define ERFEND 526
#define MAXSTART 527
#define MAXEND 528
#define ALLDIFFSTART 529
#define ALLDIFFEND 530
#define MINSTART 531
#define MINEND 532
#define ESTART 533
#define EEND 534
#define PISTART 535
#define PIEND 536
#define TIMESSTART 537
#define TIMESEND 538
#define NUMBERSTART 539
#define NUMBEREND 540
#define MATRIXDETERMINANTSTART 541
#define MATRIXDETERMINANTEND 542
#define MATRIXTRACESTART 543
#define MATRIXTRACEEND 544
#define MATRIXTOSCALARSTART 545
#define MATRIXTOSCALAREND 546
#define MATRIXDIAGONALSTART 547
#define MATRIXDIAGONALEND 548
#define MATRIXDOTTIMESSTART 549
#define MATRIXDOTTIMESEND 550
#define MATRIXLOWERTRIANGLESTART 551
#define MATRIXLOWERTRIANGLEEND 552
#define MATRIXUPPERTRIANGLESTART 553
#define MATRIXUPPERTRIANGLEEND 554
#define MATRIXMERGESTART 555
#define MATRIXMERGEEND 556
#define MATRIXMINUSSTART 557
#define MATRIXMINUSEND 558
#define MATRIXPLUSSTART 559
#define MATRIXPLUSEND 560
#define MATRIXTIMESSTART 561
#define MATRIXTIMESEND 562
#define MATRIXPRODUCTSTART 563
#define MATRIXPRODUCTEND 564
#define MATRIXSCALARTIMESSTART 565
#define MATRIXSCALARTIMESEND 566
#define MATRIXSUBMATRIXATSTART 567
#define MATRIXSUBMATRIXATEND 568
#define MATRIXTRANSPOSESTART 569
#define MATRIXTRANSPOSEEND 570
#define MATRIXREFERENCESTART 571
#define MATRIXREFERENCEEND 572
#define IDENTITYMATRIXSTART 573
#define IDENTITYMATRIXEND 574
#define MATRIXINVERSESTART 575
#define MATRIXINVERSEEND 576
#define EMPTYINCLUDEDIAGONALATT 577
#define INCLUDEDIAGONALATT 578
#define IDATT 579
#define COEFATT 580




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
#define YYLAST   1213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  330
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  660
/* YYNRULES -- Number of rules.  */
#define YYNRULES  962
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1519

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   580

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   327,
     329,     2,     2,   328,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   326,     2,     2,     2,     2,     2,     2,     2,
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
     325
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
     433,   435,   437,   439,   441,   444,   445,   449,   451,   453,
     455,   457,   459,   463,   465,   466,   469,   473,   475,   477,
     478,   481,   483,   485,   487,   489,   491,   493,   495,   497,
     499,   501,   503,   505,   509,   511,   513,   514,   517,   521,
     524,   526,   527,   531,   533,   535,   537,   539,   541,   545,
     547,   548,   551,   555,   557,   559,   560,   563,   565,   567,
     569,   571,   573,   575,   577,   579,   581,   583,   585,   587,
     589,   591,   595,   597,   599,   600,   604,   606,   608,   610,
     612,   614,   618,   619,   622,   628,   633,   634,   637,   639,
     641,   643,   645,   648,   652,   656,   661,   663,   669,   671,
     674,   675,   680,   681,   685,   687,   691,   695,   696,   700,
     701,   704,   706,   708,   713,   718,   720,   724,   726,   729,
     731,   734,   735,   740,   745,   747,   750,   751,   755,   756,
     759,   761,   763,   768,   773,   775,   779,   781,   784,   786,
     789,   790,   795,   800,   802,   805,   806,   810,   811,   814,
     816,   818,   823,   825,   829,   831,   834,   836,   839,   840,
     845,   850,   852,   855,   856,   861,   863,   866,   867,   870,
     872,   874,   879,   884,   889,   894,   899,   904,   909,   914,
     919,   924,   929,   934,   939,   943,   947,   952,   957,   962,
     967,   972,   976,   981,   986,   991,   996,  1001,  1006,  1011,
    1016,  1020,  1025,  1030,  1035,  1039,  1043,  1046,  1047,  1050,
    1052,  1054,  1056,  1058,  1060,  1062,  1063,  1066,  1070,  1072,
    1074,  1075,  1078,  1080,  1082,  1086,  1090,  1092,  1094,  1097,
    1099,  1103,  1105,  1107,  1108,  1111,  1115,  1117,  1118,  1120,
    1124,  1128,  1130,  1132,  1135,  1137,  1141,  1145,  1147,  1149,
    1150,  1153,  1155,  1157,  1159,  1161,  1163,  1167,  1171,  1175,
    1177,  1179,  1181,  1185,  1188,  1189,  1193,  1195,  1197,  1198,
    1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,  1217,  1219,
    1224,  1229,  1234,  1239,  1244,  1249,  1254,  1256,  1258,  1260,
    1262,  1266,  1271,  1274,  1276,  1277,  1280,  1282,  1284,  1286,
    1289,  1291,  1293,  1295,  1297,  1306,  1308,  1309,  1314,  1316,
    1318,  1319,  1322,  1324,  1326,  1330,  1331,  1334,  1337,  1339,
    1341,  1343,  1345,  1349,  1351,  1354,  1356,  1358,  1360,  1362,
    1366,  1368,  1371,  1373,  1375,  1377,  1379,  1383,  1385,  1386,
    1391,  1393,  1395,  1396,  1399,  1401,  1403,  1407,  1408,  1411,
    1414,  1416,  1418,  1420,  1422,  1426,  1428,  1431,  1433,  1435,
    1437,  1439,  1443,  1445,  1448,  1450,  1452,  1454,  1456,  1460,
    1462,  1463,  1468,  1470,  1472,  1473,  1476,  1478,  1480,  1484,
    1485,  1488,  1491,  1493,  1495,  1497,  1499,  1503,  1505,  1508,
    1510,  1512,  1514,  1516,  1520,  1522,  1523,  1526,  1528,  1530,
    1532,  1534,  1538,  1540,  1541,  1544,  1548,  1550,  1552,  1553,
    1556,  1558,  1560,  1565,  1567,  1569,  1571,  1575,  1576,  1579,
    1583,  1585,  1586,  1591,  1595,  1596,  1601,  1603,  1605,  1606,
    1609,  1611,  1613,  1617,  1618,  1621,  1624,  1626,  1628,  1630,
    1632,  1636,  1638,  1641,  1643,  1645,  1647,  1649,  1653,  1655,
    1656,  1659,  1661,  1663,  1665,  1667,  1671,  1672,  1675,  1678,
    1680,  1682,  1684,  1686,  1690,  1691,  1696,  1698,  1700,  1701,
    1704,  1706,  1708,  1712,  1713,  1716,  1719,  1721,  1723,  1725,
    1727,  1731,  1733,  1735,  1737,  1739,  1743,  1745,  1748,  1750,
    1752,  1754,  1756,  1760,  1762,  1765,  1767,  1769,  1771,  1773,
    1777,  1779,  1780,  1785,  1787,  1789,  1790,  1793,  1795,  1797,
    1801,  1802,  1805,  1808,  1810,  1812,  1814,  1816,  1820,  1822,
    1825,  1827,  1829,  1831,  1833,  1837,  1839,  1842,  1844,  1846,
    1848,  1850,  1854,  1856,  1861,  1863,  1865,  1869,  1871,  1873,
    1879,  1881,  1885,  1887,  1889,  1891,  1893,  1895,  1899,  1901,
    1905,  1907,  1909,  1911,  1913,  1915,  1919,  1921,  1922,  1925,
    1929,  1931,  1933,  1934,  1937,  1939,  1941,  1943,  1948,  1953,
    1955,  1957,  1959,  1963,  1966,  1971,  1976,  1981,  1986,  1991,
    1996,  2001,  2006,  2011,  2013,  2015,  2017,  2021,  2022,  2027,
    2029,  2035,  2036,  2039,  2045,  2047,  2052,  2054,  2056,  2058,
    2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,
    2100,  2102,  2104,  2106,  2107,  2111,  2113,  2116,  2117,  2121,
    2123,  2126,  2127,  2133,  2134,  2140,  2141,  2147,  2148,  2153,
    2154,  2160,  2161,  2167,  2168,  2173,  2174,  2179,  2180,  2185,
    2186,  2191,  2192,  2197,  2198,  2203,  2204,  2209,  2210,  2215,
    2216,  2223,  2224,  2229,  2230,  2235,  2236,  2241,  2242,  2247,
    2249,  2252,  2253,  2256,  2258,  2260,  2262,  2263,  2268,  2269,
    2274,  2279,  2280,  2285,  2287,  2290,  2291,  2296,  2297,  2300,
    2302,  2304,  2309,  2314,  2315,  2320,  2321,  2324,  2325,  2330,
    2331,  2334,  2335,  2340,  2341,  2344,  2345,  2350,  2351,  2354,
    2355,  2360,  2361,  2364,  2366,  2368,  2370,  2372,  2374,  2376,
    2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,  2394,  2395,
    2400,  2402,  2405,  2410,  2413,  2415,  2418,  2421,  2423,  2427,
    2430,  2432,  2435,  2438,  2440,  2443,  2448,  2450,  2451,  2453,
    2456,  2461,  2463,  2464,  2466,  2469,  2471,  2475,  2478,  2480,
    2482,  2485,  2488,  2490,  2494,  2497,  2499,  2503,  2506,  2508,
    2512,  2513,  2518,  2519,  2522,  2525,  2527,  2531,  2534,  2536,
    2543,  2546,  2548
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     331,     0,    -1,   335,   857,   347,   354,   422,   490,   332,
     333,    -1,    14,    -1,    13,    -1,   334,    -1,    12,    -1,
      -1,    -1,    24,   336,   337,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   337,   338,    -1,   339,   341,   340,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   341,
     342,    -1,   343,    -1,   344,    -1,   345,    -1,   346,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     325,     3,   577,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   348,   349,   350,    -1,    29,    -1,   548,    -1,   351,
      -1,   352,    -1,    10,    -1,    11,   353,    30,    -1,    -1,
     353,   603,    -1,    -1,   355,   356,   357,    -1,    32,    -1,
     549,    -1,   358,    -1,   359,    -1,    10,    -1,    11,   360,
      33,    -1,    -1,   360,   361,    -1,   362,    -1,   368,    -1,
     374,    -1,   380,    -1,   386,    -1,   392,    -1,   407,    -1,
     363,   364,   367,    -1,    35,    -1,   365,    -1,    -1,   365,
     366,    -1,   550,    -1,   551,    -1,   557,    -1,    10,    -1,
      11,    36,    -1,   369,   370,   373,    -1,    37,    -1,   371,
      -1,    -1,   371,   372,    -1,   550,    -1,   551,    -1,   557,
      -1,    10,    -1,    11,    38,    -1,   375,   376,   379,    -1,
      41,    -1,   377,    -1,    -1,   377,   378,    -1,   550,    -1,
     551,    -1,   557,    -1,   560,    -1,   559,    -1,   561,    -1,
      10,    -1,    11,    42,    -1,   381,   382,   385,    -1,    43,
      -1,   383,    -1,    -1,   383,   384,    -1,   550,    -1,   551,
      -1,   557,    -1,   560,    -1,   559,    -1,   562,    -1,   563,
      -1,    10,    -1,    11,    44,    -1,   387,   388,   391,    -1,
      45,    -1,   389,    -1,    -1,   389,   390,    -1,   550,    -1,
     551,    -1,   557,    -1,   564,    -1,    10,    -1,    11,    46,
      -1,   393,   394,   397,    -1,    47,    -1,   395,    -1,    -1,
     395,   396,    -1,   550,    -1,   551,    -1,   557,    -1,    11,
     398,   406,    -1,   399,   400,   401,    -1,    55,    -1,   547,
      -1,   402,    -1,   403,    -1,    10,    -1,    11,   404,   405,
      -1,   581,    -1,    56,    -1,    48,    -1,   408,   409,   412,
      -1,    49,    -1,   410,    -1,    -1,   410,   411,    -1,   550,
      -1,   551,    -1,   557,    -1,    11,   413,   421,    -1,   414,
     415,   416,    -1,    57,    -1,   547,    -1,   417,    -1,   418,
      -1,    10,    -1,    11,   419,   420,    -1,   581,    -1,    58,
      -1,    50,    -1,    -1,   423,   424,    -1,    66,    -1,   425,
      -1,   426,    -1,    10,    -1,    11,   427,   441,   463,   481,
      67,    -1,    -1,   428,   429,   430,    -1,    69,    -1,   552,
      -1,   431,    -1,   432,    -1,    10,    -1,    11,   434,   433,
      -1,    70,    -1,    -1,   434,   435,    -1,   436,   437,   440,
      -1,    72,    -1,   438,    -1,    -1,   438,   439,    -1,   848,
      -1,   846,    -1,   572,    -1,   574,    -1,   566,    -1,   568,
      -1,   569,    -1,   570,    -1,   557,    -1,   573,    -1,    10,
      -1,    11,    73,    -1,    -1,   442,   443,   444,    -1,    74,
      -1,   553,    -1,   445,    -1,   446,    -1,    10,    -1,    11,
     448,   447,    -1,    75,    -1,    -1,   448,   449,    -1,   450,
     451,   454,    -1,    77,    -1,   452,    -1,    -1,   452,   453,
      -1,   848,    -1,   846,    -1,   572,    -1,   575,    -1,   571,
      -1,   567,    -1,   557,    -1,   558,    -1,   555,    -1,   455,
      -1,   456,    -1,    10,    -1,    11,   457,   458,    -1,   459,
      -1,    78,    -1,    -1,   459,   460,    -1,   461,   940,   462,
      -1,    85,    11,    -1,    86,    -1,    -1,   464,   465,   466,
      -1,    79,    -1,   554,    -1,   467,    -1,   468,    -1,    10,
      -1,    11,   470,   469,    -1,    80,    -1,    -1,   470,   471,
      -1,   472,   473,   476,    -1,    82,    -1,   474,    -1,    -1,
     474,   475,    -1,   848,    -1,   846,    -1,   572,    -1,   576,
      -1,   566,    -1,   568,    -1,   569,    -1,   570,    -1,   557,
      -1,   558,    -1,   555,    -1,   477,    -1,   478,    -1,    10,
      -1,    11,   479,   480,    -1,   459,    -1,    83,    -1,    -1,
     482,   483,   484,    -1,    87,    -1,   556,    -1,   485,    -1,
     486,    -1,    10,    -1,    11,   487,    88,    -1,    -1,   487,
     488,    -1,    90,   489,    11,   864,    91,    -1,    18,     3,
       7,     3,    -1,    -1,   491,   492,    -1,   105,    -1,   493,
      -1,   494,    -1,    10,    -1,    11,   106,    -1,    11,   495,
     106,    -1,    11,   539,   106,    -1,   496,   497,   498,   108,
      -1,   107,    -1,   111,     3,     7,     3,    11,    -1,   499,
      -1,   498,   499,    -1,    -1,   500,   109,   501,   502,    -1,
      -1,    21,     4,     3,    -1,    10,    -1,    11,   503,   110,
      -1,   504,   516,   528,    -1,    -1,   114,   505,   509,    -1,
      -1,   505,   506,    -1,   507,    -1,   508,    -1,   120,     3,
       7,     3,    -1,   123,     3,     7,     3,    -1,   510,    -1,
      11,   511,   117,    -1,    10,    -1,    11,   117,    -1,   512,
      -1,   511,   512,    -1,    -1,   513,   124,   514,   515,    -1,
      18,     3,     7,     3,    -1,    10,    -1,    11,   125,    -1,
      -1,   115,   517,   521,    -1,    -1,   517,   518,    -1,   519,
      -1,   520,    -1,   121,     3,     7,     3,    -1,   123,     3,
       7,     3,    -1,   522,    -1,    11,   523,   118,    -1,    10,
      -1,    11,   118,    -1,   524,    -1,   523,   524,    -1,    -1,
     525,   126,   526,   527,    -1,    18,     3,     7,     3,    -1,
      10,    -1,    11,   127,    -1,    -1,   116,   529,   532,    -1,
      -1,   529,   530,    -1,   531,    -1,   544,    -1,   122,     3,
       7,     3,    -1,   533,    -1,    11,   534,   119,    -1,    10,
      -1,    11,   119,    -1,   535,    -1,   534,   535,    -1,    -1,
     536,   128,   537,   538,    -1,    18,     3,     7,     3,    -1,
      10,    -1,    11,   129,    -1,    -1,   540,   130,   542,   541,
      -1,    10,    -1,    11,   131,    -1,    -1,   542,   543,    -1,
     545,    -1,   546,    -1,   123,     3,     7,     3,    -1,   112,
       3,   577,     3,    -1,   113,     3,   577,     3,    -1,   156,
     578,     7,   578,    -1,    31,     3,     7,     3,    -1,    34,
       3,     7,     3,    -1,   183,     3,     7,     3,    -1,   182,
       3,     7,     3,    -1,    71,     3,     7,     3,    -1,    76,
       3,     7,     3,    -1,    81,     3,     7,     3,    -1,    84,
       3,     7,     3,    -1,    89,     3,     7,     3,    -1,    21,
       4,     3,    -1,   103,     4,     3,    -1,    59,     3,   577,
       3,    -1,    60,     3,     7,     3,    -1,    61,     3,     7,
       3,    -1,    62,     3,     7,     3,    -1,    63,     3,     7,
       3,    -1,    65,     4,     3,    -1,    92,     3,     7,     3,
      -1,    93,     3,     7,     3,    -1,   102,     3,     7,     3,
      -1,    94,     3,     7,     3,    -1,    95,     3,     7,     3,
      -1,    96,     3,     7,     3,    -1,   101,     3,     7,     3,
      -1,    97,     3,     7,     3,    -1,    68,     4,     3,    -1,
      98,     3,     7,     3,    -1,    99,     3,     7,     3,    -1,
     100,     3,     7,     3,    -1,   579,     7,   579,    -1,   579,
       8,   579,    -1,   579,     3,    -1,    -1,   579,   580,    -1,
     326,    -1,   327,    -1,   328,    -1,   329,    -1,   582,    -1,
     589,    -1,    -1,   582,   583,    -1,   584,   585,   588,    -1,
     166,    -1,   586,    -1,    -1,   586,   587,    -1,   853,    -1,
     852,    -1,    11,     7,   167,    -1,   161,   851,   590,    -1,
     591,    -1,   592,    -1,    11,   162,    -1,    10,    -1,    11,
       5,   162,    -1,   594,    -1,   599,    -1,    -1,   594,   595,
      -1,   596,   597,   598,    -1,   166,    -1,    -1,   853,    -1,
      11,   577,   167,    -1,   161,   851,   600,    -1,   601,    -1,
     602,    -1,    11,   162,    -1,    10,    -1,    11,     5,   162,
      -1,   604,   605,   611,    -1,   168,    -1,   606,    -1,    -1,
     606,   607,    -1,   608,    -1,   848,    -1,   846,    -1,   609,
      -1,   610,    -1,   177,     4,     3,    -1,    21,     4,     3,
      -1,    22,     4,     3,    -1,   612,    -1,   613,    -1,    10,
      -1,    11,   614,   169,    -1,   615,   633,    -1,    -1,   616,
     617,   632,    -1,   171,    -1,   618,    -1,    -1,   618,   619,
      -1,   620,    -1,   621,    -1,   622,    -1,   623,    -1,   624,
      -1,   625,    -1,   626,    -1,   627,    -1,   631,    -1,   186,
       3,     7,     3,    -1,   187,     3,     7,     3,    -1,   188,
       3,     7,     3,    -1,   189,     3,     7,     3,    -1,   190,
       3,     7,     3,    -1,   191,     3,     7,     3,    -1,   192,
       3,     7,     3,    -1,   628,    -1,   629,    -1,   630,    -1,
     194,    -1,   195,     4,   578,    -1,   193,     3,   577,     3,
      -1,    11,   170,    -1,    10,    -1,    -1,   633,   634,    -1,
     635,    -1,   811,    -1,   814,    -1,   636,   637,    -1,   196,
      -1,   638,    -1,   639,    -1,    10,    -1,    11,   641,   666,
     691,   731,   786,   761,   640,    -1,   197,    -1,    -1,   642,
     643,    11,   646,    -1,   198,    -1,   644,    -1,    -1,   644,
     645,    -1,   849,    -1,   854,    -1,   648,   647,   199,    -1,
      -1,   654,   660,    -1,   649,   650,    -1,   200,    -1,   651,
      -1,   652,    -1,    10,    -1,    11,   653,   201,    -1,   581,
      -1,   655,   656,    -1,   204,    -1,   657,    -1,   658,    -1,
      10,    -1,    11,   659,   205,    -1,   581,    -1,   661,   662,
      -1,   206,    -1,   663,    -1,   664,    -1,    10,    -1,    11,
     665,   207,    -1,   593,    -1,    -1,   667,   668,    11,   671,
      -1,   208,    -1,   669,    -1,    -1,   669,   670,    -1,   849,
      -1,   854,    -1,   673,   672,   209,    -1,    -1,   679,   685,
      -1,   674,   675,    -1,   200,    -1,   676,    -1,   677,    -1,
      10,    -1,    11,   678,   201,    -1,   581,    -1,   680,   681,
      -1,   204,    -1,   682,    -1,   683,    -1,    10,    -1,    11,
     684,   205,    -1,   581,    -1,   686,   687,    -1,   206,    -1,
     688,    -1,   689,    -1,    10,    -1,    11,   690,   207,    -1,
     581,    -1,    -1,   692,   693,    11,   696,    -1,   210,    -1,
     694,    -1,    -1,   694,   695,    -1,   849,    -1,   854,    -1,
     698,   697,   211,    -1,    -1,   704,   710,    -1,   699,   700,
      -1,   200,    -1,   701,    -1,   702,    -1,    10,    -1,    11,
     703,   201,    -1,   581,    -1,   705,   706,    -1,   204,    -1,
     707,    -1,   708,    -1,    10,    -1,    11,   709,   205,    -1,
     581,    -1,    -1,   711,   712,    -1,   206,    -1,   713,    -1,
     714,    -1,    10,    -1,    11,   715,   207,    -1,   716,    -1,
      -1,   716,   717,    -1,   718,   719,   723,    -1,   166,    -1,
     720,    -1,    -1,   720,   721,    -1,   850,    -1,   722,    -1,
     180,     3,   577,     3,    -1,   724,    -1,   725,    -1,    10,
      -1,    11,   726,   167,    -1,    -1,   726,   727,    -1,   728,
     729,   730,    -1,   220,    -1,    -1,   325,     3,   577,     3,
      -1,    11,     7,   221,    -1,    -1,   732,   733,    11,   736,
      -1,   212,    -1,   734,    -1,    -1,   734,   735,    -1,   849,
      -1,   854,    -1,   738,   737,   213,    -1,    -1,   744,   750,
      -1,   739,   740,    -1,   200,    -1,   741,    -1,   742,    -1,
      10,    -1,    11,   743,   201,    -1,   581,    -1,   745,   746,
      -1,   204,    -1,   747,    -1,   748,    -1,    10,    -1,    11,
     749,   205,    -1,   581,    -1,    -1,   751,   752,    -1,   206,
      -1,   753,    -1,   754,    -1,    10,    -1,    11,   755,   207,
      -1,    -1,   755,   756,    -1,   757,   758,    -1,   166,    -1,
     759,    -1,   760,    -1,    10,    -1,    11,   864,   167,    -1,
      -1,   762,   763,    11,   766,    -1,   214,    -1,   764,    -1,
      -1,   764,   765,    -1,   849,    -1,   854,    -1,   768,   767,
     215,    -1,    -1,   774,   780,    -1,   769,   770,    -1,   200,
      -1,   771,    -1,   772,    -1,    10,    -1,    11,   773,   201,
      -1,   581,    -1,   771,    -1,   772,    -1,    10,    -1,    11,
     773,   201,    -1,   581,    -1,   775,   776,    -1,   204,    -1,
     777,    -1,   778,    -1,    10,    -1,    11,   779,   205,    -1,
     581,    -1,   781,   782,    -1,   206,    -1,   783,    -1,   784,
      -1,    10,    -1,    11,   785,   207,    -1,   581,    -1,    -1,
     787,   788,    11,   791,    -1,   216,    -1,   789,    -1,    -1,
     789,   790,    -1,   849,    -1,   854,    -1,   793,   792,   217,
      -1,    -1,   799,   805,    -1,   794,   795,    -1,   200,    -1,
     796,    -1,   797,    -1,    10,    -1,    11,   798,   201,    -1,
     581,    -1,   800,   801,    -1,   204,    -1,   802,    -1,   803,
      -1,    10,    -1,    11,   804,   205,    -1,   581,    -1,   806,
     807,    -1,   206,    -1,   808,    -1,   809,    -1,    10,    -1,
      11,   810,   207,    -1,   581,    -1,   812,    11,   940,   813,
      -1,   222,    -1,   223,    -1,   815,   816,   817,    -1,   174,
      -1,   845,    -1,    11,   819,   826,   833,   818,    -1,   175,
      -1,   820,   821,   822,    -1,   224,    -1,   847,    -1,   823,
      -1,   824,    -1,    10,    -1,    11,   825,   225,    -1,   581,
      -1,   827,   828,   829,    -1,   226,    -1,   847,    -1,   830,
      -1,   831,    -1,    10,    -1,    11,   832,   227,    -1,   581,
      -1,    -1,   833,   834,    -1,   835,   836,   841,    -1,   172,
      -1,   837,    -1,    -1,   837,   838,    -1,   839,    -1,   840,
      -1,   608,    -1,   230,   578,     7,   578,    -1,   231,   578,
       7,   578,    -1,   842,    -1,   843,    -1,    10,    -1,    11,
     844,   173,    -1,   615,   633,    -1,   181,     3,     7,     3,
      -1,   182,     3,     7,     3,    -1,   156,     3,     7,     3,
      -1,   183,     3,     7,     3,    -1,   184,     3,     7,     3,
      -1,   185,     3,     7,     3,    -1,   165,     3,     7,     3,
      -1,   163,     3,     7,     3,    -1,   164,     3,     7,     3,
      -1,   855,    -1,   856,    -1,   228,    -1,   229,     4,     3,
      -1,    -1,   858,   859,   860,   234,    -1,   233,    -1,   235,
       3,     7,     3,    11,    -1,    -1,   860,   861,    -1,   862,
     863,    11,   864,   237,    -1,   236,    -1,    18,     3,     7,
       3,    -1,   907,    -1,   917,    -1,   871,    -1,   873,    -1,
     925,    -1,   875,    -1,   877,    -1,   879,    -1,   881,    -1,
     937,    -1,   883,    -1,   885,    -1,   887,    -1,   891,    -1,
     889,    -1,   893,    -1,   899,    -1,   895,    -1,   897,    -1,
     931,    -1,   934,    -1,   865,    -1,   868,    -1,   928,    -1,
     901,    -1,   903,    -1,   905,    -1,    -1,   278,   866,   867,
      -1,    10,    -1,    11,   279,    -1,    -1,   280,   869,   870,
      -1,    10,    -1,    11,   281,    -1,    -1,   282,   872,   864,
     864,   283,    -1,    -1,   240,   874,   864,   864,   241,    -1,
      -1,   242,   876,   864,   864,   243,    -1,    -1,   256,   878,
     864,   257,    -1,    -1,   244,   880,   864,   864,   245,    -1,
      -1,   238,   882,   864,   864,   239,    -1,    -1,   246,   884,
     864,   247,    -1,    -1,   248,   886,   864,   249,    -1,    -1,
     260,   888,   864,   261,    -1,    -1,   262,   890,   864,   263,
      -1,    -1,   264,   892,   864,   265,    -1,    -1,   254,   894,
     864,   255,    -1,    -1,   268,   896,   864,   269,    -1,    -1,
     270,   898,   864,   271,    -1,    -1,   258,   900,   864,   864,
     864,   259,    -1,    -1,   286,   902,   940,   287,    -1,    -1,
     288,   904,   940,   289,    -1,    -1,   290,   906,   940,   291,
      -1,    -1,   284,   908,   910,   909,    -1,    10,    -1,    11,
     285,    -1,    -1,   910,   911,    -1,   912,    -1,   916,    -1,
     914,    -1,    -1,    22,     4,   913,     3,    -1,    -1,   324,
       4,   915,     3,    -1,    23,     3,   577,     3,    -1,    -1,
     266,   918,   921,   919,    -1,    10,    -1,    11,   267,    -1,
      -1,    11,   864,   920,   267,    -1,    -1,   921,   922,    -1,
     923,    -1,   924,    -1,   325,     3,   577,     3,    -1,    18,
       3,     7,     3,    -1,    -1,   250,   926,   927,   251,    -1,
      -1,   927,   864,    -1,    -1,   274,   929,   930,   275,    -1,
      -1,   930,   864,    -1,    -1,   272,   932,   933,   273,    -1,
      -1,   933,   864,    -1,    -1,   276,   935,   936,   277,    -1,
      -1,   936,   864,    -1,    -1,   252,   938,   939,   253,    -1,
      -1,   939,   864,    -1,   941,    -1,   944,    -1,   947,    -1,
     953,    -1,   956,    -1,   960,    -1,   966,    -1,   969,    -1,
     972,    -1,   975,    -1,   978,    -1,   981,    -1,   984,    -1,
     987,    -1,   950,    -1,    -1,   316,   942,   565,   943,    -1,
      10,    -1,    11,   317,    -1,    18,     3,     7,     3,    -1,
     945,   946,    -1,   292,    -1,   940,   293,    -1,   948,   949,
      -1,   294,    -1,   940,   940,   295,    -1,   951,   952,    -1,
     318,    -1,   864,   319,    -1,   954,   955,    -1,   320,    -1,
     940,   321,    -1,   957,   958,    11,   959,    -1,   296,    -1,
      -1,   964,    -1,   940,   297,    -1,   961,   962,    11,   963,
      -1,   298,    -1,    -1,   964,    -1,   940,   299,    -1,   965,
      -1,   323,     4,     3,    -1,   967,   968,    -1,   300,    -1,
      10,    -1,    11,   301,    -1,   970,   971,    -1,   302,    -1,
     940,   940,   303,    -1,   973,   974,    -1,   304,    -1,   940,
     940,   305,    -1,   976,   977,    -1,   306,    -1,   940,   940,
     307,    -1,    -1,   308,   979,   980,   309,    -1,    -1,   980,
     940,    -1,   982,   983,    -1,   310,    -1,   864,   940,   311,
      -1,   985,   986,    -1,   312,    -1,   940,   864,   864,   864,
     864,   313,    -1,   988,   989,    -1,   314,    -1,   940,   315,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   386,   386,   389,   390,   392,   401,   402,   405,   406,
     411,   418,   418,   420,   433,   439,   440,   443,   444,   447,
     450,   453,   456,   462,   469,   476,   484,   489,   489,   495,
     500,   513,   513,   515,   517,   524,   524,   527,   527,   529,
     531,   533,   533,   535,   537,   539,   539,   541,   542,   544,
     545,   547,   554,   555,   560,   562,   564,   566,   566,   569,
     570,   571,   573,   573,   575,   577,   579,   581,   581,   584,
     585,   586,   588,   588,   592,   594,   596,   598,   598,   601,
     602,   603,   604,   605,   606,   609,   609,   611,   613,   615,
     617,   617,   620,   621,   622,   623,   624,   625,   626,   629,
     629,   633,   635,   637,   639,   639,   642,   643,   644,   645,
     648,   648,   662,   664,   666,   668,   668,   671,   672,   673,
     676,   678,   680,   682,   684,   684,   686,   688,   690,   692,
     694,   696,   698,   700,   702,   702,   705,   706,   707,   710,
     712,   714,   716,   718,   718,   720,   722,   724,   726,   728,
     737,   737,   739,   741,   741,   743,   746,   748,   748,   750,
     752,   754,   754,   756,   758,   760,   762,   762,   764,   766,
     768,   770,   770,   773,   774,   775,   776,   777,   778,   779,
     780,   781,   782,   785,   786,   788,   788,   790,   792,   794,
     794,   796,   798,   800,   802,   802,   804,   806,   808,   810,
     810,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     824,   824,   826,   828,   830,   832,   836,   836,   838,   840,
     842,   845,   845,   847,   849,   851,   851,   853,   855,   857,
     859,   859,   861,   863,   865,   867,   867,   870,   871,   872,
     873,   874,   875,   876,   877,   878,   879,   880,   883,   883,
     885,   887,   889,   891,   894,   894,   896,   898,   900,   900,
     902,   904,   906,   906,   908,   910,   912,   912,   914,   916,
     916,   918,   919,   922,   923,   926,   977,   979,   993,   994,
     996,   996,  1020,  1021,  1024,  1025,  1027,  1029,  1030,  1034,
    1035,  1037,  1038,  1040,  1056,  1064,  1071,  1076,  1077,  1079,
    1080,  1082,  1082,  1085,  1094,  1095,  1097,  1098,  1102,  1103,
    1105,  1106,  1108,  1124,  1132,  1139,  1144,  1145,  1147,  1148,
    1150,  1150,  1153,  1162,  1163,  1165,  1175,  1179,  1180,  1182,
    1183,  1185,  1201,  1208,  1213,  1214,  1216,  1217,  1219,  1219,
    1222,  1231,  1232,  1237,  1237,  1245,  1246,  1248,  1249,  1251,
    1255,  1261,  1269,  1273,  1278,  1287,  1298,  1309,  1320,  1331,
    1339,  1347,  1355,  1363,  1372,  1381,  1389,  1400,  1411,  1423,
    1434,  1445,  1456,  1467,  1478,  1489,  1500,  1511,  1522,  1533,
    1545,  1557,  1568,  1579,  1592,  1593,  1600,  1602,  1602,  1604,
    1605,  1606,  1607,  1772,  1781,  1783,  1783,  1785,  1787,  1796,
    1798,  1798,  1800,  1800,  1802,  1819,  1822,  1822,  1824,  1824,
    1827,  1858,  1866,  1868,  1868,  1870,  1872,  1880,  1880,  1882,
    1899,  1901,  1901,  1903,  1903,  1905,  2001,  2010,  2032,  2050,
    2050,  2053,  2054,  2055,  2056,  2057,  2060,  2072,  2084,  2096,
    2096,  2098,  2100,  2109,  2111,  2111,  2116,  2134,  2158,  2158,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2171,
    2186,  2196,  2206,  2216,  2226,  2238,  2250,  2257,  2257,  2259,
    2264,  2276,  2284,  2284,  2286,  2286,  2291,  2291,  2291,  2293,
    2299,  2309,  2309,  2311,  2313,  2316,  2318,  2318,  2320,  2329,
    2335,  2335,  2338,  2342,  2348,  2350,  2350,  2352,  2361,  2372,
    2372,  2374,  2376,  2378,  2381,  2391,  2399,  2399,  2401,  2403,
    2405,  2408,  2417,  2425,  2425,  2427,  2429,  2431,  2452,  2452,
    2454,  2461,  2467,  2467,  2470,  2474,  2480,  2482,  2482,  2484,
    2493,  2504,  2504,  2506,  2508,  2510,  2512,  2521,  2529,  2529,
    2531,  2533,  2535,  2538,  2547,  2555,  2555,  2557,  2559,  2561,
    2590,  2590,  2592,  2599,  2605,  2605,  2608,  2612,  2618,  2620,
    2620,  2622,  2631,  2643,  2643,  2645,  2647,  2649,  2652,  2661,
    2669,  2669,  2671,  2673,  2675,  2734,  2739,  2751,  2768,  2768,
    2770,  2772,  2774,  2776,  2776,  2778,  2786,  2792,  2802,  2802,
    2805,  2806,  2808,  2820,  2820,  2822,  2824,  2826,  2826,  2829,
    2831,  2839,  2839,  2844,  2850,  2850,  2852,  2859,  2865,  2865,
    2868,  2872,  2878,  2880,  2880,  2882,  2891,  2903,  2903,  2905,
    2907,  2909,  2912,  2921,  2929,  2929,  2931,  2933,  2935,  2997,
    2998,  3000,  3015,  3015,  3017,  3019,  3021,  3021,  3023,  3025,
    3036,  3036,  3038,  3040,  3050,  3050,  3052,  3059,  3065,  3065,
    3068,  3072,  3078,  3080,  3080,  3082,  3091,  3103,  3103,  3105,
    3107,  3109,  3111,  3111,  3113,  3115,  3117,  3119,  3128,  3136,
    3136,  3138,  3140,  3142,  3145,  3154,  3162,  3162,  3164,  3166,
    3168,  3197,  3197,  3199,  3206,  3212,  3212,  3215,  3219,  3225,
    3227,  3227,  3229,  3238,  3250,  3250,  3252,  3254,  3256,  3259,
    3268,  3276,  3276,  3278,  3280,  3282,  3285,  3294,  3302,  3302,
    3304,  3306,  3308,  3416,  3421,  3427,  3429,  3431,  3437,  3442,
    3447,  3449,  3463,  3469,  3475,  3475,  3477,  3479,  3481,  3483,
    3497,  3503,  3509,  3509,  3511,  3513,  3515,  3517,  3517,  3519,
    3521,  3523,  3525,  3525,  3528,  3529,  3530,  3537,  3546,  3555,
    3555,  3557,  3559,  3561,  3563,  3572,  3581,  3590,  3599,  3608,
    3617,  3622,  3630,  3639,  3639,  3641,  3650,  3704,  3705,  3711,
    3716,  3735,  3736,  3738,  3746,  3760,  3770,  3771,  3772,  3773,
    3774,  3775,  3776,  3777,  3778,  3779,  3780,  3781,  3782,  3783,
    3784,  3785,  3786,  3787,  3788,  3789,  3790,  3791,  3792,  3793,
    3795,  3796,  3797,  3801,  3801,  3804,  3805,  3807,  3807,  3810,
    3811,  3815,  3815,  3820,  3820,  3825,  3825,  3830,  3830,  3835,
    3835,  3840,  3840,  3845,  3845,  3850,  3850,  3855,  3855,  3860,
    3860,  3865,  3865,  3870,  3870,  3875,  3875,  3882,  3882,  3888,
    3888,  3897,  3897,  3902,  3902,  3907,  3907,  3917,  3917,  3922,
    3923,  3925,  3926,  3928,  3929,  3930,  3934,  3933,  3942,  3941,
    3949,  3959,  3958,  3965,  3966,  3968,  3967,  3974,  3975,  3978,
    3984,  3992,  3999,  4019,  4019,  4030,  4030,  4033,  4033,  4045,
    4046,  4049,  4049,  4060,  4061,  4064,  4064,  4075,  4076,  4079,
    4079,  4089,  4090,  4096,  4097,  4098,  4099,  4100,  4101,  4102,
    4103,  4104,  4105,  4106,  4107,  4108,  4109,  4110,  4114,  4113,
    4120,  4121,  4123,  4131,  4133,  4139,  4141,  4143,  4149,  4151,
    4153,  4159,  4161,  4163,  4169,  4171,  4173,  4179,  4179,  4181,
    4183,  4185,  4191,  4191,  4193,  4195,  4202,  4212,  4214,  4219,
    4219,  4221,  4223,  4229,  4231,  4233,  4239,  4241,  4243,  4249,
    4252,  4252,  4262,  4263,  4267,  4269,  4275,  4277,  4279,  4285,
    4287,  4289,  4295
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
  "MATRIXPROGRAMMINGSTART", "MATRIXPROGRAMMINGEND", "VARTYPEATT",
  "MATRIXVARIABLESSTART", "MATRIXVARIABLESEND", "NUMBEROFMATRIXVARATT",
  "MATRIXVARSTART", "MATRIXVAREND", "MATRIXOBJECTIVESSTART",
  "MATRIXOBJECTIVESEND", "NUMBEROFMATRIXOBJATT", "MATRIXOBJSTART",
  "MATRIXOBJEND", "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND",
  "NUMBEROFMATRIXCONATT", "MATRIXCONSTART", "MATRIXCONEND",
  "NUMBEROFMATRIXTERMSATT", "MATRIXTERMSTART", "MATRIXTERMEND",
  "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND",
  "NUMBEROFMATRIXEXPRATT", "MATRIXEXPRSTART", "MATRIXEXPREND",
  "MATRIXIDXATT", "LBMATRIXIDXATT", "LBCONEIDXATT", "UBMATRIXIDXATT",
  "UBCONEIDXATT", "TEMPLATEMATRIXIDXATT", "VARREFERENCEMATRIXIDXATT",
  "OBJREFERENCEMATRIXIDXATT", "CONREFERENCEMATRIXIDXATT",
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
  "templateMatrixIdxATT", "varTypeATT", "varReferenceMatrixIdxATT",
  "objReferenceMatrixIdxATT", "conReferenceMatrixIdxATT", "aNumber",
  "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "osglIntVectorBase64Content", "osglIntVectorBase64Empty",
  "osglIntVectorBase64Laden", "osglDblArrayData", "osglDblVectorElArray",
  "osglDblVectorEl", "osglDblVectorElStart", "osglDblVectorElAttributes",
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
  "conReferenceElementsValuesBody", "objReferenceElements",
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
     575,   576,   577,   578,   579,   580,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   330,   331,   332,   332,   333,   334,   334,   335,   335,
     336,   337,   337,   338,   339,   340,   340,   341,   341,   342,
     342,   342,   342,   343,   344,   345,   346,   347,   347,   348,
     349,   350,   350,   351,   352,   353,   353,   354,   354,   355,
     356,   357,   357,   358,   359,   360,   360,   361,   361,   361,
     361,   361,   361,   361,   362,   363,   364,   365,   365,   366,
     366,   366,   367,   367,   368,   369,   370,   371,   371,   372,
     372,   372,   373,   373,   374,   375,   376,   377,   377,   378,
     378,   378,   378,   378,   378,   379,   379,   380,   381,   382,
     383,   383,   384,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   387,   388,   389,   389,   390,   390,   390,   390,
     391,   391,   392,   393,   394,   395,   395,   396,   396,   396,
     397,   398,   399,   400,   401,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   410,   411,   411,   411,   412,
     413,   414,   415,   416,   416,   417,   418,   419,   420,   421,
     422,   422,   423,   424,   424,   425,   426,   427,   427,   428,
     429,   430,   430,   431,   432,   433,   434,   434,   435,   436,
     437,   438,   438,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   440,   440,   441,   441,   442,   443,   444,
     444,   445,   446,   447,   448,   448,   449,   450,   451,   452,
     452,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     454,   454,   455,   456,   457,   458,   459,   459,   460,   461,
     462,   463,   463,   464,   465,   466,   466,   467,   468,   469,
     470,   470,   471,   472,   473,   474,   474,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   476,   476,
     477,   478,   479,   480,   481,   481,   482,   483,   484,   484,
     485,   486,   487,   487,   488,   489,   490,   490,   491,   492,
     492,   493,   493,   494,   494,   495,   496,   497,   498,   498,
     500,   499,   501,   501,   502,   502,   503,   504,   504,   505,
     505,   506,   506,   507,   508,   509,   509,   510,   510,   511,
     511,   513,   512,   514,   515,   515,   516,   516,   517,   517,
     518,   518,   519,   520,   521,   521,   522,   522,   523,   523,
     525,   524,   526,   527,   527,   528,   528,   529,   529,   530,
     530,   531,   532,   532,   533,   533,   534,   534,   536,   535,
     537,   538,   538,   540,   539,   541,   541,   542,   542,   543,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   577,   578,   579,   579,   580,
     580,   580,   580,   581,   581,   582,   582,   583,   584,   585,
     586,   586,   587,   587,   588,   589,   590,   590,   591,   591,
     592,   593,   593,   594,   594,   595,   596,   597,   597,   598,
     599,   600,   600,   601,   601,   602,   603,   604,   605,   606,
     606,   607,   607,   607,   607,   607,   608,   609,   610,   611,
     611,   612,   613,   614,   615,   615,   616,   617,   618,   618,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   628,   629,
     630,   631,   632,   632,   633,   633,   634,   634,   634,   635,
     636,   637,   637,   638,   639,   640,   641,   641,   642,   643,
     644,   644,   645,   645,   646,   647,   647,   648,   649,   650,
     650,   651,   652,   653,   654,   655,   656,   656,   657,   658,
     659,   660,   661,   662,   662,   663,   664,   665,   666,   666,
     667,   668,   669,   669,   670,   670,   671,   672,   672,   673,
     674,   675,   675,   676,   677,   678,   679,   680,   681,   681,
     682,   683,   684,   685,   686,   687,   687,   688,   689,   690,
     691,   691,   692,   693,   694,   694,   695,   695,   696,   697,
     697,   698,   699,   700,   700,   701,   702,   703,   704,   705,
     706,   706,   707,   708,   709,   710,   710,   711,   712,   712,
     713,   714,   715,   716,   716,   717,   718,   719,   720,   720,
     721,   721,   722,   723,   723,   724,   725,   726,   726,   727,
     728,   729,   729,   730,   731,   731,   732,   733,   734,   734,
     735,   735,   736,   737,   737,   738,   739,   740,   740,   741,
     742,   743,   744,   745,   746,   746,   747,   748,   749,   750,
     750,   751,   752,   752,   753,   754,   755,   755,   756,   757,
     758,   758,   759,   760,   761,   761,   762,   763,   764,   764,
     765,   765,   766,   767,   767,   768,   769,   770,   770,   771,
     772,   773,   770,   770,   771,   772,   773,   774,   775,   776,
     776,   777,   778,   779,   780,   781,   782,   782,   783,   784,
     785,   786,   786,   787,   788,   789,   789,   790,   790,   791,
     792,   792,   793,   794,   795,   795,   796,   797,   798,   799,
     800,   801,   801,   802,   803,   804,   805,   806,   807,   807,
     808,   809,   810,   811,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   822,   823,   824,   825,   826,
     827,   828,   829,   829,   830,   831,   832,   833,   833,   834,
     835,   836,   837,   837,   838,   838,   838,   839,   840,   841,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   854,   854,   855,   856,   857,   857,   858,
     859,   860,   860,   861,   862,   863,   864,   864,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   866,   865,   867,   867,   869,   868,   870,
     870,   872,   871,   874,   873,   876,   875,   878,   877,   880,
     879,   882,   881,   884,   883,   886,   885,   888,   887,   890,
     889,   892,   891,   894,   893,   896,   895,   898,   897,   900,
     899,   902,   901,   904,   903,   906,   905,   908,   907,   909,
     909,   910,   910,   911,   911,   911,   913,   912,   915,   914,
     916,   918,   917,   919,   919,   920,   919,   921,   921,   922,
     922,   923,   924,   926,   925,   927,   927,   929,   928,   930,
     930,   932,   931,   933,   933,   935,   934,   936,   936,   938,
     937,   939,   939,   940,   940,   940,   940,   940,   940,   940,
     940,   940,   940,   940,   940,   940,   940,   940,   942,   941,
     943,   943,   565,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   958,   959,
     960,   961,   962,   962,   963,   964,   965,   966,   967,   968,
     968,   969,   970,   971,   972,   973,   974,   975,   976,   977,
     979,   978,   980,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989
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
       1,     1,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     2,     3,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     0,     2,     5,     4,     0,     2,     1,     1,
       1,     1,     2,     3,     3,     4,     1,     5,     1,     2,
       0,     4,     0,     3,     1,     3,     3,     0,     3,     0,
       2,     1,     1,     4,     4,     1,     3,     1,     2,     1,
       2,     0,     4,     4,     1,     2,     0,     3,     0,     2,
       1,     1,     4,     4,     1,     3,     1,     2,     1,     2,
       0,     4,     4,     1,     2,     0,     3,     0,     2,     1,
       1,     4,     1,     3,     1,     2,     1,     2,     0,     4,
       4,     1,     2,     0,     4,     1,     2,     0,     2,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     3,     4,     4,     4,     4,
       4,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     4,     4,     4,     3,     3,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     1,     2,     1,
       3,     1,     1,     0,     2,     3,     1,     0,     1,     3,
       3,     1,     1,     2,     1,     3,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       1,     1,     3,     2,     0,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       3,     4,     2,     1,     0,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     8,     1,     0,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     0,     4,
       1,     1,     0,     2,     1,     1,     3,     0,     2,     2,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       0,     4,     1,     1,     0,     2,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     4,     1,     1,     1,     3,     0,     2,     3,
       1,     0,     4,     3,     0,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     0,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     0,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     3,     1,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     4,     4,     1,
       1,     1,     3,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     0,     4,     1,
       5,     0,     2,     5,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     2,     0,     3,     1,
       2,     0,     5,     0,     5,     0,     5,     0,     4,     0,
       5,     0,     5,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       6,     0,     4,     0,     4,     0,     4,     0,     4,     1,
       2,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       4,     0,     4,     1,     2,     0,     4,     0,     2,     1,
       1,     4,     4,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     2,     4,     2,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     2,     4,     1,     0,     1,     2,
       4,     1,     0,     1,     2,     1,     3,     2,     1,     1,
       2,     2,     1,     3,     2,     1,     3,     2,     1,     3,
       0,     4,     0,     2,     2,     1,     3,     2,     1,     6,
       2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   767,     0,    11,     1,   769,    27,     0,
       0,     0,    29,    37,     0,     0,   771,     0,     9,    14,
      12,    17,    39,   150,     0,     0,     0,    30,     0,     0,
       0,     0,   152,   266,     0,     0,     0,    40,     0,    33,
      35,    28,    31,    32,     0,   768,   774,   772,     0,    10,
      15,     0,     0,     0,     0,     0,    13,    18,    19,    20,
      21,    22,   268,     0,     0,   155,   157,   151,   153,   154,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   387,     4,     3,     7,   271,
     343,   267,   269,   270,   159,   185,     0,     0,     0,   355,
      34,   427,    36,   429,   770,     0,     0,     0,     0,     0,
       0,     0,     6,     2,     5,   272,   276,     0,     0,     0,
       0,   187,   221,     0,     0,     0,   160,   356,    44,    55,
      65,    75,    88,   102,   113,   132,    46,    47,    57,    48,
      67,    49,    77,    50,    90,    51,   104,    52,   115,    53,
     134,     0,   428,     0,   821,   813,   815,   819,   823,   825,
     873,   889,   833,   817,   839,   827,   829,   831,   861,   835,
     837,   881,   877,   885,   803,   807,   811,   847,   841,   843,
     845,     0,   797,   798,   778,   779,   781,   782,   783,   784,
     786,   787,   788,   790,   789,   791,   793,   794,   792,   800,
     801,   802,   776,   777,   780,   799,   795,   796,   785,    26,
      23,    24,    25,   387,   387,   389,   390,   391,   392,   388,
     273,     0,   280,   274,   347,   223,   254,     0,     0,     0,
     188,     0,   163,   166,   158,   161,   162,     0,    56,     0,
      66,     0,    76,     0,    89,     0,   103,     0,   114,     0,
     133,   441,   444,   426,   439,   440,     0,     0,     0,     0,
       0,   430,   431,   434,   435,   433,   432,   775,     0,     0,
       0,     0,     0,     0,   875,   891,     0,     0,     0,     0,
       0,     0,   867,     0,     0,   883,   879,   887,     0,     0,
       0,   851,     0,     0,     0,   773,   384,   385,     0,   280,
     278,     0,     0,   256,     0,     0,     0,     0,   224,     0,
     191,   194,   186,   189,   190,     0,     0,    62,     0,    54,
       0,     0,     0,    58,    59,    60,    61,    72,     0,    64,
      68,    69,    70,    71,    85,     0,    74,     0,     0,     0,
      78,    79,    80,    81,    83,    82,    84,    99,     0,    87,
       0,     0,    91,    92,    93,    94,    96,    95,    97,    98,
     110,     0,   101,     0,   105,   106,   107,   108,   109,     0,
     112,   116,   117,   118,   119,     0,   131,   135,   136,   137,
     138,   446,     0,   474,   448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     805,     0,   804,   809,     0,   808,     0,     0,   914,   917,
     926,   931,   938,   942,   945,   948,   950,   955,   958,   961,
     908,   920,   923,     0,   893,   894,     0,   895,     0,   907,
       0,   896,     0,   897,   927,   898,   932,   899,     0,   900,
       0,   901,     0,   902,     0,   903,   904,     0,   905,     0,
     906,     0,     0,     0,     0,   275,   279,   282,   345,     0,
       0,     0,   344,   348,   349,   350,   156,     0,     0,   257,
       0,   227,   230,   222,   225,   226,     0,     0,   359,   165,
     169,   164,   167,   171,    63,     0,     0,     0,    73,    86,
     387,     0,     0,   100,     0,     0,   111,     0,   122,     0,
       0,   141,     0,     0,   442,   443,     0,   447,   437,   438,
     436,     0,     0,     0,     0,     0,     0,   824,   826,   874,
     876,   890,   892,   834,   818,     0,   828,   830,   832,   863,
       0,     0,     0,   862,   868,   869,   870,   836,   838,   882,
     884,   878,   880,   886,   888,   806,   810,     0,   849,     0,
       0,     0,     0,   848,   852,   853,   855,   854,   952,     0,
     842,     0,   913,     0,   916,     0,   919,     0,   922,     0,
       0,   928,   935,     0,   933,   939,     0,   937,     0,   941,
       0,   944,     0,   947,     0,   954,     0,   957,     0,   960,
     844,   846,     0,     0,     0,   346,   387,   387,     0,   260,
     262,   255,   258,   259,     0,     0,   360,   193,   197,   192,
     195,   199,     0,   170,   364,     0,     0,     0,     0,     0,
       0,     0,   371,   130,   120,   387,     0,   123,   149,   139,
       0,   142,   717,   480,   714,   475,   476,     0,   477,     0,
     478,     0,   473,     0,   445,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   466,   467,   468,   458,   755,   757,
     822,   814,   816,   820,     0,   864,   865,     0,   387,   812,
     850,   856,   387,   858,     0,     0,     0,     0,   915,     0,
     921,   924,     0,     0,     0,   940,     0,     0,     0,     0,
       0,   962,   277,     0,   284,   287,   281,     0,     0,     0,
       0,   361,   229,   233,   228,   231,   235,     0,   198,   183,
       0,   168,     0,     0,     0,     0,     0,     0,     0,   172,
     181,   177,   178,   179,   180,   175,   182,   176,   174,   173,
     358,   357,   366,   367,   368,   369,   370,     0,     0,   126,
     395,   121,   124,   125,   145,   395,   140,   143,   144,   483,
     486,   479,   481,   482,     0,     0,     0,   718,   472,     0,
       0,     0,     0,     0,     0,     0,   387,   387,   840,     0,
       0,     0,     0,     0,     0,   951,   953,     0,     0,   910,
       0,   909,   918,   936,     0,   925,     0,   930,   943,   946,
     949,   956,     0,   283,   289,     0,   306,   352,   353,   363,
     261,     0,   263,     0,   234,   212,   216,   196,   210,   211,
       0,     0,     0,     0,     0,   200,   209,   207,   208,   206,
     205,   203,   204,   202,   201,   184,     0,     0,     0,     0,
       0,     0,     0,   387,   386,     0,     0,   128,   393,   394,
       0,   147,   488,   518,   490,     0,     0,     0,   716,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   866,   872,
     871,   857,   860,   859,     0,     0,   911,   929,   934,     0,
       0,   285,   308,   325,     0,     0,   250,   216,   232,   248,
     249,     0,   236,   247,   245,   246,   241,   242,   243,   244,
     239,   240,   238,   237,     0,   214,     0,     0,     0,     0,
       0,   380,     0,     0,     0,     0,     0,     0,   354,     0,
       0,   129,   127,   398,   396,   400,   148,   146,   520,   550,
     522,     0,   489,   715,   713,     0,   722,     0,     0,   459,
     460,   461,   462,   463,   464,   465,   471,   912,   372,     0,
     297,   301,     0,     0,   290,   291,   292,   288,   295,     0,
     327,   286,     0,     0,   252,     0,     0,   215,   213,     0,
     217,     0,     0,     0,     0,     0,   365,   373,   375,   376,
     377,   379,   381,     0,   409,     0,   405,   406,   407,     0,
     399,   552,   604,   554,     0,   521,     0,     0,   765,     0,
     491,   492,   493,   763,   764,   754,   730,   737,     0,     0,
       0,   723,   959,   298,   301,   299,     0,     0,     0,   316,
     320,     0,     0,   309,   310,   311,   307,   314,     0,     0,
       0,   253,   251,     0,   219,     0,   362,   382,   378,   374,
       0,     0,   408,     0,   397,     0,     0,   401,   403,   402,
     606,   681,   608,     0,   553,     0,   523,   524,   525,   498,
     487,   495,     0,     0,     0,     0,     0,   731,     0,   726,
     395,   721,   724,   725,   296,   300,     0,     0,     0,   317,
     320,   318,     0,     0,     0,   334,   338,     0,     0,   328,
     329,   326,   332,   330,   265,   264,   383,   220,   218,   760,
     410,     0,     0,     0,   683,   644,   685,     0,   607,     0,
     555,   556,   557,   530,   519,   527,     0,   505,     0,     0,
       0,   501,   395,   497,   499,   500,     0,   766,   740,   720,
     719,   738,   742,   734,   395,   729,   732,   733,     0,   728,
       0,     0,     0,   293,   294,   315,   319,     0,     0,     0,
     335,   338,   336,     0,     0,     0,   404,     0,     0,   646,
       0,   648,     0,   684,     0,   609,   610,   611,   562,   551,
     559,     0,   537,     0,     0,     0,   533,   395,   529,   531,
     532,   494,   512,   496,     0,   508,   395,   504,   506,   507,
     503,     0,   758,     0,   741,   736,     0,   756,   727,     0,
     304,     0,   302,     0,     0,   312,   313,   333,   337,     0,
       0,     0,   761,   762,   485,   484,     0,   647,     0,   686,
     687,   688,   616,   605,   613,     0,   569,     0,   575,     0,
     565,   395,   561,   563,   564,   526,   544,   528,     0,   540,
     395,   536,   538,   539,   535,     0,   515,   413,   511,   513,
     514,   510,     0,   502,   751,   444,   739,   749,   750,   387,
     387,   746,   743,   744,   745,   735,     0,   305,     0,   323,
       0,   321,     0,     0,   331,   351,     0,   649,   650,   651,
     693,   682,   690,     0,   623,     0,   629,     0,   619,   395,
     615,   617,   618,   558,   577,   560,     0,   572,   395,   568,
     570,   571,   567,     0,   547,   395,   543,   545,   546,   542,
       0,   534,     0,   517,   411,   412,     0,   509,   474,     0,
       0,     0,   303,     0,   324,     0,   341,     0,   339,   656,
     645,   653,     0,   700,     0,     0,     0,   696,   395,   692,
     694,   695,   612,   631,   614,     0,   626,   395,   622,   624,
     625,   621,     0,   580,   583,   576,   578,   579,   574,     0,
     566,   549,     0,   541,     0,   416,   414,   417,   516,   753,
     752,   387,   387,   322,     0,   342,   668,     0,     0,     0,
     659,   395,   655,   657,   658,   689,   707,   691,     0,   703,
     395,   699,   701,   702,   698,     0,   634,   636,   630,   632,
     633,   628,     0,   620,     0,   582,   573,   548,   424,     0,
     420,   421,   422,     0,   418,   747,   748,   340,   652,   675,
     654,     0,   671,   395,   667,   669,   670,   661,     0,   710,
     395,   706,   708,   709,   705,     0,   697,     0,   627,   581,
     586,   584,   588,     0,   423,   387,   415,   678,   395,   674,
     676,   677,   673,     0,   660,   712,     0,   704,   639,   635,
     637,     0,     0,   587,   425,     0,   680,     0,   672,   711,
     642,     0,   638,   640,   641,   595,   597,   585,   593,   594,
       0,     0,   589,   591,   590,   419,   679,     0,     0,   387,
       0,   643,   596,   600,   598,   601,     0,     0,     0,     0,
     592,   759,   387,     0,   599,     0,     0,   602,   603
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
     636,   761,   762,   763,   856,   932,   634,   149,   150,   249,
     250,   377,   376,   512,   513,   640,   766,   767,   768,   860,
     937,   639,    33,    34,    67,    68,    69,    95,    96,   125,
     234,   235,   236,   491,   316,   492,   493,   622,   623,   739,
     731,   122,   123,   229,   312,   313,   314,   619,   487,   620,
     621,   727,   728,   835,   827,   828,   829,   914,   978,   915,
     980,   981,  1108,   226,   227,   307,   483,   484,   485,   724,
     615,   725,   726,   823,   824,   902,   898,   899,   900,   975,
    1042,   304,   305,   478,   611,   612,   613,   720,   822,   895,
      63,    64,    91,    92,    93,   117,   118,   222,   299,   300,
     301,   604,   716,   815,   816,   890,   964,   965,   966,   967,
     968,  1024,  1025,  1026,  1152,  1212,   893,   969,  1033,  1034,
    1035,  1036,  1037,  1090,  1091,  1092,  1214,  1281,   971,  1038,
    1099,  1100,  1101,  1102,  1161,  1162,  1163,  1283,  1338,   119,
     120,   472,   302,   473,  1103,   474,   475,   637,    27,    37,
     324,   325,   126,   230,   308,   836,   479,   326,   838,   344,
     345,   346,   358,   359,   368,   697,   741,   839,   742,   743,
     744,   840,   745,   746,   747,   842,   911,   110,   757,   111,
     219,   857,   858,   934,   935,   999,  1000,  1057,  1054,   859,
     996,   997,   998,  1323,  1324,  1376,  1377,  1423,  1456,  1325,
    1420,  1421,  1422,   102,   103,   151,   152,   261,   262,   263,
     264,   253,   254,   255,   382,   383,   384,   516,   517,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   654,   515,   645,   646,   647,   771,   772,   773,
    1225,   863,   864,   941,   942,  1010,  1070,  1128,  1071,  1072,
    1133,  1134,  1135,  1201,  1129,  1130,  1197,  1198,  1199,  1262,
    1193,  1194,  1258,  1259,  1260,  1326,   939,   940,  1004,  1005,
    1066,  1124,  1183,  1125,  1126,  1188,  1189,  1190,  1255,  1184,
    1185,  1251,  1252,  1253,  1320,  1247,  1248,  1316,  1317,  1318,
    1372,  1002,  1003,  1063,  1064,  1120,  1179,  1237,  1180,  1181,
    1242,  1243,  1244,  1313,  1238,  1239,  1309,  1310,  1311,  1369,
    1305,  1306,  1365,  1366,  1367,  1414,  1415,  1451,  1452,  1472,
    1473,  1492,  1493,  1487,  1488,  1489,  1498,  1504,  1505,  1509,
    1514,  1061,  1062,  1117,  1118,  1175,  1233,  1295,  1234,  1235,
    1300,  1301,  1302,  1362,  1296,  1297,  1358,  1359,  1360,  1412,
    1354,  1355,  1408,  1409,  1410,  1447,  1470,  1471,  1482,  1483,
    1484,  1170,  1171,  1226,  1227,  1287,  1340,  1387,  1341,  1342,
    1392,  1393,  1394,  1438,  1388,  1389,  1434,  1435,  1436,  1463,
    1430,  1431,  1459,  1460,  1461,  1477,  1115,  1116,  1172,  1173,
    1229,  1291,  1344,  1292,  1293,  1349,  1350,  1351,  1405,  1345,
    1346,  1401,  1402,  1403,  1445,  1397,  1398,  1441,  1442,  1443,
    1466,   648,   649,   944,   650,   651,   776,   868,  1140,   947,
     948,  1020,  1081,  1082,  1083,  1150,  1017,  1018,  1076,  1145,
    1146,  1147,  1206,  1075,  1141,  1142,  1203,  1204,  1272,  1273,
    1274,  1266,  1267,  1268,  1329,   777,   265,  1021,   266,  1011,
    1494,   930,  1058,  1059,  1012,  1013,  1014,     8,     9,    16,
      29,    47,    48,    80,   181,   182,   288,   412,   183,   289,
     415,   184,   290,   185,   269,   186,   270,   187,   277,   188,
     271,   189,   268,   190,   272,   191,   273,   192,   279,   193,
     280,   194,   281,   195,   276,   196,   283,   197,   284,   198,
     278,   199,   292,   200,   293,   201,   294,   202,   291,   563,
     417,   564,   565,   792,   566,   794,   567,   203,   282,   543,
     789,   404,   544,   545,   546,   204,   274,   396,   205,   286,
     408,   206,   285,   407,   207,   287,   409,   208,   275,   397,
     433,   434,   569,   801,   435,   436,   572,   437,   438,   574,
     439,   440,   576,   441,   442,   578,   443,   444,   580,   805,
     445,   446,   583,   807,   581,   582,   447,   448,   587,   449,
     450,   589,   451,   452,   591,   453,   454,   593,   455,   568,
     694,   456,   457,   595,   458,   459,   597,   460,   461,   599
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -982
static const yytype_int16 yypact[] =
{
      25,    60,    97,  -160,    89,  -982,  -982,  -982,   101,  -100,
     131,    71,  -982,   137,   140,   171,  -982,   174,  -982,  -982,
    -982,  -982,  -982,   115,   145,   183,    56,  -982,   181,   -90,
     179,    26,  -982,   102,    70,   200,   105,  -982,   219,  -982,
    -982,  -982,  -982,  -982,   206,  -982,  -982,  -982,   203,  -982,
    -982,   208,   225,   231,   235,   239,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,   136,   155,  -982,   175,  -982,  -982,  -982,
     241,  -982,  -982,  -982,  -982,  -982,   247,    23,   242,   252,
     246,  -982,   254,   256,   261,  -982,  -982,  -982,   258,  -982,
     113,  -982,  -982,  -982,  -982,   185,   205,   271,   202,  -982,
    -982,  -982,  -982,  -982,  -982,   299,   638,   275,   295,   305,
     307,    27,  -982,  -982,  -982,  -982,  -982,   218,   215,   224,
     182,  -982,   273,   264,   357,   201,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   214,    33,   359,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   127,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   363,  -982,  -982,  -982,  -982,   281,   289,   369,   222,
    -982,   367,  -982,  -982,  -982,  -982,  -982,   255,    35,   282,
      35,   284,    40,   286,    31,   291,    48,   371,    35,   375,
      35,  -982,   207,  -982,  -982,  -982,   376,   384,   386,   389,
     391,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   638,   638,
     638,   638,   638,   638,  -982,  -982,   638,   638,   638,   638,
     638,   638,  -982,   638,   638,  -982,  -982,  -982,   293,   324,
     638,  -982,   149,   149,   149,  -982,  -251,  -251,   393,   290,
    -982,   301,    92,  -982,   341,   313,   401,   326,  -982,   405,
    -982,  -982,  -982,  -982,  -982,   424,    75,  -982,   378,  -982,
     436,   441,   443,  -982,  -982,  -982,  -982,  -982,   412,  -982,
    -982,  -982,  -982,  -982,  -982,   410,  -982,   451,   453,   455,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   416,  -982,
     459,   461,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   420,  -982,   526,  -982,  -982,  -982,  -982,  -982,   437,
    -982,  -982,  -982,  -982,  -982,   444,  -982,  -982,  -982,  -982,
    -982,  -982,   362,  -982,  -982,   465,   529,   530,   528,   531,
     638,   638,   638,   638,   287,   288,   125,   471,   285,   279,
     638,   278,   280,   276,    32,   277,   274,   490,   527,   566,
    -982,   263,  -982,  -982,   266,  -982,   638,    37,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,   262,  -982,  -982,   149,  -982,   149,  -982,
     638,  -982,   149,  -982,   227,  -982,   227,  -982,   328,  -982,
     149,  -982,   149,  -982,   149,  -982,  -982,   638,  -982,   149,
    -982,   149,   259,   265,   549,  -982,  -982,   532,  -982,   426,
     551,   552,  -982,  -982,  -982,  -982,  -982,   555,   335,  -982,
     554,  -982,  -982,  -982,  -982,  -982,   556,    82,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,   559,   557,   558,  -982,  -982,
    -982,   561,   562,  -982,   563,   564,  -982,   560,  -982,   524,
     417,  -982,   525,   417,  -982,   -86,   337,    96,  -982,  -982,
    -982,   571,   573,   327,   336,   338,   333,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,   638,  -982,  -982,  -982,  -982,
     607,   576,   579,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,   300,  -982,   302,
     580,   582,   584,  -982,  -982,  -982,  -982,  -982,  -982,    50,
    -982,   296,  -982,   149,  -982,   267,  -982,   269,  -982,   587,
     581,  -982,  -982,   583,  -982,  -982,   292,  -982,   149,  -982,
     149,  -982,   149,  -982,   149,  -982,   638,  -982,   283,  -982,
    -982,  -982,   585,   591,   339,  -982,  -982,  -982,   590,  -982,
    -982,  -982,  -982,  -982,   596,    78,  -982,  -982,  -982,  -982,
    -982,  -982,   348,    58,  -982,   598,   599,   600,   601,   602,
     603,   605,  -982,  -982,  -982,  -982,   406,  -982,  -982,  -982,
     408,  -982,  -982,  -982,  -982,  -982,  -982,   411,  -982,   606,
    -982,   429,  -982,   442,  -982,   608,   610,   611,   615,   616,
     617,   619,   620,  -982,   621,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   365,  -982,  -982,   622,  -982,  -982,
    -982,  -982,  -982,  -982,    13,   623,   624,   413,  -982,   340,
    -982,  -982,   625,   149,   149,  -982,   329,   325,   330,   320,
     638,  -982,  -982,   630,  -982,   520,  -982,   633,   635,   636,
      73,  -982,  -982,  -982,  -982,  -982,  -982,   415,    98,  -982,
     567,  -982,   637,   639,   641,   642,   644,   645,   646,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,   643,    15,  -982,
     492,  -982,  -982,  -982,  -982,   492,  -982,  -982,  -982,  -982,
     456,  -982,  -982,  -982,   149,   648,   647,  -982,  -982,   649,
     650,   652,   653,   654,   655,   656,  -982,  -982,  -982,   388,
     661,   662,   663,   664,   665,  -982,  -982,   666,   667,  -982,
     352,  -982,  -982,  -982,   373,  -982,   372,  -982,  -982,  -982,
    -982,  -982,   638,  -982,  -982,   565,   568,  -982,  -982,  -982,
    -982,   658,  -982,   421,    11,  -982,  -982,  -982,  -982,  -982,
     669,   674,   675,   676,   677,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,   679,   673,   680,   681,
     682,   683,   684,  -982,  -982,   519,   640,  -982,   533,  -982,
     628,  -982,  -982,   485,  -982,   475,   687,   473,  -982,   692,
     697,   698,   699,   700,   701,   703,   705,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   709,   711,  -982,  -982,  -982,   638,
      47,  -982,  -982,   604,   713,   707,  -982,  -982,  -982,  -982,
    -982,   719,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   704,   715,   777,   779,   781,   783,
     723,  -982,   789,   791,   793,   795,   816,   818,  -982,   820,
     423,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   627,
    -982,   814,  -144,  -982,  -982,   824,  -982,   609,   685,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   545,
    -982,   712,   828,   830,  -982,  -982,  -982,  -982,  -982,    52,
    -982,  -982,   832,   638,   715,   785,   853,  -982,  -982,   851,
    -982,   149,   861,   863,   867,   869,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,   892,  -982,    34,  -982,  -982,  -982,   890,
     272,  -982,   691,  -982,   894,  -144,   717,   904,  -982,   905,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   685,   908,
     427,  -982,  -982,  -982,   796,  -982,   797,   912,   916,  -982,
     807,   924,   926,  -982,  -982,  -982,  -982,  -982,    61,   927,
     840,  -982,  -982,   929,  -982,   829,  -982,  -982,  -982,  -982,
     930,   772,  -982,   928,  -982,   933,   934,  -982,  -982,  -982,
    -982,   722,  -982,   931,  -144,   739,  -982,  -982,  -982,  -982,
    -982,   736,   460,   936,   938,   -63,   462,  -982,   937,  -982,
     492,  -982,  -982,  -982,  -982,  -982,   932,   942,   943,  -982,
     831,  -982,   821,   941,   944,  -982,   833,   950,   951,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   788,   949,   952,  -982,   743,  -982,   947,  -144,   760,
    -982,  -982,  -982,  -982,  -982,   757,   464,  -982,   763,   758,
     466,  -982,   492,  -982,  -982,  -982,   960,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   492,  -982,  -982,  -982,   962,  -982,
     741,   964,   468,  -982,  -982,  -982,  -982,   953,   965,   967,
    -982,   854,  -982,   844,   968,   969,  -982,   971,   974,  -982,
     782,  -982,   970,  -144,   778,  -982,  -982,  -982,  -982,  -982,
     776,   470,  -982,   773,   780,   472,  -982,   492,  -982,  -982,
    -982,  -982,  -982,  -982,   474,  -982,   492,  -982,  -982,  -982,
    -982,   784,  -982,   476,  -113,  -982,   756,  -982,  -982,   977,
    -982,   862,  -982,   985,   478,  -982,  -982,  -982,  -982,   972,
     986,   988,  -982,  -982,  -982,  -982,   981,  -144,   794,  -982,
    -982,  -982,  -982,  -982,   792,   480,  -982,   786,   787,   484,
    -982,   492,  -982,  -982,  -982,  -982,  -982,  -982,   486,  -982,
     492,  -982,  -982,  -982,  -982,   798,  -982,   834,  -982,  -982,
    -982,  -982,   799,  -982,  -982,   207,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,   995,  -982,   993,  -982,
     874,  -982,   999,   488,  -982,  -982,   803,  -982,  -982,  -982,
    -982,  -982,   801,   495,  -982,   802,   800,   497,  -982,   492,
    -982,  -982,  -982,  -982,  -982,  -982,   499,  -982,   492,  -982,
    -982,  -982,  -982,   806,  -982,   492,  -982,  -982,  -982,  -982,
     804,  -982,   519,  -982,   842,  -982,   805,  -982,  -982,   837,
    1004,  1007,  -982,  1013,  -982,  1010,  -982,   889,  -982,  -982,
    -982,   815,   502,  -982,   808,   817,   504,  -982,   492,  -982,
    -982,  -982,  -982,  -982,  -982,   506,  -982,   492,  -982,  -982,
    -982,  -982,   819,  -982,  -982,  -982,  -982,  -982,  -982,   822,
    -982,  -982,   823,  -982,   508,  -982,  -982,   857,  -982,   -86,
    -982,  -982,  -982,  -982,  1019,  -982,  -982,   809,   825,   510,
    -982,   492,  -982,  -982,  -982,  -982,  -982,  -982,   512,  -982,
     492,  -982,  -982,  -982,  -982,   827,  -982,  -982,  -982,  -982,
    -982,  -982,   835,  -982,   826,   866,  -982,  -982,  -982,    46,
    -982,  -982,  -982,  1018,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,   514,  -982,   492,  -982,  -982,  -982,  -982,   836,  -982,
     492,  -982,  -982,  -982,  -982,   838,  -982,  -125,  -982,  -982,
    -982,  -982,  -982,   872,  -982,  -982,  -982,  -982,   492,  -982,
    -982,  -982,  -982,   839,  -982,  -982,   841,  -982,  -982,  -982,
    -982,   516,   518,  -115,  -982,   868,  -982,   843,  -982,  -982,
    -982,   638,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    1033,  1035,  -982,  -982,  -982,  -982,  -982,   875,   -93,  -982,
    1032,  -982,  -982,  -982,  -982,   716,  1042,  1043,  1044,  1038,
    -982,  -982,  -982,  1045,  -982,  1048,   845,  -982,  -982
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   156,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,   755,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,    36,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   -35,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -105,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,   544,  -982,  -982,
      14,    29,  -982,  -982,  -982,   234,  -982,  -217,   237,   846,
     847,  -982,  -982,  -982,  -982,  -982,   240,  -982,   243,   244,
     245,  -982,  -690,  -982,  -982,  -982,  -982,  -486,  -766,  -207,
    -982,  -748,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -145,  -982,
    -982,  -982,  -982,  -982,  -982,  -200,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -258,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -597,    53,  -595,  -981,
    -982,  -250,  -982,  -304,  -975,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -268,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -274,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,   629,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,
    -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982,  -982
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     390,   391,   392,   393,   394,   395,   296,   297,   398,   399,
     400,   401,   402,   403,   627,   405,   406,   861,   854,   462,
     463,   877,   416,   333,  1067,   343,   748,   355,   749,   367,
    1068,   374,   320,   380,   213,   214,    50,    51,   841,  1051,
    1007,  1468,   539,   540,    52,    53,    54,   558,   559,     1,
     541,  1453,   320,   100,   256,   257,   320,   960,   961,   560,
     561,   320,  1029,  1030,   258,  1490,    39,    40,   695,   320,
    1491,  1095,  1096,     7,  1502,   215,   216,   217,   218,   320,
      65,    66,  1469,  1121,  1008,  1009,     4,   928,   642,  1122,
     337,   338,    10,   350,   351,   830,    18,     6,    19,   337,
     338,   339,   468,   469,   733,   734,   735,   736,   737,  1138,
     643,   901,  1139,   363,   834,    71,    72,  1269,  1270,   320,
     717,   718,   523,   524,   525,   526,   732,  1503,   530,   532,
      12,   843,   535,   844,   910,    15,   644,  1176,    17,   550,
     552,   554,   696,  1177,    45,   489,    46,   490,   557,    86,
      87,   733,   734,   735,   736,   737,   738,   617,   722,   618,
     723,   820,   571,   821,   573,    89,    90,   962,   577,    22,
     963,    25,   575,  1031,    28,  1032,   588,    30,   590,    35,
     592,    32,   830,  1097,  1098,   596,    38,   598,    44,   594,
      49,   101,  1230,   259,   260,   737,  1052,   831,  1231,   832,
     833,   834,   791,    70,   470,   471,   793,    62,  1454,    78,
     258,   232,   233,   321,   322,   259,   260,   321,   322,   115,
     116,    79,   321,   322,   251,   252,    76,   912,    82,   913,
     321,   322,   310,   311,    83,   128,    81,   129,    84,   130,
     259,   260,    85,   131,    94,   132,  1288,   133,    97,   134,
      99,   135,  1289,   104,   331,   105,   341,   106,   353,   121,
     365,   107,   372,   108,   378,   317,   318,   684,   109,   332,
     112,   342,   686,   354,   127,   366,   124,   373,   209,   379,
     259,   260,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   327,   328,   334,   335,   347,   348,   210,   699,
     876,   360,   361,   410,   411,   418,   153,   419,   211,   420,
     212,   421,   224,   422,   706,   423,   707,   424,   708,   425,
     709,   426,   795,   427,   220,   428,   221,   429,   710,   430,
     223,   431,  1149,   432,   413,   414,   481,   482,   585,   586,
     228,   215,   216,   217,   218,   609,   610,   652,   653,   714,
     715,    55,   225,   215,   216,   217,   218,   542,   729,   730,
     231,   562,   267,   154,   295,   155,   298,   156,   303,   157,
     306,   158,   309,   159,   315,   160,   529,   161,   381,   162,
     385,   163,   369,   164,  1200,   165,   375,   166,   386,   167,
     387,   168,   388,   169,   389,   170,  1205,   171,   465,   172,
     464,   173,   477,   174,   480,   175,   740,   176,   476,   177,
     467,   178,   486,   179,   494,   180,   759,   760,   764,   765,
     796,   769,   770,   799,   800,   825,   826,   488,   758,   804,
     806,   896,   897,   994,   995,  1055,  1056,  1079,  1080,  1254,
     495,   418,   812,   419,   496,   420,   497,   421,  1261,   422,
     498,   423,   499,   424,   500,   425,   501,   426,   502,   427,
     503,   428,   504,   429,   505,   430,   506,   431,   518,   432,
    1131,  1132,  1143,  1144,  1186,  1187,  1195,  1196,  1210,  1211,
    1240,  1241,  1249,  1250,  1256,  1257,  1264,  1265,  1279,  1280,
    1298,  1299,   508,  1312,  1307,  1308,  1314,  1315,  1336,  1337,
     865,   511,  1319,  1330,  1331,  1347,  1348,  1356,  1357,  1363,
    1364,   837,  1390,  1391,  1399,  1400,  1406,  1407,  1418,  1419,
    1432,  1433,  1439,  1440,  1457,  1458,  1480,  1481,  1485,  1486,
     507,   514,   519,   520,   527,   521,   534,   528,   522,   536,
     533,   538,   555,   537,   889,   548,   547,   556,   600,   570,
     579,  1361,   602,   603,   606,   607,   601,   605,   608,   616,
    1368,   614,   624,   632,   625,   626,   680,  1371,   628,   629,
     630,   631,   633,   635,   678,   638,   679,   681,   683,   687,
     758,   682,   688,   689,   691,   692,   700,   690,   693,   698,
     701,   702,   703,   705,   704,   713,   712,   719,   711,   721,
    1404,   750,   751,   752,   753,   754,   755,   904,   756,  1411,
     775,   779,   778,   780,   781,  1425,  1426,   774,   782,   783,
     784,   959,   785,   786,   788,   787,   797,   798,   803,   790,
     809,   811,   808,   813,   814,   802,   817,   810,   818,   819,
     845,   846,   847,  1437,   848,   849,   758,   850,   851,   852,
     853,   866,  1444,   855,   862,   878,   869,   870,   867,   871,
     872,   873,   874,   875,   879,   880,   881,   882,   883,   886,
     887,   888,   916,   884,   885,   891,   894,   917,   918,   919,
     922,   920,   921,   892,   929,  1462,   936,   923,   924,   925,
     926,   927,  1465,   938,   945,   949,   931,   946,   943,   933,
     950,   951,   952,   953,   954,  1040,   955,  1045,   956,   154,
    1476,   155,   957,   156,   958,   157,   972,   158,   973,   159,
     970,   160,   976,   161,   531,   162,   986,   163,   154,   164,
     155,   165,   156,   166,   157,   167,   158,   168,   159,   169,
     160,   170,   161,   171,   162,   172,   163,   173,   164,   174,
     165,   175,   166,   176,   167,   177,   168,   178,   169,   179,
     170,   180,   171,   549,   172,   154,   173,   155,   174,   156,
     175,   157,   176,   158,   177,   159,   178,   160,   179,   161,
     180,   162,   977,   163,   982,   164,   983,   165,   984,   166,
     985,   167,   987,   168,   988,   169,   989,   170,   990,   171,
     979,   172,   551,   173,   154,   174,   155,   175,   156,   176,
     157,   177,   158,   178,   159,   179,   160,   180,   161,   991,
     162,   992,   163,   993,   164,  1006,   165,  1015,   166,  1023,
     167,  1027,   168,  1028,   169,  1016,   170,  1001,   171,  1039,
     172,  1019,   173,   553,   174,   154,   175,   155,   176,   156,
     177,   157,   178,   158,   179,   159,   180,   160,  1022,   161,
    1043,   162,  1044,   163,  1046,   164,  1047,   165,  1041,   166,
    1048,   167,  1049,   168,   685,   169,   154,   170,   155,   171,
     156,   172,   157,   173,   158,   174,   159,   175,   160,   176,
     161,   177,   162,   178,   163,   179,   164,   180,   165,  1050,
     166,  1053,   167,  1060,   168,  1065,   169,  1073,   170,  1074,
     171,  1078,   172,  1084,   173,  1107,   174,  1069,   175,  1087,
     176,  1086,   177,  1088,   178,  1089,   179,  1093,   180,  1094,
    1104,  1105,  1106,  1109,  1110,  1111,  1112,  1113,  1114,  1123,
    1127,  1137,  1119,  1136,  1148,  1153,  1154,  1157,  1158,  1155,
    1151,  1159,  1160,  1164,  1165,  1166,  1167,  1169,  1174,  1168,
    1178,  1182,  1191,  1202,  1192,  1207,  1208,  1209,  1215,  1475,
    1216,  1213,  1219,  1217,  1222,  1220,  1221,  1223,  1232,  1224,
    1236,  1228,  1245,  1275,  1276,  1263,  1246,  1277,  1278,  1284,
    1282,  1285,  1286,  1304,  1290,  1322,  1294,  1303,  1332,  1321,
    1333,  1334,  1335,  1339,  1327,  1343,  1353,  1370,  1375,  1373,
    1380,  1381,  1378,  1506,  1382,  1352,  1383,  1384,  1385,  1386,
    1413,  1056,  1427,  1396,  1428,  1395,  1515,  1416,  1446,  1455,
    1417,  1429,  1450,  1449,  1474,  1495,  1499,  1464,  1500,  1507,
    1448,  1508,  1501,  1467,  1478,  1510,  1511,  1512,  1479,  1513,
    1496,  1517,  1516,   974,   466,  1156,  1218,   641,   903,  1271,
    1085,   905,   758,   758,   906,  1328,  1518,   907,   908,   909,
    1379,  1077,  1374,  1424,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   758,   758,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1497
};

static const yytype_int16 yycheck[] =
{
     268,   269,   270,   271,   272,   273,   213,   214,   276,   277,
     278,   279,   280,   281,   500,   283,   284,   765,     3,   293,
     294,   787,   290,   240,  1005,   242,   623,   244,   623,   246,
    1005,   248,    21,   250,     7,     8,    10,    11,   728,     5,
     184,   166,    10,    11,    18,    19,    20,    10,    11,    24,
      18,     5,    21,    30,    21,    22,    21,    10,    11,    22,
      23,    21,    10,    11,   177,   180,    10,    11,    18,    21,
     185,    10,    11,   233,   167,   326,   327,   328,   329,    21,
      10,    11,   207,  1064,   228,   229,    26,   853,   174,  1064,
      59,    60,     3,    62,    63,    84,    25,     0,    27,    59,
      60,    61,    10,    11,    93,    94,    95,    96,    97,   172,
     196,   100,   175,    65,   103,    10,    11,   230,   231,    21,
     606,   607,   390,   391,   392,   393,    68,   220,   396,   397,
      29,   728,   400,   728,   824,   235,   222,  1118,     7,   407,
     408,   409,    92,  1118,   234,    70,   236,    72,   416,    13,
      14,    93,    94,    95,    96,    97,    98,    75,    80,    77,
      82,    88,   436,    90,   438,    10,    11,   120,   442,    32,
     123,    31,   440,   121,     3,   123,   450,     3,   452,    34,
     454,    66,    84,   122,   123,   459,     3,   461,     7,   457,
      11,   168,  1173,   182,   183,    97,   162,    99,  1173,   101,
     102,   103,   688,     3,   112,   113,   692,   105,   162,     3,
     177,    10,    11,   182,   183,   182,   183,   182,   183,   106,
     107,    18,   182,   183,    10,    11,     7,   824,     3,   824,
     182,   183,    10,    11,     3,    33,    28,    35,     3,    37,
     182,   183,     3,    41,    69,    43,  1227,    45,     7,    47,
       3,    49,  1227,    11,   240,     3,   242,    11,   244,    74,
     246,     7,   248,     7,   250,    10,    11,   535,     7,   240,
      12,   242,   540,   244,     3,   246,    71,   248,     3,   250,
     182,   183,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    10,    11,    10,    11,    10,    11,     3,   573,
     786,    10,    11,    10,    11,   292,     7,   294,     3,   296,
       3,   298,   130,   300,   588,   302,   590,   304,   592,   306,
     594,   308,   309,   310,   106,   312,   111,   314,   596,   316,
     106,   318,  1080,   320,    10,    11,    10,    11,    10,    11,
      76,   326,   327,   328,   329,    10,    11,    10,    11,    10,
      11,   325,    79,   326,   327,   328,   329,   325,    10,    11,
       3,   324,     3,   238,   237,   240,     3,   242,    87,   244,
      81,   246,     3,   248,     7,   250,   251,   252,   171,   254,
       4,   256,    11,   258,  1132,   260,    11,   262,     4,   264,
       4,   266,     3,   268,     3,   270,  1144,   272,   108,   274,
       7,   276,    89,   278,     3,   280,   623,   282,    67,   284,
     109,   286,     7,   288,    36,   290,    10,    11,    10,    11,
     694,    10,    11,    10,    11,    10,    11,     3,   635,   703,
     704,    10,    11,    10,    11,   163,   164,    10,    11,  1187,
       4,   292,   710,   294,     3,   296,     3,   298,  1196,   300,
      38,   302,    42,   304,     3,   306,     3,   308,     3,   310,
      44,   312,     3,   314,     3,   316,    46,   318,     3,   320,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    55,  1241,    10,    11,    10,    11,    10,    11,
     774,    57,  1250,  1269,  1270,    10,    11,    10,    11,    10,
      11,   728,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       4,   169,     3,     3,   247,     7,   257,   249,     7,   261,
     255,   265,   279,   263,   812,   271,   269,   281,   289,   287,
     323,  1299,     3,    21,     3,     3,   291,   131,     3,     3,
    1308,     7,     3,     3,     7,     7,   239,  1315,     7,     7,
       7,     7,    48,   156,     3,    50,     3,   241,   245,     3,
     787,   243,     3,   283,     4,     3,   319,   285,     4,   293,
     321,     4,    11,   301,    11,     4,    11,     7,   315,     3,
    1348,     3,     3,     3,     3,     3,     3,   824,     3,  1357,
     181,     3,   170,     3,     3,  1381,  1382,    11,     3,     3,
       3,   889,     3,     3,   259,     4,     3,     3,     3,     7,
     305,   311,   303,     3,   114,   295,     3,   307,     3,     3,
      73,     4,     3,  1391,     3,     3,   853,     3,     3,     3,
       7,     3,  1400,   161,   198,   267,     7,     7,    11,     7,
       7,     7,     7,     7,     3,     3,     3,     3,     3,   317,
     297,   299,     3,     7,     7,   110,    18,     3,     3,     3,
       7,     4,     3,   115,   165,  1433,    58,     7,     7,     7,
       7,     7,  1440,   208,     7,     3,    56,   224,   223,   166,
       3,     3,     3,     3,     3,   973,     3,   981,     3,   238,
    1458,   240,     3,   242,     3,   244,     3,   246,    11,   248,
     116,   250,     3,   252,   253,   254,     3,   256,   238,   258,
     240,   260,   242,   262,   244,   264,   246,   266,   248,   268,
     250,   270,   252,   272,   254,   274,   256,   276,   258,   278,
     260,   280,   262,   282,   264,   284,   266,   286,   268,   288,
     270,   290,   272,   273,   274,   238,   276,   240,   278,   242,
     280,   244,   282,   246,   284,   248,   286,   250,   288,   252,
     290,   254,    78,   256,     7,   258,     7,   260,     7,   262,
       7,   264,     3,   266,     3,   268,     3,   270,     3,   272,
      85,   274,   275,   276,   238,   278,   240,   280,   242,   282,
     244,   284,   246,   286,   248,   288,   250,   290,   252,     3,
     254,     3,   256,     3,   258,    11,   260,     3,   262,   117,
     264,     3,   266,     3,   268,   226,   270,   210,   272,     7,
     274,   156,   276,   277,   278,   238,   280,   240,   282,   242,
     284,   244,   286,   246,   288,   248,   290,   250,   313,   252,
       7,   254,    11,   256,     3,   258,     3,   260,    83,   262,
       3,   264,     3,   266,   267,   268,   238,   270,   240,   272,
     242,   274,   244,   276,   246,   278,   248,   280,   250,   282,
     252,   284,   254,   286,   256,   288,   258,   290,   260,     7,
     262,    11,   264,   212,   266,    11,   268,     3,   270,     4,
     272,     3,   274,   117,   276,    86,   278,   200,   280,     7,
     282,   124,   284,     7,   286,   118,   288,     3,   290,     3,
       3,    91,     3,     3,   162,     7,     3,     3,   216,   200,
     204,     3,    11,     7,     7,     3,     3,   126,     7,   118,
      18,     7,   119,     3,     3,   167,     7,   214,    11,     7,
     200,   204,   199,     3,   206,     3,   225,     3,     3,  1455,
       3,    18,   128,   119,     3,     7,     7,     3,   200,   197,
     204,    11,   209,   227,     7,   201,   206,   125,     3,     3,
      18,     3,    11,   206,   200,   161,   204,   211,     3,   201,
       7,   127,     3,   200,   205,   204,   206,   201,   166,   205,
     173,     7,   207,  1499,     7,   213,     3,     7,   129,   204,
     201,   164,     3,   206,   215,   217,  1512,   205,   201,    11,
     207,   206,   166,   207,   162,   167,     3,   201,     3,     7,
     205,   325,   167,   205,   205,     3,     3,     3,   207,    11,
     207,     3,     7,   897,   299,  1090,  1161,   513,   824,  1204,
    1024,   824,  1269,  1270,   824,  1265,   221,   824,   824,   824,
    1328,  1018,  1322,  1377,    -1,   446,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1381,  1382,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1481
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   331,   335,    26,   336,     0,   233,   857,   858,
       3,   337,    29,   347,   348,   235,   859,     7,    25,    27,
     338,   339,    32,   354,   355,    31,   349,   548,     3,   860,
       3,   341,    66,   422,   423,    34,   356,   549,     3,    10,
      11,   350,   351,   352,     7,   234,   236,   861,   862,    11,
      10,    11,    18,    19,    20,   325,   340,   342,   343,   344,
     345,   346,   105,   490,   491,    10,    11,   424,   425,   426,
       3,    10,    11,   357,   358,   359,     7,   353,     3,    18,
     863,    28,     3,     3,     3,     3,    13,    14,   332,    10,
      11,   492,   493,   494,    69,   427,   428,     7,   360,     3,
      30,   168,   603,   604,    11,     3,    11,     7,     7,     7,
     577,   579,    12,   333,   334,   106,   107,   495,   496,   539,
     540,    74,   441,   442,    71,   429,   552,     3,    33,    35,
      37,    41,    43,    45,    47,    49,   361,   362,   363,   368,
     369,   374,   375,   380,   381,   386,   387,   392,   393,   407,
     408,   605,   606,     7,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   272,   274,   276,   278,   280,   282,   284,   286,   288,
     290,   864,   865,   868,   871,   873,   875,   877,   879,   881,
     883,   885,   887,   889,   891,   893,   895,   897,   899,   901,
     903,   905,   907,   917,   925,   928,   931,   934,   937,     3,
       3,     3,     3,     7,     8,   326,   327,   328,   329,   580,
     106,   111,   497,   106,   130,    79,   463,   464,    76,   443,
     553,     3,    10,    11,   430,   431,   432,   364,   365,   370,
     371,   376,   377,   382,   383,   388,   389,   394,   395,   409,
     410,    10,    11,   611,   612,   613,    21,    22,   177,   182,
     183,   607,   608,   609,   610,   846,   848,     3,   882,   874,
     876,   880,   884,   886,   926,   938,   894,   878,   900,   888,
     890,   892,   918,   896,   898,   932,   929,   935,   866,   869,
     872,   908,   902,   904,   906,   237,   579,   579,     3,   498,
     499,   500,   542,    87,   481,   482,    81,   465,   554,     3,
      10,    11,   444,   445,   446,     7,   434,    10,    11,   367,
      21,   182,   183,   366,   550,   551,   557,    10,    11,   373,
     372,   550,   551,   557,    10,    11,   379,    59,    60,    61,
     378,   550,   551,   557,   559,   560,   561,    10,    11,   385,
      62,    63,   384,   550,   551,   557,   559,   560,   562,   563,
      10,    11,   391,    65,   390,   550,   551,   557,   564,    11,
     397,   396,   550,   551,   557,    11,   412,   411,   550,   551,
     557,   171,   614,   615,   616,     4,     4,     4,     3,     3,
     864,   864,   864,   864,   864,   864,   927,   939,   864,   864,
     864,   864,   864,   864,   921,   864,   864,   933,   930,   936,
      10,    11,   867,    10,    11,   870,   864,   910,   292,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   940,   941,   944,   945,   947,   948,   950,
     951,   953,   954,   956,   957,   960,   961,   966,   967,   969,
     970,   972,   973,   975,   976,   978,   981,   982,   984,   985,
     987,   988,   940,   940,     7,   108,   499,   109,    10,    11,
     112,   113,   541,   543,   545,   546,    67,    89,   483,   556,
       3,    10,    11,   466,   467,   468,     7,   448,     3,    70,
      72,   433,   435,   436,    36,     4,     3,     3,    38,    42,
       3,     3,     3,    44,     3,     3,    46,     4,    55,   398,
     399,    57,   413,   414,   169,   633,   617,   618,     3,     3,
       3,     7,     7,   864,   864,   864,   864,   247,   249,   251,
     864,   253,   864,   255,   257,   864,   261,   263,   265,    10,
      11,    18,   325,   919,   922,   923,   924,   269,   271,   273,
     864,   275,   864,   277,   864,   279,   281,   864,    10,    11,
      22,    23,   324,   909,   911,   912,   914,   916,   979,   942,
     287,   940,   946,   940,   949,   864,   952,   940,   955,   323,
     958,   964,   965,   962,   964,    10,    11,   968,   940,   971,
     940,   974,   940,   977,   864,   983,   940,   986,   940,   989,
     289,   291,     3,    21,   501,   131,     3,     3,     3,    10,
      11,   484,   485,   486,     7,   470,     3,    75,    77,   447,
     449,   450,   437,   438,     3,     7,     7,   577,     7,     7,
       7,     7,     3,    48,   406,   156,   400,   547,    50,   421,
     415,   547,   174,   196,   222,   634,   635,   636,   811,   812,
     814,   815,    10,    11,   632,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,     3,     3,
     239,   241,   243,   245,   864,   267,   864,     3,     3,   283,
     285,     4,     3,     4,   980,    18,    92,   565,   293,   940,
     319,   321,     4,    11,    11,   301,   940,   940,   940,   940,
     864,   315,    11,     4,    10,    11,   502,   577,   577,     7,
     487,     3,    80,    82,   469,   471,   472,   451,   452,    10,
      11,   440,    68,    93,    94,    95,    96,    97,    98,   439,
     557,   566,   568,   569,   570,   572,   573,   574,   846,   848,
       3,     3,     3,     3,     3,     3,     3,   578,   579,    10,
      11,   401,   402,   403,    10,    11,   416,   417,   418,    10,
      11,   637,   638,   639,    11,   181,   816,   845,   170,     3,
       3,     3,     3,     3,     3,     3,     3,     4,   259,   920,
       7,   577,   913,   577,   915,   309,   940,     3,     3,    10,
      11,   943,   295,     3,   940,   959,   940,   963,   303,   305,
     307,   311,   864,     3,   114,   503,   504,     3,     3,     3,
      88,    90,   488,   473,   474,    10,    11,   454,   455,   456,
      84,    99,   101,   102,   103,   453,   555,   557,   558,   567,
     571,   572,   575,   846,   848,    73,     4,     3,     3,     3,
       3,     3,     3,     7,     3,   161,   404,   581,   582,   589,
     419,   581,   198,   641,   642,   940,     3,    11,   817,     7,
       7,     7,     7,     7,     7,     7,   577,   578,   267,     3,
       3,     3,     3,     3,     7,     7,   317,   297,   299,   864,
     505,   110,   115,   516,    18,   489,    10,    11,   476,   477,
     478,   100,   475,   555,   557,   558,   566,   568,   569,   570,
     572,   576,   846,   848,   457,   459,     3,     3,     3,     3,
       4,     3,     7,     7,     7,     7,     7,     7,   578,   165,
     851,    56,   405,   166,   583,   584,    58,   420,   208,   666,
     667,   643,   644,   223,   813,     7,   224,   819,   820,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,   864,
      10,    11,   120,   123,   506,   507,   508,   509,   510,   517,
     116,   528,     3,    11,   459,   479,     3,    78,   458,    85,
     460,   461,     7,     7,     7,     7,     3,     3,     3,     3,
       3,     3,     3,     3,    10,    11,   590,   591,   592,   585,
     586,   210,   691,   692,   668,   669,    11,   184,   228,   229,
     645,   849,   854,   855,   856,     3,   226,   826,   827,   156,
     821,   847,   313,   117,   511,   512,   513,     3,     3,    10,
      11,   121,   123,   518,   519,   520,   521,   522,   529,     7,
     864,    83,   480,     7,    11,   940,     3,     3,     3,     3,
       7,     5,   162,    11,   588,   163,   164,   587,   852,   853,
     212,   731,   732,   693,   694,    11,   670,   849,   854,   200,
     646,   648,   649,     3,     4,   833,   828,   847,     3,    10,
      11,   822,   823,   824,   117,   512,   124,     7,     7,   118,
     523,   524,   525,     3,     3,    10,    11,   122,   123,   530,
     531,   532,   533,   544,     3,    91,     3,    86,   462,     3,
     162,     7,     3,     3,   216,   786,   787,   733,   734,    11,
     695,   849,   854,   200,   671,   673,   674,   204,   647,   654,
     655,    10,    11,   650,   651,   652,     7,     3,   172,   175,
     818,   834,   835,    10,    11,   829,   830,   831,     7,   581,
     825,    18,   514,     3,     3,   118,   524,   126,     7,     7,
     119,   534,   535,   536,     3,     3,   167,     7,     7,   214,
     761,   762,   788,   789,    11,   735,   849,   854,   200,   696,
     698,   699,   204,   672,   679,   680,    10,    11,   675,   676,
     677,   199,   206,   660,   661,    10,    11,   656,   657,   658,
     581,   653,     3,   836,   837,   581,   832,     3,   225,     3,
      10,    11,   515,    18,   526,     3,     3,   119,   535,   128,
       7,     7,     3,     3,   197,   640,   763,   764,    11,   790,
     849,   854,   200,   736,   738,   739,   204,   697,   704,   705,
      10,    11,   700,   701,   702,   209,   206,   685,   686,    10,
      11,   681,   682,   683,   581,   678,    10,    11,   662,   663,
     664,   581,   659,   201,    10,    11,   841,   842,   843,   230,
     231,   608,   838,   839,   840,   227,     7,   125,     3,    10,
      11,   527,    18,   537,     3,     3,    11,   765,   849,   854,
     200,   791,   793,   794,   204,   737,   744,   745,    10,    11,
     740,   741,   742,   211,   206,   710,   711,    10,    11,   706,
     707,   708,   581,   703,    10,    11,   687,   688,   689,   581,
     684,   201,   161,   593,   594,   599,   665,   205,   615,   844,
     578,   578,     3,     7,   127,     3,    10,    11,   538,   200,
     766,   768,   769,   204,   792,   799,   800,    10,    11,   795,
     796,   797,   213,   206,   750,   751,    10,    11,   746,   747,
     748,   581,   743,    10,    11,   712,   713,   714,   581,   709,
     201,   581,   690,   205,   851,   166,   595,   596,   207,   633,
     173,     7,     7,     3,     7,   129,   204,   767,   774,   775,
      10,    11,   770,   771,   772,   217,   206,   805,   806,    10,
      11,   801,   802,   803,   581,   798,    10,    11,   752,   753,
     754,   581,   749,   201,   715,   716,   205,   207,    10,    11,
     600,   601,   602,   597,   853,   578,   578,     3,   215,   206,
     780,   781,    10,    11,   776,   777,   778,   581,   773,    10,
      11,   807,   808,   809,   581,   804,   201,   755,   205,   207,
     166,   717,   718,     5,   162,    11,   598,    10,    11,   782,
     783,   784,   581,   779,   201,   581,   810,   205,   166,   207,
     756,   757,   719,   720,   162,   577,   581,   785,   205,   207,
      10,    11,   758,   759,   760,    10,    11,   723,   724,   725,
     180,   185,   721,   722,   850,   167,   207,   864,   726,     3,
       3,   167,   167,   220,   727,   728,   577,     7,   325,   729,
       3,     3,     3,    11,   730,   577,     7,     3,   221
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

  case 268:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 275:

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

  case 276:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 277:

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

  case 280:

    {
    if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many stages");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 281:

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

  case 283:

    {
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 288:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 293:

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

  case 294:

    {
    if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");
    parserData->stageVariablesOrdered = true;
    parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 295:

    {
    if ((parserData->stageVariablesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
    }
    break;

  case 296:

    {
      if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few variables supplied");
      }
    break;

  case 301:

    {if (parserData->stageVariablesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no varlist expected");}
    break;

  case 303:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index out of range");         
    if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variables in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stagevarcount++;
}
    break;

  case 307:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 312:

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

  case 313:

    {
    if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");
    parserData->stageConstraintsOrdered = true;
    parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 314:

    {
    if ((parserData->stageConstraintsOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
    }
    break;

  case 315:

    {
      if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few constraints supplied");
      }
    break;

  case 320:

    {if (parserData->stageConstraintsOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no conlist expected");}
    break;

  case 322:

    {
    if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constraint index out of range");         
    if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many constraints in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageconcount++;
}
    break;

  case 325:

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

  case 326:

    {
      parserData->stageObjectivesON = true;
    }
    break;

  case 331:

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

  case 332:

    {
    if ((parserData->stageObjectivesOrdered != true) && 
         (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objlist missing");
    for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
        osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
    }
    break;

  case 333:

    {
      if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
          parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too few objectives supplied");
    }
    break;

  case 338:

    {if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "no objlist expected");}
    break;

  case 340:

    {
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");         
    if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many objectives in this stage");
    osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
    parserData->stageobjcount++;
}
    break;

  case 343:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 344:

    {
        parserData->intervalhorizonON = false;
        parserData->intervalstartON = false;
        printf("Interval not yet supported.\n\n");
}
    break;

  case 349:

    { if(parserData->intervalhorizonON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval horizon attributes");
        parserData->intervalhorizonON = true; }
    break;

  case 350:

    { if(parserData->intervalstartON) 
       parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many interval start attributes");
        parserData->intervalstartON = true; }
    break;

  case 351:

    {
    if (parserData->stageObjectivesOrdered == true) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "duplicate attribute");
    if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objective index out of range");
    parserData->stageObjectivesOrdered = true;
    parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 352:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalhorizon = parserData->tempVal;}
    break;

  case 353:

    {
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        parserData->intervalstart = parserData->tempVal;}
    break;

  case 354:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOfEl = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 355:

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

  case 356:

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

  case 357:

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

  case 358:

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

  case 359:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 360:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 361:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 362:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix terms cannot be negative");
    parserData->numberOfMatrixTerms = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 363:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
    parserData->numberOfMatrixExpr = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 364:

    {
    if (parserData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->namePresent = true;
    parserData->name = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 365:

    {
    if (parserData->shapePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "shape attribute previously set");
    parserData->shapePresent = true;
    parserData->shape = (yyvsp[(2) - (3)].sval); 
}
    break;

  case 366:

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

  case 367:

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

  case 368:

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

  case 369:

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

  case 370:

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

  case 371:

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

  case 372:

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

  case 373:

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

  case 374:

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

  case 375:

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

  case 376:

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

  case 377:

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

  case 378:

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

  case 379:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "template matrix index cannot be negative");
    parserData->templateMatrixIdxAttributePresent = true;
    parserData->templateMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 380:

    {
    if (parserData->varTypeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType attribute previously set");
    parserData->varTypeAttributePresent = true;
    if ((yyvsp[(2) - (3)].sval) != "true" && (yyvsp[(2) - (3)].sval) != "false")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType must be one of C, B, I, S, D, J");
    else
        parserData->varType = *((yyvsp[(2) - (3)].sval));
std::cout << "default var type: " << parserData->varType << std::endl;
}
    break;

  case 381:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->varReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varReference matrix index cannot be negative");
    parserData->varReferenceMatrixIdxAttributePresent = true;
    parserData->varReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 382:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->objReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objReference matrix index cannot be negative");
    parserData->objReferenceMatrixIdxAttributePresent = true;
    parserData->objReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 383:

    {
    if ((yyvsp[(2) - (4)].sval) != (yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->conReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReference matrix index cannot be negative");
    parserData->conReferenceMatrixIdxAttributePresent = true;
    parserData->conReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 384:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 385:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 393:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 398:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 404:

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

  case 410:

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

  case 411:

    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 416:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 419:

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

  case 425:

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

  case 426:

    {
//	IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osinstance->instanceData->matrices->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osinstance->instanceData->matrices->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 427:

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

  case 428:

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

  case 436:

    { 
std::string ts = (yyvsp[(2) - (3)].sval);
std::cout << "symmetry attribute read:   |" << (yyvsp[(2) - (3)].sval) << "|" << std::endl;
std::cout << "symmetry attribute stored: |" << ts << "|" << std::endl;
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 437:

    { 
std::string ts = (yyvsp[(2) - (3)].sval);
std::cout << "matrix name attribute read:   |" << (yyvsp[(2) - (3)].sval) << "|" << std::endl;
std::cout << "matrix name attribute stored: |" << ts << "|" << std::endl;
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 438:

    {
std::string ts = (yyvsp[(2) - (3)].sval);
std::cout << "matrix type attribute read:   |" << (yyvsp[(2) - (3)].sval) << "|" << std::endl;
std::cout << "matrix type attribute stored: |" << ts << "|" << std::endl;
    if (osglData->matrixTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->matrixTypeAttributePresent = true;   
    osglData->matrixTypeAttribute = (yyvsp[(2) - (3)].sval); 
//    free($2);
}
    break;

  case 442:

    {
//    ((MatrixConstructor*)osglData->mtxBlkVec.back())->m_mChildren = 
//        new MatrixConstructor*[((MatrixConstructor*)osglData->mtxBlkVec.back())->inumberOfChildren];
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 445:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 446:

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

  case 447:

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

  case 459:

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

  case 460:

    { 
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 461:

    { 
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 462:

    { 
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 463:

    { 
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 464:

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

  case 465:

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

  case 466:

    { 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
}
    break;

  case 469:

    {
    osglData->baseTransposeAttribute = true;
}
    break;

  case 470:

    {
std::string ts = (yyvsp[(2) - (3)].sval);
std::cout << "baseTranspose attribute read:   |" << (yyvsp[(2) - (3)].sval) << "|" << std::endl;
std::cout << "baseTranspose attribute stored: |" << ts << "|" << std::endl;
    if      ((yyvsp[(2) - (3)].sval) == "false") osglData->baseTransposeAttribute = false;
    else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->baseTransposeAttribute = true;
    else if ((yyvsp[(2) - (3)].sval) == "")      osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
//    free($2);
}
    break;

  case 471:

    {
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
}
    break;

  case 475:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 479:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 480:

    {
    osglData->tempC = new MatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
//    osglData->rowMajorAttribute = false;
}
    break;

  case 488:

    {
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 489:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 492:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 493:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 497:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 498:

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

  case 504:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->numberOfEl
        = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 505:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 511:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->values = new DoubleVector();
    ((MatrixElements*)osglData->tempC)->constantElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->values->el = osglData->osglDblArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 512:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 520:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements = new VarReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 521:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 524:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 525:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 529:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 530:

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

  case 536:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 537:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 543:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 544:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 552:

    {
    ((MatrixElements*)osglData->tempC)->linearElements = new LinearMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 553:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 556:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 557:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 561:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 562:

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

  case 568:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 569:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 575:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <values> element");
    }
    break;

  case 576:

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

  case 577:

    {
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglNonzeroCounter = 0;
    ((MatrixElements*)osglData->tempC)->linearElements->values = new LinearMatrixValues();
    ((MatrixElements*)osglData->tempC)->linearElements->values->numberOfEl
        = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;    
    ((MatrixElements*)osglData->tempC)->linearElements->values->el
        = new LinearMatrixElement*[((MatrixElements*)osglData->tempC)->linearElements->numberOfValues]; 
    for (int i=0; i < ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues; i++)
        ((MatrixElements*)osglData->tempC)->linearElements->values->el[i]
            = new LinearMatrixElement(); 
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 585:

    {
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
        
}
    break;

  case 586:

    {
    osglData->osglNumberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 587:

    {
    if (!osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
}
    break;

  case 592:

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

  case 600:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 602:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 603:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = parserData->tempVal;
}
    break;

  case 606:

    {
    ((MatrixElements*)osglData->tempC)->generalElements = new GeneralMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 607:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 610:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 611:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 615:

    {
    ((MatrixElements*)osglData->tempC)->generalElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 616:

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

  case 622:

    {
    ((MatrixElements*)osglData->tempC)->generalElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 623:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 631:

    {
    osglData->osglNonzeroCounter = 0;
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;

    ((MatrixElements*)osglData->tempC)->generalElements->values = new GeneralMatrixValues();
    ((MatrixElements*)osglData->tempC)->generalElements->values->numberOfEl = osglData->osglNumberOfNonzeros;
    ((MatrixElements*)osglData->tempC)->generalElements->values->el
        = new OSExpressionTree*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((MatrixElements*)osglData->tempC)->generalElements->values->el[i] = new OSExpressionTree();
std::cout << "values vector has length " << osglData->osglNumberOfNonzeros << std::endl;  
}
    break;

  case 639:

    {
        if (osglData->osglNumberOfNonzeros >= osglData->osglNonzeroCounter) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, " number of <el> terms greater than expected");
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
    }
    break;

  case 643:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((MatrixElements*)osglData->tempC)->generalElements->values->el[osglData->osglNonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->osglNonzeroCounter++;
    }
    break;

  case 646:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements = new ConReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 647:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 650:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 651:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 655:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 656:

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

  case 667:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 668:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 674:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 675:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 683:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements = new ObjReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
}
    break;

  case 684:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 687:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 688:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 692:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 693:

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

  case 699:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 700:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 706:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->el = osglData->osglIntArray;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 707:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 713:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 714:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 717:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 718:

    {
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks = osglData->numberOfBlocks;
}
    break;

  case 719:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 721:

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

  case 722:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 723:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 729:

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

  case 730:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 731:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 746:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 747:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
    osglData->blockRowIdxAttributePresent = true;        
    osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 748:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
    osglData->blockColIdxAttributePresent = true;        
    osglData->blockColIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 754:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 755:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 756:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 757:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 758:

    {
    if (osglData->numberOfValuesAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesAttributePresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 759:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 760:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 761:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 762:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 765:

    {
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajorAttribute = true;
    osglData->rowMajorAttributePresent = true;
}
    break;

  case 766:

    { 
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
std::string ts = (yyvsp[(2) - (3)].sval);
std::cout << "rowMajor attribute read:   |" << (yyvsp[(2) - (3)].sval) << "|" << std::endl;
std::cout << "rowMajor attribute stored: |" << ts << "|" << std::endl;
 ts = (yyvsp[(3) - (3)].sval);
std::cout << "QUOTE read:   |" << (yyvsp[(3) - (3)].sval) << "|" << std::endl;
std::cout << "QUOTE stored: |" << ts << "|" << std::endl;

        if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;

        if      ((yyvsp[(2) - (3)].sval) == "false") osglData->rowMajorAttribute = false;
        else if ((yyvsp[(2) - (3)].sval) == "true")  osglData->rowMajorAttribute = true;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorAttributePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 768:

    {  
        if (osnlData->nlnodecount < osnlData->tmpnlcount)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 769:

    {               
    osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
}
    break;

  case 770:

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

  case 773:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->nlnodecount++;
    }
    break;

  case 774:

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

  case 775:

    { 
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        //osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
    }
    break;

  case 803:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 807:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 811:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 813:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 815:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 817:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 819:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 821:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 823:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 825:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 827:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 829:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 831:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 833:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 835:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 836:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 837:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 838:

    {
}
    break;

  case 839:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 840:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 841:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 843:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 845:

    {
//    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 847:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 848:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 856:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 858:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 860:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 861:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 862:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 865:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 869:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 870:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 871:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 872:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 873:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 874:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 876:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 877:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 878:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 880:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 881:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 882:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 884:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 885:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 886:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 888:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 889:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 890:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 892:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 908:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 909:

    {osnlData->matrixidxattON = false;}
    break;

  case 912:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 914:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 917:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 920:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 923:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 926:

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

  case 936:

    {
    if ((yyvsp[(2) - (3)].sval) != "false" && (yyvsp[(2) - (3)].sval) != "true")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "includeDiagonal attribute must be \"true\" or \"false\"");
    else 
        osnlData->includeDiagonalAttribute = (yyvsp[(2) - (3)].sval);
//    free($2);
}
    break;

  case 938:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 942:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 945:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 948:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 950:

    {
//    osnlData->nlNodePoint = new OSnLNodeProduct();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
//    osnlData->mtxProdVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 951:

    {
//    osnlData->mtxProdVec.back()->m_mChildren = new OSnLNode*[ osnlData->mtxProdVec.back()->inumberOfMatrixChildren];
//    osnlData->mtxProdVec.pop_back();
}
    break;

  case 953:

    { /*osnlData->mtxProdVec.back()->inumberOfMatrixChildren++; */}
    break;

  case 955:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 958:

    {
//    osnlData->nlNodePoint = new OSnLNodeTimes();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 961:

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


