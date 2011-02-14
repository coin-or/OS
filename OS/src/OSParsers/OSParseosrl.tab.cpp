/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse osrlparse
#define yylex   osrllex
#define yyerror osrlerror
#define yylval  osrllval
#define yychar  osrlchar
#define yydebug osrldebug
#define yynerrs osrlnerrs
#define yylloc osrllloc

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
     HEADERSTART = 310,
     HEADEREND = 311,
     GENERALSTART = 312,
     GENERALEND = 313,
     SYSTEMSTART = 314,
     SYSTEMEND = 315,
     SERVICESTART = 316,
     SERVICEEND = 317,
     JOBSTART = 318,
     JOBEND = 319,
     OPTIMIZATIONSTART = 320,
     OPTIMIZATIONEND = 321,
     ITEMSTART = 322,
     ITEMEND = 323,
     ITEMSTARTANDEND = 324,
     ITEMEMPTY = 325,
     FILENAMESTART = 326,
     FILENAMEEND = 327,
     FILENAMEEMPTY = 328,
     FILENAMESTARTANDEND = 329,
     FILESOURCESTART = 330,
     FILESOURCEEND = 331,
     FILESOURCEEMPTY = 332,
     FILESOURCESTARTANDEND = 333,
     FILEDESCRIPTIONSTART = 334,
     FILEDESCRIPTIONEND = 335,
     FILEDESCRIPTIONEMPTY = 336,
     FILEDESCRIPTIONSTARTANDEND = 337,
     FILECREATORSTART = 338,
     FILECREATOREND = 339,
     FILECREATOREMPTY = 340,
     FILECREATORSTARTANDEND = 341,
     FILELICENCESTART = 342,
     FILELICENCEEND = 343,
     FILELICENCEEMPTY = 344,
     FILELICENCESTARTANDEND = 345,
     ACTUALSTARTTIMESTART = 346,
     ACTUALSTARTTIMEEND = 347,
     ATLOWERSTART = 348,
     ATLOWEREND = 349,
     ATUPPERSTART = 350,
     ATUPPEREND = 351,
     AVAILABLECPUNUMBERSTART = 352,
     AVAILABLECPUNUMBEREND = 353,
     AVAILABLECPUSPEEDSTART = 354,
     AVAILABLECPUSPEEDEND = 355,
     AVAILABLEDISKSPACESTART = 356,
     AVAILABLEDISKSPACEEND = 357,
     AVAILABLEMEMORYSTART = 358,
     AVAILABLEMEMORYEND = 359,
     BASE64START = 360,
     BASE64END = 361,
     BASICSTART = 362,
     BASICEND = 363,
     BASISSTATUSSTART = 364,
     BASISSTATUSEND = 365,
     BASSTATUSSTART = 366,
     BASSTATUSEND = 367,
     CONSTART = 368,
     CONEND = 369,
     CONSTRAINTSSTART = 370,
     CONSTRAINTSEND = 371,
     CURRENTJOBCOUNTSTART = 372,
     CURRENTJOBCOUNTEND = 373,
     CURRENTSTATESTART = 374,
     CURRENTSTATEEND = 375,
     DUALVALUESSTART = 376,
     DUALVALUESEND = 377,
     ELSTART = 378,
     ELEND = 379,
     ENUMERATIONSTART = 380,
     ENUMERATIONEND = 381,
     ENDTIMESTART = 382,
     ENDTIMEEND = 383,
     GENERALSTATUSSTART = 384,
     GENERALSTATUSEND = 385,
     GENERALSUBSTATUSSTART = 386,
     GENERALSUBSTATUSEND = 387,
     IDXSTART = 388,
     IDXEND = 389,
     INSTANCENAMESTART = 390,
     INSTANCENAMEEND = 391,
     ISFREESTART = 392,
     ISFREEEND = 393,
     JOBIDSTART = 394,
     JOBIDEND = 395,
     MESSAGESTART = 396,
     MESSAGEEND = 397,
     OBJSTART = 398,
     OBJEND = 399,
     OBJECTIVESSTART = 400,
     OBJECTIVESEND = 401,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 402,
     OPTIMIZATIONSOLUTIONSTATUSEND = 403,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 404,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 405,
     OTHERSTART = 406,
     OTHEREND = 407,
     OTHERRESULTSSTART = 408,
     OTHERRESULTSEND = 409,
     OTHERSOLUTIONRESULTSTART = 410,
     OTHERSOLUTIONRESULTEND = 411,
     OTHERSOLUTIONRESULTSSTART = 412,
     OTHERSOLUTIONRESULTSEND = 413,
     OTHERSOLVEROUTPUTSTART = 414,
     OTHERSOLVEROUTPUTEND = 415,
     SCHEDULEDSTARTTIMESTART = 416,
     SCHEDULEDSTARTTIMEEND = 417,
     SERVICENAMESTART = 418,
     SERVICENAMEEND = 419,
     SERVICEURISTART = 420,
     SERVICEURIEND = 421,
     SERVICEUTILIZATIONSTART = 422,
     SERVICEUTILIZATIONEND = 423,
     SOLUTIONSTART = 424,
     SOLUTIONEND = 425,
     SOLVERINVOKEDSTART = 426,
     SOLVERINVOKEDEND = 427,
     SOLVEROUTPUTSTART = 428,
     SOLVEROUTPUTEND = 429,
     STATUSSTART = 430,
     STATUSEND = 431,
     SUBMITTIMESTART = 432,
     SUBMITTIMEEND = 433,
     SUBSTATUSSTART = 434,
     SUBSTATUSEND = 435,
     SUPERBASICSTART = 436,
     SUPERBASICEND = 437,
     SYSTEMINFORMATIONSTART = 438,
     SYSTEMINFORMATIONEND = 439,
     TIMESTART = 440,
     TIMEEND = 441,
     TIMESERVICESTARTEDSTART = 442,
     TIMESERVICESTARTEDEND = 443,
     TIMESTAMPSTART = 444,
     TIMESTAMPEND = 445,
     TIMINGINFORMATIONSTART = 446,
     TIMINGINFORMATIONEND = 447,
     TOTALJOBSSOFARSTART = 448,
     TOTALJOBSSOFAREND = 449,
     UNKNOWNSTART = 450,
     UNKNOWNEND = 451,
     USEDCPUNUMBERSTART = 452,
     USEDCPUNUMBEREND = 453,
     USEDCPUSPEEDSTART = 454,
     USEDCPUSPEEDEND = 455,
     USEDDISKSPACESTART = 456,
     USEDDISKSPACEEND = 457,
     USEDMEMORYSTART = 458,
     USEDMEMORYEND = 459,
     VALUESSTART = 460,
     VALUESEND = 461,
     VALUESSTRINGSTART = 462,
     VALUESSTRINGEND = 463,
     VARSTART = 464,
     VAREND = 465,
     VARIABLESSTART = 466,
     VARIABLESEND = 467,
     VARIDXSTART = 468,
     VARIDXEND = 469,
     DUMMY = 470
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
#define HEADERSTART 310
#define HEADEREND 311
#define GENERALSTART 312
#define GENERALEND 313
#define SYSTEMSTART 314
#define SYSTEMEND 315
#define SERVICESTART 316
#define SERVICEEND 317
#define JOBSTART 318
#define JOBEND 319
#define OPTIMIZATIONSTART 320
#define OPTIMIZATIONEND 321
#define ITEMSTART 322
#define ITEMEND 323
#define ITEMSTARTANDEND 324
#define ITEMEMPTY 325
#define FILENAMESTART 326
#define FILENAMEEND 327
#define FILENAMEEMPTY 328
#define FILENAMESTARTANDEND 329
#define FILESOURCESTART 330
#define FILESOURCEEND 331
#define FILESOURCEEMPTY 332
#define FILESOURCESTARTANDEND 333
#define FILEDESCRIPTIONSTART 334
#define FILEDESCRIPTIONEND 335
#define FILEDESCRIPTIONEMPTY 336
#define FILEDESCRIPTIONSTARTANDEND 337
#define FILECREATORSTART 338
#define FILECREATOREND 339
#define FILECREATOREMPTY 340
#define FILECREATORSTARTANDEND 341
#define FILELICENCESTART 342
#define FILELICENCEEND 343
#define FILELICENCEEMPTY 344
#define FILELICENCESTARTANDEND 345
#define ACTUALSTARTTIMESTART 346
#define ACTUALSTARTTIMEEND 347
#define ATLOWERSTART 348
#define ATLOWEREND 349
#define ATUPPERSTART 350
#define ATUPPEREND 351
#define AVAILABLECPUNUMBERSTART 352
#define AVAILABLECPUNUMBEREND 353
#define AVAILABLECPUSPEEDSTART 354
#define AVAILABLECPUSPEEDEND 355
#define AVAILABLEDISKSPACESTART 356
#define AVAILABLEDISKSPACEEND 357
#define AVAILABLEMEMORYSTART 358
#define AVAILABLEMEMORYEND 359
#define BASE64START 360
#define BASE64END 361
#define BASICSTART 362
#define BASICEND 363
#define BASISSTATUSSTART 364
#define BASISSTATUSEND 365
#define BASSTATUSSTART 366
#define BASSTATUSEND 367
#define CONSTART 368
#define CONEND 369
#define CONSTRAINTSSTART 370
#define CONSTRAINTSEND 371
#define CURRENTJOBCOUNTSTART 372
#define CURRENTJOBCOUNTEND 373
#define CURRENTSTATESTART 374
#define CURRENTSTATEEND 375
#define DUALVALUESSTART 376
#define DUALVALUESEND 377
#define ELSTART 378
#define ELEND 379
#define ENUMERATIONSTART 380
#define ENUMERATIONEND 381
#define ENDTIMESTART 382
#define ENDTIMEEND 383
#define GENERALSTATUSSTART 384
#define GENERALSTATUSEND 385
#define GENERALSUBSTATUSSTART 386
#define GENERALSUBSTATUSEND 387
#define IDXSTART 388
#define IDXEND 389
#define INSTANCENAMESTART 390
#define INSTANCENAMEEND 391
#define ISFREESTART 392
#define ISFREEEND 393
#define JOBIDSTART 394
#define JOBIDEND 395
#define MESSAGESTART 396
#define MESSAGEEND 397
#define OBJSTART 398
#define OBJEND 399
#define OBJECTIVESSTART 400
#define OBJECTIVESEND 401
#define OPTIMIZATIONSOLUTIONSTATUSSTART 402
#define OPTIMIZATIONSOLUTIONSTATUSEND 403
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 404
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 405
#define OTHERSTART 406
#define OTHEREND 407
#define OTHERRESULTSSTART 408
#define OTHERRESULTSEND 409
#define OTHERSOLUTIONRESULTSTART 410
#define OTHERSOLUTIONRESULTEND 411
#define OTHERSOLUTIONRESULTSSTART 412
#define OTHERSOLUTIONRESULTSEND 413
#define OTHERSOLVEROUTPUTSTART 414
#define OTHERSOLVEROUTPUTEND 415
#define SCHEDULEDSTARTTIMESTART 416
#define SCHEDULEDSTARTTIMEEND 417
#define SERVICENAMESTART 418
#define SERVICENAMEEND 419
#define SERVICEURISTART 420
#define SERVICEURIEND 421
#define SERVICEUTILIZATIONSTART 422
#define SERVICEUTILIZATIONEND 423
#define SOLUTIONSTART 424
#define SOLUTIONEND 425
#define SOLVERINVOKEDSTART 426
#define SOLVERINVOKEDEND 427
#define SOLVEROUTPUTSTART 428
#define SOLVEROUTPUTEND 429
#define STATUSSTART 430
#define STATUSEND 431
#define SUBMITTIMESTART 432
#define SUBMITTIMEEND 433
#define SUBSTATUSSTART 434
#define SUBSTATUSEND 435
#define SUPERBASICSTART 436
#define SUPERBASICEND 437
#define SYSTEMINFORMATIONSTART 438
#define SYSTEMINFORMATIONEND 439
#define TIMESTART 440
#define TIMEEND 441
#define TIMESERVICESTARTEDSTART 442
#define TIMESERVICESTARTEDEND 443
#define TIMESTAMPSTART 444
#define TIMESTAMPEND 445
#define TIMINGINFORMATIONSTART 446
#define TIMINGINFORMATIONEND 447
#define TOTALJOBSSOFARSTART 448
#define TOTALJOBSSOFAREND 449
#define UNKNOWNSTART 450
#define UNKNOWNEND 451
#define USEDCPUNUMBERSTART 452
#define USEDCPUNUMBEREND 453
#define USEDCPUSPEEDSTART 454
#define USEDCPUSPEEDEND 455
#define USEDDISKSPACESTART 456
#define USEDDISKSPACEEND 457
#define USEDMEMORYSTART 458
#define USEDMEMORYEND 459
#define VALUESSTART 460
#define VALUESEND 461
#define VALUESSTRINGSTART 462
#define VALUESSTRINGEND 463
#define VARSTART 464
#define VAREND 465
#define VARIABLESSTART 466
#define VARIABLESEND 467
#define VARIDXSTART 468
#define VARIDXEND 469
#define DUMMY 470




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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


