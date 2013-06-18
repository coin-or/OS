
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
     DUMMY = 482
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
#define DUMMY 482




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



void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, const char* errormsg);
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
#define YYLAST   1413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  811
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1195
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1622

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   482

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   229,
     231,     2,     2,   230,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   228,     2,     2,     2,     2,     2,     2,     2,
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
     225,   226,   227
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    31,    38,    39,    42,    44,    46,
      48,    50,    54,    60,    61,    63,    65,    67,    69,    71,
      75,    76,    78,    80,    82,    84,    86,    90,    91,    93,
      95,    97,    99,   101,   105,   106,   108,   110,   112,   114,
     116,   120,   121,   123,   125,   127,   129,   131,   135,   136,
     139,   141,   143,   145,   148,   150,   154,   156,   158,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   183,
     185,   187,   189,   192,   194,   196,   198,   200,   202,   205,
     207,   211,   213,   215,   218,   222,   224,   226,   227,   230,
     232,   234,   237,   239,   242,   244,   246,   248,   251,   253,
     257,   259,   262,   264,   266,   268,   271,   273,   277,   279,
     282,   284,   286,   288,   291,   293,   297,   299,   302,   304,
     306,   308,   311,   313,   317,   319,   322,   324,   326,   328,
     331,   333,   337,   339,   342,   344,   346,   348,   351,   353,
     357,   359,   362,   364,   366,   368,   371,   373,   377,   379,
     383,   385,   387,   389,   391,   394,   396,   400,   402,   404,
     407,   411,   413,   415,   416,   419,   421,   423,   425,   428,
     430,   431,   434,   436,   438,   440,   443,   445,   449,   451,
     453,   456,   458,   460,   462,   464,   466,   468,   471,   473,
     475,   477,   480,   482,   486,   488,   492,   494,   496,   497,
     500,   502,   504,   508,   510,   514,   516,   518,   519,   522,
     524,   526,   530,   532,   536,   538,   540,   541,   544,   546,
     548,   552,   554,   558,   560,   561,   563,   567,   569,   573,
     575,   577,   579,   581,   584,   586,   590,   592,   594,   597,
     601,   603,   605,   606,   609,   611,   613,   615,   618,   620,
     621,   624,   626,   628,   630,   633,   635,   639,   641,   643,
     646,   648,   650,   652,   654,   656,   658,   661,   663,   665,
     667,   670,   672,   676,   678,   681,   683,   685,   687,   690,
     692,   696,   698,   701,   703,   705,   707,   710,   712,   716,
     718,   721,   723,   725,   727,   730,   732,   736,   738,   741,
     743,   745,   747,   750,   752,   756,   758,   762,   764,   766,
     768,   770,   773,   775,   779,   781,   783,   786,   790,   792,
     794,   795,   798,   800,   802,   804,   807,   809,   810,   813,
     815,   817,   819,   822,   824,   828,   830,   832,   835,   837,
     839,   841,   843,   845,   847,   849,   851,   853,   855,   857,
     860,   862,   864,   866,   869,   871,   875,   877,   880,   882,
     884,   886,   889,   891,   895,   897,   900,   902,   904,   906,
     909,   911,   915,   917,   920,   922,   924,   926,   929,   931,
     935,   937,   940,   942,   944,   946,   949,   951,   955,   957,
     961,   963,   965,   967,   969,   972,   974,   978,   980,   982,
     985,   989,   991,   992,   995,   997,   999,  1001,  1003,  1005,
    1007,  1010,  1012,  1016,  1018,  1020,  1022,  1026,  1028,  1030,
    1031,  1034,  1036,  1038,  1042,  1044,  1048,  1050,  1052,  1053,
    1056,  1058,  1060,  1064,  1066,  1070,  1072,  1074,  1075,  1078,
    1080,  1082,  1086,  1088,  1092,  1094,  1095,  1097,  1101,  1103,
    1107,  1109,  1111,  1113,  1115,  1118,  1120,  1124,  1126,  1128,
    1131,  1135,  1137,  1139,  1140,  1143,  1145,  1147,  1149,  1152,
    1154,  1155,  1159,  1161,  1163,  1164,  1167,  1169,  1171,  1173,
    1175,  1177,  1179,  1182,  1184,  1188,  1191,  1193,  1196,  1200,
    1202,  1204,  1205,  1208,  1210,  1212,  1214,  1219,  1223,  1227,
    1236,  1240,  1242,  1244,  1246,  1249,  1251,  1253,  1255,  1257,
    1259,  1262,  1264,  1268,  1270,  1272,  1275,  1279,  1281,  1283,
    1284,  1287,  1289,  1291,  1294,  1296,  1297,  1300,  1302,  1304,
    1306,  1309,  1311,  1315,  1317,  1318,  1322,  1324,  1325,  1327,
    1329,  1331,  1333,  1337,  1342,  1343,  1347,  1349,  1351,  1353,
    1355,  1358,  1360,  1364,  1366,  1368,  1371,  1375,  1377,  1378,
    1381,  1383,  1385,  1389,  1390,  1394,  1396,  1398,  1400,  1402,
    1405,  1407,  1411,  1413,  1415,  1418,  1422,  1424,  1425,  1428,
    1430,  1432,  1434,  1436,  1439,  1441,  1445,  1447,  1448,  1451,
    1453,  1455,  1457,  1459,  1463,  1471,  1472,  1476,  1478,  1480,
    1482,  1484,  1486,  1490,  1492,  1493,  1497,  1499,  1501,  1503,
    1505,  1507,  1511,  1513,  1514,  1518,  1520,  1522,  1524,  1526,
    1528,  1532,  1534,  1535,  1539,  1541,  1543,  1545,  1547,  1549,
    1553,  1555,  1556,  1560,  1562,  1564,  1566,  1568,  1570,  1574,
    1576,  1577,  1581,  1583,  1585,  1587,  1589,  1591,  1595,  1597,
    1598,  1602,  1604,  1606,  1608,  1610,  1612,  1616,  1618,  1619,
    1622,  1626,  1628,  1630,  1631,  1634,  1636,  1638,  1640,  1642,
    1644,  1646,  1648,  1650,  1652,  1654,  1657,  1659,  1663,  1665,
    1667,  1669,  1672,  1676,  1678,  1679,  1682,  1684,  1686,  1688,
    1690,  1693,  1695,  1699,  1701,  1703,  1706,  1710,  1712,  1714,
    1715,  1718,  1720,  1722,  1724,  1726,  1728,  1730,  1734,  1736,
    1737,  1741,  1743,  1744,  1746,  1748,  1750,  1752,  1756,  1760,
    1761,  1765,  1767,  1769,  1771,  1773,  1776,  1778,  1782,  1784,
    1786,  1789,  1793,  1795,  1796,  1799,  1801,  1803,  1807,  1808,
    1811,  1813,  1815,  1817,  1819,  1823,  1831,  1832,  1836,  1838,
    1840,  1842,  1844,  1846,  1850,  1852,  1853,  1857,  1859,  1861,
    1863,  1865,  1867,  1871,  1873,  1874,  1878,  1880,  1882,  1884,
    1886,  1888,  1892,  1894,  1895,  1899,  1901,  1903,  1905,  1907,
    1909,  1913,  1915,  1916,  1920,  1922,  1924,  1926,  1928,  1930,
    1934,  1936,  1937,  1941,  1943,  1945,  1947,  1949,  1951,  1955,
    1957,  1958,  1962,  1964,  1966,  1968,  1970,  1972,  1976,  1978,
    1979,  1982,  1986,  1988,  1990,  1991,  1994,  1996,  1998,  2000,
    2002,  2004,  2006,  2008,  2010,  2012,  2014,  2017,  2019,  2023,
    2025,  2027,  2029,  2032,  2036,  2038,  2039,  2042,  2044,  2046,
    2048,  2050,  2053,  2055,  2059,  2061,  2063,  2066,  2070,  2072,
    2074,  2075,  2078,  2080,  2082,  2084,  2086,  2088,  2090,  2094,
    2096,  2097,  2101,  2103,  2104,  2106,  2108,  2110,  2112,  2116,
    2120,  2121,  2125,  2127,  2129,  2131,  2133,  2136,  2138,  2142,
    2144,  2146,  2149,  2153,  2155,  2156,  2159,  2161,  2163,  2167,
    2168,  2171,  2173,  2175,  2177,  2179,  2183,  2191,  2192,  2196,
    2198,  2200,  2202,  2204,  2206,  2210,  2212,  2213,  2217,  2219,
    2221,  2223,  2225,  2227,  2231,  2233,  2234,  2238,  2240,  2242,
    2244,  2246,  2248,  2252,  2254,  2255,  2259,  2261,  2263,  2265,
    2267,  2269,  2273,  2275,  2276,  2280,  2282,  2284,  2286,  2288,
    2290,  2294,  2296,  2297,  2301,  2303,  2305,  2307,  2309,  2311,
    2315,  2317,  2318,  2322,  2324,  2326,  2328,  2330,  2332,  2336,
    2338,  2339,  2342,  2346,  2348,  2350,  2351,  2354,  2356,  2358,
    2360,  2362,  2364,  2366,  2368,  2370,  2372,  2374,  2377,  2379,
    2383,  2385,  2387,  2389,  2392,  2396,  2398,  2399,  2402,  2404,
    2406,  2408,  2410,  2413,  2415,  2419,  2421,  2423,  2426,  2430,
    2432,  2434,  2435,  2438,  2440,  2442,  2444,  2446,  2448,  2450,
    2454,  2456,  2457,  2461,  2463,  2465,  2467,  2469,  2472,  2474,
    2478,  2480,  2482,  2485,  2489,  2491,  2493,  2494,  2497,  2499,
    2501,  2503,  2505,  2507,  2509,  2511,  2514,  2516,  2520,  2522,
    2524,  2527,  2529,  2531,  2533,  2535,  2537,  2541,  2543,  2544,
    2548,  2550,  2552,  2554,  2556,  2559,  2561,  2565,  2567,  2569,
    2572,  2576,  2578,  2580,  2581,  2584,  2586,  2588,  2590,  2592,
    2594,  2596,  2599,  2601,  2605,  2607,  2609,  2612,  2614,  2616,
    2618,  2620,  2622,  2626,  2628,  2630,  2632,  2634,  2636,  2640,
    2642,  2644,  2646,  2648,  2652,  2654,  2656,  2658,  2660,  2664,
    2666,  2668,  2670,  2672,  2676,  2681,  2683,  2685,  2687,  2689,
    2693,  2695,  2697,  2699,  2701,  2705,  2707,  2709,  2711,  2713,
    2717,  2719,  2721,  2723,  2725,  2729,  2731,  2733,  2735,  2737,
    2741,  2743,  2745,  2747,  2749,  2753,  2758,  2763,  2768,  2773,
    2778,  2783,  2788,  2793,  2798,  2803,  2808,  2813,  2818,  2823,
    2828,  2833,  2838,  2843,  2845,  2847,  2848,  2851,  2855,  2857,
    2859,  2860,  2863,  2865,  2867,  2871,  2875,  2880,  2882,  2884,
    2887,  2889,  2893,  2898,  2903,  2905,  2907,  2909,  2911,  2913,
    2916,  2917,  2920,  2922,  2924,  2926
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     233,     0,    -1,   234,   241,   240,    -1,   235,   236,   237,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   238,    -1,
     239,    -1,    11,    -1,    10,   241,   240,    -1,    15,    -1,
      -1,   242,   268,   348,   402,   454,   549,    -1,    -1,   243,
     244,    -1,    65,    -1,   245,    -1,   246,    -1,    11,    -1,
      10,   247,    66,    -1,   248,   252,   256,   260,   264,    -1,
      -1,   249,    -1,   250,    -1,   251,    -1,    84,    -1,    83,
      -1,    81,     5,    82,    -1,    -1,   253,    -1,   254,    -1,
     255,    -1,    88,    -1,    87,    -1,    85,     5,    86,    -1,
      -1,   257,    -1,   258,    -1,   259,    -1,    92,    -1,    91,
      -1,    89,     5,    90,    -1,    -1,   261,    -1,   262,    -1,
     263,    -1,    96,    -1,    95,    -1,    93,     5,    94,    -1,
      -1,   265,    -1,   266,    -1,   267,    -1,   100,    -1,    99,
      -1,    97,     5,    98,    -1,    -1,   269,   270,    -1,    67,
      -1,   271,    -1,   272,    -1,    10,    68,    -1,    11,    -1,
      10,   273,    68,    -1,   274,    -1,   275,    -1,   274,   275,
      -1,   276,    -1,   292,    -1,   298,    -1,   304,    -1,   310,
      -1,   316,    -1,   322,    -1,   328,    -1,   334,    -1,   277,
     278,   281,    -1,   141,    -1,   279,    -1,   280,    -1,   279,
     280,    -1,   989,    -1,   972,    -1,  1019,    -1,   282,    -1,
     283,    -1,    10,   142,    -1,    11,    -1,    10,   284,   142,
      -1,   285,    -1,   286,    -1,   285,   286,    -1,   287,   288,
     291,    -1,   191,    -1,   289,    -1,    -1,   289,   290,    -1,
     981,    -1,   972,    -1,    10,   192,    -1,    11,    -1,   293,
     294,    -1,   153,    -1,   295,    -1,   296,    -1,    10,   154,
      -1,    11,    -1,    10,   297,   154,    -1,     4,    -1,   299,
     300,    -1,   177,    -1,   301,    -1,   302,    -1,    10,   178,
      -1,    11,    -1,    10,   303,   178,    -1,     4,    -1,   305,
     306,    -1,   175,    -1,   307,    -1,   308,    -1,    10,   176,
      -1,    11,    -1,    10,   309,   176,    -1,     4,    -1,   311,
     312,    -1,   147,    -1,   313,    -1,   314,    -1,    10,   148,
      -1,    11,    -1,    10,   315,   148,    -1,     4,    -1,   317,
     318,    -1,   151,    -1,   319,    -1,   320,    -1,    10,   152,
      -1,    11,    -1,    10,   321,   152,    -1,     4,    -1,   323,
     324,    -1,   183,    -1,   325,    -1,   326,    -1,    10,   184,
      -1,    11,    -1,    10,   327,   184,    -1,     4,    -1,   329,
     330,    -1,   201,    -1,   331,    -1,   332,    -1,    10,   202,
      -1,    11,    -1,    10,   333,   202,    -1,     4,    -1,   335,
     336,   337,    -1,   165,    -1,  1014,    -1,   338,    -1,   339,
      -1,    10,   166,    -1,    11,    -1,    10,   340,   166,    -1,
     341,    -1,   342,    -1,   341,   342,    -1,   343,   344,   347,
      -1,   163,    -1,   345,    -1,    -1,   345,   346,    -1,   981,
      -1,   997,    -1,   972,    -1,    10,   164,    -1,    11,    -1,
      -1,   349,   350,    -1,    69,    -1,   351,    -1,   352,    -1,
      10,    70,    -1,    11,    -1,    10,   353,    70,    -1,   354,
      -1,   355,    -1,   354,   355,    -1,   356,    -1,   362,    -1,
     369,    -1,   376,    -1,   383,    -1,   388,    -1,   357,   358,
      -1,   195,    -1,   359,    -1,   360,    -1,    10,   196,    -1,
      11,    -1,    10,   361,   196,    -1,     4,    -1,   363,   364,
     367,    -1,   113,    -1,   365,    -1,    -1,   365,   366,    -1,
     993,    -1,   972,    -1,    10,   368,   114,    -1,  1038,    -1,
     370,   371,   374,    -1,   115,    -1,   372,    -1,    -1,   372,
     373,    -1,   993,    -1,   972,    -1,    10,   375,   116,    -1,
    1038,    -1,   377,   378,   381,    -1,   111,    -1,   379,    -1,
      -1,   379,   380,    -1,   993,    -1,   972,    -1,    10,   382,
     112,    -1,  1038,    -1,   384,   385,   386,    -1,   109,    -1,
      -1,   972,    -1,    10,   387,   110,    -1,     6,    -1,   389,
     390,   391,    -1,   165,    -1,  1014,    -1,   392,    -1,   393,
      -1,    10,   166,    -1,    11,    -1,    10,   394,   166,    -1,
     395,    -1,   396,    -1,   395,   396,    -1,   397,   398,   401,
      -1,   163,    -1,   399,    -1,    -1,   399,   400,    -1,   981,
      -1,   997,    -1,   972,    -1,    10,   164,    -1,    11,    -1,
      -1,   403,   404,    -1,    71,    -1,   405,    -1,   406,    -1,
      10,    72,    -1,    11,    -1,    10,   407,    72,    -1,   408,
      -1,   409,    -1,   408,   409,    -1,   410,    -1,   416,    -1,
     422,    -1,   428,    -1,   434,    -1,   440,    -1,   411,   412,
      -1,   131,    -1,   413,    -1,   414,    -1,    10,   132,    -1,
      11,    -1,    10,   415,   132,    -1,     4,    -1,   417,   418,
      -1,   129,    -1,   419,    -1,   420,    -1,    10,   130,    -1,
      11,    -1,    10,   421,   130,    -1,     6,    -1,   423,   424,
      -1,   205,    -1,   425,    -1,   426,    -1,    10,   206,    -1,
      11,    -1,    10,   427,   206,    -1,     6,    -1,   429,   430,
      -1,   199,    -1,   431,    -1,   432,    -1,    10,   200,    -1,
      11,    -1,    10,   433,   200,    -1,     4,    -1,   435,   436,
      -1,   179,    -1,   437,    -1,   438,    -1,    10,   180,    -1,
      11,    -1,    10,   439,   180,    -1,  1038,    -1,   441,   442,
     443,    -1,   165,    -1,  1014,    -1,   444,    -1,   445,    -1,
      10,   166,    -1,    11,    -1,    10,   446,   166,    -1,   447,
      -1,   448,    -1,   447,   448,    -1,   449,   450,   453,    -1,
     163,    -1,   451,    -1,    -1,   451,   452,    -1,   981,    -1,
     997,    -1,   972,    -1,    10,   164,    -1,    11,    -1,    -1,
     455,   456,    -1,    73,    -1,   457,    -1,   458,    -1,    10,
      74,    -1,    11,    -1,    10,   459,    74,    -1,   460,    -1,
     461,    -1,   460,   461,    -1,   462,    -1,   468,    -1,   474,
      -1,   480,    -1,   486,    -1,   492,    -1,   509,    -1,   516,
      -1,   523,    -1,   530,    -1,   535,    -1,   463,   464,    -1,
     187,    -1,   465,    -1,   466,    -1,    10,   188,    -1,    11,
      -1,    10,   467,   188,    -1,     4,    -1,   469,   470,    -1,
     189,    -1,   471,    -1,   472,    -1,    10,   190,    -1,    11,
      -1,    10,   473,   190,    -1,     4,    -1,   475,   476,    -1,
     173,    -1,   477,    -1,   478,    -1,    10,   174,    -1,    11,
      -1,    10,   479,   174,    -1,     4,    -1,   481,   482,    -1,
     101,    -1,   483,    -1,   484,    -1,    10,   102,    -1,    11,
      -1,    10,   485,   102,    -1,     4,    -1,   487,   488,    -1,
     139,    -1,   489,    -1,   490,    -1,    10,   140,    -1,    11,
      -1,    10,   491,   140,    -1,     4,    -1,   493,   494,   495,
      -1,   203,    -1,  1020,    -1,   496,    -1,   497,    -1,    10,
     204,    -1,    11,    -1,    10,   498,   204,    -1,   499,    -1,
     500,    -1,   499,   500,    -1,   501,   502,   504,    -1,   197,
      -1,    -1,   502,   503,    -1,   993,    -1,   989,    -1,   964,
      -1,   972,    -1,   505,    -1,   506,    -1,    10,   198,    -1,
      11,    -1,    10,   507,   198,    -1,   508,    -1,     7,    -1,
       6,    -1,   510,   511,   514,    -1,   213,    -1,   512,    -1,
      -1,   512,   513,    -1,   993,    -1,   972,    -1,    10,   515,
     214,    -1,  1038,    -1,   517,   518,   521,    -1,   215,    -1,
     519,    -1,    -1,   519,   520,    -1,   993,    -1,   972,    -1,
      10,   522,   216,    -1,  1038,    -1,   524,   525,   528,    -1,
     211,    -1,   526,    -1,    -1,   526,   527,    -1,   993,    -1,
     972,    -1,    10,   529,   212,    -1,  1038,    -1,   531,   532,
     533,    -1,   209,    -1,    -1,   972,    -1,    10,   534,   210,
      -1,     6,    -1,   536,   537,   538,    -1,   165,    -1,  1014,
      -1,   539,    -1,   540,    -1,    10,   166,    -1,    11,    -1,
      10,   541,   166,    -1,   542,    -1,   543,    -1,   542,   543,
      -1,   544,   545,   548,    -1,   163,    -1,   546,    -1,    -1,
     546,   547,    -1,   981,    -1,   997,    -1,   972,    -1,    10,
     164,    -1,    11,    -1,    -1,   550,   551,   554,    -1,    75,
      -1,   552,    -1,    -1,   552,   553,    -1,  1017,    -1,  1022,
      -1,  1006,    -1,  1011,    -1,   555,    -1,   556,    -1,    10,
      76,    -1,    11,    -1,    10,   557,    76,    -1,   558,   941,
      -1,   559,    -1,   558,   559,    -1,   560,   561,   567,    -1,
     181,    -1,   562,    -1,    -1,   562,   563,    -1,   564,    -1,
     565,    -1,   566,    -1,    36,  1040,     6,  1040,    -1,    63,
       3,  1040,    -1,    61,     3,  1040,    -1,    10,   568,   584,
     590,   710,   814,   918,   182,    -1,   569,   570,   573,    -1,
     187,    -1,   571,    -1,   572,    -1,   571,   572,    -1,   989,
      -1,   972,    -1,  1019,    -1,   574,    -1,   575,    -1,    10,
     188,    -1,    11,    -1,    10,   576,   188,    -1,   577,    -1,
     578,    -1,   577,   578,    -1,   579,   580,   583,    -1,   191,
      -1,   581,    -1,    -1,   581,   582,    -1,   989,    -1,   972,
      -1,    10,   192,    -1,    11,    -1,    -1,   585,   586,    -1,
     153,    -1,   587,    -1,   588,    -1,    10,   154,    -1,    11,
      -1,    10,   589,   154,    -1,     4,    -1,    -1,   591,   592,
     593,    -1,   223,    -1,    -1,  1016,    -1,   594,    -1,   595,
      -1,    11,    -1,    10,   596,   224,    -1,   597,   610,   626,
     681,    -1,    -1,   598,   599,   600,    -1,   217,    -1,  1021,
      -1,   601,    -1,   602,    -1,    10,   218,    -1,    11,    -1,
      10,   603,   218,    -1,   604,    -1,   605,    -1,   604,   605,
      -1,   606,   607,   609,    -1,   221,    -1,    -1,   607,   608,
      -1,   980,    -1,   981,    -1,    10,  1038,   222,    -1,    -1,
     611,   612,   613,    -1,   219,    -1,  1021,    -1,   614,    -1,
     615,    -1,    10,   220,    -1,    11,    -1,    10,   616,   220,
      -1,   617,    -1,   618,    -1,   617,   618,    -1,   619,   620,
     622,    -1,   221,    -1,    -1,   620,   621,    -1,   980,    -1,
     981,    -1,   623,    -1,   624,    -1,    10,   222,    -1,    11,
      -1,    10,   625,   222,    -1,     4,    -1,    -1,   627,   628,
      -1,   121,    -1,   629,    -1,   630,    -1,    11,    -1,    10,
     631,   122,    -1,   632,   639,   646,   653,   660,   667,   674,
      -1,    -1,   633,   634,   635,    -1,   119,    -1,  1007,    -1,
     636,    -1,   637,    -1,    11,    -1,    10,   638,   120,    -1,
    1023,    -1,    -1,   640,   641,   642,    -1,   105,    -1,  1007,
      -1,   643,    -1,   644,    -1,    11,    -1,    10,   645,   106,
      -1,  1023,    -1,    -1,   647,   648,   649,    -1,   107,    -1,
    1007,    -1,   650,    -1,   651,    -1,    11,    -1,    10,   652,
     108,    -1,  1023,    -1,    -1,   654,   655,   656,    -1,   103,
      -1,  1007,    -1,   657,    -1,   658,    -1,    11,    -1,    10,
     659,   104,    -1,  1023,    -1,    -1,   661,   662,   663,    -1,
     149,    -1,  1007,    -1,   664,    -1,   665,    -1,    11,    -1,
      10,   666,   150,    -1,  1023,    -1,    -1,   668,   669,   670,
      -1,   193,    -1,  1007,    -1,   671,    -1,   672,    -1,    11,
      -1,    10,   673,   194,    -1,  1023,    -1,    -1,   675,   676,
     677,    -1,   207,    -1,  1007,    -1,   678,    -1,   679,    -1,
      11,    -1,    10,   680,   208,    -1,  1023,    -1,    -1,   681,
     682,    -1,   683,   684,   687,    -1,   163,    -1,   685,    -1,
      -1,   685,   686,    -1,  1021,    -1,  1008,    -1,   997,    -1,
     981,    -1,   989,    -1,  1001,    -1,   976,    -1,   972,    -1,
     688,    -1,   689,    -1,    10,   164,    -1,    11,    -1,    10,
     690,   164,    -1,   691,    -1,   700,    -1,   692,    -1,   691,
     692,    -1,   693,   694,   696,    -1,   221,    -1,    -1,   694,
     695,    -1,   980,    -1,   981,    -1,   697,    -1,   698,    -1,
      10,   222,    -1,    11,    -1,    10,   699,   222,    -1,  1039,
      -1,   701,    -1,   700,   701,    -1,   702,   703,   706,    -1,
     137,    -1,   704,    -1,    -1,   704,   705,    -1,  1007,    -1,
     997,    -1,   972,    -1,   707,    -1,   708,    -1,    11,    -1,
      10,   709,   138,    -1,  1023,    -1,    -1,   711,   712,   713,
      -1,   157,    -1,    -1,  1013,    -1,   714,    -1,   715,    -1,
      11,    -1,    10,   716,   158,    -1,   717,   730,   785,    -1,
      -1,   718,   719,   720,    -1,   217,    -1,  1010,    -1,   721,
      -1,   722,    -1,    10,   218,    -1,    11,    -1,    10,   723,
     218,    -1,   724,    -1,   725,    -1,   724,   725,    -1,   726,
     727,   729,    -1,   155,    -1,    -1,   727,   728,    -1,   980,
      -1,   981,    -1,    10,  1038,   156,    -1,    -1,   731,   732,
      -1,   121,    -1,   733,    -1,   734,    -1,    11,    -1,    10,
     735,   122,    -1,   736,   743,   750,   757,   764,   771,   778,
      -1,    -1,   737,   738,   739,    -1,   119,    -1,  1007,    -1,
     740,    -1,   741,    -1,    11,    -1,    10,   742,   120,    -1,
    1023,    -1,    -1,   744,   745,   746,    -1,   105,    -1,  1007,
      -1,   747,    -1,   748,    -1,    11,    -1,    10,   749,   106,
      -1,  1023,    -1,    -1,   751,   752,   753,    -1,   107,    -1,
    1007,    -1,   754,    -1,   755,    -1,    11,    -1,    10,   756,
     108,    -1,  1023,    -1,    -1,   758,   759,   760,    -1,   103,
      -1,  1007,    -1,   761,    -1,   762,    -1,    11,    -1,    10,
     763,   104,    -1,  1023,    -1,    -1,   765,   766,   767,    -1,
     149,    -1,  1007,    -1,   768,    -1,   769,    -1,    11,    -1,
      10,   770,   150,    -1,  1023,    -1,    -1,   772,   773,   774,
      -1,   193,    -1,  1007,    -1,   775,    -1,   776,    -1,    11,
      -1,    10,   777,   194,    -1,  1023,    -1,    -1,   779,   780,
     781,    -1,   207,    -1,  1007,    -1,   782,    -1,   783,    -1,
      11,    -1,    10,   784,   208,    -1,  1023,    -1,    -1,   785,
     786,    -1,   787,   788,   791,    -1,   163,    -1,   789,    -1,
      -1,   789,   790,    -1,  1010,    -1,  1008,    -1,   997,    -1,
     981,    -1,   989,    -1,   985,    -1,   976,    -1,   972,    -1,
     792,    -1,   793,    -1,    10,   164,    -1,    11,    -1,    10,
     794,   164,    -1,   795,    -1,   804,    -1,   796,    -1,   795,
     796,    -1,   797,   798,   800,    -1,   155,    -1,    -1,   798,
     799,    -1,   980,    -1,   981,    -1,   801,    -1,   802,    -1,
      10,   156,    -1,    11,    -1,    10,   803,   156,    -1,  1039,
      -1,   805,    -1,   804,   805,    -1,   806,   807,   810,    -1,
     137,    -1,   808,    -1,    -1,   808,   809,    -1,  1007,    -1,
     997,    -1,   972,    -1,   811,    -1,   812,    -1,    11,    -1,
      10,   813,   138,    -1,  1023,    -1,    -1,   815,   816,   817,
      -1,   127,    -1,    -1,  1012,    -1,   818,    -1,   819,    -1,
      11,    -1,    10,   820,   128,    -1,   821,   834,   889,    -1,
      -1,   822,   823,   824,    -1,   133,    -1,  1005,    -1,   825,
      -1,   826,    -1,    10,   134,    -1,    11,    -1,    10,   827,
     134,    -1,   828,    -1,   829,    -1,   828,   829,    -1,   830,
     831,   833,    -1,   125,    -1,    -1,   831,   832,    -1,   980,
      -1,   981,    -1,    10,  1038,   126,    -1,    -1,   835,   836,
      -1,   121,    -1,   837,    -1,   838,    -1,    11,    -1,    10,
     839,   122,    -1,   840,   847,   854,   861,   868,   875,   882,
      -1,    -1,   841,   842,   843,    -1,   119,    -1,  1007,    -1,
     844,    -1,   845,    -1,    11,    -1,    10,   846,   120,    -1,
    1023,    -1,    -1,   848,   849,   850,    -1,   105,    -1,  1007,
      -1,   851,    -1,   852,    -1,    11,    -1,    10,   853,   106,
      -1,  1023,    -1,    -1,   855,   856,   857,    -1,   107,    -1,
    1007,    -1,   858,    -1,   859,    -1,    11,    -1,    10,   860,
     108,    -1,  1023,    -1,    -1,   862,   863,   864,    -1,   103,
      -1,  1007,    -1,   865,    -1,   866,    -1,    11,    -1,    10,
     867,   104,    -1,  1023,    -1,    -1,   869,   870,   871,    -1,
     149,    -1,  1007,    -1,   872,    -1,   873,    -1,    11,    -1,
      10,   874,   150,    -1,  1023,    -1,    -1,   876,   877,   878,
      -1,   193,    -1,  1007,    -1,   879,    -1,   880,    -1,    11,
      -1,    10,   881,   194,    -1,  1023,    -1,    -1,   883,   884,
     885,    -1,   207,    -1,  1007,    -1,   886,    -1,   887,    -1,
      11,    -1,    10,   888,   208,    -1,  1023,    -1,    -1,   889,
     890,    -1,   891,   892,   895,    -1,   163,    -1,   893,    -1,
      -1,   893,   894,    -1,  1005,    -1,  1008,    -1,   997,    -1,
     981,    -1,   989,    -1,   968,    -1,   976,    -1,   972,    -1,
     896,    -1,   897,    -1,    10,   164,    -1,    11,    -1,    10,
     898,   164,    -1,   899,    -1,   908,    -1,   900,    -1,   899,
     900,    -1,   901,   902,   904,    -1,   125,    -1,    -1,   902,
     903,    -1,   980,    -1,   981,    -1,   905,    -1,   906,    -1,
      10,   126,    -1,    11,    -1,    10,   907,   126,    -1,  1039,
      -1,   909,    -1,   908,   909,    -1,   910,   911,   914,    -1,
     137,    -1,   912,    -1,    -1,   912,   913,    -1,  1007,    -1,
     997,    -1,   972,    -1,   915,    -1,   916,    -1,    11,    -1,
      10,   917,   138,    -1,  1023,    -1,    -1,   919,   920,   921,
      -1,   169,    -1,  1015,    -1,   922,    -1,   923,    -1,    10,
     170,    -1,    11,    -1,    10,   924,   170,    -1,   925,    -1,
     926,    -1,   925,   926,    -1,   927,   928,   931,    -1,   167,
      -1,   929,    -1,    -1,   929,   930,    -1,   981,    -1,   997,
      -1,   964,    -1,   972,    -1,  1009,    -1,   932,    -1,   933,
      -1,    10,   168,    -1,    11,    -1,    10,   934,   168,    -1,
     935,    -1,   936,    -1,   935,   936,    -1,   937,    -1,   938,
      -1,   939,    -1,    79,    -1,    80,    -1,    77,   940,    78,
      -1,     5,    -1,    -1,   942,   943,   944,    -1,   171,    -1,
    1018,    -1,   945,    -1,   946,    -1,    10,   172,    -1,    11,
      -1,    10,   947,   172,    -1,   948,    -1,   949,    -1,   948,
     949,    -1,   950,   951,   954,    -1,   185,    -1,   952,    -1,
      -1,   952,   953,    -1,   981,    -1,   964,    -1,   972,    -1,
    1009,    -1,   955,    -1,   956,    -1,    10,   186,    -1,    11,
      -1,    10,   957,   186,    -1,   958,    -1,   959,    -1,   958,
     959,    -1,   960,    -1,   961,    -1,   962,    -1,    79,    -1,
      80,    -1,    77,   963,    78,    -1,     5,    -1,   965,    -1,
     966,    -1,   967,    -1,    42,    -1,    41,     3,  1040,    -1,
     969,    -1,   970,    -1,   971,    -1,    50,    -1,    49,     3,
    1040,    -1,   973,    -1,   974,    -1,   975,    -1,    44,    -1,
      43,     3,  1040,    -1,   977,    -1,   978,    -1,   979,    -1,
      52,    -1,    51,     3,  1040,    -1,    37,  1040,     6,  1040,
      -1,   982,    -1,   983,    -1,   984,    -1,    46,    -1,    45,
       3,  1040,    -1,   986,    -1,   987,    -1,   988,    -1,    54,
      -1,    53,     3,  1040,    -1,   990,    -1,   991,    -1,   992,
      -1,    48,    -1,    47,     3,  1040,    -1,   994,    -1,   995,
      -1,   996,    -1,    58,    -1,    57,     3,  1040,    -1,   998,
      -1,   999,    -1,  1000,    -1,    60,    -1,    59,     3,  1040,
      -1,  1002,    -1,  1003,    -1,  1004,    -1,    56,    -1,    55,
       3,  1040,    -1,    16,  1040,     6,  1040,    -1,    17,  1040,
       6,  1040,    -1,    18,  1040,     6,  1040,    -1,    19,  1040,
       6,  1040,    -1,    21,  1040,     6,  1040,    -1,    22,  1040,
       6,  1040,    -1,    23,  1040,     6,  1040,    -1,    24,  1040,
       6,  1040,    -1,    25,  1040,     6,  1040,    -1,    26,  1040,
       6,  1040,    -1,    27,  1040,     6,  1040,    -1,    28,  1040,
       6,  1040,    -1,    29,  1040,     6,  1040,    -1,    30,  1040,
       6,  1040,    -1,    31,  1040,     6,  1040,    -1,    32,  1040,
       6,  1040,    -1,    33,  1040,     6,  1040,    -1,    34,  1040,
       6,  1040,    -1,  1024,    -1,  1031,    -1,    -1,  1024,  1025,
      -1,  1026,  1027,  1030,    -1,   135,    -1,  1028,    -1,    -1,
    1028,  1029,    -1,  1037,    -1,  1036,    -1,    10,     6,   136,
      -1,   117,  1032,  1033,    -1,    40,  1040,     6,  1040,    -1,
    1034,    -1,  1035,    -1,    10,   118,    -1,    11,    -1,    10,
       4,   118,    -1,    38,  1040,     6,  1040,    -1,    39,  1040,
       6,  1040,    -1,     6,    -1,     7,    -1,     4,    -1,     6,
      -1,     7,    -1,  1041,     8,    -1,    -1,  1041,  1042,    -1,
     228,    -1,   229,    -1,   230,    -1,   231,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   196,   198,   205,   212,   212,   214,   214,
     216,   218,   220,   221,   224,   233,   233,   240,   249,   249,
     251,   253,   255,   257,   257,   259,   259,   261,   261,   263,
     269,   269,   271,   271,   273,   273,   275,   281,   281,   283,
     283,   285,   285,   287,   293,   293,   295,   295,   297,   297,
     299,   305,   305,   307,   307,   309,   309,   311,   322,   322,
     324,   338,   338,   340,   340,   342,   344,   346,   346,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   360,   362,
     377,   384,   384,   387,   392,   396,   405,   409,   414,   414,
     416,   418,   420,   420,   422,   427,   437,   443,   443,   446,
     451,   457,   457,   460,   462,   469,   469,   471,   471,   473,
     475,   478,   480,   487,   487,   489,   489,   491,   493,   498,
     500,   507,   507,   509,   509,   511,   513,   518,   520,   527,
     527,   529,   529,   531,   533,   538,   540,   547,   547,   549,
     549,   551,   553,   558,   560,   567,   567,   569,   569,   571,
     573,   578,   580,   587,   587,   589,   589,   591,   593,   598,
     600,   607,   617,   622,   628,   628,   630,   632,   634,   634,
     636,   641,   653,   659,   659,   662,   669,   674,   681,   681,
     685,   685,   687,   698,   698,   700,   700,   702,   704,   706,
     706,   709,   710,   711,   712,   713,   714,   717,   719,   726,
     726,   728,   728,   730,   732,   739,   741,   752,   754,   754,
     757,   763,   769,   771,   777,   779,   790,   792,   792,   795,
     801,   807,   809,   816,   818,   829,   831,   831,   834,   840,
     846,   848,   855,   857,   866,   867,   873,   875,   881,   883,
     890,   900,   905,   911,   911,   913,   915,   917,   917,   919,
     924,   936,   942,   942,   945,   952,   957,   963,   963,   967,
     967,   969,   980,   980,   982,   982,   984,   986,   988,   988,
     991,   992,   993,   994,   995,   996,   999,  1001,  1008,  1008,
    1010,  1010,  1012,  1014,  1022,  1024,  1031,  1031,  1033,  1033,
    1035,  1037,  1042,  1044,  1051,  1051,  1053,  1053,  1055,  1057,
    1062,  1064,  1071,  1071,  1073,  1073,  1075,  1077,  1082,  1084,
    1091,  1091,  1093,  1093,  1095,  1097,  1104,  1106,  1113,  1123,
    1128,  1134,  1134,  1136,  1138,  1140,  1140,  1142,  1147,  1159,
    1165,  1165,  1168,  1175,  1180,  1187,  1187,  1190,  1190,  1192,
    1208,  1208,  1210,  1210,  1212,  1214,  1216,  1216,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1232,
    1234,  1241,  1241,  1243,  1243,  1245,  1247,  1255,  1257,  1264,
    1264,  1266,  1266,  1268,  1270,  1275,  1277,  1284,  1284,  1286,
    1286,  1288,  1290,  1295,  1297,  1304,  1304,  1306,  1306,  1308,
    1310,  1315,  1317,  1324,  1324,  1326,  1326,  1328,  1330,  1335,
    1337,  1344,  1354,  1359,  1365,  1365,  1367,  1369,  1371,  1371,
    1373,  1375,  1389,  1389,  1392,  1392,  1392,  1392,  1395,  1395,
    1397,  1397,  1399,  1401,  1410,  1411,  1414,  1416,  1427,  1429,
    1429,  1432,  1438,  1444,  1446,  1453,  1455,  1466,  1468,  1468,
    1471,  1477,  1483,  1485,  1492,  1494,  1505,  1507,  1507,  1510,
    1516,  1522,  1524,  1531,  1533,  1543,  1544,  1550,  1552,  1559,
    1561,  1568,  1578,  1583,  1589,  1589,  1591,  1593,  1595,  1595,
    1597,  1602,  1614,  1620,  1620,  1623,  1630,  1635,  1642,  1642,
    1645,  1645,  1647,  1655,  1661,  1661,  1664,  1671,  1677,  1683,
    1691,  1696,  1702,  1702,  1704,  1706,  1708,  1708,  1710,  1712,
    1721,  1723,  1723,  1725,  1725,  1725,  1727,  1737,  1747,  1767,
    1773,  1775,  1785,  1791,  1791,  1794,  1799,  1804,  1814,  1819,
    1825,  1825,  1827,  1829,  1831,  1831,  1833,  1838,  1848,  1854,
    1854,  1857,  1863,  1870,  1870,  1873,  1873,  1875,  1877,  1877,
    1879,  1879,  1881,  1883,  1891,  1891,  1893,  1899,  1899,  1907,
    1907,  1909,  1911,  1913,  1915,  1915,  1917,  1919,  1927,  1932,
    1938,  1938,  1940,  1942,  1944,  1944,  1946,  1957,  1966,  1966,
    1969,  1970,  1973,  1976,  1976,  1978,  1980,  1988,  1993,  1999,
    1999,  2001,  2003,  2005,  2005,  2007,  2018,  2027,  2027,  2030,
    2031,  2035,  2036,  2038,  2038,  2040,  2042,  2047,  2047,  2049,
    2054,  2054,  2056,  2058,  2060,  2062,  2062,  2071,  2073,  2080,
    2080,  2082,  2084,  2086,  2089,  2089,  2099,  2101,  2108,  2108,
    2110,  2112,  2114,  2117,  2117,  2126,  2128,  2135,  2135,  2137,
    2139,  2141,  2144,  2144,  2153,  2155,  2162,  2162,  2164,  2166,
    2168,  2171,  2171,  2180,  2182,  2189,  2189,  2191,  2193,  2195,
    2198,  2198,  2207,  2209,  2216,  2216,  2218,  2220,  2222,  2225,
    2225,  2234,  2236,  2243,  2243,  2245,  2247,  2249,  2252,  2252,
    2254,  2259,  2278,  2284,  2284,  2287,  2298,  2309,  2315,  2321,
    2327,  2333,  2339,  2346,  2346,  2348,  2348,  2350,  2352,  2352,
    2354,  2354,  2356,  2363,  2372,  2372,  2375,  2381,  2388,  2388,
    2390,  2390,  2392,  2394,  2403,  2403,  2405,  2416,  2424,  2430,
    2430,  2433,  2439,  2440,  2444,  2444,  2446,  2448,  2451,  2455,
    2455,  2457,  2465,  2465,  2473,  2473,  2475,  2477,  2479,  2481,
    2481,  2483,  2485,  2493,  2498,  2504,  2504,  2506,  2508,  2511,
    2511,  2513,  2522,  2532,  2532,  2535,  2536,  2539,  2542,  2542,
    2544,  2549,  2549,  2552,  2554,  2556,  2558,  2558,  2567,  2569,
    2576,  2576,  2578,  2580,  2582,  2584,  2584,  2593,  2595,  2602,
    2602,  2604,  2606,  2608,  2611,  2611,  2620,  2622,  2629,  2629,
    2631,  2633,  2635,  2638,  2638,  2647,  2649,  2656,  2656,  2658,
    2660,  2662,  2665,  2665,  2674,  2676,  2683,  2683,  2685,  2687,
    2689,  2692,  2692,  2701,  2703,  2710,  2710,  2712,  2714,  2716,
    2719,  2719,  2728,  2730,  2737,  2737,  2739,  2741,  2743,  2746,
    2746,  2748,  2754,  2773,  2780,  2780,  2783,  2794,  2805,  2811,
    2817,  2823,  2829,  2835,  2844,  2844,  2846,  2846,  2848,  2850,
    2850,  2852,  2852,  2854,  2859,  2869,  2869,  2872,  2877,  2884,
    2884,  2886,  2886,  2888,  2890,  2897,  2897,  2899,  2910,  2918,
    2924,  2924,  2927,  2933,  2934,  2938,  2938,  2940,  2942,  2945,
    2948,  2948,  2950,  2957,  2957,  2965,  2965,  2967,  2969,  2971,
    2973,  2973,  2975,  2978,  2986,  2991,  2997,  2997,  2999,  3001,
    3003,  3003,  3005,  3014,  3023,  3023,  3026,  3027,  3030,  3033,
    3033,  3035,  3040,  3040,  3042,  3044,  3046,  3048,  3048,  3057,
    3059,  3066,  3066,  3068,  3070,  3072,  3074,  3074,  3083,  3085,
    3092,  3092,  3094,  3096,  3098,  3101,  3101,  3110,  3112,  3119,
    3119,  3121,  3123,  3125,  3128,  3128,  3137,  3139,  3146,  3146,
    3148,  3150,  3152,  3155,  3155,  3164,  3166,  3173,  3173,  3175,
    3177,  3179,  3182,  3182,  3191,  3193,  3200,  3200,  3202,  3204,
    3206,  3209,  3209,  3218,  3220,  3227,  3227,  3229,  3231,  3233,
    3236,  3236,  3238,  3244,  3263,  3269,  3269,  3272,  3283,  3294,
    3300,  3306,  3312,  3318,  3324,  3331,  3331,  3333,  3333,  3335,
    3337,  3337,  3339,  3339,  3341,  3348,  3357,  3357,  3361,  3366,
    3374,  3374,  3376,  3376,  3378,  3380,  3387,  3387,  3389,  3400,
    3408,  3414,  3414,  3417,  3423,  3424,  3428,  3428,  3430,  3432,
    3434,  3438,  3438,  3440,  3445,  3454,  3459,  3465,  3465,  3467,
    3469,  3471,  3471,  3473,  3478,  3492,  3500,  3500,  3503,  3509,
    3515,  3521,  3529,  3539,  3544,  3550,  3550,  3552,  3554,  3556,
    3556,  3558,  3564,  3569,  3571,  3571,  3573,  3575,  3587,  3587,
    3589,  3594,  3603,  3608,  3614,  3614,  3616,  3618,  3620,  3620,
    3622,  3627,  3639,  3647,  3647,  3650,  3655,  3661,  3667,  3676,
    3681,  3687,  3687,  3689,  3691,  3693,  3693,  3695,  3701,  3706,
    3708,  3708,  3710,  3712,  3723,  3730,  3730,  3732,  3737,  3742,
    3749,  3749,  3751,  3756,  3761,  3768,  3768,  3770,  3775,  3780,
    3787,  3787,  3789,  3794,  3799,  3807,  3814,  3814,  3816,  3821,
    3826,  3833,  3833,  3835,  3840,  3845,  3852,  3852,  3854,  3859,
    3864,  3871,  3871,  3873,  3878,  3883,  3890,  3890,  3892,  3897,
    3902,  3909,  3909,  3911,  3916,  3922,  3928,  3937,  3943,  3957,
    3966,  3972,  3981,  3987,  3993,  3999,  4005,  4011,  4020,  4026,
    4035,  4040,  4046,  4073,  4078,  4080,  4080,  4082,  4084,  4093,
    4095,  4095,  4097,  4097,  4099,  4107,  4109,  4114,  4114,  4116,
    4116,  4118,  4141,  4149,  4163,  4164,  4168,  4169,  4170,  4172,
    4174,  4174,  4176,  4177,  4178,  4179
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
  "VARIABLESEND", "VARIDXSTART", "VARIDXEND", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlStartEmpty", "osrlStart",
  "osrlAttributes", "osrlContent", "osrlEmpty", "osrlLaden", "osrlEnd",
  "osrlBody", "headerElement", "headerElementStart",
  "headerElementContent", "headerElementEmpty", "headerElementLaden",
  "headerElementBody", "fileName", "fileNameContent", "fileNameEmpty",
  "fileNameLaden", "fileSource", "fileSourceContent", "fileSourceEmpty",
  "fileSourceLaden", "fileDescription", "fileDescriptionContent",
  "fileDescriptionEmpty", "fileDescriptionLaden", "fileCreator",
  "fileCreatorContent", "fileCreatorEmpty", "fileCreatorLaden",
  "fileLicence", "fileLicenceContent", "fileLicenceEmpty",
  "fileLicenceLaden", "generalElement", "generalElementStart",
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
  "numberOfVariablesAttribute", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute",
  "aNumber", "ElementValue", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar", 0
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
     475,   476,   477,   478,   479,   480,   481,   482,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   232,   233,   233,   234,   235,   236,   236,   237,   237,
     238,   239,   240,   240,   241,   242,   242,   243,   244,   244,
     245,   246,   247,   248,   248,   249,   249,   250,   250,   251,
     252,   252,   253,   253,   254,   254,   255,   256,   256,   257,
     257,   258,   258,   259,   260,   260,   261,   261,   262,   262,
     263,   264,   264,   265,   265,   266,   266,   267,   268,   268,
     269,   270,   270,   271,   271,   272,   273,   274,   274,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   276,   277,
     278,   279,   279,   280,   280,   280,   281,   281,   282,   282,
     283,   284,   285,   285,   286,   287,   288,   289,   289,   290,
     290,   291,   291,   292,   293,   294,   294,   295,   295,   296,
     297,   298,   299,   300,   300,   301,   301,   302,   303,   304,
     305,   306,   306,   307,   307,   308,   309,   310,   311,   312,
     312,   313,   313,   314,   315,   316,   317,   318,   318,   319,
     319,   320,   321,   322,   323,   324,   324,   325,   325,   326,
     327,   328,   329,   330,   330,   331,   331,   332,   333,   334,
     335,   336,   337,   337,   338,   338,   339,   340,   341,   341,
     342,   343,   344,   345,   345,   346,   346,   346,   347,   347,
     348,   348,   349,   350,   350,   351,   351,   352,   353,   354,
     354,   355,   355,   355,   355,   355,   355,   356,   357,   358,
     358,   359,   359,   360,   361,   362,   363,   364,   365,   365,
     366,   366,   367,   368,   369,   370,   371,   372,   372,   373,
     373,   374,   375,   376,   377,   378,   379,   379,   380,   380,
     381,   382,   383,   384,   385,   385,   386,   387,   388,   389,
     390,   391,   391,   392,   392,   393,   394,   395,   395,   396,
     397,   398,   399,   399,   400,   400,   400,   401,   401,   402,
     402,   403,   404,   404,   405,   405,   406,   407,   408,   408,
     409,   409,   409,   409,   409,   409,   410,   411,   412,   412,
     413,   413,   414,   415,   416,   417,   418,   418,   419,   419,
     420,   421,   422,   423,   424,   424,   425,   425,   426,   427,
     428,   429,   430,   430,   431,   431,   432,   433,   434,   435,
     436,   436,   437,   437,   438,   439,   440,   441,   442,   443,
     443,   444,   444,   445,   446,   447,   447,   448,   449,   450,
     451,   451,   452,   452,   452,   453,   453,   454,   454,   455,
     456,   456,   457,   457,   458,   459,   460,   460,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   462,
     463,   464,   464,   465,   465,   466,   467,   468,   469,   470,
     470,   471,   471,   472,   473,   474,   475,   476,   476,   477,
     477,   478,   479,   480,   481,   482,   482,   483,   483,   484,
     485,   486,   487,   488,   488,   489,   489,   490,   491,   492,
     493,   494,   495,   495,   496,   496,   497,   498,   499,   499,
     500,   501,   502,   502,   503,   503,   503,   503,   504,   504,
     505,   505,   506,   507,   508,   508,   509,   510,   511,   512,
     512,   513,   513,   514,   515,   516,   517,   518,   519,   519,
     520,   520,   521,   522,   523,   524,   525,   526,   526,   527,
     527,   528,   529,   530,   531,   532,   532,   533,   534,   535,
     536,   537,   538,   538,   539,   539,   540,   541,   542,   542,
     543,   544,   545,   546,   546,   547,   547,   547,   548,   548,
     549,   549,   550,   551,   552,   552,   553,   553,   553,   553,
     554,   554,   555,   555,   556,   557,   558,   558,   559,   560,
     561,   562,   562,   563,   563,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   571,   572,   572,   572,   573,   573,
     574,   574,   575,   576,   577,   577,   578,   579,   580,   581,
     581,   582,   582,   583,   583,   584,   584,   585,   586,   586,
     587,   587,   588,   589,   590,   590,   591,   592,   592,   593,
     593,   594,   595,   596,   597,   597,   598,   599,   600,   600,
     601,   601,   602,   603,   604,   604,   605,   606,   607,   607,
     608,   608,   609,   610,   610,   611,   612,   613,   613,   614,
     614,   615,   616,   617,   617,   618,   619,   620,   620,   621,
     621,   622,   622,   623,   623,   624,   625,   626,   626,   627,
     628,   628,   629,   630,   631,   632,   632,   633,   634,   635,
     635,   636,   637,   638,   639,   639,   640,   641,   642,   642,
     643,   644,   645,   646,   646,   647,   648,   649,   649,   650,
     651,   652,   653,   653,   654,   655,   656,   656,   657,   658,
     659,   660,   660,   661,   662,   663,   663,   664,   665,   666,
     667,   667,   668,   669,   670,   670,   671,   672,   673,   674,
     674,   675,   676,   677,   677,   678,   679,   680,   681,   681,
     682,   683,   684,   685,   685,   686,   686,   686,   686,   686,
     686,   686,   686,   687,   687,   688,   688,   689,   690,   690,
     691,   691,   692,   693,   694,   694,   695,   695,   696,   696,
     697,   697,   698,   699,   700,   700,   701,   702,   703,   704,
     704,   705,   705,   705,   706,   706,   707,   708,   709,   710,
     710,   711,   712,   712,   713,   713,   714,   715,   716,   717,
     717,   718,   719,   720,   720,   721,   721,   722,   723,   724,
     724,   725,   726,   727,   727,   728,   728,   729,   730,   730,
     731,   732,   732,   733,   734,   735,   736,   736,   737,   738,
     739,   739,   740,   741,   742,   743,   743,   744,   745,   746,
     746,   747,   748,   749,   750,   750,   751,   752,   753,   753,
     754,   755,   756,   757,   757,   758,   759,   760,   760,   761,
     762,   763,   764,   764,   765,   766,   767,   767,   768,   769,
     770,   771,   771,   772,   773,   774,   774,   775,   776,   777,
     778,   778,   779,   780,   781,   781,   782,   783,   784,   785,
     785,   786,   787,   788,   789,   789,   790,   790,   790,   790,
     790,   790,   790,   790,   791,   791,   792,   792,   793,   794,
     794,   795,   795,   796,   797,   798,   798,   799,   799,   800,
     800,   801,   801,   802,   803,   804,   804,   805,   806,   807,
     808,   808,   809,   809,   809,   810,   810,   811,   812,   813,
     814,   814,   815,   816,   816,   817,   817,   818,   819,   820,
     821,   821,   822,   823,   824,   824,   825,   825,   826,   827,
     828,   828,   829,   830,   831,   831,   832,   832,   833,   834,
     834,   835,   836,   836,   837,   838,   839,   840,   840,   841,
     842,   843,   843,   844,   845,   846,   847,   847,   848,   849,
     850,   850,   851,   852,   853,   854,   854,   855,   856,   857,
     857,   858,   859,   860,   861,   861,   862,   863,   864,   864,
     865,   866,   867,   868,   868,   869,   870,   871,   871,   872,
     873,   874,   875,   875,   876,   877,   878,   878,   879,   880,
     881,   882,   882,   883,   884,   885,   885,   886,   887,   888,
     889,   889,   890,   891,   892,   893,   893,   894,   894,   894,
     894,   894,   894,   894,   894,   895,   895,   896,   896,   897,
     898,   898,   899,   899,   900,   901,   902,   902,   903,   903,
     904,   904,   905,   905,   906,   907,   908,   908,   909,   910,
     911,   912,   912,   913,   913,   913,   914,   914,   915,   916,
     917,   918,   918,   919,   920,   921,   921,   922,   922,   923,
     924,   925,   925,   926,   927,   928,   929,   929,   930,   930,
     930,   930,   930,   931,   931,   932,   932,   933,   934,   935,
     935,   936,   937,   937,   938,   938,   939,   940,   941,   941,
     942,   943,   944,   944,   945,   945,   946,   947,   948,   948,
     949,   950,   951,   952,   952,   953,   953,   953,   953,   954,
     954,   955,   955,   956,   957,   958,   958,   959,   960,   960,
     961,   961,   962,   963,   964,   965,   965,   966,   967,   968,
     969,   969,   970,   971,   972,   973,   973,   974,   975,   976,
     977,   977,   978,   979,   980,   981,   982,   982,   983,   984,
     985,   986,   986,   987,   988,   989,   990,   990,   991,   992,
     993,   994,   994,   995,   996,   997,   998,   998,   999,  1000,
    1001,  1002,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1023,  1024,  1024,  1025,  1026,  1027,
    1028,  1028,  1029,  1029,  1030,  1031,  1032,  1033,  1033,  1034,
    1034,  1035,  1036,  1037,  1038,  1038,  1039,  1039,  1039,  1040,
    1041,  1041,  1042,  1042,  1042,  1042
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     0,     6,     0,     2,     1,     1,     1,
       1,     3,     5,     0,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     2,
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
       4,     4,     4,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     4,     1,     1,     2,
       1,     3,     4,     4,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    15,     6,     1,    17,    13,    58,
       0,     7,     0,    12,     2,    60,   180,     0,    23,    20,
      16,    18,    19,    15,    10,     3,     8,     9,   182,   259,
       0,     0,    64,    59,    61,    62,     0,    28,    27,     0,
      30,    24,    25,    26,    13,   261,   337,     0,     0,   186,
     181,   183,   184,    63,    79,   128,   136,   104,   160,   120,
     112,   144,   152,     0,    66,    67,    69,     0,    70,     0,
      71,     0,    72,     0,    73,     0,    74,     0,    75,     0,
      76,     0,    77,     0,     0,    21,     0,    35,    34,    37,
      31,    32,    33,    11,   339,   480,     0,     0,   265,   260,
     262,   263,   185,   233,   224,   206,   215,   239,   198,     0,
     188,   189,   191,     0,   192,   208,   193,   217,   194,   226,
     195,   234,   196,     0,    65,    68,  1190,     0,  1107,     0,
    1128,     0,    80,    81,    84,  1104,  1105,  1106,    83,  1125,
    1126,  1127,    85,     0,   108,   103,   105,   106,     0,   116,
     111,   113,   114,     0,   124,   119,   121,   122,     0,   132,
     127,   129,   130,     0,   140,   135,   137,   138,     0,   148,
     143,   145,   146,     0,   156,   151,   153,   154,  1190,     0,
     161,    29,     0,     0,    42,    41,    44,    38,    39,    40,
     482,    14,   484,     0,   343,   338,   340,   341,   264,   285,
     277,   317,   309,   301,   293,     0,   267,   268,   270,     0,
     271,     0,   272,     0,   273,     0,   274,     0,   275,     0,
     187,   190,     0,   202,   197,   199,   200,     0,   207,     0,
     216,     0,   225,     0,   235,     0,   240,     0,     0,  1190,
    1190,     0,    89,    78,    86,    87,    82,   110,   107,     0,
     118,   115,     0,   126,   123,     0,   134,   131,     0,   142,
     139,     0,   150,   147,     0,   158,   155,     0,     0,     0,
     165,   159,   162,   163,    36,     0,     0,    49,    48,    51,
      45,    46,    47,     0,   483,   342,   384,   392,   460,   376,
     360,   368,   400,   454,   445,   427,   436,     0,   345,   346,
     348,     0,   349,     0,   350,     0,   351,     0,   352,     0,
     353,     0,   354,   429,   355,   438,   356,   447,   357,   455,
     358,     0,   266,   269,     0,   281,   276,   278,   279,     0,
     289,   284,   286,   287,     0,   297,   292,   294,   295,     0,
     305,   300,   302,   303,     0,   313,   308,   310,   311,     0,
     318,   204,   201,     0,     0,   205,     0,  1133,   209,   211,
     210,  1130,  1131,  1132,     0,   214,   218,   220,   219,     0,
     223,   227,   229,   228,     0,   232,     0,   244,   238,   241,
     242,  1190,  1189,  1192,  1193,  1194,  1195,  1191,  1108,  1129,
      88,    95,     0,    91,    92,    97,   109,   117,   125,   133,
     141,   149,   157,  1190,   171,   164,     0,   167,   168,   173,
      43,     0,     0,    56,    55,    22,    52,    53,    54,     0,
     493,   481,   490,   491,  1190,  1190,  1190,  1190,   485,   488,
     489,   486,   487,   344,   347,     0,   364,   359,   361,   362,
       0,   372,   367,   369,   370,     0,   380,   375,   377,   378,
       0,   388,   383,   385,   386,     0,   396,   391,   393,   394,
    1190,     0,   401,     0,   428,     0,   437,     0,   446,     0,
     456,     0,   461,   283,   280,     0,   291,   288,     0,   299,
     296,     0,   307,   304,     0,  1184,  1185,   312,     0,   315,
       0,   322,   316,   319,   320,   203,     0,   213,  1190,     0,
     222,     0,   231,   237,     0,   250,   243,     0,   246,   247,
     252,  1159,    90,    93,     0,    96,  1154,   166,   169,     0,
     172,    50,     0,   492,   499,     0,  1058,   496,   501,     0,
       0,     0,     0,   366,   363,     0,   374,   371,     0,   382,
     379,     0,   390,   387,     0,   398,   395,     0,     0,     0,
     405,   399,   402,   403,     0,   426,   430,   432,   431,     0,
     435,   439,   441,   440,     0,   444,   448,   450,   449,     0,
     453,     0,   465,   459,   462,   463,   282,   290,   298,   306,
     314,   328,   321,     0,   324,   325,   330,   212,  1134,   221,
     230,   236,   245,   248,     0,   251,     0,   102,    94,     0,
    1118,    98,   100,    99,  1115,  1116,  1117,     0,   179,   170,
       0,  1138,   174,   177,   175,   176,  1135,  1136,  1137,    57,
     494,  1060,   497,   495,     0,     0,   500,  1190,  1190,  1190,
    1190,   365,   373,   381,   389,   397,  1190,   411,   404,     0,
     407,   408,   412,     0,   434,     0,   443,     0,   452,   458,
       0,   471,   464,     0,   467,   468,   473,   323,   326,     0,
     329,     0,   258,   249,   253,   256,   254,   255,   101,  1190,
     178,  1190,  1190,     0,  1061,     0,   498,  1190,     0,     0,
     502,   503,   504,   505,  1146,  1151,  1157,  1162,  1160,   406,
     409,     0,   433,   442,   451,   457,   466,   469,     0,   472,
       0,   336,   327,   331,   334,   332,   333,   257,  1119,  1139,
       0,     0,  1065,  1059,  1062,  1063,   511,   535,     0,     0,
    1190,  1190,     0,   421,     0,  1097,   413,   410,   418,   419,
     416,  1094,  1095,  1096,   417,   415,   414,     0,   479,   470,
     474,   477,   475,   476,   335,  1190,  1064,  1071,     0,  1067,
    1068,  1073,   537,   544,     0,     0,   512,   513,   516,   515,
     517,  1190,   508,   507,   425,   424,   420,     0,   423,  1190,
     478,  1158,  1066,  1069,     0,  1072,   546,   719,   547,     0,
     541,   536,   538,   539,     0,   521,   510,   518,   519,   514,
     506,   422,  1098,     0,  1082,  1070,  1079,  1080,  1190,  1074,
    1076,  1077,  1075,  1078,   721,   870,   722,  1190,     0,   548,
     543,   540,     0,   520,   527,     0,   523,   524,   529,     0,
    1090,  1091,  1081,     0,  1084,  1085,  1087,  1088,  1089,     0,
     872,  1021,   873,  1190,     0,   723,     0,   554,   551,   545,
     549,   550,   542,   522,   525,     0,   528,  1093,     0,  1083,
    1086,  1190,  1023,     0,     0,  1190,     0,   874,     0,   729,
     726,   720,   724,   725,  1190,   556,     0,   573,     0,     0,
     534,   526,   530,   532,   531,  1092,  1149,   509,  1190,     0,
    1024,     0,   880,   877,   871,   875,   876,  1190,   731,     0,
     748,     0,  1156,   552,   575,   597,     0,  1190,     0,   557,
     533,     0,     0,  1028,  1022,  1025,  1026,  1190,   882,     0,
     899,     0,  1153,   727,   750,   819,     0,  1190,     0,   732,
     599,   668,     0,     0,   576,     0,     0,   561,   555,   558,
     559,  1190,  1034,  1027,     0,  1030,  1031,  1036,  1152,   878,
     901,   970,     0,  1190,     0,   883,   728,   756,   753,   749,
     751,   752,     0,     0,   736,   730,   733,   734,   553,   605,
     602,   598,   600,   601,     0,   580,   574,   577,   578,  1190,
     560,   567,     0,   563,   564,   568,  1155,  1029,  1032,     0,
    1035,   879,   907,   904,   900,   902,   903,     0,     0,   887,
     881,   884,   885,   822,   820,   824,   758,     0,   765,     0,
    1190,   742,   735,     0,   738,   739,   743,   671,   669,   673,
     607,     0,   614,     0,   579,   586,     0,   582,   583,   587,
    1161,   562,   565,     0,     0,  1046,  1033,  1043,  1044,  1037,
    1040,  1041,  1038,  1039,  1042,   973,   971,   975,   909,     0,
     916,     0,  1190,   893,   886,     0,   889,   890,   894,     0,
     823,   754,   767,   774,     0,  1190,     0,   759,  1150,   737,
     740,     0,     0,   672,   603,   616,   623,     0,     0,   608,
     581,   584,     0,     0,  1190,   569,   566,   570,   571,     0,
    1054,  1055,  1045,     0,  1048,  1049,  1051,  1052,  1053,     0,
     974,   905,   918,   925,     0,     0,   910,  1145,   888,   891,
       0,     0,   837,   821,   834,   835,  1190,     0,  1112,     0,
    1123,   825,   833,   832,  1109,  1110,  1111,   829,   831,  1120,
    1121,  1122,   830,   828,   827,   826,   776,   783,     0,     0,
     768,     0,  1165,   762,   757,   760,   761,     0,   744,   741,
     745,   746,     0,   686,   670,   683,   684,     0,  1143,   674,
     682,   681,   678,   679,   677,   680,  1140,  1141,  1142,   676,
     675,   625,   632,     0,     0,   617,  1165,   611,   606,   609,
     610,     0,   594,   588,   585,   591,   592,   589,   590,     0,
       0,  1057,     0,  1047,  1050,     0,   988,   972,   985,   986,
       0,  1102,   976,   982,  1099,  1100,  1101,   984,   983,   980,
     981,   979,   977,   978,   927,   934,     0,     0,   919,  1165,
     913,   908,   911,   912,     0,   895,   892,   896,   897,   858,
     844,   836,     0,   839,   841,   845,   840,   855,   860,     0,
    1190,  1190,   785,   792,     0,     0,   777,  1165,   771,   766,
     769,   770,  1190,     0,     0,   764,  1163,  1164,     0,   707,
     685,   693,     0,   688,   690,   694,   689,   704,   709,  1190,
     634,   641,     0,     0,   626,  1165,   620,   615,   618,   619,
       0,   613,   596,   593,     0,   572,  1190,  1056,   995,  1009,
     987,     0,   990,   992,   996,   991,  1006,  1011,  1190,   936,
     943,     0,     0,   928,  1165,   922,   917,   920,   921,     0,
     915,     0,   838,   842,     0,   856,     0,   859,  1190,  1113,
    1124,   794,   801,     0,     0,   786,  1165,   780,   775,   778,
     779,     0,   773,  1147,  1190,     0,   763,  1168,  1166,  1170,
     747,   687,   691,     0,   705,     0,   708,  1144,   643,   650,
       0,     0,   635,  1165,   629,   624,   627,   628,     0,   622,
     612,   595,  1114,   989,   993,     0,  1007,     0,  1010,  1103,
     945,   952,     0,     0,   937,  1165,   931,   926,   929,   930,
       0,   924,   914,   898,     0,   852,   846,   843,   849,   850,
     847,   848,  1165,   867,   857,   865,   866,   861,   864,   863,
     862,  1148,   803,   810,     0,     0,   795,  1165,   789,   784,
     787,   788,     0,   782,   772,     0,     0,  1180,  1175,  1177,
    1178,     0,  1169,     0,   701,   695,   692,   698,   699,   696,
     697,  1165,   716,   706,   714,   715,   710,   713,   712,   711,
     652,   659,     0,     0,   644,  1165,   638,   633,   636,   637,
       0,   631,   621,     0,  1003,   997,   994,  1000,  1001,   998,
     999,  1165,  1018,  1008,  1016,  1017,  1012,  1015,  1014,  1013,
     954,   961,     0,     0,   946,  1165,   940,   935,   938,   939,
       0,   933,   923,  1186,  1187,  1188,   851,     0,   854,     0,
     869,   812,   755,     0,     0,   804,  1165,   798,   793,   796,
     797,     0,   791,   781,  1190,     0,  1179,     0,  1167,  1190,
    1190,  1171,  1173,  1172,   700,     0,   703,     0,   718,   661,
     604,     0,     0,   653,  1165,   647,   642,   645,   646,     0,
     640,   630,  1002,     0,  1005,     0,  1020,   963,   906,     0,
       0,   955,  1165,   949,   944,   947,   948,     0,   942,   932,
     853,   868,     0,   813,  1165,   807,   802,   805,   806,     0,
     800,   790,  1176,  1181,     0,     0,     0,   702,   717,     0,
     662,  1165,   656,   651,   654,   655,     0,   649,   639,  1004,
    1019,     0,   964,  1165,   958,   953,   956,   957,     0,   951,
     941,  1165,   816,   811,   814,   815,     0,   809,   799,  1174,
    1190,  1190,  1165,   665,   660,   663,   664,     0,   658,   648,
    1165,   967,   962,   965,   966,     0,   960,   950,     0,   818,
     808,  1182,  1183,     0,   667,   657,     0,   969,   959,   817,
     666,   968
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    25,    26,    27,    14,     8,
       9,    10,    20,    21,    22,    39,    40,    41,    42,    43,
      89,    90,    91,    92,   186,   187,   188,   189,   279,   280,
     281,   282,   415,   416,   417,   418,    16,    17,    33,    34,
      35,    63,    64,    65,    66,    67,   131,   132,   133,   243,
     244,   245,   392,   393,   394,   395,   514,   515,   601,   598,
      68,    69,   145,   146,   147,   249,    70,    71,   150,   151,
     152,   252,    72,    73,   155,   156,   157,   255,    74,    75,
     160,   161,   162,   258,    76,    77,   165,   166,   167,   261,
      78,    79,   170,   171,   172,   264,    80,    81,   175,   176,
     177,   267,    82,    83,   179,   271,   272,   273,   406,   407,
     408,   409,   519,   520,   612,   609,    29,    30,    50,    51,
      52,   109,   110,   111,   112,   113,   224,   225,   226,   353,
     114,   115,   227,   228,   358,   355,   496,   116,   117,   229,
     230,   366,   365,   499,   118,   119,   231,   232,   371,   370,
     501,   120,   121,   233,   375,   504,   122,   123,   235,   378,
     379,   380,   507,   508,   509,   510,   594,   595,   664,   663,
      46,    47,    99,   100,   101,   205,   206,   207,   208,   209,
     326,   327,   328,   475,   210,   211,   331,   332,   333,   478,
     212,   213,   336,   337,   338,   481,   214,   215,   341,   342,
     343,   484,   216,   217,   346,   347,   348,   488,   218,   219,
     349,   492,   493,   494,   583,   584,   585,   586,   659,   660,
     703,   702,    95,    96,   195,   196,   197,   297,   298,   299,
     300,   301,   437,   438,   439,   535,   302,   303,   442,   443,
     444,   538,   304,   305,   447,   448,   449,   541,   306,   307,
     452,   453,   454,   544,   308,   309,   457,   458,   459,   547,
     310,   311,   461,   551,   552,   553,   639,   640,   641,   642,
     691,   726,   727,   728,   729,   767,   768,   312,   313,   463,
     464,   556,   555,   643,   314,   315,   465,   466,   561,   560,
     645,   316,   317,   467,   468,   566,   565,   647,   318,   319,
     469,   570,   650,   320,   321,   471,   573,   574,   575,   653,
     654,   655,   656,   698,   699,   740,   739,   191,   192,   283,
     284,   428,   421,   422,   423,   525,   526,   527,   528,   625,
     626,   680,   681,   682,   683,   676,   717,   718,   755,   756,
     757,   786,   787,   788,   815,   816,   817,   818,   845,   846,
     872,   871,   753,   754,   781,   782,   783,   812,   777,   778,
     808,   839,   840,   841,   866,   867,   868,   898,   928,   929,
     930,   972,   973,   974,   975,  1023,  1075,  1076,   895,   896,
     923,   966,   967,   968,  1016,  1017,  1018,  1019,  1072,  1173,
    1174,  1175,  1176,  1274,   921,   922,   961,   962,   963,  1011,
    1012,  1013,  1068,  1168,  1169,  1170,  1270,  1066,  1067,  1164,
    1267,  1268,  1269,  1348,  1162,  1163,  1263,  1345,  1346,  1347,
    1440,  1261,  1262,  1341,  1437,  1438,  1439,  1519,  1339,  1340,
    1433,  1516,  1517,  1518,  1566,  1431,  1432,  1512,  1563,  1564,
    1565,  1597,  1510,  1511,  1559,  1594,  1595,  1596,  1613,   958,
    1008,  1009,  1062,  1063,  1149,  1144,  1145,  1146,  1252,  1253,
    1254,  1255,  1333,  1415,  1416,  1417,  1418,  1505,  1256,  1257,
    1258,  1335,  1336,  1426,  1423,  1424,  1425,  1507,   805,   806,
     834,   861,   862,   863,   889,   890,   891,   918,   955,   956,
     957,  1003,  1004,  1005,  1006,  1061,  1138,  1139,   915,   916,
     949,   950,   951,   997,   998,   999,  1056,  1134,  1135,  1136,
    1244,  1053,  1054,  1129,  1239,  1240,  1241,  1321,  1127,  1128,
    1235,  1318,  1319,  1320,  1402,  1233,  1234,  1314,  1399,  1400,
    1401,  1491,  1312,  1313,  1395,  1488,  1489,  1490,  1549,  1393,
    1394,  1484,  1546,  1547,  1548,  1586,  1482,  1483,  1542,  1583,
    1584,  1585,  1608,   946,   994,   995,  1049,  1050,  1111,  1103,
    1104,  1105,  1222,  1223,  1224,  1225,  1304,  1376,  1377,  1378,
    1379,  1477,  1226,  1227,  1228,  1306,  1307,  1387,  1384,  1385,
    1386,  1479,   831,   832,   856,   884,   885,   886,   909,   910,
     911,   944,   990,   991,   992,  1045,  1046,  1047,  1048,  1100,
    1215,  1216,   941,   942,   984,   985,   986,  1039,  1040,  1041,
    1095,  1211,  1212,  1213,  1299,  1093,  1094,  1207,  1296,  1297,
    1298,  1370,  1205,  1206,  1292,  1367,  1368,  1369,  1470,  1290,
    1291,  1363,  1467,  1468,  1469,  1537,  1361,  1362,  1463,  1534,
    1535,  1536,  1578,  1461,  1462,  1530,  1575,  1576,  1577,  1605,
    1528,  1529,  1571,  1602,  1603,  1604,  1616,   981,  1036,  1037,
    1089,  1090,  1192,  1187,  1188,  1189,  1281,  1282,  1283,  1284,
    1355,  1445,  1446,  1447,  1448,  1523,  1285,  1286,  1287,  1357,
    1358,  1456,  1453,  1454,  1455,  1525,   853,   854,   879,   904,
     905,   906,   934,   935,   936,   937,   979,   980,  1029,  1026,
    1027,  1028,  1083,  1084,  1085,  1086,  1087,  1088,  1182,   623,
     624,   673,   713,   714,   715,   748,   749,   750,   751,   774,
     775,   799,   795,   796,   797,   823,   824,   825,   826,   827,
     828,   848,   730,   731,   732,   733,  1193,  1194,  1195,  1196,
     134,   135,   136,   137,  1113,  1114,  1115,  1116,  1077,   603,
     604,   605,   606,  1118,  1119,  1120,  1121,   138,   139,   140,
     141,   360,   361,   362,   363,   615,   616,   617,   618,  1155,
    1156,  1157,  1158,   945,   429,  1057,  1124,   803,   919,   430,
     857,   835,   180,   880,   809,   431,   674,   142,   462,   899,
     432,  1245,  1246,  1328,  1329,  1411,  1412,  1501,  1498,  1247,
    1325,  1408,  1409,  1410,  1502,  1503,   489,  1478,   237,   238,
     387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1329
