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
     GENERALSTART = 310,
     GENERALEND = 311,
     SYSTEMSTART = 312,
     SYSTEMEND = 313,
     SERVICESTART = 314,
     SERVICEEND = 315,
     JOBSTART = 316,
     JOBEND = 317,
     OPTIMIZATIONSTART = 318,
     OPTIMIZATIONEND = 319,
     ITEMSTART = 320,
     ITEMEND = 321,
     ITEMSTARTANDEND = 322,
     ITEMEMPTY = 323,
     ACTUALSTARTTIMESTART = 324,
     ACTUALSTARTTIMEEND = 325,
     ATLOWERSTART = 326,
     ATLOWEREND = 327,
     ATUPPERSTART = 328,
     ATUPPEREND = 329,
     AVAILABLECPUNUMBERSTART = 330,
     AVAILABLECPUNUMBEREND = 331,
     AVAILABLECPUSPEEDSTART = 332,
     AVAILABLECPUSPEEDEND = 333,
     AVAILABLEDISKSPACESTART = 334,
     AVAILABLEDISKSPACEEND = 335,
     AVAILABLEMEMORYSTART = 336,
     AVAILABLEMEMORYEND = 337,
     BASE64START = 338,
     BASE64END = 339,
     BASICSTART = 340,
     BASICEND = 341,
     BASISSTATUSSTART = 342,
     BASISSTATUSEND = 343,
     BASSTATUSSTART = 344,
     BASSTATUSEND = 345,
     CONSTART = 346,
     CONEND = 347,
     CONSTRAINTSSTART = 348,
     CONSTRAINTSEND = 349,
     CURRENTJOBCOUNTSTART = 350,
     CURRENTJOBCOUNTEND = 351,
     CURRENTSTATESTART = 352,
     CURRENTSTATEEND = 353,
     DUALVALUESSTART = 354,
     DUALVALUESEND = 355,
     ELSTART = 356,
     ELEND = 357,
     ENUMERATIONSTART = 358,
     ENUMERATIONEND = 359,
     ENDTIMESTART = 360,
     ENDTIMEEND = 361,
     GENERALSTATUSSTART = 362,
     GENERALSTATUSEND = 363,
     GENERALSUBSTATUSSTART = 364,
     GENERALSUBSTATUSEND = 365,
     IDXSTART = 366,
     IDXEND = 367,
     INSTANCENAMESTART = 368,
     INSTANCENAMEEND = 369,
     ISFREESTART = 370,
     ISFREEEND = 371,
     JOBIDSTART = 372,
     JOBIDEND = 373,
     MESSAGESTART = 374,
     MESSAGEEND = 375,
     OBJSTART = 376,
     OBJEND = 377,
     OBJECTIVESSTART = 378,
     OBJECTIVESEND = 379,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 380,
     OPTIMIZATIONSOLUTIONSTATUSEND = 381,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 382,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 383,
     OTHERSTART = 384,
     OTHEREND = 385,
     OTHERRESULTSSTART = 386,
     OTHERRESULTSEND = 387,
     OTHERSOLUTIONRESULTSTART = 388,
     OTHERSOLUTIONRESULTEND = 389,
     OTHERSOLUTIONRESULTSSTART = 390,
     OTHERSOLUTIONRESULTSEND = 391,
     OTHERSOLVEROUTPUTSTART = 392,
     OTHERSOLVEROUTPUTEND = 393,
     SCHEDULEDSTARTTIMESTART = 394,
     SCHEDULEDSTARTTIMEEND = 395,
     SERVICENAMESTART = 396,
     SERVICENAMEEND = 397,
     SERVICEURISTART = 398,
     SERVICEURIEND = 399,
     SERVICEUTILIZATIONSTART = 400,
     SERVICEUTILIZATIONEND = 401,
     SOLUTIONSTART = 402,
     SOLUTIONEND = 403,
     SOLVERINVOKEDSTART = 404,
     SOLVERINVOKEDEND = 405,
     SOLVEROUTPUTSTART = 406,
     SOLVEROUTPUTEND = 407,
     STATUSSTART = 408,
     STATUSEND = 409,
     SUBMITTIMESTART = 410,
     SUBMITTIMEEND = 411,
     SUBSTATUSSTART = 412,
     SUBSTATUSEND = 413,
     SUPERBASICSTART = 414,
     SUPERBASICEND = 415,
     SYSTEMINFORMATIONSTART = 416,
     SYSTEMINFORMATIONEND = 417,
     TIMESTART = 418,
     TIMEEND = 419,
     TIMESERVICESTARTEDSTART = 420,
     TIMESERVICESTARTEDEND = 421,
     TIMESTAMPSTART = 422,
     TIMESTAMPEND = 423,
     TIMINGINFORMATIONSTART = 424,
     TIMINGINFORMATIONEND = 425,
     TOTALJOBSSOFARSTART = 426,
     TOTALJOBSSOFAREND = 427,
     UNKNOWNSTART = 428,
     UNKNOWNEND = 429,
     USEDCPUNUMBERSTART = 430,
     USEDCPUNUMBEREND = 431,
     USEDCPUSPEEDSTART = 432,
     USEDCPUSPEEDEND = 433,
     USEDDISKSPACESTART = 434,
     USEDDISKSPACEEND = 435,
     USEDMEMORYSTART = 436,
     USEDMEMORYEND = 437,
     VALUESSTART = 438,
     VALUESEND = 439,
     VALUESSTRINGSTART = 440,
     VALUESSTRINGEND = 441,
     VARSTART = 442,
     VAREND = 443,
     VARIABLESSTART = 444,
     VARIABLESEND = 445,
     VARIDXSTART = 446,
     VARIDXEND = 447,
     DUMMY = 448
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
#define GENERALSTART 310
#define GENERALEND 311
#define SYSTEMSTART 312
#define SYSTEMEND 313
#define SERVICESTART 314
#define SERVICEEND 315
#define JOBSTART 316
#define JOBEND 317
#define OPTIMIZATIONSTART 318
#define OPTIMIZATIONEND 319
#define ITEMSTART 320
#define ITEMEND 321
#define ITEMSTARTANDEND 322
#define ITEMEMPTY 323
#define ACTUALSTARTTIMESTART 324
#define ACTUALSTARTTIMEEND 325
#define ATLOWERSTART 326
#define ATLOWEREND 327
#define ATUPPERSTART 328
#define ATUPPEREND 329
#define AVAILABLECPUNUMBERSTART 330
#define AVAILABLECPUNUMBEREND 331
#define AVAILABLECPUSPEEDSTART 332
#define AVAILABLECPUSPEEDEND 333
#define AVAILABLEDISKSPACESTART 334
#define AVAILABLEDISKSPACEEND 335
#define AVAILABLEMEMORYSTART 336
#define AVAILABLEMEMORYEND 337
#define BASE64START 338
#define BASE64END 339
#define BASICSTART 340
#define BASICEND 341
#define BASISSTATUSSTART 342
#define BASISSTATUSEND 343
#define BASSTATUSSTART 344
#define BASSTATUSEND 345
#define CONSTART 346
#define CONEND 347
#define CONSTRAINTSSTART 348
#define CONSTRAINTSEND 349
#define CURRENTJOBCOUNTSTART 350
#define CURRENTJOBCOUNTEND 351
#define CURRENTSTATESTART 352
#define CURRENTSTATEEND 353
#define DUALVALUESSTART 354
#define DUALVALUESEND 355
#define ELSTART 356
#define ELEND 357
#define ENUMERATIONSTART 358
#define ENUMERATIONEND 359
#define ENDTIMESTART 360
#define ENDTIMEEND 361
#define GENERALSTATUSSTART 362
#define GENERALSTATUSEND 363
#define GENERALSUBSTATUSSTART 364
#define GENERALSUBSTATUSEND 365
#define IDXSTART 366
#define IDXEND 367
#define INSTANCENAMESTART 368
#define INSTANCENAMEEND 369
#define ISFREESTART 370
#define ISFREEEND 371
#define JOBIDSTART 372
#define JOBIDEND 373
#define MESSAGESTART 374
#define MESSAGEEND 375
#define OBJSTART 376
#define OBJEND 377
#define OBJECTIVESSTART 378
#define OBJECTIVESEND 379
#define OPTIMIZATIONSOLUTIONSTATUSSTART 380
#define OPTIMIZATIONSOLUTIONSTATUSEND 381
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 382
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 383
#define OTHERSTART 384
#define OTHEREND 385
#define OTHERRESULTSSTART 386
#define OTHERRESULTSEND 387
#define OTHERSOLUTIONRESULTSTART 388
#define OTHERSOLUTIONRESULTEND 389
#define OTHERSOLUTIONRESULTSSTART 390
#define OTHERSOLUTIONRESULTSEND 391
#define OTHERSOLVEROUTPUTSTART 392
#define OTHERSOLVEROUTPUTEND 393
#define SCHEDULEDSTARTTIMESTART 394
#define SCHEDULEDSTARTTIMEEND 395
#define SERVICENAMESTART 396
#define SERVICENAMEEND 397
#define SERVICEURISTART 398
#define SERVICEURIEND 399
#define SERVICEUTILIZATIONSTART 400
#define SERVICEUTILIZATIONEND 401
#define SOLUTIONSTART 402
#define SOLUTIONEND 403
#define SOLVERINVOKEDSTART 404
#define SOLVERINVOKEDEND 405
#define SOLVEROUTPUTSTART 406
#define SOLVEROUTPUTEND 407
#define STATUSSTART 408
#define STATUSEND 409
#define SUBMITTIMESTART 410
#define SUBMITTIMEEND 411
#define SUBSTATUSSTART 412
#define SUBSTATUSEND 413
#define SUPERBASICSTART 414
#define SUPERBASICEND 415
#define SYSTEMINFORMATIONSTART 416
#define SYSTEMINFORMATIONEND 417
#define TIMESTART 418
#define TIMEEND 419
#define TIMESERVICESTARTEDSTART 420
#define TIMESERVICESTARTEDEND 421
#define TIMESTAMPSTART 422
#define TIMESTAMPEND 423
#define TIMINGINFORMATIONSTART 424
#define TIMINGINFORMATIONEND 425
#define TOTALJOBSSOFARSTART 426
#define TOTALJOBSSOFAREND 427
#define UNKNOWNSTART 428
#define UNKNOWNEND 429
#define USEDCPUNUMBERSTART 430
#define USEDCPUNUMBEREND 431
#define USEDCPUSPEEDSTART 432
#define USEDCPUSPEEDEND 433
#define USEDDISKSPACESTART 434
#define USEDDISKSPACEEND 435
#define USEDMEMORYSTART 436
#define USEDMEMORYEND 437
#define VALUESSTART 438
#define VALUESEND 439
#define VALUESSTRINGSTART 440
#define VALUESSTRINGEND 441
#define VARSTART 442
#define VAREND 443
#define VARIABLESSTART 444
#define VARIABLESEND 445
#define VARIDXSTART 446
#define VARIDXEND 447
#define DUMMY 448




