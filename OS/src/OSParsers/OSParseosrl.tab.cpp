
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
#define YYNNTS  814
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1203
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1626

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
      22,    24,    28,    30,    32,    33,    40,    41,    44,    46,
      48,    50,    52,    56,    58,    60,    63,    65,    67,    69,
      71,    73,    74,    76,    78,    80,    82,    84,    88,    89,
      91,    93,    95,    97,    99,   103,   104,   106,   108,   110,
     112,   114,   118,   119,   121,   123,   125,   127,   129,   133,
     134,   136,   138,   140,   142,   144,   148,   149,   152,   154,
     156,   158,   161,   163,   167,   169,   171,   174,   176,   178,
     180,   182,   184,   186,   188,   190,   192,   196,   198,   200,
     202,   205,   207,   209,   211,   213,   215,   218,   220,   224,
     226,   228,   231,   235,   237,   239,   240,   243,   245,   247,
     250,   252,   255,   257,   259,   261,   264,   266,   270,   272,
     275,   277,   279,   281,   284,   286,   290,   292,   295,   297,
     299,   301,   304,   306,   310,   312,   315,   317,   319,   321,
     324,   326,   330,   332,   335,   337,   339,   341,   344,   346,
     350,   352,   355,   357,   359,   361,   364,   366,   370,   372,
     375,   377,   379,   381,   384,   386,   390,   392,   396,   398,
     400,   402,   404,   407,   409,   413,   415,   417,   420,   424,
     426,   428,   429,   432,   434,   436,   438,   441,   443,   444,
     447,   449,   451,   453,   456,   458,   462,   464,   466,   469,
     471,   473,   475,   477,   479,   481,   484,   486,   488,   490,
     493,   495,   499,   501,   505,   507,   509,   510,   513,   515,
     517,   521,   523,   527,   529,   531,   532,   535,   537,   539,
     543,   545,   549,   551,   553,   554,   557,   559,   561,   565,
     567,   571,   573,   574,   576,   580,   582,   586,   588,   590,
     592,   594,   597,   599,   603,   605,   607,   610,   614,   616,
     618,   619,   622,   624,   626,   628,   631,   633,   634,   637,
     639,   641,   643,   646,   648,   652,   654,   656,   659,   661,
     663,   665,   667,   669,   671,   674,   676,   678,   680,   683,
     685,   689,   691,   694,   696,   698,   700,   703,   705,   709,
     711,   714,   716,   718,   720,   723,   725,   729,   731,   734,
     736,   738,   740,   743,   745,   749,   751,   754,   756,   758,
     760,   763,   765,   769,   771,   775,   777,   779,   781,   783,
     786,   788,   792,   794,   796,   799,   803,   805,   807,   808,
     811,   813,   815,   817,   820,   822,   823,   826,   828,   830,
     832,   835,   837,   841,   843,   845,   848,   850,   852,   854,
     856,   858,   860,   862,   864,   866,   868,   870,   873,   875,
     877,   879,   882,   884,   888,   890,   893,   895,   897,   899,
     902,   904,   908,   910,   913,   915,   917,   919,   922,   924,
     928,   930,   933,   935,   937,   939,   942,   944,   948,   950,
     953,   955,   957,   959,   962,   964,   968,   970,   974,   976,
     978,   980,   982,   985,   987,   991,   993,   995,   998,  1002,
    1004,  1005,  1008,  1010,  1012,  1014,  1016,  1018,  1020,  1023,
    1025,  1029,  1031,  1033,  1035,  1039,  1041,  1043,  1044,  1047,
    1049,  1051,  1055,  1057,  1061,  1063,  1065,  1066,  1069,  1071,
    1073,  1077,  1079,  1083,  1085,  1087,  1088,  1091,  1093,  1095,
    1099,  1101,  1105,  1107,  1108,  1110,  1114,  1116,  1120,  1122,
    1124,  1126,  1128,  1131,  1133,  1137,  1139,  1141,  1144,  1148,
    1150,  1152,  1153,  1156,  1158,  1160,  1162,  1165,  1167,  1168,
    1172,  1174,  1176,  1177,  1180,  1182,  1184,  1186,  1188,  1190,
    1192,  1195,  1197,  1201,  1204,  1206,  1209,  1213,  1215,  1217,
    1218,  1221,  1223,  1225,  1227,  1232,  1236,  1240,  1249,  1253,
    1255,  1257,  1259,  1262,  1264,  1266,  1268,  1270,  1272,  1275,
    1277,  1281,  1283,  1285,  1288,  1292,  1294,  1296,  1297,  1300,
    1302,  1304,  1307,  1309,  1310,  1313,  1315,  1317,  1319,  1322,
    1324,  1328,  1330,  1331,  1335,  1337,  1338,  1340,  1342,  1344,
    1346,  1350,  1355,  1356,  1360,  1362,  1364,  1366,  1368,  1371,
    1373,  1377,  1379,  1381,  1384,  1388,  1390,  1391,  1394,  1396,
    1398,  1402,  1403,  1407,  1409,  1411,  1413,  1415,  1418,  1420,
    1424,  1426,  1428,  1431,  1435,  1437,  1438,  1441,  1443,  1445,
    1447,  1449,  1452,  1454,  1458,  1460,  1461,  1464,  1466,  1468,
    1470,  1472,  1476,  1484,  1485,  1489,  1491,  1493,  1495,  1497,
    1499,  1503,  1505,  1506,  1510,  1512,  1514,  1516,  1518,  1520,
    1524,  1526,  1527,  1531,  1533,  1535,  1537,  1539,  1541,  1545,
    1547,  1548,  1552,  1554,  1556,  1558,  1560,  1562,  1566,  1568,
    1569,  1573,  1575,  1577,  1579,  1581,  1583,  1587,  1589,  1590,
    1594,  1596,  1598,  1600,  1602,  1604,  1608,  1610,  1611,  1615,
    1617,  1619,  1621,  1623,  1625,  1629,  1631,  1632,  1635,  1639,
    1641,  1643,  1644,  1647,  1649,  1651,  1653,  1655,  1657,  1659,
    1661,  1663,  1665,  1667,  1670,  1672,  1676,  1678,  1680,  1682,
    1685,  1689,  1691,  1692,  1695,  1697,  1699,  1701,  1703,  1706,
    1708,  1712,  1714,  1716,  1719,  1723,  1725,  1727,  1728,  1731,
    1733,  1735,  1737,  1739,  1741,  1743,  1747,  1749,  1750,  1754,
    1756,  1757,  1759,  1761,  1763,  1765,  1769,  1773,  1774,  1778,
    1780,  1782,  1784,  1786,  1789,  1791,  1795,  1797,  1799,  1802,
    1806,  1808,  1809,  1812,  1814,  1816,  1820,  1821,  1824,  1826,
    1828,  1830,  1832,  1836,  1844,  1845,  1849,  1851,  1853,  1855,
    1857,  1859,  1863,  1865,  1866,  1870,  1872,  1874,  1876,  1878,
    1880,  1884,  1886,  1887,  1891,  1893,  1895,  1897,  1899,  1901,
    1905,  1907,  1908,  1912,  1914,  1916,  1918,  1920,  1922,  1926,
    1928,  1929,  1933,  1935,  1937,  1939,  1941,  1943,  1947,  1949,
    1950,  1954,  1956,  1958,  1960,  1962,  1964,  1968,  1970,  1971,
    1975,  1977,  1979,  1981,  1983,  1985,  1989,  1991,  1992,  1995,
    1999,  2001,  2003,  2004,  2007,  2009,  2011,  2013,  2015,  2017,
    2019,  2021,  2023,  2025,  2027,  2030,  2032,  2036,  2038,  2040,
    2042,  2045,  2049,  2051,  2052,  2055,  2057,  2059,  2061,  2063,
    2066,  2068,  2072,  2074,  2076,  2079,  2083,  2085,  2087,  2088,
    2091,  2093,  2095,  2097,  2099,  2101,  2103,  2107,  2109,  2110,
    2114,  2116,  2117,  2119,  2121,  2123,  2125,  2129,  2133,  2134,
    2138,  2140,  2142,  2144,  2146,  2149,  2151,  2155,  2157,  2159,
    2162,  2166,  2168,  2169,  2172,  2174,  2176,  2180,  2181,  2184,
    2186,  2188,  2190,  2192,  2196,  2204,  2205,  2209,  2211,  2213,
    2215,  2217,  2219,  2223,  2225,  2226,  2230,  2232,  2234,  2236,
    2238,  2240,  2244,  2246,  2247,  2251,  2253,  2255,  2257,  2259,
    2261,  2265,  2267,  2268,  2272,  2274,  2276,  2278,  2280,  2282,
    2286,  2288,  2289,  2293,  2295,  2297,  2299,  2301,  2303,  2307,
    2309,  2310,  2314,  2316,  2318,  2320,  2322,  2324,  2328,  2330,
    2331,  2335,  2337,  2339,  2341,  2343,  2345,  2349,  2351,  2352,
    2355,  2359,  2361,  2363,  2364,  2367,  2369,  2371,  2373,  2375,
    2377,  2379,  2381,  2383,  2385,  2387,  2390,  2392,  2396,  2398,
    2400,  2402,  2405,  2409,  2411,  2412,  2415,  2417,  2419,  2421,
    2423,  2426,  2428,  2432,  2434,  2436,  2439,  2443,  2445,  2447,
    2448,  2451,  2453,  2455,  2457,  2459,  2461,  2463,  2467,  2469,
    2470,  2474,  2476,  2478,  2480,  2482,  2485,  2487,  2491,  2493,
    2495,  2498,  2502,  2504,  2506,  2507,  2510,  2512,  2514,  2516,
    2518,  2520,  2522,  2524,  2527,  2529,  2533,  2535,  2537,  2540,
    2542,  2544,  2546,  2548,  2550,  2554,  2556,  2557,  2561,  2563,
    2565,  2567,  2569,  2572,  2574,  2578,  2580,  2582,  2585,  2589,
    2591,  2593,  2594,  2597,  2599,  2601,  2603,  2605,  2607,  2609,
    2612,  2614,  2618,  2620,  2622,  2625,  2627,  2629,  2631,  2633,
    2635,  2639,  2641,  2643,  2645,  2647,  2649,  2653,  2655,  2657,
    2659,  2661,  2665,  2667,  2669,  2671,  2673,  2677,  2679,  2681,
    2683,  2685,  2689,  2694,  2696,  2698,  2700,  2702,  2706,  2708,
    2710,  2712,  2714,  2718,  2720,  2722,  2724,  2726,  2730,  2732,
    2734,  2736,  2738,  2742,  2744,  2746,  2748,  2750,  2754,  2756,
    2758,  2760,  2762,  2766,  2771,  2776,  2781,  2786,  2791,  2796,
    2801,  2806,  2811,  2816,  2821,  2826,  2831,  2836,  2841,  2846,
    2851,  2856,  2858,  2860,  2861,  2864,  2868,  2870,  2872,  2873,
    2876,  2878,  2880,  2884,  2888,  2893,  2895,  2897,  2900,  2902,
    2906,  2911,  2916,  2918,  2920,  2922,  2924,  2926,  2929,  2930,
    2933,  2935,  2937,  2939
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     233,     0,    -1,   234,   242,   240,    -1,   235,   236,   237,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   238,    -1,
     239,    -1,    11,    -1,    10,   242,   240,    -1,   241,    -1,
      15,    -1,    -1,   243,   271,   351,   405,   457,   552,    -1,
      -1,   244,   245,    -1,    65,    -1,   246,    -1,   247,    -1,
      11,    -1,    10,   248,    66,    -1,   249,    -1,   250,    -1,
     249,   250,    -1,   251,    -1,   255,    -1,   259,    -1,   263,
      -1,   267,    -1,    -1,   252,    -1,   253,    -1,   254,    -1,
      84,    -1,    83,    -1,    81,     5,    82,    -1,    -1,   256,
      -1,   257,    -1,   258,    -1,    88,    -1,    87,    -1,    85,
       5,    86,    -1,    -1,   260,    -1,   261,    -1,   262,    -1,
      92,    -1,    91,    -1,    89,     5,    90,    -1,    -1,   264,
      -1,   265,    -1,   266,    -1,    96,    -1,    95,    -1,    93,
       5,    94,    -1,    -1,   268,    -1,   269,    -1,   270,    -1,
     100,    -1,    99,    -1,    97,     5,    98,    -1,    -1,   272,
     273,    -1,    67,    -1,   274,    -1,   275,    -1,    10,    68,
      -1,    11,    -1,    10,   276,    68,    -1,   277,    -1,   278,
      -1,   277,   278,    -1,   279,    -1,   295,    -1,   301,    -1,
     307,    -1,   313,    -1,   319,    -1,   325,    -1,   331,    -1,
     337,    -1,   280,   281,   284,    -1,   141,    -1,   282,    -1,
     283,    -1,   282,   283,    -1,   992,    -1,   975,    -1,  1022,
      -1,   285,    -1,   286,    -1,    10,   142,    -1,    11,    -1,
      10,   287,   142,    -1,   288,    -1,   289,    -1,   288,   289,
      -1,   290,   291,   294,    -1,   191,    -1,   292,    -1,    -1,
     292,   293,    -1,   984,    -1,   975,    -1,    10,   192,    -1,
      11,    -1,   296,   297,    -1,   153,    -1,   298,    -1,   299,
      -1,    10,   154,    -1,    11,    -1,    10,   300,   154,    -1,
       4,    -1,   302,   303,    -1,   177,    -1,   304,    -1,   305,
      -1,    10,   178,    -1,    11,    -1,    10,   306,   178,    -1,
       4,    -1,   308,   309,    -1,   175,    -1,   310,    -1,   311,
      -1,    10,   176,    -1,    11,    -1,    10,   312,   176,    -1,
       4,    -1,   314,   315,    -1,   147,    -1,   316,    -1,   317,
      -1,    10,   148,    -1,    11,    -1,    10,   318,   148,    -1,
       4,    -1,   320,   321,    -1,   151,    -1,   322,    -1,   323,
      -1,    10,   152,    -1,    11,    -1,    10,   324,   152,    -1,
       4,    -1,   326,   327,    -1,   183,    -1,   328,    -1,   329,
      -1,    10,   184,    -1,    11,    -1,    10,   330,   184,    -1,
       4,    -1,   332,   333,    -1,   201,    -1,   334,    -1,   335,
      -1,    10,   202,    -1,    11,    -1,    10,   336,   202,    -1,
       4,    -1,   338,   339,   340,    -1,   165,    -1,  1017,    -1,
     341,    -1,   342,    -1,    10,   166,    -1,    11,    -1,    10,
     343,   166,    -1,   344,    -1,   345,    -1,   344,   345,    -1,
     346,   347,   350,    -1,   163,    -1,   348,    -1,    -1,   348,
     349,    -1,   984,    -1,  1000,    -1,   975,    -1,    10,   164,
      -1,    11,    -1,    -1,   352,   353,    -1,    69,    -1,   354,
      -1,   355,    -1,    10,    70,    -1,    11,    -1,    10,   356,
      70,    -1,   357,    -1,   358,    -1,   357,   358,    -1,   359,
      -1,   365,    -1,   372,    -1,   379,    -1,   386,    -1,   391,
      -1,   360,   361,    -1,   195,    -1,   362,    -1,   363,    -1,
      10,   196,    -1,    11,    -1,    10,   364,   196,    -1,     4,
      -1,   366,   367,   370,    -1,   113,    -1,   368,    -1,    -1,
     368,   369,    -1,   996,    -1,   975,    -1,    10,   371,   114,
      -1,  1041,    -1,   373,   374,   377,    -1,   115,    -1,   375,
      -1,    -1,   375,   376,    -1,   996,    -1,   975,    -1,    10,
     378,   116,    -1,  1041,    -1,   380,   381,   384,    -1,   111,
      -1,   382,    -1,    -1,   382,   383,    -1,   996,    -1,   975,
      -1,    10,   385,   112,    -1,  1041,    -1,   387,   388,   389,
      -1,   109,    -1,    -1,   975,    -1,    10,   390,   110,    -1,
       6,    -1,   392,   393,   394,    -1,   165,    -1,  1017,    -1,
     395,    -1,   396,    -1,    10,   166,    -1,    11,    -1,    10,
     397,   166,    -1,   398,    -1,   399,    -1,   398,   399,    -1,
     400,   401,   404,    -1,   163,    -1,   402,    -1,    -1,   402,
     403,    -1,   984,    -1,  1000,    -1,   975,    -1,    10,   164,
      -1,    11,    -1,    -1,   406,   407,    -1,    71,    -1,   408,
      -1,   409,    -1,    10,    72,    -1,    11,    -1,    10,   410,
      72,    -1,   411,    -1,   412,    -1,   411,   412,    -1,   413,
      -1,   419,    -1,   425,    -1,   431,    -1,   437,    -1,   443,
      -1,   414,   415,    -1,   131,    -1,   416,    -1,   417,    -1,
      10,   132,    -1,    11,    -1,    10,   418,   132,    -1,     4,
      -1,   420,   421,    -1,   129,    -1,   422,    -1,   423,    -1,
      10,   130,    -1,    11,    -1,    10,   424,   130,    -1,     6,
      -1,   426,   427,    -1,   205,    -1,   428,    -1,   429,    -1,
      10,   206,    -1,    11,    -1,    10,   430,   206,    -1,     6,
      -1,   432,   433,    -1,   199,    -1,   434,    -1,   435,    -1,
      10,   200,    -1,    11,    -1,    10,   436,   200,    -1,     4,
      -1,   438,   439,    -1,   179,    -1,   440,    -1,   441,    -1,
      10,   180,    -1,    11,    -1,    10,   442,   180,    -1,  1041,
      -1,   444,   445,   446,    -1,   165,    -1,  1017,    -1,   447,
      -1,   448,    -1,    10,   166,    -1,    11,    -1,    10,   449,
     166,    -1,   450,    -1,   451,    -1,   450,   451,    -1,   452,
     453,   456,    -1,   163,    -1,   454,    -1,    -1,   454,   455,
      -1,   984,    -1,  1000,    -1,   975,    -1,    10,   164,    -1,
      11,    -1,    -1,   458,   459,    -1,    73,    -1,   460,    -1,
     461,    -1,    10,    74,    -1,    11,    -1,    10,   462,    74,
      -1,   463,    -1,   464,    -1,   463,   464,    -1,   465,    -1,
     471,    -1,   477,    -1,   483,    -1,   489,    -1,   495,    -1,
     512,    -1,   519,    -1,   526,    -1,   533,    -1,   538,    -1,
     466,   467,    -1,   187,    -1,   468,    -1,   469,    -1,    10,
     188,    -1,    11,    -1,    10,   470,   188,    -1,     4,    -1,
     472,   473,    -1,   189,    -1,   474,    -1,   475,    -1,    10,
     190,    -1,    11,    -1,    10,   476,   190,    -1,     4,    -1,
     478,   479,    -1,   173,    -1,   480,    -1,   481,    -1,    10,
     174,    -1,    11,    -1,    10,   482,   174,    -1,     4,    -1,
     484,   485,    -1,   101,    -1,   486,    -1,   487,    -1,    10,
     102,    -1,    11,    -1,    10,   488,   102,    -1,     4,    -1,
     490,   491,    -1,   139,    -1,   492,    -1,   493,    -1,    10,
     140,    -1,    11,    -1,    10,   494,   140,    -1,     4,    -1,
     496,   497,   498,    -1,   203,    -1,  1023,    -1,   499,    -1,
     500,    -1,    10,   204,    -1,    11,    -1,    10,   501,   204,
      -1,   502,    -1,   503,    -1,   502,   503,    -1,   504,   505,
     507,    -1,   197,    -1,    -1,   505,   506,    -1,   996,    -1,
     992,    -1,   967,    -1,   975,    -1,   508,    -1,   509,    -1,
      10,   198,    -1,    11,    -1,    10,   510,   198,    -1,   511,
      -1,     7,    -1,     6,    -1,   513,   514,   517,    -1,   213,
      -1,   515,    -1,    -1,   515,   516,    -1,   996,    -1,   975,
      -1,    10,   518,   214,    -1,  1041,    -1,   520,   521,   524,
      -1,   215,    -1,   522,    -1,    -1,   522,   523,    -1,   996,
      -1,   975,    -1,    10,   525,   216,    -1,  1041,    -1,   527,
     528,   531,    -1,   211,    -1,   529,    -1,    -1,   529,   530,
      -1,   996,    -1,   975,    -1,    10,   532,   212,    -1,  1041,
      -1,   534,   535,   536,    -1,   209,    -1,    -1,   975,    -1,
      10,   537,   210,    -1,     6,    -1,   539,   540,   541,    -1,
     165,    -1,  1017,    -1,   542,    -1,   543,    -1,    10,   166,
      -1,    11,    -1,    10,   544,   166,    -1,   545,    -1,   546,
      -1,   545,   546,    -1,   547,   548,   551,    -1,   163,    -1,
     549,    -1,    -1,   549,   550,    -1,   984,    -1,  1000,    -1,
     975,    -1,    10,   164,    -1,    11,    -1,    -1,   553,   554,
     557,    -1,    75,    -1,   555,    -1,    -1,   555,   556,    -1,
    1020,    -1,  1025,    -1,  1009,    -1,  1014,    -1,   558,    -1,
     559,    -1,    10,    76,    -1,    11,    -1,    10,   560,    76,
      -1,   561,   944,    -1,   562,    -1,   561,   562,    -1,   563,
     564,   570,    -1,   181,    -1,   565,    -1,    -1,   565,   566,
      -1,   567,    -1,   568,    -1,   569,    -1,    36,  1043,     6,
    1043,    -1,    63,     3,  1043,    -1,    61,     3,  1043,    -1,
      10,   571,   587,   593,   713,   817,   921,   182,    -1,   572,
     573,   576,    -1,   187,    -1,   574,    -1,   575,    -1,   574,
     575,    -1,   992,    -1,   975,    -1,  1022,    -1,   577,    -1,
     578,    -1,    10,   188,    -1,    11,    -1,    10,   579,   188,
      -1,   580,    -1,   581,    -1,   580,   581,    -1,   582,   583,
     586,    -1,   191,    -1,   584,    -1,    -1,   584,   585,    -1,
     992,    -1,   975,    -1,    10,   192,    -1,    11,    -1,    -1,
     588,   589,    -1,   153,    -1,   590,    -1,   591,    -1,    10,
     154,    -1,    11,    -1,    10,   592,   154,    -1,     4,    -1,
      -1,   594,   595,   596,    -1,   223,    -1,    -1,  1019,    -1,
     597,    -1,   598,    -1,    11,    -1,    10,   599,   224,    -1,
     600,   613,   629,   684,    -1,    -1,   601,   602,   603,    -1,
     217,    -1,  1024,    -1,   604,    -1,   605,    -1,    10,   218,
      -1,    11,    -1,    10,   606,   218,    -1,   607,    -1,   608,
      -1,   607,   608,    -1,   609,   610,   612,    -1,   221,    -1,
      -1,   610,   611,    -1,   983,    -1,   984,    -1,    10,  1041,
     222,    -1,    -1,   614,   615,   616,    -1,   219,    -1,  1024,
      -1,   617,    -1,   618,    -1,    10,   220,    -1,    11,    -1,
      10,   619,   220,    -1,   620,    -1,   621,    -1,   620,   621,
      -1,   622,   623,   625,    -1,   221,    -1,    -1,   623,   624,
      -1,   983,    -1,   984,    -1,   626,    -1,   627,    -1,    10,
     222,    -1,    11,    -1,    10,   628,   222,    -1,     4,    -1,
      -1,   630,   631,    -1,   121,    -1,   632,    -1,   633,    -1,
      11,    -1,    10,   634,   122,    -1,   635,   642,   649,   656,
     663,   670,   677,    -1,    -1,   636,   637,   638,    -1,   119,
      -1,  1010,    -1,   639,    -1,   640,    -1,    11,    -1,    10,
     641,   120,    -1,  1026,    -1,    -1,   643,   644,   645,    -1,
     105,    -1,  1010,    -1,   646,    -1,   647,    -1,    11,    -1,
      10,   648,   106,    -1,  1026,    -1,    -1,   650,   651,   652,
      -1,   107,    -1,  1010,    -1,   653,    -1,   654,    -1,    11,
      -1,    10,   655,   108,    -1,  1026,    -1,    -1,   657,   658,
     659,    -1,   103,    -1,  1010,    -1,   660,    -1,   661,    -1,
      11,    -1,    10,   662,   104,    -1,  1026,    -1,    -1,   664,
     665,   666,    -1,   149,    -1,  1010,    -1,   667,    -1,   668,
      -1,    11,    -1,    10,   669,   150,    -1,  1026,    -1,    -1,
     671,   672,   673,    -1,   193,    -1,  1010,    -1,   674,    -1,
     675,    -1,    11,    -1,    10,   676,   194,    -1,  1026,    -1,
      -1,   678,   679,   680,    -1,   207,    -1,  1010,    -1,   681,
      -1,   682,    -1,    11,    -1,    10,   683,   208,    -1,  1026,
      -1,    -1,   684,   685,    -1,   686,   687,   690,    -1,   163,
      -1,   688,    -1,    -1,   688,   689,    -1,  1024,    -1,  1011,
      -1,  1000,    -1,   984,    -1,   992,    -1,  1004,    -1,   979,
      -1,   975,    -1,   691,    -1,   692,    -1,    10,   164,    -1,
      11,    -1,    10,   693,   164,    -1,   694,    -1,   703,    -1,
     695,    -1,   694,   695,    -1,   696,   697,   699,    -1,   221,
      -1,    -1,   697,   698,    -1,   983,    -1,   984,    -1,   700,
      -1,   701,    -1,    10,   222,    -1,    11,    -1,    10,   702,
     222,    -1,  1042,    -1,   704,    -1,   703,   704,    -1,   705,
     706,   709,    -1,   137,    -1,   707,    -1,    -1,   707,   708,
      -1,  1010,    -1,  1000,    -1,   975,    -1,   710,    -1,   711,
      -1,    11,    -1,    10,   712,   138,    -1,  1026,    -1,    -1,
     714,   715,   716,    -1,   157,    -1,    -1,  1016,    -1,   717,
      -1,   718,    -1,    11,    -1,    10,   719,   158,    -1,   720,
     733,   788,    -1,    -1,   721,   722,   723,    -1,   217,    -1,
    1013,    -1,   724,    -1,   725,    -1,    10,   218,    -1,    11,
      -1,    10,   726,   218,    -1,   727,    -1,   728,    -1,   727,
     728,    -1,   729,   730,   732,    -1,   155,    -1,    -1,   730,
     731,    -1,   983,    -1,   984,    -1,    10,  1041,   156,    -1,
      -1,   734,   735,    -1,   121,    -1,   736,    -1,   737,    -1,
      11,    -1,    10,   738,   122,    -1,   739,   746,   753,   760,
     767,   774,   781,    -1,    -1,   740,   741,   742,    -1,   119,
      -1,  1010,    -1,   743,    -1,   744,    -1,    11,    -1,    10,
     745,   120,    -1,  1026,    -1,    -1,   747,   748,   749,    -1,
     105,    -1,  1010,    -1,   750,    -1,   751,    -1,    11,    -1,
      10,   752,   106,    -1,  1026,    -1,    -1,   754,   755,   756,
      -1,   107,    -1,  1010,    -1,   757,    -1,   758,    -1,    11,
      -1,    10,   759,   108,    -1,  1026,    -1,    -1,   761,   762,
     763,    -1,   103,    -1,  1010,    -1,   764,    -1,   765,    -1,
      11,    -1,    10,   766,   104,    -1,  1026,    -1,    -1,   768,
     769,   770,    -1,   149,    -1,  1010,    -1,   771,    -1,   772,
      -1,    11,    -1,    10,   773,   150,    -1,  1026,    -1,    -1,
     775,   776,   777,    -1,   193,    -1,  1010,    -1,   778,    -1,
     779,    -1,    11,    -1,    10,   780,   194,    -1,  1026,    -1,
      -1,   782,   783,   784,    -1,   207,    -1,  1010,    -1,   785,
      -1,   786,    -1,    11,    -1,    10,   787,   208,    -1,  1026,
      -1,    -1,   788,   789,    -1,   790,   791,   794,    -1,   163,
      -1,   792,    -1,    -1,   792,   793,    -1,  1013,    -1,  1011,
      -1,  1000,    -1,   984,    -1,   992,    -1,   988,    -1,   979,
      -1,   975,    -1,   795,    -1,   796,    -1,    10,   164,    -1,
      11,    -1,    10,   797,   164,    -1,   798,    -1,   807,    -1,
     799,    -1,   798,   799,    -1,   800,   801,   803,    -1,   155,
      -1,    -1,   801,   802,    -1,   983,    -1,   984,    -1,   804,
      -1,   805,    -1,    10,   156,    -1,    11,    -1,    10,   806,
     156,    -1,  1042,    -1,   808,    -1,   807,   808,    -1,   809,
     810,   813,    -1,   137,    -1,   811,    -1,    -1,   811,   812,
      -1,  1010,    -1,  1000,    -1,   975,    -1,   814,    -1,   815,
      -1,    11,    -1,    10,   816,   138,    -1,  1026,    -1,    -1,
     818,   819,   820,    -1,   127,    -1,    -1,  1015,    -1,   821,
      -1,   822,    -1,    11,    -1,    10,   823,   128,    -1,   824,
     837,   892,    -1,    -1,   825,   826,   827,    -1,   133,    -1,
    1008,    -1,   828,    -1,   829,    -1,    10,   134,    -1,    11,
      -1,    10,   830,   134,    -1,   831,    -1,   832,    -1,   831,
     832,    -1,   833,   834,   836,    -1,   125,    -1,    -1,   834,
     835,    -1,   983,    -1,   984,    -1,    10,  1041,   126,    -1,
      -1,   838,   839,    -1,   121,    -1,   840,    -1,   841,    -1,
      11,    -1,    10,   842,   122,    -1,   843,   850,   857,   864,
     871,   878,   885,    -1,    -1,   844,   845,   846,    -1,   119,
      -1,  1010,    -1,   847,    -1,   848,    -1,    11,    -1,    10,
     849,   120,    -1,  1026,    -1,    -1,   851,   852,   853,    -1,
     105,    -1,  1010,    -1,   854,    -1,   855,    -1,    11,    -1,
      10,   856,   106,    -1,  1026,    -1,    -1,   858,   859,   860,
      -1,   107,    -1,  1010,    -1,   861,    -1,   862,    -1,    11,
      -1,    10,   863,   108,    -1,  1026,    -1,    -1,   865,   866,
     867,    -1,   103,    -1,  1010,    -1,   868,    -1,   869,    -1,
      11,    -1,    10,   870,   104,    -1,  1026,    -1,    -1,   872,
     873,   874,    -1,   149,    -1,  1010,    -1,   875,    -1,   876,
      -1,    11,    -1,    10,   877,   150,    -1,  1026,    -1,    -1,
     879,   880,   881,    -1,   193,    -1,  1010,    -1,   882,    -1,
     883,    -1,    11,    -1,    10,   884,   194,    -1,  1026,    -1,
      -1,   886,   887,   888,    -1,   207,    -1,  1010,    -1,   889,
      -1,   890,    -1,    11,    -1,    10,   891,   208,    -1,  1026,
      -1,    -1,   892,   893,    -1,   894,   895,   898,    -1,   163,
      -1,   896,    -1,    -1,   896,   897,    -1,  1008,    -1,  1011,
      -1,  1000,    -1,   984,    -1,   992,    -1,   971,    -1,   979,
      -1,   975,    -1,   899,    -1,   900,    -1,    10,   164,    -1,
      11,    -1,    10,   901,   164,    -1,   902,    -1,   911,    -1,
     903,    -1,   902,   903,    -1,   904,   905,   907,    -1,   125,
      -1,    -1,   905,   906,    -1,   983,    -1,   984,    -1,   908,
      -1,   909,    -1,    10,   126,    -1,    11,    -1,    10,   910,
     126,    -1,  1042,    -1,   912,    -1,   911,   912,    -1,   913,
     914,   917,    -1,   137,    -1,   915,    -1,    -1,   915,   916,
      -1,  1010,    -1,  1000,    -1,   975,    -1,   918,    -1,   919,
      -1,    11,    -1,    10,   920,   138,    -1,  1026,    -1,    -1,
     922,   923,   924,    -1,   169,    -1,  1018,    -1,   925,    -1,
     926,    -1,    10,   170,    -1,    11,    -1,    10,   927,   170,
      -1,   928,    -1,   929,    -1,   928,   929,    -1,   930,   931,
     934,    -1,   167,    -1,   932,    -1,    -1,   932,   933,    -1,
     984,    -1,  1000,    -1,   967,    -1,   975,    -1,  1012,    -1,
     935,    -1,   936,    -1,    10,   168,    -1,    11,    -1,    10,
     937,   168,    -1,   938,    -1,   939,    -1,   938,   939,    -1,
     940,    -1,   941,    -1,   942,    -1,    79,    -1,    80,    -1,
      77,   943,    78,    -1,     5,    -1,    -1,   945,   946,   947,
      -1,   171,    -1,  1021,    -1,   948,    -1,   949,    -1,    10,
     172,    -1,    11,    -1,    10,   950,   172,    -1,   951,    -1,
     952,    -1,   951,   952,    -1,   953,   954,   957,    -1,   185,
      -1,   955,    -1,    -1,   955,   956,    -1,   984,    -1,   967,
      -1,   975,    -1,  1012,    -1,   958,    -1,   959,    -1,    10,
     186,    -1,    11,    -1,    10,   960,   186,    -1,   961,    -1,
     962,    -1,   961,   962,    -1,   963,    -1,   964,    -1,   965,
      -1,    79,    -1,    80,    -1,    77,   966,    78,    -1,     5,
      -1,   968,    -1,   969,    -1,   970,    -1,    42,    -1,    41,
       3,  1043,    -1,   972,    -1,   973,    -1,   974,    -1,    50,
      -1,    49,     3,  1043,    -1,   976,    -1,   977,    -1,   978,
      -1,    44,    -1,    43,     3,  1043,    -1,   980,    -1,   981,
      -1,   982,    -1,    52,    -1,    51,     3,  1043,    -1,    37,
    1043,     6,  1043,    -1,   985,    -1,   986,    -1,   987,    -1,
      46,    -1,    45,     3,  1043,    -1,   989,    -1,   990,    -1,
     991,    -1,    54,    -1,    53,     3,  1043,    -1,   993,    -1,
     994,    -1,   995,    -1,    48,    -1,    47,     3,  1043,    -1,
     997,    -1,   998,    -1,   999,    -1,    58,    -1,    57,     3,
    1043,    -1,  1001,    -1,  1002,    -1,  1003,    -1,    60,    -1,
      59,     3,  1043,    -1,  1005,    -1,  1006,    -1,  1007,    -1,
      56,    -1,    55,     3,  1043,    -1,    16,  1043,     6,  1043,
      -1,    17,  1043,     6,  1043,    -1,    18,  1043,     6,  1043,
      -1,    19,  1043,     6,  1043,    -1,    21,  1043,     6,  1043,
      -1,    22,  1043,     6,  1043,    -1,    23,  1043,     6,  1043,
      -1,    24,  1043,     6,  1043,    -1,    25,  1043,     6,  1043,
      -1,    26,  1043,     6,  1043,    -1,    27,  1043,     6,  1043,
      -1,    28,  1043,     6,  1043,    -1,    29,  1043,     6,  1043,
      -1,    30,  1043,     6,  1043,    -1,    31,  1043,     6,  1043,
      -1,    32,  1043,     6,  1043,    -1,    33,  1043,     6,  1043,
      -1,    34,  1043,     6,  1043,    -1,  1027,    -1,  1034,    -1,
      -1,  1027,  1028,    -1,  1029,  1030,  1033,    -1,   135,    -1,
    1031,    -1,    -1,  1031,  1032,    -1,  1040,    -1,  1039,    -1,
      10,     6,   136,    -1,   117,  1035,  1036,    -1,    40,  1043,
       6,  1043,    -1,  1037,    -1,  1038,    -1,    10,   118,    -1,
      11,    -1,    10,     4,   118,    -1,    38,  1043,     6,  1043,
      -1,    39,  1043,     6,  1043,    -1,     6,    -1,     7,    -1,
       4,    -1,     6,    -1,     7,    -1,  1044,     8,    -1,    -1,
    1044,  1045,    -1,   228,    -1,   229,    -1,   230,    -1,   231,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   196,   198,   205,   215,   215,   217,   217,
     219,   221,   223,   232,   233,   236,   245,   245,   252,   266,
     266,   268,   270,   272,   274,   274,   277,   278,   279,   280,
     281,   283,   283,   291,   291,   293,   293,   295,   301,   301,
     309,   309,   311,   311,   313,   319,   319,   327,   327,   329,
     329,   331,   337,   337,   345,   345,   347,   347,   349,   355,
     355,   362,   362,   364,   364,   366,   377,   377,   379,   393,
     393,   395,   395,   397,   399,   401,   401,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   415,   417,   432,   439,
     439,   442,   447,   451,   460,   464,   469,   469,   471,   473,
     475,   475,   477,   482,   492,   498,   498,   501,   506,   512,
     512,   515,   517,   524,   524,   526,   526,   528,   530,   533,
     535,   542,   542,   544,   544,   546,   548,   553,   555,   562,
     562,   564,   564,   566,   568,   573,   575,   582,   582,   584,
     584,   586,   588,   593,   595,   602,   602,   604,   604,   606,
     608,   613,   615,   622,   622,   624,   624,   626,   628,   633,
     635,   642,   642,   644,   644,   646,   648,   653,   655,   662,
     672,   677,   683,   683,   685,   687,   689,   689,   691,   696,
     708,   714,   714,   717,   724,   729,   736,   736,   740,   740,
     742,   753,   753,   755,   755,   757,   759,   761,   761,   764,
     765,   766,   767,   768,   769,   772,   774,   781,   781,   783,
     783,   785,   787,   794,   796,   807,   809,   809,   812,   818,
     824,   826,   832,   834,   845,   847,   847,   850,   856,   862,
     864,   871,   873,   884,   886,   886,   889,   895,   901,   903,
     910,   912,   921,   922,   928,   930,   936,   938,   945,   955,
     960,   966,   966,   968,   970,   972,   972,   974,   979,   991,
     997,   997,  1000,  1007,  1012,  1018,  1018,  1022,  1022,  1024,
    1035,  1035,  1037,  1037,  1039,  1041,  1043,  1043,  1046,  1047,
    1048,  1049,  1050,  1051,  1054,  1056,  1063,  1063,  1065,  1065,
    1067,  1069,  1077,  1079,  1086,  1086,  1088,  1088,  1090,  1092,
    1097,  1099,  1106,  1106,  1108,  1108,  1110,  1112,  1117,  1119,
    1126,  1126,  1128,  1128,  1130,  1132,  1137,  1139,  1146,  1146,
    1148,  1148,  1150,  1152,  1159,  1161,  1168,  1178,  1183,  1189,
    1189,  1191,  1193,  1195,  1195,  1197,  1202,  1214,  1220,  1220,
    1223,  1230,  1235,  1242,  1242,  1245,  1245,  1247,  1263,  1263,
    1265,  1265,  1267,  1269,  1271,  1271,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  1287,  1289,  1296,
    1296,  1298,  1298,  1300,  1302,  1310,  1312,  1319,  1319,  1321,
    1321,  1323,  1325,  1330,  1332,  1339,  1339,  1341,  1341,  1343,
    1345,  1350,  1352,  1359,  1359,  1361,  1361,  1363,  1365,  1370,
    1372,  1379,  1379,  1381,  1381,  1383,  1385,  1390,  1392,  1399,
    1409,  1414,  1420,  1420,  1422,  1424,  1426,  1426,  1428,  1430,
    1444,  1444,  1447,  1447,  1447,  1447,  1450,  1450,  1452,  1452,
    1454,  1456,  1465,  1466,  1469,  1471,  1482,  1484,  1484,  1487,
    1493,  1499,  1501,  1508,  1510,  1521,  1523,  1523,  1526,  1532,
    1538,  1540,  1547,  1549,  1560,  1562,  1562,  1565,  1571,  1577,
    1579,  1586,  1588,  1598,  1599,  1605,  1607,  1614,  1616,  1623,
    1633,  1638,  1644,  1644,  1646,  1648,  1650,  1650,  1652,  1657,
    1669,  1675,  1675,  1678,  1685,  1690,  1697,  1697,  1700,  1700,
    1702,  1710,  1716,  1716,  1719,  1726,  1732,  1738,  1746,  1751,
    1757,  1757,  1759,  1761,  1763,  1763,  1765,  1767,  1776,  1778,
    1778,  1780,  1780,  1780,  1782,  1792,  1802,  1822,  1828,  1830,
    1840,  1846,  1846,  1849,  1854,  1859,  1869,  1874,  1880,  1880,
    1882,  1884,  1886,  1886,  1888,  1893,  1903,  1909,  1909,  1912,
    1918,  1925,  1925,  1928,  1928,  1930,  1932,  1932,  1934,  1934,
    1936,  1938,  1946,  1946,  1948,  1954,  1954,  1962,  1962,  1964,
    1966,  1968,  1970,  1970,  1972,  1974,  1982,  1987,  1993,  1993,
    1995,  1997,  1999,  1999,  2001,  2012,  2021,  2021,  2024,  2025,
    2028,  2031,  2031,  2033,  2035,  2043,  2048,  2054,  2054,  2056,
    2058,  2060,  2060,  2062,  2073,  2082,  2082,  2085,  2086,  2090,
    2091,  2093,  2093,  2095,  2097,  2102,  2102,  2104,  2109,  2109,
    2111,  2113,  2115,  2117,  2117,  2126,  2128,  2135,  2135,  2137,
    2139,  2141,  2144,  2144,  2154,  2156,  2163,  2163,  2165,  2167,
    2169,  2172,  2172,  2181,  2183,  2190,  2190,  2192,  2194,  2196,
    2199,  2199,  2208,  2210,  2217,  2217,  2219,  2221,  2223,  2226,
    2226,  2235,  2237,  2244,  2244,  2246,  2248,  2250,  2253,  2253,
    2262,  2264,  2271,  2271,  2273,  2275,  2277,  2280,  2280,  2289,
    2291,  2298,  2298,  2300,  2302,  2304,  2307,  2307,  2309,  2314,
    2333,  2339,  2339,  2342,  2353,  2364,  2370,  2376,  2382,  2388,
    2394,  2401,  2401,  2403,  2403,  2405,  2407,  2407,  2409,  2409,
    2411,  2418,  2427,  2427,  2430,  2436,  2443,  2443,  2445,  2445,
    2447,  2449,  2458,  2458,  2460,  2471,  2479,  2485,  2485,  2488,
    2494,  2495,  2499,  2499,  2501,  2503,  2506,  2510,  2510,  2512,
    2520,  2520,  2528,  2528,  2530,  2532,  2534,  2536,  2536,  2538,
    2540,  2548,  2553,  2559,  2559,  2561,  2563,  2566,  2566,  2568,
    2577,  2587,  2587,  2590,  2591,  2594,  2597,  2597,  2599,  2604,
    2604,  2607,  2609,  2611,  2613,  2613,  2622,  2624,  2631,  2631,
    2633,  2635,  2637,  2639,  2639,  2648,  2650,  2657,  2657,  2659,
    2661,  2663,  2666,  2666,  2675,  2677,  2684,  2684,  2686,  2688,
    2690,  2693,  2693,  2702,  2704,  2711,  2711,  2713,  2715,  2717,
    2720,  2720,  2729,  2731,  2738,  2738,  2740,  2742,  2744,  2747,
    2747,  2756,  2758,  2765,  2765,  2767,  2769,  2771,  2774,  2774,
    2783,  2785,  2792,  2792,  2794,  2796,  2798,  2801,  2801,  2803,
    2809,  2828,  2835,  2835,  2838,  2849,  2860,  2866,  2872,  2878,
    2884,  2890,  2899,  2899,  2901,  2901,  2903,  2905,  2905,  2907,
    2907,  2909,  2914,  2924,  2924,  2927,  2932,  2939,  2939,  2941,
    2941,  2943,  2945,  2952,  2952,  2954,  2965,  2973,  2979,  2979,
    2982,  2988,  2989,  2993,  2993,  2995,  2997,  3000,  3003,  3003,
    3005,  3012,  3012,  3020,  3020,  3022,  3024,  3026,  3028,  3028,
    3030,  3033,  3041,  3046,  3052,  3052,  3054,  3056,  3058,  3058,
    3060,  3069,  3078,  3078,  3081,  3082,  3085,  3088,  3088,  3090,
    3095,  3095,  3097,  3099,  3101,  3103,  3103,  3112,  3114,  3121,
    3121,  3123,  3125,  3127,  3129,  3129,  3138,  3140,  3147,  3147,
    3149,  3151,  3153,  3156,  3156,  3165,  3167,  3174,  3174,  3176,
    3178,  3180,  3183,  3183,  3192,  3194,  3201,  3201,  3203,  3205,
    3207,  3210,  3210,  3219,  3221,  3228,  3228,  3230,  3232,  3234,
    3237,  3237,  3246,  3248,  3255,  3255,  3257,  3259,  3261,  3264,
    3264,  3273,  3275,  3282,  3282,  3284,  3286,  3288,  3291,  3291,
    3293,  3299,  3318,  3324,  3324,  3327,  3338,  3349,  3355,  3361,
    3367,  3373,  3379,  3386,  3386,  3388,  3388,  3390,  3392,  3392,
    3394,  3394,  3396,  3403,  3412,  3412,  3416,  3421,  3429,  3429,
    3431,  3431,  3433,  3435,  3442,  3442,  3444,  3455,  3463,  3469,
    3469,  3472,  3478,  3479,  3483,  3483,  3485,  3487,  3489,  3493,
    3493,  3495,  3500,  3509,  3514,  3520,  3520,  3522,  3524,  3526,
    3526,  3528,  3533,  3547,  3555,  3555,  3558,  3564,  3570,  3576,
    3584,  3594,  3599,  3605,  3605,  3607,  3609,  3611,  3611,  3613,
    3619,  3624,  3626,  3626,  3628,  3630,  3642,  3642,  3644,  3649,
    3658,  3663,  3669,  3669,  3671,  3673,  3675,  3675,  3677,  3682,
    3694,  3702,  3702,  3705,  3710,  3716,  3722,  3731,  3736,  3742,
    3742,  3744,  3746,  3748,  3748,  3750,  3756,  3761,  3763,  3763,
    3765,  3767,  3778,  3785,  3785,  3787,  3792,  3797,  3804,  3804,
    3806,  3811,  3816,  3823,  3823,  3825,  3830,  3835,  3842,  3842,
    3844,  3849,  3854,  3862,  3869,  3869,  3871,  3876,  3881,  3888,
    3888,  3890,  3895,  3900,  3907,  3907,  3909,  3914,  3919,  3926,
    3926,  3928,  3933,  3938,  3945,  3945,  3947,  3952,  3957,  3964,
    3964,  3966,  3971,  3977,  3983,  3992,  3998,  4012,  4021,  4027,
    4036,  4042,  4048,  4054,  4060,  4066,  4075,  4081,  4090,  4095,
    4101,  4128,  4133,  4135,  4135,  4137,  4139,  4148,  4150,  4150,
    4152,  4152,  4154,  4162,  4164,  4169,  4169,  4171,  4171,  4173,
    4196,  4204,  4218,  4219,  4223,  4224,  4225,  4227,  4229,  4229,
    4231,  4232,  4233,  4234
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
  "osrlEnding", "osrlBody", "headerElement", "headerElementStart",
  "headerElementContent", "headerElementEmpty", "headerElementLaden",
  "headerElementBody", "headerElementList", "headerChild", "fileName",
  "fileNameContent", "fileNameEmpty", "fileNameLaden", "fileSource",
  "fileSourceContent", "fileSourceEmpty", "fileSourceLaden",
  "fileDescription", "fileDescriptionContent", "fileDescriptionEmpty",
  "fileDescriptionLaden", "fileCreator", "fileCreatorContent",
  "fileCreatorEmpty", "fileCreatorLaden", "fileLicence",
  "fileLicenceContent", "fileLicenceEmpty", "fileLicenceLaden",
  "generalElement", "generalElementStart", "generalElementContent",
  "generalElementEmpty", "generalElementLaden", "generalElementBody",
  "generalElementList", "generalChild", "generalStatus",
  "generalStatusStart", "generalStatusAttributes", "generalStatusAttList",
  "generalStatusATT", "generalStatusContent", "generalStatusEmpty",
  "generalStatusLaden", "generalStatusBody", "generalSubstatusArray",
  "generalSubstatus", "generalSubstatusStart",
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
     245,   246,   247,   248,   249,   249,   250,   250,   250,   250,
     250,   251,   251,   252,   252,   253,   253,   254,   255,   255,
     256,   256,   257,   257,   258,   259,   259,   260,   260,   261,
     261,   262,   263,   263,   264,   264,   265,   265,   266,   267,
     267,   268,   268,   269,   269,   270,   271,   271,   272,   273,
     273,   274,   274,   275,   276,   277,   277,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   279,   280,   281,   282,
     282,   283,   283,   283,   284,   284,   285,   285,   286,   287,
     288,   288,   289,   290,   291,   292,   292,   293,   293,   294,
     294,   295,   296,   297,   297,   298,   298,   299,   300,   301,
     302,   303,   303,   304,   304,   305,   306,   307,   308,   309,
     309,   310,   310,   311,   312,   313,   314,   315,   315,   316,
     316,   317,   318,   319,   320,   321,   321,   322,   322,   323,
     324,   325,   326,   327,   327,   328,   328,   329,   330,   331,
     332,   333,   333,   334,   334,   335,   336,   337,   338,   339,
     340,   340,   341,   341,   342,   343,   344,   344,   345,   346,
     347,   348,   348,   349,   349,   349,   350,   350,   351,   351,
     352,   353,   353,   354,   354,   355,   356,   357,   357,   358,
     358,   358,   358,   358,   358,   359,   360,   361,   361,   362,
     362,   363,   364,   365,   366,   367,   368,   368,   369,   369,
     370,   371,   372,   373,   374,   375,   375,   376,   376,   377,
     378,   379,   380,   381,   382,   382,   383,   383,   384,   385,
     386,   387,   388,   388,   389,   390,   391,   392,   393,   394,
     394,   395,   395,   396,   397,   398,   398,   399,   400,   401,
     402,   402,   403,   403,   403,   404,   404,   405,   405,   406,
     407,   407,   408,   408,   409,   410,   411,   411,   412,   412,
     412,   412,   412,   412,   413,   414,   415,   415,   416,   416,
     417,   418,   419,   420,   421,   421,   422,   422,   423,   424,
     425,   426,   427,   427,   428,   428,   429,   430,   431,   432,
     433,   433,   434,   434,   435,   436,   437,   438,   439,   439,
     440,   440,   441,   442,   443,   444,   445,   446,   446,   447,
     447,   448,   449,   450,   450,   451,   452,   453,   454,   454,
     455,   455,   455,   456,   456,   457,   457,   458,   459,   459,
     460,   460,   461,   462,   463,   463,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   465,   466,   467,
     467,   468,   468,   469,   470,   471,   472,   473,   473,   474,
     474,   475,   476,   477,   478,   479,   479,   480,   480,   481,
     482,   483,   484,   485,   485,   486,   486,   487,   488,   489,
     490,   491,   491,   492,   492,   493,   494,   495,   496,   497,
     498,   498,   499,   499,   500,   501,   502,   502,   503,   504,
     505,   505,   506,   506,   506,   506,   507,   507,   508,   508,
     509,   510,   511,   511,   512,   513,   514,   515,   515,   516,
     516,   517,   518,   519,   520,   521,   522,   522,   523,   523,
     524,   525,   526,   527,   528,   529,   529,   530,   530,   531,
     532,   533,   534,   535,   535,   536,   537,   538,   539,   540,
     541,   541,   542,   542,   543,   544,   545,   545,   546,   547,
     548,   549,   549,   550,   550,   550,   551,   551,   552,   552,
     553,   554,   555,   555,   556,   556,   556,   556,   557,   557,
     558,   558,   559,   560,   561,   561,   562,   563,   564,   565,
     565,   566,   566,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   574,   575,   575,   575,   576,   576,   577,   577,
     578,   579,   580,   580,   581,   582,   583,   584,   584,   585,
     585,   586,   586,   587,   587,   588,   589,   589,   590,   590,
     591,   592,   593,   593,   594,   595,   595,   596,   596,   597,
     598,   599,   600,   600,   601,   602,   603,   603,   604,   604,
     605,   606,   607,   607,   608,   609,   610,   610,   611,   611,
     612,   613,   613,   614,   615,   616,   616,   617,   617,   618,
     619,   620,   620,   621,   622,   623,   623,   624,   624,   625,
     625,   626,   626,   627,   628,   629,   629,   630,   631,   631,
     632,   633,   634,   635,   635,   636,   637,   638,   638,   639,
     640,   641,   642,   642,   643,   644,   645,   645,   646,   647,
     648,   649,   649,   650,   651,   652,   652,   653,   654,   655,
     656,   656,   657,   658,   659,   659,   660,   661,   662,   663,
     663,   664,   665,   666,   666,   667,   668,   669,   670,   670,
     671,   672,   673,   673,   674,   675,   676,   677,   677,   678,
     679,   680,   680,   681,   682,   683,   684,   684,   685,   686,
     687,   688,   688,   689,   689,   689,   689,   689,   689,   689,
     689,   690,   690,   691,   691,   692,   693,   693,   694,   694,
     695,   696,   697,   697,   698,   698,   699,   699,   700,   700,
     701,   702,   703,   703,   704,   705,   706,   707,   707,   708,
     708,   708,   709,   709,   710,   711,   712,   713,   713,   714,
     715,   715,   716,   716,   717,   718,   719,   720,   720,   721,
     722,   723,   723,   724,   724,   725,   726,   727,   727,   728,
     729,   730,   730,   731,   731,   732,   733,   733,   734,   735,
     735,   736,   737,   738,   739,   739,   740,   741,   742,   742,
     743,   744,   745,   746,   746,   747,   748,   749,   749,   750,
     751,   752,   753,   753,   754,   755,   756,   756,   757,   758,
     759,   760,   760,   761,   762,   763,   763,   764,   765,   766,
     767,   767,   768,   769,   770,   770,   771,   772,   773,   774,
     774,   775,   776,   777,   777,   778,   779,   780,   781,   781,
     782,   783,   784,   784,   785,   786,   787,   788,   788,   789,
     790,   791,   792,   792,   793,   793,   793,   793,   793,   793,
     793,   793,   794,   794,   795,   795,   796,   797,   797,   798,
     798,   799,   800,   801,   801,   802,   802,   803,   803,   804,
     804,   805,   806,   807,   807,   808,   809,   810,   811,   811,
     812,   812,   812,   813,   813,   814,   815,   816,   817,   817,
     818,   819,   819,   820,   820,   821,   822,   823,   824,   824,
     825,   826,   827,   827,   828,   828,   829,   830,   831,   831,
     832,   833,   834,   834,   835,   835,   836,   837,   837,   838,
     839,   839,   840,   841,   842,   843,   843,   844,   845,   846,
     846,   847,   848,   849,   850,   850,   851,   852,   853,   853,
     854,   855,   856,   857,   857,   858,   859,   860,   860,   861,
     862,   863,   864,   864,   865,   866,   867,   867,   868,   869,
     870,   871,   871,   872,   873,   874,   874,   875,   876,   877,
     878,   878,   879,   880,   881,   881,   882,   883,   884,   885,
     885,   886,   887,   888,   888,   889,   890,   891,   892,   892,
     893,   894,   895,   896,   896,   897,   897,   897,   897,   897,
     897,   897,   897,   898,   898,   899,   899,   900,   901,   901,
     902,   902,   903,   904,   905,   905,   906,   906,   907,   907,
     908,   908,   909,   910,   911,   911,   912,   913,   914,   915,
     915,   916,   916,   916,   917,   917,   918,   919,   920,   921,
     921,   922,   923,   924,   924,   925,   925,   926,   927,   928,
     928,   929,   930,   931,   932,   932,   933,   933,   933,   933,
     933,   934,   934,   935,   935,   936,   937,   938,   938,   939,
     940,   940,   941,   941,   942,   943,   944,   944,   945,   946,
     947,   947,   948,   948,   949,   950,   951,   951,   952,   953,
     954,   955,   955,   956,   956,   956,   956,   957,   957,   958,
     958,   959,   960,   961,   961,   962,   963,   963,   964,   964,
     965,   966,   967,   968,   968,   969,   970,   971,   972,   972,
     973,   974,   975,   976,   976,   977,   978,   979,   980,   980,
     981,   982,   983,   984,   985,   985,   986,   987,   988,   989,
     989,   990,   991,   992,   993,   993,   994,   995,   996,   997,
     997,   998,   999,  1000,  1001,  1001,  1002,  1003,  1004,  1005,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1026,  1027,  1027,  1028,  1029,  1030,  1031,  1031,
    1032,  1032,  1033,  1034,  1035,  1036,  1036,  1037,  1037,  1038,
    1039,  1040,  1041,  1041,  1042,  1042,  1042,  1043,  1044,  1044,
    1045,  1045,  1045,  1045
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     2,     1,     1,
       1,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     4,     3,     3,     8,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     0,     3,     1,     0,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       3,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     2,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     3,     7,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       0,     1,     1,     1,     1,     3,     3,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     0,     2,     1,     1,     3,     0,     2,     1,     1,
       1,     1,     3,     7,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     0,     1,     1,     1,     1,     3,     3,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     3,     0,     2,     1,
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
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     3,     3,     4,     1,     1,     2,     1,     3,
       4,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,    18,    14,    66,
       0,     7,     0,    13,     2,    12,    68,   188,     0,    31,
      21,    17,    19,    20,    16,    10,     3,     8,     9,   190,
     267,     0,     0,    72,    67,    69,    70,     0,    36,    35,
       0,    43,    42,     0,    50,    49,     0,    57,    56,     0,
      64,    63,     0,    23,    24,    26,    32,    33,    34,    27,
      39,    40,    41,    28,    46,    47,    48,    29,    53,    54,
      55,    30,    60,    61,    62,    14,   269,   345,     0,     0,
     194,   189,   191,   192,    71,    87,   136,   144,   112,   168,
     128,   120,   152,   160,     0,    74,    75,    77,     0,    78,
       0,    79,     0,    80,     0,    81,     0,    82,     0,    83,
       0,    84,     0,    85,     0,     0,     0,     0,     0,     0,
      22,    25,    11,   347,   488,     0,     0,   273,   268,   270,
     271,   193,   241,   232,   214,   223,   247,   206,     0,   196,
     197,   199,     0,   200,   216,   201,   225,   202,   234,   203,
     242,   204,     0,    73,    76,  1198,     0,  1115,     0,  1136,
       0,    88,    89,    92,  1112,  1113,  1114,    91,  1133,  1134,
    1135,    93,     0,   116,   111,   113,   114,     0,   124,   119,
     121,   122,     0,   132,   127,   129,   130,     0,   140,   135,
     137,   138,     0,   148,   143,   145,   146,     0,   156,   151,
     153,   154,     0,   164,   159,   161,   162,  1198,     0,   169,
      37,    44,    51,    58,    65,   490,    15,   492,     0,   351,
     346,   348,   349,   272,   293,   285,   325,   317,   309,   301,
       0,   275,   276,   278,     0,   279,     0,   280,     0,   281,
       0,   282,     0,   283,     0,   195,   198,     0,   210,   205,
     207,   208,     0,   215,     0,   224,     0,   233,     0,   243,
       0,   248,     0,     0,  1198,  1198,     0,    97,    86,    94,
      95,    90,   118,   115,     0,   126,   123,     0,   134,   131,
       0,   142,   139,     0,   150,   147,     0,   158,   155,     0,
     166,   163,     0,     0,     0,   173,   167,   170,   171,     0,
     491,   350,   392,   400,   468,   384,   368,   376,   408,   462,
     453,   435,   444,     0,   353,   354,   356,     0,   357,     0,
     358,     0,   359,     0,   360,     0,   361,     0,   362,   437,
     363,   446,   364,   455,   365,   463,   366,     0,   274,   277,
       0,   289,   284,   286,   287,     0,   297,   292,   294,   295,
       0,   305,   300,   302,   303,     0,   313,   308,   310,   311,
       0,   321,   316,   318,   319,     0,   326,   212,   209,     0,
       0,   213,     0,  1141,   217,   219,   218,  1138,  1139,  1140,
       0,   222,   226,   228,   227,     0,   231,   235,   237,   236,
       0,   240,     0,   252,   246,   249,   250,  1198,  1197,  1200,
    1201,  1202,  1203,  1199,  1116,  1137,    96,   103,     0,    99,
     100,   105,   117,   125,   133,   141,   149,   157,   165,  1198,
     179,   172,     0,   175,   176,   181,     0,   501,   489,   498,
     499,  1198,  1198,  1198,  1198,   493,   496,   497,   494,   495,
     352,   355,     0,   372,   367,   369,   370,     0,   380,   375,
     377,   378,     0,   388,   383,   385,   386,     0,   396,   391,
     393,   394,     0,   404,   399,   401,   402,  1198,     0,   409,
       0,   436,     0,   445,     0,   454,     0,   464,     0,   469,
     291,   288,     0,   299,   296,     0,   307,   304,     0,   315,
     312,     0,  1192,  1193,   320,     0,   323,     0,   330,   324,
     327,   328,   211,     0,   221,  1198,     0,   230,     0,   239,
     245,     0,   258,   251,     0,   254,   255,   260,  1167,    98,
     101,     0,   104,  1162,   174,   177,     0,   180,   500,   507,
       0,  1066,   504,   509,     0,     0,     0,     0,   374,   371,
       0,   382,   379,     0,   390,   387,     0,   398,   395,     0,
     406,   403,     0,     0,     0,   413,   407,   410,   411,     0,
     434,   438,   440,   439,     0,   443,   447,   449,   448,     0,
     452,   456,   458,   457,     0,   461,     0,   473,   467,   470,
     471,   290,   298,   306,   314,   322,   336,   329,     0,   332,
     333,   338,   220,  1142,   229,   238,   244,   253,   256,     0,
     259,     0,   110,   102,     0,  1126,   106,   108,   107,  1123,
    1124,  1125,     0,   187,   178,     0,  1146,   182,   185,   183,
     184,  1143,  1144,  1145,   502,  1068,   505,   503,     0,     0,
     508,  1198,  1198,  1198,  1198,   373,   381,   389,   397,   405,
    1198,   419,   412,     0,   415,   416,   420,     0,   442,     0,
     451,     0,   460,   466,     0,   479,   472,     0,   475,   476,
     481,   331,   334,     0,   337,     0,   266,   257,   261,   264,
     262,   263,   109,  1198,   186,  1198,  1198,     0,  1069,     0,
     506,  1198,     0,     0,   510,   511,   512,   513,  1154,  1159,
    1165,  1170,  1168,   414,   417,     0,   441,   450,   459,   465,
     474,   477,     0,   480,     0,   344,   335,   339,   342,   340,
     341,   265,  1127,  1147,     0,     0,  1073,  1067,  1070,  1071,
     519,   543,     0,     0,  1198,  1198,     0,   429,     0,  1105,
     421,   418,   426,   427,   424,  1102,  1103,  1104,   425,   423,
     422,     0,   487,   478,   482,   485,   483,   484,   343,  1198,
    1072,  1079,     0,  1075,  1076,  1081,   545,   552,     0,     0,
     520,   521,   524,   523,   525,  1198,   516,   515,   433,   432,
     428,     0,   431,  1198,   486,  1166,  1074,  1077,     0,  1080,
     554,   727,   555,     0,   549,   544,   546,   547,     0,   529,
     518,   526,   527,   522,   514,   430,  1106,     0,  1090,  1078,
    1087,  1088,  1198,  1082,  1084,  1085,  1083,  1086,   729,   878,
     730,  1198,     0,   556,   551,   548,     0,   528,   535,     0,
     531,   532,   537,     0,  1098,  1099,  1089,     0,  1092,  1093,
    1095,  1096,  1097,     0,   880,  1029,   881,  1198,     0,   731,
       0,   562,   559,   553,   557,   558,   550,   530,   533,     0,
     536,  1101,     0,  1091,  1094,  1198,  1031,     0,     0,  1198,
       0,   882,     0,   737,   734,   728,   732,   733,  1198,   564,
       0,   581,     0,     0,   542,   534,   538,   540,   539,  1100,
    1157,   517,  1198,     0,  1032,     0,   888,   885,   879,   883,
     884,  1198,   739,     0,   756,     0,  1164,   560,   583,   605,
       0,  1198,     0,   565,   541,     0,     0,  1036,  1030,  1033,
    1034,  1198,   890,     0,   907,     0,  1161,   735,   758,   827,
       0,  1198,     0,   740,   607,   676,     0,     0,   584,     0,
       0,   569,   563,   566,   567,  1198,  1042,  1035,     0,  1038,
    1039,  1044,  1160,   886,   909,   978,     0,  1198,     0,   891,
     736,   764,   761,   757,   759,   760,     0,     0,   744,   738,
     741,   742,   561,   613,   610,   606,   608,   609,     0,   588,
     582,   585,   586,  1198,   568,   575,     0,   571,   572,   576,
    1163,  1037,  1040,     0,  1043,   887,   915,   912,   908,   910,
     911,     0,     0,   895,   889,   892,   893,   830,   828,   832,
     766,     0,   773,     0,  1198,   750,   743,     0,   746,   747,
     751,   679,   677,   681,   615,     0,   622,     0,   587,   594,
       0,   590,   591,   595,  1169,   570,   573,     0,     0,  1054,
    1041,  1051,  1052,  1045,  1048,  1049,  1046,  1047,  1050,   981,
     979,   983,   917,     0,   924,     0,  1198,   901,   894,     0,
     897,   898,   902,     0,   831,   762,   775,   782,     0,  1198,
       0,   767,  1158,   745,   748,     0,     0,   680,   611,   624,
     631,     0,     0,   616,   589,   592,     0,     0,  1198,   577,
     574,   578,   579,     0,  1062,  1063,  1053,     0,  1056,  1057,
    1059,  1060,  1061,     0,   982,   913,   926,   933,     0,     0,
     918,  1153,   896,   899,     0,     0,   845,   829,   842,   843,
    1198,     0,  1120,     0,  1131,   833,   841,   840,  1117,  1118,
    1119,   837,   839,  1128,  1129,  1130,   838,   836,   835,   834,
     784,   791,     0,     0,   776,     0,  1173,   770,   765,   768,
     769,     0,   752,   749,   753,   754,     0,   694,   678,   691,
     692,     0,  1151,   682,   690,   689,   686,   687,   685,   688,
    1148,  1149,  1150,   684,   683,   633,   640,     0,     0,   625,
    1173,   619,   614,   617,   618,     0,   602,   596,   593,   599,
     600,   597,   598,     0,     0,  1065,     0,  1055,  1058,     0,
     996,   980,   993,   994,     0,  1110,   984,   990,  1107,  1108,
    1109,   992,   991,   988,   989,   987,   985,   986,   935,   942,
       0,     0,   927,  1173,   921,   916,   919,   920,     0,   903,
     900,   904,   905,   866,   852,   844,     0,   847,   849,   853,
     848,   863,   868,     0,  1198,  1198,   793,   800,     0,     0,
     785,  1173,   779,   774,   777,   778,  1198,     0,     0,   772,
    1171,  1172,     0,   715,   693,   701,     0,   696,   698,   702,
     697,   712,   717,  1198,   642,   649,     0,     0,   634,  1173,
     628,   623,   626,   627,     0,   621,   604,   601,     0,   580,
    1198,  1064,  1003,  1017,   995,     0,   998,  1000,  1004,   999,
    1014,  1019,  1198,   944,   951,     0,     0,   936,  1173,   930,
     925,   928,   929,     0,   923,     0,   846,   850,     0,   864,
       0,   867,  1198,  1121,  1132,   802,   809,     0,     0,   794,
    1173,   788,   783,   786,   787,     0,   781,  1155,  1198,     0,
     771,  1176,  1174,  1178,   755,   695,   699,     0,   713,     0,
     716,  1152,   651,   658,     0,     0,   643,  1173,   637,   632,
     635,   636,     0,   630,   620,   603,  1122,   997,  1001,     0,
    1015,     0,  1018,  1111,   953,   960,     0,     0,   945,  1173,
     939,   934,   937,   938,     0,   932,   922,   906,     0,   860,
     854,   851,   857,   858,   855,   856,  1173,   875,   865,   873,
     874,   869,   872,   871,   870,  1156,   811,   818,     0,     0,
     803,  1173,   797,   792,   795,   796,     0,   790,   780,     0,
       0,  1188,  1183,  1185,  1186,     0,  1177,     0,   709,   703,
     700,   706,   707,   704,   705,  1173,   724,   714,   722,   723,
     718,   721,   720,   719,   660,   667,     0,     0,   652,  1173,
     646,   641,   644,   645,     0,   639,   629,     0,  1011,  1005,
    1002,  1008,  1009,  1006,  1007,  1173,  1026,  1016,  1024,  1025,
    1020,  1023,  1022,  1021,   962,   969,     0,     0,   954,  1173,
     948,   943,   946,   947,     0,   941,   931,  1194,  1195,  1196,
     859,     0,   862,     0,   877,   820,   763,     0,     0,   812,
    1173,   806,   801,   804,   805,     0,   799,   789,  1198,     0,
    1187,     0,  1175,  1198,  1198,  1179,  1181,  1180,   708,     0,
     711,     0,   726,   669,   612,     0,     0,   661,  1173,   655,
     650,   653,   654,     0,   648,   638,  1010,     0,  1013,     0,
    1028,   971,   914,     0,     0,   963,  1173,   957,   952,   955,
     956,     0,   950,   940,   861,   876,     0,   821,  1173,   815,
     810,   813,   814,     0,   808,   798,  1184,  1189,     0,     0,
       0,   710,   725,     0,   670,  1173,   664,   659,   662,   663,
       0,   657,   647,  1012,  1027,     0,   972,  1173,   966,   961,
     964,   965,     0,   959,   949,  1173,   824,   819,   822,   823,
       0,   817,   807,  1182,  1198,  1198,  1173,   673,   668,   671,
     672,     0,   666,   656,  1173,   975,   970,   973,   974,     0,
     968,   958,     0,   826,   816,  1190,  1191,     0,   675,   665,
       0,   977,   967,   825,   674,   976
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    26,    27,    28,    14,    15,
       8,     9,    10,    21,    22,    23,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    17,
      18,    34,    35,    36,    94,    95,    96,    97,    98,   160,
     161,   162,   268,   269,   270,   408,   409,   410,   411,   521,
     522,   606,   603,    99,   100,   174,   175,   176,   274,   101,
     102,   179,   180,   181,   277,   103,   104,   184,   185,   186,
     280,   105,   106,   189,   190,   191,   283,   107,   108,   194,
     195,   196,   286,   109,   110,   199,   200,   201,   289,   111,
     112,   204,   205,   206,   292,   113,   114,   208,   296,   297,
     298,   422,   423,   424,   425,   526,   527,   617,   614,    30,
      31,    81,    82,    83,   138,   139,   140,   141,   142,   249,
     250,   251,   369,   143,   144,   252,   253,   374,   371,   503,
     145,   146,   254,   255,   382,   381,   506,   147,   148,   256,
     257,   387,   386,   508,   149,   150,   258,   391,   511,   151,
     152,   260,   394,   395,   396,   514,   515,   516,   517,   599,
     600,   668,   667,    77,    78,   128,   129,   130,   230,   231,
     232,   233,   234,   342,   343,   344,   482,   235,   236,   347,
     348,   349,   485,   237,   238,   352,   353,   354,   488,   239,
     240,   357,   358,   359,   491,   241,   242,   362,   363,   364,
     495,   243,   244,   365,   499,   500,   501,   588,   589,   590,
     591,   663,   664,   707,   706,   124,   125,   220,   221,   222,
     313,   314,   315,   316,   317,   444,   445,   446,   540,   318,
     319,   449,   450,   451,   543,   320,   321,   454,   455,   456,
     546,   322,   323,   459,   460,   461,   549,   324,   325,   464,
     465,   466,   552,   326,   327,   468,   556,   557,   558,   643,
     644,   645,   646,   695,   730,   731,   732,   733,   771,   772,
     328,   329,   470,   471,   561,   560,   647,   330,   331,   472,
     473,   566,   565,   649,   332,   333,   474,   475,   571,   570,
     651,   334,   335,   476,   575,   654,   336,   337,   478,   578,
     579,   580,   657,   658,   659,   660,   702,   703,   744,   743,
     216,   217,   299,   300,   435,   428,   429,   430,   530,   531,
     532,   533,   629,   630,   684,   685,   686,   687,   680,   721,
     722,   759,   760,   761,   790,   791,   792,   819,   820,   821,
     822,   849,   850,   876,   875,   757,   758,   785,   786,   787,
     816,   781,   782,   812,   843,   844,   845,   870,   871,   872,
     902,   932,   933,   934,   976,   977,   978,   979,  1027,  1079,
    1080,   899,   900,   927,   970,   971,   972,  1020,  1021,  1022,
    1023,  1076,  1177,  1178,  1179,  1180,  1278,   925,   926,   965,
     966,   967,  1015,  1016,  1017,  1072,  1172,  1173,  1174,  1274,
    1070,  1071,  1168,  1271,  1272,  1273,  1352,  1166,  1167,  1267,
    1349,  1350,  1351,  1444,  1265,  1266,  1345,  1441,  1442,  1443,
    1523,  1343,  1344,  1437,  1520,  1521,  1522,  1570,  1435,  1436,
    1516,  1567,  1568,  1569,  1601,  1514,  1515,  1563,  1598,  1599,
    1600,  1617,   962,  1012,  1013,  1066,  1067,  1153,  1148,  1149,
    1150,  1256,  1257,  1258,  1259,  1337,  1419,  1420,  1421,  1422,
    1509,  1260,  1261,  1262,  1339,  1340,  1430,  1427,  1428,  1429,
    1511,   809,   810,   838,   865,   866,   867,   893,   894,   895,
     922,   959,   960,   961,  1007,  1008,  1009,  1010,  1065,  1142,
    1143,   919,   920,   953,   954,   955,  1001,  1002,  1003,  1060,
    1138,  1139,  1140,  1248,  1057,  1058,  1133,  1243,  1244,  1245,
    1325,  1131,  1132,  1239,  1322,  1323,  1324,  1406,  1237,  1238,
    1318,  1403,  1404,  1405,  1495,  1316,  1317,  1399,  1492,  1493,
    1494,  1553,  1397,  1398,  1488,  1550,  1551,  1552,  1590,  1486,
    1487,  1546,  1587,  1588,  1589,  1612,   950,   998,   999,  1053,
    1054,  1115,  1107,  1108,  1109,  1226,  1227,  1228,  1229,  1308,
    1380,  1381,  1382,  1383,  1481,  1230,  1231,  1232,  1310,  1311,
    1391,  1388,  1389,  1390,  1483,   835,   836,   860,   888,   889,
     890,   913,   914,   915,   948,   994,   995,   996,  1049,  1050,
    1051,  1052,  1104,  1219,  1220,   945,   946,   988,   989,   990,
    1043,  1044,  1045,  1099,  1215,  1216,  1217,  1303,  1097,  1098,
    1211,  1300,  1301,  1302,  1374,  1209,  1210,  1296,  1371,  1372,
    1373,  1474,  1294,  1295,  1367,  1471,  1472,  1473,  1541,  1365,
    1366,  1467,  1538,  1539,  1540,  1582,  1465,  1466,  1534,  1579,
    1580,  1581,  1609,  1532,  1533,  1575,  1606,  1607,  1608,  1620,
     985,  1040,  1041,  1093,  1094,  1196,  1191,  1192,  1193,  1285,
    1286,  1287,  1288,  1359,  1449,  1450,  1451,  1452,  1527,  1289,
    1290,  1291,  1361,  1362,  1460,  1457,  1458,  1459,  1529,   857,
     858,   883,   908,   909,   910,   938,   939,   940,   941,   983,
     984,  1033,  1030,  1031,  1032,  1087,  1088,  1089,  1090,  1091,
    1092,  1186,   627,   628,   677,   717,   718,   719,   752,   753,
     754,   755,   778,   779,   803,   799,   800,   801,   827,   828,
     829,   830,   831,   832,   852,   734,   735,   736,   737,  1197,
    1198,  1199,  1200,   163,   164,   165,   166,  1117,  1118,  1119,
    1120,  1081,   608,   609,   610,   611,  1122,  1123,  1124,  1125,
     167,   168,   169,   170,   376,   377,   378,   379,   620,   621,
     622,   623,  1159,  1160,  1161,  1162,   949,   436,  1061,  1128,
     807,   923,   437,   861,   839,   209,   884,   813,   438,   678,
     171,   469,   903,   439,  1249,  1250,  1332,  1333,  1415,  1416,
    1505,  1502,  1251,  1329,  1412,  1413,  1414,  1506,  1507,   496,
    1482,   262,   263,   403
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1337
static const yytype_int16 yypact[] =
{
      71, -1337, -1337,    60,     3,    50, -1337, -1337,    91,   105,
      78, -1337,   184, -1337, -1337, -1337, -1337,    43,   200,   554,
   -1337, -1337, -1337, -1337,     3, -1337, -1337, -1337, -1337, -1337,
      95,   218,   -26, -1337, -1337, -1337, -1337,   212, -1337, -1337,
     249, -1337, -1337,   251, -1337, -1337,   261, -1337, -1337,   273,
   -1337, -1337,   157,   554, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,    91, -1337,   221,   228,   -17,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   232,   194, -1337, -1337,   436, -1337,
     272, -1337,   309, -1337,   327, -1337,   350, -1337,   365, -1337,
     390, -1337,   393, -1337,   270,   244,   238,   265,   268,   282,
   -1337, -1337, -1337, -1337,   312,   398,   102, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   313,   148,
   -1337, -1337,   400, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     387, -1337,   270, -1337, -1337, -1337,   388, -1337,   403, -1337,
     426,   436, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,    28, -1337, -1337, -1337, -1337,    13, -1337, -1337,
   -1337, -1337,    30, -1337, -1337, -1337, -1337,    33, -1337, -1337,
   -1337, -1337,    32, -1337, -1337, -1337, -1337,    16, -1337, -1337,
   -1337, -1337,     6, -1337, -1337, -1337, -1337, -1337,   428, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,    82, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     351,   -36, -1337, -1337,   438, -1337,   440, -1337,   445, -1337,
     477, -1337,   482, -1337,   270, -1337, -1337,     8, -1337, -1337,
   -1337, -1337,   422,   192,   424,   192,   431,   192,   447, -1337,
     485, -1337,   458,    15, -1337, -1337,   -81, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   319, -1337, -1337,   293, -1337, -1337,
     299, -1337, -1337,   330, -1337, -1337,   329, -1337, -1337,   316,
   -1337, -1337,   318,   532,   -63, -1337, -1337, -1337, -1337,   487,
     118, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   466,   119, -1337, -1337,   493, -1337,   495,
   -1337,   497, -1337,   499, -1337,   501, -1337,   545, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   387, -1337,   270, -1337, -1337,
      41, -1337, -1337, -1337, -1337,    40, -1337, -1337, -1337, -1337,
       1, -1337, -1337, -1337, -1337,     5, -1337, -1337, -1337, -1337,
      23, -1337, -1337, -1337, -1337,   504, -1337, -1337, -1337,   361,
     516, -1337,   564, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     516, -1337, -1337, -1337, -1337,   516, -1337, -1337, -1337, -1337,
     567, -1337,   -21, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   437,   414,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   449,   448, -1337, -1337,   -22, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,    31, -1337, -1337, -1337, -1337,    11, -1337, -1337,
   -1337, -1337,    35, -1337, -1337, -1337, -1337,    48, -1337, -1337,
   -1337, -1337,    36, -1337, -1337, -1337, -1337, -1337,   514, -1337,
     624,   192,   626,   192,   630,   192,   634, -1337,   519, -1337,
   -1337, -1337,   542, -1337, -1337,   563, -1337, -1337,   503, -1337,
   -1337,   513, -1337, -1337, -1337,   546, -1337,     2, -1337, -1337,
   -1337, -1337, -1337,   587, -1337, -1337,   609, -1337,   591, -1337,
   -1337,   605, -1337, -1337,   566,   568, -1337, -1337, -1337, -1337,
   -1337,   521,   266, -1337, -1337, -1337,   523,   417, -1337, -1337,
     651,   -27, -1337, -1337,   723,   724,   727,   728, -1337, -1337,
     547, -1337, -1337,   548, -1337, -1337,   562, -1337, -1337,   635,
   -1337, -1337,   601,   733,   -44, -1337, -1337, -1337, -1337,   516,
   -1337, -1337, -1337, -1337,   516, -1337, -1337, -1337, -1337,   516,
   -1337, -1337, -1337, -1337,   736, -1337,    99, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   577,   581,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   525,
     417,   555, -1337, -1337,   743, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   584, -1337, -1337,   746, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   720,   741,
      63, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   549,   557, -1337, -1337,   544, -1337,   536,
   -1337,   551, -1337, -1337,   558, -1337, -1337,   589,   593, -1337,
   -1337, -1337, -1337,   533,   417,   595, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   535, -1337,   570,
   -1337, -1337,   757,   758, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,    75, -1337, -1337, -1337, -1337,
   -1337, -1337,   538,   417,   598, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   759,  -105, -1337, -1337, -1337, -1337,
   -1337,   611,   436,   763, -1337, -1337,    20, -1337,   767, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   607, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   600,   594, -1337, -1337, -1337,   553,   541,   543,
     436, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   575, -1337, -1337, -1337, -1337, -1337, -1337,   550,   401,
   -1337,   618,   749,    34, -1337, -1337, -1337, -1337,    84, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,    -7, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   653,
     753, -1337,   552, -1337, -1337, -1337,   627, -1337, -1337,   596,
     602, -1337, -1337,   778, -1337, -1337, -1337,   604,   237, -1337,
   -1337, -1337, -1337,   779, -1337,   617,   764, -1337,   559, -1337,
     781,   572, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   561,
     442, -1337,   714, -1337, -1337, -1337, -1337,   613,   769, -1337,
     565, -1337,   785,   582, -1337, -1337, -1337, -1337, -1337, -1337,
     574,   585,   761,   608, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   576, -1337,   795,   669, -1337, -1337, -1337,
   -1337, -1337, -1337,   648,   682,   783, -1337, -1337, -1337,   686,
     761, -1337,   583, -1337, -1337,   802,    29, -1337, -1337, -1337,
   -1337, -1337, -1337,   684,   688,   794, -1337, -1337, -1337, -1337,
     588, -1337,   590, -1337, -1337, -1337,   592,   597, -1337,   807,
     115, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   644,   650,
   -1337, -1337, -1337, -1337, -1337, -1337,   599, -1337,   603, -1337,
     655,   696, -1337, -1337, -1337, -1337,   810,  -104, -1337, -1337,
   -1337, -1337,   657,   700, -1337, -1337, -1337, -1337,   306, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   606,   610, -1337, -1337,
   -1337, -1337, -1337,   612,   308,   659,   702, -1337, -1337, -1337,
   -1337,   817,    55, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   703,   721,   809, -1337, -1337, -1337,   614,   673, -1337,
   -1337, -1337, -1337, -1337, -1337,   708,   729,   809, -1337, -1337,
     615,   619, -1337, -1337, -1337, -1337, -1337,   231,    -1, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   715,   737,   809, -1337, -1337, -1337,   704,
     716, -1337, -1337,   616,   537, -1337, -1337,   722,   809, -1337,
     645, -1337, -1337, -1337, -1337,   242,   647,   573, -1337, -1337,
     738,   809,   649, -1337, -1337, -1337,    45,   516, -1337, -1337,
   -1337, -1337, -1337,   838, -1337, -1337, -1337,   676,   317, -1337,
   -1337, -1337, -1337,   652,   369, -1337, -1337,   739,   809,   654,
   -1337, -1337, -1337, -1337,   336,    -9, -1337, -1337, -1337, -1337,
   -1337,   844, -1337,   845, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   747,   809,   656, -1337,   843,   740, -1337, -1337, -1337,
   -1337,   516, -1337, -1337, -1337, -1337,   -87, -1337, -1337, -1337,
   -1337,   850, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   751,   809,   658, -1337,
     740, -1337, -1337, -1337, -1337,     0, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   633,   852, -1337,   782, -1337, -1337,   -24,
   -1337, -1337, -1337, -1337,   853, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   756,
     809,   660, -1337,   740, -1337, -1337, -1337, -1337,   516, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   698,   706, -1337, -1337,
     726, -1337, -1337,   858, -1337, -1337, -1337,   717,   809,   662,
   -1337,   740, -1337, -1337, -1337, -1337, -1337,   825,   748, -1337,
     732, -1337,   718, -1337, -1337, -1337,   705,   661, -1337, -1337,
     735, -1337, -1337, -1337, -1337,   730,   809,   666, -1337,   740,
   -1337, -1337, -1337, -1337,   750, -1337, -1337, -1337,   663, -1337,
   -1337, -1337, -1337, -1337, -1337,   712,   752, -1337, -1337,   744,
   -1337, -1337, -1337, -1337,   731,   809,   668, -1337,   740, -1337,
   -1337, -1337, -1337,   755, -1337,   760, -1337, -1337,   294, -1337,
     670,   230, -1337, -1337, -1337, -1337,   680,   809,   672, -1337,
     740, -1337, -1337, -1337, -1337,   772, -1337, -1337, -1337,   675,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   347, -1337,   677,
     230, -1337, -1337,   690,   809,   679, -1337,   740, -1337, -1337,
   -1337, -1337,   784, -1337, -1337, -1337, -1337, -1337, -1337,   353,
   -1337,   681,   230, -1337, -1337,   691,   809,   685, -1337,   740,
   -1337, -1337, -1337, -1337,   786, -1337, -1337, -1337,    37, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   740, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   692,   809,   687,
   -1337,   740, -1337, -1337, -1337, -1337,   780, -1337, -1337,   881,
      44, -1337, -1337, -1337, -1337,   879,   526,    18, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   740, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   693,   809,   689, -1337,   740,
   -1337, -1337, -1337, -1337,   787, -1337, -1337,    59, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   740, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337,   694,   809,   695, -1337,   740,
   -1337, -1337, -1337, -1337,   788, -1337, -1337, -1337, -1337, -1337,
   -1337,   742, -1337,   766, -1337, -1337, -1337,   809,   697, -1337,
     740, -1337, -1337, -1337, -1337,   789, -1337, -1337, -1337,   773,
   -1337,   888, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   683,
   -1337,   770, -1337, -1337, -1337,   809,   701, -1337,   740, -1337,
   -1337, -1337, -1337,   793, -1337, -1337, -1337,   776, -1337,   771,
   -1337, -1337, -1337,   809,   707, -1337,   740, -1337, -1337, -1337,
   -1337,   803, -1337, -1337, -1337, -1337,   709, -1337,   740, -1337,
   -1337, -1337, -1337,   762, -1337, -1337, -1337, -1337,   774,   905,
     907, -1337, -1337,   711, -1337,   740, -1337, -1337, -1337, -1337,
     765, -1337, -1337, -1337, -1337,   713, -1337,   740, -1337, -1337,
   -1337, -1337,   768, -1337, -1337,   740, -1337, -1337, -1337, -1337,
     734, -1337, -1337, -1337, -1337, -1337,   740, -1337, -1337, -1337,
   -1337,   745, -1337, -1337,   740, -1337, -1337, -1337, -1337,   754,
   -1337, -1337,   719, -1337, -1337, -1337, -1337,   725, -1337, -1337,
     775, -1337, -1337, -1337, -1337, -1337
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   839, -1337,
     892, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   864, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   826, -1337, -1337, -1337,
   -1337,   777, -1337, -1337, -1337, -1337, -1337,   511, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   500, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   790, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,   407, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     699, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   335,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,   620, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,   281, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337,   274, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     395, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,   171, -1337, -1337, -1337, -1337, -1337,   116,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   -42, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,   -84,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,  -317, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337,  -319, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,   -66, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -284, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,  -286, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    -103, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337,  -341, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    -340, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,    12, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -138, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     199, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
     125, -1337, -1337, -1337, -1337,  -768, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337,  -148, -1337, -1337, -1337,  -963, -1337, -1337,
   -1337, -1057,  -526, -1337, -1337, -1337, -1337, -1337, -1337, -1337,
    -689, -1337, -1337, -1337,  -241, -1337, -1337, -1337,  -595, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337,  -140, -1337,  -996,  -930,
     -29,   -98, -1337, -1337, -1337,  -124, -1337, -1337, -1337, -1337,
    -663, -1337,  -869, -1337, -1083, -1337, -1337, -1337, -1337, -1337,
   -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337, -1337,  -367,
   -1336,  -207, -1337, -1337
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     293,   619,   259,   504,  1276,   671,   739,   486,  1144,   489,
     290,   804,   367,   507,   384,   541,   389,   275,   509,  1181,
     287,  1073,  1477,   398,  1478,  1479,   768,   769,   261,   492,
     493,   928,   272,   763,   278,   538,   284,   281,   814,   544,
     550,  1477,    84,  1478,  1479,   480,   483,  1221,  1499,  1100,
    1253,  1005,   547,   131,   528,  1175,  1176,   404,   405,   764,
       6,   406,  1134,  1477,    11,  1478,  1479,   750,     7,   710,
     823,   763,   824,   825,   670,  1169,  1083,  1254,  1084,  1085,
     751,  1510,  1078,     1,     2,   726,   727,  1275,    19,    20,
     604,   605,   132,   224,   133,   225,   134,   764,   135,   681,
     420,  1282,  1212,   421,  1155,   375,    13,   383,   747,   388,
     407,  1528,    29,  1283,  1006,    85,   728,   729,   156,   157,
     366,    86,   158,   159,   682,    87,   683,    88,  1223,   226,
    1304,  1202,   372,   373,  1255,   431,  1240,  1163,   709,    89,
    1284,   432,   512,   227,   625,   513,  1224,   433,   136,    90,
     548,    91,   434,   641,   529,  1225,   301,    92,  1326,   529,
     642,   878,  1500,   228,  1207,   586,    76,  1086,   587,   229,
     484,  1268,    16,   481,   223,    93,   551,   746,   137,   826,
    1047,   282,   273,   302,   285,  1526,  1353,   477,   815,  1048,
     518,   276,   648,  1480,    24,    25,   936,   650,  1164,   937,
     288,   542,   652,   494,   368,   490,   279,   487,   291,   545,
      32,    33,   523,   479,  1297,  1375,  1034,   115,   770,   539,
     302,   303,  1277,   120,   534,   535,   536,   537,    79,    80,
     563,   224,   568,   225,   573,   156,   157,  1407,   126,   127,
    1508,  1077,  1319,   399,   400,   401,   402,   304,  1059,   372,
     373,  1384,  1141,   806,   116,   305,   117,   132,   303,   133,
     553,   134,   655,   135,  1445,   656,   118,   226,  1078,   306,
    1346,   307,   817,   156,   157,   818,   604,   605,   119,  1078,
    1423,   227,   172,   173,   304,   308,  1475,   604,   605,   615,
     616,   309,   305,   310,   123,   311,   207,   312,   593,  1368,
     153,   228,  1453,  1484,  1378,  1379,   306,   229,   307,   156,
     157,   604,   605,   136,   823,  1394,   824,   825,  1496,   177,
     178,  1400,   308,   562,   211,   567,   210,   572,   309,   802,
     310,  1078,   311,   974,   312,    85,   975,   182,   183,   604,
     605,    86,  1512,   137,  1433,    87,  1218,    88,  1438,   728,
     729,   156,   157,   604,   605,   212,  1524,  1417,  1418,    89,
     187,   188,   213,  1447,  1448,  1126,  1463,   615,   616,    90,
    1468,    91,  1530,  1078,   607,   192,   193,    92,  1157,   618,
     214,   604,   605,   245,  1078,   947,  1542,   215,  1110,  1037,
    1078,   264,   604,   605,  1083,    93,  1084,  1085,   604,   605,
     197,   198,  1489,   202,   203,  1204,   265,  1554,   218,   219,
     247,   248,   156,   157,   604,   605,   158,   159,  1194,  1195,
    1111,  1112,   802,   338,   688,   689,   690,   691,   615,   616,
     156,   157,   370,   692,   380,  1571,   266,   267,   294,   295,
    1517,   385,   728,   729,   156,   157,   604,   605,   340,   341,
     345,   346,   669,  1583,   740,   350,   351,   390,  1036,  1127,
     156,   157,   604,   605,   397,  1591,   712,   155,   713,   714,
    1535,   413,  1158,   412,   723,   414,   615,   616,   415,   156,
     157,   416,  1602,   158,   159,   156,   157,   355,   356,   158,
     159,  1547,   360,   361,  1610,   392,   393,   426,   427,  1205,
     417,  1082,  1613,   442,   443,   447,   448,   452,   453,   457,
     458,   462,   463,  1618,   497,   498,   708,   766,   767,  1564,
     418,  1621,   492,   493,   554,   555,  1018,  1019,  1121,   576,
     577,   601,   602,   612,   613,   665,   666,  1576,   419,  1145,
     440,  1156,   775,   704,   705,   715,   716,   738,   741,   742,
    1182,   783,   784,   788,   789,   745,  1110,   502,   794,   921,
     797,   798,   841,   842,  1503,  1504,   796,   505,  1203,   863,
     864,   873,   874,   510,   762,   886,   887,   467,  1222,   519,
     156,   157,   604,   605,   158,   159,   906,   907,  1111,  1112,
    1113,  1114,  1110,   930,   931,   833,   615,   616,   951,   952,
     957,   958,   963,   964,   840,   407,   901,   968,   969,   986,
     987,   420,   762,   992,   993,   524,   156,   157,   604,   605,
     158,   159,  1028,  1029,  1111,  1112,  1105,  1106,  1151,  1152,
     862,   805,   615,   616,   559,    37,   564,    38,    39,    40,
     569,    41,    42,    43,   574,    44,    45,    46,   880,    47,
      48,    49,   885,    50,    51,  1136,  1137,  1146,  1147,  1170,
    1171,   896,  1189,  1190,  1213,  1214,  1241,  1242,  1269,  1270,
    1298,  1299,  1320,  1321,   581,   905,  1347,  1348,  1369,  1370,
    1386,  1387,  1401,  1402,   916,  1410,  1411,  1425,  1426,  1439,
    1440,  1455,  1456,   582,   929,  1469,  1470,  1490,  1491,  1518,
    1519,   592,   877,   595,   942,  1536,  1537,  1548,  1549,   583,
    1183,  1565,  1566,   584,   956,   596,  1393,  1577,  1578,  1585,
    1586,  1596,  1597,  1604,  1605,   594,   585,   624,   980,   631,
     632,   512,   597,   633,   634,   635,   637,   638,   636,   640,
     991,   639,   653,   661,   586,  1432,   673,   672,   674,   675,
     676,   679,   697,   693,   641,   700,   655,   720,   696,   711,
     724,   725,   748,   698,   756,   749,  1024,  1462,   699,   765,
     773,   774,   776,   795,  1252,   808,   780,   811,   837,   751,
     834,   846,  1385,   851,   847,   855,   856,   868,   859,   869,
     853,   891,   879,   818,   901,   881,   882,  1062,   897,   892,
     904,   911,   912,   918,   898,   921,   917,   924,   935,   944,
     947,  1424,   943,   973,   981,  1000,  1004,   936,   997,  1014,
    1011,  1042,  1039,  1046,  1025,  1055,  1056,  1059,  1005,  1130,
    1068,   975,  1063,  1454,  1069,  1074,  1035,  1095,  1102,  1101,
    1019,  1047,  1096,  1185,  1187,  1165,  1208,  1234,  1235,  1246,
    1236,  1305,  1135,  1263,  1264,  1279,  1292,  1247,  1280,  1293,
    1281,  1224,  1306,  1223,  1312,  1328,  1315,  1331,  1330,  1335,
    1354,  1184,  1253,  1396,  1334,  1376,  1357,  1282,  1408,  1342,
    1364,  1283,  1255,  1434,  1464,  1355,  1377,  1498,  1497,  1501,
    1446,  1557,  1476,  1555,  1558,  1525,  1543,  1572,  1544,  1485,
    1513,  1531,  1573,  1233,  1545,  1561,  1116,  1584,  1562,  1574,
    1593,  1594,  1592,  1595,   122,  1603,    75,   121,  1611,  1154,
     520,   154,   598,   525,   662,   694,   626,  1623,  1614,   246,
     339,   793,   701,  1624,   441,  1026,   848,  1075,   271,  1619,
    1336,  1338,  1064,  1307,  1309,  1358,  1201,  1103,  1622,  1360,
    1188,   982,   777,   854,  1206,  1038,  1129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1625,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1313,  1314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1327,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1431,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1556,     0,     0,     0,     0,  1559,  1560,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1615,  1616
};