/* Line 216 of yacc.c.  */


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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  766
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1549

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   473

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   220,
     222,     2,     2,   221,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   219,     2,     2,     2,     2,     2,     2,     2,
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
     215,   216,   217,   218
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    35,    36,    39,    41,    43,    45,    47,
      51,    57,    58,    60,    62,    64,    66,    68,    72,    73,
      75,    77,    79,    81,    83,    87,    88,    90,    92,    94,
      96,    98,   102,   103,   105,   107,   109,   111,   113,   117,
     118,   120,   122,   124,   126,   128,   132,   133,   136,   138,
     140,   142,   145,   147,   151,   153,   155,   158,   160,   162,
     164,   166,   168,   170,   172,   174,   176,   180,   182,   184,
     186,   189,   191,   193,   195,   197,   199,   202,   204,   208,
     210,   212,   215,   219,   221,   223,   224,   227,   229,   231,
     234,   236,   239,   241,   243,   245,   248,   250,   254,   256,
     259,   261,   263,   265,   268,   270,   274,   276,   279,   281,
     283,   285,   288,   290,   294,   296,   299,   301,   303,   305,
     308,   310,   314,   316,   319,   321,   323,   325,   328,   330,
     334,   336,   339,   341,   343,   345,   348,   350,   354,   356,
     359,   361,   363,   365,   368,   370,   374,   376,   380,   382,
     384,   386,   388,   391,   393,   397,   399,   401,   404,   408,
     410,   412,   413,   416,   418,   420,   422,   425,   427,   428,
     431,   433,   435,   437,   440,   442,   446,   448,   450,   453,
     455,   457,   459,   461,   463,   465,   468,   470,   472,   474,
     477,   479,   483,   485,   489,   491,   493,   494,   497,   499,
     501,   505,   507,   511,   513,   515,   516,   519,   521,   523,
     527,   529,   533,   535,   537,   538,   541,   543,   545,   549,
     551,   555,   557,   558,   560,   564,   566,   570,   572,   574,
     576,   578,   581,   583,   587,   589,   591,   594,   598,   600,
     602,   603,   606,   608,   610,   612,   615,   617,   618,   621,
     623,   625,   627,   630,   632,   636,   638,   640,   643,   645,
     647,   649,   651,   653,   655,   658,   660,   662,   664,   667,
     669,   673,   675,   678,   680,   682,   684,   687,   689,   693,
     695,   698,   700,   702,   704,   707,   709,   713,   715,   718,
     720,   722,   724,   727,   729,   733,   735,   738,   740,   742,
     744,   747,   749,   753,   755,   759,   761,   763,   765,   767,
     770,   772,   776,   778,   780,   783,   787,   789,   791,   792,
     795,   797,   799,   801,   804,   806,   807,   810,   812,   814,
     816,   819,   821,   825,   827,   829,   832,   834,   836,   838,
     840,   842,   844,   846,   848,   850,   852,   854,   857,   859,
     861,   863,   866,   868,   872,   874,   877,   879,   881,   883,
     886,   888,   892,   894,   897,   899,   901,   903,   906,   908,
     912,   914,   917,   919,   921,   923,   926,   928,   932,   934,
     937,   939,   941,   943,   946,   948,   952,   954,   958,   960,
     962,   964,   966,   969,   971,   975,   977,   979,   982,   986,
     988,   989,   992,   994,   996,   998,  1000,  1002,  1004,  1007,
    1009,  1013,  1015,  1017,  1019,  1023,  1025,  1027,  1028,  1031,
    1033,  1035,  1039,  1041,  1045,  1047,  1049,  1050,  1053,  1055,
    1057,  1061,  1063,  1067,  1069,  1071,  1072,  1075,  1077,  1079,
    1083,  1085,  1089,  1091,  1092,  1094,  1098,  1100,  1104,  1106,
    1108,  1110,  1112,  1115,  1117,  1121,  1123,  1125,  1128,  1132,
    1134,  1136,  1137,  1140,  1142,  1144,  1146,  1149,  1151,  1152,
    1156,  1158,  1160,  1161,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1179,  1181,  1185,  1188,  1190,  1193,  1197,  1199,  1201,
    1202,  1205,  1207,  1209,  1214,  1218,  1227,  1231,  1233,  1235,
    1237,  1240,  1242,  1244,  1246,  1248,  1250,  1253,  1255,  1259,
    1261,  1263,  1266,  1270,  1272,  1274,  1275,  1278,  1280,  1282,
    1285,  1287,  1288,  1291,  1293,  1295,  1297,  1300,  1302,  1306,
    1308,  1309,  1313,  1315,  1316,  1318,  1320,  1322,  1324,  1328,
    1333,  1334,  1338,  1340,  1342,  1344,  1346,  1349,  1351,  1355,
    1357,  1359,  1362,  1366,  1368,  1373,  1374,  1379,  1380,  1384,
    1386,  1388,  1390,  1392,  1395,  1397,  1401,  1403,  1405,  1408,
    1412,  1414,  1419,  1421,  1423,  1426,  1428,  1432,  1434,  1435,
    1438,  1440,  1442,  1444,  1446,  1450,  1457,  1458,  1462,  1464,
    1466,  1468,  1470,  1472,  1476,  1478,  1479,  1483,  1485,  1487,
    1489,  1491,  1493,  1497,  1499,  1500,  1504,  1506,  1508,  1510,
    1512,  1514,  1518,  1520,  1521,  1525,  1527,  1529,  1531,  1533,
    1535,  1539,  1541,  1542,  1546,  1548,  1550,  1552,  1554,  1556,
    1560,  1562,  1563,  1567,  1569,  1571,  1573,  1575,  1577,  1581,
    1583,  1584,  1587,  1591,  1593,  1595,  1596,  1599,  1601,  1603,
    1605,  1607,  1609,  1611,  1613,  1616,  1618,  1622,  1624,  1626,
    1628,  1631,  1635,  1637,  1642,  1644,  1646,  1649,  1651,  1655,
    1657,  1659,  1662,  1666,  1668,  1670,  1671,  1674,  1676,  1678,
    1680,  1682,  1684,  1686,  1690,  1692,  1693,  1697,  1699,  1700,
    1702,  1704,  1706,  1708,  1712,  1716,  1717,  1721,  1723,  1725,
    1727,  1729,  1732,  1734,  1738,  1740,  1742,  1745,  1749,  1751,
    1752,  1757,  1761,  1763,  1765,  1766,  1769,  1771,  1773,  1775,
    1777,  1781,  1788,  1789,  1793,  1795,  1797,  1799,  1801,  1803,
    1807,  1809,  1810,  1814,  1816,  1818,  1820,  1822,  1824,  1828,
    1830,  1831,  1835,  1837,  1839,  1841,  1843,  1845,  1849,  1851,
    1852,  1856,  1858,  1860,  1862,  1864,  1866,  1870,  1872,  1873,
    1877,  1879,  1881,  1883,  1885,  1887,  1891,  1893,  1894,  1898,
    1900,  1902,  1904,  1906,  1908,  1912,  1914,  1915,  1918,  1922,
    1924,  1926,  1927,  1930,  1932,  1934,  1936,  1938,  1940,  1942,
    1944,  1947,  1949,  1953,  1955,  1957,  1959,  1962,  1966,  1968,
    1973,  1975,  1977,  1980,  1982,  1986,  1988,  1990,  1993,  1997,
    1999,  2001,  2002,  2005,  2007,  2009,  2011,  2013,  2015,  2017,
    2021,  2023,  2024,  2028,  2030,  2031,  2033,  2035,  2037,  2039,
    2043,  2047,  2048,  2052,  2054,  2056,  2058,  2060,  2063,  2065,
    2069,  2071,  2073,  2076,  2080,  2082,  2087,  2091,  2092,  2095,
    2097,  2099,  2101,  2103,  2107,  2114,  2115,  2119,  2121,  2123,
    2125,  2127,  2129,  2133,  2135,  2136,  2140,  2142,  2144,  2146,
    2148,  2150,  2154,  2156,  2157,  2161,  2163,  2165,  2167,  2169,
    2171,  2175,  2177,  2178,  2182,  2184,  2186,  2188,  2190,  2192,
    2196,  2198,  2199,  2203,  2205,  2207,  2209,  2211,  2213,  2217,
    2219,  2220,  2224,  2226,  2228,  2230,  2232,  2234,  2238,  2240,
    2241,  2244,  2248,  2250,  2252,  2253,  2256,  2258,  2260,  2262,
    2264,  2266,  2268,  2270,  2273,  2275,  2279,  2281,  2283,  2285,
    2288,  2292,  2294,  2299,  2301,  2303,  2306,  2308,  2312,  2314,
    2316,  2319,  2323,  2325,  2327,  2328,  2331,  2333,  2335,  2337,
    2339,  2341,  2343,  2347,  2349,  2350,  2354,  2356,  2358,  2360,
    2362,  2365,  2367,  2371,  2373,  2375,  2378,  2382,  2384,  2386,
    2387,  2390,  2392,  2394,  2396,  2398,  2400,  2402,  2405,  2407,
    2411,  2413,  2415,  2418,  2420,  2422,  2424,  2426,  2428,  2432,
    2434,  2435,  2439,  2441,  2443,  2445,  2447,  2450,  2452,  2456,
    2458,  2460,  2463,  2467,  2469,  2471,  2472,  2475,  2477,  2479,
    2481,  2483,  2485,  2487,  2490,  2492,  2496,  2498,  2500,  2503,
    2505,  2507,  2509,  2511,  2513,  2517,  2519,  2521,  2523,  2525,
    2527,  2531,  2533,  2535,  2537,  2539,  2543,  2545,  2547,  2549,
    2551,  2555,  2557,  2559,  2561,  2563,  2567,  2569,  2571,  2573,
    2575,  2579,  2581,  2583,  2585,  2587,  2591,  2596,  2601,  2606,
    2611,  2616,  2621,  2626,  2631,  2636,  2641,  2646,  2651,  2656,
    2661,  2666,  2671,  2676,  2681,  2683,  2685,  2686,  2689,  2693,
    2695,  2697,  2698,  2701,  2703,  2705,  2709,  2713,  2718,  2720,
    2722,  2725,  2727,  2731,  2736,  2741,  2743,  2745,  2747,  2749,
    2751,  2753,  2755,  2757,  2760,  2761,  2764,  2766,  2768,  2770
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     224,     0,    -1,   225,   231,    15,    -1,   226,   227,   228,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   229,    -1,
     230,    -1,    11,    -1,    10,   231,    15,    -1,   232,   258,
     338,   392,   444,   539,    -1,    -1,   233,   234,    -1,    55,
      -1,   235,    -1,   236,    -1,    11,    -1,    10,   237,    56,
      -1,   238,   242,   246,   250,   254,    -1,    -1,   239,    -1,
     240,    -1,   241,    -1,    74,    -1,    73,    -1,    71,     5,
      72,    -1,    -1,   243,    -1,   244,    -1,   245,    -1,    78,
      -1,    77,    -1,    75,     5,    76,    -1,    -1,   247,    -1,
     248,    -1,   249,    -1,    82,    -1,    81,    -1,    79,     5,
      80,    -1,    -1,   251,    -1,   252,    -1,   253,    -1,    86,
      -1,    85,    -1,    83,     5,    84,    -1,    -1,   255,    -1,
     256,    -1,   257,    -1,    90,    -1,    89,    -1,    87,     5,
      88,    -1,    -1,   259,   260,    -1,    57,    -1,   261,    -1,
     262,    -1,    10,    58,    -1,    11,    -1,    10,   263,    58,
      -1,   264,    -1,   265,    -1,   264,   265,    -1,   266,    -1,
     282,    -1,   288,    -1,   294,    -1,   300,    -1,   306,    -1,
     312,    -1,   318,    -1,   324,    -1,   267,   268,   271,    -1,
     129,    -1,   269,    -1,   270,    -1,   269,   270,    -1,   939,
      -1,   931,    -1,   965,    -1,   272,    -1,   273,    -1,    10,
     130,    -1,    11,    -1,    10,   274,   130,    -1,   275,    -1,
     276,    -1,   275,   276,    -1,   277,   278,   281,    -1,   179,
      -1,   279,    -1,    -1,   279,   280,    -1,   935,    -1,   931,
      -1,    10,   180,    -1,    11,    -1,   283,   284,    -1,   141,
      -1,   285,    -1,   286,    -1,    10,   142,    -1,    11,    -1,
      10,   287,   142,    -1,     4,    -1,   289,   290,    -1,   165,
      -1,   291,    -1,   292,    -1,    10,   166,    -1,    11,    -1,
      10,   293,   166,    -1,     4,    -1,   295,   296,    -1,   163,
      -1,   297,    -1,   298,    -1,    10,   164,    -1,    11,    -1,
      10,   299,   164,    -1,     4,    -1,   301,   302,    -1,   135,
      -1,   303,    -1,   304,    -1,    10,   136,    -1,    11,    -1,
      10,   305,   136,    -1,     4,    -1,   307,   308,    -1,   139,
      -1,   309,    -1,   310,    -1,    10,   140,    -1,    11,    -1,
      10,   311,   140,    -1,     4,    -1,   313,   314,    -1,   171,
      -1,   315,    -1,   316,    -1,    10,   172,    -1,    11,    -1,
      10,   317,   172,    -1,     4,    -1,   319,   320,    -1,   189,
      -1,   321,    -1,   322,    -1,    10,   190,    -1,    11,    -1,
      10,   323,   190,    -1,     4,    -1,   325,   326,   327,    -1,
     153,    -1,   960,    -1,   328,    -1,   329,    -1,    10,   154,
      -1,    11,    -1,    10,   330,   154,    -1,   331,    -1,   332,
      -1,   331,   332,    -1,   333,   334,   337,    -1,   151,    -1,
     335,    -1,    -1,   335,   336,    -1,   935,    -1,   947,    -1,
     931,    -1,    10,   152,    -1,    11,    -1,    -1,   339,   340,
      -1,    59,    -1,   341,    -1,   342,    -1,    10,    60,    -1,
      11,    -1,    10,   343,    60,    -1,   344,    -1,   345,    -1,
     344,   345,    -1,   346,    -1,   352,    -1,   359,    -1,   366,
      -1,   373,    -1,   378,    -1,   347,   348,    -1,   183,    -1,
     349,    -1,   350,    -1,    10,   184,    -1,    11,    -1,    10,
     351,   184,    -1,     4,    -1,   353,   354,   357,    -1,   101,
      -1,   355,    -1,    -1,   355,   356,    -1,   943,    -1,   931,
      -1,    10,   358,   102,    -1,   984,    -1,   360,   361,   364,
      -1,   103,    -1,   362,    -1,    -1,   362,   363,    -1,   943,
      -1,   931,    -1,    10,   365,   104,    -1,   984,    -1,   367,
     368,   371,    -1,    99,    -1,   369,    -1,    -1,   369,   370,
      -1,   943,    -1,   931,    -1,    10,   372,   100,    -1,   984,
      -1,   374,   375,   376,    -1,    97,    -1,    -1,   931,    -1,
      10,   377,    98,    -1,     6,    -1,   379,   380,   381,    -1,
     153,    -1,   960,    -1,   382,    -1,   383,    -1,    10,   154,
      -1,    11,    -1,    10,   384,   154,    -1,   385,    -1,   386,
      -1,   385,   386,    -1,   387,   388,   391,    -1,   151,    -1,
     389,    -1,    -1,   389,   390,    -1,   935,    -1,   947,    -1,
     931,    -1,    10,   152,    -1,    11,    -1,    -1,   393,   394,
      -1,    61,    -1,   395,    -1,   396,    -1,    10,    62,    -1,
      11,    -1,    10,   397,    62,    -1,   398,    -1,   399,    -1,
     398,   399,    -1,   400,    -1,   406,    -1,   412,    -1,   418,
      -1,   424,    -1,   430,    -1,   401,   402,    -1,   119,    -1,
     403,    -1,   404,    -1,    10,   120,    -1,    11,    -1,    10,
     405,   120,    -1,     4,    -1,   407,   408,    -1,   117,    -1,
     409,    -1,   410,    -1,    10,   118,    -1,    11,    -1,    10,
     411,   118,    -1,     6,    -1,   413,   414,    -1,   193,    -1,
     415,    -1,   416,    -1,    10,   194,    -1,    11,    -1,    10,
     417,   194,    -1,     6,    -1,   419,   420,    -1,   187,    -1,
     421,    -1,   422,    -1,    10,   188,    -1,    11,    -1,    10,
     423,   188,    -1,     4,    -1,   425,   426,    -1,   167,    -1,
     427,    -1,   428,    -1,    10,   168,    -1,    11,    -1,    10,
     429,   168,    -1,   984,    -1,   431,   432,   433,    -1,   153,
      -1,   960,    -1,   434,    -1,   435,    -1,    10,   154,    -1,
      11,    -1,    10,   436,   154,    -1,   437,    -1,   438,    -1,
     437,   438,    -1,   439,   440,   443,    -1,   151,    -1,   441,
      -1,    -1,   441,   442,    -1,   935,    -1,   947,    -1,   931,
      -1,    10,   152,    -1,    11,    -1,    -1,   445,   446,    -1,
      63,    -1,   447,    -1,   448,    -1,    10,    64,    -1,    11,
      -1,    10,   449,    64,    -1,   450,    -1,   451,    -1,   450,
     451,    -1,   452,    -1,   458,    -1,   464,    -1,   470,    -1,
     476,    -1,   482,    -1,   499,    -1,   506,    -1,   513,    -1,
     520,    -1,   525,    -1,   453,   454,    -1,   175,    -1,   455,
      -1,   456,    -1,    10,   176,    -1,    11,    -1,    10,   457,
     176,    -1,     4,    -1,   459,   460,    -1,   177,    -1,   461,
      -1,   462,    -1,    10,   178,    -1,    11,    -1,    10,   463,
     178,    -1,     4,    -1,   465,   466,    -1,   161,    -1,   467,
      -1,   468,    -1,    10,   162,    -1,    11,    -1,    10,   469,
     162,    -1,     4,    -1,   471,   472,    -1,    91,    -1,   473,
      -1,   474,    -1,    10,    92,    -1,    11,    -1,    10,   475,
      92,    -1,     4,    -1,   477,   478,    -1,   127,    -1,   479,
      -1,   480,    -1,    10,   128,    -1,    11,    -1,    10,   481,
     128,    -1,     4,    -1,   483,   484,   485,    -1,   191,    -1,
     966,    -1,   486,    -1,   487,    -1,    10,   192,    -1,    11,
      -1,    10,   488,   192,    -1,   489,    -1,   490,    -1,   489,
     490,    -1,   491,   492,   494,    -1,   185,    -1,    -1,   492,
     493,    -1,   943,    -1,   939,    -1,   927,    -1,   931,    -1,
     495,    -1,   496,    -1,    10,   186,    -1,    11,    -1,    10,
     497,   186,    -1,   498,    -1,     7,    -1,     6,    -1,   500,
     501,   504,    -1,   201,    -1,   502,    -1,    -1,   502,   503,
      -1,   943,    -1,   931,    -1,    10,   505,   202,    -1,   984,
      -1,   507,   508,   511,    -1,   203,    -1,   509,    -1,    -1,
     509,   510,    -1,   943,    -1,   931,    -1,    10,   512,   204,
      -1,   984,    -1,   514,   515,   518,    -1,   199,    -1,   516,
      -1,    -1,   516,   517,    -1,   943,    -1,   931,    -1,    10,
     519,   200,    -1,   984,    -1,   521,   522,   523,    -1,   197,
      -1,    -1,   931,    -1,    10,   524,   198,    -1,     6,    -1,
     526,   527,   528,    -1,   153,    -1,   960,    -1,   529,    -1,
     530,    -1,    10,   154,    -1,    11,    -1,    10,   531,   154,
      -1,   532,    -1,   533,    -1,   532,   533,    -1,   534,   535,
     538,    -1,   151,    -1,   536,    -1,    -1,   536,   537,    -1,
     935,    -1,   947,    -1,   931,    -1,    10,   152,    -1,    11,
      -1,    -1,   540,   541,   544,    -1,    65,    -1,   542,    -1,
      -1,   542,   543,    -1,   963,    -1,   968,    -1,   952,    -1,
     957,    -1,   545,    -1,   546,    -1,    10,    66,    -1,    11,
      -1,    10,   547,    66,    -1,   548,   904,    -1,   549,    -1,
     548,   549,    -1,   550,   551,   556,    -1,   169,    -1,   552,
      -1,    -1,   552,   553,    -1,   554,    -1,   555,    -1,    36,
     986,     6,   986,    -1,    53,     3,   986,    -1,    10,   557,
     573,   579,   690,   786,   881,   170,    -1,   558,   559,   562,
      -1,   175,    -1,   560,    -1,   561,    -1,   560,   561,    -1,
     939,    -1,   931,    -1,   965,    -1,   563,    -1,   564,    -1,
      10,   176,    -1,    11,    -1,    10,   565,   176,    -1,   566,
      -1,   567,    -1,   566,   567,    -1,   568,   569,   572,    -1,
     179,    -1,   570,    -1,    -1,   570,   571,    -1,   939,    -1,
     931,    -1,    10,   180,    -1,    11,    -1,    -1,   574,   575,
      -1,   141,    -1,   576,    -1,   577,    -1,    10,   142,    -1,
      11,    -1,    10,   578,   142,    -1,     4,    -1,    -1,   580,
     581,   582,    -1,   211,    -1,    -1,   962,    -1,   583,    -1,
     584,    -1,    11,    -1,    10,   585,   212,    -1,   586,   599,
     614,   662,    -1,    -1,   587,   588,   589,    -1,   205,    -1,
     967,    -1,   590,    -1,   591,    -1,    10,   206,    -1,    11,
      -1,    10,   592,   206,    -1,   593,    -1,   594,    -1,   593,
     594,    -1,   595,   596,   597,    -1,   209,    -1,    37,   986,
       6,   986,    -1,    -1,    10,   985,   598,   210,    -1,    -1,
     600,   601,   602,    -1,   207,    -1,   967,    -1,   603,    -1,
     604,    -1,    10,   208,    -1,    11,    -1,    10,   605,   208,
      -1,   606,    -1,   607,    -1,   606,   607,    -1,   608,   609,
     610,    -1,   209,    -1,    37,   986,     6,   986,    -1,   611,
      -1,   612,    -1,    10,   210,    -1,    11,    -1,    10,   613,
     210,    -1,     4,    -1,    -1,   615,   616,    -1,   109,    -1,
     617,    -1,   618,    -1,    11,    -1,    10,   619,   110,    -1,
     620,   627,   634,   641,   648,   655,    -1,    -1,   621,   622,
     623,    -1,   107,    -1,   953,    -1,   624,    -1,   625,    -1,
      11,    -1,    10,   626,   108,    -1,   969,    -1,    -1,   628,
     629,   630,    -1,    93,    -1,   953,    -1,   631,    -1,   632,
      -1,    11,    -1,    10,   633,    94,    -1,   969,    -1,    -1,
     635,   636,   637,    -1,    95,    -1,   953,    -1,   638,    -1,
     639,    -1,    11,    -1,    10,   640,    96,    -1,   969,    -1,
      -1,   642,   643,   644,    -1,   137,    -1,   953,    -1,   645,
      -1,   646,    -1,    11,    -1,    10,   647,   138,    -1,   969,
      -1,    -1,   649,   650,   651,    -1,   181,    -1,   953,    -1,
     652,    -1,   653,    -1,    11,    -1,    10,   654,   182,    -1,
     969,    -1,    -1,   656,   657,   658,    -1,   195,    -1,   953,
      -1,   659,    -1,   660,    -1,    11,    -1,    10,   661,   196,
      -1,   969,    -1,    -1,   662,   663,    -1,   664,   665,   668,
      -1,   151,    -1,   666,    -1,    -1,   666,   667,    -1,   967,
      -1,   954,    -1,   947,    -1,   935,    -1,   931,    -1,   669,
      -1,   670,    -1,    10,   152,    -1,    11,    -1,    10,   671,
     152,    -1,   672,    -1,   680,    -1,   673,    -1,   672,   673,
      -1,   674,   675,   676,    -1,   209,    -1,    37,   986,     6,
     986,    -1,   677,    -1,   678,    -1,    10,   210,    -1,    11,
      -1,    10,   679,   210,    -1,   985,    -1,   681,    -1,   680,
     681,    -1,   682,   683,   686,    -1,   125,    -1,   684,    -1,
      -1,   684,   685,    -1,   953,    -1,   947,    -1,   931,    -1,
     687,    -1,   688,    -1,    11,    -1,    10,   689,   126,    -1,
     969,    -1,    -1,   691,   692,   693,    -1,   145,    -1,    -1,
     959,    -1,   694,    -1,   695,    -1,    11,    -1,    10,   696,
     146,    -1,   697,   710,   758,    -1,    -1,   698,   699,   700,
      -1,   205,    -1,   956,    -1,   701,    -1,   702,    -1,    10,
     206,    -1,    11,    -1,    10,   703,   206,    -1,   704,    -1,
     705,    -1,   704,   705,    -1,   706,   707,   708,    -1,   143,
      -1,    -1,    37,   986,     6,   986,    -1,    10,   709,   144,
      -1,     6,    -1,     7,    -1,    -1,   711,   712,    -1,   109,
      -1,   713,    -1,   714,    -1,    11,    -1,    10,   715,   110,
      -1,   716,   723,   730,   737,   744,   751,    -1,    -1,   717,
     718,   719,    -1,   107,    -1,   953,    -1,   720,    -1,   721,
      -1,    11,    -1,    10,   722,   108,    -1,   969,    -1,    -1,
     724,   725,   726,    -1,    93,    -1,   953,    -1,   727,    -1,
     728,    -1,    11,    -1,    10,   729,    94,    -1,   969,    -1,
      -1,   731,   732,   733,    -1,    95,    -1,   953,    -1,   734,
      -1,   735,    -1,    11,    -1,    10,   736,    96,    -1,   969,
      -1,    -1,   738,   739,   740,    -1,   137,    -1,   953,    -1,
     741,    -1,   742,    -1,    11,    -1,    10,   743,   138,    -1,
     969,    -1,    -1,   745,   746,   747,    -1,   181,    -1,   953,
      -1,   748,    -1,   749,    -1,    11,    -1,    10,   750,   182,
      -1,   969,    -1,    -1,   752,   753,   754,    -1,   195,    -1,
     953,    -1,   755,    -1,   756,    -1,    11,    -1,    10,   757,
     196,    -1,   969,    -1,    -1,   758,   759,    -1,   760,   761,
     764,    -1,   151,    -1,   762,    -1,    -1,   762,   763,    -1,
     956,    -1,   954,    -1,   947,    -1,   935,    -1,   931,    -1,
     765,    -1,   766,    -1,    10,   152,    -1,    11,    -1,    10,
     767,   152,    -1,   768,    -1,   776,    -1,   769,    -1,   768,
     769,    -1,   770,   771,   772,    -1,   143,    -1,    37,   986,
       6,   986,    -1,   773,    -1,   774,    -1,    10,   144,    -1,
      11,    -1,    10,   775,   144,    -1,   985,    -1,   777,    -1,
     776,   777,    -1,   778,   779,   782,    -1,   125,    -1,   780,
      -1,    -1,   780,   781,    -1,   953,    -1,   947,    -1,   931,
      -1,   783,    -1,   784,    -1,    11,    -1,    10,   785,   126,
      -1,   969,    -1,    -1,   787,   788,   789,    -1,   115,    -1,
      -1,   958,    -1,   790,    -1,   791,    -1,    11,    -1,    10,
     792,   116,    -1,   793,   805,   853,    -1,    -1,   794,   795,
     796,    -1,   121,    -1,   951,    -1,   797,    -1,   798,    -1,
      10,   122,    -1,    11,    -1,    10,   799,   122,    -1,   800,
      -1,   801,    -1,   800,   801,    -1,   802,   803,   804,    -1,
     113,    -1,    37,   986,     6,   986,    -1,    10,   984,   114,
      -1,    -1,   806,   807,    -1,   109,    -1,   808,    -1,   809,
      -1,    11,    -1,    10,   810,   110,    -1,   811,   818,   825,
     832,   839,   846,    -1,    -1,   812,   813,   814,    -1,   107,
      -1,   953,    -1,   815,    -1,   816,    -1,    11,    -1,    10,
     817,   108,    -1,   969,    -1,    -1,   819,   820,   821,    -1,
      93,    -1,   953,    -1,   822,    -1,   823,    -1,    11,    -1,
      10,   824,    94,    -1,   969,    -1,    -1,   826,   827,   828,
      -1,    95,    -1,   953,    -1,   829,    -1,   830,    -1,    11,
      -1,    10,   831,    96,    -1,   969,    -1,    -1,   833,   834,
     835,    -1,   137,    -1,   953,    -1,   836,    -1,   837,    -1,
      11,    -1,    10,   838,   138,    -1,   969,    -1,    -1,   840,
     841,   842,    -1,   181,    -1,   953,    -1,   843,    -1,   844,
      -1,    11,    -1,    10,   845,   182,    -1,   969,    -1,    -1,
     847,   848,   849,    -1,   195,    -1,   953,    -1,   850,    -1,
     851,    -1,    11,    -1,    10,   852,   196,    -1,   969,    -1,
      -1,   853,   854,    -1,   855,   856,   859,    -1,   151,    -1,
     857,    -1,    -1,   857,   858,    -1,   951,    -1,   954,    -1,
     947,    -1,   935,    -1,   931,    -1,   860,    -1,   861,    -1,
      10,   152,    -1,    11,    -1,    10,   862,   152,    -1,   863,
      -1,   871,    -1,   864,    -1,   863,   864,    -1,   865,   866,
     867,    -1,   113,    -1,    37,   986,     6,   986,    -1,   868,
      -1,   869,    -1,    10,   114,    -1,    11,    -1,    10,   870,
     114,    -1,   985,    -1,   872,    -1,   871,   872,    -1,   873,
     874,   877,    -1,   125,    -1,   875,    -1,    -1,   875,   876,
      -1,   953,    -1,   947,    -1,   931,    -1,   878,    -1,   879,
      -1,    11,    -1,    10,   880,   126,    -1,   969,    -1,    -1,
     882,   883,   884,    -1,   157,    -1,   961,    -1,   885,    -1,
     886,    -1,    10,   158,    -1,    11,    -1,    10,   887,   158,
      -1,   888,    -1,   889,    -1,   888,   889,    -1,   890,   891,
     894,    -1,   155,    -1,   892,    -1,    -1,   892,   893,    -1,
     935,    -1,   927,    -1,   931,    -1,   955,    -1,   895,    -1,
     896,    -1,    10,   156,    -1,    11,    -1,    10,   897,   156,
      -1,   898,    -1,   899,    -1,   898,   899,    -1,   900,    -1,
     901,    -1,   902,    -1,    69,    -1,    70,    -1,    67,   903,
      68,    -1,     5,    -1,    -1,   905,   906,   907,    -1,   159,
      -1,   964,    -1,   908,    -1,   909,    -1,    10,   160,    -1,
      11,    -1,    10,   910,   160,    -1,   911,    -1,   912,    -1,
     911,   912,    -1,   913,   914,   917,    -1,   173,    -1,   915,
      -1,    -1,   915,   916,    -1,   935,    -1,   927,    -1,   931,
      -1,   955,    -1,   918,    -1,   919,    -1,    10,   174,    -1,
      11,    -1,    10,   920,   174,    -1,   921,    -1,   922,    -1,
     921,   922,    -1,   923,    -1,   924,    -1,   925,    -1,    69,
      -1,    70,    -1,    67,   926,    68,    -1,     5,    -1,   928,
      -1,   929,    -1,   930,    -1,    42,    -1,    41,     3,   986,
      -1,   932,    -1,   933,    -1,   934,    -1,    44,    -1,    43,
       3,   986,    -1,   936,    -1,   937,    -1,   938,    -1,    46,
      -1,    45,     3,   986,    -1,   940,    -1,   941,    -1,   942,
      -1,    48,    -1,    47,     3,   986,    -1,   944,    -1,   945,
      -1,   946,    -1,    50,    -1,    49,     3,   986,    -1,   948,
      -1,   949,    -1,   950,    -1,    52,    -1,    51,     3,   986,
      -1,    16,   986,     6,   986,    -1,    17,   986,     6,   986,
      -1,    18,   986,     6,   986,    -1,    19,   986,     6,   986,
      -1,    21,   986,     6,   986,    -1,    22,   986,     6,   986,
      -1,    23,   986,     6,   986,    -1,    24,   986,     6,   986,
      -1,    25,   986,     6,   986,    -1,    26,   986,     6,   986,
      -1,    27,   986,     6,   986,    -1,    28,   986,     6,   986,
      -1,    29,   986,     6,   986,    -1,    30,   986,     6,   986,
      -1,    31,   986,     6,   986,    -1,    32,   986,     6,   986,
      -1,    33,   986,     6,   986,    -1,    34,   986,     6,   986,
      -1,   970,    -1,   977,    -1,    -1,   970,   971,    -1,   972,
     973,   976,    -1,   123,    -1,   974,    -1,    -1,   974,   975,
      -1,   983,    -1,   982,    -1,    10,     6,   124,    -1,   105,
     978,   979,    -1,    40,   986,     6,   986,    -1,   980,    -1,
     981,    -1,    10,   106,    -1,    11,    -1,    10,     4,   106,
      -1,    38,   986,     6,   986,    -1,    39,   986,     6,   986,
      -1,     6,    -1,     7,    -1,   216,    -1,   217,    -1,   218,
      -1,     4,    -1,     6,    -1,     7,    -1,   987,     8,    -1,
      -1,   987,   988,    -1,   219,    -1,   220,    -1,   221,    -1,
     222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   192,   194,   201,   208,   208,   210,   210,
     212,   214,   217,   226,   226,   237,   246,   246,   248,   250,
     252,   254,   254,   256,   256,   258,   258,   260,   265,   265,
     267,   267,   269,   269,   271,   276,   276,   278,   278,   280,
     280,   282,   287,   287,   289,   289,   291,   291,   293,   298,
     298,   300,   300,   302,   302,   304,   314,   314,   316,   318,
     318,   320,   320,   322,   324,   326,   326,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   340,   342,   356,   362,
     362,   365,   370,   374,   382,   386,   391,   391,   393,   395,
     397,   397,   399,   403,   412,   417,   417,   420,   425,   431,
     431,   434,   436,   442,   442,   444,   444,   446,   448,   451,
     453,   459,   459,   461,   461,   463,   465,   468,   470,   476,
     476,   478,   478,   480,   482,   485,   487,   493,   493,   495,
     495,   497,   499,   502,   504,   510,   510,   512,   512,   514,
     516,   519,   521,   527,   527,   529,   529,   531,   533,   536,
     538,   544,   544,   546,   546,   548,   550,   553,   555,   561,
     571,   575,   580,   580,   582,   584,   586,   586,   588,   592,
     603,   608,   608,   611,   617,   622,   629,   629,   633,   633,
     635,   637,   637,   639,   639,   641,   643,   645,   645,   648,
     649,   650,   651,   652,   653,   656,   658,   664,   664,   666,
     666,   668,   670,   676,   678,   688,   690,   690,   693,   699,
     704,   706,   711,   713,   723,   725,   725,   728,   734,   739,
     741,   747,   749,   759,   761,   761,   764,   770,   775,   777,
     783,   785,   793,   794,   799,   801,   805,   807,   813,   823,
     827,   832,   832,   834,   836,   838,   838,   840,   844,   855,
     860,   860,   863,   869,   874,   881,   881,   885,   885,   887,
     889,   889,   891,   891,   893,   895,   897,   897,   900,   901,
     902,   903,   904,   905,   908,   910,   916,   916,   918,   918,
     920,   922,   929,   931,   937,   937,   939,   939,   941,   943,
     946,   948,   954,   954,   956,   956,   958,   960,   963,   965,
     971,   971,   973,   973,   975,   977,   980,   982,   988,   988,
     990,   990,   992,   994,  1000,  1002,  1008,  1018,  1022,  1027,
    1027,  1029,  1031,  1033,  1033,  1035,  1039,  1050,  1055,  1055,
    1058,  1064,  1069,  1076,  1076,  1079,  1079,  1081,  1083,  1083,
    1085,  1085,  1087,  1089,  1091,  1091,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1107,  1109,  1115,
    1115,  1117,  1117,  1119,  1121,  1128,  1130,  1136,  1136,  1138,
    1138,  1140,  1142,  1145,  1147,  1153,  1153,  1155,  1155,  1157,
    1159,  1162,  1164,  1170,  1170,  1172,  1172,  1174,  1176,  1179,
    1181,  1187,  1187,  1189,  1189,  1191,  1193,  1196,  1198,  1204,
    1213,  1217,  1222,  1222,  1224,  1226,  1228,  1228,  1230,  1232,
    1245,  1245,  1248,  1248,  1248,  1248,  1251,  1251,  1253,  1253,
    1255,  1257,  1270,  1271,  1274,  1276,  1286,  1288,  1288,  1291,
    1297,  1302,  1304,  1310,  1312,  1322,  1324,  1324,  1327,  1333,
    1338,  1340,  1346,  1348,  1358,  1360,  1360,  1363,  1369,  1374,
    1376,  1382,  1384,  1393,  1394,  1399,  1401,  1406,  1408,  1414,
    1424,  1428,  1433,  1433,  1435,  1437,  1439,  1439,  1441,  1445,
    1456,  1461,  1461,  1464,  1470,  1475,  1482,  1482,  1485,  1485,
    1487,  1495,  1500,  1500,  1503,  1510,  1516,  1522,  1530,  1534,
    1539,  1539,  1541,  1543,  1545,  1545,  1547,  1549,  1557,  1559,
    1559,  1561,  1561,  1563,  1572,  1589,  1595,  1597,  1607,  1612,
    1612,  1615,  1620,  1624,  1633,  1637,  1643,  1643,  1645,  1647,
    1649,  1649,  1651,  1654,  1663,  1668,  1668,  1671,  1677,  1684,
    1684,  1687,  1687,  1689,  1691,  1691,  1693,  1693,  1695,  1697,
    1704,  1704,  1706,  1709,  1709,  1718,  1718,  1720,  1722,  1724,
    1726,  1726,  1728,  1730,  1738,  1742,  1747,  1747,  1749,  1751,
    1753,  1753,  1755,  1762,  1768,  1770,  1770,  1773,  1773,  1775,
    1777,  1785,  1789,  1794,  1794,  1796,  1798,  1800,  1800,  1802,
    1810,  1816,  1819,  1820,  1822,  1822,  1824,  1826,  1829,  1829,
    1831,  1833,  1833,  1835,  1837,  1839,  1841,  1841,  1850,  1852,
    1859,  1859,  1861,  1863,  1865,  1868,  1868,  1878,  1880,  1887,
    1887,  1889,  1891,  1893,  1896,  1896,  1905,  1907,  1914,  1914,
    1916,  1918,  1920,  1923,  1923,  1932,  1934,  1941,  1941,  1943,
    1945,  1947,  1950,  1950,  1959,  1961,  1968,  1968,  1970,  1972,
    1974,  1977,  1977,  1986,  1988,  1995,  1995,  1997,  1999,  2001,
    2004,  2004,  2006,  2011,  2024,  2031,  2031,  2034,  2044,  2054,
    2060,  2066,  2073,  2073,  2075,  2075,  2077,  2079,  2079,  2081,
    2081,  2083,  2088,  2090,  2097,  2097,  2099,  2099,  2101,  2103,
    2112,  2112,  2114,  2125,  2134,  2141,  2141,  2144,  2150,  2156,
    2164,  2164,  2166,  2168,  2171,  2175,  2175,  2177,  2183,  2183,
    2192,  2192,  2194,  2196,  2198,  2200,  2200,  2202,  2204,  2212,
    2216,  2221,  2221,  2223,  2225,  2228,  2228,  2230,  2237,  2244,
    2244,  2246,  2249,  2250,  2253,  2253,  2255,  2257,  2257,  2261,
    2263,  2265,  2267,  2267,  2276,  2278,  2285,  2285,  2287,  2289,
    2291,  2293,  2293,  2302,  2304,  2311,  2311,  2313,  2315,  2317,
    2320,  2320,  2329,  2331,  2338,  2338,  2340,  2342,  2344,  2347,
    2347,  2356,  2358,  2365,  2365,  2367,  2369,  2371,  2374,  2374,
    2383,  2385,  2392,  2392,  2394,  2396,  2398,  2401,  2401,  2410,
    2412,  2419,  2419,  2421,  2423,  2425,  2428,  2428,  2430,  2436,
    2449,  2457,  2457,  2460,  2470,  2480,  2486,  2492,  2501,  2501,
    2503,  2503,  2505,  2507,  2507,  2509,  2509,  2511,  2516,  2518,
    2523,  2523,  2525,  2525,  2527,  2529,  2535,  2535,  2537,  2548,
    2557,  2564,  2564,  2567,  2573,  2579,  2587,  2587,  2589,  2591,
    2594,  2597,  2597,  2599,  2604,  2604,  2612,  2612,  2614,  2616,
    2618,  2620,  2620,  2622,  2625,  2633,  2637,  2642,  2642,  2644,
    2646,  2648,  2648,  2650,  2657,  2663,  2665,  2668,  2668,  2670,
    2672,  2672,  2674,  2676,  2678,  2680,  2680,  2689,  2691,  2698,
    2698,  2700,  2702,  2704,  2706,  2706,  2715,  2717,  2724,  2724,
    2726,  2728,  2730,  2733,  2733,  2742,  2744,  2751,  2751,  2753,
    2755,  2757,  2760,  2760,  2769,  2771,  2778,  2778,  2780,  2782,
    2784,  2787,  2787,  2796,  2798,  2805,  2805,  2807,  2809,  2811,
    2814,  2814,  2823,  2825,  2832,  2832,  2834,  2836,  2838,  2841,
    2841,  2843,  2849,  2862,  2869,  2869,  2872,  2882,  2892,  2898,
    2904,  2911,  2911,  2913,  2913,  2915,  2917,  2917,  2919,  2919,
    2921,  2926,  2928,  2934,  2934,  2936,  2936,  2938,  2940,  2947,
    2947,  2949,  2960,  2969,  2976,  2976,  2979,  2985,  2991,  2999,
    2999,  3001,  3003,  3005,  3009,  3009,  3011,  3016,  3025,  3029,
    3034,  3034,  3036,  3038,  3040,  3040,  3042,  3046,  3057,  3064,
    3064,  3067,  3073,  3079,  3087,  3097,  3101,  3106,  3106,  3108,
    3110,  3112,  3112,  3114,  3119,  3123,  3125,  3125,  3127,  3129,
    3140,  3140,  3142,  3147,  3156,  3160,  3165,  3165,  3167,  3169,
    3171,  3171,  3173,  3177,  3188,  3195,  3195,  3198,  3203,  3209,
    3215,  3224,  3228,  3233,  3233,  3235,  3237,  3239,  3239,  3241,
    3246,  3250,  3252,  3252,  3254,  3256,  3266,  3272,  3272,  3274,
    3277,  3280,  3286,  3286,  3288,  3291,  3295,  3301,  3301,  3303,
    3306,  3309,  3315,  3315,  3317,  3320,  3323,  3329,  3329,  3331,
    3334,  3337,  3343,  3343,  3345,  3348,  3371,  3377,  3385,  3391,
    3404,  3413,  3419,  3427,  3433,  3439,  3445,  3451,  3457,  3465,
    3471,  3479,  3484,  3490,  3516,  3521,  3523,  3523,  3525,  3527,
    3536,  3538,  3538,  3540,  3540,  3542,  3550,  3552,  3557,  3557,
    3559,  3559,  3561,  3584,  3592,  3606,  3607,  3608,  3609,  3610,
    3614,  3615,  3616,  3618,  3620,  3620,  3622,  3623,  3624,  3625
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
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "HEADERSTART",
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
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "ATLOWERSTART",
  "ATLOWEREND", "ATUPPERSTART", "ATUPPEREND", "AVAILABLECPUNUMBERSTART",
  "AVAILABLECPUNUMBEREND", "AVAILABLECPUSPEEDSTART",
  "AVAILABLECPUSPEEDEND", "AVAILABLEDISKSPACESTART",
  "AVAILABLEDISKSPACEEND", "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND",
  "BASE64START", "BASE64END", "BASICSTART", "BASICEND", "BASISSTATUSSTART",
  "BASISSTATUSEND", "BASSTATUSSTART", "BASSTATUSEND", "CONSTART", "CONEND",
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
  "VARIABLESEND", "VARIDXSTART", "VARIDXEND", "DUMMY", "\"INF\"",
  "\"-INF\"", "\"NaN\"", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlStartEmpty", "osrlStart", "osrlAttributes",
  "osrlContent", "osrlEmpty", "osrlLaden", "osrlBody", "headerElement",
  "headerElementStart", "headerElementContent", "headerElementEmpty",
  "headerElementLaden", "headerElementBody", "fileName", "fileNameContent",
  "fileNameEmpty", "fileNameLaden", "fileSource", "fileSourceContent",
  "fileSourceEmpty", "fileSourceLaden", "fileDescription",
  "fileDescriptionContent", "fileDescriptionEmpty", "fileDescriptionLaden",
  "fileCreator", "fileCreatorContent", "fileCreatorEmpty",
  "fileCreatorLaden", "fileLicence", "fileLicenceContent",
  "fileLicenceEmpty", "fileLicenceLaden", "generalElement",
  "generalElementStart", "generalElementContent", "generalElementEmpty",
  "generalElementLaden", "generalElementBody", "generalElementList",
  "generalChild", "generalStatus", "generalStatusStart",
  "generalStatusAttributes", "generalStatusAttList", "generalStatusATT",
  "generalStatusContent", "generalStatusEmpty", "generalStatusLaden",
  "generalStatusBody", "generalSubstatusArray", "generalSubstatus",
  "generalSubstatusStart", "generalSubstatusAttributes",
  "generalSubstatusAttList", "generalSubstatusATT", "generalSubstatusEnd",
  "generalMessage", "generalMessageStart", "generalMessageContent",
  "generalMessageEmpty", "generalMessageLaden", "generalMessageBody",
  "serviceURI", "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
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
  "weightedObjectivesATT", "solutionContent", "solutionStatus",
  "solutionStatusStart", "solutionStatusAttributes",
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
  "varValueArray", "varValue", "varValueStart", "varIdxATT",
  "varValueContent", "@1", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringLaden", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varStrIdxATT", "varValueStringContent", "varValueStringEmpty",
  "varValueStringLaden", "varValueStringBody", "variableBasisStatus",
  "variableBasisStatusStart", "variableBasisStatusContent",
  "variableBasisStatusEmpty", "variableBasisStatusLaden",
  "variableBasisStatusBody", "variablesBasic", "variablesBasicStart",
  "variablesBasicNumberOfElATT", "variablesBasicContent",
  "variablesBasicEmpty", "variablesBasicLaden", "variablesBasicBody",
  "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesIsFree", "variablesIsFreeStart",
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
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "otherVarEmpty", "otherVarLaden", "otherVarBody",
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
  "objIdxATT", "objValueContent", "objVal", "objectiveBasisStatus",
  "objectiveBasisStatusStart", "objectiveBasisStatusContent",
  "objectiveBasisStatusEmpty", "objectiveBasisStatusLaden",
  "objectiveBasisStatusBody", "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesIsFree", "objectivesIsFreeStart",
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
  "otherObj", "otherObjStart", "otherObjIdxATT", "otherObjContent",
  "otherObjEmpty", "otherObjLaden", "otherObjBody",
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
  "conIdxATT", "dualValueContent", "slackBasisStatus",
  "slackBasisStatusStart", "slackBasisStatusContent",
  "slackBasisStatusEmpty", "slackBasisStatusLaden", "slackBasisStatusBody",
  "slacksBasic", "slacksBasicStart", "slacksBasicNumberOfElATT",
  "slacksBasicContent", "slacksBasicEmpty", "slacksBasicLaden",
  "slacksBasicBody", "slacksAtLower", "slacksAtLowerStart",
  "slacksAtLowerNumberOfElATT", "slacksAtLowerContent",
  "slacksAtLowerEmpty", "slacksAtLowerLaden", "slacksAtLowerBody",
  "slacksAtUpper", "slacksAtUpperStart", "slacksAtUpperNumberOfElATT",
  "slacksAtUpperContent", "slacksAtUpperEmpty", "slacksAtUpperLaden",
  "slacksAtUpperBody", "slacksIsFree", "slacksIsFreeStart",
  "slacksIsFreeNumberOfElATT", "slacksIsFreeContent", "slacksIsFreeEmpty",
  "slacksIsFreeLaden", "slacksIsFreeBody", "slacksSuperbasic",
  "slacksSuperbasicStart", "slacksSuperbasicNumberOfElATT",
  "slacksSuperbasicContent", "slacksSuperbasicEmpty",
  "slacksSuperbasicLaden", "slacksSuperbasicBody", "slacksUnknown",
  "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintResultsArray",
  "otherConstraintResult", "otherConstraintResultStart",
  "otherConstraintResultAttributes", "otherConstraintResultAttList",
  "otherConstraintResultATT", "otherConstraintResultContent",
  "otherConstraintResultEmpty", "otherConstraintResultLaden",
  "otherConstraintResultBody", "otherConList", "otherCon", "otherConStart",
  "otherConIdxATT", "otherConContent", "otherConEmpty", "otherConLaden",
  "otherConBody", "otherConEnumerationList", "otherConEnumeration",
  "otherConEnumerationStart", "otherConEnumerationAttributes",
  "otherConEnumerationAttList", "otherConEnumerationATT",
  "otherConEnumerationContent", "otherConEnumerationEmpty",
  "otherConEnumerationLaden", "otherConEnumerationBody",
  "otherSolutionResults", "otherSolutionResultsStart",
  "numberOfOtherSolutionResults", "otherSolutionResultsContent",
  "otherSolutionResultsEmpty", "otherSolutionResultsLaden",
  "otherSolutionResultsBody", "otherSolutionResultArray",
  "otherSolutionResult", "otherSolutionResultStart",
  "otherSolutionResultAttributes", "otherSolutionResultAttList",
  "otherSolutionResultAtt", "otherSolutionResultContent",
  "otherSolutionResultEmpty", "otherSolutionResultLaden",
  "otherSolutionResultBody", "otherSolutionResultItemArray",
  "otherSolutionResultItem", "otherSolutionResultItemContent",
  "otherSolutionResultItemEmpty", "otherSolutionResultItemLaden",
  "otherSolutionResultItemBody", "otherSolverOutput",
  "otherSolverOutputStart", "numberOfSolverOutputsATT",
  "otherSolverOutputContent", "otherSolverOutputEmpty",
  "otherSolverOutputLaden", "otherSolverOutputBody", "solverOutputArray",
  "solverOutput", "solverOutputStart", "solverOutputAttributes",
  "solverOutputAttList", "solverOutputAtt", "solverOutputContent",
  "solverOutputEmpty", "solverOutputLaden", "solverOutputBody",
  "solverOutputItemArray", "solverOutputItem", "solverOutputItemContent",
  "solverOutputItemEmpty", "solverOutputItemLaden", "solverOutputItemBody",
  "categoryAttribute", "categoryAtt", "categoryAttEmpty",
  "categoryAttContent", "descriptionAttribute", "descriptionAtt",
  "descriptionAttEmpty", "descriptionAttContent", "nameAttribute",
  "nameAtt", "nameAttEmpty", "nameAttContent", "typeAttribute", "typeAtt",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   223,   224,   224,   225,   226,   227,   227,   228,   228,
     229,   230,   231,   232,   232,   233,   234,   234,   235,   236,
     237,   238,   238,   239,   239,   240,   240,   241,   242,   242,
     243,   243,   244,   244,   245,   246,   246,   247,   247,   248,
     248,   249,   250,   250,   251,   251,   252,   252,   253,   254,
     254,   255,   255,   256,   256,   257,   258,   258,   259,   260,
     260,   261,   261,   262,   263,   264,   264,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   266,   267,   268,   269,
     269,   270,   270,   270,   271,   271,   272,   272,   273,   274,
     275,   275,   276,   277,   278,   279,   279,   280,   280,   281,
     281,   282,   283,   284,   284,   285,   285,   286,   287,   288,
     289,   290,   290,   291,   291,   292,   293,   294,   295,   296,
     296,   297,   297,   298,   299,   300,   301,   302,   302,   303,
     303,   304,   305,   306,   307,   308,   308,   309,   309,   310,
     311,   312,   313,   314,   314,   315,   315,   316,   317,   318,
     319,   320,   320,   321,   321,   322,   323,   324,   325,   326,
     327,   327,   328,   328,   329,   330,   331,   331,   332,   333,
     334,   335,   335,   336,   336,   336,   337,   337,   338,   338,
     339,   340,   340,   341,   341,   342,   343,   344,   344,   345,
     345,   345,   345,   345,   345,   346,   347,   348,   348,   349,
     349,   350,   351,   352,   353,   354,   355,   355,   356,   356,
     357,   358,   359,   360,   361,   362,   362,   363,   363,   364,
     365,   366,   367,   368,   369,   369,   370,   370,   371,   372,
     373,   374,   375,   375,   376,   377,   378,   379,   380,   381,
     381,   382,   382,   383,   384,   385,   385,   386,   387,   388,
     389,   389,   390,   390,   390,   391,   391,   392,   392,   393,
     394,   394,   395,   395,   396,   397,   398,   398,   399,   399,
     399,   399,   399,   399,   400,   401,   402,   402,   403,   403,
     404,   405,   406,   407,   408,   408,   409,   409,   410,   411,
     412,   413,   414,   414,   415,   415,   416,   417,   418,   419,
     420,   420,   421,   421,   422,   423,   424,   425,   426,   426,
     427,   427,   428,   429,   430,   431,   432,   433,   433,   434,
     434,   435,   436,   437,   437,   438,   439,   440,   441,   441,
     442,   442,   442,   443,   443,   444,   444,   445,   446,   446,
     447,   447,   448,   449,   450,   450,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   452,   453,   454,
     454,   455,   455,   456,   457,   458,   459,   460,   460,   461,
     461,   462,   463,   464,   465,   466,   466,   467,   467,   468,
     469,   470,   471,   472,   472,   473,   473,   474,   475,   476,
     477,   478,   478,   479,   479,   480,   481,   482,   483,   484,
     485,   485,   486,   486,   487,   488,   489,   489,   490,   491,
     492,   492,   493,   493,   493,   493,   494,   494,   495,   495,
     496,   497,   498,   498,   499,   500,   501,   502,   502,   503,
     503,   504,   505,   506,   507,   508,   509,   509,   510,   510,
     511,   512,   513,   514,   515,   516,   516,   517,   517,   518,
     519,   520,   521,   522,   522,   523,   524,   525,   526,   527,
     528,   528,   529,   529,   530,   531,   532,   532,   533,   534,
     535,   536,   536,   537,   537,   537,   538,   538,   539,   539,
     540,   541,   542,   542,   543,   543,   543,   543,   544,   544,
     545,   545,   546,   547,   548,   548,   549,   550,   551,   552,
     552,   553,   553,   554,   555,   556,   557,   558,   559,   560,
     560,   561,   561,   561,   562,   562,   563,   563,   564,   565,
     566,   566,   567,   568,   569,   570,   570,   571,   571,   572,
     572,   573,   573,   574,   575,   575,   576,   576,   577,   578,
     579,   579,   580,   581,   581,   582,   582,   583,   584,   585,
     586,   586,   587,   588,   589,   589,   590,   590,   591,   592,
     593,   593,   594,   595,   596,   598,   597,   599,   599,   600,
     601,   602,   602,   603,   603,   604,   605,   606,   606,   607,
     608,   609,   610,   610,   611,   611,   612,   613,   614,   614,
     615,   616,   616,   617,   618,   619,   620,   620,   621,   622,
     623,   623,   624,   625,   626,   627,   627,   628,   629,   630,
     630,   631,   632,   633,   634,   634,   635,   636,   637,   637,
     638,   639,   640,   641,   641,   642,   643,   644,   644,   645,
     646,   647,   648,   648,   649,   650,   651,   651,   652,   653,
     654,   655,   655,   656,   657,   658,   658,   659,   660,   661,
     662,   662,   663,   664,   665,   666,   666,   667,   667,   667,
     667,   667,   668,   668,   669,   669,   670,   671,   671,   672,
     672,   673,   674,   675,   676,   676,   677,   677,   678,   679,
     680,   680,   681,   682,   683,   684,   684,   685,   685,   685,
     686,   686,   687,   688,   689,   690,   690,   691,   692,   692,
     693,   693,   694,   695,   696,   697,   697,   698,   699,   700,
     700,   701,   701,   702,   703,   704,   704,   705,   706,   707,
     707,   708,   709,   709,   710,   710,   711,   712,   712,   713,
     714,   715,   716,   716,   717,   718,   719,   719,   720,   721,
     722,   723,   723,   724,   725,   726,   726,   727,   728,   729,
     730,   730,   731,   732,   733,   733,   734,   735,   736,   737,
     737,   738,   739,   740,   740,   741,   742,   743,   744,   744,
     745,   746,   747,   747,   748,   749,   750,   751,   751,   752,
     753,   754,   754,   755,   756,   757,   758,   758,   759,   760,
     761,   762,   762,   763,   763,   763,   763,   763,   764,   764,
     765,   765,   766,   767,   767,   768,   768,   769,   770,   771,
     772,   772,   773,   773,   774,   775,   776,   776,   777,   778,
     779,   780,   780,   781,   781,   781,   782,   782,   783,   784,
     785,   786,   786,   787,   788,   788,   789,   789,   790,   791,
     792,   793,   793,   794,   795,   796,   796,   797,   797,   798,
     799,   800,   800,   801,   802,   803,   804,   805,   805,   806,
     807,   807,   808,   809,   810,   811,   811,   812,   813,   814,
     814,   815,   816,   817,   818,   818,   819,   820,   821,   821,
     822,   823,   824,   825,   825,   826,   827,   828,   828,   829,
     830,   831,   832,   832,   833,   834,   835,   835,   836,   837,
     838,   839,   839,   840,   841,   842,   842,   843,   844,   845,
     846,   846,   847,   848,   849,   849,   850,   851,   852,   853,
     853,   854,   855,   856,   857,   857,   858,   858,   858,   858,
     858,   859,   859,   860,   860,   861,   862,   862,   863,   863,
     864,   865,   866,   867,   867,   868,   868,   869,   870,   871,
     871,   872,   873,   874,   875,   875,   876,   876,   876,   877,
     877,   878,   879,   880,   881,   881,   882,   883,   884,   884,
     885,   885,   886,   887,   888,   888,   889,   890,   891,   892,
     892,   893,   893,   893,   893,   894,   894,   895,   895,   896,
     897,   898,   898,   899,   900,   900,   901,   901,   902,   903,
     904,   904,   905,   906,   907,   907,   908,   908,   909,   910,
     911,   911,   912,   913,   914,   915,   915,   916,   916,   916,
     916,   917,   917,   918,   918,   919,   920,   921,   921,   922,
     923,   923,   924,   924,   925,   926,   927,   928,   928,   929,
     930,   931,   932,   932,   933,   934,   935,   936,   936,   937,
     938,   939,   940,   940,   941,   942,   943,   944,   944,   945,
     946,   947,   948,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,   969,   969,   970,   970,   971,   972,
     973,   974,   974,   975,   975,   976,   977,   978,   979,   979,
     980,   980,   981,   982,   983,   984,   984,   984,   984,   984,
     985,   985,   985,   986,   987,   987,   988,   988,   988,   988
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     6,     0,     2,     1,     1,     1,     1,     3,
       5,     0,     1,     1,     1,     1,     1,     3,     0,     1,
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
       2,     1,     1,     4,     3,     8,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     4,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     0,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     0,     1,
       1,     1,     1,     3,     3,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     0,
       4,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       3,     6,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     0,     1,     1,     1,     1,     3,
       3,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     4,     3,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     3,     3,     4,     1,     1,
       2,     1,     3,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    13,     6,     1,    15,     0,    56,
       0,     7,     0,     2,    58,   178,     0,    21,    18,    14,
      16,    17,    13,    10,     3,     8,     9,   180,   257,     0,
       0,    62,    57,    59,    60,     0,    26,    25,     0,    28,
      22,    23,    24,     0,   259,   335,     0,     0,   184,   179,
     181,   182,    61,    77,   126,   134,   102,   158,   118,   110,
     142,   150,     0,    64,    65,    67,     0,    68,     0,    69,
       0,    70,     0,    71,     0,    72,     0,    73,     0,    74,
       0,    75,     0,     0,    19,     0,    33,    32,    35,    29,
      30,    31,    11,   337,   478,     0,     0,   263,   258,   260,
     261,   183,   231,   222,   204,   213,   237,   196,     0,   186,
     187,   189,     0,   190,   206,   191,   215,   192,   224,   193,
     232,   194,     0,    63,    66,  1114,     0,  1044,     0,  1054,
       0,    78,    79,    82,  1041,  1042,  1043,    81,  1051,  1052,
    1053,    83,     0,   106,   101,   103,   104,     0,   114,   109,
     111,   112,     0,   122,   117,   119,   120,     0,   130,   125,
     127,   128,     0,   138,   133,   135,   136,     0,   146,   141,
     143,   144,     0,   154,   149,   151,   152,  1114,     0,   159,
      27,     0,     0,    40,    39,    42,    36,    37,    38,   480,
      12,   482,     0,   341,   336,   338,   339,   262,   283,   275,
     315,   307,   299,   291,     0,   265,   266,   268,     0,   269,
       0,   270,     0,   271,     0,   272,     0,   273,     0,   185,
     188,     0,   200,   195,   197,   198,     0,   205,     0,   214,
       0,   223,     0,   233,     0,   238,     0,     0,  1114,  1114,
       0,    87,    76,    84,    85,    80,   108,   105,     0,   116,
     113,     0,   124,   121,     0,   132,   129,     0,   140,   137,
       0,   148,   145,     0,   156,   153,     0,     0,     0,   163,
     157,   160,   161,    34,     0,     0,    47,    46,    49,    43,
      44,    45,     0,   481,   340,   382,   390,   458,   374,   358,
     366,   398,   452,   443,   425,   434,     0,   343,   344,   346,
       0,   347,     0,   348,     0,   349,     0,   350,     0,   351,
       0,   352,   427,   353,   436,   354,   445,   355,   453,   356,
       0,   264,   267,     0,   279,   274,   276,   277,     0,   287,
     282,   284,   285,     0,   295,   290,   292,   293,     0,   303,
     298,   300,   301,     0,   311,   306,   308,   309,     0,   316,
     202,   199,     0,     0,   203,     0,  1059,   207,   209,   208,
    1056,  1057,  1058,     0,   212,   216,   218,   217,     0,   221,
     225,   227,   226,     0,   230,     0,   242,   236,   239,   240,
    1114,  1113,  1116,  1117,  1118,  1119,  1115,  1045,  1055,    86,
      93,     0,    89,    90,    95,   107,   115,   123,   131,   139,
     147,   155,  1114,   169,   162,     0,   165,   166,   171,    41,
       0,     0,    54,    53,    20,    50,    51,    52,     0,   491,
     479,   488,   489,  1114,  1114,  1114,  1114,   483,   486,   487,
     484,   485,   342,   345,     0,   362,   357,   359,   360,     0,
     370,   365,   367,   368,     0,   378,   373,   375,   376,     0,
     386,   381,   383,   384,     0,   394,   389,   391,   392,  1114,
       0,   399,     0,   426,     0,   435,     0,   444,     0,   454,
       0,   459,   281,   278,     0,   289,   286,     0,   297,   294,
       0,   305,   302,     0,  1105,  1106,   310,  1107,  1108,  1109,
       0,   313,     0,   320,   314,   317,   318,   201,     0,   211,
    1114,     0,   220,     0,   229,   235,     0,   248,   241,     0,
     244,   245,   250,  1080,    88,    91,     0,    94,  1075,   164,
     167,     0,   170,    48,     0,   490,   497,     0,  1000,   494,
     499,     0,     0,     0,     0,   364,   361,     0,   372,   369,
       0,   380,   377,     0,   388,   385,     0,   396,   393,     0,
       0,     0,   403,   397,   400,   401,     0,   424,   428,   430,
     429,     0,   433,   437,   439,   438,     0,   442,   446,   448,
     447,     0,   451,     0,   463,   457,   460,   461,   280,   288,
     296,   304,   312,   326,   319,     0,   322,   323,   328,   210,
    1060,   219,   228,   234,   243,   246,     0,   249,     0,   100,
      92,     0,  1049,    96,    98,    97,  1046,  1047,  1048,     0,
     177,   168,     0,  1064,   172,   175,   173,   174,  1061,  1062,
    1063,    55,   492,  1002,   495,   493,     0,     0,   498,  1114,
    1114,  1114,  1114,   363,   371,   379,   387,   395,  1114,   409,
     402,     0,   405,   406,   410,     0,   432,     0,   441,     0,
     450,   456,     0,   469,   462,     0,   465,   466,   471,   321,
     324,     0,   327,     0,   256,   247,   251,   254,   252,   253,
      99,  1114,   176,  1114,  1114,     0,  1003,     0,   496,  1114,
       0,   500,   501,   502,  1067,  1072,  1078,  1083,  1081,   404,
     407,     0,   431,   440,   449,   455,   464,   467,     0,   470,
       0,   334,   325,   329,   332,   330,   331,   255,  1050,  1065,
       0,     0,  1007,  1001,  1004,  1005,   507,   531,     0,     0,
    1114,     0,   419,     0,  1039,   411,   408,   416,   417,   414,
    1036,  1037,  1038,   415,   413,   412,     0,   477,   468,   472,
     475,   473,   474,   333,  1114,  1006,  1013,     0,  1009,  1010,
    1015,   533,   540,     0,     0,   508,   509,   512,   511,   513,
    1114,   504,   423,   422,   418,     0,   421,  1114,   476,  1079,
    1008,  1011,     0,  1014,   542,   695,   543,     0,   537,   532,
     534,   535,     0,   517,   506,   514,   515,   510,   503,   420,
    1040,     0,  1024,  1012,  1021,  1022,  1114,  1016,  1018,  1019,
    1017,  1020,   697,   831,   698,  1114,     0,   544,   539,   536,
       0,   516,   523,     0,   519,   520,   525,     0,  1032,  1033,
    1023,     0,  1026,  1027,  1029,  1030,  1031,     0,   833,   964,
     834,  1114,     0,   699,     0,   550,   547,   541,   545,   546,
     538,   518,   521,     0,   524,  1035,     0,  1025,  1028,  1114,
     966,     0,     0,  1114,     0,   835,     0,   705,   702,   696,
     700,   701,  1114,   552,     0,   567,     0,     0,   530,   522,
     526,   528,   527,  1034,  1070,   505,  1114,     0,   967,     0,
     841,   838,   832,   836,   837,  1114,   707,     0,   724,     0,
    1077,   548,   569,   588,     0,  1114,     0,   553,   529,     0,
       0,   971,   965,   968,   969,  1114,   843,     0,   857,     0,
    1074,   703,   726,   786,     0,  1114,     0,   708,   590,   650,
       0,     0,   570,     0,     0,   557,   551,   554,   555,  1114,
     977,   970,     0,   973,   974,   979,  1073,   839,   859,   919,
       0,  1114,     0,   844,   704,   732,   729,   725,   727,   728,
       0,     0,   712,   706,   709,   710,   549,   596,   593,   589,
     591,   592,     0,   574,   568,   571,   572,  1114,   556,   563,
       0,   559,   560,     0,  1076,   972,   975,     0,   978,   840,
     865,   862,   858,   860,   861,     0,     0,   848,   842,   845,
     846,   789,   787,   791,   734,     0,   741,     0,  1114,   718,
     711,     0,   714,   715,   719,   653,   651,   655,   598,     0,
     605,     0,   573,   580,     0,   576,   577,     0,  1082,   558,
     561,  1114,     0,     0,   988,   976,   985,   986,   980,   982,
     983,   981,   984,   922,   920,   924,   867,     0,   874,     0,
    1114,   854,   847,     0,   850,   851,     0,     0,   790,   730,
     743,   750,     0,  1114,     0,   735,  1071,   713,   716,  1114,
       0,     0,   654,   594,   607,   614,     0,     0,   599,   575,
     578,  1114,     0,     0,     0,   562,     0,   996,   997,   987,
       0,   990,   991,   993,   994,   995,     0,   923,   863,   876,
     883,     0,     0,   868,  1066,   849,   852,  1114,     0,     0,
     801,   788,   798,   799,  1114,   792,   797,   796,   795,   794,
     793,   752,   759,     0,     0,   744,     0,  1086,   738,   733,
     736,   737,     0,     0,   717,     0,   665,   652,   662,   663,
     656,   661,   660,   659,   658,   657,   616,   623,     0,     0,
     608,  1086,   602,   597,   600,   601,     0,     0,   585,   579,
     582,   583,  1114,  1110,  1111,  1112,   565,   999,     0,   989,
     992,     0,   934,   921,   931,   932,   925,   930,   929,   928,
     926,   927,   885,   892,     0,     0,   877,  1086,   871,   866,
     869,   870,     0,     0,   853,   819,   808,   800,     0,   803,
     805,     0,   804,   816,   821,     0,   761,   768,     0,     0,
     753,  1086,   747,   742,   745,   746,  1114,     0,     0,   740,
    1084,  1085,  1114,   722,   723,     0,   683,   664,   672,     0,
     667,   669,     0,   668,   680,   685,   625,   632,     0,     0,
     617,  1086,   611,   606,   609,   610,     0,   604,  1114,   587,
     584,     0,   564,     0,   998,   941,   952,   933,     0,   936,
     938,     0,   937,   949,   954,   894,   901,     0,     0,   886,
    1086,   880,   875,   878,   879,     0,   873,  1114,     0,   802,
     806,  1114,     0,   817,     0,   820,  1114,   770,   777,     0,
       0,   762,  1086,   756,   751,   754,   755,     0,   749,  1068,
    1114,     0,   739,  1089,  1087,  1091,   720,   721,   666,   670,
    1114,     0,   681,     0,   684,   634,   641,     0,     0,   626,
    1086,   620,   615,   618,   619,     0,   613,   603,   581,   586,
     566,   935,   939,  1114,     0,   950,     0,   953,   903,   910,
       0,     0,   895,  1086,   889,   884,   887,   888,     0,   882,
     872,   855,   856,     0,     0,   813,   807,   810,   811,  1086,
     828,   818,   826,   827,   822,   825,   824,   823,  1069,   779,
     731,     0,     0,   771,  1086,   765,   760,   763,   764,     0,
     758,   748,     0,     0,  1101,  1096,  1098,  1099,     0,  1090,
       0,     0,   677,   671,   674,   675,  1086,   692,   682,   690,
     691,   686,   689,   688,   687,   643,   595,     0,     0,   635,
    1086,   629,   624,   627,   628,     0,   622,   612,     0,     0,
     946,   940,   943,   944,  1086,   961,   951,   959,   960,   955,
     958,   957,   956,   912,   864,     0,     0,   904,  1086,   898,
     893,   896,   897,     0,   891,   881,  1114,   812,     0,   815,
       0,   830,     0,   780,  1086,   774,   769,   772,   773,     0,
     767,   757,  1114,     0,  1100,     0,  1088,  1114,  1114,  1092,
    1094,  1093,  1114,   676,     0,   679,     0,   694,     0,   644,
    1086,   638,   633,   636,   637,     0,   631,   621,  1114,   945,
       0,   948,     0,   963,     0,   913,  1086,   907,   902,   905,
     906,     0,   900,   890,   809,   814,   829,  1086,   783,   778,
     781,   782,     0,   776,   766,  1097,  1102,     0,     0,     0,
     673,   678,   693,  1086,   647,   642,   645,   646,     0,   640,
     630,   942,   947,   962,  1086,   916,   911,   914,   915,     0,
     909,   899,     0,   785,   775,  1095,  1114,  1114,     0,   649,
     639,     0,   918,   908,   784,  1103,  1104,   648,   917
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    24,    25,    26,     8,     9,
      10,    19,    20,    21,    38,    39,    40,    41,    42,    88,
      89,    90,    91,   185,   186,   187,   188,   278,   279,   280,
     281,   414,   415,   416,   417,    15,    16,    32,    33,    34,
      62,    63,    64,    65,    66,   130,   131,   132,   242,   243,
     244,   391,   392,   393,   394,   516,   517,   603,   600,    67,
      68,   144,   145,   146,   248,    69,    70,   149,   150,   151,
     251,    71,    72,   154,   155,   156,   254,    73,    74,   159,
     160,   161,   257,    75,    76,   164,   165,   166,   260,    77,
      78,   169,   170,   171,   263,    79,    80,   174,   175,   176,
     266,    81,    82,   178,   270,   271,   272,   405,   406,   407,
     408,   521,   522,   614,   611,    28,    29,    49,    50,    51,
     108,   109,   110,   111,   112,   223,   224,   225,   352,   113,
     114,   226,   227,   357,   354,   498,   115,   116,   228,   229,
     365,   364,   501,   117,   118,   230,   231,   370,   369,   503,
     119,   120,   232,   374,   506,   121,   122,   234,   377,   378,
     379,   509,   510,   511,   512,   596,   597,   666,   665,    45,
      46,    98,    99,   100,   204,   205,   206,   207,   208,   325,
     326,   327,   474,   209,   210,   330,   331,   332,   477,   211,
     212,   335,   336,   337,   480,   213,   214,   340,   341,   342,
     483,   215,   216,   345,   346,   347,   490,   217,   218,   348,
     494,   495,   496,   585,   586,   587,   588,   661,   662,   703,
     702,    94,    95,   194,   195,   196,   296,   297,   298,   299,
     300,   436,   437,   438,   537,   301,   302,   441,   442,   443,
     540,   303,   304,   446,   447,   448,   543,   305,   306,   451,
     452,   453,   546,   307,   308,   456,   457,   458,   549,   309,
     310,   460,   553,   554,   555,   641,   642,   643,   644,   691,
     725,   726,   727,   728,   765,   766,   311,   312,   462,   463,
     558,   557,   645,   313,   314,   464,   465,   563,   562,   647,
     315,   316,   466,   467,   568,   567,   649,   317,   318,   468,
     572,   652,   319,   320,   470,   575,   576,   577,   655,   656,
     657,   658,   698,   699,   739,   738,   190,   191,   282,   283,
     427,   420,   421,   422,   527,   528,   529,   530,   627,   628,
     681,   682,   683,   678,   717,   718,   754,   755,   756,   784,
     785,   786,   813,   814,   815,   816,   843,   844,   870,   869,
     752,   753,   779,   780,   781,   810,   775,   776,   806,   837,
     838,   839,   864,   865,   866,   896,   926,   927,   928,   970,
     971,   972,   973,  1022,  1075,  1243,   893,   894,   921,   964,
     965,   966,  1014,  1015,  1016,  1017,  1072,  1149,  1150,  1151,
    1241,   919,   920,   959,   960,   961,  1009,  1010,  1011,  1067,
    1143,  1144,  1145,  1236,  1065,  1066,  1139,  1233,  1234,  1235,
    1315,  1137,  1138,  1229,  1312,  1313,  1314,  1405,  1227,  1228,
    1308,  1402,  1403,  1404,  1475,  1306,  1307,  1398,  1472,  1473,
    1474,  1518,  1396,  1397,  1468,  1515,  1516,  1517,  1538,   956,
    1006,  1007,  1061,  1062,  1130,  1127,  1128,  1129,  1219,  1220,
    1221,  1222,  1301,  1383,  1384,  1385,  1464,  1223,  1224,  1225,
    1303,  1304,  1391,  1388,  1389,  1390,  1466,   803,   804,   832,
     859,   860,   861,   887,   888,   889,   916,   953,   954,   955,
    1001,  1002,  1003,  1004,  1060,  1124,  1215,   913,   914,   947,
     948,   949,   995,   996,   997,  1054,  1119,  1120,  1121,  1208,
    1051,  1052,  1114,  1203,  1204,  1205,  1287,  1112,  1113,  1199,
    1284,  1285,  1286,  1369,  1197,  1198,  1280,  1366,  1367,  1368,
    1449,  1278,  1279,  1362,  1446,  1447,  1448,  1502,  1360,  1361,
    1442,  1499,  1500,  1501,  1532,   944,   992,   993,  1047,  1048,
    1105,  1101,  1102,  1103,  1188,  1189,  1190,  1191,  1272,  1346,
    1347,  1348,  1438,  1192,  1193,  1194,  1274,  1275,  1354,  1351,
    1352,  1353,  1440,   829,   830,   854,   882,   883,   884,   907,
     908,   909,   942,   988,   989,   990,  1043,  1044,  1045,  1046,
    1098,  1184,   939,   940,   982,   983,   984,  1037,  1038,  1039,
    1092,  1179,  1180,  1181,  1265,  1090,  1091,  1175,  1262,  1263,
    1264,  1338,  1173,  1174,  1258,  1335,  1336,  1337,  1433,  1256,
    1257,  1331,  1430,  1431,  1432,  1491,  1329,  1330,  1426,  1488,
    1489,  1490,  1529,  1424,  1425,  1484,  1526,  1527,  1528,  1541,
     979,  1034,  1035,  1086,  1087,  1166,  1163,  1164,  1165,  1248,
    1249,  1250,  1251,  1324,  1411,  1412,  1413,  1480,  1252,  1253,
    1254,  1326,  1327,  1419,  1416,  1417,  1418,  1482,   851,   852,
     877,   902,   903,   904,   932,   933,   934,   935,   977,   978,
    1028,  1025,  1026,  1027,  1080,  1081,  1082,  1083,  1084,  1085,
    1158,   625,   626,   675,   713,   714,   715,   747,   748,   749,
     750,   772,   773,   797,   793,   794,   795,   821,   822,   823,
     824,   825,   826,   846,   729,   730,   731,   732,   133,   134,
     135,   136,   605,   606,   607,   608,   137,   138,   139,   140,
     359,   360,   361,   362,   617,   618,   619,   620,   943,   428,
    1055,  1109,   801,   917,   429,   855,   833,   179,   878,   807,
     430,   676,   141,   461,   897,   431,  1209,  1210,  1294,  1295,
    1378,  1379,  1459,  1456,  1211,  1291,  1375,  1376,  1377,  1460,
    1461,   491,  1156,   236,   237,   386
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1288
static const yytype_int16 yypact[] =
{
     280, -1288, -1288,    69,    53,    81, -1288, -1288,   118,    46,
     305, -1288,   311, -1288, -1288,    76,   376,   115, -1288, -1288,
   -1288, -1288,    53, -1288, -1288, -1288, -1288, -1288,   121,   382,
     -10, -1288, -1288, -1288, -1288,   180, -1288, -1288,   139,    43,
   -1288, -1288, -1288,   184, -1288,   150,   387,   -19, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,   163,   124, -1288, -1288,   207, -1288,   396, -1288,
     400, -1288,   407, -1288,   415, -1288,   417, -1288,   423, -1288,
     429, -1288,   214,   172, -1288,   256, -1288, -1288,   155, -1288,
   -1288, -1288, -1288, -1288,   201,   431,     9, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   211,   -14,
   -1288, -1288,   433, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
     402, -1288,   214, -1288, -1288, -1288,   277, -1288,   281, -1288,
     438,   207, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,    33, -1288, -1288, -1288, -1288,    24, -1288, -1288,
   -1288, -1288,    27, -1288, -1288, -1288, -1288,    41, -1288, -1288,
   -1288, -1288,    31, -1288, -1288, -1288, -1288,    21, -1288, -1288,
   -1288, -1288,    17, -1288, -1288, -1288, -1288, -1288,   440, -1288,
   -1288,   210,   289, -1288, -1288,   219, -1288, -1288, -1288, -1288,
   -1288, -1288,   171, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,   246,   114, -1288, -1288,   447, -1288,
     449, -1288,   454, -1288,   456, -1288,   461, -1288,   214, -1288,
   -1288,    35, -1288, -1288, -1288, -1288,   290,   247,   320,   247,
     347,   247,   349, -1288,   465, -1288,   314,    -4, -1288, -1288,
     -80, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   227, -1288,
   -1288,   205, -1288, -1288,   215, -1288, -1288,   231, -1288, -1288,
     235, -1288, -1288,   209, -1288, -1288,   222,   389,   -87, -1288,
   -1288, -1288, -1288, -1288,   343,   430, -1288, -1288,   238, -1288,
   -1288, -1288,   467,   241, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   404,   -61, -1288, -1288,
     470, -1288,   472, -1288,   474, -1288,   476, -1288,   478, -1288,
     441, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   402, -1288,
     214, -1288, -1288,    39, -1288, -1288, -1288, -1288,    47, -1288,
   -1288, -1288, -1288,    11, -1288, -1288, -1288, -1288,    23, -1288,
   -1288, -1288, -1288,     6, -1288, -1288, -1288, -1288,   480, -1288,
   -1288, -1288,   361,    12, -1288,   528, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288,    12, -1288, -1288, -1288, -1288,    12, -1288,
   -1288, -1288, -1288,   543, -1288,    88, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,   436,   391, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   418,   448, -1288, -1288, -1288,
     496,   577, -1288, -1288, -1288, -1288, -1288, -1288,   -17, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,    25, -1288, -1288, -1288, -1288,    20,
   -1288, -1288, -1288, -1288,    30, -1288, -1288, -1288, -1288,    64,
   -1288, -1288, -1288, -1288,    32, -1288, -1288, -1288, -1288, -1288,
     482, -1288,   621,   247,   622,   247,   623,   247,   624, -1288,
     488, -1288, -1288, -1288,   516, -1288, -1288,   520, -1288, -1288,
     445, -1288, -1288,   452, -1288, -1288, -1288, -1288, -1288, -1288,
     473, -1288,   125, -1288, -1288, -1288, -1288, -1288,   533, -1288,
   -1288,   538, -1288,   545, -1288, -1288,   549, -1288, -1288,   489,
     498, -1288, -1288, -1288, -1288, -1288,   490,   310, -1288, -1288,
   -1288,   493,   370, -1288,   556, -1288, -1288,   580,   -73, -1288,
   -1288,   642,   644,   645,   646, -1288, -1288,   477, -1288, -1288,
     479, -1288, -1288,   494, -1288, -1288,   566, -1288, -1288,   532,
     653,    -5, -1288, -1288, -1288, -1288,    12, -1288, -1288, -1288,
   -1288,    12, -1288, -1288, -1288, -1288,    12, -1288, -1288, -1288,
   -1288,   655, -1288,   226, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   508,   512, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   495,   370,   484, -1288,
   -1288,   662, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   514,
   -1288, -1288,   664, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   638,   659,    19, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,   481,   485, -1288, -1288,   469, -1288,   471, -1288,   486,
   -1288, -1288,   483, -1288, -1288,   524,   526, -1288, -1288, -1288,
   -1288,   497,   370,   522, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   499, -1288,   504, -1288, -1288,
     677, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,   341, -1288, -1288, -1288, -1288, -1288, -1288,   501,   370,
     530, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
     678,   -67, -1288, -1288, -1288, -1288, -1288,   547,   207,   681,
   -1288,    26, -1288,   686, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   539, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   534,   536, -1288,
   -1288, -1288,   487,   503,   505,   207, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   506, -1288, -1288, -1288, -1288,
   -1288, -1288,   507,   298, -1288,   551,   665,    36, -1288, -1288,
   -1288, -1288,   -35, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,    78, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288,   575,   670, -1288,   509, -1288, -1288, -1288,
     555, -1288, -1288,   535,   521, -1288, -1288,   696, -1288, -1288,
   -1288,   540,   264, -1288, -1288, -1288, -1288,   697, -1288,   553,
     680, -1288,   511, -1288,   699,   502, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288,   513,   225, -1288,   634, -1288, -1288, -1288,
   -1288,   557,   679, -1288,   515, -1288,   707,   510, -1288, -1288,
   -1288, -1288, -1288, -1288,   518,   541,   683,   559, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   517, -1288,   711,
     598, -1288, -1288, -1288, -1288, -1288, -1288,   586,   611,   700,
   -1288, -1288, -1288,   615,   683, -1288,   519, -1288, -1288,   715,
     203, -1288, -1288, -1288, -1288, -1288, -1288,   607,   620,   709,
   -1288, -1288, -1288, -1288,   523, -1288,   525, -1288, -1288, -1288,
     527,   529, -1288,   725,   -39, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,   582,   588, -1288, -1288, -1288, -1288, -1288, -1288,
     531, -1288,   537, -1288,   590,   626, -1288, -1288, -1288, -1288,
     728,   -89, -1288, -1288, -1288, -1288,   594,   629, -1288, -1288,
   -1288, -1288,   342, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
     560,   561, -1288,   705, -1288, -1288, -1288,   542,   298,   596,
     630, -1288, -1288, -1288, -1288,   738,   -12, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   636,   656,   732, -1288, -1288,
   -1288,   562,   608, -1288,   716, -1288, -1288, -1288, -1288,   647,
     661,   732, -1288, -1288,   563,   565, -1288,   718, -1288, -1288,
   -1288, -1288,   746,     7, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   648,   666,   732,
   -1288, -1288, -1288,   639,   649, -1288,   723,   544,   266, -1288,
   -1288,   668,   732, -1288,   546, -1288, -1288, -1288, -1288, -1288,
     755,   548,   386, -1288, -1288,   672,   732,   550, -1288, -1288,
   -1288, -1288,   552,   763,   331, -1288,   767, -1288, -1288, -1288,
     617,   296, -1288, -1288, -1288, -1288,   554,   357, -1288, -1288,
     682,   732,   558, -1288, -1288, -1288, -1288, -1288,   765,   -20,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,   641,   732,   564, -1288,   770,   674, -1288, -1288,
   -1288, -1288,   774,   570, -1288,   -37, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   650,   732,   568,
   -1288,   674, -1288, -1288, -1288, -1288,   775,    10, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   714, -1288,
   -1288,   -50, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288,   651,   732,   574, -1288,   674, -1288, -1288,
   -1288, -1288,   777,    12, -1288, -1288, -1288, -1288,   632,   643,
   -1288,   748,   667, -1288, -1288,   783, -1288,   613,   732,   576,
   -1288,   674, -1288, -1288, -1288, -1288, -1288,   751,   685, -1288,
     673, -1288, -1288, -1288, -1288,   654, -1288, -1288, -1288,   652,
     592, -1288,   758,   675, -1288, -1288, -1288,   618,   732,   578,
   -1288,   674, -1288, -1288, -1288, -1288,   689, -1288, -1288, -1288,
   -1288,   600, -1288,   602, -1288, -1288, -1288, -1288,   657,   690,
   -1288,   768,   688, -1288, -1288, -1288,   625,   732,   581, -1288,
     674, -1288, -1288, -1288, -1288,   694, -1288, -1288,   693, -1288,
   -1288, -1288,   583, -1288,   585,   106, -1288, -1288,   627,   732,
     587, -1288,   674, -1288, -1288, -1288, -1288,   717, -1288, -1288,
   -1288,   591, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,   593, -1288,   595,   106, -1288,   628,   732,   597, -1288,
     674, -1288, -1288, -1288, -1288,   720, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,   599, -1288,   601,   106, -1288,   631,
     732,   603, -1288,   674, -1288, -1288, -1288, -1288,   721, -1288,
   -1288, -1288, -1288,   802,    40, -1288, -1288, -1288, -1288,   674,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,   732,   605, -1288,   674, -1288, -1288, -1288, -1288,   722,
   -1288, -1288,   810,    48, -1288, -1288, -1288, -1288,   807,   579,
     813,    16, -1288, -1288, -1288, -1288,   674, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   732,   610, -1288,
     674, -1288, -1288, -1288, -1288,   724, -1288, -1288,   818,    52,
   -1288, -1288, -1288, -1288,   674, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   732,   612, -1288,   674, -1288,
   -1288, -1288, -1288,   729, -1288, -1288, -1288, -1288,   684, -1288,
     701, -1288,   614, -1288,   674, -1288, -1288, -1288, -1288,   691,
   -1288, -1288, -1288,   726, -1288,   824, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,   633, -1288,   708, -1288,   616, -1288,
     674, -1288, -1288, -1288, -1288,   695, -1288, -1288, -1288, -1288,
     727, -1288,   710, -1288,   619, -1288,   674, -1288, -1288, -1288,
   -1288,   702, -1288, -1288, -1288, -1288, -1288,   674, -1288, -1288,
   -1288, -1288,   660, -1288, -1288, -1288, -1288,   713,   829,   832,
   -1288, -1288, -1288,   674, -1288, -1288, -1288, -1288,   663, -1288,
   -1288, -1288, -1288, -1288,   674, -1288, -1288, -1288, -1288,   669,
   -1288, -1288,   658, -1288, -1288, -1288, -1288, -1288,   671, -1288,
   -1288,   676, -1288, -1288, -1288, -1288, -1288, -1288, -1288
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   817, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,   784, -1288, -1288, -1288, -1288,   719, -1288, -1288,
   -1288, -1288, -1288,   457, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   442,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,   737, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288,   345, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   687, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288,   267, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   567, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288,   216, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
     196, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   328, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   102, -1288,
   -1288, -1288, -1288, -1288,    45, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,  -110, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,  -153, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
    -355, -1288, -1288, -1288, -1288, -1288, -1288, -1288,  -357, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288,  -134, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,  -320, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288,  -322, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,  -173, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,  -376, -1288, -1288, -1288, -1288, -1288, -1288, -1288,  -378,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,   -58, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288,  -204, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,   130,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,    57,
   -1288, -1288, -1288, -1288,  -770, -1288, -1288, -1288,  -118, -1288,
   -1288, -1288,  -516, -1288, -1288, -1288,  -676, -1288, -1288, -1288,
    -222, -1288, -1288, -1288,  -592, -1288, -1288, -1288,  -207, -1288,
   -1001,  -989,   -97,  -165, -1288, -1288, -1288,  -114, -1288, -1288,
   -1288, -1288,  -658, -1288,  -868, -1288, -1050, -1288, -1288, -1288,
   -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288, -1288,
   -1288,  -352, -1287,  -177, -1288, -1288
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     267,   499,   233,   798,   381,   669,   616,   367,   235,   372,
    1068,   502,   484,   485,  1239,   734,   504,   478,   484,   485,
    1153,   264,  1154,  1155,   538,   261,   922,   481,   249,   535,
     285,   252,   762,   763,   541,   258,   547,   246,  1093,   350,
     808,   101,   758,   472,  1153,   255,  1154,  1155,    52,   525,
     389,  1115,  1453,   475,   999,   679,  1153,  1439,  1154,  1155,
     759,   387,   388,  1245,   403,  1140,   286,   404,   544,     6,
     706,   197,   680,  1134,  1076,  1246,  1077,  1078,   102,   758,
     103,   668,   104,   102,   105,   103,   623,   104,  1216,   105,
    1176,  1237,   287,   745,  1465,    11,   526,   759,  1171,   390,
     288,  1041,  1247,    14,   349,  1185,   746,   742,     7,   358,
    1042,   366,  1200,   371,   289,  1217,   290,  1000,    85,    53,
      86,    87,  1481,  1186,  1053,    54,   198,  1266,   199,    55,
     291,    56,  1187,    13,   106,    27,   292,  1230,   293,   106,
     294,   811,   295,    57,   812,   817,   705,   818,   819,   126,
     127,  1288,   526,    58,  1454,    59,   545,   612,   613,   473,
     548,    60,   200,  1079,   107,   476,  1479,   968,   872,   107,
     969,   259,  1218,  1259,   486,   247,   201,   256,   809,    61,
     639,  1316,    44,   741,  1437,    83,    35,   640,    36,    37,
     250,   253,   542,   262,  1135,    84,   202,  1281,   539,    92,
     469,   536,   203,   513,   646,   479,   471,   265,  1029,   648,
    1339,   482,   764,    93,   650,   382,   383,   384,   385,   351,
    1240,   123,   487,   488,   489,   518,  1463,  1309,   487,   488,
     489,   198,  1370,   199,   182,   284,   183,   184,   125,   507,
     177,   560,   508,   565,   180,   570,   531,   532,   533,   534,
     126,   127,   820,    53,   128,   129,  1332,   800,   423,    54,
    1406,   181,   285,    55,   424,    56,   189,   200,   126,   127,
     425,   219,   128,   129,  1357,   426,   583,    57,  1363,   584,
     238,   201,   550,  1434,   239,  1104,   273,    58,   915,    59,
     126,   127,     1,     2,   274,    60,   355,   356,   286,  1441,
     353,   202,   275,  1394,   276,   277,  1399,   203,   321,   126,
     127,   601,   602,    61,  1450,    17,    18,   612,   613,   796,
     380,    22,    23,   590,   287,   411,  1422,   412,   413,  1427,
     363,   817,   288,   818,   819,  1153,  1467,  1154,  1155,   723,
     724,   126,   127,   601,   602,   559,   289,   564,   290,   569,
    1476,   721,   722,   126,   127,   601,   602,   368,   930,   373,
    1443,   931,   291,  1076,  1483,  1077,  1078,   398,   292,   395,
     293,   396,   294,   941,   295,   399,  1104,   653,  1492,   397,
     654,   400,   723,   724,   126,   127,    30,    31,   128,   129,
     355,   356,    47,    48,  1503,   402,  1469,    96,    97,   604,
     126,   127,   601,   602,   615,  1104,   142,   143,   612,   613,
     147,   148,   401,   126,   127,   601,   602,   152,   153,   895,
    1519,   612,   613,   409,  1485,   157,   158,   162,   163,   126,
     127,   601,   602,   167,   168,   410,  1530,   612,   613,   172,
     173,   192,   193,   221,   222,   126,   127,  1533,   240,   241,
     268,   269,   684,   685,   686,   687,  1108,   323,   324,   328,
     329,   688,  1031,  1539,   333,   334,   338,   339,   432,   735,
    1133,   343,   344,   459,  1542,   375,   376,   418,   419,   667,
     434,   435,   439,   440,   444,   445,   449,   450,   454,   455,
     492,   493,   551,   552,   708,  1169,   709,   710,   573,   574,
     598,   599,   719,   609,   610,   663,   664,   700,   701,   711,
     712,   736,   737,   777,   778,   782,   783,   791,   792,   835,
     836,   857,   858,   867,   868,   880,   881,   900,   901,   924,
     925,   500,  1107,   945,   946,   951,   952,   957,   958,   962,
     963,   980,   981,   761,   704,   497,  1132,   986,   987,   505,
    1012,  1013,  1023,  1024,  1099,  1100,  1117,  1118,  1125,  1126,
    1141,  1142,  1147,  1148,  1161,  1162,   514,   769,  1177,  1178,
     390,  1168,   519,   733,  1201,  1202,  1213,  1214,  1231,  1232,
     523,   740,   524,   788,  1260,  1261,  1282,  1283,  1310,  1311,
     790,  1333,  1334,  1344,  1345,  1349,  1350,  1364,  1365,   403,
     757,  1373,  1374,  1381,  1382,  1386,  1387,  1400,  1401,  1409,
    1410,  1414,  1415,  1428,  1429,  1444,  1445,  1457,  1458,   827,
    1470,  1471,  1486,  1487,  1497,  1498,  1513,  1514,   834,  1524,
    1525,   556,   561,   566,   571,   589,   578,   757,   579,   580,
     581,   582,   591,   594,   621,   592,   622,   593,   629,   507,
     630,   631,   632,   633,   856,   799,   635,   634,   636,   638,
     637,   651,   659,   583,   670,   671,   672,   673,   674,   677,
     639,   692,   874,   689,   707,   693,   879,   653,   696,   716,
     720,   695,   743,  1356,   744,   890,   694,   760,   751,   767,
     828,   768,   789,   805,   770,   831,   802,   840,   774,   899,
     812,   845,   873,   849,   853,   862,   876,   863,   910,   746,
     850,   841,  1393,   885,   847,   886,   895,   905,   923,   906,
     912,   929,   915,   937,   918,   941,   871,   875,   936,   938,
     891,   967,   911,   994,   998,  1421,  1008,  1036,   950,   898,
     975,   991,  1021,   930,  1040,  1005,  1049,  1033,   892,  1050,
    1053,   999,   974,  1059,  1064,  1071,  1074,  1063,  1088,  1089,
    1097,  1095,  1041,  1111,   985,  1123,  1019,  1136,  1057,  1152,
     969,  1069,  1157,  1159,  1013,  1183,  1206,  1172,  1196,  1207,
    1212,  1238,  1244,  1267,  1269,  1271,  1186,  1226,  1255,  1276,
    1018,  1290,  1185,  1292,  1277,  1300,  1293,  1317,  1297,  1305,
    1216,  1218,  1340,  1245,  1298,  1323,  1328,  1342,  1436,  1321,
    1319,  1371,  1320,  1246,  1407,  1435,  1452,  1455,  1451,  1462,
    1477,  1056,  1359,  1395,  1478,  1493,  1423,  1496,  1495,  1504,
    1507,  1268,  1506,  1520,  1512,  1536,  1523,  1535,  1537,    43,
    1531,  1522,  1534,  1511,  1073,  1540,   220,   124,   520,   515,
     245,  1543,   697,   660,  1544,   595,   624,   787,   690,   842,
    1030,  1020,  1070,  1094,   433,  1299,  1302,  1547,  1058,  1270,
    1273,  1096,  1548,  1322,  1325,   976,  1116,  1160,   771,   848,
    1170,  1032,  1122,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,  1146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1182,     0,     0,     0,     0,     0,     0,  1195,     0,     0,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1167,
       0,     0,     0,     0,     0,  1242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1289,
       0,     0,     0,     0,     0,  1296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1341,     0,     0,     0,  1343,     0,     0,     0,     0,  1358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1380,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1420,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1505,     0,     0,     0,     0,
    1508,  1509,     0,     0,     0,  1510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1545,
    1546
};