/* Copy the first part of user declarations.  */



 
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSConfig.h"
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
#define YYLAST   1327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  198
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  739
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1072
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1490

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   448

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   195,
     197,     2,     2,   196,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   194,     2,     2,     2,     2,     2,     2,     2,
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
     185,   186,   187,   188,   189,   190,   191,   192,   193
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    34,    35,    38,    40,    42,    44,    47,
      49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
      72,    74,    76,    78,    82,    84,    86,    88,    91,    93,
      95,    97,    99,   101,   104,   106,   110,   112,   114,   117,
     121,   123,   125,   126,   129,   131,   133,   136,   138,   141,
     143,   145,   147,   150,   152,   156,   158,   161,   163,   165,
     167,   170,   172,   176,   178,   181,   183,   185,   187,   190,
     192,   196,   198,   201,   203,   205,   207,   210,   212,   216,
     218,   221,   223,   225,   227,   230,   232,   236,   238,   241,
     243,   245,   247,   250,   252,   256,   258,   261,   263,   265,
     267,   270,   272,   276,   278,   282,   284,   286,   288,   290,
     293,   295,   299,   301,   303,   306,   310,   312,   314,   315,
     318,   320,   322,   324,   327,   329,   330,   333,   335,   337,
     339,   342,   344,   348,   350,   352,   355,   357,   359,   361,
     363,   365,   367,   370,   372,   374,   376,   379,   381,   385,
     387,   391,   393,   395,   396,   399,   401,   403,   407,   409,
     413,   415,   417,   418,   421,   423,   425,   429,   431,   435,
     437,   439,   440,   443,   445,   447,   451,   453,   457,   459,
     460,   462,   466,   468,   472,   474,   476,   478,   480,   483,
     485,   489,   491,   493,   496,   500,   502,   504,   505,   508,
     510,   512,   514,   517,   519,   520,   523,   525,   527,   529,
     532,   534,   538,   540,   542,   545,   547,   549,   551,   553,
     555,   557,   560,   562,   564,   566,   569,   571,   575,   577,
     580,   582,   584,   586,   589,   591,   595,   597,   600,   602,
     604,   606,   609,   611,   615,   617,   620,   622,   624,   626,
     629,   631,   635,   637,   640,   642,   644,   646,   649,   651,
     655,   657,   661,   663,   665,   667,   669,   672,   674,   678,
     680,   682,   685,   689,   691,   693,   694,   697,   699,   701,
     703,   706,   708,   709,   712,   714,   716,   718,   721,   723,
     727,   729,   731,   734,   736,   738,   740,   742,   744,   746,
     748,   750,   752,   754,   756,   759,   761,   763,   765,   768,
     770,   774,   776,   779,   781,   783,   785,   788,   790,   794,
     796,   799,   801,   803,   805,   808,   810,   814,   816,   819,
     821,   823,   825,   828,   830,   834,   836,   839,   841,   843,
     845,   848,   850,   854,   856,   860,   862,   864,   866,   868,
     871,   873,   877,   879,   881,   884,   888,   890,   891,   894,
     896,   898,   900,   902,   904,   906,   909,   911,   915,   917,
     919,   921,   925,   927,   929,   930,   933,   935,   937,   941,
     943,   947,   949,   951,   952,   955,   957,   959,   963,   965,
     969,   971,   973,   974,   977,   979,   981,   985,   987,   991,
     993,   994,   996,  1000,  1002,  1006,  1008,  1010,  1012,  1014,
    1017,  1019,  1023,  1025,  1027,  1030,  1034,  1036,  1038,  1039,
    1042,  1044,  1046,  1048,  1051,  1053,  1054,  1058,  1060,  1062,
    1063,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1081,  1083,
    1087,  1090,  1092,  1095,  1099,  1101,  1103,  1104,  1107,  1109,
    1111,  1116,  1120,  1129,  1133,  1135,  1137,  1139,  1142,  1144,
    1146,  1148,  1150,  1152,  1155,  1157,  1161,  1163,  1165,  1168,
    1172,  1174,  1176,  1177,  1180,  1182,  1184,  1187,  1189,  1190,
    1193,  1195,  1197,  1199,  1202,  1204,  1208,  1210,  1211,  1215,
    1217,  1218,  1220,  1222,  1224,  1226,  1230,  1235,  1236,  1240,
    1242,  1244,  1246,  1248,  1251,  1253,  1257,  1259,  1261,  1264,
    1268,  1270,  1275,  1279,  1280,  1284,  1286,  1288,  1290,  1292,
    1295,  1297,  1301,  1303,  1305,  1308,  1312,  1314,  1319,  1321,
    1323,  1326,  1328,  1332,  1334,  1335,  1338,  1340,  1342,  1344,
    1346,  1350,  1357,  1358,  1362,  1364,  1366,  1368,  1370,  1372,
    1376,  1378,  1379,  1383,  1385,  1387,  1389,  1391,  1393,  1397,
    1399,  1400,  1404,  1406,  1408,  1410,  1412,  1414,  1418,  1420,
    1421,  1425,  1427,  1429,  1431,  1433,  1435,  1439,  1441,  1442,
    1446,  1448,  1450,  1452,  1454,  1456,  1460,  1462,  1463,  1467,
    1469,  1471,  1473,  1475,  1477,  1481,  1483,  1484,  1487,  1491,
    1493,  1495,  1496,  1499,  1501,  1503,  1505,  1507,  1509,  1511,
    1513,  1516,  1518,  1522,  1524,  1526,  1528,  1531,  1535,  1537,
    1542,  1544,  1546,  1549,  1551,  1555,  1557,  1559,  1562,  1566,
    1568,  1570,  1571,  1574,  1576,  1578,  1580,  1582,  1584,  1586,
    1590,  1592,  1593,  1597,  1599,  1600,  1602,  1604,  1606,  1608,
    1612,  1616,  1617,  1621,  1623,  1625,  1627,  1629,  1632,  1634,
    1638,  1640,  1642,  1645,  1649,  1651,  1652,  1657,  1661,  1663,
    1665,  1666,  1669,  1671,  1673,  1675,  1677,  1681,  1688,  1689,
    1693,  1695,  1697,  1699,  1701,  1703,  1707,  1709,  1710,  1714,
    1716,  1718,  1720,  1722,  1724,  1728,  1730,  1731,  1735,  1737,
    1739,  1741,  1743,  1745,  1749,  1751,  1752,  1756,  1758,  1760,
    1762,  1764,  1766,  1770,  1772,  1773,  1777,  1779,  1781,  1783,
    1785,  1787,  1791,  1793,  1794,  1798,  1800,  1802,  1804,  1806,
    1808,  1812,  1814,  1815,  1818,  1822,  1824,  1826,  1827,  1830,
    1832,  1834,  1836,  1838,  1840,  1842,  1844,  1847,  1849,  1853,
    1855,  1857,  1859,  1862,  1866,  1868,  1873,  1875,  1877,  1880,
    1882,  1886,  1888,  1890,  1893,  1897,  1899,  1901,  1902,  1905,
    1907,  1909,  1911,  1913,  1915,  1917,  1921,  1923,  1924,  1928,
    1930,  1931,  1933,  1935,  1937,  1939,  1943,  1947,  1948,  1952,
    1954,  1956,  1958,  1960,  1963,  1965,  1969,  1971,  1973,  1976,
    1980,  1982,  1987,  1991,  1992,  1995,  1997,  1999,  2001,  2003,
    2007,  2014,  2015,  2019,  2021,  2023,  2025,  2027,  2029,  2033,
    2035,  2036,  2040,  2042,  2044,  2046,  2048,  2050,  2054,  2056,
    2057,  2061,  2063,  2065,  2067,  2069,  2071,  2075,  2077,  2078,
    2082,  2084,  2086,  2088,  2090,  2092,  2096,  2098,  2099,  2103,
    2105,  2107,  2109,  2111,  2113,  2117,  2119,  2120,  2124,  2126,
    2128,  2130,  2132,  2134,  2138,  2140,  2141,  2144,  2148,  2150,
    2152,  2153,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,
    2173,  2175,  2179,  2181,  2183,  2185,  2188,  2192,  2194,  2199,
    2201,  2203,  2206,  2208,  2212,  2214,  2216,  2219,  2223,  2225,
    2227,  2228,  2231,  2233,  2235,  2237,  2239,  2241,  2243,  2247,
    2249,  2250,  2254,  2256,  2258,  2260,  2262,  2265,  2267,  2271,
    2273,  2275,  2278,  2282,  2284,  2286,  2287,  2290,  2292,  2294,
    2296,  2298,  2300,  2302,  2305,  2307,  2311,  2313,  2315,  2318,
    2320,  2322,  2324,  2326,  2328,  2332,  2334,  2335,  2339,  2341,
    2343,  2345,  2347,  2350,  2352,  2356,  2358,  2360,  2363,  2367,
    2369,  2371,  2372,  2375,  2377,  2379,  2381,  2383,  2385,  2387,
    2390,  2392,  2396,  2398,  2400,  2403,  2405,  2407,  2409,  2411,
    2413,  2417,  2419,  2421,  2423,  2425,  2427,  2431,  2433,  2435,
    2437,  2439,  2443,  2445,  2447,  2449,  2451,  2455,  2457,  2459,
    2461,  2463,  2467,  2469,  2471,  2473,  2475,  2479,  2481,  2483,
    2485,  2487,  2491,  2496,  2501,  2506,  2511,  2516,  2521,  2526,
    2531,  2536,  2541,  2546,  2551,  2556,  2561,  2566,  2571,  2576,
    2581,  2583,  2585,  2586,  2589,  2593,  2595,  2597,  2598,  2601,
    2603,  2605,  2609,  2613,  2618,  2620,  2622,  2625,  2627,  2631,
    2636,  2641,  2643,  2645,  2647,  2649,  2651,  2654,  2655,  2658,
    2660,  2662,  2664
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     199,     0,    -1,   200,   206,    15,    -1,   201,   202,   203,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   204,    -1,
     205,    -1,    11,    -1,    10,   206,    15,    -1,   207,   287,
     341,   393,   488,    -1,    -1,   208,   209,    -1,    55,    -1,
     210,    -1,   211,    -1,    10,    56,    -1,    11,    -1,    10,
     212,    56,    -1,   213,    -1,   214,    -1,   213,   214,    -1,
     215,    -1,   231,    -1,   237,    -1,   243,    -1,   249,    -1,
     255,    -1,   261,    -1,   267,    -1,   273,    -1,   216,   217,
     220,    -1,   107,    -1,   218,    -1,   219,    -1,   218,   219,
      -1,   887,    -1,   879,    -1,   913,    -1,   221,    -1,   222,
      -1,    10,   108,    -1,    11,    -1,    10,   223,   108,    -1,
     224,    -1,   225,    -1,   224,   225,    -1,   226,   227,   230,
      -1,   157,    -1,   228,    -1,    -1,   228,   229,    -1,   883,
      -1,   879,    -1,    10,   158,    -1,    11,    -1,   232,   233,
      -1,   119,    -1,   234,    -1,   235,    -1,    10,   120,    -1,
      11,    -1,    10,   236,   120,    -1,     4,    -1,   238,   239,
      -1,   143,    -1,   240,    -1,   241,    -1,    10,   144,    -1,
      11,    -1,    10,   242,   144,    -1,     4,    -1,   244,   245,
      -1,   141,    -1,   246,    -1,   247,    -1,    10,   142,    -1,
      11,    -1,    10,   248,   142,    -1,     4,    -1,   250,   251,
      -1,   113,    -1,   252,    -1,   253,    -1,    10,   114,    -1,
      11,    -1,    10,   254,   114,    -1,     4,    -1,   256,   257,
      -1,   117,    -1,   258,    -1,   259,    -1,    10,   118,    -1,
      11,    -1,    10,   260,   118,    -1,     4,    -1,   262,   263,
      -1,   149,    -1,   264,    -1,   265,    -1,    10,   150,    -1,
      11,    -1,    10,   266,   150,    -1,     4,    -1,   268,   269,
      -1,   167,    -1,   270,    -1,   271,    -1,    10,   168,    -1,
      11,    -1,    10,   272,   168,    -1,     4,    -1,   274,   275,
     276,    -1,   131,    -1,   908,    -1,   277,    -1,   278,    -1,
      10,   132,    -1,    11,    -1,    10,   279,   132,    -1,   280,
      -1,   281,    -1,   280,   281,    -1,   282,   283,   286,    -1,
     129,    -1,   284,    -1,    -1,   284,   285,    -1,   883,    -1,
     895,    -1,   879,    -1,    10,   130,    -1,    11,    -1,    -1,
     288,   289,    -1,    57,    -1,   290,    -1,   291,    -1,    10,
      58,    -1,    11,    -1,    10,   292,    58,    -1,   293,    -1,
     294,    -1,   293,   294,    -1,   295,    -1,   301,    -1,   308,
      -1,   315,    -1,   322,    -1,   327,    -1,   296,   297,    -1,
     161,    -1,   298,    -1,   299,    -1,    10,   162,    -1,    11,
      -1,    10,   300,   162,    -1,     4,    -1,   302,   303,   306,
      -1,    79,    -1,   304,    -1,    -1,   304,   305,    -1,   891,
      -1,   879,    -1,    10,   307,    80,    -1,   932,    -1,   309,
     310,   313,    -1,    81,    -1,   311,    -1,    -1,   311,   312,
      -1,   891,    -1,   879,    -1,    10,   314,    82,    -1,   932,
      -1,   316,   317,   320,    -1,    77,    -1,   318,    -1,    -1,
     318,   319,    -1,   891,    -1,   879,    -1,    10,   321,    78,
      -1,   932,    -1,   323,   324,   325,    -1,    75,    -1,    -1,
     879,    -1,    10,   326,    76,    -1,     6,    -1,   328,   329,
     330,    -1,   131,    -1,   908,    -1,   331,    -1,   332,    -1,
      10,   132,    -1,    11,    -1,    10,   333,   132,    -1,   334,
      -1,   335,    -1,   334,   335,    -1,   336,   337,   340,    -1,
     129,    -1,   338,    -1,    -1,   338,   339,    -1,   883,    -1,
     895,    -1,   879,    -1,    10,   130,    -1,    11,    -1,    -1,
     342,   343,    -1,    59,    -1,   344,    -1,   345,    -1,    10,
      60,    -1,    11,    -1,    10,   346,    60,    -1,   347,    -1,
     348,    -1,   347,   348,    -1,   349,    -1,   355,    -1,   361,
      -1,   367,    -1,   373,    -1,   379,    -1,   350,   351,    -1,
      97,    -1,   352,    -1,   353,    -1,    10,    98,    -1,    11,
      -1,    10,   354,    98,    -1,     4,    -1,   356,   357,    -1,
      95,    -1,   358,    -1,   359,    -1,    10,    96,    -1,    11,
      -1,    10,   360,    96,    -1,     6,    -1,   362,   363,    -1,
     171,    -1,   364,    -1,   365,    -1,    10,   172,    -1,    11,
      -1,    10,   366,   172,    -1,     6,    -1,   368,   369,    -1,
     165,    -1,   370,    -1,   371,    -1,    10,   166,    -1,    11,
      -1,    10,   372,   166,    -1,     4,    -1,   374,   375,    -1,
     145,    -1,   376,    -1,   377,    -1,    10,   146,    -1,    11,
      -1,    10,   378,   146,    -1,   932,    -1,   380,   381,   382,
      -1,   131,    -1,   908,    -1,   383,    -1,   384,    -1,    10,
     132,    -1,    11,    -1,    10,   385,   132,    -1,   386,    -1,
     387,    -1,   386,   387,    -1,   388,   389,   392,    -1,   129,
      -1,   390,    -1,    -1,   390,   391,    -1,   883,    -1,   895,
      -1,   879,    -1,    10,   130,    -1,    11,    -1,    -1,   394,
     395,    -1,    61,    -1,   396,    -1,   397,    -1,    10,    62,
      -1,    11,    -1,    10,   398,    62,    -1,   399,    -1,   400,
      -1,   399,   400,    -1,   401,    -1,   407,    -1,   413,    -1,
     419,    -1,   425,    -1,   431,    -1,   448,    -1,   455,    -1,
     462,    -1,   469,    -1,   474,    -1,   402,   403,    -1,   153,
      -1,   404,    -1,   405,    -1,    10,   154,    -1,    11,    -1,
      10,   406,   154,    -1,     4,    -1,   408,   409,    -1,   155,
      -1,   410,    -1,   411,    -1,    10,   156,    -1,    11,    -1,
      10,   412,   156,    -1,     4,    -1,   414,   415,    -1,   139,
      -1,   416,    -1,   417,    -1,    10,   140,    -1,    11,    -1,
      10,   418,   140,    -1,     4,    -1,   420,   421,    -1,    69,
      -1,   422,    -1,   423,    -1,    10,    70,    -1,    11,    -1,
      10,   424,    70,    -1,     4,    -1,   426,   427,    -1,   105,
      -1,   428,    -1,   429,    -1,    10,   106,    -1,    11,    -1,
      10,   430,   106,    -1,     4,    -1,   432,   433,   434,    -1,
     169,    -1,   914,    -1,   435,    -1,   436,    -1,    10,   170,
      -1,    11,    -1,    10,   437,   170,    -1,   438,    -1,   439,
      -1,   438,   439,    -1,   440,   441,   443,    -1,   163,    -1,
      -1,   441,   442,    -1,   891,    -1,   887,    -1,   875,    -1,
     879,    -1,   444,    -1,   445,    -1,    10,   164,    -1,    11,
      -1,    10,   446,   164,    -1,   447,    -1,     7,    -1,     6,
      -1,   449,   450,   453,    -1,   179,    -1,   451,    -1,    -1,
     451,   452,    -1,   891,    -1,   879,    -1,    10,   454,   180,
      -1,   932,    -1,   456,   457,   460,    -1,   181,    -1,   458,
      -1,    -1,   458,   459,    -1,   891,    -1,   879,    -1,    10,
     461,   182,    -1,   932,    -1,   463,   464,   467,    -1,   177,
      -1,   465,    -1,    -1,   465,   466,    -1,   891,    -1,   879,
      -1,    10,   468,   178,    -1,   932,    -1,   470,   471,   472,
      -1,   175,    -1,    -1,   879,    -1,    10,   473,   176,    -1,
       6,    -1,   475,   476,   477,    -1,   131,    -1,   908,    -1,
     478,    -1,   479,    -1,    10,   132,    -1,    11,    -1,    10,
     480,   132,    -1,   481,    -1,   482,    -1,   481,   482,    -1,
     483,   484,   487,    -1,   129,    -1,   485,    -1,    -1,   485,
     486,    -1,   883,    -1,   895,    -1,   879,    -1,    10,   130,
      -1,    11,    -1,    -1,   489,   490,   493,    -1,    63,    -1,
     491,    -1,    -1,   491,   492,    -1,   911,    -1,   916,    -1,
     900,    -1,   905,    -1,   494,    -1,   495,    -1,    10,    64,
      -1,    11,    -1,    10,   496,    64,    -1,   497,   852,    -1,
     498,    -1,   497,   498,    -1,   499,   500,   505,    -1,   147,
      -1,   501,    -1,    -1,   501,   502,    -1,   503,    -1,   504,
      -1,    36,   934,     6,   934,    -1,    53,     3,   934,    -1,
      10,   506,   522,   528,   638,   734,   829,   148,    -1,   507,
     508,   511,    -1,   153,    -1,   509,    -1,   510,    -1,   509,
     510,    -1,   887,    -1,   879,    -1,   913,    -1,   512,    -1,
     513,    -1,    10,   154,    -1,    11,    -1,    10,   514,   154,
      -1,   515,    -1,   516,    -1,   515,   516,    -1,   517,   518,
     521,    -1,   157,    -1,   519,    -1,    -1,   519,   520,    -1,
     887,    -1,   879,    -1,    10,   158,    -1,    11,    -1,    -1,
     523,   524,    -1,   119,    -1,   525,    -1,   526,    -1,    10,
     120,    -1,    11,    -1,    10,   527,   120,    -1,     4,    -1,
      -1,   529,   530,   531,    -1,   189,    -1,    -1,   910,    -1,
     532,    -1,   533,    -1,    11,    -1,    10,   534,   190,    -1,
     535,   547,   562,   610,    -1,    -1,   536,   537,   538,    -1,
     183,    -1,   915,    -1,   539,    -1,   540,    -1,    10,   184,
      -1,    11,    -1,    10,   541,   184,    -1,   542,    -1,   543,
      -1,   542,   543,    -1,   544,   545,   546,    -1,   187,    -1,
      37,   934,     6,   934,    -1,    10,   932,   188,    -1,    -1,
     548,   549,   550,    -1,   185,    -1,   915,    -1,   551,    -1,
     552,    -1,    10,   186,    -1,    11,    -1,    10,   553,   186,
      -1,   554,    -1,   555,    -1,   554,   555,    -1,   556,   557,
     558,    -1,   187,    -1,    37,   934,     6,   934,    -1,   559,
      -1,   560,    -1,    10,   188,    -1,    11,    -1,    10,   561,
     188,    -1,     4,    -1,    -1,   563,   564,    -1,    87,    -1,
     565,    -1,   566,    -1,    11,    -1,    10,   567,    88,    -1,
     568,   575,   582,   589,   596,   603,    -1,    -1,   569,   570,
     571,    -1,    85,    -1,   901,    -1,   572,    -1,   573,    -1,
      11,    -1,    10,   574,    86,    -1,   917,    -1,    -1,   576,
     577,   578,    -1,    71,    -1,   901,    -1,   579,    -1,   580,
      -1,    11,    -1,    10,   581,    72,    -1,   917,    -1,    -1,
     583,   584,   585,    -1,    73,    -1,   901,    -1,   586,    -1,
     587,    -1,    11,    -1,    10,   588,    74,    -1,   917,    -1,
      -1,   590,   591,   592,    -1,   115,    -1,   901,    -1,   593,
      -1,   594,    -1,    11,    -1,    10,   595,   116,    -1,   917,
      -1,    -1,   597,   598,   599,    -1,   159,    -1,   901,    -1,
     600,    -1,   601,    -1,    11,    -1,    10,   602,   160,    -1,
     917,    -1,    -1,   604,   605,   606,    -1,   173,    -1,   901,
      -1,   607,    -1,   608,    -1,    11,    -1,    10,   609,   174,
      -1,   917,    -1,    -1,   610,   611,    -1,   612,   613,   616,
      -1,   129,    -1,   614,    -1,    -1,   614,   615,    -1,   915,
      -1,   902,    -1,   895,    -1,   883,    -1,   879,    -1,   617,
      -1,   618,    -1,    10,   130,    -1,    11,    -1,    10,   619,
     130,    -1,   620,    -1,   628,    -1,   621,    -1,   620,   621,
      -1,   622,   623,   624,    -1,   187,    -1,    37,   934,     6,
     934,    -1,   625,    -1,   626,    -1,    10,   188,    -1,    11,
      -1,    10,   627,   188,    -1,   933,    -1,   629,    -1,   628,
     629,    -1,   630,   631,   634,    -1,   103,    -1,   632,    -1,
      -1,   632,   633,    -1,   901,    -1,   895,    -1,   879,    -1,
     635,    -1,   636,    -1,    11,    -1,    10,   637,   104,    -1,
     917,    -1,    -1,   639,   640,   641,    -1,   123,    -1,    -1,
     907,    -1,   642,    -1,   643,    -1,    11,    -1,    10,   644,
     124,    -1,   645,   658,   706,    -1,    -1,   646,   647,   648,
      -1,   183,    -1,   904,    -1,   649,    -1,   650,    -1,    10,
     184,    -1,    11,    -1,    10,   651,   184,    -1,   652,    -1,
     653,    -1,   652,   653,    -1,   654,   655,   656,    -1,   121,
      -1,    -1,    37,   934,     6,   934,    -1,    10,   657,   122,
      -1,     6,    -1,     7,    -1,    -1,   659,   660,    -1,    87,
      -1,   661,    -1,   662,    -1,    11,    -1,    10,   663,    88,
      -1,   664,   671,   678,   685,   692,   699,    -1,    -1,   665,
     666,   667,    -1,    85,    -1,   901,    -1,   668,    -1,   669,
      -1,    11,    -1,    10,   670,    86,    -1,   917,    -1,    -1,
     672,   673,   674,    -1,    71,    -1,   901,    -1,   675,    -1,
     676,    -1,    11,    -1,    10,   677,    72,    -1,   917,    -1,
      -1,   679,   680,   681,    -1,    73,    -1,   901,    -1,   682,
      -1,   683,    -1,    11,    -1,    10,   684,    74,    -1,   917,
      -1,    -1,   686,   687,   688,    -1,   115,    -1,   901,    -1,
     689,    -1,   690,    -1,    11,    -1,    10,   691,   116,    -1,
     917,    -1,    -1,   693,   694,   695,    -1,   159,    -1,   901,
      -1,   696,    -1,   697,    -1,    11,    -1,    10,   698,   160,
      -1,   917,    -1,    -1,   700,   701,   702,    -1,   173,    -1,
     901,    -1,   703,    -1,   704,    -1,    11,    -1,    10,   705,
     174,    -1,   917,    -1,    -1,   706,   707,    -1,   708,   709,
     712,    -1,   129,    -1,   710,    -1,    -1,   710,   711,    -1,
     904,    -1,   902,    -1,   895,    -1,   883,    -1,   879,    -1,
     713,    -1,   714,    -1,    10,   130,    -1,    11,    -1,    10,
     715,   130,    -1,   716,    -1,   724,    -1,   717,    -1,   716,
     717,    -1,   718,   719,   720,    -1,   121,    -1,    37,   934,
       6,   934,    -1,   721,    -1,   722,    -1,    10,   122,    -1,
      11,    -1,    10,   723,   122,    -1,   933,    -1,   725,    -1,
     724,   725,    -1,   726,   727,   730,    -1,   103,    -1,   728,
      -1,    -1,   728,   729,    -1,   901,    -1,   895,    -1,   879,
      -1,   731,    -1,   732,    -1,    11,    -1,    10,   733,   104,
      -1,   917,    -1,    -1,   735,   736,   737,    -1,    93,    -1,
      -1,   906,    -1,   738,    -1,   739,    -1,    11,    -1,    10,
     740,    94,    -1,   741,   753,   801,    -1,    -1,   742,   743,
     744,    -1,    99,    -1,   899,    -1,   745,    -1,   746,    -1,
      10,   100,    -1,    11,    -1,    10,   747,   100,    -1,   748,
      -1,   749,    -1,   748,   749,    -1,   750,   751,   752,    -1,
      91,    -1,    37,   934,     6,   934,    -1,    10,   932,    92,
      -1,    -1,   754,   755,    -1,    87,    -1,   756,    -1,   757,
      -1,    11,    -1,    10,   758,    88,    -1,   759,   766,   773,
     780,   787,   794,    -1,    -1,   760,   761,   762,    -1,    85,
      -1,   901,    -1,   763,    -1,   764,    -1,    11,    -1,    10,
     765,    86,    -1,   917,    -1,    -1,   767,   768,   769,    -1,
      71,    -1,   901,    -1,   770,    -1,   771,    -1,    11,    -1,
      10,   772,    72,    -1,   917,    -1,    -1,   774,   775,   776,
      -1,    73,    -1,   901,    -1,   777,    -1,   778,    -1,    11,
      -1,    10,   779,    74,    -1,   917,    -1,    -1,   781,   782,
     783,    -1,   115,    -1,   901,    -1,   784,    -1,   785,    -1,
      11,    -1,    10,   786,   116,    -1,   917,    -1,    -1,   788,
     789,   790,    -1,   159,    -1,   901,    -1,   791,    -1,   792,
      -1,    11,    -1,    10,   793,   160,    -1,   917,    -1,    -1,
     795,   796,   797,    -1,   173,    -1,   901,    -1,   798,    -1,
     799,    -1,    11,    -1,    10,   800,   174,    -1,   917,    -1,
      -1,   801,   802,    -1,   803,   804,   807,    -1,   129,    -1,
     805,    -1,    -1,   805,   806,    -1,   899,    -1,   902,    -1,
     895,    -1,   883,    -1,   879,    -1,   808,    -1,   809,    -1,
      10,   130,    -1,    11,    -1,    10,   810,   130,    -1,   811,
      -1,   819,    -1,   812,    -1,   811,   812,    -1,   813,   814,
     815,    -1,    91,    -1,    37,   934,     6,   934,    -1,   816,
      -1,   817,    -1,    10,    92,    -1,    11,    -1,    10,   818,
      92,    -1,   933,    -1,   820,    -1,   819,   820,    -1,   821,
     822,   825,    -1,   103,    -1,   823,    -1,    -1,   823,   824,
      -1,   901,    -1,   895,    -1,   879,    -1,   826,    -1,   827,
      -1,    11,    -1,    10,   828,   104,    -1,   917,    -1,    -1,
     830,   831,   832,    -1,   135,    -1,   909,    -1,   833,    -1,
     834,    -1,    10,   136,    -1,    11,    -1,    10,   835,   136,
      -1,   836,    -1,   837,    -1,   836,   837,    -1,   838,   839,
     842,    -1,   133,    -1,   840,    -1,    -1,   840,   841,    -1,
     883,    -1,   875,    -1,   879,    -1,   903,    -1,   843,    -1,
     844,    -1,    10,   134,    -1,    11,    -1,    10,   845,   134,
      -1,   846,    -1,   847,    -1,   846,   847,    -1,   848,    -1,
     849,    -1,   850,    -1,    67,    -1,    68,    -1,    65,   851,
      66,    -1,     5,    -1,    -1,   853,   854,   855,    -1,   137,
      -1,   912,    -1,   856,    -1,   857,    -1,    10,   138,    -1,
      11,    -1,    10,   858,   138,    -1,   859,    -1,   860,    -1,
     859,   860,    -1,   861,   862,   865,    -1,   151,    -1,   863,
      -1,    -1,   863,   864,    -1,   883,    -1,   875,    -1,   879,
      -1,   903,    -1,   866,    -1,   867,    -1,    10,   152,    -1,
      11,    -1,    10,   868,   152,    -1,   869,    -1,   870,    -1,
     869,   870,    -1,   871,    -1,   872,    -1,   873,    -1,    67,
      -1,    68,    -1,    65,   874,    66,    -1,     5,    -1,   876,
      -1,   877,    -1,   878,    -1,    42,    -1,    41,     3,   934,
      -1,   880,    -1,   881,    -1,   882,    -1,    44,    -1,    43,
       3,   934,    -1,   884,    -1,   885,    -1,   886,    -1,    46,
      -1,    45,     3,   934,    -1,   888,    -1,   889,    -1,   890,
      -1,    48,    -1,    47,     3,   934,    -1,   892,    -1,   893,
      -1,   894,    -1,    50,    -1,    49,     3,   934,    -1,   896,
      -1,   897,    -1,   898,    -1,    52,    -1,    51,     3,   934,
      -1,    16,   934,     6,   934,    -1,    17,   934,     6,   934,
      -1,    18,   934,     6,   934,    -1,    19,   934,     6,   934,
      -1,    21,   934,     6,   934,    -1,    22,   934,     6,   934,
      -1,    23,   934,     6,   934,    -1,    24,   934,     6,   934,
      -1,    25,   934,     6,   934,    -1,    26,   934,     6,   934,
      -1,    27,   934,     6,   934,    -1,    28,   934,     6,   934,
      -1,    29,   934,     6,   934,    -1,    30,   934,     6,   934,
      -1,    31,   934,     6,   934,    -1,    32,   934,     6,   934,
      -1,    33,   934,     6,   934,    -1,    34,   934,     6,   934,
      -1,   918,    -1,   925,    -1,    -1,   918,   919,    -1,   920,
     921,   924,    -1,   101,    -1,   922,    -1,    -1,   922,   923,
      -1,   931,    -1,   930,    -1,    10,     6,   102,    -1,    83,
     926,   927,    -1,    40,   934,     6,   934,    -1,   928,    -1,
     929,    -1,    10,    84,    -1,    11,    -1,    10,     4,    84,
      -1,    38,   934,     6,   934,    -1,    39,   934,     6,   934,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,   935,     8,    -1,    -1,   935,   936,    -1,   194,    -1,
     195,    -1,   196,    -1,   197,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   187,   189,   196,   203,   203,   205,   205,
     207,   209,   212,   215,   215,   217,   219,   219,   221,   221,
     223,   225,   227,   227,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   241,   243,   257,   263,   263,   266,   271,
     275,   283,   287,   292,   292,   294,   296,   298,   298,   300,
     304,   313,   318,   318,   321,   326,   332,   332,   335,   337,
     343,   343,   345,   345,   347,   349,   352,   354,   360,   360,
     362,   362,   364,   366,   369,   371,   377,   377,   379,   379,
     381,   383,   386,   388,   394,   394,   396,   396,   398,   400,
     403,   405,   411,   411,   413,   413,   415,   417,   420,   422,
     428,   428,   430,   430,   432,   434,   437,   439,   445,   445,
     447,   447,   449,   451,   454,   456,   462,   472,   476,   481,
     481,   483,   485,   487,   487,   489,   493,   504,   509,   509,
     512,   518,   523,   530,   530,   534,   534,   536,   538,   538,
     540,   540,   542,   544,   546,   546,   549,   550,   551,   552,
     553,   554,   557,   559,   565,   565,   567,   567,   569,   571,
     577,   579,   589,   591,   591,   594,   600,   605,   607,   612,
     614,   624,   626,   626,   629,   635,   640,   642,   648,   650,
     660,   662,   662,   665,   671,   676,   678,   684,   686,   694,
     695,   700,   702,   706,   708,   714,   724,   728,   733,   733,
     735,   737,   739,   739,   741,   745,   756,   761,   761,   764,
     770,   775,   782,   782,   786,   786,   788,   790,   790,   792,
     792,   794,   796,   798,   798,   801,   802,   803,   804,   805,
     806,   809,   811,   817,   817,   819,   819,   821,   823,   830,
     832,   838,   838,   840,   840,   842,   844,   847,   849,   855,
     855,   857,   857,   859,   861,   864,   866,   872,   872,   874,
     874,   876,   878,   881,   883,   889,   889,   891,   891,   893,
     895,   901,   903,   909,   919,   923,   928,   928,   930,   932,
     934,   934,   936,   940,   951,   956,   956,   959,   965,   970,
     977,   977,   980,   980,   982,   984,   984,   986,   986,   988,
     990,   992,   992,   995,   996,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1008,  1010,  1016,  1016,  1018,  1018,
    1020,  1022,  1029,  1031,  1037,  1037,  1039,  1039,  1041,  1043,
    1046,  1048,  1054,  1054,  1056,  1056,  1058,  1060,  1063,  1065,
    1071,  1071,  1073,  1073,  1075,  1077,  1080,  1082,  1088,  1088,
    1090,  1090,  1092,  1094,  1097,  1099,  1105,  1114,  1118,  1123,
    1123,  1125,  1127,  1129,  1129,  1131,  1133,  1146,  1146,  1149,
    1149,  1149,  1149,  1152,  1152,  1154,  1154,  1156,  1158,  1171,
    1172,  1175,  1177,  1187,  1189,  1189,  1192,  1198,  1203,  1205,
    1211,  1213,  1223,  1225,  1225,  1228,  1234,  1239,  1241,  1247,
    1249,  1259,  1261,  1261,  1264,  1270,  1275,  1277,  1283,  1285,
    1294,  1295,  1300,  1302,  1307,  1309,  1315,  1325,  1329,  1334,
    1334,  1336,  1338,  1340,  1340,  1342,  1346,  1357,  1362,  1362,
    1365,  1371,  1376,  1383,  1383,  1386,  1386,  1388,  1396,  1401,
    1401,  1404,  1411,  1417,  1423,  1431,  1435,  1440,  1440,  1442,
    1444,  1446,  1446,  1448,  1450,  1458,  1460,  1460,  1462,  1462,
    1464,  1473,  1490,  1496,  1498,  1508,  1513,  1513,  1516,  1521,
    1525,  1534,  1538,  1544,  1544,  1546,  1548,  1550,  1550,  1552,
    1555,  1564,  1569,  1569,  1572,  1578,  1585,  1585,  1588,  1588,
    1590,  1592,  1592,  1594,  1594,  1596,  1598,  1605,  1605,  1607,
    1610,  1610,  1619,  1619,  1621,  1623,  1625,  1627,  1627,  1629,
    1631,  1639,  1643,  1648,  1648,  1650,  1652,  1654,  1654,  1656,
    1663,  1669,  1671,  1674,  1674,  1676,  1678,  1686,  1690,  1695,
    1695,  1697,  1699,  1701,  1701,  1703,  1711,  1717,  1720,  1721,
    1723,  1723,  1725,  1727,  1730,  1730,  1732,  1734,  1734,  1736,
    1738,  1740,  1742,  1742,  1751,  1753,  1760,  1760,  1762,  1764,
    1766,  1769,  1769,  1779,  1781,  1788,  1788,  1790,  1792,  1794,
    1797,  1797,  1806,  1808,  1815,  1815,  1817,  1819,  1821,  1824,
    1824,  1833,  1835,  1842,  1842,  1844,  1846,  1848,  1851,  1851,
    1860,  1862,  1869,  1869,  1871,  1873,  1875,  1878,  1878,  1887,
    1889,  1896,  1896,  1898,  1900,  1902,  1905,  1905,  1907,  1912,
    1925,  1932,  1932,  1935,  1945,  1955,  1961,  1967,  1974,  1974,
    1976,  1976,  1978,  1980,  1980,  1982,  1982,  1984,  1989,  1991,
    1998,  1998,  2000,  2000,  2002,  2004,  2013,  2013,  2015,  2026,
    2035,  2042,  2042,  2045,  2051,  2057,  2065,  2065,  2067,  2069,
    2072,  2076,  2076,  2078,  2084,  2084,  2093,  2093,  2095,  2097,
    2099,  2101,  2101,  2103,  2105,  2113,  2117,  2122,  2122,  2124,
    2126,  2129,  2129,  2131,  2138,  2145,  2145,  2147,  2150,  2151,
    2154,  2154,  2156,  2158,  2158,  2162,  2164,  2166,  2168,  2168,
    2177,  2179,  2186,  2186,  2188,  2190,  2192,  2194,  2194,  2203,
    2205,  2212,  2212,  2214,  2216,  2218,  2221,  2221,  2230,  2232,
    2239,  2239,  2241,  2243,  2245,  2248,  2248,  2257,  2259,  2266,
    2266,  2268,  2270,  2272,  2275,  2275,  2284,  2286,  2293,  2293,
    2295,  2297,  2299,  2302,  2302,  2311,  2313,  2320,  2320,  2322,
    2324,  2326,  2329,  2329,  2331,  2337,  2350,  2358,  2358,  2361,
    2371,  2381,  2387,  2393,  2402,  2402,  2404,  2404,  2406,  2408,
    2408,  2410,  2410,  2412,  2417,  2419,  2424,  2424,  2426,  2426,
    2428,  2430,  2436,  2436,  2438,  2449,  2458,  2465,  2465,  2468,
    2474,  2480,  2488,  2488,  2490,  2492,  2495,  2498,  2498,  2500,
    2505,  2505,  2513,  2513,  2515,  2517,  2519,  2521,  2521,  2523,
    2526,  2534,  2538,  2543,  2543,  2545,  2547,  2549,  2549,  2551,
    2558,  2564,  2566,  2569,  2569,  2571,  2573,  2573,  2575,  2577,
    2579,  2581,  2581,  2590,  2592,  2599,  2599,  2601,  2603,  2605,
    2607,  2607,  2616,  2618,  2625,  2625,  2627,  2629,  2631,  2634,
    2634,  2643,  2645,  2652,  2652,  2654,  2656,  2658,  2661,  2661,
    2670,  2672,  2679,  2679,  2681,  2683,  2685,  2688,  2688,  2697,
    2699,  2706,  2706,  2708,  2710,  2712,  2715,  2715,  2724,  2726,
    2733,  2733,  2735,  2737,  2739,  2742,  2742,  2744,  2750,  2763,
    2770,  2770,  2773,  2783,  2793,  2799,  2805,  2812,  2812,  2814,
    2814,  2816,  2818,  2818,  2820,  2820,  2822,  2827,  2829,  2835,
    2835,  2837,  2837,  2839,  2841,  2848,  2848,  2850,  2861,  2870,
    2877,  2877,  2880,  2886,  2892,  2900,  2900,  2902,  2904,  2906,
    2910,  2910,  2912,  2917,  2926,  2930,  2935,  2935,  2937,  2939,
    2941,  2941,  2943,  2947,  2958,  2965,  2965,  2968,  2974,  2980,
    2988,  2998,  3002,  3007,  3007,  3009,  3011,  3013,  3013,  3015,
    3020,  3024,  3026,  3026,  3028,  3030,  3041,  3041,  3043,  3048,
    3057,  3061,  3066,  3066,  3068,  3070,  3072,  3072,  3074,  3078,
    3089,  3096,  3096,  3099,  3104,  3110,  3116,  3125,  3129,  3134,
    3134,  3136,  3138,  3140,  3140,  3142,  3147,  3151,  3153,  3153,
    3155,  3157,  3167,  3173,  3173,  3175,  3178,  3181,  3187,  3187,
    3189,  3192,  3196,  3202,  3202,  3204,  3207,  3210,  3216,  3216,
    3218,  3221,  3224,  3230,  3230,  3232,  3235,  3238,  3244,  3244,
    3246,  3249,  3272,  3278,  3286,  3292,  3305,  3314,  3320,  3328,
    3334,  3340,  3346,  3352,  3358,  3366,  3372,  3380,  3385,  3391,
    3417,  3422,  3424,  3424,  3426,  3428,  3437,  3439,  3439,  3441,
    3441,  3443,  3451,  3453,  3458,  3458,  3460,  3460,  3462,  3485,
    3493,  3507,  3508,  3511,  3512,  3513,  3515,  3517,  3517,  3519,
    3520,  3521,  3522
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
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND", "ITEMEMPTY",
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
  "VARIABLESEND", "VARIDXSTART", "VARIDXEND", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlStartEmpty", "osrlStart",
  "osrlAttributes", "osrlContent", "osrlEmpty", "osrlLaden", "osrlBody",
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
  "varValueContent", "variableValuesString", "variableValuesStringStart",
  "numberOfVarStringATT", "variableValuesStringContent",
  "variableValuesStringEmpty", "variableValuesStringLaden",
  "variableValuesStringBody", "varValueStringArray", "varValueString",
  "varValueStringStart", "varStrIdxATT", "varValueStringContent",
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
     445,   446,   447,   448,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   198,   199,   199,   200,   201,   202,   202,   203,   203,
     204,   205,   206,   207,   207,   208,   209,   209,   210,   210,
     211,   212,   213,   213,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   215,   216,   217,   218,   218,   219,   219,
     219,   220,   220,   221,   221,   222,   223,   224,   224,   225,
     226,   227,   228,   228,   229,   229,   230,   230,   231,   232,
     233,   233,   234,   234,   235,   236,   237,   238,   239,   239,
     240,   240,   241,   242,   243,   244,   245,   245,   246,   246,
     247,   248,   249,   250,   251,   251,   252,   252,   253,   254,
     255,   256,   257,   257,   258,   258,   259,   260,   261,   262,
     263,   263,   264,   264,   265,   266,   267,   268,   269,   269,
     270,   270,   271,   272,   273,   274,   275,   276,   276,   277,
     277,   278,   279,   280,   280,   281,   282,   283,   284,   284,
     285,   285,   285,   286,   286,   287,   287,   288,   289,   289,
     290,   290,   291,   292,   293,   293,   294,   294,   294,   294,
     294,   294,   295,   296,   297,   297,   298,   298,   299,   300,
     301,   302,   303,   304,   304,   305,   305,   306,   307,   308,
     309,   310,   311,   311,   312,   312,   313,   314,   315,   316,
     317,   318,   318,   319,   319,   320,   321,   322,   323,   324,
     324,   325,   326,   327,   328,   329,   330,   330,   331,   331,
     332,   333,   334,   334,   335,   336,   337,   338,   338,   339,
     339,   339,   340,   340,   341,   341,   342,   343,   343,   344,
     344,   345,   346,   347,   347,   348,   348,   348,   348,   348,
     348,   349,   350,   351,   351,   352,   352,   353,   354,   355,
     356,   357,   357,   358,   358,   359,   360,   361,   362,   363,
     363,   364,   364,   365,   366,   367,   368,   369,   369,   370,
     370,   371,   372,   373,   374,   375,   375,   376,   376,   377,
     378,   379,   380,   381,   382,   382,   383,   383,   384,   385,
     386,   386,   387,   388,   389,   390,   390,   391,   391,   391,
     392,   392,   393,   393,   394,   395,   395,   396,   396,   397,
     398,   399,   399,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   401,   402,   403,   403,   404,   404,
     405,   406,   407,   408,   409,   409,   410,   410,   411,   412,
     413,   414,   415,   415,   416,   416,   417,   418,   419,   420,
     421,   421,   422,   422,   423,   424,   425,   426,   427,   427,
     428,   428,   429,   430,   431,   432,   433,   434,   434,   435,
     435,   436,   437,   438,   438,   439,   440,   441,   441,   442,
     442,   442,   442,   443,   443,   444,   444,   445,   446,   447,
     447,   448,   449,   450,   451,   451,   452,   452,   453,   454,
     455,   456,   457,   458,   458,   459,   459,   460,   461,   462,
     463,   464,   465,   465,   466,   466,   467,   468,   469,   470,
     471,   471,   472,   473,   474,   475,   476,   477,   477,   478,
     478,   479,   480,   481,   481,   482,   483,   484,   485,   485,
     486,   486,   486,   487,   487,   488,   488,   489,   490,   491,
     491,   492,   492,   492,   492,   493,   493,   494,   494,   495,
     496,   497,   497,   498,   499,   500,   501,   501,   502,   502,
     503,   504,   505,   506,   507,   508,   509,   509,   510,   510,
     510,   511,   511,   512,   512,   513,   514,   515,   515,   516,
     517,   518,   519,   519,   520,   520,   521,   521,   522,   522,
     523,   524,   524,   525,   525,   526,   527,   528,   528,   529,
     530,   530,   531,   531,   532,   533,   534,   535,   535,   536,
     537,   538,   538,   539,   539,   540,   541,   542,   542,   543,
     544,   545,   546,   547,   547,   548,   549,   550,   550,   551,
     551,   552,   553,   554,   554,   555,   556,   557,   558,   558,
     559,   559,   560,   561,   562,   562,   563,   564,   564,   565,
     566,   567,   568,   568,   569,   570,   571,   571,   572,   573,
     574,   575,   575,   576,   577,   578,   578,   579,   580,   581,
     582,   582,   583,   584,   585,   585,   586,   587,   588,   589,
     589,   590,   591,   592,   592,   593,   594,   595,   596,   596,
     597,   598,   599,   599,   600,   601,   602,   603,   603,   604,
     605,   606,   606,   607,   608,   609,   610,   610,   611,   612,
     613,   614,   614,   615,   615,   615,   615,   615,   616,   616,
     617,   617,   618,   619,   619,   620,   620,   621,   622,   623,
     624,   624,   625,   625,   626,   627,   628,   628,   629,   630,
     631,   632,   632,   633,   633,   633,   634,   634,   635,   636,
     637,   638,   638,   639,   640,   640,   641,   641,   642,   643,
     644,   645,   645,   646,   647,   648,   648,   649,   649,   650,
     651,   652,   652,   653,   654,   655,   655,   656,   657,   657,
     658,   658,   659,   660,   660,   661,   662,   663,   664,   664,
     665,   666,   667,   667,   668,   669,   670,   671,   671,   672,
     673,   674,   674,   675,   676,   677,   678,   678,   679,   680,
     681,   681,   682,   683,   684,   685,   685,   686,   687,   688,
     688,   689,   690,   691,   692,   692,   693,   694,   695,   695,
     696,   697,   698,   699,   699,   700,   701,   702,   702,   703,
     704,   705,   706,   706,   707,   708,   709,   710,   710,   711,
     711,   711,   711,   711,   712,   712,   713,   713,   714,   715,
     715,   716,   716,   717,   718,   719,   720,   720,   721,   721,
     722,   723,   724,   724,   725,   726,   727,   728,   728,   729,
     729,   729,   730,   730,   731,   732,   733,   734,   734,   735,
     736,   736,   737,   737,   738,   739,   740,   741,   741,   742,
     743,   744,   744,   745,   745,   746,   747,   748,   748,   749,
     750,   751,   752,   753,   753,   754,   755,   755,   756,   757,
     758,   759,   759,   760,   761,   762,   762,   763,   764,   765,
     766,   766,   767,   768,   769,   769,   770,   771,   772,   773,
     773,   774,   775,   776,   776,   777,   778,   779,   780,   780,
     781,   782,   783,   783,   784,   785,   786,   787,   787,   788,
     789,   790,   790,   791,   792,   793,   794,   794,   795,   796,
     797,   797,   798,   799,   800,   801,   801,   802,   803,   804,
     805,   805,   806,   806,   806,   806,   806,   807,   807,   808,
     808,   809,   810,   810,   811,   811,   812,   813,   814,   815,
     815,   816,   816,   817,   818,   819,   819,   820,   821,   822,
     823,   823,   824,   824,   824,   825,   825,   826,   827,   828,
     829,   829,   830,   831,   832,   832,   833,   833,   834,   835,
     836,   836,   837,   838,   839,   840,   840,   841,   841,   841,
     841,   842,   842,   843,   843,   844,   845,   846,   846,   847,
     848,   848,   849,   849,   850,   851,   852,   852,   853,   854,
     855,   855,   856,   856,   857,   858,   859,   859,   860,   861,
     862,   863,   863,   864,   864,   864,   864,   865,   865,   866,
     866,   867,   868,   869,   869,   870,   871,   871,   872,   872,
     873,   874,   875,   876,   876,   877,   878,   879,   880,   880,
     881,   882,   883,   884,   884,   885,   886,   887,   888,   888,
     889,   890,   891,   892,   892,   893,   894,   895,   896,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   917,   918,   918,   919,   920,   921,   922,   922,   923,
     923,   924,   925,   926,   927,   927,   928,   928,   929,   930,
     931,   932,   932,   933,   933,   933,   934,   935,   935,   936,
     936,   936,   936
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     5,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     0,     2,     1,     1,     3,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     3,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     1,     0,     2,     1,     1,     3,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     3,     1,
       0,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       2,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       4,     3,     8,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     0,     3,     1,
       0,     1,     1,     1,     1,     3,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     4,     3,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     0,     2,     1,     1,     1,     1,
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
       1,     1,     2,     3,     1,     0,     4,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     3,     6,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       0,     1,     1,     1,     1,     3,     3,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     4,     3,     0,     2,     1,     1,     1,     1,     3,
       6,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     2,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     4,     1,     1,     2,     1,     3,     4,
       4,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    13,     6,     1,    15,     0,   135,
       0,     7,     0,     2,   137,   214,     0,     0,    19,    14,
      16,    17,    13,    10,     3,     8,     9,   216,   292,     0,
       0,   141,   136,   138,   139,    18,    34,    83,    91,    59,
     115,    75,    67,    99,   107,     0,    21,    22,    24,     0,
      25,     0,    26,     0,    27,     0,    28,     0,    29,     0,
      30,     0,    31,     0,    32,     0,     0,   294,   435,     0,
       0,   220,   215,   217,   218,   140,   188,   179,   161,   170,
     194,   153,     0,   143,   144,   146,     0,   147,   163,   148,
     172,   149,   181,   150,   189,   151,     0,    20,    23,  1067,
       0,  1000,     0,  1010,     0,    35,    36,    39,   997,   998,
     999,    38,  1007,  1008,  1009,    40,     0,    63,    58,    60,
      61,     0,    71,    66,    68,    69,     0,    79,    74,    76,
      77,     0,    87,    82,    84,    85,     0,    95,    90,    92,
      93,     0,   103,    98,   100,   101,     0,   111,   106,   108,
     109,  1067,     0,   116,    11,   437,    12,   439,     0,   298,
     293,   295,   296,   219,   240,   232,   272,   264,   256,   248,
       0,   222,   223,   225,     0,   226,     0,   227,     0,   228,
       0,   229,     0,   230,     0,   142,   145,     0,   157,   152,
     154,   155,     0,   162,     0,   171,     0,   180,     0,   190,
       0,   195,     0,     0,  1067,  1067,     0,    44,    33,    41,
      42,    37,    65,    62,     0,    73,    70,     0,    81,    78,
       0,    89,    86,     0,    97,    94,     0,   105,   102,     0,
     113,   110,     0,     0,     0,   120,   114,   117,   118,     0,
     438,   297,   339,   347,   415,   331,   315,   323,   355,   409,
     400,   382,   391,     0,   300,   301,   303,     0,   304,     0,
     305,     0,   306,     0,   307,     0,   308,     0,   309,   384,
     310,   393,   311,   402,   312,   410,   313,     0,   221,   224,
       0,   236,   231,   233,   234,     0,   244,   239,   241,   242,
       0,   252,   247,   249,   250,     0,   260,   255,   257,   258,
       0,   268,   263,   265,   266,     0,   273,   159,   156,     0,
       0,   160,     0,  1015,   164,   166,   165,  1012,  1013,  1014,
       0,   169,   173,   175,   174,     0,   178,   182,   184,   183,
       0,   187,     0,   199,   193,   196,   197,  1067,  1066,  1069,
    1070,  1071,  1072,  1068,  1001,  1011,    43,    50,     0,    46,
      47,    52,    64,    72,    80,    88,    96,   104,   112,  1067,
     126,   119,     0,   122,   123,   128,     0,   448,   436,   445,
     446,  1067,  1067,  1067,  1067,   440,   443,   444,   441,   442,
     299,   302,     0,   319,   314,   316,   317,     0,   327,   322,
     324,   325,     0,   335,   330,   332,   333,     0,   343,   338,
     340,   341,     0,   351,   346,   348,   349,  1067,     0,   356,
       0,   383,     0,   392,     0,   401,     0,   411,     0,   416,
     238,   235,     0,   246,   243,     0,   254,   251,     0,   262,
     259,     0,  1061,  1062,   267,     0,   270,     0,   277,   271,
     274,   275,   158,     0,   168,  1067,     0,   177,     0,   186,
     192,     0,   205,   198,     0,   201,   202,   207,  1036,    45,
      48,     0,    51,  1031,   121,   124,     0,   127,   447,   454,
       0,   956,   451,   456,     0,     0,     0,     0,   321,   318,
       0,   329,   326,     0,   337,   334,     0,   345,   342,     0,
     353,   350,     0,     0,     0,   360,   354,   357,   358,     0,
     381,   385,   387,   386,     0,   390,   394,   396,   395,     0,
     399,   403,   405,   404,     0,   408,     0,   420,   414,   417,
     418,   237,   245,   253,   261,   269,   283,   276,     0,   279,
     280,   285,   167,  1016,   176,   185,   191,   200,   203,     0,
     206,     0,    57,    49,     0,  1005,    53,    55,    54,  1002,
    1003,  1004,     0,   134,   125,     0,  1020,   129,   132,   130,
     131,  1017,  1018,  1019,   449,   958,   452,   450,     0,     0,
     455,  1067,  1067,  1067,  1067,   320,   328,   336,   344,   352,
    1067,   366,   359,     0,   362,   363,   367,     0,   389,     0,
     398,     0,   407,   413,     0,   426,   419,     0,   422,   423,
     428,   278,   281,     0,   284,     0,   213,   204,   208,   211,
     209,   210,    56,  1067,   133,  1067,  1067,     0,   959,     0,
     453,  1067,     0,   457,   458,   459,  1023,  1028,  1034,  1039,
    1037,   361,   364,     0,   388,   397,   406,   412,   421,   424,
       0,   427,     0,   291,   282,   286,   289,   287,   288,   212,
    1006,  1021,     0,     0,   963,   957,   960,   961,   464,   488,
       0,     0,  1067,     0,   376,     0,   995,   368,   365,   373,
     374,   371,   992,   993,   994,   372,   370,   369,     0,   434,
     425,   429,   432,   430,   431,   290,  1067,   962,   969,     0,
     965,   966,   971,   490,   497,     0,     0,   465,   466,   469,
     468,   470,  1067,   461,   380,   379,   375,     0,   378,  1067,
     433,  1035,   964,   967,     0,   970,   499,   651,   500,     0,
     494,   489,   491,   492,     0,   474,   463,   471,   472,   467,
     460,   377,   996,     0,   980,   968,   977,   978,  1067,   972,
     974,   975,   973,   976,   653,   787,   654,  1067,     0,   501,
     496,   493,     0,   473,   480,     0,   476,   477,   482,     0,
     988,   989,   979,     0,   982,   983,   985,   986,   987,     0,
     789,   920,   790,  1067,     0,   655,     0,   507,   504,   498,
     502,   503,   495,   475,   478,     0,   481,   991,     0,   981,
     984,  1067,   922,     0,     0,  1067,     0,   791,     0,   661,
     658,   652,   656,   657,  1067,   509,     0,   523,     0,     0,
     487,   479,   483,   485,   484,   990,  1026,   462,  1067,     0,
     923,     0,   797,   794,   788,   792,   793,  1067,   663,     0,
     680,     0,  1033,   505,   525,   544,     0,  1067,     0,   510,
     486,     0,     0,   927,   921,   924,   925,  1067,   799,     0,
     813,     0,  1030,   659,   682,   742,     0,  1067,     0,   664,
     546,   606,     0,     0,   526,     0,     0,   514,   508,   511,
     512,  1067,   933,   926,     0,   929,   930,   935,  1029,   795,
     815,   875,     0,  1067,     0,   800,   660,   688,   685,   681,
     683,   684,     0,     0,   668,   662,   665,   666,   506,   552,
     549,   545,   547,   548,     0,   530,   524,   527,   528,  1067,
     513,   520,     0,   516,   517,     0,  1032,   928,   931,     0,
     934,   796,   821,   818,   814,   816,   817,     0,     0,   804,
     798,   801,   802,   745,   743,   747,   690,     0,   697,     0,
    1067,   674,   667,     0,   670,   671,   675,   609,   607,   611,
     554,     0,   561,     0,   529,   536,     0,   532,   533,     0,
    1038,   515,   518,  1067,     0,     0,   944,   932,   941,   942,
     936,   938,   939,   937,   940,   878,   876,   880,   823,     0,
     830,     0,  1067,   810,   803,     0,   806,   807,     0,     0,
     746,   686,   699,   706,     0,  1067,     0,   691,  1027,   669,
     672,  1067,     0,     0,   610,   550,   563,   570,     0,     0,
     555,   531,   534,  1067,     0,     0,     0,   519,     0,   952,
     953,   943,     0,   946,   947,   949,   950,   951,     0,   879,
     819,   832,   839,     0,     0,   824,  1022,   805,   808,  1067,
       0,     0,   757,   744,   754,   755,  1067,   748,   753,   752,
     751,   750,   749,   708,   715,     0,     0,   700,     0,  1042,
     694,   689,   692,   693,     0,     0,   673,     0,   621,   608,
     618,   619,   612,   617,   616,   615,   614,   613,   572,   579,
       0,     0,   564,  1042,   558,   553,   556,   557,     0,     0,
     541,   535,   538,   539,  1067,     0,   955,     0,   945,   948,
       0,   890,   877,   887,   888,   881,   886,   885,   884,   882,
     883,   841,   848,     0,     0,   833,  1042,   827,   822,   825,
     826,     0,     0,   809,   775,   764,   756,     0,   759,   761,
       0,   760,   772,   777,     0,   717,   724,     0,     0,   709,
    1042,   703,   698,   701,   702,  1067,     0,     0,   696,  1040,
    1041,  1067,   678,   679,     0,   639,   620,   628,     0,   623,
     625,     0,   624,   636,   641,   581,   588,     0,     0,   573,
    1042,   567,   562,   565,   566,     0,   560,  1067,   543,   540,
       0,   521,   522,   954,   897,   908,   889,     0,   892,   894,
       0,   893,   905,   910,   850,   857,     0,     0,   842,  1042,
     836,   831,   834,   835,     0,   829,  1067,     0,   758,   762,
    1067,     0,   773,     0,   776,  1067,   726,   733,     0,     0,
     718,  1042,   712,   707,   710,   711,     0,   705,  1024,  1067,
       0,   695,  1045,  1043,  1047,   676,   677,   622,   626,  1067,
       0,   637,     0,   640,   590,   597,     0,     0,   582,  1042,
     576,   571,   574,   575,     0,   569,   559,   537,   542,   891,
     895,  1067,     0,   906,     0,   909,   859,   866,     0,     0,
     851,  1042,   845,   840,   843,   844,     0,   838,   828,   811,
     812,     0,     0,   769,   763,   766,   767,  1042,   784,   774,
     782,   783,   778,   781,   780,   779,  1025,   735,   687,     0,
       0,   727,  1042,   721,   716,   719,   720,     0,   714,   704,
       0,     0,  1057,  1052,  1054,  1055,     0,  1046,     0,     0,
     633,   627,   630,   631,  1042,   648,   638,   646,   647,   642,
     645,   644,   643,   599,   551,     0,     0,   591,  1042,   585,
     580,   583,   584,     0,   578,   568,     0,     0,   902,   896,
     899,   900,  1042,   917,   907,   915,   916,   911,   914,   913,
     912,   868,   820,     0,     0,   860,  1042,   854,   849,   852,
     853,     0,   847,   837,  1067,  1063,  1064,  1065,   768,     0,
     771,     0,   786,     0,   736,  1042,   730,   725,   728,   729,
       0,   723,   713,  1067,     0,  1056,     0,  1044,  1067,  1067,
    1048,  1050,  1049,  1067,   632,     0,   635,     0,   650,     0,
     600,  1042,   594,   589,   592,   593,     0,   587,   577,  1067,
     901,     0,   904,     0,   919,     0,   869,  1042,   863,   858,
     861,   862,     0,   856,   846,   765,   770,   785,  1042,   739,
     734,   737,   738,     0,   732,   722,  1053,  1058,     0,     0,
       0,   629,   634,   649,  1042,   603,   598,   601,   602,     0,
     596,   586,   898,   903,   918,  1042,   872,   867,   870,   871,
       0,   865,   855,     0,   741,   731,  1051,  1067,  1067,     0,
     605,   595,     0,   874,   864,   740,  1059,  1060,   604,   873
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    24,    25,    26,     8,     9,
      10,    19,    20,    21,    45,    46,    47,    48,    49,   104,
     105,   106,   208,   209,   210,   348,   349,   350,   351,   461,
     462,   546,   543,    50,    51,   118,   119,   120,   214,    52,
      53,   123,   124,   125,   217,    54,    55,   128,   129,   130,
     220,    56,    57,   133,   134,   135,   223,    58,    59,   138,
     139,   140,   226,    60,    61,   143,   144,   145,   229,    62,
      63,   148,   149,   150,   232,    64,    65,   152,   236,   237,
     238,   362,   363,   364,   365,   466,   467,   557,   554,    15,
      16,    32,    33,    34,    82,    83,    84,    85,    86,   189,
     190,   191,   309,    87,    88,   192,   193,   314,   311,   443,
      89,    90,   194,   195,   322,   321,   446,    91,    92,   196,
     197,   327,   326,   448,    93,    94,   198,   331,   451,    95,
      96,   200,   334,   335,   336,   454,   455,   456,   457,   539,
     540,   608,   607,    28,    29,    72,    73,    74,   170,   171,
     172,   173,   174,   282,   283,   284,   422,   175,   176,   287,
     288,   289,   425,   177,   178,   292,   293,   294,   428,   179,
     180,   297,   298,   299,   431,   181,   182,   302,   303,   304,
     435,   183,   184,   305,   439,   440,   441,   528,   529,   530,
     531,   603,   604,   645,   644,    68,    69,   160,   161,   162,
     253,   254,   255,   256,   257,   384,   385,   386,   480,   258,
     259,   389,   390,   391,   483,   260,   261,   394,   395,   396,
     486,   262,   263,   399,   400,   401,   489,   264,   265,   404,
     405,   406,   492,   266,   267,   408,   496,   497,   498,   583,
     584,   585,   586,   633,   667,   668,   669,   670,   707,   708,
     268,   269,   410,   411,   501,   500,   587,   270,   271,   412,
     413,   506,   505,   589,   272,   273,   414,   415,   511,   510,
     591,   274,   275,   416,   515,   594,   276,   277,   418,   518,
     519,   520,   597,   598,   599,   600,   640,   641,   681,   680,
     156,   157,   239,   240,   375,   368,   369,   370,   470,   471,
     472,   473,   569,   570,   623,   624,   625,   620,   659,   660,
     696,   697,   698,   726,   727,   728,   755,   756,   757,   758,
     785,   786,   812,   811,   694,   695,   721,   722,   723,   752,
     717,   718,   748,   779,   780,   781,   806,   807,   808,   838,
     868,   869,   870,   912,   913,   914,   915,   964,  1017,   835,
     836,   863,   906,   907,   908,   956,   957,   958,   959,  1014,
    1091,  1092,  1093,  1180,   861,   862,   901,   902,   903,   951,
     952,   953,  1009,  1085,  1086,  1087,  1175,  1007,  1008,  1081,
    1172,  1173,  1174,  1254,  1079,  1080,  1168,  1251,  1252,  1253,
    1343,  1166,  1167,  1247,  1340,  1341,  1342,  1416,  1245,  1246,
    1336,  1413,  1414,  1415,  1459,  1334,  1335,  1409,  1456,  1457,
    1458,  1479,   898,   948,   949,  1003,  1004,  1072,  1069,  1070,
    1071,  1158,  1159,  1160,  1161,  1240,  1321,  1322,  1323,  1405,
    1162,  1163,  1164,  1242,  1243,  1329,  1326,  1327,  1328,  1407,
     745,   746,   774,   801,   802,   803,   829,   830,   831,   858,
     895,   896,   897,   943,   944,   945,   946,  1002,  1066,  1154,
     855,   856,   889,   890,   891,   937,   938,   939,   996,  1061,
    1062,  1063,  1147,   993,   994,  1056,  1142,  1143,  1144,  1226,
    1054,  1055,  1138,  1223,  1224,  1225,  1307,  1136,  1137,  1219,
    1304,  1305,  1306,  1390,  1217,  1218,  1300,  1387,  1388,  1389,
    1443,  1298,  1299,  1383,  1440,  1441,  1442,  1473,   886,   934,
     935,   989,   990,  1047,  1043,  1044,  1045,  1127,  1128,  1129,
    1130,  1211,  1284,  1285,  1286,  1379,  1131,  1132,  1133,  1213,
    1214,  1292,  1289,  1290,  1291,  1381,   771,   772,   796,   824,
     825,   826,   849,   850,   851,   884,   930,   931,   932,   985,
     986,   987,   988,  1040,  1123,   881,   882,   924,   925,   926,
     979,   980,   981,  1034,  1118,  1119,  1120,  1204,  1032,  1033,
    1114,  1201,  1202,  1203,  1276,  1112,  1113,  1197,  1273,  1274,
    1275,  1371,  1195,  1196,  1269,  1368,  1369,  1370,  1432,  1267,
    1268,  1364,  1429,  1430,  1431,  1470,  1362,  1363,  1425,  1467,
    1468,  1469,  1482,   921,   976,   977,  1028,  1029,  1105,  1102,
    1103,  1104,  1187,  1188,  1189,  1190,  1262,  1349,  1350,  1351,
    1421,  1191,  1192,  1193,  1264,  1265,  1357,  1354,  1355,  1356,
    1423,   793,   794,   819,   844,   845,   846,   874,   875,   876,
     877,   919,   920,   970,   967,   968,   969,  1022,  1023,  1024,
    1025,  1026,  1027,  1097,   567,   568,   617,   655,   656,   657,
     689,   690,   691,   692,   714,   715,   739,   735,   736,   737,
     763,   764,   765,   766,   767,   768,   788,   671,   672,   673,
     674,   107,   108,   109,   110,   548,   549,   550,   551,   111,
     112,   113,   114,   316,   317,   318,   319,   560,   561,   562,
     563,   885,   376,   997,  1051,   743,   859,   377,   797,   775,
     153,   820,   749,   378,   618,   115,   409,   839,   379,  1148,
    1149,  1233,  1234,  1316,  1317,  1400,  1397,  1150,  1230,  1313,
    1314,  1315,  1401,  1402,   436,  1380,   202,   203,   343
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1248
static const yytype_int16 yypact[] =
{
     230, -1248, -1248,    66,    34,    63, -1248, -1248,    76,    67,
     263, -1248,   275, -1248, -1248,    54,   292,   -21, -1248, -1248,
   -1248, -1248,    34, -1248, -1248, -1248, -1248, -1248,    77,   322,
     180, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,    94,   158, -1248, -1248,   371,
   -1248,   325, -1248,   328, -1248,   337, -1248,   346, -1248,   348,
   -1248,   352, -1248,   366, -1248,   128,   151, -1248,   105,   374,
      65, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   134,   173, -1248, -1248,   384, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,   356, -1248,   128, -1248, -1248, -1248,
     195, -1248,   198, -1248,   406,   371, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248,    29, -1248, -1248, -1248,
   -1248,    38, -1248, -1248, -1248, -1248,    28, -1248, -1248, -1248,
   -1248,    45, -1248, -1248, -1248, -1248,    40, -1248, -1248, -1248,
   -1248,    21, -1248, -1248, -1248, -1248,     5, -1248, -1248, -1248,
   -1248, -1248,   416, -1248, -1248, -1248, -1248, -1248,   -24, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
     147,   122, -1248, -1248,   430, -1248,   434, -1248,   439, -1248,
     441, -1248,   443, -1248,   128, -1248, -1248,    22, -1248, -1248,
   -1248, -1248,   202,   220,   204,   220,   206,   220,   208, -1248,
     447, -1248,   219,     9, -1248, -1248,   -49, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,   112, -1248, -1248,    90, -1248, -1248,
     107, -1248, -1248,   133, -1248, -1248,   142, -1248, -1248,   129,
   -1248, -1248,   130,   256,     1, -1248, -1248, -1248, -1248,   449,
     249, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,   244,    58, -1248, -1248,   456, -1248,   461,
   -1248,   463, -1248,   465, -1248,   467, -1248,   277, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   356, -1248,   128, -1248, -1248,
      37, -1248, -1248, -1248, -1248,    41, -1248, -1248, -1248, -1248,
       7, -1248, -1248, -1248, -1248,    10, -1248, -1248, -1248, -1248,
      23, -1248, -1248, -1248, -1248,   469, -1248, -1248, -1248,   156,
     475, -1248,   317, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
     475, -1248, -1248, -1248, -1248,   475, -1248, -1248, -1248, -1248,
     316, -1248,    15, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   216,   169,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   196,   213, -1248, -1248,    47, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,    24, -1248, -1248, -1248, -1248,    18, -1248, -1248,
   -1248, -1248,    27, -1248, -1248, -1248, -1248,    53, -1248, -1248,
   -1248, -1248,    35, -1248, -1248, -1248, -1248, -1248,   473, -1248,
     344,   220,   359,   220,   364,   220,   386, -1248,   476, -1248,
   -1248, -1248,   233, -1248, -1248,   264, -1248, -1248,   209, -1248,
   -1248,   235, -1248, -1248, -1248,   257, -1248,    32, -1248, -1248,
   -1248, -1248, -1248,   331, -1248, -1248,   326, -1248,   369, -1248,
   -1248,   385, -1248, -1248,   296,   334, -1248, -1248, -1248, -1248,
   -1248,   478,   271, -1248, -1248, -1248,   480,   387, -1248, -1248,
     404,   -59, -1248, -1248,   479,   595,   610,   611, -1248, -1248,
     394, -1248, -1248,   448, -1248, -1248,   410, -1248, -1248,   455,
   -1248, -1248,   512,   613,   -73, -1248, -1248, -1248, -1248,   475,
   -1248, -1248, -1248, -1248,   475, -1248, -1248, -1248, -1248,   475,
   -1248, -1248, -1248, -1248,   614, -1248,    56, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   492,   496,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   482,
     387,   468, -1248, -1248,   618, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   498, -1248, -1248,   624, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   599,   620,
      73, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,   462,   470, -1248, -1248,   451, -1248,   452,
   -1248,   457, -1248, -1248,   460, -1248, -1248,   506,   508, -1248,
   -1248, -1248, -1248,   485,   387,   515, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,   487, -1248,   486,
   -1248, -1248,   638, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,   302, -1248, -1248, -1248, -1248, -1248, -1248,
     489,   387,   516, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   636,   -64, -1248, -1248, -1248, -1248, -1248,   524,
     371,   641, -1248,    17, -1248,   645, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   520, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   514,
     500, -1248, -1248, -1248,   466,   491,   493,   371, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,   490, -1248, -1248,
   -1248, -1248, -1248, -1248,   495,   347, -1248,   526,   628,    36,
   -1248, -1248, -1248, -1248,   127, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,    -4, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   566,   632, -1248,   497, -1248,
   -1248, -1248,   538, -1248, -1248,   510,   504, -1248, -1248,   655,
   -1248, -1248, -1248,   518,    51, -1248, -1248, -1248, -1248,   656,
   -1248,   530,   639, -1248,   499, -1248,   660,   488, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   503,   197, -1248,   603, -1248,
   -1248, -1248, -1248,   525,   647, -1248,   505, -1248,   662,   494,
   -1248, -1248, -1248, -1248, -1248, -1248,   501,   502,   642,   522,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   507,
   -1248,   666,   579, -1248, -1248, -1248, -1248, -1248, -1248,   558,
     594,   661, -1248, -1248, -1248,   597,   642, -1248,   509, -1248,
   -1248,   679,   159, -1248, -1248, -1248, -1248, -1248, -1248,   601,
     605,   672, -1248, -1248, -1248, -1248,   511, -1248,   513, -1248,
   -1248, -1248,   517,   519, -1248,   683,   113, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,   554,   560, -1248, -1248, -1248, -1248,
   -1248, -1248,   521, -1248,   523, -1248,   568,   615, -1248, -1248,
   -1248, -1248,   692,   -63, -1248, -1248, -1248, -1248,   570,   616,
   -1248, -1248, -1248, -1248,   350, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   527,   529, -1248,   665, -1248, -1248, -1248,   528,
     347,   574,   619, -1248, -1248, -1248, -1248,   699,   -20, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,   621,   643,   694,
   -1248, -1248, -1248,   531,   592, -1248,   673, -1248, -1248, -1248,
   -1248,   629,   648,   694, -1248, -1248,   535,   537, -1248,   681,
   -1248, -1248, -1248, -1248,   712,     0, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   635,
     654,   694, -1248, -1248, -1248,   626,   637, -1248,   690,   532,
     361, -1248, -1248,   658,   694, -1248,   534, -1248, -1248, -1248,
   -1248, -1248,   719,   536,   391, -1248, -1248,   663,   694,   542,
   -1248, -1248, -1248, -1248,   544,   727,   475, -1248,   729, -1248,
   -1248, -1248,   606,   223, -1248, -1248, -1248, -1248,   546,   321,
   -1248, -1248,   664,   694,   549, -1248, -1248, -1248, -1248, -1248,
     725,   -28, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,   623,   694,   551, -1248,   733,   659,
   -1248, -1248, -1248, -1248,   735,   557, -1248,   -48, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   630,
     694,   556, -1248,   659, -1248, -1248, -1248, -1248,   737,     3,
   -1248, -1248, -1248, -1248, -1248,   562, -1248,   678, -1248, -1248,
     -18, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   631,   694,   559, -1248,   659, -1248, -1248, -1248,
   -1248,   741,   475, -1248, -1248, -1248, -1248,   622,   627, -1248,
     714,   646, -1248, -1248,   747, -1248,   607,   694,   561, -1248,
     659, -1248, -1248, -1248, -1248, -1248,   715,   668, -1248,   667,
   -1248, -1248, -1248, -1248,   634, -1248, -1248, -1248,   633,   572,
   -1248,   720,   657, -1248, -1248, -1248,   608,   694,   563, -1248,
     659, -1248, -1248, -1248, -1248,   675, -1248, -1248, -1248, -1248,
     576, -1248, -1248, -1248, -1248, -1248, -1248,   640,   671, -1248,
     728,   669, -1248, -1248, -1248,   612,   694,   565, -1248,   659,
   -1248, -1248, -1248, -1248,   687, -1248, -1248,   677, -1248, -1248,
   -1248,   567, -1248,   569,   335, -1248, -1248,   609,   694,   571,
   -1248,   659, -1248, -1248, -1248, -1248,   702, -1248, -1248, -1248,
     573, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
     575, -1248,   578,   335, -1248,   617,   694,   580, -1248,   659,
   -1248, -1248, -1248, -1248,   703, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   582, -1248,   584,   335, -1248,   625,   694,   587,
   -1248,   659, -1248, -1248, -1248, -1248,   704, -1248, -1248, -1248,
   -1248,   771,    30, -1248, -1248, -1248, -1248,   659, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   694,
     589, -1248,   659, -1248, -1248, -1248, -1248,   705, -1248, -1248,
     772,    48, -1248, -1248, -1248, -1248,   770,   564,   775,    14,
   -1248, -1248, -1248, -1248,   659, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   694,   596, -1248,   659, -1248,
   -1248, -1248, -1248,   709, -1248, -1248,   778,    44, -1248, -1248,
   -1248, -1248,   659, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,   694,   598, -1248,   659, -1248, -1248, -1248,
   -1248,   711, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   670,
   -1248,   682, -1248,   600, -1248,   659, -1248, -1248, -1248, -1248,
     680, -1248, -1248, -1248,   707, -1248,   781, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   644, -1248,   684, -1248,   602,
   -1248,   659, -1248, -1248, -1248, -1248,   685, -1248, -1248, -1248,
   -1248,   701, -1248,   691, -1248,   604, -1248,   659, -1248, -1248,
   -1248, -1248,   686, -1248, -1248, -1248, -1248, -1248,   659, -1248,
   -1248, -1248, -1248,   649, -1248, -1248, -1248, -1248,   695,   788,
     793, -1248, -1248, -1248,   659, -1248, -1248, -1248, -1248,   650,
   -1248, -1248, -1248, -1248, -1248,   659, -1248, -1248, -1248, -1248,
     651, -1248, -1248,   652, -1248, -1248, -1248, -1248, -1248,   653,
   -1248, -1248,   674, -1248, -1248, -1248, -1248, -1248, -1248, -1248
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   782, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248,   754, -1248, -1248, -1248,
   -1248,   698, -1248, -1248, -1248, -1248, -1248,   458, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,   442, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248,   723, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,   353, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
     676, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   285,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   581, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248,   231, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,   218, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
     349, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   120, -1248, -1248, -1248, -1248, -1248,    62, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,   -94, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,  -136, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248,  -337, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248,  -339, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248,  -120, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,  -303,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248,  -302, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248,  -156, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,  -355, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,  -357, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,   -39,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,  -186,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,   148, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248,    75, -1248, -1248, -1248, -1248,  -711, -1248, -1248,
   -1248,   -92, -1248, -1248, -1248,  -464, -1248, -1248, -1248,  -614,
   -1248, -1248, -1248,  -187, -1248, -1248, -1248,  -535, -1248, -1248,
   -1248,  -189, -1248,  -938,  -925,   -79,  -148, -1248, -1248, -1248,
     -90, -1248, -1248, -1248, -1248,  -598, -1248,  -824, -1248, -1056,
   -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248, -1248,
   -1248, -1248, -1248, -1248,  -309, -1247,  -151, -1248, -1248
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     233,   444,   199,   559,   740,   611,   201,  1178,   324,   230,
     329,   447,   864,   426,   429,  1010,   449,   338,  1375,   676,
    1376,  1377,   481,   704,   705,   227,   307,  1176,   478,   432,
     433,   484,   218,   212,  1375,    35,  1376,  1377,   241,   490,
     750,   420,   215,  1035,   224,   242,   700,   423,  1375,   221,
    1376,  1377,  1394,   344,   345,  1155,  1057,   487,   941,   346,
    1205,   759,   701,   760,   761,  1018,     6,  1019,  1020,   648,
    1082,   983,  1406,  1184,   687,  1124,   610,    11,   565,  1076,
     984,   243,  1156,   700,  1227,  1185,    36,   688,   469,     7,
     581,    13,    37,  1125,   306,  1115,    38,   582,    39,   701,
    1422,   315,  1126,   323,  1110,   328,   684,   244,   347,   621,
      40,   468,  1186,    27,  1255,   245,   759,  1139,   760,   761,
      41,   942,    42,   488,    14,   163,   622,   242,    43,   246,
     360,   247,  1395,   361,  1021,   421,  1420,   424,    67,  1157,
     647,   491,  1169,  1277,   452,   248,    44,   453,   762,   213,
      97,   249,  1378,   250,   151,   251,   751,   252,   225,   222,
     164,   526,   165,   243,   527,  1308,   154,   485,   155,   434,
     219,   228,   814,   231,   482,  1198,   430,   683,   479,   427,
    1077,   706,   216,   417,   308,   595,   458,   419,   596,   244,
     588,  1179,   185,  1344,   469,   590,   166,   245,   204,  1220,
     592,   205,  1404,   339,   340,   341,   342,   278,   463,   971,
     167,   246,   310,   247,   320,  1372,   325,   164,   330,   165,
     474,   475,   476,   477,   503,   337,   508,   248,   513,  1248,
     168,  1382,   352,   249,   353,   250,   169,   251,    75,   252,
     100,   101,     1,     2,   102,   103,  1391,   355,    76,   354,
      77,   742,    78,   166,    79,    76,   493,    77,  1270,    78,
     356,    79,   359,   100,   101,    36,   371,   167,  1408,   312,
     313,    37,   372,    17,    18,    38,  1295,    39,   373,   357,
    1301,   753,  1417,   374,   754,    22,    23,   168,  1018,    40,
    1019,  1020,   872,   169,   533,   873,  1424,   910,   358,    41,
     911,    42,    30,    31,    80,  1332,   380,    43,  1337,   407,
    1433,    80,   663,   664,   100,   101,   544,   545,   442,   502,
     445,   507,   450,   512,   459,    44,   347,  1360,   464,  1444,
    1365,   521,    70,    71,    81,   116,   117,   883,   121,   122,
    1046,    81,   360,   665,   666,   100,   101,   126,   127,   102,
     103,   312,   313,   995,   499,  1460,   131,   132,   136,   137,
     522,  1384,   141,   142,   100,   101,   544,   545,   738,   504,
     547,  1471,   555,   556,   509,   558,   146,   147,   100,   101,
    1046,   523,  1474,   857,   158,   159,   555,   556,   665,   666,
     100,   101,   544,   545,   187,   188,   514,  1410,  1480,   100,
     101,   524,    99,   525,   100,   101,   544,   545,   534,  1483,
    1046,   532,   555,   556,   100,   101,   206,   207,   102,   103,
     626,   627,   628,   629,   837,  1426,   234,   235,   537,   630,
     100,   101,   544,   545,   100,   101,   544,   545,   555,   556,
     280,   281,   555,   556,   285,   286,   677,   535,   609,   290,
     291,   295,   296,   300,   301,  1050,   973,   332,   333,   366,
     367,   536,   650,   452,   651,   652,   382,   383,   564,  1075,
     661,   387,   388,   392,   393,   397,   398,   402,   403,   437,
     438,   432,   433,   494,   495,   571,   516,   517,   541,   542,
     552,   553,   605,   606,  1108,   642,   643,   653,   654,   678,
     679,   719,   720,   724,   725,   733,   734,   777,   778,   799,
     800,   703,   646,   809,   810,   822,   823,   842,   843,   866,
     867,   887,   888,   893,   894,   578,  1049,   899,   900,   904,
     905,   922,   923,   928,   929,   711,   954,   955,   965,   966,
    1074,   675,  1041,  1042,  1059,  1060,  1067,  1068,   575,   682,
     577,   730,  1083,  1084,  1089,  1090,  1100,  1101,   732,  1116,
    1117,  1140,  1141,  1152,  1153,  1107,  1170,  1171,   699,  1199,
    1200,  1221,  1222,  1249,  1250,  1271,  1272,  1282,  1283,  1287,
    1288,  1302,  1303,  1311,  1312,  1319,  1320,   769,  1324,  1325,
    1338,  1339,  1347,  1348,  1352,  1353,   776,  1366,  1367,  1385,
    1386,   572,  1398,  1399,   576,   699,  1411,  1412,  1427,  1428,
    1438,  1439,  1454,  1455,  1465,  1466,   573,   574,   579,   580,
     593,   613,   798,   741,   601,   526,   612,   615,   614,   616,
     619,   634,   631,   581,   635,   636,   637,   595,   638,   658,
     816,   662,   686,   693,   821,   649,   685,   702,   709,   744,
     710,   688,   712,   832,   731,   716,   747,   773,   782,   770,
     787,   754,   791,   795,   783,   792,   804,   841,   827,   815,
     789,   805,   847,   817,   818,   837,   852,   828,   848,  1294,
     840,   854,   853,   857,   860,   871,   865,   834,   883,   909,
     917,   833,   880,   872,   813,   879,   878,   933,   940,   947,
     936,   950,   963,   975,   978,   982,   892,  1095,  1331,   991,
    1001,   961,   995,   941,   992,   999,   911,  1005,  1013,  1006,
     916,  1011,  1016,  1030,   955,  1031,  1037,  1039,   983,  1065,
    1359,  1053,   927,  1094,  1096,  1122,  1078,  1111,  1135,  1145,
    1098,  1151,  1146,  1177,  1183,  1165,  1194,  1206,  1125,  1124,
    1182,  1210,  1208,  1215,  1231,  1229,  1236,  1239,   960,  1157,
    1155,  1256,  1184,  1237,  1258,  1261,  1216,  1244,  1232,  1280,
    1259,  1266,  1185,  1278,  1309,  1345,  1373,  1374,  1393,  1392,
    1396,  1403,  1297,  1418,  1419,  1434,  1437,  1448,  1453,   998,
    1333,  1447,  1436,  1463,  1477,  1464,  1445,  1476,  1361,  1478,
      98,  1461,  1472,   211,    66,   465,   186,   460,   538,  1475,
    1481,  1484,  1015,  1207,   602,   632,   639,   729,   784,   962,
     566,  1012,  1238,  1241,  1000,  1209,  1485,  1488,   972,  1212,
    1038,  1036,  1452,  1260,  1263,   381,   918,  1099,   713,   790,
    1109,   974,  1052,     0,  1058,     0,     0,   279,  1489,     0,
    1064,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1088,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1121,     0,
       0,     0,     0,     0,     0,  1134,     0,     0,  1048,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1073,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1106,     0,     0,
       0,     0,     0,  1181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1228,     0,     0,     0,     0,     0,
    1235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1279,     0,     0,     0,  1281,
       0,     0,     0,     0,  1296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1446,     0,     0,     0,     0,  1449,  1450,     0,
       0,     0,  1451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1486,  1487
};