static const yytype_int16 yypact[] =
{
     186, -1329, -1329,    73,    37,    84, -1329, -1329,   105,    72,
     317, -1329,   331, -1329, -1329, -1329,    85,   340,   112, -1329,
   -1329, -1329, -1329,    37, -1329, -1329, -1329, -1329, -1329,    87,
     378,   -22, -1329, -1329, -1329, -1329,   167, -1329, -1329,    96,
     286, -1329, -1329, -1329,   105, -1329,   151,   437,   -20, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   174,   118, -1329, -1329,   454, -1329,   464,
   -1329,   467, -1329,   469, -1329,   471, -1329,   476, -1329,   478,
   -1329,   493, -1329,   218,   153, -1329,   249, -1329, -1329,   293,
   -1329, -1329, -1329, -1329, -1329,   185,   495,   -15, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   196,
     -25, -1329, -1329,   497, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   470, -1329,   218, -1329, -1329, -1329,   265, -1329,   273,
   -1329,   512,   454, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,    28, -1329, -1329, -1329, -1329,    41, -1329,
   -1329, -1329, -1329,    25, -1329, -1329, -1329, -1329,    33, -1329,
   -1329, -1329, -1329,    31, -1329, -1329, -1329, -1329,    18, -1329,
   -1329, -1329, -1329,    10, -1329, -1329, -1329, -1329, -1329,   520,
   -1329, -1329,   195,   299, -1329, -1329,   297, -1329, -1329, -1329,
   -1329, -1329, -1329,   166, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,   242,   -57, -1329, -1329,   524,
   -1329,   528, -1329,   534, -1329,   542, -1329,   544, -1329,   218,
   -1329, -1329,    24, -1329, -1329, -1329, -1329,   313,   179,   325,
     179,   327,   179,   333, -1329,   546, -1329,   346,     2, -1329,
   -1329,   -59, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   200,
   -1329, -1329,   189, -1329, -1329,   202, -1329, -1329,   213, -1329,
   -1329,   250, -1329, -1329,   220, -1329, -1329,   223,   414,   -14,
   -1329, -1329, -1329, -1329, -1329,   343,   430, -1329, -1329,   298,
   -1329, -1329, -1329,   549,   107, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   379,   157, -1329,
   -1329,   571, -1329,   574, -1329,   577, -1329,   579, -1329,   582,
   -1329,   423, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   470,
   -1329,   218, -1329, -1329,    44, -1329, -1329, -1329, -1329,    43,
   -1329, -1329, -1329, -1329,     5, -1329, -1329, -1329, -1329,    13,
   -1329, -1329, -1329, -1329,    27, -1329, -1329, -1329, -1329,   584,
   -1329, -1329, -1329,   271,   590, -1329,   458, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,   590, -1329, -1329, -1329, -1329,   590,
   -1329, -1329, -1329, -1329,   484, -1329,     8, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329,   322,   279, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329,   318,   337, -1329, -1329,
   -1329,   416,   507, -1329, -1329, -1329, -1329, -1329, -1329,   -24,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,    21, -1329, -1329, -1329, -1329,
      14, -1329, -1329, -1329, -1329,    34, -1329, -1329, -1329, -1329,
      49, -1329, -1329, -1329, -1329,    40, -1329, -1329, -1329, -1329,
   -1329,   591, -1329,   505,   179,   530,   179,   536,   179,   538,
   -1329,   593, -1329, -1329, -1329,   396, -1329, -1329,   420, -1329,
   -1329,   362, -1329, -1329,   371, -1329, -1329, -1329,   395, -1329,
     121, -1329, -1329, -1329, -1329, -1329,   465, -1329, -1329,   482,
   -1329,   488, -1329, -1329,   509, -1329, -1329,   510,   491, -1329,
   -1329, -1329, -1329, -1329,   595,   183, -1329, -1329, -1329,   597,
     229, -1329,   614, -1329, -1329,   560,   -44, -1329, -1329,   722,
     726,   727,   728, -1329, -1329,   511, -1329, -1329,   545, -1329,
   -1329,   562, -1329, -1329,   616, -1329, -1329,   598,   731,   -10,
   -1329, -1329, -1329, -1329,   590, -1329, -1329, -1329, -1329,   590,
   -1329, -1329, -1329, -1329,   590, -1329, -1329, -1329, -1329,   734,
   -1329,   134, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   575,   580, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,   599,   229,   552, -1329, -1329,   742,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   583, -1329, -1329,
     743, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,   718,   739,    60, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   547,
     553, -1329, -1329,   540, -1329,   539, -1329,   548, -1329, -1329,
     551, -1329, -1329,   586,   594, -1329, -1329, -1329, -1329,   601,
     229,   592, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   603, -1329,   572, -1329, -1329,   755,   759,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   268, -1329, -1329, -1329, -1329, -1329, -1329,   605,   229,
     602, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
     757,   -68, -1329, -1329, -1329, -1329, -1329,   618,   454,   761,
   -1329, -1329,    20, -1329,   765, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   606, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   600,   588,
   -1329, -1329, -1329,   554,   607,   611,   454, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   576, -1329, -1329,
   -1329, -1329, -1329, -1329,   613,   397, -1329,   612,   747,    32,
   -1329, -1329, -1329, -1329,     0, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,    -9, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,   652,   751, -1329,   615, -1329,
   -1329, -1329,   626, -1329, -1329,   596,   587, -1329, -1329,   776,
   -1329, -1329, -1329,   608,   342, -1329, -1329, -1329, -1329,   777,
   -1329,   623,   758, -1329,   617, -1329,   779,   569, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,   620,   209, -1329,   709, -1329,
   -1329, -1329, -1329,   619,   762, -1329,   622, -1329,   787,   578,
   -1329, -1329, -1329, -1329, -1329, -1329,   573,   581,   763,   610,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   624,
   -1329,   792,   666, -1329, -1329, -1329, -1329, -1329, -1329,   645,
     684,   782, -1329, -1329, -1329,   686,   763, -1329,   628, -1329,
   -1329,   800,   136, -1329, -1329, -1329, -1329, -1329, -1329,   680,
     688,   794, -1329, -1329, -1329, -1329,   630, -1329,   632, -1329,
   -1329, -1329,   634,   636, -1329,   805,   111, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,   642,   646, -1329, -1329, -1329, -1329,
   -1329, -1329,   638, -1329,   640, -1329,   654,   695, -1329, -1329,
   -1329, -1329,   809,  -100, -1329, -1329, -1329, -1329,   658,   699,
   -1329, -1329, -1329, -1329,   432, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329,   609,   604, -1329, -1329, -1329, -1329, -1329,   647,
     385,   660,   701, -1329, -1329, -1329, -1329,   810,    22, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   702,   721,   811,
   -1329, -1329, -1329,   621,   673, -1329, -1329, -1329, -1329, -1329,
   -1329,   708,   729,   811, -1329, -1329,   625,   627, -1329, -1329,
   -1329, -1329, -1329,   123,    -2, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   711,
     730,   811, -1329, -1329, -1329,   698,   713, -1329, -1329,   649,
     473, -1329, -1329,   724,   811, -1329,   651, -1329, -1329, -1329,
   -1329,   240,   653,   518, -1329, -1329,   733,   811,   655, -1329,
   -1329, -1329,    89,   590, -1329, -1329, -1329, -1329, -1329,   831,
   -1329, -1329, -1329,   669,   380, -1329, -1329, -1329, -1329,   657,
     364, -1329, -1329,   735,   811,   659, -1329, -1329, -1329, -1329,
     311,   -58, -1329, -1329, -1329, -1329, -1329,   840, -1329,   841,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   744,   811,   661,
   -1329,   843,   736, -1329, -1329, -1329, -1329,   590, -1329, -1329,
   -1329, -1329,   -77, -1329, -1329, -1329, -1329,   847, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329,   748,   811,   664, -1329,   736, -1329, -1329, -1329,
   -1329,    -1, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   633,
     846, -1329,   768, -1329, -1329,   -61, -1329, -1329, -1329, -1329,
     851, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,   753,   811,   668, -1329,   736,
   -1329, -1329, -1329, -1329,   590, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329,   694,   705, -1329, -1329,   725, -1329, -1329,   853,
   -1329, -1329, -1329,   714,   811,   670, -1329,   736, -1329, -1329,
   -1329, -1329, -1329,   817,   746, -1329,   732, -1329,   716, -1329,
   -1329, -1329,   707,   648, -1329, -1329,   737, -1329, -1329, -1329,
   -1329,   719,   811,   672, -1329,   736, -1329, -1329, -1329, -1329,
     750, -1329, -1329, -1329,   656, -1329, -1329, -1329, -1329, -1329,
   -1329,   717,   754, -1329, -1329,   738, -1329, -1329, -1329, -1329,
     740,   811,   674, -1329,   736, -1329, -1329, -1329, -1329,   756,
   -1329,   760, -1329, -1329,   253, -1329,   677,   274, -1329, -1329,
   -1329, -1329,   689,   811,   679, -1329,   736, -1329, -1329, -1329,
   -1329,   767, -1329, -1329, -1329,   681, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   354, -1329,   683,   274, -1329, -1329,   690,
     811,   685, -1329,   736, -1329, -1329, -1329, -1329,   774, -1329,
   -1329, -1329, -1329, -1329, -1329,   426, -1329,   687,   274, -1329,
   -1329,   692,   811,   691, -1329,   736, -1329, -1329, -1329, -1329,
     778, -1329, -1329, -1329,    36, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329,   736, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   696,   811,   693, -1329,   736, -1329, -1329,
   -1329, -1329,   780, -1329, -1329,   881,    47, -1329, -1329, -1329,
   -1329,   880,   667,    17, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   736, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   703,   811,   697, -1329,   736, -1329, -1329, -1329, -1329,
     783, -1329, -1329,    52, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   736, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   723,   811,   700, -1329,   736, -1329, -1329, -1329, -1329,
     784, -1329, -1329, -1329, -1329, -1329, -1329,   741, -1329,   764,
   -1329, -1329, -1329,   811,   704, -1329,   736, -1329, -1329, -1329,
   -1329,   789, -1329, -1329, -1329,   781, -1329,   888, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329,   676, -1329,   766, -1329, -1329,
   -1329,   811,   706, -1329,   736, -1329, -1329, -1329, -1329,   791,
   -1329, -1329, -1329,   775, -1329,   769, -1329, -1329, -1329,   811,
     710, -1329,   736, -1329, -1329, -1329, -1329,   796, -1329, -1329,
   -1329, -1329,   712, -1329,   736, -1329, -1329, -1329, -1329,   770,
   -1329, -1329, -1329, -1329,   772,   899,   900, -1329, -1329,   715,
   -1329,   736, -1329, -1329, -1329, -1329,   771, -1329, -1329, -1329,
   -1329,   720, -1329,   736, -1329, -1329, -1329, -1329,   773, -1329,
   -1329,   736, -1329, -1329, -1329, -1329,   745, -1329, -1329, -1329,
   -1329, -1329,   736, -1329, -1329, -1329, -1329,   749, -1329, -1329,
     736, -1329, -1329, -1329, -1329,   752, -1329, -1329,   785, -1329,
   -1329, -1329, -1329,   786, -1329, -1329,   788, -1329, -1329, -1329,
   -1329, -1329
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   865,   889,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   849, -1329, -1329, -1329, -1329,   790, -1329,
   -1329, -1329, -1329, -1329,   521, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
     504, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   806, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,   407, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   793, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329,   334, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   629,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,   277, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329,   270, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   393, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
     169, -1329, -1329, -1329, -1329, -1329,   110, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   -41, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329,   -88, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
    -320, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,  -322,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,   -69, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,  -287, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,  -289, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,  -108, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,  -342, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,  -344, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,     7, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329,  -139, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   198, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,   124, -1329, -1329,
   -1329, -1329,  -763, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
    -119, -1329, -1329, -1329,  -998, -1329, -1329, -1329, -1053,  -514,
   -1329, -1329, -1329, -1329, -1329, -1329, -1329,  -687, -1329, -1329,
   -1329,  -223, -1329, -1329, -1329,  -594, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329,  -141, -1329, -1000,  -983,   -30,   -99, -1329,
   -1329, -1329,  -107, -1329, -1329, -1329, -1329,  -655, -1329,  -866,
   -1329, -1127, -1329, -1329, -1329, -1329, -1329, -1329, -1329, -1329,
   -1329, -1329, -1329, -1329, -1329, -1329,  -349, -1328,  -178, -1329,
   -1329
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     268,   667,   234,  1272,   735,   497,   614,   368,  1140,   373,
     382,   479,   800,  1069,   265,   500,   236,   482,   536,  1177,
     502,  1473,   262,  1474,  1475,   533,   764,   765,   351,   253,
     924,   759,   247,   485,   486,   259,   810,   256,   539,  1271,
    1473,  1096,  1474,  1475,   545,   250,    53,  1217,   473,   476,
     102,  1495,   523,   542,  1130,  1001,  1473,   198,  1474,  1475,
    1249,   388,   389,   760,  1278,  1151,   706,  1165,   819,   759,
     820,   821,   199,     6,   200,  1079,  1279,  1080,  1081,  1219,
    1159,   666,  1300,   390,   103,  1506,   104,  1250,   105,   103,
     106,   104,  1198,   105,  1208,   106,   677,  1220,    11,  1171,
    1172,   760,     7,  1280,   746,   743,  1221,  1203,   201,   359,
    1322,   367,   350,   372,   199,  1524,   200,   747,  1002,    54,
      13,   678,   202,   679,   424,    55,  1074,   621,  1236,    56,
     425,    57,   391,  1073,   599,   600,   426,   524,  1349,    15,
     107,   427,   203,    58,  1251,   107,   705,  1043,   204,   404,
     201,   543,   405,    59,    28,    60,  1044,   524,    45,   874,
    1074,    61,    85,  1264,   202,  1496,  1082,  1371,   599,   600,
     108,   505,    84,   477,   506,   108,   474,   822,  1522,    62,
     546,   257,   248,   260,   203,   742,   811,   637,   813,  1403,
     204,   814,  1476,    36,   638,    37,    38,  1160,     1,     2,
     470,   254,   263,   511,   537,   644,  1293,   487,   540,   534,
     646,   480,   266,   483,   472,   648,  1441,  1030,   766,   251,
     352,  1273,   127,   128,    94,   516,   127,   128,   599,   600,
     383,   384,   385,   386,  1315,   181,   356,   357,  1471,  1504,
     285,   558,   124,   563,   178,   568,   529,   530,   531,   532,
    1137,  1380,   127,   128,   182,  1480,   129,   130,   286,    54,
     190,   802,  1342,  1374,  1375,    55,   220,   286,   239,    56,
    1492,    57,   127,   128,   599,   600,   240,  1074,   722,   723,
    1419,   274,   548,    58,   581,   599,   600,   582,   610,   611,
    1074,  1364,  1055,    59,  1508,    60,   287,   651,   599,   600,
     652,    61,  1449,   932,   275,   287,   933,  1390,  1520,   724,
     725,   127,   128,  1396,   322,   129,   130,   127,   128,    62,
     588,  1214,   288,   354,  1526,   356,   357,    18,    19,   970,
     289,   288,   971,   610,   611,   364,  1429,   369,  1538,   289,
    1434,    23,    24,   374,   290,   557,   291,   562,  1074,   567,
      31,    32,   381,   290,   396,   291,   599,   600,  1459,  1550,
     292,   399,  1464,  1122,  1413,  1414,   293,   397,   294,   292,
     295,    86,   296,    87,    88,   293,  1153,   294,   398,   295,
     943,   296,   183,  1106,   184,   185,  1033,  1567,    48,    49,
     276,  1074,   277,   278,  1485,   412,   602,   413,   414,   599,
     600,   613,   400,  1200,   401,  1579,   798,   127,   128,   599,
     600,   129,   130,  1190,  1191,  1107,  1108,  1587,   798,   819,
     403,   820,   821,   610,   611,   402,   724,   725,   127,   128,
     599,   600,  1513,   410,  1598,   411,  1443,  1444,   724,   725,
     127,   128,   599,   600,   610,   611,  1606,    97,    98,   684,
     685,   686,   687,   433,  1609,   460,  1123,  1079,   688,  1080,
    1081,   498,  1531,  1074,   512,  1614,  1032,   495,   736,  1154,
     391,   599,   600,  1617,   143,   144,   665,   148,   149,   153,
     154,   158,   159,  1543,   517,   126,   163,   164,   168,   169,
     503,   708,  1106,   709,   710,   917,  1201,   127,   128,   719,
     404,   129,   130,   173,   174,   193,   194,   222,   223,  1078,
     521,  1560,   522,   127,   128,   554,   127,   128,   599,   600,
     129,   130,   241,   242,  1107,  1108,  1109,  1110,   576,  1572,
     269,   270,   610,   611,   324,   325,  1117,  1106,   329,   330,
     559,   704,   762,   763,   334,   335,   564,  1141,   569,  1152,
     577,   897,   339,   340,   344,   345,   376,   377,  1178,   419,
     420,   127,   128,   599,   600,   129,   130,   771,   578,  1107,
    1108,   579,   734,  1147,  1148,   580,  1199,   610,   611,   587,
     741,   435,   436,   790,   440,   441,  1218,   445,   446,   450,
     451,   792,   455,   456,   490,   491,   485,   486,   589,   758,
     590,   549,   550,   571,   572,   596,   597,   607,   608,   661,
     662,   700,   701,   711,   712,   737,   738,   779,   780,   591,
     829,   784,   785,   793,   794,   837,   838,   859,   860,   836,
     869,   870,   882,   883,   902,   903,   620,   758,   926,   927,
     947,   948,   953,   954,   959,   960,   964,   965,   982,   983,
     988,   989,  1014,  1015,   505,   858,   801,  1024,  1025,  1101,
    1102,  1132,  1133,  1142,  1143,  1166,  1167,  1185,  1186,  1209,
    1210,  1237,  1238,   876,  1265,  1266,   592,   881,  1294,  1295,
    1316,  1317,  1343,  1344,  1365,  1366,   892,  1382,  1383,  1397,
    1398,  1406,  1407,  1421,  1422,  1435,  1436,  1451,  1452,   631,
     901,  1465,  1466,  1486,  1487,  1499,  1500,  1514,  1515,   912,
    1532,  1533,   619,  1389,  1544,  1545,  1561,  1562,   634,   925,
    1573,  1574,  1581,  1582,  1179,  1592,  1593,   873,   627,   938,
    1600,  1601,   628,   629,   630,   632,   633,   636,   635,   952,
     649,   657,  1428,   581,   668,   669,   671,   670,   672,   675,
     637,   689,   696,   976,   692,   693,   707,   651,   720,   716,
     694,   695,   721,   745,  1458,   987,   744,   761,   769,   804,
     770,   752,   772,   747,   791,   807,   833,   776,   814,   830,
     842,   847,   855,   851,   843,   864,   865,   875,  1248,   878,
    1381,  1020,   852,   887,   849,   888,   897,   893,   907,   908,
     894,   877,   900,   913,   917,   914,   931,   920,   939,   940,
     943,   969,   977,   932,   996,  1000,  1042,   993,  1010,  1420,
    1038,  1007,  1058,  1035,  1051,   971,  1052,  1021,  1001,  1055,
    1064,  1126,  1098,  1091,  1065,  1092,  1181,  1183,  1043,  1059,
    1161,  1450,  1204,  1230,  1231,  1070,  1277,  1232,  1015,  1242,
    1259,  1260,  1276,  1243,  1288,  1275,  1289,  1324,  1302,  1308,
    1220,  1031,  1219,  1311,  1097,  1301,  1326,  1327,  1338,  1251,
    1350,  1331,  1330,  1404,  1249,  1279,  1372,  1131,  1351,  1278,
    1442,  1353,  1392,  1430,  1472,  1460,  1373,  1494,  1493,  1360,
    1497,  1521,  1539,  1551,  1554,  1568,  1180,  1540,  1557,  1553,
    1580,  1569,  1541,  1481,  1558,  1590,  1591,  1570,  1589,    93,
    1509,   518,    44,   125,   513,   593,   221,   690,   658,   622,
    1588,  1599,   246,  1607,   697,   789,   844,   434,  1229,  1071,
    1527,  1112,  1022,  1332,  1334,  1060,  1303,  1305,  1099,  1610,
    1354,  1356,   978,  1615,  1150,  1184,  1618,   773,   850,  1202,
    1034,  1125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,  1620,     0,  1621,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1309,  1310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1352,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1405,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1457,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1552,     0,     0,     0,
       0,  1555,  1556,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1611,  1612
};