static const yytype_int16 yycheck[] =
{
     177,   353,   120,   773,     8,   597,   522,   229,   122,   231,
    1011,   363,     6,     7,     4,   691,   368,     6,     6,     7,
       4,     4,     6,     7,     4,     4,   894,     4,     4,     4,
      91,     4,     6,     7,     4,     4,     4,     4,  1039,     4,
       4,    60,   718,     4,     4,     4,     6,     7,    58,    66,
     130,  1052,     4,     6,   143,    36,     4,  1344,     6,     7,
     718,   238,   239,   113,   151,  1066,   127,   154,     4,     0,
     662,    62,    53,  1062,    67,   125,    69,    70,    97,   755,
      99,   597,   101,    97,   103,    99,   159,   101,   125,   103,
    1091,  1141,   153,   160,  1381,    14,   169,   755,  1087,   179,
     161,   113,   152,    57,   218,   125,   173,   699,    55,   227,
     122,   229,  1113,   231,   175,   152,   177,   206,    75,   129,
      77,    78,  1409,   143,    18,   135,   117,  1177,   119,   139,
     191,   141,   152,    15,   153,    59,   197,  1138,   199,   153,
     201,   176,   203,   153,   179,    67,   662,    69,    70,    43,
      44,  1201,   169,   163,   106,   165,    92,    51,    52,   120,
     128,   171,   153,   156,   183,   118,   114,   206,   844,   183,
     209,   140,   209,  1174,   168,   142,   167,   136,   142,   189,
     185,  1231,    61,   699,   144,     5,    71,   192,    73,    74,
     166,   164,   162,   172,  1062,    56,   187,  1198,   178,    15,
     318,   176,   193,   380,   556,   194,   320,   190,   978,   561,
    1260,   188,   186,    63,   566,   219,   220,   221,   222,   184,
     210,    58,   216,   217,   218,   402,   210,  1228,   216,   217,
     218,   117,  1282,   119,    79,    64,    81,    82,    31,   151,
      26,   463,   154,   465,    72,   467,   423,   424,   425,   426,
      43,    44,   174,   129,    47,    48,  1257,   773,    17,   135,
    1310,     5,    91,   139,    23,   141,    65,   153,    43,    44,
      29,    60,    47,    48,  1275,    34,   151,   153,  1279,   154,
       3,   167,   459,  1333,     3,    19,    76,   163,    22,   165,
      43,    44,    12,    13,     5,   171,    49,    50,   127,  1349,
      10,   187,    83,  1304,    85,    86,  1307,   193,    62,    43,
      44,    45,    46,   189,  1364,    10,    11,    51,    52,    21,
       6,    10,    11,   500,   153,    87,  1327,    89,    90,  1330,
      10,    67,   161,    69,    70,     4,  1386,     6,     7,    41,
      42,    43,    44,    45,    46,   463,   175,   465,   177,   467,
    1400,    10,    11,    43,    44,    45,    46,    10,   155,    10,
    1361,   158,   191,    67,  1414,    69,    70,   136,   197,   142,
     199,   166,   201,    16,   203,   140,    19,   151,  1428,   164,
     154,   172,    41,    42,    43,    44,    10,    11,    47,    48,
      49,    50,    10,    11,  1444,     6,  1397,    10,    11,   517,
      43,    44,    45,    46,   522,    19,    10,    11,    51,    52,
      10,    11,   190,    43,    44,    45,    46,    10,    11,    33,
    1470,    51,    52,    80,  1425,    10,    11,    10,    11,    43,
      44,    45,    46,    10,    11,     5,  1486,    51,    52,    10,
      11,    10,    11,    10,    11,    43,    44,  1497,    10,    11,
      10,    11,   629,   630,   631,   632,  1048,    10,    11,    10,
      11,   638,   978,  1513,    10,    11,    10,    11,    64,   691,
    1062,    10,    11,    32,  1524,    10,    11,    10,    11,   597,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   671,  1087,   673,   674,    10,    11,
      10,    11,   679,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     3,  1048,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   720,   662,   184,  1062,    10,    11,     6,
     208,   209,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   130,   744,    10,    11,
     179,  1087,   154,   691,    10,    11,     6,     7,    10,    11,
      84,   699,     5,   760,    10,    11,    10,    11,    10,    11,
     767,    10,    11,    10,    11,    10,    11,    10,    11,   151,
     718,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    38,    39,   796,
      10,    11,    10,    11,    10,    11,    10,    11,   805,    10,
      11,    10,    10,    10,    10,   102,   120,   755,   118,   194,
     188,   168,   104,   154,    88,   100,    66,    98,     6,   151,
       6,     6,     6,   176,   831,   773,   162,   178,    92,     6,
     128,     6,   154,   151,   180,     3,   152,     3,    30,    10,
     185,   202,   849,   192,   152,   204,   853,   151,   154,   175,
       3,   198,   152,  1275,     6,   862,   200,     6,   141,     3,
     115,   152,   186,    28,   160,    25,   145,   142,   211,   876,
     179,     5,    68,     6,    24,     6,    27,   205,   885,   173,
     157,   176,  1304,     6,   174,   205,    33,     6,   895,   121,
     109,     6,    22,   116,   109,    16,   844,   170,   905,   109,
     212,     6,   146,   107,     6,  1327,   107,   107,   915,   180,
     158,   151,    37,   155,     6,   151,   110,   151,   207,    93,
      18,   143,   929,    37,    93,    37,    10,   110,   110,    93,
      37,   122,   113,    95,   941,    10,   206,    95,   206,     6,
     209,   208,     5,   156,   209,    10,     6,    95,   137,   105,
       6,     6,    68,     6,   152,    37,   143,   137,   137,     6,
     967,    40,   125,   108,   181,    37,   123,   108,   144,   181,
     125,   209,   108,   113,   152,    37,   181,   114,     6,   152,
     210,    94,   210,   125,    94,    94,     6,    10,    96,     6,
      96,   998,   195,   195,     6,    96,   195,   126,   144,   138,
       6,  1183,   106,   138,   126,     6,   126,   124,     6,    22,
     138,   114,   182,   210,  1021,   182,   109,    63,   406,   392,
     131,   182,   656,   586,   196,   510,   528,   755,   642,   814,
     978,   971,  1015,  1040,   297,  1220,  1223,   196,  1002,  1189,
    1192,  1044,   196,  1249,  1252,   933,  1053,  1081,   748,   822,
    1087,   978,  1059,  1048,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,  1071,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1097,    -1,    -1,    -1,    -1,    -1,    -1,  1104,    -1,    -1,
    1048,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1087,
      -1,    -1,    -1,    -1,    -1,  1152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1206,
      -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1267,    -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,  1276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1304,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1327,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1452,    -1,    -1,    -1,    -1,
    1457,  1458,    -1,    -1,    -1,  1462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1536,
    1537
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   224,   225,   226,     0,    55,   231,   232,
     233,    14,   227,    15,    57,   258,   259,    10,    11,   234,
     235,   236,    10,    11,   228,   229,   230,    59,   338,   339,
      10,    11,   260,   261,   262,    71,    73,    74,   237,   238,
     239,   240,   241,   231,    61,   392,   393,    10,    11,   340,
     341,   342,    58,   129,   135,   139,   141,   153,   163,   165,
     171,   189,   263,   264,   265,   266,   267,   282,   283,   288,
     289,   294,   295,   300,   301,   306,   307,   312,   313,   318,
     319,   324,   325,     5,    56,    75,    77,    78,   242,   243,
     244,   245,    15,    63,   444,   445,    10,    11,   394,   395,
     396,    60,    97,    99,   101,   103,   153,   183,   343,   344,
     345,   346,   347,   352,   353,   359,   360,   366,   367,   373,
     374,   378,   379,    58,   265,    31,    43,    44,    47,    48,
     268,   269,   270,   931,   932,   933,   934,   939,   940,   941,
     942,   965,    10,    11,   284,   285,   286,    10,    11,   290,
     291,   292,    10,    11,   296,   297,   298,    10,    11,   302,
     303,   304,    10,    11,   308,   309,   310,    10,    11,   314,
     315,   316,    10,    11,   320,   321,   322,    26,   326,   960,
      72,     5,    79,    81,    82,   246,   247,   248,   249,    65,
     539,   540,    10,    11,   446,   447,   448,    62,   117,   119,
     153,   167,   187,   193,   397,   398,   399,   400,   401,   406,
     407,   412,   413,   418,   419,   424,   425,   430,   431,    60,
     345,    10,    11,   348,   349,   350,   354,   355,   361,   362,
     368,   369,   375,   931,   380,   960,   986,   987,     3,     3,
      10,    11,   271,   272,   273,   270,     4,   142,   287,     4,
     166,   293,     4,   164,   299,     4,   136,   305,     4,   140,
     311,     4,   172,   317,     4,   190,   323,   986,    10,    11,
     327,   328,   329,    76,     5,    83,    85,    86,   250,   251,
     252,   253,   541,   542,    64,    91,   127,   153,   161,   175,
     177,   191,   197,   199,   201,   203,   449,   450,   451,   452,
     453,   458,   459,   464,   465,   470,   471,   476,   477,   482,
     483,   499,   500,   506,   507,   513,   514,   520,   521,   525,
     526,    62,   399,    10,    11,   402,   403,   404,    10,    11,
     408,   409,   410,    10,    11,   414,   415,   416,    10,    11,
     420,   421,   422,    10,    11,   426,   427,   428,   432,   960,
       4,   184,   351,    10,   357,    49,    50,   356,   931,   943,
     944,   945,   946,    10,   364,   363,   931,   943,    10,   371,
     370,   931,   943,    10,   376,    10,    11,   381,   382,   383,
       6,     8,   219,   220,   221,   222,   988,   986,   986,   130,
     179,   274,   275,   276,   277,   142,   166,   164,   136,   140,
     172,   190,     6,   151,   154,   330,   331,   332,   333,    80,
       5,    87,    89,    90,   254,   255,   256,   257,    10,    11,
     544,   545,   546,    17,    23,    29,    34,   543,   952,   957,
     963,   968,    64,   451,    10,    11,   454,   455,   456,    10,
      11,   460,   461,   462,    10,    11,   466,   467,   468,    10,
      11,   472,   473,   474,    10,    11,   478,   479,   480,    32,
     484,   966,   501,   502,   508,   509,   515,   516,   522,   931,
     527,   960,     4,   120,   405,     6,   118,   411,     6,   194,
     417,     4,   188,   423,     6,     7,   168,   216,   217,   218,
     429,   984,    10,    11,   433,   434,   435,   184,   358,   984,
       3,   365,   984,   372,   984,     6,   377,   151,   154,   384,
     385,   386,   387,   986,   130,   276,   278,   279,   986,   154,
     332,   334,   335,    84,     5,    66,   169,   547,   548,   549,
     550,   986,   986,   986,   986,     4,   176,   457,     4,   178,
     463,     4,   162,   469,     4,    92,   475,     4,   128,   481,
     986,    10,    11,   485,   486,   487,    10,   504,   503,   931,
     943,    10,   511,   510,   931,   943,    10,   518,   517,   931,
     943,    10,   523,    10,    11,   528,   529,   530,   120,   118,
     194,   188,   168,   151,   154,   436,   437,   438,   439,   102,
     986,   104,   100,    98,   154,   386,   388,   389,    10,    11,
     281,    45,    46,   280,   931,   935,   936,   937,   938,    10,
      11,   337,    51,    52,   336,   931,   935,   947,   948,   949,
     950,    88,    66,   159,   549,   904,   905,   551,   552,     6,
       6,     6,     6,   176,   178,   162,    92,   128,     6,   185,
     192,   488,   489,   490,   491,   505,   984,   512,   984,   519,
     984,     6,   524,   151,   154,   531,   532,   533,   534,   154,
     438,   440,   441,    10,    11,   391,   390,   931,   935,   947,
     180,     3,   152,     3,    30,   906,   964,    10,   556,    36,
      53,   553,   554,   555,   986,   986,   986,   986,   986,   192,
     490,   492,   202,   204,   200,   198,   154,   533,   535,   536,
      10,    11,   443,   442,   931,   935,   947,   152,   986,   986,
     986,    10,    11,   907,   908,   909,   175,   557,   558,   986,
       3,    10,    11,    41,    42,   493,   494,   495,   496,   927,
     928,   929,   930,   931,   939,   943,    10,    11,   538,   537,
     931,   935,   947,   152,     6,   160,   173,   910,   911,   912,
     913,   141,   573,   574,   559,   560,   561,   931,   939,   965,
       6,   986,     6,     7,   186,   497,   498,     3,   152,   986,
     160,   912,   914,   915,   211,   579,   580,    10,    11,   575,
     576,   577,    10,    11,   562,   563,   564,   561,   986,   186,
     986,    10,    11,   917,   918,   919,    21,   916,   927,   931,
     935,   955,   145,   690,   691,    28,   581,   962,     4,   142,
     578,   176,   179,   565,   566,   567,   568,    67,    69,    70,
     174,   920,   921,   922,   923,   924,   925,   986,   115,   786,
     787,    25,   692,   959,   986,    10,    11,   582,   583,   584,
     142,   176,   567,   569,   570,     5,   926,   174,   922,     6,
     157,   881,   882,    24,   788,   958,   986,    10,    11,   693,
     694,   695,     6,   205,   585,   586,   587,    10,    11,   572,
     571,   931,   939,    68,   986,   170,    27,   883,   961,   986,
      10,    11,   789,   790,   791,     6,   205,   696,   697,   698,
     986,   212,   207,   599,   600,    33,   588,   967,   180,   986,
      10,    11,   884,   885,   886,     6,   121,   792,   793,   794,
     986,   146,   109,   710,   711,    22,   699,   956,   109,   614,
     615,   601,   967,   986,    10,    11,   589,   590,   591,     6,
     155,   158,   887,   888,   889,   890,   986,   116,   109,   805,
     806,    16,   795,   951,   758,    10,    11,   712,   713,   714,
     986,    10,    11,   700,   701,   702,   662,    10,    11,   616,
     617,   618,    10,    11,   602,   603,   604,     6,   206,   209,
     592,   593,   594,   595,   986,   158,   889,   891,   892,   853,
      10,    11,   807,   808,   809,   986,    10,    11,   796,   797,
     798,   151,   759,   760,   107,   715,   716,   717,     6,   143,
     206,   703,   704,   705,   706,   151,   663,   664,   107,   619,
     620,   621,   208,   209,   605,   606,   607,   608,   986,   206,
     594,    37,   596,    10,    11,   894,   895,   896,   893,   927,
     931,   935,   955,   151,   854,   855,   107,   810,   811,   812,
       6,   113,   122,   799,   800,   801,   802,   761,   762,   110,
      93,   723,   724,    18,   718,   953,   986,   206,   705,    37,
     707,   665,   666,   110,    93,   627,   628,   622,   953,   208,
     607,    37,   609,   986,    10,   597,    67,    69,    70,   156,
     897,   898,   899,   900,   901,   902,   856,   857,   110,    93,
     818,   819,   813,   953,   986,   122,   801,    37,   803,    10,
      11,   764,   765,   766,    19,   763,   931,   935,   947,   954,
     956,    95,   730,   731,   725,   953,   986,    10,    11,   719,
     720,   721,   986,    10,   708,    10,    11,   668,   669,   670,
     667,   931,   935,   947,   954,   967,    95,   634,   635,   629,
     953,    10,    11,   623,   624,   625,   986,    10,    11,   610,
     611,   612,     6,     4,     6,     7,   985,     5,   903,   156,
     899,    10,    11,   859,   860,   861,   858,   931,   935,   947,
     951,   954,    95,   825,   826,   820,   953,    10,    11,   814,
     815,   816,   986,    10,   804,   125,   143,   152,   767,   768,
     769,   770,   776,   777,   778,   986,   137,   737,   738,   732,
     953,    10,    11,   726,   727,   728,     6,   105,   722,   969,
     970,   977,     6,     6,     7,   709,   125,   152,   209,   671,
     672,   673,   674,   680,   681,   682,   137,   641,   642,   636,
     953,    10,    11,   630,   631,   632,   626,   969,     6,     4,
     210,   613,   986,   598,    68,   113,   125,   152,   862,   863,
     864,   865,   871,   872,   873,   137,   832,   833,   827,   953,
      10,    11,   821,   822,   823,   817,   969,     6,   984,   152,
     769,    37,   771,   777,   779,   780,     6,   181,   744,   745,
     739,   953,    10,    11,   733,   734,   735,   729,   969,   986,
      40,   978,   108,   123,   971,   972,   986,   144,   152,   673,
      37,   675,   681,   683,   684,   181,   648,   649,   643,   953,
      10,    11,   637,   638,   639,   633,   969,   108,   986,   210,
     210,   152,   864,    37,   866,   872,   874,   875,   181,   839,
     840,   834,   953,    10,    11,   828,   829,   830,   824,   969,
     108,   986,   114,   986,    10,    11,   772,   773,   774,    10,
      11,   782,   783,   784,   781,   931,   947,   953,   986,   195,
     751,   752,   746,   953,    10,    11,   740,   741,   742,   736,
     969,    94,   986,    10,    11,   979,   980,   981,   973,   974,
     986,    10,    11,   676,   677,   678,    10,    11,   686,   687,
     688,   685,   931,   947,   953,   195,   655,   656,   650,   953,
      10,    11,   644,   645,   646,   640,   969,    94,   986,    10,
      11,   867,   868,   869,    10,    11,   877,   878,   879,   876,
     931,   947,   953,   195,   846,   847,   841,   953,    10,    11,
     835,   836,   837,   831,   969,    94,     6,   144,   775,   985,
     785,   969,   753,   953,    10,    11,   747,   748,   749,   743,
     969,    96,     6,     4,   106,    10,   976,    38,    39,   975,
     982,   983,     6,   210,   679,   985,   689,   969,   657,   953,
      10,    11,   651,   652,   653,   647,   969,    96,     6,   114,
     870,   985,   880,   969,   848,   953,    10,    11,   842,   843,
     844,   838,   969,    96,   986,   144,   126,    10,    11,   754,
     755,   756,   750,   969,   138,   986,   106,     6,   986,   986,
     986,   210,   126,    10,    11,   658,   659,   660,   654,   969,
     138,   986,   114,   126,    10,    11,   849,   850,   851,   845,
     969,   138,   757,   969,   182,   124,     6,     6,   661,   969,
     182,   852,   969,   182,   196,   986,   986,   196,   196
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData, osglData);
      fprintf (stderr, "\n");
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