static const yytype_int16 yycheck[] =
{
     151,   310,    94,   467,   715,   540,    96,     4,   195,     4,
     197,   320,   836,     6,     4,   953,   325,     8,     4,   633,
       6,     7,     4,     6,     7,     4,     4,  1083,     4,     6,
       7,     4,     4,     4,     4,    56,     6,     7,    62,     4,
       4,     4,     4,   981,     4,    69,   660,     6,     4,     4,
       6,     7,     4,   204,   205,   103,   994,     4,   121,   108,
    1116,    65,   660,    67,    68,    65,     0,    67,    68,   604,
    1008,    91,  1319,    91,   138,   103,   540,    14,   137,  1004,
     100,   105,   130,   697,  1140,   103,   107,   151,   147,    55,
     163,    15,   113,   121,   184,  1033,   117,   170,   119,   697,
    1347,   193,   130,   195,  1029,   197,   641,   131,   157,    36,
     131,    64,   130,    59,  1170,   139,    65,  1055,    67,    68,
     141,   184,   143,    70,    57,    60,    53,    69,   149,   153,
     129,   155,    84,   132,   134,    98,    92,    96,    61,   187,
     604,   106,  1080,  1199,   129,   169,   167,   132,   152,   120,
      56,   175,   122,   177,    26,   179,   120,   181,   118,   114,
      95,   129,    97,   105,   132,  1221,    15,   140,    63,   146,
     142,   150,   786,   168,   156,  1113,   166,   641,   154,   172,
    1004,   164,   144,   275,   162,   129,   337,   277,   132,   131,
     499,   188,    58,  1249,   147,   504,   131,   139,     3,  1137,
     509,     3,   188,   194,   195,   196,   197,    60,   359,   920,
     145,   153,    10,   155,    10,  1271,    10,    95,    10,    97,
     371,   372,   373,   374,   411,     6,   413,   169,   415,  1167,
     165,  1287,   120,   175,   144,   177,   171,   179,    58,   181,
      43,    44,    12,    13,    47,    48,  1302,   114,    75,   142,
      77,   715,    79,   131,    81,    75,   407,    77,  1196,    79,
     118,    81,     6,    43,    44,   107,    17,   145,  1324,    49,
      50,   113,    23,    10,    11,   117,  1214,   119,    29,   150,
    1218,   154,  1338,    34,   157,    10,    11,   165,    65,   131,
      67,    68,   133,   171,   445,   136,  1352,   184,   168,   141,
     187,   143,    10,    11,   131,  1243,    62,   149,  1246,    32,
    1366,   131,    10,    11,    43,    44,    45,    46,   162,   411,
       3,   413,     6,   415,   108,   167,   157,  1265,   132,  1385,
    1268,    98,    10,    11,   161,    10,    11,    16,    10,    11,
      19,   161,   129,    41,    42,    43,    44,    10,    11,    47,
      48,    49,    50,    18,    10,  1411,    10,    11,    10,    11,
      96,  1299,    10,    11,    43,    44,    45,    46,    21,    10,
     462,  1427,    51,    52,    10,   467,    10,    11,    43,    44,
      19,   172,  1438,    22,    10,    11,    51,    52,    41,    42,
      43,    44,    45,    46,    10,    11,    10,  1335,  1454,    43,
      44,   166,    31,   146,    43,    44,    45,    46,    82,  1465,
      19,    80,    51,    52,    43,    44,    10,    11,    47,    48,
     571,   572,   573,   574,    33,  1363,    10,    11,   132,   580,
      43,    44,    45,    46,    43,    44,    45,    46,    51,    52,
      10,    11,    51,    52,    10,    11,   633,    78,   540,    10,
      11,    10,    11,    10,    11,   990,   920,    10,    11,    10,
      11,    76,   613,   129,   615,   616,    10,    11,    64,  1004,
     621,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     6,     7,    10,    11,     6,    10,    11,    10,    11,
      10,    11,    10,    11,  1029,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   662,   604,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    70,   990,    10,    11,    10,
      11,    10,    11,    10,    11,   686,   186,   187,    10,    11,
    1004,   633,    10,    11,    10,    11,    10,    11,   154,   641,
     140,   702,    10,    11,    10,    11,    10,    11,   709,    10,
      11,    10,    11,     6,     7,  1029,    10,    11,   660,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   738,    10,    11,
      10,    11,    10,    11,    10,    11,   747,    10,    11,    10,
      11,     6,    38,    39,   156,   697,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,     6,   106,     6,
       6,     3,   773,   715,   132,   129,   158,     3,   130,    30,
      10,   180,   170,   163,   182,   178,   176,   129,   132,   153,
     791,     3,     6,   119,   795,   130,   130,     6,     3,   123,
     130,   151,   138,   804,   164,   189,    28,    25,   120,    93,
       5,   157,     6,    24,   154,   135,     6,   818,     6,    66,
     152,   183,     6,   148,    27,    33,   827,   183,    99,  1214,
     158,    87,   124,    22,    87,     6,   837,   185,    16,     6,
     136,   190,    87,   133,   786,    94,   847,   129,     6,   129,
      85,    85,    37,   129,    85,     6,   857,  1016,  1243,    88,
      37,   184,    18,   121,    71,   184,   187,    88,    37,    71,
     871,   186,    10,    88,   187,    71,   100,    37,    91,    10,
    1265,    73,   883,     6,     5,    10,    73,    73,   115,     6,
     134,     6,    83,     6,    66,   115,   115,     6,   121,   103,
     188,    37,   130,     6,    86,    40,   122,    37,   909,   187,
     103,    86,    91,   130,   188,    37,   159,   159,   101,    92,
     130,   159,   103,    86,    72,    72,    72,     6,     6,    74,
      10,     6,   173,    74,     6,    74,   104,     6,   104,   940,
     173,    84,   122,    92,     6,   104,   116,   102,   173,     6,
      46,   116,   116,   105,    22,   363,    83,   349,   455,   160,
     160,   160,   963,  1122,   529,   584,   598,   697,   756,   913,
     471,   957,  1159,  1162,   944,  1128,   174,   174,   920,  1131,
     986,   982,   188,  1188,  1191,   254,   875,  1023,   690,   764,
    1029,   920,   990,    -1,   995,    -1,    -1,   171,   174,    -1,
    1001,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,
      -1,    -1,    -1,    -1,    -1,  1046,    -1,    -1,   990,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1029,    -1,    -1,
      -1,    -1,    -1,  1094,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1145,    -1,    -1,    -1,    -1,    -1,
    1151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1206,    -1,    -1,    -1,  1210,
      -1,    -1,    -1,    -1,  1215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1374,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1393,    -1,    -1,    -1,    -1,  1398,  1399,    -1,
      -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1419,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1477,  1478
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   199,   200,   201,     0,    55,   206,   207,
     208,    14,   202,    15,    57,   287,   288,    10,    11,   209,
     210,   211,    10,    11,   203,   204,   205,    59,   341,   342,
      10,    11,   289,   290,   291,    56,   107,   113,   117,   119,
     131,   141,   143,   149,   167,   212,   213,   214,   215,   216,
     231,   232,   237,   238,   243,   244,   249,   250,   255,   256,
     261,   262,   267,   268,   273,   274,   206,    61,   393,   394,
      10,    11,   343,   344,   345,    58,    75,    77,    79,    81,
     131,   161,   292,   293,   294,   295,   296,   301,   302,   308,
     309,   315,   316,   322,   323,   327,   328,    56,   214,    31,
      43,    44,    47,    48,   217,   218,   219,   879,   880,   881,
     882,   887,   888,   889,   890,   913,    10,    11,   233,   234,
     235,    10,    11,   239,   240,   241,    10,    11,   245,   246,
     247,    10,    11,   251,   252,   253,    10,    11,   257,   258,
     259,    10,    11,   263,   264,   265,    10,    11,   269,   270,
     271,    26,   275,   908,    15,    63,   488,   489,    10,    11,
     395,   396,   397,    60,    95,    97,   131,   145,   165,   171,
     346,   347,   348,   349,   350,   355,   356,   361,   362,   367,
     368,   373,   374,   379,   380,    58,   294,    10,    11,   297,
     298,   299,   303,   304,   310,   311,   317,   318,   324,   879,
     329,   908,   934,   935,     3,     3,    10,    11,   220,   221,
     222,   219,     4,   120,   236,     4,   144,   242,     4,   142,
     248,     4,   114,   254,     4,   118,   260,     4,   150,   266,
       4,   168,   272,   934,    10,    11,   276,   277,   278,   490,
     491,    62,    69,   105,   131,   139,   153,   155,   169,   175,
     177,   179,   181,   398,   399,   400,   401,   402,   407,   408,
     413,   414,   419,   420,   425,   426,   431,   432,   448,   449,
     455,   456,   462,   463,   469,   470,   474,   475,    60,   348,
      10,    11,   351,   352,   353,    10,    11,   357,   358,   359,
      10,    11,   363,   364,   365,    10,    11,   369,   370,   371,
      10,    11,   375,   376,   377,   381,   908,     4,   162,   300,
      10,   306,    49,    50,   305,   879,   891,   892,   893,   894,
      10,   313,   312,   879,   891,    10,   320,   319,   879,   891,
      10,   325,    10,    11,   330,   331,   332,     6,     8,   194,
     195,   196,   197,   936,   934,   934,   108,   157,   223,   224,
     225,   226,   120,   144,   142,   114,   118,   150,   168,     6,
     129,   132,   279,   280,   281,   282,    10,    11,   493,   494,
     495,    17,    23,    29,    34,   492,   900,   905,   911,   916,
      62,   400,    10,    11,   403,   404,   405,    10,    11,   409,
     410,   411,    10,    11,   415,   416,   417,    10,    11,   421,
     422,   423,    10,    11,   427,   428,   429,    32,   433,   914,
     450,   451,   457,   458,   464,   465,   471,   879,   476,   908,
       4,    98,   354,     6,    96,   360,     6,   172,   366,     4,
     166,   372,     6,     7,   146,   378,   932,    10,    11,   382,
     383,   384,   162,   307,   932,     3,   314,   932,   321,   932,
       6,   326,   129,   132,   333,   334,   335,   336,   934,   108,
     225,   227,   228,   934,   132,   281,   283,   284,    64,   147,
     496,   497,   498,   499,   934,   934,   934,   934,     4,   154,
     406,     4,   156,   412,     4,   140,   418,     4,    70,   424,
       4,   106,   430,   934,    10,    11,   434,   435,   436,    10,
     453,   452,   879,   891,    10,   460,   459,   879,   891,    10,
     467,   466,   879,   891,    10,   472,    10,    11,   477,   478,
     479,    98,    96,   172,   166,   146,   129,   132,   385,   386,
     387,   388,    80,   934,    82,    78,    76,   132,   335,   337,
     338,    10,    11,   230,    45,    46,   229,   879,   883,   884,
     885,   886,    10,    11,   286,    51,    52,   285,   879,   883,
     895,   896,   897,   898,    64,   137,   498,   852,   853,   500,
     501,     6,     6,     6,     6,   154,   156,   140,    70,   106,
       6,   163,   170,   437,   438,   439,   440,   454,   932,   461,
     932,   468,   932,     6,   473,   129,   132,   480,   481,   482,
     483,   132,   387,   389,   390,    10,    11,   340,   339,   879,
     883,   895,   158,     3,   130,     3,    30,   854,   912,    10,
     505,    36,    53,   502,   503,   504,   934,   934,   934,   934,
     934,   170,   439,   441,   180,   182,   178,   176,   132,   482,
     484,   485,    10,    11,   392,   391,   879,   883,   895,   130,
     934,   934,   934,    10,    11,   855,   856,   857,   153,   506,
     507,   934,     3,    10,    11,    41,    42,   442,   443,   444,
     445,   875,   876,   877,   878,   879,   887,   891,    10,    11,
     487,   486,   879,   883,   895,   130,     6,   138,   151,   858,
     859,   860,   861,   119,   522,   523,   508,   509,   510,   879,
     887,   913,     6,   934,     6,     7,   164,   446,   447,     3,
     130,   934,   138,   860,   862,   863,   189,   528,   529,    10,
      11,   524,   525,   526,    10,    11,   511,   512,   513,   510,
     934,   164,   934,    10,    11,   865,   866,   867,    21,   864,
     875,   879,   883,   903,   123,   638,   639,    28,   530,   910,
       4,   120,   527,   154,   157,   514,   515,   516,   517,    65,
      67,    68,   152,   868,   869,   870,   871,   872,   873,   934,
      93,   734,   735,    25,   640,   907,   934,    10,    11,   531,
     532,   533,   120,   154,   516,   518,   519,     5,   874,   152,
     870,     6,   135,   829,   830,    24,   736,   906,   934,    10,
      11,   641,   642,   643,     6,   183,   534,   535,   536,    10,
      11,   521,   520,   879,   887,    66,   934,   148,    27,   831,
     909,   934,    10,    11,   737,   738,   739,     6,   183,   644,
     645,   646,   934,   190,   185,   547,   548,    33,   537,   915,
     158,   934,    10,    11,   832,   833,   834,     6,    99,   740,
     741,   742,   934,   124,    87,   658,   659,    22,   647,   904,
      87,   562,   563,   549,   915,   934,    10,    11,   538,   539,
     540,     6,   133,   136,   835,   836,   837,   838,   934,    94,
      87,   753,   754,    16,   743,   899,   706,    10,    11,   660,
     661,   662,   934,    10,    11,   648,   649,   650,   610,    10,
      11,   564,   565,   566,    10,    11,   550,   551,   552,     6,
     184,   187,   541,   542,   543,   544,   934,   136,   837,   839,
     840,   801,    10,    11,   755,   756,   757,   934,    10,    11,
     744,   745,   746,   129,   707,   708,    85,   663,   664,   665,
       6,   121,   184,   651,   652,   653,   654,   129,   611,   612,
      85,   567,   568,   569,   186,   187,   553,   554,   555,   556,
     934,   184,   543,    37,   545,    10,    11,   842,   843,   844,
     841,   875,   879,   883,   903,   129,   802,   803,    85,   758,
     759,   760,     6,    91,   100,   747,   748,   749,   750,   709,
     710,    88,    71,   671,   672,    18,   666,   901,   934,   184,
     653,    37,   655,   613,   614,    88,    71,   575,   576,   570,
     901,   186,   555,    37,   557,   934,    10,   546,    65,    67,
      68,   134,   845,   846,   847,   848,   849,   850,   804,   805,
      88,    71,   766,   767,   761,   901,   934,   100,   749,    37,
     751,    10,    11,   712,   713,   714,    19,   711,   879,   883,
     895,   902,   904,    73,   678,   679,   673,   901,   934,    10,
      11,   667,   668,   669,   934,    10,   656,    10,    11,   616,
     617,   618,   615,   879,   883,   895,   902,   915,    73,   582,
     583,   577,   901,    10,    11,   571,   572,   573,   934,    10,
      11,   558,   559,   560,     6,   932,     5,   851,   134,   847,
      10,    11,   807,   808,   809,   806,   879,   883,   895,   899,
     902,    73,   773,   774,   768,   901,    10,    11,   762,   763,
     764,   934,    10,   752,   103,   121,   130,   715,   716,   717,
     718,   724,   725,   726,   934,   115,   685,   686,   680,   901,
      10,    11,   674,   675,   676,     6,    83,   670,   917,   918,
     925,     6,     6,     7,   657,   103,   130,   187,   619,   620,
     621,   622,   628,   629,   630,   115,   589,   590,   584,   901,
      10,    11,   578,   579,   580,   574,   917,     6,     4,   188,
     561,   934,   188,    66,    91,   103,   130,   810,   811,   812,
     813,   819,   820,   821,   115,   780,   781,   775,   901,    10,
      11,   769,   770,   771,   765,   917,     6,   932,   130,   717,
      37,   719,   725,   727,   728,     6,   159,   692,   693,   687,
     901,    10,    11,   681,   682,   683,   677,   917,   934,    40,
     926,    86,   101,   919,   920,   934,   122,   130,   621,    37,
     623,   629,   631,   632,   159,   596,   597,   591,   901,    10,
      11,   585,   586,   587,   581,   917,    86,   934,   188,   130,
     812,    37,   814,   820,   822,   823,   159,   787,   788,   782,
     901,    10,    11,   776,   777,   778,   772,   917,    86,   934,
      92,   934,    10,    11,   720,   721,   722,    10,    11,   730,
     731,   732,   729,   879,   895,   901,   934,   173,   699,   700,
     694,   901,    10,    11,   688,   689,   690,   684,   917,    72,
     934,    10,    11,   927,   928,   929,   921,   922,   934,    10,
      11,   624,   625,   626,    10,    11,   634,   635,   636,   633,
     879,   895,   901,   173,   603,   604,   598,   901,    10,    11,
     592,   593,   594,   588,   917,    72,   934,    10,    11,   815,
     816,   817,    10,    11,   825,   826,   827,   824,   879,   895,
     901,   173,   794,   795,   789,   901,    10,    11,   783,   784,
     785,   779,   917,    72,     6,     4,     6,     7,   122,   723,
     933,   733,   917,   701,   901,    10,    11,   695,   696,   697,
     691,   917,    74,     6,     4,    84,    10,   924,    38,    39,
     923,   930,   931,     6,   188,   627,   933,   637,   917,   605,
     901,    10,    11,   599,   600,   601,   595,   917,    74,     6,
      92,   818,   933,   828,   917,   796,   901,    10,    11,   790,
     791,   792,   786,   917,    74,   934,   122,   104,    10,    11,
     702,   703,   704,   698,   917,   116,   934,    84,     6,   934,
     934,   934,   188,   104,    10,    11,   606,   607,   608,   602,
     917,   116,   934,    92,   104,    10,    11,   797,   798,   799,
     793,   917,   116,   705,   917,   160,   102,     6,     6,   609,
     917,   160,   800,   917,   160,   174,   934,   934,   174,   174
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

  case 34:

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

  case 35:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 38:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	;}
    break;

  case 39:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 40:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 41:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 42:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 49:

    {	parserData->kounter++;
;}
    break;

  case 50:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 51:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
