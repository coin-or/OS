
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
#define yyparse         osrlparse
#define yylex           osrllex
#define yyerror         osrlerror
#define yylval          osrllval
#define yychar          osrlchar
#define yydebug         osrldebug
#define yynerrs         osrlnerrs
#define yylloc          osrllloc

/* Copy the first part of user declarations.  */



 
#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string (const char *yy_str , void* yyscanner  );
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* yyscanner );
int osrlget_lineno( void* yyscanner);
char *osrlget_text (void* yyscanner );
void osrlset_lineno (int line_number , void* yyscanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osrl_empty_vectors( OSrLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);






/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
     GREATERTHAN = 265,
     ENDOFELEMENT = 266,
     OSRLSTART = 267,
     OSRLSTARTEMPTY = 268,
     OSRLATTRIBUTETEXT = 269,
     OSRLEND = 270,
     NUMBEROFCONATT = 271,
     NUMBEROFCONSTRAINTSATT = 272,
     NUMBEROFELATT = 273,
     NUMBEROFENUMERATIONSATT = 274,
     NUMBEROFIDXATT = 275,
     NUMBEROFITEMSATT = 276,
     NUMBEROFOBJATT = 277,
     NUMBEROFOBJECTIVESATT = 278,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 279,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 280,
     NUMBEROFOTHERRESULTSATT = 281,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 282,
     NUMBEROFOTHERVARIABLERESULTSATT = 283,
     NUMBEROFSOLUTIONSATT = 284,
     NUMBEROFSOLVEROUTPUTSATT = 285,
     NUMBEROFSUBSTATUSESATT = 286,
     NUMBEROFTIMESATT = 287,
     NUMBEROFVARATT = 288,
     NUMBEROFVARIABLESATT = 289,
     NUMBEROFVARIDXATT = 290,
     TARGETOBJECTIVEIDXATT = 291,
     IDXATT = 292,
     INCRATT = 293,
     MULTATT = 294,
     SIZEOFATT = 295,
     CATEGORYATT = 296,
     EMPTYCATEGORYATT = 297,
     DESCRIPTIONATT = 298,
     EMPTYDESCRIPTIONATT = 299,
     NAMEATT = 300,
     EMPTYNAMEATT = 301,
     TYPEATT = 302,
     EMPTYTYPEATT = 303,
     CONTYPEATT = 304,
     EMPTYCONTYPEATT = 305,
     ENUMTYPEATT = 306,
     EMPTYENUMTYPEATT = 307,
     OBJTYPEATT = 308,
     EMPTYOBJTYPEATT = 309,
     VARTYPEATT = 310,
     EMPTYVARTYPEATT = 311,
     UNITATT = 312,
     EMPTYUNITATT = 313,
     VALUEATT = 314,
     EMPTYVALUEATT = 315,
     WEIGHTEDOBJECTIVESATT = 316,
     EMPTYWEIGHTEDOBJECTIVESATT = 317,
     TARGETOBJECTIVENAMEATT = 318,
     EMPTYTARGETOBJECTIVENAMEATT = 319,
     HEADERSTART = 320,
     HEADEREND = 321,
     GENERALSTART = 322,
     GENERALEND = 323,
     SYSTEMSTART = 324,
     SYSTEMEND = 325,
     SERVICESTART = 326,
     SERVICEEND = 327,
     JOBSTART = 328,
     JOBEND = 329,
     OPTIMIZATIONSTART = 330,
     OPTIMIZATIONEND = 331,
     ITEMSTART = 332,
     ITEMEND = 333,
     ITEMSTARTANDEND = 334,
     ITEMEMPTY = 335,
     FILENAMESTART = 336,
     FILENAMEEND = 337,
     FILENAMEEMPTY = 338,
     FILENAMESTARTANDEND = 339,
     FILESOURCESTART = 340,
     FILESOURCEEND = 341,
     FILESOURCEEMPTY = 342,
     FILESOURCESTARTANDEND = 343,
     FILEDESCRIPTIONSTART = 344,
     FILEDESCRIPTIONEND = 345,
     FILEDESCRIPTIONEMPTY = 346,
     FILEDESCRIPTIONSTARTANDEND = 347,
     FILECREATORSTART = 348,
     FILECREATOREND = 349,
     FILECREATOREMPTY = 350,
     FILECREATORSTARTANDEND = 351,
     FILELICENCESTART = 352,
     FILELICENCEEND = 353,
     FILELICENCEEMPTY = 354,
     FILELICENCESTARTANDEND = 355,
     ACTUALSTARTTIMESTART = 356,
     ACTUALSTARTTIMEEND = 357,
     ATEQUALITYSTART = 358,
     ATEQUALITYEND = 359,
     ATLOWERSTART = 360,
     ATLOWEREND = 361,
     ATUPPERSTART = 362,
     ATUPPEREND = 363,
     AVAILABLECPUNUMBERSTART = 364,
     AVAILABLECPUNUMBEREND = 365,
     AVAILABLECPUSPEEDSTART = 366,
     AVAILABLECPUSPEEDEND = 367,
     AVAILABLEDISKSPACESTART = 368,
     AVAILABLEDISKSPACEEND = 369,
     AVAILABLEMEMORYSTART = 370,
     AVAILABLEMEMORYEND = 371,
     BASE64START = 372,
     BASE64END = 373,
     BASICSTART = 374,
     BASICEND = 375,
     BASISSTATUSSTART = 376,
     BASISSTATUSEND = 377,
     BASSTATUSSTART = 378,
     BASSTATUSEND = 379,
     CONSTART = 380,
     CONEND = 381,
     CONSTRAINTSSTART = 382,
     CONSTRAINTSEND = 383,
     CURRENTJOBCOUNTSTART = 384,
     CURRENTJOBCOUNTEND = 385,
     CURRENTSTATESTART = 386,
     CURRENTSTATEEND = 387,
     DUALVALUESSTART = 388,
     DUALVALUESEND = 389,
     ELSTART = 390,
     ELEND = 391,
     ENUMERATIONSTART = 392,
     ENUMERATIONEND = 393,
     ENDTIMESTART = 394,
     ENDTIMEEND = 395,
     GENERALSTATUSSTART = 396,
     GENERALSTATUSEND = 397,
     GENERALSUBSTATUSSTART = 398,
     GENERALSUBSTATUSEND = 399,
     IDXSTART = 400,
     IDXEND = 401,
     INSTANCENAMESTART = 402,
     INSTANCENAMEEND = 403,
     ISFREESTART = 404,
     ISFREEEND = 405,
     JOBIDSTART = 406,
     JOBIDEND = 407,
     MESSAGESTART = 408,
     MESSAGEEND = 409,
     OBJSTART = 410,
     OBJEND = 411,
     OBJECTIVESSTART = 412,
     OBJECTIVESEND = 413,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 414,
     OPTIMIZATIONSOLUTIONSTATUSEND = 415,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 416,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 417,
     OTHERSTART = 418,
     OTHEREND = 419,
     OTHERRESULTSSTART = 420,
     OTHERRESULTSEND = 421,
     OTHERSOLUTIONRESULTSTART = 422,
     OTHERSOLUTIONRESULTEND = 423,
     OTHERSOLUTIONRESULTSSTART = 424,
     OTHERSOLUTIONRESULTSEND = 425,
     OTHERSOLVEROUTPUTSTART = 426,
     OTHERSOLVEROUTPUTEND = 427,
     SCHEDULEDSTARTTIMESTART = 428,
     SCHEDULEDSTARTTIMEEND = 429,
     SERVICENAMESTART = 430,
     SERVICENAMEEND = 431,
     SERVICEURISTART = 432,
     SERVICEURIEND = 433,
     SERVICEUTILIZATIONSTART = 434,
     SERVICEUTILIZATIONEND = 435,
     SOLUTIONSTART = 436,
     SOLUTIONEND = 437,
     SOLVERINVOKEDSTART = 438,
     SOLVERINVOKEDEND = 439,
     SOLVEROUTPUTSTART = 440,
     SOLVEROUTPUTEND = 441,
     STATUSSTART = 442,
     STATUSEND = 443,
     SUBMITTIMESTART = 444,
     SUBMITTIMEEND = 445,
     SUBSTATUSSTART = 446,
     SUBSTATUSEND = 447,
     SUPERBASICSTART = 448,
     SUPERBASICEND = 449,
     SYSTEMINFORMATIONSTART = 450,
     SYSTEMINFORMATIONEND = 451,
     TIMESTART = 452,
     TIMEEND = 453,
     TIMESERVICESTARTEDSTART = 454,
     TIMESERVICESTARTEDEND = 455,
     TIMESTAMPSTART = 456,
     TIMESTAMPEND = 457,
     TIMINGINFORMATIONSTART = 458,
     TIMINGINFORMATIONEND = 459,
     TOTALJOBSSOFARSTART = 460,
     TOTALJOBSSOFAREND = 461,
     UNKNOWNSTART = 462,
     UNKNOWNEND = 463,
     USEDCPUNUMBERSTART = 464,
     USEDCPUNUMBEREND = 465,
     USEDCPUSPEEDSTART = 466,
     USEDCPUSPEEDEND = 467,
     USEDDISKSPACESTART = 468,
     USEDDISKSPACEEND = 469,
     USEDMEMORYSTART = 470,
     USEDMEMORYEND = 471,
     VALUESSTART = 472,
     VALUESEND = 473,
     VALUESSTRINGSTART = 474,
     VALUESSTRINGEND = 475,
     VARSTART = 476,
     VAREND = 477,
     VARIABLESSTART = 478,
     VARIABLESEND = 479,
     VARIDXSTART = 480,
     VARIDXEND = 481,
     MATRIXSTART = 482,
     MATRIXEND = 483,
     BASEMATRIXEND = 484,
     BASEMATRIXSTART = 485,
     BLOCKSTART = 486,
     BLOCKEND = 487,
     BLOCKSSTART = 488,
     BLOCKSEND = 489,
     EMPTYSYMMETRYATT = 490,
     SYMMETRYATT = 491,
     NUMBEROFBLOCKSATT = 492,
     NUMBEROFCOLUMNSATT = 493,
     NUMBEROFROWSATT = 494,
     BASEMATRIXIDXATT = 495,
     TARGETMATRIXFIRSTROWATT = 496,
     TARGETMATRIXFIRSTCOLATT = 497,
     BASEMATRIXSTARTROWATT = 498,
     BASEMATRIXSTARTCOLATT = 499,
     BASEMATRIXENDROWATT = 500,
     BASEMATRIXENDCOLATT = 501,
     SCALARMULTIPLIERATT = 502,
     EMPTYBASETRANSPOSEATT = 503,
     BASETRANSPOSEATT = 504,
     DUMMY = 505
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
#define GREATERTHAN 265
#define ENDOFELEMENT 266
#define OSRLSTART 267
#define OSRLSTARTEMPTY 268
#define OSRLATTRIBUTETEXT 269
#define OSRLEND 270
#define NUMBEROFCONATT 271
#define NUMBEROFCONSTRAINTSATT 272
#define NUMBEROFELATT 273
#define NUMBEROFENUMERATIONSATT 274
#define NUMBEROFIDXATT 275
#define NUMBEROFITEMSATT 276
#define NUMBEROFOBJATT 277
#define NUMBEROFOBJECTIVESATT 278
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 279
#define NUMBEROFOTHEROBJECTIVERESULTSATT 280
#define NUMBEROFOTHERRESULTSATT 281
#define NUMBEROFOTHERSOLUTIONRESULTSATT 282
#define NUMBEROFOTHERVARIABLERESULTSATT 283
#define NUMBEROFSOLUTIONSATT 284
#define NUMBEROFSOLVEROUTPUTSATT 285
#define NUMBEROFSUBSTATUSESATT 286
#define NUMBEROFTIMESATT 287
#define NUMBEROFVARATT 288
#define NUMBEROFVARIABLESATT 289
#define NUMBEROFVARIDXATT 290
#define TARGETOBJECTIVEIDXATT 291
#define IDXATT 292
#define INCRATT 293
#define MULTATT 294
#define SIZEOFATT 295
#define CATEGORYATT 296
#define EMPTYCATEGORYATT 297
#define DESCRIPTIONATT 298
#define EMPTYDESCRIPTIONATT 299
#define NAMEATT 300
#define EMPTYNAMEATT 301
#define TYPEATT 302
#define EMPTYTYPEATT 303
#define CONTYPEATT 304
#define EMPTYCONTYPEATT 305
#define ENUMTYPEATT 306
#define EMPTYENUMTYPEATT 307
#define OBJTYPEATT 308
#define EMPTYOBJTYPEATT 309
#define VARTYPEATT 310
#define EMPTYVARTYPEATT 311
#define UNITATT 312
#define EMPTYUNITATT 313
#define VALUEATT 314
#define EMPTYVALUEATT 315
#define WEIGHTEDOBJECTIVESATT 316
#define EMPTYWEIGHTEDOBJECTIVESATT 317
#define TARGETOBJECTIVENAMEATT 318
#define EMPTYTARGETOBJECTIVENAMEATT 319
#define HEADERSTART 320
#define HEADEREND 321
#define GENERALSTART 322
#define GENERALEND 323
#define SYSTEMSTART 324
#define SYSTEMEND 325
#define SERVICESTART 326
#define SERVICEEND 327
#define JOBSTART 328
#define JOBEND 329
#define OPTIMIZATIONSTART 330
#define OPTIMIZATIONEND 331
#define ITEMSTART 332
#define ITEMEND 333
#define ITEMSTARTANDEND 334
#define ITEMEMPTY 335
#define FILENAMESTART 336
#define FILENAMEEND 337
#define FILENAMEEMPTY 338
#define FILENAMESTARTANDEND 339
#define FILESOURCESTART 340
#define FILESOURCEEND 341
#define FILESOURCEEMPTY 342
#define FILESOURCESTARTANDEND 343
#define FILEDESCRIPTIONSTART 344
#define FILEDESCRIPTIONEND 345
#define FILEDESCRIPTIONEMPTY 346
#define FILEDESCRIPTIONSTARTANDEND 347
#define FILECREATORSTART 348
#define FILECREATOREND 349
#define FILECREATOREMPTY 350
#define FILECREATORSTARTANDEND 351
#define FILELICENCESTART 352
#define FILELICENCEEND 353
#define FILELICENCEEMPTY 354
#define FILELICENCESTARTANDEND 355
#define ACTUALSTARTTIMESTART 356
#define ACTUALSTARTTIMEEND 357
#define ATEQUALITYSTART 358
#define ATEQUALITYEND 359
#define ATLOWERSTART 360
#define ATLOWEREND 361
#define ATUPPERSTART 362
#define ATUPPEREND 363
#define AVAILABLECPUNUMBERSTART 364
#define AVAILABLECPUNUMBEREND 365
#define AVAILABLECPUSPEEDSTART 366
#define AVAILABLECPUSPEEDEND 367
#define AVAILABLEDISKSPACESTART 368
#define AVAILABLEDISKSPACEEND 369
#define AVAILABLEMEMORYSTART 370
#define AVAILABLEMEMORYEND 371
#define BASE64START 372
#define BASE64END 373
#define BASICSTART 374
#define BASICEND 375
#define BASISSTATUSSTART 376
#define BASISSTATUSEND 377
#define BASSTATUSSTART 378
#define BASSTATUSEND 379
#define CONSTART 380
#define CONEND 381
#define CONSTRAINTSSTART 382
#define CONSTRAINTSEND 383
#define CURRENTJOBCOUNTSTART 384
#define CURRENTJOBCOUNTEND 385
#define CURRENTSTATESTART 386
#define CURRENTSTATEEND 387
#define DUALVALUESSTART 388
#define DUALVALUESEND 389
#define ELSTART 390
#define ELEND 391
#define ENUMERATIONSTART 392
#define ENUMERATIONEND 393
#define ENDTIMESTART 394
#define ENDTIMEEND 395
#define GENERALSTATUSSTART 396
#define GENERALSTATUSEND 397
#define GENERALSUBSTATUSSTART 398
#define GENERALSUBSTATUSEND 399
#define IDXSTART 400
#define IDXEND 401
#define INSTANCENAMESTART 402
#define INSTANCENAMEEND 403
#define ISFREESTART 404
#define ISFREEEND 405
#define JOBIDSTART 406
#define JOBIDEND 407
#define MESSAGESTART 408
#define MESSAGEEND 409
#define OBJSTART 410
#define OBJEND 411
#define OBJECTIVESSTART 412
#define OBJECTIVESEND 413
#define OPTIMIZATIONSOLUTIONSTATUSSTART 414
#define OPTIMIZATIONSOLUTIONSTATUSEND 415
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 416
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 417
#define OTHERSTART 418
#define OTHEREND 419
#define OTHERRESULTSSTART 420
#define OTHERRESULTSEND 421
#define OTHERSOLUTIONRESULTSTART 422
#define OTHERSOLUTIONRESULTEND 423
#define OTHERSOLUTIONRESULTSSTART 424
#define OTHERSOLUTIONRESULTSEND 425
#define OTHERSOLVEROUTPUTSTART 426
#define OTHERSOLVEROUTPUTEND 427
#define SCHEDULEDSTARTTIMESTART 428
#define SCHEDULEDSTARTTIMEEND 429
#define SERVICENAMESTART 430
#define SERVICENAMEEND 431
#define SERVICEURISTART 432
#define SERVICEURIEND 433
#define SERVICEUTILIZATIONSTART 434
#define SERVICEUTILIZATIONEND 435
#define SOLUTIONSTART 436
#define SOLUTIONEND 437
#define SOLVERINVOKEDSTART 438
#define SOLVERINVOKEDEND 439
#define SOLVEROUTPUTSTART 440
#define SOLVEROUTPUTEND 441
#define STATUSSTART 442
#define STATUSEND 443
#define SUBMITTIMESTART 444
#define SUBMITTIMEEND 445
#define SUBSTATUSSTART 446
#define SUBSTATUSEND 447
#define SUPERBASICSTART 448
#define SUPERBASICEND 449
#define SYSTEMINFORMATIONSTART 450
#define SYSTEMINFORMATIONEND 451
#define TIMESTART 452
#define TIMEEND 453
#define TIMESERVICESTARTEDSTART 454
#define TIMESERVICESTARTEDEND 455
#define TIMESTAMPSTART 456
#define TIMESTAMPEND 457
#define TIMINGINFORMATIONSTART 458
#define TIMINGINFORMATIONEND 459
#define TOTALJOBSSOFARSTART 460
#define TOTALJOBSSOFAREND 461
#define UNKNOWNSTART 462
#define UNKNOWNEND 463
#define USEDCPUNUMBERSTART 464
#define USEDCPUNUMBEREND 465
#define USEDCPUSPEEDSTART 466
#define USEDCPUSPEEDEND 467
#define USEDDISKSPACESTART 468
#define USEDDISKSPACEEND 469
#define USEDMEMORYSTART 470
#define USEDMEMORYEND 471
#define VALUESSTART 472
#define VALUESEND 473
#define VALUESSTRINGSTART 474
#define VALUESSTRINGEND 475
#define VARSTART 476
#define VAREND 477
#define VARIABLESSTART 478
#define VARIABLESEND 479
#define VARIDXSTART 480
#define VARIDXEND 481
#define MATRIXSTART 482
#define MATRIXEND 483
#define BASEMATRIXEND 484
#define BASEMATRIXSTART 485
#define BLOCKSTART 486
#define BLOCKEND 487
#define BLOCKSSTART 488
#define BLOCKSEND 489
#define EMPTYSYMMETRYATT 490
#define SYMMETRYATT 491
#define NUMBEROFBLOCKSATT 492
#define NUMBEROFCOLUMNSATT 493
#define NUMBEROFROWSATT 494
#define BASEMATRIXIDXATT 495
#define TARGETMATRIXFIRSTROWATT 496
#define TARGETMATRIXFIRSTCOLATT 497
#define BASEMATRIXSTARTROWATT 498
#define BASEMATRIXSTARTCOLATT 499
#define BASEMATRIXENDROWATT 500
#define BASEMATRIXENDCOLATT 501
#define SCALARMULTIPLIERATT 502
#define EMPTYBASETRANSPOSEATT 503
#define BASETRANSPOSEATT 504
#define DUMMY 505




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


std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, const char* errormsg ) ;
void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, std::string errormsg);
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
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
#define YYLAST   1388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  255
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1628

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   505

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   252,
     254,     2,     2,   253,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   251,     2,     2,     2,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    43,    44,
      47,    49,    51,    53,    56,    58,    62,    64,    66,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    91,
      93,    95,    97,   100,   102,   104,   106,   108,   110,   113,
     115,   119,   121,   123,   126,   130,   132,   134,   135,   138,
     140,   142,   145,   147,   150,   152,   154,   156,   159,   161,
     165,   167,   170,   172,   174,   176,   179,   181,   185,   187,
     190,   192,   194,   196,   199,   201,   205,   207,   210,   212,
     214,   216,   219,   221,   225,   227,   230,   232,   234,   236,
     239,   241,   245,   247,   250,   252,   254,   256,   259,   261,
     265,   267,   270,   272,   274,   276,   279,   281,   285,   287,
     291,   293,   295,   297,   299,   302,   304,   308,   310,   312,
     315,   319,   321,   323,   324,   327,   329,   331,   333,   336,
     338,   339,   342,   344,   346,   348,   351,   353,   357,   359,
     361,   364,   366,   368,   370,   372,   374,   376,   379,   381,
     383,   385,   388,   390,   394,   396,   400,   402,   404,   405,
     408,   410,   412,   416,   418,   422,   424,   426,   427,   430,
     432,   434,   438,   440,   444,   446,   448,   449,   452,   454,
     456,   460,   462,   466,   468,   469,   471,   475,   477,   481,
     483,   485,   487,   489,   492,   494,   498,   500,   502,   505,
     509,   511,   513,   514,   517,   519,   521,   523,   526,   528,
     529,   532,   534,   536,   538,   541,   543,   547,   549,   551,
     554,   556,   558,   560,   562,   564,   566,   569,   571,   573,
     575,   578,   580,   584,   586,   589,   591,   593,   595,   598,
     600,   604,   606,   609,   611,   613,   615,   618,   620,   624,
     626,   629,   631,   633,   635,   638,   640,   644,   646,   649,
     651,   653,   655,   658,   660,   664,   666,   670,   672,   674,
     676,   678,   681,   683,   687,   689,   691,   694,   698,   700,
     702,   703,   706,   708,   710,   712,   715,   717,   718,   721,
     723,   725,   727,   730,   732,   736,   738,   740,   743,   745,
     747,   749,   751,   753,   755,   757,   759,   761,   763,   765,
     768,   770,   772,   774,   777,   779,   783,   785,   788,   790,
     792,   794,   797,   799,   803,   805,   808,   810,   812,   814,
     817,   819,   823,   825,   828,   830,   832,   834,   837,   839,
     843,   845,   848,   850,   852,   854,   857,   859,   863,   865,
     869,   871,   873,   875,   877,   880,   882,   886,   888,   890,
     893,   897,   899,   900,   903,   905,   907,   909,   911,   913,
     915,   918,   920,   924,   926,   928,   930,   934,   936,   938,
     939,   942,   944,   946,   950,   952,   956,   958,   960,   961,
     964,   966,   968,   972,   974,   978,   980,   982,   983,   986,
     988,   990,   994,   996,  1000,  1002,  1003,  1005,  1009,  1011,
    1015,  1017,  1019,  1021,  1023,  1026,  1028,  1032,  1034,  1036,
    1039,  1043,  1045,  1047,  1048,  1051,  1053,  1055,  1057,  1060,
    1062,  1063,  1067,  1069,  1071,  1072,  1075,  1077,  1079,  1081,
    1083,  1085,  1087,  1090,  1092,  1096,  1099,  1101,  1104,  1108,
    1110,  1112,  1113,  1116,  1118,  1120,  1122,  1127,  1131,  1135,
    1144,  1148,  1150,  1152,  1154,  1157,  1159,  1161,  1163,  1165,
    1167,  1170,  1172,  1176,  1178,  1180,  1183,  1187,  1189,  1191,
    1192,  1195,  1197,  1199,  1202,  1204,  1205,  1208,  1210,  1212,
    1214,  1217,  1219,  1223,  1225,  1226,  1230,  1232,  1233,  1235,
    1237,  1239,  1241,  1245,  1250,  1251,  1255,  1257,  1259,  1261,
    1263,  1266,  1268,  1272,  1274,  1276,  1279,  1283,  1285,  1286,
    1289,  1291,  1293,  1297,  1298,  1302,  1304,  1306,  1308,  1310,
    1313,  1315,  1319,  1321,  1323,  1326,  1330,  1332,  1333,  1336,
    1338,  1340,  1342,  1344,  1347,  1349,  1353,  1355,  1356,  1359,
    1361,  1363,  1365,  1367,  1371,  1379,  1380,  1384,  1386,  1388,
    1390,  1392,  1394,  1398,  1400,  1401,  1405,  1407,  1409,  1411,
    1413,  1415,  1419,  1421,  1422,  1426,  1428,  1430,  1432,  1434,
    1436,  1440,  1442,  1443,  1447,  1449,  1451,  1453,  1455,  1457,
    1461,  1463,  1464,  1468,  1470,  1472,  1474,  1476,  1478,  1482,
    1484,  1485,  1489,  1491,  1493,  1495,  1497,  1499,  1503,  1505,
    1506,  1510,  1512,  1514,  1516,  1518,  1520,  1524,  1526,  1527,
    1530,  1534,  1536,  1538,  1539,  1542,  1544,  1546,  1548,  1550,
    1552,  1554,  1556,  1558,  1560,  1562,  1565,  1567,  1571,  1573,
    1575,  1577,  1580,  1584,  1586,  1587,  1590,  1592,  1594,  1596,
    1598,  1601,  1603,  1607,  1609,  1611,  1614,  1618,  1620,  1622,
    1623,  1626,  1628,  1630,  1632,  1634,  1636,  1638,  1642,  1644,
    1645,  1649,  1651,  1652,  1654,  1656,  1658,  1660,  1664,  1668,
    1669,  1673,  1675,  1677,  1679,  1681,  1684,  1686,  1690,  1692,
    1694,  1697,  1701,  1703,  1704,  1707,  1709,  1711,  1715,  1716,
    1719,  1721,  1723,  1725,  1727,  1731,  1739,  1740,  1744,  1746,
    1748,  1750,  1752,  1754,  1758,  1760,  1761,  1765,  1767,  1769,
    1771,  1773,  1775,  1779,  1781,  1782,  1786,  1788,  1790,  1792,
    1794,  1796,  1800,  1802,  1803,  1807,  1809,  1811,  1813,  1815,
    1817,  1821,  1823,  1824,  1828,  1830,  1832,  1834,  1836,  1838,
    1842,  1844,  1845,  1849,  1851,  1853,  1855,  1857,  1859,  1863,
    1865,  1866,  1870,  1872,  1874,  1876,  1878,  1880,  1884,  1886,
    1887,  1890,  1894,  1896,  1898,  1899,  1902,  1904,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1920,  1922,  1925,  1927,  1931,
    1933,  1935,  1937,  1940,  1944,  1946,  1947,  1950,  1952,  1954,
    1956,  1958,  1961,  1963,  1967,  1969,  1971,  1974,  1978,  1980,
    1982,  1983,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2002,
    2004,  2005,  2009,  2011,  2012,  2014,  2016,  2018,  2020,  2024,
    2028,  2029,  2033,  2035,  2037,  2039,  2041,  2044,  2046,  2050,
    2052,  2054,  2057,  2061,  2063,  2064,  2067,  2069,  2071,  2075,
    2076,  2079,  2081,  2083,  2085,  2087,  2091,  2099,  2100,  2104,
    2106,  2108,  2110,  2112,  2114,  2118,  2120,  2121,  2125,  2127,
    2129,  2131,  2133,  2135,  2139,  2141,  2142,  2146,  2148,  2150,
    2152,  2154,  2156,  2160,  2162,  2163,  2167,  2169,  2171,  2173,
    2175,  2177,  2181,  2183,  2184,  2188,  2190,  2192,  2194,  2196,
    2198,  2202,  2204,  2205,  2209,  2211,  2213,  2215,  2217,  2219,
    2223,  2225,  2226,  2230,  2232,  2234,  2236,  2238,  2240,  2244,
    2246,  2247,  2250,  2254,  2256,  2258,  2259,  2262,  2264,  2266,
    2268,  2270,  2272,  2274,  2276,  2278,  2280,  2282,  2285,  2287,
    2291,  2293,  2295,  2297,  2300,  2304,  2306,  2307,  2310,  2312,
    2314,  2316,  2318,  2321,  2323,  2327,  2329,  2331,  2334,  2338,
    2340,  2342,  2343,  2346,  2348,  2350,  2352,  2354,  2356,  2358,
    2362,  2364,  2365,  2369,  2371,  2373,  2375,  2377,  2380,  2382,
    2386,  2388,  2390,  2393,  2397,  2399,  2401,  2402,  2405,  2407,
    2409,  2411,  2413,  2415,  2417,  2419,  2422,  2424,  2428,  2430,
    2432,  2435,  2437,  2439,  2441,  2443,  2445,  2449,  2451,  2452,
    2456,  2458,  2460,  2462,  2464,  2467,  2469,  2473,  2475,  2477,
    2480,  2484,  2486,  2488,  2489,  2492,  2494,  2496,  2498,  2500,
    2502,  2504,  2507,  2509,  2513,  2515,  2517,  2520,  2522,  2524,
    2526,  2528,  2530,  2534,  2536,  2538,  2540,  2542,  2544,  2548,
    2550,  2552,  2554,  2556,  2560,  2562,  2564,  2566,  2568,  2572,
    2574,  2576,  2578,  2580,  2584,  2589,  2591,  2593,  2595,  2597,
    2601,  2603,  2605,  2607,  2609,  2613,  2615,  2617,  2619,  2621,
    2625,  2627,  2629,  2631,  2633,  2637,  2639,  2641,  2643,  2645,
    2649,  2651,  2653,  2655,  2657,  2661,  2666,  2671,  2676,  2681,
    2686,  2691,  2696,  2701,  2706,  2711,  2716,  2721,  2726,  2731,
    2736,  2741,  2746,  2751,  2753,  2755,  2757,  2759,  2761,  2764,
    2765,  2768,  2770,  2772,  2774,  2776,  2779,  2781,  2783,  2785,
    2788,  2790,  2794,  2796,  2798,  2801,  2803,  2805,  2807,  2809,
    2811,  2812,  2814,  2816,  2818,  2820,  2822,  2826,  2827,  2829,
    2831,  2833,  2835,  2837,  2841,  2842,  2844,  2846,  2848,  2850,
    2852,  2856,  2857,  2859,  2861,  2863,  2865,  2867,  2871,  2872,
    2874,  2876,  2878,  2880,  2882,  2886,  2888,  2890,  2891,  2894,
    2898,  2900,  2902,  2903,  2906,  2908,  2910,  2914,  2918,  2923,
    2925,  2927,  2930,  2932,  2936,  2941
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     256,     0,    -1,   257,   265,   263,    -1,   258,   259,   260,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   261,    -1,
     262,    -1,    11,    -1,    10,   265,   263,    -1,   264,    -1,
      15,    -1,    -1,   266,   267,   347,   401,   453,   548,    -1,
      -1,  1027,    -1,    -1,   268,   269,    -1,    67,    -1,   270,
      -1,   271,    -1,    10,    68,    -1,    11,    -1,    10,   272,
      68,    -1,   273,    -1,   274,    -1,   273,   274,    -1,   275,
      -1,   291,    -1,   297,    -1,   303,    -1,   309,    -1,   315,
      -1,   321,    -1,   327,    -1,   333,    -1,   276,   277,   280,
      -1,   141,    -1,   278,    -1,   279,    -1,   278,   279,    -1,
     988,    -1,   971,    -1,  1018,    -1,   281,    -1,   282,    -1,
      10,   142,    -1,    11,    -1,    10,   283,   142,    -1,   284,
      -1,   285,    -1,   284,   285,    -1,   286,   287,   290,    -1,
     191,    -1,   288,    -1,    -1,   288,   289,    -1,   980,    -1,
     971,    -1,    10,   192,    -1,    11,    -1,   292,   293,    -1,
     153,    -1,   294,    -1,   295,    -1,    10,   154,    -1,    11,
      -1,    10,   296,   154,    -1,     4,    -1,   298,   299,    -1,
     177,    -1,   300,    -1,   301,    -1,    10,   178,    -1,    11,
      -1,    10,   302,   178,    -1,     4,    -1,   304,   305,    -1,
     175,    -1,   306,    -1,   307,    -1,    10,   176,    -1,    11,
      -1,    10,   308,   176,    -1,     4,    -1,   310,   311,    -1,
     147,    -1,   312,    -1,   313,    -1,    10,   148,    -1,    11,
      -1,    10,   314,   148,    -1,     4,    -1,   316,   317,    -1,
     151,    -1,   318,    -1,   319,    -1,    10,   152,    -1,    11,
      -1,    10,   320,   152,    -1,     4,    -1,   322,   323,    -1,
     183,    -1,   324,    -1,   325,    -1,    10,   184,    -1,    11,
      -1,    10,   326,   184,    -1,     4,    -1,   328,   329,    -1,
     201,    -1,   330,    -1,   331,    -1,    10,   202,    -1,    11,
      -1,    10,   332,   202,    -1,     4,    -1,   334,   335,   336,
      -1,   165,    -1,  1013,    -1,   337,    -1,   338,    -1,    10,
     166,    -1,    11,    -1,    10,   339,   166,    -1,   340,    -1,
     341,    -1,   340,   341,    -1,   342,   343,   346,    -1,   163,
      -1,   344,    -1,    -1,   344,   345,    -1,   980,    -1,   996,
      -1,   971,    -1,    10,   164,    -1,    11,    -1,    -1,   348,
     349,    -1,    69,    -1,   350,    -1,   351,    -1,    10,    70,
      -1,    11,    -1,    10,   352,    70,    -1,   353,    -1,   354,
      -1,   353,   354,    -1,   355,    -1,   361,    -1,   368,    -1,
     375,    -1,   382,    -1,   387,    -1,   356,   357,    -1,   195,
      -1,   358,    -1,   359,    -1,    10,   196,    -1,    11,    -1,
      10,   360,   196,    -1,     4,    -1,   362,   363,   366,    -1,
     113,    -1,   364,    -1,    -1,   364,   365,    -1,   992,    -1,
     971,    -1,    10,   367,   114,    -1,  1022,    -1,   369,   370,
     373,    -1,   115,    -1,   371,    -1,    -1,   371,   372,    -1,
     992,    -1,   971,    -1,    10,   374,   116,    -1,  1022,    -1,
     376,   377,   380,    -1,   111,    -1,   378,    -1,    -1,   378,
     379,    -1,   992,    -1,   971,    -1,    10,   381,   112,    -1,
    1022,    -1,   383,   384,   385,    -1,   109,    -1,    -1,   971,
      -1,    10,   386,   110,    -1,     6,    -1,   388,   389,   390,
      -1,   165,    -1,  1013,    -1,   391,    -1,   392,    -1,    10,
     166,    -1,    11,    -1,    10,   393,   166,    -1,   394,    -1,
     395,    -1,   394,   395,    -1,   396,   397,   400,    -1,   163,
      -1,   398,    -1,    -1,   398,   399,    -1,   980,    -1,   996,
      -1,   971,    -1,    10,   164,    -1,    11,    -1,    -1,   402,
     403,    -1,    71,    -1,   404,    -1,   405,    -1,    10,    72,
      -1,    11,    -1,    10,   406,    72,    -1,   407,    -1,   408,
      -1,   407,   408,    -1,   409,    -1,   415,    -1,   421,    -1,
     427,    -1,   433,    -1,   439,    -1,   410,   411,    -1,   131,
      -1,   412,    -1,   413,    -1,    10,   132,    -1,    11,    -1,
      10,   414,   132,    -1,     4,    -1,   416,   417,    -1,   129,
      -1,   418,    -1,   419,    -1,    10,   130,    -1,    11,    -1,
      10,   420,   130,    -1,     6,    -1,   422,   423,    -1,   205,
      -1,   424,    -1,   425,    -1,    10,   206,    -1,    11,    -1,
      10,   426,   206,    -1,     6,    -1,   428,   429,    -1,   199,
      -1,   430,    -1,   431,    -1,    10,   200,    -1,    11,    -1,
      10,   432,   200,    -1,     4,    -1,   434,   435,    -1,   179,
      -1,   436,    -1,   437,    -1,    10,   180,    -1,    11,    -1,
      10,   438,   180,    -1,  1022,    -1,   440,   441,   442,    -1,
     165,    -1,  1013,    -1,   443,    -1,   444,    -1,    10,   166,
      -1,    11,    -1,    10,   445,   166,    -1,   446,    -1,   447,
      -1,   446,   447,    -1,   448,   449,   452,    -1,   163,    -1,
     450,    -1,    -1,   450,   451,    -1,   980,    -1,   996,    -1,
     971,    -1,    10,   164,    -1,    11,    -1,    -1,   454,   455,
      -1,    73,    -1,   456,    -1,   457,    -1,    10,    74,    -1,
      11,    -1,    10,   458,    74,    -1,   459,    -1,   460,    -1,
     459,   460,    -1,   461,    -1,   467,    -1,   473,    -1,   479,
      -1,   485,    -1,   491,    -1,   508,    -1,   515,    -1,   522,
      -1,   529,    -1,   534,    -1,   462,   463,    -1,   187,    -1,
     464,    -1,   465,    -1,    10,   188,    -1,    11,    -1,    10,
     466,   188,    -1,     4,    -1,   468,   469,    -1,   189,    -1,
     470,    -1,   471,    -1,    10,   190,    -1,    11,    -1,    10,
     472,   190,    -1,     4,    -1,   474,   475,    -1,   173,    -1,
     476,    -1,   477,    -1,    10,   174,    -1,    11,    -1,    10,
     478,   174,    -1,     4,    -1,   480,   481,    -1,   101,    -1,
     482,    -1,   483,    -1,    10,   102,    -1,    11,    -1,    10,
     484,   102,    -1,     4,    -1,   486,   487,    -1,   139,    -1,
     488,    -1,   489,    -1,    10,   140,    -1,    11,    -1,    10,
     490,   140,    -1,     4,    -1,   492,   493,   494,    -1,   203,
      -1,  1019,    -1,   495,    -1,   496,    -1,    10,   204,    -1,
      11,    -1,    10,   497,   204,    -1,   498,    -1,   499,    -1,
     498,   499,    -1,   500,   501,   503,    -1,   197,    -1,    -1,
     501,   502,    -1,   992,    -1,   988,    -1,   963,    -1,   971,
      -1,   504,    -1,   505,    -1,    10,   198,    -1,    11,    -1,
      10,   506,   198,    -1,   507,    -1,     7,    -1,     6,    -1,
     509,   510,   513,    -1,   213,    -1,   511,    -1,    -1,   511,
     512,    -1,   992,    -1,   971,    -1,    10,   514,   214,    -1,
    1022,    -1,   516,   517,   520,    -1,   215,    -1,   518,    -1,
      -1,   518,   519,    -1,   992,    -1,   971,    -1,    10,   521,
     216,    -1,  1022,    -1,   523,   524,   527,    -1,   211,    -1,
     525,    -1,    -1,   525,   526,    -1,   992,    -1,   971,    -1,
      10,   528,   212,    -1,  1022,    -1,   530,   531,   532,    -1,
     209,    -1,    -1,   971,    -1,    10,   533,   210,    -1,     6,
      -1,   535,   536,   537,    -1,   165,    -1,  1013,    -1,   538,
      -1,   539,    -1,    10,   166,    -1,    11,    -1,    10,   540,
     166,    -1,   541,    -1,   542,    -1,   541,   542,    -1,   543,
     544,   547,    -1,   163,    -1,   545,    -1,    -1,   545,   546,
      -1,   980,    -1,   996,    -1,   971,    -1,    10,   164,    -1,
      11,    -1,    -1,   549,   550,   553,    -1,    75,    -1,   551,
      -1,    -1,   551,   552,    -1,  1016,    -1,  1021,    -1,  1005,
      -1,  1010,    -1,   554,    -1,   555,    -1,    10,    76,    -1,
      11,    -1,    10,   556,    76,    -1,   557,   940,    -1,   558,
      -1,   557,   558,    -1,   559,   560,   566,    -1,   181,    -1,
     561,    -1,    -1,   561,   562,    -1,   563,    -1,   564,    -1,
     565,    -1,    36,  1024,     6,  1024,    -1,    63,     3,  1024,
      -1,    61,     3,  1024,    -1,    10,   567,   583,   589,   709,
     813,   917,   182,    -1,   568,   569,   572,    -1,   187,    -1,
     570,    -1,   571,    -1,   570,   571,    -1,   988,    -1,   971,
      -1,  1018,    -1,   573,    -1,   574,    -1,    10,   188,    -1,
      11,    -1,    10,   575,   188,    -1,   576,    -1,   577,    -1,
     576,   577,    -1,   578,   579,   582,    -1,   191,    -1,   580,
      -1,    -1,   580,   581,    -1,   988,    -1,   971,    -1,    10,
     192,    -1,    11,    -1,    -1,   584,   585,    -1,   153,    -1,
     586,    -1,   587,    -1,    10,   154,    -1,    11,    -1,    10,
     588,   154,    -1,     4,    -1,    -1,   590,   591,   592,    -1,
     223,    -1,    -1,  1015,    -1,   593,    -1,   594,    -1,    11,
      -1,    10,   595,   224,    -1,   596,   609,   625,   680,    -1,
      -1,   597,   598,   599,    -1,   217,    -1,  1020,    -1,   600,
      -1,   601,    -1,    10,   218,    -1,    11,    -1,    10,   602,
     218,    -1,   603,    -1,   604,    -1,   603,   604,    -1,   605,
     606,   608,    -1,   221,    -1,    -1,   606,   607,    -1,   979,
      -1,   980,    -1,    10,  1022,   222,    -1,    -1,   610,   611,
     612,    -1,   219,    -1,  1020,    -1,   613,    -1,   614,    -1,
      10,   220,    -1,    11,    -1,    10,   615,   220,    -1,   616,
      -1,   617,    -1,   616,   617,    -1,   618,   619,   621,    -1,
     221,    -1,    -1,   619,   620,    -1,   979,    -1,   980,    -1,
     622,    -1,   623,    -1,    10,   222,    -1,    11,    -1,    10,
     624,   222,    -1,     4,    -1,    -1,   626,   627,    -1,   121,
      -1,   628,    -1,   629,    -1,    11,    -1,    10,   630,   122,
      -1,   631,   638,   645,   652,   659,   666,   673,    -1,    -1,
     632,   633,   634,    -1,   119,    -1,  1006,    -1,   635,    -1,
     636,    -1,    11,    -1,    10,   637,   120,    -1,  1055,    -1,
      -1,   639,   640,   641,    -1,   105,    -1,  1006,    -1,   642,
      -1,   643,    -1,    11,    -1,    10,   644,   106,    -1,  1055,
      -1,    -1,   646,   647,   648,    -1,   107,    -1,  1006,    -1,
     649,    -1,   650,    -1,    11,    -1,    10,   651,   108,    -1,
    1055,    -1,    -1,   653,   654,   655,    -1,   103,    -1,  1006,
      -1,   656,    -1,   657,    -1,    11,    -1,    10,   658,   104,
      -1,  1055,    -1,    -1,   660,   661,   662,    -1,   149,    -1,
    1006,    -1,   663,    -1,   664,    -1,    11,    -1,    10,   665,
     150,    -1,  1055,    -1,    -1,   667,   668,   669,    -1,   193,
      -1,  1006,    -1,   670,    -1,   671,    -1,    11,    -1,    10,
     672,   194,    -1,  1055,    -1,    -1,   674,   675,   676,    -1,
     207,    -1,  1006,    -1,   677,    -1,   678,    -1,    11,    -1,
      10,   679,   208,    -1,  1055,    -1,    -1,   680,   681,    -1,
     682,   683,   686,    -1,   163,    -1,   684,    -1,    -1,   684,
     685,    -1,  1020,    -1,  1007,    -1,   996,    -1,   980,    -1,
     988,    -1,  1000,    -1,   975,    -1,   971,    -1,   687,    -1,
     688,    -1,    10,   164,    -1,    11,    -1,    10,   689,   164,
      -1,   690,    -1,   699,    -1,   691,    -1,   690,   691,    -1,
     692,   693,   695,    -1,   221,    -1,    -1,   693,   694,    -1,
     979,    -1,   980,    -1,   696,    -1,   697,    -1,    10,   222,
      -1,    11,    -1,    10,   698,   222,    -1,  1023,    -1,   700,
      -1,   699,   700,    -1,   701,   702,   705,    -1,   137,    -1,
     703,    -1,    -1,   703,   704,    -1,  1006,    -1,   996,    -1,
     971,    -1,   706,    -1,   707,    -1,    11,    -1,    10,   708,
     138,    -1,  1055,    -1,    -1,   710,   711,   712,    -1,   157,
      -1,    -1,  1012,    -1,   713,    -1,   714,    -1,    11,    -1,
      10,   715,   158,    -1,   716,   729,   784,    -1,    -1,   717,
     718,   719,    -1,   217,    -1,  1009,    -1,   720,    -1,   721,
      -1,    10,   218,    -1,    11,    -1,    10,   722,   218,    -1,
     723,    -1,   724,    -1,   723,   724,    -1,   725,   726,   728,
      -1,   155,    -1,    -1,   726,   727,    -1,   979,    -1,   980,
      -1,    10,  1022,   156,    -1,    -1,   730,   731,    -1,   121,
      -1,   732,    -1,   733,    -1,    11,    -1,    10,   734,   122,
      -1,   735,   742,   749,   756,   763,   770,   777,    -1,    -1,
     736,   737,   738,    -1,   119,    -1,  1006,    -1,   739,    -1,
     740,    -1,    11,    -1,    10,   741,   120,    -1,  1055,    -1,
      -1,   743,   744,   745,    -1,   105,    -1,  1006,    -1,   746,
      -1,   747,    -1,    11,    -1,    10,   748,   106,    -1,  1055,
      -1,    -1,   750,   751,   752,    -1,   107,    -1,  1006,    -1,
     753,    -1,   754,    -1,    11,    -1,    10,   755,   108,    -1,
    1055,    -1,    -1,   757,   758,   759,    -1,   103,    -1,  1006,
      -1,   760,    -1,   761,    -1,    11,    -1,    10,   762,   104,
      -1,  1055,    -1,    -1,   764,   765,   766,    -1,   149,    -1,
    1006,    -1,   767,    -1,   768,    -1,    11,    -1,    10,   769,
     150,    -1,  1055,    -1,    -1,   771,   772,   773,    -1,   193,
      -1,  1006,    -1,   774,    -1,   775,    -1,    11,    -1,    10,
     776,   194,    -1,  1055,    -1,    -1,   778,   779,   780,    -1,
     207,    -1,  1006,    -1,   781,    -1,   782,    -1,    11,    -1,
      10,   783,   208,    -1,  1055,    -1,    -1,   784,   785,    -1,
     786,   787,   790,    -1,   163,    -1,   788,    -1,    -1,   788,
     789,    -1,  1009,    -1,  1007,    -1,   996,    -1,   980,    -1,
     988,    -1,   984,    -1,   975,    -1,   971,    -1,   791,    -1,
     792,    -1,    10,   164,    -1,    11,    -1,    10,   793,   164,
      -1,   794,    -1,   803,    -1,   795,    -1,   794,   795,    -1,
     796,   797,   799,    -1,   155,    -1,    -1,   797,   798,    -1,
     979,    -1,   980,    -1,   800,    -1,   801,    -1,    10,   156,
      -1,    11,    -1,    10,   802,   156,    -1,  1023,    -1,   804,
      -1,   803,   804,    -1,   805,   806,   809,    -1,   137,    -1,
     807,    -1,    -1,   807,   808,    -1,  1006,    -1,   996,    -1,
     971,    -1,   810,    -1,   811,    -1,    11,    -1,    10,   812,
     138,    -1,  1055,    -1,    -1,   814,   815,   816,    -1,   127,
      -1,    -1,  1011,    -1,   817,    -1,   818,    -1,    11,    -1,
      10,   819,   128,    -1,   820,   833,   888,    -1,    -1,   821,
     822,   823,    -1,   133,    -1,  1004,    -1,   824,    -1,   825,
      -1,    10,   134,    -1,    11,    -1,    10,   826,   134,    -1,
     827,    -1,   828,    -1,   827,   828,    -1,   829,   830,   832,
      -1,   125,    -1,    -1,   830,   831,    -1,   979,    -1,   980,
      -1,    10,  1022,   126,    -1,    -1,   834,   835,    -1,   121,
      -1,   836,    -1,   837,    -1,    11,    -1,    10,   838,   122,
      -1,   839,   846,   853,   860,   867,   874,   881,    -1,    -1,
     840,   841,   842,    -1,   119,    -1,  1006,    -1,   843,    -1,
     844,    -1,    11,    -1,    10,   845,   120,    -1,  1055,    -1,
      -1,   847,   848,   849,    -1,   105,    -1,  1006,    -1,   850,
      -1,   851,    -1,    11,    -1,    10,   852,   106,    -1,  1055,
      -1,    -1,   854,   855,   856,    -1,   107,    -1,  1006,    -1,
     857,    -1,   858,    -1,    11,    -1,    10,   859,   108,    -1,
    1055,    -1,    -1,   861,   862,   863,    -1,   103,    -1,  1006,
      -1,   864,    -1,   865,    -1,    11,    -1,    10,   866,   104,
      -1,  1055,    -1,    -1,   868,   869,   870,    -1,   149,    -1,
    1006,    -1,   871,    -1,   872,    -1,    11,    -1,    10,   873,
     150,    -1,  1055,    -1,    -1,   875,   876,   877,    -1,   193,
      -1,  1006,    -1,   878,    -1,   879,    -1,    11,    -1,    10,
     880,   194,    -1,  1055,    -1,    -1,   882,   883,   884,    -1,
     207,    -1,  1006,    -1,   885,    -1,   886,    -1,    11,    -1,
      10,   887,   208,    -1,  1055,    -1,    -1,   888,   889,    -1,
     890,   891,   894,    -1,   163,    -1,   892,    -1,    -1,   892,
     893,    -1,  1004,    -1,  1007,    -1,   996,    -1,   980,    -1,
     988,    -1,   967,    -1,   975,    -1,   971,    -1,   895,    -1,
     896,    -1,    10,   164,    -1,    11,    -1,    10,   897,   164,
      -1,   898,    -1,   907,    -1,   899,    -1,   898,   899,    -1,
     900,   901,   903,    -1,   125,    -1,    -1,   901,   902,    -1,
     979,    -1,   980,    -1,   904,    -1,   905,    -1,    10,   126,
      -1,    11,    -1,    10,   906,   126,    -1,  1023,    -1,   908,
      -1,   907,   908,    -1,   909,   910,   913,    -1,   137,    -1,
     911,    -1,    -1,   911,   912,    -1,  1006,    -1,   996,    -1,
     971,    -1,   914,    -1,   915,    -1,    11,    -1,    10,   916,
     138,    -1,  1055,    -1,    -1,   918,   919,   920,    -1,   169,
      -1,  1014,    -1,   921,    -1,   922,    -1,    10,   170,    -1,
      11,    -1,    10,   923,   170,    -1,   924,    -1,   925,    -1,
     924,   925,    -1,   926,   927,   930,    -1,   167,    -1,   928,
      -1,    -1,   928,   929,    -1,   980,    -1,   996,    -1,   963,
      -1,   971,    -1,  1008,    -1,   931,    -1,   932,    -1,    10,
     168,    -1,    11,    -1,    10,   933,   168,    -1,   934,    -1,
     935,    -1,   934,   935,    -1,   936,    -1,   937,    -1,   938,
      -1,    79,    -1,    80,    -1,    77,   939,    78,    -1,     5,
      -1,    -1,   941,   942,   943,    -1,   171,    -1,  1017,    -1,
     944,    -1,   945,    -1,    10,   172,    -1,    11,    -1,    10,
     946,   172,    -1,   947,    -1,   948,    -1,   947,   948,    -1,
     949,   950,   953,    -1,   185,    -1,   951,    -1,    -1,   951,
     952,    -1,   980,    -1,   963,    -1,   971,    -1,  1008,    -1,
     954,    -1,   955,    -1,    10,   186,    -1,    11,    -1,    10,
     956,   186,    -1,   957,    -1,   958,    -1,   957,   958,    -1,
     959,    -1,   960,    -1,   961,    -1,    79,    -1,    80,    -1,
      77,   962,    78,    -1,     5,    -1,   964,    -1,   965,    -1,
     966,    -1,    42,    -1,    41,     3,  1024,    -1,   968,    -1,
     969,    -1,   970,    -1,    50,    -1,    49,     3,  1024,    -1,
     972,    -1,   973,    -1,   974,    -1,    44,    -1,    43,     3,
    1024,    -1,   976,    -1,   977,    -1,   978,    -1,    52,    -1,
      51,     3,  1024,    -1,    37,  1024,     6,  1024,    -1,   981,
      -1,   982,    -1,   983,    -1,    46,    -1,    45,     3,  1024,
      -1,   985,    -1,   986,    -1,   987,    -1,    54,    -1,    53,
       3,  1024,    -1,   989,    -1,   990,    -1,   991,    -1,    48,
      -1,    47,     3,  1024,    -1,   993,    -1,   994,    -1,   995,
      -1,    58,    -1,    57,     3,  1024,    -1,   997,    -1,   998,
      -1,   999,    -1,    60,    -1,    59,     3,  1024,    -1,  1001,
      -1,  1002,    -1,  1003,    -1,    56,    -1,    55,     3,  1024,
      -1,    16,  1024,     6,  1024,    -1,    17,  1024,     6,  1024,
      -1,    18,  1024,     6,  1024,    -1,    19,  1024,     6,  1024,
      -1,    21,  1024,     6,  1024,    -1,    22,  1024,     6,  1024,
      -1,    23,  1024,     6,  1024,    -1,    24,  1024,     6,  1024,
      -1,    25,  1024,     6,  1024,    -1,    26,  1024,     6,  1024,
      -1,    27,  1024,     6,  1024,    -1,    28,  1024,     6,  1024,
      -1,    29,  1024,     6,  1024,    -1,    30,  1024,     6,  1024,
      -1,    31,  1024,     6,  1024,    -1,    32,  1024,     6,  1024,
      -1,    33,  1024,     6,  1024,    -1,    34,  1024,     6,  1024,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1025,     8,    -1,    -1,  1025,  1026,    -1,   251,    -1,
     252,    -1,   253,    -1,   254,    -1,  1028,  1029,    -1,    65,
      -1,  1030,    -1,  1031,    -1,    10,    66,    -1,    11,    -1,
      10,  1032,    66,    -1,  1033,    -1,  1034,    -1,  1033,  1034,
      -1,  1035,    -1,  1039,    -1,  1043,    -1,  1047,    -1,  1051,
      -1,    -1,  1036,    -1,  1037,    -1,  1038,    -1,    84,    -1,
      83,    -1,    81,     5,    82,    -1,    -1,  1040,    -1,  1041,
      -1,  1042,    -1,    88,    -1,    87,    -1,    85,     5,    86,
      -1,    -1,  1044,    -1,  1045,    -1,  1046,    -1,    92,    -1,
      91,    -1,    89,     5,    90,    -1,    -1,  1048,    -1,  1049,
      -1,  1050,    -1,    96,    -1,    95,    -1,    93,     5,    94,
      -1,    -1,  1052,    -1,  1053,    -1,  1054,    -1,   100,    -1,
      99,    -1,    97,     5,    98,    -1,  1056,    -1,  1063,    -1,
      -1,  1056,  1057,    -1,  1058,  1059,  1062,    -1,   135,    -1,
    1060,    -1,    -1,  1060,  1061,    -1,  1069,    -1,  1068,    -1,
      10,     6,   136,    -1,   117,  1064,  1065,    -1,    40,  1024,
       6,  1024,    -1,  1066,    -1,  1067,    -1,    10,   118,    -1,
      11,    -1,    10,     4,   118,    -1,    38,  1024,     6,  1024,
      -1,    39,  1024,     6,  1024,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   213,   213,   214,   216,   223,   233,   233,   235,   235,
     237,   239,   241,   250,   251,   254,   263,   263,   276,   276,
     278,   292,   292,   294,   294,   296,   298,   300,   300,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   314,   316,
     331,   338,   338,   341,   346,   350,   359,   363,   368,   368,
     370,   372,   374,   374,   376,   381,   391,   397,   397,   400,
     405,   411,   411,   414,   416,   423,   423,   425,   425,   427,
     429,   432,   434,   441,   441,   443,   443,   445,   447,   452,
     454,   461,   461,   463,   463,   465,   467,   472,   474,   481,
     481,   483,   483,   485,   487,   492,   494,   501,   501,   503,
     503,   505,   507,   512,   514,   521,   521,   523,   523,   525,
     527,   532,   534,   541,   541,   543,   543,   545,   547,   552,
     554,   561,   571,   576,   582,   582,   584,   586,   588,   588,
     590,   595,   607,   613,   613,   616,   623,   628,   635,   635,
     639,   639,   641,   652,   652,   654,   654,   656,   658,   660,
     660,   663,   664,   665,   666,   667,   668,   671,   673,   680,
     680,   682,   682,   684,   686,   693,   695,   706,   708,   708,
     711,   717,   723,   725,   731,   733,   744,   746,   746,   749,
     755,   761,   763,   770,   772,   783,   785,   785,   788,   794,
     800,   802,   809,   811,   820,   821,   827,   829,   835,   837,
     844,   854,   859,   865,   865,   867,   869,   871,   871,   873,
     878,   890,   896,   896,   899,   906,   911,   917,   917,   921,
     921,   923,   934,   934,   936,   936,   938,   940,   942,   942,
     945,   946,   947,   948,   949,   950,   953,   955,   962,   962,
     964,   964,   966,   968,   976,   978,   985,   985,   987,   987,
     989,   991,   996,   998,  1005,  1005,  1007,  1007,  1009,  1011,
    1016,  1018,  1025,  1025,  1027,  1027,  1029,  1031,  1036,  1038,
    1045,  1045,  1047,  1047,  1049,  1051,  1058,  1060,  1067,  1077,
    1082,  1088,  1088,  1090,  1092,  1094,  1094,  1096,  1101,  1113,
    1119,  1119,  1122,  1129,  1134,  1141,  1141,  1144,  1144,  1146,
    1162,  1162,  1164,  1164,  1166,  1168,  1170,  1170,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1186,
    1188,  1195,  1195,  1197,  1197,  1199,  1201,  1209,  1211,  1218,
    1218,  1220,  1220,  1222,  1224,  1229,  1231,  1238,  1238,  1240,
    1240,  1242,  1244,  1249,  1251,  1258,  1258,  1260,  1260,  1262,
    1264,  1269,  1271,  1278,  1278,  1280,  1280,  1282,  1284,  1289,
    1291,  1298,  1308,  1313,  1319,  1319,  1321,  1323,  1325,  1325,
    1327,  1329,  1343,  1343,  1346,  1346,  1346,  1346,  1349,  1349,
    1351,  1351,  1353,  1355,  1364,  1365,  1368,  1370,  1381,  1383,
    1383,  1386,  1392,  1398,  1400,  1407,  1409,  1420,  1422,  1422,
    1425,  1431,  1437,  1439,  1446,  1448,  1459,  1461,  1461,  1464,
    1470,  1476,  1478,  1485,  1487,  1497,  1498,  1504,  1506,  1513,
    1515,  1522,  1532,  1537,  1543,  1543,  1545,  1547,  1549,  1549,
    1551,  1556,  1568,  1574,  1574,  1577,  1584,  1589,  1596,  1596,
    1599,  1599,  1601,  1609,  1615,  1615,  1618,  1625,  1631,  1637,
    1645,  1650,  1656,  1656,  1658,  1660,  1662,  1662,  1664,  1666,
    1675,  1677,  1677,  1679,  1679,  1679,  1681,  1691,  1701,  1721,
    1727,  1729,  1739,  1745,  1745,  1748,  1753,  1758,  1768,  1773,
    1779,  1779,  1781,  1783,  1785,  1785,  1787,  1792,  1802,  1808,
    1808,  1811,  1817,  1824,  1824,  1827,  1827,  1829,  1831,  1831,
    1833,  1833,  1835,  1837,  1845,  1845,  1847,  1853,  1853,  1861,
    1861,  1863,  1865,  1867,  1869,  1869,  1871,  1873,  1881,  1886,
    1892,  1892,  1894,  1896,  1898,  1898,  1900,  1911,  1920,  1920,
    1923,  1924,  1927,  1930,  1930,  1932,  1934,  1942,  1947,  1953,
    1953,  1955,  1957,  1959,  1959,  1961,  1972,  1981,  1981,  1984,
    1985,  1989,  1990,  1992,  1992,  1994,  1996,  2001,  2001,  2003,
    2008,  2008,  2010,  2012,  2014,  2016,  2016,  2025,  2027,  2034,
    2034,  2036,  2038,  2040,  2043,  2043,  2053,  2055,  2062,  2062,
    2064,  2066,  2068,  2071,  2071,  2080,  2082,  2089,  2089,  2091,
    2093,  2095,  2098,  2098,  2107,  2109,  2116,  2116,  2118,  2120,
    2122,  2125,  2125,  2134,  2136,  2143,  2143,  2145,  2147,  2149,
    2152,  2152,  2161,  2163,  2170,  2170,  2172,  2174,  2176,  2179,
    2179,  2188,  2190,  2197,  2197,  2199,  2201,  2203,  2206,  2206,
    2208,  2213,  2232,  2238,  2238,  2241,  2252,  2263,  2269,  2275,
    2281,  2287,  2293,  2300,  2300,  2302,  2302,  2304,  2306,  2306,
    2308,  2308,  2310,  2317,  2326,  2326,  2329,  2335,  2342,  2342,
    2344,  2344,  2346,  2348,  2357,  2357,  2359,  2370,  2378,  2384,
    2384,  2387,  2393,  2394,  2398,  2398,  2400,  2402,  2405,  2409,
    2409,  2411,  2419,  2419,  2427,  2427,  2429,  2431,  2433,  2435,
    2435,  2437,  2439,  2447,  2452,  2458,  2458,  2460,  2462,  2465,
    2465,  2467,  2476,  2486,  2486,  2489,  2490,  2493,  2496,  2496,
    2498,  2503,  2503,  2506,  2508,  2510,  2512,  2512,  2521,  2523,
    2530,  2530,  2532,  2534,  2536,  2538,  2538,  2547,  2549,  2556,
    2556,  2558,  2560,  2562,  2565,  2565,  2574,  2576,  2583,  2583,
    2585,  2587,  2589,  2592,  2592,  2601,  2603,  2610,  2610,  2612,
    2614,  2616,  2619,  2619,  2628,  2630,  2637,  2637,  2639,  2641,
    2643,  2646,  2646,  2655,  2657,  2664,  2664,  2666,  2668,  2670,
    2673,  2673,  2682,  2684,  2691,  2691,  2693,  2695,  2697,  2700,
    2700,  2702,  2708,  2727,  2734,  2734,  2737,  2748,  2759,  2765,
    2771,  2777,  2783,  2789,  2798,  2798,  2800,  2800,  2802,  2804,
    2804,  2806,  2806,  2808,  2813,  2823,  2823,  2826,  2831,  2838,
    2838,  2840,  2840,  2842,  2844,  2851,  2851,  2853,  2864,  2872,
    2878,  2878,  2881,  2887,  2888,  2892,  2892,  2894,  2896,  2899,
    2902,  2902,  2904,  2911,  2911,  2919,  2919,  2921,  2923,  2925,
    2927,  2927,  2929,  2932,  2940,  2945,  2951,  2951,  2953,  2955,
    2957,  2957,  2959,  2968,  2977,  2977,  2980,  2981,  2984,  2987,
    2987,  2989,  2994,  2994,  2996,  2998,  3000,  3002,  3002,  3011,
    3013,  3020,  3020,  3022,  3024,  3026,  3028,  3028,  3037,  3039,
    3046,  3046,  3048,  3050,  3052,  3055,  3055,  3064,  3066,  3073,
    3073,  3075,  3077,  3079,  3082,  3082,  3091,  3093,  3100,  3100,
    3102,  3104,  3106,  3109,  3109,  3118,  3120,  3127,  3127,  3129,
    3131,  3133,  3136,  3136,  3145,  3147,  3154,  3154,  3156,  3158,
    3160,  3163,  3163,  3172,  3174,  3181,  3181,  3183,  3185,  3187,
    3190,  3190,  3192,  3198,  3217,  3223,  3223,  3226,  3237,  3248,
    3254,  3260,  3266,  3272,  3278,  3285,  3285,  3287,  3287,  3289,
    3291,  3291,  3293,  3293,  3295,  3302,  3311,  3311,  3315,  3320,
    3328,  3328,  3330,  3330,  3332,  3334,  3341,  3341,  3343,  3354,
    3362,  3368,  3368,  3371,  3377,  3378,  3382,  3382,  3384,  3386,
    3388,  3392,  3392,  3394,  3399,  3408,  3413,  3419,  3419,  3421,
    3423,  3425,  3425,  3427,  3432,  3446,  3454,  3454,  3457,  3463,
    3469,  3475,  3483,  3493,  3498,  3504,  3504,  3506,  3508,  3510,
    3510,  3512,  3518,  3523,  3525,  3525,  3527,  3529,  3541,  3541,
    3543,  3548,  3557,  3562,  3568,  3568,  3570,  3572,  3574,  3574,
    3576,  3581,  3593,  3601,  3601,  3604,  3609,  3615,  3621,  3630,
    3635,  3641,  3641,  3643,  3645,  3647,  3647,  3649,  3655,  3660,
    3662,  3662,  3664,  3666,  3677,  3684,  3684,  3686,  3691,  3696,
    3703,  3703,  3705,  3710,  3715,  3722,  3722,  3724,  3729,  3734,
    3741,  3741,  3743,  3748,  3753,  3761,  3768,  3768,  3770,  3775,
    3780,  3787,  3787,  3789,  3794,  3799,  3806,  3806,  3808,  3813,
    3818,  3825,  3825,  3827,  3832,  3837,  3844,  3844,  3846,  3851,
    3856,  3863,  3863,  3865,  3870,  3876,  3882,  3891,  3897,  3911,
    3920,  3926,  3935,  3941,  3947,  3953,  3959,  3965,  3974,  3980,
    3989,  3994,  4000,  4017,  4018,  4022,  4023,  4024,  4026,  4028,
    4028,  4030,  4031,  4032,  4033,  4066,  4068,  4082,  4082,  4084,
    4084,  4086,  4088,  4090,  4090,  4093,  4094,  4095,  4096,  4097,
    4099,  4099,  4107,  4107,  4109,  4109,  4111,  4117,  4117,  4125,
    4125,  4127,  4127,  4129,  4135,  4135,  4143,  4143,  4145,  4145,
    4147,  4153,  4153,  4161,  4161,  4163,  4163,  4165,  4171,  4171,
    4179,  4179,  4181,  4181,  4183,  4195,  4203,  4205,  4205,  4207,
    4209,  4218,  4220,  4220,  4222,  4222,  4224,  4240,  4242,  4247,
    4247,  4249,  4249,  4252,  4278,  4286
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "OSRLSTART", "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT",
  "OSRLEND", "NUMBEROFCONATT", "NUMBEROFCONSTRAINTSATT", "NUMBEROFELATT",
  "NUMBEROFENUMERATIONSATT", "NUMBEROFIDXATT", "NUMBEROFITEMSATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFSOLVEROUTPUTSATT", "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIABLESATT", "NUMBEROFVARIDXATT",
  "TARGETOBJECTIVEIDXATT", "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT",
  "CATEGORYATT", "EMPTYCATEGORYATT", "DESCRIPTIONATT",
  "EMPTYDESCRIPTIONATT", "NAMEATT", "EMPTYNAMEATT", "TYPEATT",
  "EMPTYTYPEATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT",
  "EMPTYVALUEATT", "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
  "TARGETOBJECTIVENAMEATT", "EMPTYTARGETOBJECTIVENAMEATT", "HEADERSTART",
  "HEADEREND", "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND",
  "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "ITEMEMPTY", "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY",
  "FILENAMESTARTANDEND", "FILESOURCESTART", "FILESOURCEEND",
  "FILESOURCEEMPTY", "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART",
  "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND", "ATUPPERSTART",
  "ATUPPEREND", "AVAILABLECPUNUMBERSTART", "AVAILABLECPUNUMBEREND",
  "AVAILABLECPUSPEEDSTART", "AVAILABLECPUSPEEDEND",
  "AVAILABLEDISKSPACESTART", "AVAILABLEDISKSPACEEND",
  "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND", "BASE64START", "BASE64END",
  "BASICSTART", "BASICEND", "BASISSTATUSSTART", "BASISSTATUSEND",
  "BASSTATUSSTART", "BASSTATUSEND", "CONSTART", "CONEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "CURRENTJOBCOUNTSTART",
  "CURRENTJOBCOUNTEND", "CURRENTSTATESTART", "CURRENTSTATEEND",
  "DUALVALUESSTART", "DUALVALUESEND", "ELSTART", "ELEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ENDTIMESTART", "ENDTIMEEND",
  "GENERALSTATUSSTART", "GENERALSTATUSEND", "GENERALSUBSTATUSSTART",
  "GENERALSUBSTATUSEND", "IDXSTART", "IDXEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "ISFREESTART", "ISFREEEND", "JOBIDSTART", "JOBIDEND",
  "MESSAGESTART", "MESSAGEEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART",
  "OBJECTIVESEND", "OPTIMIZATIONSOLUTIONSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSTATUSEND", "OPTIMIZATIONSOLUTIONSUBSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSUBSTATUSEND", "OTHERSTART", "OTHEREND",
  "OTHERRESULTSSTART", "OTHERRESULTSEND", "OTHERSOLUTIONRESULTSTART",
  "OTHERSOLUTIONRESULTEND", "OTHERSOLUTIONRESULTSSTART",
  "OTHERSOLUTIONRESULTSEND", "OTHERSOLVEROUTPUTSTART",
  "OTHERSOLVEROUTPUTEND", "SCHEDULEDSTARTTIMESTART",
  "SCHEDULEDSTARTTIMEEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICEUTILIZATIONSTART",
  "SERVICEUTILIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND",
  "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND", "SOLVEROUTPUTSTART",
  "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND", "SUBMITTIMESTART",
  "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND", "SUPERBASICSTART",
  "SUPERBASICEND", "SYSTEMINFORMATIONSTART", "SYSTEMINFORMATIONEND",
  "TIMESTART", "TIMEEND", "TIMESERVICESTARTEDSTART",
  "TIMESERVICESTARTEDEND", "TIMESTAMPSTART", "TIMESTAMPEND",
  "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND", "TOTALJOBSSOFARSTART",
  "TOTALJOBSSOFAREND", "UNKNOWNSTART", "UNKNOWNEND", "USEDCPUNUMBERSTART",
  "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART", "USEDCPUSPEEDEND",
  "USEDDISKSPACESTART", "USEDDISKSPACEEND", "USEDMEMORYSTART",
  "USEDMEMORYEND", "VALUESSTART", "VALUESEND", "VALUESSTRINGSTART",
  "VALUESSTRINGEND", "VARSTART", "VAREND", "VARIABLESSTART",
  "VARIABLESEND", "VARIDXSTART", "VARIDXEND", "MATRIXSTART", "MATRIXEND",
  "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND",
  "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT", "SYMMETRYATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlStartEmpty", "osrlStart", "osrlAttributes",
  "osrlContent", "osrlEmpty", "osrlLaden", "osrlEnd", "osrlEnding",
  "osrlBody", "headerElement", "generalElement", "generalElementStart",
  "generalElementContent", "generalElementEmpty", "generalElementLaden",
  "generalElementBody", "generalElementList", "generalChild",
  "generalStatus", "generalStatusStart", "generalStatusAttributes",
  "generalStatusAttList", "generalStatusATT", "generalStatusContent",
  "generalStatusEmpty", "generalStatusLaden", "generalStatusBody",
  "generalSubstatusArray", "generalSubstatus", "generalSubstatusStart",
  "generalSubstatusAttributes", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusEnd", "generalMessage",
  "generalMessageStart", "generalMessageContent", "generalMessageEmpty",
  "generalMessageLaden", "generalMessageBody", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty",
  "jobIDLaden", "jobIDBody", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "solverInvokedEmpty", "solverInvokedLaden",
  "solverInvokedBody", "timeStamp", "timeStampStart", "timeStampContent",
  "timeStampEmpty", "timeStampLaden", "timeStampBody",
  "otherGeneralResults", "otherGeneralResultsStart",
  "otherGeneralResultsAttributes", "otherGeneralResultsContent",
  "otherGeneralResultsEmpty", "otherGeneralResultsLaden",
  "otherGeneralResultsBody", "otherGeneralResultArray",
  "otherGeneralResult", "otherGeneralResultStart",
  "otherGeneralResultAttributes", "otherGeneralResultAttList",
  "otherGeneralResultAtt", "otherGeneralResultEnd", "systemElement",
  "systemElementStart", "systemElementContent", "systemElementEmpty",
  "systemElementLaden", "systemElementBody", "systemElementList",
  "systemChild", "systemInformation", "systemInformationStart",
  "systemInformationContent", "systemInformationEmpty",
  "systemInformationLaden", "systemInformationBody", "availableDiskSpace",
  "availableDiskSpaceStart", "availableDiskSpaceAttributes",
  "availableDiskSpaceAttList", "availableDiskSpaceAtt",
  "availableDiskSpaceContent", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryStart", "availableMemoryAttributes",
  "availableMemoryAttList", "availableMemoryAtt", "availableMemoryContent",
  "availableMemoryValue", "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttributes", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedContent",
  "availableCPUSpeedValue", "availableCPUNumber",
  "availableCPUNumberStart", "availableCPUNumberAttributes",
  "availableCPUNumberContent", "availableCPUNumberValue",
  "otherSystemResults", "otherSystemResultsStart",
  "otherSystemResultsAttributes", "otherSystemResultsContent",
  "otherSystemResultsEmpty", "otherSystemResultsLaden",
  "otherSystemResultsBody", "otherSystemResultArray", "otherSystemResult",
  "otherSystemResultStart", "otherSystemResultAttributes",
  "otherSystemResultAttList", "otherSystemResultAtt",
  "otherSystemResultEnd", "serviceElement", "serviceElementStart",
  "serviceElementContent", "serviceElementEmpty", "serviceElementLaden",
  "serviceElementBody", "serviceElementList", "serviceChild",
  "currentState", "currentStateStart", "currentStateContent",
  "currentStateEmpty", "currentStateLaden", "currentStateBody",
  "currentJobCount", "currentJobCountStart", "currentJobCountContent",
  "currentJobCountEmpty", "currentJobCountLaden", "currentJobCountBody",
  "totalJobsSoFar", "totalJobsSoFarStart", "totalJobsSoFarContent",
  "totalJobsSoFarEmpty", "totalJobsSoFarLaden", "totalJobsSoFarBody",
  "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedLaden", "timeServiceStartedBody",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceUtilizationEmpty",
  "serviceUtilizationLaden", "serviceUtilizationBody",
  "otherServiceResults", "otherServiceResultsStart",
  "otherServiceResultsAttributes", "otherServiceResultsContent",
  "otherServiceResultsEmpty", "otherServiceResultsLaden",
  "otherServiceResultsBody", "otherServiceResultArray",
  "otherServiceResult", "otherServiceResultStart",
  "otherServiceResultAttributes", "otherServiceResultAttList",
  "otherServiceResultAtt", "otherServiceResultEnd", "jobElement",
  "jobElementStart", "jobElementContent", "jobElementEmpty",
  "jobElementLaden", "jobElementBody", "jobElementList", "jobChild",
  "jobStatus", "jobStatusStart", "jobStatusContent", "jobStatusEmpty",
  "jobStatusLaden", "jobStatusBody", "submitTime", "submitTimeStart",
  "submitTimeContent", "submitTimeEmpty", "submitTimeLaden",
  "submitTimeBody", "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "scheduledStartTimeEmpty",
  "scheduledStartTimeLaden", "scheduledStartTimeBody", "actualStartTime",
  "actualStartTimeStart", "actualStartTimeContent", "actualStartTimeEmpty",
  "actualStartTimeLaden", "actualStartTimeBody", "endTime", "endTimeStart",
  "endTimeContent", "endTimeEmpty", "endTimeLaden", "endTimeBody",
  "timingInformation", "timingInformationStart",
  "timingInformationAttributes", "timingInformationContent",
  "timingInformationEmpty", "timingInformationLaden",
  "timingInformationBody", "timeArray", "time", "timeStart",
  "timeAttributes", "timeAtt", "timeContent", "timeEmpty", "timeLaden",
  "timeBody", "timeValue", "usedDiskSpace", "usedDiskSpaceStart",
  "usedDiskSpaceAttributes", "usedDiskSpaceAttList", "usedDiskSpaceAtt",
  "usedDiskSpaceContent", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryStart", "usedMemoryAttributes", "usedMemoryAttList",
  "usedMemoryAtt", "usedMemoryContent", "usedMemoryValue", "usedCPUSpeed",
  "usedCPUSpeedStart", "usedCPUSpeedAttributes", "usedCPUSpeedAttList",
  "usedCPUSpeedAtt", "usedCPUSpeedContent", "usedCPUSpeedValue",
  "usedCPUNumber", "usedCPUNumberStart", "usedCPUNumberAttributes",
  "usedCPUNumberContent", "usedCPUNumberValue", "otherJobResults",
  "otherJobResultsStart", "otherJobResultsAttributes",
  "otherJobResultsContent", "otherJobResultsEmpty", "otherJobResultsLaden",
  "otherJobResultsBody", "otherJobResultArray", "otherJobResult",
  "otherJobResultStart", "otherJobResultAttributes",
  "otherJobResultAttList", "otherJobResultAtt", "otherJobResultEnd",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "solutionArray", "solution", "solutionStart", "solutionAttributes",
  "solutionAttList", "solutionATT", "targetObjectiveIdxATT",
  "targetObjectiveNameATT", "weightedObjectivesATT", "solutionContent",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusLaden", "solutionStatusBody",
  "solutionSubstatusArray", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusEnd", "solutionMessage",
  "solutionMessageStart", "solutionMessageContent", "solutionMessageEmpty",
  "solutionMessageLaden", "solutionMessageBody", "variables",
  "variablesStart", "numberOfOtherVariableResults", "variablesContent",
  "variablesEmpty", "variablesLaden", "variablesBody", "variableValues",
  "variableValuesStart", "numberOfVarATT", "variableValuesContent",
  "variableValuesEmpty", "variableValuesLaden", "variableValuesBody",
  "varValueArray", "varValue", "varValueStart", "varValueAttList",
  "varValueAtt", "varValueContent", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringLaden", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varValueStringAttList", "varValueStringAtt", "varValueStringContent",
  "varValueStringEmpty", "varValueStringLaden", "varValueStringBody",
  "variableBasisStatus", "variableBasisStatusStart",
  "variableBasisStatusContent", "variableBasisStatusEmpty",
  "variableBasisStatusLaden", "variableBasisStatusBody", "variablesBasic",
  "variablesBasicStart", "variablesBasicNumberOfElATT",
  "variablesBasicContent", "variablesBasicEmpty", "variablesBasicLaden",
  "variablesBasicBody", "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesAtEquality", "variablesAtEqualityStart",
  "variablesAtEqualityNumberOfElATT", "variablesAtEqualityContent",
  "variablesAtEqualityEmpty", "variablesAtEqualityLaden",
  "variablesAtEqualityBody", "variablesIsFree", "variablesIsFreeStart",
  "variablesIsFreeNumberOfElATT", "variablesIsFreeContent",
  "variablesIsFreeEmpty", "variablesIsFreeLaden", "variablesIsFreeBody",
  "variablesSuperbasic", "variablesSuperbasicStart",
  "variablesSuperbasicNumberOfElATT", "variablesSuperbasicContent",
  "variablesSuperbasicEmpty", "variablesSuperbasicLaden",
  "variablesSuperbasicBody", "variablesUnknown", "variablesUnknownStart",
  "variablesUnknownNumberOfElATT", "variablesUnknownContent",
  "variablesUnknownEmpty", "variablesUnknownLaden", "variablesUnknownBody",
  "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "otherVariableResultContent", "otherVariableResultEmpty",
  "otherVariableResultLaden", "otherVariableResultBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarAttList", "otherVarAtt",
  "otherVarContent", "otherVarEmpty", "otherVarLaden", "otherVarBody",
  "otherVarEnumerationList", "otherVarEnumeration",
  "otherVarEnumerationStart", "otherVarEnumerationAttributes",
  "otherVarEnumerationAttList", "otherVarEnumerationATT",
  "otherVarEnumerationContent", "otherVarEnumerationEmpty",
  "otherVarEnumerationLaden", "otherVarEnumerationBody", "objectives",
  "objectivesStart", "numberOfOtherObjectiveResults", "objectivesContent",
  "objectivesEmpty", "objectivesLaden", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesLaden",
  "objectiveValuesBody", "objValueArray", "objValue", "objValueStart",
  "objValueAttList", "objValueAtt", "objValueContent",
  "objectiveBasisStatus", "objectiveBasisStatusStart",
  "objectiveBasisStatusContent", "objectiveBasisStatusEmpty",
  "objectiveBasisStatusLaden", "objectiveBasisStatusBody",
  "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesAtEquality",
  "objectivesAtEqualityStart", "objectivesAtEqualityNumberOfElATT",
  "objectivesAtEqualityContent", "objectivesAtEqualityEmpty",
  "objectivesAtEqualityLaden", "objectivesAtEqualityBody",
  "objectivesIsFree", "objectivesIsFreeStart",
  "objectivesIsFreeNumberOfElATT", "objectivesIsFreeContent",
  "objectivesIsFreeEmpty", "objectivesIsFreeLaden", "objectivesIsFreeBody",
  "objectivesSuperbasic", "objectivesSuperbasicStart",
  "objectivesSuperbasicNumberOfElATT", "objectivesSuperbasicContent",
  "objectivesSuperbasicEmpty", "objectivesSuperbasicLaden",
  "objectivesSuperbasicBody", "objectivesUnknown",
  "objectivesUnknownStart", "objectivesUnknownNumberOfElATT",
  "objectivesUnknownContent", "objectivesUnknownEmpty",
  "objectivesUnknownLaden", "objectivesUnknownBody",
  "otherObjectiveResultsArray", "otherObjectiveResult",
  "otherObjectiveResultStart", "otherObjectiveResultAttributes",
  "otherObjectiveResultAttList", "otherObjectiveResultATT",
  "otherObjectiveResultContent", "otherObjectiveResultEmpty",
  "otherObjectiveResultLaden", "otherObjectiveResultBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjAttList", "otherObjAtt",
  "otherObjContent", "otherObjEmpty", "otherObjLaden", "otherObjBody",
  "otherObjEnumerationList", "otherObjEnumeration",
  "otherObjEnumerationStart", "otherObjEnumerationAttributes",
  "otherObjEnumerationAttList", "otherObjEnumerationATT",
  "otherObjEnumerationContent", "otherObjEnumerationEmpty",
  "otherObjEnumerationLaden", "otherObjEnumerationBody", "constraints",
  "constraintsStart", "numberOfOtherConstraintResults",
  "constraintsContent", "constraintsEmpty", "constraintsLaden",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesLaden",
  "dualValuesBody", "dualValueArray", "dualValue", "dualValueStart",
  "dualValueAttList", "dualValueAtt", "dualValueContent",
  "slackBasisStatus", "slackBasisStatusStart", "slackBasisStatusContent",
  "slackBasisStatusEmpty", "slackBasisStatusLaden", "slackBasisStatusBody",
  "slacksBasic", "slacksBasicStart", "slacksBasicNumberOfElATT",
  "slacksBasicContent", "slacksBasicEmpty", "slacksBasicLaden",
  "slacksBasicBody", "slacksAtLower", "slacksAtLowerStart",
  "slacksAtLowerNumberOfElATT", "slacksAtLowerContent",
  "slacksAtLowerEmpty", "slacksAtLowerLaden", "slacksAtLowerBody",
  "slacksAtUpper", "slacksAtUpperStart", "slacksAtUpperNumberOfElATT",
  "slacksAtUpperContent", "slacksAtUpperEmpty", "slacksAtUpperLaden",
  "slacksAtUpperBody", "slacksAtEquality", "slacksAtEqualityStart",
  "slacksAtEqualityNumberOfElATT", "slacksAtEqualityContent",
  "slacksAtEqualityEmpty", "slacksAtEqualityLaden", "slacksAtEqualityBody",
  "slacksIsFree", "slacksIsFreeStart", "slacksIsFreeNumberOfElATT",
  "slacksIsFreeContent", "slacksIsFreeEmpty", "slacksIsFreeLaden",
  "slacksIsFreeBody", "slacksSuperbasic", "slacksSuperbasicStart",
  "slacksSuperbasicNumberOfElATT", "slacksSuperbasicContent",
  "slacksSuperbasicEmpty", "slacksSuperbasicLaden", "slacksSuperbasicBody",
  "slacksUnknown", "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintResultsArray",
  "otherConstraintResult", "otherConstraintResultStart",
  "otherConstraintResultAttributes", "otherConstraintResultAttList",
  "otherConstraintResultATT", "otherConstraintResultContent",
  "otherConstraintResultEmpty", "otherConstraintResultLaden",
  "otherConstraintResultBody", "otherConList", "otherCon", "otherConStart",
  "otherConAttList", "otherConAtt", "otherConContent", "otherConEmpty",
  "otherConLaden", "otherConBody", "otherConEnumerationList",
  "otherConEnumeration", "otherConEnumerationStart",
  "otherConEnumerationAttributes", "otherConEnumerationAttList",
  "otherConEnumerationATT", "otherConEnumerationContent",
  "otherConEnumerationEmpty", "otherConEnumerationLaden",
  "otherConEnumerationBody", "otherSolutionResults",
  "otherSolutionResultsStart", "numberOfOtherSolutionResults",
  "otherSolutionResultsContent", "otherSolutionResultsEmpty",
  "otherSolutionResultsLaden", "otherSolutionResultsBody",
  "otherSolutionResultArray", "otherSolutionResult",
  "otherSolutionResultStart", "otherSolutionResultAttributes",
  "otherSolutionResultAttList", "otherSolutionResultAtt",
  "otherSolutionResultContent", "otherSolutionResultEmpty",
  "otherSolutionResultLaden", "otherSolutionResultBody",
  "otherSolutionResultItemArray", "otherSolutionResultItem",
  "otherSolutionResultItemContent", "otherSolutionResultItemEmpty",
  "otherSolutionResultItemLaden", "otherSolutionResultItemBody",
  "otherSolverOutput", "otherSolverOutputStart",
  "numberOfSolverOutputsATT", "otherSolverOutputContent",
  "otherSolverOutputEmpty", "otherSolverOutputLaden",
  "otherSolverOutputBody", "solverOutputArray", "solverOutput",
  "solverOutputStart", "solverOutputAttributes", "solverOutputAttList",
  "solverOutputAtt", "solverOutputContent", "solverOutputEmpty",
  "solverOutputLaden", "solverOutputBody", "solverOutputItemArray",
  "solverOutputItem", "solverOutputItemContent", "solverOutputItemEmpty",
  "solverOutputItemLaden", "solverOutputItemBody", "categoryAttribute",
  "categoryAtt", "categoryAttEmpty", "categoryAttContent",
  "conTypeAttribute", "conTypeAtt", "conTypeAttEmpty", "conTypeAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "enumTypeAttribute", "enumTypeAtt",
  "enumTypeAttEmpty", "enumTypeAttContent", "idxAttribute",
  "nameAttribute", "nameAtt", "nameAttEmpty", "nameAttContent",
  "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty", "objTypeAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "unitAttribute", "unitAtt", "unitAttEmpty", "unitAttContent",
  "valueAttribute", "valueAtt", "valueAttEmpty", "valueAttContent",
  "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty", "varTypeAttContent",
  "numberOfConAttribute", "numberOfConstraintsAttribute",
  "numberOfElAttribute", "numberOfEnumerationsAttribute",
  "numberOfItemsAttribute", "numberOfObjAttribute",
  "numberOfObjectivesAttribute", "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherResultsAttribute", "numberOfOtherSolutionResultsAttribute",
  "numberOfOtherVariableResultsAttribute", "numberOfSolutionsAttribute",
  "numberOfSolverOutputsAttribute", "numberOfSubstatusesAttribute",
  "numberOfTimesAttribute", "numberOfVarAttribute",
  "numberOfVariablesAttribute", "aNumber", "ElementValue", "quote",
  "xmlWhiteSpace", "xmlWhiteSpaceChar", "osglFileHeader",
  "headerElementStart", "headerElementContent", "headerElementEmpty",
  "headerElementLaden", "headerElementBody", "headerElementList",
  "headerChild", "fileName", "fileNameContent", "fileNameEmpty",
  "fileNameLaden", "fileSource", "fileSourceContent", "fileSourceEmpty",
  "fileSourceLaden", "fileDescription", "fileDescriptionContent",
  "fileDescriptionEmpty", "fileDescriptionLaden", "fileCreator",
  "fileCreatorContent", "fileCreatorEmpty", "fileCreatorLaden",
  "fileLicence", "fileLicenceContent", "fileLicenceEmpty",
  "fileLicenceLaden", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute", 0
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
     505,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   255,   256,   256,   257,   258,   259,   259,   260,   260,
     261,   262,   263,   264,   264,   265,   266,   266,   267,   267,
     268,   269,   269,   270,   270,   271,   272,   273,   273,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   275,   276,
     277,   278,   278,   279,   279,   279,   280,   280,   281,   281,
     282,   283,   284,   284,   285,   286,   287,   288,   288,   289,
     289,   290,   290,   291,   292,   293,   293,   294,   294,   295,
     296,   297,   298,   299,   299,   300,   300,   301,   302,   303,
     304,   305,   305,   306,   306,   307,   308,   309,   310,   311,
     311,   312,   312,   313,   314,   315,   316,   317,   317,   318,
     318,   319,   320,   321,   322,   323,   323,   324,   324,   325,
     326,   327,   328,   329,   329,   330,   330,   331,   332,   333,
     334,   335,   336,   336,   337,   337,   338,   339,   340,   340,
     341,   342,   343,   344,   344,   345,   345,   345,   346,   346,
     347,   347,   348,   349,   349,   350,   350,   351,   352,   353,
     353,   354,   354,   354,   354,   354,   354,   355,   356,   357,
     357,   358,   358,   359,   360,   361,   362,   363,   364,   364,
     365,   365,   366,   367,   368,   369,   370,   371,   371,   372,
     372,   373,   374,   375,   376,   377,   378,   378,   379,   379,
     380,   381,   382,   383,   384,   384,   385,   386,   387,   388,
     389,   390,   390,   391,   391,   392,   393,   394,   394,   395,
     396,   397,   398,   398,   399,   399,   399,   400,   400,   401,
     401,   402,   403,   403,   404,   404,   405,   406,   407,   407,
     408,   408,   408,   408,   408,   408,   409,   410,   411,   411,
     412,   412,   413,   414,   415,   416,   417,   417,   418,   418,
     419,   420,   421,   422,   423,   423,   424,   424,   425,   426,
     427,   428,   429,   429,   430,   430,   431,   432,   433,   434,
     435,   435,   436,   436,   437,   438,   439,   440,   441,   442,
     442,   443,   443,   444,   445,   446,   446,   447,   448,   449,
     450,   450,   451,   451,   451,   452,   452,   453,   453,   454,
     455,   455,   456,   456,   457,   458,   459,   459,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   461,
     462,   463,   463,   464,   464,   465,   466,   467,   468,   469,
     469,   470,   470,   471,   472,   473,   474,   475,   475,   476,
     476,   477,   478,   479,   480,   481,   481,   482,   482,   483,
     484,   485,   486,   487,   487,   488,   488,   489,   490,   491,
     492,   493,   494,   494,   495,   495,   496,   497,   498,   498,
     499,   500,   501,   501,   502,   502,   502,   502,   503,   503,
     504,   504,   505,   506,   507,   507,   508,   509,   510,   511,
     511,   512,   512,   513,   514,   515,   516,   517,   518,   518,
     519,   519,   520,   521,   522,   523,   524,   525,   525,   526,
     526,   527,   528,   529,   530,   531,   531,   532,   533,   534,
     535,   536,   537,   537,   538,   538,   539,   540,   541,   541,
     542,   543,   544,   545,   545,   546,   546,   546,   547,   547,
     548,   548,   549,   550,   551,   551,   552,   552,   552,   552,
     553,   553,   554,   554,   555,   556,   557,   557,   558,   559,
     560,   561,   561,   562,   562,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   570,   571,   571,   571,   572,   572,
     573,   573,   574,   575,   576,   576,   577,   578,   579,   580,
     580,   581,   581,   582,   582,   583,   583,   584,   585,   585,
     586,   586,   587,   588,   589,   589,   590,   591,   591,   592,
     592,   593,   594,   595,   596,   596,   597,   598,   599,   599,
     600,   600,   601,   602,   603,   603,   604,   605,   606,   606,
     607,   607,   608,   609,   609,   610,   611,   612,   612,   613,
     613,   614,   615,   616,   616,   617,   618,   619,   619,   620,
     620,   621,   621,   622,   622,   623,   624,   625,   625,   626,
     627,   627,   628,   629,   630,   631,   631,   632,   633,   634,
     634,   635,   636,   637,   638,   638,   639,   640,   641,   641,
     642,   643,   644,   645,   645,   646,   647,   648,   648,   649,
     650,   651,   652,   652,   653,   654,   655,   655,   656,   657,
     658,   659,   659,   660,   661,   662,   662,   663,   664,   665,
     666,   666,   667,   668,   669,   669,   670,   671,   672,   673,
     673,   674,   675,   676,   676,   677,   678,   679,   680,   680,
     681,   682,   683,   684,   684,   685,   685,   685,   685,   685,
     685,   685,   685,   686,   686,   687,   687,   688,   689,   689,
     690,   690,   691,   692,   693,   693,   694,   694,   695,   695,
     696,   696,   697,   698,   699,   699,   700,   701,   702,   703,
     703,   704,   704,   704,   705,   705,   706,   707,   708,   709,
     709,   710,   711,   711,   712,   712,   713,   714,   715,   716,
     716,   717,   718,   719,   719,   720,   720,   721,   722,   723,
     723,   724,   725,   726,   726,   727,   727,   728,   729,   729,
     730,   731,   731,   732,   733,   734,   735,   735,   736,   737,
     738,   738,   739,   740,   741,   742,   742,   743,   744,   745,
     745,   746,   747,   748,   749,   749,   750,   751,   752,   752,
     753,   754,   755,   756,   756,   757,   758,   759,   759,   760,
     761,   762,   763,   763,   764,   765,   766,   766,   767,   768,
     769,   770,   770,   771,   772,   773,   773,   774,   775,   776,
     777,   777,   778,   779,   780,   780,   781,   782,   783,   784,
     784,   785,   786,   787,   788,   788,   789,   789,   789,   789,
     789,   789,   789,   789,   790,   790,   791,   791,   792,   793,
     793,   794,   794,   795,   796,   797,   797,   798,   798,   799,
     799,   800,   800,   801,   802,   803,   803,   804,   805,   806,
     807,   807,   808,   808,   808,   809,   809,   810,   811,   812,
     813,   813,   814,   815,   815,   816,   816,   817,   818,   819,
     820,   820,   821,   822,   823,   823,   824,   824,   825,   826,
     827,   827,   828,   829,   830,   830,   831,   831,   832,   833,
     833,   834,   835,   835,   836,   837,   838,   839,   839,   840,
     841,   842,   842,   843,   844,   845,   846,   846,   847,   848,
     849,   849,   850,   851,   852,   853,   853,   854,   855,   856,
     856,   857,   858,   859,   860,   860,   861,   862,   863,   863,
     864,   865,   866,   867,   867,   868,   869,   870,   870,   871,
     872,   873,   874,   874,   875,   876,   877,   877,   878,   879,
     880,   881,   881,   882,   883,   884,   884,   885,   886,   887,
     888,   888,   889,   890,   891,   892,   892,   893,   893,   893,
     893,   893,   893,   893,   893,   894,   894,   895,   895,   896,
     897,   897,   898,   898,   899,   900,   901,   901,   902,   902,
     903,   903,   904,   904,   905,   906,   907,   907,   908,   909,
     910,   911,   911,   912,   912,   912,   913,   913,   914,   915,
     916,   917,   917,   918,   919,   920,   920,   921,   921,   922,
     923,   924,   924,   925,   926,   927,   928,   928,   929,   929,
     929,   929,   929,   930,   930,   931,   931,   932,   933,   934,
     934,   935,   936,   936,   937,   937,   938,   939,   940,   940,
     941,   942,   943,   943,   944,   944,   945,   946,   947,   947,
     948,   949,   950,   951,   951,   952,   952,   952,   952,   953,
     953,   954,   954,   955,   956,   957,   957,   958,   959,   959,
     960,   960,   961,   962,   963,   964,   964,   965,   966,   967,
     968,   968,   969,   970,   971,   972,   972,   973,   974,   975,
     976,   976,   977,   978,   979,   980,   981,   981,   982,   983,
     984,   985,   985,   986,   987,   988,   989,   989,   990,   991,
     992,   993,   993,   994,   995,   996,   997,   997,   998,   999,
    1000,  1001,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1022,  1023,  1023,  1023,  1024,  1025,
    1025,  1026,  1026,  1026,  1026,  1027,  1028,  1029,  1029,  1030,
    1030,  1031,  1032,  1033,  1033,  1034,  1034,  1034,  1034,  1034,
    1035,  1035,  1036,  1036,  1037,  1037,  1038,  1039,  1039,  1040,
    1040,  1041,  1041,  1042,  1043,  1043,  1044,  1044,  1045,  1045,
    1046,  1047,  1047,  1048,  1048,  1049,  1049,  1050,  1051,  1051,
    1052,  1052,  1053,  1053,  1054,  1055,  1055,  1056,  1056,  1057,
    1058,  1059,  1060,  1060,  1061,  1061,  1062,  1063,  1064,  1065,
    1065,  1066,  1066,  1067,  1068,  1069
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     0,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     4,     3,     3,     8,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     4,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     3,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     3,     7,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     0,     1,     1,     1,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     2,     1,     1,     3,     0,     2,
       1,     1,     1,     1,     3,     7,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     0,     2,     1,     1,     3,     0,
       2,     1,     1,     1,     1,     3,     7,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     4,     1,
       1,     2,     1,     3,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1136,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   140,     0,
       0,  1140,  1135,  1137,  1138,    16,    10,     3,     8,     9,
     142,   219,     0,     0,    24,    19,    21,    22,  1139,     0,
    1155,  1154,     0,  1162,  1161,     0,  1169,  1168,     0,  1176,
    1175,     0,  1183,  1182,     0,  1142,  1143,  1145,  1151,  1152,
    1153,  1146,  1158,  1159,  1160,  1147,  1165,  1166,  1167,  1148,
    1172,  1173,  1174,  1149,  1179,  1180,  1181,    14,   221,   297,
       0,     0,   146,   141,   143,   144,    23,    39,    88,    96,
      64,   120,    80,    72,   104,   112,     0,    26,    27,    29,
       0,    30,     0,    31,     0,    32,     0,    33,     0,    34,
       0,    35,     0,    36,     0,    37,     0,     0,     0,     0,
       0,     0,  1141,  1144,    11,   299,   440,     0,     0,   225,
     220,   222,   223,   145,   193,   184,   166,   175,   199,   158,
       0,   148,   149,   151,     0,   152,   168,   153,   177,   154,
     186,   155,   194,   156,     0,    25,    28,  1129,     0,  1067,
       0,  1088,     0,    40,    41,    44,  1064,  1065,  1066,    43,
    1085,  1086,  1087,    45,     0,    68,    63,    65,    66,     0,
      76,    71,    73,    74,     0,    84,    79,    81,    82,     0,
      92,    87,    89,    90,     0,   100,    95,    97,    98,     0,
     108,   103,   105,   106,     0,   116,   111,   113,   114,  1129,
       0,   121,  1156,  1163,  1170,  1177,  1184,   442,    15,   444,
       0,   303,   298,   300,   301,   224,   245,   237,   277,   269,
     261,   253,     0,   227,   228,   230,     0,   231,     0,   232,
       0,   233,     0,   234,     0,   235,     0,   147,   150,     0,
     162,   157,   159,   160,     0,   167,     0,   176,     0,   185,
       0,   195,     0,   200,     0,     0,  1129,  1129,     0,    49,
      38,    46,    47,    42,    70,    67,     0,    78,    75,     0,
      86,    83,     0,    94,    91,     0,   102,    99,     0,   110,
     107,     0,   118,   115,     0,     0,     0,   125,   119,   122,
     123,     0,   443,   302,   344,   352,   420,   336,   320,   328,
     360,   414,   405,   387,   396,     0,   305,   306,   308,     0,
     309,     0,   310,     0,   311,     0,   312,     0,   313,     0,
     314,   389,   315,   398,   316,   407,   317,   415,   318,     0,
     226,   229,     0,   241,   236,   238,   239,     0,   249,   244,
     246,   247,     0,   257,   252,   254,   255,     0,   265,   260,
     262,   263,     0,   273,   268,   270,   271,     0,   278,   164,
     161,     0,     0,   165,     0,  1093,   169,   171,   170,  1090,
    1091,  1092,     0,   174,   178,   180,   179,     0,   183,   187,
     189,   188,     0,   192,     0,   204,   198,   201,   202,  1129,
    1128,  1131,  1132,  1133,  1134,  1130,  1068,  1089,    48,    55,
       0,    51,    52,    57,    69,    77,    85,    93,   101,   109,
     117,  1129,   131,   124,     0,   127,   128,   133,     0,   453,
     441,   450,   451,  1129,  1129,  1129,  1129,   445,   448,   449,
     446,   447,   304,   307,     0,   324,   319,   321,   322,     0,
     332,   327,   329,   330,     0,   340,   335,   337,   338,     0,
     348,   343,   345,   346,     0,   356,   351,   353,   354,  1129,
       0,   361,     0,   388,     0,   397,     0,   406,     0,   416,
       0,   421,   243,   240,     0,   251,   248,     0,   259,   256,
       0,   267,   264,     0,  1123,  1124,   272,     0,   275,     0,
     282,   276,   279,   280,   163,     0,   173,  1129,     0,   182,
       0,   191,   197,     0,   210,   203,     0,   206,   207,   212,
    1119,    50,    53,     0,    56,  1114,   126,   129,     0,   132,
     452,   459,     0,  1018,   456,   461,     0,     0,     0,     0,
     326,   323,     0,   334,   331,     0,   342,   339,     0,   350,
     347,     0,   358,   355,     0,     0,     0,   365,   359,   362,
     363,     0,   386,   390,   392,   391,     0,   395,   399,   401,
     400,     0,   404,   408,   410,   409,     0,   413,     0,   425,
     419,   422,   423,   242,   250,   258,   266,   274,   288,   281,
       0,   284,   285,   290,   172,  1094,   181,   190,   196,   205,
     208,     0,   211,     0,    62,    54,     0,  1078,    58,    60,
      59,  1075,  1076,  1077,     0,   139,   130,     0,  1098,   134,
     137,   135,   136,  1095,  1096,  1097,   454,  1020,   457,   455,
       0,     0,   460,  1129,  1129,  1129,  1129,   325,   333,   341,
     349,   357,  1129,   371,   364,     0,   367,   368,   372,     0,
     394,     0,   403,     0,   412,   418,     0,   431,   424,     0,
     427,   428,   433,   283,   286,     0,   289,     0,   218,   209,
     213,   216,   214,   215,    61,  1129,   138,  1129,  1129,     0,
    1021,     0,   458,  1129,     0,     0,   462,   463,   464,   465,
    1106,  1111,  1117,  1122,  1120,   366,   369,     0,   393,   402,
     411,   417,   426,   429,     0,   432,     0,   296,   287,   291,
     294,   292,   293,   217,  1079,  1099,     0,     0,  1025,  1019,
    1022,  1023,   471,   495,     0,     0,  1129,  1129,     0,   381,
       0,  1057,   373,   370,   378,   379,   376,  1054,  1055,  1056,
     377,   375,   374,     0,   439,   430,   434,   437,   435,   436,
     295,  1129,  1024,  1031,     0,  1027,  1028,  1033,   497,   504,
       0,     0,   472,   473,   476,   475,   477,  1129,   468,   467,
     385,   384,   380,     0,   383,  1129,   438,  1118,  1026,  1029,
       0,  1032,   506,   679,   507,     0,   501,   496,   498,   499,
       0,   481,   470,   478,   479,   474,   466,   382,  1058,     0,
    1042,  1030,  1039,  1040,  1129,  1034,  1036,  1037,  1035,  1038,
     681,   830,   682,  1129,     0,   508,   503,   500,     0,   480,
     487,     0,   483,   484,   489,     0,  1050,  1051,  1041,     0,
    1044,  1045,  1047,  1048,  1049,     0,   832,   981,   833,  1129,
       0,   683,     0,   514,   511,   505,   509,   510,   502,   482,
     485,     0,   488,  1053,     0,  1043,  1046,  1129,   983,     0,
       0,  1129,     0,   834,     0,   689,   686,   680,   684,   685,
    1129,   516,     0,   533,     0,     0,   494,   486,   490,   492,
     491,  1052,  1109,   469,  1129,     0,   984,     0,   840,   837,
     831,   835,   836,  1129,   691,     0,   708,     0,  1116,   512,
     535,   557,     0,  1129,     0,   517,   493,     0,     0,   988,
     982,   985,   986,  1129,   842,     0,   859,     0,  1113,   687,
     710,   779,     0,  1129,     0,   692,   559,   628,     0,     0,
     536,     0,     0,   521,   515,   518,   519,  1129,   994,   987,
       0,   990,   991,   996,  1112,   838,   861,   930,     0,  1129,
       0,   843,   688,   716,   713,   709,   711,   712,     0,     0,
     696,   690,   693,   694,   513,   565,   562,   558,   560,   561,
       0,   540,   534,   537,   538,  1129,   520,   527,     0,   523,
     524,   528,  1115,   989,   992,     0,   995,   839,   867,   864,
     860,   862,   863,     0,     0,   847,   841,   844,   845,   782,
     780,   784,   718,     0,   725,     0,  1129,   702,   695,     0,
     698,   699,   703,   631,   629,   633,   567,     0,   574,     0,
     539,   546,     0,   542,   543,   547,  1121,   522,   525,     0,
       0,  1006,   993,  1003,  1004,   997,  1000,  1001,   998,   999,
    1002,   933,   931,   935,   869,     0,   876,     0,  1129,   853,
     846,     0,   849,   850,   854,     0,   783,   714,   727,   734,
       0,  1129,     0,   719,  1110,   697,   700,     0,     0,   632,
     563,   576,   583,     0,     0,   568,   541,   544,     0,     0,
    1129,   529,   526,   530,   531,     0,  1014,  1015,  1005,     0,
    1008,  1009,  1011,  1012,  1013,     0,   934,   865,   878,   885,
       0,     0,   870,  1105,   848,   851,     0,     0,   797,   781,
     794,   795,  1129,     0,  1072,     0,  1083,   785,   793,   792,
    1069,  1070,  1071,   789,   791,  1080,  1081,  1082,   790,   788,
     787,   786,   736,   743,     0,     0,   728,     0,  1187,   722,
     717,   720,   721,     0,   704,   701,   705,   706,     0,   646,
     630,   643,   644,     0,  1103,   634,   642,   641,   638,   639,
     637,   640,  1100,  1101,  1102,   636,   635,   585,   592,     0,
       0,   577,  1187,   571,   566,   569,   570,     0,   554,   548,
     545,   551,   552,   549,   550,     0,     0,  1017,     0,  1007,
    1010,     0,   948,   932,   945,   946,     0,  1062,   936,   942,
    1059,  1060,  1061,   944,   943,   940,   941,   939,   937,   938,
     887,   894,     0,     0,   879,  1187,   873,   868,   871,   872,
       0,   855,   852,   856,   857,   818,   804,   796,     0,   799,
     801,   805,   800,   815,   820,     0,  1129,  1129,   745,   752,
       0,     0,   737,  1187,   731,   726,   729,   730,  1129,     0,
       0,   724,  1185,  1186,     0,   667,   645,   653,     0,   648,
     650,   654,   649,   664,   669,  1129,   594,   601,     0,     0,
     586,  1187,   580,   575,   578,   579,     0,   573,   556,   553,
       0,   532,  1129,  1016,   955,   969,   947,     0,   950,   952,
     956,   951,   966,   971,  1129,   896,   903,     0,     0,   888,
    1187,   882,   877,   880,   881,     0,   875,     0,   798,   802,
       0,   816,     0,   819,  1129,  1073,  1084,   754,   761,     0,
       0,   746,  1187,   740,   735,   738,   739,     0,   733,  1107,
    1129,     0,   723,  1190,  1188,  1192,   707,   647,   651,     0,
     665,     0,   668,  1104,   603,   610,     0,     0,   595,  1187,
     589,   584,   587,   588,     0,   582,   572,   555,  1074,   949,
     953,     0,   967,     0,   970,  1063,   905,   912,     0,     0,
     897,  1187,   891,   886,   889,   890,     0,   884,   874,   858,
       0,   812,   806,   803,   809,   810,   807,   808,  1187,   827,
     817,   825,   826,   821,   824,   823,   822,  1108,   763,   770,
       0,     0,   755,  1187,   749,   744,   747,   748,     0,   742,
     732,     0,     0,  1202,  1197,  1199,  1200,     0,  1191,     0,
     661,   655,   652,   658,   659,   656,   657,  1187,   676,   666,
     674,   675,   670,   673,   672,   671,   612,   619,     0,     0,
     604,  1187,   598,   593,   596,   597,     0,   591,   581,     0,
     963,   957,   954,   960,   961,   958,   959,  1187,   978,   968,
     976,   977,   972,   975,   974,   973,   914,   921,     0,     0,
     906,  1187,   900,   895,   898,   899,     0,   893,   883,  1125,
    1126,  1127,   811,     0,   814,     0,   829,   772,   715,     0,
       0,   764,  1187,   758,   753,   756,   757,     0,   751,   741,
    1129,     0,  1201,     0,  1189,  1129,  1129,  1193,  1195,  1194,
     660,     0,   663,     0,   678,   621,   564,     0,     0,   613,
    1187,   607,   602,   605,   606,     0,   600,   590,   962,     0,
     965,     0,   980,   923,   866,     0,     0,   915,  1187,   909,
     904,   907,   908,     0,   902,   892,   813,   828,     0,   773,
    1187,   767,   762,   765,   766,     0,   760,   750,  1198,  1203,
       0,     0,     0,   662,   677,     0,   622,  1187,   616,   611,
     614,   615,     0,   609,   599,   964,   979,     0,   924,  1187,
     918,   913,   916,   917,     0,   911,   901,  1187,   776,   771,
     774,   775,     0,   769,   759,  1196,  1129,  1129,  1187,   625,
     620,   623,   624,     0,   618,   608,  1187,   927,   922,   925,
     926,     0,   920,   910,     0,   778,   768,  1204,  1205,     0,
     627,   617,     0,   929,   919,   777,   626,   928
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    96,    97,    98,
      99,   100,   162,   163,   164,   270,   271,   272,   410,   411,
     412,   413,   523,   524,   608,   605,   101,   102,   176,   177,
     178,   276,   103,   104,   181,   182,   183,   279,   105,   106,
     186,   187,   188,   282,   107,   108,   191,   192,   193,   285,
     109,   110,   196,   197,   198,   288,   111,   112,   201,   202,
     203,   291,   113,   114,   206,   207,   208,   294,   115,   116,
     210,   298,   299,   300,   424,   425,   426,   427,   528,   529,
     619,   616,    31,    32,    83,    84,    85,   140,   141,   142,
     143,   144,   251,   252,   253,   371,   145,   146,   254,   255,
     376,   373,   505,   147,   148,   256,   257,   384,   383,   508,
     149,   150,   258,   259,   389,   388,   510,   151,   152,   260,
     393,   513,   153,   154,   262,   396,   397,   398,   516,   517,
     518,   519,   601,   602,   670,   669,    79,    80,   130,   131,
     132,   232,   233,   234,   235,   236,   344,   345,   346,   484,
     237,   238,   349,   350,   351,   487,   239,   240,   354,   355,
     356,   490,   241,   242,   359,   360,   361,   493,   243,   244,
     364,   365,   366,   497,   245,   246,   367,   501,   502,   503,
     590,   591,   592,   593,   665,   666,   709,   708,   126,   127,
     222,   223,   224,   315,   316,   317,   318,   319,   446,   447,
     448,   542,   320,   321,   451,   452,   453,   545,   322,   323,
     456,   457,   458,   548,   324,   325,   461,   462,   463,   551,
     326,   327,   466,   467,   468,   554,   328,   329,   470,   558,
     559,   560,   645,   646,   647,   648,   697,   732,   733,   734,
     735,   773,   774,   330,   331,   472,   473,   563,   562,   649,
     332,   333,   474,   475,   568,   567,   651,   334,   335,   476,
     477,   573,   572,   653,   336,   337,   478,   577,   656,   338,
     339,   480,   580,   581,   582,   659,   660,   661,   662,   704,
     705,   746,   745,   218,   219,   301,   302,   437,   430,   431,
     432,   532,   533,   534,   535,   631,   632,   686,   687,   688,
     689,   682,   723,   724,   761,   762,   763,   792,   793,   794,
     821,   822,   823,   824,   851,   852,   878,   877,   759,   760,
     787,   788,   789,   818,   783,   784,   814,   845,   846,   847,
     872,   873,   874,   904,   934,   935,   936,   978,   979,   980,
     981,  1029,  1081,  1082,   901,   902,   929,   972,   973,   974,
    1022,  1023,  1024,  1025,  1078,  1179,  1180,  1181,  1182,  1280,
     927,   928,   967,   968,   969,  1017,  1018,  1019,  1074,  1174,
    1175,  1176,  1276,  1072,  1073,  1170,  1273,  1274,  1275,  1354,
    1168,  1169,  1269,  1351,  1352,  1353,  1446,  1267,  1268,  1347,
    1443,  1444,  1445,  1525,  1345,  1346,  1439,  1522,  1523,  1524,
    1572,  1437,  1438,  1518,  1569,  1570,  1571,  1603,  1516,  1517,
    1565,  1600,  1601,  1602,  1619,   964,  1014,  1015,  1068,  1069,
    1155,  1150,  1151,  1152,  1258,  1259,  1260,  1261,  1339,  1421,
    1422,  1423,  1424,  1511,  1262,  1263,  1264,  1341,  1342,  1432,
    1429,  1430,  1431,  1513,   811,   812,   840,   867,   868,   869,
     895,   896,   897,   924,   961,   962,   963,  1009,  1010,  1011,
    1012,  1067,  1144,  1145,   921,   922,   955,   956,   957,  1003,
    1004,  1005,  1062,  1140,  1141,  1142,  1250,  1059,  1060,  1135,
    1245,  1246,  1247,  1327,  1133,  1134,  1241,  1324,  1325,  1326,
    1408,  1239,  1240,  1320,  1405,  1406,  1407,  1497,  1318,  1319,
    1401,  1494,  1495,  1496,  1555,  1399,  1400,  1490,  1552,  1553,
    1554,  1592,  1488,  1489,  1548,  1589,  1590,  1591,  1614,   952,
    1000,  1001,  1055,  1056,  1117,  1109,  1110,  1111,  1228,  1229,
    1230,  1231,  1310,  1382,  1383,  1384,  1385,  1483,  1232,  1233,
    1234,  1312,  1313,  1393,  1390,  1391,  1392,  1485,   837,   838,
     862,   890,   891,   892,   915,   916,   917,   950,   996,   997,
     998,  1051,  1052,  1053,  1054,  1106,  1221,  1222,   947,   948,
     990,   991,   992,  1045,  1046,  1047,  1101,  1217,  1218,  1219,
    1305,  1099,  1100,  1213,  1302,  1303,  1304,  1376,  1211,  1212,
    1298,  1373,  1374,  1375,  1476,  1296,  1297,  1369,  1473,  1474,
    1475,  1543,  1367,  1368,  1469,  1540,  1541,  1542,  1584,  1467,
    1468,  1536,  1581,  1582,  1583,  1611,  1534,  1535,  1577,  1608,
    1609,  1610,  1622,   987,  1042,  1043,  1095,  1096,  1198,  1193,
    1194,  1195,  1287,  1288,  1289,  1290,  1361,  1451,  1452,  1453,
    1454,  1529,  1291,  1292,  1293,  1363,  1364,  1462,  1459,  1460,
    1461,  1531,   859,   860,   885,   910,   911,   912,   940,   941,
     942,   943,   985,   986,  1035,  1032,  1033,  1034,  1089,  1090,
    1091,  1092,  1093,  1094,  1188,   629,   630,   679,   719,   720,
     721,   754,   755,   756,   757,   780,   781,   805,   801,   802,
     803,   829,   830,   831,   832,   833,   834,   854,   736,   737,
     738,   739,  1199,  1200,  1201,  1202,   165,   166,   167,   168,
    1119,  1120,  1121,  1122,  1083,   610,   611,   612,   613,  1124,
    1125,  1126,  1127,   169,   170,   171,   172,   378,   379,   380,
     381,   622,   623,   624,   625,  1161,  1162,  1163,  1164,   951,
     438,  1063,  1130,   809,   925,   439,   863,   841,   211,   886,
     815,   440,   680,   173,   471,   905,   441,   498,  1484,   264,
     265,   405,    10,    11,    22,    23,    24,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    1251,  1252,  1334,  1335,  1417,  1418,  1507,  1504,  1253,  1331,
    1414,  1415,  1416,  1508,  1509
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1361
static const yytype_int16 yypact[] =
{
      87, -1361, -1361,    60,    17,    70, -1361, -1361,   101,    56,
   -1361,   212, -1361,   233, -1361, -1361, -1361, -1361,    71,   329,
     581, -1361, -1361, -1361, -1361,    17, -1361, -1361, -1361, -1361,
   -1361,    83,   336,   -26, -1361, -1361, -1361, -1361, -1361,   137,
   -1361, -1361,   155, -1361, -1361,   161, -1361, -1361,   168, -1361,
   -1361,   175, -1361, -1361,    98,   634, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   101, -1361,   109,
     340,   -17, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   116,   166, -1361, -1361,
     403, -1361,   347, -1361,   366, -1361,   387, -1361,   408, -1361,
     431, -1361,   445, -1361,   465, -1361,   163,   147,   149,   108,
     139,   133, -1361, -1361, -1361, -1361,   170,   467,    90, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     182,   -32, -1361, -1361,   475, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,    91, -1361,   163, -1361, -1361, -1361,   256, -1361,
     262, -1361,   477,   403, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,    31, -1361, -1361, -1361, -1361,    28,
   -1361, -1361, -1361, -1361,    42, -1361, -1361, -1361, -1361,    33,
   -1361, -1361, -1361, -1361,    41, -1361, -1361, -1361, -1361,    27,
   -1361, -1361, -1361, -1361,     8, -1361, -1361, -1361, -1361, -1361,
     479, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     172, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   195,   -53, -1361, -1361,   482, -1361,   485, -1361,
     487, -1361,   501, -1361,   504, -1361,   163, -1361, -1361,    13,
   -1361, -1361, -1361, -1361,   268,   112,   273,   112,   275,   112,
     283, -1361,   514, -1361,   294,    -4, -1361, -1361,   -77, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   151, -1361, -1361,   132,
   -1361, -1361,   140, -1361, -1361,   176, -1361, -1361,   162, -1361,
   -1361,   136, -1361, -1361,   158,   358,   124, -1361, -1361, -1361,
   -1361,   516,   414, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   297,   119, -1361, -1361,   533,
   -1361,   535, -1361,   538, -1361,   541, -1361,   549, -1361,   341,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,    91, -1361,   163,
   -1361, -1361,    40, -1361, -1361, -1361, -1361,    44, -1361, -1361,
   -1361, -1361,     1, -1361, -1361, -1361, -1361,     5, -1361, -1361,
   -1361, -1361,    23, -1361, -1361, -1361, -1361,   551, -1361, -1361,
   -1361,   184,   557, -1361,   379, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   557, -1361, -1361, -1361, -1361,   557, -1361, -1361,
   -1361, -1361,   378, -1361,   128, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     248,   201, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   235,   243, -1361, -1361,   -28, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,    20, -1361, -1361, -1361, -1361,    11,
   -1361, -1361, -1361, -1361,    30, -1361, -1361, -1361, -1361,    39,
   -1361, -1361, -1361, -1361,    36, -1361, -1361, -1361, -1361, -1361,
     559, -1361,   398,   112,   401,   112,   422,   112,   426, -1361,
     561, -1361, -1361, -1361,   317, -1361, -1361,   327, -1361, -1361,
     258, -1361, -1361,   267, -1361, -1361, -1361,   293, -1361,   138,
   -1361, -1361, -1361, -1361, -1361,   367, -1361, -1361,   384, -1361,
     371, -1361, -1361,   410, -1361, -1361,   337,   373, -1361, -1361,
   -1361, -1361, -1361,   565,   417, -1361, -1361, -1361,   580,   309,
   -1361, -1361,   453,   -34, -1361, -1361,   532,   534,   548,   567,
   -1361, -1361,   377, -1361, -1361,   389, -1361, -1361,   383, -1361,
   -1361,   503, -1361, -1361,   427,   571,  -109, -1361, -1361, -1361,
   -1361,   557, -1361, -1361, -1361, -1361,   557, -1361, -1361, -1361,
   -1361,   557, -1361, -1361, -1361, -1361,   605, -1361,   146, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     449,   481, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   583,   309,   459, -1361, -1361,   660, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   507, -1361, -1361,   664, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     649,   683,    50, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   497,   506, -1361, -1361,   495,
   -1361,   508, -1361,   520, -1361, -1361,   510, -1361, -1361,   547,
     576, -1361, -1361, -1361, -1361,   588,   309,   615, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   590,
   -1361,   593, -1361, -1361,   778,   780, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   352, -1361, -1361,
   -1361, -1361, -1361, -1361,   592,   309,   620, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   779,  -105, -1361, -1361,
   -1361, -1361, -1361,   633,   403,   781, -1361, -1361,    19, -1361,
     785, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   625, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   618,   606, -1361, -1361, -1361,   569,
     597,   599,   403, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   595, -1361, -1361, -1361, -1361, -1361, -1361,
     603,   489, -1361,   637,   768,    37, -1361, -1361, -1361, -1361,
     145, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,    -7,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   668,   773, -1361,   612, -1361, -1361, -1361,   646, -1361,
   -1361,   611,   610, -1361, -1361,   797, -1361, -1361, -1361,   617,
     177, -1361, -1361, -1361, -1361,   798, -1361,   636,   782, -1361,
     616, -1361,   801,   591, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   624,   152, -1361,   732, -1361, -1361, -1361, -1361,   627,
     786, -1361,   626, -1361,   806,   598, -1361, -1361, -1361, -1361,
   -1361, -1361,   594,   600,   783,   622, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   628, -1361,   811,   688, -1361,
   -1361, -1361, -1361, -1361, -1361,   662,   702,   800, -1361, -1361,
   -1361,   703,   783, -1361,   630, -1361, -1361,   819,   159, -1361,
   -1361, -1361, -1361, -1361, -1361,   698,   706,   812, -1361, -1361,
   -1361, -1361,   632, -1361,   635, -1361, -1361, -1361,   639,   643,
   -1361,   823,   117, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     661,   663, -1361, -1361, -1361, -1361, -1361, -1361,   645, -1361,
     647, -1361,   669,   715, -1361, -1361, -1361, -1361,   829,   -99,
   -1361, -1361, -1361, -1361,   674,   719, -1361, -1361, -1361, -1361,
     439, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   623,   619,
   -1361, -1361, -1361, -1361, -1361,   672,   463,   680,   723, -1361,
   -1361, -1361, -1361,   838,   -24, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   724,   743,   827, -1361, -1361, -1361,   629,
     694, -1361, -1361, -1361, -1361, -1361, -1361,   728,   748,   827,
   -1361, -1361,   638,   640, -1361, -1361, -1361, -1361, -1361,   122,
     -25, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   734,   749,   827, -1361, -1361,
   -1361,   721,   735, -1361, -1361,   675,   369, -1361, -1361,   755,
     827, -1361,   677, -1361, -1361, -1361, -1361,   226,   679,   573,
   -1361, -1361,   756,   827,   681, -1361, -1361, -1361,   229,   557,
   -1361, -1361, -1361, -1361, -1361,   852, -1361, -1361, -1361,   691,
     202, -1361, -1361, -1361, -1361,   685,   537, -1361, -1361,   757,
     827,   687, -1361, -1361, -1361, -1361,   231,   -33, -1361, -1361,
   -1361, -1361, -1361,   862, -1361,   863, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   764,   827,   689, -1361,   864,   751, -1361,
   -1361, -1361, -1361,   557, -1361, -1361, -1361, -1361,   -71, -1361,
   -1361, -1361, -1361,   866, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   769,   827,
     695, -1361,   751, -1361, -1361, -1361, -1361,     6, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   651,   868, -1361,   799, -1361,
   -1361,   -40, -1361, -1361, -1361, -1361,   872, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   775,   827,   697, -1361,   751, -1361, -1361, -1361, -1361,
     557, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   712,   726,
   -1361, -1361,   745, -1361, -1361,   873, -1361, -1361, -1361,   737,
     827,   701, -1361,   751, -1361, -1361, -1361, -1361, -1361,   840,
     763, -1361,   753, -1361,   729, -1361, -1361, -1361,   730,   666,
   -1361, -1361,   747, -1361, -1361, -1361, -1361,   741,   827,   725,
   -1361,   751, -1361, -1361, -1361, -1361,   771, -1361, -1361, -1361,
     667, -1361, -1361, -1361, -1361, -1361, -1361,   759,   770, -1361,
   -1361,   761, -1361, -1361, -1361, -1361,   766,   827,   727, -1361,
     751, -1361, -1361, -1361, -1361,   772, -1361,   774, -1361, -1361,
     251, -1361,   731,    85, -1361, -1361, -1361, -1361,   700,   827,
     733, -1361,   751, -1361, -1361, -1361, -1361,   790, -1361, -1361,
   -1361,   736, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   393,
   -1361,   738,    85, -1361, -1361,   704,   827,   740, -1361,   751,
   -1361, -1361, -1361, -1361,   793, -1361, -1361, -1361, -1361, -1361,
   -1361,   434, -1361,   742,    85, -1361, -1361,   708,   827,   744,
   -1361,   751, -1361, -1361, -1361, -1361,   796, -1361, -1361, -1361,
      32, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   751, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   705,
     827,   746, -1361,   751, -1361, -1361, -1361, -1361,   802, -1361,
   -1361,   898,    47, -1361, -1361, -1361, -1361,   895,   720,    16,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   751, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   707,   827,   750,
   -1361,   751, -1361, -1361, -1361, -1361,   803, -1361, -1361,    57,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   751, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   709,   827,   752,
   -1361,   751, -1361, -1361, -1361, -1361,   805, -1361, -1361, -1361,
   -1361, -1361, -1361,   776, -1361,   784, -1361, -1361, -1361,   827,
     754, -1361,   751, -1361, -1361, -1361, -1361,   804, -1361, -1361,
   -1361,   789, -1361,   903, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   696, -1361,   787, -1361, -1361, -1361,   827,   758, -1361,
     751, -1361, -1361, -1361, -1361,   813, -1361, -1361, -1361,   794,
   -1361,   788, -1361, -1361, -1361,   827,   760, -1361,   751, -1361,
   -1361, -1361, -1361,   817, -1361, -1361, -1361, -1361,   762, -1361,
     751, -1361, -1361, -1361, -1361,   777, -1361, -1361, -1361, -1361,
     792,   918,   923, -1361, -1361,   765, -1361,   751, -1361, -1361,
   -1361, -1361,   791, -1361, -1361, -1361, -1361,   767, -1361,   751,
   -1361, -1361, -1361, -1361,   795, -1361, -1361,   751, -1361, -1361,
   -1361, -1361,   739, -1361, -1361, -1361, -1361, -1361,   751, -1361,
   -1361, -1361, -1361,   807, -1361, -1361,   751, -1361, -1361, -1361,
   -1361,   808, -1361, -1361,   722, -1361, -1361, -1361, -1361,   809,
   -1361, -1361,   810, -1361, -1361, -1361, -1361, -1361
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   854, -1361,
     909, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   839,
   -1361, -1361, -1361, -1361,   814, -1361, -1361, -1361, -1361, -1361,
     524, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   512, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   815,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     421, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   710, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   348, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   631, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   296, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   280, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   411, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   186, -1361, -1361, -1361,
   -1361, -1361,   127, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   -29,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   -72, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,  -307, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,  -309, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   -56,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
    -274, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,  -275,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   -94, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,  -329, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,  -331, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
      21, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
    -129, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   208, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   134, -1361, -1361, -1361, -1361,  -770, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,  -150, -1361, -1361, -1361,
    -979, -1361, -1361, -1361, -1059,  -528, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,  -691, -1361, -1361, -1361,  -243, -1361, -1361,
   -1361,  -597, -1361, -1361, -1361, -1361, -1361, -1361, -1361,  -131,
   -1361,  -998,  -978,   -20,   -89, -1361, -1361, -1361,  -126, -1361,
   -1361, -1361, -1361,  -656, -1361,  -875, -1361,  -369, -1360,  -209,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   913,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1085, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     295,   621,   261,   506,   400,   673,   741,   488,  1146,   491,
    1278,   806,   292,   509,   386,   543,   391,   369,   511,  1183,
    1479,  1075,  1480,  1481,   540,   770,   771,   930,   263,   494,
     495,   289,   277,   765,   546,   274,  1479,   283,  1480,  1481,
     552,   816,    86,   549,   482,   286,   280,  1223,   530,  1102,
     485,  1501,  1085,   133,  1086,  1087,  1007,   406,   407,  1512,
       6,  1479,  1136,  1480,  1481,   408,  1255,   752,   766,   712,
     825,   765,   826,   827,   672,  1171,   226,   134,   227,   135,
     753,   136,     7,   137,    12,  1284,   683,  1277,   643,  1530,
    1157,  1165,   134,  1256,   135,   644,   136,  1285,   137,     1,
       2,  1049,  1214,  1061,  1225,   377,   766,   385,   749,   390,
    1050,   684,   228,   685,   409,    87,    14,  1204,  1209,  1008,
     368,    88,  1226,    17,  1286,    89,   229,    90,   158,   159,
    1306,  1227,  1079,   138,   158,   159,  1242,   627,   711,    91,
      30,   550,   117,  1088,   617,   618,   230,   531,   138,    92,
    1257,    93,   231,   531,    78,   158,   159,    94,  1328,  1080,
     118,   880,   225,   139,   122,  1502,   119,   606,   607,   374,
     375,  1270,   483,   120,   486,    95,   553,   748,   139,   828,
     121,   284,   125,  1528,   155,   275,  1355,   479,  1482,   209,
     520,   817,   650,   287,  1166,   158,   159,   652,   214,   160,
     161,   544,   654,   496,   547,   492,   278,   489,   541,   370,
     293,   290,   525,   481,  1299,  1377,  1036,   772,   281,   226,
     304,   227,    20,    21,   536,   537,   538,   539,  1279,   212,
     565,   216,   570,   215,   575,   213,  1143,  1409,  1510,  1177,
    1178,  1220,  1321,    25,    26,   217,   303,   401,   402,   403,
     404,  1386,   247,   808,   825,   228,   826,   827,   305,   266,
     555,  1380,  1381,  1080,  1447,   267,  1080,   340,  1080,   229,
    1348,   606,   607,   304,   606,   607,   606,   607,   372,  1085,
    1425,  1086,  1087,   382,   306,   387,  1477,   422,  1080,   230,
     423,   514,   307,   392,   515,   231,   606,   607,   595,  1370,
     399,   588,  1455,  1486,   589,   414,   308,    87,   309,   657,
     415,   305,   658,    88,   418,  1396,   416,    89,  1498,    90,
     419,  1402,   310,   564,   417,   569,   938,   574,   311,   939,
     312,    91,   313,   819,   314,   976,   820,   306,   977,    33,
      34,    92,  1514,    93,  1435,   307,    81,    82,  1440,    94,
     128,   129,   158,   159,   606,   607,  1526,   174,   175,   308,
     420,   309,   728,   729,   421,  1128,  1465,    95,   617,   618,
    1470,   442,  1532,   469,   609,   310,   179,   180,  1159,   620,
     504,   311,   507,   312,   512,   313,  1544,   314,  1112,  1039,
     521,   923,   409,   730,   731,   158,   159,   184,   185,   160,
     161,   526,  1491,  1419,  1420,  1206,   422,  1556,   561,   374,
     375,   566,   158,   159,   606,   607,   160,   161,   189,   190,
    1113,  1114,  1115,  1116,   690,   691,   692,   693,   617,   618,
    1080,   433,   571,   694,   157,  1573,   576,   434,   606,   607,
    1519,   194,   195,   435,  1449,  1450,   158,   159,   436,   583,
     160,   161,   671,  1585,   742,   199,   200,   584,  1038,  1129,
     158,   159,   606,   607,   585,  1593,   714,   586,   715,   716,
    1537,  1080,  1160,   587,   725,   204,   205,   220,   221,   606,
     607,   594,  1604,   597,   804,   249,   250,   268,   269,   296,
     297,  1549,   342,   343,  1612,   347,   348,   352,   353,  1207,
     596,  1084,  1615,   599,   730,   731,   158,   159,   606,   607,
     804,   357,   358,  1620,   362,   363,   710,   768,   769,  1566,
     598,  1623,   617,   618,   394,   395,   428,   429,  1123,   626,
     730,   731,   158,   159,   606,   607,   514,  1578,   633,  1147,
     634,  1158,   777,   444,   445,   449,   450,   740,   454,   455,
    1184,   459,   460,   949,   635,   747,  1112,   639,   796,   464,
     465,   499,   500,   494,   495,   637,   798,   641,  1205,   556,
     557,   578,   579,   636,   764,   603,   604,   642,  1224,   638,
     158,   159,   606,   607,   160,   161,  1196,  1197,  1113,  1114,
     614,   615,  1112,   667,   668,   835,   617,   618,   706,   707,
     717,   718,   743,   744,   842,   640,   903,   785,   786,   790,
     791,   655,   764,   799,   800,   663,   158,   159,   606,   607,
     160,   161,   843,   844,  1113,  1114,   865,   866,  1153,  1154,
     864,   807,   617,   618,   875,   876,   888,   889,   908,   909,
     932,   933,   953,   954,   588,   959,   960,    38,   882,   965,
     966,   674,   887,   970,   971,   988,   989,   994,   995,  1020,
    1021,   898,    39,   675,    40,    41,    42,   677,    43,    44,
      45,   676,    46,    47,    48,   907,    49,    50,    51,   678,
      52,    53,  1030,  1031,   918,  1107,  1108,  1138,  1139,  1148,
    1149,  1172,  1173,   681,   931,  1191,  1192,  1215,  1216,  1243,
    1244,   695,   879,   643,   944,  1271,  1272,  1300,  1301,   698,
    1185,  1322,  1323,   702,   958,    39,  1395,    40,    41,    42,
     701,    43,    44,    45,   699,    46,    47,    48,   982,    49,
      50,    51,   700,    52,    53,  1349,  1350,  1371,  1372,   657,
     993,  1388,  1389,  1403,  1404,  1434,  1412,  1413,  1427,  1428,
    1441,  1442,  1457,  1458,  1471,  1472,  1492,  1493,  1505,  1506,
    1520,  1521,  1538,  1539,  1550,  1551,  1026,  1464,  1567,  1568,
    1579,  1580,  1587,  1588,  1254,  1598,  1599,  1606,  1607,   713,
     722,   726,  1387,   727,   750,   751,   758,   767,   775,   776,
     778,   753,   782,   797,   810,   836,   813,  1064,   839,   849,
     848,   820,   853,   855,   857,   858,   861,   870,   871,   883,
     881,  1426,   893,   884,   906,   894,   903,   913,   899,   900,
     919,   914,   923,   920,   926,   937,   945,   946,   949,   975,
     938,   983,   999,  1456,  1002,  1006,  1037,  1013,  1016,  1103,
     977,  1027,  1044,  1041,  1048,  1061,  1057,  1065,  1058,  1007,
    1070,  1307,  1137,  1071,  1098,  1104,  1097,  1187,  1076,  1189,
    1049,  1021,  1132,  1167,  1210,  1236,  1237,  1238,  1249,  1265,
    1248,  1186,  1266,  1281,  1282,  1294,  1308,  1283,  1295,  1314,
    1330,  1226,  1225,  1332,  1255,  1336,  1317,  1257,  1333,  1357,
    1344,  1356,  1378,  1398,  1337,  1284,  1410,  1436,  1285,  1448,
    1379,  1466,  1478,  1235,  1500,  1503,  1118,  1559,  1557,  1560,
    1499,  1527,  1487,  1545,  1515,  1366,  1533,  1574,  1563,  1156,
    1575,  1586,  1547,  1359,  1596,  1564,  1576,  1594,  1595,  1597,
    1625,   124,  1546,  1616,    77,   522,   156,   527,   600,   664,
     703,  1605,   696,   341,   628,  1613,  1203,   443,   795,   850,
    1028,  1077,  1338,  1340,  1066,  1309,   248,  1311,  1105,  1360,
    1362,  1190,   984,   779,   856,  1208,  1040,  1131,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1621,  1624,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1626,  1627,     0,
       0,     0,     0,     0,     0,     0,     0,  1315,  1316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1329,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1397,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1558,     0,     0,     0,     0,  1561,  1562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1617,  1618
};