/*----------.
| yyparse.  |
`----------*/

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
  yylloc.first_column = yylloc.last_column = 0;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
;}
    break;

  case 5:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 14:

    {
	if (osglData->fileName    != "" || osglData->source      != "" ||
		osglData->fileCreator != "" || osglData->description != "" ||
		osglData->licence     != "")
		if(!osresult->setResultHeader(osglData->fileName, osglData->source, 	
				osglData->description, 
osglData->fileCreator, osglData->licence) )	
			osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
;}
    break;

  case 15:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
;}
    break;

  case 27:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 34:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 41:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 48:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 55:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 77:

    {	if (parserData->generalStatusPresent)
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
	;}
    break;

  case 78:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 81:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	;}
    break;

  case 82:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 83:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 84:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 85:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 92:

    {	parserData->kounter++;
;}
    break;

  case 93:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 94:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
;}
    break;

  case 97:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	;}
    break;

  case 98:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	;}
    break;

  case 102:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 108:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 110:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 116:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 118:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 124:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 126:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 132:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 134:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 140:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 142:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 148:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 150:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 156:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 158:

    {	if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	;}
    break;

  case 159:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 160:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 161:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 168:

    {	parserData->kounter++;
;}
    break;

  case 169:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 170:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 173:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	;}
    break;

  case 174:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	;}
    break;

  case 175:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	;}
    break;

  case 196:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 202:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	;}
    break;

  case 204:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 208:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 209:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 211:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 213:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 217:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 218:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 220:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 222:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 226:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 227:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 229:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 231:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 233:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 235:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 237:

    {	if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	;}
    break;

  case 238:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 239:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 240:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 247:

    {	parserData->kounter++;
;}
    break;

  case 248:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 249:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 252:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	;}
    break;

  case 253:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	;}
    break;

  case 254:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	;}
    break;

  case 275:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 281:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 283:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 289:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 291:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 297:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 299:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 305:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 307:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 313:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