;}
    break;

  case 54:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	;}
    break;

  case 55:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	;}
    break;

  case 59:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 65:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 67:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 73:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 75:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 81:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 83:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 89:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 91:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 97:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 99:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 105:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 107:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 113:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 115:

    {	if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	;}
    break;

  case 116:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 117:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 118:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 125:

    {	parserData->kounter++;
;}
    break;

  case 126:

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

  case 127:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 130:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	;}
    break;

  case 131:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	;}
    break;

  case 132:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	;}
    break;

  case 153:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 159:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	;}
    break;

  case 161:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 165:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 166:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 168:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 170:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 174:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 175:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 177:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 179:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 183:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 184:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 186:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 188:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 190:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 192:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 194:

    {	if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	;}
    break;

  case 195:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 196:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 197:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 204:

    {	parserData->kounter++;
;}
    break;

  case 205:

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

  case 206:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 209:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	;}
    break;

  case 210:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	;}
    break;

  case 211:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	;}
    break;

  case 232:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 238:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 240:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 246:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 248:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 254:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 256:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 262:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 264:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 270:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
;}
    break;

  case 272:

    {	if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	;}
    break;

  case 273:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 274:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 275:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 282:

    {	parserData->kounter++;
;}
    break;

  case 283:

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

  case 284:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 287:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	;}
    break;

  case 288:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	;}
    break;

  case 289:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	;}
    break;

  case 315:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 321:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	;}
    break;

  case 323:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 329:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 331:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 337:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 339:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 345:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 347:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 353:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 355:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 356:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
