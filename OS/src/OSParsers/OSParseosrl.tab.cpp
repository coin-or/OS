
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
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1628

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
      22,    24,    28,    30,    32,    33,    40,    41,    43,    46,
      48,    50,    52,    55,    57,    61,    63,    65,    68,    70,
      72,    74,    76,    78,    79,    81,    83,    85,    87,    89,
      93,    94,    96,    98,   100,   102,   104,   108,   109,   111,
     113,   115,   117,   119,   123,   124,   126,   128,   130,   132,
     134,   138,   139,   141,   143,   145,   147,   149,   153,   154,
     157,   159,   161,   163,   166,   168,   172,   174,   176,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   201,
     203,   205,   207,   210,   212,   214,   216,   218,   220,   223,
     225,   229,   231,   233,   236,   240,   242,   244,   245,   248,
     250,   252,   255,   257,   260,   262,   264,   266,   269,   271,
     275,   277,   280,   282,   284,   286,   289,   291,   295,   297,
     300,   302,   304,   306,   309,   311,   315,   317,   320,   322,
     324,   326,   329,   331,   335,   337,   340,   342,   344,   346,
     349,   351,   355,   357,   360,   362,   364,   366,   369,   371,
     375,   377,   380,   382,   384,   386,   389,   391,   395,   397,
     401,   403,   405,   407,   409,   412,   414,   418,   420,   422,
     425,   429,   431,   433,   434,   437,   439,   441,   443,   446,
     448,   449,   452,   454,   456,   458,   461,   463,   467,   469,
     471,   474,   476,   478,   480,   482,   484,   486,   489,   491,
     493,   495,   498,   500,   504,   506,   510,   512,   514,   515,
     518,   520,   522,   526,   528,   532,   534,   536,   537,   540,
     542,   544,   548,   550,   554,   556,   558,   559,   562,   564,
     566,   570,   572,   576,   578,   579,   581,   585,   587,   591,
     593,   595,   597,   599,   602,   604,   608,   610,   612,   615,
     619,   621,   623,   624,   627,   629,   631,   633,   636,   638,
     639,   642,   644,   646,   648,   651,   653,   657,   659,   661,
     664,   666,   668,   670,   672,   674,   676,   679,   681,   683,
     685,   688,   690,   694,   696,   699,   701,   703,   705,   708,
     710,   714,   716,   719,   721,   723,   725,   728,   730,   734,
     736,   739,   741,   743,   745,   748,   750,   754,   756,   759,
     761,   763,   765,   768,   770,   774,   776,   780,   782,   784,
     786,   788,   791,   793,   797,   799,   801,   804,   808,   810,
     812,   813,   816,   818,   820,   822,   825,   827,   828,   831,
     833,   835,   837,   840,   842,   846,   848,   850,   853,   855,
     857,   859,   861,   863,   865,   867,   869,   871,   873,   875,
     878,   880,   882,   884,   887,   889,   893,   895,   898,   900,
     902,   904,   907,   909,   913,   915,   918,   920,   922,   924,
     927,   929,   933,   935,   938,   940,   942,   944,   947,   949,
     953,   955,   958,   960,   962,   964,   967,   969,   973,   975,
     979,   981,   983,   985,   987,   990,   992,   996,   998,  1000,
    1003,  1007,  1009,  1010,  1013,  1015,  1017,  1019,  1021,  1023,
    1025,  1028,  1030,  1034,  1036,  1038,  1040,  1044,  1046,  1048,
    1049,  1052,  1054,  1056,  1060,  1062,  1066,  1068,  1070,  1071,
    1074,  1076,  1078,  1082,  1084,  1088,  1090,  1092,  1093,  1096,
    1098,  1100,  1104,  1106,  1110,  1112,  1113,  1115,  1119,  1121,
    1125,  1127,  1129,  1131,  1133,  1136,  1138,  1142,  1144,  1146,
    1149,  1153,  1155,  1157,  1158,  1161,  1163,  1165,  1167,  1170,
    1172,  1173,  1177,  1179,  1181,  1182,  1185,  1187,  1189,  1191,
    1193,  1195,  1197,  1200,  1202,  1206,  1209,  1211,  1214,  1218,
    1220,  1222,  1223,  1226,  1228,  1230,  1232,  1237,  1241,  1245,
    1254,  1258,  1260,  1262,  1264,  1267,  1269,  1271,  1273,  1275,
    1277,  1280,  1282,  1286,  1288,  1290,  1293,  1297,  1299,  1301,
    1302,  1305,  1307,  1309,  1312,  1314,  1315,  1318,  1320,  1322,
    1324,  1327,  1329,  1333,  1335,  1336,  1340,  1342,  1343,  1345,
    1347,  1349,  1351,  1355,  1360,  1361,  1365,  1367,  1369,  1371,
    1373,  1376,  1378,  1382,  1384,  1386,  1389,  1393,  1395,  1396,
    1399,  1401,  1403,  1407,  1408,  1412,  1414,  1416,  1418,  1420,
    1423,  1425,  1429,  1431,  1433,  1436,  1440,  1442,  1443,  1446,
    1448,  1450,  1452,  1454,  1457,  1459,  1463,  1465,  1466,  1469,
    1471,  1473,  1475,  1477,  1481,  1489,  1490,  1494,  1496,  1498,
    1500,  1502,  1504,  1508,  1510,  1511,  1515,  1517,  1519,  1521,
    1523,  1525,  1529,  1531,  1532,  1536,  1538,  1540,  1542,  1544,
    1546,  1550,  1552,  1553,  1557,  1559,  1561,  1563,  1565,  1567,
    1571,  1573,  1574,  1578,  1580,  1582,  1584,  1586,  1588,  1592,
    1594,  1595,  1599,  1601,  1603,  1605,  1607,  1609,  1613,  1615,
    1616,  1620,  1622,  1624,  1626,  1628,  1630,  1634,  1636,  1637,
    1640,  1644,  1646,  1648,  1649,  1652,  1654,  1656,  1658,  1660,
    1662,  1664,  1666,  1668,  1670,  1672,  1675,  1677,  1681,  1683,
    1685,  1687,  1690,  1694,  1696,  1697,  1700,  1702,  1704,  1706,
    1708,  1711,  1713,  1717,  1719,  1721,  1724,  1728,  1730,  1732,
    1733,  1736,  1738,  1740,  1742,  1744,  1746,  1748,  1752,  1754,
    1755,  1759,  1761,  1762,  1764,  1766,  1768,  1770,  1774,  1778,
    1779,  1783,  1785,  1787,  1789,  1791,  1794,  1796,  1800,  1802,
    1804,  1807,  1811,  1813,  1814,  1817,  1819,  1821,  1825,  1826,
    1829,  1831,  1833,  1835,  1837,  1841,  1849,  1850,  1854,  1856,
    1858,  1860,  1862,  1864,  1868,  1870,  1871,  1875,  1877,  1879,
    1881,  1883,  1885,  1889,  1891,  1892,  1896,  1898,  1900,  1902,
    1904,  1906,  1910,  1912,  1913,  1917,  1919,  1921,  1923,  1925,
    1927,  1931,  1933,  1934,  1938,  1940,  1942,  1944,  1946,  1948,
    1952,  1954,  1955,  1959,  1961,  1963,  1965,  1967,  1969,  1973,
    1975,  1976,  1980,  1982,  1984,  1986,  1988,  1990,  1994,  1996,
    1997,  2000,  2004,  2006,  2008,  2009,  2012,  2014,  2016,  2018,
    2020,  2022,  2024,  2026,  2028,  2030,  2032,  2035,  2037,  2041,
    2043,  2045,  2047,  2050,  2054,  2056,  2057,  2060,  2062,  2064,
    2066,  2068,  2071,  2073,  2077,  2079,  2081,  2084,  2088,  2090,
    2092,  2093,  2096,  2098,  2100,  2102,  2104,  2106,  2108,  2112,
    2114,  2115,  2119,  2121,  2122,  2124,  2126,  2128,  2130,  2134,
    2138,  2139,  2143,  2145,  2147,  2149,  2151,  2154,  2156,  2160,
    2162,  2164,  2167,  2171,  2173,  2174,  2177,  2179,  2181,  2185,
    2186,  2189,  2191,  2193,  2195,  2197,  2201,  2209,  2210,  2214,
    2216,  2218,  2220,  2222,  2224,  2228,  2230,  2231,  2235,  2237,
    2239,  2241,  2243,  2245,  2249,  2251,  2252,  2256,  2258,  2260,
    2262,  2264,  2266,  2270,  2272,  2273,  2277,  2279,  2281,  2283,
    2285,  2287,  2291,  2293,  2294,  2298,  2300,  2302,  2304,  2306,
    2308,  2312,  2314,  2315,  2319,  2321,  2323,  2325,  2327,  2329,
    2333,  2335,  2336,  2340,  2342,  2344,  2346,  2348,  2350,  2354,
    2356,  2357,  2360,  2364,  2366,  2368,  2369,  2372,  2374,  2376,
    2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,  2395,  2397,
    2401,  2403,  2405,  2407,  2410,  2414,  2416,  2417,  2420,  2422,
    2424,  2426,  2428,  2431,  2433,  2437,  2439,  2441,  2444,  2448,
    2450,  2452,  2453,  2456,  2458,  2460,  2462,  2464,  2466,  2468,
    2472,  2474,  2475,  2479,  2481,  2483,  2485,  2487,  2490,  2492,
    2496,  2498,  2500,  2503,  2507,  2509,  2511,  2512,  2515,  2517,
    2519,  2521,  2523,  2525,  2527,  2529,  2532,  2534,  2538,  2540,
    2542,  2545,  2547,  2549,  2551,  2553,  2555,  2559,  2561,  2562,
    2566,  2568,  2570,  2572,  2574,  2577,  2579,  2583,  2585,  2587,
    2590,  2594,  2596,  2598,  2599,  2602,  2604,  2606,  2608,  2610,
    2612,  2614,  2617,  2619,  2623,  2625,  2627,  2630,  2632,  2634,
    2636,  2638,  2640,  2644,  2646,  2648,  2650,  2652,  2654,  2658,
    2660,  2662,  2664,  2666,  2670,  2672,  2674,  2676,  2678,  2682,
    2684,  2686,  2688,  2690,  2694,  2699,  2701,  2703,  2705,  2707,
    2711,  2713,  2715,  2717,  2719,  2723,  2725,  2727,  2729,  2731,
    2735,  2737,  2739,  2741,  2743,  2747,  2749,  2751,  2753,  2755,
    2759,  2761,  2763,  2765,  2767,  2771,  2776,  2781,  2786,  2791,
    2796,  2801,  2806,  2811,  2816,  2821,  2826,  2831,  2836,  2841,
    2846,  2851,  2856,  2861,  2863,  2865,  2866,  2869,  2873,  2875,
    2877,  2878,  2881,  2883,  2885,  2889,  2893,  2898,  2900,  2902,
    2905,  2907,  2911,  2916,  2921,  2923,  2925,  2927,  2929,  2931,
    2934,  2935,  2938,  2940,  2942,  2944
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     233,     0,    -1,   234,   242,   240,    -1,   235,   236,   237,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   238,    -1,
     239,    -1,    11,    -1,    10,   242,   240,    -1,   241,    -1,
      15,    -1,    -1,   243,   272,   352,   406,   458,   553,    -1,
      -1,   244,    -1,   245,   246,    -1,    65,    -1,   247,    -1,
     248,    -1,    10,    66,    -1,    11,    -1,    10,   249,    66,
      -1,   250,    -1,   251,    -1,   250,   251,    -1,   252,    -1,
     256,    -1,   260,    -1,   264,    -1,   268,    -1,    -1,   253,
      -1,   254,    -1,   255,    -1,    84,    -1,    83,    -1,    81,
       5,    82,    -1,    -1,   257,    -1,   258,    -1,   259,    -1,
      88,    -1,    87,    -1,    85,     5,    86,    -1,    -1,   261,
      -1,   262,    -1,   263,    -1,    92,    -1,    91,    -1,    89,
       5,    90,    -1,    -1,   265,    -1,   266,    -1,   267,    -1,
      96,    -1,    95,    -1,    93,     5,    94,    -1,    -1,   269,
      -1,   270,    -1,   271,    -1,   100,    -1,    99,    -1,    97,
       5,    98,    -1,    -1,   273,   274,    -1,    67,    -1,   275,
      -1,   276,    -1,    10,    68,    -1,    11,    -1,    10,   277,
      68,    -1,   278,    -1,   279,    -1,   278,   279,    -1,   280,
      -1,   296,    -1,   302,    -1,   308,    -1,   314,    -1,   320,
      -1,   326,    -1,   332,    -1,   338,    -1,   281,   282,   285,
      -1,   141,    -1,   283,    -1,   284,    -1,   283,   284,    -1,
     993,    -1,   976,    -1,  1023,    -1,   286,    -1,   287,    -1,
      10,   142,    -1,    11,    -1,    10,   288,   142,    -1,   289,
      -1,   290,    -1,   289,   290,    -1,   291,   292,   295,    -1,
     191,    -1,   293,    -1,    -1,   293,   294,    -1,   985,    -1,
     976,    -1,    10,   192,    -1,    11,    -1,   297,   298,    -1,
     153,    -1,   299,    -1,   300,    -1,    10,   154,    -1,    11,
      -1,    10,   301,   154,    -1,     4,    -1,   303,   304,    -1,
     177,    -1,   305,    -1,   306,    -1,    10,   178,    -1,    11,
      -1,    10,   307,   178,    -1,     4,    -1,   309,   310,    -1,
     175,    -1,   311,    -1,   312,    -1,    10,   176,    -1,    11,
      -1,    10,   313,   176,    -1,     4,    -1,   315,   316,    -1,
     147,    -1,   317,    -1,   318,    -1,    10,   148,    -1,    11,
      -1,    10,   319,   148,    -1,     4,    -1,   321,   322,    -1,
     151,    -1,   323,    -1,   324,    -1,    10,   152,    -1,    11,
      -1,    10,   325,   152,    -1,     4,    -1,   327,   328,    -1,
     183,    -1,   329,    -1,   330,    -1,    10,   184,    -1,    11,
      -1,    10,   331,   184,    -1,     4,    -1,   333,   334,    -1,
     201,    -1,   335,    -1,   336,    -1,    10,   202,    -1,    11,
      -1,    10,   337,   202,    -1,     4,    -1,   339,   340,   341,
      -1,   165,    -1,  1018,    -1,   342,    -1,   343,    -1,    10,
     166,    -1,    11,    -1,    10,   344,   166,    -1,   345,    -1,
     346,    -1,   345,   346,    -1,   347,   348,   351,    -1,   163,
      -1,   349,    -1,    -1,   349,   350,    -1,   985,    -1,  1001,
      -1,   976,    -1,    10,   164,    -1,    11,    -1,    -1,   353,
     354,    -1,    69,    -1,   355,    -1,   356,    -1,    10,    70,
      -1,    11,    -1,    10,   357,    70,    -1,   358,    -1,   359,
      -1,   358,   359,    -1,   360,    -1,   366,    -1,   373,    -1,
     380,    -1,   387,    -1,   392,    -1,   361,   362,    -1,   195,
      -1,   363,    -1,   364,    -1,    10,   196,    -1,    11,    -1,
      10,   365,   196,    -1,     4,    -1,   367,   368,   371,    -1,
     113,    -1,   369,    -1,    -1,   369,   370,    -1,   997,    -1,
     976,    -1,    10,   372,   114,    -1,  1042,    -1,   374,   375,
     378,    -1,   115,    -1,   376,    -1,    -1,   376,   377,    -1,
     997,    -1,   976,    -1,    10,   379,   116,    -1,  1042,    -1,
     381,   382,   385,    -1,   111,    -1,   383,    -1,    -1,   383,
     384,    -1,   997,    -1,   976,    -1,    10,   386,   112,    -1,
    1042,    -1,   388,   389,   390,    -1,   109,    -1,    -1,   976,
      -1,    10,   391,   110,    -1,     6,    -1,   393,   394,   395,
      -1,   165,    -1,  1018,    -1,   396,    -1,   397,    -1,    10,
     166,    -1,    11,    -1,    10,   398,   166,    -1,   399,    -1,
     400,    -1,   399,   400,    -1,   401,   402,   405,    -1,   163,
      -1,   403,    -1,    -1,   403,   404,    -1,   985,    -1,  1001,
      -1,   976,    -1,    10,   164,    -1,    11,    -1,    -1,   407,
     408,    -1,    71,    -1,   409,    -1,   410,    -1,    10,    72,
      -1,    11,    -1,    10,   411,    72,    -1,   412,    -1,   413,
      -1,   412,   413,    -1,   414,    -1,   420,    -1,   426,    -1,
     432,    -1,   438,    -1,   444,    -1,   415,   416,    -1,   131,
      -1,   417,    -1,   418,    -1,    10,   132,    -1,    11,    -1,
      10,   419,   132,    -1,     4,    -1,   421,   422,    -1,   129,
      -1,   423,    -1,   424,    -1,    10,   130,    -1,    11,    -1,
      10,   425,   130,    -1,     6,    -1,   427,   428,    -1,   205,
      -1,   429,    -1,   430,    -1,    10,   206,    -1,    11,    -1,
      10,   431,   206,    -1,     6,    -1,   433,   434,    -1,   199,
      -1,   435,    -1,   436,    -1,    10,   200,    -1,    11,    -1,
      10,   437,   200,    -1,     4,    -1,   439,   440,    -1,   179,
      -1,   441,    -1,   442,    -1,    10,   180,    -1,    11,    -1,
      10,   443,   180,    -1,  1042,    -1,   445,   446,   447,    -1,
     165,    -1,  1018,    -1,   448,    -1,   449,    -1,    10,   166,
      -1,    11,    -1,    10,   450,   166,    -1,   451,    -1,   452,
      -1,   451,   452,    -1,   453,   454,   457,    -1,   163,    -1,
     455,    -1,    -1,   455,   456,    -1,   985,    -1,  1001,    -1,
     976,    -1,    10,   164,    -1,    11,    -1,    -1,   459,   460,
      -1,    73,    -1,   461,    -1,   462,    -1,    10,    74,    -1,
      11,    -1,    10,   463,    74,    -1,   464,    -1,   465,    -1,
     464,   465,    -1,   466,    -1,   472,    -1,   478,    -1,   484,
      -1,   490,    -1,   496,    -1,   513,    -1,   520,    -1,   527,
      -1,   534,    -1,   539,    -1,   467,   468,    -1,   187,    -1,
     469,    -1,   470,    -1,    10,   188,    -1,    11,    -1,    10,
     471,   188,    -1,     4,    -1,   473,   474,    -1,   189,    -1,
     475,    -1,   476,    -1,    10,   190,    -1,    11,    -1,    10,
     477,   190,    -1,     4,    -1,   479,   480,    -1,   173,    -1,
     481,    -1,   482,    -1,    10,   174,    -1,    11,    -1,    10,
     483,   174,    -1,     4,    -1,   485,   486,    -1,   101,    -1,
     487,    -1,   488,    -1,    10,   102,    -1,    11,    -1,    10,
     489,   102,    -1,     4,    -1,   491,   492,    -1,   139,    -1,
     493,    -1,   494,    -1,    10,   140,    -1,    11,    -1,    10,
     495,   140,    -1,     4,    -1,   497,   498,   499,    -1,   203,
      -1,  1024,    -1,   500,    -1,   501,    -1,    10,   204,    -1,
      11,    -1,    10,   502,   204,    -1,   503,    -1,   504,    -1,
     503,   504,    -1,   505,   506,   508,    -1,   197,    -1,    -1,
     506,   507,    -1,   997,    -1,   993,    -1,   968,    -1,   976,
      -1,   509,    -1,   510,    -1,    10,   198,    -1,    11,    -1,
      10,   511,   198,    -1,   512,    -1,     7,    -1,     6,    -1,
     514,   515,   518,    -1,   213,    -1,   516,    -1,    -1,   516,
     517,    -1,   997,    -1,   976,    -1,    10,   519,   214,    -1,
    1042,    -1,   521,   522,   525,    -1,   215,    -1,   523,    -1,
      -1,   523,   524,    -1,   997,    -1,   976,    -1,    10,   526,
     216,    -1,  1042,    -1,   528,   529,   532,    -1,   211,    -1,
     530,    -1,    -1,   530,   531,    -1,   997,    -1,   976,    -1,
      10,   533,   212,    -1,  1042,    -1,   535,   536,   537,    -1,
     209,    -1,    -1,   976,    -1,    10,   538,   210,    -1,     6,
      -1,   540,   541,   542,    -1,   165,    -1,  1018,    -1,   543,
      -1,   544,    -1,    10,   166,    -1,    11,    -1,    10,   545,
     166,    -1,   546,    -1,   547,    -1,   546,   547,    -1,   548,
     549,   552,    -1,   163,    -1,   550,    -1,    -1,   550,   551,
      -1,   985,    -1,  1001,    -1,   976,    -1,    10,   164,    -1,
      11,    -1,    -1,   554,   555,   558,    -1,    75,    -1,   556,
      -1,    -1,   556,   557,    -1,  1021,    -1,  1026,    -1,  1010,
      -1,  1015,    -1,   559,    -1,   560,    -1,    10,    76,    -1,
      11,    -1,    10,   561,    76,    -1,   562,   945,    -1,   563,
      -1,   562,   563,    -1,   564,   565,   571,    -1,   181,    -1,
     566,    -1,    -1,   566,   567,    -1,   568,    -1,   569,    -1,
     570,    -1,    36,  1044,     6,  1044,    -1,    63,     3,  1044,
      -1,    61,     3,  1044,    -1,    10,   572,   588,   594,   714,
     818,   922,   182,    -1,   573,   574,   577,    -1,   187,    -1,
     575,    -1,   576,    -1,   575,   576,    -1,   993,    -1,   976,
      -1,  1023,    -1,   578,    -1,   579,    -1,    10,   188,    -1,
      11,    -1,    10,   580,   188,    -1,   581,    -1,   582,    -1,
     581,   582,    -1,   583,   584,   587,    -1,   191,    -1,   585,
      -1,    -1,   585,   586,    -1,   993,    -1,   976,    -1,    10,
     192,    -1,    11,    -1,    -1,   589,   590,    -1,   153,    -1,
     591,    -1,   592,    -1,    10,   154,    -1,    11,    -1,    10,
     593,   154,    -1,     4,    -1,    -1,   595,   596,   597,    -1,
     223,    -1,    -1,  1020,    -1,   598,    -1,   599,    -1,    11,
      -1,    10,   600,   224,    -1,   601,   614,   630,   685,    -1,
      -1,   602,   603,   604,    -1,   217,    -1,  1025,    -1,   605,
      -1,   606,    -1,    10,   218,    -1,    11,    -1,    10,   607,
     218,    -1,   608,    -1,   609,    -1,   608,   609,    -1,   610,
     611,   613,    -1,   221,    -1,    -1,   611,   612,    -1,   984,
      -1,   985,    -1,    10,  1042,   222,    -1,    -1,   615,   616,
     617,    -1,   219,    -1,  1025,    -1,   618,    -1,   619,    -1,
      10,   220,    -1,    11,    -1,    10,   620,   220,    -1,   621,
      -1,   622,    -1,   621,   622,    -1,   623,   624,   626,    -1,
     221,    -1,    -1,   624,   625,    -1,   984,    -1,   985,    -1,
     627,    -1,   628,    -1,    10,   222,    -1,    11,    -1,    10,
     629,   222,    -1,     4,    -1,    -1,   631,   632,    -1,   121,
      -1,   633,    -1,   634,    -1,    11,    -1,    10,   635,   122,
      -1,   636,   643,   650,   657,   664,   671,   678,    -1,    -1,
     637,   638,   639,    -1,   119,    -1,  1011,    -1,   640,    -1,
     641,    -1,    11,    -1,    10,   642,   120,    -1,  1027,    -1,
      -1,   644,   645,   646,    -1,   105,    -1,  1011,    -1,   647,
      -1,   648,    -1,    11,    -1,    10,   649,   106,    -1,  1027,
      -1,    -1,   651,   652,   653,    -1,   107,    -1,  1011,    -1,
     654,    -1,   655,    -1,    11,    -1,    10,   656,   108,    -1,
    1027,    -1,    -1,   658,   659,   660,    -1,   103,    -1,  1011,
      -1,   661,    -1,   662,    -1,    11,    -1,    10,   663,   104,
      -1,  1027,    -1,    -1,   665,   666,   667,    -1,   149,    -1,
    1011,    -1,   668,    -1,   669,    -1,    11,    -1,    10,   670,
     150,    -1,  1027,    -1,    -1,   672,   673,   674,    -1,   193,
      -1,  1011,    -1,   675,    -1,   676,    -1,    11,    -1,    10,
     677,   194,    -1,  1027,    -1,    -1,   679,   680,   681,    -1,
     207,    -1,  1011,    -1,   682,    -1,   683,    -1,    11,    -1,
      10,   684,   208,    -1,  1027,    -1,    -1,   685,   686,    -1,
     687,   688,   691,    -1,   163,    -1,   689,    -1,    -1,   689,
     690,    -1,  1025,    -1,  1012,    -1,  1001,    -1,   985,    -1,
     993,    -1,  1005,    -1,   980,    -1,   976,    -1,   692,    -1,
     693,    -1,    10,   164,    -1,    11,    -1,    10,   694,   164,
      -1,   695,    -1,   704,    -1,   696,    -1,   695,   696,    -1,
     697,   698,   700,    -1,   221,    -1,    -1,   698,   699,    -1,
     984,    -1,   985,    -1,   701,    -1,   702,    -1,    10,   222,
      -1,    11,    -1,    10,   703,   222,    -1,  1043,    -1,   705,
      -1,   704,   705,    -1,   706,   707,   710,    -1,   137,    -1,
     708,    -1,    -1,   708,   709,    -1,  1011,    -1,  1001,    -1,
     976,    -1,   711,    -1,   712,    -1,    11,    -1,    10,   713,
     138,    -1,  1027,    -1,    -1,   715,   716,   717,    -1,   157,
      -1,    -1,  1017,    -1,   718,    -1,   719,    -1,    11,    -1,
      10,   720,   158,    -1,   721,   734,   789,    -1,    -1,   722,
     723,   724,    -1,   217,    -1,  1014,    -1,   725,    -1,   726,
      -1,    10,   218,    -1,    11,    -1,    10,   727,   218,    -1,
     728,    -1,   729,    -1,   728,   729,    -1,   730,   731,   733,
      -1,   155,    -1,    -1,   731,   732,    -1,   984,    -1,   985,
      -1,    10,  1042,   156,    -1,    -1,   735,   736,    -1,   121,
      -1,   737,    -1,   738,    -1,    11,    -1,    10,   739,   122,
      -1,   740,   747,   754,   761,   768,   775,   782,    -1,    -1,
     741,   742,   743,    -1,   119,    -1,  1011,    -1,   744,    -1,
     745,    -1,    11,    -1,    10,   746,   120,    -1,  1027,    -1,
      -1,   748,   749,   750,    -1,   105,    -1,  1011,    -1,   751,
      -1,   752,    -1,    11,    -1,    10,   753,   106,    -1,  1027,
      -1,    -1,   755,   756,   757,    -1,   107,    -1,  1011,    -1,
     758,    -1,   759,    -1,    11,    -1,    10,   760,   108,    -1,
    1027,    -1,    -1,   762,   763,   764,    -1,   103,    -1,  1011,
      -1,   765,    -1,   766,    -1,    11,    -1,    10,   767,   104,
      -1,  1027,    -1,    -1,   769,   770,   771,    -1,   149,    -1,
    1011,    -1,   772,    -1,   773,    -1,    11,    -1,    10,   774,
     150,    -1,  1027,    -1,    -1,   776,   777,   778,    -1,   193,
      -1,  1011,    -1,   779,    -1,   780,    -1,    11,    -1,    10,
     781,   194,    -1,  1027,    -1,    -1,   783,   784,   785,    -1,
     207,    -1,  1011,    -1,   786,    -1,   787,    -1,    11,    -1,
      10,   788,   208,    -1,  1027,    -1,    -1,   789,   790,    -1,
     791,   792,   795,    -1,   163,    -1,   793,    -1,    -1,   793,
     794,    -1,  1014,    -1,  1012,    -1,  1001,    -1,   985,    -1,
     993,    -1,   989,    -1,   980,    -1,   976,    -1,   796,    -1,
     797,    -1,    10,   164,    -1,    11,    -1,    10,   798,   164,
      -1,   799,    -1,   808,    -1,   800,    -1,   799,   800,    -1,
     801,   802,   804,    -1,   155,    -1,    -1,   802,   803,    -1,
     984,    -1,   985,    -1,   805,    -1,   806,    -1,    10,   156,
      -1,    11,    -1,    10,   807,   156,    -1,  1043,    -1,   809,
      -1,   808,   809,    -1,   810,   811,   814,    -1,   137,    -1,
     812,    -1,    -1,   812,   813,    -1,  1011,    -1,  1001,    -1,
     976,    -1,   815,    -1,   816,    -1,    11,    -1,    10,   817,
     138,    -1,  1027,    -1,    -1,   819,   820,   821,    -1,   127,
      -1,    -1,  1016,    -1,   822,    -1,   823,    -1,    11,    -1,
      10,   824,   128,    -1,   825,   838,   893,    -1,    -1,   826,
     827,   828,    -1,   133,    -1,  1009,    -1,   829,    -1,   830,
      -1,    10,   134,    -1,    11,    -1,    10,   831,   134,    -1,
     832,    -1,   833,    -1,   832,   833,    -1,   834,   835,   837,
      -1,   125,    -1,    -1,   835,   836,    -1,   984,    -1,   985,
      -1,    10,  1042,   126,    -1,    -1,   839,   840,    -1,   121,
      -1,   841,    -1,   842,    -1,    11,    -1,    10,   843,   122,
      -1,   844,   851,   858,   865,   872,   879,   886,    -1,    -1,
     845,   846,   847,    -1,   119,    -1,  1011,    -1,   848,    -1,
     849,    -1,    11,    -1,    10,   850,   120,    -1,  1027,    -1,
      -1,   852,   853,   854,    -1,   105,    -1,  1011,    -1,   855,
      -1,   856,    -1,    11,    -1,    10,   857,   106,    -1,  1027,
      -1,    -1,   859,   860,   861,    -1,   107,    -1,  1011,    -1,
     862,    -1,   863,    -1,    11,    -1,    10,   864,   108,    -1,
    1027,    -1,    -1,   866,   867,   868,    -1,   103,    -1,  1011,
      -1,   869,    -1,   870,    -1,    11,    -1,    10,   871,   104,
      -1,  1027,    -1,    -1,   873,   874,   875,    -1,   149,    -1,
    1011,    -1,   876,    -1,   877,    -1,    11,    -1,    10,   878,
     150,    -1,  1027,    -1,    -1,   880,   881,   882,    -1,   193,
      -1,  1011,    -1,   883,    -1,   884,    -1,    11,    -1,    10,
     885,   194,    -1,  1027,    -1,    -1,   887,   888,   889,    -1,
     207,    -1,  1011,    -1,   890,    -1,   891,    -1,    11,    -1,
      10,   892,   208,    -1,  1027,    -1,    -1,   893,   894,    -1,
     895,   896,   899,    -1,   163,    -1,   897,    -1,    -1,   897,
     898,    -1,  1009,    -1,  1012,    -1,  1001,    -1,   985,    -1,
     993,    -1,   972,    -1,   980,    -1,   976,    -1,   900,    -1,
     901,    -1,    10,   164,    -1,    11,    -1,    10,   902,   164,
      -1,   903,    -1,   912,    -1,   904,    -1,   903,   904,    -1,
     905,   906,   908,    -1,   125,    -1,    -1,   906,   907,    -1,
     984,    -1,   985,    -1,   909,    -1,   910,    -1,    10,   126,
      -1,    11,    -1,    10,   911,   126,    -1,  1043,    -1,   913,
      -1,   912,   913,    -1,   914,   915,   918,    -1,   137,    -1,
     916,    -1,    -1,   916,   917,    -1,  1011,    -1,  1001,    -1,
     976,    -1,   919,    -1,   920,    -1,    11,    -1,    10,   921,
     138,    -1,  1027,    -1,    -1,   923,   924,   925,    -1,   169,
      -1,  1019,    -1,   926,    -1,   927,    -1,    10,   170,    -1,
      11,    -1,    10,   928,   170,    -1,   929,    -1,   930,    -1,
     929,   930,    -1,   931,   932,   935,    -1,   167,    -1,   933,
      -1,    -1,   933,   934,    -1,   985,    -1,  1001,    -1,   968,
      -1,   976,    -1,  1013,    -1,   936,    -1,   937,    -1,    10,
     168,    -1,    11,    -1,    10,   938,   168,    -1,   939,    -1,
     940,    -1,   939,   940,    -1,   941,    -1,   942,    -1,   943,
      -1,    79,    -1,    80,    -1,    77,   944,    78,    -1,     5,
      -1,    -1,   946,   947,   948,    -1,   171,    -1,  1022,    -1,
     949,    -1,   950,    -1,    10,   172,    -1,    11,    -1,    10,
     951,   172,    -1,   952,    -1,   953,    -1,   952,   953,    -1,
     954,   955,   958,    -1,   185,    -1,   956,    -1,    -1,   956,
     957,    -1,   985,    -1,   968,    -1,   976,    -1,  1013,    -1,
     959,    -1,   960,    -1,    10,   186,    -1,    11,    -1,    10,
     961,   186,    -1,   962,    -1,   963,    -1,   962,   963,    -1,
     964,    -1,   965,    -1,   966,    -1,    79,    -1,    80,    -1,
      77,   967,    78,    -1,     5,    -1,   969,    -1,   970,    -1,
     971,    -1,    42,    -1,    41,     3,  1044,    -1,   973,    -1,
     974,    -1,   975,    -1,    50,    -1,    49,     3,  1044,    -1,
     977,    -1,   978,    -1,   979,    -1,    44,    -1,    43,     3,
    1044,    -1,   981,    -1,   982,    -1,   983,    -1,    52,    -1,
      51,     3,  1044,    -1,    37,  1044,     6,  1044,    -1,   986,
      -1,   987,    -1,   988,    -1,    46,    -1,    45,     3,  1044,
      -1,   990,    -1,   991,    -1,   992,    -1,    54,    -1,    53,
       3,  1044,    -1,   994,    -1,   995,    -1,   996,    -1,    48,
      -1,    47,     3,  1044,    -1,   998,    -1,   999,    -1,  1000,
      -1,    58,    -1,    57,     3,  1044,    -1,  1002,    -1,  1003,
      -1,  1004,    -1,    60,    -1,    59,     3,  1044,    -1,  1006,
      -1,  1007,    -1,  1008,    -1,    56,    -1,    55,     3,  1044,
      -1,    16,  1044,     6,  1044,    -1,    17,  1044,     6,  1044,
      -1,    18,  1044,     6,  1044,    -1,    19,  1044,     6,  1044,
      -1,    21,  1044,     6,  1044,    -1,    22,  1044,     6,  1044,
      -1,    23,  1044,     6,  1044,    -1,    24,  1044,     6,  1044,
      -1,    25,  1044,     6,  1044,    -1,    26,  1044,     6,  1044,
      -1,    27,  1044,     6,  1044,    -1,    28,  1044,     6,  1044,
      -1,    29,  1044,     6,  1044,    -1,    30,  1044,     6,  1044,
      -1,    31,  1044,     6,  1044,    -1,    32,  1044,     6,  1044,
      -1,    33,  1044,     6,  1044,    -1,    34,  1044,     6,  1044,
      -1,  1028,    -1,  1035,    -1,    -1,  1028,  1029,    -1,  1030,
    1031,  1034,    -1,   135,    -1,  1032,    -1,    -1,  1032,  1033,
      -1,  1041,    -1,  1040,    -1,    10,     6,   136,    -1,   117,
    1036,  1037,    -1,    40,  1044,     6,  1044,    -1,  1038,    -1,
    1039,    -1,    10,   118,    -1,    11,    -1,    10,     4,   118,
      -1,    38,  1044,     6,  1044,    -1,    39,  1044,     6,  1044,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1045,     8,    -1,    -1,  1045,  1046,    -1,   228,    -1,
     229,    -1,   230,    -1,   231,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   196,   198,   205,   215,   215,   217,   217,
     219,   221,   223,   232,   233,   236,   245,   245,   252,   254,
     268,   268,   270,   270,   272,   274,   276,   276,   279,   280,
     281,   282,   283,   285,   285,   293,   293,   295,   295,   297,
     303,   303,   311,   311,   313,   313,   315,   321,   321,   329,
     329,   331,   331,   333,   339,   339,   347,   347,   349,   349,
     351,   357,   357,   365,   365,   367,   367,   369,   380,   380,
     382,   396,   396,   398,   398,   400,   402,   404,   404,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   418,   420,
     435,   442,   442,   445,   450,   454,   463,   467,   472,   472,
     474,   476,   478,   478,   480,   485,   495,   501,   501,   504,
     509,   515,   515,   518,   520,   527,   527,   529,   529,   531,
     533,   536,   538,   545,   545,   547,   547,   549,   551,   556,
     558,   565,   565,   567,   567,   569,   571,   576,   578,   585,
     585,   587,   587,   589,   591,   596,   598,   605,   605,   607,
     607,   609,   611,   616,   618,   625,   625,   627,   627,   629,
     631,   636,   638,   645,   645,   647,   647,   649,   651,   656,
     658,   665,   675,   680,   686,   686,   688,   690,   692,   692,
     694,   699,   711,   717,   717,   720,   727,   732,   739,   739,
     743,   743,   745,   756,   756,   758,   758,   760,   762,   764,
     764,   767,   768,   769,   770,   771,   772,   775,   777,   784,
     784,   786,   786,   788,   790,   797,   799,   810,   812,   812,
     815,   821,   827,   829,   835,   837,   848,   850,   850,   853,
     859,   865,   867,   874,   876,   887,   889,   889,   892,   898,
     904,   906,   913,   915,   924,   925,   931,   933,   939,   941,
     948,   958,   963,   969,   969,   971,   973,   975,   975,   977,
     982,   994,  1000,  1000,  1003,  1010,  1015,  1021,  1021,  1025,
    1025,  1027,  1038,  1038,  1040,  1040,  1042,  1044,  1046,  1046,
    1049,  1050,  1051,  1052,  1053,  1054,  1057,  1059,  1066,  1066,
    1068,  1068,  1070,  1072,  1080,  1082,  1089,  1089,  1091,  1091,
    1093,  1095,  1100,  1102,  1109,  1109,  1111,  1111,  1113,  1115,
    1120,  1122,  1129,  1129,  1131,  1131,  1133,  1135,  1140,  1142,
    1149,  1149,  1151,  1151,  1153,  1155,  1162,  1164,  1171,  1181,
    1186,  1192,  1192,  1194,  1196,  1198,  1198,  1200,  1205,  1217,
    1223,  1223,  1226,  1233,  1238,  1245,  1245,  1248,  1248,  1250,
    1266,  1266,  1268,  1268,  1270,  1272,  1274,  1274,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1290,
    1292,  1299,  1299,  1301,  1301,  1303,  1305,  1313,  1315,  1322,
    1322,  1324,  1324,  1326,  1328,  1333,  1335,  1342,  1342,  1344,
    1344,  1346,  1348,  1353,  1355,  1362,  1362,  1364,  1364,  1366,
    1368,  1373,  1375,  1382,  1382,  1384,  1384,  1386,  1388,  1393,
    1395,  1402,  1412,  1417,  1423,  1423,  1425,  1427,  1429,  1429,
    1431,  1433,  1447,  1447,  1450,  1450,  1450,  1450,  1453,  1453,
    1455,  1455,  1457,  1459,  1468,  1469,  1472,  1474,  1485,  1487,
    1487,  1490,  1496,  1502,  1504,  1511,  1513,  1524,  1526,  1526,
    1529,  1535,  1541,  1543,  1550,  1552,  1563,  1565,  1565,  1568,
    1574,  1580,  1582,  1589,  1591,  1601,  1602,  1608,  1610,  1617,
    1619,  1626,  1636,  1641,  1647,  1647,  1649,  1651,  1653,  1653,
    1655,  1660,  1672,  1678,  1678,  1681,  1688,  1693,  1700,  1700,
    1703,  1703,  1705,  1713,  1719,  1719,  1722,  1729,  1735,  1741,
    1749,  1754,  1760,  1760,  1762,  1764,  1766,  1766,  1768,  1770,
    1779,  1781,  1781,  1783,  1783,  1783,  1785,  1795,  1805,  1825,
    1831,  1833,  1843,  1849,  1849,  1852,  1857,  1862,  1872,  1877,
    1883,  1883,  1885,  1887,  1889,  1889,  1891,  1896,  1906,  1912,
    1912,  1915,  1921,  1928,  1928,  1931,  1931,  1933,  1935,  1935,
    1937,  1937,  1939,  1941,  1949,  1949,  1951,  1957,  1957,  1965,
    1965,  1967,  1969,  1971,  1973,  1973,  1975,  1977,  1985,  1990,
    1996,  1996,  1998,  2000,  2002,  2002,  2004,  2015,  2024,  2024,
    2027,  2028,  2031,  2034,  2034,  2036,  2038,  2046,  2051,  2057,
    2057,  2059,  2061,  2063,  2063,  2065,  2076,  2085,  2085,  2088,
    2089,  2093,  2094,  2096,  2096,  2098,  2100,  2105,  2105,  2107,
    2112,  2112,  2114,  2116,  2118,  2120,  2120,  2129,  2131,  2138,
    2138,  2140,  2142,  2144,  2147,  2147,  2157,  2159,  2166,  2166,
    2168,  2170,  2172,  2175,  2175,  2184,  2186,  2193,  2193,  2195,
    2197,  2199,  2202,  2202,  2211,  2213,  2220,  2220,  2222,  2224,
    2226,  2229,  2229,  2238,  2240,  2247,  2247,  2249,  2251,  2253,
    2256,  2256,  2265,  2267,  2274,  2274,  2276,  2278,  2280,  2283,
    2283,  2292,  2294,  2301,  2301,  2303,  2305,  2307,  2310,  2310,
    2312,  2317,  2336,  2342,  2342,  2345,  2356,  2367,  2373,  2379,
    2385,  2391,  2397,  2404,  2404,  2406,  2406,  2408,  2410,  2410,
    2412,  2412,  2414,  2421,  2430,  2430,  2433,  2439,  2446,  2446,
    2448,  2448,  2450,  2452,  2461,  2461,  2463,  2474,  2482,  2488,
    2488,  2491,  2497,  2498,  2502,  2502,  2504,  2506,  2509,  2513,
    2513,  2515,  2523,  2523,  2531,  2531,  2533,  2535,  2537,  2539,
    2539,  2541,  2543,  2551,  2556,  2562,  2562,  2564,  2566,  2569,
    2569,  2571,  2580,  2590,  2590,  2593,  2594,  2597,  2600,  2600,
    2602,  2607,  2607,  2610,  2612,  2614,  2616,  2616,  2625,  2627,
    2634,  2634,  2636,  2638,  2640,  2642,  2642,  2651,  2653,  2660,
    2660,  2662,  2664,  2666,  2669,  2669,  2678,  2680,  2687,  2687,
    2689,  2691,  2693,  2696,  2696,  2705,  2707,  2714,  2714,  2716,
    2718,  2720,  2723,  2723,  2732,  2734,  2741,  2741,  2743,  2745,
    2747,  2750,  2750,  2759,  2761,  2768,  2768,  2770,  2772,  2774,
    2777,  2777,  2786,  2788,  2795,  2795,  2797,  2799,  2801,  2804,
    2804,  2806,  2812,  2831,  2838,  2838,  2841,  2852,  2863,  2869,
    2875,  2881,  2887,  2893,  2902,  2902,  2904,  2904,  2906,  2908,
    2908,  2910,  2910,  2912,  2917,  2927,  2927,  2930,  2935,  2942,
    2942,  2944,  2944,  2946,  2948,  2955,  2955,  2957,  2968,  2976,
    2982,  2982,  2985,  2991,  2992,  2996,  2996,  2998,  3000,  3003,
    3006,  3006,  3008,  3015,  3015,  3023,  3023,  3025,  3027,  3029,
    3031,  3031,  3033,  3036,  3044,  3049,  3055,  3055,  3057,  3059,
    3061,  3061,  3063,  3072,  3081,  3081,  3084,  3085,  3088,  3091,
    3091,  3093,  3098,  3098,  3100,  3102,  3104,  3106,  3106,  3115,
    3117,  3124,  3124,  3126,  3128,  3130,  3132,  3132,  3141,  3143,
    3150,  3150,  3152,  3154,  3156,  3159,  3159,  3168,  3170,  3177,
    3177,  3179,  3181,  3183,  3186,  3186,  3195,  3197,  3204,  3204,
    3206,  3208,  3210,  3213,  3213,  3222,  3224,  3231,  3231,  3233,
    3235,  3237,  3240,  3240,  3249,  3251,  3258,  3258,  3260,  3262,
    3264,  3267,  3267,  3276,  3278,  3285,  3285,  3287,  3289,  3291,
    3294,  3294,  3296,  3302,  3321,  3327,  3327,  3330,  3341,  3352,
    3358,  3364,  3370,  3376,  3382,  3389,  3389,  3391,  3391,  3393,
    3395,  3395,  3397,  3397,  3399,  3406,  3415,  3415,  3419,  3424,
    3432,  3432,  3434,  3434,  3436,  3438,  3445,  3445,  3447,  3458,
    3466,  3472,  3472,  3475,  3481,  3482,  3486,  3486,  3488,  3490,
    3492,  3496,  3496,  3498,  3503,  3512,  3517,  3523,  3523,  3525,
    3527,  3529,  3529,  3531,  3536,  3550,  3558,  3558,  3561,  3567,
    3573,  3579,  3587,  3597,  3602,  3608,  3608,  3610,  3612,  3614,
    3614,  3616,  3622,  3627,  3629,  3629,  3631,  3633,  3645,  3645,
    3647,  3652,  3661,  3666,  3672,  3672,  3674,  3676,  3678,  3678,
    3680,  3685,  3697,  3705,  3705,  3708,  3713,  3719,  3725,  3734,
    3739,  3745,  3745,  3747,  3749,  3751,  3751,  3753,  3759,  3764,
    3766,  3766,  3768,  3770,  3781,  3788,  3788,  3790,  3795,  3800,
    3807,  3807,  3809,  3814,  3819,  3826,  3826,  3828,  3833,  3838,
    3845,  3845,  3847,  3852,  3857,  3865,  3872,  3872,  3874,  3879,
    3884,  3891,  3891,  3893,  3898,  3903,  3910,  3910,  3912,  3917,
    3922,  3929,  3929,  3931,  3936,  3941,  3948,  3948,  3950,  3955,
    3960,  3967,  3967,  3969,  3974,  3980,  3986,  3995,  4001,  4015,
    4024,  4030,  4039,  4045,  4051,  4057,  4063,  4069,  4078,  4084,
    4093,  4098,  4104,  4131,  4136,  4138,  4138,  4140,  4142,  4151,
    4153,  4153,  4155,  4155,  4157,  4165,  4167,  4172,  4172,  4174,
    4174,  4176,  4199,  4207,  4221,  4222,  4226,  4227,  4228,  4230,
    4232,  4232,  4234,  4235,  4236,  4237
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
  "osrlEnding", "osrlBody", "headerElement", "osglFileHeader",
  "headerElementStart", "headerElementContent", "headerElementEmpty",
  "headerElementLaden", "headerElementBody", "headerElementList",
  "headerChild", "fileName", "fileNameContent", "fileNameEmpty",
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
     238,   239,   240,   241,   241,   242,   243,   243,   244,   245,
     246,   246,   247,   247,   248,   249,   250,   250,   251,   251,
     251,   251,   251,   252,   252,   253,   253,   254,   254,   255,
     256,   256,   257,   257,   258,   258,   259,   260,   260,   261,
     261,   262,   262,   263,   264,   264,   265,   265,   266,   266,
     267,   268,   268,   269,   269,   270,   270,   271,   272,   272,
     273,   274,   274,   275,   275,   276,   277,   278,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   280,   281,
     282,   283,   283,   284,   284,   284,   285,   285,   286,   286,
     287,   288,   289,   289,   290,   291,   292,   293,   293,   294,
     294,   295,   295,   296,   297,   298,   298,   299,   299,   300,
     301,   302,   303,   304,   304,   305,   305,   306,   307,   308,
     309,   310,   310,   311,   311,   312,   313,   314,   315,   316,
     316,   317,   317,   318,   319,   320,   321,   322,   322,   323,
     323,   324,   325,   326,   327,   328,   328,   329,   329,   330,
     331,   332,   333,   334,   334,   335,   335,   336,   337,   338,
     339,   340,   341,   341,   342,   342,   343,   344,   345,   345,
     346,   347,   348,   349,   349,   350,   350,   350,   351,   351,
     352,   352,   353,   354,   354,   355,   355,   356,   357,   358,
     358,   359,   359,   359,   359,   359,   359,   360,   361,   362,
     362,   363,   363,   364,   365,   366,   367,   368,   369,   369,
     370,   370,   371,   372,   373,   374,   375,   376,   376,   377,
     377,   378,   379,   380,   381,   382,   383,   383,   384,   384,
     385,   386,   387,   388,   389,   389,   390,   391,   392,   393,
     394,   395,   395,   396,   396,   397,   398,   399,   399,   400,
     401,   402,   403,   403,   404,   404,   404,   405,   405,   406,
     406,   407,   408,   408,   409,   409,   410,   411,   412,   412,
     413,   413,   413,   413,   413,   413,   414,   415,   416,   416,
     417,   417,   418,   419,   420,   421,   422,   422,   423,   423,
     424,   425,   426,   427,   428,   428,   429,   429,   430,   431,
     432,   433,   434,   434,   435,   435,   436,   437,   438,   439,
     440,   440,   441,   441,   442,   443,   444,   445,   446,   447,
     447,   448,   448,   449,   450,   451,   451,   452,   453,   454,
     455,   455,   456,   456,   456,   457,   457,   458,   458,   459,
     460,   460,   461,   461,   462,   463,   464,   464,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   466,
     467,   468,   468,   469,   469,   470,   471,   472,   473,   474,
     474,   475,   475,   476,   477,   478,   479,   480,   480,   481,
     481,   482,   483,   484,   485,   486,   486,   487,   487,   488,
     489,   490,   491,   492,   492,   493,   493,   494,   495,   496,
     497,   498,   499,   499,   500,   500,   501,   502,   503,   503,
     504,   505,   506,   506,   507,   507,   507,   507,   508,   508,
     509,   509,   510,   511,   512,   512,   513,   514,   515,   516,
     516,   517,   517,   518,   519,   520,   521,   522,   523,   523,
     524,   524,   525,   526,   527,   528,   529,   530,   530,   531,
     531,   532,   533,   534,   535,   536,   536,   537,   538,   539,
     540,   541,   542,   542,   543,   543,   544,   545,   546,   546,
     547,   548,   549,   550,   550,   551,   551,   551,   552,   552,
     553,   553,   554,   555,   556,   556,   557,   557,   557,   557,
     558,   558,   559,   559,   560,   561,   562,   562,   563,   564,
     565,   566,   566,   567,   567,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   575,   576,   576,   576,   577,   577,
     578,   578,   579,   580,   581,   581,   582,   583,   584,   585,
     585,   586,   586,   587,   587,   588,   588,   589,   590,   590,
     591,   591,   592,   593,   594,   594,   595,   596,   596,   597,
     597,   598,   599,   600,   601,   601,   602,   603,   604,   604,
     605,   605,   606,   607,   608,   608,   609,   610,   611,   611,
     612,   612,   613,   614,   614,   615,   616,   617,   617,   618,
     618,   619,   620,   621,   621,   622,   623,   624,   624,   625,
     625,   626,   626,   627,   627,   628,   629,   630,   630,   631,
     632,   632,   633,   634,   635,   636,   636,   637,   638,   639,
     639,   640,   641,   642,   643,   643,   644,   645,   646,   646,
     647,   648,   649,   650,   650,   651,   652,   653,   653,   654,
     655,   656,   657,   657,   658,   659,   660,   660,   661,   662,
     663,   664,   664,   665,   666,   667,   667,   668,   669,   670,
     671,   671,   672,   673,   674,   674,   675,   676,   677,   678,
     678,   679,   680,   681,   681,   682,   683,   684,   685,   685,
     686,   687,   688,   689,   689,   690,   690,   690,   690,   690,
     690,   690,   690,   691,   691,   692,   692,   693,   694,   694,
     695,   695,   696,   697,   698,   698,   699,   699,   700,   700,
     701,   701,   702,   703,   704,   704,   705,   706,   707,   708,
     708,   709,   709,   709,   710,   710,   711,   712,   713,   714,
     714,   715,   716,   716,   717,   717,   718,   719,   720,   721,
     721,   722,   723,   724,   724,   725,   725,   726,   727,   728,
     728,   729,   730,   731,   731,   732,   732,   733,   734,   734,
     735,   736,   736,   737,   738,   739,   740,   740,   741,   742,
     743,   743,   744,   745,   746,   747,   747,   748,   749,   750,
     750,   751,   752,   753,   754,   754,   755,   756,   757,   757,
     758,   759,   760,   761,   761,   762,   763,   764,   764,   765,
     766,   767,   768,   768,   769,   770,   771,   771,   772,   773,
     774,   775,   775,   776,   777,   778,   778,   779,   780,   781,
     782,   782,   783,   784,   785,   785,   786,   787,   788,   789,
     789,   790,   791,   792,   793,   793,   794,   794,   794,   794,
     794,   794,   794,   794,   795,   795,   796,   796,   797,   798,
     798,   799,   799,   800,   801,   802,   802,   803,   803,   804,
     804,   805,   805,   806,   807,   808,   808,   809,   810,   811,
     812,   812,   813,   813,   813,   814,   814,   815,   816,   817,
     818,   818,   819,   820,   820,   821,   821,   822,   823,   824,
     825,   825,   826,   827,   828,   828,   829,   829,   830,   831,
     832,   832,   833,   834,   835,   835,   836,   836,   837,   838,
     838,   839,   840,   840,   841,   842,   843,   844,   844,   845,
     846,   847,   847,   848,   849,   850,   851,   851,   852,   853,
     854,   854,   855,   856,   857,   858,   858,   859,   860,   861,
     861,   862,   863,   864,   865,   865,   866,   867,   868,   868,
     869,   870,   871,   872,   872,   873,   874,   875,   875,   876,
     877,   878,   879,   879,   880,   881,   882,   882,   883,   884,
     885,   886,   886,   887,   888,   889,   889,   890,   891,   892,
     893,   893,   894,   895,   896,   897,   897,   898,   898,   898,
     898,   898,   898,   898,   898,   899,   899,   900,   900,   901,
     902,   902,   903,   903,   904,   905,   906,   906,   907,   907,
     908,   908,   909,   909,   910,   911,   912,   912,   913,   914,
     915,   916,   916,   917,   917,   917,   918,   918,   919,   920,
     921,   922,   922,   923,   924,   925,   925,   926,   926,   927,
     928,   929,   929,   930,   931,   932,   933,   933,   934,   934,
     934,   934,   934,   935,   935,   936,   936,   937,   938,   939,
     939,   940,   941,   941,   942,   942,   943,   944,   945,   945,
     946,   947,   948,   948,   949,   949,   950,   951,   952,   952,
     953,   954,   955,   956,   956,   957,   957,   957,   957,   958,
     958,   959,   959,   960,   961,   962,   962,   963,   964,   964,
     965,   965,   966,   967,   968,   969,   969,   970,   971,   972,
     973,   973,   974,   975,   976,   977,   977,   978,   979,   980,
     981,   981,   982,   983,   984,   985,   986,   986,   987,   988,
     989,   990,   990,   991,   992,   993,   994,   994,   995,   996,
     997,   998,   998,   999,  1000,  1001,  1002,  1002,  1003,  1004,
    1005,  1006,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1027,  1028,  1028,  1029,  1030,  1031,
    1032,  1032,  1033,  1033,  1034,  1035,  1036,  1037,  1037,  1038,
    1038,  1039,  1040,  1041,  1042,  1042,  1043,  1043,  1043,  1044,
    1045,  1045,  1046,  1046,  1046,  1046
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     3,
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
       0,     5,     4,     0,    16,     6,     1,    19,    14,    68,
      17,     0,     7,     0,    13,     2,    12,    70,   190,     0,
       0,    23,    18,    20,    21,    16,    10,     3,     8,     9,
     192,   269,     0,     0,    74,    69,    71,    72,    22,     0,
      38,    37,     0,    45,    44,     0,    52,    51,     0,    59,
      58,     0,    66,    65,     0,    25,    26,    28,    34,    35,
      36,    29,    41,    42,    43,    30,    48,    49,    50,    31,
      55,    56,    57,    32,    62,    63,    64,    14,   271,   347,
       0,     0,   196,   191,   193,   194,    73,    89,   138,   146,
     114,   170,   130,   122,   154,   162,     0,    76,    77,    79,
       0,    80,     0,    81,     0,    82,     0,    83,     0,    84,
       0,    85,     0,    86,     0,    87,     0,     0,     0,     0,
       0,     0,    24,    27,    11,   349,   490,     0,     0,   275,
     270,   272,   273,   195,   243,   234,   216,   225,   249,   208,
       0,   198,   199,   201,     0,   202,   218,   203,   227,   204,
     236,   205,   244,   206,     0,    75,    78,  1200,     0,  1117,
       0,  1138,     0,    90,    91,    94,  1114,  1115,  1116,    93,
    1135,  1136,  1137,    95,     0,   118,   113,   115,   116,     0,
     126,   121,   123,   124,     0,   134,   129,   131,   132,     0,
     142,   137,   139,   140,     0,   150,   145,   147,   148,     0,
     158,   153,   155,   156,     0,   166,   161,   163,   164,  1200,
       0,   171,    39,    46,    53,    60,    67,   492,    15,   494,
       0,   353,   348,   350,   351,   274,   295,   287,   327,   319,
     311,   303,     0,   277,   278,   280,     0,   281,     0,   282,
       0,   283,     0,   284,     0,   285,     0,   197,   200,     0,
     212,   207,   209,   210,     0,   217,     0,   226,     0,   235,
       0,   245,     0,   250,     0,     0,  1200,  1200,     0,    99,
      88,    96,    97,    92,   120,   117,     0,   128,   125,     0,
     136,   133,     0,   144,   141,     0,   152,   149,     0,   160,
     157,     0,   168,   165,     0,     0,     0,   175,   169,   172,
     173,     0,   493,   352,   394,   402,   470,   386,   370,   378,
     410,   464,   455,   437,   446,     0,   355,   356,   358,     0,
     359,     0,   360,     0,   361,     0,   362,     0,   363,     0,
     364,   439,   365,   448,   366,   457,   367,   465,   368,     0,
     276,   279,     0,   291,   286,   288,   289,     0,   299,   294,
     296,   297,     0,   307,   302,   304,   305,     0,   315,   310,
     312,   313,     0,   323,   318,   320,   321,     0,   328,   214,
     211,     0,     0,   215,     0,  1143,   219,   221,   220,  1140,
    1141,  1142,     0,   224,   228,   230,   229,     0,   233,   237,
     239,   238,     0,   242,     0,   254,   248,   251,   252,  1200,
    1199,  1202,  1203,  1204,  1205,  1201,  1118,  1139,    98,   105,
       0,   101,   102,   107,   119,   127,   135,   143,   151,   159,
     167,  1200,   181,   174,     0,   177,   178,   183,     0,   503,
     491,   500,   501,  1200,  1200,  1200,  1200,   495,   498,   499,
     496,   497,   354,   357,     0,   374,   369,   371,   372,     0,
     382,   377,   379,   380,     0,   390,   385,   387,   388,     0,
     398,   393,   395,   396,     0,   406,   401,   403,   404,  1200,
       0,   411,     0,   438,     0,   447,     0,   456,     0,   466,
       0,   471,   293,   290,     0,   301,   298,     0,   309,   306,
       0,   317,   314,     0,  1194,  1195,   322,     0,   325,     0,
     332,   326,   329,   330,   213,     0,   223,  1200,     0,   232,
       0,   241,   247,     0,   260,   253,     0,   256,   257,   262,
    1169,   100,   103,     0,   106,  1164,   176,   179,     0,   182,
     502,   509,     0,  1068,   506,   511,     0,     0,     0,     0,
     376,   373,     0,   384,   381,     0,   392,   389,     0,   400,
     397,     0,   408,   405,     0,     0,     0,   415,   409,   412,
     413,     0,   436,   440,   442,   441,     0,   445,   449,   451,
     450,     0,   454,   458,   460,   459,     0,   463,     0,   475,
     469,   472,   473,   292,   300,   308,   316,   324,   338,   331,
       0,   334,   335,   340,   222,  1144,   231,   240,   246,   255,
     258,     0,   261,     0,   112,   104,     0,  1128,   108,   110,
     109,  1125,  1126,  1127,     0,   189,   180,     0,  1148,   184,
     187,   185,   186,  1145,  1146,  1147,   504,  1070,   507,   505,
       0,     0,   510,  1200,  1200,  1200,  1200,   375,   383,   391,
     399,   407,  1200,   421,   414,     0,   417,   418,   422,     0,
     444,     0,   453,     0,   462,   468,     0,   481,   474,     0,
     477,   478,   483,   333,   336,     0,   339,     0,   268,   259,
     263,   266,   264,   265,   111,  1200,   188,  1200,  1200,     0,
    1071,     0,   508,  1200,     0,     0,   512,   513,   514,   515,
    1156,  1161,  1167,  1172,  1170,   416,   419,     0,   443,   452,
     461,   467,   476,   479,     0,   482,     0,   346,   337,   341,
     344,   342,   343,   267,  1129,  1149,     0,     0,  1075,  1069,
    1072,  1073,   521,   545,     0,     0,  1200,  1200,     0,   431,
       0,  1107,   423,   420,   428,   429,   426,  1104,  1105,  1106,
     427,   425,   424,     0,   489,   480,   484,   487,   485,   486,
     345,  1200,  1074,  1081,     0,  1077,  1078,  1083,   547,   554,
       0,     0,   522,   523,   526,   525,   527,  1200,   518,   517,
     435,   434,   430,     0,   433,  1200,   488,  1168,  1076,  1079,
       0,  1082,   556,   729,   557,     0,   551,   546,   548,   549,
       0,   531,   520,   528,   529,   524,   516,   432,  1108,     0,
    1092,  1080,  1089,  1090,  1200,  1084,  1086,  1087,  1085,  1088,
     731,   880,   732,  1200,     0,   558,   553,   550,     0,   530,
     537,     0,   533,   534,   539,     0,  1100,  1101,  1091,     0,
    1094,  1095,  1097,  1098,  1099,     0,   882,  1031,   883,  1200,
       0,   733,     0,   564,   561,   555,   559,   560,   552,   532,
     535,     0,   538,  1103,     0,  1093,  1096,  1200,  1033,     0,
       0,  1200,     0,   884,     0,   739,   736,   730,   734,   735,
    1200,   566,     0,   583,     0,     0,   544,   536,   540,   542,
     541,  1102,  1159,   519,  1200,     0,  1034,     0,   890,   887,
     881,   885,   886,  1200,   741,     0,   758,     0,  1166,   562,
     585,   607,     0,  1200,     0,   567,   543,     0,     0,  1038,
    1032,  1035,  1036,  1200,   892,     0,   909,     0,  1163,   737,
     760,   829,     0,  1200,     0,   742,   609,   678,     0,     0,
     586,     0,     0,   571,   565,   568,   569,  1200,  1044,  1037,
       0,  1040,  1041,  1046,  1162,   888,   911,   980,     0,  1200,
       0,   893,   738,   766,   763,   759,   761,   762,     0,     0,
     746,   740,   743,   744,   563,   615,   612,   608,   610,   611,
       0,   590,   584,   587,   588,  1200,   570,   577,     0,   573,
     574,   578,  1165,  1039,  1042,     0,  1045,   889,   917,   914,
     910,   912,   913,     0,     0,   897,   891,   894,   895,   832,
     830,   834,   768,     0,   775,     0,  1200,   752,   745,     0,
     748,   749,   753,   681,   679,   683,   617,     0,   624,     0,
     589,   596,     0,   592,   593,   597,  1171,   572,   575,     0,
       0,  1056,  1043,  1053,  1054,  1047,  1050,  1051,  1048,  1049,
    1052,   983,   981,   985,   919,     0,   926,     0,  1200,   903,
     896,     0,   899,   900,   904,     0,   833,   764,   777,   784,
       0,  1200,     0,   769,  1160,   747,   750,     0,     0,   682,
     613,   626,   633,     0,     0,   618,   591,   594,     0,     0,
    1200,   579,   576,   580,   581,     0,  1064,  1065,  1055,     0,
    1058,  1059,  1061,  1062,  1063,     0,   984,   915,   928,   935,
       0,     0,   920,  1155,   898,   901,     0,     0,   847,   831,
     844,   845,  1200,     0,  1122,     0,  1133,   835,   843,   842,
    1119,  1120,  1121,   839,   841,  1130,  1131,  1132,   840,   838,
     837,   836,   786,   793,     0,     0,   778,     0,  1175,   772,
     767,   770,   771,     0,   754,   751,   755,   756,     0,   696,
     680,   693,   694,     0,  1153,   684,   692,   691,   688,   689,
     687,   690,  1150,  1151,  1152,   686,   685,   635,   642,     0,
       0,   627,  1175,   621,   616,   619,   620,     0,   604,   598,
     595,   601,   602,   599,   600,     0,     0,  1067,     0,  1057,
    1060,     0,   998,   982,   995,   996,     0,  1112,   986,   992,
    1109,  1110,  1111,   994,   993,   990,   991,   989,   987,   988,
     937,   944,     0,     0,   929,  1175,   923,   918,   921,   922,
       0,   905,   902,   906,   907,   868,   854,   846,     0,   849,
     851,   855,   850,   865,   870,     0,  1200,  1200,   795,   802,
       0,     0,   787,  1175,   781,   776,   779,   780,  1200,     0,
       0,   774,  1173,  1174,     0,   717,   695,   703,     0,   698,
     700,   704,   699,   714,   719,  1200,   644,   651,     0,     0,
     636,  1175,   630,   625,   628,   629,     0,   623,   606,   603,
       0,   582,  1200,  1066,  1005,  1019,   997,     0,  1000,  1002,
    1006,  1001,  1016,  1021,  1200,   946,   953,     0,     0,   938,
    1175,   932,   927,   930,   931,     0,   925,     0,   848,   852,
       0,   866,     0,   869,  1200,  1123,  1134,   804,   811,     0,
       0,   796,  1175,   790,   785,   788,   789,     0,   783,  1157,
    1200,     0,   773,  1178,  1176,  1180,   757,   697,   701,     0,
     715,     0,   718,  1154,   653,   660,     0,     0,   645,  1175,
     639,   634,   637,   638,     0,   632,   622,   605,  1124,   999,
    1003,     0,  1017,     0,  1020,  1113,   955,   962,     0,     0,
     947,  1175,   941,   936,   939,   940,     0,   934,   924,   908,
       0,   862,   856,   853,   859,   860,   857,   858,  1175,   877,
     867,   875,   876,   871,   874,   873,   872,  1158,   813,   820,
       0,     0,   805,  1175,   799,   794,   797,   798,     0,   792,
     782,     0,     0,  1190,  1185,  1187,  1188,     0,  1179,     0,
     711,   705,   702,   708,   709,   706,   707,  1175,   726,   716,
     724,   725,   720,   723,   722,   721,   662,   669,     0,     0,
     654,  1175,   648,   643,   646,   647,     0,   641,   631,     0,
    1013,  1007,  1004,  1010,  1011,  1008,  1009,  1175,  1028,  1018,
    1026,  1027,  1022,  1025,  1024,  1023,   964,   971,     0,     0,
     956,  1175,   950,   945,   948,   949,     0,   943,   933,  1196,
    1197,  1198,   861,     0,   864,     0,   879,   822,   765,     0,
       0,   814,  1175,   808,   803,   806,   807,     0,   801,   791,
    1200,     0,  1189,     0,  1177,  1200,  1200,  1181,  1183,  1182,
     710,     0,   713,     0,   728,   671,   614,     0,     0,   663,
    1175,   657,   652,   655,   656,     0,   650,   640,  1012,     0,
    1015,     0,  1030,   973,   916,     0,     0,   965,  1175,   959,
     954,   957,   958,     0,   952,   942,   863,   878,     0,   823,
    1175,   817,   812,   815,   816,     0,   810,   800,  1186,  1191,
       0,     0,     0,   712,   727,     0,   672,  1175,   666,   661,
     664,   665,     0,   659,   649,  1014,  1029,     0,   974,  1175,
     968,   963,   966,   967,     0,   961,   951,  1175,   826,   821,
     824,   825,     0,   819,   809,  1184,  1200,  1200,  1175,   675,
     670,   673,   674,     0,   668,   658,  1175,   977,   972,   975,
     976,     0,   970,   960,     0,   828,   818,  1192,  1193,     0,
     677,   667,     0,   979,   969,   827,   676,   978
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    10,    11,    22,    23,    24,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      18,    19,    35,    36,    37,    96,    97,    98,    99,   100,
     162,   163,   164,   270,   271,   272,   410,   411,   412,   413,
     523,   524,   608,   605,   101,   102,   176,   177,   178,   276,
     103,   104,   181,   182,   183,   279,   105,   106,   186,   187,
     188,   282,   107,   108,   191,   192,   193,   285,   109,   110,
     196,   197,   198,   288,   111,   112,   201,   202,   203,   291,
     113,   114,   206,   207,   208,   294,   115,   116,   210,   298,
     299,   300,   424,   425,   426,   427,   528,   529,   619,   616,
      31,    32,    83,    84,    85,   140,   141,   142,   143,   144,
     251,   252,   253,   371,   145,   146,   254,   255,   376,   373,
     505,   147,   148,   256,   257,   384,   383,   508,   149,   150,
     258,   259,   389,   388,   510,   151,   152,   260,   393,   513,
     153,   154,   262,   396,   397,   398,   516,   517,   518,   519,
     601,   602,   670,   669,    79,    80,   130,   131,   132,   232,
     233,   234,   235,   236,   344,   345,   346,   484,   237,   238,
     349,   350,   351,   487,   239,   240,   354,   355,   356,   490,
     241,   242,   359,   360,   361,   493,   243,   244,   364,   365,
     366,   497,   245,   246,   367,   501,   502,   503,   590,   591,
     592,   593,   665,   666,   709,   708,   126,   127,   222,   223,
     224,   315,   316,   317,   318,   319,   446,   447,   448,   542,
     320,   321,   451,   452,   453,   545,   322,   323,   456,   457,
     458,   548,   324,   325,   461,   462,   463,   551,   326,   327,
     466,   467,   468,   554,   328,   329,   470,   558,   559,   560,
     645,   646,   647,   648,   697,   732,   733,   734,   735,   773,
     774,   330,   331,   472,   473,   563,   562,   649,   332,   333,
     474,   475,   568,   567,   651,   334,   335,   476,   477,   573,
     572,   653,   336,   337,   478,   577,   656,   338,   339,   480,
     580,   581,   582,   659,   660,   661,   662,   704,   705,   746,
     745,   218,   219,   301,   302,   437,   430,   431,   432,   532,
     533,   534,   535,   631,   632,   686,   687,   688,   689,   682,
     723,   724,   761,   762,   763,   792,   793,   794,   821,   822,
     823,   824,   851,   852,   878,   877,   759,   760,   787,   788,
     789,   818,   783,   784,   814,   845,   846,   847,   872,   873,
     874,   904,   934,   935,   936,   978,   979,   980,   981,  1029,
    1081,  1082,   901,   902,   929,   972,   973,   974,  1022,  1023,
    1024,  1025,  1078,  1179,  1180,  1181,  1182,  1280,   927,   928,
     967,   968,   969,  1017,  1018,  1019,  1074,  1174,  1175,  1176,
    1276,  1072,  1073,  1170,  1273,  1274,  1275,  1354,  1168,  1169,
    1269,  1351,  1352,  1353,  1446,  1267,  1268,  1347,  1443,  1444,
    1445,  1525,  1345,  1346,  1439,  1522,  1523,  1524,  1572,  1437,
    1438,  1518,  1569,  1570,  1571,  1603,  1516,  1517,  1565,  1600,
    1601,  1602,  1619,   964,  1014,  1015,  1068,  1069,  1155,  1150,
    1151,  1152,  1258,  1259,  1260,  1261,  1339,  1421,  1422,  1423,
    1424,  1511,  1262,  1263,  1264,  1341,  1342,  1432,  1429,  1430,
    1431,  1513,   811,   812,   840,   867,   868,   869,   895,   896,
     897,   924,   961,   962,   963,  1009,  1010,  1011,  1012,  1067,
    1144,  1145,   921,   922,   955,   956,   957,  1003,  1004,  1005,
    1062,  1140,  1141,  1142,  1250,  1059,  1060,  1135,  1245,  1246,
    1247,  1327,  1133,  1134,  1241,  1324,  1325,  1326,  1408,  1239,
    1240,  1320,  1405,  1406,  1407,  1497,  1318,  1319,  1401,  1494,
    1495,  1496,  1555,  1399,  1400,  1490,  1552,  1553,  1554,  1592,
    1488,  1489,  1548,  1589,  1590,  1591,  1614,   952,  1000,  1001,
    1055,  1056,  1117,  1109,  1110,  1111,  1228,  1229,  1230,  1231,
    1310,  1382,  1383,  1384,  1385,  1483,  1232,  1233,  1234,  1312,
    1313,  1393,  1390,  1391,  1392,  1485,   837,   838,   862,   890,
     891,   892,   915,   916,   917,   950,   996,   997,   998,  1051,
    1052,  1053,  1054,  1106,  1221,  1222,   947,   948,   990,   991,
     992,  1045,  1046,  1047,  1101,  1217,  1218,  1219,  1305,  1099,
    1100,  1213,  1302,  1303,  1304,  1376,  1211,  1212,  1298,  1373,
    1374,  1375,  1476,  1296,  1297,  1369,  1473,  1474,  1475,  1543,
    1367,  1368,  1469,  1540,  1541,  1542,  1584,  1467,  1468,  1536,
    1581,  1582,  1583,  1611,  1534,  1535,  1577,  1608,  1609,  1610,
    1622,   987,  1042,  1043,  1095,  1096,  1198,  1193,  1194,  1195,
    1287,  1288,  1289,  1290,  1361,  1451,  1452,  1453,  1454,  1529,
    1291,  1292,  1293,  1363,  1364,  1462,  1459,  1460,  1461,  1531,
     859,   860,   885,   910,   911,   912,   940,   941,   942,   943,
     985,   986,  1035,  1032,  1033,  1034,  1089,  1090,  1091,  1092,
    1093,  1094,  1188,   629,   630,   679,   719,   720,   721,   754,
     755,   756,   757,   780,   781,   805,   801,   802,   803,   829,
     830,   831,   832,   833,   834,   854,   736,   737,   738,   739,
    1199,  1200,  1201,  1202,   165,   166,   167,   168,  1119,  1120,
    1121,  1122,  1083,   610,   611,   612,   613,  1124,  1125,  1126,
    1127,   169,   170,   171,   172,   378,   379,   380,   381,   622,
     623,   624,   625,  1161,  1162,  1163,  1164,   951,   438,  1063,
    1130,   809,   925,   439,   863,   841,   211,   886,   815,   440,
     680,   173,   471,   905,   441,  1251,  1252,  1334,  1335,  1417,
    1418,  1507,  1504,  1253,  1331,  1414,  1415,  1416,  1508,  1509,
     498,  1484,   264,   265,   405
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1339
static const yytype_int16 yypact[] =
{
      71, -1339, -1339,    60,     3,    50, -1339, -1339,    91,   105,
   -1339,    78, -1339,   184, -1339, -1339, -1339, -1339,    43,   200,
     581, -1339, -1339, -1339, -1339,     3, -1339, -1339, -1339, -1339,
   -1339,    95,   218,   -26, -1339, -1339, -1339, -1339, -1339,   212,
   -1339, -1339,   249, -1339, -1339,   251, -1339, -1339,   261, -1339,
   -1339,   273, -1339, -1339,   157,   634, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,    91, -1339,   221,
     228,   -17, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339,   232,   194, -1339, -1339,
     436, -1339,   272, -1339,   309, -1339,   327, -1339,   350, -1339,
     365, -1339,   390, -1339,   393, -1339,   270,   244,   238,   265,
     268,   282, -1339, -1339, -1339, -1339,   312,   398,   102, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     313,   148, -1339, -1339,   400, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339,   387, -1339,   270, -1339, -1339, -1339,   388, -1339,
     403, -1339,   426,   436, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,    28, -1339, -1339, -1339, -1339,    13,
   -1339, -1339, -1339, -1339,    30, -1339, -1339, -1339, -1339,    33,
   -1339, -1339, -1339, -1339,    32, -1339, -1339, -1339, -1339,    16,
   -1339, -1339, -1339, -1339,     6, -1339, -1339, -1339, -1339, -1339,
     428, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
      82, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339,   351,   -36, -1339, -1339,   438, -1339,   440, -1339,
     445, -1339,   477, -1339,   482, -1339,   270, -1339, -1339,     8,
   -1339, -1339, -1339, -1339,   422,   192,   424,   192,   431,   192,
     447, -1339,   485, -1339,   458,    15, -1339, -1339,   -81, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339,   319, -1339, -1339,   293,
   -1339, -1339,   299, -1339, -1339,   330, -1339, -1339,   329, -1339,
   -1339,   316, -1339, -1339,   318,   532,   -63, -1339, -1339, -1339,
   -1339,   487,   118, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   466,   119, -1339, -1339,   493,
   -1339,   495, -1339,   497, -1339,   499, -1339,   501, -1339,   545,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   387, -1339,   270,
   -1339, -1339,    41, -1339, -1339, -1339, -1339,    40, -1339, -1339,
   -1339, -1339,     1, -1339, -1339, -1339, -1339,     5, -1339, -1339,
   -1339, -1339,    23, -1339, -1339, -1339, -1339,   504, -1339, -1339,
   -1339,   361,   516, -1339,   564, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339,   516, -1339, -1339, -1339, -1339,   516, -1339, -1339,
   -1339, -1339,   567, -1339,   -21, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     437,   414, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,   449,   448, -1339, -1339,   -22, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,    31, -1339, -1339, -1339, -1339,    11,
   -1339, -1339, -1339, -1339,    35, -1339, -1339, -1339, -1339,    48,
   -1339, -1339, -1339, -1339,    36, -1339, -1339, -1339, -1339, -1339,
     514, -1339,   641,   192,   653,   192,   657,   192,   669, -1339,
     519, -1339, -1339, -1339,   512, -1339, -1339,   563, -1339, -1339,
     465, -1339, -1339,   503, -1339, -1339, -1339,   529, -1339,     2,
   -1339, -1339, -1339, -1339, -1339,   587, -1339, -1339,   604, -1339,
     601, -1339, -1339,   614, -1339, -1339,   566,   585, -1339, -1339,
   -1339, -1339, -1339,   521,   266, -1339, -1339, -1339,   523,   417,
   -1339, -1339,   663,   -27, -1339, -1339,   743,   744,   745,   746,
   -1339, -1339,   568, -1339, -1339,   569, -1339, -1339,   579, -1339,
   -1339,   652, -1339, -1339,   615,   751,   -44, -1339, -1339, -1339,
   -1339,   516, -1339, -1339, -1339, -1339,   516, -1339, -1339, -1339,
   -1339,   516, -1339, -1339, -1339, -1339,   752, -1339,    99, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     594,   598, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   525,   417,   570, -1339, -1339,   760, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,   600, -1339, -1339,   762, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     738,   759,    63, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   571,   574, -1339, -1339,   556,
   -1339,   557, -1339,   560, -1339, -1339,   575, -1339, -1339,   610,
     617, -1339, -1339, -1339, -1339,   533,   417,   613, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   535,
   -1339,   591, -1339, -1339,   776,   778, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,    75, -1339, -1339,
   -1339, -1339, -1339, -1339,   538,   417,   619, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339,   780,  -105, -1339, -1339,
   -1339, -1339, -1339,   631,   436,   781, -1339, -1339,    20, -1339,
     785, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,   625, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,   618,   606, -1339, -1339, -1339,   572,
     541,   543,   436, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,   595, -1339, -1339, -1339, -1339, -1339, -1339,
     550,   401, -1339,   637,   764,    34, -1339, -1339, -1339, -1339,
      84, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,    -7,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   671,   771, -1339,   552, -1339, -1339, -1339,   646, -1339,
   -1339,   611,   621, -1339, -1339,   796, -1339, -1339, -1339,   620,
     237, -1339, -1339, -1339, -1339,   797, -1339,   633,   783, -1339,
     554, -1339,   798,   593, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   559,   442, -1339,   730, -1339, -1339, -1339, -1339,   623,
     782, -1339,   561, -1339,   807,   602, -1339, -1339, -1339, -1339,
   -1339, -1339,   596,   605,   784,   622, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   565, -1339,   809,   683, -1339,
   -1339, -1339, -1339, -1339, -1339,   660,   700,   800, -1339, -1339,
   -1339,   702,   784, -1339,   576, -1339, -1339,   819,    29, -1339,
   -1339, -1339, -1339, -1339, -1339,   698,   706,   812, -1339, -1339,
   -1339, -1339,   583, -1339,   588, -1339, -1339, -1339,   590,   592,
   -1339,   823,   115, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     662,   664, -1339, -1339, -1339, -1339, -1339, -1339,   597, -1339,
     599, -1339,   667,   715, -1339, -1339, -1339, -1339,   829,  -104,
   -1339, -1339, -1339, -1339,   674,   719, -1339, -1339, -1339, -1339,
     306, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   627,   629,
   -1339, -1339, -1339, -1339, -1339,   603,   308,   678,   721, -1339,
   -1339, -1339, -1339,   836,    55, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,   722,   741,   825, -1339, -1339, -1339,   636,
     692, -1339, -1339, -1339, -1339, -1339, -1339,   726,   748,   825,
   -1339, -1339,   638,   640, -1339, -1339, -1339, -1339, -1339,   231,
      -1, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   734,   750,   825, -1339, -1339,
   -1339,   723,   724, -1339, -1339,   612,   537, -1339, -1339,   753,
     825, -1339,   616, -1339, -1339, -1339, -1339,   242,   624,   573,
   -1339, -1339,   755,   825,   626, -1339, -1339, -1339,    45,   516,
   -1339, -1339, -1339, -1339, -1339,   854, -1339, -1339, -1339,   696,
     317, -1339, -1339, -1339, -1339,   628,   369, -1339, -1339,   756,
     825,   630, -1339, -1339, -1339, -1339,   336,    -9, -1339, -1339,
   -1339, -1339, -1339,   862, -1339,   863, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,   765,   825,   632, -1339,   861,   757, -1339,
   -1339, -1339, -1339,   516, -1339, -1339, -1339, -1339,   -87, -1339,
   -1339, -1339, -1339,   866, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   767,   825,
     635, -1339,   757, -1339, -1339, -1339, -1339,     0, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   650,   867, -1339,   799, -1339,
   -1339,   -24, -1339, -1339, -1339, -1339,   872, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   773,   825,   639, -1339,   757, -1339, -1339, -1339, -1339,
     516, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   714,   728,
   -1339, -1339,   742, -1339, -1339,   874, -1339, -1339, -1339,   732,
     825,   643, -1339,   757, -1339, -1339, -1339, -1339, -1339,   842,
     766, -1339,   749, -1339,   729, -1339, -1339, -1339,   735,   666,
   -1339, -1339,   754, -1339, -1339, -1339, -1339,   739,   825,   645,
   -1339,   757, -1339, -1339, -1339, -1339,   769, -1339, -1339, -1339,
     668, -1339, -1339, -1339, -1339, -1339, -1339,   737,   768, -1339,
   -1339,   758, -1339, -1339, -1339, -1339,   747,   825,   647, -1339,
     757, -1339, -1339, -1339, -1339,   772, -1339,   774, -1339, -1339,
     294, -1339,   649,   230, -1339, -1339, -1339, -1339,   704,   825,
     672, -1339,   757, -1339, -1339, -1339, -1339,   788, -1339, -1339,
   -1339,   675, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   347,
   -1339,   677,   230, -1339, -1339,   705,   825,   679, -1339,   757,
   -1339, -1339, -1339, -1339,   801, -1339, -1339, -1339, -1339, -1339,
   -1339,   353, -1339,   681,   230, -1339, -1339,   709,   825,   685,
   -1339,   757, -1339, -1339, -1339, -1339,   802, -1339, -1339, -1339,
      37, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   757, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   703,
     825,   687, -1339,   757, -1339, -1339, -1339, -1339,   803, -1339,
   -1339,   898,    44, -1339, -1339, -1339, -1339,   895,   661,    18,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   757, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   707,   825,   695,
   -1339,   757, -1339, -1339, -1339, -1339,   804, -1339, -1339,    59,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   757, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   708,   825,   697,
   -1339,   757, -1339, -1339, -1339, -1339,   805, -1339, -1339, -1339,
   -1339, -1339, -1339,   761, -1339,   786, -1339, -1339, -1339,   825,
     701, -1339,   757, -1339, -1339, -1339, -1339,   814, -1339, -1339,
   -1339,   791, -1339,   910, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   699, -1339,   787, -1339, -1339, -1339,   825,   725, -1339,
     757, -1339, -1339, -1339, -1339,   816, -1339, -1339, -1339,   806,
   -1339,   789, -1339, -1339, -1339,   825,   727, -1339,   757, -1339,
   -1339, -1339, -1339,   818, -1339, -1339, -1339, -1339,   731, -1339,
     757, -1339, -1339, -1339, -1339,   779, -1339, -1339, -1339, -1339,
     790,   917,   922, -1339, -1339,   733, -1339,   757, -1339, -1339,
   -1339, -1339,   792, -1339, -1339, -1339, -1339,   736, -1339,   757,
   -1339, -1339, -1339, -1339,   793, -1339, -1339,   757, -1339, -1339,
   -1339, -1339,   740, -1339, -1339, -1339, -1339, -1339,   757, -1339,
   -1339, -1339, -1339,   763, -1339, -1339,   757, -1339, -1339, -1339,
   -1339,   770, -1339, -1339,   775, -1339, -1339, -1339, -1339,   777,
   -1339, -1339,   794, -1339, -1339, -1339, -1339, -1339
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   853, -1339,
     906, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   878,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   838, -1339, -1339,
   -1339, -1339,   795, -1339, -1339, -1339, -1339, -1339,   526, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,   511, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   808, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,   421, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   711, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     348, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,   644, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339,   295, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339,   280, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   412, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,   185, -1339, -1339, -1339, -1339, -1339,
     126, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   -29, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
     -72, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,  -307, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339,  -309, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,   -56, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,  -274, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,  -276, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   -93, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339,  -327, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,  -329, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,    22, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,  -125, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   211, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,   137, -1339, -1339, -1339, -1339,  -770, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339,  -150, -1339, -1339, -1339,  -965, -1339,
   -1339, -1339, -1059,  -528, -1339, -1339, -1339, -1339, -1339, -1339,
   -1339,  -691, -1339, -1339, -1339,  -243, -1339, -1339, -1339,  -597,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339,  -128, -1339,  -998,
    -932,   -16,   -85, -1339, -1339, -1339,  -126, -1339, -1339, -1339,
   -1339,  -665, -1339,  -871, -1339, -1085, -1339, -1339, -1339, -1339,
   -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339, -1339,
    -369, -1338,  -209, -1339, -1339
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     295,   621,   261,   506,  1278,   673,   741,   488,  1146,   491,
     292,   806,   369,   509,   386,   543,   391,   277,   511,  1183,
     289,  1075,  1479,   400,  1480,  1481,   770,   771,   263,   494,
     495,   930,   274,   765,   280,   540,   286,   283,   816,   546,
     552,  1479,    86,  1480,  1481,   482,   485,  1223,  1501,  1102,
    1255,  1007,   549,   133,   530,  1177,  1178,   406,   407,   766,
       6,   408,  1136,  1479,    12,  1480,  1481,   752,     7,   712,
     825,   765,   826,   827,   672,  1171,  1085,  1256,  1086,  1087,
     753,  1512,  1080,     1,     2,   728,   729,  1277,    20,    21,
     606,   607,   134,   226,   135,   227,   136,   766,   137,   683,
     422,  1284,  1214,   423,  1157,   377,    14,   385,   749,   390,
     409,  1530,    30,  1285,  1008,    87,   730,   731,   158,   159,
     368,    88,   160,   161,   684,    89,   685,    90,  1225,   228,
    1306,  1204,   374,   375,  1257,   433,  1242,  1165,   711,    91,
    1286,   434,   514,   229,   627,   515,  1226,   435,   138,    92,
     550,    93,   436,   643,   531,  1227,   303,    94,  1328,   531,
     644,   880,  1502,   230,  1209,   588,    78,  1088,   589,   231,
     486,  1270,    17,   483,   225,    95,   553,   748,   139,   828,
    1049,   284,   275,   304,   287,  1528,  1355,   479,   817,  1050,
     520,   278,   650,  1482,    25,    26,   938,   652,  1166,   939,
     290,   544,   654,   496,   370,   492,   281,   489,   293,   547,
      33,    34,   525,   481,  1299,  1377,  1036,   117,   772,   541,
     304,   305,  1279,   122,   536,   537,   538,   539,    81,    82,
     565,   226,   570,   227,   575,   158,   159,  1409,   128,   129,
    1510,  1079,  1321,   401,   402,   403,   404,   306,  1061,   374,
     375,  1386,  1143,   808,   118,   307,   119,   134,   305,   135,
     555,   136,   657,   137,  1447,   658,   120,   228,  1080,   308,
    1348,   309,   819,   158,   159,   820,   606,   607,   121,  1080,
    1425,   229,   174,   175,   306,   310,  1477,   606,   607,   617,
     618,   311,   307,   312,   125,   313,   209,   314,   595,  1370,
     155,   230,  1455,  1486,  1380,  1381,   308,   231,   309,   158,
     159,   606,   607,   138,   825,  1396,   826,   827,  1498,   179,
     180,  1402,   310,   564,   213,   569,   212,   574,   311,   804,
     312,  1080,   313,   976,   314,    87,   977,   184,   185,   606,
     607,    88,  1514,   139,  1435,    89,  1220,    90,  1440,   730,
     731,   158,   159,   606,   607,   214,  1526,  1419,  1420,    91,
     189,   190,   215,  1449,  1450,  1128,  1465,   617,   618,    92,
    1470,    93,  1532,  1080,   609,   194,   195,    94,  1159,   620,
     216,   606,   607,   247,  1080,   949,  1544,   217,  1112,  1039,
    1080,   266,   606,   607,  1085,    95,  1086,  1087,   606,   607,
     199,   200,  1491,   204,   205,  1206,   267,  1556,   220,   221,
     249,   250,   158,   159,   606,   607,   160,   161,  1196,  1197,
    1113,  1114,   804,   340,   690,   691,   692,   693,   617,   618,
     158,   159,   372,   694,   382,  1573,   268,   269,   296,   297,
    1519,   387,   730,   731,   158,   159,   606,   607,   342,   343,
     347,   348,   671,  1585,   742,   352,   353,   392,  1038,  1129,
     158,   159,   606,   607,   399,  1593,   714,   157,   715,   716,
    1537,   415,  1160,   414,   725,   416,   617,   618,   417,   158,
     159,   418,  1604,   160,   161,   158,   159,   357,   358,   160,
     161,  1549,   362,   363,  1612,   394,   395,   428,   429,  1207,
     419,  1084,  1615,   444,   445,   449,   450,   454,   455,   459,
     460,   464,   465,  1620,   499,   500,   710,   768,   769,  1566,
     420,  1623,   494,   495,   556,   557,  1020,  1021,  1123,   578,
     579,   603,   604,   614,   615,   667,   668,  1578,   421,  1147,
     442,  1158,   777,   706,   707,   717,   718,   740,   743,   744,
    1184,   785,   786,   790,   791,   747,  1112,   504,   796,   923,
     799,   800,   843,   844,   865,   866,   798,   507,  1205,   875,
     876,   888,   889,   512,   764,   908,   909,   469,  1224,   521,
     158,   159,   606,   607,   160,   161,   932,   933,  1113,  1114,
    1115,  1116,  1112,   953,   954,   835,   617,   618,   959,   960,
     965,   966,   970,   971,   842,   409,   903,   988,   989,   994,
     995,   422,   764,  1030,  1031,   526,   158,   159,   606,   607,
     160,   161,  1107,  1108,  1113,  1114,  1138,  1139,  1153,  1154,
     864,   807,   617,   618,  1148,  1149,  1172,  1173,  1191,  1192,
    1215,  1216,  1243,  1244,   583,  1271,  1272,    38,   882,  1300,
    1301,   561,   887,  1322,  1323,  1349,  1350,  1371,  1372,  1388,
    1389,   898,    39,   566,    40,    41,    42,   571,    43,    44,
      45,   585,    46,    47,    48,   907,    49,    50,    51,   576,
      52,    53,  1403,  1404,   918,  1412,  1413,  1427,  1428,  1441,
    1442,  1457,  1458,   584,   931,  1471,  1472,  1492,  1493,  1505,
    1506,   594,   879,   586,   944,  1520,  1521,  1538,  1539,   587,
    1185,  1550,  1551,   597,   958,    39,  1395,    40,    41,    42,
     596,    43,    44,    45,   598,    46,    47,    48,   982,    49,
      50,    51,   599,    52,    53,  1567,  1568,  1579,  1580,   626,
     993,  1587,  1588,  1598,  1599,  1434,  1606,  1607,   514,   633,
     634,   635,   636,   639,   640,   641,   637,   642,   655,   638,
     663,   588,   674,   675,   676,   677,  1026,  1464,   678,   681,
     698,   643,   700,   699,  1254,   695,   702,   713,   722,   726,
     657,   727,  1387,   750,   758,   701,   751,   767,   775,   776,
     778,   753,   813,   797,   810,   782,   839,  1064,   836,   849,
     848,   853,   858,   857,   870,   883,   855,   861,   881,   884,
     871,  1426,   820,   893,   906,   913,   914,   903,   919,   894,
     899,   920,   923,   926,   900,   937,   945,   946,   949,   975,
     999,   938,   983,  1456,  1002,  1006,  1037,  1013,  1016,  1103,
    1044,  1041,  1048,  1061,  1057,  1027,  1058,  1007,  1070,  1049,
     977,  1307,  1137,  1071,  1065,  1098,  1097,  1104,  1076,  1187,
    1132,  1021,  1167,  1210,  1189,  1236,  1237,  1248,  1238,  1265,
    1266,  1186,  1281,  1282,  1249,  1294,  1295,  1283,  1308,  1225,
    1314,  1317,  1330,  1226,  1333,  1336,  1332,  1257,  1344,  1356,
    1357,  1255,  1378,  1284,  1410,  1285,  1366,  1398,  1436,  1337,
    1379,  1359,  1466,  1235,  1500,  1503,  1118,  1448,  1478,  1559,
    1487,  1499,  1527,  1545,  1515,  1533,  1560,  1546,  1557,  1156,
    1574,  1563,  1586,  1596,  1547,  1564,  1595,  1576,  1597,  1594,
     124,    77,  1575,   123,  1616,   156,   527,   522,   600,   664,
     703,   696,  1605,  1613,   341,   628,  1203,   795,   850,   248,
    1028,  1077,  1338,  1340,  1066,  1309,  1311,  1621,   273,  1105,
     443,  1360,  1362,   984,  1624,  1190,   779,   856,  1208,     0,
    1040,  1131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1625,     0,  1626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1627,     0,     0,     0,     0,     0,     0,     0,
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
     209,   529,   152,   372,     4,   602,   697,     6,  1067,     4,
       4,   781,     4,   382,   257,     4,   259,     4,   387,  1078,
       4,  1019,     4,     8,     6,     7,     6,     7,   154,     6,
       7,   902,     4,   724,     4,     4,     4,     4,     4,     4,
       4,     4,    68,     6,     7,     4,     6,  1106,     4,  1047,
     137,   155,     4,    70,    76,    10,    11,   266,   267,   724,
       0,   142,  1060,     4,    14,     6,     7,   172,    65,   666,
      77,   762,    79,    80,   602,  1073,    77,   164,    79,    80,
     185,  1419,    37,    12,    13,    10,    11,  1172,    10,    11,
      45,    46,   109,   129,   111,   131,   113,   762,   115,    36,
     163,   125,  1100,   166,  1069,   255,    15,   257,   705,   259,
     191,  1449,    69,   137,   218,   141,    41,    42,    43,    44,
     246,   147,    47,    48,    61,   151,    63,   153,   137,   165,
    1215,  1096,    57,    58,   221,    17,  1134,  1069,   666,   165,
     164,    23,   163,   179,   171,   166,   155,    29,   165,   175,
     102,   177,    34,   197,   181,   164,    74,   183,  1243,   181,
     204,   852,   118,   199,  1096,   163,    71,   168,   166,   205,
     130,  1169,    67,   132,    72,   201,   140,   705,   195,   186,
     125,   148,   154,   101,   152,   126,  1271,   337,   154,   134,
     399,   178,   561,   156,    10,    11,   167,   566,  1069,   170,
     184,   190,   571,   180,   196,   200,   176,   206,   202,   174,
      10,    11,   421,   339,  1212,  1300,   986,     5,   198,   188,
     101,   139,   222,    66,   433,   434,   435,   436,    10,    11,
     473,   129,   475,   131,   477,    43,    44,  1322,    10,    11,
     222,    10,  1240,   228,   229,   230,   231,   165,    18,    57,
      58,  1310,    10,   781,     5,   173,     5,   109,   139,   111,
     469,   113,   163,   115,  1349,   166,     5,   165,    37,   187,
    1268,   189,   188,    43,    44,   191,    45,    46,     5,    37,
    1339,   179,    10,    11,   165,   203,  1371,    45,    46,    59,
      60,   209,   173,   211,    73,   213,    26,   215,   507,  1297,
      68,   199,  1361,  1388,    10,    11,   187,   205,   189,    43,
      44,    45,    46,   165,    77,  1313,    79,    80,  1403,    10,
      11,  1319,   203,   473,    86,   475,    82,   477,   209,    21,
     211,    37,   213,   218,   215,   141,   221,    10,    11,    45,
      46,   147,  1427,   195,  1342,   151,    10,   153,  1346,    41,
      42,    43,    44,    45,    46,    90,  1441,    10,    11,   165,
      10,    11,    94,    10,    11,  1056,  1364,    59,    60,   175,
    1368,   177,  1457,    37,   524,    10,    11,   183,  1069,   529,
      98,    45,    46,    70,    37,    16,  1471,    75,    19,   986,
      37,     3,    45,    46,    77,   201,    79,    80,    45,    46,
      10,    11,  1400,    10,    11,  1096,     3,  1492,    10,    11,
      10,    11,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    21,    72,   633,   634,   635,   636,    59,    60,
      43,    44,    10,   642,    10,  1520,    10,    11,    10,    11,
    1438,    10,    41,    42,    43,    44,    45,    46,    10,    11,
      10,    11,   602,  1538,   697,    10,    11,    10,   986,  1056,
      43,    44,    45,    46,     6,  1550,   675,    31,   677,   678,
    1468,   178,  1069,   154,   683,   176,    59,    60,   148,    43,
      44,   152,  1567,    47,    48,    43,    44,    10,    11,    47,
      48,  1489,    10,    11,  1579,    10,    11,    10,    11,  1096,
     184,  1029,  1587,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,  1598,    10,    11,   666,   726,   727,  1517,
     202,  1606,     6,     7,    10,    11,   220,   221,  1056,    10,
      11,    10,    11,    10,    11,    10,    11,  1535,     6,  1067,
      74,  1069,   751,    10,    11,    10,    11,   697,    10,    11,
    1078,    10,    11,    10,    11,   705,    19,   196,   767,    22,
      10,    11,    10,    11,    10,    11,   775,     3,  1096,    10,
      11,    10,    11,     6,   724,    10,    11,    32,  1106,   142,
      43,    44,    45,    46,    47,    48,    10,    11,    51,    52,
      53,    54,    19,    10,    11,   804,    59,    60,    10,    11,
      10,    11,    10,    11,   813,   191,    33,    10,    11,    10,
      11,   163,   762,    10,    11,   166,    43,    44,    45,    46,
      47,    48,    10,    11,    51,    52,    10,    11,    55,    56,
     839,   781,    59,    60,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   132,    10,    11,    66,   857,    10,
      11,    10,   861,    10,    11,    10,    11,    10,    11,    10,
      11,   870,    81,    10,    83,    84,    85,    10,    87,    88,
      89,   206,    91,    92,    93,   884,    95,    96,    97,    10,
      99,   100,    10,    11,   893,    10,    11,    10,    11,    10,
      11,    10,    11,   130,   903,    10,    11,    10,    11,    38,
      39,   114,   852,   200,   913,    10,    11,    10,    11,   180,
    1079,    10,    11,   112,   923,    81,  1313,    83,    84,    85,
     116,    87,    88,    89,   110,    91,    92,    93,   937,    95,
      96,    97,   166,    99,   100,    10,    11,    10,    11,    76,
     949,    10,    11,    10,    11,  1342,    10,    11,   163,     6,
       6,     6,     6,   174,   102,   140,   188,     6,     6,   190,
     166,   163,   192,     3,   164,     3,   975,  1364,    30,    10,
     214,   197,   212,   216,  1143,   204,   166,   164,   187,     3,
     163,     3,  1310,   164,   153,   210,     6,     6,     3,   164,
     172,   185,    28,   198,   157,   223,    25,  1006,   127,   188,
     154,     5,   169,     6,     6,   182,   186,    24,    78,    27,
     217,  1339,   191,     6,   192,     6,   133,    33,   158,   217,
     224,   121,    22,   121,   219,     6,   128,   121,    16,     6,
     163,   167,   170,  1361,   119,     6,   986,   163,   119,  1048,
     119,   163,     6,    18,   122,   218,   105,   155,   122,   125,
     221,  1220,  1061,   105,   218,   105,   122,   134,   220,     5,
     107,   221,   107,   107,   168,     3,     3,     6,   103,     3,
     103,  1080,   222,     6,   117,     3,   103,    78,   164,   137,
       6,   149,    40,   155,   135,   156,   120,   221,   149,   120,
     222,   137,   120,   125,   106,   137,   149,   193,   193,   164,
     126,   164,   193,  1112,     6,    10,  1056,   106,   106,   118,
     207,   108,   108,   108,   207,   207,     6,   156,   104,  1069,
     104,   222,   104,     6,   138,   138,   136,   138,     6,   150,
      77,    25,   126,    55,   194,    97,   425,   411,   517,   591,
     660,   646,   150,   150,   233,   533,  1096,   762,   822,   141,
     979,  1023,  1259,  1262,  1010,  1229,  1232,   194,   163,  1052,
     316,  1288,  1291,   941,   194,  1090,   755,   830,  1096,    -1,
     986,  1056,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    12,    13,   233,   234,   235,     0,    65,   242,   243,
     244,   245,    14,   236,    15,   240,   241,    67,   272,   273,
      10,    11,   246,   247,   248,    10,    11,   237,   238,   239,
      69,   352,   353,    10,    11,   274,   275,   276,    66,    81,
      83,    84,    85,    87,    88,    89,    91,    92,    93,    95,
      96,    97,    99,   100,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   242,    71,   406,
     407,    10,    11,   354,   355,   356,    68,   141,   147,   151,
     153,   165,   175,   177,   183,   201,   277,   278,   279,   280,
     281,   296,   297,   302,   303,   308,   309,   314,   315,   320,
     321,   326,   327,   332,   333,   338,   339,     5,     5,     5,
       5,     5,    66,   251,   240,    73,   458,   459,    10,    11,
     408,   409,   410,    70,   109,   111,   113,   115,   165,   195,
     357,   358,   359,   360,   361,   366,   367,   373,   374,   380,
     381,   387,   388,   392,   393,    68,   279,    31,    43,    44,
      47,    48,   282,   283,   284,   976,   977,   978,   979,   993,
     994,   995,   996,  1023,    10,    11,   298,   299,   300,    10,
      11,   304,   305,   306,    10,    11,   310,   311,   312,    10,
      11,   316,   317,   318,    10,    11,   322,   323,   324,    10,
      11,   328,   329,   330,    10,    11,   334,   335,   336,    26,
     340,  1018,    82,    86,    90,    94,    98,    75,   553,   554,
      10,    11,   460,   461,   462,    72,   129,   131,   165,   179,
     199,   205,   411,   412,   413,   414,   415,   420,   421,   426,
     427,   432,   433,   438,   439,   444,   445,    70,   359,    10,
      11,   362,   363,   364,   368,   369,   375,   376,   382,   383,
     389,   976,   394,  1018,  1044,  1045,     3,     3,    10,    11,
     285,   286,   287,   284,     4,   154,   301,     4,   178,   307,
       4,   176,   313,     4,   148,   319,     4,   152,   325,     4,
     184,   331,     4,   202,   337,  1044,    10,    11,   341,   342,
     343,   555,   556,    74,   101,   139,   165,   173,   187,   189,
     203,   209,   211,   213,   215,   463,   464,   465,   466,   467,
     472,   473,   478,   479,   484,   485,   490,   491,   496,   497,
     513,   514,   520,   521,   527,   528,   534,   535,   539,   540,
      72,   413,    10,    11,   416,   417,   418,    10,    11,   422,
     423,   424,    10,    11,   428,   429,   430,    10,    11,   434,
     435,   436,    10,    11,   440,   441,   442,   446,  1018,     4,
     196,   365,    10,   371,    57,    58,   370,   976,   997,   998,
     999,  1000,    10,   378,   377,   976,   997,    10,   385,   384,
     976,   997,    10,   390,    10,    11,   395,   396,   397,     6,
       8,   228,   229,   230,   231,  1046,  1044,  1044,   142,   191,
     288,   289,   290,   291,   154,   178,   176,   148,   152,   184,
     202,     6,   163,   166,   344,   345,   346,   347,    10,    11,
     558,   559,   560,    17,    23,    29,    34,   557,  1010,  1015,
    1021,  1026,    74,   465,    10,    11,   468,   469,   470,    10,
      11,   474,   475,   476,    10,    11,   480,   481,   482,    10,
      11,   486,   487,   488,    10,    11,   492,   493,   494,    32,
     498,  1024,   515,   516,   522,   523,   529,   530,   536,   976,
     541,  1018,     4,   132,   419,     6,   130,   425,     6,   206,
     431,     4,   200,   437,     6,     7,   180,   443,  1042,    10,
      11,   447,   448,   449,   196,   372,  1042,     3,   379,  1042,
     386,  1042,     6,   391,   163,   166,   398,   399,   400,   401,
    1044,   142,   290,   292,   293,  1044,   166,   346,   348,   349,
      76,   181,   561,   562,   563,   564,  1044,  1044,  1044,  1044,
       4,   188,   471,     4,   190,   477,     4,   174,   483,     4,
     102,   489,     4,   140,   495,  1044,    10,    11,   499,   500,
     501,    10,   518,   517,   976,   997,    10,   525,   524,   976,
     997,    10,   532,   531,   976,   997,    10,   537,    10,    11,
     542,   543,   544,   132,   130,   206,   200,   180,   163,   166,
     450,   451,   452,   453,   114,  1044,   116,   112,   110,   166,
     400,   402,   403,    10,    11,   295,    45,    46,   294,   976,
     985,   986,   987,   988,    10,    11,   351,    59,    60,   350,
     976,   985,  1001,  1002,  1003,  1004,    76,   171,   563,   945,
     946,   565,   566,     6,     6,     6,     6,   188,   190,   174,
     102,   140,     6,   197,   204,   502,   503,   504,   505,   519,
    1042,   526,  1042,   533,  1042,     6,   538,   163,   166,   545,
     546,   547,   548,   166,   452,   454,   455,    10,    11,   405,
     404,   976,   985,  1001,   192,     3,   164,     3,    30,   947,
    1022,    10,   571,    36,    61,    63,   567,   568,   569,   570,
    1044,  1044,  1044,  1044,  1044,   204,   504,   506,   214,   216,
     212,   210,   166,   547,   549,   550,    10,    11,   457,   456,
     976,   985,  1001,   164,  1044,  1044,  1044,    10,    11,   948,
     949,   950,   187,   572,   573,  1044,     3,     3,    10,    11,
      41,    42,   507,   508,   509,   510,   968,   969,   970,   971,
     976,   993,   997,    10,    11,   552,   551,   976,   985,  1001,
     164,     6,   172,   185,   951,   952,   953,   954,   153,   588,
     589,   574,   575,   576,   976,   993,  1023,     6,  1044,  1044,
       6,     7,   198,   511,   512,     3,   164,  1044,   172,   953,
     955,   956,   223,   594,   595,    10,    11,   590,   591,   592,
      10,    11,   577,   578,   579,   576,  1044,   198,  1044,    10,
      11,   958,   959,   960,    21,   957,   968,   976,   985,  1013,
     157,   714,   715,    28,   596,  1020,     4,   154,   593,   188,
     191,   580,   581,   582,   583,    77,    79,    80,   186,   961,
     962,   963,   964,   965,   966,  1044,   127,   818,   819,    25,
     716,  1017,  1044,    10,    11,   597,   598,   599,   154,   188,
     582,   584,   585,     5,   967,   186,   963,     6,   169,   922,
     923,    24,   820,  1016,  1044,    10,    11,   717,   718,   719,
       6,   217,   600,   601,   602,    10,    11,   587,   586,   976,
     993,    78,  1044,   182,    27,   924,  1019,  1044,    10,    11,
     821,   822,   823,     6,   217,   720,   721,   722,  1044,   224,
     219,   614,   615,    33,   603,  1025,   192,  1044,    10,    11,
     925,   926,   927,     6,   133,   824,   825,   826,  1044,   158,
     121,   734,   735,    22,   723,  1014,   121,   630,   631,   616,
    1025,  1044,    10,    11,   604,   605,   606,     6,   167,   170,
     928,   929,   930,   931,  1044,   128,   121,   838,   839,    16,
     827,  1009,   789,    10,    11,   736,   737,   738,  1044,    10,
      11,   724,   725,   726,   685,    10,    11,   632,   633,   634,
      10,    11,   617,   618,   619,     6,   218,   221,   607,   608,
     609,   610,  1044,   170,   930,   932,   933,   893,    10,    11,
     840,   841,   842,  1044,    10,    11,   828,   829,   830,   163,
     790,   791,   119,   739,   740,   741,     6,   155,   218,   727,
     728,   729,   730,   163,   686,   687,   119,   635,   636,   637,
     220,   221,   620,   621,   622,   623,  1044,   218,   609,   611,
      10,    11,   935,   936,   937,   934,   968,   976,   985,  1001,
    1013,   163,   894,   895,   119,   843,   844,   845,     6,   125,
     134,   831,   832,   833,   834,   792,   793,   122,   105,   747,
     748,    18,   742,  1011,  1044,   218,   729,   731,   688,   689,
     122,   105,   643,   644,   638,  1011,   220,   622,   624,    10,
      37,   612,   613,   984,   985,    77,    79,    80,   168,   938,
     939,   940,   941,   942,   943,   896,   897,   122,   105,   851,
     852,   846,  1011,  1044,   134,   833,   835,    10,    11,   795,
     796,   797,    19,    51,    52,    53,    54,   794,   976,   980,
     981,   982,   983,   985,   989,   990,   991,   992,   993,  1001,
    1012,  1014,   107,   754,   755,   749,  1011,  1044,    10,    11,
     743,   744,   745,    10,   732,   733,   984,   985,    10,    11,
     691,   692,   693,    55,    56,   690,   976,   980,   985,   993,
    1001,  1005,  1006,  1007,  1008,  1012,  1025,   107,   650,   651,
     645,  1011,    10,    11,   639,   640,   641,    10,    11,   625,
     626,   627,   628,   984,   985,  1042,  1044,     5,   944,   168,
     940,    10,    11,   899,   900,   901,    49,    50,   898,   972,
     973,   974,   975,   976,   980,   985,   993,  1001,  1009,  1012,
     107,   858,   859,   853,  1011,    10,    11,   847,   848,   849,
      10,   836,   837,   984,   985,   137,   155,   164,   798,   799,
     800,   801,   808,   809,   810,  1044,     3,     3,   103,   761,
     762,   756,  1011,    10,    11,   750,   751,   752,     6,   117,
     746,  1027,  1028,  1035,  1042,   137,   164,   221,   694,   695,
     696,   697,   704,   705,   706,     3,   103,   657,   658,   652,
    1011,    10,    11,   646,   647,   648,   642,  1027,     4,   222,
     629,   222,     6,    78,   125,   137,   164,   902,   903,   904,
     905,   912,   913,   914,     3,   103,   865,   866,   860,  1011,
      10,    11,   854,   855,   856,   850,  1027,  1042,   164,   800,
     802,   809,   811,   812,     6,  1044,  1044,   149,   768,   769,
     763,  1011,    10,    11,   757,   758,   759,   753,  1027,  1044,
      40,  1036,   120,   135,  1029,  1030,   156,   164,   696,   698,
     705,   707,   708,  1044,   149,   664,   665,   659,  1011,    10,
      11,   653,   654,   655,   649,  1027,   120,   222,  1044,   164,
     904,   906,   913,   915,   916,  1044,   149,   872,   873,   867,
    1011,    10,    11,   861,   862,   863,   857,  1027,   120,   126,
      10,    11,   803,   804,   805,   806,   984,   985,    10,    11,
     814,   815,   816,   813,   976,  1001,  1011,  1044,   193,   775,
     776,   770,  1011,    10,    11,   764,   765,   766,   760,  1027,
     106,  1044,    10,    11,  1037,  1038,  1039,  1031,  1032,    10,
      11,   699,   700,   701,   702,   984,   985,    10,    11,   710,
     711,   712,   709,   976,  1001,  1011,   193,   671,   672,   666,
    1011,    10,    11,   660,   661,   662,   656,  1027,   106,    10,
      11,   907,   908,   909,   910,   984,   985,    10,    11,   918,
     919,   920,   917,   976,  1001,  1011,   193,   879,   880,   874,
    1011,    10,    11,   868,   869,   870,   864,  1027,   106,     4,
       6,     7,   156,   807,  1043,   817,  1027,   207,   782,   783,
     777,  1011,    10,    11,   771,   772,   773,   767,  1027,   108,
       6,     4,   118,    10,  1034,    38,    39,  1033,  1040,  1041,
     222,   703,  1043,   713,  1027,   207,   678,   679,   673,  1011,
      10,    11,   667,   668,   669,   663,  1027,   108,   126,   911,
    1043,   921,  1027,   207,   886,   887,   881,  1011,    10,    11,
     875,   876,   877,   871,  1027,   108,   156,   138,   784,  1011,
      10,    11,   778,   779,   780,   774,  1027,   104,  1044,   118,
       6,  1044,  1044,   222,   138,   680,  1011,    10,    11,   674,
     675,   676,   670,  1027,   104,   126,   138,   888,  1011,    10,
      11,   882,   883,   884,   878,  1027,   104,    10,    11,   785,
     786,   787,   781,  1027,   150,   136,     6,     6,    10,    11,
     681,   682,   683,   677,  1027,   150,    10,    11,   889,   890,
     891,   885,  1027,   150,   788,  1027,   194,  1044,  1044,   684,
    1027,   194,   892,  1027,   194,   208,   208,   208
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

  case 19:

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

  case 34:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 39:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 41:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 46:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 48:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 53:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 55:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 60:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 62:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 67:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 70:

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

  case 89:

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

  case 90:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    }
    break;

  case 93:

    { 
        if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
    }
    break;

  case 94:

    {   
        osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
    }
    break;

  case 95:

    {
       if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 96:

    {    if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 97:

    {    if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 104:

    {
    parserData->kounter++;
}
    break;

  case 105:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 106:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
}
    break;

  case 109:

    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
    }
    break;

  case 110:

    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
    }
    break;

  case 114:

    {
        if (parserData->generalMessagePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
        parserData->generalMessagePresent = true;
    }
    break;

  case 120:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 122:

    {
        if (parserData->generalServiceURIPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
        parserData->generalServiceURIPresent = true;
    }
    break;

  case 128:

    {
        osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 130:

    {
        if (parserData->generalServiceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
        parserData->generalServiceNamePresent = true;
    }
    break;

  case 136:

    {
        osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 138:

    {
        if (parserData->generalInstanceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
        parserData->generalInstanceNamePresent = true;
    }
    break;

  case 144:

    {
        osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 146:

    {
        if (parserData->generalJobIDPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
        parserData->generalJobIDPresent = true;
    }
    break;

  case 152:

    {
        osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 154:

    {
        if (parserData->generalSolverInvokedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
        parserData->generalSolverInvokedPresent = true;
    }
    break;

  case 160:

    {
        osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 162:

    {
        if (parserData->generalTimeStampPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
        parserData->generalTimeStampPresent = true;
    }
    break;

  case 168:

    {
        osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 170:

    {
        if (parserData->otherGeneralResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
        parserData->otherGeneralResultsPresent = true;
    }
    break;

  case 171:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
    if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 172:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 173:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 180:

    {
    parserData->kounter++;
}
    break;

  case 181:

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

  case 182:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 185:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
    }
    break;

  case 186:

    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
    }
    break;

  case 187:

    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
    }
    break;

  case 192:

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

  case 208:

    {
        if (parserData->systemInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
        parserData->systemInformationPresent = true;
    }
    break;

  case 214:

    {
        osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 216:

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

  case 220:

    {
        if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 221:

    {
        osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 223:

    {
    osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 225:

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

  case 229:

    {
        if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 230:

    {
        osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 232:

    {
    osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 234:

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

  case 238:

    {
        if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 239:

    {
        osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 241:

    {
    osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 243:

    {
        if (parserData->systemAvailableCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
        parserData->systemAvailableCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 245:

    {
        osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 247:

    {
    osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;
}
    break;

  case 249:

    {
        if (parserData->otherSystemResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
        parserData->otherSystemResultsPresent = true;
    }
    break;

  case 250:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
    if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 251:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 252:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 259:

    {
    parserData->kounter++;
}
    break;

  case 260:

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

  case 261:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 264:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
    }
    break;

  case 265:

    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
    }
    break;

  case 266:

    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
    }
    break;

  case 271:

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

  case 287:

    {
        if (parserData->serviceCurrentStatePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
        parserData->serviceCurrentStatePresent = true;
    }
    break;

  case 293:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setCurrentState(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 295:

    {
        if (parserData->serviceCurrentJobCountPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
        parserData->serviceCurrentJobCountPresent = true;
    }
    break;

  case 301:

    {
        osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL;
    }
    break;

  case 303:

    {
        if (parserData->serviceTotalJobsSoFarPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
        parserData->serviceTotalJobsSoFarPresent = true;
    }
    break;

  case 309:

    {
        osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; 
    }
    break;

  case 311:

    {
        if (parserData->timeServiceStartedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
        parserData->timeServiceStartedPresent = true;
    }
    break;

  case 317:

    {
        osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 319:

    {
        if (parserData->serviceUtilizationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
        parserData->serviceUtilizationPresent = true;
    }
    break;

  case 325:

    {
    if (osresult->setServiceUtilization( parserData->tempVal) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
    parserData->errorText = NULL;
}
    break;

  case 327:

    {
        if (parserData->otherServiceResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
        parserData->otherServiceResultsPresent = true;
    }
    break;

  case 328:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
    if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 329:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 330:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 337:

    {
    parserData->kounter++;
}
    break;

  case 338:

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

  case 339:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 342:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
    }
    break;

  case 343:

    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
    }
    break;

  case 344:

    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
    }
    break;

  case 349:

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

  case 370:

    {
        if (parserData->jobStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
        parserData->jobStatusPresent = true;
    }
    break;

  case 376:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setJobStatus(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
        parserData->errorText = NULL;
    }
    break;

  case 378:

    {
        if (parserData->jobSubmitTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
        parserData->jobSubmitTimePresent = true;
    }
    break;

  case 384:

    {
        osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 386:

    {
        if (parserData->scheduledStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
        parserData->scheduledStartTimePresent = true;
    }
    break;

  case 392:

    {
        osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 394:

    {
        if (parserData->actualStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
        parserData->actualStartTimePresent = true;
    }
    break;

  case 400:

    {
        osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 402:

    {
        if (parserData->jobEndTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
        parserData->jobEndTimePresent = true;
    }
    break;

  case 408:

    {
        osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 410:

    {
        if (parserData->jobTimingInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
        parserData->jobTimingInformationPresent = true;
    }
    break;

  case 411:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
    if (osresult->setNumberOfTimes(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
    parserData->numberOfTimes = parserData->tempInt;
    parserData->ivar = 0;
}
    break;

  case 412:

    {
        if (parserData->numberOfTimes > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
    }
    break;

  case 413:

    {
        if (parserData->ivar != parserData->numberOfTimes)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
    }
    break;

  case 421:

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

  case 433:

    {    
    if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
        parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
            osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
    parserData->ivar++;
}
    break;

  case 434:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 435:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 437:

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

  case 441:

    {
        if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 442:

    {
        osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 444:

    {
    osresult->setUsedDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 446:

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

  case 450:

    {
        if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 451:

    {
        osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 453:

    {
    osresult->setUsedMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 455:

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

  case 459:

    {
        if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 460:

    {
        osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 462:

    {
    osresult->setUsedCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 464:

    {
        if (parserData->jobUsedCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
        parserData->jobUsedCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 466:

    {
        osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 468:

    { 
    osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; 
}
    break;

  case 470:

    {
        if (parserData->otherJobResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
        parserData->otherJobResultsPresent = true;
    }
    break;

  case 471:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
    if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 472:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 473:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 480:

    {
    parserData->kounter++;
}
    break;

  case 481:

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

  case 482:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 485:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
    }
    break;

  case 486:

    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
    }
    break;

  case 487:

    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
    }
    break;

  case 492:

    {
    parserData->numberAttributePresent = false;
    parserData->nVarPresent = false;
    parserData->nObjPresent = false;
    parserData->nConPresent = false;
}
    break;

  case 493:

    {
    if (!parserData->numberAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
}
    break;

  case 496:

    {
        parserData->numberOfSolutions = parserData->tempInt; 
        if (osresult->setSolutionNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
        parserData->solutionIdx = 0;
    }
    break;

  case 497:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osresult->setVariableNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
    }
    break;

  case 498:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osresult->setConstraintNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
    }
    break;

  case 499:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osresult->setObjectiveNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
    }
    break;

  case 500:

    {
        if (parserData->numberOfSolutions > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
    }
    break;

  case 501:

    {
        if (parserData->solutionIdx != parserData->numberOfSolutions)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
    }
    break;

  case 509:

    {
    if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->weightedObjAttributePresent = false;
}
    break;

  case 516:

    {
    if (parserData->idxAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
    parserData->idxAttributePresent = true;
    if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 517:

    {
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 518:

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

  case 519:

    {
        parserData->solutionIdx++;
    }
    break;

  case 521:

    {
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 522:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
    }
    break;

  case 525:

    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
    }
    break;

  case 526:

    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
    }
    break;

  case 527:

    {
        if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 528:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 529:

    {
        if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 536:

    {
    parserData->kounter++; 
}
    break;

  case 537:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 538:

    {
    if (!parserData->typeAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
}
    break;

  case 541:

    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
    }
    break;

  case 542:

    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
    }
    break;

  case 553:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
        osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
        parserData->errorText = NULL;
    }
    break;

  case 556:

    {
    parserData->numberOfOtherVariableResults = 0;
    osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 558:

    {    
    if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
    parserData->numberOfOtherVariableResults = parserData->tempInt;
    parserData->iOther = 0;
}
    break;

  case 567:

    {
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}
    break;

  case 568:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 569:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 576:

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

  case 577:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 586:

    {
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}
    break;

  case 587:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 588:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 595:

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

  case 596:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 601:

    {parserData->tempStr = "";}
    break;

  case 606:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 609:

    {
    osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 616:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 618:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 625:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 627:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 634:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 636:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 643:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 645:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 652:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 654:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 661:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 663:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 670:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 672:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 680:

    {      
        parserData->iOther++;
    }
    break;

  case 681:

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

  case 682:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 685:

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

  case 686:

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

  case 687:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 688:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
    break;

  case 689:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultType failed");
    }
    break;

  case 690:

    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->varTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarType failed");
    }
    break;

  case 691:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 692:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 702:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 703:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 706:

    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
    }
    break;

  case 707:

    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
    }
    break;

  case 713:

    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
    }
    break;

  case 716:

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

  case 717:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 718:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 721:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 731:

    {
    parserData->numberOfOtherObjectiveResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 733:

    {
    parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
}
    break;

  case 742:

    {
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}
    break;

  case 743:

    {
        if (parserData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
    }
    break;

  case 744:

    {
        if (parserData->kounter != parserData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
    }
    break;

  case 751:

    {
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
    parserData->kounter++;
}
    break;

  case 752:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 760:

    {
    osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 767:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 769:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 776:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 778:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 785:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 787:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 794:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 796:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 803:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 805:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 812:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 814:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 821:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 823:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 831:

    {      
        parserData->iOther++;  
    }
    break;

  case 832:

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

  case 833:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 836:

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

  case 837:

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

  case 838:

    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 839:

    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 840:

    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultType failed");
    }
    break;

  case 841:

    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->objTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 842:

    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 843:

    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->descriptionAttribute) 
                                                              == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 853:

    {  
    parserData->kounter++;
}
    break;

  case 854:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;    
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 857:

    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
    }
    break;

  case 858:

    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
    }
    break;

  case 864:

    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
    }
    break;

  case 867:

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

  case 868:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 869:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 872:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 882:

    {
    parserData->numberOfOtherConstraintResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 884:

    {
    parserData->numberOfOtherConstraintResults = parserData->tempInt;
    if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
}
    break;

  case 892:

    {    parserData->numberAttributePresent = false; }
    break;

  case 893:

    {
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
}
    break;

  case 894:

    {
        if (parserData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
    }
    break;

  case 895:

    {
        if (parserData->kounter != parserData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
    }
    break;

  case 902:

    {
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               parserData->idx,         parserData->nameAttribute,
                               parserData->tempVal                           ) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
    parserData->kounter++;
}
    break;

  case 903:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 911:

    {
    osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 918:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 920:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 927:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 929:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 936:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 938:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 945:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 947:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 954:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 956:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 963:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 965:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 972:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 974:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 982:

    {      
        parserData->iOther++;  
    }
    break;

  case 983:

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

  case 984:

    {
        if (!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 987:

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

  case 988:

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

  case 989:

    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 990:

    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 991:

    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultType failed");
    }
    break;

  case 992:

    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->conTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConType failed");
    }
    break;

  case 993:

    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 994:

    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 1004:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 1005:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 1008:

    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
    }
    break;

  case 1009:

    {    
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
    }
    break;

  case 1015:

    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
    }
    break;

  case 1018:

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

  case 1019:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1020:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 1023:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1033:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1034:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1035:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 1036:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 1043:

    {
    parserData->iOther++;
}
    break;

  case 1044:

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

  case 1045:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1048:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
    }
    break;

  case 1049:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                 parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 1050:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 1051:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
                                                        parserData->iOther,
                                                        parserData->descriptionAttribute) 
                                                            == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 1052:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1053:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1054:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1061:

    {
    parserData->kounter++;
}
    break;

  case 1062:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1067:

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

  case 1070:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1071:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1072:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
    }
    break;

  case 1073:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 1080:

    {
    parserData->iOther++;
}
    break;

  case 1081:

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

  case 1082:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
    if (!parserData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1085:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
    }
    break;

  case 1086:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, 
                                              parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
    }
    break;

  case 1087:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, 
                                                 parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
    }
    break;

  case 1088:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
                                                   parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1089:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1090:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1097:

    {
    parserData->kounter++;
}
    break;

  case 1098:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1103:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1104:

    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
        parserData->categoryAttributePresent = true;
    }
    break;

  case 1107:

    { 
    parserData->categoryAttribute = ""; 
}
    break;

  case 1108:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1109:

    {
        if (parserData->conTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one conType attribute allowed for this element");
        parserData->conTypeAttributePresent = true;
    }
    break;

  case 1112:

    { 
    parserData->conTypeAttribute = ""; 
}
    break;

  case 1113:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1114:

    {
        if (parserData->descriptionAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
        parserData->descriptionAttributePresent = true;
    }
    break;

  case 1117:

    { 
    parserData->descriptionAttribute = ""; 
}
    break;

  case 1118:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1119:

    {
        if (parserData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one enumType attribute allowed for this element");
        parserData->enumTypeAttributePresent = true;
    }
    break;

  case 1122:

    { 
    parserData->enumTypeAttribute = ""; 
}
    break;

  case 1123:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1124:

    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = (yyvsp[(3) - (4)].ival); 
    }
    break;

  case 1125:

    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1128:

    { 
    parserData->nameAttribute = ""; 
}
    break;

  case 1129:

    { 
    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1130:

    {
        if (parserData->objTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one objType attribute allowed for this element");
        parserData->objTypeAttributePresent = true;
    }
    break;

  case 1133:

    { 
    parserData->objTypeAttribute = ""; 
}
    break;

  case 1134:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1135:

    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
        parserData->typeAttributePresent = true;
    }
    break;

  case 1138:

    { 
    parserData->typeAttribute = ""; 
}
    break;

  case 1139:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1140:

    {
        if (parserData->unitAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
        parserData->unitAttributePresent = true;
    }
    break;

  case 1143:

    { 
    parserData->unitAttribute = ""; 
}
    break;

  case 1144:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1145:

    {
        if (parserData->valueAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
        parserData->valueAttributePresent = true;
    }
    break;

  case 1148:

    { 
    parserData->valueAttribute = ""; 
}
    break;

  case 1149:

    { 
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1150:

    {
        if (parserData->varTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one varType attribute allowed for this element");
        parserData->varTypeAttributePresent = true;
    }
    break;

  case 1153:

    { 
    parserData->varTypeAttribute = ""; 
}
    break;

  case 1154:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1155:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1156:

    {
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1157:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1158:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1159:

    {    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1160:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1161:

    {
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1162:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1163:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1164:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1165:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1166:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1167:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1168:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1169:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1170:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1171:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1172:

    {
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1173:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
    }
    break;

  case 1178:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1184:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
        osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
    for (int i=0; i<osglData->osglMult; i++)
        osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1186:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1191:

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

  case 1192:

    {    
    if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1193:

    {    
    if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1194:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1195:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1196:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1197:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1198:

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