;}
    break;

  case 315:

    {	if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	;}
    break;

  case 316:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 317:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 318:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 325:

    {	parserData->kounter++;
;}
    break;

  case 326:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 327:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 330:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	;}
    break;

  case 331:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	;}
    break;

  case 332:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	;}
    break;

  case 358:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 364:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	;}
    break;

  case 366:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 372:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 374:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 380:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 382:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 388:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 390:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 396:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 398:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 399:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
;}
    break;

  case 400:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	;}
    break;

  case 401:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	;}
    break;

  case 409:

    {	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, osglData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "second";
	parserData->typeAttribute = "elapsedTime";
	parserData->categoryAttribute = "total";
	parserData->descriptionAttribute = "";
;}
    break;

  case 421:

    {	
	if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
			osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
	parserData->ivar++;
//	parserData->timeType = "elapsedTime";
//	parserData->timeCategory = "total";
//	parserData->timeUnit = "unit";
//	parserData->timeDescription = "";      
;}
    break;

  case 422:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 423:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 425:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 429:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 430:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 432:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 434:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 438:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 439:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 441:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 443:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 447:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 448:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 450:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 452:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 454:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 456:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 458:

    {	if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	;}
    break;

  case 459:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 460:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 461:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 468:

    {	parserData->kounter++;
;}
    break;

  case 469:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 470:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 473:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	;}
    break;

  case 474:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	;}
    break;

  case 475:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	;}
    break;

  case 480:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 481:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
