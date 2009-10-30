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
     NUMBEROFCONATT = 267,
     NUMBEROFCONSTRAINTSATT = 268,
     NUMBEROFITEMSATT = 269,
     NUMBEROFOBJATT = 270,
     NUMBEROFOBJECTIVESATT = 271,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 272,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 273,
     NUMBEROFOTHERRESULTSATT = 274,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 275,
     NUMBEROFOTHERVARIABLERESULTSATT = 276,
     NUMBEROFSOLUTIONSATT = 277,
     NUMBEROFSOLVEROUTPUTSATT = 278,
     NUMBEROFSUBSTATUSESATT = 279,
     NUMBEROFTIMESATT = 280,
     NUMBEROFVARATT = 281,
     NUMBEROFVARIABLESATT = 282,
     TARGETOBJECTIVEIDXATT = 283,
     IDXATT = 284,
     CATEGORYATT = 285,
     EMPTYCATEGORYATT = 286,
     DESCRIPTIONATT = 287,
     EMPTYDESCRIPTIONATT = 288,
     NAMEATT = 289,
     EMPTYNAMEATT = 290,
     TYPEATT = 291,
     EMPTYTYPEATT = 292,
     UNITATT = 293,
     EMPTYUNITATT = 294,
     VALUEATT = 295,
     EMPTYVALUEATT = 296,
     WEIGHTEDOBJECTIVESATT = 297,
     EMPTYWEIGHTEDOBJECTIVESATT = 298,
     OSRLSTART = 299,
     OSRLSTARTEMPTY = 300,
     OSRLATTRIBUTETEXT = 301,
     OSRLEND = 302,
     GENERALSTART = 303,
     GENERALEND = 304,
     SYSTEMSTART = 305,
     SYSTEMEND = 306,
     SERVICESTART = 307,
     SERVICEEND = 308,
     JOBSTART = 309,
     JOBEND = 310,
     OPTIMIZATIONSTART = 311,
     OPTIMIZATIONEND = 312,
     ITEMSTART = 313,
     ITEMEND = 314,
     ITEMSTARTANDEND = 315,
     ITEMEMPTY = 316,
     ACTUALSTARTTIMESTART = 317,
     ACTUALSTARTTIMEEND = 318,
     AVAILABLECPUNUMBERSTART = 319,
     AVAILABLECPUNUMBEREND = 320,
     AVAILABLECPUSPEEDSTART = 321,
     AVAILABLECPUSPEEDEND = 322,
     AVAILABLEDISKSPACESTART = 323,
     AVAILABLEDISKSPACEEND = 324,
     AVAILABLEMEMORYSTART = 325,
     AVAILABLEMEMORYEND = 326,
     BASISSTATUSSTART = 327,
     BASISSTATUSEND = 328,
     BASSTATUSSTART = 329,
     BASSTATUSEND = 330,
     CONSTART = 331,
     CONEND = 332,
     CONSTRAINTSSTART = 333,
     CONSTRAINTSEND = 334,
     CURRENTJOBCOUNTSTART = 335,
     CURRENTJOBCOUNTEND = 336,
     CURRENTSTATESTART = 337,
     CURRENTSTATEEND = 338,
     DUALVALUESSTART = 339,
     DUALVALUESEND = 340,
     ENDTIMESTART = 341,
     ENDTIMEEND = 342,
     GENERALSTATUSSTART = 343,
     GENERALSTATUSEND = 344,
     GENERALSUBSTATUSSTART = 345,
     GENERALSUBSTATUSEND = 346,
     INSTANCENAMESTART = 347,
     INSTANCENAMEEND = 348,
     JOBIDSTART = 349,
     JOBIDEND = 350,
     MESSAGESTART = 351,
     MESSAGEEND = 352,
     OBJSTART = 353,
     OBJEND = 354,
     OBJECTIVESSTART = 355,
     OBJECTIVESEND = 356,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 357,
     OPTIMIZATIONSOLUTIONSTATUSEND = 358,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 359,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 360,
     OTHERSTART = 361,
     OTHEREND = 362,
     OTHERRESULTSSTART = 363,
     OTHERRESULTSEND = 364,
     OTHERSOLUTIONRESULTSTART = 365,
     OTHERSOLUTIONRESULTEND = 366,
     OTHERSOLUTIONRESULTSSTART = 367,
     OTHERSOLUTIONRESULTSEND = 368,
     OTHERSOLVEROUTPUTSTART = 369,
     OTHERSOLVEROUTPUTEND = 370,
     SCHEDULEDSTARTTIMESTART = 371,
     SCHEDULEDSTARTTIMEEND = 372,
     SERVICENAMESTART = 373,
     SERVICENAMEEND = 374,
     SERVICEURISTART = 375,
     SERVICEURIEND = 376,
     SERVICEUTILIZATIONSTART = 377,
     SERVICEUTILIZATIONEND = 378,
     SOLUTIONSTART = 379,
     SOLUTIONEND = 380,
     SOLVERINVOKEDSTART = 381,
     SOLVERINVOKEDEND = 382,
     SOLVEROUTPUTSTART = 383,
     SOLVEROUTPUTEND = 384,
     STATUSSTART = 385,
     STATUSEND = 386,
     SUBMITTIMESTART = 387,
     SUBMITTIMEEND = 388,
     SUBSTATUSSTART = 389,
     SUBSTATUSEND = 390,
     SYSTEMINFORMATIONSTART = 391,
     SYSTEMINFORMATIONEND = 392,
     TIMESTART = 393,
     TIMEEND = 394,
     TIMESERVICESTARTEDSTART = 395,
     TIMESERVICESTARTEDEND = 396,
     TIMESTAMPSTART = 397,
     TIMESTAMPEND = 398,
     TIMINGINFORMATIONSTART = 399,
     TIMINGINFORMATIONEND = 400,
     TOTALJOBSSOFARSTART = 401,
     TOTALJOBSSOFAREND = 402,
     USEDCPUNUMBERSTART = 403,
     USEDCPUNUMBEREND = 404,
     USEDCPUSPEEDSTART = 405,
     USEDCPUSPEEDEND = 406,
     USEDDISKSPACESTART = 407,
     USEDDISKSPACEEND = 408,
     USEDMEMORYSTART = 409,
     USEDMEMORYEND = 410,
     VALUESSTART = 411,
     VALUESEND = 412,
     VALUESSTRINGSTART = 413,
     VALUESSTRINGEND = 414,
     VARSTART = 415,
     VAREND = 416,
     VARIABLESSTART = 417,
     VARIABLESEND = 418,
     DUMMY = 419
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
#define NUMBEROFCONATT 267
#define NUMBEROFCONSTRAINTSATT 268
#define NUMBEROFITEMSATT 269
#define NUMBEROFOBJATT 270
#define NUMBEROFOBJECTIVESATT 271
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 272
#define NUMBEROFOTHEROBJECTIVERESULTSATT 273
#define NUMBEROFOTHERRESULTSATT 274
#define NUMBEROFOTHERSOLUTIONRESULTSATT 275
#define NUMBEROFOTHERVARIABLERESULTSATT 276
#define NUMBEROFSOLUTIONSATT 277
#define NUMBEROFSOLVEROUTPUTSATT 278
#define NUMBEROFSUBSTATUSESATT 279
#define NUMBEROFTIMESATT 280
#define NUMBEROFVARATT 281
#define NUMBEROFVARIABLESATT 282
#define TARGETOBJECTIVEIDXATT 283
#define IDXATT 284
#define CATEGORYATT 285
#define EMPTYCATEGORYATT 286
#define DESCRIPTIONATT 287
#define EMPTYDESCRIPTIONATT 288
#define NAMEATT 289
#define EMPTYNAMEATT 290
#define TYPEATT 291
#define EMPTYTYPEATT 292
#define UNITATT 293
#define EMPTYUNITATT 294
#define VALUEATT 295
#define EMPTYVALUEATT 296
#define WEIGHTEDOBJECTIVESATT 297
#define EMPTYWEIGHTEDOBJECTIVESATT 298
#define OSRLSTART 299
#define OSRLSTARTEMPTY 300
#define OSRLATTRIBUTETEXT 301
#define OSRLEND 302
#define GENERALSTART 303
#define GENERALEND 304
#define SYSTEMSTART 305
#define SYSTEMEND 306
#define SERVICESTART 307
#define SERVICEEND 308
#define JOBSTART 309
#define JOBEND 310
#define OPTIMIZATIONSTART 311
#define OPTIMIZATIONEND 312
#define ITEMSTART 313
#define ITEMEND 314
#define ITEMSTARTANDEND 315
#define ITEMEMPTY 316
#define ACTUALSTARTTIMESTART 317
#define ACTUALSTARTTIMEEND 318
#define AVAILABLECPUNUMBERSTART 319
#define AVAILABLECPUNUMBEREND 320
#define AVAILABLECPUSPEEDSTART 321
#define AVAILABLECPUSPEEDEND 322
#define AVAILABLEDISKSPACESTART 323
#define AVAILABLEDISKSPACEEND 324
#define AVAILABLEMEMORYSTART 325
#define AVAILABLEMEMORYEND 326
#define BASISSTATUSSTART 327
#define BASISSTATUSEND 328
#define BASSTATUSSTART 329
#define BASSTATUSEND 330
#define CONSTART 331
#define CONEND 332
#define CONSTRAINTSSTART 333
#define CONSTRAINTSEND 334
#define CURRENTJOBCOUNTSTART 335
#define CURRENTJOBCOUNTEND 336
#define CURRENTSTATESTART 337
#define CURRENTSTATEEND 338
#define DUALVALUESSTART 339
#define DUALVALUESEND 340
#define ENDTIMESTART 341
#define ENDTIMEEND 342
#define GENERALSTATUSSTART 343
#define GENERALSTATUSEND 344
#define GENERALSUBSTATUSSTART 345
#define GENERALSUBSTATUSEND 346
#define INSTANCENAMESTART 347
#define INSTANCENAMEEND 348
#define JOBIDSTART 349
#define JOBIDEND 350
#define MESSAGESTART 351
#define MESSAGEEND 352
#define OBJSTART 353
#define OBJEND 354
#define OBJECTIVESSTART 355
#define OBJECTIVESEND 356
#define OPTIMIZATIONSOLUTIONSTATUSSTART 357
#define OPTIMIZATIONSOLUTIONSTATUSEND 358
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 359
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 360
#define OTHERSTART 361
#define OTHEREND 362
#define OTHERRESULTSSTART 363
#define OTHERRESULTSEND 364
#define OTHERSOLUTIONRESULTSTART 365
#define OTHERSOLUTIONRESULTEND 366
#define OTHERSOLUTIONRESULTSSTART 367
#define OTHERSOLUTIONRESULTSEND 368
#define OTHERSOLVEROUTPUTSTART 369
#define OTHERSOLVEROUTPUTEND 370
#define SCHEDULEDSTARTTIMESTART 371
#define SCHEDULEDSTARTTIMEEND 372
#define SERVICENAMESTART 373
#define SERVICENAMEEND 374
#define SERVICEURISTART 375
#define SERVICEURIEND 376
#define SERVICEUTILIZATIONSTART 377
#define SERVICEUTILIZATIONEND 378
#define SOLUTIONSTART 379
#define SOLUTIONEND 380
#define SOLVERINVOKEDSTART 381
#define SOLVERINVOKEDEND 382
#define SOLVEROUTPUTSTART 383
#define SOLVEROUTPUTEND 384
#define STATUSSTART 385
#define STATUSEND 386
#define SUBMITTIMESTART 387
#define SUBMITTIMEEND 388
#define SUBSTATUSSTART 389
#define SUBSTATUSEND 390
#define SYSTEMINFORMATIONSTART 391
#define SYSTEMINFORMATIONEND 392
#define TIMESTART 393
#define TIMEEND 394
#define TIMESERVICESTARTEDSTART 395
#define TIMESERVICESTARTEDEND 396
#define TIMESTAMPSTART 397
#define TIMESTAMPEND 398
#define TIMINGINFORMATIONSTART 399
#define TIMINGINFORMATIONEND 400
#define TOTALJOBSSOFARSTART 401
#define TOTALJOBSSOFAREND 402
#define USEDCPUNUMBERSTART 403
#define USEDCPUNUMBEREND 404
#define USEDCPUSPEEDSTART 405
#define USEDCPUSPEEDEND 406
#define USEDDISKSPACESTART 407
#define USEDDISKSPACEEND 408
#define USEDMEMORYSTART 409
#define USEDMEMORYEND 410
#define VALUESSTART 411
#define VALUESEND 412
#define VALUESSTRINGSTART 413
#define VALUESSTRINGEND 414
#define VARSTART 415
#define VAREND 416
#define VARIABLESSTART 417
#define VARIABLESEND 418
#define DUMMY 419




/* Copy the first part of user declarations.  */



 
#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
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
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData ) throw(ErrorClass);
void osrl_empty_vectors( OSrLParserData* parserData);




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



