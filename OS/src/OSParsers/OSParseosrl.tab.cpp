
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
     UNITATT = 304,
     EMPTYUNITATT = 305,
     VALUEATT = 306,
     EMPTYVALUEATT = 307,
     WEIGHTEDOBJECTIVESATT = 308,
     EMPTYWEIGHTEDOBJECTIVESATT = 309,
     TARGETOBJECTIVENAMEATT = 310,
     EMPTYTARGETOBJECTIVENAMEATT = 311,
     HEADERSTART = 312,
     HEADEREND = 313,
     GENERALSTART = 314,
     GENERALEND = 315,
     SYSTEMSTART = 316,
     SYSTEMEND = 317,
     SERVICESTART = 318,
     SERVICEEND = 319,
     JOBSTART = 320,
     JOBEND = 321,
     OPTIMIZATIONSTART = 322,
     OPTIMIZATIONEND = 323,
     ITEMSTART = 324,
     ITEMEND = 325,
     ITEMSTARTANDEND = 326,
     ITEMEMPTY = 327,
     FILENAMESTART = 328,
     FILENAMEEND = 329,
     FILENAMEEMPTY = 330,
     FILENAMESTARTANDEND = 331,
     FILESOURCESTART = 332,
     FILESOURCEEND = 333,
     FILESOURCEEMPTY = 334,
     FILESOURCESTARTANDEND = 335,
     FILEDESCRIPTIONSTART = 336,
     FILEDESCRIPTIONEND = 337,
     FILEDESCRIPTIONEMPTY = 338,
     FILEDESCRIPTIONSTARTANDEND = 339,
     FILECREATORSTART = 340,
     FILECREATOREND = 341,
     FILECREATOREMPTY = 342,
     FILECREATORSTARTANDEND = 343,
     FILELICENCESTART = 344,
     FILELICENCEEND = 345,
     FILELICENCEEMPTY = 346,
     FILELICENCESTARTANDEND = 347,
     ACTUALSTARTTIMESTART = 348,
     ACTUALSTARTTIMEEND = 349,
     ATEQUALITYSTART = 350,
     ATEQUALITYEND = 351,
     ATLOWERSTART = 352,
     ATLOWEREND = 353,
     ATUPPERSTART = 354,
     ATUPPEREND = 355,
     AVAILABLECPUNUMBERSTART = 356,
     AVAILABLECPUNUMBEREND = 357,
     AVAILABLECPUSPEEDSTART = 358,
     AVAILABLECPUSPEEDEND = 359,
     AVAILABLEDISKSPACESTART = 360,
     AVAILABLEDISKSPACEEND = 361,
     AVAILABLEMEMORYSTART = 362,
     AVAILABLEMEMORYEND = 363,
     BASE64START = 364,
     BASE64END = 365,
     BASICSTART = 366,
     BASICEND = 367,
     BASISSTATUSSTART = 368,
     BASISSTATUSEND = 369,
     BASSTATUSSTART = 370,
     BASSTATUSEND = 371,
     CONSTART = 372,
     CONEND = 373,
     CONSTRAINTSSTART = 374,
     CONSTRAINTSEND = 375,
     CURRENTJOBCOUNTSTART = 376,
     CURRENTJOBCOUNTEND = 377,
     CURRENTSTATESTART = 378,
     CURRENTSTATEEND = 379,
     DUALVALUESSTART = 380,
     DUALVALUESEND = 381,
     ELSTART = 382,
     ELEND = 383,
     ENUMERATIONSTART = 384,
     ENUMERATIONEND = 385,
     ENDTIMESTART = 386,
     ENDTIMEEND = 387,
     GENERALSTATUSSTART = 388,
     GENERALSTATUSEND = 389,
     GENERALSUBSTATUSSTART = 390,
     GENERALSUBSTATUSEND = 391,
     IDXSTART = 392,
     IDXEND = 393,
     INSTANCENAMESTART = 394,
     INSTANCENAMEEND = 395,
     ISFREESTART = 396,
     ISFREEEND = 397,
     JOBIDSTART = 398,
     JOBIDEND = 399,
     MESSAGESTART = 400,
     MESSAGEEND = 401,
     OBJSTART = 402,
     OBJEND = 403,
     OBJECTIVESSTART = 404,
     OBJECTIVESEND = 405,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 406,
     OPTIMIZATIONSOLUTIONSTATUSEND = 407,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 408,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 409,
     OTHERSTART = 410,
     OTHEREND = 411,
     OTHERRESULTSSTART = 412,
     OTHERRESULTSEND = 413,
     OTHERSOLUTIONRESULTSTART = 414,
     OTHERSOLUTIONRESULTEND = 415,
     OTHERSOLUTIONRESULTSSTART = 416,
     OTHERSOLUTIONRESULTSEND = 417,
     OTHERSOLVEROUTPUTSTART = 418,
     OTHERSOLVEROUTPUTEND = 419,
     SCHEDULEDSTARTTIMESTART = 420,
     SCHEDULEDSTARTTIMEEND = 421,
     SERVICENAMESTART = 422,
     SERVICENAMEEND = 423,
     SERVICEURISTART = 424,
     SERVICEURIEND = 425,
     SERVICEUTILIZATIONSTART = 426,
     SERVICEUTILIZATIONEND = 427,
     SOLUTIONSTART = 428,
     SOLUTIONEND = 429,
     SOLVERINVOKEDSTART = 430,
     SOLVERINVOKEDEND = 431,
     SOLVEROUTPUTSTART = 432,
     SOLVEROUTPUTEND = 433,
     STATUSSTART = 434,
     STATUSEND = 435,
     SUBMITTIMESTART = 436,
     SUBMITTIMEEND = 437,
     SUBSTATUSSTART = 438,
     SUBSTATUSEND = 439,
     SUPERBASICSTART = 440,
     SUPERBASICEND = 441,
     SYSTEMINFORMATIONSTART = 442,
     SYSTEMINFORMATIONEND = 443,
     TIMESTART = 444,
     TIMEEND = 445,
     TIMESERVICESTARTEDSTART = 446,
     TIMESERVICESTARTEDEND = 447,
     TIMESTAMPSTART = 448,
     TIMESTAMPEND = 449,
     TIMINGINFORMATIONSTART = 450,
     TIMINGINFORMATIONEND = 451,
     TOTALJOBSSOFARSTART = 452,
     TOTALJOBSSOFAREND = 453,
     UNKNOWNSTART = 454,
     UNKNOWNEND = 455,
     USEDCPUNUMBERSTART = 456,
     USEDCPUNUMBEREND = 457,
     USEDCPUSPEEDSTART = 458,
     USEDCPUSPEEDEND = 459,
     USEDDISKSPACESTART = 460,
     USEDDISKSPACEEND = 461,
     USEDMEMORYSTART = 462,
     USEDMEMORYEND = 463,
     VALUESSTART = 464,
     VALUESEND = 465,
     VALUESSTRINGSTART = 466,
     VALUESSTRINGEND = 467,
     VARSTART = 468,
     VAREND = 469,
     VARIABLESSTART = 470,
     VARIABLESEND = 471,
     VARIDXSTART = 472,
     VARIDXEND = 473,
     DUMMY = 474
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
#define UNITATT 304
#define EMPTYUNITATT 305
#define VALUEATT 306
#define EMPTYVALUEATT 307
#define WEIGHTEDOBJECTIVESATT 308
#define EMPTYWEIGHTEDOBJECTIVESATT 309
#define TARGETOBJECTIVENAMEATT 310
#define EMPTYTARGETOBJECTIVENAMEATT 311
#define HEADERSTART 312
#define HEADEREND 313
#define GENERALSTART 314
#define GENERALEND 315
#define SYSTEMSTART 316
#define SYSTEMEND 317
#define SERVICESTART 318
#define SERVICEEND 319
#define JOBSTART 320
#define JOBEND 321
#define OPTIMIZATIONSTART 322
#define OPTIMIZATIONEND 323
#define ITEMSTART 324
#define ITEMEND 325
#define ITEMSTARTANDEND 326
#define ITEMEMPTY 327
#define FILENAMESTART 328
#define FILENAMEEND 329
#define FILENAMEEMPTY 330
#define FILENAMESTARTANDEND 331
#define FILESOURCESTART 332
#define FILESOURCEEND 333
#define FILESOURCEEMPTY 334
#define FILESOURCESTARTANDEND 335
#define FILEDESCRIPTIONSTART 336
#define FILEDESCRIPTIONEND 337
#define FILEDESCRIPTIONEMPTY 338
#define FILEDESCRIPTIONSTARTANDEND 339
#define FILECREATORSTART 340
#define FILECREATOREND 341
#define FILECREATOREMPTY 342
#define FILECREATORSTARTANDEND 343
#define FILELICENCESTART 344
#define FILELICENCEEND 345
#define FILELICENCEEMPTY 346
#define FILELICENCESTARTANDEND 347
#define ACTUALSTARTTIMESTART 348
#define ACTUALSTARTTIMEEND 349
#define ATEQUALITYSTART 350
#define ATEQUALITYEND 351
#define ATLOWERSTART 352
#define ATLOWEREND 353
#define ATUPPERSTART 354
#define ATUPPEREND 355
#define AVAILABLECPUNUMBERSTART 356
#define AVAILABLECPUNUMBEREND 357
#define AVAILABLECPUSPEEDSTART 358
#define AVAILABLECPUSPEEDEND 359
#define AVAILABLEDISKSPACESTART 360
#define AVAILABLEDISKSPACEEND 361
#define AVAILABLEMEMORYSTART 362
#define AVAILABLEMEMORYEND 363
#define BASE64START 364
#define BASE64END 365
#define BASICSTART 366
#define BASICEND 367
#define BASISSTATUSSTART 368
#define BASISSTATUSEND 369
#define BASSTATUSSTART 370
#define BASSTATUSEND 371
#define CONSTART 372
#define CONEND 373
#define CONSTRAINTSSTART 374
#define CONSTRAINTSEND 375
#define CURRENTJOBCOUNTSTART 376
#define CURRENTJOBCOUNTEND 377
#define CURRENTSTATESTART 378
#define CURRENTSTATEEND 379
#define DUALVALUESSTART 380
#define DUALVALUESEND 381
#define ELSTART 382
#define ELEND 383
#define ENUMERATIONSTART 384
#define ENUMERATIONEND 385
#define ENDTIMESTART 386
#define ENDTIMEEND 387
#define GENERALSTATUSSTART 388
#define GENERALSTATUSEND 389
#define GENERALSUBSTATUSSTART 390
#define GENERALSUBSTATUSEND 391
#define IDXSTART 392
#define IDXEND 393
#define INSTANCENAMESTART 394
#define INSTANCENAMEEND 395
#define ISFREESTART 396
#define ISFREEEND 397
#define JOBIDSTART 398
#define JOBIDEND 399
#define MESSAGESTART 400
#define MESSAGEEND 401
#define OBJSTART 402
#define OBJEND 403
#define OBJECTIVESSTART 404
#define OBJECTIVESEND 405
#define OPTIMIZATIONSOLUTIONSTATUSSTART 406
#define OPTIMIZATIONSOLUTIONSTATUSEND 407
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 408
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 409
#define OTHERSTART 410
#define OTHEREND 411
#define OTHERRESULTSSTART 412
#define OTHERRESULTSEND 413
#define OTHERSOLUTIONRESULTSTART 414
#define OTHERSOLUTIONRESULTEND 415
#define OTHERSOLUTIONRESULTSSTART 416
#define OTHERSOLUTIONRESULTSEND 417
#define OTHERSOLVEROUTPUTSTART 418
#define OTHERSOLVEROUTPUTEND 419
#define SCHEDULEDSTARTTIMESTART 420
#define SCHEDULEDSTARTTIMEEND 421
#define SERVICENAMESTART 422
#define SERVICENAMEEND 423
#define SERVICEURISTART 424
#define SERVICEURIEND 425
#define SERVICEUTILIZATIONSTART 426
#define SERVICEUTILIZATIONEND 427
#define SOLUTIONSTART 428
#define SOLUTIONEND 429
#define SOLVERINVOKEDSTART 430
#define SOLVERINVOKEDEND 431
#define SOLVEROUTPUTSTART 432
#define SOLVEROUTPUTEND 433
#define STATUSSTART 434
#define STATUSEND 435
#define SUBMITTIMESTART 436
#define SUBMITTIMEEND 437
#define SUBSTATUSSTART 438
#define SUBSTATUSEND 439
#define SUPERBASICSTART 440
#define SUPERBASICEND 441
#define SYSTEMINFORMATIONSTART 442
#define SYSTEMINFORMATIONEND 443
#define TIMESTART 444
#define TIMEEND 445
#define TIMESERVICESTARTEDSTART 446
#define TIMESERVICESTARTEDEND 447
#define TIMESTAMPSTART 448
#define TIMESTAMPEND 449
#define TIMINGINFORMATIONSTART 450
#define TIMINGINFORMATIONEND 451
#define TOTALJOBSSOFARSTART 452
#define TOTALJOBSSOFAREND 453
#define UNKNOWNSTART 454
#define UNKNOWNEND 455
#define USEDCPUNUMBERSTART 456
#define USEDCPUNUMBEREND 457
#define USEDCPUSPEEDSTART 458
#define USEDCPUSPEEDEND 459
#define USEDDISKSPACESTART 460
#define USEDDISKSPACEEND 461
#define USEDMEMORYSTART 462
#define USEDMEMORYEND 463
#define VALUESSTART 464
#define VALUESEND 465
#define VALUESSTRINGSTART 466
#define VALUESSTRINGEND 467
#define VARSTART 468
#define VAREND 469
#define VARIABLESSTART 470
#define VARIABLESEND 471
#define VARIDXSTART 472
#define VARIDXEND 473
#define DUMMY 474




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
#define YYLAST   1375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  795
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1165
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1584

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   474

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   221,
     223,     2,     2,   222,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   220,     2,     2,     2,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219
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
    1644,  1646,  1648,  1651,  1653,  1657,  1659,  1661,  1663,  1666,
    1670,  1672,  1673,  1676,  1678,  1680,  1682,  1684,  1687,  1689,
    1693,  1695,  1697,  1700,  1704,  1706,  1708,  1709,  1712,  1714,
    1716,  1718,  1720,  1722,  1724,  1728,  1730,  1731,  1735,  1737,
    1738,  1740,  1742,  1744,  1746,  1750,  1754,  1755,  1759,  1761,
    1763,  1765,  1767,  1770,  1772,  1776,  1778,  1780,  1783,  1787,
    1789,  1790,  1793,  1795,  1797,  1801,  1802,  1805,  1807,  1809,
    1811,  1813,  1817,  1825,  1826,  1830,  1832,  1834,  1836,  1838,
    1840,  1844,  1846,  1847,  1851,  1853,  1855,  1857,  1859,  1861,
    1865,  1867,  1868,  1872,  1874,  1876,  1878,  1880,  1882,  1886,
    1888,  1889,  1893,  1895,  1897,  1899,  1901,  1903,  1907,  1909,
    1910,  1914,  1916,  1918,  1920,  1922,  1924,  1928,  1930,  1931,
    1935,  1937,  1939,  1941,  1943,  1945,  1949,  1951,  1952,  1956,
    1958,  1960,  1962,  1964,  1966,  1970,  1972,  1973,  1976,  1980,
    1982,  1984,  1985,  1988,  1990,  1992,  1994,  1996,  1998,  2000,
    2002,  2005,  2007,  2011,  2013,  2015,  2017,  2020,  2024,  2026,
    2027,  2030,  2032,  2034,  2036,  2038,  2041,  2043,  2047,  2049,
    2051,  2054,  2058,  2060,  2062,  2063,  2066,  2068,  2070,  2072,
    2074,  2076,  2078,  2082,  2084,  2085,  2089,  2091,  2092,  2094,
    2096,  2098,  2100,  2104,  2108,  2109,  2113,  2115,  2117,  2119,
    2121,  2124,  2126,  2130,  2132,  2134,  2137,  2141,  2143,  2144,
    2147,  2149,  2151,  2155,  2156,  2159,  2161,  2163,  2165,  2167,
    2171,  2179,  2180,  2184,  2186,  2188,  2190,  2192,  2194,  2198,
    2200,  2201,  2205,  2207,  2209,  2211,  2213,  2215,  2219,  2221,
    2222,  2226,  2228,  2230,  2232,  2234,  2236,  2240,  2242,  2243,
    2247,  2249,  2251,  2253,  2255,  2257,  2261,  2263,  2264,  2268,
    2270,  2272,  2274,  2276,  2278,  2282,  2284,  2285,  2289,  2291,
    2293,  2295,  2297,  2299,  2303,  2305,  2306,  2310,  2312,  2314,
    2316,  2318,  2320,  2324,  2326,  2327,  2330,  2334,  2336,  2338,
    2339,  2342,  2344,  2346,  2348,  2350,  2352,  2354,  2356,  2359,
    2361,  2365,  2367,  2369,  2371,  2374,  2378,  2380,  2381,  2384,
    2386,  2388,  2390,  2392,  2395,  2397,  2401,  2403,  2405,  2408,
    2412,  2414,  2416,  2417,  2420,  2422,  2424,  2426,  2428,  2430,
    2432,  2436,  2438,  2439,  2443,  2445,  2447,  2449,  2451,  2454,
    2456,  2460,  2462,  2464,  2467,  2471,  2473,  2475,  2476,  2479,
    2481,  2483,  2485,  2487,  2489,  2491,  2494,  2496,  2500,  2502,
    2504,  2507,  2509,  2511,  2513,  2515,  2517,  2521,  2523,  2524,
    2528,  2530,  2532,  2534,  2536,  2539,  2541,  2545,  2547,  2549,
    2552,  2556,  2558,  2560,  2561,  2564,  2566,  2568,  2570,  2572,
    2574,  2576,  2579,  2581,  2585,  2587,  2589,  2592,  2594,  2596,
    2598,  2600,  2602,  2606,  2608,  2610,  2612,  2614,  2616,  2620,
    2622,  2624,  2626,  2628,  2632,  2637,  2639,  2641,  2643,  2645,
    2649,  2651,  2653,  2655,  2657,  2661,  2663,  2665,  2667,  2669,
    2673,  2675,  2677,  2679,  2681,  2685,  2690,  2695,  2700,  2705,
    2710,  2715,  2720,  2725,  2730,  2735,  2740,  2745,  2750,  2755,
    2760,  2765,  2770,  2775,  2777,  2779,  2780,  2783,  2787,  2789,
    2791,  2792,  2795,  2797,  2799,  2803,  2807,  2812,  2814,  2816,
    2819,  2821,  2825,  2830,  2835,  2837,  2839,  2841,  2843,  2845,
    2848,  2849,  2852,  2854,  2856,  2858
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     225,     0,    -1,   226,   233,   232,    -1,   227,   228,   229,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   230,    -1,
     231,    -1,    11,    -1,    10,   233,   232,    -1,    15,    -1,
      -1,   234,   260,   340,   394,   446,   541,    -1,    -1,   235,
     236,    -1,    57,    -1,   237,    -1,   238,    -1,    11,    -1,
      10,   239,    58,    -1,   240,   244,   248,   252,   256,    -1,
      -1,   241,    -1,   242,    -1,   243,    -1,    76,    -1,    75,
      -1,    73,     5,    74,    -1,    -1,   245,    -1,   246,    -1,
     247,    -1,    80,    -1,    79,    -1,    77,     5,    78,    -1,
      -1,   249,    -1,   250,    -1,   251,    -1,    84,    -1,    83,
      -1,    81,     5,    82,    -1,    -1,   253,    -1,   254,    -1,
     255,    -1,    88,    -1,    87,    -1,    85,     5,    86,    -1,
      -1,   257,    -1,   258,    -1,   259,    -1,    92,    -1,    91,
      -1,    89,     5,    90,    -1,    -1,   261,   262,    -1,    59,
      -1,   263,    -1,   264,    -1,    10,    60,    -1,    11,    -1,
      10,   265,    60,    -1,   266,    -1,   267,    -1,   266,   267,
      -1,   268,    -1,   284,    -1,   290,    -1,   296,    -1,   302,
      -1,   308,    -1,   314,    -1,   320,    -1,   326,    -1,   269,
     270,   273,    -1,   133,    -1,   271,    -1,   272,    -1,   271,
     272,    -1,   969,    -1,   960,    -1,   995,    -1,   274,    -1,
     275,    -1,    10,   134,    -1,    11,    -1,    10,   276,   134,
      -1,   277,    -1,   278,    -1,   277,   278,    -1,   279,   280,
     283,    -1,   183,    -1,   281,    -1,    -1,   281,   282,    -1,
     965,    -1,   960,    -1,    10,   184,    -1,    11,    -1,   285,
     286,    -1,   145,    -1,   287,    -1,   288,    -1,    10,   146,
      -1,    11,    -1,    10,   289,   146,    -1,     4,    -1,   291,
     292,    -1,   169,    -1,   293,    -1,   294,    -1,    10,   170,
      -1,    11,    -1,    10,   295,   170,    -1,     4,    -1,   297,
     298,    -1,   167,    -1,   299,    -1,   300,    -1,    10,   168,
      -1,    11,    -1,    10,   301,   168,    -1,     4,    -1,   303,
     304,    -1,   139,    -1,   305,    -1,   306,    -1,    10,   140,
      -1,    11,    -1,    10,   307,   140,    -1,     4,    -1,   309,
     310,    -1,   143,    -1,   311,    -1,   312,    -1,    10,   144,
      -1,    11,    -1,    10,   313,   144,    -1,     4,    -1,   315,
     316,    -1,   175,    -1,   317,    -1,   318,    -1,    10,   176,
      -1,    11,    -1,    10,   319,   176,    -1,     4,    -1,   321,
     322,    -1,   193,    -1,   323,    -1,   324,    -1,    10,   194,
      -1,    11,    -1,    10,   325,   194,    -1,     4,    -1,   327,
     328,   329,    -1,   157,    -1,   990,    -1,   330,    -1,   331,
      -1,    10,   158,    -1,    11,    -1,    10,   332,   158,    -1,
     333,    -1,   334,    -1,   333,   334,    -1,   335,   336,   339,
      -1,   155,    -1,   337,    -1,    -1,   337,   338,    -1,   965,
      -1,   977,    -1,   960,    -1,    10,   156,    -1,    11,    -1,
      -1,   341,   342,    -1,    61,    -1,   343,    -1,   344,    -1,
      10,    62,    -1,    11,    -1,    10,   345,    62,    -1,   346,
      -1,   347,    -1,   346,   347,    -1,   348,    -1,   354,    -1,
     361,    -1,   368,    -1,   375,    -1,   380,    -1,   349,   350,
      -1,   187,    -1,   351,    -1,   352,    -1,    10,   188,    -1,
      11,    -1,    10,   353,   188,    -1,     4,    -1,   355,   356,
     359,    -1,   105,    -1,   357,    -1,    -1,   357,   358,    -1,
     973,    -1,   960,    -1,    10,   360,   106,    -1,  1014,    -1,
     362,   363,   366,    -1,   107,    -1,   364,    -1,    -1,   364,
     365,    -1,   973,    -1,   960,    -1,    10,   367,   108,    -1,
    1014,    -1,   369,   370,   373,    -1,   103,    -1,   371,    -1,
      -1,   371,   372,    -1,   973,    -1,   960,    -1,    10,   374,
     104,    -1,  1014,    -1,   376,   377,   378,    -1,   101,    -1,
      -1,   960,    -1,    10,   379,   102,    -1,     6,    -1,   381,
     382,   383,    -1,   157,    -1,   990,    -1,   384,    -1,   385,
      -1,    10,   158,    -1,    11,    -1,    10,   386,   158,    -1,
     387,    -1,   388,    -1,   387,   388,    -1,   389,   390,   393,
      -1,   155,    -1,   391,    -1,    -1,   391,   392,    -1,   965,
      -1,   977,    -1,   960,    -1,    10,   156,    -1,    11,    -1,
      -1,   395,   396,    -1,    63,    -1,   397,    -1,   398,    -1,
      10,    64,    -1,    11,    -1,    10,   399,    64,    -1,   400,
      -1,   401,    -1,   400,   401,    -1,   402,    -1,   408,    -1,
     414,    -1,   420,    -1,   426,    -1,   432,    -1,   403,   404,
      -1,   123,    -1,   405,    -1,   406,    -1,    10,   124,    -1,
      11,    -1,    10,   407,   124,    -1,     4,    -1,   409,   410,
      -1,   121,    -1,   411,    -1,   412,    -1,    10,   122,    -1,
      11,    -1,    10,   413,   122,    -1,     6,    -1,   415,   416,
      -1,   197,    -1,   417,    -1,   418,    -1,    10,   198,    -1,
      11,    -1,    10,   419,   198,    -1,     6,    -1,   421,   422,
      -1,   191,    -1,   423,    -1,   424,    -1,    10,   192,    -1,
      11,    -1,    10,   425,   192,    -1,     4,    -1,   427,   428,
      -1,   171,    -1,   429,    -1,   430,    -1,    10,   172,    -1,
      11,    -1,    10,   431,   172,    -1,  1014,    -1,   433,   434,
     435,    -1,   157,    -1,   990,    -1,   436,    -1,   437,    -1,
      10,   158,    -1,    11,    -1,    10,   438,   158,    -1,   439,
      -1,   440,    -1,   439,   440,    -1,   441,   442,   445,    -1,
     155,    -1,   443,    -1,    -1,   443,   444,    -1,   965,    -1,
     977,    -1,   960,    -1,    10,   156,    -1,    11,    -1,    -1,
     447,   448,    -1,    65,    -1,   449,    -1,   450,    -1,    10,
      66,    -1,    11,    -1,    10,   451,    66,    -1,   452,    -1,
     453,    -1,   452,   453,    -1,   454,    -1,   460,    -1,   466,
      -1,   472,    -1,   478,    -1,   484,    -1,   501,    -1,   508,
      -1,   515,    -1,   522,    -1,   527,    -1,   455,   456,    -1,
     179,    -1,   457,    -1,   458,    -1,    10,   180,    -1,    11,
      -1,    10,   459,   180,    -1,     4,    -1,   461,   462,    -1,
     181,    -1,   463,    -1,   464,    -1,    10,   182,    -1,    11,
      -1,    10,   465,   182,    -1,     4,    -1,   467,   468,    -1,
     165,    -1,   469,    -1,   470,    -1,    10,   166,    -1,    11,
      -1,    10,   471,   166,    -1,     4,    -1,   473,   474,    -1,
      93,    -1,   475,    -1,   476,    -1,    10,    94,    -1,    11,
      -1,    10,   477,    94,    -1,     4,    -1,   479,   480,    -1,
     131,    -1,   481,    -1,   482,    -1,    10,   132,    -1,    11,
      -1,    10,   483,   132,    -1,     4,    -1,   485,   486,   487,
      -1,   195,    -1,   996,    -1,   488,    -1,   489,    -1,    10,
     196,    -1,    11,    -1,    10,   490,   196,    -1,   491,    -1,
     492,    -1,   491,   492,    -1,   493,   494,   496,    -1,   189,
      -1,    -1,   494,   495,    -1,   973,    -1,   969,    -1,   956,
      -1,   960,    -1,   497,    -1,   498,    -1,    10,   190,    -1,
      11,    -1,    10,   499,   190,    -1,   500,    -1,     7,    -1,
       6,    -1,   502,   503,   506,    -1,   205,    -1,   504,    -1,
      -1,   504,   505,    -1,   973,    -1,   960,    -1,    10,   507,
     206,    -1,  1014,    -1,   509,   510,   513,    -1,   207,    -1,
     511,    -1,    -1,   511,   512,    -1,   973,    -1,   960,    -1,
      10,   514,   208,    -1,  1014,    -1,   516,   517,   520,    -1,
     203,    -1,   518,    -1,    -1,   518,   519,    -1,   973,    -1,
     960,    -1,    10,   521,   204,    -1,  1014,    -1,   523,   524,
     525,    -1,   201,    -1,    -1,   960,    -1,    10,   526,   202,
      -1,     6,    -1,   528,   529,   530,    -1,   157,    -1,   990,
      -1,   531,    -1,   532,    -1,    10,   158,    -1,    11,    -1,
      10,   533,   158,    -1,   534,    -1,   535,    -1,   534,   535,
      -1,   536,   537,   540,    -1,   155,    -1,   538,    -1,    -1,
     538,   539,    -1,   965,    -1,   977,    -1,   960,    -1,    10,
     156,    -1,    11,    -1,    -1,   542,   543,   546,    -1,    67,
      -1,   544,    -1,    -1,   544,   545,    -1,   993,    -1,   998,
      -1,   982,    -1,   987,    -1,   547,    -1,   548,    -1,    10,
      68,    -1,    11,    -1,    10,   549,    68,    -1,   550,   933,
      -1,   551,    -1,   550,   551,    -1,   552,   553,   559,    -1,
     173,    -1,   554,    -1,    -1,   554,   555,    -1,   556,    -1,
     557,    -1,   558,    -1,    36,  1016,     6,  1016,    -1,    55,
       3,  1016,    -1,    53,     3,  1016,    -1,    10,   560,   576,
     582,   702,   806,   910,   174,    -1,   561,   562,   565,    -1,
     179,    -1,   563,    -1,   564,    -1,   563,   564,    -1,   969,
      -1,   960,    -1,   995,    -1,   566,    -1,   567,    -1,    10,
     180,    -1,    11,    -1,    10,   568,   180,    -1,   569,    -1,
     570,    -1,   569,   570,    -1,   571,   572,   575,    -1,   183,
      -1,   573,    -1,    -1,   573,   574,    -1,   969,    -1,   960,
      -1,    10,   184,    -1,    11,    -1,    -1,   577,   578,    -1,
     145,    -1,   579,    -1,   580,    -1,    10,   146,    -1,    11,
      -1,    10,   581,   146,    -1,     4,    -1,    -1,   583,   584,
     585,    -1,   215,    -1,    -1,   992,    -1,   586,    -1,   587,
      -1,    11,    -1,    10,   588,   216,    -1,   589,   602,   618,
     673,    -1,    -1,   590,   591,   592,    -1,   209,    -1,   997,
      -1,   593,    -1,   594,    -1,    10,   210,    -1,    11,    -1,
      10,   595,   210,    -1,   596,    -1,   597,    -1,   596,   597,
      -1,   598,   599,   601,    -1,   213,    -1,    -1,   599,   600,
      -1,   964,    -1,   965,    -1,    10,  1014,   214,    -1,    -1,
     603,   604,   605,    -1,   211,    -1,   997,    -1,   606,    -1,
     607,    -1,    10,   212,    -1,    11,    -1,    10,   608,   212,
      -1,   609,    -1,   610,    -1,   609,   610,    -1,   611,   612,
     614,    -1,   213,    -1,    -1,   612,   613,    -1,   964,    -1,
     965,    -1,   615,    -1,   616,    -1,    10,   214,    -1,    11,
      -1,    10,   617,   214,    -1,     4,    -1,    -1,   619,   620,
      -1,   113,    -1,   621,    -1,   622,    -1,    11,    -1,    10,
     623,   114,    -1,   624,   631,   638,   645,   652,   659,   666,
      -1,    -1,   625,   626,   627,    -1,   111,    -1,   983,    -1,
     628,    -1,   629,    -1,    11,    -1,    10,   630,   112,    -1,
     999,    -1,    -1,   632,   633,   634,    -1,    97,    -1,   983,
      -1,   635,    -1,   636,    -1,    11,    -1,    10,   637,    98,
      -1,   999,    -1,    -1,   639,   640,   641,    -1,    99,    -1,
     983,    -1,   642,    -1,   643,    -1,    11,    -1,    10,   644,
     100,    -1,   999,    -1,    -1,   646,   647,   648,    -1,    95,
      -1,   983,    -1,   649,    -1,   650,    -1,    11,    -1,    10,
     651,    96,    -1,   999,    -1,    -1,   653,   654,   655,    -1,
     141,    -1,   983,    -1,   656,    -1,   657,    -1,    11,    -1,
      10,   658,   142,    -1,   999,    -1,    -1,   660,   661,   662,
      -1,   185,    -1,   983,    -1,   663,    -1,   664,    -1,    11,
      -1,    10,   665,   186,    -1,   999,    -1,    -1,   667,   668,
     669,    -1,   199,    -1,   983,    -1,   670,    -1,   671,    -1,
      11,    -1,    10,   672,   200,    -1,   999,    -1,    -1,   673,
     674,    -1,   675,   676,   679,    -1,   155,    -1,   677,    -1,
      -1,   677,   678,    -1,   997,    -1,   984,    -1,   977,    -1,
     965,    -1,   960,    -1,   680,    -1,   681,    -1,    10,   156,
      -1,    11,    -1,    10,   682,   156,    -1,   683,    -1,   692,
      -1,   684,    -1,   683,   684,    -1,   685,   686,   688,    -1,
     213,    -1,    -1,   686,   687,    -1,   964,    -1,   965,    -1,
     689,    -1,   690,    -1,    10,   214,    -1,    11,    -1,    10,
     691,   214,    -1,  1015,    -1,   693,    -1,   692,   693,    -1,
     694,   695,   698,    -1,   129,    -1,   696,    -1,    -1,   696,
     697,    -1,   983,    -1,   977,    -1,   960,    -1,   699,    -1,
     700,    -1,    11,    -1,    10,   701,   130,    -1,   999,    -1,
      -1,   703,   704,   705,    -1,   149,    -1,    -1,   989,    -1,
     706,    -1,   707,    -1,    11,    -1,    10,   708,   150,    -1,
     709,   722,   777,    -1,    -1,   710,   711,   712,    -1,   209,
      -1,   986,    -1,   713,    -1,   714,    -1,    10,   210,    -1,
      11,    -1,    10,   715,   210,    -1,   716,    -1,   717,    -1,
     716,   717,    -1,   718,   719,   721,    -1,   147,    -1,    -1,
     719,   720,    -1,   964,    -1,   965,    -1,    10,  1014,   148,
      -1,    -1,   723,   724,    -1,   113,    -1,   725,    -1,   726,
      -1,    11,    -1,    10,   727,   114,    -1,   728,   735,   742,
     749,   756,   763,   770,    -1,    -1,   729,   730,   731,    -1,
     111,    -1,   983,    -1,   732,    -1,   733,    -1,    11,    -1,
      10,   734,   112,    -1,   999,    -1,    -1,   736,   737,   738,
      -1,    97,    -1,   983,    -1,   739,    -1,   740,    -1,    11,
      -1,    10,   741,    98,    -1,   999,    -1,    -1,   743,   744,
     745,    -1,    99,    -1,   983,    -1,   746,    -1,   747,    -1,
      11,    -1,    10,   748,   100,    -1,   999,    -1,    -1,   750,
     751,   752,    -1,    95,    -1,   983,    -1,   753,    -1,   754,
      -1,    11,    -1,    10,   755,    96,    -1,   999,    -1,    -1,
     757,   758,   759,    -1,   141,    -1,   983,    -1,   760,    -1,
     761,    -1,    11,    -1,    10,   762,   142,    -1,   999,    -1,
      -1,   764,   765,   766,    -1,   185,    -1,   983,    -1,   767,
      -1,   768,    -1,    11,    -1,    10,   769,   186,    -1,   999,
      -1,    -1,   771,   772,   773,    -1,   199,    -1,   983,    -1,
     774,    -1,   775,    -1,    11,    -1,    10,   776,   200,    -1,
     999,    -1,    -1,   777,   778,    -1,   779,   780,   783,    -1,
     155,    -1,   781,    -1,    -1,   781,   782,    -1,   986,    -1,
     984,    -1,   977,    -1,   965,    -1,   960,    -1,   784,    -1,
     785,    -1,    10,   156,    -1,    11,    -1,    10,   786,   156,
      -1,   787,    -1,   796,    -1,   788,    -1,   787,   788,    -1,
     789,   790,   792,    -1,   147,    -1,    -1,   790,   791,    -1,
     964,    -1,   965,    -1,   793,    -1,   794,    -1,    10,   148,
      -1,    11,    -1,    10,   795,   148,    -1,  1015,    -1,   797,
      -1,   796,   797,    -1,   798,   799,   802,    -1,   129,    -1,
     800,    -1,    -1,   800,   801,    -1,   983,    -1,   977,    -1,
     960,    -1,   803,    -1,   804,    -1,    11,    -1,    10,   805,
     130,    -1,   999,    -1,    -1,   807,   808,   809,    -1,   119,
      -1,    -1,   988,    -1,   810,    -1,   811,    -1,    11,    -1,
      10,   812,   120,    -1,   813,   826,   881,    -1,    -1,   814,
     815,   816,    -1,   125,    -1,   981,    -1,   817,    -1,   818,
      -1,    10,   126,    -1,    11,    -1,    10,   819,   126,    -1,
     820,    -1,   821,    -1,   820,   821,    -1,   822,   823,   825,
      -1,   117,    -1,    -1,   823,   824,    -1,   964,    -1,   965,
      -1,    10,  1014,   118,    -1,    -1,   827,   828,    -1,   113,
      -1,   829,    -1,   830,    -1,    11,    -1,    10,   831,   114,
      -1,   832,   839,   846,   853,   860,   867,   874,    -1,    -1,
     833,   834,   835,    -1,   111,    -1,   983,    -1,   836,    -1,
     837,    -1,    11,    -1,    10,   838,   112,    -1,   999,    -1,
      -1,   840,   841,   842,    -1,    97,    -1,   983,    -1,   843,
      -1,   844,    -1,    11,    -1,    10,   845,    98,    -1,   999,
      -1,    -1,   847,   848,   849,    -1,    99,    -1,   983,    -1,
     850,    -1,   851,    -1,    11,    -1,    10,   852,   100,    -1,
     999,    -1,    -1,   854,   855,   856,    -1,    95,    -1,   983,
      -1,   857,    -1,   858,    -1,    11,    -1,    10,   859,    96,
      -1,   999,    -1,    -1,   861,   862,   863,    -1,   141,    -1,
     983,    -1,   864,    -1,   865,    -1,    11,    -1,    10,   866,
     142,    -1,   999,    -1,    -1,   868,   869,   870,    -1,   185,
      -1,   983,    -1,   871,    -1,   872,    -1,    11,    -1,    10,
     873,   186,    -1,   999,    -1,    -1,   875,   876,   877,    -1,
     199,    -1,   983,    -1,   878,    -1,   879,    -1,    11,    -1,
      10,   880,   200,    -1,   999,    -1,    -1,   881,   882,    -1,
     883,   884,   887,    -1,   155,    -1,   885,    -1,    -1,   885,
     886,    -1,   981,    -1,   984,    -1,   977,    -1,   965,    -1,
     960,    -1,   888,    -1,   889,    -1,    10,   156,    -1,    11,
      -1,    10,   890,   156,    -1,   891,    -1,   900,    -1,   892,
      -1,   891,   892,    -1,   893,   894,   896,    -1,   117,    -1,
      -1,   894,   895,    -1,   964,    -1,   965,    -1,   897,    -1,
     898,    -1,    10,   118,    -1,    11,    -1,    10,   899,   118,
      -1,  1015,    -1,   901,    -1,   900,   901,    -1,   902,   903,
     906,    -1,   129,    -1,   904,    -1,    -1,   904,   905,    -1,
     983,    -1,   977,    -1,   960,    -1,   907,    -1,   908,    -1,
      11,    -1,    10,   909,   130,    -1,   999,    -1,    -1,   911,
     912,   913,    -1,   161,    -1,   991,    -1,   914,    -1,   915,
      -1,    10,   162,    -1,    11,    -1,    10,   916,   162,    -1,
     917,    -1,   918,    -1,   917,   918,    -1,   919,   920,   923,
      -1,   159,    -1,   921,    -1,    -1,   921,   922,    -1,   965,
      -1,   956,    -1,   960,    -1,   985,    -1,   924,    -1,   925,
      -1,    10,   160,    -1,    11,    -1,    10,   926,   160,    -1,
     927,    -1,   928,    -1,   927,   928,    -1,   929,    -1,   930,
      -1,   931,    -1,    71,    -1,    72,    -1,    69,   932,    70,
      -1,     5,    -1,    -1,   934,   935,   936,    -1,   163,    -1,
     994,    -1,   937,    -1,   938,    -1,    10,   164,    -1,    11,
      -1,    10,   939,   164,    -1,   940,    -1,   941,    -1,   940,
     941,    -1,   942,   943,   946,    -1,   177,    -1,   944,    -1,
      -1,   944,   945,    -1,   965,    -1,   956,    -1,   960,    -1,
     985,    -1,   947,    -1,   948,    -1,    10,   178,    -1,    11,
      -1,    10,   949,   178,    -1,   950,    -1,   951,    -1,   950,
     951,    -1,   952,    -1,   953,    -1,   954,    -1,    71,    -1,
      72,    -1,    69,   955,    70,    -1,     5,    -1,   957,    -1,
     958,    -1,   959,    -1,    42,    -1,    41,     3,  1016,    -1,
     961,    -1,   962,    -1,   963,    -1,    44,    -1,    43,     3,
    1016,    -1,    37,  1016,     6,  1016,    -1,   966,    -1,   967,
      -1,   968,    -1,    46,    -1,    45,     3,  1016,    -1,   970,
      -1,   971,    -1,   972,    -1,    48,    -1,    47,     3,  1016,
      -1,   974,    -1,   975,    -1,   976,    -1,    50,    -1,    49,
       3,  1016,    -1,   978,    -1,   979,    -1,   980,    -1,    52,
      -1,    51,     3,  1016,    -1,    16,  1016,     6,  1016,    -1,
      17,  1016,     6,  1016,    -1,    18,  1016,     6,  1016,    -1,
      19,  1016,     6,  1016,    -1,    21,  1016,     6,  1016,    -1,
      22,  1016,     6,  1016,    -1,    23,  1016,     6,  1016,    -1,
      24,  1016,     6,  1016,    -1,    25,  1016,     6,  1016,    -1,
      26,  1016,     6,  1016,    -1,    27,  1016,     6,  1016,    -1,
      28,  1016,     6,  1016,    -1,    29,  1016,     6,  1016,    -1,
      30,  1016,     6,  1016,    -1,    31,  1016,     6,  1016,    -1,
      32,  1016,     6,  1016,    -1,    33,  1016,     6,  1016,    -1,
      34,  1016,     6,  1016,    -1,  1000,    -1,  1007,    -1,    -1,
    1000,  1001,    -1,  1002,  1003,  1006,    -1,   127,    -1,  1004,
      -1,    -1,  1004,  1005,    -1,  1013,    -1,  1012,    -1,    10,
       6,   128,    -1,   109,  1008,  1009,    -1,    40,  1016,     6,
    1016,    -1,  1010,    -1,  1011,    -1,    10,   110,    -1,    11,
      -1,    10,     4,   110,    -1,    38,  1016,     6,  1016,    -1,
      39,  1016,     6,  1016,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1017,     8,    -1,    -1,  1017,
    1018,    -1,   220,    -1,   221,    -1,   222,    -1,   223,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   194,   196,   203,   210,   210,   212,   212,
     214,   216,   218,   219,   222,   231,   231,   238,   247,   247,
     249,   251,   253,   255,   255,   257,   257,   259,   259,   261,
     267,   267,   269,   269,   271,   271,   273,   279,   279,   281,
     281,   283,   283,   285,   291,   291,   293,   293,   295,   295,
     297,   303,   303,   305,   305,   307,   307,   309,   320,   320,
     322,   336,   336,   338,   338,   340,   342,   344,   344,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   358,   360,
     375,   382,   382,   385,   390,   394,   403,   407,   412,   412,
     414,   416,   418,   418,   420,   425,   435,   441,   441,   444,
     449,   455,   455,   458,   460,   467,   467,   469,   469,   471,
     473,   476,   478,   485,   485,   487,   487,   489,   491,   496,
     498,   505,   505,   507,   507,   509,   511,   516,   518,   525,
     525,   527,   527,   529,   531,   536,   538,   545,   545,   547,
     547,   549,   551,   556,   558,   565,   565,   567,   567,   569,
     571,   576,   578,   585,   585,   587,   587,   589,   591,   596,
     598,   605,   615,   620,   626,   626,   628,   630,   632,   632,
     634,   639,   651,   657,   657,   660,   667,   672,   679,   679,
     683,   683,   685,   696,   696,   698,   698,   700,   702,   704,
     704,   707,   708,   709,   710,   711,   712,   715,   717,   724,
     724,   726,   726,   728,   730,   737,   739,   750,   752,   752,
     755,   761,   767,   769,   775,   777,   788,   790,   790,   793,
     799,   805,   807,   814,   816,   827,   829,   829,   832,   838,
     844,   846,   853,   855,   864,   865,   871,   873,   879,   881,
     888,   898,   903,   909,   909,   911,   913,   915,   915,   917,
     922,   934,   940,   940,   943,   950,   955,   961,   961,   965,
     965,   967,   978,   978,   980,   980,   982,   984,   986,   986,
     989,   990,   991,   992,   993,   994,   997,   999,  1006,  1006,
    1008,  1008,  1010,  1012,  1020,  1022,  1029,  1029,  1031,  1031,
    1033,  1035,  1040,  1042,  1049,  1049,  1051,  1051,  1053,  1055,
    1060,  1062,  1069,  1069,  1071,  1071,  1073,  1075,  1080,  1082,
    1089,  1089,  1091,  1091,  1093,  1095,  1102,  1104,  1111,  1121,
    1126,  1132,  1132,  1134,  1136,  1138,  1138,  1140,  1145,  1157,
    1163,  1163,  1166,  1173,  1178,  1185,  1185,  1188,  1188,  1190,
    1206,  1206,  1208,  1208,  1210,  1212,  1214,  1214,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1230,
    1232,  1239,  1239,  1241,  1241,  1243,  1245,  1253,  1255,  1262,
    1262,  1264,  1264,  1266,  1268,  1273,  1275,  1282,  1282,  1284,
    1284,  1286,  1288,  1293,  1295,  1302,  1302,  1304,  1304,  1306,
    1308,  1313,  1315,  1322,  1322,  1324,  1324,  1326,  1328,  1333,
    1335,  1342,  1352,  1357,  1363,  1363,  1365,  1367,  1369,  1369,
    1371,  1373,  1387,  1387,  1390,  1390,  1390,  1390,  1393,  1393,
    1395,  1395,  1397,  1399,  1408,  1409,  1412,  1414,  1425,  1427,
    1427,  1430,  1436,  1442,  1444,  1451,  1453,  1464,  1466,  1466,
    1469,  1475,  1481,  1483,  1490,  1492,  1503,  1505,  1505,  1508,
    1514,  1520,  1522,  1529,  1531,  1541,  1542,  1548,  1550,  1557,
    1559,  1566,  1576,  1581,  1587,  1587,  1589,  1591,  1593,  1593,
    1595,  1600,  1612,  1618,  1618,  1621,  1628,  1633,  1640,  1640,
    1643,  1643,  1645,  1653,  1659,  1659,  1662,  1669,  1675,  1681,
    1689,  1694,  1700,  1700,  1702,  1704,  1706,  1706,  1708,  1710,
    1719,  1721,  1721,  1723,  1723,  1723,  1725,  1735,  1745,  1765,
    1771,  1773,  1783,  1789,  1789,  1792,  1797,  1802,  1812,  1817,
    1823,  1823,  1825,  1827,  1829,  1829,  1831,  1836,  1846,  1852,
    1852,  1855,  1861,  1868,  1868,  1871,  1871,  1873,  1875,  1875,
    1877,  1877,  1879,  1881,  1889,  1889,  1891,  1897,  1897,  1905,
    1905,  1907,  1909,  1911,  1913,  1913,  1915,  1917,  1925,  1930,
    1936,  1936,  1938,  1940,  1942,  1942,  1944,  1955,  1964,  1964,
    1967,  1968,  1971,  1974,  1974,  1976,  1978,  1986,  1991,  1997,
    1997,  1999,  2001,  2003,  2003,  2005,  2016,  2025,  2025,  2028,
    2029,  2033,  2034,  2036,  2036,  2038,  2040,  2045,  2045,  2047,
    2052,  2052,  2054,  2056,  2058,  2060,  2060,  2069,  2071,  2078,
    2078,  2080,  2082,  2084,  2087,  2087,  2097,  2099,  2106,  2106,
    2108,  2110,  2112,  2115,  2115,  2124,  2126,  2133,  2133,  2135,
    2137,  2139,  2142,  2142,  2151,  2153,  2160,  2160,  2162,  2164,
    2166,  2169,  2169,  2178,  2180,  2187,  2187,  2189,  2191,  2193,
    2196,  2196,  2205,  2207,  2214,  2214,  2216,  2218,  2220,  2223,
    2223,  2232,  2234,  2241,  2241,  2243,  2245,  2247,  2250,  2250,
    2252,  2257,  2270,  2276,  2276,  2279,  2290,  2301,  2307,  2313,
    2320,  2320,  2322,  2322,  2324,  2326,  2326,  2328,  2328,  2330,
    2337,  2346,  2346,  2349,  2355,  2362,  2362,  2364,  2364,  2366,
    2368,  2377,  2377,  2379,  2390,  2398,  2404,  2404,  2407,  2413,
    2414,  2418,  2418,  2420,  2422,  2425,  2429,  2429,  2431,  2439,
    2439,  2447,  2447,  2449,  2451,  2453,  2455,  2455,  2457,  2459,
    2467,  2472,  2478,  2478,  2480,  2482,  2485,  2485,  2487,  2496,
    2506,  2506,  2509,  2510,  2513,  2516,  2516,  2518,  2523,  2523,
    2526,  2528,  2530,  2532,  2532,  2541,  2543,  2550,  2550,  2552,
    2554,  2556,  2558,  2558,  2567,  2569,  2576,  2576,  2578,  2580,
    2582,  2585,  2585,  2594,  2596,  2603,  2603,  2605,  2607,  2609,
    2612,  2612,  2621,  2623,  2630,  2630,  2632,  2634,  2636,  2639,
    2639,  2648,  2650,  2657,  2657,  2659,  2661,  2663,  2666,  2666,
    2675,  2677,  2684,  2684,  2686,  2688,  2690,  2693,  2693,  2702,
    2704,  2711,  2711,  2713,  2715,  2717,  2720,  2720,  2722,  2728,
    2741,  2748,  2748,  2751,  2762,  2773,  2779,  2785,  2794,  2794,
    2796,  2796,  2798,  2800,  2800,  2802,  2802,  2804,  2809,  2819,
    2819,  2822,  2827,  2834,  2834,  2836,  2836,  2838,  2840,  2847,
    2847,  2849,  2860,  2868,  2874,  2874,  2877,  2883,  2884,  2888,
    2888,  2890,  2892,  2895,  2898,  2898,  2900,  2907,  2907,  2915,
    2915,  2917,  2919,  2921,  2923,  2923,  2925,  2928,  2936,  2941,
    2947,  2947,  2949,  2951,  2953,  2953,  2955,  2964,  2973,  2973,
    2976,  2977,  2980,  2983,  2983,  2985,  2990,  2990,  2992,  2994,
    2996,  2998,  2998,  3007,  3009,  3016,  3016,  3018,  3020,  3022,
    3024,  3024,  3033,  3035,  3042,  3042,  3044,  3046,  3048,  3051,
    3051,  3060,  3062,  3069,  3069,  3071,  3073,  3075,  3078,  3078,
    3087,  3089,  3096,  3096,  3098,  3100,  3102,  3105,  3105,  3114,
    3116,  3123,  3123,  3125,  3127,  3129,  3132,  3132,  3141,  3143,
    3150,  3150,  3152,  3154,  3156,  3159,  3159,  3168,  3170,  3177,
    3177,  3179,  3181,  3183,  3186,  3186,  3188,  3194,  3207,  3213,
    3213,  3216,  3227,  3238,  3244,  3250,  3257,  3257,  3259,  3259,
    3261,  3263,  3263,  3265,  3265,  3267,  3274,  3283,  3283,  3287,
    3292,  3300,  3300,  3302,  3302,  3304,  3306,  3313,  3313,  3315,
    3326,  3334,  3340,  3340,  3343,  3349,  3350,  3354,  3354,  3356,
    3358,  3360,  3364,  3364,  3366,  3371,  3380,  3385,  3391,  3391,
    3393,  3395,  3397,  3397,  3399,  3404,  3416,  3424,  3424,  3427,
    3433,  3439,  3447,  3457,  3462,  3468,  3468,  3470,  3472,  3474,
    3474,  3476,  3482,  3487,  3489,  3489,  3491,  3493,  3505,  3505,
    3507,  3512,  3521,  3526,  3532,  3532,  3534,  3536,  3538,  3538,
    3540,  3545,  3557,  3565,  3565,  3568,  3573,  3579,  3585,  3594,
    3599,  3605,  3605,  3607,  3609,  3611,  3611,  3613,  3619,  3624,
    3626,  3626,  3628,  3630,  3641,  3648,  3648,  3650,  3655,  3660,
    3667,  3667,  3669,  3674,  3679,  3687,  3694,  3694,  3696,  3701,
    3706,  3713,  3713,  3715,  3720,  3725,  3732,  3732,  3734,  3739,
    3744,  3751,  3751,  3753,  3758,  3764,  3770,  3779,  3785,  3799,
    3808,  3814,  3823,  3829,  3835,  3841,  3847,  3853,  3862,  3868,
    3877,  3882,  3888,  3915,  3920,  3922,  3922,  3924,  3926,  3935,
    3937,  3937,  3939,  3939,  3941,  3949,  3951,  3956,  3956,  3958,
    3958,  3960,  3983,  3991,  4005,  4006,  4010,  4011,  4012,  4014,
    4016,  4016,  4018,  4019,  4020,  4021
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
  "EMPTYTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT", "EMPTYVALUEATT",
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
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
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "idxAttribute", "nameAttribute", "nameAtt",
  "nameAttEmpty", "nameAttContent", "typeAttribute", "typeAtt",
  "typeAttEmpty", "typeAttContent", "unitAttribute", "unitAtt",
  "unitAttEmpty", "unitAttContent", "valueAttribute", "valueAtt",
  "valueAttEmpty", "valueAttContent", "numberOfConAttribute",
  "numberOfConstraintsAttribute", "numberOfElAttribute",
  "numberOfEnumerationsAttribute", "numberOfItemsAttribute",
  "numberOfObjAttribute", "numberOfObjectivesAttribute",
  "numberOfOtherConstraintResultsAttribute",
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
      32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   224,   225,   225,   226,   227,   228,   228,   229,   229,
     230,   231,   232,   232,   233,   234,   234,   235,   236,   236,
     237,   238,   239,   240,   240,   241,   241,   242,   242,   243,
     244,   244,   245,   245,   246,   246,   247,   248,   248,   249,
     249,   250,   250,   251,   252,   252,   253,   253,   254,   254,
     255,   256,   256,   257,   257,   258,   258,   259,   260,   260,
     261,   262,   262,   263,   263,   264,   265,   266,   266,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   268,   269,
     270,   271,   271,   272,   272,   272,   273,   273,   274,   274,
     275,   276,   277,   277,   278,   279,   280,   281,   281,   282,
     282,   283,   283,   284,   285,   286,   286,   287,   287,   288,
     289,   290,   291,   292,   292,   293,   293,   294,   295,   296,
     297,   298,   298,   299,   299,   300,   301,   302,   303,   304,
     304,   305,   305,   306,   307,   308,   309,   310,   310,   311,
     311,   312,   313,   314,   315,   316,   316,   317,   317,   318,
     319,   320,   321,   322,   322,   323,   323,   324,   325,   326,
     327,   328,   329,   329,   330,   330,   331,   332,   333,   333,
     334,   335,   336,   337,   337,   338,   338,   338,   339,   339,
     340,   340,   341,   342,   342,   343,   343,   344,   345,   346,
     346,   347,   347,   347,   347,   347,   347,   348,   349,   350,
     350,   351,   351,   352,   353,   354,   355,   356,   357,   357,
     358,   358,   359,   360,   361,   362,   363,   364,   364,   365,
     365,   366,   367,   368,   369,   370,   371,   371,   372,   372,
     373,   374,   375,   376,   377,   377,   378,   379,   380,   381,
     382,   383,   383,   384,   384,   385,   386,   387,   387,   388,
     389,   390,   391,   391,   392,   392,   392,   393,   393,   394,
     394,   395,   396,   396,   397,   397,   398,   399,   400,   400,
     401,   401,   401,   401,   401,   401,   402,   403,   404,   404,
     405,   405,   406,   407,   408,   409,   410,   410,   411,   411,
     412,   413,   414,   415,   416,   416,   417,   417,   418,   419,
     420,   421,   422,   422,   423,   423,   424,   425,   426,   427,
     428,   428,   429,   429,   430,   431,   432,   433,   434,   435,
     435,   436,   436,   437,   438,   439,   439,   440,   441,   442,
     443,   443,   444,   444,   444,   445,   445,   446,   446,   447,
     448,   448,   449,   449,   450,   451,   452,   452,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   454,
     455,   456,   456,   457,   457,   458,   459,   460,   461,   462,
     462,   463,   463,   464,   465,   466,   467,   468,   468,   469,
     469,   470,   471,   472,   473,   474,   474,   475,   475,   476,
     477,   478,   479,   480,   480,   481,   481,   482,   483,   484,
     485,   486,   487,   487,   488,   488,   489,   490,   491,   491,
     492,   493,   494,   494,   495,   495,   495,   495,   496,   496,
     497,   497,   498,   499,   500,   500,   501,   502,   503,   504,
     504,   505,   505,   506,   507,   508,   509,   510,   511,   511,
     512,   512,   513,   514,   515,   516,   517,   518,   518,   519,
     519,   520,   521,   522,   523,   524,   524,   525,   526,   527,
     528,   529,   530,   530,   531,   531,   532,   533,   534,   534,
     535,   536,   537,   538,   538,   539,   539,   539,   540,   540,
     541,   541,   542,   543,   544,   544,   545,   545,   545,   545,
     546,   546,   547,   547,   548,   549,   550,   550,   551,   552,
     553,   554,   554,   555,   555,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   563,   564,   564,   564,   565,   565,
     566,   566,   567,   568,   569,   569,   570,   571,   572,   573,
     573,   574,   574,   575,   575,   576,   576,   577,   578,   578,
     579,   579,   580,   581,   582,   582,   583,   584,   584,   585,
     585,   586,   587,   588,   589,   589,   590,   591,   592,   592,
     593,   593,   594,   595,   596,   596,   597,   598,   599,   599,
     600,   600,   601,   602,   602,   603,   604,   605,   605,   606,
     606,   607,   608,   609,   609,   610,   611,   612,   612,   613,
     613,   614,   614,   615,   615,   616,   617,   618,   618,   619,
     620,   620,   621,   622,   623,   624,   624,   625,   626,   627,
     627,   628,   629,   630,   631,   631,   632,   633,   634,   634,
     635,   636,   637,   638,   638,   639,   640,   641,   641,   642,
     643,   644,   645,   645,   646,   647,   648,   648,   649,   650,
     651,   652,   652,   653,   654,   655,   655,   656,   657,   658,
     659,   659,   660,   661,   662,   662,   663,   664,   665,   666,
     666,   667,   668,   669,   669,   670,   671,   672,   673,   673,
     674,   675,   676,   677,   677,   678,   678,   678,   678,   678,
     679,   679,   680,   680,   681,   682,   682,   683,   683,   684,
     685,   686,   686,   687,   687,   688,   688,   689,   689,   690,
     691,   692,   692,   693,   694,   695,   696,   696,   697,   697,
     697,   698,   698,   699,   700,   701,   702,   702,   703,   704,
     704,   705,   705,   706,   707,   708,   709,   709,   710,   711,
     712,   712,   713,   713,   714,   715,   716,   716,   717,   718,
     719,   719,   720,   720,   721,   722,   722,   723,   724,   724,
     725,   726,   727,   728,   728,   729,   730,   731,   731,   732,
     733,   734,   735,   735,   736,   737,   738,   738,   739,   740,
     741,   742,   742,   743,   744,   745,   745,   746,   747,   748,
     749,   749,   750,   751,   752,   752,   753,   754,   755,   756,
     756,   757,   758,   759,   759,   760,   761,   762,   763,   763,
     764,   765,   766,   766,   767,   768,   769,   770,   770,   771,
     772,   773,   773,   774,   775,   776,   777,   777,   778,   779,
     780,   781,   781,   782,   782,   782,   782,   782,   783,   783,
     784,   784,   785,   786,   786,   787,   787,   788,   789,   790,
     790,   791,   791,   792,   792,   793,   793,   794,   795,   796,
     796,   797,   798,   799,   800,   800,   801,   801,   801,   802,
     802,   803,   804,   805,   806,   806,   807,   808,   808,   809,
     809,   810,   811,   812,   813,   813,   814,   815,   816,   816,
     817,   817,   818,   819,   820,   820,   821,   822,   823,   823,
     824,   824,   825,   826,   826,   827,   828,   828,   829,   830,
     831,   832,   832,   833,   834,   835,   835,   836,   837,   838,
     839,   839,   840,   841,   842,   842,   843,   844,   845,   846,
     846,   847,   848,   849,   849,   850,   851,   852,   853,   853,
     854,   855,   856,   856,   857,   858,   859,   860,   860,   861,
     862,   863,   863,   864,   865,   866,   867,   867,   868,   869,
     870,   870,   871,   872,   873,   874,   874,   875,   876,   877,
     877,   878,   879,   880,   881,   881,   882,   883,   884,   885,
     885,   886,   886,   886,   886,   886,   887,   887,   888,   888,
     889,   890,   890,   891,   891,   892,   893,   894,   894,   895,
     895,   896,   896,   897,   897,   898,   899,   900,   900,   901,
     902,   903,   904,   904,   905,   905,   905,   906,   906,   907,
     908,   909,   910,   910,   911,   912,   913,   913,   914,   914,
     915,   916,   917,   917,   918,   919,   920,   921,   921,   922,
     922,   922,   922,   923,   923,   924,   924,   925,   926,   927,
     927,   928,   929,   929,   930,   930,   931,   932,   933,   933,
     934,   935,   936,   936,   937,   937,   938,   939,   940,   940,
     941,   942,   943,   944,   944,   945,   945,   945,   945,   946,
     946,   947,   947,   948,   949,   950,   950,   951,   952,   952,
     953,   953,   954,   955,   956,   957,   957,   958,   959,   960,
     961,   961,   962,   963,   964,   965,   966,   966,   967,   968,
     969,   970,   970,   971,   972,   973,   974,   974,   975,   976,
     977,   978,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,   999,  1000,  1000,  1001,  1002,  1003,
    1004,  1004,  1005,  1005,  1006,  1007,  1008,  1009,  1009,  1010,
    1010,  1011,  1012,  1013,  1014,  1014,  1015,  1015,  1015,  1016,
    1017,  1017,  1018,  1018,  1018,  1018
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
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     3,     3,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     3,     0,     2,     1,     1,     1,
       1,     3,     7,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     3,     0,     2,     1,     1,     1,     1,     3,
       7,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     3,
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
     195,   234,   196,     0,    65,    68,  1160,     0,  1092,     0,
    1103,     0,    80,    81,    84,  1089,  1090,  1091,    83,  1100,
    1101,  1102,    85,     0,   108,   103,   105,   106,     0,   116,
     111,   113,   114,     0,   124,   119,   121,   122,     0,   132,
     127,   129,   130,     0,   140,   135,   137,   138,     0,   148,
     143,   145,   146,     0,   156,   151,   153,   154,  1160,     0,
     161,    29,     0,     0,    42,    41,    44,    38,    39,    40,
     482,    14,   484,     0,   343,   338,   340,   341,   264,   285,
     277,   317,   309,   301,   293,     0,   267,   268,   270,     0,
     271,     0,   272,     0,   273,     0,   274,     0,   275,     0,
     187,   190,     0,   202,   197,   199,   200,     0,   207,     0,
     216,     0,   225,     0,   235,     0,   240,     0,     0,  1160,
    1160,     0,    89,    78,    86,    87,    82,   110,   107,     0,
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
     318,   204,   201,     0,     0,   205,     0,  1108,   209,   211,
     210,  1105,  1106,  1107,     0,   214,   218,   220,   219,     0,
     223,   227,   229,   228,     0,   232,     0,   244,   238,   241,
     242,  1160,  1159,  1162,  1163,  1164,  1165,  1161,  1093,  1104,
      88,    95,     0,    91,    92,    97,   109,   117,   125,   133,
     141,   149,   157,  1160,   171,   164,     0,   167,   168,   173,
      43,     0,     0,    56,    55,    22,    52,    53,    54,     0,
     493,   481,   490,   491,  1160,  1160,  1160,  1160,   485,   488,
     489,   486,   487,   344,   347,     0,   364,   359,   361,   362,
       0,   372,   367,   369,   370,     0,   380,   375,   377,   378,
       0,   388,   383,   385,   386,     0,   396,   391,   393,   394,
    1160,     0,   401,     0,   428,     0,   437,     0,   446,     0,
     456,     0,   461,   283,   280,     0,   291,   288,     0,   299,
     296,     0,   307,   304,     0,  1154,  1155,   312,     0,   315,
       0,   322,   316,   319,   320,   203,     0,   213,  1160,     0,
     222,     0,   231,   237,     0,   250,   243,     0,   246,   247,
     252,  1129,    90,    93,     0,    96,  1124,   166,   169,     0,
     172,    50,     0,   492,   499,     0,  1048,   496,   501,     0,
       0,     0,     0,   366,   363,     0,   374,   371,     0,   382,
     379,     0,   390,   387,     0,   398,   395,     0,     0,     0,
     405,   399,   402,   403,     0,   426,   430,   432,   431,     0,
     435,   439,   441,   440,     0,   444,   448,   450,   449,     0,
     453,     0,   465,   459,   462,   463,   282,   290,   298,   306,
     314,   328,   321,     0,   324,   325,   330,   212,  1109,   221,
     230,   236,   245,   248,     0,   251,     0,   102,    94,     0,
    1098,    98,   100,    99,  1095,  1096,  1097,     0,   179,   170,
       0,  1113,   174,   177,   175,   176,  1110,  1111,  1112,    57,
     494,  1050,   497,   495,     0,     0,   500,  1160,  1160,  1160,
    1160,   365,   373,   381,   389,   397,  1160,   411,   404,     0,
     407,   408,   412,     0,   434,     0,   443,     0,   452,   458,
       0,   471,   464,     0,   467,   468,   473,   323,   326,     0,
     329,     0,   258,   249,   253,   256,   254,   255,   101,  1160,
     178,  1160,  1160,     0,  1051,     0,   498,  1160,     0,     0,
     502,   503,   504,   505,  1116,  1121,  1127,  1132,  1130,   406,
     409,     0,   433,   442,   451,   457,   466,   469,     0,   472,
       0,   336,   327,   331,   334,   332,   333,   257,  1099,  1114,
       0,     0,  1055,  1049,  1052,  1053,   511,   535,     0,     0,
    1160,  1160,     0,   421,     0,  1087,   413,   410,   418,   419,
     416,  1084,  1085,  1086,   417,   415,   414,     0,   479,   470,
     474,   477,   475,   476,   335,  1160,  1054,  1061,     0,  1057,
    1058,  1063,   537,   544,     0,     0,   512,   513,   516,   515,
     517,  1160,   508,   507,   425,   424,   420,     0,   423,  1160,
     478,  1128,  1056,  1059,     0,  1062,   546,   716,   547,     0,
     541,   536,   538,   539,     0,   521,   510,   518,   519,   514,
     506,   422,  1088,     0,  1072,  1060,  1069,  1070,  1160,  1064,
    1066,  1067,  1065,  1068,   718,   864,   719,  1160,     0,   548,
     543,   540,     0,   520,   527,     0,   523,   524,   529,     0,
    1080,  1081,  1071,     0,  1074,  1075,  1077,  1078,  1079,     0,
     866,  1012,   867,  1160,     0,   720,     0,   554,   551,   545,
     549,   550,   542,   522,   525,     0,   528,  1083,     0,  1073,
    1076,  1160,  1014,     0,     0,  1160,     0,   868,     0,   726,
     723,   717,   721,   722,  1160,   556,     0,   573,     0,     0,
     534,   526,   530,   532,   531,  1082,  1119,   509,  1160,     0,
    1015,     0,   874,   871,   865,   869,   870,  1160,   728,     0,
     745,     0,  1126,   552,   575,   597,     0,  1160,     0,   557,
     533,     0,     0,  1019,  1013,  1016,  1017,  1160,   876,     0,
     893,     0,  1123,   724,   747,   816,     0,  1160,     0,   729,
     599,   668,     0,     0,   576,     0,     0,   561,   555,   558,
     559,  1160,  1025,  1018,     0,  1021,  1022,  1027,  1122,   872,
     895,   964,     0,  1160,     0,   877,   725,   753,   750,   746,
     748,   749,     0,     0,   733,   727,   730,   731,   553,   605,
     602,   598,   600,   601,     0,   580,   574,   577,   578,  1160,
     560,   567,     0,   563,   564,   568,  1125,  1020,  1023,     0,
    1026,   873,   901,   898,   894,   896,   897,     0,     0,   881,
     875,   878,   879,   819,   817,   821,   755,     0,   762,     0,
    1160,   739,   732,     0,   735,   736,   740,   671,   669,   673,
     607,     0,   614,     0,   579,   586,     0,   582,   583,   587,
    1131,   562,   565,     0,     0,  1036,  1024,  1033,  1034,  1028,
    1030,  1031,  1029,  1032,   967,   965,   969,   903,     0,   910,
       0,  1160,   887,   880,     0,   883,   884,   888,     0,   820,
     751,   764,   771,     0,  1160,     0,   756,  1120,   734,   737,
       0,     0,   672,   603,   616,   623,     0,     0,   608,   581,
     584,     0,     0,  1160,   569,   566,   570,   571,     0,  1044,
    1045,  1035,     0,  1038,  1039,  1041,  1042,  1043,     0,   968,
     899,   912,   919,     0,     0,   904,  1115,   882,   885,     0,
       0,   831,   818,   828,   829,  1160,   822,   827,   826,   825,
     824,   823,   773,   780,     0,     0,   765,     0,  1135,   759,
     754,   757,   758,     0,   741,   738,   742,   743,     0,   683,
     670,   680,   681,   674,   679,   678,   677,   676,   675,   625,
     632,     0,     0,   617,  1135,   611,   606,   609,   610,     0,
     594,   588,   585,   591,   592,   589,   590,     0,     0,  1047,
       0,  1037,  1040,     0,   979,   966,   976,   977,   970,   975,
     974,   973,   971,   972,   921,   928,     0,     0,   913,  1135,
     907,   902,   905,   906,     0,   889,   886,   890,   891,   852,
     838,   830,     0,   833,   835,   839,   834,   849,   854,     0,
     782,   789,     0,     0,   774,  1135,   768,   763,   766,   767,
    1160,     0,     0,   761,  1133,  1134,     0,   704,   682,   690,
       0,   685,   687,   691,   686,   701,   706,   634,   641,     0,
       0,   626,  1135,   620,   615,   618,   619,     0,   613,   596,
     593,     0,   572,  1160,  1046,   986,  1000,   978,     0,   981,
     983,   987,   982,   997,  1002,   930,   937,     0,     0,   922,
    1135,   916,   911,   914,   915,     0,   909,     0,   832,   836,
       0,   850,     0,   853,  1160,   791,   798,     0,     0,   783,
    1135,   777,   772,   775,   776,     0,   770,  1117,  1160,     0,
     760,  1138,  1136,  1140,   744,   684,   688,     0,   702,     0,
     705,   643,   650,     0,     0,   635,  1135,   629,   624,   627,
     628,     0,   622,   612,   595,  1094,   980,   984,     0,   998,
       0,  1001,   939,   946,     0,     0,   931,  1135,   925,   920,
     923,   924,     0,   918,   908,   892,     0,   846,   840,   837,
     843,   844,   841,   842,  1135,   861,   851,   859,   860,   855,
     858,   857,   856,  1118,   800,   807,     0,     0,   792,  1135,
     786,   781,   784,   785,     0,   779,   769,     0,     0,  1150,
    1145,  1147,  1148,     0,  1139,     0,   698,   692,   689,   695,
     696,   693,   694,  1135,   713,   703,   711,   712,   707,   710,
     709,   708,   652,   659,     0,     0,   644,  1135,   638,   633,
     636,   637,     0,   631,   621,     0,   994,   988,   985,   991,
     992,   989,   990,  1135,  1009,   999,  1007,  1008,  1003,  1006,
    1005,  1004,   948,   955,     0,     0,   940,  1135,   934,   929,
     932,   933,     0,   927,   917,  1156,  1157,  1158,   845,     0,
     848,     0,   863,   809,   752,     0,     0,   801,  1135,   795,
     790,   793,   794,     0,   788,   778,  1160,     0,  1149,     0,
    1137,  1160,  1160,  1141,  1143,  1142,   697,     0,   700,     0,
     715,   661,   604,     0,     0,   653,  1135,   647,   642,   645,
     646,     0,   640,   630,   993,     0,   996,     0,  1011,   957,
     900,     0,     0,   949,  1135,   943,   938,   941,   942,     0,
     936,   926,   847,   862,     0,   810,  1135,   804,   799,   802,
     803,     0,   797,   787,  1146,  1151,     0,     0,     0,   699,
     714,     0,   662,  1135,   656,   651,   654,   655,     0,   649,
     639,   995,  1010,     0,   958,  1135,   952,   947,   950,   951,
       0,   945,   935,  1135,   813,   808,   811,   812,     0,   806,
     796,  1144,  1160,  1160,  1135,   665,   660,   663,   664,     0,
     658,   648,  1135,   961,   956,   959,   960,     0,   954,   944,
       0,   815,   805,  1152,  1153,     0,   667,   657,     0,   963,
     953,   814,   666,   962
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
     930,   972,   973,   974,   975,  1023,  1074,  1075,   895,   896,
     923,   966,   967,   968,  1016,  1017,  1018,  1019,  1071,  1151,
    1152,  1153,  1154,  1241,   921,   922,   961,   962,   963,  1011,
    1012,  1013,  1067,  1146,  1147,  1148,  1237,  1065,  1066,  1142,
    1234,  1235,  1236,  1311,  1140,  1141,  1230,  1308,  1309,  1310,
    1402,  1228,  1229,  1304,  1399,  1400,  1401,  1481,  1302,  1303,
    1395,  1478,  1479,  1480,  1528,  1393,  1394,  1474,  1525,  1526,
    1527,  1559,  1472,  1473,  1521,  1556,  1557,  1558,  1575,   958,
    1008,  1009,  1061,  1062,  1133,  1130,  1131,  1132,  1220,  1221,
    1222,  1223,  1297,  1377,  1378,  1379,  1380,  1467,  1224,  1225,
    1226,  1299,  1300,  1388,  1385,  1386,  1387,  1469,   805,   806,
     834,   861,   862,   863,   889,   890,   891,   918,   955,   956,
     957,  1003,  1004,  1005,  1006,  1060,  1124,  1125,   915,   916,
     949,   950,   951,   997,   998,   999,  1055,  1120,  1121,  1122,
    1212,  1052,  1053,  1115,  1207,  1208,  1209,  1285,  1113,  1114,
    1203,  1282,  1283,  1284,  1364,  1201,  1202,  1278,  1361,  1362,
    1363,  1453,  1276,  1277,  1357,  1450,  1451,  1452,  1511,  1355,
    1356,  1446,  1508,  1509,  1510,  1548,  1444,  1445,  1504,  1545,
    1546,  1547,  1570,   946,   994,   995,  1048,  1049,  1106,  1102,
    1103,  1104,  1192,  1193,  1194,  1195,  1270,  1338,  1339,  1340,
    1341,  1439,  1196,  1197,  1198,  1272,  1273,  1349,  1346,  1347,
    1348,  1441,   831,   832,   856,   884,   885,   886,   909,   910,
     911,   944,   990,   991,   992,  1044,  1045,  1046,  1047,  1099,
    1185,  1186,   941,   942,   984,   985,   986,  1038,  1039,  1040,
    1094,  1181,  1182,  1183,  1265,  1092,  1093,  1177,  1262,  1263,
    1264,  1332,  1175,  1176,  1258,  1329,  1330,  1331,  1432,  1256,
    1257,  1325,  1429,  1430,  1431,  1499,  1323,  1324,  1425,  1496,
    1497,  1498,  1540,  1423,  1424,  1492,  1537,  1538,  1539,  1567,
    1490,  1491,  1533,  1564,  1565,  1566,  1578,   981,  1035,  1036,
    1088,  1089,  1168,  1165,  1166,  1167,  1248,  1249,  1250,  1251,
    1318,  1407,  1408,  1409,  1410,  1485,  1252,  1253,  1254,  1320,
    1321,  1418,  1415,  1416,  1417,  1487,   853,   854,   879,   904,
     905,   906,   934,   935,   936,   937,   979,   980,  1029,  1026,
    1027,  1028,  1082,  1083,  1084,  1085,  1086,  1087,  1160,   623,
     624,   673,   713,   714,   715,   748,   749,   750,   751,   774,
     775,   799,   795,   796,   797,   823,   824,   825,   826,   827,
     828,   848,   730,   731,   732,   733,   134,   135,   136,   137,
    1076,   603,   604,   605,   606,   138,   139,   140,   141,   360,
     361,   362,   363,   615,   616,   617,   618,   945,   429,  1056,
    1110,   803,   919,   430,   857,   835,   180,   880,   809,   431,
     674,   142,   462,   899,   432,  1213,  1214,  1292,  1293,  1373,
    1374,  1463,  1460,  1215,  1289,  1370,  1371,  1372,  1464,  1465,
     489,  1440,   237,   238,   387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1303