;}
    break;

  case 484:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	;}
    break;

  case 485:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	;}
    break;

  case 486:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	;}
    break;

  case 487:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	;}
    break;

  case 488:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	;}
    break;

  case 489:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	;}
    break;

  case 497:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 503:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 ;}
    break;

  case 504:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr == "true")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else if (parserData->tempStr == "false")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else
		osrlerror(NULL, NULL, parserData, osglData, "weightedobjectives must be true or false");
;}
    break;

  case 505:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 507:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 508:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	;}
    break;

  case 511:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	;}
    break;

  case 512:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	;}
    break;

  case 513:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 514:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 515:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 522:

    {	parserData->kounter++; ;}
    break;

  case 523:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 524:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
;}
    break;

  case 527:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	;}
    break;

  case 528:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	;}
    break;

  case 539:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	;}
    break;

  case 542:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 544:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
;}
    break;

  case 553:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
;}
    break;

  case 554:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 555:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 562:

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 563:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 564:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 565:

    {/*aNumber*/;}
    break;

  case 570:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 571:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 572:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 579:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 580:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 581:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 582:

    {parserData->tempStr = "";;}
    break;

  case 587:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 597:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 599:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 606:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 608:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 615:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 617:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 624:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 626:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 633:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 635:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 642:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 644:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 652:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 653:

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
;}
    break;

  case 654:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 657:

    {	if (parserData->numberOfVarAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
		parserData->numberOfVarAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	;}
    break;

  case 658:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 659:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 660:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 661:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 671:

    { 	
	parserData->kounter++;
;}
    break;

  case 673:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
;}
    break;

  case 679:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 682:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 683:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 684:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 687:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 688:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 689:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 697:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 699:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 708:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 709:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 710:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 717:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 718:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 720:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 722:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 723:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 733:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 735:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 742:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 744:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 751:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 753:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 760:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 762:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 769:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 771:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 778:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 780:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 788:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 789:

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
;}
    break;

  case 790:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 793:

    {	if (parserData->numberOfObjAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
		parserData->numberOfObjAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	;}
    break;

  case 794:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 795:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 796:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 797:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 807:

    {  
	parserData->kounter++;
;}
    break;

  case 809:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
;}
    break;

  case 815:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 818:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 819:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 820:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 823:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 824:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 825:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 833:

    {	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 835:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 843:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 844:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 845:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 846:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 853:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 854:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
;}
    break;

  case 855:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 866:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 868:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 875:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 877:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 884:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 886:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 893:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 895:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 902:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 904:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 911:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 913:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 921:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 922:

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
;}
    break;

  case 923:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 926:

    {	if (parserData->numberOfConAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
		parserData->numberOfConAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	;}
    break;

  case 927:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 928:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 929:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 930:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 940:

    { 	
	parserData->kounter++;
;}
    break;

  case 942:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
;}
    break;

  case 948:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 951:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 952:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 953:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 956:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 957:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 958:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 966:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 967:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 968:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 969:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 976:

    {	parserData->iOther++;
;}
    break;

  case 977:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 978:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 981:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 982:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 983:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 984:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 985:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 986:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 993:

    {	parserData->kounter++;
;}
    break;

  case 994:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 999:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 1002:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 1003:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 1004:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 1005:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 1012:

    {	parserData->iOther++;
;}
    break;

  case 1013:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 1014:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 1017:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 1018:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 1019:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 1020:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 1021:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1022:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1029:

    {	parserData->kounter++;
;}
    break;

  case 1030:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1035:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 1036:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 1039:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 1040:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 1041:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 1044:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1045:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1046:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1049:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1050:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1051:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1054:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1055:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1056:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1059:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1060:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1061:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1064:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1065:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1066:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1067:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1068:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1069:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1070:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1071:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1072:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1073:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1074:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1075:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1076:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1077:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1078:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1079:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1080:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1081:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1082:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1083:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1084:

    {
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1089:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1095:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1097:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1102:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if( b64string == NULL) 
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data length does not match numberOfEl"); 
	intvec = (int*)&base64decodeddata[0];
	for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete [] b64string;
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1103:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1104:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1105:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1106:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1107:

    {parserData->tempVal =  OSDBL_MAX;;}
    break;

  case 1108:

    {parserData->tempVal = -OSDBL_MAX;;}
    break;

  case 1109:

    {parserData->tempVal = OSNAN;;}
    break;

  case 1110:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1111:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1112:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); ;}
    break;


/* Line 1267 of yacc.c.  */

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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osresult, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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
	osrl_empty_vectors( parserData);
	osgl_empty_vectors(	osglData);
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

void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass){
	try{
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
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult


void osrl_empty_vectors( OSrLParserData* parserData){

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
}//end osrl_empty_vectors

//void osgl_empty_vectors( OSgLParserData* osglData){
//	if (osglData->osglIntArray != NULL)
//		delete[] osglData->osglIntArray;
//}//end osgl_empty_vectors

