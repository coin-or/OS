
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
#define YYLAST   1214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  332
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  661
/* YYNRULES -- Number of rules.  */
#define YYNRULES  959
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1520

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
     919,   924,   929,   934,   938,   942,   947,   952,   957,   962,
     967,   971,   976,   981,   986,   991,   996,  1001,  1006,  1011,
    1015,  1020,  1025,  1030,  1034,  1038,  1041,  1042,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1058,  1061,  1065,  1067,  1069,
    1070,  1073,  1075,  1077,  1081,  1085,  1087,  1089,  1092,  1094,
    1098,  1100,  1102,  1103,  1106,  1110,  1112,  1113,  1115,  1119,
    1123,  1125,  1127,  1130,  1132,  1136,  1140,  1142,  1144,  1145,
    1148,  1150,  1152,  1154,  1156,  1158,  1162,  1166,  1170,  1172,
    1174,  1176,  1180,  1183,  1184,  1188,  1190,  1192,  1193,  1196,
    1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,  1219,
    1224,  1229,  1234,  1239,  1244,  1249,  1251,  1253,  1255,  1257,
    1261,  1266,  1269,  1271,  1272,  1275,  1277,  1279,  1281,  1284,
    1286,  1288,  1290,  1292,  1301,  1303,  1304,  1309,  1311,  1313,
    1314,  1317,  1319,  1321,  1325,  1326,  1329,  1332,  1334,  1336,
    1338,  1340,  1344,  1346,  1349,  1351,  1353,  1355,  1357,  1361,
    1363,  1366,  1368,  1370,  1372,  1374,  1378,  1380,  1381,  1386,
    1388,  1390,  1391,  1394,  1396,  1398,  1402,  1403,  1406,  1409,
    1411,  1413,  1415,  1417,  1421,  1423,  1426,  1428,  1430,  1432,
    1434,  1438,  1440,  1443,  1445,  1447,  1449,  1451,  1455,  1457,
    1458,  1463,  1465,  1467,  1468,  1471,  1473,  1475,  1479,  1480,
    1483,  1486,  1488,  1490,  1492,  1494,  1498,  1500,  1503,  1505,
    1507,  1509,  1511,  1515,  1517,  1518,  1521,  1523,  1525,  1527,
    1529,  1533,  1535,  1536,  1539,  1543,  1545,  1547,  1548,  1551,
    1553,  1555,  1560,  1562,  1564,  1566,  1570,  1571,  1574,  1578,
    1580,  1581,  1586,  1590,  1591,  1596,  1598,  1600,  1601,  1604,
    1606,  1608,  1612,  1613,  1616,  1619,  1621,  1623,  1625,  1627,
    1631,  1633,  1636,  1638,  1640,  1642,  1644,  1648,  1650,  1651,
    1654,  1656,  1658,  1660,  1662,  1666,  1667,  1670,  1673,  1675,
    1677,  1679,  1681,  1685,  1686,  1691,  1693,  1695,  1696,  1699,
    1701,  1703,  1707,  1708,  1711,  1714,  1716,  1718,  1720,  1722,
    1726,  1728,  1731,  1733,  1735,  1737,  1739,  1743,  1745,  1748,
    1750,  1752,  1754,  1756,  1760,  1762,  1763,  1768,  1770,  1772,
    1773,  1776,  1778,  1780,  1784,  1785,  1788,  1791,  1793,  1795,
    1797,  1799,  1803,  1805,  1808,  1810,  1812,  1814,  1816,  1820,
    1822,  1825,  1827,  1829,  1831,  1833,  1837,  1839,  1844,  1846,
    1848,  1852,  1854,  1856,  1862,  1864,  1868,  1870,  1872,  1874,
    1876,  1878,  1882,  1884,  1888,  1890,  1892,  1894,  1896,  1898,
    1902,  1904,  1905,  1908,  1912,  1914,  1916,  1917,  1920,  1922,
    1924,  1926,  1931,  1936,  1938,  1940,  1942,  1946,  1949,  1954,
    1959,  1964,  1969,  1974,  1979,  1984,  1989,  1994,  1996,  1998,
    2000,  2004,  2005,  2010,  2012,  2018,  2019,  2022,  2028,  2030,
    2035,  2037,  2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,
    2055,  2057,  2059,  2061,  2063,  2065,  2067,  2069,  2071,  2073,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2090,  2094,
    2096,  2099,  2100,  2104,  2106,  2109,  2110,  2116,  2117,  2123,
    2124,  2130,  2131,  2136,  2137,  2143,  2144,  2150,  2151,  2156,
    2157,  2162,  2163,  2168,  2169,  2174,  2175,  2180,  2181,  2186,
    2187,  2192,  2193,  2198,  2199,  2206,  2207,  2212,  2213,  2218,
    2219,  2224,  2225,  2230,  2232,  2235,  2236,  2239,  2241,  2243,
    2245,  2246,  2251,  2252,  2257,  2262,  2263,  2268,  2270,  2273,
    2274,  2279,  2280,  2283,  2285,  2287,  2292,  2297,  2298,  2303,
    2304,  2307,  2308,  2313,  2314,  2317,  2318,  2323,  2324,  2327,
    2328,  2333,  2334,  2337,  2338,  2343,  2344,  2347,  2349,  2351,
    2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,
    2373,  2375,  2377,  2379,  2383,  2385,  2387,  2390,  2395,  2398,
    2400,  2403,  2406,  2408,  2412,  2415,  2417,  2420,  2423,  2425,
    2428,  2433,  2435,  2436,  2438,  2441,  2446,  2448,  2449,  2451,
    2454,  2458,  2461,  2463,  2465,  2468,  2471,  2473,  2477,  2480,
    2482,  2485,  2488,  2490,  2494,  2497,  2499,  2503,  2504,  2509,
    2510,  2513,  2516,  2518,  2522,  2525,  2527,  2534,  2537,  2539
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     333,     0,    -1,   337,   858,   349,   356,   424,   492,   334,
     335,    -1,    14,    -1,    13,    -1,   336,    -1,    12,    -1,
      -1,    -1,    24,   338,   339,    25,    -1,    26,     3,     7,
       3,    11,    -1,    -1,   339,   340,    -1,   341,   343,   342,
      -1,    27,    -1,    10,    -1,    11,    28,    -1,    -1,   343,
     344,    -1,   345,    -1,   346,    -1,   347,    -1,   348,    -1,
      19,     3,     7,     3,    -1,    20,     3,     7,     3,    -1,
     327,     3,   578,     3,    -1,    18,     3,     7,     3,    -1,
      -1,   350,   351,   352,    -1,    29,    -1,   549,    -1,   353,
      -1,   354,    -1,    10,    -1,    11,   355,    30,    -1,    -1,
     355,   604,    -1,    -1,   357,   358,   359,    -1,    32,    -1,
     550,    -1,   360,    -1,   361,    -1,    10,    -1,    11,   362,
      33,    -1,    -1,   362,   363,    -1,   364,    -1,   370,    -1,
     376,    -1,   382,    -1,   388,    -1,   394,    -1,   409,    -1,
     365,   366,   369,    -1,    35,    -1,   367,    -1,    -1,   367,
     368,    -1,   551,    -1,   552,    -1,   558,    -1,    10,    -1,
      11,    36,    -1,   371,   372,   375,    -1,    37,    -1,   373,
      -1,    -1,   373,   374,    -1,   551,    -1,   552,    -1,   558,
      -1,    10,    -1,    11,    38,    -1,   377,   378,   381,    -1,
      41,    -1,   379,    -1,    -1,   379,   380,    -1,   551,    -1,
     552,    -1,   558,    -1,   561,    -1,   560,    -1,   562,    -1,
      10,    -1,    11,    42,    -1,   383,   384,   387,    -1,    43,
      -1,   385,    -1,    -1,   385,   386,    -1,   551,    -1,   552,
      -1,   558,    -1,   561,    -1,   560,    -1,   563,    -1,   564,
      -1,    10,    -1,    11,    44,    -1,   389,   390,   393,    -1,
      45,    -1,   391,    -1,    -1,   391,   392,    -1,   551,    -1,
     552,    -1,   558,    -1,   565,    -1,    10,    -1,    11,    46,
      -1,   395,   396,   399,    -1,    47,    -1,   397,    -1,    -1,
     397,   398,    -1,   551,    -1,   552,    -1,   558,    -1,    11,
     400,   408,    -1,   401,   402,   403,    -1,    55,    -1,   848,
      -1,   404,    -1,   405,    -1,    10,    -1,    11,   406,   407,
      -1,   582,    -1,    56,    -1,    48,    -1,   410,   411,   414,
      -1,    49,    -1,   412,    -1,    -1,   412,   413,    -1,   551,
      -1,   552,    -1,   558,    -1,    11,   415,   423,    -1,   416,
     417,   418,    -1,    57,    -1,   848,    -1,   419,    -1,   420,
      -1,    10,    -1,    11,   421,   422,    -1,   582,    -1,    58,
      -1,    50,    -1,    -1,   425,   426,    -1,    66,    -1,   427,
      -1,   428,    -1,    10,    -1,    11,   429,   443,   465,   483,
      67,    -1,    -1,   430,   431,   432,    -1,    69,    -1,   553,
      -1,   433,    -1,   434,    -1,    10,    -1,    11,   436,   435,
      -1,    70,    -1,    -1,   436,   437,    -1,   438,   439,   442,
      -1,    72,    -1,   440,    -1,    -1,   440,   441,    -1,   849,
      -1,   847,    -1,   573,    -1,   575,    -1,   567,    -1,   569,
      -1,   570,    -1,   571,    -1,   558,    -1,   574,    -1,    10,
      -1,    11,    73,    -1,    -1,   444,   445,   446,    -1,    74,
      -1,   554,    -1,   447,    -1,   448,    -1,    10,    -1,    11,
     450,   449,    -1,    75,    -1,    -1,   450,   451,    -1,   452,
     453,   456,    -1,    77,    -1,   454,    -1,    -1,   454,   455,
      -1,   849,    -1,   847,    -1,   573,    -1,   576,    -1,   572,
      -1,   568,    -1,   558,    -1,   559,    -1,   556,    -1,   457,
      -1,   458,    -1,    10,    -1,    11,   459,   460,    -1,   461,
      -1,    78,    -1,    -1,   461,   462,    -1,   463,   941,   464,
      -1,    85,    11,    -1,    86,    -1,    -1,   466,   467,   468,
      -1,    79,    -1,   555,    -1,   469,    -1,   470,    -1,    10,
      -1,    11,   472,   471,    -1,    80,    -1,    -1,   472,   473,
      -1,   474,   475,   478,    -1,    82,    -1,   476,    -1,    -1,
     476,   477,    -1,   849,    -1,   847,    -1,   573,    -1,   577,
      -1,   567,    -1,   569,    -1,   570,    -1,   571,    -1,   558,
      -1,   559,    -1,   556,    -1,   479,    -1,   480,    -1,    10,
      -1,    11,   481,   482,    -1,   461,    -1,    83,    -1,    -1,
     484,   485,   486,    -1,    87,    -1,   557,    -1,   487,    -1,
     488,    -1,    10,    -1,    11,   489,    88,    -1,    -1,   489,
     490,    -1,    90,   491,    11,   865,    91,    -1,    18,     3,
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
       3,   578,     3,    -1,   113,     3,   578,     3,    -1,    31,
       3,     7,     3,    -1,    34,     3,     7,     3,    -1,   183,
       3,     7,     3,    -1,   182,     3,     7,     3,    -1,    71,
       3,     7,     3,    -1,    76,     3,     7,     3,    -1,    81,
       3,     7,     3,    -1,    84,     3,     7,     3,    -1,    89,
       3,     7,     3,    -1,    21,     4,     3,    -1,   103,     4,
       3,    -1,    59,     3,   578,     3,    -1,    60,     3,     7,
       3,    -1,    61,     3,     7,     3,    -1,    62,     3,     7,
       3,    -1,    63,     3,     7,     3,    -1,    65,     4,     3,
      -1,    92,     3,     7,     3,    -1,    93,     3,     7,     3,
      -1,   102,     3,     7,     3,    -1,    94,     3,     7,     3,
      -1,    95,     3,     7,     3,    -1,    96,     3,     7,     3,
      -1,   101,     3,     7,     3,    -1,    97,     3,     7,     3,
      -1,    68,     4,     3,    -1,    98,     3,     7,     3,    -1,
      99,     3,     7,     3,    -1,   100,     3,     7,     3,    -1,
     580,     7,   580,    -1,   580,     8,   580,    -1,   580,     3,
      -1,    -1,   580,   581,    -1,   328,    -1,   329,    -1,   330,
      -1,   331,    -1,   583,    -1,   590,    -1,    -1,   583,   584,
      -1,   585,   586,   589,    -1,   166,    -1,   587,    -1,    -1,
     587,   588,    -1,   854,    -1,   853,    -1,    11,     7,   167,
      -1,   161,   852,   591,    -1,   592,    -1,   593,    -1,    11,
     162,    -1,    10,    -1,    11,     5,   162,    -1,   595,    -1,
     600,    -1,    -1,   595,   596,    -1,   597,   598,   599,    -1,
     166,    -1,    -1,   854,    -1,    11,   578,   167,    -1,   161,
     852,   601,    -1,   602,    -1,   603,    -1,    11,   162,    -1,
      10,    -1,    11,     5,   162,    -1,   605,   606,   612,    -1,
     168,    -1,   607,    -1,    -1,   607,   608,    -1,   609,    -1,
     849,    -1,   847,    -1,   610,    -1,   611,    -1,   177,     4,
       3,    -1,    21,     4,     3,    -1,    22,     4,     3,    -1,
     613,    -1,   614,    -1,    10,    -1,    11,   615,   169,    -1,
     616,   634,    -1,    -1,   617,   618,   633,    -1,   171,    -1,
     619,    -1,    -1,   619,   620,    -1,   621,    -1,   622,    -1,
     623,    -1,   624,    -1,   625,    -1,   626,    -1,   627,    -1,
     628,    -1,   632,    -1,   186,     3,     7,     3,    -1,   187,
       3,     7,     3,    -1,   188,     3,     7,     3,    -1,   189,
       3,     7,     3,    -1,   190,     3,     7,     3,    -1,   191,
       3,     7,     3,    -1,   192,     3,     7,     3,    -1,   629,
      -1,   630,    -1,   631,    -1,   194,    -1,   195,     4,   579,
      -1,   193,     3,   578,     3,    -1,    11,   170,    -1,    10,
      -1,    -1,   634,   635,    -1,   636,    -1,   812,    -1,   815,
      -1,   637,   638,    -1,   196,    -1,   639,    -1,   640,    -1,
      10,    -1,    11,   642,   667,   692,   732,   787,   762,   641,
      -1,   197,    -1,    -1,   643,   644,    11,   647,    -1,   198,
      -1,   645,    -1,    -1,   645,   646,    -1,   850,    -1,   855,
      -1,   649,   648,   199,    -1,    -1,   655,   661,    -1,   650,
     651,    -1,   200,    -1,   652,    -1,   653,    -1,    10,    -1,
      11,   654,   201,    -1,   582,    -1,   656,   657,    -1,   204,
      -1,   658,    -1,   659,    -1,    10,    -1,    11,   660,   205,
      -1,   582,    -1,   662,   663,    -1,   206,    -1,   664,    -1,
     665,    -1,    10,    -1,    11,   666,   207,    -1,   594,    -1,
      -1,   668,   669,    11,   672,    -1,   208,    -1,   670,    -1,
      -1,   670,   671,    -1,   850,    -1,   855,    -1,   674,   673,
     209,    -1,    -1,   680,   686,    -1,   675,   676,    -1,   200,
      -1,   677,    -1,   678,    -1,    10,    -1,    11,   679,   201,
      -1,   582,    -1,   681,   682,    -1,   204,    -1,   683,    -1,
     684,    -1,    10,    -1,    11,   685,   205,    -1,   582,    -1,
     687,   688,    -1,   206,    -1,   689,    -1,   690,    -1,    10,
      -1,    11,   691,   207,    -1,   582,    -1,    -1,   693,   694,
      11,   697,    -1,   210,    -1,   695,    -1,    -1,   695,   696,
      -1,   850,    -1,   855,    -1,   699,   698,   211,    -1,    -1,
     705,   711,    -1,   700,   701,    -1,   200,    -1,   702,    -1,
     703,    -1,    10,    -1,    11,   704,   201,    -1,   582,    -1,
     706,   707,    -1,   204,    -1,   708,    -1,   709,    -1,    10,
      -1,    11,   710,   205,    -1,   582,    -1,    -1,   712,   713,
      -1,   206,    -1,   714,    -1,   715,    -1,    10,    -1,    11,
     716,   207,    -1,   717,    -1,    -1,   717,   718,    -1,   719,
     720,   724,    -1,   166,    -1,   721,    -1,    -1,   721,   722,
      -1,   851,    -1,   723,    -1,   180,     3,   578,     3,    -1,
     725,    -1,   726,    -1,    10,    -1,    11,   727,   167,    -1,
      -1,   727,   728,    -1,   729,   730,   731,    -1,   220,    -1,
      -1,   327,     3,   578,     3,    -1,    11,     7,   221,    -1,
      -1,   733,   734,    11,   737,    -1,   212,    -1,   735,    -1,
      -1,   735,   736,    -1,   850,    -1,   855,    -1,   739,   738,
     213,    -1,    -1,   745,   751,    -1,   740,   741,    -1,   200,
      -1,   742,    -1,   743,    -1,    10,    -1,    11,   744,   201,
      -1,   582,    -1,   746,   747,    -1,   204,    -1,   748,    -1,
     749,    -1,    10,    -1,    11,   750,   205,    -1,   582,    -1,
      -1,   752,   753,    -1,   206,    -1,   754,    -1,   755,    -1,
      10,    -1,    11,   756,   207,    -1,    -1,   756,   757,    -1,
     758,   759,    -1,   166,    -1,   760,    -1,   761,    -1,    10,
      -1,    11,   865,   167,    -1,    -1,   763,   764,    11,   767,
      -1,   214,    -1,   765,    -1,    -1,   765,   766,    -1,   850,
      -1,   855,    -1,   769,   768,   215,    -1,    -1,   775,   781,
      -1,   770,   771,    -1,   200,    -1,   772,    -1,   773,    -1,
      10,    -1,    11,   774,   201,    -1,   582,    -1,   776,   777,
      -1,   204,    -1,   778,    -1,   779,    -1,    10,    -1,    11,
     780,   205,    -1,   582,    -1,   782,   783,    -1,   206,    -1,
     784,    -1,   785,    -1,    10,    -1,    11,   786,   207,    -1,
     582,    -1,    -1,   788,   789,    11,   792,    -1,   216,    -1,
     790,    -1,    -1,   790,   791,    -1,   850,    -1,   855,    -1,
     794,   793,   217,    -1,    -1,   800,   806,    -1,   795,   796,
      -1,   200,    -1,   797,    -1,   798,    -1,    10,    -1,    11,
     799,   201,    -1,   582,    -1,   801,   802,    -1,   204,    -1,
     803,    -1,   804,    -1,    10,    -1,    11,   805,   205,    -1,
     582,    -1,   807,   808,    -1,   206,    -1,   809,    -1,   810,
      -1,    10,    -1,    11,   811,   207,    -1,   582,    -1,   813,
      11,   941,   814,    -1,   222,    -1,   223,    -1,   816,   817,
     818,    -1,   174,    -1,   846,    -1,    11,   820,   827,   834,
     819,    -1,   175,    -1,   821,   822,   823,    -1,   224,    -1,
     848,    -1,   824,    -1,   825,    -1,    10,    -1,    11,   826,
     225,    -1,   582,    -1,   828,   829,   830,    -1,   226,    -1,
     848,    -1,   831,    -1,   832,    -1,    10,    -1,    11,   833,
     227,    -1,   582,    -1,    -1,   834,   835,    -1,   836,   837,
     842,    -1,   172,    -1,   838,    -1,    -1,   838,   839,    -1,
     840,    -1,   841,    -1,   609,    -1,   230,   579,     7,   579,
      -1,   231,   579,     7,   579,    -1,   843,    -1,   844,    -1,
      10,    -1,    11,   845,   173,    -1,   616,   634,    -1,   181,
       3,     7,     3,    -1,   182,     3,     7,     3,    -1,   156,
       3,     7,     3,    -1,   183,     3,     7,     3,    -1,   184,
       3,     7,     3,    -1,   185,     3,     7,     3,    -1,   165,
       3,     7,     3,    -1,   163,     3,     7,     3,    -1,   164,
       3,     7,     3,    -1,   856,    -1,   857,    -1,   228,    -1,
     229,     4,     3,    -1,    -1,   859,   860,   861,   234,    -1,
     233,    -1,   235,     3,     7,     3,    11,    -1,    -1,   861,
     862,    -1,   863,   864,    11,   865,   237,    -1,   236,    -1,
      18,     3,     7,     3,    -1,   908,    -1,   918,    -1,   872,
      -1,   874,    -1,   926,    -1,   876,    -1,   878,    -1,   880,
      -1,   882,    -1,   938,    -1,   884,    -1,   886,    -1,   888,
      -1,   892,    -1,   890,    -1,   894,    -1,   900,    -1,   896,
      -1,   898,    -1,   932,    -1,   935,    -1,   866,    -1,   869,
      -1,   929,    -1,   902,    -1,   904,    -1,   906,    -1,    -1,
     278,   867,   868,    -1,    10,    -1,    11,   279,    -1,    -1,
     280,   870,   871,    -1,    10,    -1,    11,   281,    -1,    -1,
     282,   873,   865,   865,   283,    -1,    -1,   240,   875,   865,
     865,   241,    -1,    -1,   242,   877,   865,   865,   243,    -1,
      -1,   256,   879,   865,   257,    -1,    -1,   244,   881,   865,
     865,   245,    -1,    -1,   238,   883,   865,   865,   239,    -1,
      -1,   246,   885,   865,   247,    -1,    -1,   248,   887,   865,
     249,    -1,    -1,   260,   889,   865,   261,    -1,    -1,   262,
     891,   865,   263,    -1,    -1,   264,   893,   865,   265,    -1,
      -1,   254,   895,   865,   255,    -1,    -1,   268,   897,   865,
     269,    -1,    -1,   270,   899,   865,   271,    -1,    -1,   258,
     901,   865,   865,   865,   259,    -1,    -1,   286,   903,   941,
     287,    -1,    -1,   288,   905,   941,   289,    -1,    -1,   290,
     907,   941,   291,    -1,    -1,   284,   909,   911,   910,    -1,
      10,    -1,    11,   285,    -1,    -1,   911,   912,    -1,   913,
      -1,   917,    -1,   915,    -1,    -1,    22,     4,   914,     3,
      -1,    -1,   326,     4,   916,     3,    -1,    23,     3,   578,
       3,    -1,    -1,   266,   919,   922,   920,    -1,    10,    -1,
      11,   267,    -1,    -1,    11,   865,   921,   267,    -1,    -1,
     922,   923,    -1,   924,    -1,   925,    -1,   327,     3,   578,
       3,    -1,    18,     3,     7,     3,    -1,    -1,   250,   927,
     928,   251,    -1,    -1,   928,   865,    -1,    -1,   274,   930,
     931,   275,    -1,    -1,   931,   865,    -1,    -1,   272,   933,
     934,   273,    -1,    -1,   934,   865,    -1,    -1,   276,   936,
     937,   277,    -1,    -1,   937,   865,    -1,    -1,   252,   939,
     940,   253,    -1,    -1,   940,   865,    -1,   942,    -1,   945,
      -1,   948,    -1,   954,    -1,   957,    -1,   961,    -1,   966,
      -1,   969,    -1,   972,    -1,   975,    -1,   978,    -1,   981,
      -1,   984,    -1,   987,    -1,   990,    -1,   951,    -1,   943,
     566,   944,    -1,   318,    -1,    10,    -1,    11,   319,    -1,
      18,     3,     7,     3,    -1,   946,   947,    -1,   292,    -1,
     941,   293,    -1,   949,   950,    -1,   294,    -1,   941,   941,
     295,    -1,   952,   953,    -1,   320,    -1,   865,   321,    -1,
     955,   956,    -1,   322,    -1,   941,   323,    -1,   958,   959,
      11,   960,    -1,   296,    -1,    -1,   965,    -1,   941,   297,
      -1,   962,   963,    11,   964,    -1,   298,    -1,    -1,   965,
      -1,   941,   299,    -1,   325,     4,     3,    -1,   967,   968,
      -1,   300,    -1,    10,    -1,    11,   301,    -1,   970,   971,
      -1,   302,    -1,   941,   941,   303,    -1,   973,   974,    -1,
     304,    -1,   941,   305,    -1,   976,   977,    -1,   306,    -1,
     941,   941,   307,    -1,   979,   980,    -1,   308,    -1,   941,
     941,   309,    -1,    -1,   310,   982,   983,   311,    -1,    -1,
     983,   941,    -1,   985,   986,    -1,   312,    -1,   865,   941,
     313,    -1,   988,   989,    -1,   314,    -1,   865,   865,   865,
     865,   941,   315,    -1,   991,   992,    -1,   316,    -1,   941,
     317,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   386,   386,   389,   390,   392,   401,   402,   405,   406,
     411,   418,   418,   420,   433,   439,   440,   443,   444,   447,
     450,   453,   456,   462,   469,   476,   484,   489,   489,   497,
     499,   507,   507,   509,   511,   518,   518,   521,   521,   527,
     532,   540,   540,   542,   544,   548,   548,   554,   555,   557,
     558,   560,   567,   568,   573,   575,   584,   586,   586,   589,
     594,   599,   604,   604,   606,   608,   617,   619,   619,   622,
     627,   632,   637,   637,   641,   643,   655,   657,   657,   660,
     665,   670,   674,   679,   684,   691,   691,   693,   695,   708,
     710,   710,   713,   718,   723,   728,   733,   738,   743,   750,
     750,   754,   756,   766,   768,   768,   771,   776,   781,   785,
     792,   792,   806,   808,   817,   819,   819,   822,   827,   832,
     837,   839,   841,   847,   853,   853,   855,   857,   859,   861,
     874,   876,   878,   887,   889,   889,   892,   897,   902,   907,
     909,   911,   917,   923,   923,   925,   927,   929,   931,   944,
     953,   953,   955,   957,   957,   959,   962,   964,   964,   966,
     968,   970,   970,   972,   974,   976,   978,   978,   980,   982,
     984,   986,   986,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,  1001,  1002,  1004,  1004,  1006,  1008,  1010,
    1010,  1012,  1014,  1016,  1018,  1018,  1020,  1022,  1024,  1026,
    1026,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1040,  1040,  1042,  1044,  1046,  1048,  1052,  1052,  1054,  1056,
    1058,  1061,  1061,  1063,  1065,  1067,  1067,  1069,  1071,  1073,
    1075,  1075,  1077,  1079,  1081,  1083,  1083,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1099,  1099,
    1101,  1103,  1105,  1107,  1110,  1110,  1112,  1114,  1116,  1116,
    1118,  1120,  1122,  1122,  1124,  1126,  1128,  1128,  1130,  1132,
    1132,  1134,  1135,  1138,  1139,  1142,  1193,  1195,  1209,  1210,
    1212,  1212,  1236,  1237,  1240,  1241,  1243,  1245,  1246,  1250,
    1251,  1253,  1254,  1256,  1275,  1286,  1293,  1298,  1299,  1301,
    1302,  1304,  1304,  1307,  1319,  1320,  1322,  1323,  1327,  1328,
    1330,  1331,  1333,  1352,  1363,  1370,  1375,  1376,  1378,  1379,
    1381,  1381,  1384,  1396,  1397,  1399,  1409,  1413,  1414,  1416,
    1417,  1419,  1438,  1445,  1450,  1451,  1453,  1454,  1456,  1456,
    1459,  1471,  1472,  1477,  1477,  1485,  1486,  1488,  1489,  1491,
    1495,  1501,  1512,  1517,  1532,  1543,  1554,  1565,  1576,  1584,
    1592,  1600,  1608,  1617,  1627,  1636,  1647,  1658,  1670,  1681,
    1692,  1704,  1715,  1726,  1737,  1748,  1759,  1770,  1781,  1793,
    1805,  1816,  1827,  1840,  1841,  1848,  1850,  1850,  1852,  1853,
    1854,  1855,  2020,  2029,  2031,  2031,  2033,  2035,  2044,  2046,
    2046,  2048,  2048,  2050,  2067,  2070,  2070,  2072,  2072,  2075,
    2106,  2114,  2116,  2116,  2118,  2120,  2128,  2128,  2130,  2147,
    2149,  2149,  2151,  2151,  2153,  2247,  2256,  2278,  2296,  2296,
    2299,  2300,  2301,  2302,  2303,  2306,  2315,  2324,  2333,  2333,
    2335,  2337,  2344,  2346,  2346,  2351,  2369,  2393,  2393,  2396,
    2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2406,  2422,
    2434,  2446,  2458,  2470,  2484,  2498,  2505,  2505,  2507,  2512,
    2520,  2530,  2530,  2532,  2532,  2537,  2537,  2537,  2539,  2542,
    2551,  2551,  2553,  2555,  2558,  2560,  2560,  2562,  2572,  2578,
    2578,  2581,  2585,  2591,  2593,  2593,  2595,  2605,  2615,  2615,
    2617,  2619,  2621,  2624,  2635,  2642,  2642,  2644,  2646,  2648,
    2651,  2661,  2668,  2668,  2670,  2672,  2674,  2695,  2695,  2697,
    2705,  2711,  2711,  2714,  2718,  2724,  2726,  2726,  2728,  2738,
    2748,  2748,  2750,  2752,  2754,  2756,  2766,  2773,  2773,  2775,
    2777,  2779,  2782,  2792,  2799,  2799,  2801,  2803,  2805,  2834,
    2834,  2836,  2844,  2850,  2850,  2853,  2857,  2863,  2865,  2865,
    2867,  2877,  2888,  2888,  2890,  2892,  2894,  2897,  2907,  2914,
    2914,  2916,  2918,  2920,  2978,  2983,  2995,  3012,  3012,  3014,
    3016,  3018,  3020,  3020,  3022,  3030,  3036,  3047,  3047,  3050,
    3051,  3053,  3067,  3067,  3069,  3071,  3073,  3073,  3076,  3078,
    3086,  3086,  3093,  3100,  3100,  3102,  3110,  3116,  3116,  3119,
    3123,  3129,  3131,  3131,  3133,  3143,  3154,  3154,  3156,  3158,
    3160,  3163,  3173,  3180,  3180,  3182,  3184,  3186,  3248,  3249,
    3251,  3265,  3265,  3267,  3269,  3271,  3271,  3273,  3275,  3290,
    3290,  3292,  3294,  3304,  3304,  3306,  3314,  3320,  3320,  3323,
    3327,  3333,  3335,  3335,  3337,  3347,  3358,  3358,  3360,  3362,
    3364,  3366,  3376,  3383,  3383,  3385,  3387,  3389,  3392,  3402,
    3409,  3409,  3411,  3413,  3415,  3444,  3444,  3446,  3454,  3460,
    3460,  3463,  3467,  3473,  3475,  3475,  3477,  3487,  3498,  3498,
    3500,  3502,  3504,  3507,  3517,  3524,  3524,  3526,  3528,  3530,
    3533,  3543,  3550,  3550,  3552,  3554,  3556,  3664,  3669,  3685,
    3692,  3701,  3708,  3715,  3717,  3719,  3731,  3737,  3743,  3743,
    3745,  3747,  3749,  3751,  3761,  3767,  3773,  3773,  3775,  3777,
    3779,  3781,  3781,  3783,  3788,  3799,  3801,  3801,  3804,  3805,
    3806,  3813,  3831,  3849,  3849,  3851,  3853,  3859,  3861,  3872,
    3883,  3894,  3905,  3916,  3927,  3934,  3944,  3955,  3955,  3957,
    3966,  4011,  4012,  4018,  4023,  4042,  4043,  4045,  4053,  4069,
    4079,  4080,  4081,  4082,  4083,  4084,  4085,  4086,  4087,  4088,
    4089,  4090,  4091,  4092,  4093,  4094,  4095,  4096,  4097,  4098,
    4099,  4100,  4101,  4102,  4104,  4105,  4106,  4110,  4110,  4113,
    4114,  4116,  4116,  4119,  4120,  4124,  4124,  4129,  4129,  4134,
    4134,  4139,  4139,  4144,  4144,  4149,  4149,  4154,  4154,  4159,
    4159,  4164,  4164,  4169,  4169,  4174,  4174,  4179,  4179,  4184,
    4184,  4191,  4191,  4197,  4197,  4206,  4206,  4211,  4211,  4216,
    4216,  4226,  4226,  4231,  4232,  4234,  4235,  4237,  4238,  4239,
    4243,  4242,  4252,  4251,  4260,  4270,  4269,  4276,  4277,  4279,
    4278,  4285,  4286,  4289,  4295,  4303,  4310,  4330,  4330,  4341,
    4341,  4344,  4344,  4356,  4357,  4360,  4360,  4371,  4372,  4375,
    4375,  4386,  4387,  4390,  4390,  4400,  4401,  4407,  4408,  4409,
    4410,  4411,  4412,  4413,  4414,  4415,  4416,  4417,  4418,  4419,
    4420,  4421,  4422,  4425,  4430,  4437,  4438,  4440,  4451,  4453,
    4459,  4461,  4463,  4469,  4471,  4473,  4479,  4481,  4483,  4489,
    4491,  4493,  4499,  4499,  4504,  4506,  4508,  4514,  4514,  4519,
    4521,  4530,  4532,  4537,  4537,  4539,  4541,  4547,  4550,  4552,
    4558,  4561,  4563,  4569,  4572,  4574,  4580,  4583,  4583,  4593,
    4594,  4598,  4600,  4606,  4608,  4610,  4616,  4619,  4621,  4627
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
  "osilIntervalstartATT", "osilNumberOfMatricesATT",
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
     575,   576,   577,   578,   578,   579,   580,   580,   581,   581,
     581,   581,   582,   582,   583,   583,   584,   585,   586,   587,
     587,   588,   588,   589,   590,   591,   591,   592,   592,   593,
     594,   594,   595,   595,   596,   597,   598,   598,   599,   600,
     601,   601,   602,   602,   603,   604,   605,   606,   607,   607,
     608,   608,   608,   608,   608,   609,   610,   611,   612,   612,
     613,   614,   615,   616,   616,   617,   618,   619,   619,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   629,   630,   631,
     632,   633,   633,   634,   634,   635,   635,   635,   636,   637,
     638,   638,   639,   640,   641,   642,   642,   643,   644,   645,
     645,   646,   646,   647,   648,   648,   649,   650,   651,   651,
     652,   653,   654,   655,   656,   657,   657,   658,   659,   660,
     661,   662,   663,   663,   664,   665,   666,   667,   667,   668,
     669,   670,   670,   671,   671,   672,   673,   673,   674,   675,
     676,   676,   677,   678,   679,   680,   681,   682,   682,   683,
     684,   685,   686,   687,   688,   688,   689,   690,   691,   692,
     692,   693,   694,   695,   695,   696,   696,   697,   698,   698,
     699,   700,   701,   701,   702,   703,   704,   705,   706,   707,
     707,   708,   709,   710,   711,   711,   712,   713,   713,   714,
     715,   716,   717,   717,   718,   719,   720,   721,   721,   722,
     722,   723,   724,   724,   725,   726,   727,   727,   728,   729,
     730,   730,   731,   732,   732,   733,   734,   735,   735,   736,
     736,   737,   738,   738,   739,   740,   741,   741,   742,   743,
     744,   745,   746,   747,   747,   748,   749,   750,   751,   751,
     752,   753,   753,   754,   755,   756,   756,   757,   758,   759,
     759,   760,   761,   762,   762,   763,   764,   765,   765,   766,
     766,   767,   768,   768,   769,   770,   771,   771,   772,   773,
     774,   775,   776,   777,   777,   778,   779,   780,   781,   782,
     783,   783,   784,   785,   786,   787,   787,   788,   789,   790,
     790,   791,   791,   792,   793,   793,   794,   795,   796,   796,
     797,   798,   799,   800,   801,   802,   802,   803,   804,   805,
     806,   807,   808,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   823,
     824,   825,   826,   827,   828,   829,   830,   830,   831,   832,
     833,   834,   834,   835,   836,   837,   838,   838,   839,   839,
     839,   840,   841,   842,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   855,   856,
     857,   858,   858,   859,   860,   861,   861,   862,   863,   864,
     865,   865,   865,   865,   865,   865,   865,   865,   865,   865,
     865,   865,   865,   865,   865,   865,   865,   865,   865,   865,
     865,   865,   865,   865,   865,   865,   865,   867,   866,   868,
     868,   870,   869,   871,   871,   873,   872,   875,   874,   877,
     876,   879,   878,   881,   880,   883,   882,   885,   884,   887,
     886,   889,   888,   891,   890,   893,   892,   895,   894,   897,
     896,   899,   898,   901,   900,   903,   902,   905,   904,   907,
     906,   909,   908,   910,   910,   911,   911,   912,   912,   912,
     914,   913,   916,   915,   917,   919,   918,   920,   920,   921,
     920,   922,   922,   923,   923,   924,   925,   927,   926,   928,
     928,   930,   929,   931,   931,   933,   932,   934,   934,   936,
     935,   937,   937,   939,   938,   940,   940,   941,   941,   941,
     941,   941,   941,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   941,   942,   943,   944,   944,   566,   945,   946,
     947,   948,   949,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   959,   960,   961,   962,   963,   963,   964,
     965,   966,   967,   968,   968,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   982,   981,   983,
     983,   984,   985,   986,   987,   988,   989,   990,   991,   992
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
       4,     4,     4,     3,     3,     4,     4,     4,     4,     4,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     3,
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
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     3,     1,     0,     4,     1,
       1,     0,     2,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     0,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     4,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     4,     3,     0,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     0,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       3,     1,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     4,     4,     1,     1,     1,     3,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       3,     0,     4,     1,     5,     0,     2,     5,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     6,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     2,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     4,     0,     4,     1,     2,     0,
       4,     0,     2,     1,     1,     4,     4,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     4,     2,     1,
       2,     2,     1,     3,     2,     1,     2,     2,     1,     2,
       4,     1,     0,     1,     2,     4,     1,     0,     1,     2,
       3,     2,     1,     1,     2,     2,     1,     3,     2,     1,
       2,     2,     1,     3,     2,     1,     3,     0,     4,     0,
       2,     2,     1,     3,     2,     1,     6,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,   761,     0,    11,     1,   763,    27,     0,
       0,     0,    29,    37,     0,     0,   765,     0,     9,    14,
      12,    17,    39,   150,     0,     0,     0,    30,     0,     0,
       0,     0,   152,   266,     0,     0,     0,    40,     0,    33,
      35,    28,    31,    32,     0,   762,   768,   766,     0,    10,
      15,     0,     0,     0,     0,     0,    13,    18,    19,    20,
      21,    22,   268,     0,     0,   155,   157,   151,   153,   154,
       0,    43,    45,    38,    41,    42,     0,     0,     0,     0,
       0,    16,     0,     0,     0,   386,     4,     3,     7,   271,
     343,   267,   269,   270,   159,   185,     0,     0,     0,   354,
      34,   426,    36,   428,   764,     0,     0,     0,     0,     0,
       0,     0,     6,     2,     5,   272,   276,     0,     0,     0,
       0,   187,   221,     0,     0,     0,   160,   355,    44,    55,
      65,    75,    88,   102,   113,   132,    46,    47,    57,    48,
      67,    49,    77,    50,    90,    51,   104,    52,   115,    53,
     134,     0,   427,     0,   815,   807,   809,   813,   817,   819,
     867,   883,   827,   811,   833,   821,   823,   825,   855,   829,
     831,   875,   871,   879,   797,   801,   805,   841,   835,   837,
     839,     0,   791,   792,   772,   773,   775,   776,   777,   778,
     780,   781,   782,   784,   783,   785,   787,   788,   786,   794,
     795,   796,   770,   771,   774,   793,   789,   790,   779,    26,
      23,    24,    25,   386,   386,   388,   389,   390,   391,   387,
     273,     0,   280,   274,   347,   223,   254,     0,     0,     0,
     188,     0,   163,   166,   158,   161,   162,     0,    56,     0,
      66,     0,    76,     0,    89,     0,   103,     0,   114,     0,
     133,   440,   443,   425,   438,   439,     0,     0,     0,     0,
       0,   429,   430,   433,   434,   432,   431,   769,     0,     0,
       0,     0,     0,     0,   869,   885,     0,     0,     0,     0,
       0,     0,   861,     0,     0,   877,   873,   881,     0,     0,
       0,   845,     0,     0,     0,   767,   383,   384,     0,   280,
     278,     0,     0,   256,     0,     0,     0,     0,   224,     0,
     191,   194,   186,   189,   190,     0,     0,    62,     0,    54,
       0,     0,     0,    58,    59,    60,    61,    72,     0,    64,
      68,    69,    70,    71,    85,     0,    74,     0,     0,     0,
      78,    79,    80,    81,    83,    82,    84,    99,     0,    87,
       0,     0,    91,    92,    93,    94,    96,    95,    97,    98,
     110,     0,   101,     0,   105,   106,   107,   108,   109,     0,
     112,   116,   117,   118,   119,     0,   131,   135,   136,   137,
     138,   445,     0,   473,   447,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     799,     0,   798,   803,     0,   802,     0,     0,   909,   912,
     921,   926,   932,   936,   939,   942,   945,   947,   952,   955,
     958,   904,   915,   918,     0,   887,     0,   888,     0,   889,
       0,   902,     0,   890,     0,   891,   922,   892,   927,   893,
       0,   894,     0,   895,     0,   896,     0,   897,     0,   898,
     899,     0,   900,     0,   901,     0,     0,     0,     0,   275,
     279,   282,   345,     0,     0,     0,   344,   348,   349,   350,
     156,     0,     0,   257,     0,   227,   230,   222,   225,   226,
       0,     0,   358,   165,   169,   164,   167,   171,    63,     0,
       0,     0,    73,    86,   386,     0,     0,   100,     0,     0,
     111,     0,   122,     0,     0,   141,     0,     0,   441,   442,
       0,   446,   436,   437,   435,     0,     0,     0,     0,     0,
       0,   818,   820,   868,   870,   884,   886,   828,   812,     0,
     822,   824,   826,   857,     0,     0,     0,   856,   862,   863,
     864,   830,   832,   876,   878,   872,   874,   880,   882,   800,
     804,     0,   843,     0,     0,     0,     0,   842,   846,   847,
     849,   848,   949,   836,     0,     0,     0,     0,   908,     0,
     911,     0,   914,     0,   917,     0,     0,   923,     0,   928,
     933,     0,   931,     0,   935,     0,   938,     0,   941,     0,
     944,     0,   951,     0,   954,     0,   957,   838,   840,     0,
       0,     0,   346,   386,   386,     0,   260,   262,   255,   258,
     259,     0,     0,   359,   193,   197,   192,   195,   199,     0,
     170,   363,     0,     0,     0,     0,     0,     0,     0,   370,
     130,   120,     0,     0,   123,   149,   139,     0,   142,   711,
     479,   708,   474,   475,     0,   476,     0,   477,     0,   472,
       0,   444,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   465,   466,   467,   457,   749,   751,   816,   808,   810,
     814,     0,   858,   859,     0,   386,   806,   844,   850,   386,
     852,     0,     0,     0,   905,     0,   903,   910,     0,   916,
     919,     0,     0,     0,   934,     0,   940,     0,     0,     0,
       0,   959,   277,     0,   284,   287,   281,     0,     0,     0,
       0,   360,   229,   233,   228,   231,   235,     0,   198,   183,
       0,   168,     0,     0,     0,     0,     0,     0,     0,   172,
     181,   177,   178,   179,   180,   175,   182,   176,   174,   173,
     357,   356,   365,   366,   367,   368,   369,     0,   126,   394,
     121,   124,   125,   145,   394,   140,   143,   144,   482,   485,
     478,   480,   481,     0,     0,     0,   712,   471,     0,     0,
       0,     0,     0,     0,     0,   386,   386,   834,     0,     0,
       0,     0,     0,     0,   948,   950,     0,     0,   906,   913,
     930,     0,   920,     0,   925,   937,   943,   946,   953,     0,
     283,   289,     0,   306,   352,   353,   362,   261,     0,   263,
       0,   234,   212,   216,   196,   210,   211,     0,     0,     0,
       0,     0,   200,   209,   207,   208,   206,   205,   203,   204,
     202,   201,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   392,   393,     0,   147,   487,   517,
     489,     0,     0,     0,   710,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,   860,   866,   865,   851,   854,
     853,   907,   371,   924,   929,     0,     0,   285,   308,   325,
       0,     0,   250,   216,   232,   248,   249,     0,   236,   247,
     245,   246,   241,   242,   243,   244,   239,   240,   238,   237,
       0,   214,     0,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,   750,     0,     0,   129,   127,   397,
     395,   399,   148,   146,   519,   549,   521,     0,   488,   709,
     707,     0,   716,     0,     0,   458,   459,   460,   461,   462,
     463,   464,   470,   385,     0,   297,   301,     0,     0,   290,
     291,   292,   288,   295,     0,   327,   286,     0,     0,   252,
       0,     0,   215,   213,     0,   217,     0,     0,     0,     0,
       0,   364,   372,   374,   375,   376,   378,   380,     0,   408,
       0,   404,   405,   406,     0,   398,   551,   603,   553,     0,
     520,     0,     0,   759,     0,   490,   491,   492,   757,   758,
     748,   724,   731,     0,     0,   717,   956,   298,   301,   299,
       0,     0,     0,   316,   320,     0,     0,   309,   310,   311,
     307,   314,     0,     0,     0,   253,   251,     0,   219,     0,
     361,   381,   377,   373,     0,     0,   407,     0,   396,     0,
       0,   400,   402,   401,   605,   675,   607,     0,   552,     0,
     522,   523,   524,   497,   486,   494,     0,     0,     0,     0,
       0,   725,   720,   394,   715,   718,   719,   296,   300,     0,
       0,     0,   317,   320,   318,     0,     0,     0,   334,   338,
       0,     0,   328,   329,   326,   332,   330,   265,   264,   382,
     220,   218,   754,   409,     0,     0,     0,   677,   643,   679,
       0,   606,     0,   554,   555,   556,   529,   518,   526,     0,
     504,     0,     0,     0,   500,   394,   496,   498,   499,     0,
     760,   734,   714,   713,   732,   736,   728,   394,   723,   726,
     727,   722,     0,     0,     0,   293,   294,   315,   319,     0,
       0,     0,   335,   338,   336,     0,     0,     0,   403,     0,
       0,   645,     0,   647,     0,   678,     0,   608,   609,   610,
     561,   550,   558,     0,   536,     0,     0,     0,   532,   394,
     528,   530,   531,   493,   511,   495,     0,   507,   394,   503,
     505,   506,   502,     0,   752,     0,   735,   730,     0,   721,
       0,   304,     0,   302,     0,     0,   312,   313,   333,   337,
       0,     0,     0,   755,   756,   484,   483,     0,   646,     0,
     680,   681,   682,   615,   604,   612,     0,   568,     0,   574,
       0,   564,   394,   560,   562,   563,   525,   543,   527,     0,
     539,   394,   535,   537,   538,   534,     0,   514,   412,   510,
     512,   513,   509,     0,   501,   745,   443,   733,   743,   744,
     386,   386,   740,   737,   738,   739,   729,     0,   305,     0,
     323,     0,   321,     0,     0,   331,   351,     0,   648,   649,
     650,   687,   676,   684,     0,   622,     0,   628,     0,   618,
     394,   614,   616,   617,   557,   576,   559,     0,   571,   394,
     567,   569,   570,   566,     0,   546,   394,   542,   544,   545,
     541,     0,   533,     0,   516,   410,   411,     0,   508,   473,
       0,     0,     0,   303,     0,   324,     0,   341,     0,   339,
     655,   644,   652,     0,   694,     0,     0,     0,   690,   394,
     686,   688,   689,   611,   630,   613,     0,   625,   394,   621,
     623,   624,   620,     0,   579,   582,   575,   577,   578,   573,
       0,   565,   548,     0,   540,     0,   415,   413,   416,   515,
     747,   746,   386,   386,   322,     0,   342,   662,     0,     0,
       0,   658,   394,   654,   656,   657,   683,   701,   685,     0,
     697,   394,   693,   695,   696,   692,     0,   633,   635,   629,
     631,   632,   627,     0,   619,     0,   581,   572,   547,   423,
       0,   419,   420,   421,     0,   417,   741,   742,   340,   651,
     669,   653,     0,   665,   394,   661,   663,   664,   660,     0,
     704,   394,   700,   702,   703,   699,     0,   691,     0,   626,
     580,   585,   583,   587,     0,   422,   386,   414,   672,   394,
     668,   670,   671,   667,     0,   659,   706,     0,   698,   638,
     634,   636,     0,     0,   586,   424,     0,   674,     0,   666,
     705,   641,     0,   637,   639,   640,   594,   596,   584,   592,
     593,     0,     0,   588,   590,   589,   418,   673,     0,     0,
     386,     0,   642,   595,   599,   597,   600,     0,     0,     0,
       0,   591,   753,   386,     0,   598,     0,     0,   601,   602
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
     643,   770,   771,   772,   862,   938,   641,   149,   150,   249,
     250,   377,   376,   516,   517,   647,   775,   776,   777,   866,
     943,   646,    33,    34,    67,    68,    69,    95,    96,   125,
     234,   235,   236,   495,   316,   496,   497,   629,   630,   749,
     741,   122,   123,   229,   312,   313,   314,   626,   491,   627,
     628,   737,   738,   842,   834,   835,   836,   920,   983,   921,
     985,   986,  1111,   226,   227,   307,   487,   488,   489,   734,
     622,   735,   736,   830,   831,   908,   904,   905,   906,   980,
    1046,   304,   305,   482,   618,   619,   620,   730,   829,   901,
      63,    64,    91,    92,    93,   117,   118,   222,   299,   300,
     301,   611,   726,   822,   823,   896,   969,   970,   971,   972,
     973,  1028,  1029,  1030,  1154,  1213,   899,   974,  1037,  1038,
    1039,  1040,  1041,  1093,  1094,  1095,  1215,  1282,   976,  1042,
    1102,  1103,  1104,  1105,  1163,  1164,  1165,  1284,  1339,   119,
     120,   476,   302,   477,  1106,   478,   479,    27,    37,   324,
     325,   126,   230,   308,   843,   483,   326,   845,   344,   345,
     346,   358,   359,   368,   576,   751,   846,   752,   753,   754,
     847,   755,   756,   757,   849,   917,   110,   883,   111,   219,
     863,   864,   940,   941,  1004,  1005,  1061,  1058,   865,  1001,
    1002,  1003,  1324,  1325,  1377,  1378,  1424,  1457,  1326,  1421,
    1422,  1423,   102,   103,   151,   152,   261,   262,   263,   264,
     253,   254,   255,   382,   383,   384,   520,   521,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   661,   519,   652,   653,   654,   780,   781,   782,  1226,
     869,   870,   947,   948,  1015,  1074,  1131,  1075,  1076,  1136,
    1137,  1138,  1203,  1132,  1133,  1199,  1200,  1201,  1263,  1195,
    1196,  1259,  1260,  1261,  1327,   945,   946,  1009,  1010,  1070,
    1127,  1185,  1128,  1129,  1190,  1191,  1192,  1256,  1186,  1187,
    1252,  1253,  1254,  1321,  1248,  1249,  1317,  1318,  1319,  1373,
    1007,  1008,  1067,  1068,  1123,  1181,  1238,  1182,  1183,  1243,
    1244,  1245,  1314,  1239,  1240,  1310,  1311,  1312,  1370,  1306,
    1307,  1366,  1367,  1368,  1415,  1416,  1452,  1453,  1473,  1474,
    1493,  1494,  1488,  1489,  1490,  1499,  1505,  1506,  1510,  1515,
    1065,  1066,  1120,  1121,  1177,  1234,  1296,  1235,  1236,  1301,
    1302,  1303,  1363,  1297,  1298,  1359,  1360,  1361,  1413,  1355,
    1356,  1409,  1410,  1411,  1448,  1471,  1472,  1483,  1484,  1485,
    1172,  1173,  1227,  1228,  1288,  1341,  1388,  1342,  1343,  1393,
    1394,  1395,  1439,  1389,  1390,  1435,  1436,  1437,  1464,  1431,
    1432,  1460,  1461,  1462,  1478,  1118,  1119,  1174,  1175,  1230,
    1292,  1345,  1293,  1294,  1350,  1351,  1352,  1406,  1346,  1347,
    1402,  1403,  1404,  1446,  1398,  1399,  1442,  1443,  1444,  1467,
     655,   656,   950,   657,   658,   785,   874,  1143,   953,   954,
    1024,  1084,  1085,  1086,  1152,  1022,  1023,  1080,  1148,  1149,
    1150,  1208,  1079,  1144,  1145,  1205,  1206,  1273,  1274,  1275,
    1267,  1268,  1269,  1330,   786,   265,   644,   266,  1016,  1495,
     936,  1062,  1063,  1017,  1018,  1019,     8,     9,    16,    29,
      47,    48,    80,   181,   182,   288,   412,   183,   289,   415,
     184,   290,   185,   269,   186,   270,   187,   277,   188,   271,
     189,   268,   190,   272,   191,   273,   192,   279,   193,   280,
     194,   281,   195,   276,   196,   283,   197,   284,   198,   278,
     199,   292,   200,   293,   201,   294,   202,   291,   567,   417,
     568,   569,   801,   570,   803,   571,   203,   282,   547,   798,
     404,   548,   549,   550,   204,   274,   396,   205,   286,   408,
     206,   285,   407,   207,   287,   409,   208,   275,   397,   434,
     435,   436,   706,   437,   438,   578,   439,   440,   580,   441,
     442,   582,   443,   444,   584,   445,   446,   586,   812,   447,
     448,   588,   814,   587,   449,   450,   592,   451,   452,   594,
     453,   454,   596,   455,   456,   598,   457,   458,   600,   459,
     572,   701,   460,   461,   602,   462,   463,   604,   464,   465,
     606
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1156
static const yytype_int16 yypact[] =
{
      49,    36,    76,  -154,    85, -1156, -1156, -1156,    84,  -139,
     139,    58, -1156,   118,   130,   163, -1156,   168, -1156, -1156,
   -1156, -1156, -1156,   116,   158,   191,   132, -1156,   219,  -137,
     187,    30, -1156,   102,   195,   227,   200, -1156,   229, -1156,
   -1156, -1156, -1156, -1156,   231, -1156, -1156, -1156,   220, -1156,
   -1156,   212,   239,   243,   245,   247, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156,   205,   214, -1156,   193, -1156, -1156, -1156,
     260, -1156, -1156, -1156, -1156, -1156,   266,     7,   267,   277,
     271, -1156,   279,   283,   285, -1156, -1156, -1156,   272, -1156,
     252, -1156, -1156, -1156, -1156,   222,   235,   291,   223, -1156,
   -1156, -1156, -1156, -1156, -1156,   293,   622,   295,   299,   307,
     309,    25, -1156, -1156, -1156, -1156, -1156,   208,   209,   210,
     201, -1156,   254,   261,   360,   405, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   407,    32,   362, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   134, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   364, -1156, -1156, -1156, -1156,   282,   292,   372,   409,
   -1156,   376, -1156, -1156, -1156, -1156, -1156,   411,    40,   413,
      40,   417,    34,   419,    18,   421,    38,   368,    40,   374,
      40, -1156,   216, -1156, -1156, -1156,   385,   387,   391,   394,
     396, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   622,   622,
     622,   622,   622,   622, -1156, -1156,   622,   622,   622,   622,
     622,   622, -1156,   622,   622, -1156, -1156, -1156,   423,   429,
     622, -1156,   161,   161,   161, -1156,  -210,  -210,   398,   301,
   -1156,   294,    55, -1156,   334,   318,   410,   431, -1156,   418,
   -1156, -1156, -1156, -1156, -1156,   433,    63, -1156,   420, -1156,
     450,   440,   455, -1156, -1156, -1156, -1156, -1156,   422, -1156,
   -1156, -1156, -1156, -1156, -1156,   424, -1156,   459,   461,   465,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   426, -1156,
     469,   471, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   430, -1156,   476, -1156, -1156, -1156, -1156, -1156,   427,
   -1156, -1156, -1156, -1156, -1156,   464, -1156, -1156, -1156, -1156,
   -1156, -1156,   315, -1156, -1156,   484,   551,   558,   566,   567,
     622,   622,   622,   622,   313,   326,    37,   124,   321,   221,
     622,   316,   317,   314,    33,   312,   311,   474,   511,   550,
   -1156,   304, -1156, -1156,   297, -1156,   622,    35, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156,   298, -1156,    52, -1156,   161, -1156,
     161, -1156,   622, -1156,   161, -1156,   259, -1156,   259, -1156,
     435, -1156,   161, -1156,   161, -1156,   161, -1156,   161, -1156,
   -1156,   622, -1156,   622, -1156,   161,   302,   296,   583, -1156,
   -1156,   569, -1156,   457,   589,   590, -1156, -1156, -1156, -1156,
   -1156,   593,   437, -1156,   587, -1156, -1156, -1156, -1156, -1156,
     594,    95, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   595,
     592,   596, -1156, -1156, -1156,   598,   599, -1156,   600,   601,
   -1156,   597, -1156,   554,   445, -1156,   560,   445, -1156,   -92,
     439,   153, -1156, -1156, -1156,   606,   608,   375,   377,   370,
     371, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   622,
   -1156, -1156, -1156, -1156,   591,   612,   614, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   336, -1156,   337,   617,   620,   621, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156,   623,   624,   475,   331, -1156,   161,
   -1156,   308, -1156,   305, -1156,   626,   625, -1156,   628, -1156,
   -1156,   330, -1156,   161, -1156,   327, -1156,   161, -1156,   161,
   -1156,   161, -1156,   622, -1156,   320, -1156, -1156, -1156,   629,
     630,   479, -1156, -1156, -1156,   634, -1156, -1156, -1156, -1156,
   -1156,   632,    20, -1156, -1156, -1156, -1156, -1156, -1156,   481,
      91, -1156,   639,   640,   641,   642,   643,   645,   646, -1156,
   -1156, -1156,   647,   483, -1156, -1156, -1156,   485, -1156, -1156,
   -1156, -1156, -1156, -1156,   488, -1156,   644, -1156,   452, -1156,
     482, -1156,   648,   650,   651,   653,   654,   655,   656,   657,
   -1156,   658, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,   402, -1156, -1156,   659, -1156, -1156, -1156, -1156, -1156,
   -1156,   -57,   660,   661, -1156,   344, -1156, -1156,   369, -1156,
   -1156,   662,   161,   161, -1156,   366, -1156,   363,   365,   358,
     622, -1156, -1156,   669, -1156,   562, -1156,   670,   672,   674,
      67, -1156, -1156, -1156, -1156, -1156, -1156,   490,    50, -1156,
     605, -1156,   675,   678,   679,   680,   681,   682,   683, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156,   684, -1156,   527,
   -1156, -1156, -1156, -1156,   527, -1156, -1156, -1156, -1156,   491,
   -1156, -1156, -1156,   161,   687,   685, -1156, -1156,   686,   688,
     690,   691,   692,   693,   694, -1156, -1156, -1156,   425,   699,
     700,   701,   703,   704, -1156, -1156,   705,   706, -1156, -1156,
   -1156,   397, -1156,   414, -1156, -1156, -1156, -1156, -1156,   622,
   -1156, -1156,   607,   604, -1156, -1156, -1156, -1156,   697, -1156,
     492,    14, -1156, -1156, -1156, -1156, -1156,   718,   720,   722,
     724,   725, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156,   728,   726,   730,   732,   734,   736,   738,
     763,   570,   712, -1156,   610, -1156,   714, -1156, -1156,   572,
   -1156,   547,   767,   579, -1156,   775,   779,   781,   802,   804,
     806,   808,   810, -1156,    21, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156,   161,    53, -1156, -1156,   707,
     812,   814, -1156, -1156, -1156, -1156, -1156,   816, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
     739,   757,   837,   839,   841,   843,   818, -1156,   849,   851,
     853,   880,   882,   884, -1156,   886,   494, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156,   689, -1156,   890,  -142, -1156,
   -1156,   888, -1156,   667,   445, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156,   580, -1156,   780,   900,   902, -1156,
   -1156, -1156, -1156, -1156,    57, -1156, -1156,   904,   622,   757,
     824,   906, -1156, -1156,   898, -1156,   161,   911,   912,   913,
     914, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   915, -1156,
      42, -1156, -1156, -1156,   907,   343, -1156,   708, -1156,   908,
    -142,   721,   920, -1156,   921, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156,   445,   499, -1156, -1156, -1156,   807, -1156,
     803,   919,   922, -1156,   813,   925,   927, -1156, -1156, -1156,
   -1156, -1156,    80,   929,   842, -1156, -1156,   931, -1156,   850,
   -1156, -1156, -1156, -1156,   932,   776, -1156,   930, -1156,   936,
     937, -1156, -1156, -1156, -1156,   727, -1156,   933,  -142,   741,
   -1156, -1156, -1156, -1156, -1156,   742,   501,   935,   942,  -100,
     503, -1156, -1156,   527, -1156, -1156, -1156, -1156, -1156,   934,
     944,   945, -1156,   831, -1156,   825,   943,   946, -1156,   835,
     952,   953, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156,   790,   951,   954, -1156,   745, -1156,
     949,  -142,   762, -1156, -1156, -1156, -1156, -1156,   759,   505,
   -1156,   765,   760,   507, -1156,   527, -1156, -1156, -1156,   962,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156,   527, -1156, -1156,
   -1156, -1156,   743,   964,   512, -1156, -1156, -1156, -1156,   955,
     967,   968, -1156,   855, -1156,   844,   969,   970, -1156,   972,
     975, -1156,   782, -1156,   971,  -142,   783, -1156, -1156, -1156,
   -1156, -1156,   777,   514, -1156,   771,   778,   516, -1156,   527,
   -1156, -1156, -1156, -1156, -1156, -1156,   518, -1156,   527, -1156,
   -1156, -1156, -1156,   784, -1156,   520,  -125, -1156,   761, -1156,
     979, -1156,   862, -1156,   986,   522, -1156, -1156, -1156, -1156,
     973,   987,   989, -1156, -1156, -1156, -1156,   982,  -142,   794,
   -1156, -1156, -1156, -1156, -1156,   791,   524, -1156,   785,   792,
     526, -1156,   527, -1156, -1156, -1156, -1156, -1156, -1156,   528,
   -1156,   527, -1156, -1156, -1156, -1156,   796, -1156,   838, -1156,
   -1156, -1156, -1156,   795, -1156, -1156,   216, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156,   998, -1156,   995,
   -1156,   876, -1156,  1001,   530, -1156, -1156,   805, -1156, -1156,
   -1156, -1156, -1156,   811,   532, -1156,   793,   801,   534, -1156,
     527, -1156, -1156, -1156, -1156, -1156, -1156,   537, -1156,   527,
   -1156, -1156, -1156, -1156,   809, -1156,   527, -1156, -1156, -1156,
   -1156,   815, -1156,   570, -1156,   845, -1156,   817, -1156, -1156,
     836,  1005,  1007, -1156,  1013, -1156,  1010, -1156,   879, -1156,
   -1156, -1156,   819,   539, -1156,   820,   821,   542, -1156,   527,
   -1156, -1156, -1156, -1156, -1156, -1156,   546, -1156,   527, -1156,
   -1156, -1156, -1156,   827, -1156, -1156, -1156, -1156, -1156, -1156,
     826, -1156, -1156,   822, -1156,   548, -1156, -1156,   854, -1156,
     -92, -1156, -1156, -1156, -1156,  1016, -1156, -1156,   823,   828,
     553, -1156,   527, -1156, -1156, -1156, -1156, -1156, -1156,   555,
   -1156,   527, -1156, -1156, -1156, -1156,   829, -1156, -1156, -1156,
   -1156, -1156, -1156,   830, -1156,   832,   856, -1156, -1156, -1156,
      51, -1156, -1156, -1156,  1014, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156,   557, -1156,   527, -1156, -1156, -1156, -1156,   840,
   -1156,   527, -1156, -1156, -1156, -1156,   846, -1156,  -106, -1156,
   -1156, -1156, -1156, -1156,   859, -1156, -1156, -1156, -1156,   527,
   -1156, -1156, -1156, -1156,   847, -1156, -1156,   833, -1156, -1156,
   -1156, -1156,   559,   561,  -111, -1156,   865, -1156,   848, -1156,
   -1156, -1156,   622, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156,  1030,  1033, -1156, -1156, -1156, -1156, -1156,   875,  -131,
   -1156,  1036, -1156, -1156, -1156, -1156,   717,  1042,  1043,  1044,
    1037, -1156, -1156, -1156,  1046, -1156,  1047,   852, -1156, -1156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   146,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   755,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156,    28, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156,   -36, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156,  -105, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,   -86,
      88, -1156, -1156, -1156,   228, -1156,  -219,   230,   834,   857,
   -1156, -1156, -1156, -1156, -1156,   234, -1156,   236,   237,   238,
   -1156,  -700, -1156, -1156, -1156, -1156,  -487, -1155,  -207, -1156,
    -754, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156,  -146, -1156, -1156,
   -1156, -1156, -1156, -1156,  -204, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156,  -263, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156,  -602,  -503,  -600,  -984, -1156,
    -253, -1156,  -307,  -976, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156,  -268, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,  -275,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156,   627, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156, -1156,
   -1156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     390,   391,   392,   393,   394,   395,   296,   297,   398,   399,
     400,   401,   402,   403,   648,   405,   406,   634,   466,   467,
     867,   333,   416,   343,   963,   355,  1071,   367,   758,   374,
     759,   380,   213,   214,  1072,   320,  1503,   100,   848,   320,
      50,    51,  1012,   543,   544,   562,   563,  1055,    52,    53,
      54,   545,   258,   256,   257,   320,  1454,   564,   565,   320,
    1469,   320,     4,   965,   966,   472,   473,  1033,  1034,  1491,
     574,   320,  1141,     1,  1492,  1142,     6,   337,   338,     7,
     350,   351,   649,    18,  1124,    19,  1013,  1014,    10,  1504,
    1098,  1099,  1125,   337,   338,   339,    15,    45,   837,    46,
     732,  1470,   733,   363,   650,  1270,  1271,   743,   744,   745,
     746,   747,   320,    12,   907,  1331,  1332,   841,   215,   216,
     217,   218,   527,   528,   529,   530,   727,   728,   534,   536,
     651,   916,   539,   493,   837,   494,   850,  1178,   851,   554,
     556,   558,    39,    40,   575,  1179,    17,   747,   561,   838,
      22,   839,   840,   841,   331,   827,   341,   828,   353,   742,
     365,    25,   372,   577,   378,   579,    28,   474,   475,   583,
     624,    30,   625,   967,   581,   101,   968,   593,  1035,   595,
    1036,   597,    32,   599,   743,   744,   745,   746,   747,   748,
     605,  1231,    35,   601,    38,   603,   259,   260,    49,  1232,
     321,   322,  1100,  1101,  1056,    65,    66,    62,   800,   258,
      71,    72,   802,  1455,   259,   260,   321,   322,    86,    87,
     321,   322,   321,   322,    89,    90,    44,  1426,  1427,   918,
      70,   919,   259,   260,    78,   418,    76,   419,    79,   420,
      81,   421,    82,   422,  1289,   423,    83,   424,    84,   425,
      85,   426,  1290,   427,   804,   428,   128,   429,   129,   430,
     130,   431,    94,   432,   131,   433,   132,    97,   133,    99,
     134,   691,   135,   259,   260,   154,   693,   155,   104,   156,
     105,   157,   106,   158,   112,   159,   107,   160,   533,   161,
     108,   162,   109,   163,   127,   164,   121,   165,   209,   166,
     153,   167,   210,   168,   708,   169,   124,   170,   882,   171,
     211,   172,   212,   173,   220,   174,   223,   175,   715,   176,
     221,   177,   717,   178,   718,   179,   719,   180,   332,  1151,
     342,   224,   354,   225,   366,   720,   373,   228,   379,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   215,
     216,   217,   218,   215,   216,   217,   218,    55,   115,   116,
     546,   566,   154,   231,   155,   267,   156,   298,   157,   303,
     158,   295,   159,   306,   160,   309,   161,   535,   162,   369,
     163,  1202,   164,   315,   165,   375,   166,   381,   167,   385,
     168,   386,   169,  1207,   170,   387,   171,   388,   172,   389,
     173,   480,   174,   471,   175,   468,   176,   481,   177,   469,
     178,   750,   179,   484,   180,   232,   233,   251,   252,   310,
     311,   317,   318,   327,   328,   490,   805,   334,   335,   347,
     348,   360,   361,   410,   411,  1255,   492,   811,   813,   413,
     414,   485,   486,   500,  1262,   590,   591,   616,   617,   659,
     660,  1025,   819,   418,   499,   419,   498,   420,   501,   421,
     502,   422,   504,   423,   505,   424,   503,   425,   506,   426,
     507,   427,   508,   428,   509,   429,   510,   430,   538,   431,
     511,   432,   512,   433,   518,   704,   705,   522,  1313,   724,
     725,   739,   740,   768,   769,   773,   774,  1320,   778,   779,
     832,   833,   902,   903,   999,  1000,  1059,  1060,   871,  1082,
    1083,  1134,  1135,  1146,  1147,  1188,  1189,  1197,  1198,   844,
    1081,   515,  1211,  1212,  1241,  1242,  1250,  1251,  1257,  1258,
    1265,  1266,  1280,  1281,  1299,  1300,  1308,  1309,  1315,  1316,
    1337,  1338,  1348,  1349,  1357,  1358,  1362,  1364,  1365,  1391,
    1392,   895,  1400,  1401,   523,  1369,  1407,  1408,  1419,  1420,
     531,   524,  1372,  1433,  1434,  1440,  1441,  1458,  1459,  1481,
    1482,  1486,  1487,   525,   526,   532,   537,   540,   560,   542,
     541,   551,   552,   559,   585,   573,   609,   608,   612,   884,
     610,   607,   613,   614,   621,  1405,   615,   623,   631,   632,
     639,   642,   640,   633,  1412,   635,   636,   637,   638,   685,
     645,   686,   910,   689,   687,   694,   690,   695,   688,   696,
     964,   698,   697,   699,   707,   700,   702,   703,   710,   709,
     711,   714,   716,   784,   723,   731,   712,   721,  1438,   713,
     722,   729,   760,   761,   762,   763,   764,  1445,   765,   766,
     767,   788,   787,   789,   790,   783,   791,   792,   793,   794,
     795,   797,   796,   808,   809,   810,   799,   806,   807,   815,
     816,   818,   820,   824,   817,   825,   821,   826,   852,   853,
    1463,   854,   855,   856,   857,   858,   859,  1466,   861,   868,
     872,   860,   885,   875,   893,   876,   873,   877,   878,   879,
     880,   881,   886,   887,   888,  1477,   889,   890,   891,   892,
    1044,  1049,   154,   894,   155,   900,   156,   897,   157,   898,
     158,   922,   159,   923,   160,   924,   161,   925,   162,   926,
     163,   927,   164,   928,   165,   935,   166,   929,   167,   930,
     168,   931,   169,   932,   170,   933,   171,   553,   172,   154,
     173,   155,   174,   156,   175,   157,   176,   158,   177,   159,
     178,   160,   179,   161,   180,   162,   934,   163,   937,   164,
     949,   165,   942,   166,   951,   167,   939,   168,   955,   169,
     944,   170,   956,   171,   957,   172,   555,   173,   154,   174,
     155,   175,   156,   176,   157,   177,   158,   178,   159,   179,
     160,   180,   161,   952,   162,   958,   163,   959,   164,   960,
     165,   961,   166,   962,   167,   977,   168,   982,   169,   981,
     170,   991,   171,   975,   172,   978,   173,   557,   174,   154,
     175,   155,   176,   156,   177,   157,   178,   158,   179,   159,
     180,   160,   984,   161,   987,   162,   988,   163,   989,   164,
     990,   165,   992,   166,   993,   167,   994,   168,   692,   169,
     154,   170,   155,   171,   156,   172,   157,   173,   158,   174,
     159,   175,   160,   176,   161,   177,   162,   178,   163,   179,
     164,   180,   165,   995,   166,   996,   167,   997,   168,   998,
     169,  1020,   170,  1021,   171,  1026,   172,  1027,   173,  1006,
     174,  1011,   175,  1031,   176,  1032,   177,  1045,   178,  1048,
     179,  1043,   180,  1047,  1050,  1051,  1052,  1053,  1057,  1069,
    1064,  1073,  1054,  1077,  1087,  1078,  1090,  1089,  1096,  1091,
    1097,  1092,  1107,  1108,  1109,  1112,  1110,  1114,  1113,  1115,
    1116,  1126,  1139,  1117,  1122,  1140,  1130,  1155,  1156,  1157,
    1160,  1159,  1153,  1161,  1162,  1166,  1167,  1168,  1169,  1171,
    1176,  1170,  1180,  1184,  1193,  1204,  1194,  1210,  1209,  1476,
    1216,  1217,  1220,  1214,  1218,  1223,  1221,  1222,  1224,  1225,
    1246,  1237,  1229,  1233,  1247,  1264,  1277,  1278,  1276,  1279,
    1285,  1283,  1286,  1287,  1291,  1295,  1304,  1322,  1305,  1323,
    1328,  1333,  1334,  1335,  1336,  1340,  1353,  1354,  1386,  1381,
    1371,  1376,  1382,  1507,  1383,  1344,  1384,  1385,  1060,  1428,
    1374,  1475,  1451,  1387,  1379,  1456,  1516,  1397,  1414,  1418,
    1447,  1417,  1496,  1500,  1430,  1449,  1501,  1396,  1429,  1450,
    1480,  1465,  1502,  1508,  1509,  1511,  1512,  1513,  1514,   979,
    1518,  1468,  1479,  1517,   470,  1497,  1088,  1158,  1219,   909,
    1272,   911,  1329,   884,   884,   912,  1380,   913,   914,   915,
    1375,  1425,     0,  1519,     0,   589,     0,     0,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   884,   884,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1498
};