static const yytype_int16 yypact[] =
{
     158, -1303, -1303,    64,    15,    70, -1303, -1303,   100,    58,
     233, -1303,   260, -1303, -1303, -1303,    60,   331,   180, -1303,
   -1303, -1303, -1303,    15, -1303, -1303, -1303, -1303, -1303,    67,
     357,    -2, -1303, -1303, -1303, -1303,   133, -1303, -1303,    84,
     204, -1303, -1303, -1303,   100, -1303,    83,   395,   -13, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,    97,   165, -1303, -1303,   424, -1303,   429,
   -1303,   443, -1303,   452, -1303,   464, -1303,   491, -1303,   493,
   -1303,   495, -1303,   124,    85, -1303,   156, -1303, -1303,   267,
   -1303, -1303, -1303, -1303, -1303,    96,   506,   105, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   119,
     -10, -1303, -1303,   508, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,   132, -1303,   124, -1303, -1303, -1303,   213, -1303,   224,
   -1303,   510,   424, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,    36, -1303, -1303, -1303, -1303,    29, -1303,
   -1303, -1303, -1303,    30, -1303, -1303, -1303, -1303,    38, -1303,
   -1303, -1303, -1303,    43, -1303, -1303, -1303, -1303,    21, -1303,
   -1303, -1303, -1303,    11, -1303, -1303, -1303, -1303, -1303,   512,
   -1303, -1303,   151,   252, -1303, -1303,   344, -1303, -1303, -1303,
   -1303, -1303, -1303,   174, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   195,   109, -1303, -1303,   514,
   -1303,   516, -1303,   518, -1303,   520, -1303,   522, -1303,   124,
   -1303, -1303,    18, -1303, -1303, -1303, -1303,   275,   225,   287,
     225,   289,   225,   291, -1303,   525, -1303,   297,    -1, -1303,
   -1303,   -65, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   167,
   -1303, -1303,   141, -1303, -1303,   155, -1303, -1303,   197, -1303,
   -1303,   208, -1303, -1303,   181, -1303, -1303,   172,   353,   -69,
   -1303, -1303, -1303, -1303, -1303,   294,   368, -1303, -1303,   356,
   -1303, -1303, -1303,   527,   355, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   321,   223, -1303,
   -1303,   529, -1303,   538, -1303,   540, -1303,   542, -1303,   544,
   -1303,   358, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   132,
   -1303,   124, -1303, -1303,    42, -1303, -1303, -1303, -1303,    46,
   -1303, -1303, -1303, -1303,     3, -1303, -1303, -1303, -1303,    19,
   -1303, -1303, -1303, -1303,    20, -1303, -1303, -1303, -1303,   547,
   -1303, -1303, -1303,   207,   553, -1303,   382, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   553, -1303, -1303, -1303, -1303,   553,
   -1303, -1303, -1303, -1303,   401, -1303,    -6, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303,   276,   230, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303,   269,   270, -1303, -1303,
   -1303,   360,   436, -1303, -1303, -1303, -1303, -1303, -1303,   -15,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,    16, -1303, -1303, -1303, -1303,
      13, -1303, -1303, -1303, -1303,    27, -1303, -1303, -1303, -1303,
      52, -1303, -1303, -1303, -1303,    40, -1303, -1303, -1303, -1303,
   -1303,   551, -1303,   447,   225,   449,   225,   454,   225,   456,
   -1303,   554, -1303, -1303, -1303,   345, -1303, -1303,   363, -1303,
   -1303,   298, -1303, -1303,   286, -1303, -1303, -1303,   320, -1303,
      57, -1303, -1303, -1303, -1303, -1303,   403, -1303, -1303,   399,
   -1303,   440, -1303, -1303,   444, -1303, -1303,   405,   411, -1303,
   -1303, -1303, -1303, -1303,   558,   376, -1303, -1303, -1303,   560,
     190, -1303,   483, -1303, -1303,   511,   -41, -1303, -1303,   648,
     689,   690,   691, -1303, -1303,   418, -1303, -1303,   494, -1303,
   -1303,   470, -1303, -1303,   591, -1303, -1303,   566,   693,   -73,
   -1303, -1303, -1303, -1303,   553, -1303, -1303, -1303, -1303,   553,
   -1303, -1303, -1303, -1303,   553, -1303, -1303, -1303, -1303,   695,
   -1303,   134, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   545,   549, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   565,   190,   521, -1303, -1303,   699,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   550, -1303, -1303,
     704, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   678,   700,    71, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   517,
     523, -1303, -1303,   509, -1303,   513, -1303,   519, -1303, -1303,
     515, -1303, -1303,   556,   561, -1303, -1303, -1303, -1303,   567,
     190,   562, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   571, -1303,   541, -1303, -1303,   721,   722,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,   350, -1303, -1303, -1303, -1303, -1303, -1303,   575,   190,
     570, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
     724,   -94, -1303, -1303, -1303, -1303, -1303,   583,   424,   725,
   -1303, -1303,    23, -1303,   730, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   578, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   572,   563,
   -1303, -1303, -1303,   526,   577,   579,   424, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   548, -1303, -1303,
   -1303, -1303, -1303, -1303,   582,   469, -1303,   588,   707,    39,
   -1303, -1303, -1303, -1303,   144, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,     5, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   623,   718, -1303,   584, -1303,
   -1303, -1303,   599, -1303, -1303,   564,   568, -1303, -1303,   741,
   -1303, -1303, -1303,   569,   415, -1303, -1303, -1303, -1303,   742,
   -1303,   589,   728, -1303,   586, -1303,   743,   552, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   590,   271, -1303,   684, -1303,
   -1303, -1303, -1303,   585,   729, -1303,   592, -1303,   751,   555,
   -1303, -1303, -1303, -1303, -1303, -1303,   546,   557,   727,   574,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   594,
   -1303,   757,   641, -1303, -1303, -1303, -1303, -1303, -1303,   619,
     654,   748, -1303, -1303, -1303,   658,   727, -1303,   596, -1303,
   -1303,   766,   184, -1303, -1303, -1303, -1303, -1303, -1303,   656,
     661,   759, -1303, -1303, -1303, -1303,   598, -1303,   600, -1303,
   -1303, -1303,   602,   604, -1303,   771,   123, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   616,   621, -1303, -1303, -1303, -1303,
   -1303, -1303,   606, -1303,   608, -1303,   626,   673, -1303, -1303,
   -1303, -1303,   773,   -90, -1303, -1303, -1303, -1303,   631,   674,
   -1303, -1303, -1303, -1303,   409, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303,   573,   576, -1303, -1303, -1303, -1303, -1303,   613,
     469,   635,   676, -1303, -1303, -1303, -1303,   782,     2, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   680,   696,   774,
   -1303, -1303, -1303,   587,   652, -1303, -1303, -1303, -1303, -1303,
   -1303,   682,   698,   774, -1303, -1303,   593,   595, -1303, -1303,
   -1303, -1303, -1303,    90,    -4, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   686,   701,
     774, -1303, -1303, -1303,   675,   685, -1303, -1303,   615,   392,
   -1303, -1303,   705,   774, -1303,   617, -1303, -1303, -1303, -1303,
     241,   620,   437, -1303, -1303,   708,   774,   622, -1303, -1303,
   -1303,    88,   553, -1303, -1303, -1303, -1303, -1303,   801, -1303,
   -1303, -1303,   650,   426, -1303, -1303, -1303, -1303,   624,   319,
   -1303, -1303,   710,   774,   628, -1303, -1303, -1303, -1303,   280,
     -51, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   716,   774,   630, -1303,   806,   706, -1303,
   -1303, -1303, -1303,   553, -1303, -1303, -1303, -1303,   -74, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
     719,   774,   632, -1303,   706, -1303, -1303, -1303, -1303,     9,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   603,   807, -1303,
     746, -1303, -1303,   -42, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   723,   774,   634, -1303,   706,
   -1303, -1303, -1303, -1303,   553, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303,   663,   688, -1303, -1303,   692, -1303, -1303,   814,
   -1303,   687,   774,   636, -1303,   706, -1303, -1303, -1303, -1303,
   -1303,   783,   712, -1303,   702, -1303,   694, -1303, -1303, -1303,
     669,   614, -1303, -1303,   697, -1303, -1303, -1303,   703,   774,
     638, -1303,   706, -1303, -1303, -1303, -1303,   720, -1303, -1303,
   -1303,   625, -1303, -1303, -1303, -1303, -1303, -1303,   709,   713,
   -1303, -1303,   711, -1303, -1303, -1303,   714,   774,   640, -1303,
     706, -1303, -1303, -1303, -1303,   726, -1303,   715, -1303, -1303,
     143, -1303,   642,   365, -1303, -1303,   646,   774,   647, -1303,
     706, -1303, -1303, -1303, -1303,   738, -1303, -1303, -1303,   649,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   227, -1303,   651,
     365, -1303,   660,   774,   653, -1303,   706, -1303, -1303, -1303,
   -1303,   739, -1303, -1303, -1303, -1303, -1303, -1303,   284, -1303,
     655,   365, -1303,   662,   774,   657, -1303,   706, -1303, -1303,
   -1303, -1303,   745, -1303, -1303, -1303,    31, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   706, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   665,   774,   659, -1303,   706,
   -1303, -1303, -1303, -1303,   749, -1303, -1303,   835,    41, -1303,
   -1303, -1303, -1303,   836,   633,     4, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   706, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   667,   774,   664, -1303,   706, -1303, -1303,
   -1303, -1303,   750, -1303, -1303,    44, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   706, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   671,   774,   668, -1303,   706, -1303, -1303,
   -1303, -1303,   752, -1303, -1303, -1303, -1303, -1303, -1303,   731,
   -1303,   732, -1303, -1303, -1303,   774,   670, -1303,   706, -1303,
   -1303, -1303, -1303,   755, -1303, -1303, -1303,   744, -1303,   842,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   639, -1303,   737,
   -1303, -1303, -1303,   774,   672, -1303,   706, -1303, -1303, -1303,
   -1303,   760, -1303, -1303, -1303,   740, -1303,   747, -1303, -1303,
   -1303,   774,   677, -1303,   706, -1303, -1303, -1303, -1303,   761,
   -1303, -1303, -1303, -1303,   679, -1303,   706, -1303, -1303, -1303,
   -1303,   717, -1303, -1303, -1303, -1303,   753,   854,   862, -1303,
   -1303,   681, -1303,   706, -1303, -1303, -1303, -1303,   733, -1303,
   -1303, -1303, -1303,   683, -1303,   706, -1303, -1303, -1303, -1303,
     736, -1303, -1303,   706, -1303, -1303, -1303, -1303,   734, -1303,
   -1303, -1303, -1303, -1303,   706, -1303, -1303, -1303, -1303,   735,
   -1303, -1303,   706, -1303, -1303, -1303, -1303,   754, -1303, -1303,
     756, -1303, -1303, -1303, -1303,   758, -1303, -1303,   762, -1303,
   -1303, -1303, -1303, -1303
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   825,   848,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   808, -1303, -1303, -1303, -1303,   764, -1303,
   -1303, -1303, -1303, -1303,   480, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
     467, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   770, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   374, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   763, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303,   299, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   601,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   244, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,   231, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   361, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
     130, -1303, -1303, -1303, -1303, -1303,    72, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   -84, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303,  -127, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
    -330, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,  -332,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,  -110, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,  -300, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,  -299, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,  -147, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,  -349, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,  -351, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,   -33, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303,  -180, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,   157, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,    80, -1303, -1303,
   -1303, -1303,  -772, -1303, -1303, -1303,  -119, -1303, -1303, -1303,
   -1039,  -515, -1303, -1303, -1303,  -652, -1303, -1303, -1303,  -214,
   -1303, -1303, -1303,  -589, -1303, -1303, -1303,  -184, -1303, -1012,
    -983,   -72,  -142, -1303, -1303, -1303,  -111, -1303, -1303, -1303,
   -1303,  -655, -1303,  -860, -1303, -1120, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
    -350, -1302,  -178, -1303, -1303
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     268,  1068,   234,   800,   497,   614,   667,   382,  1435,   479,
    1436,  1437,   236,  1239,   500,   265,   368,   536,   373,   502,
     533,  1126,   351,   482,  1238,   262,   485,   486,  1095,   764,
     765,   539,  1155,   250,   253,  1435,   924,  1436,  1437,   735,
     247,  1116,   256,   810,   545,  1457,   473,   259,  1435,   102,
    1436,  1437,   476,   523,  1143,  1217,   542,  1001,    53,  1266,
    1187,   388,   389,   760,     6,  1078,   759,  1079,  1080,   390,
     746,   706,     7,  1468,   819,  1245,   820,   821,  1189,  1137,
     666,  1178,  1218,   747,    11,  1286,   404,  1246,   103,   405,
     104,   103,   105,   104,   106,   105,  1190,   106,  1149,  1150,
    1072,   760,  1204,  1486,   759,  1191,  1173,   677,   350,   359,
     743,   367,  1312,   372,  1247,    13,   637,    15,   391,  1042,
    1002,    28,   621,   638,   678,  1073,   679,  1073,  1043,  1231,
      45,    54,   524,   599,   600,   599,   600,    55,    84,  1219,
    1333,    56,    85,    57,   107,   705,   543,   107,    94,   505,
     178,  1458,   506,  1336,  1337,    58,  1081,   124,   524,   181,
    1365,   182,  1484,   190,  1259,    59,   474,    60,   477,   198,
       1,     2,   546,    61,   108,   127,   128,   108,   257,  1438,
    1073,   220,   248,   822,   742,   811,  1403,   260,   599,   600,
    1279,    62,   487,   540,   874,   537,   534,   263,   254,   251,
     470,   480,  1138,   511,   644,   266,   352,  1433,  1030,   646,
     472,   483,   581,   766,   648,   582,   239,  1305,  1466,   383,
     384,   385,   386,  1240,  1442,   516,   199,   240,   200,   274,
     199,  1342,   200,   127,   128,   599,   600,  1375,  1376,  1454,
     285,   610,   611,    18,    19,  1326,   529,   530,   531,   532,
     558,  1123,   563,    36,   568,    37,    38,   275,  1381,   322,
     802,  1352,   201,  1470,  1073,  1358,   201,   286,   127,   128,
      23,    24,   599,   600,   356,   357,   202,  1482,  1073,  1411,
     202,    86,   548,    87,    88,   354,   599,   600,  1391,   651,
    1184,  1396,   652,  1488,  1405,  1406,   203,   364,    54,   369,
     203,   374,   204,   381,    55,   287,   204,  1500,    56,  1421,
      57,   397,  1426,   396,   127,   128,   286,  1073,   129,   130,
     588,  1073,    58,   398,   813,   599,   600,   814,  1512,   599,
     600,   288,    59,   970,    60,   943,   971,   399,  1105,   289,
      61,    31,    32,   932,  1447,   557,   933,   562,   183,   567,
     184,   185,   400,   290,   287,   291,  1529,   401,    62,   403,
     722,   723,   127,   128,   599,   600,   402,    48,    49,   292,
     610,   611,   424,   411,  1541,   293,   410,   294,   425,   295,
     288,   296,  1475,  1054,   426,   498,  1549,   433,   289,   427,
     460,   724,   725,   127,   128,   495,   602,   129,   130,   356,
     357,   613,   290,  1560,   291,    97,    98,   503,   127,   128,
     512,  1105,  1493,   391,   917,  1568,   610,   611,   292,   127,
     128,   599,   600,  1571,   293,   404,   294,   517,   295,   276,
     296,   277,   278,  1505,  1576,   127,   128,   599,   600,   143,
     144,   522,  1579,   610,   611,   412,   521,   413,   414,   684,
     685,   686,   687,   148,   149,   126,  1105,   554,   688,   559,
    1109,  1522,   153,   154,   564,  1032,   569,   127,   128,   576,
     897,   129,   130,  1136,   158,   159,   665,   736,   579,  1534,
     127,   128,   599,   600,   819,   577,   820,   821,   610,   611,
     798,   708,   580,   709,   710,  1078,   578,  1079,  1080,   719,
    1171,   163,   164,   168,   169,   173,   174,   589,  1077,   587,
     724,   725,   127,   128,   599,   600,   193,   194,   222,   223,
     241,   242,   269,   270,   324,   325,   329,   330,   334,   335,
     339,   340,   344,   345,  1108,   376,   377,   419,   420,   435,
     436,   704,   762,   763,   590,  1127,   591,  1135,   440,   441,
     445,   446,   450,   451,   455,   456,  1156,   490,   491,   485,
     486,   549,   550,   592,   571,   572,   505,   771,   596,   597,
     607,   608,   734,   619,  1170,   661,   662,   700,   701,   620,
     741,   711,   712,   790,  1188,   737,   738,   779,   780,   784,
     785,   792,   793,   794,   837,   838,   859,   860,   631,   758,
     869,   870,   882,   883,   902,   903,   926,   927,   947,   948,
     953,   954,   959,   960,   964,   965,   982,   983,   988,   989,
     829,  1014,  1015,  1024,  1025,  1100,  1101,  1118,  1119,   836,
    1128,  1129,  1144,  1145,  1163,  1164,   633,   758,  1179,  1180,
    1205,  1206,  1232,  1233,  1260,  1261,  1280,  1281,  1306,  1307,
    1327,  1328,  1344,  1345,   627,   858,   801,  1359,  1360,  1368,
    1369,  1383,  1384,  1397,  1398,  1413,  1414,  1427,  1428,  1448,
    1449,  1461,  1462,   876,  1476,  1477,   632,   881,  1494,  1495,
    1506,  1507,  1523,  1524,  1351,   634,   892,  1535,  1536,  1543,
    1544,  1554,  1555,  1562,  1563,   628,   629,   630,   635,   636,
     901,   649,   669,   657,   581,   668,   670,   671,   672,   912,
     675,  1390,   637,   689,   696,   692,   651,   695,   707,   925,
     716,   693,  1157,   694,   720,   721,   744,   873,   752,   938,
     745,   761,  1420,   769,   770,   807,   772,   804,   791,   952,
     747,   776,   830,   833,   843,   842,   847,   849,   851,   864,
     852,   814,   855,   976,   875,  1343,   878,   887,   900,   877,
     897,   865,   893,   907,   888,   987,   908,   914,   894,   913,
     917,   920,   931,  1216,   940,   943,   939,   969,   977,  1000,
     932,   993,  1382,  1021,   996,  1010,  1007,  1037,  1041,   971,
    1034,  1020,  1054,  1051,  1050,  1064,  1063,  1058,  1091,  1001,
    1090,  1097,  1042,  1412,  1112,  1069,  1159,  1139,  1015,  1174,
    1161,  1200,  1210,  1243,  1227,  1211,  1244,  1242,  1255,  1268,
    1274,  1189,  1057,  1288,  1290,  1295,  1217,  1219,  1275,  1291,
    1245,  1354,  1313,  1335,  1267,  1190,  1366,  1404,  1334,  1314,
    1246,  1456,  1294,  1434,  1301,  1392,  1459,  1422,  1516,  1455,
    1483,  1513,  1501,  1519,  1515,  1322,  1530,  1542,  1531,  1550,
    1552,  1031,  1503,  1096,  1443,  1316,  1471,  1520,  1553,    93,
    1489,    44,   125,   513,   518,  1561,  1117,  1532,  1569,  1502,
     221,  1551,   593,   658,   690,   697,   789,   622,   844,  1022,
    1070,  1296,  1298,  1269,  1059,  1158,   246,  1271,  1098,   434,
    1317,  1319,   978,  1162,   850,  1172,   773,  1111,  1033,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1572,  1577,     0,     0,     0,     0,     0,  1199,     0,     0,
    1107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1580,     0,     0,  1134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1581,     0,  1582,     0,
       0,     0,  1583,     0,     0,     0,     0,     0,     0,   323,
    1169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1350,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1514,     0,
       0,     0,     0,  1517,  1518,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1573,  1574
};