void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg );
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   988

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  547
/* YYNRULES -- Number of rules.  */
#define YYNRULES  819
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   166,
     168,     2,     2,   167,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   165,     2,     2,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    10,    12,    16,    22,    23,
      26,    28,    30,    32,    35,    37,    41,    43,    45,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    70,
      72,    74,    76,    79,    81,    83,    85,    87,    89,    92,
      94,    98,   100,   102,   105,   109,   111,   113,   114,   117,
     119,   121,   124,   126,   129,   131,   133,   135,   138,   140,
     144,   146,   149,   151,   153,   155,   158,   160,   164,   166,
     169,   171,   173,   175,   178,   180,   184,   186,   189,   191,
     193,   195,   198,   200,   204,   206,   209,   211,   213,   215,
     218,   220,   224,   226,   229,   231,   233,   235,   238,   240,
     244,   246,   249,   251,   253,   255,   258,   260,   264,   266,
     270,   272,   274,   276,   278,   281,   283,   287,   289,   291,
     294,   298,   300,   302,   303,   306,   308,   310,   312,   315,
     317,   318,   321,   323,   325,   327,   330,   332,   336,   338,
     340,   343,   345,   347,   349,   351,   353,   355,   358,   360,
     362,   364,   367,   369,   373,   375,   379,   381,   383,   384,
     387,   389,   391,   395,   397,   399,   403,   405,   407,   408,
     411,   413,   415,   419,   421,   423,   427,   429,   431,   432,
     435,   437,   439,   443,   445,   447,   451,   453,   454,   456,
     460,   462,   466,   468,   470,   472,   474,   477,   479,   483,
     485,   487,   490,   494,   496,   498,   499,   502,   504,   506,
     508,   511,   513,   514,   517,   522,   523,   526,   528,   530,
     532,   534,   536,   538,   541,   543,   545,   547,   550,   552,
     556,   558,   561,   563,   565,   567,   570,   572,   576,   578,
     581,   583,   585,   587,   590,   592,   596,   598,   601,   603,
     605,   607,   610,   612,   616,   618,   621,   623,   625,   627,
     630,   632,   636,   638,   642,   644,   646,   648,   650,   653,
     655,   659,   661,   663,   666,   670,   672,   674,   675,   678,
     680,   682,   684,   687,   689,   690,   693,   698,   699,   702,
     704,   706,   708,   710,   712,   714,   716,   718,   720,   722,
     724,   727,   729,   731,   733,   736,   738,   742,   744,   747,
     749,   751,   753,   756,   758,   762,   764,   767,   769,   771,
     773,   776,   778,   782,   784,   787,   789,   791,   793,   796,
     798,   802,   804,   807,   809,   811,   813,   816,   818,   822,
     824,   828,   830,   832,   834,   836,   839,   841,   845,   847,
     849,   852,   856,   858,   859,   862,   864,   866,   868,   870,
     872,   874,   877,   879,   883,   885,   887,   889,   893,   895,
     897,   898,   901,   903,   905,   909,   911,   913,   917,   919,
     921,   922,   925,   927,   929,   933,   935,   937,   941,   943,
     945,   946,   949,   951,   953,   957,   959,   961,   965,   967,
     968,   970,   974,   976,   980,   982,   984,   986,   988,   991,
     993,   997,   999,  1001,  1004,  1008,  1010,  1012,  1013,  1016,
    1018,  1020,  1022,  1025,  1027,  1028,  1032,  1034,  1036,  1037,
    1040,  1042,  1044,  1046,  1048,  1050,  1052,  1055,  1057,  1061,
    1064,  1066,  1069,  1073,  1075,  1077,  1078,  1081,  1083,  1085,
    1090,  1094,  1103,  1107,  1109,  1111,  1113,  1116,  1118,  1120,
    1122,  1124,  1126,  1129,  1131,  1135,  1137,  1139,  1142,  1146,
    1148,  1150,  1151,  1154,  1156,  1158,  1161,  1163,  1164,  1167,
    1169,  1171,  1173,  1176,  1178,  1182,  1184,  1185,  1189,  1191,
    1192,  1194,  1196,  1198,  1200,  1204,  1209,  1210,  1214,  1216,
    1218,  1220,  1222,  1225,  1227,  1231,  1233,  1235,  1238,  1242,
    1244,  1249,  1253,  1255,  1257,  1258,  1262,  1264,  1266,  1268,
    1270,  1273,  1275,  1279,  1281,  1283,  1286,  1290,  1292,  1297,
    1299,  1301,  1304,  1306,  1310,  1312,  1313,  1317,  1319,  1321,
    1323,  1325,  1328,  1330,  1334,  1336,  1338,  1341,  1345,  1347,
    1352,  1356,  1357,  1360,  1364,  1366,  1368,  1369,  1372,  1374,
    1376,  1378,  1380,  1382,  1384,  1387,  1389,  1393,  1395,  1397,
    1400,  1404,  1406,  1411,  1413,  1415,  1418,  1420,  1424,  1426,
    1427,  1431,  1433,  1434,  1436,  1438,  1440,  1442,  1446,  1449,
    1450,  1454,  1456,  1458,  1460,  1462,  1465,  1467,  1471,  1473,
    1475,  1478,  1482,  1484,  1485,  1490,  1494,  1496,  1498,  1499,
    1502,  1506,  1508,  1510,  1511,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1529,  1531,  1535,  1537,  1539,  1542,  1546,  1548,
    1553,  1555,  1557,  1560,  1562,  1566,  1568,  1569,  1573,  1575,
    1576,  1578,  1580,  1582,  1584,  1588,  1591,  1592,  1596,  1598,
    1600,  1602,  1604,  1607,  1609,  1613,  1615,  1617,  1620,  1626,
    1628,  1633,  1635,  1637,  1638,  1641,  1645,  1647,  1649,  1650,
    1653,  1655,  1657,  1659,  1661,  1663,  1665,  1668,  1670,  1674,
    1676,  1678,  1681,  1685,  1687,  1692,  1694,  1696,  1699,  1701,
    1705,  1707,  1708,  1712,  1714,  1716,  1718,  1720,  1723,  1725,
    1729,  1731,  1733,  1736,  1740,  1742,  1744,  1745,  1748,  1750,
    1752,  1754,  1756,  1758,  1760,  1763,  1765,  1769,  1771,  1773,
    1776,  1778,  1780,  1782,  1784,  1786,  1790,  1792,  1793,  1797,
    1799,  1801,  1803,  1805,  1808,  1810,  1814,  1816,  1818,  1821,
    1825,  1827,  1829,  1830,  1833,  1835,  1837,  1839,  1841,  1843,
    1845,  1848,  1850,  1854,  1856,  1858,  1861,  1863,  1865,  1867,
    1869,  1871,  1875,  1877,  1879,  1881,  1883,  1887,  1889,  1891,
    1893,  1895,  1899,  1901,  1903,  1905,  1907,  1911,  1913,  1915,
    1917,  1919,  1923,  1925,  1927,  1929,  1931,  1935,  1937,  1939,
    1941,  1943,  1947,  1952,  1957,  1962,  1967,  1972,  1977,  1982,
    1987,  1992,  1997,  2002,  2007,  2012,  2017,  2022,  2027,  2029,
    2031,  2033,  2035,  2037,  2040,  2041,  2044,  2046,  2048,  2050
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   173,    -1,    44,    -1,    -1,
      46,    -1,    10,   174,    47,    -1,   175,   255,   309,   356,
     446,    -1,    -1,   176,   177,    -1,    48,    -1,   178,    -1,
     179,    -1,    10,    49,    -1,    11,    -1,    10,   180,    49,
      -1,   181,    -1,   182,    -1,   181,   182,    -1,   183,    -1,
     199,    -1,   205,    -1,   211,    -1,   217,    -1,   223,    -1,
     229,    -1,   235,    -1,   241,    -1,   184,   185,   188,    -1,
      88,    -1,   186,    -1,   187,    -1,   186,   187,    -1,   683,
      -1,   675,    -1,   710,    -1,   189,    -1,   190,    -1,    10,
      89,    -1,    11,    -1,    10,   191,    89,    -1,   192,    -1,
     193,    -1,   192,   193,    -1,   194,   195,   198,    -1,   134,
      -1,   196,    -1,    -1,   196,   197,    -1,   679,    -1,   675,
      -1,    10,   135,    -1,    11,    -1,   200,   201,    -1,    96,
      -1,   202,    -1,   203,    -1,    10,    97,    -1,    11,    -1,
      10,   204,    97,    -1,     4,    -1,   206,   207,    -1,   120,
      -1,   208,    -1,   209,    -1,    10,   121,    -1,    11,    -1,
      10,   210,   121,    -1,     4,    -1,   212,   213,    -1,   118,
      -1,   214,    -1,   215,    -1,    10,   119,    -1,    11,    -1,
      10,   216,   119,    -1,     4,    -1,   218,   219,    -1,    92,
      -1,   220,    -1,   221,    -1,    10,    93,    -1,    11,    -1,
      10,   222,    93,    -1,     4,    -1,   224,   225,    -1,    94,
      -1,   226,    -1,   227,    -1,    10,    95,    -1,    11,    -1,
      10,   228,    95,    -1,     4,    -1,   230,   231,    -1,   126,
      -1,   232,    -1,   233,    -1,    10,   127,    -1,    11,    -1,
      10,   234,   127,    -1,     4,    -1,   236,   237,    -1,   142,
      -1,   238,    -1,   239,    -1,    10,   143,    -1,    11,    -1,
      10,   240,   143,    -1,     4,    -1,   242,   243,   244,    -1,
     108,    -1,   695,    -1,   245,    -1,   246,    -1,    10,   109,
      -1,    11,    -1,    10,   247,   109,    -1,   248,    -1,   249,
      -1,   248,   249,    -1,   250,   251,   254,    -1,   106,    -1,
     252,    -1,    -1,   252,   253,    -1,   679,    -1,   691,    -1,
     675,    -1,    10,   107,    -1,    11,    -1,    -1,   256,   257,
      -1,    50,    -1,   258,    -1,   259,    -1,    10,    51,    -1,
      11,    -1,    10,   260,    51,    -1,   261,    -1,   262,    -1,
     261,   262,    -1,   263,    -1,   269,    -1,   276,    -1,   283,
      -1,   290,    -1,   295,    -1,   264,   265,    -1,   136,    -1,
     266,    -1,   267,    -1,    10,   137,    -1,    11,    -1,    10,
     268,   137,    -1,     4,    -1,   270,   271,   274,    -1,    68,
      -1,   272,    -1,    -1,   272,   273,    -1,   687,    -1,   675,
      -1,    10,   275,    69,    -1,     6,    -1,     7,    -1,   277,
     278,   281,    -1,    70,    -1,   279,    -1,    -1,   279,   280,
      -1,   687,    -1,   675,    -1,    10,   282,    71,    -1,     6,
      -1,     7,    -1,   284,   285,   288,    -1,    66,    -1,   286,
      -1,    -1,   286,   287,    -1,   687,    -1,   675,    -1,    10,
     289,    67,    -1,     6,    -1,     7,    -1,   291,   292,   293,
      -1,    64,    -1,    -1,   675,    -1,    10,   294,    65,    -1,
       6,    -1,   296,   297,   298,    -1,   108,    -1,   695,    -1,
     299,    -1,   300,    -1,    10,   109,    -1,    11,    -1,    10,
     301,   109,    -1,   302,    -1,   303,    -1,   302,   303,    -1,
     304,   305,   308,    -1,   106,    -1,   306,    -1,    -1,   306,
     307,    -1,   679,    -1,   691,    -1,   675,    -1,    10,   107,
      -1,    11,    -1,    -1,    52,    11,    -1,    52,    10,   310,
      53,    -1,    -1,   310,   311,    -1,   312,    -1,   318,    -1,
     324,    -1,   330,    -1,   336,    -1,   342,    -1,   313,   314,
      -1,    82,    -1,   315,    -1,   316,    -1,    10,    83,    -1,
      11,    -1,    10,   317,    83,    -1,     4,    -1,   319,   320,
      -1,    80,    -1,   321,    -1,   322,    -1,    10,    81,    -1,
      11,    -1,    10,   323,    81,    -1,     6,    -1,   325,   326,
      -1,   146,    -1,   327,    -1,   328,    -1,    10,   147,    -1,
      11,    -1,    10,   329,   147,    -1,     6,    -1,   331,   332,
      -1,   140,    -1,   333,    -1,   334,    -1,    10,   141,    -1,
      11,    -1,    10,   335,   141,    -1,     4,    -1,   337,   338,
      -1,   122,    -1,   339,    -1,   340,    -1,    10,   123,    -1,
      11,    -1,    10,   341,   123,    -1,   711,    -1,   343,   344,
     345,    -1,   108,    -1,   695,    -1,   346,    -1,   347,    -1,
      10,   109,    -1,    11,    -1,    10,   348,   109,    -1,   349,
      -1,   350,    -1,   349,   350,    -1,   351,   352,   355,    -1,
     106,    -1,   353,    -1,    -1,   353,   354,    -1,   679,    -1,
     691,    -1,   675,    -1,    10,   107,    -1,    11,    -1,    -1,
      54,    11,    -1,    54,    10,   357,    55,    -1,    -1,   357,
     358,    -1,   359,    -1,   365,    -1,   371,    -1,   377,    -1,
     383,    -1,   389,    -1,   406,    -1,   413,    -1,   420,    -1,
     427,    -1,   432,    -1,   360,   361,    -1,   130,    -1,   362,
      -1,   363,    -1,    10,   131,    -1,    11,    -1,    10,   364,
     131,    -1,     4,    -1,   366,   367,    -1,   132,    -1,   368,
      -1,   369,    -1,    10,   133,    -1,    11,    -1,    10,   370,
     133,    -1,     4,    -1,   372,   373,    -1,   116,    -1,   374,
      -1,   375,    -1,    10,   117,    -1,    11,    -1,    10,   376,
     117,    -1,     4,    -1,   378,   379,    -1,    62,    -1,   380,
      -1,   381,    -1,    10,    63,    -1,    11,    -1,    10,   382,
      63,    -1,     4,    -1,   384,   385,    -1,    86,    -1,   386,
      -1,   387,    -1,    10,    87,    -1,    11,    -1,    10,   388,
      87,    -1,     4,    -1,   390,   391,   392,    -1,   144,    -1,
     707,    -1,   393,    -1,   394,    -1,    10,   145,    -1,    11,
      -1,    10,   395,   145,    -1,   396,    -1,   397,    -1,   396,
     397,    -1,   398,   399,   401,    -1,   138,    -1,    -1,   399,
     400,    -1,   687,    -1,   683,    -1,   671,    -1,   675,    -1,
     402,    -1,   403,    -1,    10,   139,    -1,    11,    -1,    10,
     404,   139,    -1,   405,    -1,     7,    -1,     6,    -1,   407,
     408,   411,    -1,   152,    -1,   409,    -1,    -1,   409,   410,
      -1,   687,    -1,   675,    -1,    10,   412,   153,    -1,     6,
      -1,     7,    -1,   414,   415,   418,    -1,   154,    -1,   416,
      -1,    -1,   416,   417,    -1,   687,    -1,   675,    -1,    10,
     419,   155,    -1,     6,    -1,     7,    -1,   421,   422,   425,
      -1,   150,    -1,   423,    -1,    -1,   423,   424,    -1,   687,
      -1,   675,    -1,    10,   426,   151,    -1,     6,    -1,     7,
      -1,   428,   429,   430,    -1,   148,    -1,    -1,   675,    -1,
      10,   431,   149,    -1,     6,    -1,   433,   434,   435,    -1,
     108,    -1,   695,    -1,   436,    -1,   437,    -1,    10,   109,
      -1,    11,    -1,    10,   438,   109,    -1,   439,    -1,   440,
      -1,   439,   440,    -1,   441,   442,   445,    -1,   106,    -1,
     443,    -1,    -1,   443,   444,    -1,   679,    -1,   691,    -1,
     675,    -1,    10,   107,    -1,    11,    -1,    -1,   447,   448,
     451,    -1,    56,    -1,   449,    -1,    -1,   449,   450,    -1,
     696,    -1,   697,    -1,   698,    -1,   699,    -1,   452,    -1,
     453,    -1,    10,    57,    -1,    11,    -1,    10,   454,    57,
      -1,   455,   649,    -1,   456,    -1,   455,   456,    -1,   457,
     458,   463,    -1,   124,    -1,   459,    -1,    -1,   459,   460,
      -1,   461,    -1,   462,    -1,    28,   713,     6,   713,    -1,
      42,     3,   713,    -1,    10,   464,   480,   486,   551,   589,
     626,   125,    -1,   465,   466,   469,    -1,   130,    -1,   467,
      -1,   468,    -1,   467,   468,    -1,   683,    -1,   675,    -1,
     710,    -1,   470,    -1,   471,    -1,    10,   131,    -1,    11,
      -1,    10,   472,   131,    -1,   473,    -1,   474,    -1,   473,
     474,    -1,   475,   476,   479,    -1,   134,    -1,   477,    -1,
      -1,   477,   478,    -1,   683,    -1,   675,    -1,    10,   135,
      -1,    11,    -1,    -1,   481,   482,    -1,    96,    -1,   483,
      -1,   484,    -1,    10,    97,    -1,    11,    -1,    10,   485,
      97,    -1,     4,    -1,    -1,   487,   488,   489,    -1,   162,
      -1,    -1,   700,    -1,   490,    -1,   491,    -1,    11,    -1,
      10,   492,   163,    -1,   493,   506,   521,   533,    -1,    -1,
     494,   495,   496,    -1,   156,    -1,   704,    -1,   497,    -1,
     498,    -1,    10,   157,    -1,    11,    -1,    10,   499,   157,
      -1,   500,    -1,   501,    -1,   500,   501,    -1,   502,   503,
     504,    -1,   160,    -1,    29,   713,     6,   713,    -1,    10,
     505,   161,    -1,     6,    -1,     7,    -1,    -1,   507,   508,
     509,    -1,   158,    -1,   704,    -1,   510,    -1,   511,    -1,
      10,   159,    -1,    11,    -1,    10,   512,   159,    -1,   513,
      -1,   514,    -1,   513,   514,    -1,   515,   516,   517,    -1,
     160,    -1,    29,   713,     6,   713,    -1,   518,    -1,   519,
      -1,    10,   161,    -1,    11,    -1,    10,   520,   161,    -1,
       4,    -1,    -1,   522,   523,   524,    -1,    72,    -1,   704,
      -1,   525,    -1,   526,    -1,    10,    73,    -1,    11,    -1,
      10,   527,    73,    -1,   528,    -1,   529,    -1,   528,   529,
      -1,   530,   531,   532,    -1,   160,    -1,    29,   713,     6,
     713,    -1,    10,     4,   161,    -1,    -1,   533,   534,    -1,
     535,   536,   539,    -1,   106,    -1,   537,    -1,    -1,   537,
     538,    -1,   704,    -1,   691,    -1,   679,    -1,   675,    -1,
     540,    -1,   541,    -1,    10,   107,    -1,    11,    -1,    10,
     542,   107,    -1,   543,    -1,   544,    -1,   543,   544,    -1,
     545,   546,   547,    -1,   160,    -1,    29,   713,     6,   713,
      -1,   548,    -1,   549,    -1,    10,   161,    -1,    11,    -1,
      10,   550,   161,    -1,   712,    -1,    -1,   552,   553,   554,
      -1,   100,    -1,    -1,   701,    -1,   555,    -1,   556,    -1,
      11,    -1,    10,   557,   101,    -1,   558,   571,    -1,    -1,
     559,   560,   561,    -1,   156,    -1,   705,    -1,   562,    -1,
     563,    -1,    10,   157,    -1,    11,    -1,    10,   564,   157,
      -1,   565,    -1,   566,    -1,   565,   566,    -1,   567,   568,
     569,    -1,    98,    -1,    -1,    29,   713,     6,   713,    -1,
      10,   570,    99,    -1,     6,    -1,     7,    -1,    -1,   571,
     572,    -1,   573,   574,   577,    -1,   106,    -1,   575,    -1,
      -1,   575,   576,    -1,   705,    -1,   691,    -1,   679,    -1,
     675,    -1,   578,    -1,   579,    -1,    10,   107,    -1,    11,
      -1,    10,   580,   107,    -1,   581,    -1,   582,    -1,   581,
     582,    -1,   583,   584,   585,    -1,    98,    -1,    29,   713,
       6,   713,    -1,   586,    -1,   587,    -1,    10,    99,    -1,
      11,    -1,    10,   588,    99,    -1,   712,    -1,    -1,   590,
     591,   592,    -1,    78,    -1,    -1,   702,    -1,   593,    -1,
     594,    -1,    11,    -1,    10,   595,    79,    -1,   596,   608,
      -1,    -1,   597,   598,   599,    -1,    84,    -1,   706,    -1,
     600,    -1,   601,    -1,    10,    85,    -1,    11,    -1,    10,
     602,    85,    -1,   603,    -1,   604,    -1,   603,   604,    -1,
     605,   606,    10,   607,    77,    -1,    76,    -1,    29,   713,
       6,   713,    -1,     6,    -1,     7,    -1,    -1,   608,   609,
      -1,   610,   611,   614,    -1,   106,    -1,   612,    -1,    -1,
     612,   613,    -1,   706,    -1,   691,    -1,   679,    -1,   675,
      -1,   615,    -1,   616,    -1,    10,   107,    -1,    11,    -1,
      10,   617,   107,    -1,   618,    -1,   619,    -1,   618,   619,
      -1,   620,   621,   622,    -1,    76,    -1,    29,   713,     6,
     713,    -1,   623,    -1,   624,    -1,    10,    77,    -1,    11,
      -1,    10,   625,    77,    -1,   712,    -1,    -1,   627,   628,
     629,    -1,   112,    -1,   703,    -1,   630,    -1,   631,    -1,
      10,   113,    -1,    11,    -1,    10,   632,   113,    -1,   633,
      -1,   634,    -1,   633,   634,    -1,   635,   636,   639,    -1,
     110,    -1,   637,    -1,    -1,   637,   638,    -1,   679,    -1,
     671,    -1,   675,    -1,   708,    -1,   640,    -1,   641,    -1,
      10,   111,    -1,    11,    -1,    10,   642,   111,    -1,   643,
      -1,   644,    -1,   643,   644,    -1,   645,    -1,   646,    -1,
     647,    -1,    60,    -1,    61,    -1,    58,   648,    59,    -1,
       5,    -1,    -1,   650,   651,   652,    -1,   114,    -1,   709,
      -1,   653,    -1,   654,    -1,    10,   115,    -1,    11,    -1,
      10,   655,   115,    -1,   656,    -1,   657,    -1,   656,   657,
      -1,   658,   659,   662,    -1,   128,    -1,   660,    -1,    -1,
     660,   661,    -1,   679,    -1,   671,    -1,   675,    -1,   708,
      -1,   663,    -1,   664,    -1,    10,   129,    -1,    11,    -1,
      10,   665,   129,    -1,   666,    -1,   667,    -1,   666,   667,
      -1,   668,    -1,   669,    -1,   670,    -1,    60,    -1,    61,
      -1,    58,     5,    59,    -1,   672,    -1,   673,    -1,   674,
      -1,    31,    -1,    30,     3,   713,    -1,   676,    -1,   677,
      -1,   678,    -1,    33,    -1,    32,     3,   713,    -1,   680,
      -1,   681,    -1,   682,    -1,    35,    -1,    34,     3,   713,
      -1,   684,    -1,   685,    -1,   686,    -1,    37,    -1,    36,
       3,   713,    -1,   688,    -1,   689,    -1,   690,    -1,    39,
      -1,    38,     3,   713,    -1,   692,    -1,   693,    -1,   694,
      -1,    41,    -1,    40,     3,   713,    -1,    19,   713,     6,
     713,    -1,    22,   713,     6,   713,    -1,    27,   713,     6,
     713,    -1,    13,   713,     6,   713,    -1,    16,   713,     6,
     713,    -1,    21,   713,     6,   713,    -1,    18,   713,     6,
     713,    -1,    17,   713,     6,   713,    -1,    20,   713,     6,
     713,    -1,    26,   713,     6,   713,    -1,    15,   713,     6,
     713,    -1,    12,   713,     6,   713,    -1,    25,   713,     6,
     713,    -1,    14,   713,     6,   713,    -1,    23,   713,     6,
     713,    -1,    24,   713,     6,   713,    -1,     6,    -1,     7,
      -1,     4,    -1,     6,    -1,     7,    -1,   714,     8,    -1,
      -1,   714,   715,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   169,   176,   176,   178,   180,   183,   183,
     185,   187,   187,   189,   189,   191,   193,   195,   195,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   209,   211,
     223,   229,   229,   232,   240,   244,   252,   256,   261,   261,
     263,   265,   267,   267,   269,   273,   280,   285,   285,   288,
     292,   297,   297,   300,   302,   308,   308,   310,   310,   312,
     314,   317,   319,   325,   325,   327,   327,   329,   331,   334,
     336,   342,   342,   344,   344,   346,   348,   351,   353,   359,
     359,   361,   361,   363,   365,   368,   370,   376,   376,   378,
     378,   380,   382,   385,   387,   393,   393,   395,   395,   397,
     399,   402,   404,   410,   410,   412,   412,   414,   416,   419,
     421,   427,   437,   441,   446,   446,   448,   450,   452,   452,
     454,   458,   466,   471,   471,   474,   479,   483,   489,   489,
     493,   493,   495,   497,   497,   499,   499,   501,   503,   505,
     505,   508,   509,   510,   511,   512,   513,   516,   518,   524,
     524,   526,   526,   528,   530,   533,   535,   543,   545,   545,
     548,   560,   565,   568,   569,   572,   574,   582,   584,   584,
     587,   599,   604,   607,   608,   611,   613,   621,   623,   623,
     626,   642,   647,   650,   651,   654,   656,   663,   664,   669,
     672,   675,   677,   683,   692,   696,   701,   701,   703,   705,
     707,   707,   709,   713,   721,   726,   726,   729,   734,   738,
     744,   744,   748,   748,   749,   751,   751,   754,   755,   756,
     757,   758,   759,   762,   764,   770,   770,   772,   772,   774,
     776,   788,   790,   796,   796,   798,   798,   800,   802,   805,
     807,   813,   813,   815,   815,   817,   819,   822,   824,   830,
     830,   832,   832,   834,   836,   839,   841,   847,   847,   849,
     849,   851,   853,   856,   858,   864,   873,   877,   882,   882,
     884,   886,   888,   888,   890,   894,   902,   907,   907,   910,
     915,   919,   925,   925,   928,   928,   929,   931,   931,   934,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     947,   949,   955,   955,   957,   957,   959,   961,   973,   975,
     981,   981,   983,   983,   985,   987,   990,   992,   998,   998,
    1000,  1000,  1002,  1004,  1007,  1009,  1015,  1015,  1017,  1017,
    1019,  1021,  1024,  1026,  1032,  1032,  1034,  1034,  1036,  1038,
    1041,  1043,  1049,  1056,  1060,  1065,  1065,  1067,  1069,  1071,
    1071,  1073,  1075,  1088,  1088,  1091,  1103,  1109,  1119,  1122,
    1122,  1124,  1124,  1126,  1128,  1139,  1140,  1143,  1145,  1153,
    1155,  1155,  1158,  1170,  1175,  1178,  1179,  1182,  1184,  1192,
    1194,  1194,  1197,  1209,  1214,  1217,  1218,  1221,  1223,  1233,
    1235,  1235,  1238,  1254,  1259,  1262,  1263,  1266,  1268,  1276,
    1277,  1282,  1285,  1289,  1291,  1297,  1306,  1310,  1315,  1315,
    1317,  1319,  1321,  1321,  1323,  1327,  1335,  1340,  1340,  1343,
    1348,  1352,  1358,  1358,  1361,  1361,  1363,  1370,  1375,  1375,
    1378,  1384,  1389,  1394,  1401,  1405,  1410,  1410,  1412,  1414,
    1416,  1416,  1418,  1420,  1428,  1430,  1430,  1432,  1432,  1434,
    1442,  1452,  1458,  1460,  1467,  1472,  1472,  1475,  1489,  1492,
    1500,  1504,  1510,  1510,  1512,  1514,  1516,  1516,  1518,  1521,
    1528,  1533,  1533,  1536,  1545,  1551,  1551,  1554,  1554,  1556,
    1558,  1558,  1560,  1560,  1562,  1564,  1569,  1569,  1571,  1574,
    1574,  1581,  1581,  1583,  1585,  1587,  1589,  1589,  1591,  1593,
    1600,  1604,  1609,  1609,  1611,  1613,  1615,  1615,  1617,  1623,
    1629,  1631,  1634,  1635,  1638,  1638,  1640,  1642,  1649,  1653,
    1658,  1658,  1660,  1662,  1664,  1664,  1666,  1673,  1679,  1682,
    1683,  1685,  1685,  1687,  1689,  1692,  1692,  1694,  1696,  1703,
    1707,  1712,  1712,  1714,  1716,  1718,  1718,  1720,  1722,  1728,
    1730,  1743,  1743,  1745,  1750,  1760,  1767,  1767,  1770,  1778,
    1783,  1788,  1794,  1794,  1796,  1796,  1798,  1800,  1802,  1802,
    1804,  1809,  1811,  1816,  1816,  1818,  1818,  1820,  1822,  1827,
    1827,  1829,  1835,  1835,  1842,  1842,  1844,  1846,  1848,  1850,
    1850,  1852,  1854,  1861,  1865,  1870,  1870,  1872,  1874,  1877,
    1877,  1879,  1885,  1892,  1892,  1894,  1897,  1898,  1902,  1902,
    1904,  1910,  1920,  1928,  1928,  1931,  1939,  1944,  1949,  1955,
    1955,  1957,  1957,  1959,  1961,  1963,  1963,  1965,  1970,  1972,
    1976,  1976,  1978,  1978,  1980,  1982,  1987,  1987,  1989,  1994,
    1994,  2001,  2001,  2003,  2005,  2007,  2009,  2009,  2011,  2014,
    2021,  2025,  2030,  2030,  2032,  2034,  2036,  2036,  2038,  2044,
    2050,  2053,  2054,  2057,  2057,  2059,  2065,  2075,  2082,  2082,
    2085,  2093,  2098,  2103,  2109,  2109,  2111,  2111,  2113,  2115,
    2117,  2117,  2119,  2124,  2126,  2131,  2131,  2133,  2133,  2135,
    2137,  2143,  2143,  2145,  2150,  2158,  2162,  2167,  2167,  2169,
    2171,  2173,  2173,  2175,  2179,  2188,  2195,  2195,  2198,  2203,
    2208,  2213,  2221,  2225,  2230,  2230,  2232,  2234,  2236,  2236,
    2238,  2243,  2247,  2249,  2249,  2251,  2253,  2262,  2262,  2264,
    2269,  2277,  2281,  2286,  2286,  2288,  2290,  2292,  2292,  2294,
    2298,  2307,  2314,  2314,  2317,  2321,  2325,  2329,  2336,  2340,
    2345,  2345,  2347,  2349,  2351,  2351,  2353,  2358,  2362,  2364,
    2364,  2366,  2375,  2381,  2381,  2383,  2386,  2389,  2395,  2395,
    2397,  2400,  2404,  2410,  2410,  2412,  2415,  2418,  2424,  2424,
    2426,  2429,  2432,  2438,  2438,  2440,  2443,  2446,  2452,  2452,
    2454,  2457,  2460,  2465,  2473,  2481,  2489,  2497,  2503,  2509,
    2515,  2521,  2527,  2533,  2539,  2544,  2553,  2559,  2568,  2569,
    2572,  2573,  2574,  2576,  2578,  2578,  2580,  2581,  2582,  2583
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "NUMBEROFCONATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFITEMSATT", "NUMBEROFOBJATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFSOLVEROUTPUTSATT", "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIABLESATT", "TARGETOBJECTIVEIDXATT",
  "IDXATT", "CATEGORYATT", "EMPTYCATEGORYATT", "DESCRIPTIONATT",
  "EMPTYDESCRIPTIONATT", "NAMEATT", "EMPTYNAMEATT", "TYPEATT",
  "EMPTYTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT", "EMPTYVALUEATT",
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "OSRLSTART",
  "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT", "OSRLEND", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND", "ITEMEMPTY",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "AVAILABLECPUNUMBERSTART",
  "AVAILABLECPUNUMBEREND", "AVAILABLECPUSPEEDSTART",
  "AVAILABLECPUSPEEDEND", "AVAILABLEDISKSPACESTART",
  "AVAILABLEDISKSPACEEND", "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND",
  "BASISSTATUSSTART", "BASISSTATUSEND", "BASSTATUSSTART", "BASSTATUSEND",
  "CONSTART", "CONEND", "CONSTRAINTSSTART", "CONSTRAINTSEND",
  "CURRENTJOBCOUNTSTART", "CURRENTJOBCOUNTEND", "CURRENTSTATESTART",
  "CURRENTSTATEEND", "DUALVALUESSTART", "DUALVALUESEND", "ENDTIMESTART",
  "ENDTIMEEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "GENERALSUBSTATUSSTART", "GENERALSUBSTATUSEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND", "MESSAGESTART",
  "MESSAGEEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OPTIMIZATIONSOLUTIONSTATUSSTART", "OPTIMIZATIONSOLUTIONSTATUSEND",
  "OPTIMIZATIONSOLUTIONSUBSTATUSSTART", "OPTIMIZATIONSOLUTIONSUBSTATUSEND",
  "OTHERSTART", "OTHEREND", "OTHERRESULTSSTART", "OTHERRESULTSEND",
  "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLVEROUTPUTSTART", "OTHERSOLVEROUTPUTEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "SERVICENAMESTART",
  "SERVICENAMEEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICEUTILIZATIONSTART", "SERVICEUTILIZATIONEND", "SOLUTIONSTART",
  "SOLUTIONEND", "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND",
  "SOLVEROUTPUTSTART", "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND",
  "SUBMITTIMESTART", "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND",
  "SYSTEMINFORMATIONSTART", "SYSTEMINFORMATIONEND", "TIMESTART", "TIMEEND",
  "TIMESERVICESTARTEDSTART", "TIMESERVICESTARTEDEND", "TIMESTAMPSTART",
  "TIMESTAMPEND", "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND",
  "TOTALJOBSSOFARSTART", "TOTALJOBSSOFAREND", "USEDCPUNUMBERSTART",
  "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART", "USEDCPUSPEEDEND",
  "USEDDISKSPACESTART", "USEDDISKSPACEEND", "USEDMEMORYSTART",
  "USEDMEMORYEND", "VALUESSTART", "VALUESEND", "VALUESSTRINGSTART",
  "VALUESSTRINGEND", "VARSTART", "VAREND", "VARIABLESSTART",
  "VARIABLESEND", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlStart", "osrlAttributes", "osrlContent", "osrlBody",
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
  "generalOtherResults", "generalOtherResultsStart",
  "generalOtherResultsAttributes", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsLaden",
  "generalOtherResultsBody", "generalOtherResultArray",
  "generalOtherResult", "generalOtherResultStart",
  "generalOtherAttributes", "generalOtherAttList", "generalOtherAtt",
  "generalOtherEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild",
  "systemInformation", "systemInformationStart",
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
  "systemOtherResults", "systemOtherResultsStart",
  "systemOtherResultsAttributes", "systemOtherResultsContent",
  "systemOtherResultsEmpty", "systemOtherResultsLaden",
  "systemOtherResultsBody", "systemOtherResultArray", "systemOtherResult",
  "systemOtherResultStart", "systemOtherAttributes", "systemOtherAttList",
  "systemOtherAtt", "systemOtherEnd", "serviceElement", "serviceContent",
  "serviceChild", "currentState", "currentStateStart",
  "currentStateContent", "currentStateEmpty", "currentStateLaden",
  "currentStateBody", "currentJobCount", "currentJobCountStart",
  "currentJobCountContent", "currentJobCountEmpty", "currentJobCountLaden",
  "currentJobCountBody", "totalJobsSoFar", "totalJobsSoFarStart",
  "totalJobsSoFarContent", "totalJobsSoFarEmpty", "totalJobsSoFarLaden",
  "totalJobsSoFarBody", "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedLaden", "timeServiceStartedBody",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceUtilizationEmpty",
  "serviceUtilizationLaden", "serviceUtilizationBody",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttributes", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsLaden",
  "serviceOtherResultsBody", "serviceOtherResultArray",
  "serviceOtherResult", "serviceOtherResultStart",
  "serviceOtherAttributes", "serviceOtherAttList", "serviceOtherAtt",
  "serviceOtherEnd", "jobElement", "jobContent", "jobChild", "jobStatus",
  "jobStatusStart", "jobStatusContent", "jobStatusEmpty", "jobStatusLaden",
  "jobStatusBody", "submitTime", "submitTimeStart", "submitTimeContent",
  "submitTimeEmpty", "submitTimeLaden", "submitTimeBody",
  "scheduledStartTime", "scheduledStartTimeStart",
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
  "usedCPUNumberContent", "usedCPUNumberValue", "jobOtherResults",
  "jobOtherResultsStart", "jobOtherResultsAttributes",
  "jobOtherResultsContent", "jobOtherResultsEmpty", "jobOtherResultsLaden",
  "jobOtherResultsBody", "jobOtherResultArray", "jobOtherResult",
  "jobOtherResultStart", "jobOtherAttributes", "jobOtherAttList",
  "jobOtherAtt", "jobOtherEnd", "optimizationElement", "optimizationStart",
  "optimizationAttributes", "optimizationAttList", "optimizationATT",
  "optimizationContent", "optimizationEmpty", "optimizationLaden",
  "optimizationBody", "solutionArray", "solution", "solutionStart",
  "solutionAttributes", "solutionAttList", "solutionATT",
  "targetObjectiveIdxATT", "weightedObjectivesATT", "solutionContent",
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
  "varValueArray", "varValue", "varValueStart", "varIdxATT",
  "varValueContent", "varVal", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringLaden", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varStrIdxATT", "varValueStringContent", "varValueStringEmpty",
  "varValueStringLaden", "varValueStringBody", "basisStatus",
  "basisStatusStart", "numberOfBasisVarATT", "basisStatusContent",
  "basisStatusEmpty", "basisStatusLaden", "basisStatusBody",
  "basisVarArray", "basisVar", "basisVarStart", "basisVarIdxATT",
  "basisVarContent", "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "otherVariableResultContent", "otherVariableResultEmpty",
  "otherVariableResultLaden", "otherVariableResultBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "otherVarEmpty", "otherVarLaden", "otherVarBody", "objectives",
  "objectivesStart", "numberOfOtherObjectiveResults", "objectivesContent",
  "objectivesEmpty", "objectivesLaden", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesLaden",
  "objectiveValuesBody", "objValueArray", "objValue", "objValueStart",
  "objIdxATT", "objValueContent", "objVal", "otherObjectiveResultsArray",
  "otherObjectiveResult", "otherObjectiveResultStart",
  "otherObjectiveResultAttributes", "otherObjectiveResultAttList",
  "otherObjectiveResultATT", "otherObjectiveResultContent",
  "otherObjectiveResultEmpty", "otherObjectiveResultLaden",
  "otherObjectiveResultBody", "otherObjList", "otherObj", "otherObjStart",
  "otherObjIdxATT", "otherObjContent", "otherObjEmpty", "otherObjLaden",
  "otherObjBody", "constraints", "constraintsStart",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody", "dualValues",
  "dualValuesStart", "numberOfConATT", "dualValuesContent",
  "dualValuesEmpty", "dualValuesLaden", "dualValuesBody", "dualValueArray",
  "dualValue", "dualValueStart", "conIdxATT", "dualVal",
  "otherConstraintResultsArray", "otherConstraintResult",
  "otherConstraintResultStart", "otherConstraintResultAttributes",
  "otherConstraintResultAttList", "otherConstraintResultATT",
  "otherConstraintResultContent", "otherConstraintResultEmpty",
  "otherConstraintResultLaden", "otherConstraintResultBody",
  "otherConList", "otherCon", "otherConStart", "otherConIdxATT",
  "otherConContent", "otherConEmpty", "otherConLaden", "otherConBody",
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
  "solverOutputItemEmpty", "solverOutputItemBody", "categoryAttribute",
  "categoryAtt", "categoryAttEmpty", "categoryAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "typeAttribute", "typeAtt", "typeAttEmpty",
  "typeAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "numberOfOtherResultsAttribute",
  "numberOfSolutionsAttribute", "numberOfVariablesAttribute",
  "numberOfConstraintsAttribute", "numberOfObjectivesAttribute",
  "numberOfOtherVariableResultsAttribute",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherSolutionResultsAttribute", "numberOfVarAttribute",
  "numberOfObjAttribute", "numberOfConAttribute", "numberOfTimesAttribute",
  "numberOfItemsAttribute", "numberOfSolverOutputsAttribute",
  "numberOfSubstatusesAttribute", "aNumber", "ElementValue", "quote",
  "xmlWhiteSpace", "xmlWhiteSpaceChar", 0
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
     415,   416,   417,   418,   419,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   171,   172,   172,   173,   174,   175,   175,
     176,   177,   177,   178,   178,   179,   180,   181,   181,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   183,   184,
     185,   186,   186,   187,   187,   187,   188,   188,   189,   189,
     190,   191,   192,   192,   193,   194,   195,   196,   196,   197,
     197,   198,   198,   199,   200,   201,   201,   202,   202,   203,
     204,   205,   206,   207,   207,   208,   208,   209,   210,   211,
     212,   213,   213,   214,   214,   215,   216,   217,   218,   219,
     219,   220,   220,   221,   222,   223,   224,   225,   225,   226,
     226,   227,   228,   229,   230,   231,   231,   232,   232,   233,
     234,   235,   236,   237,   237,   238,   238,   239,   240,   241,
     242,   243,   244,   244,   245,   245,   246,   247,   248,   248,
     249,   250,   251,   252,   252,   253,   253,   253,   254,   254,
     255,   255,   256,   257,   257,   258,   258,   259,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   263,   264,   265,
     265,   266,   266,   267,   268,   269,   270,   271,   272,   272,
     273,   273,   274,   275,   275,   276,   277,   278,   279,   279,
     280,   280,   281,   282,   282,   283,   284,   285,   286,   286,
     287,   287,   288,   289,   289,   290,   291,   292,   292,   293,
     294,   295,   296,   297,   298,   298,   299,   299,   300,   301,
     302,   302,   303,   304,   305,   306,   306,   307,   307,   307,
     308,   308,   309,   309,   309,   310,   310,   311,   311,   311,
     311,   311,   311,   312,   313,   314,   314,   315,   315,   316,
     317,   318,   319,   320,   320,   321,   321,   322,   323,   324,
     325,   326,   326,   327,   327,   328,   329,   330,   331,   332,
     332,   333,   333,   334,   335,   336,   337,   338,   338,   339,
     339,   340,   341,   342,   343,   344,   345,   345,   346,   346,
     347,   348,   349,   349,   350,   351,   352,   353,   353,   354,
     354,   354,   355,   355,   356,   356,   356,   357,   357,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   360,   361,   361,   362,   362,   363,   364,   365,   366,
     367,   367,   368,   368,   369,   370,   371,   372,   373,   373,
     374,   374,   375,   376,   377,   378,   379,   379,   380,   380,
     381,   382,   383,   384,   385,   385,   386,   386,   387,   388,
     389,   390,   391,   392,   392,   393,   393,   394,   395,   396,
     396,   397,   398,   399,   399,   400,   400,   400,   400,   401,
     401,   402,   402,   403,   404,   405,   405,   406,   407,   408,
     409,   409,   410,   410,   411,   412,   412,   413,   414,   415,
     416,   416,   417,   417,   418,   419,   419,   420,   421,   422,
     423,   423,   424,   424,   425,   426,   426,   427,   428,   429,
     429,   430,   431,   432,   433,   434,   435,   435,   436,   436,
     437,   438,   439,   439,   440,   441,   442,   443,   443,   444,
     444,   444,   445,   445,   446,   446,   447,   448,   449,   449,
     450,   450,   450,   450,   451,   451,   452,   452,   453,   454,
     455,   455,   456,   457,   458,   459,   459,   460,   460,   461,
     462,   463,   464,   465,   466,   467,   467,   468,   468,   468,
     469,   469,   470,   470,   471,   472,   473,   473,   474,   475,
     476,   477,   477,   478,   478,   479,   479,   480,   480,   481,
     482,   482,   483,   483,   484,   485,   486,   486,   487,   488,
     488,   489,   489,   490,   491,   492,   493,   493,   494,   495,
     496,   496,   497,   497,   498,   499,   500,   500,   501,   502,
     503,   504,   505,   505,   506,   506,   507,   508,   509,   509,
     510,   510,   511,   512,   513,   513,   514,   515,   516,   517,
     517,   518,   518,   519,   520,   521,   521,   522,   523,   524,
     524,   525,   525,   526,   527,   528,   528,   529,   530,   531,
     532,   533,   533,   534,   535,   536,   537,   537,   538,   538,
     538,   538,   539,   539,   540,   540,   541,   542,   543,   543,
     544,   545,   546,   547,   547,   548,   548,   549,   550,   551,
     551,   552,   553,   553,   554,   554,   555,   556,   557,   558,
     558,   559,   560,   561,   561,   562,   562,   563,   564,   565,
     565,   566,   567,   568,   568,   569,   570,   570,   571,   571,
     572,   573,   574,   575,   575,   576,   576,   576,   576,   577,
     577,   578,   578,   579,   580,   581,   581,   582,   583,   584,
     585,   585,   586,   586,   587,   588,   589,   589,   590,   591,
     591,   592,   592,   593,   594,   595,   596,   596,   597,   598,
     599,   599,   600,   600,   601,   602,   603,   603,   604,   605,
     606,   607,   607,   608,   608,   609,   610,   611,   612,   612,
     613,   613,   613,   613,   614,   614,   615,   615,   616,   617,
     618,   618,   619,   620,   621,   622,   622,   623,   623,   624,
     625,   626,   626,   627,   628,   629,   629,   630,   630,   631,
     632,   633,   633,   634,   635,   636,   637,   637,   638,   638,
     638,   638,   639,   639,   640,   640,   641,   642,   643,   643,
     644,   645,   645,   646,   646,   647,   648,   649,   649,   650,
     651,   652,   652,   653,   653,   654,   655,   656,   656,   657,
     658,   659,   660,   660,   661,   661,   661,   661,   662,   662,
     663,   663,   664,   665,   666,   666,   667,   668,   668,   669,
     669,   670,   671,   672,   672,   673,   674,   675,   676,   676,
     677,   678,   679,   680,   680,   681,   682,   683,   684,   684,
     685,   686,   687,   688,   688,   689,   690,   691,   692,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   711,
     712,   712,   712,   713,   714,   714,   715,   715,   715,   715
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     1,     3,     5,     0,     2,
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
       1,     1,     3,     1,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     1,     3,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     2,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     2,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     4,
       3,     8,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     3,     4,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       4,     3,     1,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     4,
       3,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     0,
       3,     1,     0,     1,     1,     1,     1,     3,     2,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     4,     3,     1,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     3,     2,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     5,     1,
       4,     1,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     4,     1,     5,     0,     8,     2,    10,
       0,   130,     0,     6,   132,   212,     0,     0,    14,     9,
      11,    12,     0,   284,     0,   136,   131,   133,   134,    13,
      29,    78,    86,    54,   110,    70,    62,    94,   102,     0,
      16,    17,    19,     0,    20,     0,    21,     0,    22,     0,
      23,     0,    24,     0,    25,     0,    26,     0,    27,     0,
     215,   213,     0,   424,   135,   186,   176,   156,   166,   192,
     148,     0,   138,   139,   141,     0,   142,   158,   143,   168,
     144,   178,   145,   187,   146,     0,    15,    18,   814,     0,
     770,     0,   780,     0,    30,    31,    34,   767,   768,   769,
      33,   777,   778,   779,    35,     0,    58,    53,    55,    56,
       0,    66,    61,    63,    64,     0,    74,    69,    71,    72,
       0,    82,    77,    79,    80,     0,    90,    85,    87,    88,
       0,    98,    93,    95,    96,     0,   106,   101,   103,   104,
     814,     0,   111,     0,   287,   285,   426,     7,   428,   137,
     140,     0,   152,   147,   149,   150,     0,   157,     0,   167,
       0,   177,     0,   188,     0,   193,     0,     0,   814,   814,
       0,    39,    28,    36,    37,    32,    60,    57,     0,    68,
      65,     0,    76,    73,     0,    84,    81,     0,    92,    89,
       0,   100,    97,     0,   108,   105,     0,     0,     0,   115,
     109,   112,   113,   214,   232,   224,   264,   256,   248,   240,
     216,   217,     0,   218,     0,   219,     0,   220,     0,   221,
       0,   222,     0,     0,     0,   427,   154,   151,     0,     0,
     155,     0,   785,   159,   161,   160,   782,   783,   784,     0,
     165,   169,   171,   170,     0,   175,   179,   181,   180,     0,
     185,     0,   197,   191,   194,   195,   814,   813,   816,   817,
     818,   819,   815,   771,   781,    38,    45,     0,    41,    42,
      47,    59,    67,    75,    83,    91,    99,   107,   814,   121,
     114,     0,   117,   118,   123,     0,   228,   223,   225,   226,
       0,   236,   231,   233,   234,     0,   244,   239,   241,   242,
       0,   252,   247,   249,   250,     0,   260,   255,   257,   258,
       0,   265,   286,   325,   333,   404,   317,   301,   309,   341,
     398,   388,   368,   378,   288,   289,     0,   290,     0,   291,
       0,   292,     0,   293,     0,   294,     0,   295,   370,   296,
     380,   297,   390,   298,   399,   299,     0,     0,   437,   425,
     434,   435,   814,   814,   814,   814,   429,   430,   431,   432,
     433,   153,   163,   164,     0,   814,   173,   174,     0,   183,
     184,     0,   190,     0,   203,   196,     0,   199,   200,   205,
     807,    40,    43,     0,    46,   792,   116,   119,     0,   122,
     230,   227,     0,   238,   235,     0,   246,   243,     0,   254,
     251,     0,   808,   809,   259,     0,   262,     0,   269,   263,
     266,   267,     0,   305,   300,   302,   303,     0,   313,   308,
     310,   311,     0,   321,   316,   318,   319,     0,   329,   324,
     326,   327,     0,   337,   332,   334,   335,   814,     0,   342,
       0,   369,     0,   379,     0,   389,     0,   400,     0,   405,
     436,   443,     0,   727,   440,   445,     0,     0,     0,     0,
     162,   786,   172,   182,   189,   198,   201,     0,   204,     0,
      52,    44,     0,   775,    48,    50,    49,   772,   773,   774,
       0,   129,   120,     0,   790,   124,   127,   125,   126,   787,
     788,   789,   229,   237,   245,   253,   261,   275,   268,     0,
     271,   272,   277,   307,   304,     0,   315,   312,     0,   323,
     320,     0,   331,   328,     0,   339,   336,     0,     0,     0,
     346,   340,   343,   344,     0,   367,   371,   373,   372,     0,
     377,   381,   383,   382,     0,   387,   391,   393,   392,     0,
     397,     0,   409,   403,   406,   407,   438,   729,   441,   439,
       0,     0,   444,   814,   814,   814,   814,     0,   211,   202,
     206,   209,   207,   208,    51,   814,   128,   814,   270,   273,
       0,   276,   306,   314,   322,   330,   338,   814,   352,   345,
       0,   348,   349,   353,   375,   376,     0,   385,   386,     0,
     395,   396,     0,   402,     0,   415,   408,     0,   411,   412,
     417,   814,     0,   730,     0,   442,   814,     0,   446,   447,
     448,   795,   796,   793,   794,   210,   776,   791,     0,   283,
     274,   278,   281,   279,   280,   804,   347,   350,     0,   374,
     384,   394,   401,   410,   413,     0,   416,     0,     0,   734,
     728,   731,   732,   453,   477,     0,     0,   814,   282,     0,
     362,     0,   765,   354,   351,   359,   360,   357,   762,   763,
     764,   358,   356,   355,     0,   423,   414,   418,   421,   419,
     420,   814,   733,   740,     0,   736,   737,   742,   479,   486,
       0,     0,   454,   455,   458,   457,   459,   814,   450,   366,
     365,   361,     0,   364,   814,   422,   806,   735,   738,     0,
     741,   488,   579,   489,     0,   483,   478,   480,   481,     0,
     463,   452,   460,   461,   456,   449,   363,   766,     0,   751,
     739,   748,   749,   814,   743,   745,   746,   744,   747,   581,
     636,   582,   814,     0,   490,   485,   482,     0,   462,   469,
       0,   465,   466,   471,     0,   759,   760,   750,     0,   753,
     754,   756,   757,   758,     0,   638,   691,   639,   814,     0,
     583,     0,   496,   493,   487,   491,   492,   484,   464,   467,
       0,   470,     0,   752,   755,   814,   693,     0,     0,   814,
       0,   640,     0,   589,   586,   580,   584,   585,   814,   498,
       0,   514,     0,     0,   476,   468,   472,   474,   473,   761,
     805,   451,   814,     0,   694,     0,   646,   643,   637,   641,
     642,   814,   591,     0,   608,     0,   797,   494,   516,   535,
       0,   814,     0,   499,   475,     0,     0,   698,   692,   695,
     696,   814,   648,     0,   663,     0,   798,   587,   588,   814,
       0,   592,   537,   551,     0,     0,   517,     0,     0,   503,
     497,   500,   501,   814,   704,   697,     0,   700,   701,   706,
     799,   644,   645,   814,     0,   649,   611,   609,   613,     0,
       0,   596,   590,   593,   594,   495,     0,   538,     0,   521,
     515,   518,   519,   814,   502,   509,     0,   505,   506,     0,
     800,   699,   702,     0,   705,   666,   664,   668,     0,     0,
     653,   647,   650,   651,     0,   612,   814,   602,   595,     0,
     598,   599,   603,   554,   552,   556,     0,   542,   536,   539,
     540,   520,   527,     0,   523,   524,     0,   801,   504,   507,
     814,     0,     0,   715,   703,   712,   713,   707,   709,   710,
     708,   711,     0,   667,   814,   659,   652,     0,   655,   656,
       0,     0,   622,   610,   619,   620,   614,   618,   617,   616,
     615,   802,   597,   600,   814,     0,     0,   555,   541,   548,
       0,   544,   545,     0,   522,   525,   814,     0,     0,     0,
     508,     0,   723,   724,   714,     0,   717,   718,   720,   721,
     722,     0,   677,   665,   674,   675,   669,   673,   672,   671,
     670,   803,   654,   657,   814,     0,   628,   621,     0,   624,
     625,     0,     0,     0,   601,     0,   565,   553,   562,   563,
     557,   561,   560,   559,   558,   543,   546,   814,     0,     0,
       0,   532,   526,   529,   530,   814,   512,   513,     0,   726,
       0,   716,   719,   683,   676,     0,   679,   680,     0,     0,
       0,   623,   626,   814,     0,   814,   606,   607,     0,   564,
     571,     0,   567,   568,     0,     0,     0,   547,   814,   534,
     531,     0,   510,   511,   725,   678,   681,   814,     0,   814,
     661,   662,     0,     0,     0,   633,   627,   630,   631,   604,
     605,   566,   569,   814,     0,   814,     0,   528,   533,     0,
       0,   688,   682,   685,   686,   660,   658,   814,   810,   811,
     812,   632,     0,   635,     0,     0,   576,   570,   573,   574,
     549,   550,   814,   687,     0,   690,   629,   634,   814,   575,
       0,   578,   684,   689,   572,   577
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    11,    12,    19,    20,
      21,    39,    40,    41,    42,    43,    93,    94,    95,   172,
     173,   174,   267,   268,   269,   270,   383,   384,   474,   471,
      44,    45,   107,   108,   109,   178,    46,    47,   112,   113,
     114,   181,    48,    49,   117,   118,   119,   184,    50,    51,
     122,   123,   124,   187,    52,    53,   127,   128,   129,   190,
      54,    55,   132,   133,   134,   193,    56,    57,   137,   138,
     139,   196,    58,    59,   141,   200,   201,   202,   281,   282,
     283,   284,   388,   389,   485,   482,    15,    16,    26,    27,
      28,    71,    72,    73,    74,    75,   153,   154,   155,   228,
      76,    77,   156,   157,   233,   230,   364,    78,    79,   158,
     159,   241,   240,   368,    80,    81,   160,   161,   246,   245,
     371,    82,    83,   162,   250,   373,    84,    85,   164,   253,
     254,   255,   376,   377,   378,   379,   467,   468,   560,   559,
      23,   143,   210,   211,   212,   287,   288,   289,   392,   213,
     214,   292,   293,   294,   395,   215,   216,   297,   298,   299,
     398,   217,   218,   302,   303,   304,   401,   219,   220,   307,
     308,   309,   405,   221,   222,   310,   409,   410,   411,   499,
     500,   501,   502,   570,   571,   621,   620,    63,   223,   324,
     325,   326,   414,   415,   416,   505,   327,   328,   419,   420,
     421,   508,   329,   330,   424,   425,   426,   511,   331,   332,
     429,   430,   431,   514,   333,   334,   434,   435,   436,   517,
     335,   336,   438,   521,   522,   523,   580,   581,   582,   583,
     628,   653,   654,   655,   656,   692,   693,   337,   338,   440,
     441,   526,   525,   586,   339,   340,   442,   443,   531,   530,
     589,   341,   342,   444,   445,   536,   535,   592,   343,   344,
     446,   540,   594,   345,   346,   448,   543,   544,   545,   597,
     598,   599,   600,   635,   636,   667,   666,   147,   148,   224,
     225,   356,   349,   350,   351,   452,   453,   454,   455,   551,
     552,   608,   609,   610,   605,   644,   645,   681,   682,   683,
     711,   712,   713,   740,   741,   742,   743,   770,   771,   796,
     795,   679,   680,   706,   707,   708,   737,   702,   703,   733,
     764,   765,   766,   790,   791,   792,   822,   850,   851,   852,
     886,   887,   888,   889,   931,   980,  1038,   819,   820,   845,
     880,   881,   882,   923,   924,   925,   926,   977,  1032,  1033,
    1034,  1071,   843,   844,   876,   918,   919,   920,   970,   971,
     972,   973,  1028,  1067,   875,   914,   915,   966,   967,  1020,
    1017,  1018,  1019,  1061,  1062,  1063,  1064,  1094,  1117,  1118,
    1119,  1130,   730,   731,   759,   785,   786,   787,   813,   814,
     815,   840,   872,   873,   874,   909,   910,   911,   912,   965,
    1014,  1058,   838,   867,   868,   904,   905,   956,   953,   954,
     955,  1008,  1009,  1010,  1011,  1054,  1086,  1087,  1088,  1112,
     756,   757,   780,   808,   809,   810,   833,   834,   835,   864,
     901,   902,   903,   947,   948,   949,   950,  1005,  1082,   862,
     896,   897,   942,   943,   996,   993,   994,   995,  1045,  1046,
    1047,  1048,  1078,  1102,  1103,  1104,  1124,   777,   778,   803,
     828,   829,   830,   856,   857,   858,   859,   893,   894,   937,
     934,   935,   936,   985,   986,   987,   988,   989,   990,  1040,
     549,   550,   602,   640,   641,   642,   674,   675,   676,   677,
     699,   700,   724,   720,   721,   722,   748,   749,   750,   751,
     752,   753,   657,   658,   659,   660,    96,    97,    98,    99,
     476,   477,   478,   479,   100,   101,   102,   103,   235,   236,
     237,   238,   488,   489,   490,   491,   142,   357,   358,   359,
     360,   734,   760,   781,   804,   823,   841,   865,   439,   728,
     603,   104,   406,  1113,   166,   167,   262
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1048
static const yytype_int16 yypact[] =
{
      17, -1048,    59,    53, -1048, -1048,    57,    30, -1048, -1048,
      61,    67,   151, -1048, -1048,    74,   239,     2, -1048, -1048,
   -1048, -1048,   251,    88,     7, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   126,
     100, -1048, -1048,   127, -1048,   297, -1048,   303, -1048,   305,
   -1048,   307, -1048,   309, -1048,   311, -1048,   313, -1048,   166,
   -1048, -1048,   315,   131, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   140,   108, -1048, -1048,   317, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,   237, -1048,   166, -1048, -1048, -1048,   204,
   -1048,   214, -1048,   319,   127, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,    35, -1048, -1048, -1048, -1048,
      20, -1048, -1048, -1048, -1048,    26, -1048, -1048, -1048, -1048,
      32, -1048, -1048, -1048, -1048,    39, -1048, -1048, -1048, -1048,
      22, -1048, -1048, -1048, -1048,    14, -1048, -1048, -1048, -1048,
   -1048,   321, -1048,   -34, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,    21, -1048, -1048, -1048, -1048,   183,   190,   209,   190,
     233,   190,   235, -1048,   323, -1048,   250,     0, -1048, -1048,
     -27, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   182, -1048,
   -1048,   142, -1048, -1048,   177, -1048, -1048,   191, -1048, -1048,
     192, -1048, -1048,   162, -1048, -1048,   210,   299,    80, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   325, -1048,   327, -1048,   329, -1048,   331, -1048,
     333, -1048,   166,   -21,   335,   168, -1048, -1048,   225,   341,
   -1048,   361, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   343,
   -1048, -1048, -1048, -1048,   345, -1048, -1048, -1048, -1048,   444,
   -1048,   118, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,   277,   292, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   349,   330, -1048, -1048,    36, -1048, -1048, -1048, -1048,
      43, -1048, -1048, -1048, -1048,     5, -1048, -1048, -1048, -1048,
       9, -1048, -1048, -1048, -1048,    25, -1048, -1048, -1048, -1048,
     344, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,   346, -1048,   348, -1048,
     350, -1048,   358, -1048,   360, -1048,   434, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   237, -1048,   166,   -10, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   369, -1048, -1048, -1048,   386, -1048,
   -1048,   396, -1048,   400, -1048, -1048,   351,   356, -1048, -1048,
   -1048, -1048, -1048,   362,   165, -1048, -1048, -1048,   364,   269,
   -1048, -1048,   384, -1048, -1048,   388, -1048, -1048,   324, -1048,
   -1048,   334, -1048, -1048, -1048,   347, -1048,   128, -1048, -1048,
   -1048, -1048,    16, -1048, -1048, -1048, -1048,    13, -1048, -1048,
   -1048, -1048,    19, -1048, -1048, -1048, -1048,    41, -1048, -1048,
   -1048, -1048,    52, -1048, -1048, -1048, -1048, -1048,   366, -1048,
     454,   190,   458,   190,   462,   190,   464, -1048,   368, -1048,
   -1048, -1048,   419,   -48, -1048, -1048,   472,   473,   474,   475,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,   370,   269,   352,
   -1048, -1048,   479, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     377, -1048, -1048,   480, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   379,
     390, -1048, -1048, -1048, -1048,   354, -1048, -1048,   353, -1048,
   -1048,   372, -1048, -1048,   427, -1048, -1048,   404,   486,   -52,
   -1048, -1048, -1048, -1048,   376, -1048, -1048, -1048, -1048,   378,
   -1048, -1048, -1048, -1048,   380, -1048, -1048, -1048, -1048,   488,
   -1048,   174, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     476,   485,    27, -1048, -1048, -1048, -1048,   398, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     381,   269, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     355,   359, -1048, -1048, -1048, -1048,   357, -1048, -1048,   363,
   -1048, -1048,   365, -1048,   371, -1048, -1048,   394,   392, -1048,
   -1048, -1048,   383, -1048,   374, -1048, -1048,   499, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   402, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   221, -1048,
   -1048, -1048, -1048, -1048, -1048,   385,   269,   502,   -58, -1048,
   -1048, -1048, -1048, -1048,   415,   127,   506, -1048, -1048,    15,
   -1048,   510, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   408, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   406,   405, -1048, -1048, -1048,   367,
     387,   389,   127, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   375, -1048, -1048, -1048, -1048, -1048, -1048,   391,
     241, -1048,   423,   498,    38, -1048, -1048, -1048, -1048,    75,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,    42, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     446,   504, -1048,   393, -1048, -1048, -1048,   428, -1048, -1048,
     403,   410, -1048, -1048,   521, -1048, -1048, -1048,   412,   175,
   -1048, -1048, -1048, -1048,   522, -1048,   425,   513, -1048,   395,
   -1048,   526,   382, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     397,   245,   468, -1048, -1048, -1048, -1048,   414,   515, -1048,
     399, -1048,   530,   416, -1048, -1048, -1048, -1048, -1048, -1048,
     417,   426,   514,   421, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,   401, -1048,   536,   459, -1048, -1048, -1048,
   -1048, -1048, -1048,   447, -1048,   531, -1048, -1048, -1048,   477,
     514, -1048,   407, -1048, -1048,   539,   185, -1048, -1048, -1048,
   -1048, -1048, -1048,   478, -1048,   540, -1048, -1048,   453, -1048,
     409, -1048, -1048, -1048,   514,   411, -1048,   545,   -39, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,   448,   450, -1048, -1048,
   -1048, -1048,   456, -1048,   413, -1048, -1048, -1048, -1048,   547,
     -44, -1048, -1048, -1048, -1048,   457,   418, -1048,   229, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,   429,   431, -1048,   535,
   -1048, -1048, -1048,   420,   241, -1048, -1048, -1048,   559,   -13,
   -1048, -1048, -1048, -1048,   422,   206, -1048, -1048, -1048,   433,
     470, -1048,   537, -1048, -1048, -1048,   -23, -1048, -1048, -1048,
   -1048, -1048, -1048,   435,   436, -1048,   541, -1048, -1048, -1048,
   -1048,   561,   119, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   424,   170, -1048, -1048, -1048,   484,   497, -1048,
     546,    -6, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,   564,   430,   259, -1048, -1048,
     503,   437, -1048,   548, -1048, -1048, -1048,   432,   572,   438,
   -1048,   576, -1048, -1048, -1048,   471,   207, -1048, -1048, -1048,
   -1048,   -16, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,   575, -1048, -1048,   481,   489,
   -1048,   560,   587,   440, -1048,   -63, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   585,   592,
      12, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   439, -1048,
     542, -1048, -1048, -1048, -1048,   492,   527, -1048,   573,   599,
     442, -1048, -1048, -1048,   441, -1048, -1048, -1048,   507, -1048,
   -1048,   500,   449, -1048,   579,   604,   607, -1048, -1048, -1048,
   -1048,   451, -1048, -1048, -1048, -1048, -1048, -1048,   443, -1048,
   -1048, -1048,   538,   608,    31, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   445, -1048,   452, -1048, -1048,   610,
      78, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   518, -1048,   613,     8, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   543, -1048, -1048, -1048, -1048, -1048,
     460, -1048, -1048, -1048, -1048, -1048
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,   583, -1048, -1048, -1048, -1048,   532, -1048,
   -1048, -1048, -1048, -1048,   373, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
     342, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,   553, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   252, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   130, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,    46, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,    33, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,   179, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   -54,
   -1048, -1048, -1048, -1048, -1048,  -108, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,  -253, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -288, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
    -334, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -424, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,  -270, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,  -367, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -305, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
    -402, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -212, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -340, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   -28, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,  -100, -1048,
   -1048, -1048,  -693, -1048, -1048, -1048,   -78, -1048, -1048, -1048,
    -388, -1048, -1048, -1048,  -618, -1048, -1048, -1048,  -155, -1048,
   -1048, -1048,  -466, -1048, -1048, -1048,   -82, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,  -811,  -255,  -292, -1048,  -242,
   -1048,  -593, -1048, -1047,  -140, -1048, -1048
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     197,   487,   563,   165,   243,   163,   248,   725,   257,   846,
     662,   396,  1108,   399,  1109,  1110,  1069,   506,   194,   203,
     503,   689,   690,   509,   179,   226,   191,   685,   263,   264,
     182,   402,   403,   877,   312,  1108,   185,  1109,  1110,   176,
     390,   313,   735,   188,  1059,   512,   204,   450,   205,   393,
     968,    29,   686,  1125,   907,   606,   515,   672,    64,     4,
    1043,     1,   265,   945,   685,   314,   547,     7,  1131,   607,
     673,    65,   946,    66,   206,    67,   451,    68,     9,   234,
     562,   242,  1108,   247,  1109,  1110,   578,   315,   207,   686,
      30,  1044,  1006,   579,    31,   316,    32,  1060,    33,     5,
     744,  1007,   745,   746,   513,   624,   208,   266,    13,   317,
      34,   318,   209,   908,   451,    69,   380,    14,   884,   391,
      35,   885,    36,   319,   394,   186,    22,   320,    37,   321,
    1111,   322,   177,   323,   189,   736,   510,   969,   385,   516,
     311,   180,    62,    70,    38,   183,   507,   504,   404,   192,
     400,    88,   397,   798,   691,  1123,  1024,   195,   227,    89,
      90,    17,    18,    91,    92,   258,   259,   260,   261,  1129,
     670,   747,    65,  1070,    66,    86,    67,   981,    68,   982,
     983,   352,   863,   623,   353,   140,   279,   146,    30,   280,
     354,   149,    31,   229,    32,   355,    33,    89,    90,   472,
     473,   938,    89,    90,   472,   473,   738,   168,    34,   739,
     483,   484,   456,   457,   458,   459,    69,   169,    35,   239,
      36,   839,    89,    90,   374,   461,    37,   375,   231,   232,
     984,   649,   650,   744,   497,   745,   746,   498,    89,    90,
     472,   473,    38,   244,    70,   249,   483,   484,   669,    24,
      25,   651,   652,    89,    90,   723,   256,    91,    92,   231,
     232,    60,    61,   272,   449,   981,   447,   982,   983,    89,
      90,   651,   652,    89,    90,   472,   473,    89,    90,   271,
     595,    91,    92,   596,   274,   821,   528,   275,   533,   276,
     538,    89,    90,   472,   473,   854,   273,   518,   855,   483,
     484,    89,    90,   472,   473,   278,   475,   105,   106,   483,
     484,   486,   727,   110,   111,   115,   116,   120,   121,   125,
     126,   130,   131,   135,   136,   144,   145,   151,   152,   170,
     171,   198,   199,   251,   252,   285,   286,   290,   291,   295,
     296,   300,   301,   305,   306,   347,   348,   362,   363,   366,
     367,   369,   370,   277,   407,   408,   412,   413,   417,   418,
     422,   423,   361,   527,   365,   532,   381,   537,   427,   428,
     432,   433,   469,   470,   480,   481,   519,   520,   541,   542,
     557,   558,   584,   585,   587,   588,   590,   591,   921,   922,
     561,   618,   619,   638,   639,   664,   665,   704,   705,   709,
     710,   718,   719,   762,   763,   783,   784,   793,   794,   806,
     807,   826,   827,   611,   612,   613,   614,   848,   849,   870,
     871,   878,   879,   899,   900,   616,   266,   617,   916,   917,
     932,   933,   951,   952,   991,   992,   279,   625,   460,   959,
    1015,  1016,  1030,  1031,  1036,  1037,  1056,  1057,  1080,  1081,
     372,  1084,  1085,  1100,  1101,  1115,  1116,   462,   386,   437,
     465,   637,   374,   463,   524,   464,   646,   492,   529,   493,
     496,   494,   534,   663,   539,   495,   546,   999,   553,   554,
     555,   556,   565,   567,   566,   572,   573,   564,   568,   574,
     575,   576,   577,   622,   593,   604,   497,   578,   595,   601,
     626,  1023,   647,   633,   643,   615,   940,   688,   671,   648,
     629,   678,   687,   694,   716,   695,   631,   958,   630,   732,
     632,   697,   758,   729,   755,   767,   772,   799,   775,   701,
     779,   696,   788,   673,   768,   802,   811,   776,   789,   801,
     821,   773,   831,   832,   739,   853,   839,   715,   837,   842,
     661,   883,   863,   906,   717,   998,   824,   861,   668,   866,
     854,   891,   895,   913,   930,   944,   964,   684,   907,  1002,
     976,   979,   812,   945,  1013,  1004,  1025,  1027,  1035,  1022,
     817,  1039,  1041,   754,   818,  1050,   928,  1006,  1051,  1053,
     962,   885,   761,  1055,   974,  1066,   922,   969,  1068,  1075,
    1073,  1074,  1077,  1043,   684,  1079,  1090,  1091,  1093,  1060,
    1095,  1096,  1098,  1121,  1107,  1106,  1122,  1127,   782,  1128,
    1133,  1135,   726,    87,   387,   150,   175,   627,   714,   466,
     569,   634,   548,   769,   929,   800,   975,  1026,  1092,   805,
     963,   382,  1052,  1003,  1076,   892,  1042,   698,   816,   774,
     960,  1000,   941,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   825,     0,     0,     0,     0,     0,     0,     0,
       0,   836,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   847,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   860,     0,   797,     0,     0,     0,     0,     0,   869,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   898,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   927,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   961,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     978,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1001,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   939,     0,     0,     0,
       0,     0,     0,     0,  1012,     0,     0,   957,     0,     0,
       0,     0,     0,     0,     0,     0,  1029,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1049,   997,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1065,     0,  1021,
       0,     0,     0,     0,     0,  1072,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,     0,  1089,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1097,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,  1105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,  1120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1132,     0,     0,     0,     0,     0,  1134
};

