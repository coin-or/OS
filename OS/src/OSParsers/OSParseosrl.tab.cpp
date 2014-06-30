
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
     DUMMY = 493
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
#define DUMMY 493




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
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1628

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   240,
     242,     2,     2,   241,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   239,     2,     2,     2,     2,     2,     2,     2,
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
     235,   236,   237,   238
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
     244,     0,    -1,   245,   253,   251,    -1,   246,   247,   248,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   249,    -1,
     250,    -1,    11,    -1,    10,   253,   251,    -1,   252,    -1,
      15,    -1,    -1,   254,   255,   335,   389,   441,   536,    -1,
      -1,  1015,    -1,    -1,   256,   257,    -1,    67,    -1,   258,
      -1,   259,    -1,    10,    68,    -1,    11,    -1,    10,   260,
      68,    -1,   261,    -1,   262,    -1,   261,   262,    -1,   263,
      -1,   279,    -1,   285,    -1,   291,    -1,   297,    -1,   303,
      -1,   309,    -1,   315,    -1,   321,    -1,   264,   265,   268,
      -1,   141,    -1,   266,    -1,   267,    -1,   266,   267,    -1,
     976,    -1,   959,    -1,  1006,    -1,   269,    -1,   270,    -1,
      10,   142,    -1,    11,    -1,    10,   271,   142,    -1,   272,
      -1,   273,    -1,   272,   273,    -1,   274,   275,   278,    -1,
     191,    -1,   276,    -1,    -1,   276,   277,    -1,   968,    -1,
     959,    -1,    10,   192,    -1,    11,    -1,   280,   281,    -1,
     153,    -1,   282,    -1,   283,    -1,    10,   154,    -1,    11,
      -1,    10,   284,   154,    -1,     4,    -1,   286,   287,    -1,
     177,    -1,   288,    -1,   289,    -1,    10,   178,    -1,    11,
      -1,    10,   290,   178,    -1,     4,    -1,   292,   293,    -1,
     175,    -1,   294,    -1,   295,    -1,    10,   176,    -1,    11,
      -1,    10,   296,   176,    -1,     4,    -1,   298,   299,    -1,
     147,    -1,   300,    -1,   301,    -1,    10,   148,    -1,    11,
      -1,    10,   302,   148,    -1,     4,    -1,   304,   305,    -1,
     151,    -1,   306,    -1,   307,    -1,    10,   152,    -1,    11,
      -1,    10,   308,   152,    -1,     4,    -1,   310,   311,    -1,
     183,    -1,   312,    -1,   313,    -1,    10,   184,    -1,    11,
      -1,    10,   314,   184,    -1,     4,    -1,   316,   317,    -1,
     201,    -1,   318,    -1,   319,    -1,    10,   202,    -1,    11,
      -1,    10,   320,   202,    -1,     4,    -1,   322,   323,   324,
      -1,   165,    -1,  1001,    -1,   325,    -1,   326,    -1,    10,
     166,    -1,    11,    -1,    10,   327,   166,    -1,   328,    -1,
     329,    -1,   328,   329,    -1,   330,   331,   334,    -1,   163,
      -1,   332,    -1,    -1,   332,   333,    -1,   968,    -1,   984,
      -1,   959,    -1,    10,   164,    -1,    11,    -1,    -1,   336,
     337,    -1,    69,    -1,   338,    -1,   339,    -1,    10,    70,
      -1,    11,    -1,    10,   340,    70,    -1,   341,    -1,   342,
      -1,   341,   342,    -1,   343,    -1,   349,    -1,   356,    -1,
     363,    -1,   370,    -1,   375,    -1,   344,   345,    -1,   195,
      -1,   346,    -1,   347,    -1,    10,   196,    -1,    11,    -1,
      10,   348,   196,    -1,     4,    -1,   350,   351,   354,    -1,
     113,    -1,   352,    -1,    -1,   352,   353,    -1,   980,    -1,
     959,    -1,    10,   355,   114,    -1,  1010,    -1,   357,   358,
     361,    -1,   115,    -1,   359,    -1,    -1,   359,   360,    -1,
     980,    -1,   959,    -1,    10,   362,   116,    -1,  1010,    -1,
     364,   365,   368,    -1,   111,    -1,   366,    -1,    -1,   366,
     367,    -1,   980,    -1,   959,    -1,    10,   369,   112,    -1,
    1010,    -1,   371,   372,   373,    -1,   109,    -1,    -1,   959,
      -1,    10,   374,   110,    -1,     6,    -1,   376,   377,   378,
      -1,   165,    -1,  1001,    -1,   379,    -1,   380,    -1,    10,
     166,    -1,    11,    -1,    10,   381,   166,    -1,   382,    -1,
     383,    -1,   382,   383,    -1,   384,   385,   388,    -1,   163,
      -1,   386,    -1,    -1,   386,   387,    -1,   968,    -1,   984,
      -1,   959,    -1,    10,   164,    -1,    11,    -1,    -1,   390,
     391,    -1,    71,    -1,   392,    -1,   393,    -1,    10,    72,
      -1,    11,    -1,    10,   394,    72,    -1,   395,    -1,   396,
      -1,   395,   396,    -1,   397,    -1,   403,    -1,   409,    -1,
     415,    -1,   421,    -1,   427,    -1,   398,   399,    -1,   131,
      -1,   400,    -1,   401,    -1,    10,   132,    -1,    11,    -1,
      10,   402,   132,    -1,     4,    -1,   404,   405,    -1,   129,
      -1,   406,    -1,   407,    -1,    10,   130,    -1,    11,    -1,
      10,   408,   130,    -1,     6,    -1,   410,   411,    -1,   205,
      -1,   412,    -1,   413,    -1,    10,   206,    -1,    11,    -1,
      10,   414,   206,    -1,     6,    -1,   416,   417,    -1,   199,
      -1,   418,    -1,   419,    -1,    10,   200,    -1,    11,    -1,
      10,   420,   200,    -1,     4,    -1,   422,   423,    -1,   179,
      -1,   424,    -1,   425,    -1,    10,   180,    -1,    11,    -1,
      10,   426,   180,    -1,  1010,    -1,   428,   429,   430,    -1,
     165,    -1,  1001,    -1,   431,    -1,   432,    -1,    10,   166,
      -1,    11,    -1,    10,   433,   166,    -1,   434,    -1,   435,
      -1,   434,   435,    -1,   436,   437,   440,    -1,   163,    -1,
     438,    -1,    -1,   438,   439,    -1,   968,    -1,   984,    -1,
     959,    -1,    10,   164,    -1,    11,    -1,    -1,   442,   443,
      -1,    73,    -1,   444,    -1,   445,    -1,    10,    74,    -1,
      11,    -1,    10,   446,    74,    -1,   447,    -1,   448,    -1,
     447,   448,    -1,   449,    -1,   455,    -1,   461,    -1,   467,
      -1,   473,    -1,   479,    -1,   496,    -1,   503,    -1,   510,
      -1,   517,    -1,   522,    -1,   450,   451,    -1,   187,    -1,
     452,    -1,   453,    -1,    10,   188,    -1,    11,    -1,    10,
     454,   188,    -1,     4,    -1,   456,   457,    -1,   189,    -1,
     458,    -1,   459,    -1,    10,   190,    -1,    11,    -1,    10,
     460,   190,    -1,     4,    -1,   462,   463,    -1,   173,    -1,
     464,    -1,   465,    -1,    10,   174,    -1,    11,    -1,    10,
     466,   174,    -1,     4,    -1,   468,   469,    -1,   101,    -1,
     470,    -1,   471,    -1,    10,   102,    -1,    11,    -1,    10,
     472,   102,    -1,     4,    -1,   474,   475,    -1,   139,    -1,
     476,    -1,   477,    -1,    10,   140,    -1,    11,    -1,    10,
     478,   140,    -1,     4,    -1,   480,   481,   482,    -1,   203,
      -1,  1007,    -1,   483,    -1,   484,    -1,    10,   204,    -1,
      11,    -1,    10,   485,   204,    -1,   486,    -1,   487,    -1,
     486,   487,    -1,   488,   489,   491,    -1,   197,    -1,    -1,
     489,   490,    -1,   980,    -1,   976,    -1,   951,    -1,   959,
      -1,   492,    -1,   493,    -1,    10,   198,    -1,    11,    -1,
      10,   494,   198,    -1,   495,    -1,     7,    -1,     6,    -1,
     497,   498,   501,    -1,   213,    -1,   499,    -1,    -1,   499,
     500,    -1,   980,    -1,   959,    -1,    10,   502,   214,    -1,
    1010,    -1,   504,   505,   508,    -1,   215,    -1,   506,    -1,
      -1,   506,   507,    -1,   980,    -1,   959,    -1,    10,   509,
     216,    -1,  1010,    -1,   511,   512,   515,    -1,   211,    -1,
     513,    -1,    -1,   513,   514,    -1,   980,    -1,   959,    -1,
      10,   516,   212,    -1,  1010,    -1,   518,   519,   520,    -1,
     209,    -1,    -1,   959,    -1,    10,   521,   210,    -1,     6,
      -1,   523,   524,   525,    -1,   165,    -1,  1001,    -1,   526,
      -1,   527,    -1,    10,   166,    -1,    11,    -1,    10,   528,
     166,    -1,   529,    -1,   530,    -1,   529,   530,    -1,   531,
     532,   535,    -1,   163,    -1,   533,    -1,    -1,   533,   534,
      -1,   968,    -1,   984,    -1,   959,    -1,    10,   164,    -1,
      11,    -1,    -1,   537,   538,   541,    -1,    75,    -1,   539,
      -1,    -1,   539,   540,    -1,  1004,    -1,  1009,    -1,   993,
      -1,   998,    -1,   542,    -1,   543,    -1,    10,    76,    -1,
      11,    -1,    10,   544,    76,    -1,   545,   928,    -1,   546,
      -1,   545,   546,    -1,   547,   548,   554,    -1,   181,    -1,
     549,    -1,    -1,   549,   550,    -1,   551,    -1,   552,    -1,
     553,    -1,    36,  1012,     6,  1012,    -1,    63,     3,  1012,
      -1,    61,     3,  1012,    -1,    10,   555,   571,   577,   697,
     801,   905,   182,    -1,   556,   557,   560,    -1,   187,    -1,
     558,    -1,   559,    -1,   558,   559,    -1,   976,    -1,   959,
      -1,  1006,    -1,   561,    -1,   562,    -1,    10,   188,    -1,
      11,    -1,    10,   563,   188,    -1,   564,    -1,   565,    -1,
     564,   565,    -1,   566,   567,   570,    -1,   191,    -1,   568,
      -1,    -1,   568,   569,    -1,   976,    -1,   959,    -1,    10,
     192,    -1,    11,    -1,    -1,   572,   573,    -1,   153,    -1,
     574,    -1,   575,    -1,    10,   154,    -1,    11,    -1,    10,
     576,   154,    -1,     4,    -1,    -1,   578,   579,   580,    -1,
     223,    -1,    -1,  1003,    -1,   581,    -1,   582,    -1,    11,
      -1,    10,   583,   224,    -1,   584,   597,   613,   668,    -1,
      -1,   585,   586,   587,    -1,   217,    -1,  1008,    -1,   588,
      -1,   589,    -1,    10,   218,    -1,    11,    -1,    10,   590,
     218,    -1,   591,    -1,   592,    -1,   591,   592,    -1,   593,
     594,   596,    -1,   221,    -1,    -1,   594,   595,    -1,   967,
      -1,   968,    -1,    10,  1010,   222,    -1,    -1,   598,   599,
     600,    -1,   219,    -1,  1008,    -1,   601,    -1,   602,    -1,
      10,   220,    -1,    11,    -1,    10,   603,   220,    -1,   604,
      -1,   605,    -1,   604,   605,    -1,   606,   607,   609,    -1,
     221,    -1,    -1,   607,   608,    -1,   967,    -1,   968,    -1,
     610,    -1,   611,    -1,    10,   222,    -1,    11,    -1,    10,
     612,   222,    -1,     4,    -1,    -1,   614,   615,    -1,   121,
      -1,   616,    -1,   617,    -1,    11,    -1,    10,   618,   122,
      -1,   619,   626,   633,   640,   647,   654,   661,    -1,    -1,
     620,   621,   622,    -1,   119,    -1,   994,    -1,   623,    -1,
     624,    -1,    11,    -1,    10,   625,   120,    -1,  1043,    -1,
      -1,   627,   628,   629,    -1,   105,    -1,   994,    -1,   630,
      -1,   631,    -1,    11,    -1,    10,   632,   106,    -1,  1043,
      -1,    -1,   634,   635,   636,    -1,   107,    -1,   994,    -1,
     637,    -1,   638,    -1,    11,    -1,    10,   639,   108,    -1,
    1043,    -1,    -1,   641,   642,   643,    -1,   103,    -1,   994,
      -1,   644,    -1,   645,    -1,    11,    -1,    10,   646,   104,
      -1,  1043,    -1,    -1,   648,   649,   650,    -1,   149,    -1,
     994,    -1,   651,    -1,   652,    -1,    11,    -1,    10,   653,
     150,    -1,  1043,    -1,    -1,   655,   656,   657,    -1,   193,
      -1,   994,    -1,   658,    -1,   659,    -1,    11,    -1,    10,
     660,   194,    -1,  1043,    -1,    -1,   662,   663,   664,    -1,
     207,    -1,   994,    -1,   665,    -1,   666,    -1,    11,    -1,
      10,   667,   208,    -1,  1043,    -1,    -1,   668,   669,    -1,
     670,   671,   674,    -1,   163,    -1,   672,    -1,    -1,   672,
     673,    -1,  1008,    -1,   995,    -1,   984,    -1,   968,    -1,
     976,    -1,   988,    -1,   963,    -1,   959,    -1,   675,    -1,
     676,    -1,    10,   164,    -1,    11,    -1,    10,   677,   164,
      -1,   678,    -1,   687,    -1,   679,    -1,   678,   679,    -1,
     680,   681,   683,    -1,   221,    -1,    -1,   681,   682,    -1,
     967,    -1,   968,    -1,   684,    -1,   685,    -1,    10,   222,
      -1,    11,    -1,    10,   686,   222,    -1,  1011,    -1,   688,
      -1,   687,   688,    -1,   689,   690,   693,    -1,   137,    -1,
     691,    -1,    -1,   691,   692,    -1,   994,    -1,   984,    -1,
     959,    -1,   694,    -1,   695,    -1,    11,    -1,    10,   696,
     138,    -1,  1043,    -1,    -1,   698,   699,   700,    -1,   157,
      -1,    -1,  1000,    -1,   701,    -1,   702,    -1,    11,    -1,
      10,   703,   158,    -1,   704,   717,   772,    -1,    -1,   705,
     706,   707,    -1,   217,    -1,   997,    -1,   708,    -1,   709,
      -1,    10,   218,    -1,    11,    -1,    10,   710,   218,    -1,
     711,    -1,   712,    -1,   711,   712,    -1,   713,   714,   716,
      -1,   155,    -1,    -1,   714,   715,    -1,   967,    -1,   968,
      -1,    10,  1010,   156,    -1,    -1,   718,   719,    -1,   121,
      -1,   720,    -1,   721,    -1,    11,    -1,    10,   722,   122,
      -1,   723,   730,   737,   744,   751,   758,   765,    -1,    -1,
     724,   725,   726,    -1,   119,    -1,   994,    -1,   727,    -1,
     728,    -1,    11,    -1,    10,   729,   120,    -1,  1043,    -1,
      -1,   731,   732,   733,    -1,   105,    -1,   994,    -1,   734,
      -1,   735,    -1,    11,    -1,    10,   736,   106,    -1,  1043,
      -1,    -1,   738,   739,   740,    -1,   107,    -1,   994,    -1,
     741,    -1,   742,    -1,    11,    -1,    10,   743,   108,    -1,
    1043,    -1,    -1,   745,   746,   747,    -1,   103,    -1,   994,
      -1,   748,    -1,   749,    -1,    11,    -1,    10,   750,   104,
      -1,  1043,    -1,    -1,   752,   753,   754,    -1,   149,    -1,
     994,    -1,   755,    -1,   756,    -1,    11,    -1,    10,   757,
     150,    -1,  1043,    -1,    -1,   759,   760,   761,    -1,   193,
      -1,   994,    -1,   762,    -1,   763,    -1,    11,    -1,    10,
     764,   194,    -1,  1043,    -1,    -1,   766,   767,   768,    -1,
     207,    -1,   994,    -1,   769,    -1,   770,    -1,    11,    -1,
      10,   771,   208,    -1,  1043,    -1,    -1,   772,   773,    -1,
     774,   775,   778,    -1,   163,    -1,   776,    -1,    -1,   776,
     777,    -1,   997,    -1,   995,    -1,   984,    -1,   968,    -1,
     976,    -1,   972,    -1,   963,    -1,   959,    -1,   779,    -1,
     780,    -1,    10,   164,    -1,    11,    -1,    10,   781,   164,
      -1,   782,    -1,   791,    -1,   783,    -1,   782,   783,    -1,
     784,   785,   787,    -1,   155,    -1,    -1,   785,   786,    -1,
     967,    -1,   968,    -1,   788,    -1,   789,    -1,    10,   156,
      -1,    11,    -1,    10,   790,   156,    -1,  1011,    -1,   792,
      -1,   791,   792,    -1,   793,   794,   797,    -1,   137,    -1,
     795,    -1,    -1,   795,   796,    -1,   994,    -1,   984,    -1,
     959,    -1,   798,    -1,   799,    -1,    11,    -1,    10,   800,
     138,    -1,  1043,    -1,    -1,   802,   803,   804,    -1,   127,
      -1,    -1,   999,    -1,   805,    -1,   806,    -1,    11,    -1,
      10,   807,   128,    -1,   808,   821,   876,    -1,    -1,   809,
     810,   811,    -1,   133,    -1,   992,    -1,   812,    -1,   813,
      -1,    10,   134,    -1,    11,    -1,    10,   814,   134,    -1,
     815,    -1,   816,    -1,   815,   816,    -1,   817,   818,   820,
      -1,   125,    -1,    -1,   818,   819,    -1,   967,    -1,   968,
      -1,    10,  1010,   126,    -1,    -1,   822,   823,    -1,   121,
      -1,   824,    -1,   825,    -1,    11,    -1,    10,   826,   122,
      -1,   827,   834,   841,   848,   855,   862,   869,    -1,    -1,
     828,   829,   830,    -1,   119,    -1,   994,    -1,   831,    -1,
     832,    -1,    11,    -1,    10,   833,   120,    -1,  1043,    -1,
      -1,   835,   836,   837,    -1,   105,    -1,   994,    -1,   838,
      -1,   839,    -1,    11,    -1,    10,   840,   106,    -1,  1043,
      -1,    -1,   842,   843,   844,    -1,   107,    -1,   994,    -1,
     845,    -1,   846,    -1,    11,    -1,    10,   847,   108,    -1,
    1043,    -1,    -1,   849,   850,   851,    -1,   103,    -1,   994,
      -1,   852,    -1,   853,    -1,    11,    -1,    10,   854,   104,
      -1,  1043,    -1,    -1,   856,   857,   858,    -1,   149,    -1,
     994,    -1,   859,    -1,   860,    -1,    11,    -1,    10,   861,
     150,    -1,  1043,    -1,    -1,   863,   864,   865,    -1,   193,
      -1,   994,    -1,   866,    -1,   867,    -1,    11,    -1,    10,
     868,   194,    -1,  1043,    -1,    -1,   870,   871,   872,    -1,
     207,    -1,   994,    -1,   873,    -1,   874,    -1,    11,    -1,
      10,   875,   208,    -1,  1043,    -1,    -1,   876,   877,    -1,
     878,   879,   882,    -1,   163,    -1,   880,    -1,    -1,   880,
     881,    -1,   992,    -1,   995,    -1,   984,    -1,   968,    -1,
     976,    -1,   955,    -1,   963,    -1,   959,    -1,   883,    -1,
     884,    -1,    10,   164,    -1,    11,    -1,    10,   885,   164,
      -1,   886,    -1,   895,    -1,   887,    -1,   886,   887,    -1,
     888,   889,   891,    -1,   125,    -1,    -1,   889,   890,    -1,
     967,    -1,   968,    -1,   892,    -1,   893,    -1,    10,   126,
      -1,    11,    -1,    10,   894,   126,    -1,  1011,    -1,   896,
      -1,   895,   896,    -1,   897,   898,   901,    -1,   137,    -1,
     899,    -1,    -1,   899,   900,    -1,   994,    -1,   984,    -1,
     959,    -1,   902,    -1,   903,    -1,    11,    -1,    10,   904,
     138,    -1,  1043,    -1,    -1,   906,   907,   908,    -1,   169,
      -1,  1002,    -1,   909,    -1,   910,    -1,    10,   170,    -1,
      11,    -1,    10,   911,   170,    -1,   912,    -1,   913,    -1,
     912,   913,    -1,   914,   915,   918,    -1,   167,    -1,   916,
      -1,    -1,   916,   917,    -1,   968,    -1,   984,    -1,   951,
      -1,   959,    -1,   996,    -1,   919,    -1,   920,    -1,    10,
     168,    -1,    11,    -1,    10,   921,   168,    -1,   922,    -1,
     923,    -1,   922,   923,    -1,   924,    -1,   925,    -1,   926,
      -1,    79,    -1,    80,    -1,    77,   927,    78,    -1,     5,
      -1,    -1,   929,   930,   931,    -1,   171,    -1,  1005,    -1,
     932,    -1,   933,    -1,    10,   172,    -1,    11,    -1,    10,
     934,   172,    -1,   935,    -1,   936,    -1,   935,   936,    -1,
     937,   938,   941,    -1,   185,    -1,   939,    -1,    -1,   939,
     940,    -1,   968,    -1,   951,    -1,   959,    -1,   996,    -1,
     942,    -1,   943,    -1,    10,   186,    -1,    11,    -1,    10,
     944,   186,    -1,   945,    -1,   946,    -1,   945,   946,    -1,
     947,    -1,   948,    -1,   949,    -1,    79,    -1,    80,    -1,
      77,   950,    78,    -1,     5,    -1,   952,    -1,   953,    -1,
     954,    -1,    42,    -1,    41,     3,  1012,    -1,   956,    -1,
     957,    -1,   958,    -1,    50,    -1,    49,     3,  1012,    -1,
     960,    -1,   961,    -1,   962,    -1,    44,    -1,    43,     3,
    1012,    -1,   964,    -1,   965,    -1,   966,    -1,    52,    -1,
      51,     3,  1012,    -1,    37,  1012,     6,  1012,    -1,   969,
      -1,   970,    -1,   971,    -1,    46,    -1,    45,     3,  1012,
      -1,   973,    -1,   974,    -1,   975,    -1,    54,    -1,    53,
       3,  1012,    -1,   977,    -1,   978,    -1,   979,    -1,    48,
      -1,    47,     3,  1012,    -1,   981,    -1,   982,    -1,   983,
      -1,    58,    -1,    57,     3,  1012,    -1,   985,    -1,   986,
      -1,   987,    -1,    60,    -1,    59,     3,  1012,    -1,   989,
      -1,   990,    -1,   991,    -1,    56,    -1,    55,     3,  1012,
      -1,    16,  1012,     6,  1012,    -1,    17,  1012,     6,  1012,
      -1,    18,  1012,     6,  1012,    -1,    19,  1012,     6,  1012,
      -1,    21,  1012,     6,  1012,    -1,    22,  1012,     6,  1012,
      -1,    23,  1012,     6,  1012,    -1,    24,  1012,     6,  1012,
      -1,    25,  1012,     6,  1012,    -1,    26,  1012,     6,  1012,
      -1,    27,  1012,     6,  1012,    -1,    28,  1012,     6,  1012,
      -1,    29,  1012,     6,  1012,    -1,    30,  1012,     6,  1012,
      -1,    31,  1012,     6,  1012,    -1,    32,  1012,     6,  1012,
      -1,    33,  1012,     6,  1012,    -1,    34,  1012,     6,  1012,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1013,     8,    -1,    -1,  1013,  1014,    -1,   239,    -1,
     240,    -1,   241,    -1,   242,    -1,  1016,  1017,    -1,    65,
      -1,  1018,    -1,  1019,    -1,    10,    66,    -1,    11,    -1,
      10,  1020,    66,    -1,  1021,    -1,  1022,    -1,  1021,  1022,
      -1,  1023,    -1,  1027,    -1,  1031,    -1,  1035,    -1,  1039,
      -1,    -1,  1024,    -1,  1025,    -1,  1026,    -1,    84,    -1,
      83,    -1,    81,     5,    82,    -1,    -1,  1028,    -1,  1029,
      -1,  1030,    -1,    88,    -1,    87,    -1,    85,     5,    86,
      -1,    -1,  1032,    -1,  1033,    -1,  1034,    -1,    92,    -1,
      91,    -1,    89,     5,    90,    -1,    -1,  1036,    -1,  1037,
      -1,  1038,    -1,    96,    -1,    95,    -1,    93,     5,    94,
      -1,    -1,  1040,    -1,  1041,    -1,  1042,    -1,   100,    -1,
      99,    -1,    97,     5,    98,    -1,  1044,    -1,  1051,    -1,
      -1,  1044,  1045,    -1,  1046,  1047,  1050,    -1,   135,    -1,
    1048,    -1,    -1,  1048,  1049,    -1,  1057,    -1,  1056,    -1,
      10,     6,   136,    -1,   117,  1052,  1053,    -1,    40,  1012,
       6,  1012,    -1,  1054,    -1,  1055,    -1,    10,   118,    -1,
      11,    -1,    10,     4,   118,    -1,    38,  1012,     6,  1012,
      -1,    39,  1012,     6,  1012,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   211,   213,   220,   230,   230,   232,   232,
     234,   236,   238,   247,   248,   251,   260,   260,   273,   273,
     275,   289,   289,   291,   291,   293,   295,   297,   297,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   311,   313,
     328,   335,   335,   338,   343,   347,   356,   360,   365,   365,
     367,   369,   371,   371,   373,   378,   388,   394,   394,   397,
     402,   408,   408,   411,   413,   420,   420,   422,   422,   424,
     426,   429,   431,   438,   438,   440,   440,   442,   444,   449,
     451,   458,   458,   460,   460,   462,   464,   469,   471,   478,
     478,   480,   480,   482,   484,   489,   491,   498,   498,   500,
     500,   502,   504,   509,   511,   518,   518,   520,   520,   522,
     524,   529,   531,   538,   538,   540,   540,   542,   544,   549,
     551,   558,   568,   573,   579,   579,   581,   583,   585,   585,
     587,   592,   604,   610,   610,   613,   620,   625,   632,   632,
     636,   636,   638,   649,   649,   651,   651,   653,   655,   657,
     657,   660,   661,   662,   663,   664,   665,   668,   670,   677,
     677,   679,   679,   681,   683,   690,   692,   703,   705,   705,
     708,   714,   720,   722,   728,   730,   741,   743,   743,   746,
     752,   758,   760,   767,   769,   780,   782,   782,   785,   791,
     797,   799,   806,   808,   817,   818,   824,   826,   832,   834,
     841,   851,   856,   862,   862,   864,   866,   868,   868,   870,
     875,   887,   893,   893,   896,   903,   908,   914,   914,   918,
     918,   920,   931,   931,   933,   933,   935,   937,   939,   939,
     942,   943,   944,   945,   946,   947,   950,   952,   959,   959,
     961,   961,   963,   965,   973,   975,   982,   982,   984,   984,
     986,   988,   993,   995,  1002,  1002,  1004,  1004,  1006,  1008,
    1013,  1015,  1022,  1022,  1024,  1024,  1026,  1028,  1033,  1035,
    1042,  1042,  1044,  1044,  1046,  1048,  1055,  1057,  1064,  1074,
    1079,  1085,  1085,  1087,  1089,  1091,  1091,  1093,  1098,  1110,
    1116,  1116,  1119,  1126,  1131,  1138,  1138,  1141,  1141,  1143,
    1159,  1159,  1161,  1161,  1163,  1165,  1167,  1167,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1183,
    1185,  1192,  1192,  1194,  1194,  1196,  1198,  1206,  1208,  1215,
    1215,  1217,  1217,  1219,  1221,  1226,  1228,  1235,  1235,  1237,
    1237,  1239,  1241,  1246,  1248,  1255,  1255,  1257,  1257,  1259,
    1261,  1266,  1268,  1275,  1275,  1277,  1277,  1279,  1281,  1286,
    1288,  1295,  1305,  1310,  1316,  1316,  1318,  1320,  1322,  1322,
    1324,  1326,  1340,  1340,  1343,  1343,  1343,  1343,  1346,  1346,
    1348,  1348,  1350,  1352,  1361,  1362,  1365,  1367,  1378,  1380,
    1380,  1383,  1389,  1395,  1397,  1404,  1406,  1417,  1419,  1419,
    1422,  1428,  1434,  1436,  1443,  1445,  1456,  1458,  1458,  1461,
    1467,  1473,  1475,  1482,  1484,  1494,  1495,  1501,  1503,  1510,
    1512,  1519,  1529,  1534,  1540,  1540,  1542,  1544,  1546,  1546,
    1548,  1553,  1565,  1571,  1571,  1574,  1581,  1586,  1593,  1593,
    1596,  1596,  1598,  1606,  1612,  1612,  1615,  1622,  1628,  1634,
    1642,  1647,  1653,  1653,  1655,  1657,  1659,  1659,  1661,  1663,
    1672,  1674,  1674,  1676,  1676,  1676,  1678,  1688,  1698,  1718,
    1724,  1726,  1736,  1742,  1742,  1745,  1750,  1755,  1765,  1770,
    1776,  1776,  1778,  1780,  1782,  1782,  1784,  1789,  1799,  1805,
    1805,  1808,  1814,  1821,  1821,  1824,  1824,  1826,  1828,  1828,
    1830,  1830,  1832,  1834,  1842,  1842,  1844,  1850,  1850,  1858,
    1858,  1860,  1862,  1864,  1866,  1866,  1868,  1870,  1878,  1883,
    1889,  1889,  1891,  1893,  1895,  1895,  1897,  1908,  1917,  1917,
    1920,  1921,  1924,  1927,  1927,  1929,  1931,  1939,  1944,  1950,
    1950,  1952,  1954,  1956,  1956,  1958,  1969,  1978,  1978,  1981,
    1982,  1986,  1987,  1989,  1989,  1991,  1993,  1998,  1998,  2000,
    2005,  2005,  2007,  2009,  2011,  2013,  2013,  2022,  2024,  2031,
    2031,  2033,  2035,  2037,  2040,  2040,  2050,  2052,  2059,  2059,
    2061,  2063,  2065,  2068,  2068,  2077,  2079,  2086,  2086,  2088,
    2090,  2092,  2095,  2095,  2104,  2106,  2113,  2113,  2115,  2117,
    2119,  2122,  2122,  2131,  2133,  2140,  2140,  2142,  2144,  2146,
    2149,  2149,  2158,  2160,  2167,  2167,  2169,  2171,  2173,  2176,
    2176,  2185,  2187,  2194,  2194,  2196,  2198,  2200,  2203,  2203,
    2205,  2210,  2229,  2235,  2235,  2238,  2249,  2260,  2266,  2272,
    2278,  2284,  2290,  2297,  2297,  2299,  2299,  2301,  2303,  2303,
    2305,  2305,  2307,  2314,  2323,  2323,  2326,  2332,  2339,  2339,
    2341,  2341,  2343,  2345,  2354,  2354,  2356,  2367,  2375,  2381,
    2381,  2384,  2390,  2391,  2395,  2395,  2397,  2399,  2402,  2406,
    2406,  2408,  2416,  2416,  2424,  2424,  2426,  2428,  2430,  2432,
    2432,  2434,  2436,  2444,  2449,  2455,  2455,  2457,  2459,  2462,
    2462,  2464,  2473,  2483,  2483,  2486,  2487,  2490,  2493,  2493,
    2495,  2500,  2500,  2503,  2505,  2507,  2509,  2509,  2518,  2520,
    2527,  2527,  2529,  2531,  2533,  2535,  2535,  2544,  2546,  2553,
    2553,  2555,  2557,  2559,  2562,  2562,  2571,  2573,  2580,  2580,
    2582,  2584,  2586,  2589,  2589,  2598,  2600,  2607,  2607,  2609,
    2611,  2613,  2616,  2616,  2625,  2627,  2634,  2634,  2636,  2638,
    2640,  2643,  2643,  2652,  2654,  2661,  2661,  2663,  2665,  2667,
    2670,  2670,  2679,  2681,  2688,  2688,  2690,  2692,  2694,  2697,
    2697,  2699,  2705,  2724,  2731,  2731,  2734,  2745,  2756,  2762,
    2768,  2774,  2780,  2786,  2795,  2795,  2797,  2797,  2799,  2801,
    2801,  2803,  2803,  2805,  2810,  2820,  2820,  2823,  2828,  2835,
    2835,  2837,  2837,  2839,  2841,  2848,  2848,  2850,  2861,  2869,
    2875,  2875,  2878,  2884,  2885,  2889,  2889,  2891,  2893,  2896,
    2899,  2899,  2901,  2908,  2908,  2916,  2916,  2918,  2920,  2922,
    2924,  2924,  2926,  2929,  2937,  2942,  2948,  2948,  2950,  2952,
    2954,  2954,  2956,  2965,  2974,  2974,  2977,  2978,  2981,  2984,
    2984,  2986,  2991,  2991,  2993,  2995,  2997,  2999,  2999,  3008,
    3010,  3017,  3017,  3019,  3021,  3023,  3025,  3025,  3034,  3036,
    3043,  3043,  3045,  3047,  3049,  3052,  3052,  3061,  3063,  3070,
    3070,  3072,  3074,  3076,  3079,  3079,  3088,  3090,  3097,  3097,
    3099,  3101,  3103,  3106,  3106,  3115,  3117,  3124,  3124,  3126,
    3128,  3130,  3133,  3133,  3142,  3144,  3151,  3151,  3153,  3155,
    3157,  3160,  3160,  3169,  3171,  3178,  3178,  3180,  3182,  3184,
    3187,  3187,  3189,  3195,  3214,  3220,  3220,  3223,  3234,  3245,
    3251,  3257,  3263,  3269,  3275,  3282,  3282,  3284,  3284,  3286,
    3288,  3288,  3290,  3290,  3292,  3299,  3308,  3308,  3312,  3317,
    3325,  3325,  3327,  3327,  3329,  3331,  3338,  3338,  3340,  3351,
    3359,  3365,  3365,  3368,  3374,  3375,  3379,  3379,  3381,  3383,
    3385,  3389,  3389,  3391,  3396,  3405,  3410,  3416,  3416,  3418,
    3420,  3422,  3422,  3424,  3429,  3443,  3451,  3451,  3454,  3460,
    3466,  3472,  3480,  3490,  3495,  3501,  3501,  3503,  3505,  3507,
    3507,  3509,  3515,  3520,  3522,  3522,  3524,  3526,  3538,  3538,
    3540,  3545,  3554,  3559,  3565,  3565,  3567,  3569,  3571,  3571,
    3573,  3578,  3590,  3598,  3598,  3601,  3606,  3612,  3618,  3627,
    3632,  3638,  3638,  3640,  3642,  3644,  3644,  3646,  3652,  3657,
    3659,  3659,  3661,  3663,  3674,  3681,  3681,  3683,  3688,  3693,
    3700,  3700,  3702,  3707,  3712,  3719,  3719,  3721,  3726,  3731,
    3738,  3738,  3740,  3745,  3750,  3758,  3765,  3765,  3767,  3772,
    3777,  3784,  3784,  3786,  3791,  3796,  3803,  3803,  3805,  3810,
    3815,  3822,  3822,  3824,  3829,  3834,  3841,  3841,  3843,  3848,
    3853,  3860,  3860,  3862,  3867,  3873,  3879,  3888,  3894,  3908,
    3917,  3923,  3932,  3938,  3944,  3950,  3956,  3962,  3971,  3977,
    3986,  3991,  3997,  4014,  4015,  4019,  4020,  4021,  4023,  4025,
    4025,  4027,  4028,  4029,  4030,  4063,  4065,  4079,  4079,  4081,
    4081,  4083,  4085,  4087,  4087,  4090,  4091,  4092,  4093,  4094,
    4096,  4096,  4104,  4104,  4106,  4106,  4108,  4114,  4114,  4122,
    4122,  4124,  4124,  4126,  4132,  4132,  4140,  4140,  4142,  4142,
    4144,  4150,  4150,  4158,  4158,  4160,  4160,  4162,  4168,  4168,
    4176,  4176,  4178,  4178,  4180,  4192,  4200,  4202,  4202,  4204,
    4206,  4215,  4217,  4217,  4219,  4219,  4221,  4237,  4239,  4244,
    4244,  4246,  4246,  4249,  4275,  4283
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
  "NUMBEROFBLOCKSATT", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'",
  "$accept", "osrldoc", "osrlStartEmpty", "osrlStart", "osrlAttributes",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   243,   244,   244,   245,   246,   247,   247,   248,   248,
     249,   250,   251,   252,   252,   253,   254,   254,   255,   255,
     256,   257,   257,   258,   258,   259,   260,   261,   261,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   264,
     265,   266,   266,   267,   267,   267,   268,   268,   269,   269,
     270,   271,   272,   272,   273,   274,   275,   276,   276,   277,
     277,   278,   278,   279,   280,   281,   281,   282,   282,   283,
     284,   285,   286,   287,   287,   288,   288,   289,   290,   291,
     292,   293,   293,   294,   294,   295,   296,   297,   298,   299,
     299,   300,   300,   301,   302,   303,   304,   305,   305,   306,
     306,   307,   308,   309,   310,   311,   311,   312,   312,   313,
     314,   315,   316,   317,   317,   318,   318,   319,   320,   321,
     322,   323,   324,   324,   325,   325,   326,   327,   328,   328,
     329,   330,   331,   332,   332,   333,   333,   333,   334,   334,
     335,   335,   336,   337,   337,   338,   338,   339,   340,   341,
     341,   342,   342,   342,   342,   342,   342,   343,   344,   345,
     345,   346,   346,   347,   348,   349,   350,   351,   352,   352,
     353,   353,   354,   355,   356,   357,   358,   359,   359,   360,
     360,   361,   362,   363,   364,   365,   366,   366,   367,   367,
     368,   369,   370,   371,   372,   372,   373,   374,   375,   376,
     377,   378,   378,   379,   379,   380,   381,   382,   382,   383,
     384,   385,   386,   386,   387,   387,   387,   388,   388,   389,
     389,   390,   391,   391,   392,   392,   393,   394,   395,   395,
     396,   396,   396,   396,   396,   396,   397,   398,   399,   399,
     400,   400,   401,   402,   403,   404,   405,   405,   406,   406,
     407,   408,   409,   410,   411,   411,   412,   412,   413,   414,
     415,   416,   417,   417,   418,   418,   419,   420,   421,   422,
     423,   423,   424,   424,   425,   426,   427,   428,   429,   430,
     430,   431,   431,   432,   433,   434,   434,   435,   436,   437,
     438,   438,   439,   439,   439,   440,   440,   441,   441,   442,
     443,   443,   444,   444,   445,   446,   447,   447,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   449,
     450,   451,   451,   452,   452,   453,   454,   455,   456,   457,
     457,   458,   458,   459,   460,   461,   462,   463,   463,   464,
     464,   465,   466,   467,   468,   469,   469,   470,   470,   471,
     472,   473,   474,   475,   475,   476,   476,   477,   478,   479,
     480,   481,   482,   482,   483,   483,   484,   485,   486,   486,
     487,   488,   489,   489,   490,   490,   490,   490,   491,   491,
     492,   492,   493,   494,   495,   495,   496,   497,   498,   499,
     499,   500,   500,   501,   502,   503,   504,   505,   506,   506,
     507,   507,   508,   509,   510,   511,   512,   513,   513,   514,
     514,   515,   516,   517,   518,   519,   519,   520,   521,   522,
     523,   524,   525,   525,   526,   526,   527,   528,   529,   529,
     530,   531,   532,   533,   533,   534,   534,   534,   535,   535,
     536,   536,   537,   538,   539,   539,   540,   540,   540,   540,
     541,   541,   542,   542,   543,   544,   545,   545,   546,   547,
     548,   549,   549,   550,   550,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   558,   559,   559,   559,   560,   560,
     561,   561,   562,   563,   564,   564,   565,   566,   567,   568,
     568,   569,   569,   570,   570,   571,   571,   572,   573,   573,
     574,   574,   575,   576,   577,   577,   578,   579,   579,   580,
     580,   581,   582,   583,   584,   584,   585,   586,   587,   587,
     588,   588,   589,   590,   591,   591,   592,   593,   594,   594,
     595,   595,   596,   597,   597,   598,   599,   600,   600,   601,
     601,   602,   603,   604,   604,   605,   606,   607,   607,   608,
     608,   609,   609,   610,   610,   611,   612,   613,   613,   614,
     615,   615,   616,   617,   618,   619,   619,   620,   621,   622,
     622,   623,   624,   625,   626,   626,   627,   628,   629,   629,
     630,   631,   632,   633,   633,   634,   635,   636,   636,   637,
     638,   639,   640,   640,   641,   642,   643,   643,   644,   645,
     646,   647,   647,   648,   649,   650,   650,   651,   652,   653,
     654,   654,   655,   656,   657,   657,   658,   659,   660,   661,
     661,   662,   663,   664,   664,   665,   666,   667,   668,   668,
     669,   670,   671,   672,   672,   673,   673,   673,   673,   673,
     673,   673,   673,   674,   674,   675,   675,   676,   677,   677,
     678,   678,   679,   680,   681,   681,   682,   682,   683,   683,
     684,   684,   685,   686,   687,   687,   688,   689,   690,   691,
     691,   692,   692,   692,   693,   693,   694,   695,   696,   697,
     697,   698,   699,   699,   700,   700,   701,   702,   703,   704,
     704,   705,   706,   707,   707,   708,   708,   709,   710,   711,
     711,   712,   713,   714,   714,   715,   715,   716,   717,   717,
     718,   719,   719,   720,   721,   722,   723,   723,   724,   725,
     726,   726,   727,   728,   729,   730,   730,   731,   732,   733,
     733,   734,   735,   736,   737,   737,   738,   739,   740,   740,
     741,   742,   743,   744,   744,   745,   746,   747,   747,   748,
     749,   750,   751,   751,   752,   753,   754,   754,   755,   756,
     757,   758,   758,   759,   760,   761,   761,   762,   763,   764,
     765,   765,   766,   767,   768,   768,   769,   770,   771,   772,
     772,   773,   774,   775,   776,   776,   777,   777,   777,   777,
     777,   777,   777,   777,   778,   778,   779,   779,   780,   781,
     781,   782,   782,   783,   784,   785,   785,   786,   786,   787,
     787,   788,   788,   789,   790,   791,   791,   792,   793,   794,
     795,   795,   796,   796,   796,   797,   797,   798,   799,   800,
     801,   801,   802,   803,   803,   804,   804,   805,   806,   807,
     808,   808,   809,   810,   811,   811,   812,   812,   813,   814,
     815,   815,   816,   817,   818,   818,   819,   819,   820,   821,
     821,   822,   823,   823,   824,   825,   826,   827,   827,   828,
     829,   830,   830,   831,   832,   833,   834,   834,   835,   836,
     837,   837,   838,   839,   840,   841,   841,   842,   843,   844,
     844,   845,   846,   847,   848,   848,   849,   850,   851,   851,
     852,   853,   854,   855,   855,   856,   857,   858,   858,   859,
     860,   861,   862,   862,   863,   864,   865,   865,   866,   867,
     868,   869,   869,   870,   871,   872,   872,   873,   874,   875,
     876,   876,   877,   878,   879,   880,   880,   881,   881,   881,
     881,   881,   881,   881,   881,   882,   882,   883,   883,   884,
     885,   885,   886,   886,   887,   888,   889,   889,   890,   890,
     891,   891,   892,   892,   893,   894,   895,   895,   896,   897,
     898,   899,   899,   900,   900,   900,   901,   901,   902,   903,
     904,   905,   905,   906,   907,   908,   908,   909,   909,   910,
     911,   912,   912,   913,   914,   915,   916,   916,   917,   917,
     917,   917,   917,   918,   918,   919,   919,   920,   921,   922,
     922,   923,   924,   924,   925,   925,   926,   927,   928,   928,
     929,   930,   931,   931,   932,   932,   933,   934,   935,   935,
     936,   937,   938,   939,   939,   940,   940,   940,   940,   941,
     941,   942,   942,   943,   944,   945,   945,   946,   947,   947,
     948,   948,   949,   950,   951,   952,   952,   953,   954,   955,
     956,   956,   957,   958,   959,   960,   960,   961,   962,   963,
     964,   964,   965,   966,   967,   968,   969,   969,   970,   971,
     972,   973,   973,   974,   975,   976,   977,   977,   978,   979,
     980,   981,   981,   982,   983,   984,   985,   985,   986,   987,
     988,   989,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1010,  1011,  1011,  1011,  1012,  1013,
    1013,  1014,  1014,  1014,  1014,  1015,  1016,  1017,  1017,  1018,
    1018,  1019,  1020,  1021,  1021,  1022,  1022,  1022,  1022,  1022,
    1023,  1023,  1024,  1024,  1025,  1025,  1026,  1027,  1027,  1028,
    1028,  1029,  1029,  1030,  1031,  1031,  1032,  1032,  1033,  1033,
    1034,  1035,  1035,  1036,  1036,  1037,  1037,  1038,  1039,  1039,
    1040,  1040,  1041,  1041,  1042,  1043,  1043,  1044,  1044,  1045,
    1046,  1047,  1048,  1048,  1049,  1049,  1050,  1051,  1052,  1053,
    1053,  1054,  1054,  1055,  1056,  1057
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
#define YYPACT_NINF -1337
static const yytype_int16 yypact[] =
{
     269, -1337, -1337,    68,    28,    83, -1337, -1337,    99,    55,
   -1337,   283, -1337,   325, -1337, -1337, -1337, -1337,    72,   327,
     634, -1337, -1337, -1337, -1337,    28, -1337, -1337, -1337, -1337,
   -1337,    17,   357,   -26, -1337, -1337, -1337, -1337, -1337,   142,
   -1337, -1337,   151, -1337, -1337,   160, -1337, -1337,   184, -1337,
   -1337,   186, -1337, -1337,   135,   663, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,    99, -1337,   134,
     380,   -15, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   155,   198, -1337, -1337,
     432, -1337,   387, -1337,   398, -1337,   407, -1337,   421, -1337,
     428, -1337,   439, -1337,   450, -1337,   193,   147,   158,   164,
     162,   152, -1337, -1337, -1337, -1337,   194,   467,    -5, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     201,   146, -1337, -1337,   473, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   442, -1337,   193, -1337, -1337, -1337,   286, -1337,
     292, -1337,   477,   432, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,    27, -1337, -1337, -1337, -1337,    20,
   -1337, -1337, -1337, -1337,    19, -1337, -1337, -1337, -1337,    37,
   -1337, -1337, -1337, -1337,    31, -1337, -1337, -1337, -1337,    33,
   -1337, -1337, -1337, -1337,     6, -1337, -1337, -1337, -1337, -1337,
     479, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     119, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   238,   -59, -1337, -1337,   482, -1337,   485, -1337,
     487, -1337,   493, -1337,   495, -1337,   193, -1337, -1337,     8,
   -1337, -1337, -1337, -1337,   302,   109,   310,   109,   314,   109,
     330, -1337,   497, -1337,   337,    -1, -1337, -1337,   -90, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   192, -1337, -1337,   172,
   -1337, -1337,   176, -1337, -1337,   206, -1337, -1337,   210, -1337,
   -1337,   180, -1337, -1337,   167,   365,   -21, -1337, -1337, -1337,
   -1337,   499,    56, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   306,   144, -1337, -1337,   501,
   -1337,   504, -1337,   512, -1337,   514, -1337,   516, -1337,   352,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   442, -1337,   193,
   -1337, -1337,    46, -1337, -1337, -1337, -1337,    40, -1337, -1337,
   -1337, -1337,     3, -1337, -1337, -1337, -1337,    11, -1337, -1337,
   -1337, -1337,    38, -1337, -1337, -1337, -1337,   519, -1337, -1337,
   -1337,   196,   525, -1337,   385, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   525, -1337, -1337, -1337, -1337,   525, -1337, -1337,
   -1337, -1337,   394, -1337,    16, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     262,   215, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   244,   260, -1337, -1337,   -33, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,    18, -1337, -1337, -1337, -1337,    13,
   -1337, -1337, -1337, -1337,    22, -1337, -1337, -1337, -1337,    52,
   -1337, -1337, -1337, -1337,    36, -1337, -1337, -1337, -1337, -1337,
     523, -1337,   424,   109,   431,   109,   441,   109,   445, -1337,
     533, -1337, -1337, -1337,   332, -1337, -1337,   341, -1337, -1337,
     256, -1337, -1337,   267, -1337, -1337, -1337,   293, -1337,    65,
   -1337, -1337, -1337, -1337, -1337,   367, -1337, -1337,   384, -1337,
     408, -1337, -1337,   430, -1337, -1337,   388,   375, -1337, -1337,
   -1337, -1337, -1337,   535,   222, -1337, -1337, -1337,   538,   203,
   -1337, -1337,   481,   -37, -1337, -1337,   567,   571,   573,   617,
   -1337, -1337,   377, -1337, -1337,   404, -1337, -1337,   393, -1337,
   -1337,   509, -1337, -1337,   496,   633,  -115, -1337, -1337, -1337,
   -1337,   525, -1337, -1337, -1337, -1337,   525, -1337, -1337, -1337,
   -1337,   525, -1337, -1337, -1337, -1337,   638, -1337,   141, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     494,   488, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   541,   203,   476, -1337, -1337,   673, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   529, -1337, -1337,   680, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     671,   689,    74, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   505,   506, -1337, -1337,   510,
   -1337,   527, -1337,   508, -1337, -1337,   503, -1337, -1337,   566,
     576, -1337, -1337, -1337, -1337,   549,   203,   585, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   551,
   -1337,   570, -1337, -1337,   750,   778, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   372, -1337, -1337,
   -1337, -1337, -1337, -1337,   553,   203,   621, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   755,   -54, -1337, -1337,
   -1337, -1337, -1337,   635,   432,   780, -1337, -1337,    23, -1337,
     784, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   625, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   618,   606, -1337, -1337, -1337,   569,
     559,   561,   432, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   596, -1337, -1337, -1337, -1337, -1337, -1337,
     565,   401, -1337,   641,   768,    30, -1337, -1337, -1337, -1337,
     128, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   -14,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   666,   770, -1337,   580, -1337, -1337, -1337,   646, -1337,
   -1337,   613,   608, -1337, -1337,   797, -1337, -1337, -1337,   619,
     156, -1337, -1337, -1337, -1337,   798, -1337,   637,   779, -1337,
     582, -1337,   801,   592, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   588,   253, -1337,   730, -1337, -1337, -1337, -1337,   628,
     785, -1337,   591, -1337,   807,   598, -1337, -1337, -1337, -1337,
   -1337, -1337,   590,   600,   783,   629, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   595, -1337,   811,   690, -1337,
   -1337, -1337, -1337, -1337, -1337,   660,   699,   800, -1337, -1337,
   -1337,   704,   783, -1337,   597, -1337, -1337,   818,    43, -1337,
   -1337, -1337, -1337, -1337, -1337,   698,   706,   812, -1337, -1337,
   -1337, -1337,   599, -1337,   603, -1337, -1337, -1337,   605,   607,
   -1337,   823,   108, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     661,   665, -1337, -1337, -1337, -1337, -1337, -1337,   609, -1337,
     611, -1337,   667,   715, -1337, -1337, -1337, -1337,   829,   -95,
   -1337, -1337, -1337, -1337,   674,   719, -1337, -1337, -1337, -1337,
     315, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   622,   620,
   -1337, -1337, -1337, -1337, -1337,   627,   231,   682,   723, -1337,
   -1337, -1337, -1337,   837,    34, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   722,   741,   830, -1337, -1337, -1337,   631,
     692, -1337, -1337, -1337, -1337, -1337, -1337,   728,   748,   830,
   -1337, -1337,   640,   642, -1337, -1337, -1337, -1337, -1337,   348,
       1, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   732,   751,   830, -1337, -1337,
   -1337,   721,   733, -1337, -1337,   632,   581, -1337, -1337,   752,
     830, -1337,   636, -1337, -1337, -1337, -1337,   391,   639,   626,
   -1337, -1337,   757,   830,   643, -1337, -1337, -1337,   118,   525,
   -1337, -1337, -1337, -1337, -1337,   852, -1337, -1337, -1337,   693,
     208, -1337, -1337, -1337, -1337,   645,   537, -1337, -1337,   759,
     830,   647, -1337, -1337, -1337, -1337,   411,   -60, -1337, -1337,
   -1337, -1337, -1337,   859, -1337,   862, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   764,   830,   652, -1337,   863,   753, -1337,
   -1337, -1337, -1337,   525, -1337, -1337, -1337, -1337,   -78, -1337,
   -1337, -1337, -1337,   865, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   771,   830,
     654, -1337,   753, -1337, -1337, -1337, -1337,     0, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   650,   867, -1337,   799, -1337,
   -1337,   -61, -1337, -1337, -1337, -1337,   872, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   775,   830,   656, -1337,   753, -1337, -1337, -1337, -1337,
     525, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   712,   724,
   -1337, -1337,   743, -1337, -1337,   875, -1337, -1337, -1337,   734,
     830,   669, -1337,   753, -1337, -1337, -1337, -1337, -1337,   842,
     766, -1337,   749, -1337,   729, -1337, -1337, -1337,   726,   668,
   -1337, -1337,   756, -1337, -1337, -1337, -1337,   738,   830,   677,
   -1337,   753, -1337, -1337, -1337, -1337,   772, -1337, -1337, -1337,
     672, -1337, -1337, -1337, -1337, -1337, -1337,   731,   763, -1337,
   -1337,   761, -1337, -1337, -1337, -1337,   742,   830,   679, -1337,
     753, -1337, -1337, -1337, -1337,   776, -1337,   774, -1337, -1337,
     268, -1337,   681,    73, -1337, -1337, -1337, -1337,   708,   830,
     685, -1337,   753, -1337, -1337, -1337, -1337,   791, -1337, -1337,
   -1337,   687, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   350,
   -1337,   695,    73, -1337, -1337,   709,   830,   697, -1337,   753,
   -1337, -1337, -1337, -1337,   793, -1337, -1337, -1337, -1337, -1337,
   -1337,   366, -1337,   701,    73, -1337, -1337,   711,   830,   725,
   -1337,   753, -1337, -1337, -1337, -1337,   802, -1337, -1337, -1337,
      32, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   753, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   700,
     830,   727, -1337,   753, -1337, -1337, -1337, -1337,   803, -1337,
   -1337,   899,    44, -1337, -1337, -1337, -1337,   900,   703,    21,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   753, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   702,   830,   754,
   -1337,   753, -1337, -1337, -1337, -1337,   804, -1337, -1337,    47,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   753, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   707,   830,   758,
   -1337,   753, -1337, -1337, -1337, -1337,   805, -1337, -1337, -1337,
   -1337, -1337, -1337,   777, -1337,   782, -1337, -1337, -1337,   830,
     760, -1337,   753, -1337, -1337, -1337, -1337,   813, -1337, -1337,
   -1337,   806, -1337,   909, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   694, -1337,   787, -1337, -1337, -1337,   830,   762, -1337,
     753, -1337, -1337, -1337, -1337,   814, -1337, -1337, -1337,   795,
   -1337,   788, -1337, -1337, -1337,   830,   765, -1337,   753, -1337,
   -1337, -1337, -1337,   819, -1337, -1337, -1337, -1337,   767, -1337,
     753, -1337, -1337, -1337, -1337,   781, -1337, -1337, -1337, -1337,
     786,   921,   922, -1337, -1337,   769, -1337,   753, -1337, -1337,
   -1337, -1337,   789, -1337, -1337, -1337, -1337,   773, -1337,   753,
   -1337, -1337, -1337, -1337,   790, -1337, -1337,   753, -1337, -1337,
   -1337, -1337,   735, -1337, -1337, -1337, -1337, -1337,   753, -1337,
   -1337, -1337, -1337,   736, -1337, -1337,   753, -1337, -1337, -1337,
   -1337,   740, -1337, -1337,   737, -1337, -1337, -1337, -1337,   739,
   -1337, -1337,   744, -1337, -1337, -1337, -1337, -1337
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   855, -1337,
     910, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   839,
   -1337, -1337, -1337, -1337,   792, -1337, -1337, -1337, -1337, -1337,
     526, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   513, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   808,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     425, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   710, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   353, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   644, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   295, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   288, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   417, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   189, -1337, -1337, -1337,
   -1337, -1337,   131, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   -25,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   -67, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,  -302, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,  -304, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   -51,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    -268, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -270,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   -89, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,  -324, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,  -326, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
      25, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    -123, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   213, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   139, -1337, -1337, -1337, -1337,  -770, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,  -150, -1337, -1337, -1337,
    -985, -1337, -1337, -1337, -1059,  -528, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,  -691, -1337, -1337, -1337,  -243, -1337, -1337,
   -1337,  -597, -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -126,
   -1337,  -998,  -977,   -13,   -85, -1337, -1337, -1337,  -134, -1337,
   -1337, -1337, -1337,  -663, -1337,  -870, -1337,  -369, -1336,  -209,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   917,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1085, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     295,   621,   261,   506,  1278,   673,   741,   400,  1146,   488,
     292,   806,   369,   509,   386,   491,   391,   543,   511,  1183,
     263,  1075,   540,   280,   277,  1479,   546,  1480,  1481,   770,
     771,   274,   930,   765,   816,   286,  1479,   289,  1480,  1481,
     552,   283,    86,   530,   494,   495,   485,  1223,  1501,  1102,
     482,  1479,   408,  1480,  1481,   133,   549,   406,   407,  1255,
    1007,   766,  1136,   825,  1284,   826,   827,   225,     6,   712,
     226,   765,   227,   433,   672,  1171,  1285,  1225,  1085,   434,
    1086,  1087,   643,  1512,  1157,   435,  1256,  1277,    78,   644,
     436,  1061,  1165,     7,   134,  1226,   135,    12,   136,   766,
     137,   409,  1214,  1286,  1227,   377,   228,   385,   749,   390,
     683,  1204,   368,  1530,    14,    87,   158,   159,   752,  1209,
     229,    88,    17,  1008,   226,    89,   227,    90,  1177,  1178,
    1306,   753,   617,   618,   627,   684,  1242,   685,   711,    91,
     230,    30,   422,  1257,   531,   423,   231,   117,   531,    92,
     138,    93,   158,   159,   550,  1080,   118,    94,  1328,  1049,
     228,   880,  1502,   606,   607,   119,   374,   375,  1050,  1088,
     486,  1270,   828,  1528,   229,    95,   553,   748,   483,   514,
     139,   275,   515,   287,   817,   284,  1355,   479,  1482,   120,
     520,   121,   650,   303,   230,   281,   547,   652,   278,  1166,
     231,   122,   654,   544,   370,   481,   541,   125,   293,   489,
     938,   492,   525,   939,  1299,  1377,  1036,   290,   496,   209,
     304,   772,  1279,   155,   536,   537,   538,   539,   588,   212,
     565,   589,   570,   825,   575,   826,   827,  1409,   401,   402,
     403,   404,  1321,  1510,   213,   304,   158,   159,   606,   607,
     216,  1386,   804,   808,   214,   134,   215,   135,   305,   136,
     555,   137,   617,   618,  1447,   158,   159,   606,   607,   217,
    1348,   247,   730,   731,   158,   159,   606,   607,  1380,  1381,
    1425,     1,     2,   305,   306,  1085,  1477,  1086,  1087,   266,
     617,   618,   307,    20,    21,   267,   158,   159,   595,  1370,
     160,   161,  1455,  1486,   657,  1080,   308,   658,   309,   306,
     340,   138,   372,   606,   607,  1396,   819,   307,  1498,   820,
     382,  1402,   310,   564,   387,   569,   976,   574,   311,   977,
     312,   308,   313,   309,   314,    25,    26,    33,    34,    87,
     392,   139,  1514,   399,  1435,    88,   414,   310,  1440,    89,
     415,    90,   416,   311,   417,   312,  1526,   313,  1079,   314,
    1419,  1420,   418,    91,   419,  1128,  1465,    81,    82,   420,
    1470,   421,  1532,    92,   609,    93,  1449,  1450,  1159,   620,
     442,    94,   728,   729,   469,  1080,  1544,  1080,   507,  1039,
     128,   129,   504,   606,   607,   606,   607,   174,   175,    95,
     512,  1143,  1491,  1080,   521,  1206,   409,  1556,   179,   180,
     526,   606,   607,   730,   731,   158,   159,   184,   185,   160,
     161,  1220,   804,   422,   690,   691,   692,   693,  1080,   374,
     375,   189,   190,   694,   561,  1573,   606,   607,   194,   195,
    1519,   566,   730,   731,   158,   159,   606,   607,  1080,   199,
     200,   571,   671,  1585,   742,   576,   606,   607,  1038,  1129,
     204,   205,   585,   157,   583,  1593,   714,   586,   715,   716,
    1537,   584,  1160,   587,   725,   158,   159,   220,   221,   160,
     161,   594,  1604,   249,   250,   158,   159,   268,   269,   296,
     297,  1549,   342,   343,  1612,   347,   348,   352,   353,  1207,
     596,  1084,  1615,   357,   358,   362,   363,   394,   395,   428,
     429,   444,   445,  1620,   449,   450,   710,   768,   769,  1566,
     597,  1623,   454,   455,   459,   460,   464,   465,  1123,   499,
     500,   494,   495,   556,   557,  1020,  1021,  1578,   514,  1147,
     598,  1158,   777,   578,   579,   603,   604,   740,   614,   615,
    1184,   667,   668,   949,   599,   747,  1112,   626,   796,   706,
     707,   717,   718,   743,   744,   637,   798,   639,  1205,   785,
     786,   790,   791,   633,   764,   799,   800,   634,  1224,   635,
     158,   159,   606,   607,   160,   161,  1196,  1197,  1113,  1114,
     843,   844,   865,   866,   638,   835,   617,   618,   875,   876,
    1112,   888,   889,   923,   842,   908,   909,   932,   933,   953,
     954,   640,   764,   959,   960,   965,   966,   970,   971,   988,
     989,   994,   995,   636,   158,   159,   606,   607,   160,   161,
     864,   807,  1113,  1114,  1115,  1116,   641,  1030,  1031,   642,
     617,   618,  1107,  1108,   655,  1112,  1138,  1139,   882,  1148,
    1149,   588,   887,  1172,  1173,  1191,  1192,  1215,  1216,   903,
     663,   898,  1243,  1244,  1271,  1272,  1300,  1301,   674,   158,
     159,   606,   607,   160,   161,   907,   675,  1113,  1114,  1322,
    1323,  1153,  1154,   677,   918,   617,   618,  1349,  1350,  1371,
    1372,  1388,  1389,   676,   931,  1403,  1404,  1412,  1413,   681,
      38,   678,   879,   643,   944,  1427,  1428,  1441,  1442,   695,
    1185,  1457,  1458,   701,   958,    39,  1395,    40,    41,    42,
     700,    43,    44,    45,   698,    46,    47,    48,   982,    49,
      50,    51,   702,    52,    53,  1471,  1472,  1492,  1493,   657,
     993,  1505,  1506,   699,    39,  1434,    40,    41,    42,   713,
      43,    44,    45,   726,    46,    47,    48,   722,    49,    50,
      51,   751,    52,    53,  1520,  1521,  1026,  1464,  1538,  1539,
    1550,  1551,  1567,  1568,  1254,  1579,  1580,  1587,  1588,  1598,
    1599,   727,  1387,  1606,  1607,   750,   767,   775,   758,   776,
     778,   753,   782,   836,   797,   839,   813,  1064,   810,   820,
     848,   849,   853,   861,   857,   855,   858,   870,   881,   871,
     883,  1426,   884,   893,   899,   894,   903,   913,   919,   900,
     920,   906,   923,   914,   937,   926,   945,   946,   949,   975,
     999,   983,   938,  1456,  1002,  1006,  1037,  1013,  1016,  1103,
    1027,   977,  1044,  1048,  1057,  1041,  1058,  1007,  1061,  1065,
    1070,  1307,  1137,  1071,  1097,  1104,  1098,  1187,  1049,  1132,
    1076,  1189,  1236,  1021,  1167,  1237,  1210,  1238,  1265,  1248,
    1249,  1186,  1281,  1282,  1266,  1294,  1308,  1283,  1295,  1226,
    1225,  1314,  1330,  1317,  1333,  1336,  1332,  1344,  1284,  1257,
    1337,  1366,  1356,  1255,  1357,  1359,  1378,  1410,  1285,  1448,
    1379,  1398,  1436,  1235,  1466,  1500,  1118,  1487,  1478,  1515,
    1503,  1499,  1527,  1545,  1533,  1560,  1563,  1557,  1574,  1156,
    1547,  1575,  1595,  1586,  1559,  1564,  1576,  1596,  1597,  1616,
    1621,  1594,   124,  1546,  1624,    77,   156,   522,   527,  1605,
    1613,   696,   600,   341,   664,  1625,  1203,  1626,   703,   248,
     628,   795,  1627,   850,  1028,   273,  1077,  1338,  1340,  1066,
     443,  1309,  1311,  1105,  1360,  1362,   984,  1190,   779,   856,
    1208,  1131,   123,  1040,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     209,   529,   152,   372,     4,   602,   697,     8,  1067,     6,
       4,   781,     4,   382,   257,     4,   259,     4,   387,  1078,
     154,  1019,     4,     4,     4,     4,     4,     6,     7,     6,
       7,     4,   902,   724,     4,     4,     4,     4,     6,     7,
       4,     4,    68,    76,     6,     7,     6,  1106,     4,  1047,
       4,     4,   142,     6,     7,    70,     4,   266,   267,   137,
     155,   724,  1060,    77,   125,    79,    80,    72,     0,   666,
     129,   762,   131,    17,   602,  1073,   137,   137,    77,    23,
      79,    80,   197,  1419,  1069,    29,   164,  1172,    71,   204,
      34,    18,  1069,    65,   109,   155,   111,    14,   113,   762,
     115,   191,  1100,   164,   164,   255,   165,   257,   705,   259,
      36,  1096,   246,  1449,    15,   141,    43,    44,   172,  1096,
     179,   147,    67,   218,   129,   151,   131,   153,    10,    11,
    1215,   185,    59,    60,   171,    61,  1134,    63,   666,   165,
     199,    69,   163,   221,   181,   166,   205,     5,   181,   175,
     165,   177,    43,    44,   102,    37,     5,   183,  1243,   125,
     165,   852,   118,    45,    46,     5,    57,    58,   134,   168,
     130,  1169,   186,   126,   179,   201,   140,   705,   132,   163,
     195,   154,   166,   152,   154,   148,  1271,   337,   156,     5,
     399,     5,   561,    74,   199,   176,   174,   566,   178,  1069,
     205,    66,   571,   190,   196,   339,   188,    73,   202,   206,
     167,   200,   421,   170,  1212,  1300,   986,   184,   180,    26,
     101,   198,   222,    68,   433,   434,   435,   436,   163,    82,
     473,   166,   475,    77,   477,    79,    80,  1322,   239,   240,
     241,   242,  1240,   222,    86,   101,    43,    44,    45,    46,
      98,  1310,    21,   781,    90,   109,    94,   111,   139,   113,
     469,   115,    59,    60,  1349,    43,    44,    45,    46,    75,
    1268,    70,    41,    42,    43,    44,    45,    46,    10,    11,
    1339,    12,    13,   139,   165,    77,  1371,    79,    80,     3,
      59,    60,   173,    10,    11,     3,    43,    44,   507,  1297,
      47,    48,  1361,  1388,   163,    37,   187,   166,   189,   165,
      72,   165,    10,    45,    46,  1313,   188,   173,  1403,   191,
      10,  1319,   203,   473,    10,   475,   218,   477,   209,   221,
     211,   187,   213,   189,   215,    10,    11,    10,    11,   141,
      10,   195,  1427,     6,  1342,   147,   154,   203,  1346,   151,
     178,   153,   176,   209,   148,   211,  1441,   213,    10,   215,
      10,    11,   152,   165,   184,  1056,  1364,    10,    11,   202,
    1368,     6,  1457,   175,   524,   177,    10,    11,  1069,   529,
      74,   183,    10,    11,    32,    37,  1471,    37,     3,   986,
      10,    11,   196,    45,    46,    45,    46,    10,    11,   201,
       6,    10,  1400,    37,   142,  1096,   191,  1492,    10,    11,
     166,    45,    46,    41,    42,    43,    44,    10,    11,    47,
      48,    10,    21,   163,   633,   634,   635,   636,    37,    57,
      58,    10,    11,   642,    10,  1520,    45,    46,    10,    11,
    1438,    10,    41,    42,    43,    44,    45,    46,    37,    10,
      11,    10,   602,  1538,   697,    10,    45,    46,   986,  1056,
      10,    11,   206,    31,   132,  1550,   675,   200,   677,   678,
    1468,   130,  1069,   180,   683,    43,    44,    10,    11,    47,
      48,   114,  1567,    10,    11,    43,    44,    10,    11,    10,
      11,  1489,    10,    11,  1579,    10,    11,    10,    11,  1096,
     116,  1029,  1587,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,  1598,    10,    11,   666,   726,   727,  1517,
     112,  1606,    10,    11,    10,    11,    10,    11,  1056,    10,
      11,     6,     7,    10,    11,   220,   221,  1535,   163,  1067,
     110,  1069,   751,    10,    11,    10,    11,   697,    10,    11,
    1078,    10,    11,    16,   166,   705,    19,    76,   767,    10,
      11,    10,    11,    10,    11,   188,   775,   174,  1096,    10,
      11,    10,    11,     6,   724,    10,    11,     6,  1106,     6,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      10,    11,    10,    11,   190,   804,    59,    60,    10,    11,
      19,    10,    11,    22,   813,    10,    11,    10,    11,    10,
      11,   102,   762,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     6,    43,    44,    45,    46,    47,    48,
     839,   781,    51,    52,    53,    54,   140,    10,    11,     6,
      59,    60,    10,    11,     6,    19,    10,    11,   857,    10,
      11,   163,   861,    10,    11,    10,    11,    10,    11,    33,
     166,   870,    10,    11,    10,    11,    10,    11,   192,    43,
      44,    45,    46,    47,    48,   884,     3,    51,    52,    10,
      11,    55,    56,     3,   893,    59,    60,    10,    11,    10,
      11,    10,    11,   164,   903,    10,    11,    10,    11,    10,
      66,    30,   852,   197,   913,    10,    11,    10,    11,   204,
    1079,    10,    11,   210,   923,    81,  1313,    83,    84,    85,
     212,    87,    88,    89,   214,    91,    92,    93,   937,    95,
      96,    97,   166,    99,   100,    10,    11,    10,    11,   163,
     949,    38,    39,   216,    81,  1342,    83,    84,    85,   164,
      87,    88,    89,     3,    91,    92,    93,   187,    95,    96,
      97,     6,    99,   100,    10,    11,   975,  1364,    10,    11,
      10,    11,    10,    11,  1143,    10,    11,    10,    11,    10,
      11,     3,  1310,    10,    11,   164,     6,     3,   153,   164,
     172,   185,   223,   127,   198,    25,    28,  1006,   157,   191,
     154,   188,     5,    24,     6,   186,   169,     6,    78,   217,
     182,  1339,    27,     6,   224,   217,    33,     6,   158,   219,
     121,   192,    22,   133,     6,   121,   128,   121,    16,     6,
     163,   170,   167,  1361,   119,     6,   986,   163,   119,  1048,
     218,   221,   119,     6,   122,   163,   105,   155,    18,   218,
     122,  1220,  1061,   105,   122,   134,   105,     5,   125,   107,
     220,   168,     3,   221,   107,     3,   107,   103,     3,     6,
     117,  1080,   222,     6,   103,     3,   164,    78,   103,   155,
     137,     6,    40,   149,   135,   156,   120,   149,   125,   221,
     164,   149,   120,   137,   222,   164,   120,   106,   137,   106,
     126,   193,   193,  1112,   193,     6,  1056,   207,   106,   207,
      10,   108,   108,   108,   207,     6,   222,   104,   104,  1069,
     138,   126,   136,   104,   118,   138,   138,     6,     6,   194,
     194,   150,    77,   156,   194,    25,    97,   411,   425,   150,
     150,   646,   517,   233,   591,   208,  1096,   208,   660,   141,
     533,   762,   208,   822,   979,   163,  1023,  1259,  1262,  1010,
     316,  1229,  1232,  1052,  1288,  1291,   941,  1090,   755,   830,
    1096,  1056,    55,   986,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    12,    13,   244,   245,   246,     0,    65,   253,   254,
    1015,  1016,    14,   247,    15,   251,   252,    67,   255,   256,
      10,    11,  1017,  1018,  1019,    10,    11,   248,   249,   250,
      69,   335,   336,    10,    11,   257,   258,   259,    66,    81,
      83,    84,    85,    87,    88,    89,    91,    92,    93,    95,
      96,    97,    99,   100,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,   253,    71,   389,
     390,    10,    11,   337,   338,   339,    68,   141,   147,   151,
     153,   165,   175,   177,   183,   201,   260,   261,   262,   263,
     264,   279,   280,   285,   286,   291,   292,   297,   298,   303,
     304,   309,   310,   315,   316,   321,   322,     5,     5,     5,
       5,     5,    66,  1022,   251,    73,   441,   442,    10,    11,
     391,   392,   393,    70,   109,   111,   113,   115,   165,   195,
     340,   341,   342,   343,   344,   349,   350,   356,   357,   363,
     364,   370,   371,   375,   376,    68,   262,    31,    43,    44,
      47,    48,   265,   266,   267,   959,   960,   961,   962,   976,
     977,   978,   979,  1006,    10,    11,   281,   282,   283,    10,
      11,   287,   288,   289,    10,    11,   293,   294,   295,    10,
      11,   299,   300,   301,    10,    11,   305,   306,   307,    10,
      11,   311,   312,   313,    10,    11,   317,   318,   319,    26,
     323,  1001,    82,    86,    90,    94,    98,    75,   536,   537,
      10,    11,   443,   444,   445,    72,   129,   131,   165,   179,
     199,   205,   394,   395,   396,   397,   398,   403,   404,   409,
     410,   415,   416,   421,   422,   427,   428,    70,   342,    10,
      11,   345,   346,   347,   351,   352,   358,   359,   365,   366,
     372,   959,   377,  1001,  1012,  1013,     3,     3,    10,    11,
     268,   269,   270,   267,     4,   154,   284,     4,   178,   290,
       4,   176,   296,     4,   148,   302,     4,   152,   308,     4,
     184,   314,     4,   202,   320,  1012,    10,    11,   324,   325,
     326,   538,   539,    74,   101,   139,   165,   173,   187,   189,
     203,   209,   211,   213,   215,   446,   447,   448,   449,   450,
     455,   456,   461,   462,   467,   468,   473,   474,   479,   480,
     496,   497,   503,   504,   510,   511,   517,   518,   522,   523,
      72,   396,    10,    11,   399,   400,   401,    10,    11,   405,
     406,   407,    10,    11,   411,   412,   413,    10,    11,   417,
     418,   419,    10,    11,   423,   424,   425,   429,  1001,     4,
     196,   348,    10,   354,    57,    58,   353,   959,   980,   981,
     982,   983,    10,   361,   360,   959,   980,    10,   368,   367,
     959,   980,    10,   373,    10,    11,   378,   379,   380,     6,
       8,   239,   240,   241,   242,  1014,  1012,  1012,   142,   191,
     271,   272,   273,   274,   154,   178,   176,   148,   152,   184,
     202,     6,   163,   166,   327,   328,   329,   330,    10,    11,
     541,   542,   543,    17,    23,    29,    34,   540,   993,   998,
    1004,  1009,    74,   448,    10,    11,   451,   452,   453,    10,
      11,   457,   458,   459,    10,    11,   463,   464,   465,    10,
      11,   469,   470,   471,    10,    11,   475,   476,   477,    32,
     481,  1007,   498,   499,   505,   506,   512,   513,   519,   959,
     524,  1001,     4,   132,   402,     6,   130,   408,     6,   206,
     414,     4,   200,   420,     6,     7,   180,   426,  1010,    10,
      11,   430,   431,   432,   196,   355,  1010,     3,   362,  1010,
     369,  1010,     6,   374,   163,   166,   381,   382,   383,   384,
    1012,   142,   273,   275,   276,  1012,   166,   329,   331,   332,
      76,   181,   544,   545,   546,   547,  1012,  1012,  1012,  1012,
       4,   188,   454,     4,   190,   460,     4,   174,   466,     4,
     102,   472,     4,   140,   478,  1012,    10,    11,   482,   483,
     484,    10,   501,   500,   959,   980,    10,   508,   507,   959,
     980,    10,   515,   514,   959,   980,    10,   520,    10,    11,
     525,   526,   527,   132,   130,   206,   200,   180,   163,   166,
     433,   434,   435,   436,   114,  1012,   116,   112,   110,   166,
     383,   385,   386,    10,    11,   278,    45,    46,   277,   959,
     968,   969,   970,   971,    10,    11,   334,    59,    60,   333,
     959,   968,   984,   985,   986,   987,    76,   171,   546,   928,
     929,   548,   549,     6,     6,     6,     6,   188,   190,   174,
     102,   140,     6,   197,   204,   485,   486,   487,   488,   502,
    1010,   509,  1010,   516,  1010,     6,   521,   163,   166,   528,
     529,   530,   531,   166,   435,   437,   438,    10,    11,   388,
     387,   959,   968,   984,   192,     3,   164,     3,    30,   930,
    1005,    10,   554,    36,    61,    63,   550,   551,   552,   553,
    1012,  1012,  1012,  1012,  1012,   204,   487,   489,   214,   216,
     212,   210,   166,   530,   532,   533,    10,    11,   440,   439,
     959,   968,   984,   164,  1012,  1012,  1012,    10,    11,   931,
     932,   933,   187,   555,   556,  1012,     3,     3,    10,    11,
      41,    42,   490,   491,   492,   493,   951,   952,   953,   954,
     959,   976,   980,    10,    11,   535,   534,   959,   968,   984,
     164,     6,   172,   185,   934,   935,   936,   937,   153,   571,
     572,   557,   558,   559,   959,   976,  1006,     6,  1012,  1012,
       6,     7,   198,   494,   495,     3,   164,  1012,   172,   936,
     938,   939,   223,   577,   578,    10,    11,   573,   574,   575,
      10,    11,   560,   561,   562,   559,  1012,   198,  1012,    10,
      11,   941,   942,   943,    21,   940,   951,   959,   968,   996,
     157,   697,   698,    28,   579,  1003,     4,   154,   576,   188,
     191,   563,   564,   565,   566,    77,    79,    80,   186,   944,
     945,   946,   947,   948,   949,  1012,   127,   801,   802,    25,
     699,  1000,  1012,    10,    11,   580,   581,   582,   154,   188,
     565,   567,   568,     5,   950,   186,   946,     6,   169,   905,
     906,    24,   803,   999,  1012,    10,    11,   700,   701,   702,
       6,   217,   583,   584,   585,    10,    11,   570,   569,   959,
     976,    78,  1012,   182,    27,   907,  1002,  1012,    10,    11,
     804,   805,   806,     6,   217,   703,   704,   705,  1012,   224,
     219,   597,   598,    33,   586,  1008,   192,  1012,    10,    11,
     908,   909,   910,     6,   133,   807,   808,   809,  1012,   158,
     121,   717,   718,    22,   706,   997,   121,   613,   614,   599,
    1008,  1012,    10,    11,   587,   588,   589,     6,   167,   170,
     911,   912,   913,   914,  1012,   128,   121,   821,   822,    16,
     810,   992,   772,    10,    11,   719,   720,   721,  1012,    10,
      11,   707,   708,   709,   668,    10,    11,   615,   616,   617,
      10,    11,   600,   601,   602,     6,   218,   221,   590,   591,
     592,   593,  1012,   170,   913,   915,   916,   876,    10,    11,
     823,   824,   825,  1012,    10,    11,   811,   812,   813,   163,
     773,   774,   119,   722,   723,   724,     6,   155,   218,   710,
     711,   712,   713,   163,   669,   670,   119,   618,   619,   620,
     220,   221,   603,   604,   605,   606,  1012,   218,   592,   594,
      10,    11,   918,   919,   920,   917,   951,   959,   968,   984,
     996,   163,   877,   878,   119,   826,   827,   828,     6,   125,
     134,   814,   815,   816,   817,   775,   776,   122,   105,   730,
     731,    18,   725,   994,  1012,   218,   712,   714,   671,   672,
     122,   105,   626,   627,   621,   994,   220,   605,   607,    10,
      37,   595,   596,   967,   968,    77,    79,    80,   168,   921,
     922,   923,   924,   925,   926,   879,   880,   122,   105,   834,
     835,   829,   994,  1012,   134,   816,   818,    10,    11,   778,
     779,   780,    19,    51,    52,    53,    54,   777,   959,   963,
     964,   965,   966,   968,   972,   973,   974,   975,   976,   984,
     995,   997,   107,   737,   738,   732,   994,  1012,    10,    11,
     726,   727,   728,    10,   715,   716,   967,   968,    10,    11,
     674,   675,   676,    55,    56,   673,   959,   963,   968,   976,
     984,   988,   989,   990,   991,   995,  1008,   107,   633,   634,
     628,   994,    10,    11,   622,   623,   624,    10,    11,   608,
     609,   610,   611,   967,   968,  1010,  1012,     5,   927,   168,
     923,    10,    11,   882,   883,   884,    49,    50,   881,   955,
     956,   957,   958,   959,   963,   968,   976,   984,   992,   995,
     107,   841,   842,   836,   994,    10,    11,   830,   831,   832,
      10,   819,   820,   967,   968,   137,   155,   164,   781,   782,
     783,   784,   791,   792,   793,  1012,     3,     3,   103,   744,
     745,   739,   994,    10,    11,   733,   734,   735,     6,   117,
     729,  1043,  1044,  1051,  1010,   137,   164,   221,   677,   678,
     679,   680,   687,   688,   689,     3,   103,   640,   641,   635,
     994,    10,    11,   629,   630,   631,   625,  1043,     4,   222,
     612,   222,     6,    78,   125,   137,   164,   885,   886,   887,
     888,   895,   896,   897,     3,   103,   848,   849,   843,   994,
      10,    11,   837,   838,   839,   833,  1043,  1010,   164,   783,
     785,   792,   794,   795,     6,  1012,  1012,   149,   751,   752,
     746,   994,    10,    11,   740,   741,   742,   736,  1043,  1012,
      40,  1052,   120,   135,  1045,  1046,   156,   164,   679,   681,
     688,   690,   691,  1012,   149,   647,   648,   642,   994,    10,
      11,   636,   637,   638,   632,  1043,   120,   222,  1012,   164,
     887,   889,   896,   898,   899,  1012,   149,   855,   856,   850,
     994,    10,    11,   844,   845,   846,   840,  1043,   120,   126,
      10,    11,   786,   787,   788,   789,   967,   968,    10,    11,
     797,   798,   799,   796,   959,   984,   994,  1012,   193,   758,
     759,   753,   994,    10,    11,   747,   748,   749,   743,  1043,
     106,  1012,    10,    11,  1053,  1054,  1055,  1047,  1048,    10,
      11,   682,   683,   684,   685,   967,   968,    10,    11,   693,
     694,   695,   692,   959,   984,   994,   193,   654,   655,   649,
     994,    10,    11,   643,   644,   645,   639,  1043,   106,    10,
      11,   890,   891,   892,   893,   967,   968,    10,    11,   901,
     902,   903,   900,   959,   984,   994,   193,   862,   863,   857,
     994,    10,    11,   851,   852,   853,   847,  1043,   106,     4,
       6,     7,   156,   790,  1011,   800,  1043,   207,   765,   766,
     760,   994,    10,    11,   754,   755,   756,   750,  1043,   108,
       6,     4,   118,    10,  1050,    38,    39,  1049,  1056,  1057,
     222,   686,  1011,   696,  1043,   207,   661,   662,   656,   994,
      10,    11,   650,   651,   652,   646,  1043,   108,   126,   894,
    1011,   904,  1043,   207,   869,   870,   864,   994,    10,    11,
     858,   859,   860,   854,  1043,   108,   156,   138,   767,   994,
      10,    11,   761,   762,   763,   757,  1043,   104,  1012,   118,
       6,  1012,  1012,   222,   138,   663,   994,    10,    11,   657,
     658,   659,   653,  1043,   104,   126,   138,   871,   994,    10,
      11,   865,   866,   867,   861,  1043,   104,    10,    11,   768,
     769,   770,   764,  1043,   150,   136,     6,     6,    10,    11,
     664,   665,   666,   660,  1043,   150,    10,    11,   872,   873,
     874,   868,  1043,   150,   771,  1043,   194,  1012,  1012,   667,
    1043,   194,   875,  1043,   194,   208,   208,   208
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