static const yytype_int16 yycheck[] =
{
     178,  1013,   121,   775,   354,   520,   595,     8,     4,     6,
       6,     7,   123,     4,   364,     4,   230,     4,   232,   369,
       4,  1060,     4,     4,  1144,     4,     6,     7,  1040,     6,
       7,     4,  1071,     4,     4,     4,   896,     6,     7,   691,
       4,  1053,     4,     4,     4,     4,     4,     4,     4,    62,
       6,     7,     6,    68,  1066,   129,     4,   147,    60,  1179,
    1099,   239,   240,   718,     0,    69,   718,    71,    72,   134,
     164,   660,    57,  1375,    69,   117,    71,    72,   129,  1062,
     595,  1093,   156,   177,    14,  1205,   155,   129,   101,   158,
     103,   101,   105,   103,   107,   105,   147,   107,    10,    11,
      10,   756,  1114,  1405,   756,   156,  1089,    36,   219,   228,
     699,   230,  1232,   232,   156,    15,   189,    59,   183,   117,
     210,    61,   163,   196,    53,    37,    55,    37,   126,  1141,
      63,   133,   173,    45,    46,    45,    46,   139,     5,   213,
    1260,   143,    58,   145,   157,   660,    94,   157,    65,   155,
      26,   110,   158,    10,    11,   157,   160,    60,   173,    74,
    1280,     5,   118,    67,  1176,   167,   124,   169,   122,    64,
      12,    13,   132,   175,   187,    43,    44,   187,   140,   148,
      37,    62,   146,   178,   699,   146,  1306,   144,    45,    46,
    1202,   193,   172,   166,   846,   182,   180,   176,   168,   170,
     319,   198,  1062,   381,   554,   194,   188,  1327,   980,   559,
     321,   192,   155,   190,   564,   158,     3,  1229,   214,   220,
     221,   222,   223,   214,  1344,   403,   121,     3,   123,    78,
     121,  1270,   123,    43,    44,    45,    46,    10,    11,  1359,
      66,    51,    52,    10,    11,  1257,   424,   425,   426,   427,
     464,    10,   466,    73,   468,    75,    76,     5,  1297,    64,
     775,  1273,   157,  1383,    37,  1277,   157,    93,    43,    44,
      10,    11,    45,    46,    49,    50,   171,  1397,    37,  1318,
     171,    77,   460,    79,    80,    10,    45,    46,  1300,   155,
      10,  1303,   158,  1413,    10,    11,   191,    10,   133,    10,
     191,    10,   197,     6,   139,   131,   197,  1427,   143,  1321,
     145,   170,  1324,   146,    43,    44,    93,    37,    47,    48,
     498,    37,   157,   168,   180,    45,    46,   183,  1448,    45,
      46,   157,   167,   210,   169,    16,   213,   140,    19,   165,
     175,    10,    11,   159,  1356,   464,   162,   466,    81,   468,
      83,    84,   144,   179,   131,   181,  1476,   176,   193,     6,
      10,    11,    43,    44,    45,    46,   194,    10,    11,   195,
      51,    52,    17,     5,  1494,   201,    82,   203,    23,   205,
     157,   207,  1394,    18,    29,     3,  1506,    66,   165,    34,
      32,    41,    42,    43,    44,   188,   515,    47,    48,    49,
      50,   520,   179,  1523,   181,    10,    11,     6,    43,    44,
     134,    19,  1424,   183,    22,  1535,    51,    52,   195,    43,
      44,    45,    46,  1543,   201,   155,   203,   158,   205,    85,
     207,    87,    88,  1445,  1554,    43,    44,    45,    46,    10,
      11,     5,  1562,    51,    52,    89,    86,    91,    92,   627,
     628,   629,   630,    10,    11,    31,    19,    10,   636,    10,
    1049,  1473,    10,    11,    10,   980,    10,    43,    44,   124,
      33,    47,    48,  1062,    10,    11,   595,   691,   192,  1491,
      43,    44,    45,    46,    69,   122,    71,    72,    51,    52,
      21,   669,   172,   671,   672,    69,   198,    71,    72,   677,
    1089,    10,    11,    10,    11,    10,    11,   108,  1023,   106,
      41,    42,    43,    44,    45,    46,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1049,    10,    11,    10,    11,    10,
      11,   660,   720,   721,   104,  1060,   102,  1062,    10,    11,
      10,    11,    10,    11,    10,    11,  1071,    10,    11,     6,
       7,    10,    11,   158,    10,    11,   155,   745,    10,    11,
      10,    11,   691,    90,  1089,    10,    11,    10,    11,    68,
     699,    10,    11,   761,  1099,    10,    11,    10,    11,    10,
      11,   769,    10,    11,    10,    11,    10,    11,   180,   718,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     798,   212,   213,    10,    11,    10,    11,    10,    11,   807,
      10,    11,    10,    11,    10,    11,   166,   756,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     6,   833,   775,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    38,    39,   851,    10,    11,   182,   855,    10,    11,
      10,    11,    10,    11,  1273,    94,   864,    10,    11,    10,
      11,    10,    11,    10,    11,     6,     6,     6,   132,     6,
     878,     6,     3,   158,   155,   184,   156,     3,    30,   887,
      10,  1300,   189,   196,   158,   206,   155,   202,   156,   897,
     179,   208,  1072,   204,     3,     3,   156,   846,   145,   907,
       6,     6,  1321,     3,   156,    28,   164,   149,   190,   917,
     177,   215,   119,    25,   180,   146,     5,   178,     6,     6,
     161,   183,    24,   931,    70,  1270,    27,     6,   184,   174,
      33,   209,   216,     6,   209,   943,   125,   113,   211,   150,
      22,   113,     6,  1123,   113,    16,   120,     6,   162,     6,
     159,   155,  1297,   210,   111,   111,   155,   111,     6,   213,
     155,   969,    18,    97,   114,    97,   114,   210,    97,   147,
     114,   126,   117,  1318,    99,   212,     5,    99,   213,    99,
     160,    95,     6,     6,    95,   109,    70,   214,    95,   156,
       6,   129,  1000,    40,   112,   156,   129,   213,   141,   127,
     117,   185,   112,   118,  1184,   147,    98,    98,   112,   214,
     129,     6,   148,    98,   141,   185,    10,   185,     6,   100,
     100,    96,   100,   214,   110,   141,    96,    96,   118,   142,
       6,   980,   130,  1041,   199,   156,   199,   130,     6,    44,
     199,    23,    64,   393,   407,   142,  1054,   130,   142,   148,
     110,   128,   508,   584,   640,   654,   756,   526,   816,   973,
    1017,  1221,  1224,  1193,  1004,  1073,   132,  1196,  1045,   298,
    1249,  1252,   935,  1083,   824,  1089,   749,  1049,   980,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   186,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,
    1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   200,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,   206,
    1089,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1456,    -1,
      -1,    -1,    -1,  1461,  1462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1552,  1553
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   225,   226,   227,     0,    57,   233,   234,
     235,    14,   228,    15,   232,    59,   260,   261,    10,    11,
     236,   237,   238,    10,    11,   229,   230,   231,    61,   340,
     341,    10,    11,   262,   263,   264,    73,    75,    76,   239,
     240,   241,   242,   243,   233,    63,   394,   395,    10,    11,
     342,   343,   344,    60,   133,   139,   143,   145,   157,   167,
     169,   175,   193,   265,   266,   267,   268,   269,   284,   285,
     290,   291,   296,   297,   302,   303,   308,   309,   314,   315,
     320,   321,   326,   327,     5,    58,    77,    79,    80,   244,
     245,   246,   247,   232,    65,   446,   447,    10,    11,   396,
     397,   398,    62,   101,   103,   105,   107,   157,   187,   345,
     346,   347,   348,   349,   354,   355,   361,   362,   368,   369,
     375,   376,   380,   381,    60,   267,    31,    43,    44,    47,
      48,   270,   271,   272,   960,   961,   962,   963,   969,   970,
     971,   972,   995,    10,    11,   286,   287,   288,    10,    11,
     292,   293,   294,    10,    11,   298,   299,   300,    10,    11,
     304,   305,   306,    10,    11,   310,   311,   312,    10,    11,
     316,   317,   318,    10,    11,   322,   323,   324,    26,   328,
     990,    74,     5,    81,    83,    84,   248,   249,   250,   251,
      67,   541,   542,    10,    11,   448,   449,   450,    64,   121,
     123,   157,   171,   191,   197,   399,   400,   401,   402,   403,
     408,   409,   414,   415,   420,   421,   426,   427,   432,   433,
      62,   347,    10,    11,   350,   351,   352,   356,   357,   363,
     364,   370,   371,   377,   960,   382,   990,  1016,  1017,     3,
       3,    10,    11,   273,   274,   275,   272,     4,   146,   289,
       4,   170,   295,     4,   168,   301,     4,   140,   307,     4,
     144,   313,     4,   176,   319,     4,   194,   325,  1016,    10,
      11,   329,   330,   331,    78,     5,    85,    87,    88,   252,
     253,   254,   255,   543,   544,    66,    93,   131,   157,   165,
     179,   181,   195,   201,   203,   205,   207,   451,   452,   453,
     454,   455,   460,   461,   466,   467,   472,   473,   478,   479,
     484,   485,   501,   502,   508,   509,   515,   516,   522,   523,
     527,   528,    64,   401,    10,    11,   404,   405,   406,    10,
      11,   410,   411,   412,    10,    11,   416,   417,   418,    10,
      11,   422,   423,   424,    10,    11,   428,   429,   430,   434,
     990,     4,   188,   353,    10,   359,    49,    50,   358,   960,
     973,   974,   975,   976,    10,   366,   365,   960,   973,    10,
     373,   372,   960,   973,    10,   378,    10,    11,   383,   384,
     385,     6,     8,   220,   221,   222,   223,  1018,  1016,  1016,
     134,   183,   276,   277,   278,   279,   146,   170,   168,   140,
     144,   176,   194,     6,   155,   158,   332,   333,   334,   335,
      82,     5,    89,    91,    92,   256,   257,   258,   259,    10,
      11,   546,   547,   548,    17,    23,    29,    34,   545,   982,
     987,   993,   998,    66,   453,    10,    11,   456,   457,   458,
      10,    11,   462,   463,   464,    10,    11,   468,   469,   470,
      10,    11,   474,   475,   476,    10,    11,   480,   481,   482,
      32,   486,   996,   503,   504,   510,   511,   517,   518,   524,
     960,   529,   990,     4,   124,   407,     6,   122,   413,     6,
     198,   419,     4,   192,   425,     6,     7,   172,   431,  1014,
      10,    11,   435,   436,   437,   188,   360,  1014,     3,   367,
    1014,   374,  1014,     6,   379,   155,   158,   386,   387,   388,
     389,  1016,   134,   278,   280,   281,  1016,   158,   334,   336,
     337,    86,     5,    68,   173,   549,   550,   551,   552,  1016,
    1016,  1016,  1016,     4,   180,   459,     4,   182,   465,     4,
     166,   471,     4,    94,   477,     4,   132,   483,  1016,    10,
      11,   487,   488,   489,    10,   506,   505,   960,   973,    10,
     513,   512,   960,   973,    10,   520,   519,   960,   973,    10,
     525,    10,    11,   530,   531,   532,   124,   122,   198,   192,
     172,   155,   158,   438,   439,   440,   441,   106,  1016,   108,
     104,   102,   158,   388,   390,   391,    10,    11,   283,    45,
      46,   282,   960,   965,   966,   967,   968,    10,    11,   339,
      51,    52,   338,   960,   965,   977,   978,   979,   980,    90,
      68,   163,   551,   933,   934,   553,   554,     6,     6,     6,
       6,   180,   182,   166,    94,   132,     6,   189,   196,   490,
     491,   492,   493,   507,  1014,   514,  1014,   521,  1014,     6,
     526,   155,   158,   533,   534,   535,   536,   158,   440,   442,
     443,    10,    11,   393,   392,   960,   965,   977,   184,     3,
     156,     3,    30,   935,   994,    10,   559,    36,    53,    55,
     555,   556,   557,   558,  1016,  1016,  1016,  1016,  1016,   196,
     492,   494,   206,   208,   204,   202,   158,   535,   537,   538,
      10,    11,   445,   444,   960,   965,   977,   156,  1016,  1016,
    1016,    10,    11,   936,   937,   938,   179,   560,   561,  1016,
       3,     3,    10,    11,    41,    42,   495,   496,   497,   498,
     956,   957,   958,   959,   960,   969,   973,    10,    11,   540,
     539,   960,   965,   977,   156,     6,   164,   177,   939,   940,
     941,   942,   145,   576,   577,   562,   563,   564,   960,   969,
     995,     6,  1016,  1016,     6,     7,   190,   499,   500,     3,
     156,  1016,   164,   941,   943,   944,   215,   582,   583,    10,
      11,   578,   579,   580,    10,    11,   565,   566,   567,   564,
    1016,   190,  1016,    10,    11,   946,   947,   948,    21,   945,
     956,   960,   965,   985,   149,   702,   703,    28,   584,   992,
       4,   146,   581,   180,   183,   568,   569,   570,   571,    69,
      71,    72,   178,   949,   950,   951,   952,   953,   954,  1016,
     119,   806,   807,    25,   704,   989,  1016,    10,    11,   585,
     586,   587,   146,   180,   570,   572,   573,     5,   955,   178,
     951,     6,   161,   910,   911,    24,   808,   988,  1016,    10,
      11,   705,   706,   707,     6,   209,   588,   589,   590,    10,
      11,   575,   574,   960,   969,    70,  1016,   174,    27,   912,
     991,  1016,    10,    11,   809,   810,   811,     6,   209,   708,
     709,   710,  1016,   216,   211,   602,   603,    33,   591,   997,
     184,  1016,    10,    11,   913,   914,   915,     6,   125,   812,
     813,   814,  1016,   150,   113,   722,   723,    22,   711,   986,
     113,   618,   619,   604,   997,  1016,    10,    11,   592,   593,
     594,     6,   159,   162,   916,   917,   918,   919,  1016,   120,
     113,   826,   827,    16,   815,   981,   777,    10,    11,   724,
     725,   726,  1016,    10,    11,   712,   713,   714,   673,    10,
      11,   620,   621,   622,    10,    11,   605,   606,   607,     6,
     210,   213,   595,   596,   597,   598,  1016,   162,   918,   920,
     921,   881,    10,    11,   828,   829,   830,  1016,    10,    11,
     816,   817,   818,   155,   778,   779,   111,   727,   728,   729,
       6,   147,   210,   715,   716,   717,   718,   155,   674,   675,
     111,   623,   624,   625,   212,   213,   608,   609,   610,   611,
    1016,   210,   597,   599,    10,    11,   923,   924,   925,   922,
     956,   960,   965,   985,   155,   882,   883,   111,   831,   832,
     833,     6,   117,   126,   819,   820,   821,   822,   780,   781,
     114,    97,   735,   736,    18,   730,   983,  1016,   210,   717,
     719,   676,   677,   114,    97,   631,   632,   626,   983,   212,
     610,   612,    10,    37,   600,   601,   964,   965,    69,    71,
      72,   160,   926,   927,   928,   929,   930,   931,   884,   885,
     114,    97,   839,   840,   834,   983,  1016,   126,   821,   823,
      10,    11,   783,   784,   785,    19,   782,   960,   965,   977,
     984,   986,    99,   742,   743,   737,   983,  1016,    10,    11,
     731,   732,   733,    10,   720,   721,   964,   965,    10,    11,
     679,   680,   681,   678,   960,   965,   977,   984,   997,    99,
     638,   639,   633,   983,    10,    11,   627,   628,   629,    10,
      11,   613,   614,   615,   616,   964,   965,  1014,  1016,     5,
     932,   160,   928,    10,    11,   887,   888,   889,   886,   960,
     965,   977,   981,   984,    99,   846,   847,   841,   983,    10,
      11,   835,   836,   837,    10,   824,   825,   964,   965,   129,
     147,   156,   786,   787,   788,   789,   796,   797,   798,  1016,
      95,   749,   750,   744,   983,    10,    11,   738,   739,   740,
       6,   109,   734,   999,  1000,  1007,  1014,   129,   156,   213,
     682,   683,   684,   685,   692,   693,   694,    95,   645,   646,
     640,   983,    10,    11,   634,   635,   636,   630,   999,     4,
     214,   617,   214,     6,    70,   117,   129,   156,   890,   891,
     892,   893,   900,   901,   902,    95,   853,   854,   848,   983,
      10,    11,   842,   843,   844,   838,   999,  1014,   156,   788,
     790,   797,   799,   800,     6,   141,   756,   757,   751,   983,
      10,    11,   745,   746,   747,   741,   999,  1016,    40,  1008,
     112,   127,  1001,  1002,   148,   156,   684,   686,   693,   695,
     696,   141,   652,   653,   647,   983,    10,    11,   641,   642,
     643,   637,   999,   112,   214,  1016,   156,   892,   894,   901,
     903,   904,   141,   860,   861,   855,   983,    10,    11,   849,
     850,   851,   845,   999,   112,   118,    10,    11,   791,   792,
     793,   794,   964,   965,    10,    11,   802,   803,   804,   801,
     960,   977,   983,  1016,   185,   763,   764,   758,   983,    10,
      11,   752,   753,   754,   748,   999,    98,  1016,    10,    11,
    1009,  1010,  1011,  1003,  1004,    10,    11,   687,   688,   689,
     690,   964,   965,    10,    11,   698,   699,   700,   697,   960,
     977,   983,   185,   659,   660,   654,   983,    10,    11,   648,
     649,   650,   644,   999,    98,    10,    11,   895,   896,   897,
     898,   964,   965,    10,    11,   906,   907,   908,   905,   960,
     977,   983,   185,   867,   868,   862,   983,    10,    11,   856,
     857,   858,   852,   999,    98,     4,     6,     7,   148,   795,
    1015,   805,   999,   199,   770,   771,   765,   983,    10,    11,
     759,   760,   761,   755,   999,   100,     6,     4,   110,    10,
    1006,    38,    39,  1005,  1012,  1013,   214,   691,  1015,   701,
     999,   199,   666,   667,   661,   983,    10,    11,   655,   656,
     657,   651,   999,   100,   118,   899,  1015,   909,   999,   199,
     874,   875,   869,   983,    10,    11,   863,   864,   865,   859,
     999,   100,   148,   130,   772,   983,    10,    11,   766,   767,
     768,   762,   999,    96,  1016,   110,     6,  1016,  1016,   214,
     130,   668,   983,    10,    11,   662,   663,   664,   658,   999,
      96,   118,   130,   876,   983,    10,    11,   870,   871,   872,
     866,   999,    96,    10,    11,   773,   774,   775,   769,   999,
     142,   128,     6,     6,    10,    11,   669,   670,   671,   665,
     999,   142,    10,    11,   877,   878,   879,   873,   999,   142,
     776,   999,   186,  1016,  1016,   672,   999,   186,   880,   999,
     186,   200,   200,   200
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
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
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
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 689:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 690:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 693:

    {	
 		if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->idx) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
	}
    break;

  case 694:

    {	
 		if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
	}
    break;

  case 700:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	}
    break;

  case 703:

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

  case 704:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 705:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 708:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 718:

    {
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 720:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
}
    break;

  case 729:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}
    break;

  case 730:

    {
		if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
    break;

  case 731:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	}
    break;

  case 738:

    {
	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
}
    break;

  case 739:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 747:

    {
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 754:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 756:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 763:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 765:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 772:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 774:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 781:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 783:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 790:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 792:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 799:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 801:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 808:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 810:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 818:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 819:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfObjAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 820:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	}
    break;

  case 823:

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

  case 824:

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

  case 825:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 826:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 827:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 837:

    {  
	parserData->kounter++;
}
    break;

  case 838:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;	
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 841:

    {
		if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
	}
    break;

  case 842:

    {	
 		if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
	}
    break;

  case 848:

    {
		if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	}
    break;

  case 851:

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

  case 852:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 853:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 856:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 866:

    {
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 868:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
}
    break;

  case 876:

    {	parserData->numberAttributePresent = false; }
    break;

  case 877:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
}
    break;

  case 878:

    {
		if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	}
    break;

  case 879:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	}
    break;

  case 886:

    {
	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->nameAttribute,
							   parserData->tempVal                           ) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
}
    break;

  case 887:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 895:

    {
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 902:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 904:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 911:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 913:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 920:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 922:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 929:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 931:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 938:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 940:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 947:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 949:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 956:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 958:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 966:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 967:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfConAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 968:

    {
		if (!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
	}
    break;

  case 971:

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

  case 972:

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

  case 973:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 974:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 975:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 985:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 986:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 989:

    {	
 		if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
	}
    break;

  case 990:

    {	
 		if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
	}
    break;

  case 996:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	}
    break;

  case 999:

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

  case 1000:

    {
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1001:

    {
		if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
	}
    break;

  case 1004:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1014:

    {
	parserData->numberOf = 0; 
}
    break;

  case 1015:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 1016:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	}
    break;

  case 1017:

    {
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	}
    break;

  case 1024:

    {
	parserData->iOther++;
}
    break;

  case 1025:

    {
	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1026:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1029:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	}
    break;

  case 1030:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	}
    break;

  case 1031:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	}
    break;

  case 1032:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1033:

    {
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1034:

    {
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1041:

    {
	parserData->kounter++;
}
    break;

  case 1042:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}
    break;

  case 1047:

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

  case 1050:

    {
	parserData->numberOf = 0; 
}
    break;

  case 1051:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 1052:

    {
		if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	}
    break;

  case 1053:

    {
		if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	}
    break;

  case 1060:

    {
	parserData->iOther++;
}
    break;

  case 1061:

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

  case 1062:

    {
	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1065:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	}
    break;

  case 1066:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	}
    break;

  case 1067:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	}
    break;

  case 1068:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1069:

    {
		if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1070:

    {
		if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1077:

    {
	parserData->kounter++;
}
    break;

  case 1078:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	}
    break;

  case 1083:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1084:

    {
		if (parserData->categoryAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
		parserData->categoryAttributePresent = true;
	}
    break;

  case 1087:

    { 
	parserData->categoryAttribute = ""; 
}
    break;

  case 1088:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1089:

    {
		if (parserData->descriptionAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
		parserData->descriptionAttributePresent = true;
	}
    break;

  case 1092:

    { 
	parserData->descriptionAttribute = ""; 
}
    break;

  case 1093:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1094:

    {	
		if (parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
		parserData->idxAttributePresent = true;
		parserData->idx = (yyvsp[(3) - (4)].ival); 
	}
    break;

  case 1095:

    {
	   if (parserData->nameAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1098:

    { 
	parserData->nameAttribute = ""; 
}
    break;

  case 1099:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1100:

    {
		if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
		parserData->typeAttributePresent = true;
	}
    break;

  case 1103:

    { 
	parserData->typeAttribute = ""; 
}
    break;

  case 1104:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1105:

    {
		if (parserData->unitAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
		parserData->unitAttributePresent = true;
	}
    break;

  case 1108:

    { 
	parserData->unitAttribute = ""; 
}
    break;

  case 1109:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1110:

    {
		if (parserData->valueAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
		parserData->valueAttributePresent = true;
	}
    break;

  case 1113:

    { 
	parserData->valueAttribute = ""; 
}
    break;

  case 1114:

    { 
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1115:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1116:

    {
	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1117:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1118:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1119:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1120:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1121:

    {
	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1122:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1123:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1124:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1125:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1126:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1127:

    {
	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1128:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1130:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1131:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1132:

    {
	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1133:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	}
    break;

  case 1138:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1144:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1146:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1151:

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

  case 1152:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1153:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1154:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1155:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1156:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1157:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1158:

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