static const yytype_int16 yycheck[] =
{
     140,   389,   468,    85,   159,    83,   161,   700,     8,   820,
     628,     6,     4,     4,     6,     7,     4,     4,     4,    53,
       4,     6,     7,     4,     4,     4,     4,   645,   168,   169,
       4,     6,     7,   844,    55,     4,     4,     6,     7,     4,
       4,    62,     4,     4,   107,     4,    80,    57,    82,     6,
      73,    49,   645,  1100,    98,    28,     4,   115,    51,     0,
      76,    44,    89,    76,   682,    86,   114,    10,  1115,    42,
     128,    64,    85,    66,   108,    68,   124,    70,    48,   157,
     468,   159,     4,   161,     6,     7,   138,   108,   122,   682,
      88,   107,    98,   145,    92,   116,    94,   160,    96,    46,
      58,   107,    60,    61,    63,   571,   140,   134,    47,   130,
     108,   132,   146,   157,   124,   108,   256,    50,   157,    83,
     118,   160,   120,   144,    81,    93,    52,   148,   126,   150,
      99,   152,    97,   154,    95,    97,   117,   160,   278,    87,
     222,   121,    54,   136,   142,   119,   133,   131,   123,   127,
     141,    24,   147,   771,   139,    77,   967,   143,   137,    32,
      33,    10,    11,    36,    37,   165,   166,   167,   168,   161,
     636,   129,    64,   161,    66,    49,    68,    58,    70,    60,
      61,    13,    12,   571,    16,    19,   106,    56,    88,   109,
      22,    51,    92,    10,    94,    27,    96,    32,    33,    34,
      35,   894,    32,    33,    34,    35,   131,     3,   108,   134,
      40,    41,   352,   353,   354,   355,   108,     3,   118,    10,
     120,    15,    32,    33,   106,   365,   126,   109,    38,    39,
     111,    10,    11,    58,   106,    60,    61,   109,    32,    33,
      34,    35,   142,    10,   136,    10,    40,    41,   636,    10,
      11,    30,    31,    32,    33,    14,     6,    36,    37,    38,
      39,    10,    11,   121,   346,    58,   344,    60,    61,    32,
      33,    30,    31,    32,    33,    34,    35,    32,    33,    97,
     106,    36,    37,   109,    93,    26,   441,    95,   443,   127,
     445,    32,    33,    34,    35,   110,   119,   437,   113,    40,
      41,    32,    33,    34,    35,     6,   384,    10,    11,    40,
      41,   389,   700,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,     6,     7,     6,
       7,     6,     7,   143,    10,    11,    10,    11,    10,    11,
      10,    11,   137,   441,     3,   443,    89,   445,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     6,     7,     6,     7,     6,     7,   159,   160,
     468,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   553,   554,   555,   556,    10,    11,    10,
      11,    10,    11,    10,    11,   565,   134,   567,    10,    11,
      10,    11,    10,    11,    10,    11,   106,   577,    69,   905,
      10,    11,    10,    11,     6,     7,     6,     7,     6,     7,
       6,    10,    11,    10,    11,    10,    11,    71,   109,    25,
     109,   601,   106,    67,    10,    65,   606,    83,    10,    81,
     123,   147,    10,   628,    10,   141,    57,   943,     6,     6,
       6,     6,     3,     3,   107,   131,   133,   135,   109,   117,
      63,    87,     6,   571,     6,    10,   106,   138,   106,    23,
     145,   967,     3,   109,   130,   107,   894,   647,     6,   107,
     153,    96,     6,     3,   139,   107,   151,   905,   155,    21,
     149,   115,    18,   100,    78,    97,     5,    59,     6,   162,
      17,   671,     6,   128,   131,    20,     6,   112,   156,   125,
      26,   129,     6,    84,   134,     6,    15,   687,   101,    72,
     628,     6,    12,     6,   694,   943,   135,    79,   636,   106,
     110,   113,   106,   106,    29,     6,    29,   645,    98,    85,
      29,    10,   156,    76,    10,    29,    73,    29,     6,   967,
     163,     5,   111,   723,   158,    10,   157,    98,   107,    29,
     157,   160,   732,     6,   159,    10,   160,   160,     6,   107,
     161,    59,    29,    76,   682,     6,    99,   107,    29,   160,
       6,     4,   161,   161,     6,    77,     6,    99,   758,     6,
      77,   161,   700,    40,   282,    72,    94,   581,   682,   377,
     500,   598,   453,   741,   887,   775,   924,   971,  1062,   779,
     910,   268,  1009,   948,  1046,   857,   986,   675,   788,   749,
     905,   943,   894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   831,    -1,   771,    -1,    -1,    -1,    -1,    -1,   839,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   853,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   883,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   906,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   894,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   964,    -1,    -1,   905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1004,   943,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1027,    -1,   967,
      -1,    -1,    -1,    -1,    -1,  1035,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1053,    -1,  1055,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1068,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,    -1,  1079,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1093,    -1,  1095,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1122,    -1,    -1,    -1,    -1,    -1,  1128
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,     0,    46,   172,    10,   173,    48,
     174,   175,   176,    47,    50,   255,   256,    10,    11,   177,
     178,   179,    52,   309,    10,    11,   257,   258,   259,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   180,
     181,   182,   183,   184,   199,   200,   205,   206,   211,   212,
     217,   218,   223,   224,   229,   230,   235,   236,   241,   242,
      10,    11,    54,   356,    51,    64,    66,    68,    70,   108,
     136,   260,   261,   262,   263,   264,   269,   270,   276,   277,
     283,   284,   290,   291,   295,   296,    49,   182,    24,    32,
      33,    36,    37,   185,   186,   187,   675,   676,   677,   678,
     683,   684,   685,   686,   710,    10,    11,   201,   202,   203,
      10,    11,   207,   208,   209,    10,    11,   213,   214,   215,
      10,    11,   219,   220,   221,    10,    11,   225,   226,   227,
      10,    11,   231,   232,   233,    10,    11,   237,   238,   239,
      19,   243,   695,   310,    10,    11,    56,   446,   447,    51,
     262,    10,    11,   265,   266,   267,   271,   272,   278,   279,
     285,   286,   292,   675,   297,   695,   713,   714,     3,     3,
      10,    11,   188,   189,   190,   187,     4,    97,   204,     4,
     121,   210,     4,   119,   216,     4,    93,   222,     4,    95,
     228,     4,   127,   234,     4,   143,   240,   713,    10,    11,
     244,   245,   246,    53,    80,    82,   108,   122,   140,   146,
     311,   312,   313,   318,   319,   324,   325,   330,   331,   336,
     337,   342,   343,   357,   448,   449,     4,   137,   268,    10,
     274,    38,    39,   273,   675,   687,   688,   689,   690,    10,
     281,   280,   675,   687,    10,   288,   287,   675,   687,    10,
     293,    10,    11,   298,   299,   300,     6,     8,   165,   166,
     167,   168,   715,   713,   713,    89,   134,   191,   192,   193,
     194,    97,   121,   119,    93,    95,   127,   143,     6,   106,
     109,   247,   248,   249,   250,    10,    11,   314,   315,   316,
      10,    11,   320,   321,   322,    10,    11,   326,   327,   328,
      10,    11,   332,   333,   334,    10,    11,   338,   339,   340,
     344,   695,    55,    62,    86,   108,   116,   130,   132,   144,
     148,   150,   152,   154,   358,   359,   360,   365,   366,   371,
     372,   377,   378,   383,   384,   389,   390,   406,   407,   413,
     414,   420,   421,   427,   428,   432,   433,    10,    11,   451,
     452,   453,    13,    16,    22,    27,   450,   696,   697,   698,
     699,   137,     6,     7,   275,     3,     6,     7,   282,     6,
       7,   289,     6,   294,   106,   109,   301,   302,   303,   304,
     713,    89,   193,   195,   196,   713,   109,   249,   251,   252,
       4,    83,   317,     6,    81,   323,     6,   147,   329,     4,
     141,   335,     6,     7,   123,   341,   711,    10,    11,   345,
     346,   347,    10,    11,   361,   362,   363,    10,    11,   367,
     368,   369,    10,    11,   373,   374,   375,    10,    11,   379,
     380,   381,    10,    11,   385,   386,   387,    25,   391,   707,
     408,   409,   415,   416,   422,   423,   429,   675,   434,   695,
      57,   124,   454,   455,   456,   457,   713,   713,   713,   713,
      69,   713,    71,    67,    65,   109,   303,   305,   306,    10,
      11,   198,    34,    35,   197,   675,   679,   680,   681,   682,
      10,    11,   254,    40,    41,   253,   675,   679,   691,   692,
     693,   694,    83,    81,   147,   141,   123,   106,   109,   348,
     349,   350,   351,     4,   131,   364,     4,   133,   370,     4,
     117,   376,     4,    63,   382,     4,    87,   388,   713,    10,
      11,   392,   393,   394,    10,   411,   410,   675,   687,    10,
     418,   417,   675,   687,    10,   425,   424,   675,   687,    10,
     430,    10,    11,   435,   436,   437,    57,   114,   456,   649,
     650,   458,   459,     6,     6,     6,     6,    10,    11,   308,
     307,   675,   679,   691,   135,     3,   107,     3,   109,   350,
     352,   353,   131,   133,   117,    63,    87,     6,   138,   145,
     395,   396,   397,   398,     6,     7,   412,     6,     7,   419,
       6,     7,   426,     6,   431,   106,   109,   438,   439,   440,
     441,    23,   651,   709,    10,   463,    28,    42,   460,   461,
     462,   713,   713,   713,   713,   107,   713,   713,    10,    11,
     355,   354,   675,   679,   691,   713,   145,   397,   399,   153,
     155,   151,   149,   109,   440,   442,   443,   713,    10,    11,
     652,   653,   654,   130,   464,   465,   713,     3,   107,    10,
      11,    30,    31,   400,   401,   402,   403,   671,   672,   673,
     674,   675,   683,   687,    10,    11,   445,   444,   675,   679,
     691,     6,   115,   128,   655,   656,   657,   658,    96,   480,
     481,   466,   467,   468,   675,   683,   710,     6,   713,     6,
       7,   139,   404,   405,     3,   107,   713,   115,   657,   659,
     660,   162,   486,   487,    10,    11,   482,   483,   484,    10,
      11,   469,   470,   471,   468,   713,   139,   713,    10,    11,
     662,   663,   664,    14,   661,   671,   675,   679,   708,   100,
     551,   552,    21,   488,   700,     4,    97,   485,   131,   134,
     472,   473,   474,   475,    58,    60,    61,   129,   665,   666,
     667,   668,   669,   670,   713,    78,   589,   590,    18,   553,
     701,   713,    10,    11,   489,   490,   491,    97,   131,   474,
     476,   477,     5,   129,   667,     6,   112,   626,   627,    17,
     591,   702,   713,    10,    11,   554,   555,   556,     6,   156,
     492,   493,   494,    10,    11,   479,   478,   675,   683,    59,
     713,   125,    20,   628,   703,   713,    10,    11,   592,   593,
     594,     6,   156,   557,   558,   559,   713,   163,   158,   506,
     507,    26,   495,   704,   135,   713,    10,    11,   629,   630,
     631,     6,    84,   595,   596,   597,   713,   101,   571,    15,
     560,   705,    72,   521,   522,   508,   704,   713,    10,    11,
     496,   497,   498,     6,   110,   113,   632,   633,   634,   635,
     713,    79,   608,    12,   598,   706,   106,   572,   573,   713,
      10,    11,   561,   562,   563,   533,   523,   704,    10,    11,
     509,   510,   511,     6,   157,   160,   499,   500,   501,   502,
     713,   113,   634,   636,   637,   106,   609,   610,   713,    10,
      11,   599,   600,   601,   574,   575,     6,    98,   157,   564,
     565,   566,   567,   106,   534,   535,    10,    11,   524,   525,
     526,   159,   160,   512,   513,   514,   515,   713,   157,   501,
      29,   503,    10,    11,   639,   640,   641,   638,   671,   675,
     679,   708,   611,   612,     6,    76,    85,   602,   603,   604,
     605,    10,    11,   577,   578,   579,   576,   675,   679,   691,
     705,   713,   157,   566,    29,   568,   536,   537,    73,   160,
     527,   528,   529,   530,   159,   514,    29,   516,   713,    10,
     504,    58,    60,    61,   111,   642,   643,   644,   645,   646,
     647,    10,    11,   614,   615,   616,   613,   675,   679,   691,
     706,   713,    85,   604,    29,   606,    98,   107,   580,   581,
     582,   583,   713,    10,   569,    10,    11,   539,   540,   541,
     538,   675,   679,   691,   704,    73,   529,    29,   531,   713,
      10,    11,   517,   518,   519,     6,     6,     7,   505,     5,
     648,   111,   644,    76,   107,   617,   618,   619,   620,   713,
      10,   107,   582,    29,   584,     6,     6,     7,   570,   107,
     160,   542,   543,   544,   545,   713,    10,   532,     6,     4,
     161,   520,   713,   161,    59,   107,   619,    29,   621,     6,
       6,     7,   607,   713,    10,    11,   585,   586,   587,   713,
      99,   107,   544,    29,   546,     6,     4,   713,   161,   713,
      10,    11,   622,   623,   624,   713,    77,     6,     4,     6,
       7,    99,   588,   712,   713,    10,    11,   547,   548,   549,
     713,   161,     6,    77,   625,   712,   713,    99,     6,   161,
     550,   712,   713,    77,   713,   161
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
      yyerror (&yylloc, osresult, parserData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osresult, parserData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSResult *osresult, OSrLParserData *parserData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osresult, parserData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSResult *osresult;
    OSrLParserData *parserData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osresult, parserData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSResult *osresult, OSrLParserData *parserData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osresult, parserData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);

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
int yyparse (OSResult *osresult, OSrLParserData *parserData);
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
yyparse (OSResult *osresult, OSrLParserData *parserData)
#else
int
yyparse (osresult, parserData)
    OSResult *osresult;
    OSrLParserData *parserData;
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
        case 3:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 29:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 30:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 33:

    { 
	    if ((parserData->typeAttribute != "error"  ) &&
	        (parserData->typeAttribute != "warning") && 
	        (parserData->typeAttribute != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not match any legal value");
		osresult->setGeneralStatusType(parserData->typeAttribute); 
	;}
    break;

  case 34:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 35:

    {   if (!osresult->setNumberOfGeneralSubstatuses(parserData->tempVal))
			osrlerror(NULL, NULL, parserData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempVal;
		parserData->kounter = 0;
	;}
    break;

  case 36:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 37:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 44:

    {	parserData->kounter++;
;}
    break;

  case 45:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 46:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
;}
    break;

  case 49:

    {	
		osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 50:

    {	
		osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 54:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 60:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 62:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 68:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 70:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 76:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 78:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 84:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 86:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 92:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 94:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 100:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 102:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 108:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 110:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 111:

    {
	if (parserData->tempVal < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	if (!osresult->setNumberOfOtherGeneralResults(parserData->tempVal))
		osrlerror(NULL, NULL, parserData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempVal;
	parserData->kounter = 0;
;}
    break;

  case 112:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 113:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 120:

    {	parserData->kounter++;
;}
    break;

  case 121:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 122:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 125:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 126:

    {	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 127:

    {	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 148:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 154:

    {osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 156:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 160:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 161:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 163:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 164:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 166:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 170:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 171:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 173:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 174:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 176:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 180:

    {	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 181:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 183:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 184:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 186:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 188:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 190:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 192:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 193:

    {
	if (parserData->tempVal < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults(parserData->tempVal);
	parserData->numberOf = parserData->tempVal;
	parserData->kounter = 0;
;}
    break;

  case 194:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 195:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 202:

    {	parserData->kounter++;
;}
    break;

  case 203:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 204:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 207:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 208:

    {	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 209:

    {	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 224:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 230:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
		if (parserData->tempStr != "busy"                &&
			parserData->tempStr != "busyButAccepting"    &&
			parserData->tempStr != "idle"                &&
			parserData->tempStr != "idleButNotAccepting" &&
			parserData->tempStr != "noResponse"             )
			osrlerror(NULL, NULL, parserData, "current system state not recognized");
		osresult->setCurrentState(parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 232:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 238:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 240:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 246:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 248:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 254:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 256:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 262:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 264:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 265:

    {
	if (parserData->tempVal < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults(parserData->tempVal);
	parserData->numberOf = parserData->tempVal;
	parserData->kounter = 0;
;}
    break;

  case 266:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 267:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 274:

    {	parserData->kounter++;
;}
    break;

  case 275:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 276:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 279:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 280:

    {	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 281:

    {	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 301:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 307:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (parserData->tempStr != "waiting"  &&
			parserData->tempStr != "running"  &&
			parserData->tempStr != "killed"   &&
			parserData->tempStr != "finished" &&
			parserData->tempStr != "unknown"     )
			osrlerror (NULL, NULL, parserData, "status of this job not recognized");
		osresult->setJobStatus(parserData->tempStr);  
		parserData->errorText = NULL;
	;}
    break;

  case 309:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 315:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 317:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 323:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 325:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 331:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 333:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 339:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 341:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 342:

    {	if (parserData->tempVal < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = parserData->tempVal;
	parserData->ivar = 0;
;}
    break;

  case 343:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	;}
    break;

  case 344:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	;}
    break;

  case 352:

    {	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "";
	parserData->typeAttribute = "";
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 355:

    {	if (parserData->unitAttribute != "tick"        &&
			parserData->unitAttribute != "millisecond" &&
			parserData->unitAttribute != "second"      &&
			parserData->unitAttribute != "minute"      &&
			parserData->unitAttribute != "hour"        &&
			parserData->unitAttribute != "day"         &&
			parserData->unitAttribute != "week"        &&
			parserData->unitAttribute != "month"       &&
			parserData->unitAttribute != "year"   )     
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	;}
    break;

  case 356:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	;}
    break;

  case 357:

    {	if (parserData->categoryAttribute != "total"          &&
			parserData->categoryAttribute != "input"          &&
			parserData->categoryAttribute != "preprocessing"  &&
			parserData->categoryAttribute != "optimization"   &&
			parserData->categoryAttribute != "postprocessing" &&
			parserData->categoryAttribute != "output"         &&
 			parserData->categoryAttribute != "other"   )
			osrlerror(NULL, NULL, parserData, "time category not recognized");
	;}
    break;

  case 364:

    {	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
;}
    break;

  case 365:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 366:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 368:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 372:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setUsedDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 373:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 375:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 376:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 378:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 382:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
		osresult->setUsedMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 383:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 385:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 386:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 388:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 392:

    {	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setUsedCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 393:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 395:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 396:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 398:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 400:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 402:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 404:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 405:

    {
	if (parserData->tempVal < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults(parserData->tempVal);
	parserData->numberOf = parserData->tempVal;
	parserData->kounter = 0;
;}
    break;

  case 406:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 407:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 414:

    {	parserData->kounter++;
;}
    break;

  case 415:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 416:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 419:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 420:

    {	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 421:

    {	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 426:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 427:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
;}
    break;

  case 430:

    {
		parserData->numberOfSolutions = parserData->tempVal; 
		osresult->setSolutionNumber(parserData->tempVal);
		parserData->solutionIdx = 0;
	;}
    break;

  case 431:

    {	
		parserData->numberOfVariables = parserData->tempVal; 
		osresult->setVariableNumber(parserData->tempVal);
	;}
    break;

  case 432:

    {
		parserData->numberOfConstraints = parserData->tempVal; 
		osresult->setConstraintNumber(parserData->tempVal);
	;}
    break;

  case 433:

    {	
		parserData->numberOfObjectives = parserData->tempVal; 
		osresult->setObjectiveNumber(parserData->tempVal);
	;}
    break;

  case 434:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	;}
    break;

  case 435:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	;}
    break;

  case 443:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 449:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 450:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 451:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 453:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 454:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	;}
    break;

  case 457:

    {   if ((parserData->typeAttribute != "unbounded"      ) && 
			(parserData->typeAttribute != "globallyOptimal") && 
	        (parserData->typeAttribute != "locallyOptimal" ) &&
	        (parserData->typeAttribute != "optimal"        ) && 
	        (parserData->typeAttribute != "bestSoFar"      ) &&
	        (parserData->typeAttribute != "feasible"       ) && 
	        (parserData->typeAttribute != "infeasible"     ) &&
	        (parserData->typeAttribute != "unsure"         ) && 
	        (parserData->typeAttribute != "error"          ) &&
	        (parserData->typeAttribute != "other"          ))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute); 
	;}
    break;

  case 458:

    {   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	;}
    break;

  case 459:

    {	osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempVal);
		parserData->numberOf = parserData->tempVal;
		parserData->kounter = 0;
	;}
    break;

  case 460:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 461:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 468:

    {	parserData->kounter++; ;}
    break;

  case 469:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 470:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
;}
    break;

  case 473:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	;}
    break;

  case 474:

    {	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	;}
    break;

  case 485:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));
		parserData->errorText = NULL;
	;}
    break;

  case 488:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 490:

    {	
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempVal);
	parserData->numberOfOtherVariableResults = parserData->tempVal;
	parserData->iOther = 0;
;}
    break;

  case 499:

    {
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 500:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 501:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 508:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 509:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 510:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 512:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 513:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 517:

    {
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 518:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 519:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 526:

    {
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         parserData->tempStr);
	parserData->kounter++;
;}
    break;

  case 527:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 528:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 529:

    {parserData->tempStr = "";;}
    break;

  case 534:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 538:

    {
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 539:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 540:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 548:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 549:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 550:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "unknown"  &&
		parserData->tempStr != "basic"    &&
		parserData->tempStr != "atLower"  &&
		parserData->tempStr != "atUpper"  &&
		parserData->tempStr != "superBasic" )
		osrlerror(NULL, NULL, parserData, "unrecognized basis status");
	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 	  parserData->idx,         parserData->tempStr);
	parserData->kounter++;
;}
    break;

  case 553:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 554:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 555:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 558:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
		parserData->numberAttributePresent = true;
	 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 		                                            parserData->iOther, parserData->numberOfVar);
		parserData->kounter = 0;
	;}
    break;

  case 559:

    {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
    ;}
    break;

  case 560:

    {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
    ;}
    break;

  case 561:

    {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
    ;}
    break;

  case 570:

    { 	
	parserData->kounter++;
;}
    break;

  case 572:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 578:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 581:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 583:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempVal;
    osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempVal);
	parserData->iOther = 0;
;}
    break;

  case 592:

    {
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 593:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 594:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 601:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 602:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 604:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 606:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 607:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 610:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 611:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 612:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 615:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
		parserData->numberAttributePresent = true;
 		osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 			                                         parserData->iOther, parserData->numberOfObj);
		parserData->kounter = 0;
	;}
    break;

  case 616:

    {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
    ;}
    break;

  case 617:

    {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
    ;}
    break;

  case 618:

    {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
    ;}
    break;

  case 627:

    {  
	parserData->kounter++;
;}
    break;

  case 629:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 635:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 638:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 640:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempVal;
	osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempVal);
	parserData->iOther = 0;
;}
    break;

  case 648:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 649:

    {
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 650:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 651:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 658:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 659:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 660:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 661:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 662:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 665:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 666:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 667:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 670:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
		parserData->numberAttributePresent = true;
 		osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 			                                          parserData->iOther, parserData->numberOfCon);
		parserData->kounter = 0;
	;}
    break;

  case 671:

    {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
    ;}
    break;

  case 672:

    {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
    ;}
    break;

  case 673:

    {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
    ;}
    break;

  case 682:

    { 	
	parserData->kounter++;
;}
    break;

  case 684:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 690:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 693:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 694:

    {	
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempVal);
	parserData->numberOf = parserData->tempVal;
	parserData->iOther = 0; 