static const yytype_int16 yycheck[] =
{
     268,   269,   270,   271,   272,   273,   213,   214,   276,   277,
     278,   279,   280,   281,   517,   283,   284,   504,   293,   294,
     774,   240,   290,   242,     3,   244,  1010,   246,   630,   248,
     630,   250,     7,     8,  1010,    21,   167,    30,   738,    21,
      10,    11,   184,    10,    11,    10,    11,     5,    18,    19,
      20,    18,   177,    21,    22,    21,     5,    22,    23,    21,
     166,    21,    26,    10,    11,    10,    11,    10,    11,   180,
      18,    21,   172,    24,   185,   175,     0,    59,    60,   233,
      62,    63,   174,    25,  1068,    27,   228,   229,     3,   220,
      10,    11,  1068,    59,    60,    61,   235,   234,    84,   236,
      80,   207,    82,    65,   196,   230,   231,    93,    94,    95,
      96,    97,    21,    29,   100,  1270,  1271,   103,   328,   329,
     330,   331,   390,   391,   392,   393,   613,   614,   396,   397,
     222,   831,   400,    70,    84,    72,   738,  1121,   738,   407,
     408,   409,    10,    11,    92,  1121,     7,    97,   416,    99,
      32,   101,   102,   103,   240,    88,   242,    90,   244,    68,
     246,    31,   248,   438,   250,   440,     3,   112,   113,   444,
      75,     3,    77,   120,   442,   168,   123,   452,   121,   454,
     123,   456,    66,   458,    93,    94,    95,    96,    97,    98,
     465,  1175,    34,   461,     3,   463,   182,   183,    11,  1175,
     182,   183,   122,   123,   162,    10,    11,   105,   695,   177,
      10,    11,   699,   162,   182,   183,   182,   183,    13,    14,
     182,   183,   182,   183,    10,    11,     7,  1382,  1383,   831,
       3,   831,   182,   183,     3,   292,     7,   294,    18,   296,
      28,   298,     3,   300,  1228,   302,     3,   304,     3,   306,
       3,   308,  1228,   310,   311,   312,    33,   314,    35,   316,
      37,   318,    69,   320,    41,   322,    43,     7,    45,     3,
      47,   539,    49,   182,   183,   238,   544,   240,    11,   242,
       3,   244,    11,   246,    12,   248,     7,   250,   251,   252,
       7,   254,     7,   256,     3,   258,    74,   260,     3,   262,
       7,   264,     3,   266,   579,   268,    71,   270,   795,   272,
       3,   274,     3,   276,   106,   278,   106,   280,   593,   282,
     111,   284,   597,   286,   599,   288,   601,   290,   240,  1083,
     242,   130,   244,    79,   246,   603,   248,    76,   250,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   328,
     329,   330,   331,   328,   329,   330,   331,   327,   106,   107,
     327,   326,   238,     3,   240,     3,   242,     3,   244,    87,
     246,   237,   248,    81,   250,     3,   252,   253,   254,    11,
     256,  1135,   258,     7,   260,    11,   262,   171,   264,     4,
     266,     4,   268,  1147,   270,     4,   272,     3,   274,     3,
     276,    67,   278,   109,   280,     7,   282,    89,   284,   108,
     286,   630,   288,     3,   290,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     7,   701,    10,    11,    10,
      11,    10,    11,    10,    11,  1189,     3,   712,   713,    10,
      11,    10,    11,     3,  1198,    10,    11,    10,    11,    10,
      11,   954,   720,   292,     4,   294,    36,   296,     3,   298,
      38,   300,     3,   302,     3,   304,    42,   306,     3,   308,
      44,   310,     3,   312,     3,   314,    46,   316,   257,   318,
       4,   320,    55,   322,   169,    10,    11,     3,  1242,    10,
      11,    10,    11,    10,    11,    10,    11,  1251,    10,    11,
      10,    11,    10,    11,    10,    11,   163,   164,   783,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   738,
    1023,    57,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,  1300,    10,    11,    10,
      11,   819,    10,    11,     3,  1309,    10,    11,    10,    11,
     247,     3,  1316,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     7,     7,   249,   255,   261,   281,   265,
     263,   269,   271,   279,   325,   287,     3,   291,   131,   796,
      21,   289,     3,     3,     7,  1349,     3,     3,     3,     7,
       3,   156,    48,     7,  1358,     7,     7,     7,     7,     3,
      50,     3,   831,   243,   239,     3,   245,     3,   241,   283,
     895,     4,   285,     3,   293,     4,     3,     3,   323,   321,
       4,   301,   305,   181,     4,     3,    11,   317,  1392,    11,
      11,     7,     3,     3,     3,     3,     3,  1401,     3,     3,
       3,     3,   170,     3,     3,    11,     3,     3,     3,     3,
       3,   259,     4,   319,   295,     3,     7,     7,     7,   303,
     307,   313,     3,     3,   309,     3,   114,     3,    73,     4,
    1434,     3,     3,     3,     3,     3,     3,  1441,   161,   198,
       3,     7,   267,     7,   297,     7,    11,     7,     7,     7,
       7,     7,     3,     3,     3,  1459,     3,     3,     3,     3,
     978,   986,   238,   299,   240,    18,   242,   110,   244,   115,
     246,     3,   248,     3,   250,     3,   252,     3,   254,     4,
     256,     3,   258,     7,   260,   165,   262,     7,   264,     7,
     266,     7,   268,     7,   270,     7,   272,   273,   274,   238,
     276,   240,   278,   242,   280,   244,   282,   246,   284,   248,
     286,   250,   288,   252,   290,   254,     3,   256,    56,   258,
     223,   260,    58,   262,     7,   264,   166,   266,     3,   268,
     208,   270,     3,   272,     3,   274,   275,   276,   238,   278,
     240,   280,   242,   282,   244,   284,   246,   286,   248,   288,
     250,   290,   252,   224,   254,     3,   256,     3,   258,     3,
     260,     3,   262,     3,   264,     3,   266,    78,   268,     3,
     270,     3,   272,   116,   274,    11,   276,   277,   278,   238,
     280,   240,   282,   242,   284,   244,   286,   246,   288,   248,
     290,   250,    85,   252,     7,   254,     7,   256,     7,   258,
       7,   260,     3,   262,     3,   264,     3,   266,   267,   268,
     238,   270,   240,   272,   242,   274,   244,   276,   246,   278,
     248,   280,   250,   282,   252,   284,   254,   286,   256,   288,
     258,   290,   260,     3,   262,     3,   264,     3,   266,     3,
     268,     3,   270,   226,   272,   315,   274,   117,   276,   210,
     278,    11,   280,     3,   282,     3,   284,    83,   286,    11,
     288,     7,   290,     7,     3,     3,     3,     3,    11,    11,
     212,   200,     7,     3,   117,     4,     7,   124,     3,     7,
       3,   118,     3,    91,     3,     3,    86,     7,   162,     3,
       3,   200,     7,   216,    11,     3,   204,     3,     3,   118,
       7,   126,    18,     7,   119,     3,     3,   167,     7,   214,
      11,     7,   200,   204,   199,     3,   206,     3,   225,  1456,
       3,     3,   128,    18,   119,     3,     7,     7,     3,   197,
     209,   204,    11,   200,   206,   201,     7,   125,   227,     3,
       3,    18,     3,    11,   200,   204,   211,   201,   206,   161,
     205,     3,     7,   127,     3,   200,   213,   206,   129,   173,
     201,   166,     7,  1500,     7,   204,     3,     7,   164,     3,
     205,   162,   166,   204,   207,    11,  1513,   206,   201,   207,
     201,   205,   167,     3,   206,   205,     3,   217,   215,   207,
     207,   201,   167,     7,   327,     3,     3,     3,    11,   903,
       3,   205,   205,     7,   299,   207,  1028,  1093,  1163,   831,
    1206,   831,  1266,  1270,  1271,   831,  1329,   831,   831,   831,
    1323,  1378,    -1,   221,    -1,   448,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1382,  1383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1482
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    24,   333,   337,    26,   338,     0,   233,   858,   859,
       3,   339,    29,   349,   350,   235,   860,     7,    25,    27,
     340,   341,    32,   356,   357,    31,   351,   549,     3,   861,
       3,   343,    66,   424,   425,    34,   358,   550,     3,    10,
      11,   352,   353,   354,     7,   234,   236,   862,   863,    11,
      10,    11,    18,    19,    20,   327,   342,   344,   345,   346,
     347,   348,   105,   492,   493,    10,    11,   426,   427,   428,
       3,    10,    11,   359,   360,   361,     7,   355,     3,    18,
     864,    28,     3,     3,     3,     3,    13,    14,   334,    10,
      11,   494,   495,   496,    69,   429,   430,     7,   362,     3,
      30,   168,   604,   605,    11,     3,    11,     7,     7,     7,
     578,   580,    12,   335,   336,   106,   107,   497,   498,   541,
     542,    74,   443,   444,    71,   431,   553,     3,    33,    35,
      37,    41,    43,    45,    47,    49,   363,   364,   365,   370,
     371,   376,   377,   382,   383,   388,   389,   394,   395,   409,
     410,   606,   607,     7,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   272,   274,   276,   278,   280,   282,   284,   286,   288,
     290,   865,   866,   869,   872,   874,   876,   878,   880,   882,
     884,   886,   888,   890,   892,   894,   896,   898,   900,   902,
     904,   906,   908,   918,   926,   929,   932,   935,   938,     3,
       3,     3,     3,     7,     8,   328,   329,   330,   331,   581,
     106,   111,   499,   106,   130,    79,   465,   466,    76,   445,
     554,     3,    10,    11,   432,   433,   434,   366,   367,   372,
     373,   378,   379,   384,   385,   390,   391,   396,   397,   411,
     412,    10,    11,   612,   613,   614,    21,    22,   177,   182,
     183,   608,   609,   610,   611,   847,   849,     3,   883,   875,
     877,   881,   885,   887,   927,   939,   895,   879,   901,   889,
     891,   893,   919,   897,   899,   933,   930,   936,   867,   870,
     873,   909,   903,   905,   907,   237,   580,   580,     3,   500,
     501,   502,   544,    87,   483,   484,    81,   467,   555,     3,
      10,    11,   446,   447,   448,     7,   436,    10,    11,   369,
      21,   182,   183,   368,   551,   552,   558,    10,    11,   375,
     374,   551,   552,   558,    10,    11,   381,    59,    60,    61,
     380,   551,   552,   558,   560,   561,   562,    10,    11,   387,
      62,    63,   386,   551,   552,   558,   560,   561,   563,   564,
      10,    11,   393,    65,   392,   551,   552,   558,   565,    11,
     399,   398,   551,   552,   558,    11,   414,   413,   551,   552,
     558,   171,   615,   616,   617,     4,     4,     4,     3,     3,
     865,   865,   865,   865,   865,   865,   928,   940,   865,   865,
     865,   865,   865,   865,   922,   865,   865,   934,   931,   937,
      10,    11,   868,    10,    11,   871,   865,   911,   292,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   322,   941,   942,   943,   945,   946,   948,
     949,   951,   952,   954,   955,   957,   958,   961,   962,   966,
     967,   969,   970,   972,   973,   975,   976,   978,   979,   981,
     984,   985,   987,   988,   990,   991,   941,   941,     7,   108,
     501,   109,    10,    11,   112,   113,   543,   545,   547,   548,
      67,    89,   485,   557,     3,    10,    11,   468,   469,   470,
       7,   450,     3,    70,    72,   435,   437,   438,    36,     4,
       3,     3,    38,    42,     3,     3,     3,    44,     3,     3,
      46,     4,    55,   400,   401,    57,   415,   416,   169,   634,
     618,   619,     3,     3,     3,     7,     7,   865,   865,   865,
     865,   247,   249,   251,   865,   253,   865,   255,   257,   865,
     261,   263,   265,    10,    11,    18,   327,   920,   923,   924,
     925,   269,   271,   273,   865,   275,   865,   277,   865,   279,
     281,   865,    10,    11,    22,    23,   326,   910,   912,   913,
     915,   917,   982,   287,    18,    92,   566,   941,   947,   941,
     950,   865,   953,   941,   956,   325,   959,   965,   963,   965,
      10,    11,   968,   941,   971,   941,   974,   941,   977,   941,
     980,   865,   986,   865,   989,   941,   992,   289,   291,     3,
      21,   503,   131,     3,     3,     3,    10,    11,   486,   487,
     488,     7,   472,     3,    75,    77,   449,   451,   452,   439,
     440,     3,     7,     7,   578,     7,     7,     7,     7,     3,
      48,   408,   156,   402,   848,    50,   423,   417,   848,   174,
     196,   222,   635,   636,   637,   812,   813,   815,   816,    10,
      11,   633,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,     3,     3,   239,   241,   243,
     245,   865,   267,   865,     3,     3,   283,   285,     4,     3,
       4,   983,     3,     3,    10,    11,   944,   293,   941,   321,
     323,     4,    11,    11,   301,   941,   305,   941,   941,   941,
     865,   317,    11,     4,    10,    11,   504,   578,   578,     7,
     489,     3,    80,    82,   471,   473,   474,   453,   454,    10,
      11,   442,    68,    93,    94,    95,    96,    97,    98,   441,
     558,   567,   569,   570,   571,   573,   574,   575,   847,   849,
       3,     3,     3,     3,     3,     3,     3,     3,    10,    11,
     403,   404,   405,    10,    11,   418,   419,   420,    10,    11,
     638,   639,   640,    11,   181,   817,   846,   170,     3,     3,
       3,     3,     3,     3,     3,     3,     4,   259,   921,     7,
     578,   914,   578,   916,   311,   941,     7,     7,   319,   295,
       3,   941,   960,   941,   964,   303,   307,   309,   313,   865,
       3,   114,   505,   506,     3,     3,     3,    88,    90,   490,
     475,   476,    10,    11,   456,   457,   458,    84,    99,   101,
     102,   103,   455,   556,   558,   559,   568,   572,   573,   576,
     847,   849,    73,     4,     3,     3,     3,     3,     3,     3,
       7,   161,   406,   582,   583,   590,   421,   582,   198,   642,
     643,   941,     3,    11,   818,     7,     7,     7,     7,     7,
       7,     7,   578,   579,   580,   267,     3,     3,     3,     3,
       3,     3,     3,   297,   299,   865,   507,   110,   115,   518,
      18,   491,    10,    11,   478,   479,   480,   100,   477,   556,
     558,   559,   567,   569,   570,   571,   573,   577,   847,   849,
     459,   461,     3,     3,     3,     3,     4,     3,     7,     7,
       7,     7,     7,     7,     3,   165,   852,    56,   407,   166,
     584,   585,    58,   422,   208,   667,   668,   644,   645,   223,
     814,     7,   224,   820,   821,     3,     3,     3,     3,     3,
       3,     3,     3,     3,   941,    10,    11,   120,   123,   508,
     509,   510,   511,   512,   519,   116,   530,     3,    11,   461,
     481,     3,    78,   460,    85,   462,   463,     7,     7,     7,
       7,     3,     3,     3,     3,     3,     3,     3,     3,    10,
      11,   591,   592,   593,   586,   587,   210,   692,   693,   669,
     670,    11,   184,   228,   229,   646,   850,   855,   856,   857,
       3,   226,   827,   828,   822,   848,   315,   117,   513,   514,
     515,     3,     3,    10,    11,   121,   123,   520,   521,   522,
     523,   524,   531,     7,   865,    83,   482,     7,    11,   941,
       3,     3,     3,     3,     7,     5,   162,    11,   589,   163,
     164,   588,   853,   854,   212,   732,   733,   694,   695,    11,
     671,   850,   855,   200,   647,   649,   650,     3,     4,   834,
     829,   848,    10,    11,   823,   824,   825,   117,   514,   124,
       7,     7,   118,   525,   526,   527,     3,     3,    10,    11,
     122,   123,   532,   533,   534,   535,   546,     3,    91,     3,
      86,   464,     3,   162,     7,     3,     3,   216,   787,   788,
     734,   735,    11,   696,   850,   855,   200,   672,   674,   675,
     204,   648,   655,   656,    10,    11,   651,   652,   653,     7,
       3,   172,   175,   819,   835,   836,    10,    11,   830,   831,
     832,   582,   826,    18,   516,     3,     3,   118,   526,   126,
       7,     7,   119,   536,   537,   538,     3,     3,   167,     7,
       7,   214,   762,   763,   789,   790,    11,   736,   850,   855,
     200,   697,   699,   700,   204,   673,   680,   681,    10,    11,
     676,   677,   678,   199,   206,   661,   662,    10,    11,   657,
     658,   659,   582,   654,     3,   837,   838,   582,   833,   225,
       3,    10,    11,   517,    18,   528,     3,     3,   119,   537,
     128,     7,     7,     3,     3,   197,   641,   764,   765,    11,
     791,   850,   855,   200,   737,   739,   740,   204,   698,   705,
     706,    10,    11,   701,   702,   703,   209,   206,   686,   687,
      10,    11,   682,   683,   684,   582,   679,    10,    11,   663,
     664,   665,   582,   660,   201,    10,    11,   842,   843,   844,
     230,   231,   609,   839,   840,   841,   227,     7,   125,     3,
      10,    11,   529,    18,   539,     3,     3,    11,   766,   850,
     855,   200,   792,   794,   795,   204,   738,   745,   746,    10,
      11,   741,   742,   743,   211,   206,   711,   712,    10,    11,
     707,   708,   709,   582,   704,    10,    11,   688,   689,   690,
     582,   685,   201,   161,   594,   595,   600,   666,   205,   616,
     845,   579,   579,     3,     7,   127,     3,    10,    11,   540,
     200,   767,   769,   770,   204,   793,   800,   801,    10,    11,
     796,   797,   798,   213,   206,   751,   752,    10,    11,   747,
     748,   749,   582,   744,    10,    11,   713,   714,   715,   582,
     710,   201,   582,   691,   205,   852,   166,   596,   597,   207,
     634,   173,     7,     7,     3,     7,   129,   204,   768,   775,
     776,    10,    11,   771,   772,   773,   217,   206,   806,   807,
      10,    11,   802,   803,   804,   582,   799,    10,    11,   753,
     754,   755,   582,   750,   201,   716,   717,   205,   207,    10,
      11,   601,   602,   603,   598,   854,   579,   579,     3,   215,
     206,   781,   782,    10,    11,   777,   778,   779,   582,   774,
      10,    11,   808,   809,   810,   582,   805,   201,   756,   205,
     207,   166,   718,   719,     5,   162,    11,   599,    10,    11,
     783,   784,   785,   582,   780,   201,   582,   811,   205,   166,
     207,   757,   758,   720,   721,   162,   578,   582,   786,   205,
     207,    10,    11,   759,   760,   761,    10,    11,   724,   725,
     726,   180,   185,   722,   723,   851,   167,   207,   865,   727,
       3,     3,   167,   167,   220,   728,   729,   578,     7,   327,
     730,     3,     3,     3,    11,   731,   578,     7,     3,   221
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
    if (osglData->matrixCounter < osglData->numberOfMatrices) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer matrices than specified");
    osinstance->instanceData->matrices->numberOfMatrices = osglData->numberOfMatrices;
    osinstance->instanceData->matrices->matrix = osglData->matrix;
}
    break;

  case 30:

    {
    if (osglData->numberOfMatrices < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices cannot be negative");
    else
        osglData->matrix = new OSMatrix*[osglData->numberOfMatrices];
}
    break;

  case 38:

    {
    if (parserData->coneCounter < parserData->numberOfCones) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer cones than specified");
}
    break;

  case 39:

    {
    parserData->coneCounter = 0;
}
    break;

  case 40:

    {
    if (parserData->numberOfCones < 0) parserData->parser_errors +=
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfCones cannot be negative");
    else
        osinstance->instanceData->cones->cone = new Cone*[parserData->numberOfCones];
}
    break;

  case 44:

    {
}
    break;

  case 46:

    {
    parserData->coneCounter++;
    osinstance->instanceData->cones->numberOfCones = parserData->coneCounter;
}
    break;

  case 55:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonnegativeCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonnegative;    
}
    break;

  case 59:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 60:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 61:

    {
            ((NonnegativeCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 65:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new NonpositiveCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_nonpositive;    
}
    break;

  case 69:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 70:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 71:

    {
            ((NonpositiveCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 75:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->axisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new QuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_quadratic;    
}
    break;

  case 79:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 80:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 81:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 82:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    break;

  case 83:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    break;

  case 84:

    {
            ((QuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->axisDirection
                = parserData->axisDirection;
        }
    break;

  case 88:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    parserData->normScaleFactorPresent = false;
    parserData->distortionMatrixPresent = false;
    parserData->firstAxisDirectionPresent = false;
    parserData->secondAxisDirectionPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new RotatedQuadraticCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_rotatedQuadratic;    
}
    break;

  case 92:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 93:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 94:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name
                = parserData->name;
        }
    break;

  case 95:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->distortionMatrixIdx
                = parserData->distortionMatrix;
        }
    break;

  case 96:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->normScaleFactor
                = parserData->normScaleFactor;
        }
    break;

  case 97:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->firstAxisDirection
                = parserData->firstAxisDirection;
        }
    break;

  case 98:

    {
            ((RotatedQuadraticCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->secondAxisDirection
                = parserData->secondAxisDirection;
        }
    break;

  case 102:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    parserData->semidefinitenessPresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new SemidefiniteCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_semidefinite;    
}
    break;

  case 106:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 107:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 108:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 109:

    {
            ((SemidefiniteCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->semidefiniteness
                = parserData->semidefiniteness;
        }
    break;

  case 113:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new ProductCone();
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_product;    
}
    break;

  case 117:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 118:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 119:

    {
            ((ProductCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 122:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 123:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 129:

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

  case 132:

    {
    parserData->numberOfRowsPresent = false;
    parserData->numberOfColumnsPresent = false;
    parserData->namePresent = false;
    osinstance->instanceData->cones->cone[parserData->coneCounter] = new IntersectionCone();    
    osinstance->instanceData->cones->cone[parserData->coneCounter]->coneType = ENUM_CONE_TYPE_intersection;    
}
    break;

  case 136:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfRows
                = parserData->numberOfRows;
        }
    break;

  case 137:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->numberOfColumns
                = parserData->numberOfColumns;
        }
    break;

  case 138:

    {
            ((IntersectionCone*)osinstance->instanceData->cones->cone[parserData->coneCounter])->name = parserData->name;
        }
    break;

  case 141:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 142:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 148:

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

  case 294:

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

  case 307:

    {
        parserData->stageConstraintsON = true;
    }
    break;

  case 312:

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

  case 313:

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
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
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
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfMatricesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfMatrices attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <matrix> elements cannot be negative");
    parserData->numberOfMatricesPresent = true;
    osglData->numberOfMatrices = (yyvsp[(3) - (4)].ival);
}
    break;

  case 355:

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

  case 356:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of rows cannot be negative");
    parserData->numberOfRowsPresent = true;
    parserData->numberOfRows = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 357:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of columns cannot be negative");
    parserData->numberOfColumnsPresent = true;
    parserData->numberOfColumns = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 358:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix variables cannot be negative");
    parserData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 359:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix objectives cannot be negative");
    parserData->numberOfMatrixObj = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 360:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix constraints cannot be negative");
    parserData->numberOfMatrixCon = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 361:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of matrix terms cannot be negative");
    parserData->numberOfMatrixTerms = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 362:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
    parserData->numberOfMatrixExpr = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 363:

    {
    if (parserData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "name attribute previously set");
    parserData->namePresent = true;
    parserData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 364:

    {
    if (parserData->shapePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "shape attribute previously set");
    parserData->shapePresent = true;
    parserData->shape = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 365:

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

  case 366:

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

  case 367:

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

  case 368:

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

  case 369:

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

  case 370:

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

  case 371:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->matrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index cannot be negative");
    parserData->matrixIdxAttributePresent = true;
    parserData->matrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 372:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->lbMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lbMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lower bounding matrix index cannot be negative");
    parserData->lbMatrixIdxAttributePresent = true;
    parserData->lbMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 373:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->constantMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "constantMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index cannot be negative");
    parserData->constantMatrixIdxAttributePresent = true;
    parserData->constantMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 374:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->lbConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lbConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "lower bounding cone index cannot be negative");
    parserData->lbConeIdxAttributePresent = true;
    parserData->lbConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 375:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->ubMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "upper bounding matrix index cannot be negative");
    parserData->ubMatrixIdxAttributePresent = true;
    parserData->ubMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 376:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->ubConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "upper bounding cone index cannot be negative");
    parserData->ubConeIdxAttributePresent = true;
    parserData->ubConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 377:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->orderConeIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "ubConeIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "order cone index cannot be negative");
    parserData->orderConeIdxAttributePresent = true;
    parserData->orderConeIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 378:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->templateMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "templateMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "template matrix index cannot be negative");
    parserData->templateMatrixIdxAttributePresent = true;
    parserData->templateMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 379:

    {
    if (parserData->varTypeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType attribute previously set");
    parserData->varTypeAttributePresent = true;
    if ((yyvsp[(2) - (3)].sval) != "true" && (yyvsp[(2) - (3)].sval) != "false")
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varType must be one of C, B, I, S, D, J");
    else
        parserData->varType = *((yyvsp[(2) - (3)].sval));
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 380:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->varReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "varReference matrix index cannot be negative");
    parserData->varReferenceMatrixIdxAttributePresent = true;
    parserData->varReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 381:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->objReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "objReference matrix index cannot be negative");
    parserData->objReferenceMatrixIdxAttributePresent = true;
    parserData->objReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 382:

    {
    if (*(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval)) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "mismatched quotes");
    if (parserData->conReferenceMatrixIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReferenceMatrixIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "conReference matrix index cannot be negative");
    parserData->conReferenceMatrixIdxAttributePresent = true;
    parserData->conReferenceMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 383:

    {parserData->tempVal = (yyvsp[(2) - (3)].ival);}
    break;

  case 384:

    {parserData->tempVal = (yyvsp[(2) - (3)].dval);}
    break;

  case 392:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 397:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 403:

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

  case 409:

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

  case 410:

    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 415:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 418:

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

  case 424:

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

  case 425:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 426:

    {
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

  case 427:

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

  case 435:

    { 
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 436:

    { 
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 437:

    {
    if (osglData->matrixTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->matrixTypeAttributePresent = true;   
    osglData->matrixTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 441:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 444:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 445:

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

  case 446:

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

  case 458:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    ((MatrixType*)osglData->mtxBlkVec.back())->matrixType  = 
        mergeMatrixType(((MatrixType*)osglData->mtxBlkVec.back())->matrixType, osglData->matrix[(yyvsp[(3) - (4)].ival)]->matrixType);
    osglData->baseMatrixIdxAttributePresent = true;   
    osglData->baseMatrixIdxAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 459:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 460:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 461:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 462:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 463:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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

  case 464:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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

  case 465:

    { 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
}
    break;

  case 468:

    {
    osglData->baseTransposeAttribute = true;
}
    break;

  case 469:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTransposeAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTransposeAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 470:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
}
    break;

  case 474:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 479:

    {
    osglData->tempC = new MatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
}
    break;

  case 487:

    {
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 488:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 491:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 492:

    {
        ((MatrixElements*)osglData->tempC)->constantElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 496:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 497:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 503:

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

  case 504:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 510:

    {
    ((MatrixElements*)osglData->tempC)->constantElements->values = new DoubleVector();
    ((MatrixElements*)osglData->tempC)->constantElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->values->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 511:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 519:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements = new VarReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 520:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 523:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 524:

    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 528:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 529:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 535:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 536:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 542:

    {
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 543:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 551:

    {
    ((MatrixElements*)osglData->tempC)->linearElements = new LinearMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 552:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 555:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 556:

    {
        ((MatrixElements*)osglData->tempC)->linearElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 560:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 561:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 567:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 568:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 574:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "expected <values> element");
    }
    break;

  case 575:

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

  case 576:

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
}
    break;

  case 584:

    {
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
        
}
    break;

  case 585:

    {
    osglData->numberOfVarIdxAttributePresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 586:

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

  case 591:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
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

  case 599:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 601:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 602:

    {
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 605:

    {
    ((MatrixElements*)osglData->tempC)->generalElements = new GeneralMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 606:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 609:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 610:

    {
        ((MatrixElements*)osglData->tempC)->generalElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 614:

    {
    ((MatrixElements*)osglData->tempC)->generalElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 615:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 621:

    {
    ((MatrixElements*)osglData->tempC)->generalElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 622:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 630:

    {
    osglData->osglNonzeroCounter = 0;
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;

    ((MatrixElements*)osglData->tempC)->generalElements->values = new GeneralMatrixValues();
    ((MatrixElements*)osglData->tempC)->generalElements->values->numberOfEl = osglData->osglNumberOfNonzeros;
    ((MatrixElements*)osglData->tempC)->generalElements->values->el
        = new OSExpressionTree*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((MatrixElements*)osglData->tempC)->generalElements->values->el[i] = new OSExpressionTree();
}
    break;

  case 638:

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

  case 642:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((MatrixElements*)osglData->tempC)->generalElements->values->el[osglData->osglNonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->osglNonzeroCounter++;
    }
    break;

  case 645:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements = new ConReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 646:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 649:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 650:

    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 654:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 655:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 661:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 662:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 668:

    {
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 669:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 677:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements = new ObjReferenceMatrixElements();
    osglData->numberOfValuesAttributePresent = false;        
    osglData->rowMajorAttributePresent = false;
    osglData->rowMajorAttribute = false;
}
    break;

  case 678:

    {
    if (osglData->numberOfValuesAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 681:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 682:

    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->rowMajor = osglData->rowMajorAttribute;
    }
    break;

  case 686:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 687:

    {
    if (osglData->rowMajorAttribute == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
}
    break;

  case 693:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 694:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 700:

    {
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 701:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 707:

    {
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
}
    break;

  case 708:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);

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

  case 709:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 710:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;
    osglData->colOffsets.back() = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 711:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfBlocksAttributePresent = false;
}
    break;

  case 712:

    {
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks    = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->m_mChildren       = new MatrixNode*[osglData->numberOfBlocks];
}
    break;

  case 715:

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

  case 716:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 717:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 723:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
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

  case 733:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 734:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryAttributePresent = false;
    osglData->blockRowIdxAttributePresent = false;
    osglData->blockColIdxAttributePresent = false;   
}
    break;

  case 740:

    {
        if (verifyMatrixSymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 741:

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

  case 742:

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

  case 746:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 748:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 749:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 750:

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

  case 751:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 752:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesAttributePresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 753:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxAttributePresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 754:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 755:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 756:

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

  case 759:

    {
    if (osglData->rowMajorAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajorAttribute = true;
    osglData->rowMajorAttributePresent = true;
}
    break;

  case 760:

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

  case 762:

    {  
        if (osnlData->nlnodecount < osnlData->tmpnlcount)  
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    }
    break;

  case 763:

    {               
//    osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
}
    break;

  case 764:

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

  case 767:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->nlnodecount++;
    }
    break;

  case 768:

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

  case 769:

    { 
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
        //osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount] = new Nl();
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree = new OSExpressionTree();
    }
    break;

  case 797:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 801:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 805:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 807:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 809:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 811:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 813:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 815:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 817:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 819:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 821:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 823:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 825:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 827:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 829:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 830:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 831:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 832:

    {
}
    break;

  case 833:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 834:

    {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 835:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 837:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 839:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 841:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 842:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 850:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 852:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 854:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 855:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 856:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 859:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 863:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 864:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 865:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 866:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
    if ( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "variable index exceeds number of variables");
}
    break;

  case 867:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 868:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 870:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 871:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 872:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 874:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 875:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 876:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 878:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 879:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 880:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->nlnodecount]->osExpressionTree->bADMustReTape = true;
}
    break;

  case 882:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 883:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 884:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 886:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 903:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 904:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 907:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    if( (yyvsp[(3) - (4)].ival) >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix index exceeds number of matrices");
    
}
    break;

  case 909:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 912:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 915:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 918:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 921:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 923:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 926:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 928:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 930:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 932:

    {
     parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 936:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 939:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 942:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 945:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 947:

    {
//    osnlData->nlNodePoint = new OSnLNodeProduct();
//    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
//    osnlData->mtxProdVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 948:

    {
//    osnlData->mtxProdVec.back()->m_mChildren = new OSnLNode*[ osnlData->mtxProdVec.back()->inumberOfMatrixChildren];
//    osnlData->mtxProdVec.pop_back();
}
    break;

  case 950:

    { /*osnlData->mtxProdVec.back()->inumberOfMatrixChildren++; */}
    break;

  case 952:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 955:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 958:

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