;}
    break;

  case 357:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	;}
    break;

  case 358:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	;}
    break;

  case 366:

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

  case 378:

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

  case 379:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 380:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 382:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 386:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 387:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 389:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 391:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 395:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 396:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 398:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 400:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 404:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 405:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 407:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 409:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 411:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 413:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 415:

    {	if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	;}
    break;

  case 416:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 417:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 418:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 425:

    {	parserData->kounter++;
;}
    break;

  case 426:

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

  case 427:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 430:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	;}
    break;

  case 431:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	;}
    break;

  case 432:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	;}
    break;

  case 437:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 438:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
;}
    break;

  case 441:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	;}
    break;

  case 442:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	;}
    break;

  case 443:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	;}
    break;

  case 444:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	;}
    break;

  case 445:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	;}
    break;

  case 446:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	;}
    break;

  case 454:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 460:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 ;}
    break;

  case 461:

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

  case 462:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 464:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 465:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	;}
    break;

  case 468:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	;}
    break;

  case 469:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	;}
    break;

  case 470:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 471:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 472:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 479:

    {	parserData->kounter++; ;}
    break;

  case 480:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 481:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
;}
    break;

  case 484:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	;}
    break;

  case 485:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	;}
    break;

  case 496:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	;}
    break;

  case 499:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 501:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
