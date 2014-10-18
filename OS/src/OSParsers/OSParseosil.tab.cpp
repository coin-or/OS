
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
     MATRIXNEGATESTART = 559,
     MATRIXNEGATEEND = 560,
     MATRIXPLUSSTART = 561,
     MATRIXPLUSEND = 562,
     MATRIXTIMESSTART = 563,
     MATRIXTIMESEND = 564,
     MATRIXPRODUCTSTART = 565,
     MATRIXPRODUCTEND = 566,
     MATRIXSCALARTIMESSTART = 567,
     MATRIXSCALARTIMESEND = 568,
     MATRIXSUBMATRIXATSTART = 569,
     MATRIXSUBMATRIXATEND = 570,
     MATRIXTRANSPOSESTART = 571,
     MATRIXTRANSPOSEEND = 572,
     MATRIXREFERENCESTART = 573,
     MATRIXREFERENCEEND = 574,
     IDENTITYMATRIXSTART = 575,
     IDENTITYMATRIXEND = 576,
     MATRIXINVERSESTART = 577,
     MATRIXINVERSEEND = 578,
     EMPTYINCLUDEDIAGONALATT = 579,
     INCLUDEDIAGONALATT = 580,
     IDATT = 581,
     COEFATT = 582
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
#define MATRIXNEGATESTART 559
#define MATRIXNEGATEEND 560
#define MATRIXPLUSSTART 561
#define MATRIXPLUSEND 562
#define MATRIXTIMESSTART 563
#define MATRIXTIMESEND 564
#define MATRIXPRODUCTSTART 565
#define MATRIXPRODUCTEND 566
#define MATRIXSCALARTIMESSTART 567
#define MATRIXSCALARTIMESEND 568
#define MATRIXSUBMATRIXATSTART 569
#define MATRIXSUBMATRIXATEND 570
#define MATRIXTRANSPOSESTART 571
#define MATRIXTRANSPOSEEND 572
#define MATRIXREFERENCESTART 573
#define MATRIXREFERENCEEND 574
#define IDENTITYMATRIXSTART 575
#define IDENTITYMATRIXEND 576
#define MATRIXINVERSESTART 577
#define MATRIXINVERSEEND 578
#define EMPTYINCLUDEDIAGONALATT 579
#define INCLUDEDIAGONALATT 580
#define IDATT 581
#define COEFATT 582




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
#define YYLAST   1218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  332
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  662
/* YYNRULES -- Number of rules.  */
#define YYNRULES  960
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1524

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   582

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   329,
     331,     2,     2,   330,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   328,     2,     2,     2,     2,     2,     2,     2,
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
     325,   326,   327
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
    1727,  1731,  1733,  1736,  1738,  1740,  1742,  1744,  1748,  1750,
    1753,  1755,  1757,  1759,  1761,  1765,  1767,  1768,  1773,  1775,
    1777,  1778,  1781,  1783,  1785,  1789,  1790,  1793,  1796,  1798,
    1800,  1802,  1804,  1808,  1810,  1813,  1815,  1817,  1819,  1821,
    1825,  1827,  1830,  1832,  1834,  1836,  1838,  1842,  1844,  1849,
    1851,  1853,  1857,  1859,  1861,  1867,  1869,  1873,  1875,  1877,
    1879,  1881,  1883,  1887,  1889,  1893,  1895,  1897,  1899,  1901,
    1903,  1907,  1909,  1910,  1913,  1917,  1919,  1921,  1922,  1925,
    1927,  1929,  1931,  1936,  1941,  1943,  1945,  1947,  1951,  1954,
    1959,  1964,  1969,  1974,  1979,  1984,  1989,  1994,  1999,  2001,
    2003,  2005,  2009,  2010,  2015,  2017,  2023,  2024,  2027,  2033,
    2035,  2040,  2042,  2044,  2046,  2048,  2050,  2052,  2054,  2056,
    2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,
    2078,  2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2095,
    2099,  2101,  2104,  2105,  2109,  2111,  2114,  2115,  2121,  2122,
    2128,  2129,  2135,  2136,  2141,  2142,  2148,  2149,  2155,  2156,
    2161,  2162,  2167,  2168,  2173,  2174,  2179,  2180,  2185,  2186,
    2191,  2192,  2197,  2198,  2203,  2204,  2211,  2212,  2217,  2218,
    2223,  2224,  2229,  2230,  2235,  2237,  2240,  2241,  2244,  2246,
    2248,  2250,  2251,  2256,  2257,  2262,  2267,  2268,  2273,  2275,
    2278,  2279,  2284,  2285,  2288,  2290,  2292,  2297,  2302,  2303,
    2308,  2309,  2312,  2313,  2318,  2319,  2322,  2323,  2328,  2329,
    2332,  2333,  2338,  2339,  2342,  2343,  2348,  2349,  2352,  2354,
    2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,  2372,  2374,
    2376,  2378,  2380,  2382,  2384,  2388,  2390,  2392,  2395,  2400,
    2403,  2405,  2408,  2411,  2413,  2417,  2420,  2422,  2425,  2428,
    2430,  2433,  2438,  2440,  2441,  2443,  2446,  2451,  2453,  2454,
    2456,  2459,  2463,  2466,  2468,  2470,  2473,  2476,  2478,  2482,
    2485,  2487,  2490,  2493,  2495,  2499,  2502,  2504,  2508,  2509,
    2514,  2515,  2518,  2521,  2523,  2527,  2530,  2532,  2539,  2542,
    2544
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     333,     0,    -1,   337,   859,   349,   356,   424,   492,   334,
     335,    -1,    14,    -1,    13,    -1,   336,    -1,    12,    -1,
      -1,    -1,    24,   338,   339,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   339,   340,    -1,   341,   343,   342,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   343,
     344,    -1,   345,    -1,   346,    -1,   347,    -1,   348,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     327,     3,   579,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   350,   351,   352,    -1,    29,    -1,   550,    -1,   353,
      -1,   354,    -1,    10,    -1,    11,   355,    30,    -1,    -1,
     355,   605,    -1,    -1,   357,   358,   359,    -1,    32,    -1,
     551,    -1,   360,    -1,   361,    -1,    10,    -1,    11,   362,
      33,    -1,    -1,   362,   363,    -1,   364,    -1,   370,    -1,
     376,    -1,   382,    -1,   388,    -1,   394,    -1,   409,    -1,
     365,   366,   369,    -1,    35,    -1,   367,    -1,    -1,   367,
     368,    -1,   552,    -1,   553,    -1,   559,    -1,    10,    -1,
      11,    36,    -1,   371,   372,   375,    -1,    37,    -1,   373,
      -1,    -1,   373,   374,    -1,   552,    -1,   553,    -1,   559,
      -1,    10,    -1,    11,    38,    -1,   377,   378,   381,    -1,
      41,    -1,   379,    -1,    -1,   379,   380,    -1,   552,    -1,
     553,    -1,   559,    -1,   562,    -1,   561,    -1,   563,    -1,
      10,    -1,    11,    42,    -1,   383,   384,   387,    -1,    43,
      -1,   385,    -1,    -1,   385,   386,    -1,   552,    -1,   553,
      -1,   559,    -1,   562,    -1,   561,    -1,   564,    -1,   565,
      -1,    10,    -1,    11,    44,    -1,   389,   390,   393,    -1,
      45,    -1,   391,    -1,    -1,   391,   392,    -1,   552,    -1,
     553,    -1,   559,    -1,   566,    -1,    10,    -1,    11,    46,
      -1,   395,   396,   399,    -1,    47,    -1,   397,    -1,    -1,
     397,   398,    -1,   552,    -1,   553,    -1,   559,    -1,    11,
     400,   408,    -1,   401,   402,   403,    -1,    55,    -1,   549,
      -1,   404,    -1,   405,    -1,    10,    -1,    11,   406,   407,
      -1,   583,    -1,    56,    -1,    48,    -1,   410,   411,   414,
      -1,    49,    -1,   412,    -1,    -1,   412,   413,    -1,   552,
      -1,   553,    -1,   559,    -1,    11,   415,   423,    -1,   416,
     417,   418,    -1,    57,    -1,   549,    -1,   419,    -1,   420,
      -1,    10,    -1,    11,   421,   422,    -1,   583,    -1,    58,
      -1,    50,    -1,    -1,   425,   426,    -1,    66,    -1,   427,
      -1,   428,    -1,    10,    -1,    11,   429,   443,   465,   483,
      67,    -1,    -1,   430,   431,   432,    -1,    69,    -1,   554,
      -1,   433,    -1,   434,    -1,    10,    -1,    11,   436,   435,
      -1,    70,    -1,    -1,   436,   437,    -1,   438,   439,   442,
      -1,    72,    -1,   440,    -1,    -1,   440,   441,    -1,   850,
      -1,   848,    -1,   574,    -1,   576,    -1,   568,    -1,   570,
      -1,   571,    -1,   572,    -1,   559,    -1,   575,    -1,    10,
      -1,    11,    73,    -1,    -1,   444,   445,   446,    -1,    74,
      -1,   555,    -1,   447,    -1,   448,    -1,    10,    -1,    11,
     450,   449,    -1,    75,    -1,    -1,   450,   451,    -1,   452,
     453,   456,    -1,    77,    -1,   454,    -1,    -1,   454,   455,
      -1,   850,    -1,   848,    -1,   574,    -1,   577,    -1,   573,
      -1,   569,    -1,   559,    -1,   560,    -1,   557,    -1,   457,
      -1,   458,    -1,    10,    -1,    11,   459,   460,    -1,   461,
      -1,    78,    -1,    -1,   461,   462,    -1,   463,   942,   464,
      -1,    85,    11,    -1,    86,    -1,    -1,   466,   467,   468,
      -1,    79,    -1,   556,    -1,   469,    -1,   470,    -1,    10,
      -1,    11,   472,   471,    -1,    80,    -1,    -1,   472,   473,
      -1,   474,   475,   478,    -1,    82,    -1,   476,    -1,    -1,
     476,   477,    -1,   850,    -1,   848,    -1,   574,    -1,   578,
      -1,   568,    -1,   570,    -1,   571,    -1,   572,    -1,   559,
      -1,   560,    -1,   557,    -1,   479,    -1,   480,    -1,    10,
      -1,    11,   481,   482,    -1,   461,    -1,    83,    -1,    -1,
     484,   485,   486,    -1,    87,    -1,   558,    -1,   487,    -1,
     488,    -1,    10,    -1,    11,   489,    88,    -1,    -1,   489,
     490,    -1,    90,   491,    11,   866,    91,    -1,    18,     3,
       7,     3,    -1,    -1,   493,   494,    -1,   105,    -1,   495,
      -1,   496,    -1,    10,    -1,    11,   106,    -1,    11,   497,
     106,    -1,    11,   541,   106,    -1,   498,   499,   500,   108,
      -1,   107,    -1,   111,     3,     7,     3,    11,    -1,   501,
      -1,   500,   501,    -1,    -1,   502,   109,   503,   504,    -1,
      -1,    21,     4,     3,    -1,    10,    -1,    11,   505,   110,
      -1,   506,   518,   530,    -1,    -1,   114,   507,   511,    -1,
      -1,   507,   508,    -1,   509,    -1,   510,    -1,   120,     3,
       7,     3,    -1,   123,     3,     7,     3,    -1,   512,    -1,
      11,   513,   117,    -1,    10,    -1,    11,   117,    -1,   514,
      -1,   513,   514,    -1,    -1,   515,   124,   516,   517,    -1,
      18,     3,     7,     3,    -1,    10,    -1,    11,   125,    -1,
      -1,   115,   519,   523,    -1,    -1,   519,   520,    -1,   521,
      -1,   522,    -1,   121,     3,     7,     3,    -1,   123,     3,
       7,     3,    -1,   524,    -1,    11,   525,   118,    -1,    10,
      -1,    11,   118,    -1,   526,    -1,   525,   526,    -1,    -1,
     527,   126,   528,   529,    -1,    18,     3,     7,     3,    -1,
      10,    -1,    11,   127,    -1,    -1,   116,   531,   534,    -1,
      -1,   531,   532,    -1,   533,    -1,   546,    -1,   122,     3,
       7,     3,    -1,   535,    -1,    11,   536,   119,    -1,    10,
      -1,    11,   119,    -1,   537,    -1,   536,   537,    -1,    -1,
     538,   128,   539,   540,    -1,    18,     3,     7,     3,    -1,
      10,    -1,    11,   129,    -1,    -1,   542,   130,   544,   543,
      -1,    10,    -1,    11,   131,    -1,    -1,   544,   545,    -1,
     547,    -1,   548,    -1,   123,     3,     7,     3,    -1,   112,
       3,   579,     3,    -1,   113,     3,   579,     3,    -1,   156,
     580,     7,   580,    -1,    31,     3,     7,     3,    -1,    34,
       3,     7,     3,    -1,   183,     3,     7,     3,    -1,   182,
       3,     7,     3,    -1,    71,     3,     7,     3,    -1,    76,
       3,     7,     3,    -1,    81,     3,     7,     3,    -1,    84,
       3,     7,     3,    -1,    89,     3,     7,     3,    -1,    21,
       4,     3,    -1,   103,     4,     3,    -1,    59,     3,   579,
       3,    -1,    60,     3,     7,     3,    -1,    61,     3,     7,
       3,    -1,    62,     3,     7,     3,    -1,    63,     3,     7,
       3,    -1,    65,     4,     3,    -1,    92,     3,     7,     3,
      -1,    93,     3,     7,     3,    -1,   102,     3,     7,     3,
      -1,    94,     3,     7,     3,    -1,    95,     3,     7,     3,
      -1,    96,     3,     7,     3,    -1,   101,     3,     7,     3,
      -1,    97,     3,     7,     3,    -1,    68,     4,     3,    -1,
      98,     3,     7,     3,    -1,    99,     3,     7,     3,    -1,
     100,     3,     7,     3,    -1,   581,     7,   581,    -1,   581,
       8,   581,    -1,   581,     3,    -1,    -1,   581,   582,    -1,
     328,    -1,   329,    -1,   330,    -1,   331,    -1,   584,    -1,
     591,    -1,    -1,   584,   585,    -1,   586,   587,   590,    -1,
     166,    -1,   588,    -1,    -1,   588,   589,    -1,   855,    -1,
     854,    -1,    11,     7,   167,    -1,   161,   853,   592,    -1,
     593,    -1,   594,    -1,    11,   162,    -1,    10,    -1,    11,
       5,   162,    -1,   596,    -1,   601,    -1,    -1,   596,   597,
      -1,   598,   599,   600,    -1,   166,    -1,    -1,   855,    -1,
      11,   579,   167,    -1,   161,   853,   602,    -1,   603,    -1,
     604,    -1,    11,   162,    -1,    10,    -1,    11,     5,   162,
      -1,   606,   607,   613,    -1,   168,    -1,   608,    -1,    -1,
     608,   609,    -1,   610,    -1,   850,    -1,   848,    -1,   611,
      -1,   612,    -1,   177,     4,     3,    -1,    21,     4,     3,
      -1,    22,     4,     3,    -1,   614,    -1,   615,    -1,    10,
      -1,    11,   616,   169,    -1,   617,   635,    -1,    -1,   618,
     619,   634,    -1,   171,    -1,   620,    -1,    -1,   620,   621,
      -1,   622,    -1,   623,    -1,   624,    -1,   625,    -1,   626,
      -1,   627,    -1,   628,    -1,   629,    -1,   633,    -1,   186,
       3,     7,     3,    -1,   187,     3,     7,     3,    -1,   188,
       3,     7,     3,    -1,   189,     3,     7,     3,    -1,   190,
       3,     7,     3,    -1,   191,     3,     7,     3,    -1,   192,
       3,     7,     3,    -1,   630,    -1,   631,    -1,   632,    -1,
     194,    -1,   195,     4,   580,    -1,   193,     3,   579,     3,
      -1,    11,   170,    -1,    10,    -1,    -1,   635,   636,    -1,
     637,    -1,   813,    -1,   816,    -1,   638,   639,    -1,   196,
      -1,   640,    -1,   641,    -1,    10,    -1,    11,   643,   668,
     693,   733,   788,   763,   642,    -1,   197,    -1,    -1,   644,
     645,    11,   648,    -1,   198,    -1,   646,    -1,    -1,   646,
     647,    -1,   851,    -1,   856,    -1,   650,   649,   199,    -1,
      -1,   656,   662,    -1,   651,   652,    -1,   200,    -1,   653,
      -1,   654,    -1,    10,    -1,    11,   655,   201,    -1,   583,
      -1,   657,   658,    -1,   204,    -1,   659,    -1,   660,    -1,
      10,    -1,    11,   661,   205,    -1,   583,    -1,   663,   664,
      -1,   206,    -1,   665,    -1,   666,    -1,    10,    -1,    11,
     667,   207,    -1,   595,    -1,    -1,   669,   670,    11,   673,
      -1,   208,    -1,   671,    -1,    -1,   671,   672,    -1,   851,
      -1,   856,    -1,   675,   674,   209,    -1,    -1,   681,   687,
      -1,   676,   677,    -1,   200,    -1,   678,    -1,   679,    -1,
      10,    -1,    11,   680,   201,    -1,   583,    -1,   682,   683,
      -1,   204,    -1,   684,    -1,   685,    -1,    10,    -1,    11,
     686,   205,    -1,   583,    -1,   688,   689,    -1,   206,    -1,
     690,    -1,   691,    -1,    10,    -1,    11,   692,   207,    -1,
     583,    -1,    -1,   694,   695,    11,   698,    -1,   210,    -1,
     696,    -1,    -1,   696,   697,    -1,   851,    -1,   856,    -1,
     700,   699,   211,    -1,    -1,   706,   712,    -1,   701,   702,
      -1,   200,    -1,   703,    -1,   704,    -1,    10,    -1,    11,
     705,   201,    -1,   583,    -1,   707,   708,    -1,   204,    -1,
     709,    -1,   710,    -1,    10,    -1,    11,   711,   205,    -1,
     583,    -1,    -1,   713,   714,    -1,   206,    -1,   715,    -1,
     716,    -1,    10,    -1,    11,   717,   207,    -1,   718,    -1,
      -1,   718,   719,    -1,   720,   721,   725,    -1,   166,    -1,
     722,    -1,    -1,   722,   723,    -1,   852,    -1,   724,    -1,
     180,     3,   579,     3,    -1,   726,    -1,   727,    -1,    10,
      -1,    11,   728,   167,    -1,    -1,   728,   729,    -1,   730,
     731,   732,    -1,   220,    -1,    -1,   327,     3,   579,     3,
      -1,    11,     7,   221,    -1,    -1,   734,   735,    11,   738,
      -1,   212,    -1,   736,    -1,    -1,   736,   737,    -1,   851,
      -1,   856,    -1,   740,   739,   213,    -1,    -1,   746,   752,
      -1,   741,   742,    -1,   200,    -1,   743,    -1,   744,    -1,
      10,    -1,    11,   745,   201,    -1,   583,    -1,   747,   748,
      -1,   204,    -1,   749,    -1,   750,    -1,    10,    -1,    11,
     751,   205,    -1,   583,    -1,    -1,   753,   754,    -1,   206,
      -1,   755,    -1,   756,    -1,    10,    -1,    11,   757,   207,
      -1,    -1,   757,   758,    -1,   759,   760,    -1,   166,    -1,
     761,    -1,   762,    -1,    10,    -1,    11,   866,   167,    -1,
      -1,   764,   765,    11,   768,    -1,   214,    -1,   766,    -1,
      -1,   766,   767,    -1,   851,    -1,   856,    -1,   770,   769,
     215,    -1,    -1,   776,   782,    -1,   771,   772,    -1,   200,
      -1,   773,    -1,   774,    -1,    10,    -1,    11,   775,   201,
      -1,   583,    -1,   777,   778,    -1,   204,    -1,   779,    -1,
     780,    -1,    10,    -1,    11,   781,   205,    -1,   583,    -1,
     783,   784,    -1,   206,    -1,   785,    -1,   786,    -1,    10,
      -1,    11,   787,   207,    -1,   583,    -1,    -1,   789,   790,
      11,   793,    -1,   216,    -1,   791,    -1,    -1,   791,   792,
      -1,   851,    -1,   856,    -1,   795,   794,   217,    -1,    -1,
     801,   807,    -1,   796,   797,    -1,   200,    -1,   798,    -1,
     799,    -1,    10,    -1,    11,   800,   201,    -1,   583,    -1,
     802,   803,    -1,   204,    -1,   804,    -1,   805,    -1,    10,
      -1,    11,   806,   205,    -1,   583,    -1,   808,   809,    -1,
     206,    -1,   810,    -1,   811,    -1,    10,    -1,    11,   812,
     207,    -1,   583,    -1,   814,    11,   942,   815,    -1,   222,
      -1,   223,    -1,   817,   818,   819,    -1,   174,    -1,   847,
      -1,    11,   821,   828,   835,   820,    -1,   175,    -1,   822,
     823,   824,    -1,   224,    -1,   849,    -1,   825,    -1,   826,
      -1,    10,    -1,    11,   827,   225,    -1,   583,    -1,   829,
     830,   831,    -1,   226,    -1,   849,    -1,   832,    -1,   833,
      -1,    10,    -1,    11,   834,   227,    -1,   583,    -1,    -1,
     835,   836,    -1,   837,   838,   843,    -1,   172,    -1,   839,
      -1,    -1,   839,   840,    -1,   841,    -1,   842,    -1,   610,
      -1,   230,   580,     7,   580,    -1,   231,   580,     7,   580,
      -1,   844,    -1,   845,    -1,    10,    -1,    11,   846,   173,
      -1,   617,   635,    -1,   181,     3,     7,     3,    -1,   182,
       3,     7,     3,    -1,   156,     3,     7,     3,    -1,   183,
       3,     7,     3,    -1,   184,     3,     7,     3,    -1,   185,
       3,     7,     3,    -1,   165,     3,     7,     3,    -1,   163,
       3,     7,     3,    -1,   164,     3,     7,     3,    -1,   857,
      -1,   858,    -1,   228,    -1,   229,     4,     3,    -1,    -1,
     860,   861,   862,   234,    -1,   233,    -1,   235,     3,     7,
       3,    11,    -1,    -1,   862,   863,    -1,   864,   865,    11,
     866,   237,    -1,   236,    -1,    18,     3,     7,     3,    -1,
     909,    -1,   919,    -1,   873,    -1,   875,    -1,   927,    -1,
     877,    -1,   879,    -1,   881,    -1,   883,    -1,   939,    -1,
     885,    -1,   887,    -1,   889,    -1,   893,    -1,   891,    -1,
     895,    -1,   901,    -1,   897,    -1,   899,    -1,   933,    -1,
     936,    -1,   867,    -1,   870,    -1,   930,    -1,   903,    -1,
     905,    -1,   907,    -1,    -1,   278,   868,   869,    -1,    10,
      -1,    11,   279,    -1,    -1,   280,   871,   872,    -1,    10,
      -1,    11,   281,    -1,    -1,   282,   874,   866,   866,   283,
      -1,    -1,   240,   876,   866,   866,   241,    -1,    -1,   242,
     878,   866,   866,   243,    -1,    -1,   256,   880,   866,   257,
      -1,    -1,   244,   882,   866,   866,   245,    -1,    -1,   238,
     884,   866,   866,   239,    -1,    -1,   246,   886,   866,   247,
      -1,    -1,   248,   888,   866,   249,    -1,    -1,   260,   890,
     866,   261,    -1,    -1,   262,   892,   866,   263,    -1,    -1,
     264,   894,   866,   265,    -1,    -1,   254,   896,   866,   255,
      -1,    -1,   268,   898,   866,   269,    -1,    -1,   270,   900,
     866,   271,    -1,    -1,   258,   902,   866,   866,   866,   259,
      -1,    -1,   286,   904,   942,   287,    -1,    -1,   288,   906,
     942,   289,    -1,    -1,   290,   908,   942,   291,    -1,    -1,
     284,   910,   912,   911,    -1,    10,    -1,    11,   285,    -1,
      -1,   912,   913,    -1,   914,    -1,   918,    -1,   916,    -1,
      -1,    22,     4,   915,     3,    -1,    -1,   326,     4,   917,
       3,    -1,    23,     3,   579,     3,    -1,    -1,   266,   920,
     923,   921,    -1,    10,    -1,    11,   267,    -1,    -1,    11,
     866,   922,   267,    -1,    -1,   923,   924,    -1,   925,    -1,
     926,    -1,   327,     3,   579,     3,    -1,    18,     3,     7,
       3,    -1,    -1,   250,   928,   929,   251,    -1,    -1,   929,
     866,    -1,    -1,   274,   931,   932,   275,    -1,    -1,   932,
     866,    -1,    -1,   272,   934,   935,   273,    -1,    -1,   935,
     866,    -1,    -1,   276,   937,   938,   277,    -1,    -1,   938,
     866,    -1,    -1,   252,   940,   941,   253,    -1,    -1,   941,
     866,    -1,   943,    -1,   946,    -1,   949,    -1,   955,    -1,
     958,    -1,   962,    -1,   967,    -1,   970,    -1,   973,    -1,
     976,    -1,   979,    -1,   982,    -1,   985,    -1,   988,    -1,
     991,    -1,   952,    -1,   944,   567,   945,    -1,   318,    -1,
      10,    -1,    11,   319,    -1,    18,     3,     7,     3,    -1,
     947,   948,    -1,   292,    -1,   942,   293,    -1,   950,   951,
      -1,   294,    -1,   942,   942,   295,    -1,   953,   954,    -1,
     320,    -1,   866,   321,    -1,   956,   957,    -1,   322,    -1,
     942,   323,    -1,   959,   960,    11,   961,    -1,   296,    -1,
      -1,   966,    -1,   942,   297,    -1,   963,   964,    11,   965,
      -1,   298,    -1,    -1,   966,    -1,   942,   299,    -1,   325,
       4,     3,    -1,   968,   969,    -1,   300,    -1,    10,    -1,
      11,   301,    -1,   971,   972,    -1,   302,    -1,   942,   942,
     303,    -1,   974,   975,    -1,   304,    -1,   942,   305,    -1,
     977,   978,    -1,   306,    -1,   942,   942,   307,    -1,   980,
     981,    -1,   308,    -1,   942,   942,   309,    -1,    -1,   310,
     983,   984,   311,    -1,    -1,   984,   942,    -1,   986,   987,
      -1,   312,    -1,   866,   942,   313,    -1,   989,   990,    -1,
     314,    -1,   866,   866,   866,   866,   942,   315,    -1,   992,
     993,    -1,   316,    -1,   942,   317,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   386,   386,   389,   390,   392,   401,   402,   405,   406,
     411,   418,   418,   420,   433,   439,   440,   443,   444,   447,
     450,   453,   456,   462,   469,   476,   484,   489,   489,   495,
     500,   513,   513,   515,   517,   527,   527,   530,   530,   532,
     534,   536,   536,   538,   540,   545,   545,   547,   548,   550,
     551,   553,   560,   561,   566,   568,   570,   572,   572,   575,
     576,   577,   579,   579,   581,   583,   585,   587,   587,   590,
     591,   592,   594,   594,   598,   600,   602,   604,   604,   607,
     608,   609,   610,   611,   612,   615,   615,   617,   619,   621,
     623,   623,   626,   627,   628,   629,   630,   631,   632,   635,
     635,   639,   641,   643,   645,   645,   648,   649,   650,   651,
     654,   654,   668,   670,   672,   674,   674,   677,   678,   679,
     682,   684,   686,   688,   690,   690,   692,   694,   696,   698,
     700,   702,   704,   706,   708,   708,   711,   712,   713,   716,
     718,   720,   722,   724,   724,   726,   728,   730,   732,   734,
     743,   743,   745,   747,   747,   749,   752,   754,   754,   756,
     758,   760,   760,   762,   764,   766,   768,   768,   770,   772,
     774,   776,   776,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   791,   792,   794,   794,   796,   798,   800,
     800,   802,   804,   806,   808,   808,   810,   812,   814,   816,
     816,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     830,   830,   832,   834,   836,   838,   842,   842,   844,   846,
     848,   851,   851,   853,   855,   857,   857,   859,   861,   863,
     865,   865,   867,   869,   871,   873,   873,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   889,   889,
     891,   893,   895,   897,   900,   900,   902,   904,   906,   906,
     908,   910,   912,   912,   914,   916,   918,   918,   920,   922,
     922,   924,   925,   928,   929,   932,   983,   985,   999,  1000,
    1002,  1002,  1026,  1027,  1030,  1031,  1033,  1035,  1036,  1040,
    1041,  1043,  1044,  1046,  1062,  1070,  1077,  1082,  1083,  1085,
    1086,  1088,  1088,  1091,  1100,  1101,  1103,  1104,  1108,  1109,
    1111,  1112,  1114,  1130,  1138,  1145,  1150,  1151,  1153,  1154,
    1156,  1156,  1159,  1168,  1169,  1171,  1181,  1185,  1186,  1188,
    1189,  1191,  1207,  1214,  1219,  1220,  1222,  1223,  1225,  1225,
    1228,  1237,  1238,  1243,  1243,  1251,  1252,  1254,  1255,  1257,
    1261,  1267,  1275,  1279,  1284,  1293,  1304,  1315,  1326,  1337,
    1345,  1353,  1361,  1369,  1378,  1388,  1397,  1408,  1419,  1431,
    1442,  1453,  1465,  1476,  1487,  1498,  1509,  1520,  1531,  1542,
    1554,  1568,  1579,  1590,  1603,  1604,  1611,  1613,  1613,  1615,
    1616,  1617,  1618,  1783,  1792,  1794,  1794,  1796,  1798,  1807,
    1809,  1809,  1811,  1811,  1813,  1830,  1833,  1833,  1835,  1835,
    1838,  1869,  1877,  1879,  1879,  1881,  1883,  1891,  1891,  1893,
    1910,  1912,  1912,  1914,  1914,  1916,  2012,  2023,  2047,  2065,
    2065,  2068,  2069,  2070,  2071,  2072,  2075,  2087,  2099,  2111,
    2111,  2113,  2115,  2125,  2127,  2127,  2132,  2151,  2175,  2175,
    2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,  2186,  2188,
    2203,  2213,  2223,  2233,  2243,  2255,  2267,  2274,  2274,  2276,
    2281,  2289,  2297,  2297,  2299,  2299,  2304,  2304,  2304,  2306,
    2312,  2322,  2322,  2324,  2326,  2329,  2331,  2331,  2333,  2343,
    2349,  2349,  2352,  2356,  2362,  2364,  2364,  2366,  2376,  2387,
    2387,  2389,  2391,  2393,  2396,  2407,  2415,  2415,  2417,  2419,
    2421,  2424,  2434,  2442,  2442,  2444,  2446,  2448,  2469,  2469,
    2471,  2479,  2485,  2485,  2488,  2492,  2498,  2500,  2500,  2502,
    2512,  2523,  2523,  2525,  2527,  2529,  2531,  2541,  2549,  2549,
    2551,  2553,  2555,  2558,  2568,  2576,  2576,  2578,  2580,  2582,
    2611,  2611,  2613,  2621,  2627,  2627,  2630,  2634,  2640,  2642,
    2642,  2644,  2654,  2666,  2666,  2668,  2670,  2672,  2675,  2685,
    2693,  2693,  2695,  2697,  2699,  2758,  2763,  2775,  2793,  2793,
    2795,  2797,  2799,  2801,  2801,  2803,  2811,  2817,  2828,  2828,
    2831,  2832,  2834,  2846,  2846,  2848,  2850,  2852,  2852,  2855,
    2857,  2866,  2866,  2871,  2878,  2878,  2880,  2888,  2894,  2894,
    2897,  2901,  2907,  2909,  2909,  2911,  2921,  2933,  2933,  2935,
    2937,  2939,  2942,  2952,  2960,  2960,  2962,  2964,  2966,  3028,
    3029,  3031,  3046,  3046,  3048,  3050,  3052,  3052,  3054,  3056,
    3072,  3072,  3074,  3076,  3086,  3086,  3088,  3096,  3102,  3102,
    3105,  3109,  3115,  3117,  3117,  3119,  3129,  3141,  3141,  3143,
    3145,  3147,  3149,  3159,  3167,  3167,  3169,  3171,  3173,  3176,
    3186,  3194,  3194,  3196,  3198,  3200,  3229,  3229,  3231,  3239,
    3245,  3245,  3248,  3252,  3258,  3260,  3260,  3262,  3272,  3284,
    3284,  3286,  3288,  3290,  3293,  3303,  3311,  3311,  3313,  3315,
    3317,  3320,  3330,  3338,  3338,  3340,  3342,  3344,  3452,  3457,
    3473,  3480,  3491,  3499,  3508,  3513,  3521,  3534,  3540,  3547,
    3547,  3549,  3551,  3553,  3555,  3571,  3577,  3584,  3584,  3586,
    3588,  3590,  3592,  3592,  3594,  3600,  3613,  3615,  3615,  3618,
    3619,  3620,  3627,  3645,  3663,  3663,  3665,  3667,  3673,  3675,
    3684,  3693,  3702,  3711,  3720,  3729,  3734,  3742,  3751,  3751,
    3753,  3762,  3807,  3808,  3814,  3819,  3838,  3839,  3841,  3849,
    3865,  3875,  3876,  3877,  3878,  3879,  3880,  3881,  3882,  3883,
    3884,  3885,  3886,  3887,  3888,  3889,  3890,  3891,  3892,  3893,
    3894,  3895,  3896,  3897,  3898,  3900,  3901,  3902,  3906,  3906,
    3909,  3910,  3912,  3912,  3915,  3916,  3920,  3920,  3925,  3925,
    3930,  3930,  3935,  3935,  3940,  3940,  3945,  3945,  3950,  3950,
    3955,  3955,  3960,  3960,  3965,  3965,  3970,  3970,  3975,  3975,
    3980,  3980,  3987,  3987,  3993,  3993,  4002,  4002,  4007,  4007,
    4012,  4012,  4022,  4022,  4027,  4028,  4030,  4031,  4033,  4034,
    4035,  4039,  4038,  4048,  4047,  4056,  4066,  4065,  4072,  4073,
    4075,  4074,  4081,  4082,  4085,  4091,  4099,  4106,  4126,  4126,
    4137,  4137,  4140,  4140,  4152,  4153,  4156,  4156,  4167,  4168,
    4171,  4171,  4182,  4183,  4186,  4186,  4196,  4197,  4203,  4204,
    4205,  4206,  4207,  4208,  4209,  4210,  4211,  4212,  4213,  4214,
    4215,  4216,  4217,  4218,  4221,  4226,  4233,  4234,  4236,  4244,
    4246,  4252,  4254,  4256,  4262,  4264,  4266,  4272,  4274,  4276,
    4282,  4284,  4286,  4292,  4292,  4294,  4296,  4298,  4304,  4304,
    4306,  4308,  4317,  4319,  4324,  4324,  4326,  4328,  4334,  4337,
    4339,  4345,  4348,  4350,  4356,  4359,  4361,  4367,  4370,  4370,
    4380,  4381,  4385,  4387,  4393,  4395,  4397,  4403,  4406,  4408,
    4414
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
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXNEGATESTART",
  "MATRIXNEGATEEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
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
  "$@35", "anotherproductnlnode", "OSnLMNode", "matrixReference",
  "matrixReferenceStart", "matrixreferenceend", "matrixDiagonal",
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
     575,   576,   577,   578,   579,   580,   581,   582,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   332,   333,   334,   334,   335,   336,   336,   337,   337,
     338,   339,   339,   340,   341,   342,   342,   343,   343,   344,
     344,   344,   344,   345,   346,   347,   348,   349,   349,   350,
     351,   352,   352,   353,   354,   355,   355,   356,   356,   357,
     358,   359,   359,   360,   361,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   364,   365,   366,   367,   367,   368,
     368,   368,   369,   369,   370,   371,   372,   373,   373,   374,
     374,   374,   375,   375,   376,   377,   378,   379,   379,   380,
     380,   380,   380,   380,   380,   381,   381,   382,   383,   384,
     385,   385,   386,   386,   386,   386,   386,   386,   386,   387,
     387,   388,   389,   390,   391,   391,   392,   392,   392,   392,
     393,   393,   394,   395,   396,   397,   397,   398,   398,   398,
     399,   400,   401,   402,   403,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   412,   413,   413,   413,   414,
     415,   416,   417,   418,   418,   419,   420,   421,   422,   423,
     424,   424,   425,   426,   426,   427,   428,   429,   429,   430,
     431,   432,   432,   433,   434,   435,   436,   436,   437,   438,
     439,   440,   440,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   442,   442,   443,   443,   444,   445,   446,
     446,   447,   448,   449,   450,   450,   451,   452,   453,   454,
     454,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     456,   456,   457,   458,   459,   460,   461,   461,   462,   463,
     464,   465,   465,   466,   467,   468,   468,   469,   470,   471,
     472,   472,   473,   474,   475,   476,   476,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   478,   478,
     479,   480,   481,   482,   483,   483,   484,   485,   486,   486,
     487,   488,   489,   489,   490,   491,   492,   492,   493,   494,
     494,   495,   495,   496,   496,   497,   498,   499,   500,   500,
     502,   501,   503,   503,   504,   504,   505,   506,   506,   507,
     507,   508,   508,   509,   510,   511,   511,   512,   512,   513,
     513,   515,   514,   516,   517,   517,   518,   518,   519,   519,
     520,   520,   521,   522,   523,   523,   524,   524,   525,   525,
     527,   526,   528,   529,   529,   530,   530,   531,   531,   532,
     532,   533,   534,   534,   535,   535,   536,   536,   538,   537,
     539,   540,   540,   542,   541,   543,   543,   544,   544,   545,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   579,   580,   581,   581,   582,
     582,   582,   582,   583,   583,   584,   584,   585,   586,   587,
     588,   588,   589,   589,   590,   591,   592,   592,   593,   593,
     594,   595,   595,   596,   596,   597,   598,   599,   599,   600,
     601,   602,   602,   603,   603,   604,   605,   606,   607,   608,
     608,   609,   609,   609,   609,   609,   610,   611,   612,   613,
     613,   614,   615,   616,   617,   617,   618,   619,   620,   620,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   630,   631,
     632,   633,   634,   634,   635,   635,   636,   636,   636,   637,
     638,   639,   639,   640,   641,   642,   643,   643,   644,   645,
     646,   646,   647,   647,   648,   649,   649,   650,   651,   652,
     652,   653,   654,   655,   656,   657,   658,   658,   659,   660,
     661,   662,   663,   664,   664,   665,   666,   667,   668,   668,
     669,   670,   671,   671,   672,   672,   673,   674,   674,   675,
     676,   677,   677,   678,   679,   680,   681,   682,   683,   683,
     684,   685,   686,   687,   688,   689,   689,   690,   691,   692,
     693,   693,   694,   695,   696,   696,   697,   697,   698,   699,
     699,   700,   701,   702,   702,   703,   704,   705,   706,   707,
     708,   708,   709,   710,   711,   712,   712,   713,   714,   714,
     715,   716,   717,   718,   718,   719,   720,   721,   722,   722,
     723,   723,   724,   725,   725,   726,   727,   728,   728,   729,
     730,   731,   731,   732,   733,   733,   734,   735,   736,   736,
     737,   737,   738,   739,   739,   740,   741,   742,   742,   743,
     744,   745,   746,   747,   748,   748,   749,   750,   751,   752,
     752,   753,   754,   754,   755,   756,   757,   757,   758,   759,
     760,   760,   761,   762,   763,   763,   764,   765,   766,   766,
     767,   767,   768,   769,   769,   770,   771,   772,   772,   773,
     774,   775,   776,   777,   778,   778,   779,   780,   781,   782,
     783,   784,   784,   785,   786,   787,   788,   788,   789,   790,
     791,   791,   792,   792,   793,   794,   794,   795,   796,   797,
     797,   798,   799,   800,   801,   802,   803,   803,   804,   805,
     806,   807,   808,   809,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     824,   825,   826,   827,   828,   829,   830,   831,   831,   832,
     833,   834,   835,   835,   836,   837,   838,   839,   839,   840,
     840,   840,   841,   842,   843,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   856,
     857,   858,   859,   859,   860,   861,   862,   862,   863,   864,
     865,   866,   866,   866,   866,   866,   866,   866,   866,   866,
     866,   866,   866,   866,   866,   866,   866,   866,   866,   866,
     866,   866,   866,   866,   866,   866,   866,   866,   868,   867,
     869,   869,   871,   870,   872,   872,   874,   873,   876,   875,
     878,   877,   880,   879,   882,   881,   884,   883,   886,   885,
     888,   887,   890,   889,   892,   891,   894,   893,   896,   895,
     898,   897,   900,   899,   902,   901,   904,   903,   906,   905,
     908,   907,   910,   909,   911,   911,   912,   912,   913,   913,
     913,   915,   914,   917,   916,   918,   920,   919,   921,   921,
     922,   921,   923,   923,   924,   924,   925,   926,   928,   927,
     929,   929,   931,   930,   932,   932,   934,   933,   935,   935,
     937,   936,   938,   938,   940,   939,   941,   941,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   943,   944,   945,   945,   567,   946,
     947,   948,   949,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   960,   961,   962,   963,   964,   964,
     965,   966,   967,   968,   969,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   983,   982,
     984,   984,   985,   986,   987,   988,   989,   990,   991,   992,
     993
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
       3,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     0,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     4,     1,
       1,     3,     1,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     4,     4,     1,     1,     1,     3,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     3,     0,     4,     1,     5,     0,     2,     5,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     2,     0,     3,     1,     2,     0,     5,     0,     5,
       0,     5,     0,     4,     0,     5,     0,     5,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     6,     0,     4,     0,     4,
       0,     4,     0,     4,     1,     2,     0,     2,     1,     1,
       1,     0,     4,     0,     4,     4,     0,     4,     1,     2,
       0,     4,     0,     2,     1,     1,     4,     4,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     2,     4,     2,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       2,     4,     1,     0,     1,     2,     4,     1,     0,     1,
       2,     3,     2,     1,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     1,     3,     0,     4,
       0,     2,     2,     1,     3,     2,     1,     6,     2,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   762,     0,    11,     1,   764,    27,     0,
       0,     0,    29,    37,     0,     0,   766,     0,     9,    14,
      12,    17,    39,   150,     0,     0,     0,    30,     0,     0,
       0,     0,   152,   266,     0,     0,     0,    40,     0,    33,
      35,    28,    31,    32,     0,   763,   769,   767,     0,    10,
      15,     0,     0,     0,     0,     0,    13,    18,    19,    20,
      21,    22,   268,     0,     0,   155,   157,   151,   153,   154,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   387,     4,     3,     7,   271,
     343,   267,   269,   270,   159,   185,     0,     0,     0,   355,
      34,   427,    36,   429,   765,     0,     0,     0,     0,     0,
       0,     0,     6,     2,     5,   272,   276,     0,     0,     0,
       0,   187,   221,     0,     0,     0,   160,   356,    44,    55,
      65,    75,    88,   102,   113,   132,    46,    47,    57,    48,
      67,    49,    77,    50,    90,    51,   104,    52,   115,    53,
     134,     0,   428,     0,   816,   808,   810,   814,   818,   820,
     868,   884,   828,   812,   834,   822,   824,   826,   856,   830,
     832,   876,   872,   880,   798,   802,   806,   842,   836,   838,
     840,     0,   792,   793,   773,   774,   776,   777,   778,   779,
     781,   782,   783,   785,   784,   786,   788,   789,   787,   795,
     796,   797,   771,   772,   775,   794,   790,   791,   780,    26,
      23,    24,    25,   387,   387,   389,   390,   391,   392,   388,
     273,     0,   280,   274,   347,   223,   254,     0,     0,     0,
     188,     0,   163,   166,   158,   161,   162,     0,    56,     0,
      66,     0,    76,     0,    89,     0,   103,     0,   114,     0,
     133,   441,   444,   426,   439,   440,     0,     0,     0,     0,
       0,   430,   431,   434,   435,   433,   432,   770,     0,     0,
       0,     0,     0,     0,   870,   886,     0,     0,     0,     0,
       0,     0,   862,     0,     0,   878,   874,   882,     0,     0,
       0,   846,     0,     0,     0,   768,   384,   385,     0,   280,
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
     800,     0,   799,   804,     0,   803,     0,     0,   910,   913,
     922,   927,   933,   937,   940,   943,   946,   948,   953,   956,
     959,   905,   916,   919,     0,   888,     0,   889,     0,   890,
       0,   903,     0,   891,     0,   892,   923,   893,   928,   894,
       0,   895,     0,   896,     0,   897,     0,   898,     0,   899,
     900,     0,   901,     0,   902,     0,     0,     0,     0,   275,
     279,   282,   345,     0,     0,     0,   344,   348,   349,   350,
     156,     0,     0,   257,     0,   227,   230,   222,   225,   226,
       0,     0,   359,   165,   169,   164,   167,   171,    63,     0,
       0,     0,    73,    86,   387,     0,     0,   100,     0,     0,
     111,     0,   122,     0,     0,   141,     0,     0,   442,   443,
       0,   447,   437,   438,   436,     0,     0,     0,     0,     0,
       0,   819,   821,   869,   871,   885,   887,   829,   813,     0,
     823,   825,   827,   858,     0,     0,     0,   857,   863,   864,
     865,   831,   833,   877,   879,   873,   875,   881,   883,   801,
     805,     0,   844,     0,     0,     0,     0,   843,   847,   848,
     850,   849,   950,   837,     0,     0,     0,     0,   909,     0,
     912,     0,   915,     0,   918,     0,     0,   924,     0,   929,
     934,     0,   932,     0,   936,     0,   939,     0,   942,     0,
     945,     0,   952,     0,   955,     0,   958,   839,   841,     0,
       0,     0,   346,   387,   387,     0,   260,   262,   255,   258,
     259,     0,     0,   360,   193,   197,   192,   195,   199,     0,
     170,   364,     0,     0,     0,     0,     0,     0,     0,   371,
     130,   120,   387,     0,   123,   149,   139,     0,   142,   712,
     480,   709,   475,   476,     0,   477,     0,   478,     0,   473,
       0,   445,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   466,   467,   468,   458,   750,   752,   817,   809,   811,
     815,     0,   859,   860,     0,   387,   807,   845,   851,   387,
     853,     0,     0,     0,   906,     0,   904,   911,     0,   917,
     920,     0,     0,     0,   935,     0,   941,     0,     0,     0,
       0,   960,   277,     0,   284,   287,   281,     0,     0,     0,
       0,   361,   229,   233,   228,   231,   235,     0,   198,   183,
       0,   168,     0,     0,     0,     0,     0,     0,     0,   172,
     181,   177,   178,   179,   180,   175,   182,   176,   174,   173,
     358,   357,   366,   367,   368,   369,   370,     0,     0,   126,
     395,   121,   124,   125,   145,   395,   140,   143,   144,   483,
     486,   479,   481,   482,     0,     0,     0,   713,   472,     0,
       0,     0,     0,     0,     0,     0,   387,   387,   835,     0,
       0,     0,     0,     0,     0,   949,   951,     0,     0,   907,
     914,   931,     0,   921,     0,   926,   938,   944,   947,   954,
       0,   283,   289,     0,   306,   352,   353,   363,   261,     0,
     263,     0,   234,   212,   216,   196,   210,   211,     0,     0,
       0,     0,     0,   200,   209,   207,   208,   206,   205,   203,
     204,   202,   201,   184,     0,     0,     0,     0,     0,     0,
       0,   387,   386,     0,     0,   128,   393,   394,     0,   147,
     488,   518,   490,     0,     0,     0,   711,     0,     0,     0,
       0,     0,     0,     0,     0,   470,   861,   867,   866,   852,
     855,   854,   908,   372,   925,   930,     0,     0,   285,   308,
     325,     0,     0,   250,   216,   232,   248,   249,     0,   236,
     247,   245,   246,   241,   242,   243,   244,   239,   240,   238,
     237,     0,   214,     0,     0,     0,     0,     0,   380,     0,
       0,     0,     0,     0,     0,   354,     0,     0,   129,   127,
     398,   396,   400,   148,   146,   520,   550,   522,     0,   489,
     710,   708,     0,   717,     0,     0,   459,   460,   461,   462,
     463,   464,   465,   471,     0,   297,   301,     0,     0,   290,
     291,   292,   288,   295,     0,   327,   286,     0,     0,   252,
       0,     0,   215,   213,     0,   217,     0,     0,     0,     0,
       0,   365,   373,   375,   376,   377,   379,   381,     0,   409,
       0,   405,   406,   407,     0,   399,   552,   604,   554,     0,
     521,     0,     0,   760,     0,   491,   492,   493,   758,   759,
     749,   725,   732,     0,     0,     0,   718,   957,   298,   301,
     299,     0,     0,     0,   316,   320,     0,     0,   309,   310,
     311,   307,   314,     0,     0,     0,   253,   251,     0,   219,
       0,   362,   382,   378,   374,     0,     0,   408,     0,   397,
       0,     0,   401,   403,   402,   606,   676,   608,     0,   553,
       0,   523,   524,   525,   498,   487,   495,     0,     0,     0,
       0,     0,   726,     0,   721,   395,   716,   719,   720,   296,
     300,     0,     0,     0,   317,   320,   318,     0,     0,     0,
     334,   338,     0,     0,   328,   329,   326,   332,   330,   265,
     264,   383,   220,   218,   755,   410,     0,     0,     0,   678,
     644,   680,     0,   607,     0,   555,   556,   557,   530,   519,
     527,     0,   505,     0,     0,     0,   501,   395,   497,   499,
     500,     0,   761,   735,   715,   714,   733,   737,   729,   395,
     724,   727,   728,     0,   723,     0,     0,     0,   293,   294,
     315,   319,     0,     0,     0,   335,   338,   336,     0,     0,
       0,   404,     0,     0,   646,     0,   648,     0,   679,     0,
     609,   610,   611,   562,   551,   559,     0,   537,     0,     0,
       0,   533,   395,   529,   531,   532,   494,   512,   496,     0,
     508,   395,   504,   506,   507,   503,     0,   753,     0,   736,
     731,     0,   751,   722,     0,   304,     0,   302,     0,     0,
     312,   313,   333,   337,     0,     0,     0,   756,   757,   485,
     484,     0,   647,     0,   681,   682,   683,   616,   605,   613,
       0,   569,     0,   575,     0,   565,   395,   561,   563,   564,
     526,   544,   528,     0,   540,   395,   536,   538,   539,   535,
       0,   515,   413,   511,   513,   514,   510,     0,   502,   746,
     444,   734,   744,   745,   387,   387,   741,   738,   739,   740,
     730,     0,   305,     0,   323,     0,   321,     0,     0,   331,
     351,     0,   649,   650,   651,   688,   677,   685,     0,   623,
       0,   629,     0,   619,   395,   615,   617,   618,   558,   577,
     560,     0,   572,   395,   568,   570,   571,   567,     0,   547,
     395,   543,   545,   546,   542,     0,   534,     0,   517,   411,
     412,     0,   509,   474,     0,     0,     0,   303,     0,   324,
       0,   341,     0,   339,   656,   645,   653,     0,   695,     0,
       0,     0,   691,   395,   687,   689,   690,   612,   631,   614,
       0,   626,   395,   622,   624,   625,   621,     0,   580,   583,
     576,   578,   579,   574,     0,   566,   549,     0,   541,     0,
     416,   414,   417,   516,   748,   747,   387,   387,   322,     0,
     342,   663,     0,     0,     0,   659,   395,   655,   657,   658,
     684,   702,   686,     0,   698,   395,   694,   696,   697,   693,
       0,   634,   636,   630,   632,   633,   628,     0,   620,     0,
     582,   573,   548,   424,     0,   420,   421,   422,     0,   418,
     742,   743,   340,   652,   670,   654,     0,   666,   395,   662,
     664,   665,   661,     0,   705,   395,   701,   703,   704,   700,
       0,   692,     0,   627,   581,   586,   584,   588,     0,   423,
     387,   415,   673,   395,   669,   671,   672,   668,     0,   660,
     707,     0,   699,   639,   635,   637,     0,     0,   587,   425,
       0,   675,     0,   667,   706,   642,     0,   638,   640,   641,
     595,   597,   585,   593,   594,     0,     0,   589,   591,   590,
     419,   674,     0,     0,   387,     0,   643,   596,   600,   598,
     601,     0,     0,     0,     0,   592,   754,   387,     0,   599,
       0,     0,   602,   603
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
     364,   362,   147,   148,   247,   248,   371,   370,   513,   514,
     643,   771,   772,   773,   864,   939,   641,   149,   150,   249,
     250,   377,   376,   516,   517,   647,   776,   777,   778,   868,
     944,   646,    33,    34,    67,    68,    69,    95,    96,   125,
     234,   235,   236,   495,   316,   496,   497,   629,   630,   749,
     741,   122,   123,   229,   312,   313,   314,   626,   491,   627,
     628,   737,   738,   843,   835,   836,   837,   921,   983,   922,
     985,   986,  1113,   226,   227,   307,   487,   488,   489,   734,
     622,   735,   736,   831,   832,   909,   905,   906,   907,   980,
    1047,   304,   305,   482,   618,   619,   620,   730,   830,   902,
      63,    64,    91,    92,    93,   117,   118,   222,   299,   300,
     301,   611,   726,   823,   824,   897,   969,   970,   971,   972,
     973,  1029,  1030,  1031,  1157,  1217,   900,   974,  1038,  1039,
    1040,  1041,  1042,  1095,  1096,  1097,  1219,  1286,   976,  1043,
    1104,  1105,  1106,  1107,  1166,  1167,  1168,  1288,  1343,   119,
     120,   476,   302,   477,  1108,   478,   479,   644,    27,    37,
     324,   325,   126,   230,   308,   844,   483,   326,   846,   344,
     345,   346,   358,   359,   368,   576,   751,   847,   752,   753,
     754,   848,   755,   756,   757,   850,   918,   110,   767,   111,
     219,   865,   866,   941,   942,  1004,  1005,  1062,  1059,   867,
    1001,  1002,  1003,  1328,  1329,  1381,  1382,  1428,  1461,  1330,
    1425,  1426,  1427,   102,   103,   151,   152,   261,   262,   263,
     264,   253,   254,   255,   382,   383,   384,   520,   521,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   661,   519,   652,   653,   654,   781,   782,   783,
    1230,   871,   872,   948,   949,  1015,  1075,  1133,  1076,  1077,
    1138,  1139,  1140,  1206,  1134,  1135,  1202,  1203,  1204,  1267,
    1198,  1199,  1263,  1264,  1265,  1331,   946,   947,  1009,  1010,
    1071,  1129,  1188,  1130,  1131,  1193,  1194,  1195,  1260,  1189,
    1190,  1256,  1257,  1258,  1325,  1252,  1253,  1321,  1322,  1323,
    1377,  1007,  1008,  1068,  1069,  1125,  1184,  1242,  1185,  1186,
    1247,  1248,  1249,  1318,  1243,  1244,  1314,  1315,  1316,  1374,
    1310,  1311,  1370,  1371,  1372,  1419,  1420,  1456,  1457,  1477,
    1478,  1497,  1498,  1492,  1493,  1494,  1503,  1509,  1510,  1514,
    1519,  1066,  1067,  1122,  1123,  1180,  1238,  1300,  1239,  1240,
    1305,  1306,  1307,  1367,  1301,  1302,  1363,  1364,  1365,  1417,
    1359,  1360,  1413,  1414,  1415,  1452,  1475,  1476,  1487,  1488,
    1489,  1175,  1176,  1231,  1232,  1292,  1345,  1392,  1346,  1347,
    1397,  1398,  1399,  1443,  1393,  1394,  1439,  1440,  1441,  1468,
    1435,  1436,  1464,  1465,  1466,  1482,  1120,  1121,  1177,  1178,
    1234,  1296,  1349,  1297,  1298,  1354,  1355,  1356,  1410,  1350,
    1351,  1406,  1407,  1408,  1450,  1402,  1403,  1446,  1447,  1448,
    1471,   655,   656,   951,   657,   658,   786,   876,  1145,   954,
     955,  1025,  1086,  1087,  1088,  1155,  1022,  1023,  1081,  1150,
    1151,  1152,  1211,  1080,  1146,  1147,  1208,  1209,  1277,  1278,
    1279,  1271,  1272,  1273,  1334,   787,   265,  1026,   266,  1016,
    1499,   937,  1063,  1064,  1017,  1018,  1019,     8,     9,    16,
      29,    47,    48,    80,   181,   182,   288,   412,   183,   289,
     415,   184,   290,   185,   269,   186,   270,   187,   277,   188,
     271,   189,   268,   190,   272,   191,   273,   192,   279,   193,
     280,   194,   281,   195,   276,   196,   283,   197,   284,   198,
     278,   199,   292,   200,   293,   201,   294,   202,   291,   567,
     417,   568,   569,   802,   570,   804,   571,   203,   282,   547,
     799,   404,   548,   549,   550,   204,   274,   396,   205,   286,
     408,   206,   285,   407,   207,   287,   409,   208,   275,   397,
     434,   435,   436,   706,   437,   438,   578,   439,   440,   580,
     441,   442,   582,   443,   444,   584,   445,   446,   586,   813,
     447,   448,   588,   815,   587,   449,   450,   592,   451,   452,
     594,   453,   454,   596,   455,   456,   598,   457,   458,   600,
     459,   572,   701,   460,   461,   602,   462,   463,   604,   464,
     465,   606
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -990
static const yytype_int16 yypact[] =
{
      53,    66,    97,   -98,   146,  -990,  -990,  -990,   125,   -77,
     153,    56,  -990,   130,   135,   175,  -990,   177,  -990,  -990,
    -990,  -990,  -990,   116,   160,   193,    55,  -990,   204,  -138,
     195,    27,  -990,   134,    93,   227,   109,  -990,   234,  -990,
    -990,  -990,  -990,  -990,   244,  -990,  -990,  -990,   231,  -990,
    -990,   246,   269,   275,   305,   318,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   117,   165,  -990,   236,  -990,  -990,  -990,
     316,  -990,  -990,  -990,  -990,  -990,   322,     3,   325,   350,
     333,  -990,   348,   356,   393,  -990,  -990,  -990,   424,  -990,
      80,  -990,  -990,  -990,  -990,   372,   354,   440,   218,  -990,
    -990,  -990,  -990,  -990,  -990,   438,   641,   444,   445,   446,
     447,    28,  -990,  -990,  -990,  -990,  -990,   345,   343,   349,
     326,  -990,   378,   383,   455,   188,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   194,    20,   457,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   225,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   458,  -990,  -990,  -990,  -990,   376,   385,   461,   199,
    -990,   460,  -990,  -990,  -990,  -990,  -990,   205,    41,   222,
      41,   224,    46,   259,    31,   300,    43,   454,    41,   459,
      41,  -990,   297,  -990,  -990,  -990,   465,   467,   468,   470,
     471,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   641,   641,
     641,   641,   641,   641,  -990,  -990,   641,   641,   641,   641,
     641,   641,  -990,   641,   641,  -990,  -990,  -990,   302,   304,
     641,  -990,   -19,   -19,   -19,  -990,  -242,  -242,   469,   367,
    -990,   368,    60,  -990,   412,   389,   477,   306,  -990,   475,
    -990,  -990,  -990,  -990,  -990,   478,    29,  -990,   448,  -990,
     479,   482,   483,  -990,  -990,  -990,  -990,  -990,   449,  -990,
    -990,  -990,  -990,  -990,  -990,   451,  -990,   485,   486,   487,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   450,  -990,
     492,   494,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   453,  -990,   496,  -990,  -990,  -990,  -990,  -990,   441,
    -990,  -990,  -990,  -990,  -990,   463,  -990,  -990,  -990,  -990,
    -990,  -990,   334,  -990,  -990,   498,   499,   501,   503,   505,
     641,   641,   641,   641,   258,   257,   273,   474,   253,   261,
     641,   255,   251,   263,    33,   265,   267,   493,   530,   569,
    -990,   247,  -990,  -990,   249,  -990,   641,    38,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   245,  -990,    50,  -990,   -19,  -990,
     -19,  -990,   641,  -990,   -19,  -990,   211,  -990,   211,  -990,
     309,  -990,   -19,  -990,   -19,  -990,   -19,  -990,   -19,  -990,
    -990,   641,  -990,   641,  -990,   -19,   271,   276,   537,  -990,
    -990,   521,  -990,   415,   541,   545,  -990,  -990,  -990,  -990,
    -990,   547,   317,  -990,   551,  -990,  -990,  -990,  -990,  -990,
     559,    69,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   561,
     562,   563,  -990,  -990,  -990,   564,   566,  -990,   567,   568,
    -990,   565,  -990,   506,   410,  -990,   526,   410,  -990,   -79,
     319,   179,  -990,  -990,  -990,   574,   575,   340,   342,   337,
     336,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   641,
    -990,  -990,  -990,  -990,   610,   579,   581,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   303,  -990,   307,   583,   582,   584,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   586,   588,   321,   301,  -990,   -19,
    -990,   272,  -990,   274,  -990,   591,   585,  -990,   587,  -990,
    -990,   298,  -990,   -19,  -990,   295,  -990,   -19,  -990,   -19,
    -990,   -19,  -990,   641,  -990,   284,  -990,  -990,  -990,   595,
     598,   323,  -990,  -990,  -990,   600,  -990,  -990,  -990,  -990,
    -990,   605,    70,  -990,  -990,  -990,  -990,  -990,  -990,   328,
     124,  -990,   606,   607,   608,   609,   612,   614,   615,  -990,
    -990,  -990,  -990,   330,  -990,  -990,  -990,   332,  -990,  -990,
    -990,  -990,  -990,  -990,   339,  -990,   602,  -990,   439,  -990,
     452,  -990,   616,   620,   621,   622,   623,   624,   625,   626,
    -990,   627,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   374,  -990,  -990,   628,  -990,  -990,  -990,  -990,  -990,
    -990,   -54,   629,   630,  -990,   311,  -990,  -990,   344,  -990,
    -990,   631,   -19,   -19,  -990,   329,  -990,   331,   335,   327,
     641,  -990,  -990,   638,  -990,   528,  -990,   640,   642,   643,
      71,  -990,  -990,  -990,  -990,  -990,  -990,   341,    54,  -990,
     576,  -990,   646,   644,   648,   649,   650,   652,   653,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   651,    17,  -990,
     500,  -990,  -990,  -990,  -990,   500,  -990,  -990,  -990,  -990,
     462,  -990,  -990,  -990,   -19,   656,   654,  -990,  -990,   655,
     657,   659,   660,   661,   662,   663,  -990,  -990,  -990,   404,
     669,   670,   671,   672,   673,  -990,  -990,   674,   675,  -990,
    -990,  -990,   366,  -990,   381,  -990,  -990,  -990,  -990,  -990,
     641,  -990,  -990,   571,   570,  -990,  -990,  -990,  -990,   664,
    -990,   351,    18,  -990,  -990,  -990,  -990,  -990,   676,   680,
     681,   683,   684,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   686,   685,   687,   688,   689,   691,
     692,  -990,  -990,   522,   635,  -990,   527,  -990,   645,  -990,
    -990,   497,  -990,   481,   693,   484,  -990,   698,   699,   703,
     704,   706,   710,   714,   716,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,   -19,    44,  -990,  -990,
     613,   718,   712,  -990,  -990,  -990,  -990,  -990,   722,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   707,   702,   782,   784,   786,   788,   794,  -990,   796,
     798,   800,   819,   821,   823,  -990,   825,   365,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,   632,  -990,   827,  -144,
    -990,  -990,   829,  -990,   604,   678,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   525,  -990,   719,   841,   858,  -990,
    -990,  -990,  -990,  -990,    47,  -990,  -990,   856,   641,   702,
     790,   860,  -990,  -990,   854,  -990,   -19,   866,   868,   872,
     899,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   897,  -990,
      26,  -990,  -990,  -990,   895,   214,  -990,   696,  -990,   901,
    -144,   720,   907,  -990,   910,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   678,   913,   369,  -990,  -990,  -990,   801,
    -990,   802,   915,   917,  -990,   810,   927,   929,  -990,  -990,
    -990,  -990,  -990,    62,   930,   843,  -990,  -990,   932,  -990,
     850,  -990,  -990,  -990,  -990,   934,   776,  -990,   933,  -990,
     936,   938,  -990,  -990,  -990,  -990,   726,  -990,   935,  -144,
     743,  -990,  -990,  -990,  -990,  -990,   740,   371,   940,   942,
     -96,   373,  -990,   941,  -990,   500,  -990,  -990,  -990,  -990,
    -990,   931,   947,   948,  -990,   834,  -990,   828,   946,   949,
    -990,   836,   954,   955,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,   792,   953,   956,  -990,
     747,  -990,   951,  -144,   764,  -990,  -990,  -990,  -990,  -990,
     761,   375,  -990,   767,   762,   377,  -990,   500,  -990,  -990,
    -990,   964,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   500,
    -990,  -990,  -990,   966,  -990,   745,   968,   380,  -990,  -990,
    -990,  -990,   957,   969,   971,  -990,   857,  -990,   849,   972,
     973,  -990,   975,   978,  -990,   785,  -990,   974,  -144,   783,
    -990,  -990,  -990,  -990,  -990,   780,   382,  -990,   777,   781,
     384,  -990,   500,  -990,  -990,  -990,  -990,  -990,  -990,   386,
    -990,   500,  -990,  -990,  -990,  -990,   787,  -990,   388,  -121,
    -990,   763,  -990,  -990,   982,  -990,   867,  -990,   988,   392,
    -990,  -990,  -990,  -990,   976,   990,   992,  -990,  -990,  -990,
    -990,   985,  -144,   797,  -990,  -990,  -990,  -990,  -990,   795,
     394,  -990,   789,   799,   396,  -990,   500,  -990,  -990,  -990,
    -990,  -990,  -990,   398,  -990,   500,  -990,  -990,  -990,  -990,
     803,  -990,   837,  -990,  -990,  -990,  -990,   804,  -990,  -990,
     297,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   998,  -990,   995,  -990,   876,  -990,  1003,   400,  -990,
    -990,   807,  -990,  -990,  -990,  -990,  -990,   806,   402,  -990,
     805,   808,   405,  -990,   500,  -990,  -990,  -990,  -990,  -990,
    -990,   407,  -990,   500,  -990,  -990,  -990,  -990,   811,  -990,
     500,  -990,  -990,  -990,  -990,   814,  -990,   522,  -990,   842,
    -990,   809,  -990,  -990,   838,  1006,  1008,  -990,  1017,  -990,
    1014,  -990,   893,  -990,  -990,  -990,   820,   409,  -990,   812,
     817,   411,  -990,   500,  -990,  -990,  -990,  -990,  -990,  -990,
     413,  -990,   500,  -990,  -990,  -990,  -990,   824,  -990,  -990,
    -990,  -990,  -990,  -990,   822,  -990,  -990,   826,  -990,   417,
    -990,  -990,   862,  -990,   -79,  -990,  -990,  -990,  -990,  1025,
    -990,  -990,   816,   830,   419,  -990,   500,  -990,  -990,  -990,
    -990,  -990,  -990,   421,  -990,   500,  -990,  -990,  -990,  -990,
     831,  -990,  -990,  -990,  -990,  -990,  -990,   832,  -990,   833,
     869,  -990,  -990,  -990,    45,  -990,  -990,  -990,  1023,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,   423,  -990,   500,  -990,
    -990,  -990,  -990,   840,  -990,   500,  -990,  -990,  -990,  -990,
     839,  -990,  -107,  -990,  -990,  -990,  -990,  -990,   877,  -990,
    -990,  -990,  -990,   500,  -990,  -990,  -990,  -990,   844,  -990,
    -990,   835,  -990,  -990,  -990,  -990,   429,   431,  -111,  -990,
     871,  -990,   845,  -990,  -990,  -990,   641,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  1040,  1042,  -990,  -990,  -990,
    -990,  -990,   879,  -104,  -990,  1041,  -990,  -990,  -990,  -990,
     723,  1044,  1048,  1050,  1043,  -990,  -990,  -990,  1049,  -990,
    1052,   848,  -990,  -990
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   154,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   758,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,    30,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   -35,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -105,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   546,  -990,  -990,
      40,    52,  -990,  -990,  -990,   230,  -990,  -216,   232,   846,
     847,  -990,  -990,  -990,  -990,  -990,   233,  -990,   238,   239,
     240,  -990,  -685,  -990,  -990,  -990,  -990,  -487,  -783,  -207,
    -990,  -748,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -143,  -990,
    -990,  -990,  -990,  -990,  -990,  -197,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -259,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -605,    57,  -601,  -989,
    -990,  -252,  -990,  -306,  -987,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -268,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -275,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   633,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     390,   391,   392,   393,   394,   395,   296,   297,   398,   399,
     400,   401,   402,   403,   885,   405,   406,   634,   466,   467,
     862,  1072,   416,  1073,   333,   758,   343,   869,   355,   759,
     367,  1056,   374,   100,   380,   213,   214,    50,    51,   320,
    1012,   256,   257,   543,   544,    52,    53,    54,   562,   563,
    1458,   545,   320,   849,   965,   966,   258,  1034,  1035,  1473,
     564,   565,   320,  1507,   320,    39,    40,   320,   574,  1495,
     472,   473,  1100,  1101,  1496,   320,  1143,     1,   935,  1144,
    1126,    18,  1127,    19,  1013,  1014,   215,   216,   217,   218,
     337,   338,     4,   350,   351,   649,    45,     6,    46,   493,
    1474,   494,   838,    65,    66,   337,   338,   339,   363,  1274,
    1275,   743,   744,   745,   746,   747,  1508,   650,   908,    71,
      72,   842,   527,   528,   529,   530,   727,   728,   534,   536,
      86,    87,   539,   851,  1181,     7,  1182,   852,   838,   554,
     556,   558,   575,   651,   624,   320,   625,   917,   561,    10,
     732,   747,   733,   839,    12,   840,   841,   842,    15,   828,
      17,   829,    22,   577,   967,   579,    25,   968,  1036,   583,
    1037,   101,   474,   475,   581,    89,    90,   593,    28,   595,
      30,   597,    32,   599,  1102,  1103,   115,   116,  1057,  1235,
     605,  1236,   742,   601,    35,   603,    38,   258,   232,   233,
     259,   260,   259,   260,   251,   252,    49,  1459,   801,   310,
     311,    44,   803,   321,   322,   317,   318,   743,   744,   745,
     746,   747,   748,   321,   322,   321,   322,   919,   321,   322,
      70,   920,   327,   328,   334,   335,   259,   260,   418,    62,
     419,    76,   420,  1293,   421,  1294,   422,    78,   423,    79,
     424,   128,   425,   129,   426,   130,   427,   805,   428,   131,
     429,   132,   430,   133,   431,   134,   432,   135,   433,   347,
     348,   691,    82,   418,    81,   419,   693,   420,    83,   421,
     331,   422,   341,   423,   353,   424,   365,   425,   372,   426,
     378,   427,   332,   428,   342,   429,   354,   430,   366,   431,
     373,   432,   379,   433,   708,    94,   259,   260,    84,   884,
     360,   361,   410,   411,   413,   414,   485,   486,   715,   590,
     591,    85,   717,    97,   718,    99,   719,   616,   617,   659,
     660,   704,   705,   724,   725,   720,   104,  1154,   739,   740,
     769,   770,   774,   775,   106,   215,   216,   217,   218,   779,
     780,   833,   834,   105,    55,   107,   215,   216,   217,   218,
     546,   903,   904,   108,   566,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   999,  1000,  1060,  1061,  1084,
    1085,  1136,  1137,  1148,  1149,  1191,  1192,  1200,  1201,  1205,
    1215,  1216,  1245,  1246,  1254,  1255,  1261,  1262,  1269,  1270,
     109,  1210,  1284,  1285,  1303,  1304,  1312,  1313,  1319,  1320,
    1341,  1342,  1352,  1353,   750,  1361,  1362,  1368,  1369,  1395,
    1396,  1404,  1405,  1411,  1412,   124,   806,  1423,  1424,  1437,
    1438,  1444,  1445,  1462,  1463,   768,   112,   812,   814,  1485,
    1486,  1490,  1491,   127,  1259,   153,   121,   209,   210,   211,
     212,   220,   820,  1266,   221,   223,   224,   225,   231,   228,
     267,   298,   295,   303,   309,   369,   306,   315,   381,   385,
     375,   386,   387,   388,   389,   469,   468,   471,   481,   480,
     484,   492,   490,   499,   498,   500,   501,   502,   504,   505,
     506,  1335,  1336,   503,   507,   508,   512,   509,  1317,   510,
     511,   522,   523,   518,   524,   531,   532,  1324,   537,   873,
     525,   154,   526,   155,   541,   156,   540,   157,   538,   158,
     515,   159,   845,   160,   533,   161,   559,   162,   542,   163,
     560,   164,   573,   165,   551,   166,   585,   167,   552,   168,
     609,   169,   610,   170,   613,   171,   612,   172,   614,   173,
     615,   174,   896,   175,   640,   176,  1366,   177,   621,   178,
     607,   179,   623,   180,   631,  1373,   642,   608,   639,   632,
     633,   635,  1376,   636,   637,   638,   645,   685,   686,   687,
     689,   690,   694,   688,   695,   699,   696,   698,   700,   702,
     768,   703,   697,   709,   707,   711,   712,   710,   713,   714,
     716,   721,   723,  1430,  1431,  1409,   722,   729,   731,   760,
     761,   762,   763,   784,  1416,   764,   911,   765,   766,   789,
     785,   964,   788,   790,   791,   792,   793,   794,   795,   796,
     809,   797,   816,   798,   811,   800,   807,   808,   817,   810,
     819,   821,   822,   825,   818,   826,   827,   855,  1442,   853,
     854,   856,   857,   858,   768,   859,   860,  1449,   861,   874,
     870,   863,   877,   894,   878,   875,   879,   880,   881,   882,
     883,   886,   887,   888,   889,   890,   891,   892,   893,   923,
     895,   898,   901,   924,   925,   899,   926,   936,   927,   928,
    1467,   938,   929,   940,   930,   931,   932,  1470,   933,   934,
     952,   956,   957,   943,   950,   945,   958,   959,   953,   960,
    1045,  1050,   154,   961,   155,  1481,   156,   962,   157,   963,
     158,   977,   159,   978,   160,   981,   161,   535,   162,   975,
     163,   154,   164,   155,   165,   156,   166,   157,   167,   158,
     168,   159,   169,   160,   170,   161,   171,   162,   172,   163,
     173,   164,   174,   165,   175,   166,   176,   167,   177,   168,
     178,   169,   179,   170,   180,   171,   553,   172,   154,   173,
     155,   174,   156,   175,   157,   176,   158,   177,   159,   178,
     160,   179,   161,   180,   162,   982,   163,   984,   164,   987,
     165,   988,   166,   989,   167,   990,   168,   991,   169,   992,
     170,   993,   171,   994,   172,   555,   173,   154,   174,   155,
     175,   156,   176,   157,   177,   158,   178,   159,   179,   160,
     180,   161,   995,   162,   996,   163,   997,   164,   998,   165,
    1021,   166,  1020,   167,  1024,   168,  1028,   169,  1011,   170,
    1027,   171,  1006,   172,  1032,   173,   557,   174,   154,   175,
     155,   176,   156,   177,   157,   178,   158,   179,   159,   180,
     160,  1033,   161,  1044,   162,  1049,   163,  1048,   164,  1051,
     165,  1052,   166,  1046,   167,  1053,   168,   692,   169,   154,
     170,   155,   171,   156,   172,   157,   173,   158,   174,   159,
     175,   160,   176,   161,   177,   162,   178,   163,   179,   164,
     180,   165,  1054,   166,  1055,   167,  1058,   168,  1065,   169,
    1078,   170,  1070,   171,  1079,   172,  1083,   173,  1089,   174,
    1074,   175,  1092,   176,  1093,   177,  1091,   178,  1094,   179,
    1098,   180,  1099,  1109,  1110,  1111,  1112,  1114,  1115,  1117,
    1116,  1118,  1119,  1128,  1132,  1142,  1124,  1141,  1153,  1156,
    1158,  1159,  1160,  1163,  1162,  1165,  1164,  1169,  1170,  1171,
    1172,  1174,  1179,  1173,  1183,  1187,  1196,  1207,  1197,  1212,
    1213,  1214,  1220,  1480,  1221,  1218,  1222,  1224,  1227,  1225,
    1226,  1228,  1229,  1237,  1241,  1233,  1250,  1251,  1268,  1281,
    1280,  1283,  1282,  1289,  1287,  1290,  1291,  1295,  1327,  1299,
    1308,  1337,  1338,  1339,  1326,  1309,  1340,  1344,  1380,  1332,
    1348,  1385,  1375,  1386,  1358,  1387,  1383,  1511,  1357,  1378,
    1388,  1389,  1390,  1401,  1391,  1418,  1061,  1421,  1432,  1400,
    1520,  1433,  1451,  1422,  1460,  1455,  1434,  1453,  1500,  1479,
    1454,  1469,  1484,  1504,  1472,  1505,  1506,  1515,  1512,  1483,
    1513,  1516,  1501,  1517,  1518,  1522,  1521,   470,   979,  1090,
    1161,  1223,   910,   648,   912,   913,  1276,   768,   768,  1523,
     914,   915,   916,  1333,  1384,  1379,  1429,     0,     0,     0,
    1082,   589,     0,     0,     0,     0,     0,     0,     0,     0,
     356,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   768,
     768,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1502
};