static const yytype_int16 yycheck[] =
{
     178,   595,   121,     4,   691,   354,   520,   230,  1061,   232,
       8,     6,   775,  1013,     4,   364,   123,     4,     4,  1072,
     369,     4,     4,     6,     7,     4,     6,     7,     4,     4,
     896,   718,     4,     6,     7,     4,     4,     4,     4,  1166,
       4,  1041,     6,     7,     4,     4,    68,  1100,     4,     6,
      70,     4,    76,     4,  1054,   155,     4,    72,     6,     7,
     137,   239,   240,   718,   125,  1063,   660,  1067,    77,   756,
      79,    80,   129,     0,   131,    77,   137,    79,    80,   137,
    1063,   595,  1209,   142,   109,  1413,   111,   164,   113,   109,
     115,   111,  1090,   113,  1094,   115,    36,   155,    14,    10,
      11,   756,    65,   164,   172,   699,   164,  1090,   165,   228,
    1237,   230,   219,   232,   129,  1443,   131,   185,   218,   141,
      15,    61,   179,    63,    17,   147,    37,   171,  1128,   151,
      23,   153,   191,    10,    45,    46,    29,   181,  1265,    67,
     165,    34,   199,   165,   221,   165,   660,   125,   205,   163,
     165,   102,   166,   175,    69,   177,   134,   181,    71,   846,
      37,   183,    66,  1163,   179,   118,   168,  1294,    45,    46,
     195,   163,     5,   130,   166,   195,   132,   186,   126,   201,
     140,   148,   154,   152,   199,   699,   154,   197,   188,  1316,
     205,   191,   156,    81,   204,    83,    84,  1063,    12,    13,
     319,   176,   184,   381,   190,   554,  1206,   180,   174,   188,
     559,   206,   202,   200,   321,   564,  1343,   980,   198,   178,
     196,   222,    43,    44,    73,   403,    43,    44,    45,    46,
     228,   229,   230,   231,  1234,    82,    57,    58,  1365,   222,
      74,   464,    68,   466,    26,   468,   424,   425,   426,   427,
      10,  1304,    43,    44,     5,  1382,    47,    48,   101,   141,
      75,   775,  1262,    10,    11,   147,    70,   101,     3,   151,
    1397,   153,    43,    44,    45,    46,     3,    37,    10,    11,
    1333,    86,   460,   165,   163,    45,    46,   166,    59,    60,
      37,  1291,    18,   175,  1421,   177,   139,   163,    45,    46,
     166,   183,  1355,   167,     5,   139,   170,  1307,  1435,    41,
      42,    43,    44,  1313,    72,    47,    48,    43,    44,   201,
     498,    10,   165,    10,  1451,    57,    58,    10,    11,   218,
     173,   165,   221,    59,    60,    10,  1336,    10,  1465,   173,
    1340,    10,    11,    10,   187,   464,   189,   466,    37,   468,
      10,    11,     6,   187,   154,   189,    45,    46,  1358,  1486,
     203,   148,  1362,  1050,    10,    11,   209,   178,   211,   203,
     213,    85,   215,    87,    88,   209,  1063,   211,   176,   213,
      16,   215,    89,    19,    91,    92,   980,  1514,    10,    11,
      93,    37,    95,    96,  1394,    97,   515,    99,   100,    45,
      46,   520,   152,  1090,   184,  1532,    21,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,  1544,    21,    77,
       6,    79,    80,    59,    60,   202,    41,    42,    43,    44,
      45,    46,  1432,    90,  1561,     5,    10,    11,    41,    42,
      43,    44,    45,    46,    59,    60,  1573,    10,    11,   627,
     628,   629,   630,    74,  1581,    32,  1050,    77,   636,    79,
      80,     3,  1462,    37,   142,  1592,   980,   196,   691,  1063,
     191,    45,    46,  1600,    10,    11,   595,    10,    11,    10,
      11,    10,    11,  1483,   166,    31,    10,    11,    10,    11,
       6,   669,    19,   671,   672,    22,  1090,    43,    44,   677,
     163,    47,    48,    10,    11,    10,    11,    10,    11,  1023,
      94,  1511,     5,    43,    44,    10,    43,    44,    45,    46,
      47,    48,    10,    11,    51,    52,    53,    54,   132,  1529,
      10,    11,    59,    60,    10,    11,  1050,    19,    10,    11,
      10,   660,   720,   721,    10,    11,    10,  1061,    10,  1063,
     130,    33,    10,    11,    10,    11,    10,    11,  1072,    10,
      11,    43,    44,    45,    46,    47,    48,   745,   206,    51,
      52,   200,   691,    55,    56,   180,  1090,    59,    60,   114,
     699,    10,    11,   761,    10,    11,  1100,    10,    11,    10,
      11,   769,    10,    11,    10,    11,     6,     7,   116,   718,
     112,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   110,
     798,    10,    11,    10,    11,    10,    11,    10,    11,   807,
      10,    11,    10,    11,    10,    11,    76,   756,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   220,   221,   163,   833,   775,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   851,    10,    11,   166,   855,    10,    11,
      10,    11,    10,    11,    10,    11,   864,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   188,
     878,    10,    11,    10,    11,    38,    39,    10,    11,   887,
      10,    11,    98,  1307,    10,    11,    10,    11,   102,   897,
      10,    11,    10,    11,  1073,    10,    11,   846,     6,   907,
      10,    11,     6,     6,     6,   190,   174,     6,   140,   917,
       6,   166,  1336,   163,   192,     3,     3,   164,    30,    10,
     197,   204,   166,   931,   214,   216,   164,   163,     3,   187,
     212,   210,     3,     6,  1358,   943,   164,     6,     3,   157,
     164,   153,   172,   185,   198,    28,    25,   223,   191,   127,
     154,     5,    24,     6,   188,     6,   217,    78,  1137,    27,
    1304,   969,   169,     6,   186,   217,    33,   224,     6,   133,
     219,   182,   192,   158,    22,   121,     6,   121,   128,   121,
      16,     6,   170,   167,   119,     6,     6,   163,   119,  1333,
     119,   163,  1000,   163,   122,   221,   105,   218,   155,    18,
     122,   107,   134,   122,   105,   105,     5,   168,   125,   218,
     107,  1355,   107,     3,     3,   220,    78,   103,   221,     6,
       3,   103,     6,   117,     3,   222,   103,    40,   164,     6,
     155,   980,   137,   149,  1042,  1214,   120,   135,   149,   221,
     120,   164,   156,   106,   137,   137,   120,  1055,   222,   125,
     106,   164,   193,   193,   106,   193,   126,     6,   108,   149,
      10,   108,   108,   104,     6,   104,  1074,   156,   222,   118,
     104,   126,   138,   207,   138,     6,     6,   138,   136,    44,
     207,   407,    23,    64,   393,   508,   110,   640,   584,   526,
     150,   150,   132,   150,   654,   756,   816,   298,  1106,  1017,
     207,  1050,   973,  1253,  1256,  1004,  1223,  1226,  1046,   194,
    1282,  1285,   935,   194,  1063,  1084,   194,   749,   824,  1090,
     980,  1050,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   208,    -1,   208,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1230,  1231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1307,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1494,    -1,    -1,    -1,
      -1,  1499,  1500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1590,  1591
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   233,   234,   235,     0,    65,   241,   242,
     243,    14,   236,    15,   240,    67,   268,   269,    10,    11,
     244,   245,   246,    10,    11,   237,   238,   239,    69,   348,
     349,    10,    11,   270,   271,   272,    81,    83,    84,   247,
     248,   249,   250,   251,   241,    71,   402,   403,    10,    11,
     350,   351,   352,    68,   141,   147,   151,   153,   165,   175,
     177,   183,   201,   273,   274,   275,   276,   277,   292,   293,
     298,   299,   304,   305,   310,   311,   316,   317,   322,   323,
     328,   329,   334,   335,     5,    66,    85,    87,    88,   252,
     253,   254,   255,   240,    73,   454,   455,    10,    11,   404,
     405,   406,    70,   109,   111,   113,   115,   165,   195,   353,
     354,   355,   356,   357,   362,   363,   369,   370,   376,   377,
     383,   384,   388,   389,    68,   275,    31,    43,    44,    47,
      48,   278,   279,   280,   972,   973,   974,   975,   989,   990,
     991,   992,  1019,    10,    11,   294,   295,   296,    10,    11,
     300,   301,   302,    10,    11,   306,   307,   308,    10,    11,
     312,   313,   314,    10,    11,   318,   319,   320,    10,    11,
     324,   325,   326,    10,    11,   330,   331,   332,    26,   336,
    1014,    82,     5,    89,    91,    92,   256,   257,   258,   259,
      75,   549,   550,    10,    11,   456,   457,   458,    72,   129,
     131,   165,   179,   199,   205,   407,   408,   409,   410,   411,
     416,   417,   422,   423,   428,   429,   434,   435,   440,   441,
      70,   355,    10,    11,   358,   359,   360,   364,   365,   371,
     372,   378,   379,   385,   972,   390,  1014,  1040,  1041,     3,
       3,    10,    11,   281,   282,   283,   280,     4,   154,   297,
       4,   178,   303,     4,   176,   309,     4,   148,   315,     4,
     152,   321,     4,   184,   327,     4,   202,   333,  1040,    10,
      11,   337,   338,   339,    86,     5,    93,    95,    96,   260,
     261,   262,   263,   551,   552,    74,   101,   139,   165,   173,
     187,   189,   203,   209,   211,   213,   215,   459,   460,   461,
     462,   463,   468,   469,   474,   475,   480,   481,   486,   487,
     492,   493,   509,   510,   516,   517,   523,   524,   530,   531,
     535,   536,    72,   409,    10,    11,   412,   413,   414,    10,
      11,   418,   419,   420,    10,    11,   424,   425,   426,    10,
      11,   430,   431,   432,    10,    11,   436,   437,   438,   442,
    1014,     4,   196,   361,    10,   367,    57,    58,   366,   972,
     993,   994,   995,   996,    10,   374,   373,   972,   993,    10,
     381,   380,   972,   993,    10,   386,    10,    11,   391,   392,
     393,     6,     8,   228,   229,   230,   231,  1042,  1040,  1040,
     142,   191,   284,   285,   286,   287,   154,   178,   176,   148,
     152,   184,   202,     6,   163,   166,   340,   341,   342,   343,
      90,     5,    97,    99,   100,   264,   265,   266,   267,    10,
      11,   554,   555,   556,    17,    23,    29,    34,   553,  1006,
    1011,  1017,  1022,    74,   461,    10,    11,   464,   465,   466,
      10,    11,   470,   471,   472,    10,    11,   476,   477,   478,
      10,    11,   482,   483,   484,    10,    11,   488,   489,   490,
      32,   494,  1020,   511,   512,   518,   519,   525,   526,   532,
     972,   537,  1014,     4,   132,   415,     6,   130,   421,     6,
     206,   427,     4,   200,   433,     6,     7,   180,   439,  1038,
      10,    11,   443,   444,   445,   196,   368,  1038,     3,   375,
    1038,   382,  1038,     6,   387,   163,   166,   394,   395,   396,
     397,  1040,   142,   286,   288,   289,  1040,   166,   342,   344,
     345,    94,     5,    76,   181,   557,   558,   559,   560,  1040,
    1040,  1040,  1040,     4,   188,   467,     4,   190,   473,     4,
     174,   479,     4,   102,   485,     4,   140,   491,  1040,    10,
      11,   495,   496,   497,    10,   514,   513,   972,   993,    10,
     521,   520,   972,   993,    10,   528,   527,   972,   993,    10,
     533,    10,    11,   538,   539,   540,   132,   130,   206,   200,
     180,   163,   166,   446,   447,   448,   449,   114,  1040,   116,
     112,   110,   166,   396,   398,   399,    10,    11,   291,    45,
      46,   290,   972,   981,   982,   983,   984,    10,    11,   347,
      59,    60,   346,   972,   981,   997,   998,   999,  1000,    98,
      76,   171,   559,   941,   942,   561,   562,     6,     6,     6,
       6,   188,   190,   174,   102,   140,     6,   197,   204,   498,
     499,   500,   501,   515,  1038,   522,  1038,   529,  1038,     6,
     534,   163,   166,   541,   542,   543,   544,   166,   448,   450,
     451,    10,    11,   401,   400,   972,   981,   997,   192,     3,
     164,     3,    30,   943,  1018,    10,   567,    36,    61,    63,
     563,   564,   565,   566,  1040,  1040,  1040,  1040,  1040,   204,
     500,   502,   214,   216,   212,   210,   166,   543,   545,   546,
      10,    11,   453,   452,   972,   981,   997,   164,  1040,  1040,
    1040,    10,    11,   944,   945,   946,   187,   568,   569,  1040,
       3,     3,    10,    11,    41,    42,   503,   504,   505,   506,
     964,   965,   966,   967,   972,   989,   993,    10,    11,   548,
     547,   972,   981,   997,   164,     6,   172,   185,   947,   948,
     949,   950,   153,   584,   585,   570,   571,   572,   972,   989,
    1019,     6,  1040,  1040,     6,     7,   198,   507,   508,     3,
     164,  1040,   172,   949,   951,   952,   223,   590,   591,    10,
      11,   586,   587,   588,    10,    11,   573,   574,   575,   572,
    1040,   198,  1040,    10,    11,   954,   955,   956,    21,   953,
     964,   972,   981,  1009,   157,   710,   711,    28,   592,  1016,
       4,   154,   589,   188,   191,   576,   577,   578,   579,    77,
      79,    80,   186,   957,   958,   959,   960,   961,   962,  1040,
     127,   814,   815,    25,   712,  1013,  1040,    10,    11,   593,
     594,   595,   154,   188,   578,   580,   581,     5,   963,   186,
     959,     6,   169,   918,   919,    24,   816,  1012,  1040,    10,
      11,   713,   714,   715,     6,   217,   596,   597,   598,    10,
      11,   583,   582,   972,   989,    78,  1040,   182,    27,   920,
    1015,  1040,    10,    11,   817,   818,   819,     6,   217,   716,
     717,   718,  1040,   224,   219,   610,   611,    33,   599,  1021,
     192,  1040,    10,    11,   921,   922,   923,     6,   133,   820,
     821,   822,  1040,   158,   121,   730,   731,    22,   719,  1010,
     121,   626,   627,   612,  1021,  1040,    10,    11,   600,   601,
     602,     6,   167,   170,   924,   925,   926,   927,  1040,   128,
     121,   834,   835,    16,   823,  1005,   785,    10,    11,   732,
     733,   734,  1040,    10,    11,   720,   721,   722,   681,    10,
      11,   628,   629,   630,    10,    11,   613,   614,   615,     6,
     218,   221,   603,   604,   605,   606,  1040,   170,   926,   928,
     929,   889,    10,    11,   836,   837,   838,  1040,    10,    11,
     824,   825,   826,   163,   786,   787,   119,   735,   736,   737,
       6,   155,   218,   723,   724,   725,   726,   163,   682,   683,
     119,   631,   632,   633,   220,   221,   616,   617,   618,   619,
    1040,   218,   605,   607,    10,    11,   931,   932,   933,   930,
     964,   972,   981,   997,  1009,   163,   890,   891,   119,   839,
     840,   841,     6,   125,   134,   827,   828,   829,   830,   788,
     789,   122,   105,   743,   744,    18,   738,  1007,  1040,   218,
     725,   727,   684,   685,   122,   105,   639,   640,   634,  1007,
     220,   618,   620,    10,    37,   608,   609,   980,   981,    77,
      79,    80,   168,   934,   935,   936,   937,   938,   939,   892,
     893,   122,   105,   847,   848,   842,  1007,  1040,   134,   829,
     831,    10,    11,   791,   792,   793,    19,    51,    52,    53,
      54,   790,   972,   976,   977,   978,   979,   981,   985,   986,
     987,   988,   989,   997,  1008,  1010,   107,   750,   751,   745,
    1007,  1040,    10,    11,   739,   740,   741,    10,   728,   729,
     980,   981,    10,    11,   687,   688,   689,    55,    56,   686,
     972,   976,   981,   989,   997,  1001,  1002,  1003,  1004,  1008,
    1021,   107,   646,   647,   641,  1007,    10,    11,   635,   636,
     637,    10,    11,   621,   622,   623,   624,   980,   981,  1038,
    1040,     5,   940,   168,   936,    10,    11,   895,   896,   897,
      49,    50,   894,   968,   969,   970,   971,   972,   976,   981,
     989,   997,  1005,  1008,   107,   854,   855,   849,  1007,    10,
      11,   843,   844,   845,    10,   832,   833,   980,   981,   137,
     155,   164,   794,   795,   796,   797,   804,   805,   806,  1040,
       3,     3,   103,   757,   758,   752,  1007,    10,    11,   746,
     747,   748,     6,   117,   742,  1023,  1024,  1031,  1038,   137,
     164,   221,   690,   691,   692,   693,   700,   701,   702,     3,
     103,   653,   654,   648,  1007,    10,    11,   642,   643,   644,
     638,  1023,     4,   222,   625,   222,     6,    78,   125,   137,
     164,   898,   899,   900,   901,   908,   909,   910,     3,   103,
     861,   862,   856,  1007,    10,    11,   850,   851,   852,   846,
    1023,  1038,   164,   796,   798,   805,   807,   808,     6,  1040,
    1040,   149,   764,   765,   759,  1007,    10,    11,   753,   754,
     755,   749,  1023,  1040,    40,  1032,   120,   135,  1025,  1026,
     156,   164,   692,   694,   701,   703,   704,  1040,   149,   660,
     661,   655,  1007,    10,    11,   649,   650,   651,   645,  1023,
     120,   222,  1040,   164,   900,   902,   909,   911,   912,  1040,
     149,   868,   869,   863,  1007,    10,    11,   857,   858,   859,
     853,  1023,   120,   126,    10,    11,   799,   800,   801,   802,
     980,   981,    10,    11,   810,   811,   812,   809,   972,   997,
    1007,  1040,   193,   771,   772,   766,  1007,    10,    11,   760,
     761,   762,   756,  1023,   106,  1040,    10,    11,  1033,  1034,
    1035,  1027,  1028,    10,    11,   695,   696,   697,   698,   980,
     981,    10,    11,   706,   707,   708,   705,   972,   997,  1007,
     193,   667,   668,   662,  1007,    10,    11,   656,   657,   658,
     652,  1023,   106,    10,    11,   903,   904,   905,   906,   980,
     981,    10,    11,   914,   915,   916,   913,   972,   997,  1007,
     193,   875,   876,   870,  1007,    10,    11,   864,   865,   866,
     860,  1023,   106,     4,     6,     7,   156,   803,  1039,   813,
    1023,   207,   778,   779,   773,  1007,    10,    11,   767,   768,
     769,   763,  1023,   108,     6,     4,   118,    10,  1030,    38,
      39,  1029,  1036,  1037,   222,   699,  1039,   709,  1023,   207,
     674,   675,   669,  1007,    10,    11,   663,   664,   665,   659,
    1023,   108,   126,   907,  1039,   917,  1023,   207,   882,   883,
     877,  1007,    10,    11,   871,   872,   873,   867,  1023,   108,
     156,   138,   780,  1007,    10,    11,   774,   775,   776,   770,
    1023,   104,  1040,   118,     6,  1040,  1040,   222,   138,   676,
    1007,    10,    11,   670,   671,   672,   666,  1023,   104,   126,
     138,   884,  1007,    10,    11,   878,   879,   880,   874,  1023,
     104,    10,    11,   781,   782,   783,   777,  1023,   150,   136,
       6,     6,    10,    11,   677,   678,   679,   673,  1023,   150,
      10,    11,   885,   886,   887,   881,  1023,   150,   784,  1023,
     194,  1040,  1040,   680,  1023,   194,   888,  1023,   194,   208,
     208,   208
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
}
    break;

  case 13:

    {	osrlerror( NULL, osresult, parserData, osglData, "unexpected end of file, expecting </osrl>");}
    break;

  case 16:

    {
	if (!osresult->setResultHeader(osglData->fileName, osglData->source, 	
			osglData->description, osglData->fileCreator, osglData->licence) )	
		osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
}
    break;

  case 17:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
}
    break;

  case 29:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 36:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 43:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 50:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 57:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 60:

    {
	parserData->generalStatusPresent = false;	
	parserData->generalMessagePresent = false;
	parserData->generalServiceURIPresent = false;
	parserData->generalServiceNamePresent = false;
	parserData->generalInstanceNamePresent = false;
	parserData->generalJobIDPresent = false;
	parserData->generalSolverInvokedPresent = false;
	parserData->generalTimeStampPresent = false;
	parserData->otherGeneralResultsPresent = false;
	osresult->general = new GeneralResult();
}
    break;

  case 79:

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

  case 80:

    {
		if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	}
    break;

  case 83:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	}
    break;

  case 84:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
    break;

  case 85:

    {
	   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 86:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
    break;

  case 87:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	}
    break;

  case 94:

    {
	parserData->kounter++;
}
    break;

  case 95:

    {
	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 96:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
}
    break;

  case 99:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	}
    break;

  case 100:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	}
    break;

  case 104:

    {
		if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	}
    break;

  case 110:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 112:

    {
		if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	}
    break;

  case 118:

    {
		osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 120:

    {
		if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	}
    break;

  case 126:

    {
		osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 128:

    {
		if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	}
    break;

  case 134:

    {
		osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 136:

    {
		if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	}
    break;

  case 142:

    {
		osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 144:

    {
		if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	}
    break;

  case 150:

    {
		osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 152:

    {
		if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	}
    break;

  case 158:

    {
		osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 160:

    {
		if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	}
    break;

  case 161:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 162:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 163:

    {
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 170:

    {
	parserData->kounter++;
}
    break;

  case 171:

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

  case 172:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 175:

    {
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	}
    break;

  case 176:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	}
    break;

  case 177:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	}
    break;

  case 182:

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

  case 198:

    {
		if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	}
    break;

  case 204:

    {
		osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 206:

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

  case 210:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 211:

    {
		osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 213:

    {
	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 215:

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

  case 219:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 220:

    {
		osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 222:

    {
	osresult->setAvailableMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 224:

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

  case 228:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 229:

    {
		osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 231:

    {
	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 233:

    {
		if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 235:

    {
		osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 237:

    {
	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;
}
    break;

  case 239:

    {
		if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	}
    break;

  case 240:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 241:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 242:

    {
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 249:

    {
	parserData->kounter++;
}
    break;

  case 250:

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

  case 251:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 254:

    {
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	}
    break;

  case 255:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	}
    break;

  case 256:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	}
    break;

  case 261:

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

  case 277:

    {
		if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	}
    break;

  case 283:

    {
	   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 285:

    {
		if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	}
    break;

  case 291:

    {
		osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL;
	}
    break;

  case 293:

    {
		if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	}
    break;

  case 299:

    {
		osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; 
	}
    break;

  case 301:

    {
		if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	}
    break;

  case 307:

    {
		osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 309:

    {
		if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	}
    break;

  case 315:

    {
	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
}
    break;

  case 317:

    {
		if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	}
    break;

  case 318:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 319:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 320:

    {
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 327:

    {
	parserData->kounter++;
}
    break;

  case 328:

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

  case 329:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 332:

    {
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	}
    break;

  case 333:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	}
    break;

  case 334:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	}
    break;

  case 339:

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

  case 360:

    {
		if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	}
    break;

  case 366:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	}
    break;

  case 368:

    {
		if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	}
    break;

  case 374:

    {
		osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 376:

    {
		if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	}
    break;

  case 382:

    {
		osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
	}
    break;

  case 384:

    {
		if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	}
    break;

  case 390:

    {
		osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
	}
    break;

  case 392:

    {
		if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	}
    break;

  case 398:

    {
		osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
	}
    break;

  case 400:

    {
		if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	}
    break;

  case 401:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
}
    break;

  case 402:

    {
		if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	}
    break;

  case 403:

    {
		if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	}
    break;

  case 411:

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

  case 423:

    {	
	if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
			osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
	parserData->ivar++;
}
    break;

  case 424:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 425:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 427:

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

  case 431:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 432:

    {
		osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 434:

    {
	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 436:

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

  case 440:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 441:

    {
		osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 443:

    {
	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 445:

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

  case 449:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 450:

    {
		osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 452:

    {
	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 454:

    {
		if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 456:

    {
		osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 458:

    { 
	osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; 
}
    break;

  case 460:

    {
		if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	}
    break;

  case 461:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 462:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 463:

    {
		if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 470:

    {
	parserData->kounter++;
}
    break;

  case 471:

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

  case 472:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 475:

    {
		if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	}
    break;

  case 476:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	}
    break;

  case 477:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	}
    break;

  case 482:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
}
    break;

  case 483:

    {
	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
}
    break;

  case 486:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	}
    break;

  case 487:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	}
    break;

  case 488:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	}
    break;

  case 489:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	}
    break;

  case 490:

    {
		if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	}
    break;

  case 491:

    {
		if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	}
    break;

  case 499:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
}
    break;

  case 506:

    {
	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 507:

    {
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
	parserData->nameAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
  	if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 508:

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

  case 509:

    {
		parserData->solutionIdx++;
	}
    break;

  case 511:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	}
    break;

  case 512:

    {
		if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	}
    break;

  case 515:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	}
    break;

  case 516:

    {
	   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	}
    break;

  case 517:

    {
		if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 518:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
    break;

  case 519:

    {
		if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	}
    break;

  case 526:

    {
	parserData->kounter++; 
}
    break;

  case 527:

    {
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 528:

    {
	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
}
    break;

  case 531:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	}
    break;

  case 532:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	}
    break;

  case 543:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	}
    break;

  case 546:

    {
	parserData->numberOfOtherVariableResults = 0;
	osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 548:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
}
    break;

  case 557:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
}
    break;

  case 558:

    {
		if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 559:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 566:

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

  case 567:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 576:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
}
    break;

  case 577:

    {
		if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 578:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 585:

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

  case 586:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 591:

    {parserData->tempStr = "";}
    break;

  case 596:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	}
    break;

  case 599:

    {
	osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 606:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 608:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 615:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 617:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 624:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 626:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 633:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 635:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 642:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 644:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 651:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 653:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 660:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 662:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 670:

    { 	 
		parserData->iOther++;
	}
    break;

  case 671:

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

  case 672:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	}
    break;

  case 675:

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

  case 676:

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

  case 677:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 678:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
    break;

  case 679:

    {	
	 	if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultType failed");
    }
    break;

  case 680:

    {	
	 	if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->varTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarType failed");
    }
    break;

  case 681:

    {	
	 	if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 682:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 692:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 693:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 696:

    {	
 		if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->idx) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
	}
    break;

  case 697:

    {	
 		if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
	}
    break;

  case 703:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	}
    break;

  case 706:

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

  case 707:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 708:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 711:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 721:

    {
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 723:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
}
    break;

  case 732:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}
    break;

  case 733:

    {
		if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
    break;

  case 734:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	}
    break;

  case 741:

    {
	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
}
    break;

  case 742:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 750:

    {
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 757:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 759:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 766:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 768:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 775:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 777:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 784:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 786:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 793:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 795:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 802:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 804:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 811:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 813:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 821:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 822:

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

  case 823:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	}
    break;

  case 826:

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

  case 827:

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

  case 828:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 829:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 830:

    {	
	 	if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultType failed");
    }
    break;

  case 831:

    {	
	 	if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->objTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 832:

    {	
	 	if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 833:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 843:

    {  
	parserData->kounter++;
}
    break;

  case 844:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;	
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 847:

    {
		if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
	}
    break;

  case 848:

    {	
 		if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
	}
    break;

  case 854:

    {
		if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	}
    break;

  case 857:

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

  case 858:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 859:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 862:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 872:

    {
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 874:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
}
    break;

  case 882:

    {	parserData->numberAttributePresent = false; }
    break;

  case 883:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
}
    break;

  case 884:

    {
		if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	}
    break;

  case 885:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	}
    break;

  case 892:

    {
	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->nameAttribute,
							   parserData->tempVal                           ) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
}
    break;

  case 893:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 901:

    {
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 908:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 910:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 917:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 919:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 926:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 928:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 935:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 937:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 944:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 946:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 953:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 955:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 962:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 964:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 972:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 973:

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

  case 974:

    {
		if (!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	}
    break;

  case 977:

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

  case 978:

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

  case 979:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 980:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 981:

    {	
	 	if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultType failed");
    }
    break;

  case 982:

    {	
	 	if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->conTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConType failed");
    }
    break;

  case 983:

    {	
	 	if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
 												 parserData->enumTypeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 984:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 994:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 995:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 998:

    {	
 		if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
	}
    break;

  case 999:

    {	
 		if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
	}
    break;

  case 1005:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	}
    break;

  case 1008:

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

  case 1009:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1010:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 1013:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1023:

    {
	parserData->numberOf = 0; 
}
    break;

  case 1024:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 1025:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	}
    break;

  case 1026:

    {
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	}
    break;

  case 1033:

    {
	parserData->iOther++;
}
    break;

  case 1034:

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

  case 1035:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	//if (!parserData->numberOfItemsPresent)
	//	osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1038:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	}
    break;

  case 1039:

    {	
		if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
												 parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultValuee failed");
	}
    break;

  case 1040:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	}
    break;

  case 1041:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	}
    break;

  case 1042:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1043:

    {
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1044:

    {
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1051:

    {
	parserData->kounter++;
}
    break;

  case 1052:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}
    break;

  case 1057:

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

  case 1060:

    {
	parserData->numberOf = 0; 
}
    break;

  case 1061:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 1062:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	}
    break;

  case 1063:

    {
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	}
    break;

  case 1070:

    {
	parserData->iOther++;
}
    break;

  case 1071:

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

  case 1072:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1075:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	}
    break;

  case 1076:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	}
    break;

  case 1077:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	}
    break;

  case 1078:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1079:

    {
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1080:

    {
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1087:

    {
	parserData->kounter++;
}
    break;

  case 1088:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}
    break;

  case 1093:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1094:

    {
		if (parserData->categoryAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
		parserData->categoryAttributePresent = true;
	}
    break;

  case 1097:

    { 
	parserData->categoryAttribute = ""; 
}
    break;

  case 1098:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1099:

    {
		if (parserData->conTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one conType attribute allowed for this element");
		parserData->conTypeAttributePresent = true;
	}
    break;

  case 1102:

    { 
	parserData->conTypeAttribute = ""; 
}
    break;

  case 1103:

    { 
	parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1104:

    {
		if (parserData->descriptionAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
		parserData->descriptionAttributePresent = true;
	}
    break;

  case 1107:

    { 
	parserData->descriptionAttribute = ""; 
}
    break;

  case 1108:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1109:

    {
		if (parserData->enumTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one enumType attribute allowed for this element");
		parserData->enumTypeAttributePresent = true;
	}
    break;

  case 1112:

    { 
	parserData->enumTypeAttribute = ""; 
}
    break;

  case 1113:

    { 
	parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1114:

    {	
		if (parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
		parserData->idxAttributePresent = true;
		parserData->idx = (yyvsp[(3) - (4)].ival); 
	}
    break;

  case 1115:

    {
	   if (parserData->nameAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1118:

    { 
	parserData->nameAttribute = ""; 
}
    break;

  case 1119:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1120:

    {
		if (parserData->objTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one objType attribute allowed for this element");
		parserData->objTypeAttributePresent = true;
	}
    break;

  case 1123:

    { 
	parserData->objTypeAttribute = ""; 
}
    break;

  case 1124:

    { 
	parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1125:

    {
		if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
		parserData->typeAttributePresent = true;
	}
    break;

  case 1128:

    { 
	parserData->typeAttribute = ""; 
}
    break;

  case 1129:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1130:

    {
		if (parserData->unitAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
		parserData->unitAttributePresent = true;
	}
    break;

  case 1133:

    { 
	parserData->unitAttribute = ""; 
}
    break;

  case 1134:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1135:

    {
		if (parserData->valueAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
		parserData->valueAttributePresent = true;
	}
    break;

  case 1138:

    { 
	parserData->valueAttribute = ""; 
}
    break;

  case 1139:

    { 
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1140:

    {
		if (parserData->varTypeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one varType attribute allowed for this element");
		parserData->varTypeAttributePresent = true;
	}
    break;

  case 1143:

    { 
	parserData->varTypeAttribute = ""; 
}
    break;

  case 1144:

    { 
	parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1145:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1146:

    {
	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1147:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1148:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1149:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1150:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1151:

    {
	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1152:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1153:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1154:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1155:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1156:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1157:

    {
	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1158:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1159:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1160:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1161:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1162:

    {
	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1163:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	}
    break;

  case 1168:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1174:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1176:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1181:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if (b64string == NULL) 
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data length does not match numberOfEl"); 
	intvec = (int*)&base64decodeddata[0];
	for (int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete [] b64string;
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1182:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1183:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1184:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1185:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1186:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1187:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1188:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
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