;}
    break;

  case 510:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
;}
    break;

  case 511:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 512:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 519:

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 520:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 521:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 526:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 527:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 528:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 535:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 536:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 537:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 538:

    {parserData->tempStr = "";;}
    break;

  case 543:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 553:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 555:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 562:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 564:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 571:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 573:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 580:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 582:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 589:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 591:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 598:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 600:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 608:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 609:

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

  case 610:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 613:

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

  case 614:

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

  case 615:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 616:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 617:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 627:

    { 	
	parserData->kounter++;
;}
    break;

  case 629:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
;}
    break;

  case 635:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 638:

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

  case 639:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 640:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 643:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 644:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 645:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 653:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 655:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 664:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 665:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 666:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 673:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 674:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 676:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 678:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 679:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 689:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 691:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 698:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 700:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 707:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 709:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 716:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 718:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 725:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 727:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 734:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 736:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 744:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 745:

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

  case 746:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 749:

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

  case 750:

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

  case 751:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 752:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 753:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 763:

    {  
	parserData->kounter++;
;}
    break;

  case 765:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
;}
    break;

  case 771:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 774:

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

  case 775:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 776:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 779:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 780:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 781:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 789:

    {	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 791:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 799:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 800:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 801:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 802:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 809:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 810:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
;}
    break;

  case 811:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 822:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 824:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 831:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 833:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 840:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 842:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 849:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 851:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 858:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 860:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 867:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 869:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 877:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 878:

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

  case 879:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 882:

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

  case 883:

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

  case 884:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 885:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 886:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 896:

    { 	
	parserData->kounter++;
;}
    break;

  case 898:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
;}
    break;

  case 904:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 907:

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

  case 908:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 909:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 912:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 913:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 914:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 922:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 923:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 924:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 925:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 932:

    {	parserData->iOther++;
;}
    break;

  case 933:

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

  case 934:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 937:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 938:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 939:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 940:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 941:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 942:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 949:

    {	parserData->kounter++;
;}
    break;

  case 950:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 955:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 958:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 959:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 960:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 961:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 968:

    {	parserData->iOther++;
;}
    break;

  case 969:

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

  case 970:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 973:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 974:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 975:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 976:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 977:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 978:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 985:

    {	parserData->kounter++;
;}
    break;

  case 986:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 991:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 992:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 995:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 996:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 997:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 1000:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1001:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1002:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1005:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1006:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1007:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1010:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1011:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1012:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1015:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1016:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1017:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1020:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1021:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1022:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1023:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1024:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1025:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1026:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1027:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1028:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1029:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1030:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1031:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1032:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1033:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1034:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1035:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1036:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1037:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1038:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1039:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1040:

    {
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1045:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1051:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1053:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1058:

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

  case 1059:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1060:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1061:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1062:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1063:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1064:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1065:

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