static const yytype_int16 yycheck[] =
{
     207,   527,   150,   370,     4,   600,   695,     6,  1065,     4,
       4,   779,     4,   380,   255,     4,   257,     4,   385,  1076,
       4,  1017,     4,     8,     6,     7,     6,     7,   152,     6,
       7,   900,     4,   722,     4,     4,     4,     4,     4,     4,
       4,     4,    68,     6,     7,     4,     6,  1104,     4,  1045,
     137,   155,     4,    70,    76,    10,    11,   264,   265,   722,
       0,   142,  1058,     4,    14,     6,     7,   172,    65,   664,
      77,   760,    79,    80,   600,  1071,    77,   164,    79,    80,
     185,  1417,    37,    12,    13,    10,    11,  1170,    10,    11,
      45,    46,   109,   129,   111,   131,   113,   760,   115,    36,
     163,   125,  1098,   166,  1067,   253,    15,   255,   703,   257,
     191,  1447,    69,   137,   218,   141,    41,    42,    43,    44,
     244,   147,    47,    48,    61,   151,    63,   153,   137,   165,
    1213,  1094,    57,    58,   221,    17,  1132,  1067,   664,   165,
     164,    23,   163,   179,   171,   166,   155,    29,   165,   175,
     102,   177,    34,   197,   181,   164,    74,   183,  1241,   181,
     204,   850,   118,   199,  1094,   163,    71,   168,   166,   205,
     130,  1167,    67,   132,    72,   201,   140,   703,   195,   186,
     125,   148,   154,   101,   152,   126,  1269,   335,   154,   134,
     397,   178,   559,   156,    10,    11,   167,   564,  1067,   170,
     184,   190,   569,   180,   196,   200,   176,   206,   202,   174,
      10,    11,   419,   337,  1210,  1298,   984,     5,   198,   188,
     101,   139,   222,    66,   431,   432,   433,   434,    10,    11,
     471,   129,   473,   131,   475,    43,    44,  1320,    10,    11,
     222,    10,  1238,   228,   229,   230,   231,   165,    18,    57,
      58,  1308,    10,   779,     5,   173,     5,   109,   139,   111,
     467,   113,   163,   115,  1347,   166,     5,   165,    37,   187,
    1266,   189,   188,    43,    44,   191,    45,    46,     5,    37,
    1337,   179,    10,    11,   165,   203,  1369,    45,    46,    59,
      60,   209,   173,   211,    73,   213,    26,   215,   505,  1295,
      68,   199,  1359,  1386,    10,    11,   187,   205,   189,    43,
      44,    45,    46,   165,    77,  1311,    79,    80,  1401,    10,
      11,  1317,   203,   471,    86,   473,    82,   475,   209,    21,
     211,    37,   213,   218,   215,   141,   221,    10,    11,    45,
      46,   147,  1425,   195,  1340,   151,    10,   153,  1344,    41,
      42,    43,    44,    45,    46,    90,  1439,    10,    11,   165,
      10,    11,    94,    10,    11,  1054,  1362,    59,    60,   175,
    1366,   177,  1455,    37,   522,    10,    11,   183,  1067,   527,
      98,    45,    46,    70,    37,    16,  1469,    75,    19,   984,
      37,     3,    45,    46,    77,   201,    79,    80,    45,    46,
      10,    11,  1398,    10,    11,  1094,     3,  1490,    10,    11,
      10,    11,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    21,    72,   631,   632,   633,   634,    59,    60,
      43,    44,    10,   640,    10,  1518,    10,    11,    10,    11,
    1436,    10,    41,    42,    43,    44,    45,    46,    10,    11,
      10,    11,   600,  1536,   695,    10,    11,    10,   984,  1054,
      43,    44,    45,    46,     6,  1548,   673,    31,   675,   676,
    1466,   178,  1067,   154,   681,   176,    59,    60,   148,    43,
      44,   152,  1565,    47,    48,    43,    44,    10,    11,    47,
      48,  1487,    10,    11,  1577,    10,    11,    10,    11,  1094,
     184,  1027,  1585,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,  1596,    10,    11,   664,   724,   725,  1515,
     202,  1604,     6,     7,    10,    11,   220,   221,  1054,    10,
      11,    10,    11,    10,    11,    10,    11,  1533,     6,  1065,
      74,  1067,   749,    10,    11,    10,    11,   695,    10,    11,
    1076,    10,    11,    10,    11,   703,    19,   196,   765,    22,
      10,    11,    10,    11,    38,    39,   773,     3,  1094,    10,
      11,    10,    11,     6,   722,    10,    11,    32,  1104,   142,
      43,    44,    45,    46,    47,    48,    10,    11,    51,    52,
      53,    54,    19,    10,    11,   802,    59,    60,    10,    11,
      10,    11,    10,    11,   811,   191,    33,    10,    11,    10,
      11,   163,   760,    10,    11,   166,    43,    44,    45,    46,
      47,    48,    10,    11,    51,    52,    10,    11,    55,    56,
     837,   779,    59,    60,    10,    81,    10,    83,    84,    85,
      10,    87,    88,    89,    10,    91,    92,    93,   855,    95,
      96,    97,   859,    99,   100,    10,    11,    10,    11,    10,
      11,   868,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   132,   882,    10,    11,    10,    11,
      10,    11,    10,    11,   891,    10,    11,    10,    11,    10,
      11,    10,    11,   130,   901,    10,    11,    10,    11,    10,
      11,   114,   850,   112,   911,    10,    11,    10,    11,   206,
    1077,    10,    11,   200,   921,   110,  1311,    10,    11,    10,
      11,    10,    11,    10,    11,   116,   180,    76,   935,     6,
       6,   163,   166,     6,     6,   188,   174,   102,   190,     6,
     947,   140,     6,   166,   163,  1340,     3,   192,   164,     3,
      30,    10,   216,   204,   197,   166,   163,   187,   214,   164,
       3,     3,   164,   212,   153,     6,   973,  1362,   210,     6,
       3,   164,   172,   198,  1141,   157,   223,    28,    25,   185,
     127,   154,  1308,     5,   188,     6,   169,     6,    24,   217,
     186,     6,    78,   191,    33,   182,    27,  1004,   224,   217,
     192,     6,   133,   121,   219,    22,   158,   121,     6,   121,
      16,  1337,   128,     6,   170,   119,     6,   167,   163,   119,
     163,   119,   163,     6,   218,   122,   105,    18,   155,   107,
     122,   221,   218,  1359,   105,   220,   984,   122,   134,  1046,
     221,   125,   105,     5,   168,   107,   107,     3,     3,     6,
     103,  1218,  1059,     3,   103,   222,     3,   117,     6,   103,
      78,   155,   164,   137,     6,    40,   149,   135,   120,   164,
     120,  1078,   137,   193,   156,   120,   164,   125,   106,   149,
     149,   137,   221,   193,   193,   222,   126,     6,   108,    10,
     106,   118,   106,   104,     6,   108,   108,   104,   156,   207,
     207,   207,   126,  1110,   138,   222,  1054,   104,   138,   138,
     136,     6,   150,     6,    75,   150,    24,    53,   150,  1067,
     409,    95,   515,   423,   589,   644,   531,   208,   194,   139,
     231,   760,   658,   208,   314,   977,   820,  1021,   161,   194,
    1257,  1260,  1008,  1227,  1230,  1286,  1094,  1050,   194,  1289,
    1088,   939,   753,   828,  1094,   984,  1054,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,  1235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1362,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1498,    -1,    -1,    -1,    -1,  1503,  1504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1594,  1595
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   233,   234,   235,     0,    65,   242,   243,
     244,    14,   236,    15,   240,   241,    67,   271,   272,    10,
      11,   245,   246,   247,    10,    11,   237,   238,   239,    69,
     351,   352,    10,    11,   273,   274,   275,    81,    83,    84,
      85,    87,    88,    89,    91,    92,    93,    95,    96,    97,
      99,   100,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   242,    71,   405,   406,    10,
      11,   353,   354,   355,    68,   141,   147,   151,   153,   165,
     175,   177,   183,   201,   276,   277,   278,   279,   280,   295,
     296,   301,   302,   307,   308,   313,   314,   319,   320,   325,
     326,   331,   332,   337,   338,     5,     5,     5,     5,     5,
      66,   250,   240,    73,   457,   458,    10,    11,   407,   408,
     409,    70,   109,   111,   113,   115,   165,   195,   356,   357,
     358,   359,   360,   365,   366,   372,   373,   379,   380,   386,
     387,   391,   392,    68,   278,    31,    43,    44,    47,    48,
     281,   282,   283,   975,   976,   977,   978,   992,   993,   994,
     995,  1022,    10,    11,   297,   298,   299,    10,    11,   303,
     304,   305,    10,    11,   309,   310,   311,    10,    11,   315,
     316,   317,    10,    11,   321,   322,   323,    10,    11,   327,
     328,   329,    10,    11,   333,   334,   335,    26,   339,  1017,
      82,    86,    90,    94,    98,    75,   552,   553,    10,    11,
     459,   460,   461,    72,   129,   131,   165,   179,   199,   205,
     410,   411,   412,   413,   414,   419,   420,   425,   426,   431,
     432,   437,   438,   443,   444,    70,   358,    10,    11,   361,
     362,   363,   367,   368,   374,   375,   381,   382,   388,   975,
     393,  1017,  1043,  1044,     3,     3,    10,    11,   284,   285,
     286,   283,     4,   154,   300,     4,   178,   306,     4,   176,
     312,     4,   148,   318,     4,   152,   324,     4,   184,   330,
       4,   202,   336,  1043,    10,    11,   340,   341,   342,   554,
     555,    74,   101,   139,   165,   173,   187,   189,   203,   209,
     211,   213,   215,   462,   463,   464,   465,   466,   471,   472,
     477,   478,   483,   484,   489,   490,   495,   496,   512,   513,
     519,   520,   526,   527,   533,   534,   538,   539,    72,   412,
      10,    11,   415,   416,   417,    10,    11,   421,   422,   423,
      10,    11,   427,   428,   429,    10,    11,   433,   434,   435,
      10,    11,   439,   440,   441,   445,  1017,     4,   196,   364,
      10,   370,    57,    58,   369,   975,   996,   997,   998,   999,
      10,   377,   376,   975,   996,    10,   384,   383,   975,   996,
      10,   389,    10,    11,   394,   395,   396,     6,     8,   228,
     229,   230,   231,  1045,  1043,  1043,   142,   191,   287,   288,
     289,   290,   154,   178,   176,   148,   152,   184,   202,     6,
     163,   166,   343,   344,   345,   346,    10,    11,   557,   558,
     559,    17,    23,    29,    34,   556,  1009,  1014,  1020,  1025,
      74,   464,    10,    11,   467,   468,   469,    10,    11,   473,
     474,   475,    10,    11,   479,   480,   481,    10,    11,   485,
     486,   487,    10,    11,   491,   492,   493,    32,   497,  1023,
     514,   515,   521,   522,   528,   529,   535,   975,   540,  1017,
       4,   132,   418,     6,   130,   424,     6,   206,   430,     4,
     200,   436,     6,     7,   180,   442,  1041,    10,    11,   446,
     447,   448,   196,   371,  1041,     3,   378,  1041,   385,  1041,
       6,   390,   163,   166,   397,   398,   399,   400,  1043,   142,
     289,   291,   292,  1043,   166,   345,   347,   348,    76,   181,
     560,   561,   562,   563,  1043,  1043,  1043,  1043,     4,   188,
     470,     4,   190,   476,     4,   174,   482,     4,   102,   488,
       4,   140,   494,  1043,    10,    11,   498,   499,   500,    10,
     517,   516,   975,   996,    10,   524,   523,   975,   996,    10,
     531,   530,   975,   996,    10,   536,    10,    11,   541,   542,
     543,   132,   130,   206,   200,   180,   163,   166,   449,   450,
     451,   452,   114,  1043,   116,   112,   110,   166,   399,   401,
     402,    10,    11,   294,    45,    46,   293,   975,   984,   985,
     986,   987,    10,    11,   350,    59,    60,   349,   975,   984,
    1000,  1001,  1002,  1003,    76,   171,   562,   944,   945,   564,
     565,     6,     6,     6,     6,   188,   190,   174,   102,   140,
       6,   197,   204,   501,   502,   503,   504,   518,  1041,   525,
    1041,   532,  1041,     6,   537,   163,   166,   544,   545,   546,
     547,   166,   451,   453,   454,    10,    11,   404,   403,   975,
     984,  1000,   192,     3,   164,     3,    30,   946,  1021,    10,
     570,    36,    61,    63,   566,   567,   568,   569,  1043,  1043,
    1043,  1043,  1043,   204,   503,   505,   214,   216,   212,   210,
     166,   546,   548,   549,    10,    11,   456,   455,   975,   984,
    1000,   164,  1043,  1043,  1043,    10,    11,   947,   948,   949,
     187,   571,   572,  1043,     3,     3,    10,    11,    41,    42,
     506,   507,   508,   509,   967,   968,   969,   970,   975,   992,
     996,    10,    11,   551,   550,   975,   984,  1000,   164,     6,
     172,   185,   950,   951,   952,   953,   153,   587,   588,   573,
     574,   575,   975,   992,  1022,     6,  1043,  1043,     6,     7,
     198,   510,   511,     3,   164,  1043,   172,   952,   954,   955,
     223,   593,   594,    10,    11,   589,   590,   591,    10,    11,
     576,   577,   578,   575,  1043,   198,  1043,    10,    11,   957,
     958,   959,    21,   956,   967,   975,   984,  1012,   157,   713,
     714,    28,   595,  1019,     4,   154,   592,   188,   191,   579,
     580,   581,   582,    77,    79,    80,   186,   960,   961,   962,
     963,   964,   965,  1043,   127,   817,   818,    25,   715,  1016,
    1043,    10,    11,   596,   597,   598,   154,   188,   581,   583,
     584,     5,   966,   186,   962,     6,   169,   921,   922,    24,
     819,  1015,  1043,    10,    11,   716,   717,   718,     6,   217,
     599,   600,   601,    10,    11,   586,   585,   975,   992,    78,
    1043,   182,    27,   923,  1018,  1043,    10,    11,   820,   821,
     822,     6,   217,   719,   720,   721,  1043,   224,   219,   613,
     614,    33,   602,  1024,   192,  1043,    10,    11,   924,   925,
     926,     6,   133,   823,   824,   825,  1043,   158,   121,   733,
     734,    22,   722,  1013,   121,   629,   630,   615,  1024,  1043,
      10,    11,   603,   604,   605,     6,   167,   170,   927,   928,
     929,   930,  1043,   128,   121,   837,   838,    16,   826,  1008,
     788,    10,    11,   735,   736,   737,  1043,    10,    11,   723,
     724,   725,   684,    10,    11,   631,   632,   633,    10,    11,
     616,   617,   618,     6,   218,   221,   606,   607,   608,   609,
    1043,   170,   929,   931,   932,   892,    10,    11,   839,   840,
     841,  1043,    10,    11,   827,   828,   829,   163,   789,   790,
     119,   738,   739,   740,     6,   155,   218,   726,   727,   728,
     729,   163,   685,   686,   119,   634,   635,   636,   220,   221,
     619,   620,   621,   622,  1043,   218,   608,   610,    10,    11,
     934,   935,   936,   933,   967,   975,   984,  1000,  1012,   163,
     893,   894,   119,   842,   843,   844,     6,   125,   134,   830,
     831,   832,   833,   791,   792,   122,   105,   746,   747,    18,
     741,  1010,  1043,   218,   728,   730,   687,   688,   122,   105,
     642,   643,   637,  1010,   220,   621,   623,    10,    37,   611,
     612,   983,   984,    77,    79,    80,   168,   937,   938,   939,
     940,   941,   942,   895,   896,   122,   105,   850,   851,   845,
    1010,  1043,   134,   832,   834,    10,    11,   794,   795,   796,
      19,    51,    52,    53,    54,   793,   975,   979,   980,   981,
     982,   984,   988,   989,   990,   991,   992,  1000,  1011,  1013,
     107,   753,   754,   748,  1010,  1043,    10,    11,   742,   743,
     744,    10,   731,   732,   983,   984,    10,    11,   690,   691,
     692,    55,    56,   689,   975,   979,   984,   992,  1000,  1004,
    1005,  1006,  1007,  1011,  1024,   107,   649,   650,   644,  1010,
      10,    11,   638,   639,   640,    10,    11,   624,   625,   626,
     627,   983,   984,  1041,  1043,     5,   943,   168,   939,    10,
      11,   898,   899,   900,    49,    50,   897,   971,   972,   973,
     974,   975,   979,   984,   992,  1000,  1008,  1011,   107,   857,
     858,   852,  1010,    10,    11,   846,   847,   848,    10,   835,
     836,   983,   984,   137,   155,   164,   797,   798,   799,   800,
     807,   808,   809,  1043,     3,     3,   103,   760,   761,   755,
    1010,    10,    11,   749,   750,   751,     6,   117,   745,  1026,
    1027,  1034,  1041,   137,   164,   221,   693,   694,   695,   696,
     703,   704,   705,     3,   103,   656,   657,   651,  1010,    10,
      11,   645,   646,   647,   641,  1026,     4,   222,   628,   222,
       6,    78,   125,   137,   164,   901,   902,   903,   904,   911,
     912,   913,     3,   103,   864,   865,   859,  1010,    10,    11,
     853,   854,   855,   849,  1026,  1041,   164,   799,   801,   808,
     810,   811,     6,  1043,  1043,   149,   767,   768,   762,  1010,
      10,    11,   756,   757,   758,   752,  1026,  1043,    40,  1035,
     120,   135,  1028,  1029,   156,   164,   695,   697,   704,   706,
     707,  1043,   149,   663,   664,   658,  1010,    10,    11,   652,
     653,   654,   648,  1026,   120,   222,  1043,   164,   903,   905,
     912,   914,   915,  1043,   149,   871,   872,   866,  1010,    10,
      11,   860,   861,   862,   856,  1026,   120,   126,    10,    11,
     802,   803,   804,   805,   983,   984,    10,    11,   813,   814,
     815,   812,   975,  1000,  1010,  1043,   193,   774,   775,   769,
    1010,    10,    11,   763,   764,   765,   759,  1026,   106,  1043,
      10,    11,  1036,  1037,  1038,  1030,  1031,    10,    11,   698,
     699,   700,   701,   983,   984,    10,    11,   709,   710,   711,
     708,   975,  1000,  1010,   193,   670,   671,   665,  1010,    10,
      11,   659,   660,   661,   655,  1026,   106,    10,    11,   906,
     907,   908,   909,   983,   984,    10,    11,   917,   918,   919,
     916,   975,  1000,  1010,   193,   878,   879,   873,  1010,    10,
      11,   867,   868,   869,   863,  1026,   106,     4,     6,     7,
     156,   806,  1042,   816,  1026,   207,   781,   782,   776,  1010,
      10,    11,   770,   771,   772,   766,  1026,   108,     6,     4,
     118,    10,  1033,    38,    39,  1032,  1039,  1040,   222,   702,
    1042,   712,  1026,   207,   677,   678,   672,  1010,    10,    11,
     666,   667,   668,   662,  1026,   108,   126,   910,  1042,   920,
    1026,   207,   885,   886,   880,  1010,    10,    11,   874,   875,
     876,   870,  1026,   108,   156,   138,   783,  1010,    10,    11,
     777,   778,   779,   773,  1026,   104,  1043,   118,     6,  1043,
    1043,   222,   138,   679,  1010,    10,    11,   673,   674,   675,
     669,  1026,   104,   126,   138,   887,  1010,    10,    11,   881,
     882,   883,   877,  1026,   104,    10,    11,   784,   785,   786,
     780,  1026,   150,   136,     6,     6,    10,    11,   680,   681,
     682,   676,  1026,   150,    10,    11,   888,   889,   890,   884,
    1026,   150,   787,  1026,   194,  1043,  1043,   683,  1026,   194,
     891,  1026,   194,   208,   208,   208
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

  case 18:

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

  case 32:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 37:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 39:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 44:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 46:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 51:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 53:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 58:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 60:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 65:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 68:

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

  case 87:

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

  case 88:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    }
    break;

  case 91:

    { 
        if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
    }
    break;

  case 92:

    {   
        osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
    }
    break;

  case 93:

    {
       if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 94:

    {    if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 95:

    {    if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 102:

    {
    parserData->kounter++;
}
    break;

  case 103:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 104:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
}
    break;

  case 107:

    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
    }
    break;

  case 108:

    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
    }
    break;

  case 112:

    {
        if (parserData->generalMessagePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
        parserData->generalMessagePresent = true;
    }
    break;

  case 118:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 120:

    {
        if (parserData->generalServiceURIPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
        parserData->generalServiceURIPresent = true;
    }
    break;

  case 126:

    {
        osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 128:

    {
        if (parserData->generalServiceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
        parserData->generalServiceNamePresent = true;
    }
    break;

  case 134:

    {
        osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 136:

    {
        if (parserData->generalInstanceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
        parserData->generalInstanceNamePresent = true;
    }
    break;

  case 142:

    {
        osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 144:

    {
        if (parserData->generalJobIDPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
        parserData->generalJobIDPresent = true;
    }
    break;

  case 150:

    {
        osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 152:

    {
        if (parserData->generalSolverInvokedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
        parserData->generalSolverInvokedPresent = true;
    }
    break;

  case 158:

    {
        osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 160:

    {
        if (parserData->generalTimeStampPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
        parserData->generalTimeStampPresent = true;
    }
    break;

  case 166:

    {
        osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 168:

    {
        if (parserData->otherGeneralResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
        parserData->otherGeneralResultsPresent = true;
    }
    break;

  case 169:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
    if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 170:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 171:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 178:

    {
    parserData->kounter++;
}
    break;

  case 179:

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

  case 180:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 183:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
    }
    break;

  case 184:

    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
    }
    break;

  case 185:

    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
    }
    break;

  case 190:

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

  case 206:

    {
        if (parserData->systemInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
        parserData->systemInformationPresent = true;
    }
    break;

  case 212:

    {
        osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 214:

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

  case 218:

    {
        if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 219:

    {
        osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 221:

    {
    osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 223:

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

  case 227:

    {
        if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 228:

    {
        osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 230:

    {
    osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 232:

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

  case 236:

    {
        if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 237:

    {
        osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 239:

    {
    osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 241:

    {
        if (parserData->systemAvailableCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
        parserData->systemAvailableCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 243:

    {
        osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 245:

    {
    osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;
}
    break;

  case 247:

    {
        if (parserData->otherSystemResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
        parserData->otherSystemResultsPresent = true;
    }
    break;

  case 248:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
    if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 249:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 250:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 257:

    {
    parserData->kounter++;
}
    break;

  case 258:

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

  case 259:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 262:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
    }
    break;

  case 263:

    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
    }
    break;

  case 264:

    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
    }
    break;

  case 269:

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

  case 285:

    {
        if (parserData->serviceCurrentStatePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
        parserData->serviceCurrentStatePresent = true;
    }
    break;

  case 291:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setCurrentState(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 293:

    {
        if (parserData->serviceCurrentJobCountPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
        parserData->serviceCurrentJobCountPresent = true;
    }
    break;

  case 299:

    {
        osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL;
    }
    break;

  case 301:

    {
        if (parserData->serviceTotalJobsSoFarPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
        parserData->serviceTotalJobsSoFarPresent = true;
    }
    break;

  case 307:

    {
        osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; 
    }
    break;

  case 309:

    {
        if (parserData->timeServiceStartedPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
        parserData->timeServiceStartedPresent = true;
    }
    break;

  case 315:

    {
        osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 317:

    {
        if (parserData->serviceUtilizationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
        parserData->serviceUtilizationPresent = true;
    }
    break;

  case 323:

    {
    if (osresult->setServiceUtilization( parserData->tempVal) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
    parserData->errorText = NULL;
}
    break;

  case 325:

    {
        if (parserData->otherServiceResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
        parserData->otherServiceResultsPresent = true;
    }
    break;

  case 326:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
    if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 327:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 328:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 335:

    {
    parserData->kounter++;
}
    break;

  case 336:

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

  case 337:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 340:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
    }
    break;

  case 341:

    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
    }
    break;

  case 342:

    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
    }
    break;

  case 347:

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

  case 368:

    {
        if (parserData->jobStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
        parserData->jobStatusPresent = true;
    }
    break;

  case 374:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setJobStatus(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
        parserData->errorText = NULL;
    }
    break;

  case 376:

    {
        if (parserData->jobSubmitTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
        parserData->jobSubmitTimePresent = true;
    }
    break;

  case 382:

    {
        osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 384:

    {
        if (parserData->scheduledStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
        parserData->scheduledStartTimePresent = true;
    }
    break;

  case 390:

    {
        osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 392:

    {
        if (parserData->actualStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
        parserData->actualStartTimePresent = true;
    }
    break;

  case 398:

    {
        osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 400:

    {
        if (parserData->jobEndTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
        parserData->jobEndTimePresent = true;
    }
    break;

  case 406:

    {
        osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 408:

    {
        if (parserData->jobTimingInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
        parserData->jobTimingInformationPresent = true;
    }
    break;

  case 409:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
    if (osresult->setNumberOfTimes(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
    parserData->numberOfTimes = parserData->tempInt;
    parserData->ivar = 0;
}
    break;

  case 410:

    {
        if (parserData->numberOfTimes > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
    }
    break;

  case 411:

    {
        if (parserData->ivar != parserData->numberOfTimes)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
    }
    break;

  case 419:

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

  case 431:

    {    
    if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
        parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
            osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
    parserData->ivar++;
}
    break;

  case 432:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 433:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 435:

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

  case 439:

    {
        if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 440:

    {
        osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 442:

    {
    osresult->setUsedDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 444:

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

  case 448:

    {
        if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 449:

    {
        osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 451:

    {
    osresult->setUsedMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 453:

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

  case 457:

    {
        if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 458:

    {
        osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 460:

    {
    osresult->setUsedCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 462:

    {
        if (parserData->jobUsedCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
        parserData->jobUsedCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 464:

    {
        osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 466:

    { 
    osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; 
}
    break;

  case 468:

    {
        if (parserData->otherJobResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
        parserData->otherJobResultsPresent = true;
    }
    break;

  case 469:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
    if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 470:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 471:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 478:

    {
    parserData->kounter++;
}
    break;

  case 479:

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

  case 480:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 483:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
    }
    break;

  case 484:

    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
    }
    break;

  case 485:

    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
    }
    break;

  case 490:

    {
    parserData->numberAttributePresent = false;
    parserData->nVarPresent = false;
    parserData->nObjPresent = false;
    parserData->nConPresent = false;
}
    break;

  case 491:

    {
    if (!parserData->numberAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
}
    break;

  case 494:

    {
        parserData->numberOfSolutions = parserData->tempInt; 
        if (osresult->setSolutionNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
        parserData->solutionIdx = 0;
    }
    break;

  case 495:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osresult->setVariableNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
    }
    break;

  case 496:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osresult->setConstraintNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
    }
    break;

  case 497:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osresult->setObjectiveNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
    }
    break;

  case 498:

    {
        if (parserData->numberOfSolutions > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
    }
    break;

  case 499:

    {
        if (parserData->solutionIdx != parserData->numberOfSolutions)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
    }
    break;

  case 507:

    {
    if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->weightedObjAttributePresent = false;
}
    break;

  case 514:

    {
    if (parserData->idxAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
    parserData->idxAttributePresent = true;
    if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 515:

    {
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 516:

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

  case 517:

    {
        parserData->solutionIdx++;
    }
    break;

  case 519:

    {
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 520:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
    }
    break;

  case 523:

    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
    }
    break;

  case 524:

    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
    }
    break;

  case 525:

    {
        if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 526:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
    }
    break;

  case 527:

    {
        if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
    }
    break;

  case 534:

    {
    parserData->kounter++; 
}
    break;

  case 535:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 536:

    {
    if (!parserData->typeAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
}
    break;

  case 539:

    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
    }
    break;

  case 540:

    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
    }
    break;

  case 551:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
        osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
        parserData->errorText = NULL;
    }
    break;

  case 554:

    {
    parserData->numberOfOtherVariableResults = 0;
    osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 556:

    {    
    if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
    parserData->numberOfOtherVariableResults = parserData->tempInt;
    parserData->iOther = 0;
}
    break;

  case 565:

    {
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}
    break;

  case 566:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 567:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 574:

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

  case 575:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 584:

    {
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}
    break;

  case 585:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
    }
    break;

  case 586:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
    }
    break;

  case 593:

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

  case 594:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 599:

    {parserData->tempStr = "";}
    break;

  case 604:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 607:

    {
    osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 614:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 616:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 623:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 625:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 632:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 634:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 641:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 643:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 650:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 652:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 659:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 661:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 668:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 670:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 678:

    {      
        parserData->iOther++;
    }
    break;

  case 679:

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

  case 680:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 683:

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

  case 684:

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

  case 685:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 686:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
    break;

  case 687:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultType failed");
    }
    break;

  case 688:

    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->varTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarType failed");
    }
    break;

  case 689:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 690:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 700:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 701:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 704:

    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
    }
    break;

  case 705:

    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
    }
    break;

  case 711:

    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
    }
    break;

  case 714:

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

  case 715:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 716:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 719:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 729:

    {
    parserData->numberOfOtherObjectiveResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 731:

    {
    parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
}
    break;

  case 740:

    {
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}
    break;

  case 741:

    {
        if (parserData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
    }
    break;

  case 742:

    {
        if (parserData->kounter != parserData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
    }
    break;

  case 749:

    {
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
    parserData->kounter++;
}
    break;

  case 750:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 758:

    {
    osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 765:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 767:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 774:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 776:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 783:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 785:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 792:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 794:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 801:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 803:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 810:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 812:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 819:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 821:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 829:

    {      
        parserData->iOther++;  
    }
    break;

  case 830:

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

  case 831:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 834:

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

  case 835:

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

  case 836:

    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 837:

    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 838:

    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultType failed");
    }
    break;

  case 839:

    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->objTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 840:

    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 841:

    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->descriptionAttribute) 
                                                              == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 851:

    {  
    parserData->kounter++;
}
    break;

  case 852:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;    
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 855:

    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
    }
    break;

  case 856:

    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
    }
    break;

  case 862:

    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
    }
    break;

  case 865:

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

  case 866:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 867:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 870:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 880:

    {
    parserData->numberOfOtherConstraintResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 882:

    {
    parserData->numberOfOtherConstraintResults = parserData->tempInt;
    if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
}
    break;

  case 890:

    {    parserData->numberAttributePresent = false; }
    break;

  case 891:

    {
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
}
    break;

  case 892:

    {
        if (parserData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
    }
    break;

  case 893:

    {
        if (parserData->kounter != parserData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
    }
    break;

  case 900:

    {
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               parserData->idx,         parserData->nameAttribute,
                               parserData->tempVal                           ) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
    parserData->kounter++;
}
    break;

  case 901:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 909:

    {
    osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 916:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 918:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 925:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 927:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 934:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 936:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 943:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 945:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 952:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 954:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 961:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 963:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 970:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 972:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 980:

    {      
        parserData->iOther++;  
    }
    break;

  case 981:

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

  case 982:

    {
        if (!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
    }
    break;

  case 985:

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

  case 986:

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

  case 987:

    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 988:

    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 989:

    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultType failed");
    }
    break;

  case 990:

    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->conTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConType failed");
    }
    break;

  case 991:

    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 992:

    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 1002:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 1003:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 1006:

    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
    }
    break;

  case 1007:

    {    
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
    }
    break;

  case 1013:

    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
    }
    break;

  case 1016:

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

  case 1017:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1018:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
    }
    break;

  case 1021:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1031:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1032:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1033:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 1034:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 1041:

    {
    parserData->iOther++;
}
    break;

  case 1042:

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

  case 1043:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1046:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
    }
    break;

  case 1047:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                 parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 1048:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 1049:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
                                                        parserData->iOther,
                                                        parserData->descriptionAttribute) 
                                                            == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 1050:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1051:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1052:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1059:

    {
    parserData->kounter++;
}
    break;

  case 1060:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1065:

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

  case 1068:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1069:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1070:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
    }
    break;

  case 1071:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 1078:

    {
    parserData->iOther++;
}
    break;

  case 1079:

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

  case 1080:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
    if (!parserData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1083:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
    }
    break;

  case 1084:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, 
                                              parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
    }
    break;

  case 1085:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, 
                                                 parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
    }
    break;

  case 1086:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
                                                   parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1087:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
    }
    break;

  case 1088:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
    }
    break;

  case 1095:

    {
    parserData->kounter++;
}
    break;

  case 1096:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    }
    break;

  case 1101:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1102:

    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
        parserData->categoryAttributePresent = true;
    }
    break;

  case 1105:

    { 
    parserData->categoryAttribute = ""; 
}
    break;

  case 1106:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1107:

    {
        if (parserData->conTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one conType attribute allowed for this element");
        parserData->conTypeAttributePresent = true;
    }
    break;

  case 1110:

    { 
    parserData->conTypeAttribute = ""; 
}
    break;

  case 1111:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1112:

    {
        if (parserData->descriptionAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
        parserData->descriptionAttributePresent = true;
    }
    break;

  case 1115:

    { 
    parserData->descriptionAttribute = ""; 
}
    break;

  case 1116:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1117:

    {
        if (parserData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one enumType attribute allowed for this element");
        parserData->enumTypeAttributePresent = true;
    }
    break;

  case 1120:

    { 
    parserData->enumTypeAttribute = ""; 
}
    break;

  case 1121:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1122:

    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = (yyvsp[(3) - (4)].ival); 
    }
    break;

  case 1123:

    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1126:

    { 
    parserData->nameAttribute = ""; 
}
    break;

  case 1127:

    { 
    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1128:

    {
        if (parserData->objTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one objType attribute allowed for this element");
        parserData->objTypeAttributePresent = true;
    }
    break;

  case 1131:

    { 
    parserData->objTypeAttribute = ""; 
}
    break;

  case 1132:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1133:

    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
        parserData->typeAttributePresent = true;
    }
    break;

  case 1136:

    { 
    parserData->typeAttribute = ""; 
}
    break;

  case 1137:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1138:

    {
        if (parserData->unitAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
        parserData->unitAttributePresent = true;
    }
    break;

  case 1141:

    { 
    parserData->unitAttribute = ""; 
}
    break;

  case 1142:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1143:

    {
        if (parserData->valueAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
        parserData->valueAttributePresent = true;
    }
    break;

  case 1146:

    { 
    parserData->valueAttribute = ""; 
}
    break;

  case 1147:

    { 
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1148:

    {
        if (parserData->varTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, "only one varType attribute allowed for this element");
        parserData->varTypeAttributePresent = true;
    }
    break;

  case 1151:

    { 
    parserData->varTypeAttribute = ""; 
}
    break;

  case 1152:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1153:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1154:

    {
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1155:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1156:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1157:

    {    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1158:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1159:

    {
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1160:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1161:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1162:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1163:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1164:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1165:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1166:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1167:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1168:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1169:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1170:

    {
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1171:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
    }
    break;

  case 1176:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1182:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
        osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
    for (int i=0; i<osglData->osglMult; i++)
        osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1184:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1189:

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

  case 1190:

    {    
    if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1191:

    {    
    if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1192:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1193:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1194:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1195:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1196:

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