;}
    break;

  case 695:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 696:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 703:

    {	parserData->iOther++;
;}
    break;

  case 704:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 705:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 708:

    {	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	;}
    break;

  case 709:

    {	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	;}
    break;

  case 710:

    {	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
													parserData->descriptionAttribute);
	;}
    break;

  case 711:

    {	
		osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
													  parserData->numberOfItems);
		parserData->kounter = 0;
	;}
    break;

  case 712:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 713:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 720:

    {	parserData->kounter++;
;}
    break;

  case 721:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 726:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
;}
    break;

  case 729:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 730:

    {	
    osresult->setNumberOfSolverOutputs(parserData->tempVal);
	parserData->numberOf = parserData->tempVal;
	parserData->iOther = 0; 
;}
    break;

  case 731:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	;}
    break;

  case 732:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 739:

    {	parserData->iOther++;
;}
    break;

  case 740:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 741:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 744:

    {	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	;}
    break;

  case 745:

    {	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	;}
    break;

  case 746:

    {	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	;}
    break;

  case 747:

    {	
		osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
		parserData->kounter = 0;
	;}
    break;

  case 748:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 749:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 756:

    {	parserData->kounter++;
;}
    break;

  case 757:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 761:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
;}
    break;

  case 762:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 765:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 766:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 767:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 770:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 771:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 772:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 775:

    { parserData->nameAttribute = ""; ;}
    break;

  case 776:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 777:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 780:

    { parserData->typeAttribute = ""; ;}
    break;

  case 781:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 782:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 785:

    { parserData->unitAttribute = ""; ;}
    break;

  case 786:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 787:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 790:

    { parserData->valueAttribute = ""; ;}
    break;

  case 791:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 792:

    {
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 793:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempVal = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 794:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempVal = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 795:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempVal = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 796:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempVal = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 797:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 798:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 799:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 800:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 801:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 802:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 803:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 804:

    {
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 805:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 806:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 807:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <substatus> elements cannot be negative");
	parserData->tempVal = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 808:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 809:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 810:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 811:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 812:

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
      yyerror (&yylloc, osresult, parserData, YY_("syntax error"));
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
	    yyerror (&yylloc, osresult, parserData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osresult, parserData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osresult, parserData);
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
		  yystos[yystate], yyvsp, yylsp, osresult, parserData);
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
  yyerror (&yylloc, osresult, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osresult, parserData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osresult, parserData);
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





void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, const char* errormsg )
{
	osrl_empty_vectors( parserData);
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
	outStr << "The offending text is: " << osrlget_text ( scanner ) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osrllex_destroy( scanner);
	throw ErrorClass( error);
} //end osrlerror

void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData) throw(ErrorClass){
	try{
		osrl_scan_string( parsestring, scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData) != 0) {
			//osrllex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSrL");
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