static const yytype_int16 yycheck[] =
{
     268,   269,   270,   271,   272,   273,   213,   214,   276,   277,
     278,   279,   280,   281,   797,   283,   284,   504,   293,   294,
       3,  1010,   290,  1010,   240,   630,   242,   775,   244,   630,
     246,     5,   248,    30,   250,     7,     8,    10,    11,    21,
     184,    21,    22,    10,    11,    18,    19,    20,    10,    11,
       5,    18,    21,   738,    10,    11,   177,    10,    11,   166,
      22,    23,    21,   167,    21,    10,    11,    21,    18,   180,
      10,    11,    10,    11,   185,    21,   172,    24,   861,   175,
    1069,    25,  1069,    27,   228,   229,   328,   329,   330,   331,
      59,    60,    26,    62,    63,   174,   234,     0,   236,    70,
     207,    72,    84,    10,    11,    59,    60,    61,    65,   230,
     231,    93,    94,    95,    96,    97,   220,   196,   100,    10,
      11,   103,   390,   391,   392,   393,   613,   614,   396,   397,
      13,    14,   400,   738,  1123,   233,  1123,   738,    84,   407,
     408,   409,    92,   222,    75,    21,    77,   832,   416,     3,
      80,    97,    82,    99,    29,   101,   102,   103,   235,    88,
       7,    90,    32,   438,   120,   440,    31,   123,   121,   444,
     123,   168,   112,   113,   442,    10,    11,   452,     3,   454,
       3,   456,    66,   458,   122,   123,   106,   107,   162,  1178,
     465,  1178,    68,   461,    34,   463,     3,   177,    10,    11,
     182,   183,   182,   183,    10,    11,    11,   162,   695,    10,
      11,     7,   699,   182,   183,    10,    11,    93,    94,    95,
      96,    97,    98,   182,   183,   182,   183,   832,   182,   183,
       3,   832,    10,    11,    10,    11,   182,   183,   292,   105,
     294,     7,   296,  1232,   298,  1232,   300,     3,   302,    18,
     304,    33,   306,    35,   308,    37,   310,   311,   312,    41,
     314,    43,   316,    45,   318,    47,   320,    49,   322,    10,
      11,   539,     3,   292,    28,   294,   544,   296,     3,   298,
     240,   300,   242,   302,   244,   304,   246,   306,   248,   308,
     250,   310,   240,   312,   242,   314,   244,   316,   246,   318,
     248,   320,   250,   322,   579,    69,   182,   183,     3,   796,
      10,    11,    10,    11,    10,    11,    10,    11,   593,    10,
      11,     3,   597,     7,   599,     3,   601,    10,    11,    10,
      11,    10,    11,    10,    11,   603,    11,  1085,    10,    11,
      10,    11,    10,    11,    11,   328,   329,   330,   331,    10,
      11,    10,    11,     3,   327,     7,   328,   329,   330,   331,
     327,    10,    11,     7,   326,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,    10,    11,   163,   164,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,  1137,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       7,  1149,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   630,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    71,   701,    10,    11,    10,
      11,    10,    11,    10,    11,   642,    12,   712,   713,    10,
      11,    10,    11,     3,  1192,     7,    74,     3,     3,     3,
       3,   106,   720,  1201,   111,   106,   130,    79,     3,    76,
       3,     3,   237,    87,     3,    11,    81,     7,   171,     4,
      11,     4,     4,     3,     3,   108,     7,   109,    89,    67,
       3,     3,     7,     4,    36,     3,     3,    38,     3,     3,
       3,  1274,  1275,    42,    44,     3,    55,     3,  1246,    46,
       4,     3,     3,   169,     3,   247,   249,  1255,   255,   784,
       7,   238,     7,   240,   263,   242,   261,   244,   257,   246,
      57,   248,   738,   250,   251,   252,   279,   254,   265,   256,
     281,   258,   287,   260,   269,   262,   325,   264,   271,   266,
       3,   268,    21,   270,     3,   272,   131,   274,     3,   276,
       3,   278,   820,   280,    48,   282,  1304,   284,     7,   286,
     289,   288,     3,   290,     3,  1313,   156,   291,     3,     7,
       7,     7,  1320,     7,     7,     7,    50,     3,     3,   239,
     243,   245,     3,   241,     3,     3,   283,     4,     4,     3,
     797,     3,   285,   321,   293,     4,    11,   323,    11,   301,
     305,   317,     4,  1386,  1387,  1353,    11,     7,     3,     3,
       3,     3,     3,    11,  1362,     3,   832,     3,     3,     3,
     181,   896,   170,     3,     3,     3,     3,     3,     3,     3,
     319,     4,   303,   259,     3,     7,     7,     7,   307,   295,
     313,     3,   114,     3,   309,     3,     3,     3,  1396,    73,
       4,     3,     3,     3,   861,     3,     3,  1405,     7,     3,
     198,   161,     7,   297,     7,    11,     7,     7,     7,     7,
       7,   267,     3,     3,     3,     3,     3,     3,     3,     3,
     299,   110,    18,     3,     3,   115,     3,   165,     4,     3,
    1438,    56,     7,   166,     7,     7,     7,  1445,     7,     7,
       7,     3,     3,    58,   223,   208,     3,     3,   224,     3,
     978,   986,   238,     3,   240,  1463,   242,     3,   244,     3,
     246,     3,   248,    11,   250,     3,   252,   253,   254,   116,
     256,   238,   258,   240,   260,   242,   262,   244,   264,   246,
     266,   248,   268,   250,   270,   252,   272,   254,   274,   256,
     276,   258,   278,   260,   280,   262,   282,   264,   284,   266,
     286,   268,   288,   270,   290,   272,   273,   274,   238,   276,
     240,   278,   242,   280,   244,   282,   246,   284,   248,   286,
     250,   288,   252,   290,   254,    78,   256,    85,   258,     7,
     260,     7,   262,     7,   264,     7,   266,     3,   268,     3,
     270,     3,   272,     3,   274,   275,   276,   238,   278,   240,
     280,   242,   282,   244,   284,   246,   286,   248,   288,   250,
     290,   252,     3,   254,     3,   256,     3,   258,     3,   260,
     226,   262,     3,   264,   156,   266,   117,   268,    11,   270,
     315,   272,   210,   274,     3,   276,   277,   278,   238,   280,
     240,   282,   242,   284,   244,   286,   246,   288,   248,   290,
     250,     3,   252,     7,   254,    11,   256,     7,   258,     3,
     260,     3,   262,    83,   264,     3,   266,   267,   268,   238,
     270,   240,   272,   242,   274,   244,   276,   246,   278,   248,
     280,   250,   282,   252,   284,   254,   286,   256,   288,   258,
     290,   260,     3,   262,     7,   264,    11,   266,   212,   268,
       3,   270,    11,   272,     4,   274,     3,   276,   117,   278,
     200,   280,     7,   282,     7,   284,   124,   286,   118,   288,
       3,   290,     3,     3,    91,     3,    86,     3,   162,     3,
       7,     3,   216,   200,   204,     3,    11,     7,     7,    18,
       3,     3,   118,     7,   126,   119,     7,     3,     3,   167,
       7,   214,    11,     7,   200,   204,   199,     3,   206,     3,
     225,     3,     3,  1460,     3,    18,   119,   128,     3,     7,
       7,     3,   197,   200,   204,    11,   209,   206,   201,     7,
     227,     3,   125,     3,    18,     3,    11,   200,   161,   204,
     211,     3,     7,   127,   201,   206,     3,   200,   166,   205,
     204,   173,   201,     7,   206,     7,   207,  1504,   213,   205,
       3,     7,   129,   206,   204,   201,   164,   205,     3,   217,
    1517,   215,   201,   207,    11,   166,   206,   205,   167,   162,
     207,   201,   207,     3,   205,     3,   167,     3,     7,   205,
     327,     3,   207,     3,    11,     3,     7,   299,   904,  1029,
    1095,  1166,   832,   517,   832,   832,  1209,  1274,  1275,   221,
     832,   832,   832,  1270,  1333,  1327,  1382,    -1,    -1,    -1,
    1023,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1386,
    1387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1486
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   333,   337,    26,   338,     0,   233,   859,   860,
       3,   339,    29,   349,   350,   235,   861,     7,    25,    27,
     340,   341,    32,   356,   357,    31,   351,   550,     3,   862,
       3,   343,    66,   424,   425,    34,   358,   551,     3,    10,
      11,   352,   353,   354,     7,   234,   236,   863,   864,    11,
      10,    11,    18,    19,    20,   327,   342,   344,   345,   346,
     347,   348,   105,   492,   493,    10,    11,   426,   427,   428,
       3,    10,    11,   359,   360,   361,     7,   355,     3,    18,
     865,    28,     3,     3,     3,     3,    13,    14,   334,    10,
      11,   494,   495,   496,    69,   429,   430,     7,   362,     3,
      30,   168,   605,   606,    11,     3,    11,     7,     7,     7,
     579,   581,    12,   335,   336,   106,   107,   497,   498,   541,
     542,    74,   443,   444,    71,   431,   554,     3,    33,    35,
      37,    41,    43,    45,    47,    49,   363,   364,   365,   370,
     371,   376,   377,   382,   383,   388,   389,   394,   395,   409,
     410,   607,   608,     7,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   272,   274,   276,   278,   280,   282,   284,   286,   288,
     290,   866,   867,   870,   873,   875,   877,   879,   881,   883,
     885,   887,   889,   891,   893,   895,   897,   899,   901,   903,
     905,   907,   909,   919,   927,   930,   933,   936,   939,     3,
       3,     3,     3,     7,     8,   328,   329,   330,   331,   582,
     106,   111,   499,   106,   130,    79,   465,   466,    76,   445,
     555,     3,    10,    11,   432,   433,   434,   366,   367,   372,
     373,   378,   379,   384,   385,   390,   391,   396,   397,   411,
     412,    10,    11,   613,   614,   615,    21,    22,   177,   182,
     183,   609,   610,   611,   612,   848,   850,     3,   884,   876,
     878,   882,   886,   888,   928,   940,   896,   880,   902,   890,
     892,   894,   920,   898,   900,   934,   931,   937,   868,   871,
     874,   910,   904,   906,   908,   237,   581,   581,     3,   500,
     501,   502,   544,    87,   483,   484,    81,   467,   556,     3,
      10,    11,   446,   447,   448,     7,   436,    10,    11,   369,
      21,   182,   183,   368,   552,   553,   559,    10,    11,   375,
     374,   552,   553,   559,    10,    11,   381,    59,    60,    61,
     380,   552,   553,   559,   561,   562,   563,    10,    11,   387,
      62,    63,   386,   552,   553,   559,   561,   562,   564,   565,
      10,    11,   393,    65,   392,   552,   553,   559,   566,    11,
     399,   398,   552,   553,   559,    11,   414,   413,   552,   553,
     559,   171,   616,   617,   618,     4,     4,     4,     3,     3,
     866,   866,   866,   866,   866,   866,   929,   941,   866,   866,
     866,   866,   866,   866,   923,   866,   866,   935,   932,   938,
      10,    11,   869,    10,    11,   872,   866,   912,   292,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   322,   942,   943,   944,   946,   947,   949,
     950,   952,   953,   955,   956,   958,   959,   962,   963,   967,
     968,   970,   971,   973,   974,   976,   977,   979,   980,   982,
     985,   986,   988,   989,   991,   992,   942,   942,     7,   108,
     501,   109,    10,    11,   112,   113,   543,   545,   547,   548,
      67,    89,   485,   558,     3,    10,    11,   468,   469,   470,
       7,   450,     3,    70,    72,   435,   437,   438,    36,     4,
       3,     3,    38,    42,     3,     3,     3,    44,     3,     3,
      46,     4,    55,   400,   401,    57,   415,   416,   169,   635,
     619,   620,     3,     3,     3,     7,     7,   866,   866,   866,
     866,   247,   249,   251,   866,   253,   866,   255,   257,   866,
     261,   263,   265,    10,    11,    18,   327,   921,   924,   925,
     926,   269,   271,   273,   866,   275,   866,   277,   866,   279,
     281,   866,    10,    11,    22,    23,   326,   911,   913,   914,
     916,   918,   983,   287,    18,    92,   567,   942,   948,   942,
     951,   866,   954,   942,   957,   325,   960,   966,   964,   966,
      10,    11,   969,   942,   972,   942,   975,   942,   978,   942,
     981,   866,   987,   866,   990,   942,   993,   289,   291,     3,
      21,   503,   131,     3,     3,     3,    10,    11,   486,   487,
     488,     7,   472,     3,    75,    77,   449,   451,   452,   439,
     440,     3,     7,     7,   579,     7,     7,     7,     7,     3,
      48,   408,   156,   402,   549,    50,   423,   417,   549,   174,
     196,   222,   636,   637,   638,   813,   814,   816,   817,    10,
      11,   634,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,     3,     3,   239,   241,   243,
     245,   866,   267,   866,     3,     3,   283,   285,     4,     3,
       4,   984,     3,     3,    10,    11,   945,   293,   942,   321,
     323,     4,    11,    11,   301,   942,   305,   942,   942,   942,
     866,   317,    11,     4,    10,    11,   504,   579,   579,     7,
     489,     3,    80,    82,   471,   473,   474,   453,   454,    10,
      11,   442,    68,    93,    94,    95,    96,    97,    98,   441,
     559,   568,   570,   571,   572,   574,   575,   576,   848,   850,
       3,     3,     3,     3,     3,     3,     3,   580,   581,    10,
      11,   403,   404,   405,    10,    11,   418,   419,   420,    10,
      11,   639,   640,   641,    11,   181,   818,   847,   170,     3,
       3,     3,     3,     3,     3,     3,     3,     4,   259,   922,
       7,   579,   915,   579,   917,   311,   942,     7,     7,   319,
     295,     3,   942,   961,   942,   965,   303,   307,   309,   313,
     866,     3,   114,   505,   506,     3,     3,     3,    88,    90,
     490,   475,   476,    10,    11,   456,   457,   458,    84,    99,
     101,   102,   103,   455,   557,   559,   560,   569,   573,   574,
     577,   848,   850,    73,     4,     3,     3,     3,     3,     3,
       3,     7,     3,   161,   406,   583,   584,   591,   421,   583,
     198,   643,   644,   942,     3,    11,   819,     7,     7,     7,
       7,     7,     7,     7,   579,   580,   267,     3,     3,     3,
       3,     3,     3,     3,   297,   299,   866,   507,   110,   115,
     518,    18,   491,    10,    11,   478,   479,   480,   100,   477,
     557,   559,   560,   568,   570,   571,   572,   574,   578,   848,
     850,   459,   461,     3,     3,     3,     3,     4,     3,     7,
       7,     7,     7,     7,     7,   580,   165,   853,    56,   407,
     166,   585,   586,    58,   422,   208,   668,   669,   645,   646,
     223,   815,     7,   224,   821,   822,     3,     3,     3,     3,
       3,     3,     3,     3,   942,    10,    11,   120,   123,   508,
     509,   510,   511,   512,   519,   116,   530,     3,    11,   461,
     481,     3,    78,   460,    85,   462,   463,     7,     7,     7,
       7,     3,     3,     3,     3,     3,     3,     3,     3,    10,
      11,   592,   593,   594,   587,   588,   210,   693,   694,   670,
     671,    11,   184,   228,   229,   647,   851,   856,   857,   858,
       3,   226,   828,   829,   156,   823,   849,   315,   117,   513,
     514,   515,     3,     3,    10,    11,   121,   123,   520,   521,
     522,   523,   524,   531,     7,   866,    83,   482,     7,    11,
     942,     3,     3,     3,     3,     7,     5,   162,    11,   590,
     163,   164,   589,   854,   855,   212,   733,   734,   695,   696,
      11,   672,   851,   856,   200,   648,   650,   651,     3,     4,
     835,   830,   849,     3,    10,    11,   824,   825,   826,   117,
     514,   124,     7,     7,   118,   525,   526,   527,     3,     3,
      10,    11,   122,   123,   532,   533,   534,   535,   546,     3,
      91,     3,    86,   464,     3,   162,     7,     3,     3,   216,
     788,   789,   735,   736,    11,   697,   851,   856,   200,   673,
     675,   676,   204,   649,   656,   657,    10,    11,   652,   653,
     654,     7,     3,   172,   175,   820,   836,   837,    10,    11,
     831,   832,   833,     7,   583,   827,    18,   516,     3,     3,
     118,   526,   126,     7,     7,   119,   536,   537,   538,     3,
       3,   167,     7,     7,   214,   763,   764,   790,   791,    11,
     737,   851,   856,   200,   698,   700,   701,   204,   674,   681,
     682,    10,    11,   677,   678,   679,   199,   206,   662,   663,
      10,    11,   658,   659,   660,   583,   655,     3,   838,   839,
     583,   834,     3,   225,     3,    10,    11,   517,    18,   528,
       3,     3,   119,   537,   128,     7,     7,     3,     3,   197,
     642,   765,   766,    11,   792,   851,   856,   200,   738,   740,
     741,   204,   699,   706,   707,    10,    11,   702,   703,   704,
     209,   206,   687,   688,    10,    11,   683,   684,   685,   583,
     680,    10,    11,   664,   665,   666,   583,   661,   201,    10,
      11,   843,   844,   845,   230,   231,   610,   840,   841,   842,
     227,     7,   125,     3,    10,    11,   529,    18,   539,     3,
       3,    11,   767,   851,   856,   200,   793,   795,   796,   204,
     739,   746,   747,    10,    11,   742,   743,   744,   211,   206,
     712,   713,    10,    11,   708,   709,   710,   583,   705,    10,
      11,   689,   690,   691,   583,   686,   201,   161,   595,   596,
     601,   667,   205,   617,   846,   580,   580,     3,     7,   127,
       3,    10,    11,   540,   200,   768,   770,   771,   204,   794,
     801,   802,    10,    11,   797,   798,   799,   213,   206,   752,
     753,    10,    11,   748,   749,   750,   583,   745,    10,    11,
     714,   715,   716,   583,   711,   201,   583,   692,   205,   853,
     166,   597,   598,   207,   635,   173,     7,     7,     3,     7,
     129,   204,   769,   776,   777,    10,    11,   772,   773,   774,
     217,   206,   807,   808,    10,    11,   803,   804,   805,   583,
     800,    10,    11,   754,   755,   756,   583,   751,   201,   717,
     718,   205,   207,    10,    11,   602,   603,   604,   599,   855,
     580,   580,     3,   215,   206,   782,   783,    10,    11,   778,
     779,   780,   583,   775,    10,    11,   809,   810,   811,   583,
     806,   201,   757,   205,   207,   166,   719,   720,     5,   162,
      11,   600,    10,    11,   784,   785,   786,   583,   781,   201,
     583,   812,   205,   166,   207,   758,   759,   721,   722,   162,
     579,   583,   787,   205,   207,    10,    11,   760,   761,   762,
      10,    11,   725,   726,   727,   180,   185,   723,   724,   852,
     167,   207,   866,   728,     3,     3,   167,   167,   220,   729,
     730,   579,     7,   327,   731,     3,     3,     3,    11,   732,
     579,     7,     3,   221
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
//    osinstance->instanceData->matrices = new Matrices();
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
//        for (int i=0; i < osglData->numberOfMatrices; i++)
//            osinstance->instanceData->matrices->matrix[i] = new OSMatrix();
    }
}
    break;

  case 34:

    {
std::cout << "Finished matrices section" << std::endl;
}
    break;

  case 44:

    {
    std::cout << "finished cones section" << std::endl;
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
          osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
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
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 365:

    {
    if (parserData->shapePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "shape attribute previously set");
    parserData->shapePresent = true;
    parserData->shape = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
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
    free((yyvsp[(2) - (3)].sval));
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
    free((yyvsp[(2) - (3)].sval));

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
std::cout << "XML representation:" << std::endl;
    std::cout << osinstance->instanceData->matrices->matrix[osglData->matrixCounter]->getMatrixNodeInXML();
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
std::cout << "push back a constructor - OSMatrix" << std::endl;
std::cout << "push back a mtxBlkVec" << std::endl;
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
    free((yyvsp[(2) - (3)].sval));
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
    free((yyvsp[(2) - (3)].sval));
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
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 442:

    {
//    ((MatrixConstructor*)osglData->mtxBlkVec.back())->m_mChildren = 
//        new MatrixConstructor*[((MatrixConstructor*)osglData->mtxBlkVec.back())->inumberOfChildren];
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
std::cout << "pop back mtxBlkVec" << std::endl;
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
std::cout << "push back a constructor - BaseMatrix" << std::endl;

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
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTransposeAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
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
std::cout << "push back a constructor - MatrixElements" << std::endl;
}
    break;

  case 488:

    {
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
std::cout << "start vector has length " << osglData->osglNumberOfEl << std::endl;  
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 504:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->numberOfEl
        = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->rowMajorAttribute = false;
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->rowMajorAttribute = false;
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
//    osglData->osglDblArray = new double[osglData->osglNumberOfEl]; //valgrind: this leaks 40 bytes of memory
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxAttributePresent = false;
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
    osglData->numberOfVarIdxAttributePresent = false;
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
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx]; //valgrind: this creates error in OSGeneral.cpp:1950
    osglData->osglCounter = 0;
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
        = new LinearMatrixElementTerm(); //valgrind: this leaks 32 bytes of memory
std::cout << "create term " << osglData->osglCounter << " in linear elements nonzero " << osglData->osglNonzeroCounter << std::endl;
}
    break;

  case 602:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 603:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 606:

    {
    ((MatrixElements*)osglData->tempC)->generalElements = new GeneralMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> terms greater than expected");
std::cout << "expected " << osglData->osglNumberOfNonzeros << " general elements; got " << osglData->osglNonzeroCounter << std::endl; 
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
    osglData->rowMajorAttribute = false;
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
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
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

  case 662:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 663:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 669:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 670:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 678:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements = new ObjReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 679:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 682:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 683:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 687:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 688:

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

  case 694:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 695:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "indexes vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 701:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 702:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
std::cout << "values vector has length " << osglData->osglNumberOfEl << std::endl;  
}
    break;

  case 708:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 709:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
std::cout << "push back a constructor - MatrixTransformation" << std::endl;
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

  case 710:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 711:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;
    osglData->colOffsets.back() = NULL;
std::cout << "pop back rowOffsets" << std::endl;
    osglData->rowOffsets.pop_back();
std::cout << "pop back colOffsets" << std::endl;
    osglData->colOffsets.pop_back();
}
    break;

  case 712:

    {
    osglData->tempC = new MatrixBlocks();
std::cout << "push back a constructor - MatrixBlocks" << std::endl;
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfBlocksAttributePresent = false;
}
    break;

  case 713:

    {
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks    = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->m_mChildren       = new MatrixNode*[osglData->numberOfBlocks];
//std::cout << "pop back mtxBlkVec" << std::endl;
//    osglData->mtxBlkVec.pop_back();
}
    break;

  case 714:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 715:

    {
//    delete [] osglData->matrixBlockNumberOfRows;
//    delete [] osglData->matrixBlockNumberOfCols;
//    osglData->matrixBlockNumberOfRows = NULL;
//    osglData->matrixBlockNumberOfCols = NULL;
}
    break;

  case 716:

    {
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffsets->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
std::cout << "push back a colOffsets vector" << std::endl;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 717:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 718:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
//    osglData->matrixBlockNumberOfCols = new int[osglData->osglNumberOfEl]; //valgrind: this leaks 48 bytes of memory
}
    break;

  case 724:

    {
//    if (!parserData->ignoreDataAfterErrors)
//        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
//            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "set <blocks> rowOffsets failed");    
//    delete[] osglData->osglIntArray;
//    osglData->osglIntArray = NULL;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
std::cout << "push back a rowOffsets vector" << std::endl;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 725:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 726:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
//    osglData->matrixBlockNumberOfRows = new int[osglData->osglNumberOfEl]; //valgrind: this leaks 48 bytes of memory
}
    break;

  case 734:

    {
std::cout << "pop back mtxBlkVec" << std::endl;
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 735:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);
std::cout << "push back a constructor - MatrixBlock" << std::endl;
std::cout << "push back a mtxBlkVec" << std::endl;

    osglData->symmetryAttributePresent = false;
    osglData->blockRowIdxAttributePresent = false;
    osglData->blockColIdxAttributePresent = false;   
}
    break;

  case 741:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 742:

    {
    if (osglData->blockRowIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxAttributePresent = true;        
        osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);       
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1] 
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}
    break;

  case 743:

    {
    if (osglData->blockColIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxAttributePresent = true;
        osglData->blockColIdx = (yyvsp[(3) - (4)].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}
    break;

  case 747:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 749:

    {
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 750:

    {
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 751:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 752:

    {
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 753:

    {
    if (osglData->numberOfValuesAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesAttributePresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 754:

    {
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 755:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 756:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 757:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 760:

    {
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajorAttribute = true;
    osglData->rowMajorAttributePresent = true;
}
    break;

  case 761:

    { 
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajorAttribute = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajorAttribute = true;
        else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorAttributePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 763:

    {  
        if (osnlData->nlnodecount < osnlData->tmpnlcount)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 764:

    {               
//    osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
}
    break;

  case 765:

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

  case 768:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->nlnodecount++;
    }
    break;

  case 769:

    {
        if (osnlData->nlnodecount >= osnlData->tmpnlcount) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
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

  case 770:

    { 
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        //osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
    }
    break;

  case 798:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 802:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 806:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 808:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 810:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 812:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 814:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 816:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 818:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 820:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 822:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 824:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 826:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 828:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 830:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 831:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 832:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 833:

    {
}
    break;

  case 834:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 835:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 836:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 838:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 840:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 842:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 843:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 851:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 853:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 855:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 856:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 857:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 860:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 864:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 865:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 866:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 867:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 868:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 869:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 871:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 872:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 873:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 875:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 876:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 877:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 879:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 880:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 881:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 883:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 884:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 885:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 887:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 904:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 905:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 908:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices){
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
     }
}
    break;

  case 910:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 913:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 916:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 919:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 922:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 927:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 931:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 933:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 937:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 940:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 943:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 946:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 948:

    {
//    osnlData->nlNodePoint = new OSnLNodeProduct();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
//    osnlData->mtxProdVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 949:

    {
//    osnlData->mtxProdVec.back()->m_mChildren = new OSnLNode*[ osnlData->mtxProdVec.back()->inumberOfMatrixChildren];
//    osnlData->mtxProdVec.pop_back();
}
    break;

  case 951:

    { /*osnlData->mtxProdVec.back()->inumberOfMatrixChildren++; */}
    break;

  case 953:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 956:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 959:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
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