static const yytype_int16 yycheck[] =
{
     209,   529,   152,   372,     8,   602,   697,     6,  1067,     4,
       4,   781,     4,   382,   257,     4,   259,     4,   387,  1078,
       4,  1019,     6,     7,     4,     6,     7,   902,   154,     6,
       7,     4,     4,   724,     4,     4,     4,     4,     6,     7,
       4,     4,    68,     4,     4,     4,     4,  1106,    76,  1047,
       6,     4,    77,    70,    79,    80,   155,   266,   267,  1419,
       0,     4,  1060,     6,     7,   142,   137,   172,   724,   666,
      77,   762,    79,    80,   602,  1073,   129,   109,   131,   111,
     185,   113,    65,   115,    14,   125,    36,  1172,   197,  1449,
    1069,  1069,   109,   164,   111,   204,   113,   137,   115,    12,
      13,   125,  1100,    18,   137,   255,   762,   257,   705,   259,
     134,    61,   165,    63,   191,   141,    15,  1096,  1096,   218,
     246,   147,   155,    67,   164,   151,   179,   153,    43,    44,
    1215,   164,    10,   165,    43,    44,  1134,   171,   666,   165,
      69,   102,     5,   168,    59,    60,   199,   181,   165,   175,
     221,   177,   205,   181,    71,    43,    44,   183,  1243,    37,
       5,   852,    72,   195,    66,   118,     5,    45,    46,    57,
      58,  1169,   132,     5,   130,   201,   140,   705,   195,   186,
       5,   148,    73,   126,    68,   154,  1271,   337,   156,    26,
     399,   154,   561,   152,  1069,    43,    44,   566,    90,    47,
      48,   190,   571,   180,   174,   200,   178,   206,   188,   196,
     202,   184,   421,   339,  1212,  1300,   986,   198,   176,   129,
     101,   131,    10,    11,   433,   434,   435,   436,   222,    82,
     473,    98,   475,    94,   477,    86,    10,  1322,   222,    10,
      11,    10,  1240,    10,    11,    75,    74,   251,   252,   253,
     254,  1310,    70,   781,    77,   165,    79,    80,   139,     3,
     469,    10,    11,    37,  1349,     3,    37,    72,    37,   179,
    1268,    45,    46,   101,    45,    46,    45,    46,    10,    77,
    1339,    79,    80,    10,   165,    10,  1371,   163,    37,   199,
     166,   163,   173,    10,   166,   205,    45,    46,   507,  1297,
       6,   163,  1361,  1388,   166,   154,   187,   141,   189,   163,
     178,   139,   166,   147,   152,  1313,   176,   151,  1403,   153,
     184,  1319,   203,   473,   148,   475,   167,   477,   209,   170,
     211,   165,   213,   188,   215,   218,   191,   165,   221,    10,
      11,   175,  1427,   177,  1342,   173,    10,    11,  1346,   183,
      10,    11,    43,    44,    45,    46,  1441,    10,    11,   187,
     202,   189,    10,    11,     6,  1056,  1364,   201,    59,    60,
    1368,    74,  1457,    32,   524,   203,    10,    11,  1069,   529,
     196,   209,     3,   211,     6,   213,  1471,   215,    19,   986,
     142,    22,   191,    41,    42,    43,    44,    10,    11,    47,
      48,   166,  1400,    10,    11,  1096,   163,  1492,    10,    57,
      58,    10,    43,    44,    45,    46,    47,    48,    10,    11,
      51,    52,    53,    54,   633,   634,   635,   636,    59,    60,
      37,    17,    10,   642,    31,  1520,    10,    23,    45,    46,
    1438,    10,    11,    29,    10,    11,    43,    44,    34,   132,
      47,    48,   602,  1538,   697,    10,    11,   130,   986,  1056,
      43,    44,    45,    46,   206,  1550,   675,   200,   677,   678,
    1468,    37,  1069,   180,   683,    10,    11,    10,    11,    45,
      46,   114,  1567,   112,    21,    10,    11,    10,    11,    10,
      11,  1489,    10,    11,  1579,    10,    11,    10,    11,  1096,
     116,  1029,  1587,   166,    41,    42,    43,    44,    45,    46,
      21,    10,    11,  1598,    10,    11,   666,   726,   727,  1517,
     110,  1606,    59,    60,    10,    11,    10,    11,  1056,    76,
      41,    42,    43,    44,    45,    46,   163,  1535,     6,  1067,
       6,  1069,   751,    10,    11,    10,    11,   697,    10,    11,
    1078,    10,    11,    16,     6,   705,    19,   174,   767,    10,
      11,    10,    11,     6,     7,   188,   775,   140,  1096,    10,
      11,    10,    11,     6,   724,    10,    11,     6,  1106,   190,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      10,    11,    19,    10,    11,   804,    59,    60,    10,    11,
      10,    11,    10,    11,   813,   102,    33,    10,    11,    10,
      11,     6,   762,    10,    11,   166,    43,    44,    45,    46,
      47,    48,    10,    11,    51,    52,    10,    11,    55,    56,
     839,   781,    59,    60,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   163,    10,    11,    66,   857,    10,
      11,   192,   861,    10,    11,    10,    11,    10,    11,   220,
     221,   870,    81,     3,    83,    84,    85,     3,    87,    88,
      89,   164,    91,    92,    93,   884,    95,    96,    97,    30,
      99,   100,    10,    11,   893,    10,    11,    10,    11,    10,
      11,    10,    11,    10,   903,    10,    11,    10,    11,    10,
      11,   204,   852,   197,   913,    10,    11,    10,    11,   214,
    1079,    10,    11,   166,   923,    81,  1313,    83,    84,    85,
     210,    87,    88,    89,   216,    91,    92,    93,   937,    95,
      96,    97,   212,    99,   100,    10,    11,    10,    11,   163,
     949,    10,    11,    10,    11,  1342,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    38,    39,
      10,    11,    10,    11,    10,    11,   975,  1364,    10,    11,
      10,    11,    10,    11,  1143,    10,    11,    10,    11,   164,
     187,     3,  1310,     3,   164,     6,   153,     6,     3,   164,
     172,   185,   223,   198,   157,   127,    28,  1006,    25,   188,
     154,   191,     5,   186,     6,   169,    24,     6,   217,   182,
      78,  1339,     6,    27,   192,   217,    33,     6,   224,   219,
     158,   133,    22,   121,   121,     6,   128,   121,    16,     6,
     167,   170,   163,  1361,   119,     6,   986,   163,   119,  1048,
     221,   218,   119,   163,     6,    18,   122,   218,   105,   155,
     122,  1220,  1061,   105,   105,   134,   122,     5,   220,   168,
     125,   221,   107,   107,   107,     3,     3,   103,   117,     3,
       6,  1080,   103,   222,     6,     3,   164,    78,   103,     6,
      40,   155,   137,   120,   137,   156,   149,   221,   135,   222,
     149,   120,   120,   193,   164,   125,   106,   193,   137,   106,
     126,   193,   106,  1112,     6,    10,  1056,   118,   104,     6,
     108,   108,   207,   108,   207,   149,   207,   104,   222,  1069,
     126,   104,   138,   164,     6,   138,   138,   150,   136,     6,
     208,    77,   156,   194,    25,   411,    97,   425,   517,   591,
     660,   150,   646,   233,   533,   150,  1096,   316,   762,   822,
     979,  1023,  1259,  1262,  1010,  1229,   141,  1232,  1052,  1288,
    1291,  1090,   941,   755,   830,  1096,   986,  1056,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1236,  1237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1314,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1313,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1500,    -1,    -1,    -1,    -1,  1505,  1506,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1596,  1597
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   256,   257,   258,     0,    65,   265,   266,
    1027,  1028,    14,   259,    15,   263,   264,    67,   267,   268,
      10,    11,  1029,  1030,  1031,    10,    11,   260,   261,   262,
      69,   347,   348,    10,    11,   269,   270,   271,    66,    81,
      83,    84,    85,    87,    88,    89,    91,    92,    93,    95,
      96,    97,    99,   100,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,   265,    71,   401,
     402,    10,    11,   349,   350,   351,    68,   141,   147,   151,
     153,   165,   175,   177,   183,   201,   272,   273,   274,   275,
     276,   291,   292,   297,   298,   303,   304,   309,   310,   315,
     316,   321,   322,   327,   328,   333,   334,     5,     5,     5,
       5,     5,    66,  1034,   263,    73,   453,   454,    10,    11,
     403,   404,   405,    70,   109,   111,   113,   115,   165,   195,
     352,   353,   354,   355,   356,   361,   362,   368,   369,   375,
     376,   382,   383,   387,   388,    68,   274,    31,    43,    44,
      47,    48,   277,   278,   279,   971,   972,   973,   974,   988,
     989,   990,   991,  1018,    10,    11,   293,   294,   295,    10,
      11,   299,   300,   301,    10,    11,   305,   306,   307,    10,
      11,   311,   312,   313,    10,    11,   317,   318,   319,    10,
      11,   323,   324,   325,    10,    11,   329,   330,   331,    26,
     335,  1013,    82,    86,    90,    94,    98,    75,   548,   549,
      10,    11,   455,   456,   457,    72,   129,   131,   165,   179,
     199,   205,   406,   407,   408,   409,   410,   415,   416,   421,
     422,   427,   428,   433,   434,   439,   440,    70,   354,    10,
      11,   357,   358,   359,   363,   364,   370,   371,   377,   378,
     384,   971,   389,  1013,  1024,  1025,     3,     3,    10,    11,
     280,   281,   282,   279,     4,   154,   296,     4,   178,   302,
       4,   176,   308,     4,   148,   314,     4,   152,   320,     4,
     184,   326,     4,   202,   332,  1024,    10,    11,   336,   337,
     338,   550,   551,    74,   101,   139,   165,   173,   187,   189,
     203,   209,   211,   213,   215,   458,   459,   460,   461,   462,
     467,   468,   473,   474,   479,   480,   485,   486,   491,   492,
     508,   509,   515,   516,   522,   523,   529,   530,   534,   535,
      72,   408,    10,    11,   411,   412,   413,    10,    11,   417,
     418,   419,    10,    11,   423,   424,   425,    10,    11,   429,
     430,   431,    10,    11,   435,   436,   437,   441,  1013,     4,
     196,   360,    10,   366,    57,    58,   365,   971,   992,   993,
     994,   995,    10,   373,   372,   971,   992,    10,   380,   379,
     971,   992,    10,   385,    10,    11,   390,   391,   392,     6,
       8,   251,   252,   253,   254,  1026,  1024,  1024,   142,   191,
     283,   284,   285,   286,   154,   178,   176,   148,   152,   184,
     202,     6,   163,   166,   339,   340,   341,   342,    10,    11,
     553,   554,   555,    17,    23,    29,    34,   552,  1005,  1010,
    1016,  1021,    74,   460,    10,    11,   463,   464,   465,    10,
      11,   469,   470,   471,    10,    11,   475,   476,   477,    10,
      11,   481,   482,   483,    10,    11,   487,   488,   489,    32,
     493,  1019,   510,   511,   517,   518,   524,   525,   531,   971,
     536,  1013,     4,   132,   414,     6,   130,   420,     6,   206,
     426,     4,   200,   432,     6,     7,   180,   438,  1022,    10,
      11,   442,   443,   444,   196,   367,  1022,     3,   374,  1022,
     381,  1022,     6,   386,   163,   166,   393,   394,   395,   396,
    1024,   142,   285,   287,   288,  1024,   166,   341,   343,   344,
      76,   181,   556,   557,   558,   559,  1024,  1024,  1024,  1024,
       4,   188,   466,     4,   190,   472,     4,   174,   478,     4,
     102,   484,     4,   140,   490,  1024,    10,    11,   494,   495,
     496,    10,   513,   512,   971,   992,    10,   520,   519,   971,
     992,    10,   527,   526,   971,   992,    10,   532,    10,    11,
     537,   538,   539,   132,   130,   206,   200,   180,   163,   166,
     445,   446,   447,   448,   114,  1024,   116,   112,   110,   166,
     395,   397,   398,    10,    11,   290,    45,    46,   289,   971,
     980,   981,   982,   983,    10,    11,   346,    59,    60,   345,
     971,   980,   996,   997,   998,   999,    76,   171,   558,   940,
     941,   560,   561,     6,     6,     6,     6,   188,   190,   174,
     102,   140,     6,   197,   204,   497,   498,   499,   500,   514,
    1022,   521,  1022,   528,  1022,     6,   533,   163,   166,   540,
     541,   542,   543,   166,   447,   449,   450,    10,    11,   400,
     399,   971,   980,   996,   192,     3,   164,     3,    30,   942,
    1017,    10,   566,    36,    61,    63,   562,   563,   564,   565,
    1024,  1024,  1024,  1024,  1024,   204,   499,   501,   214,   216,
     212,   210,   166,   542,   544,   545,    10,    11,   452,   451,
     971,   980,   996,   164,  1024,  1024,  1024,    10,    11,   943,
     944,   945,   187,   567,   568,  1024,     3,     3,    10,    11,
      41,    42,   502,   503,   504,   505,   963,   964,   965,   966,
     971,   988,   992,    10,    11,   547,   546,   971,   980,   996,
     164,     6,   172,   185,   946,   947,   948,   949,   153,   583,
     584,   569,   570,   571,   971,   988,  1018,     6,  1024,  1024,
       6,     7,   198,   506,   507,     3,   164,  1024,   172,   948,
     950,   951,   223,   589,   590,    10,    11,   585,   586,   587,
      10,    11,   572,   573,   574,   571,  1024,   198,  1024,    10,
      11,   953,   954,   955,    21,   952,   963,   971,   980,  1008,
     157,   709,   710,    28,   591,  1015,     4,   154,   588,   188,
     191,   575,   576,   577,   578,    77,    79,    80,   186,   956,
     957,   958,   959,   960,   961,  1024,   127,   813,   814,    25,
     711,  1012,  1024,    10,    11,   592,   593,   594,   154,   188,
     577,   579,   580,     5,   962,   186,   958,     6,   169,   917,
     918,    24,   815,  1011,  1024,    10,    11,   712,   713,   714,
       6,   217,   595,   596,   597,    10,    11,   582,   581,   971,
     988,    78,  1024,   182,    27,   919,  1014,  1024,    10,    11,
     816,   817,   818,     6,   217,   715,   716,   717,  1024,   224,
     219,   609,   610,    33,   598,  1020,   192,  1024,    10,    11,
     920,   921,   922,     6,   133,   819,   820,   821,  1024,   158,
     121,   729,   730,    22,   718,  1009,   121,   625,   626,   611,
    1020,  1024,    10,    11,   599,   600,   601,     6,   167,   170,
     923,   924,   925,   926,  1024,   128,   121,   833,   834,    16,
     822,  1004,   784,    10,    11,   731,   732,   733,  1024,    10,
      11,   719,   720,   721,   680,    10,    11,   627,   628,   629,
      10,    11,   612,   613,   614,     6,   218,   221,   602,   603,
     604,   605,  1024,   170,   925,   927,   928,   888,    10,    11,
     835,   836,   837,  1024,    10,    11,   823,   824,   825,   163,
     785,   786,   119,   734,   735,   736,     6,   155,   218,   722,
     723,   724,   725,   163,   681,   682,   119,   630,   631,   632,
     220,   221,   615,   616,   617,   618,  1024,   218,   604,   606,
      10,    11,   930,   931,   932,   929,   963,   971,   980,   996,
    1008,   163,   889,   890,   119,   838,   839,   840,     6,   125,
     134,   826,   827,   828,   829,   787,   788,   122,   105,   742,
     743,    18,   737,  1006,  1024,   218,   724,   726,   683,   684,
     122,   105,   638,   639,   633,  1006,   220,   617,   619,    10,
      37,   607,   608,   979,   980,    77,    79,    80,   168,   933,
     934,   935,   936,   937,   938,   891,   892,   122,   105,   846,
     847,   841,  1006,  1024,   134,   828,   830,    10,    11,   790,
     791,   792,    19,    51,    52,    53,    54,   789,   971,   975,
     976,   977,   978,   980,   984,   985,   986,   987,   988,   996,
    1007,  1009,   107,   749,   750,   744,  1006,  1024,    10,    11,
     738,   739,   740,    10,   727,   728,   979,   980,    10,    11,
     686,   687,   688,    55,    56,   685,   971,   975,   980,   988,
     996,  1000,  1001,  1002,  1003,  1007,  1020,   107,   645,   646,
     640,  1006,    10,    11,   634,   635,   636,    10,    11,   620,
     621,   622,   623,   979,   980,  1022,  1024,     5,   939,   168,
     935,    10,    11,   894,   895,   896,    49,    50,   893,   967,
     968,   969,   970,   971,   975,   980,   988,   996,  1004,  1007,
     107,   853,   854,   848,  1006,    10,    11,   842,   843,   844,
      10,   831,   832,   979,   980,   137,   155,   164,   793,   794,
     795,   796,   803,   804,   805,  1024,     3,     3,   103,   756,
     757,   751,  1006,    10,    11,   745,   746,   747,     6,   117,
     741,  1055,  1056,  1063,  1022,   137,   164,   221,   689,   690,
     691,   692,   699,   700,   701,     3,   103,   652,   653,   647,
    1006,    10,    11,   641,   642,   643,   637,  1055,     4,   222,
     624,   222,     6,    78,   125,   137,   164,   897,   898,   899,
     900,   907,   908,   909,     3,   103,   860,   861,   855,  1006,
      10,    11,   849,   850,   851,   845,  1055,  1022,   164,   795,
     797,   804,   806,   807,     6,  1024,  1024,   149,   763,   764,
     758,  1006,    10,    11,   752,   753,   754,   748,  1055,  1024,
      40,  1064,   120,   135,  1057,  1058,   156,   164,   691,   693,
     700,   702,   703,  1024,   149,   659,   660,   654,  1006,    10,
      11,   648,   649,   650,   644,  1055,   120,   222,  1024,   164,
     899,   901,   908,   910,   911,  1024,   149,   867,   868,   862,
    1006,    10,    11,   856,   857,   858,   852,  1055,   120,   126,
      10,    11,   798,   799,   800,   801,   979,   980,    10,    11,
     809,   810,   811,   808,   971,   996,  1006,  1024,   193,   770,
     771,   765,  1006,    10,    11,   759,   760,   761,   755,  1055,
     106,  1024,    10,    11,  1065,  1066,  1067,  1059,  1060,    10,
      11,   694,   695,   696,   697,   979,   980,    10,    11,   705,
     706,   707,   704,   971,   996,  1006,   193,   666,   667,   661,
    1006,    10,    11,   655,   656,   657,   651,  1055,   106,    10,
      11,   902,   903,   904,   905,   979,   980,    10,    11,   913,
     914,   915,   912,   971,   996,  1006,   193,   874,   875,   869,
    1006,    10,    11,   863,   864,   865,   859,  1055,   106,     4,
       6,     7,   156,   802,  1023,   812,  1055,   207,   777,   778,
     772,  1006,    10,    11,   766,   767,   768,   762,  1055,   108,
       6,     4,   118,    10,  1062,    38,    39,  1061,  1068,  1069,
     222,   698,  1023,   708,  1055,   207,   673,   674,   668,  1006,
      10,    11,   662,   663,   664,   658,  1055,   108,   126,   906,
    1023,   916,  1055,   207,   881,   882,   876,  1006,    10,    11,
     870,   871,   872,   866,  1055,   108,   156,   138,   779,  1006,
      10,    11,   773,   774,   775,   769,  1055,   104,  1024,   118,
       6,  1024,  1024,   222,   138,   675,  1006,    10,    11,   669,
     670,   671,   665,  1055,   104,   126,   138,   883,  1006,    10,
      11,   877,   878,   879,   873,  1055,   104,    10,    11,   780,
     781,   782,   776,  1055,   150,   136,     6,     6,    10,    11,
     676,   677,   678,   672,  1055,   150,    10,    11,   884,   885,
     886,   880,  1055,   150,   783,  1055,   194,  1024,  1024,   679,
    1055,   194,   887,  1055,   194,   208,   208,   208
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
      yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osresult, parserData, osglData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osresult, parserData, osglData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData, osglData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osresult, parserData, osglData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);

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
int yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData);
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
yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
int
yyparse (osresult, parserData, osglData)
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
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
        case 4:

    {
#ifdef DEBUG
    yydebug = 1;
#endif
}
    break;

  case 5:

    {
#ifdef DEBUG
    yydebug = 1;
#endif    
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 12:

    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSrL input is either not valid or well formed.\n"); 
            osrlerror( NULL, osresult, parserData, osglData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osresult->setHeader(osglData->fileName, osglData->source,     
            osglData->description, osglData->fileCreator, osglData->licence) )    
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "setHeader failed");
}
    break;

  case 20:

    {
    parserData->generalStatusPresent        = false;    
    parserData->generalMessagePresent       = false;
    parserData->generalServiceURIPresent    = false;
    parserData->generalServiceNamePresent   = false;
    parserData->generalInstanceNamePresent  = false;
    parserData->generalJobIDPresent         = false;
    parserData->generalSolverInvokedPresent = false;
    parserData->generalTimeStampPresent     = false;
    parserData->otherGeneralResultsPresent  = false;
    osresult->general = new GeneralResult();
}
    break;

  case 39:

    {
        if (parserData->generalStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one generalStatus element allowed");    
        if (osresult->general->generalStatus != NULL) 
            osrlerror(NULL, NULL, parserData, osglData, "generalStatus previously allocated");
        parserData->generalStatusPresent = true;
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 40:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    }
    break;

  case 43:

    { 
        if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
    }
    break;

  case 44:

    {   
        osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
    }
    break;

  case 45:

    {
       if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 46:

    {    if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 47:

    {    if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 54:

    {
    parserData->kounter++;
}
    break;

  case 55:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 56:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
}
    break;

  case 59:

    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
    }
    break;

  case 60:

    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
    }
    break;

  case 64:

    {
        if (parserData->generalMessagePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
        parserData->generalMessagePresent = true;
    }
    break;

  case 70:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 72:

    {
        if (parserData->generalServiceURIPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
        parserData->generalServiceURIPresent = true;
    }
    break;

  case 78:

    {
        osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 80:

    {
        if (parserData->generalServiceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
        parserData->generalServiceNamePresent = true;
    }
    break;

  case 86:

    {
        osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 88:

    {
        if (parserData->generalInstanceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
        parserData->generalInstanceNamePresent = true;
    }
    break;

  case 94:

    {
        osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 96:

    {
        if (parserData->generalJobIDPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
        parserData->generalJobIDPresent = true;
    }
    break;

  case 102:

    {
        osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 104:

    {
        if (parserData->generalSolverInvokedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
        parserData->generalSolverInvokedPresent = true;
    }
    break;

  case 110:

    {
        osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 112:

    {
        if (parserData->generalTimeStampPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
        parserData->generalTimeStampPresent = true;
    }
    break;

  case 118:

    {
        osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 120:

    {
        if (parserData->otherGeneralResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
        parserData->otherGeneralResultsPresent = true;
    }
    break;

  case 121:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
    if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 122:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 123:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 130:

    {
    parserData->kounter++;
}
    break;

  case 131:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 132:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 135:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
    }
    break;

  case 136:

    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
    }
    break;

  case 137:

    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
    }
    break;

  case 142:

    {
    parserData->systemInformationPresent = false;    
    parserData->systemAvailableDiskSpacePresent = false;    
    parserData->systemAvailableMemoryPresent = false;
    parserData->systemAvailableCPUSpeedPresent = false;
    parserData->systemAvailableCPUNumberPresent = false;
    parserData->otherSystemResultsPresent = false;
    osresult->system = new SystemResult();
}
    break;

  case 158:

    {
        if (parserData->systemInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
        parserData->systemInformationPresent = true;
    }
    break;

  case 164:

    {
        osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 166:

    {
        if (parserData->systemAvailableDiskSpacePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
        parserData->systemAvailableDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 170:

    {
        if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 171:

    {
        osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 173:

    {
    osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 175:

    {
        if (parserData->systemAvailableMemoryPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
        parserData->systemAvailableMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 179:

    {
        if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 180:

    {
        osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 182:

    {
    osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 184:

    {
        if (parserData->systemAvailableCPUSpeedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
        parserData->systemAvailableCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 188:

    {
        if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 189:

    {
        osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 191:

    {
    osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 193:

    {
        if (parserData->systemAvailableCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
        parserData->systemAvailableCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
        osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 197:

    {
    osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;
}
    break;

  case 199:

    {
        if (parserData->otherSystemResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
        parserData->otherSystemResultsPresent = true;
    }
    break;

  case 200:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
    if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 201:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 202:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 209:

    {
    parserData->kounter++;
}
    break;

  case 210:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 211:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 214:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
    }
    break;

  case 215:

    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
    }
    break;

  case 216:

    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
    }
    break;

  case 221:

    {
    parserData->serviceCurrentStatePresent = false;    
    parserData->serviceCurrentJobCountPresent = false;    
    parserData->serviceTotalJobsSoFarPresent = false;    
    parserData->timeServiceStartedPresent = false;    
    parserData->serviceUtilizationPresent = false;    
    parserData->otherServiceResultsPresent = false;
    osresult->service = new ServiceResult();
}
    break;

  case 237:

    {
        if (parserData->serviceCurrentStatePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
        parserData->serviceCurrentStatePresent = true;
    }
    break;

  case 243:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setCurrentState(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 245:

    {
        if (parserData->serviceCurrentJobCountPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
        parserData->serviceCurrentJobCountPresent = true;
    }
    break;

  case 251:

    {
        osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL;
    }
    break;

  case 253:

    {
        if (parserData->serviceTotalJobsSoFarPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
        parserData->serviceTotalJobsSoFarPresent = true;
    }
    break;

  case 259:

    {
        osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; 
    }
    break;

  case 261:

    {
        if (parserData->timeServiceStartedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
        parserData->timeServiceStartedPresent = true;
    }
    break;

  case 267:

    {
        osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 269:

    {
        if (parserData->serviceUtilizationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
        parserData->serviceUtilizationPresent = true;
    }
    break;

  case 275:

    {
    if (osresult->setServiceUtilization( parserData->tempVal) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
    parserData->errorText = NULL;
}
    break;

  case 277:

    {
        if (parserData->otherServiceResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
        parserData->otherServiceResultsPresent = true;
    }
    break;

  case 278:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
    if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 279:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 280:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 287:

    {
    parserData->kounter++;
}
    break;

  case 288:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 289:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 292:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
    }
    break;

  case 293:

    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
    }
    break;

  case 294:

    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
    }
    break;

  case 299:

    {
    parserData->jobStatusPresent = false;    
    parserData->jobSubmitTimePresent = false;    
    parserData->scheduledStartTimePresent = false;    
    parserData->actualStartTimePresent = false;    
    parserData->jobEndTimePresent = false;    
    parserData->jobTimingInformationPresent = false;    
    parserData->jobUsedDiskSpacePresent = false;    
    parserData->jobUsedMemoryPresent = false;    
    parserData->jobUsedCPUSpeedPresent = false;    
    parserData->jobUsedCPUNumberPresent = false;    
    parserData->otherJobResultsPresent = false;     
    osresult->job = new JobResult();
}
    break;

  case 320:

    {
        if (parserData->jobStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
        parserData->jobStatusPresent = true;
    }
    break;

  case 326:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setJobStatus(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
        parserData->errorText = NULL;
    }
    break;

  case 328:

    {
        if (parserData->jobSubmitTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
        parserData->jobSubmitTimePresent = true;
    }
    break;

  case 334:

    {
        osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 336:

    {
        if (parserData->scheduledStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
        parserData->scheduledStartTimePresent = true;
    }
    break;

  case 342:

    {
        osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 344:

    {
        if (parserData->actualStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
        parserData->actualStartTimePresent = true;
    }
    break;

  case 350:

    {
        osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 352:

    {
        if (parserData->jobEndTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
        parserData->jobEndTimePresent = true;
    }
    break;

  case 358:

    {
        osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 360:

    {
        if (parserData->jobTimingInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
        parserData->jobTimingInformationPresent = true;
    }
    break;

  case 361:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
    if (osresult->setNumberOfTimes(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
    parserData->numberOfTimes = parserData->tempInt;
    parserData->ivar = 0;
}
    break;

  case 362:

    {
        if (parserData->numberOfTimes > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
    }
    break;

  case 363:

    {
        if (parserData->ivar != parserData->numberOfTimes)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
    }
    break;

  case 371:

    {
    if (parserData->ivar >= parserData->numberOfTimes)
        osrlerror(NULL, NULL, parserData, osglData, "more <time> elements than specified");
    parserData->unitAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->unitAttribute = "second";
    parserData->typeAttribute = "elapsedTime";
    parserData->categoryAttribute = "total";
    parserData->descriptionAttribute = "";
}
    break;

  case 383:

    {    
    if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
        parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
            osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
    parserData->ivar++;
}
    break;

  case 384:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 385:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 387:

    {
        if (parserData->jobUsedDiskSpacePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
        parserData->jobUsedDiskSpacePresent = true;        
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;
        parserData->unitAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 391:

    {
        if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 392:

    {
        osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 394:

    {
    osresult->setUsedDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 396:

    {
        if (parserData->jobUsedMemoryPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
        parserData->jobUsedMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 400:

    {
        if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 401:

    {
        osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 403:

    {
    osresult->setUsedMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 405:

    {
        if (parserData->jobUsedCPUSpeedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
        parserData->jobUsedCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 409:

    {
        if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 410:

    {
        osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 412:

    {
    osresult->setUsedCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 414:

    {
        if (parserData->jobUsedCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
        parserData->jobUsedCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 416:

    {
        osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 418:

    { 
    osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; 
}
    break;

  case 420:

    {
        if (parserData->otherJobResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
        parserData->otherJobResultsPresent = true;
    }
    break;

  case 421:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
    if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 422:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 423:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 430:

    {
    parserData->kounter++;
}
    break;

  case 431:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 432:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 435:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
    }
    break;

  case 436:

    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
    }
    break;

  case 437:

    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
    }
    break;

  case 442:

    {
    parserData->numberAttributePresent = false;
    parserData->nVarPresent = false;
    parserData->nObjPresent = false;
    parserData->nConPresent = false;
}
    break;

  case 443:

    {
    if (!parserData->numberAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
}
    break;

  case 446:

    {
        parserData->numberOfSolutions = parserData->tempInt; 
        if (osresult->setSolutionNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
        parserData->solutionIdx = 0;
    }
    break;

  case 447:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osresult->setVariableNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
    }
    break;

  case 448:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osresult->setConstraintNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
    }
    break;

  case 449:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osresult->setObjectiveNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
    }
    break;

  case 450:

    {
        if (parserData->numberOfSolutions > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
    }
    break;

  case 451:

    {
        if (parserData->solutionIdx != parserData->numberOfSolutions)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
    }
    break;

  case 459:

    {
    if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->weightedObjAttributePresent = false;
}
    break;

  case 466:

    {
    if (parserData->idxAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
    parserData->idxAttributePresent = true;
    if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 467:

    {
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 468:

    {
    if (parserData->weightedObjAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "weighted objective attribute previously set");
    parserData->weightedObjAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
    if (parserData->tempStr == "true")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
    }
    else if (parserData->tempStr == "false")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
    }
    else
        osrlerror(NULL, NULL, parserData, osglData, "weightedobjectives must be true or false");
}
    break;

  case 469:

    {
        parserData->solutionIdx++;
    }
    break;

  case 471:

    {
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 472:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
    }
    break;

  case 475:

    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
    }
    break;

  case 476:

    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
    }
    break;

  case 477:

    {
        if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 478:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 479:

    {
        if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 486:

    {
    parserData->kounter++; 
}
    break;

  case 487:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 488:

    {
    if (!parserData->typeAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
}
    break;

  case 491:

    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
    }
    break;

  case 492:

    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
    }
    break;

  case 503:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
        osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
        parserData->errorText = NULL;
    }
    break;

  case 506:

    {
    parserData->numberOfOtherVariableResults = 0;
    osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 508:

    {    
    if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
    parserData->numberOfOtherVariableResults = parserData->tempInt;
    parserData->iOther = 0;
}
    break;

  case 517:

    {
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}
    break;

  case 518:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 519:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 526:

    {
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
    parserData->kounter++;
}
    break;

  case 527:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 536:

    {
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}
    break;

  case 537:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 538:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 545:

    {
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
                                     parserData->idx,         parserData->nameAttribute,
                                    parserData->tempStr                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
    parserData->kounter++;
}
    break;

  case 546:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 551:

    {parserData->tempStr = "";}
    break;

  case 556:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 559:

    {
    osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 566:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 568:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 575:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 577:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 584:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 586:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 593:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 595:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 602:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 604:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 611:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 613:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 620:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 622:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 630:

    {      
        parserData->iOther++;
    }
    break;

  case 631:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, "more <otherVariableResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfVarAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->varTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";    
}
    break;

  case 632:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 635:

    {
        if (parserData->numberOfVarAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
        parserData->numberOfVarAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfVar) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfVar failed");
        parserData->kounter = 0;
    }
    break;

  case 636:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 637:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 638:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
    break;

  case 639:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultType failed");
    }
    break;

  case 640:

    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->varTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarType failed");
    }
    break;

  case 641:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 642:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 652:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 653:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 656:

    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
    }
    break;

  case 657:

    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
    }
    break;

  case 663:

    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
    }
    break;

  case 666:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 667:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 668:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 671:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 681:

    {
    parserData->numberOfOtherObjectiveResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 683:

    {
    parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
}
    break;

  case 692:

    {
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}
    break;

  case 693:

    {
        if (parserData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
    }
    break;

  case 694:

    {
        if (parserData->kounter != parserData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
    }
    break;

  case 701:

    {
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
    parserData->kounter++;
}
    break;

  case 702:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 710:

    {
    osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 717:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 719:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 726:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 728:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 735:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 737:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 744:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 746:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 753:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 755:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 762:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 764:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 771:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 773:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 781:

    {      
        parserData->iOther++;  
    }
    break;

  case 782:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
        osrlerror(NULL, NULL, parserData, osglData, "more <otherObjectiveResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->objTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 783:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 786:

    {
        if (parserData->numberOfObjAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
        parserData->numberOfObjAttributePresent = true;
         if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfObj failed");
        parserData->kounter = 0;
    }
    break;

  case 787:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 788:

    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 789:

    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 790:

    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultType failed");
    }
    break;

  case 791:

    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->objTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 792:

    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 793:

    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->descriptionAttribute) 
                                                              == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 803:

    {  
    parserData->kounter++;
}
    break;

  case 804:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;    
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 807:

    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
    }
    break;

  case 808:

    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
    }
    break;

  case 814:

    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
    }
    break;

  case 817:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 818:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 819:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 822:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 832:

    {
    parserData->numberOfOtherConstraintResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 834:

    {
    parserData->numberOfOtherConstraintResults = parserData->tempInt;
    if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
}
    break;

  case 842:

    {    parserData->numberAttributePresent = false; }
    break;

  case 843:

    {
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
}
    break;

  case 844:

    {
        if (parserData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
    }
    break;

  case 845:

    {
        if (parserData->kounter != parserData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
    }
    break;

  case 852:

    {
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               parserData->idx,         parserData->nameAttribute,
                               parserData->tempVal                           ) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
    parserData->kounter++;
}
    break;

  case 853:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 861:

    {
    osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 868:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 870:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 877:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 879:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 886:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 888:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 895:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 897:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 904:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 906:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 913:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 915:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 922:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 924:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 932:

    {      
        parserData->iOther++;  
    }
    break;

  case 933:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
        osrlerror(NULL, NULL, parserData, osglData, "more <otherConstraintResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->conTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 934:

    {
        if (!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 937:

    {
        if (parserData->numberOfConAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
        parserData->numberOfConAttributePresent = true;
         if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
                                                           parserData->iOther, 
                                                           parserData->numberOfCon) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfCon failed");
        parserData->kounter = 0;
    }
    break;

  case 938:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 939:

    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 940:

    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 941:

    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultType failed");
    }
    break;

  case 942:

    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->conTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConType failed");
    }
    break;

  case 943:

    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 944:

    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 954:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 955:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 958:

    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
    }
    break;

  case 959:

    {    
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
    }
    break;

  case 965:

    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
    }
    break;

  case 968:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 969:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 970:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 973:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 983:

    {
    parserData->numberOf = 0; 
}
    break;

  case 984:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 985:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 986:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 993:

    {
    parserData->iOther++;
}
    break;

  case 994:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
    parserData->numberOfItemsPresent = false; 
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->categoryAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
}
    break;

  case 995:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 998:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
    }
    break;

  case 999:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                 parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 1000:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 1001:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
                                                        parserData->iOther,
                                                        parserData->descriptionAttribute) 
                                                            == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 1002:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1003:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1004:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1011:

    {
    parserData->kounter++;
}
    break;

  case 1012:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1017:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
                                             parserData->kounter, parserData->itemContent) 
                                                 == false)
        osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
}
    break;

  case 1020:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1021:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1022:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
    }
    break;

  case 1023:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 1030:

    {
    parserData->iOther++;
}
    break;

  case 1031:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <solverOutput> elements than specified");
    parserData->numberOfItemsPresent = false; 
    parserData->nameAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->categoryAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1032:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
    if (!parserData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1035:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
    }
    break;

  case 1036:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, 
                                              parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
    }
    break;

  case 1037:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, 
                                                 parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
    }
    break;

  case 1038:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
                                                   parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1039:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1040:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1047:

    {
    parserData->kounter++;
}
    break;

  case 1048:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1053:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1054:

    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
        parserData->categoryAttributePresent = true;
    }
    break;

  case 1057:

    { 
    parserData->categoryAttribute = ""; 
}
    break;

  case 1058:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1059:

    {
        if (parserData->conTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one conType attribute allowed for this element");
        parserData->conTypeAttributePresent = true;
    }
    break;

  case 1062:

    { 
    parserData->conTypeAttribute = ""; 
}
    break;

  case 1063:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1064:

    {
        if (parserData->descriptionAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
        parserData->descriptionAttributePresent = true;
    }
    break;

  case 1067:

    { 
    parserData->descriptionAttribute = ""; 
}
    break;

  case 1068:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1069:

    {
        if (parserData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one enumType attribute allowed for this element");
        parserData->enumTypeAttributePresent = true;
    }
    break;

  case 1072:

    { 
    parserData->enumTypeAttribute = ""; 
}
    break;

  case 1073:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1074:

    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = (yyvsp[(3) - (4)].ival); 
    }
    break;

  case 1075:

    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1078:

    { 
    parserData->nameAttribute = ""; 
}
    break;

  case 1079:

    { 
    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1080:

    {
        if (parserData->objTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one objType attribute allowed for this element");
        parserData->objTypeAttributePresent = true;
    }
    break;

  case 1083:

    { 
    parserData->objTypeAttribute = ""; 
}
    break;

  case 1084:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1085:

    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
        parserData->typeAttributePresent = true;
    }
    break;

  case 1088:

    { 
    parserData->typeAttribute = ""; 
}
    break;

  case 1089:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1090:

    {
        if (parserData->unitAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
        parserData->unitAttributePresent = true;
    }
    break;

  case 1093:

    { 
    parserData->unitAttribute = ""; 
}
    break;

  case 1094:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1095:

    {
        if (parserData->valueAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
        parserData->valueAttributePresent = true;
    }
    break;

  case 1098:

    { 
    parserData->valueAttribute = ""; 
}
    break;

  case 1099:

    { 
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1100:

    {
        if (parserData->varTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one varType attribute allowed for this element");
        parserData->varTypeAttributePresent = true;
    }
    break;

  case 1103:

    { 
    parserData->varTypeAttribute = ""; 
}
    break;

  case 1104:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1105:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1106:

    {
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1107:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1108:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1109:

    {    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1110:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1111:

    {
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1112:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1113:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1114:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1115:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1116:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1117:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1118:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1119:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1120:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1121:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1122:

    {
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1123:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1124:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1125:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1126:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1127:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
    break;

  case 1136:

    {
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
}
    break;

  case 1151:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1156:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1158:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1163:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1165:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1170:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1172:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1177:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1179:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1184:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1185:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1190:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1196:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1198:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1203:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "base 64 data length does not match numberOfEl"); 
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

  case 1204:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1205:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
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
      yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error"));
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
	    yyerror (&yylloc, osresult, parserData, osglData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osresult, parserData, osglData);
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
		  yystos[yystate], yyvsp, yylsp, osresult, parserData, osglData);
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
  yyerror (&yylloc, osresult, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osresult, parserData, osglData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osresult, parserData, osglData);
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





void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osrl_empty_vectors( parserData );
    osgl_empty_vectors(   osglData );
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSrL input is either not valid or well formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osrlget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
    error = outStr.str();
    //printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
    //if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
    //osrllex_destroy( scanner);
    throw ErrorClass( error);
} //end osrlerror


std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osrlget_lineno( scanner) << ": "; 
    outStr << osrlget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, std::string errormsg )
{
    osrl_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    throw ErrorClass( errormsg);
} //end osolerror



void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass)
{
    try
    {
        osrl_scan_string( parsestring, scanner);
        osrlset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osrlparse( osresult,  parserData, osglData) != 0) {
            //osrllex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSrL file");
         }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSResult


void osrl_empty_vectors( OSrLParserData* parserData)
{
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for (k = 0; k < numOtherVarVec; k++)
    {
        if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarText  != NULL) ) 
            delete[] parserData->otherVarVec[k]->otherVarText;
        if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[k]->otherVarIndex;
            
        if (  parserData->otherVarVec[k] != NULL) delete parserData->otherVarVec[k];
        }
      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for (k = 0; k < numDualVals; k++)
    {
          if (parserData->dualVals[k]  != NULL  ) 
            delete parserData->dualVals[k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for (k = 0; k < numObjVals; k++)
    {
          if (parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for (k = 0; k < numPrimalVals; k++)
    {    
          if (parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
}//end osrl_empty_vectors


